#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

using std::ofstream;
using std::fstream;
class Person {
public:
	string name;
	int age;
	Person();
	Person(string Name);
};

Person::Person(string Name) : age(0), name(Name) {};
Person::Person() : age(0), name("") {};



class Student  {

public:
	Student();
	string getClass();
	Person people[100];
	int numOfpeople = 0;
	int getGrade();
	int finduser(string usrn);
	bool isFull();
	void Delete(string Name);
	void Builder();
	void Search(string name);
	void SearchByAge(int age);
	void WriteToText();
	void ReadFiles();
	void start();
	void instuctions();
	void Backup();
	void ReadFromBackup();
	void Print();
	void DeleteAll();
	void AdvancedDelete(string usrn);
	void DeleteForAdvance(int ID);
	void Sort();
	bool SortHelper(vector<int>& ID, int id);
	void SortAge();
	void Login();
	void ChangePasswordAndUsername();	
	void ChangeUser(string name,int NewAge, string NewName);
	void ChangeUser(string name,int NewAge);
	void setageANDname(int Age, string Name);
	void setgrade(int Grade);
	void setclass(string subject);
	void PasswordAndUsernameSetter();
	void PassAndUserUpdater(string password, string username);
	void AgeCounter();
private:
	string Class;
	int grade;
	const int MAX_PEOPLE = 100;
	string LoginPassword = "admin";
	string LoginUsername = "admin";
};

bool Student::isFull() {
	if (numOfpeople > MAX_PEOPLE ) {
		return true;
	}
	return false;
}
Student::Student() {
	Class = "";
	grade = 0;
}


void Student::setageANDname(int Age, string Name) {
	if (!isFull()) {
		people[numOfpeople].name = Name;
		people[numOfpeople].age = Age;
		numOfpeople++;
		cout << "Student added to system" << endl<<endl;
	}
	else {
		cout << "Full, cannot add anymore users"<<endl;

	}


}
void Student::setclass(string subject) {
	Class = subject;
}
void Student::setgrade(int Grade) {
	grade = Grade;
}
string Student::getClass() {
	return Class;
}
int Student::getGrade() {
	return grade;
}

//Finds a users ID in the array from a given username input
int Student::finduser(string usrn) {
	for (int i = 0; i <= numOfpeople; i++) {
		if (people[i].name.substr(0, usrn.length()) == usrn) {
			cout << "Users ID is " << i;
			cout << endl;
			return i;
		}
	}
	cout << "user cannot be found" << endl;
	cout << endl;
	return 9999;
}

//Deletes a user 
void Student::Delete(std::string Name) {
	int id = finduser(Name);
	string User = people[id].name;
	if (id != 9999) {
		for (int i = id; i < numOfpeople; i++) {
			people[i].name = people[i + 1].name;
			people[i].age = people[i + 1].age;
		}
		numOfpeople--;
		cout << "User " << User << " has been deleted succesfully" << endl<<endl;
	}
}

//Builds a 2d-array of ages and gets average of all of them
void Student::Builder() {
	const int num = 7;
	int* arr[num];
	for (int i = 0; i < num; i++) {
		arr[i] = new int[5];
	}
	int person = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 5; j++) {
			if (person < numOfpeople) {
				arr[i][j] = people[person].age;
				person++;
			}
			else
			{
				arr[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 5; j++) {
			cout<<  arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < num; i++) {
		delete arr[i];
		arr[i] = nullptr;
	}
	cout << endl << "all ages in system curently, -1 are place holders"<< endl;
	int avg = 0;
	for(int i = 0; i <= numOfpeople; i++) {
		avg = avg + people[i].age;
	}
	cout << "avg = " << avg / numOfpeople<<endl;
}

//Displays everyone with the name you have inputed
void Student::Search(string name) {
	vector <int> Results;
	for (int i = 0; i < numOfpeople; i++) {
		if (name == people[i].name) {
			Results.push_back(i);
		}
		else if (i == numOfpeople - 1 && Results.empty()) {
			cout << "no users found with that name" << endl;
		}
	}
	if (!Results.empty()) {
		cout << "users that have been found with the same name: " << endl;
		for (int i = 0; i < Results.size(); i++) {
			cout << people[Results[i]].name << " who is "<<people[Results[i]].age << " years old" << endl;
		}
		cout << endl;
	}
}

//searchs for everyone with the same age you inputed
void Student::SearchByAge(int age) {
	vector <int> Results;
	for (int i = 0; i < numOfpeople; i++) {
		if (age == people[i].age) {
			Results.push_back(i);
		}
		else if (i == numOfpeople - 1 && Results.empty()) {
			cout << "no users found with that age" << endl;
		}
	}
	if (!Results.empty()) {
		cout << "users that have been found with the same age: " << endl;
		for (int i = 0; i < Results.size(); i++) {
			cout << people[Results[i]].name << " who is " << people[Results[i]].age << " years old" << endl;
		}
	}
	cout << endl;
}

//Writes to a .txt file with your choice of name
void Student::WriteToText() {
	fstream file;
	string  name ;
	cout << "What do want to name the file?" << endl;
	cin >> name;
	file.open(name + ".txt", ios::in | ios::out | ios::trunc);
	if (file.is_open()) {
		file << "data-base" << "\n";
		for (int i = 0; i < numOfpeople; i++) {
			file <<i+1<<". " <<"Name: " << people[i].name << " Age: " << people[i].age << "\n";
		}
		cout << "Written successfully";
		file.close();
	}
	if (file.fail()) {
		cout << "Could not write to file";
	}
	cout << endl;
}

void Student::Backup() {
	fstream file;
	file.open("Backup.txt", ios::in | ios::out | ios::trunc);
	if (file.is_open()) {
		for (int i = 0; i < numOfpeople; i++) {
			file << "name=" << people[i].name << ": age=" << people[i].age<<";" << "\n";
		}
		file << "END";
		cout << "Backed-Up successfully"<<endl;
		file.close();
	}
	cout << endl;
}
//(optional) reads from text file and stores in data base
void Student::ReadFiles() {
	string line;
	int IDForName = 0;
	int LastIdName = 0;
	int AgeID = 0;
	int LastAgeID = 0;
	int age = 0;
	string NameOfFiles;
	cout << "Please enter name of file"<<endl;
	cin >> NameOfFiles;
	ifstream myfile(NameOfFiles + ".txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line) && !myfile.eof() )
		{
			for(int j = line.length(); j > -1; j--) {
				if (line[j] == ':') {
					LastIdName = j;
				}
				if (line[j] == '=') {
					IDForName = j;
				}
				
			}
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == 'e') {
					AgeID = i;
				}
				if (line[i] == ';') {
					LastAgeID = i;
				}

			}
			age = stoi(line.substr(AgeID + 2, LastAgeID - 1));
			people[numOfpeople].name = line.substr(IDForName + 1, LastIdName - 5);
			people[numOfpeople].age = age;
			cout << "NAME: " << people[numOfpeople].name << " AGE:" << people[numOfpeople].age << " has been stored" << endl;
			numOfpeople++;
			}
		}
		myfile.close();	
		cout << endl;
		if(myfile.fail()) {
		cout << "Unable to open file" << endl;
	    }
	}
//Loads names and ages from backup file
void Student::ReadFromBackup() {
	string line;
	int IDForName = 0;
	int LastIdName = 0;
	int AgeID = 0;
	int LastAgeID = 0;
	int age = 0;
	ifstream myfile("Backup.txt");
	if (myfile.is_open())
		{
		cout << "LOADING FROM BACKUP:" << endl;
		while (getline(myfile, line) && !myfile.eof())
		{
			for (int j = line.length(); j > -1; j--) {
				if (line[j] == ':') {
					LastIdName = j;
				}
				if (line[j] == '=') {
					IDForName = j;
				}
				
			}
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == 'e') {
					AgeID = i;
				}
				if (line[i] == ';') {
					LastAgeID = i;
				}

			}
			age = stoi(line.substr(AgeID + 2, LastAgeID - 1));
			people[numOfpeople].name = line.substr(IDForName + 1, LastIdName - 5);
			people[numOfpeople].age = age;
			cout << "NAME: " << people[numOfpeople].name << " AGE:" << people[numOfpeople].age << " has been stored" << endl;
			numOfpeople++;
		}
	}
	cout << endl;
	myfile.close();
}
//Prints out the all the options in english
void Student::instuctions() {
	cout << "Press O to open and read file into data-base" <<endl;
	cout << "Press P to write all contents of data-base to file" << endl; 
	cout << "Press Y to set new name and age" << endl;
	cout << "Press D to delete user by username(has to be excate username)" << endl;
	cout << "Press A to search through data-base to display people with same age" << endl;
	cout << "Press S to search through data-base to display people with same name" << endl;
	cout << "Press B to build 2-dim matrix of all ages" << endl;
	cout << "Press F to find users ID in data-base" << endl;
	cout << "Press L to print everyone in the system" << endl;
	cout << "Press 1 to change age of user" << endl;
	cout << "Press 2 to change name and age of user" << endl;	
	cout << "Press 3 to delete all users" << endl;	
	cout << "Press 4 for advanced delete" << endl;
	cout << "Press 5 to sort by first name" << endl; 
	cout << "Press 6 to sort by age" << endl;
	cout << "Press 7 to log out" << endl;
	cout << "Press E to exit" << endl;
}
//Starts the program
void Student::start() {
	bool StillOn = true;
	char Options;
	ReadFromBackup();
	while (StillOn) {
		instuctions();
		cout << "Enter option: ";
		cin >> Options;
		cout << endl; 
		if (Options == 'p' || Options == 'P') {
			WriteToText();
		}
		if (Options == 'o' || Options == 'O') {
			ReadFiles();
		}
		if (Options == 'y' || Options == 'Y') {
			string name;
			string Lastname;
			int age;
			cout << "Name and Age of person" << endl;
			cout << "Name: ";
			cin >> name;
			cout << endl << "(You can leave empty if not need)Last Name:";
			cin >> Lastname;
			cout << endl;
			cout << endl << "Age: ";
			cin >> age;
			cout << endl;
			setageANDname(age, name+ " " + Lastname);
		}
		if (Options == 'd' || Options == 'D') {
			string username;
			cout << "Enter username to delete: ";
			cin >> username;
			cout << endl;
			Delete(username);
		}
		if (Options == 'a' || Options == 'A') {
			int searchAge;
			cout << "Enter Age: ";
			cin >> searchAge;
			cout << endl;
			SearchByAge(searchAge);
		}
		if (Options == 's' || Options == 'S') {
			string searchName;
			cout << "Enter name to filter: ";
			cin >> searchName;
			cout << endl;
			Search(searchName);
		}
		if (Options == 'B' || Options == 'b') {
			Builder();
		}
		if (Options == 'F' || Options == 'f') {
			string finder;
			cout << "Enter name of ID: ";
			cin >> finder;
			cout << endl;
			finduser(finder);
		}
		if (Options == 'L' || Options == 'l') {
			Print();
		}
		if (Options == '1') {
			int age;
			string name;
			cout << "Enter username that you want to change: ";
			cin >> name;
			cout << endl;
			cout << "Enter new age: ";
			cin >> age;
			cout << endl;
			ChangeUser(name, age);
		}
		if (Options == '2') {
			int age;
			string name2;
			string NewName;
			string NewLastName;
			cout << "Enter username that you want to change: ";
			cin >> name2;
			cout << endl << "Enter new first name: ";
			cin >> NewName;
			cout << endl;
			cout << "(You can leave empty if not need)New last name: ";
			cin >> NewLastName;
			cout << endl;
			cout << "Enter new age: ";
			cin >> age;
			cout << endl;
			ChangeUser(name2, age, NewName + " " + NewLastName);
		}
		if (Options == '3') {
			DeleteAll();
		}
		if (Options == '4') {
			string username;
			cout << "Enter username to delete: ";
			cin >> username;
			cout << endl;
			AdvancedDelete(username);
		}
		if (Options == '5') {
			Sort();
		}
		if (Options == '6') {
			SortAge();
		}
		if (Options == '7') {
			Backup();
			std::cout << "\033[2J\033[1;1H";
			Login();
		}
		if (Options == '8') {
			ChangePasswordAndUsername();
		}
		if (Options == '9') {
			AgeCounter(); 
		}
		if (Options == 'E' || Options == 'e') {
			Backup();
			StillOn = false;
		} 

	}
	exit(0);

}
//Changes the users ages from given parameter
void Student::ChangeUser(string name, int NewAge) {
	vector <int> ID;
	for (int i = 0; i < numOfpeople; i++) {
		if (people[i].name.substr(0, name.length()) == name) {
			ID.push_back(i);
		}

	}
	if (ID.size() > 1) {
		cout << "Found multiple users with same username: " << endl << endl;
		for (int i = 0; i < ID.size(); i++) {
			cout << i << ": " << "NAME: " << std::setw(11) << people[ID[i]].name << std::setw(10) << " AGE: " << std::setw(3) << people[ID[i]].age << endl;
		}
		int choice;
		cout << "Which one would you like to change: ";
		cin >> choice;
		cout << endl;
		int OldAge = people[ID[choice]].age;
		people[ID[choice]].age = NewAge;
		cout << people[ID[choice]].name << " age has been changed from " << OldAge << " to " << people[ID[choice]].age << endl << endl;
	}
	else
	{
		
		int OldAge2 = people[ID[0]].age;
		people[ID[0]].age = NewAge;
		cout << people[ID[0]].name << " age has been changed from " << OldAge2 << " to " << people[ID[0]].age << endl << endl;
		
	}

}

//changes the users name and age from given parameter
void Student::ChangeUser(string name,int NewAge, string NewName) {
	vector <int> ID;
	for (int i = 0; i < numOfpeople; i++) {
		if (people[i].name.substr(0, name.length()) == name) {
			ID.push_back(i);
		}

	}
	if (ID.size() > 1) {
		cout << "Found multiple users with same username: " << endl << endl;
		for (int i = 0; i < ID.size(); i++) {
			cout << i << ": " << "NAME: " << std::setw(11) << people[ID[i]].name << std::setw(10) << " AGE: " << std::setw(3) << people[ID[i]].age << endl;
		}
		int choice;
		cout << "Which one would you like to change: ";
		cin >> choice;
		cout << endl;
		string OldName = people[ID[choice]].name;
		int OldAge = people[ID[choice]].age;
		people[ID[choice]].age = NewAge;
		people[ID[choice]].name = NewName;
		cout << OldName << " has been changed to " << people[ID[choice]].name << " and  age has been changed from " << OldAge << " to " << people[ID[choice]].age << endl;
	}
	else
	{

		int OldAge2 = people[ID[0]].age;
		string OldName2 = people[ID[0]].name;
		people[ID[0]].age = NewAge;
		people[ID[0]].name = NewName;
		cout << OldName2 << " has been changed to " << people[ID[0]].name << " and age has been changed from " << OldAge2 << " to " << people[ID[0]].age << endl;
	}

}




//Deletes all the users from the data-base(and from backup.txt) 
void Student::DeleteAll() {
	char choice;
	cout << "Are you sure you want to delete all the users in database?(Y/N): ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		for (int i = numOfpeople; i >= 0; i--) {
			people[i].name = "";
			people[i].age = 0;
			numOfpeople--;
		}
		numOfpeople = 0;
		cout << "Data-base has been cleared successfully" << endl<<endl;
	}
	else if (choice == 'N' || choice == 'n') {
		cout << "Nothing has been deleted" << endl<<endl;
	}
	else cout << "Aborted, please enter vaild choice" << endl<<endl;
}

//Diplays all the people currently in data-base
void Student::Print() {
	for (int i = 0; i < numOfpeople; i++) {
		cout << "NAME: " <<std::setw(11) << people[i].name << std::setw(10) << " AGE: " << std::setw(3) << people[i].age << endl;
	}
	cout << endl;

}

void Student::AdvancedDelete(string usrn) {
	vector <int> ID;
	for (int i = 0; i < numOfpeople; i++) {
		if (people[i].name.substr(0, usrn.length()) == usrn) {
			ID.push_back(i);
		}

	}
	if (ID.size() == 1) {
		Delete(people[ID[0]].name);
	}
	if (ID.size() > 1) {
		cout << "Found multiple users with same username: " << endl<<endl;
		for (int i = 0; i < ID.size(); i++) {
			cout<< i<< ": " << "NAME: " << std::setw(11) << people[ID[i]].name << std::setw(10) << " AGE: " << std::setw(3) << people[ID[i]].age << endl;
		}
		int choice;
		cout << "Which one would you like to delete or input -1 to delete all?(type the number of the username you would like to delete):  ";
		cin >> choice;
		cout << endl;
		if(choice > -1)DeleteForAdvance(ID[choice]);
		if (choice == -1) {
			for (int i = 0; i < ID.size() ; i++) {
				string NameToDelete = people[ID[i]].name;
				Delete(NameToDelete);
			}
		}
	}
}
void Student::DeleteForAdvance(int ID) {
	int id = ID;
	string User = people[id].name;
	int OldAge = people[id].age;
	if (id != 9999) {
		for (int i = id; i < numOfpeople; i++) {
			people[i].name = people[i + 1].name;
			people[i].age = people[i + 1].age;
		}
		numOfpeople--;
		cout << "User " << User << " with age " << OldAge << " has been deleted succesfully" << endl << endl;
	}
}

void Student::Sort() {
	vector<int> IDForSorting;
	vector<string> name;
	vector<int> ages;
	for (int upper = 0; upper <= 26; upper++){
		for (int lower = 0; lower <= 26; lower++) {
			for (int i = 0; i < numOfpeople; i++) {
				if (people[i].name[0] == char(97 + upper) && people[i].name[1] == char(97 + lower) && !SortHelper(IDForSorting, i)) {
					IDForSorting.push_back(i);
				}
				else if (people[i].name[0] == char(65 + upper) && people[i].name[1] == char(65 + lower) && !SortHelper(IDForSorting, i)) {
					IDForSorting.push_back(i);
				}
				else if (people[i].name[0] == char(65 + upper) && people[i].name[1] == char(97 + lower) && !SortHelper(IDForSorting, i)) {
					IDForSorting.push_back(i);
				}
				else if (people[i].name[0] == char(97 + upper) && people[i].name[1] == char(65 + lower) && !SortHelper(IDForSorting, i)) {
					IDForSorting.push_back(i);
				}
			}
		}
	}
	for (int i = 0; i < IDForSorting.size(); i++) {
		name.push_back(people[IDForSorting[i]].name);
		ages.push_back(people[IDForSorting[i]].age);
	}
	for (int i = 0; i < numOfpeople; i++) {
		people[i].name = name[i];
		people[i].age = ages[i];
	}
	cout << "Data-base has been successfully sorted by name" << endl<< endl;
}

bool Student::SortHelper(vector<int>& ID, int id) {
	for (int i = 0; i < ID.size(); i++){
		if(ID[i] == id) return true;
	}
	return false;
}

void Student::SortAge() {
	int Max = people[0].age;
	vector<int> IDForSorting;
	vector<string> name;
	vector<int> ages;
	for (int i = 0; i < numOfpeople; i++) {
		if (people[i].age > Max) {
			Max = people[i].age;
		}
	}
	for (int find = 0; find <= Max; find++) {
		for (int i = 0; i < numOfpeople; i++) {
			if (people[i].age == find) {
				IDForSorting.push_back(i);
			}
		}
	}
	for (int i = 0; i < IDForSorting.size(); i++) {
		name.push_back(people[IDForSorting[i]].name);
		ages.push_back(people[IDForSorting[i]].age);
	}
	for (int i = 0; i < numOfpeople; i++) {
		people[i].name = name[i];
		people[i].age = ages[i];
	}
	cout << "Data-base has been successfully sorted by age" << endl << endl;

}

void Student::Login() {
	PasswordAndUsernameSetter();
	string password = "";
	string username = "";
	bool Log_in = false;
	int trys = 3;
	while(!Log_in) {
		cout << "Enter username: ";
		cin >> username;
		cout << endl;
		cout << "Enter password: ";
		cin >> password;
		if (trys != 0) {
			if (password == LoginPassword && username == LoginUsername) {
				Log_in = true;
			}
			else
			{
				cout << "Wrong password or username. You have " << trys << " more tries" << endl<<endl;
				trys--;
			}
			
		}
		else if (trys == 0) {
			cout << "Too much tries have been attempted" << endl;
			exit(0);
		}
	}
	cout << "WELCOME BACK" << endl;
	start();
}

void Student::ChangePasswordAndUsername() {
	string OldPassword;
	string OldUsername;
	cout << "Please enter current password and username" << endl;
	cout << "Current username: ";
	cin >> OldUsername;
	cout << endl;
	cout << "Current Password: ";
	cin >> OldPassword;
	cout << endl;
	if (OldPassword == LoginPassword && OldUsername == LoginUsername) {
		string NewPassword;
		string NewUsername;
		cout << "New username: ";
		cin >> NewUsername;
		cout << endl;
		cout << "New password: ";
		cin >> NewPassword;
		PassAndUserUpdater(NewPassword, NewUsername);

	}
	else 
	{
		cout << "Incorrect password or username" << endl;

	}

}

void Student::PassAndUserUpdater(string password, string username) {
	fstream file;
	file.open("Password.txt", ios::in | ios::out | ios::trunc);
	file.close();
	file.open("Password.txt", ios::in | ios::out);
	if (file.fail()) {
		cout << "Contact Admin for help" << endl;
		exit(0);
	}
	if (file.is_open()) {
		file << password << "\n";
		file << username << "\n";
		file << "END";
		file.close();
	}
	const wchar_t* fileLPCWSTR = L"Password.txt"; // To avoid incompatibility
	int attr = GetFileAttributes(fileLPCWSTR);
	if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
		SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
	}

}

void Student::PasswordAndUsernameSetter() {
	string line;
	int count = 1;
	ifstream myfile("Password.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line) && !myfile.eof()) {
			
			if (count == 1) {
				LoginPassword = line;
			}
			if (count == 2) {
				LoginUsername = line;
			}
			count++;
		}
	}
	if (myfile.fail()) {
		exit(0);
	}
}

void Student::AgeCounter() {
	int total = 0;
	for (int i = 0; i < numOfpeople; i++) {
		total = total + people[i].age;
	}
	cout<<"total= "<< total << endl;
}


//(people[i].name[0] == char(65 + upper) && people[i].name[1] == char(65 + lower) && !SortHelper(IDForSorting, i)
//(people[i].name[0] == char(65 + upper) && people[i].name[1] == char(97 + lower) && !SortHelper(IDForSorting, i)
//(people[i].name[0] == char(97 + upper) && people[i].name[1] == char(65 + lower) && !SortHelper(IDForSorting, i)


int main() {
	Student User;
	User.Login();
	return 0;
}













//Dont worry about whats below, just scraped code
/*
string path = "C:\\Users\midya\Documents\writing from cool stuff code\"";
	string name = "";
	cout << "What do you want to name file?";
	cin >> name;

	age = stoi(line.substr(AgeID, LastAgeID));
	people[numOfpeople + 1].age = age;

	void Student::Sort() {
	list <string> Sort;
	vector <int> ages;
	for (int i = 0; i < numOfpeople; i++) {
		Sort.push_back(people[i].name);
	}
	Sort.sort();
	for (auto it = Sort.begin(); it != Sort.end(); it++) {
		ages.push_back(people[])
	}

}

int FinderForSort(string name, int age) {
	int result = 0;
	for (int i = 0; i < numOfpeople; i++) {
		if (people[i].name = name && people[i].age = age) {
			people[]
		}
	}
}
void Student::ChangePassword() {
	string NewPassword = "";
	string OldPassword = "";

}
*/