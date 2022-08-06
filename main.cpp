#include <iostream>
#include <fstream>
#include "termcolor.hpp"

using namespace std;

struct user {
	string username;
	string password;
};

struct usercin {
	string username;
	string password1;
	string password2;	
};

int main() {
	while (1) {

		cout << termcolor::white << "1. Register" << endl;
		cout << termcolor::white << "2. Login" << endl;
		cout << termcolor::white << "3. All users" << endl;
		cout << termcolor::white << "4. Exit" << endl;

		int what;
		cin >> what;

		switch(what) {
			case 1:
				{
					usercin userin1;
					cout << termcolor::white << "username: ";
					cin >> userin1.username;
					cout << termcolor::white << "password1: ";
					cin >> userin1.password1;
					cout << termcolor::white << "password2: ";
					cin >> userin1.password2;

					ofstream fout("users.txt", std::ios::app);

					if (userin1.password1 == userin1.password2) {
						fout << userin1.username << " " << userin1.password1 << "\n";
						cout << termcolor::green << "registration complete\n\n";
					}else {
						cout << termcolor::red << "passwords do not match\n";
					}

					break;
				}
			case 2:
				{
					user user1;
					user userin;
					ifstream fin("users.txt");
					bool haveuser = false;

					cout << termcolor::white << "username: ";
					cin >> user1.username;
					cout << termcolor::white << "password: ";
					cin >> user1.password;

					while(!fin.eof()) {
						char buffer[1024];
						for (int i = 0; i < 2; i++) {
							fin >> buffer;
							if (i == 0) {
								userin.username = buffer;
							}else {
								userin.password = buffer;
							}
						}
						if (userin.username == user1.username && userin.password == user1.password) {
							haveuser = true;
						}
					}
					fin.close();
					if (haveuser) {
						cout << termcolor::green << "you are logged\n\n";
					}else {
						cout << termcolor::red << "don't have this user\n\n";
					}
					break;
				}
			case 3:
				{
					ifstream fin("users.txt");
					char buffer[1024];
					string out[2] = {"tola", "Simba28082020"};
					cout << '\n';
					int k = 0;
					while (!fin.eof()) {
						for (int i = 0; i < 2; i++) {
							fin >> buffer;
							out[i] = buffer;
						}
						cout << termcolor::white << "[" << k << "]: " << "username: " << out[0] << " " << "password: " << out[1] << endl;
						k++;
					}
					cout << '\n';
					break;
				}
			case 4:
				cout << termcolor::green << "exited\n";
				exit(0);
		}
	}
}