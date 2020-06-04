#include "Main_Window.h"
#include <direct.h>
#include <algorithm> 

void Main_Window::AddNewRecortToTable( AddInfo structRecord )
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

void Main_Window::UpdateRecortToTable( AddInfo structRecord, QString id, QString Name, QString Date )
{
	QString tempStrVal;
	tempStrVal = CreateRequestIntoBDUpdateRecord( Name, structRecord.type, structRecord.fullPath, id, Date );
	UpdateRecord( tempStrVal );
}

void Main_Window::InitTable()
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
	
	QFont font ("Bookman Old Style", 11 );
	font.setBold( true );

	QStandardItem* itemHorizontalName = new QStandardItem();
	tableModel->setHorizontalHeaderItem( 0, itemHorizontalName );
	itemHorizontalName->setFont( font );
	tableModel->setHeaderData( 0, Qt::Horizontal, "Имя файла" );

	QStandardItem* itemHorizontalType = new QStandardItem();
	tableModel->setHorizontalHeaderItem( 1, itemHorizontalType );
	itemHorizontalType->setFont( font );
	tableModel->setHeaderData( 1, Qt::Horizontal, "Тип файла" );

	QStandardItem* itemHorizontalDate = new QStandardItem();
	tableModel->setHorizontalHeaderItem( 2, itemHorizontalDate );
	itemHorizontalDate->setFont( font );
	tableModel->setHeaderData( 2, Qt::Horizontal, "Дата добавления" );

	QStandardItem* itemHorizontalPath = new QStandardItem();
	tableModel->setHorizontalHeaderItem( 3, itemHorizontalPath );
	itemHorizontalPath->setFont( font );
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

			QStandardItem* itemFileName = new QStandardItem();
			QList< QPair< QString, int> > dataFileName = { { record.FileName.toString(), 0 } };
			itemFileName->setData( dataFileName[0].first, Qt::DisplayRole );
			itemFileName->setTextAlignment( Qt::AlignCenter );

			QStandardItem* itemType = new QStandardItem();
			QList< QPair< QString, int> > dataType = { { record.Type_document.toString(), 0 } };
			itemType->setData( dataType[0].first, Qt::DisplayRole );
			itemType->setEditable( false );
			itemType->setTextAlignment( Qt::AlignCenter );

			QStandardItem* itemDate = new QStandardItem();
			QList< QPair< QString, int> > dataDate = { { record.Date.toString(), 0 } };
			itemDate->setData( dataDate[0].first, Qt::DisplayRole );
			itemDate->setTextAlignment( Qt::AlignCenter );

			if( j == 0 ) { tableModel->setItem( index.row(), index.column(), itemFileName ); }
			if( j == 1 ) { tableModel->setItem( index.row(), index.column(), itemType ); }
			if( j == 2 ) { tableModel->setItem( index.row(), index.column(), itemDate ); }
			if( j == 3 ) { tableModel->setData( index, record.PathToFile ); }
			if( j == 4 ) { tableModel->setData( index, record.Id ); }
		}
	}
	ui.TableDataFromBD->show();
	ui.TableDataFromBD->hideColumn(4);
	ui.TableDataFromBD->reset();

}

void Main_Window::InitDeleteButtom()
{
	connect( ui.ButtonDelete, &QPushButton::clicked, [=]()
	{
		QModelIndexList selected = ui.TableDataFromBD->selectionModel()->selectedRows();
		QString ID;
		for( auto row : selected ) {
			ID = tableModel->item( row.row(), 4 )->text();
			tableModel->removeRow( row.row() );
		}
		int dec = ID.toInt();
		ui.TableDataFromBD->clearSelection();
		DeleteRecordByIndex( dec );
	} );
}

void Main_Window::InitOpenButtom()
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

void Main_Window::InitAddButtom()
{
	connect( ui.ButtonAdd, &QPushButton::clicked, [=]()
	{
		addW = new Add_Window;
		addW->setWindowTitle( "Окно добавления" );
		addW->InitChoiseFile();
		addW->InitAddTypeButtom();
		addW->show();
		connect( addW, SIGNAL( sendStruct( AddInfo ) ), this, SLOT( recieve( AddInfo ) ) );
	} );
}

void Main_Window::InitShablonButtom()
{
	connect( ui.ShablonButtom, &QPushButton::clicked, [=]()
	{
		ShablonW = new Shablon_Window;
		ShablonW->setWindowTitle( "Окно создания по шаблону" );
		QStringList list = listfilesindir( ShablonW->GetShablonPath() );
		ShablonW->AddShablonsList( list );
		ShablonW->InitChoiseFile();
		ShablonW->InitAddTypeButtom();
		ShablonW->InitButtomOk();
		ShablonW->show();
		connect( ShablonW, SIGNAL( sendStruct( AddInfo ) ), this, SLOT( recieve( AddInfo ) ) );
	} );

}

void Main_Window::InitArhiveButtom()
{
	connect( ui.Arhive, &QPushButton::clicked, [=]()
	{
		QModelIndexList selected = ui.TableDataFromBD->selectionModel()->selectedRows();
		QStringList listName;

		QString CreatedArhivDir = DocumentsPath + "\\arhiv";
		QByteArray ba = CreatedArhivDir.toLocal8Bit();
		const char *c_str2 = ba.data();

		bool resultMk = mkdir( c_str2 );
		QString ID;
		for( auto row : selected ) {
			QString path = tableModel->item( row.row(), 3 )->text();
			QString nameFile = GetNameWithExFromPath( path );
			bool result = CopyFile( path, CreatedArhivDir );
			ID = tableModel->item( row.row(), 4 )->text();
			tableModel->removeRow( row.row() );
		}

		QString command = "7z a -tzip -mx=1 " + ArhivPath + + "\\" +  "archive.zip" + " " + CreatedArhivDir;
		QByteArray ba2 = command.toLocal8Bit();
		const char *c_str22 = ba2.data();
		system( c_str22 );
		QDir dir( CreatedArhivDir );
		dir.removeRecursively();
		int dec = ID.toInt();
		ui.TableDataFromBD->clearSelection();
		DeleteRecordByIndex( dec );
	} );
}

void Main_Window::InitUpdateButtom()
{
	connect( ui.ButtomUpdate, &QPushButton::clicked, [=]()
	{	
		QString Id = -1;
		QString Date;
		QString Name;
		AddInfo updateStruct;
		QModelIndexList selected = ui.TableDataFromBD->selectionModel()->selectedRows();
		if( selected.size() != 0 ) {
			for( auto row : selected ) {
				Id = tableModel->item( row.row(), 4 )->text();
				Date = tableModel->item( row.row(), 2 )->text();
				Name = tableModel->item( row.row(), 0 )->text();
				updateStruct.fullPath = tableModel->item( row.row(), 3 )->text();
				updateStruct.type = tableModel->item( row.row(), 1 )->text();;
			}
			UpdateRecortToTable( updateStruct, Id, Name, Date );
			ui.TableDataFromBD->clearSelection();
		}
	} );
}

void Main_Window::InitRefreshButtom()
{
	connect( ui.RefreshButtom, &QPushButton::clicked, [=]()
	{
		InitTable();
	} );
}

void Main_Window::InitFindButtom()
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

Main_Window::Main_Window( QWidget *parent ) : QMainWindow( parent )
{
	ui.setupUi( this );
	this->statusBar()->setSizeGripEnabled( false );
	setWindowFlags( Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint );
	QPixmap pixmap( "Suport//refresh.png" );
	QIcon ButtonIcon( pixmap );
	ui.RefreshButtom->setIcon( ButtonIcon );
	ui.RefreshButtom->setIconSize( ui.RefreshButtom->size() );
}

Main_Window::~Main_Window()
{
	//delete addW;
}

void Main_Window::recieve( AddInfo structRecord )
{
	AddNewRecortToTable( structRecord );
}