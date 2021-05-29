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
};
