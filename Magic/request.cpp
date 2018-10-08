#include "request.h"

Request::Request()
{
}


Request::~Request()
{
}

void Request::addTableName(std::string tableName)
{
	tableNames.emplace_back(tableName);
}

std::vector<std::string> Request::getTableNames() const
{
	return tableNames;
}

std::string Request::getDBName() const
{
	return databaseName;
}

void Request::setDBName(std::string newDBName)
{
	this->databaseName = newDBName;
}