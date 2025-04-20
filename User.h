#pragma once
#include <string>
#include <qstring.h>
using namespace std;
class User
{
public:
	User();
	User(string name, string email, string password);
	~User();
	QString getName();
	QString getEmail();
	QString getPassword();
	void setName(QString name);
	void setEmail(QString email);
	void setPassword(QString password);
	void writeToFile(string fileName);
	static void readFromFile(string fileName, User &user);


private:
	string name;
	string email;
	string password;
};

