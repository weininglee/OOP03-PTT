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

public:
    const string id;
    const Privilege privilege;

    User();
    User(string, string, Privilege);

    inline bool verify(string user_id, string _passwd)
    {
        return (user_id == id && _passwd == passwd);
    }
};
