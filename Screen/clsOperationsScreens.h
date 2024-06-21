#pragma once
#include <cstdio>
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "../Src/clsBook.h"
#include "../Src/Global.h"
#include "../Src/clsOperations.h"
//I Hate Screens !

using namespace std;


class clsOperationsScreens{

private:

	

	static void _PrintBookRecordLine(clsBook Book){
		cout << "| " << setw(33) << left << Book.GetTitle();
		cout << "| " << setw(26) << left << Book.GetAuthor();
		cout << "| " << setw(19) << left << Book.GetLanguage();
		cout << "| " << setw(10) << left << Book.GetPages();
		cout << "|";
	}


public:

	static void ShowBooksList(vector <clsBook> vBooks, string Title){
		
		short i;

		system("clear");

		clsScreen::Header();
		string SubTitile = "\t\t  (" + to_string(vBooks.size()) + ") Book(s).";
		clsScreen::DrawHeader(Title, SubTitile);
		cout << endl << endl;

		cout << setw(8) << left << ""  << "______________________________________________________";
		cout << "_____________________________________________________\n\n";
		cout << setw(8) << left << "";
		cout << "| " << setw(8) << left << "Number";
		cout << "| " << setw(33) << left << "Title";
		cout << "| " << setw(26) << left << "Author";
		cout << "| " << setw(19) << left << "Language";
		// cout << "| " << setw(10) << left << "Pages";
		cout << "| " << setw(10) << left << "Pages" << "|" << endl;
		cout << setw(8) << left << "" << "_________________________________________________________";
		cout << "__________________________________________________\n\n";
		
		


		if(vBooks.size() == 0){
			cout << "\t\t\t\t\t No Books Available In This Category !\n";
		}else{
			short i = 1;
			for(clsBook Book : vBooks){	
				cout << setw(8) << left << "" ;
				cout << "| " << setw(8) << left << i;
				_PrintBookRecordLine(Book);
				cout << endl;
				i++;
			}	
		}

		cout << setw(8) << left << "" << "___________________________________________________________________________________________________________\n\n";


	}

	static void ShowBookCard(clsBook Book, string Title){
		
		system("clear");

		clsScreen::Header();

		clsScreen::DrawHeader(Title);

		cout << "\n\n";
		cout << "\t\t\t\t                   *************                   \n";
		cout << "\t\t\t\t                   * Book Card *                   \n";
		cout << "\t\t\t\t    ********************************************\n\n";
		cout << "\t\t\t\t\t\tTitle    : " << Book.GetTitle() << "\n";
		cout << "\t\t\t\t\t\tAuthor   : " << Book.GetAuthor() << "\n";
		cout << "\t\t\t\t\t\tLanguage : " << Book.GetLanguage() << "\n";
		cout << "\t\t\t\t\t\tPages    : " << Book.GetPages() << "\n\n";
		cout << "\t\t\t\t    ********************************************\n";
		
	}

	static char GetUserChoice(short NumOfBooks){

		char Choice;
		if(NumOfBooks == 0){
			do{
				cout << "Enter (+) To Add A Book , (0) To Go Back : ";
				cin >> Choice;	
			}while(Choice != '+' && Choice != '0');
			
		}else{
			do{
				cout << "Enter (+) To Add A Book , (0) To Go Back , (1) To Choose A Book : ";
				cin >> Choice;
			}while(Choice != '+' && Choice != '0' && Choice != '1');
		}

		return Choice;

	}
     
	static short ChooseBook(short NumOfBooks){
		short Choice;
		do{
			cout << "Choose A Book [1-" << NumOfBooks << "] : ";
			cin >> Choice;
		}while(Choice < 1 || Choice > NumOfBooks);
		return (Choice-1);

	}

	static clsBook ReadBookInfo(){
		clsBook Book = clsBook::GetEmptyObject();
		string Str;
		short Nbr;
		cout << "\n\n";
		cout << "Enter Book Information : \n";
		cout << "Enter The Title : ";
		getline(cin >> ws, Str);
		
		Book.SetTitle(Str);
		cout << "Enter The Author : ";
		getline(cin >> ws, Str);
		Book.SetAuthor(Str);
		cout << "Enter The Language : ";
		getline(cin >> ws, Str);
		Book.SetLanguage(Str);
		cout << "Enter The Number Of Pages : ";
		cin >> Nbr;
		Book.SetPages(Nbr);

		return Book;
				
	}

	
	static bool FindAndMoveBook(string FileName, clsBook Book){
		if(clsOperations::FindIn(CurrentlyReadingFile, Book)){
		
			BookFound(FileName, CurrentlyReadingFile, Book);
			return true;
		}		

		if(clsOperations::FindIn(WantToReadFile, Book)){
		
			BookFound(FileName, WantToReadFile, Book);

			return true;
		}

		if(clsOperations::FindIn(FinishedReadingFile, Book)){
		
			BookFound(FileName, FinishedReadingFile, Book);

			return true;
		}

		if(clsOperations::FindIn(NotInterestedFile, Book)){
		
			BookFound(FileName, NotInterestedFile, Book);

			return true;	
		}
		return false;

	}


	static void BookFound(string FileName, string FoundInFile, clsBook Book){
		if(FileName == FoundInFile){
			clsOperationsScreens::Message("The Book Is Already Exist !");
		}else{
			Message("The Book Exists In \"" + GetCatigoryName(FoundInFile) + "\" Catigory !\n");
			if(AskToMove()){

				clsOperations::MoveBook(FoundInFile, FileName, Book);
				Message("Book Meved Successfully !\n");
			}
		}

	}


	static void AddBookScreen(string FileName){
		clsBook Book = ReadBookInfo();
		if(FindAndMoveBook(FileName, Book)){
			return;
		}

		char Choice;
		do{
			cout << "Are You Shure To Add The Book [Y/N] : ";
			cin >> Choice;	
		}while(toupper(Choice) != 'Y' && toupper(Choice) != 'N');

		if(toupper(Choice) == 'Y'){
			clsOperations::AddBook(FileName, Book);
			Message("Book Added Successfully !");
		}

	}

	static void Message(string Message){
		cout << "\n\t\t\t" << Message << endl;
	}

	static bool AskToMove(){
		char Choice;
		do{
			cout << "Do You Want To Move The Book [Y/N] : ";
			cin >> Choice;	
		}while(toupper(Choice) != 'Y' && toupper(Choice) != 'N');

		return (toupper(Choice) == 'Y') ? true : false;
		
	}

	static string GetCatigoryName(string FileName){
		if(FileName == CurrentlyReadingFile){
			return "Currently Reading";
		}
		if(FileName == WantToReadFile){
			return "Want To Read";
		}
		if(FileName == FinishedReadingFile){
			return "Finished Reading";
		}
		if(FileName == NotInterestedFile){
			return "Not Interested";
		}
		return "Not Exist";
	}

	static void DeleteBookScreen(string FileName, clsBook Book){
		char Choice;
		do{
			cout << "Are You Shure To Delete The Book [Y/N] : ";
			cin >> Choice;	
		}while(toupper(Choice) != 'Y' && toupper(Choice) != 'N');

		if(toupper(Choice) == 'Y'){
			clsOperations::DeleteBook(FileName, Book);
			Message("Book Deleted Successfully !");
		}

	}

	static void UpdateBookScreen(string FileName, clsBook Book){
		clsBook NewBook = ReadBookInfo();
		if(clsOperations::FindBook(NewBook)){
			Message("Operation Failed ! Information Already Exist In A Category.");
			return;
		}
		clsOperations::UpdateBook(FileName, Book, NewBook);
		Message("Book Updated Successfully !");

	}

	static void MoveBookScreen(string MoveFromFile, string MoveToFile, clsBook Book){
		char Choice;
		do{
			cout << "Are You Shure To Move The Book [Y/N] : ";
			cin >> Choice;	
		}while(toupper(Choice) != 'Y' && toupper(Choice) != 'N');

		if(toupper(Choice) == 'Y'){
			clsOperations::MoveBook(MoveFromFile, MoveToFile, Book);
			Message("Book Meved Successfully !");
		}
	}
	
	static void ClearCatigoryScreen(string FileName){
		char Choice;
		do{
			cout << "Are You Shure To Clear The Catigory [Y/N] : ";
			cin >> Choice;	
		}while(toupper(Choice) != 'Y' && toupper(Choice) != 'N');

		if(toupper(Choice) == 'Y'){
			if(clsOperations::ClearCatigory(FileName)){
				Message("Catigory Cleared Successfully !");	
			}else{
				Message("Error! Try Again Later.");
			}
			
		}
	}

	static void ClearCatigoriesScreen(){
		char Choice;
		do{
			cout << "Are You Shure To Clear All The Catigories [Y/N] : ";
			cin >> Choice;	
		}while(toupper(Choice) != 'Y' && toupper(Choice) != 'N');

		if(toupper(Choice) == 'Y'){
			if(clsOperations::ClearCatigory(CurrentlyReadingFile) && 
			   clsOperations::ClearCatigory(WantToReadFile) && 
			   clsOperations::ClearCatigory(FinishedReadingFile) &&
			   clsOperations::ClearCatigory(NotInterestedFile)){
				Message("Catigories Cleared Successfully !");	
			}else{
				Message("Error! Try Again Later.");
			}
			
		}
	}
};