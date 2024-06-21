#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "clsBook.h"
#include "Global.h"


using namespace std;

class clsOperations{
public:
	
	static vector <string> Split(string Line, string Delim = " "){
		vector<string> vString;
     	short pos = 0;
     	string sWord; 

    	while ((pos = Line.find(Delim)) != std::string::npos){
			sWord = Line.substr(0, pos);
			vString.push_back(sWord);
			Line.erase(0, pos + Delim.length());  
      	}

		if (Line != ""){
			vString.push_back(Line); 
		}

		return vString;
	}

	static clsBook ConvertLineToRecord(string Line){
		vector <string> vItems;
		vItems = Split(Line, "#//#");
		return clsBook(vItems[0], vItems[1], vItems[2], stoi(vItems[3]));

	}

	static string ConvertRecordToLine(clsBook Book){
		string Line = "";
		string Delim = "#//#";
		Line += Book.GetTitle() + Delim;
		Line += Book.GetAuthor() + Delim;
		Line += Book.GetLanguage() + Delim;
		Line += to_string(Book.GetPages());
		return Line;
	}

	static vector <clsBook> LoadRecordsFromFile(string FileName){
		fstream File;
		vector <clsBook> vBooks;
		string Line;
		
		File.open(FileName, ios::in);

		if(File.is_open()){
			while(getline(File, Line)){
				vBooks.push_back(ConvertLineToRecord(Line));
			}
		}
		File.close();

		return vBooks;
	}

	static void SaveRecordsToFile(string FileName,vector <clsBook> vBooks){
		fstream File;
		
		File.open(FileName, ios::out);

		if(File.is_open()){
			for(clsBook Book : vBooks){
				if(!IsEmpty(Book)){
					File << ConvertRecordToLine(Book) << endl;
				}
			}
		}
		File.close();
	}

	static bool IsEqualTo(clsBook Book1, clsBook Book2){
		return (Book1.GetTitle() == Book2.GetTitle() && Book1.GetAuthor() == Book2.GetAuthor() &&
				 Book1.GetLanguage() == Book2.GetLanguage() && Book1.GetPages() == Book2.GetPages());
	}

	static bool IsEmpty(clsBook Book){
		return IsEqualTo(Book, clsBook::GetEmptyObject());
	}

	static bool FindIn(string FileName, clsBook Book){
		fstream File;
		string Line;
		
		File.open(FileName, ios::in);

		if(File.is_open()){
			while(getline(File, Line)){
				if(IsEqualTo(Book, ConvertLineToRecord(Line))){
					File.close();
					return true;
				}
			}
		}
		File.close();
		return false;	
	}


	static void AddBook(string FileName, clsBook Book){
		vector <clsBook> vBooks = LoadRecordsFromFile(FileName);
		vBooks.push_back(Book);
		SaveRecordsToFile(FileName, vBooks);
	}

	static void DeleteBook(string FileName, clsBook Book){
		vector <clsBook> vBooks = LoadRecordsFromFile(FileName);
		for(clsBook & B : vBooks){
			if(IsEqualTo(B, Book)){
				B = clsBook::GetEmptyObject();
				break;
			}
		}
		SaveRecordsToFile(FileName, vBooks);
	}

	static void MoveBook(string MoveFromFile, string MoveToFile, clsBook Book){
		DeleteBook(MoveFromFile, Book);
		AddBook(MoveToFile, Book);
	}

	static void UpdateBook(string FileName, clsBook OldBook, clsBook NewBook){
		vector <clsBook> vBooks = LoadRecordsFromFile(FileName);
		for(clsBook & Book : vBooks){
			if(IsEqualTo(Book, OldBook)){
				Book = NewBook;
				break;
			}
		}
		SaveRecordsToFile(FileName, vBooks);

	}


	static bool ClearCatigory(string FileName){
		fstream File;
		
		File.open(FileName, ios::out);

		if(File.is_open()){
			File.close();	
			return true;
		}
		return false;
			
	}

	static bool FindBook(clsBook Book){
		if(clsOperations::FindIn(CurrentlyReadingFile, Book)){
			return true;
		}		

		if(clsOperations::FindIn(WantToReadFile, Book)){
			return true;
		}

		if(clsOperations::FindIn(FinishedReadingFile, Book)){

			return true;
		}

		if(clsOperations::FindIn(NotInterestedFile, Book)){

			return true;	
		}
		return false;

	}

};