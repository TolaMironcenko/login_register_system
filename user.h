//
// Created by tola on 07.08.22.
//

#ifndef FCPP_USER_H
#define FCPP_USER_H


class User {
private:
    string username;
    string password;
public:
    User();
    User(string username, string password);
    User(string username, string password1, string password2);
    void setpassword(string password);
    void setpassword(string password1, string password2);
    void setusername(string username);
    void setpassword(string oldpassword, string oldpassword1, string newpassword1, string newpassword2);
};


#endif //FCPP_USER_H
