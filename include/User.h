#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Post;

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
    vector<Post *> my_post_list;

public:
    const string id;

    User();
    User(string _username, string _password, Privilege _privilege);

    bool verify(string user_id, string _passwd)
    {
        return (user_id == id && _passwd == passwd);
    }
    Privilege get_privilege() { return privilege; }
    void add_post(Post *p);
    void delete_post(Post *p);
};
