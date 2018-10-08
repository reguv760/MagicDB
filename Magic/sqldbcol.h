#pragma once
#include <string>
#include <QVariant>

class SQLDBCol
{
	private:
		std::string		name;
		QVariant		value; //void* acts as a generic pointer for any data type = Java Object class

	public:
		SQLDBCol(std::string name, QVariant value);
		~SQLDBCol();

		std::string		getName() const;
		QVariant		getValue() const;
};

