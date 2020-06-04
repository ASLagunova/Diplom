#pragma once

#include <QtWidgets/QMainWindow>
#include <Qstandarditemmodel.h>
#include "ui_Diplom_Work.h"
#include "AddWindow.h"
#include "Shablon.h"
#include "MySQLAppliy.h"
#include "SaportFoo.h"

class Diplom_Work : public QMainWindow
{
	Q_OBJECT

public slots:
	void recieve( AddInfo str );

public:
	Diplom_Work(QWidget *parent = 0);
	~Diplom_Work();
	void InitTable();
	void InitOpenButtom();
	void InitDeleteButtom();
	void InitAddButtom();
	void InitShablonButtom();
	void InitArhiveButtom();
	void InitFindButtom();

	void AddNewRecortToTable( AddInfo structRecord );

private:
	QString fullPath;
	QString Type;
	Dialog *addW;
	DialogShablon *ShablonW;
	Ui::Diplom_WorkClass ui;
	QStandardItemModel *tableModel;
	QString DocumentsPath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\Документы";
	QString ArhivPath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\Архив";
};

