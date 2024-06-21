#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrentlyReading.h"
#include "clsWantToRead.h"
#include "clsFinishedReading.h"
#include "clsNotInterested.h"
#include "clsAdvancedSetting.h"



using namespace std;



class clsMainMenue : public clsScreen
{

private :
	
	enum enMainMenueOptions{
		CurrentlyReading = 1,
		WantToRead = 2,
		FinishedReading = 3,
		NotInterested = 4,
		AdvancedSetting = 5,
		Exit = 6
	};

	static void _GoBackToMainMenue(){
		getchar();
		cout << "\n\nPress [Enter] to return to the main menu.\n";
		while(!getchar());
		MainMenueScreen();
	}

	static void _PerformMainMenueOptions(enMainMenueOptions Option){
		switch (Option){
			case enMainMenueOptions::CurrentlyReading :
				clsCurrentlyReading::CurrentlyReadingScreen();
				_GoBackToMainMenue();
				break;
			case enMainMenueOptions::WantToRead :
				clsWantToRead::WantToReadScreen();
				_GoBackToMainMenue();
				break;
			case enMainMenueOptions::FinishedReading :
				clsFinishedReading::FinishedReadingScreen();
				_GoBackToMainMenue();
				break;
			case enMainMenueOptions::NotInterested :
				clsNotInterested::NotInterestedScreen();
				_GoBackToMainMenue();
				break;
			case enMainMenueOptions::AdvancedSetting :
				clsAdvancedSetting::AdvancedSettingScreen();
				_GoBackToMainMenue();
				break;
			default :
				system("clear");
				break;
		}
	}

public:

	static void MainMenueScreen(){
		Header();

		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *             1) Currently Reading             *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *                2) Want To Read               *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *              3) Finished Reading             *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *               4) Not Interested              *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *              5) Advanced Setting             *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *                   6) Exit                    *\n";
		cout << "\t\t\t\t   ************************************************\n\n";

		short Choice;
		do{
			cout << "_ Enter a choice [1-6] : ";
			cin >> Choice;
		}while(Choice < 1 || Choice > 6);

		_PerformMainMenueOptions((enMainMenueOptions)Choice);

	}



	
};