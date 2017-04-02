#pragma once
#include "Master.h"
class Listnode
{
public:
	Listnode();
	~Listnode();
	
	static std::unique_ptr<Listnode> getNextPtr();

	void setRecord(string &data);
	string getRecord() const;

	void setID(string &ID);
	string getID() const;

	void setName(string &Ndat);
	string getName() const;

	void setEmail(string &Edat);
	string getEmail() const;
	
	void setCreds(string &creds);
	string getCreds() const;

	void setProgram(string &prog);
	string getProgram() const;

	void setLevel(string &lev);
	string getLevel() const;

	void setNumAbs(string &numabs);
	string getNumAbs() const;

	void setAbsDate(string &absdate);
	string getAbsDate() const;
private:
	std::unique_ptr<Listnode> nextptr;
	string Record;
	string idNum;
	string name;
	string email;
	string credits;
	string program;
	string level;
	string numAbs;
	vector<string> absences;
};

