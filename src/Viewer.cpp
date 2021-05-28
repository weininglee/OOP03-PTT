#include <iostream>
#include <string>
#include "Viewer.h"
#include "BoardManager.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

Viewer::Viewer(BoardManager *bm) : board_manager(*bm)
{
}

void Viewer::start()
{
    render_menu();
    while (1)
    {
        Command cmd = read_cmd();
        run_cmd(cmd);
    }
}

Command Viewer::read_cmd()
{
    fflush(stdin);
    cout << "$ ";
    string s;
    getline(cin, s);

    vector<string> args;
    while (s.find(' ') != -1)
    {
        args.push_back(s.substr(0, s.find(' ')));
        s = s.substr(s.find(' ') + 1);
    }
    args.push_back(s);

    Command cmd;
    cmd.id = args[0];
    args.erase(args.begin());
    cmd.args = args;

    return cmd;
}

void Viewer::run_cmd(Command cmd)
{
    if (cmd.id == "logout")
    {
        board_manager.logout();
    }
    else if (cmd.id == "board" && cmd.args.size() == 0)
    {
        render_board_list();
    }
    else if (cmd.id == "board" && cmd.args.size() == 1)
    {
        board_manager.select_board(cmd.args[0]);
    }
    else if (cmd.id == "?" && cmd.args.size() == 0)
    {
        render_help();
    }
    else
    {
        cout << "Unknown command, enter again." << endl;
    }
}

void Viewer::render_menu()
{
    string username, password;
    cout << "Enter user id: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    board_manager.login(username, password);
}

void Viewer::render_login_success()
{
    cout << "Login success!" << endl;
}

void Viewer::render_login_fail()
{
    cout << "Login failed." << endl;
}

void Viewer::render_board_list()
{
    cout << endl
         << "Board List" << endl
         << "==========" << endl;
    for (auto &board : board_manager.get_board_list())
    {
        cout << board.id << endl;
    }
}

void Viewer::render_help()
{
    cout << "logout" << endl
         << "board" << endl
         << "board [board id]" << endl;
}
