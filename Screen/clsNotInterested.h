#pragma once

#include <iostream>
#include <vector>
#include "../Src/clsOperations.h"
#include "../Src/Global.h"
#include "clsOperationsScreens.h"


using namespace std;

class clsNotInterested{
public:

	static void NotInterestedScreen(){

		vector <clsBook> vBooks = clsOperations::LoadRecordsFromFile(NotInterestedFile);
		string Title = "Not Interested";
		clsOperationsScreens::ShowBooksList(vBooks, Title);
		char Choice = clsOperationsScreens::GetUserChoice(vBooks.size());
		
		if(Choice == '+'){
			clsOperationsScreens::AddBookScreen(NotInterestedFile);

		}else if(Choice == '1'){
			short BookNumber;
			clsOperationsScreens::ShowBooksList(vBooks, Title);
			BookNumber = clsOperationsScreens::ChooseBook(vBooks.size());
			clsOperationsScreens::ShowBookCard(vBooks[BookNumber], Title);
			ShowAndPerformeBookOptions(vBooks[BookNumber]);

		}else{
			return;
		}
	}

	static void ShowAndPerformeBookOptions(clsBook Book){

		cout << "Operations : \n";
		cout << "  1) Delete.\n"
				"  2) Update.\n"
				"  3) Move To \"Currently Reading\" Catigory.\n" 
				"  4) Move To \"Want To Read\" Catigory.\n" 
				"  5) Move To \"Finished Reading\" Catigory.\n" 	
				"  6) Return.\n\n";
		
		short Choice;
		do{
			cout << "Enter A Choice [1-6] : ";
			cin >> Choice;
		}while(Choice < 1 || Choice > 6);


		switch(Choice){
			case 1 :
				clsOperationsScreens::DeleteBookScreen(NotInterestedFile, Book);
				break;
			case 2 :
				clsOperationsScreens::UpdateBookScreen(NotInterestedFile, Book);
				break;
			case 3 :
				clsOperationsScreens::MoveBookScreen(NotInterestedFile, CurrentlyReadingFile, Book);
				break;
			case 4:
				clsOperationsScreens::MoveBookScreen(NotInterestedFile, WantToReadFile, Book);
				break;
			case 5:
				clsOperationsScreens::MoveBookScreen(NotInterestedFile, FinishedReadingFile, Book);
			default:
				NotInterestedScreen();
				return;
		}


	}

	
};