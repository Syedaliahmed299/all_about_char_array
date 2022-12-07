#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;
class myString {
	char* arr;      //declearation of character array as private member
public:
	myString() {               //constructor
		arr = new char[80];  //initialization of string
	}
	myString(char ch[]) {    //parametrized constructor
		this->arr = ch;
	}

/// member functions
	void setString();       
	void dispString();
	int length();
	int search(myString);
	void charTypes();
	myString operator-(myString&);
	myString operator+(myString&);
};

/// number of upper case,lower case,digits and special character in 
/// the string
void myString::charTypes() {
	int i = 0;
	int countAlph = 0;
	int countDig = 0;
	int countSpecial = 0;
	while (arr[i] != '\0') {
		if((arr[i]>='a' && arr[i]<='z')||arr[i]>='A' && arr[i]<='Z'){
			countAlph++;
		}
		else {
			if (arr[i] >= '0' && arr[i] <= '9') {
				countDig++;
			}
			else {
				if(arr[i]!=' ')
				countSpecial++;
			}
		}
		i++;
	}
	cout << "the number of alphebets are :- " << countAlph << endl;
	cout << "the number of digits are :- " << countDig << endl;
	cout << "the number of special characters are:- " << countSpecial<<endl;

}

/// concatenation
myString myString::operator+(myString &str) {
	myString temp;
	int i = 0;
	while (arr[i] != '\0') {
		temp.arr[i] = arr[i];
		i++;
	}
	temp.arr[i++] = ' ';
	int size = strlen(str.arr);
	int j = 0;
	while (j <= size) {
		temp.arr[i++] = str.arr[j++];
	}
	return temp;
}

//deletion of string

myString myString::operator-(myString &delStr) {
	myString temp;
	int i = 0;
	while (arr[i] != '\0') {
		temp.arr[i] = arr[i];
		i++;
	}
	temp.arr[i] = '\0';
	int index =this->search(delStr);
	int size = strlen(delStr.arr);
	if (index != -1) {
		while (temp.arr[index + size] != '\0') {
			temp.arr[index] = temp.arr[index + size];
			index++;
		}
		temp.arr[index] = '\0';
	}
	else {
		cout << "string not found" << endl;
	}
	return temp;
}

//searching word in the string
int myString::search(myString str) {
	int i = 0;
	int j = 0;
	int size = strlen(str.arr);
	while (arr[i] != '\0') {
		if (arr[i] == str.arr[j]) {
			i++;
			j++;
		}
		else {
			i++;
			j = 0;
		}
		if (j == size && (arr[i] == ' ' || arr[i] == '\0')) {
			return i - size;
		}
	}
	return -1;
}

void myString::setString() {                 //taking input of char array
	cin.ignore(1, '\0');  //to clear the buffer
	cin.get(arr, 80);
}

void myString::dispString() {              //getting output of char array
	cout << arr;
}


void menu() {
	cout << setw(63) << "1.Set the string" << endl;
	cout << setw(65) << "2. Display the string" << endl;
	cout << setw(64) << "3. Search the string" << endl;
	cout << setw(64) << "4. delete the string" << endl;
	cout << setw(67) << "5.concatination of string" << endl;
	cout << setw(74) << "6.Number of character in the string" << endl;
	cout << setw(73) << "7.Types of character in the string" << endl;
}
// process of taking input of string

void case1Process(myString& str1, myString& str2) {     //setting values
	cout << "enter the first string" << endl;
	str1.setString();
	cout << "your first is set" << endl;
	cout << "enter the second string" << endl;
	str2.setString();
	cout << "your second is also set" << endl;
}


void case2Process(myString& str1, myString& str2) {    //displaying values
	cout << "your first string is :-  "; str1.dispString();
	cout << endl;
	cout << "your second string is :-  "; str2.dispString();
}
void case3() {
	cout << "1.To search in first string" << endl;
	cout << "2.To searh in second string" << endl;
}

void case4() {
	cout << "1.To delete in first string" << endl;
	cout << "2.To delete in second string" << endl;
}

//algorithm to delete word from the string
void case4Process(char option,myString str1,myString str2,myString delStr) {
	switch (option) {
	case '1':
	{myString deletedStr;
	deletedStr = str1 - delStr;
	cout << "after deletion :- ";
	deletedStr.dispString();
	}
		break;
	case '2':
		myString deletedStr2;
		deletedStr2 = str2 - delStr;
		cout << "after deletion :- ";
		deletedStr2.dispString();
		break;
	}
}

//algorithm to search word from the string
void case3Process(char option,myString str1,myString str2, myString searchStr) {
	switch (option) {	
	case '1':
	{int position = str1.search(searchStr);
	if (position != -1) {
		cout << "your string is placed at index " << position << endl;
	}
	else {
		cout << "string not found" << endl;
	}
	}
		break;
	case '2':
	{	int position2 = str2.search(searchStr);
	if (position2 != -1) {
		cout << "your string is placed at index " << position2 << endl;
	}
	else {
		cout << "string not found" << endl;
	}
	break;
	}
	}
}

//algorithm to find the length of the string
int myString::length() {
	int i = 0;
	while (arr[i] != '\0') {
		i++;
	}
	return i;
}
void case6() {
	cout << "1.To Find Number of character in first string" << endl;
	cout << "2.To Find Number of character in second string" << endl;
}

//function to display number of character in the string
void case6Process(char option, myString str1, myString str2) {
	switch (option) {
	case '1':
		cout << "the number of character in the first string are :- " <<
			str1.length();
		break;
	case '2':
		cout << "the number of character in the second string are :- " <<
			str2.length();
		break;
	}
}

void case7() {
	cout << "1.To Find types of characters in first string" << endl;
	cout << "2.To Find types of characters in second string" << endl;
}
//function to display all types of character used in the string in the string
void case7Process(char option, myString str1, myString str2) {
	switch (option) {
	case '1':
		str1.charTypes();
		break;
	case '2':
		str2.charTypes();
		break;
	}
}

int main() {
	// searchStr = object of which array/word you want to search
	//delStr=object of which array holds the rest array after deletion
	//conctStr= object of which arrays holds the array after concatination
	//of object 1 and object 2's string
	myString str1, str2, searchStr, delStr,conctStr;             //creating objects 
	char option;
	do {
		menu();
		cin >> option;
		switch (option) {
		case '1':
			case1Process(str1, str2);
			cout << endl << endl;
			break;
		case '2':
			case2Process(str1, str2);
			cout << endl;
			break;
		case '3':
			cout << "enter the string you want to search" << endl;
			searchStr.setString();
			case3();
			char option2;
			cout << "chose your option" << endl;
			cin >> option2;
			case3Process(option2, str1, str2, searchStr);
			break;
		case '4':
			cout << "enter the string you want to delete" << endl;
			delStr.setString();
			case4();
			char option3;
			cout << "chose your option" << endl;
			cin >> option3;
			case4Process(option3, str1, str2, delStr);
			break;
		case '5':
			conctStr = str1 + str2;
			conctStr.dispString();
			break;
		case '6':
			case6();
			char option4;
			cout << "chose your option" << endl;
			cin >> option4;
			case6Process(option4, str1, str2);
			break;
		case '7':
			case7();
			char option5;
			cout << "chose your option" << endl;
			cin >> option5;
			case7Process(option5,str1,str2);
			break;
		default:
			cout << "chose the correct option" << endl;
		}

	} while (true);
}