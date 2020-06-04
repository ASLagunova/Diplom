#include "Shablon_Window.h";

Shablon_Window::Shablon_Window( QWidget *parent ) : ui( new Ui::Shablon_Window )
{
	ui->setupUi( this );
	setAttribute( Qt::WA_DeleteOnClose, true );
	setWindowFlags( Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint );
	QStringList listTypeDoc = ListStrInFiles( AllTypePath );
	ui->comboBox_2->addItems( listTypeDoc );

	QPixmap pixmapPluss( "Suport//Plass.png" );
	QIcon ButtonIconPluss( pixmapPluss );
	ui->AddType->setIcon( ButtonIconPluss );
	ui->AddType->setIconSize( ui->AddType->size() );

	QPixmap pixmapFolder( "Suport//folder.png" );
	QIcon ButtonIconFolder( pixmapFolder );
	ui->choiseButtom->setIcon( ButtonIconFolder );
	ui->choiseButtom->setIconSize( ui->choiseButtom->size() );

}

Shablon_Window::~Shablon_Window()
{


}

void Shablon_Window::InitChoiseFile()
{
	connect( ui->choiseButtom, &QPushButton::clicked, [=]()
	{   QString fullPath;
		QString fileName = QFileDialog::getOpenFileName( this,
			QString::fromUtf8( "ќткрыть файл" ),
			QDir::currentPath(),
			"Ishodnye_danniye (*.txt);;All files (*.*)" );
		fullPath = fileName;
		QString NameFile = GetNameFromPath( fullPath );
		ShablonsList.append( NameFile );
		ui->comboBox->addItems( ShablonsList );
		bool result = CopyFile( fullPath, SablonsPath );
	} );
}

void Shablon_Window::InitButtomOk()
{
	connect( ui->okButton, &QPushButton::clicked, [=]()
	{ 
		QString ChoisenType = ui->comboBox->currentText();
		QString ChoisenName = ui->lineEdit->text();

		QStringList AllFiles = listfilesindir( SablonsPath );

		QString FullName = "None";
		QString Rasshirenie = "None";

		for( int i = 0; i < AllFiles.count(); i++ ) {
			QString CurrentName = AllFiles[i];
			int c = CurrentName.indexOf( ChoisenType, 0 );
			if( c == 0 )
			{
				FullName = AllFiles[i];
				QStringList supList = FullName.split( "." );
				Rasshirenie = supList[1];
			}
		}
		if( FullName != "None" ) 
		{
			QString PathFromFile = SablonsPath + "\\" + FullName;
			QString PathToFile = DocumentsPath + "\\" + ChoisenName + "." + Rasshirenie;
			bool result = QFile::copy( PathFromFile, PathToFile );
			if( result ) 
			{
				structInfo.fullPath = PathToFile;
				structInfo.type = ui->comboBox_2->currentText();
			}
		}
		emit sendStruct( structInfo );

	} );
}


QString Shablon_Window::GetShablonPath()
{
	return SablonsPath;
}

QString Shablon_Window::GetDocumentsPath()
{
	return DocumentsPath;
}

void Shablon_Window::InitAddTypeButtom()
{
	connect( ui->AddType, &QPushButton::clicked, [=]()
	{
		QByteArray ba = AllTypePath.toLocal8Bit();
		const char *c_str2 = ba.data();
		system( c_str2 );
	} );
}

void Shablon_Window::AddShablonsList( QStringList list )
{
	ui->comboBox->addItems( list );
}