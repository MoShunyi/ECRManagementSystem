#pragma once
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
class SqlDatabase
{
public:
	SqlDatabase(void);
	~SqlDatabase(void);
	
	void InitSql();
	bool ConnectDatabase();
	bool LoginCheck(QString userName, QString password);
	void QueryData(QString sql, QSqlQuery *pQuery);
	bool InsertData(QString sql);

private:
	QSettings *config;
	QSqlDatabase accessDB;
	QString accessDatabaseDir;
	QString accessDatabaseUID;
	QString accessDatabasePWD;
};

