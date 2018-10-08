#include "sqldbrow.h"

SQLDBRow::SQLDBRow()
{
}


SQLDBRow::~SQLDBRow()
{
}

void SQLDBRow::addCol(std::string name, QVariant value)
{
	cols.emplace_back(SQLDBCol(name, value));
}


std::vector<SQLDBCol> SQLDBRow::getCols() const
{
	return cols;
}