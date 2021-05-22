#pragma once
#include <vector>
#include "User.h"
#include "Board.h"
#include "Viewer.h"

using std::vector;

class BoardManager
{
    vector<User> user_list;
    vector<Board> board_list;
    Viewer viewer;

public:
    BoardManager();

    void start();
};
