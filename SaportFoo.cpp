#include "SaportFoo.h"
#include <fstream>

string intTransferStr( int number )
{
	unsigned char digitCounter = 0;

	int *buff = new int;
	*buff = number;
	while( *buff != 0 ) {
		digitCounter++;
		*buff /= 10;
	}
	delete buff;

	char *buffer = new char[digitCounter];
	itoa( number, buffer, 10 );

	string result = "";
	for( unsigned char i = 0; i < digitCounter; i++ ) {
		result += buffer[i];
	}

	return result;
}

QString GetNowTimeDate()
{
	time_t now = time( 0 );
	tm *ltm = localtime( &now );

	QString day = QString::number( ltm->tm_mday );
	QString month = QString::number( ltm->tm_mon + 1 );
	QString year = QString::number( ltm->tm_year + 1900 );
	QString date = day + "." + month + "." + year;
	return date;
}

QString GetNameFromPath( QString path )
{
	QStringList dropLstOne = path.split( "/" );
	int si = dropLstOne.count();
	if( si == 1 ) {
		dropLstOne.clear();
		dropLstOne = path.split( '\\' );
	}
	QString nameWithEx = dropLstOne[dropLstOne.count() - 1];
	QStringList dropLstTwo = nameWithEx.split( "." );
	QString name = dropLstTwo[0];

	return name;
}

QString GetNameWithExFromPath( QString path )
{
	QStringList dropLstOne = path.split( "/" );
	int si = dropLstOne.count();
	if( si == 1 ) {
		dropLstOne.clear();
		dropLstOne = path.split( '\\' );
	}
	QString nameWithEx = dropLstOne[dropLstOne.count() - 1];

	return nameWithEx;
}

bool CopyFile( QString pathFrom, QString pathTo )
{
	QStringList dropLstOne = pathFrom.split( "/" );
	QString nameWithEx = dropLstOne[dropLstOne.count() - 1];
	QString pathtoFIle = pathTo + "\\" + nameWithEx;
	bool result = QFile::copy( pathFrom, pathtoFIle );
	return result;
}

QStringList listfilesindir( QString path )
{
	/*
	Функция считывает список файлов (включая скрытые) в директории в QString.
	Входные параметры:
	 path - путь к папке.
	Возвращаемое значение:
	 Строка со списком файлов в директории, разделенные n в алфавитном порядке.
	*/
	QStringList line;
	QDir dir( path );
	bool ok = dir.exists();
	if( ok ) {
		dir.setFilter( QDir::Files | QDir::Hidden | QDir::NoSymLinks );
		dir.setSorting( QDir::Name );
		QFileInfoList list = dir.entryInfoList();

		for( int i = 0; i < list.size(); ++i ) {
			QFileInfo fileInfo = list.at( i );
			line.append(fileInfo.fileName());
		}
	}
	return line;
}

QStringList ListStrInFiles( QString pathToFile )
{
	QFile file( pathToFile );
	QStringList list;

	if( ( file.exists() ) && ( file.open( QIODevice::ReadOnly ) ) ) {
		QString str = "";
		while( !file.atEnd() ) {
				str = file.readLine();
				if( str[0] != '#' )
				{
				str.chop( 2 );
				int a = str.length();
				list.append( str );
				}
		}
		file.close();
		return list;
	}
}