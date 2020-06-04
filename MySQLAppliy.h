#pragma once
#include "ui_Diplom_Work.h"
#include <iostream>
#include <tchar.h>
#include "windowsx.h"
#include "Qstring"
#include <vector>
#include <algorithm>
#include "SaportFoo.h"
#include <qsqldatabase.h>
#include <qdebug.h>;

using namespace std;

void QTConnectToBD();

QString CreateRequestIntoBDAddRecord( QString Name, QString Type, QString date, QString PathToFile );

struct InfoAboutBD
{
	int countColomn;
	int countRow;
};

struct recordBd
{
	QVariant Id;
	QVariant FileName;
	QVariant Type_document;
	QVariant Date;
	QVariant PathToFile;
	QVariant resultStr;
};

vector<int> GetAllIDFromDB();
void InsertRecord( QString str );
void DeleteRecordByIndex( int index );
recordBd GetRecordByIndex(int index);

InfoAboutBD GetInfoAboutBD();