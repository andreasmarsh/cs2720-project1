
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.cpp"
#include "Student.cpp"
using namespace std;
void testIntegerList();
void testStudentList();
int main()
{
	int datatype;
	// Prompt user to enter type of elements
	cout << "Enter Elements Type\n1 for integer\n2 for Student\n";
	cin >> datatype;
	switch (datatype)
	{
	case 1: testIntegerList();
		    break;
	case 2: testStudentList();
		    break;
	}
	//Ö.append any needed code here
	return 0;
}


void testIntegerList()
{
	UnsortedList<int> list(5);
	string command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("intcommands.txt");
	outFile.open("outFile.txt");
	int number;
	inFile >> command; // read commands from a text file

	while (command != "Quit")
	{
		try

		{
			if (command == "MakeEmpty")
				(list.makeEmpty());

			else if (command == "IsEmpty")
				if (list.isEmpty())
					outFile << "list is empty\n";
				else
					outFile << "list is not empty\n";
			else if (command == "IsFull")
			{
				if (list.isFull())
					outFile << "List is full\n";
				else
					outFile << "List is not full\n";
			}
			else if (command == "PutItem")
			{
				inFile >> number;
				list.putItem(number);
			}
			else if (command == "DeleteItem")
			{
				inFile >> number;
				list.deleteItem(number);
			}

			else if (command == "GetLength")
				outFile << list.getLength() << "\n";
			else if (command == "PrintList")
			{
				outFile << "List Items: ";
				int value;
				for (int index = 0; index < list.getLength(); index++)
				{
					value = list.getAt(index);
					outFile << value << " ";
				}
				outFile << "\n";
			}

			else if (command == "GetAt")
			{
				int index;
				inFile >> index;
				outFile << "Item at index " << index << " is:" << list.getAt(index) << endl;
			}
			else
				outFile << "Unrecognized command \n";
			inFile >> command;

		} // try

		catch (FullList)
		{
			outFile << "List is full, Insertion failed" << endl;
			inFile >> command;
		}

		catch (EmptyList)
		{
			outFile << "List is empty" << endl;
			inFile >> command;
		}

		catch (DuplicateItem)
		{
			outFile << "Duplicate Item, Insertion failed" << endl;
			inFile >> command;
		}
		catch (OutofBound)
		{
			outFile << "Index is out of range" << endl;
			inFile >>command;
		}
		catch (ItemNotFound)
		{
			outFile << "Item is not in the list"<<endl;
			inFile >> command;
		}
	} // while
} // testIntegerList

void testStudentList()
{
    UnsortedList<Student> list(10);
	string command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("studcommands.txt");
	outFile.open("outFile.txt");
	int number;
    string name;
	inFile >> command; // read commands from a text file

	while (command != "Quit")
	{
		try

		{
			if (command == "MakeEmpty")
				(list.makeEmpty());

			else if (command == "IsEmpty")
				if (list.isEmpty())
					outFile << "list is empty\n";
				else
					outFile << "list is not empty\n";
			else if (command == "IsFull")
			{
				if (list.isFull())
					outFile << "List is full\n";
				else
					outFile << "List is not full\n";
			}
			else if (command == "PutItem")
			{
                // construct new Student object and putItem
				inFile >> number;
                inFile >> name;
                Student temp = Student(number, name);
				list.putItem(temp);
			}
			else if (command == "DeleteItem")
			{
                inFile >> number;
                Student temp = Student(number, " ");
				list.deleteItem(temp);
			}

			else if (command == "GetLength")
				outFile << list.getLength() << "\n";
			else if (command == "PrintList")
			{
				outFile << "List Items: ";
				int value;
                string name;
				for (int index = 0; index < list.getLength(); index++)
				{
					value = list.getAt(index).getStudentID();
                    name = list.getAt(index).getStudentName();
					outFile << value << " " << name << " ";
				}
				outFile << "\n";
			}

			else if (command == "GetAt")
			{
				int index;
				inFile >> index;

				outFile << "Item at index " << index << " is:" << list.getAt(index).getStudentID() << " " << list.getAt(index).getStudentName() << endl;
			}
			else
				outFile << "Unrecognized command \n";
			inFile >> command;

		} // try

		catch (FullList)
		{
			outFile << "List is full, Insertion failed" << endl;
			inFile >> command;
		}

		catch (EmptyList)
		{
			outFile << "List is empty" << endl;
			inFile >> command;
		}

		catch (DuplicateItem)
		{
			outFile << "Duplicate Item, Insertion failed" << endl;
			inFile >> command;
		}
		catch (OutofBound)
		{
			outFile << "Index is out of range" << endl;
			inFile >>command;
		}
		catch (ItemNotFound)
		{
			outFile << "Item is not in the list"<<endl;
			inFile >> command;
		}
	} // while
}// test StudentList
