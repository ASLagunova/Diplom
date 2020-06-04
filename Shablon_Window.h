#pragma once
#include <QtWidgets/QMainWindow>
#include <Qstandarditemmodel.h>
#include "ui_Shablon.h"
#include "qfiledialog.h"
#include "SaportFoo.h"

class Shablon_Window : public QDialog
{
	Q_OBJECT

signals:
	void sendStruct( AddInfo structInfo );

public:

	explicit Shablon_Window( QWidget *parent = 0 );
	~Shablon_Window();

	QString GetShablonPath();
	QString GetDocumentsPath();
	void AddShablonsList( QStringList list );

	void InitChoiseFile();
	void InitAddTypeButtom();
	void InitButtomOk();
private:
	QStringList	listTypeDoc;
	AddInfo structInfo;
	QString SablonsPath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\Шаблоны";
	QString DocumentsPath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\Документы";
	QString AllTypePath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\AllTypes.txt";
	QStringList ShablonsList;
	Ui::Shablon_Window *ui;
};

