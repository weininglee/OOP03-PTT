#pragma once
#include <string>

using std::string;

enum class Privilege
{
    Guest,
    Member,
    Admin
};

class User
{
    string passwd;
    Privilege privilege;

public:
    const string id;

    User();
    User(string _username, string _password, Privilege _privilege);

    bool verify(string user_id, string _passwd)
    {
        return (user_id == id && _passwd == passwd);
    }
    Privilege get_privilege() { return privilege; }
};
