#include "Books.h"

Books::Books(int id,string name, string type, int price)
{
	this->id = id;
	this->name = name;
	this->type = type;
	this->price = price;
}

void Books::setId(int id)
{
	this->id = id;
}
int Books::getId()
{
	return this->id;
}

void Books::setName(string name)
{
	this->name = name;
}
string Books::getName()
{
	return this->name;
}

void Books::setType(string type)
{
	this->type = type;
}
string Books::getType()
{
	return this->type;
}

void Books::setPrice(int price)
{
	this->price = price;
}
int Books::getPrice()
{
	return this->price;
}

string Books::description()
{
	string text = "";

	text += "Book Id: "+to_string(this->id) + "\n";
	text += "Name: " + this->name + "\n";
	text += "Type: " + this->type + "\n";
	text += "Price: " + to_string(this->price) + "\n";

	return text;
}

string Books::toSave()
{
	string text = "";

	text += to_string(this->id) + " ";
	text += this->name + " ";
	text += this->type + " ";
	text += to_string(this->price);

	return text;
}
