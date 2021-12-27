#include "Student.h"

Student::Student(int studId, string studName, int studAge,string password)
{
	this->studId = studId;
	this->studName = studName;
	this->studAge = studAge;
	this->password = password;
}

void Student::setStudId(int studId)
{
	this->studId = studId;
}
int Student::getStudId()
{
	return this->studId;
}

void Student::setStudName(string studName)
{
	this->studName = studName;
}
string Student::getStudName()
{
	return this->studName;
}

void Student::setStudAge(int studAge)
{
	this->studAge = studAge;
}
int Student::getStudAge()
{
	return this->studAge;
}

void Student::setPassword(string password)
{
	this->password = password;
}
string Student::getPassword()
{
	return this->password;
}

string Student::description()
{
	string text = "";

	text += "Stud Id: " + to_string(this->studId) + "\n";
	text += "Student Name: " + this->studName + "\n";
	text += "Student Age: " + to_string(this->studAge) + "\n";
	text += "Password" + this->password + "\n";

	return text;
}

string Student::toSave()
{
	string text = "";

	text += to_string(this->studId) + " ";
	text += this->studName + " ";
	text += to_string(this->studAge) + " ";
	text += this->password;

	return text;
}

