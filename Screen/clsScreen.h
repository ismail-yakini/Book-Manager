#pragma once

#include <iostream>

using namespace std;


class clsScreen {
public:
	
	static void Header(){
		cout << endl;
		system("clear");
		cout << endl;
		cout << "\t\t\t\t\t  ********************************\n";
		cout << "\t\t\t\t\t  *                              *\n";
		cout << "\t\t\t\t\t  *         Books Manager        *\n";
		cout << "\t\t\t\t\t  *                              *\n";
		cout << "\t\t\t\t\t  ********************************\n\n";
	}

	static void DrawHeader(string Title, string SubTitle = ""){
		cout << "\t\t\t\t     __________________________________________\n\n";
		cout << "\t\t\t\t\t\t"<< Title << endl;
		if(SubTitle != ""){
			cout << "\t\t\t\t  " << SubTitle << endl;
		}
		cout << "\t\t\t\t     __________________________________________\n";


		
	}
};