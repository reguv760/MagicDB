#pragma once

#include <string>
#include <vector>

class Request
{
	private:
		std::string				databaseName;
		std::vector<std::string> tableNames;

	public:
		Request();
		~Request();

		void addTableName(std::string tableName);
		std::vector<std::string> getTableNames() const;

		std::string getDBName() const;
		void setDBName(std::string newDBName);
};

