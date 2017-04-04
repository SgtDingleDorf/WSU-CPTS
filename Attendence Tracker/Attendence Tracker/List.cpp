#include "List.h"

List::List(fstream &infile)
{
	headNode = nullptr;
	UpdateList(infile);
}
List::~List()
{
	DeleteList();
}

void List::insertAtEnd(std::shared_ptr<Listnode> &Node)
{
	if (headNode == nullptr)
	{
		headNode = Node;
	}
	else
	{
		std::shared_ptr<Listnode> Prev = headNode;
		while (Prev->getNextPtr())
		{
			Prev = Prev->getNextPtr();
		}
		Prev->getNextPtr() = Node;
	}
}
void List::insertAtFront(std::shared_ptr<Listnode> &Node)
{
	insertAtFront(this->headNode, Node);
}
void List::insertAtFront(std::shared_ptr<Listnode> &headNode, std::shared_ptr<Listnode>& Node)
{
	std::shared_ptr<Listnode> temp = headNode;
	if (headNode == nullptr)
	{
		headNode = Node;
	}
	else
	{
		temp = Node;
		temp->getNextPtr() = headNode;
		headNode = temp;

	}
}

void List::EditList()
{
	EditList(this->headNode);
}

void List::UpdateList(fstream & updatefile)
{//only stores first node
	string temp;
	auto i = 0;
	string token = "Dubs Check 'Em";
	assert(updatefile.is_open());
	getline(updatefile, temp);
	while (!updatefile.eof())
	{
		try
		{
			auto k = 0;
			std::shared_ptr<Listnode> Node(new Listnode);
			getline(updatefile, temp);
			if (temp == "")
			{
				break;
			}
			while (temp[k] != '\0')
			{

				if (temp[k] == '"')
				{
					while (temp[k] != ',')
					{
						k++;
					}
					if (temp[k] == ',')
					{
						temp[k] = '_';
						break;
					}
				}
				k++;
			}
			std::stringstream temp_s(temp);
			while (true)
			{
				try
				{
					getline(temp_s, token, ',');
					if (temp_s.eof())
					{
						break;//reads until end of string stream
					}
					i++;
					switch (i)
					{
					case 1:
						Node->setRecord(token);
						break;
					case 2:
						Node->setID(token);
						break;
					case 3:
						Node->setName(token);
						break;
					case 4:
						Node->setEmail(token);
						break;
					case 5:
						Node->setCreds(token);
						break;
					case 6:
						Node->setProgram(token);
						break;
					case 7:
						Node->setLevel(token);
						break;
					case 8:
						Node->setNumAbs(token);
						break;
					default://beyond 9, read absences dates;
						Node->setAbsDate(token);
						break;

					}
				}
				catch (std::exception &e)
				{
					cout << "Exception: " << e.what() << endl;
				}
			}
			i = 0;
			insertAtFront(Node);
			//insertAtEnd(Node);
		}
		catch (std::bad_alloc)
		{
			cout << "Fucking R.I.P. : Out of Memory" << endl;
		}

	}
}
void List::EditList(std::shared_ptr<Listnode>& headNode)
{
	string regex_key = "[0-9]";
	std::regex rgx_top(regex_key, std::regex_constants::ECMAScript);
	std::smatch match_str;
	auto x = false;
	auto z = 0;
	auto v = false;
	string input1;
	std::shared_ptr<Listnode>pCur = headNode;//need to reset headnode
	while (x != true)
	{
		cout << "1. Add student" << endl;
		cout << "2. Remove student" << endl;
		cout << "3. Edit students" << endl;
		cout << "4. Exit" << endl;
		cin >> input1;
		x = regex_match(input1, match_str, rgx_top);
		if (match_str[0] == "1")
		{
			string input2;
			std::smatch match_str2;
			std::shared_ptr<Listnode> Node(new Listnode);
			while (v != true)//have default value constructor
			{
				system("cls");
				cout << "Select a field to edit: " << endl;
				cout << "0. Exit" << endl;
				cout << "1. Record" << endl;
				cout << "2. ID" << endl;
				cout << "3. Name" << endl;
				cout << "4. Email" << endl;
				cout << "5. Credits" << endl;
				cout << "6. Program" << endl;
				cout << "7. Level" << endl;
				cout << "8. Number of absences" << endl;
				cout << "9. Absences dates" << endl;
				cin >> input2;
				v = regex_match(input2, match_str2, rgx_top);
				if (match_str2[0] == "0")//move within wile loop
				{
					if (Node->getRecord() == "")
					{
						cout << "Field left blank: Record. Please fill all fields." << endl;
						system("pause");
						v = false;

					}
					else if (Node->getID() == "")
					{
						cout << "Field left blank: ID. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getName() == "")
					{
						cout << "Field left blank: Name. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getEmail() == "")
					{
						cout << "Field left blank: Email. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getCreds() == "")
					{
						cout << "Field left blank: Credits. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getProgram() == "")
					{
						cout << "Field left blank: Program. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getLevel() == "")
					{
						cout << "Field left blank: Level. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getNumAbs() == "")
					{
						cout << "Field left blank:Number of Absences. Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else if (Node->getAbsDate() == "")
					{
						cout << "Field left blank: Absence date(Enter null if 0). Please fill all fields." << endl;
						system("pause");
						v = false;
					}
					else
					{
						break;
					}
				}
				if (match_str2[0] == "1")
				{
					while (pCur != nullptr)
					{
						z++;
						pCur = pCur->getNextPtr();

					}
					pCur = headNode;
					z = z + 1;
					string token = std::to_string(z);
					Node->setRecord(token);
					cout << "Record number incremented." << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "2")
				{
					string temp;
					cout << "Enter an ID number." << endl;
					cin >> temp;
					Node->setID(temp);
					cout << "ID added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "3")
				{
					string temp;
					cout << "Enter a name." << endl;
					cin >> temp;
					Node->setName(temp);
					cout << "Name added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "4")
				{
					string temp;
					cout << "Enter an email." << endl;
					cin >> temp;
					Node->setEmail(temp);
					cout << "Email added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "5")
				{
					string temp;
					cout << "Enter number of credits." << endl;
					cin >> temp;
					Node->setCreds(temp);
					cout << "Credits added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "6")
				{
					string temp;
					cout << "Enter program." << endl;
					cin >> temp;
					Node->setProgram(temp);
					cout << "Program added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "7")
				{
					string temp;
					cout << "Enter Level." << endl;//enumerate later
					cin >> temp;
					Node->setLevel(temp);
					cout << "Level added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "8")
				{
					string temp;
					cout << "Enter number of absences." << endl;//enumerate later
					cin >> temp;
					Node->setNumAbs(temp);
					cout << "Number of absences added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "9")
				{
					string tstr;
					string temp = currentTime();
					cout << "Is student absent: " << endl;
					cout << "Y/N";
					cin >> tstr;
					if (tstr == "Y")
					{
						cout << "Absence date entered via system time." << endl;//enumerate later
						Node->setAbsDate(temp);
						cout << "Absence date added" << endl;
						system("pause");
						v = false;
					}
				}
				else
				{
					v = false;
				}
			}
		}

		/*system("cls");
		cout << "Select a student:" << endl;
		while (pCur!= nullptr)
		{
			z++;
			cout << z << pCur->getName() << endl;
			pCur = pCur->getNextPtr();

		}
		pCur = headNode;
		cin >> input;
		x = regex_match(input, match_str, rgx);
		if(x == true)
		{
			string res = match_str[0];
			while(pCur->getRecord()!= res)
			{
				pCur = pCur->getNextPtr();
			}
			cout<<"What field would you like to edit: "
		}*/
	}
}
void List::DeleteList()
{
	headNode.reset();//sends remains of list out of scope which then autodeallocates because smart ptr.
	assert(headNode == nullptr);
}
std::shared_ptr<Listnode>& List::getHead()
{
	return headNode;
}
