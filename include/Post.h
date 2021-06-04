#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

enum class Weight
{
    push,
    dislike,
    comment
};

struct Comment
{
    string author;
    string content;
    Weight weight;
    Comment(Weight _weight, string _content, string _author)
        : weight(_weight), content(_content), author(_author) {}
};

class Post
{
    string title;
    string content;
    vector<Comment> comment_list;

public:
    const string bsid; //Board scope id
    const string author_id;

    Post(string id, string _title, string author, string _content = "")
        : bsid(id), title(_title), author_id(author), content(_content)
    {
    }

    const string get_title() const { return title; }
    const string get_content() const { return content; }
    const vector<Comment> &get_comments() const { return comment_list; }

    void add_comment(Comment &&c);
};
