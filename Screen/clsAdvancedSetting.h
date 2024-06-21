#pragma once

#include <iostream>
#include "clsScreen.h"
#include "../Src/Global.h"
#include "clsOperationsScreens.h"


using namespace std;


class clsAdvancedSetting : public clsScreen
{

private :
	
	enum enAdvancedSettingMenueOptions{
		ClearCurrentlyReading = 1,
		ClearWantToRead = 2,
		ClearFinishedReading = 3,
		ClearNotInterested = 4,
		ClearAllCatigories = 5,
		Exit = 6
	};

	static void _GoBackToAdvancedSettingMenue(){
		getchar();
		cout << "\n\nPress [Enter] to return to the Advanced Setting menu.\n";
		while(!getchar());
		AdvancedSettingScreen();
	}

	
	static void _PerformAdvancedSettingMenueOptions(enAdvancedSettingMenueOptions Option){
		switch (Option){
			case enAdvancedSettingMenueOptions::ClearCurrentlyReading :
				clsOperationsScreens::ClearCatigoryScreen(CurrentlyReadingFile);
				_GoBackToAdvancedSettingMenue();
				break;
			case enAdvancedSettingMenueOptions::ClearWantToRead :
				clsOperationsScreens::ClearCatigoryScreen(WantToReadFile);
				_GoBackToAdvancedSettingMenue();
				break;
			case enAdvancedSettingMenueOptions::ClearFinishedReading :
				clsOperationsScreens::ClearCatigoryScreen(FinishedReadingFile);
				_GoBackToAdvancedSettingMenue();
				break;
			case enAdvancedSettingMenueOptions::ClearNotInterested :
				clsOperationsScreens::ClearCatigoryScreen(NotInterestedFile);
				_GoBackToAdvancedSettingMenue();
				break;
			case enAdvancedSettingMenueOptions::ClearAllCatigories :
				clsOperationsScreens::ClearCatigoriesScreen();
				_GoBackToAdvancedSettingMenue();
				break;
			default :
				return;
			
		}
	}

public:

	static void AdvancedSettingScreen(){
		clsScreen::Header();
		clsScreen::DrawHeader("Advanced Setting");
		cout << endl << endl;
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *           1) Clear \"Currently Reading\"       *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *              2) Clear \"Want To Read\"         *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *            3) Clear \"Finished Reading\"       *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *             4) Clear \"Not Interested\"        *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *              5) Clear All Catigories         *\n";
		cout << "\t\t\t\t   ************************************************\n";
		cout << "\t\t\t\t   *                   6) Return                  *\n";
		cout << "\t\t\t\t   ************************************************\n\n";

		short Choice;
		do{
			cout << "_ Enter a choice [1-6] : ";
			cin >> Choice;
		}while(Choice < 1 || Choice > 6);

		_PerformAdvancedSettingMenueOptions((enAdvancedSettingMenueOptions)Choice);

	}



	
};