#pragma once

#include <iostream>
#include <vector>
#include "../Src/clsOperations.h"
#include "../Src/Global.h"
#include "clsOperationsScreens.h"


using namespace std;

class clsFinishedReading{

public:

	static void FinishedReadingScreen(){

		vector <clsBook> vBooks = clsOperations::LoadRecordsFromFile(FinishedReadingFile);
		string Title = "Finished Reading";
		clsOperationsScreens::ShowBooksList(vBooks, Title);
		char Choice = clsOperationsScreens::GetUserChoice(vBooks.size());
		
		if(Choice == '+'){
			clsOperationsScreens::AddBookScreen(FinishedReadingFile);

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
				"  5) Move To \"Not Interested\" Catigory.\n" 
				"  6) Return.\n\n";
		
		short Choice;
		do{
			cout << "Enter A Choice [1-6] : ";
			cin >> Choice;
		}while(Choice < 1 || Choice > 6);


		switch(Choice){
			case 1 :
				clsOperationsScreens::DeleteBookScreen(FinishedReadingFile, Book);
				break;
			case 2 :
				clsOperationsScreens::UpdateBookScreen(FinishedReadingFile, Book);
				break;
			case 3 :
				clsOperationsScreens::MoveBookScreen(FinishedReadingFile, CurrentlyReadingFile, Book);
				break;
			case 4:
				clsOperationsScreens::MoveBookScreen(FinishedReadingFile, WantToReadFile, Book);
				break;
			case 5:
				clsOperationsScreens::MoveBookScreen(FinishedReadingFile, NotInterestedFile, Book);
			default:
				FinishedReadingScreen();
				return;
		}


	}

	
};