//
// Created by tola on 07.08.22.
//

#include "user.h"
#include "termcolor.hpp"

User::User() {
    username = "";
    password = "";
}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

User::User(string username, string password1, string password2) {
    if (password1 == password2) {
        this->username = username;
        this->password = password1;
    }else {
        cout << termcolor::red << "passwords do not match!\n";
    }
}

void User::setusername(string username) {
    this->username = username;
}

void User::setpassword(string oldpassword, string oldpassword1, string newpassword1, string newpassword2) {
    if (oldpassword == oldpassword1) {
        if (newpassword1 == newpassword2) {
            this->password = newpassword1;
        }else {
            cout << termcolor::red << "passwords do not match!\n";
        }
    }else {
        cout << termcolor::red << "wrong old password\n";
    }
}

void User::setpassword(string password) {
    this->password = password;
}

void User::setpassword(string password1, string password2) {
    if (password1 == password2) {
        this->password = password1;
    }
}