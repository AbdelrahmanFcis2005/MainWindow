#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;
User::User()
{
	name = "";
	email = "";
	password = "";
}
User::User(string name, string email, string password)
{
	this->name = name;
	this->email = email;
	this->password = password;
}
User::~User()
{
}
QString User::getName()
{
	return QString::fromStdString(name);
}
QString User::getEmail()
{
	return QString::fromStdString(email);
}
QString User::getPassword()
{
	return QString::fromStdString(password);
}
void User::setName(QString name)
{
	this->name = name.toStdString();
}
void User::setEmail(QString email)
{
	this->email = email.toStdString();
}
void User::setPassword(QString password)
{
	this->password = password.toStdString();
}
void User::writeToFile(string fileName)
{
	ofstream file(fileName);
	if (file.is_open())
	{
		file << name << endl;
		file << email << endl;
		file << password << endl;
		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}
void User::readFromFile(string fileName, User &user)
{
	ifstream file(fileName);
	string name, email, password;
	if (file.is_open())
	{
		getline(file, name);
		getline(file, email);
		getline(file, password);
		file.close();
	}
	else
	{
		cout << "Unable to open file";
	}
	user.setName(QString::fromStdString(name));
	user.setEmail(QString::fromStdString(email));
	user.setPassword(QString::fromStdString(password));
}
