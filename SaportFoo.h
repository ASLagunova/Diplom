#pragma once
#include <string>
#include <ctime>
#include "Qstring"
#include "QStringList"
#include <QFile>
#include <qdir.h>

struct AddInfo
{
	QString fullPath;
	QString type;
};

using namespace std;
string intTransferStr( int number );
QString GetNowTimeDate();
QString GetNameFromPath( QString path );
QString GetNameWithExFromPath( QString path );
bool CopyFile( QString pathFrom, QString pathTo );
QStringList listfilesindir( QString path );
QStringList ListStrInFiles( QString pathToFile );