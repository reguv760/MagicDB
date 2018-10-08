#pragma once

#include "sqldbcol.h"
#include <vector>
#include <string>
#include <QVariant>

class SQLDBRow
{
	private:
		std::vector<SQLDBCol> cols; //changes from row:::

	public:
		SQLDBRow();
		~SQLDBRow();

		//getter:::

		std::vector<SQLDBCol> getCols() const;
		//setter
		void addCol(std::string name, QVariant value);
};

