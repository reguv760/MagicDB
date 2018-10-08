#pragma once

#include <string>
#include <vector>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QVariant>
#include "sqldbrow.h"
#include "request.h"

class Database
{
	private:
		const std::string	SERVER = "ASUS-X751LX\\SQLEXPRESS"; //myComputer name:::
		const int			PORT_NUMBER = 1433;

		const QString DATABASE_DRIVER = "QODBC3";

		//SQL Connection
		const std::string USER_NAME					= "magic";
		const std::string PASSWORD					= "magic";
		const std::string ODBC_NAME					= "magic.dsn"; 	

		//OOP Composition::: Database HAS a connection
		QSqlDatabase connection;

		//helper function:::

		bool connect();
		void disconnect();

	public:
		Database();
		~Database();


		const std::string DATABASE_NAME = "magic";

		//MS SQL Server table names must be prefixed with dbo.
		const std::string CARD_SETS_TABLE_NAME = "dbo.card_sets"; //dbo. used by MS SQL
		const std::string CARD_SETS_TYPES_NAME = "dbo.card_types";
		const std::string CARD_SETS_SUBTYPES_NAME = "dbo.card_subtypes";
		const std::string SETS_TABLE_NAME = "dbo.sets";
		const std::string MANA_TABLE_NAME = "dbo.mana";

		std::vector<SQLDBRow> retrieveRows(Request& request);
};