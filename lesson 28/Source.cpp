#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void main() {
	string line;
	ifstream in;
	in.open("D:\\users.txt");
	cout << "________________________\n";
	string loginWrite, passWrite,loginCheck, passCheck;
	int check=0;
	int attempt = 3;

	cout << "Enter user: ";
	cin >> loginWrite;
	cout << "Enter password: ";
	cin >> passWrite;
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, loginCheck);
			getline(in, passCheck);
			if (loginWrite == loginCheck && passWrite == passCheck)
			{
				check = 1;
				break;
			}
			else if (loginWrite == loginCheck && passWrite != passCheck) {
				while (attempt !=0)
				{
					cout << "Password is incorrect! Try again!" << endl;
					cout << "Attemps: " << attempt << endl;
					cout << "\nEnter password for user "<<loginWrite<<": ";
					cin >> passWrite;
					if (loginWrite == loginCheck && passWrite != passCheck) {
						attempt--;
					}
					else {
						check = 1; 
						break;
					}
				}
			}
			if (check == 1) break;
			else if (attempt == 0) check = 2;
		}
	}
	char YesOrNo;
	if (check == 0) {
		cout << "Do you want create a new user? y/n ";
		cin >> YesOrNo;
		if (YesOrNo == 'y')
		{
			ofstream file("D:\\users.txt", ios_base::app);
			file << loginWrite << endl;
			file << passWrite << endl;
			file.close();
			cout << "Create is successfully!!" << endl;
		}
		else cout << "Goodbye!!" << endl;
	}
	else if (check == 1) cout << "Welcome!!";
	else cout << "Sorry, goodbye!!" << endl;
	in.close();
}