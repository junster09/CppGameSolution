// CPPGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Enemy.h"
#include "Room.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
using namespace std;

//dem function prototypes
void clearBuffer();
void itemMenu();
void roomMenu();
void optionsMenu();
void mainHelpList();
void readInput(string& com, string& tar);
Item* useItemsByName(string target);

string JUNK;
Room theRoom;
Player player("name", 18, 2, 2, 2, "This is the player");
string choice;
string statRead;
string fileCheck;
string name;
string hp;
string brawn;
string wit;
string speed;
bool save1 = false;
bool save2 = false;
bool save3 = false;

//temp
string currentSave = "player.txt";

// using file stream, write to file after  program closes
//fstream theFile("player.txt", ios::in | ios::out | ios::app);

int main()
{
	srand((unsigned)time(0));


	cout << "\n\n\tWelcome to Tower Climber V1.3" << endl;
	ifstream infile;
	infile.open("save1.txt");
	infile >> fileCheck;
	cout << fileCheck;
	if (fileCheck != "") {
		cout << "You a save data 1" << endl;
		save1 = true;
	}
	fileCheck = "";
	infile.close();
	infile.open("save2.txt");
	infile >> fileCheck;
	cout << fileCheck;
	if (fileCheck != "") {
		cout << "You a save data 2" << endl;
		save2 = true;
	}
	fileCheck = "";
	infile.close();
	infile.open("save3.txt");
	infile >> fileCheck;
	cout << fileCheck;
	if (fileCheck != "") {
		cout << "You a save data 3" << endl;
		save3 = true;
	}
	fileCheck = "";
	infile.close();
	cout << save1 << save2 << save3 << endl;
	while (currentSave != "save1.txt" || currentSave != "save2.txt" || currentSave != "save3.txt") {
		if (save1 == true || save2 == true || save3 == true) {
			cout << "\n\tYou have a save file, would you like to continue on any of them? (yes/no)";
			cin >> choice;
			if (choice == "yes" || choice == "y") {
				cout << "\n\tCurrent save files are: " << endl;
				if (save1 == true) {
					cout << "\t1.Save 1" << endl;
				}
				if (save2 == true) {
					cout << "\t2.Save 2" << endl;
				}
				if (save3 == true) {
					cout << "\t3.Save 3" << endl;
				}
				cout << "\tPlease type the save number your would like to use (1/2/3): ";
				cin >> currentSave;
				if (currentSave == "1") {
					infile.open("save1.txt");
					infile >> fileCheck;
					cout << fileCheck;
					if (fileCheck == "") {
						cout << "\n\tThis file doesn't have a save data, please choose another one" << endl;
					}
					else {
						currentSave = "save1.txt";
						break;
					}
					fileCheck = "";
					infile.close();
				}
				if (currentSave == "2") {
					infile.open("save2.txt");
					infile >> fileCheck;
					cout << fileCheck;
					if (fileCheck == "") {
						cout << "\n\tThis file doesn't have a save data, please choose another one" << endl;
					}
					else {
						currentSave = "save2.txt";
						break;
					}
					fileCheck = "";
					infile.close();
				}
				if (currentSave == "3") {
					infile.open("save3.txt");
					infile >> fileCheck;
					cout << fileCheck;
					if (fileCheck == "") {
						cout << "\n\tThis file doesn't have a save data, please choose another one" << endl;
					}
					else {
						currentSave = "save3.txt";
						break;
					}
					fileCheck = "";
					infile.close();
				}
			}
			else if (choice == "no" || choice == "n") {
				cout << "\n\tNo save file picked, starting a new game" << endl;
				break;
			}
			else {
				//text
			}
			choice = "";
		}
	}


	infile.open(currentSave);
	string indata;
	while (!infile.eof()) {
		infile >> indata;
		size_t a = indata.find("/") + 1;
		string statRead = indata.substr(a, indata.find(":") - a);
		if (statRead == "n") {
			size_t b = indata.find(":") + 1;
			name = indata.substr(b, indata.find("") - b);
			if (name == "") {
				cout << "\n\tPlease Enter a name for your character: ";
				getline(cin, name);
				player.setName(name);
				if (name == "Link") {
					cout << "haye";
					// include code for extra 10 inventory slot
				}
				else if (name == "AJ") {
					cout << "yooo";
					// include some special stat
				}
				else if (name == "kandersson") {
					cout << "....";
					// include speed by 10
				}
				else if (name == "rbreez") {
					cout << "...";
					// include some special stat
				}
				else if (name == "Bineet") {
					cout << "need them A's";
					// include all by 10
				}
				else {
					cout << "";
				}
			}
			else {
				player.setName(name);
				cout << "\n\tWelcome back " << name << endl;
			}
		}
		else if (statRead == "h") {
			size_t b = indata.find(":") + 1;
			hp = indata.substr(b, indata.find("") - b);
			cout << hp << endl;
		}
		else if (statRead == "b") {
			size_t b = indata.find(":") + 1;
			brawn = indata.substr(b, indata.find("") - b);
			cout << brawn << endl;
		}
		else if (statRead == "w") {
			size_t b = indata.find(":") + 1;
			wit = indata.substr(b, indata.find("") - b);
			cout << wit << endl;
		}
		else if (statRead == "s") {
			size_t b = indata.find(":") + 1;
			speed = indata.substr(b, indata.find("") - b);
			cout << speed << endl;
		}
		else {
			cout << endl;
		}

	}
	infile.close();

	while (true) {//main
		string command{ "" };
		string target{ "" };
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tstats/s" << endl
			<< "\troom/r" << endl
			<< "\titem/i" << endl
			<< "\toptions/o" << endl
			<< "\texit/e" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (main): ";
		readInput(command, target);
		if ("help" == command || "h" == command) {
			mainHelpList();
		}
		else if ("stats" == command || "s" == command) {
			cout << player.toString();
		}
		else if ("room" == command || "r" == command) {
			roomMenu();
		}
		else if ("item" == command || "i" == command) {
			itemMenu();
		}
		else if ("options" == command || "o" == command) {
			optionsMenu();
		}
		else if ("exit" == command || "e" == command) {
			cout << "\n\tAre you sure? (yes/no)";
			readInput(command, target);
			if ("no" == command || "n" == command) {
				continue;
			}
			else { break; }
		}
		else {
			cout << "\n\n\tunidentified keword \"" << command << "\" has been inputted, please type \"help\" for a list of keywords";
		}



	}
	cout << "\n\n\tThank you for playing" << endl
		<< "\t";
	ofstream outFile;
	outFile.open(currentSave);
	outFile << "/n:" << name << endl;
	outFile.close();
    //return 0;
}
//input type functions
void clearBuffer() {
	getline(cin, JUNK);
}

void readInput(string& com, string& tar) {
	com="";
	tar="";
	string input;
	getline(cin,input);
	unsigned int i{ 0 };
	while (i < input.length()) {
		if (isspace(input[i])) {
			i++;
			break;
		}
		com += input[i];
		i++;
	}
	while (i < input.length()) {
		tar += input[i];
		i++;
	}
	//cout << "command is: "<< com;
	//cout << "\ntarget is: " << tar;
}

//helplist type funcitons
void mainHelpList() {
	cout << "\n\t*********************************************" << endl 
		<< "\n\thelp/h: shows all the possible keywords for main menu" << endl
		<< "\tstats/s: opens the stats menu for you character" << endl
		<< "\troom/r: opens the room menu" << endl
		<< "\titem/i: opens the item menu" << endl
		<< "\texit/e: will prompt you to exit the game" << endl
		<< "\n\t*********************************************" << endl;
}
//menu type functions

void roomMenu() {
	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tdo/d" << endl
			<< "\tview/v" << endl
			<< "\tback/b" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (room): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\ndo/d: display possible action for the room" << endl
				<< "view/v: display the information of the room" << endl
				<< "back/b: go back to main menu" << endl;
		}

		else if ("do" == command || "d" == command) {
			if (theRoom.RoomAction(&player)) {
				++theRoom;
			}
		}
		else if ("view" == command || "v" == command) {
			theRoom.toString();
		}

		else if ("back" == command || "b"==command) {
			break;
		}
	}
}

void itemMenu() {

	while (true) {
		string command{ "" };
		string target{ "" };
		Item* tempPtr;
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tview/v" << endl
			<< "\tuse/u" << endl
			<< "\tback/b" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (item): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\nhelp: shows all the possible keywords for item menu" << endl
				<< "back: brings you back to the main menu" << endl;
		}
		else if ("view" == command || "v" == command && "" != target) {
			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				cout << tempPtr->toString();
			}
		}
		else if ("view" == command || "v" == command) {
			player.showInventory();
		}

		else if ("use" == command || "u" == command && "" != target) {

			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				player.equip(*tempPtr);
			}
		}
		else if ("use" == command || "u" == command) {
			cout << "What Item to use/equip?";
			player.showInventory();
			cout << endl<<endl;
			getline(cin, target);
			tempPtr = useItemsByName(target);
			if (tempPtr != nullptr) {
				player.equip(*tempPtr);
			}
		}

		else if ("back" == command || "b" == command) {
			break;
		}
	
	
	}

}

void optionsMenu() {
	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\n\t*********************************************" << endl
			<< "\n\tActions: " << endl
			<< "\tname/n" << endl
			<< "\treset/r" << endl
			<< "\tcredits/c" << endl
			<< "\tback/b" << endl
			<< "\tType help/h to view what each command does" << endl
			<< "\n\t*********************************************" << endl;
		cout << "\n\tPlease enter a command (options): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\ndo/d: display possible action for the room" << endl
				<< "view/v: display the information of the room" << endl
				<< "back/b: go back to main menu" << endl;
		}
		else if ("name" == command || "n" == command) {
			cout << "\tWould you like to change your name? (yes/no) ";
			cin >> choice;
			if (choice == "yes" || choice == "y") {
				cout << "\n\tWhat would you like to change it to? ";
				cin >> name;
				player.setName(name);
				//write to file;
				cout << "\n\tYou changed your name to " << name << endl;
			}
			else if (choice == "no" || choice == "n") {
				cout << "\tNo worries, your name is still " << name << endl;
			}
			else {
				cout << "\tNot a choice, please try again" << endl;
			}
			choice = "";
		}
		else if ("reset" == command || "r" == command) {
			cout << "\tDo you want to reset your file data? (yes/no) ";
			cin >> choice;
			if (choice == "yes" || choice == "y") {
				name = "'";
				//weite to file
				cout << "\tYour file has been resetted" << endl;
			}
			else if (choice == "no" || choice == "n") {
				cout << "\tNo worries, your game is still here" << endl;
			}
			else {
				cout << "\tNot a choice, please try again" << endl;
			}
			choice = "";
		}
		else if ("credit" == command || "c" == command) {
			cout << "\n\tcredits" << endl;
		}
		else if ("back" == command || "b" == command) {
			break;
		}
	}
}

Item* useItemsByName(string target) {
	if (player.getItemBag()->GetItemByName(target).getName() == target) {
		return &player.getItemBag()->GetItemByName(target);
	}
	else {
		cout << "\tName not found, try enetering the name again";
		return nullptr;
	}
}
