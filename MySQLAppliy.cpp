#include "MySQLAppliy.h"
#include <qsqlerror.h>
#include <qsqldriver.h>;
#include <mysql.h>

QString CreateRequestIntoBDAddRecord( QString Name, QString Type, QString date, QString PathToFile )
{
	QStringList dropLstOne = PathToFile.split( '\\' );
	int si = dropLstOne.count();
	if( si > 1 ) {
		dropLstOne.clear();
		PathToFile = PathToFile.replace( '\\','/' );
	}

	QString strCmd = "INSERT INTO Table_Files (File_Name, Type_document, DateCreate, PathToFile) VALUES(\'"
		+ Name + "\',\'"+ Type + "\',\'" + date + "\',\'" + PathToFile + "\');";

	return strCmd;
}

void DeleteRecordByIndex( int index )
{
	system( "cls" );
	MYSQL_RES* res;
	MYSQL_ROW row;
	recordBd result;
	wstring resultStr;
	char* strLast = new char;
	int i = 0;
	const char*st;
	MYSQL* conn;
	conn = mysql_init( NULL );
	if( conn == NULL ) {
		fprintf( stderr, "Error: can'tcreate MySQL-descriptor\n" );
	}
	if( !mysql_real_connect( conn, "localhost", "root", "12345678", "Acreditatciya", 3306, NULL, NULL ) ) {
		fprintf( stderr, "Error: can'tconnecttodatabase %s\n", mysql_error( conn ) );
	}
	else {
		fprintf( stdout, "Success!\n" );
	}
	mysql_set_character_set( conn, "utf8" );
	cout << "connectioncharacterset: " << mysql_character_set_name( conn ) << endl;

	string strIndex = intTransferStr( index );
	string strCmd = "DELETE FROM Table_Files WHERE id = ";
	strCmd = strCmd + strIndex;
	const char *ch = new char[strCmd.length()];
	ch = strCmd.c_str();

	mysql_query( conn, ch );
	//mysql_close( conn );
}

void InsertRecord( QString str )
{
	system( "cls" );
	MYSQL_RES* res;
	MYSQL_ROW row;
	InfoAboutBD result;
	int i = 0;
	const char*st;
	MYSQL* conn;
	
	conn = mysql_init( NULL );
	if( conn == NULL ) {
		fprintf( stderr, "Error: can'tcreate MySQL-descriptor\n" );
	}
	if( !mysql_real_connect( conn, "localhost", "root", "12345678", "Acreditatciya", 3306, NULL, NULL ) )
	{
		
		fprintf( stderr, "Error: can'tconnecttodatabase %s\n", mysql_error( conn ) );
	}
	else {
		fprintf( stdout, "Success!\n" );
	}
	mysql_set_character_set( conn, "cp1251" );

	mysql_query( conn, "SET NAMES cp1251" );
	cout << "connectioncharacterset: " << mysql_character_set_name( conn ) << endl;
	st = mysql_error( conn );

	QByteArray ba = str.toLocal8Bit();
	const char *c_str2 = ba.data();

	if( !mysql_ping( conn ) )
	{
		fprintf( stderr, "Error: can'tcreate MySQL-descriptor\n" );
	}

	mysql_query( conn, c_str2 ); //Делаем запрос к таблице по имени Table_Files =)
	st = mysql_error( conn );

	//mysql_close( conn );
}

recordBd GetRecordByIndex(int index)
{
    system("cls");
    MYSQL_RES* res;
    MYSQL_ROW row;
    recordBd result;
    wstring resultStr;
    char* strLast = new char;
    int i = 0;

    MYSQL* conn;
    // Получаем дескриптор соединения
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        // Если дескриптор не получен – выводим сообщение об ошибке
        fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
        //exit(1); //Если используется оконное приложение
    }
    // Подключаемся к серверу
    if (!mysql_real_connect(conn, "localhost", "root", "12345678", "Acreditatciya", 3306, NULL, NULL))
    {
        // Если нет возможности установить соединение с сервером
        // базы данных выводим сообщение об ошибке
        fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(conn));
    }
    else
    {
        // Если соединение успешно установлено выводим фразу - "Success!"
        fprintf(stdout, "Success!\n");
    }
    // Закрываем соединение с сервером базы данных

    mysql_set_character_set(conn, "utf8");
    //Смотрим изменилась ли кодировка на нужную, по умалчанию идёт latin1
    cout << "connectioncharacterset: " << mysql_character_set_name(conn) << endl;

	string strIndex = intTransferStr( index );

	string strCmd = "SELECT * FROM Table_Files WHERE id = ";
	strCmd = strCmd + strIndex;
	const char *ch = new char[strCmd.length()];
	ch = strCmd.c_str();

    mysql_query(conn, ch ); //Делаем запрос к таблице по имени Table_Files =)

    if (res = mysql_store_result(conn)) {
        while (row = mysql_fetch_row(res)) {
            for (i = 0; i < mysql_num_fields(res); i++) {
                strLast = row[i];
				if( i == 0 ) { result.Id = row[i]; }
				if( i == 1 ) { result.FileName = row[i]; }
				if( i == 2 ) { result.Type_document = row[i]; }
				if( i == 3 ) { result.Date = row[i]; }   
				if( i == 4 ) { result.PathToFile = row[i]; }
            }
        }
    }
    else
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
    }
   // mysql_close(conn);
    return result;
}

InfoAboutBD GetInfoAboutBD()
{
	system( "cls" );
	MYSQL_RES* res;
	MYSQL_ROW row;
	InfoAboutBD result;
	int i = 0;

	MYSQL* conn;
	// Получаем дескриптор соединения
	conn = mysql_init( NULL );
	if( conn == NULL ) {
		// Если дескриптор не получен – выводим сообщение об ошибке
		fprintf( stderr, "Error: can'tcreate MySQL-descriptor\n" );
		//exit(1); //Если используется оконное приложение
	}
	// Подключаемся к серверу
	if( !mysql_real_connect( conn, "localhost", "root", "12345678", "Acreditatciya", 3306, NULL, NULL ) ) {
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке
		fprintf( stderr, "Error: can'tconnecttodatabase %s\n", mysql_error( conn ) );
	}
	else {
		// Если соединение успешно установлено выводим фразу - "Success!"
		fprintf( stdout, "Success!\n" );
	}
	// Закрываем соединение с сервером базы данных

	mysql_set_character_set( conn, "utf8" );
	//Смотрим изменилась ли кодировка на нужную, по умалчанию идёт latin1
	cout << "connectioncharacterset: " << mysql_character_set_name( conn ) << endl;

	string strCmd = "SELECT * FROM Table_Files";
	const char *ch = new char[strCmd.length()];
	ch = strCmd.c_str();

	mysql_query( conn, ch ); //Делаем запрос к таблице по имени Table_Files =)
	res = mysql_store_result( conn );

	result.countColomn = mysql_num_fields( res );
	result.countRow = mysql_num_rows( res );

	return result;
}

void QTConnectToBD()
{
	//QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL", "connection" );

	//db.setDatabaseName( "Acreditatciya" );
	QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );
	db.setDatabaseName( "acreditatciya" );

	db.setUserName( "sasha" );
	db.setHostName( "localhost" );
	db.setPassword( "12345678" );
	db.setPort( 3306 );

	bool b = db.open();
	if( !db.open() ) {
		cout << "hellp";
	}
	QStringList dr = db.drivers();
	
	QString a = dr[0];
	QString a1 = dr[1];
	QString a2 = dr[2];
	QString a3 = dr[3];
	QString a4 = dr[4];
	QString str = db.lastError().text();
	qDebug() << db.lastError().text();
}

vector<int> GetAllIDFromDB()
{
	system( "cls" );
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL* conn;
	vector<int> CollectionID;

	conn = mysql_init( NULL );
	if( conn == NULL ) {
		fprintf( stderr, "Error: can'tcreate MySQL-descriptor\n" );
	}
	if( !mysql_real_connect( conn, "localhost", "root", "12345678", "Acreditatciya", 3306, NULL, NULL ) ) {
		fprintf( stderr, "Error: can'tconnecttodatabase %s\n", mysql_error( conn ) );
	}
	else {
		fprintf( stdout, "Success!\n" );
	}
	mysql_set_character_set( conn, "utf8" );
	cout << "connectioncharacterset: " << mysql_character_set_name( conn ) << endl;

	string strCmd = "SELECT * FROM Table_Files";
	const char *ch = new char[strCmd.length()];
	ch = strCmd.c_str();

	mysql_query( conn, ch ); //Делаем запрос к таблице по имени Table_Files =)

	char * strLast;
	if( res = mysql_store_result( conn ) ) {
		while( row = mysql_fetch_row( res ) ) {
			for( int i = 0; i < mysql_num_fields( res ); i++ ) {
				strLast = row[i];
				if( i == 0 ) 
				{ 
					int id = atoi( strLast );
					CollectionID.push_back( id );
				}
			}
		}
	}
	else {
		fprintf( stderr, "%s\n", mysql_error( conn ) );
	}
	//mysql_close( conn );

	sort( CollectionID.begin(), CollectionID.end() );
	return CollectionID;
}