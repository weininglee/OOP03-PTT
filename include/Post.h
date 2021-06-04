#pragma once
#include <string>

using std::string;

class Post
{
    string title;
    string content;

public:
    const string bsid; //Board scope id
    const string author_id;

    Post(string id, string _title, string author, string _content = "")
        : bsid(id), title(_title), author_id(author), content(_content)
    {
    }

    const string get_title() const { return title; }
    const string get_content() const { return content; }
};
