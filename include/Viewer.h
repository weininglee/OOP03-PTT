#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Command
{
    string id;
    vector<string> args;
};

class BoardManager;

class Viewer
{
    BoardManager &board_manager;

public:
    Viewer();
    Viewer(BoardManager *);

    void start();
    Command read_cmd();
    void run_cmd(Command cmd);

    void render_menu();
    void render_board_list();
    void render_login_success();
    void render_login_fail();
    void render_help();
    void render_permission_denied();
    void render_board_not_found();
    void render_account_already_exist();
};
