#include <iostream>
#include <string>
#include <iomanip>
#include "Viewer.h"
#include "BoardManager.h"
#include "Board.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::left;
using std::right;
using std::setw;
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

    else if (cmd.id == "addboard" && cmd.args.size() == 1)
    {
        board_manager.add_board(cmd.args[0]);
    }
    else if (cmd.id == "delboard" && cmd.args.size() == 1)
    {
        board_manager.delete_board(cmd.args[0]);
    }
    else
    {
        render_help();
    }
}

void Viewer::render_menu()
{
    string username, password;
    cout << "Menu" << endl
         << "====" << endl
         << "Enter user id(`new` for register): ";
    cin >> username;
    if (username == "new")
    {
        do
        {
            cout << "Enter user id:";
            cin >> username;
            cout << "Enter password:";
            cin >> password;
        } while (!board_manager.sign_up(username, password));
        board_manager.login(username, password);
    }
    else
    {
        cout << "Enter password: ";
        cin >> password;
        //guest
        board_manager.login(username, password);
    }
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
        cout << board.get_id() << endl;
    }
}

void Viewer::render_help()
{
    cout << "Command tutorial" << endl
         << "================" << endl
         << "logout" << endl
         << "board" << endl
         << "board [board id]" << endl
         << "addboard [board id]" << endl
         << "delboard [board id]" << endl;
}

void Viewer::render_permission_denied()
{
    cout << "Permission denied." << endl;
}

void Viewer::render_board_not_found()
{
    cout << "Board not found." << endl;
}

void Viewer::render_account_already_exist()
{
    cout << "Account already exist." << endl;
}

void Viewer::render_board_already_exist()
{
    cout << "Board already exist." << endl;
}

void Viewer::render_board(const Board &target_board)
{
    cout << "Board: " << target_board.get_id() << endl
         << "========================================================================" << endl;
    for (auto &post : target_board.get_post_list())
    {
        cout << setw(5) << post.bsid << " "
             << setw(50) << left << post.get_title() << " "
             << setw(15) << right << post.author_id << endl;
    }
}
