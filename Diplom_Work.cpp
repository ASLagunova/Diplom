#include "Diplom_Work.h"
#include <direct.h>
#include <algorithm> 
void Diplom_Work::AddNewRecortToTable( AddInfo structRecord )
{
	QString name = GetNameFromPath( structRecord.fullPath );
	QString date = GetNowTimeDate();
	QString tempStrVal;
	tempStrVal = CreateRequestIntoBDAddRecord( name, structRecord.type, date, structRecord.fullPath );
	InsertRecord( tempStrVal );

	vector<int> AllID = GetAllIDFromDB();
	int maxId = *max_element( AllID.begin(), AllID.end() );

	QModelIndex index;
	index = tableModel->index( tableModel->rowCount(), tableModel->columnCount() );
	tableModel->insertRow( tableModel->rowCount(), index );

	for( int j = 0; j < tableModel->columnCount(); j++ ) {
		index = tableModel->index( tableModel->rowCount() - 1, j );
		if( j == 0 ) { tableModel->setData( index, name ); }
		if( j == 1 ) { tableModel->setData( index, structRecord.type ); }
		if( j == 2 ) { tableModel->setData( index, date ); }
		if( j == 3 ) { tableModel->setData( index, structRecord.fullPath ); }
		if( j == 4 ) { tableModel->setData( index, maxId ); }
	}
}

void Diplom_Work::InitTable()
{
	InfoAboutBD iifoAbounBD;
	iifoAbounBD = GetInfoAboutBD();

	tableModel = new QStandardItemModel( iifoAbounBD.countRow, iifoAbounBD.countColomn, NULL );
	ui.TableDataFromBD->setModel( tableModel );
	ui.TableDataFromBD->setSelectionBehavior( QAbstractItemView::SelectionBehavior::SelectRows );

	ui.TableDataFromBD->horizontalHeader()->setStretchLastSection( true );
	int witchTable = ui.TableDataFromBD->width();

	ui.TableDataFromBD->setColumnWidth( 0, witchTable*0.19 );
	ui.TableDataFromBD->setColumnWidth( 1, witchTable*0.19 );
	ui.TableDataFromBD->setColumnWidth( 2, witchTable*0.18 );


	tableModel->setHeaderData( 0, Qt::Horizontal, "Имя файла" );
	tableModel->setHeaderData( 1, Qt::Horizontal, "Тип файла" );
	tableModel->setHeaderData( 2, Qt::Horizontal, "Дата добавления" );
	tableModel->setHeaderData( 3, Qt::Horizontal, "Путь к файлу" );
	tableModel->setHeaderData( 4, Qt::Horizontal, "ID" );
	QModelIndex index;
	recordBd record;

	vector<int> vectId = GetAllIDFromDB();

	for( int i = 0; i < tableModel->rowCount(); i++ ) {
		int a = vectId[i];
		record = GetRecordByIndex( vectId[i] );
		ui.TableDataFromBD->setRowHidden( i, false );
		for( int j = 0; j < tableModel->columnCount(); j++ ) {
			index = tableModel->index( i, j );
			if( j == 0 ) { tableModel->setData( index, record.FileName ); }
			if( j == 1 ) { tableModel->setData( index, record.Type_document ); }
			if( j == 2 ) { tableModel->setData( index, record.Date ); }
			if( j == 3 ) { tableModel->setData( index, record.PathToFile ); }
			if( j == 4 ) { tableModel->setData( index, record.Id ); }
		}
	}
	ui.TableDataFromBD->show();
	ui.TableDataFromBD->hideColumn(4);
	ui.TableDataFromBD->reset();
}

void Diplom_Work::InitDeleteButtom()
{
	connect( ui.ButtonDelete, &QPushButton::clicked, [=]()
	{
		QModelIndexList selected = ui.TableDataFromBD->selectionModel()->selectedRows();
		QString ID;
		for( auto row : selected ) {
			int a = row.row();
			ID = tableModel->item( row.row(), 4 )->text();
			tableModel->removeRow( row.row() );
		}
		int dec = ID.toInt();
		ui.TableDataFromBD->clearSelection();
		DeleteRecordByIndex( dec );
	} );
}

void Diplom_Work::InitOpenButtom()
{
	connect( ui.ButtonOpen, &QPushButton::clicked, [=]()
	{
		QModelIndexList selected = ui.TableDataFromBD->selectionModel()->selectedRows();
		if( selected.size() != 0) {
			QStandardItem *data;
			for( auto row : selected ) {
				data = tableModel->item( row.row(), 3 );
			}
			QString qstr = data->text();
			QByteArray ba = qstr.toLocal8Bit();
			const char *c_str2 = ba.data();

			ui.TableDataFromBD->clearSelection();
			system( c_str2 );
		}
	} );
}

void Diplom_Work::InitAddButtom()
{
	connect( ui.ButtonAdd, &QPushButton::clicked, [=]()
	{
		addW = new Dialog;
		addW->InitChoiseFile();
		addW->InitAddTypeButtom();
		addW->show();
		connect( addW, SIGNAL( sendStruct( AddInfo ) ), this, SLOT( recieve( AddInfo ) ) );
	} );
}

void Diplom_Work::InitShablonButtom()
{
	connect( ui.ShablonButtom, &QPushButton::clicked, [=]()
	{
		
		ShablonW = new DialogShablon;
		QStringList list = listfilesindir( ShablonW->GetShablonPath() );
		ShablonW->AddShablonsList( list );
		ShablonW->InitChoiseFile();
		ShablonW->InitAddTypeButtom();
		ShablonW->InitButtomOk();
		ShablonW->show();
		connect( ShablonW, SIGNAL( sendStruct( AddInfo ) ), this, SLOT( recieve( AddInfo ) ) );
	} );

}

void Diplom_Work::InitArhiveButtom()
{
	connect( ui.Arhive, &QPushButton::clicked, [=]()
	{
		QModelIndexList selected = ui.TableDataFromBD->selectionModel()->selectedRows();
		QStringList listName;

		QString CreatedArhivDir = DocumentsPath + "\\arhiv";
		QByteArray ba = CreatedArhivDir.toLocal8Bit();
		const char *c_str2 = ba.data();

		bool resultMk = mkdir( c_str2 );

		for( auto row : selected ) {
			QString path = tableModel->item( row.row(), 3 )->text();
			QString nameFile = GetNameWithExFromPath( path );
			bool result = CopyFile( path, CreatedArhivDir );
		}

		QString command = "7z a -tzip -mx=1 " + ArhivPath + + "\\" +  "archive.zip" + " " + CreatedArhivDir;
		QByteArray ba2 = command.toLocal8Bit();
		const char *c_str22 = ba2.data();
		system( c_str22 );

		QDir dir( CreatedArhivDir );
		dir.removeRecursively();
	} );
}

void Diplom_Work::InitFindButtom()
{
	connect( ui.FindButton, &QPushButton::clicked, [=]()
	{
		vector<int> FindedIndexRow;
		if( ui.FindLine->text() == "" ) 
		{
			InitTable();
		}

		if( ui.FindLine->text() != "" )
		{
			int countFinded = 0;
			QString wantedText = ui.FindLine->text();
			for( int i = 0; i < tableModel->rowCount(); i++ ) {
				for( int j = 0; j < tableModel->columnCount(); j++ ) {
					QModelIndex index = tableModel->index( i, j );
					QVariant text = tableModel->data( index );
					QString currentText = text.toString();
					if( currentText.contains( wantedText ) )
					{
						FindedIndexRow.push_back( i );
					}
				}
			}
			// следующие 3 строчки удаляют все повторяющиеся элементы в векторе.
			sort( FindedIndexRow.begin(), FindedIndexRow.end() );
			auto last = unique( FindedIndexRow.begin(), FindedIndexRow.end() );
			FindedIndexRow.erase( last, FindedIndexRow.end() );

			for( int k = 0; k < tableModel->rowCount(); k++ ) 
			{
				std::vector<int>::iterator it;
				it = std::find( FindedIndexRow.begin(), FindedIndexRow.end(), k );
				if( it == FindedIndexRow.end() )
					ui.TableDataFromBD->hideRow( k );
			}
		}
	} );
}

Diplom_Work::Diplom_Work(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
}

Diplom_Work::~Diplom_Work()
{
	//delete addW;
}

void Diplom_Work::recieve( AddInfo structRecord )
{
	AddNewRecortToTable( structRecord );
}