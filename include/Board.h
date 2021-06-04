#pragma once
#include <string>
#include <vector>
#include "Post.h"

using std::string;
using std::vector;

class Board
{
    vector<Post> post_list;
    string id;

public:
    Board();
    Board(string id);

    string get_id() const { return id; }
    const vector<Post> get_post_list() const { return post_list; }
    vector<Post>::iterator find_post(string post_id);
    Post *add_post(string title, string author, string content);
};
