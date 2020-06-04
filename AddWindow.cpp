#include "AddWindow.h"

Dialog::Dialog( QWidget *parent ) : ui( new Ui::Dialog )
{
	ui->setupUi( this );
	setAttribute( Qt::WA_DeleteOnClose, true );

	QStringList listTypeDoc = ListStrInFiles( AllTypePath );

	ui->comboBox->addItems( listTypeDoc );
	connect( ui->okButton, SIGNAL( clicked() ), this, SLOT( onButtonSend() ) );
}

Dialog::~Dialog()
{

}

void Dialog::InitStruct( )
{
	structInfo.fullPath = ui->lineEdit->text();
	structInfo.type = ui->comboBox->currentText();
}

void Dialog::InitChoiseFile()
{
	connect( ui->choiseFile, &QPushButton::clicked, [=]()
	{
		QString fileName = QFileDialog::getOpenFileName( this,
			QString::fromUtf8( "Открыть файл" ),
			QDir::currentPath(),
			"Ishodnye_danniye (*.txt);;All files (*.*)" );
		ui->lineEdit->setText( fileName );
	} );
}

void Dialog::InitAddTypeButtom()
{
	connect( ui->AddType, &QPushButton::clicked, [=]()
	{
		QByteArray ba = AllTypePath.toLocal8Bit();
		const char *c_str2 = ba.data();
		system( c_str2 );
	} );
}

void Dialog::onButtonSend()
{
	InitStruct();
	//emit InitStruct();
	emit sendStruct( structInfo );
}
