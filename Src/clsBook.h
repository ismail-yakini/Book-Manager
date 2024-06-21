#pragma once

#include <iostream>

using namespace std;

class clsBook{
private:
	string _Title;
	string _Language;
	string _Author;
	unsigned short _Pages;

public:

	clsBook(string Title, string Author, string Language, unsigned short Pages){
		_Title = Title;
		_Language = Language;
		_Author = Author;
		_Pages = Pages;
	}

	void SetTitle(string Title){
		_Title = Title;
	}

	string GetTitle(){
		return _Title;
	}

	void SetLanguage(string Language){
		_Language = Language;
	}

	string GetLanguage(){
		return _Language;
	}

	void SetAuthor(string Author){
		_Author = Author;
	}

	string GetAuthor(){
		return _Author;
	}

	void SetPages(unsigned short Pages){
		_Pages = Pages;
	}

	unsigned short GetPages(){
		return _Pages;
	}

	static clsBook GetEmptyObject(){
		clsBook Book("", "", "", 0);
		return Book;
	}
};