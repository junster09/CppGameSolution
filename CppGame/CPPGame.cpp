// CPPGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

//dem function prototypes
void clearBuffer();
void itemMenu();
void mainHelpList();
void readInput(string& com, string& tar);

string JUNK;
int main()
{

	while (true) {//main
		string command{ "" };
		string target{""};
		cout << "\nPlease enter a command (main): ";
		readInput(command, target);
		if ("help" == command){
			mainHelpList();
		}
		else if ("stats" == command) {
		}
		else if ("room" == command) {
		}
		else if ("item" == command) {
			itemMenu();
		}
		else if ("exit" == command) {
			cout << "\nAre you sure? ";
			readInput(command, target);
			if ("no" == command) {
				continue;
			}
			else { break; }
		}
		else{
			cout << "\n\nunidentified keword \""<<command<<"\" has been inputted, please type \"help\" for a list of keywords";
		}
	
	
	
	}

    return 0;
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
		if (isspace(input[i])) {
			i++;
			break;
		}
		tar += input[i];
		i++;
	}
	//cout << "command is: "<< com;
	//cout << "\ntarget is: " << tar;
}

//helplist type funcitons
void mainHelpList() {
	cout << "\nhelp: shows all the possible keywords for main menu" << endl
		<< "stats: opens the stats menu for you character" << endl
		<< "room: opens the room menu" << endl
		<< "item: opens the item menu" << endl
		<< "exit: will prompt you to exit the game" << endl;
}
//menu type functions
void itemMenu() {

	while (true) {
		string command{ "" };
		string target{ "" };
		cout << "\nPlease enter a command (item): ";
		readInput(command, target);
		if ("help" == command) {
			cout << "\nhelp: shows all the possible keywords for item menu" << endl
				<< "back: brings you back to the main menu" << endl;
		}
		else if ("back" == command) {
			break;
		}
	
	
	}

}
