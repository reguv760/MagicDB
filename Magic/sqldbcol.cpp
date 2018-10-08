#include "sqldbcol.h"


SQLDBCol::SQLDBCol(std::string name, QVariant value)
{
	this->name = name;
	this->value = value;
}


SQLDBCol::~SQLDBCol()
{

}


std::string SQLDBCol::getName() const
{
	return name;
}

QVariant SQLDBCol::getValue() const
{
	return value;
}