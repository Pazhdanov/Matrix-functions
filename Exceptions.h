#ifndef Exceptions_h
#define Exceptions_h
#include "Classes.h"

class SuchFileDoesNotExist{
	char Message[50];
public:
	SuchFileDoesNotExist(char*Message) {
		cout << Message << endl;
	}
};

class DimentionError{
	char Message[50];
public:
	DimentionError(char*Message) {
		cout << Message << endl;
	}
};

class DetEqualsZero{
	char Message[50];
public:
	DetEqualsZero(char*Message) {
		cout << Message << endl;
	}
};

class NotEnoughMatricies{
	char Message[50];
public:
	NotEnoughMatricies(char*Message) {
		cout << Message << endl;
	}
};

class MatriciesShouldHaveDifferentNumbers{
	char Message[50];
public:
	MatriciesShouldHaveDifferentNumbers(char*Message) {
		cout << Message << endl;
	}
};

class IncorrectNumberInput{
	char Message[50];
public:
	IncorrectNumberInput(char*Message) {
		cout << Message << endl;
	}
};

class NoElement{
	char Message[50];
	int row, col;
public: 
	NoElement(char*Message, int row, int col){
		cout << Message << row << ' ' << col << endl;
	}
};

#endif