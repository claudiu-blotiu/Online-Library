#include "Horror.h"

Horror::Horror(string ageRestrict,int id, string name, int price) :Books(id,name, "Horror", price)
{
	this->ageRestrict = ageRestrict;
}

void Horror::setAgeRestrict(string ageRestrict)
{
	this->ageRestrict = ageRestrict;
}
string Horror::getAgeRestrict()
{
	return this->ageRestrict;
}

string Horror::description()
{
	string text = Books::description();

	text += "Age Restrict: " + this->ageRestrict + "\n";

	return text;
}

string Horror::toSave()
{
	string text = "";

	text += to_string(this->getId()) + " ";
	text += this->getName() + " ";
	text += this->getType() + " ";
	text += this->ageRestrict + " ";
	text += to_string(this->getPrice());

	return text;
}
