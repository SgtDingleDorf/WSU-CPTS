#include "Listnode.h"



Listnode::Listnode()
{
	nextptr = nullptr;
	Record = "";
	idNum = "";
	name = "";
	email = "";
	credits = "";
	program = "";
	level = "";
}


Listnode::~Listnode()
{
}

std::unique_ptr<Listnode> Listnode::getNextPtr()
{
	return std::unique_ptr<Listnode>();
}

void Listnode::setRecord(string &data)
{
	Record = data;
	assert(Record == data);
}

string Listnode::getRecord() const
{
	return Record;
}

void Listnode::setID(string & ID)
{
	idNum = ID;
	assert(idNum == ID);
}

string Listnode::getID() const
{
	return idNum;
}

void Listnode::setName(string & Ndat)
{
	name = Ndat;
	assert(name == Ndat);
}

string Listnode::getName() const
{
	return name;
}

void Listnode::setEmail(string & Edat)
{
	email = Edat;
	assert(email == Edat);
}

string Listnode::getEmail() const
{
	return email;
}

void Listnode::setCreds(string & creds)
{
	credits = creds;
	assert(credits == creds);
}

string Listnode::getCreds() const
{
	return credits;
}

void Listnode::setProgram(string & prog)
{
	program = prog;
	assert(program == prog);
}

string Listnode::getProgram() const
{
	return program;
}

void Listnode::setLevel(string & lev)
{
	level = lev;
	assert(level == lev);
}

string Listnode::getLevel() const
{
	return level;
}
