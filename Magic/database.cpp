#include "database.h"
#include "request.h"

Database::Database()
{
	connection = QSqlDatabase::addDatabase(DATABASE_DRIVER);
}


Database::~Database()
{

}


bool Database::connect()
{
	//fill up connection values
	connection.setHostName(QString::fromStdString(SERVER)); //QSql expects QString:::
	connection.setPort(PORT_NUMBER);
	connection.setDatabaseName(QString::fromStdString(ODBC_NAME));

	//connection.set
	connection.setUserName(QString::fromStdString(USER_NAME));
	connection.setPassword(QString::fromStdString(PASSWORD));

	return connection.open();
}

void Database::disconnect()
{
	connection.close();
}


std::vector<SQLDBRow> Database::retrieveRows(Request& request)
{
	std::vector<SQLDBRow> rows;

	if (connect())
	{
		std::string query = "SELECT * FROM "; //last space needed to concatenate strings for query:::
		std::string databaseName = request.getDBName();
		std::vector<std::string> tableNames = request.getTableNames();

		/* for (int i = 0; i < tableNames.size(); i++)
		{
		tablesNames[i];
		//rows[i] = tableNames[i];
		//tableRequest.getTableNames()[i];
		} */

		//for_each(tableNames.begin(), tableNames.end(), getTableName);
		//for_ach

		//for (std::string tableName : tableNames) 
		//{
		//}

		//for (std::vector<std::string>::iterator it = tableNames.begin(), it ! = tableNames.end(); ++iterator)

		//cycle tablenames:::
		for (const std::string &tableName : tableNames)
		{
			//queryTabl = 
			query += databaseName + "." + tableName + ", ";

			//newer concat but must call 4X to perform above concat:::
			//query.append(databaseName + "." + tableName + ", ");

		}
		query = query.substr(0, query.size() - 2);

		//declare QSql query:
		QSqlQuery dbQuery;

		//Add SQL prep statement and convert to QString:::
		dbQuery.prepare(QString::fromStdString(query));
		
		if (dbQuery.exec())
		{
			QSqlRecord row		= dbQuery.record();
			const int colCount	= row.count();

			while (dbQuery.next())
			{
				SQLDBRow sqlDBRow;

				for (int col = 0; col < colCount; col++)
				{
					const std::string colName = row.fieldName(col).toStdString();
					//SQLDBRow.addCol(colName, dbQuery.value(col))

					//Long way::
					
					//QVariant variant = dbQuery.value(col);
					
					//void* value = variant.value<void*>();

					//if (variant.canConvert()::
					//generic value:::
					//sqlDBRow.addCol(colName, dbQuery.value(col).value<void*>());
					sqlDBRow.addCol(colName, dbQuery.value(col));
				}

				rows.emplace_back(sqlDBRow);
			}
		}

		disconnect();
	}

	return rows;
} 