#include "Rent.h"

Rent::Rent(int id, int studentId, int bookId, string studentName, int studentAge)
{
	this->id = id;
	this->studentId = studentId;
	this->bookId = bookId;
	this->studentName = studentName;
	this->studentAge = studentAge;
}

void Rent::setId(int id)
{
	this->id = id;
}
int Rent::getId()
{
	return this->id;
}

void Rent::setStudentId(int studentId)
{
	this->studentId = studentId;
}
int Rent::getStudentId()
{
	return this->studentId;
}

void Rent::setBookId(int bookId)
{
	this->bookId = bookId;
}
int Rent::getBookId()
{
	return this->bookId;
}

void Rent::setStudentName(string studentName)
{
	this->studentName = studentName;
}
string Rent::getStudentName()
{
	return this->studentName;
}

void Rent::setStudentAge(int studentAge)
{
	this->studentAge = studentAge;
}
int Rent::getStudentAge()
{
	return this->studentAge;
}

string Rent::description()
{
	string text = "";

	text += "Rent Id: " + to_string(this->id) + "\n";
	text += "Student Id: " + to_string(this->studentId) + "\n";
	text += "Book Id: " + to_string(this->bookId) + "\n";
	text += "Student Name: " + this->studentName + "\n";
	text += "Student Age: " + to_string(this->studentAge) + "\n";
	
	return text;
}

string Rent::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += to_string(this->studentId) + " ";
	text += to_string(this->bookId) + " ";
	text += this->studentName + " ";
	text += to_string(this->studentAge);

	return text;
}
