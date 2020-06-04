#pragma once
#include <QtWidgets/QMainWindow>
#include <Qstandarditemmodel.h>
#include "ui_AddWondow.h"
#include "qfiledialog.h"
#include "SaportFoo.h"


class Dialog : public QDialog
{
	Q_OBJECT

signals:
	void sendStruct( AddInfo structInfo );

private slots:
	void onButtonSend();

public:
	explicit Dialog( QWidget *parent = 0 );
	~Dialog();

	void InitChoiseFile();
	void InitAddTypeButtom();
	void InitStruct();
private:
	
	Ui::Dialog *ui;
	QStandardItemModel *tableModel;
	QStringList listTypeDoc;
	AddInfo structInfo;
	QString AllTypePath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\AllTypes.txt";
};
