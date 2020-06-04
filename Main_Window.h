#pragma once

#include <QtWidgets/QMainWindow>
#include <Qstandarditemmodel.h>
#include "ui_Diplom_Work.h"
#include "AddWindow.h"
#include "Shablon_Window.h"
#include "MySQLAppliy.h"
#include "SaportFoo.h"

class Main_Window : public QMainWindow
{
	Q_OBJECT

public slots:
	void recieve( AddInfo str );

public:
	Main_Window(QWidget *parent = 0);
	~Main_Window();
	void InitTable();
	void InitOpenButtom();
	void InitDeleteButtom();
	void InitAddButtom();
	void InitUpdateButtom();
	void InitShablonButtom();
	void InitArhiveButtom();
	void InitFindButtom();
	void InitRefreshButtom();

	void AddNewRecortToTable( AddInfo structRecord );
	void UpdateRecortToTable( AddInfo structRecord, QString id, QString Name, QString Date );



private:
	QString fullPath;
	QString Type;
	Add_Window *addW;
	Shablon_Window *ShablonW;
	Ui::Main_Window ui;
	QStandardItemModel *tableModel;
	QString DocumentsPath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\Документы";
	QString ArhivPath = "C:\\Users\\AEganov\\Source\\Repos\\AlexanderEganov\\DiplomWork_Lagunova\\Архив";
};

