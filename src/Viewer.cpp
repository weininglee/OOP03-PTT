#include <iostream>
#include <string>
#include <iomanip>
#include "Viewer.h"
#include "BoardManager.h"
#include "Board.h"
#include "Post.h"

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
    bool cont = true;
    while (cont)
    {
        Command cmd = read_cmd();
        cont = run_cmd(cmd);
    }
}

Command Viewer::read_cmd()
{
    cout << "$ ";
    string s;
    cin >> std::ws;
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

    if (cin.eof())
        cmd.id = "exit";
    return cmd;
}

bool Viewer::run_cmd(Command cmd)
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
    else if (cmd.id == "post" && cmd.args.size() == 1)
    {
        board_manager.select_post(cmd.args[0]);
    }
    else if (cmd.id == "addpost" && cmd.args.size() == 0)
    {
        string board, title, content, temp;
        cout << "Select board: ";
        cin >> board;
        cout << "Enter the title: ";
        cin >> std::ws;
        getline(cin, title);
        cout << "Enter contents:" << endl;
        cin >> std::ws;
        while (getline(cin, temp))
        {
            content += temp + "\n";
        }
        cin.clear();
        board_manager.add_post(board, title, content);
    }
    else if (cmd.id == "exit" && cmd.args.size() == 0)
    {
        return false;
    }
    else
    {
        render_help();
    }
    return true;
}

void Viewer::render_help()
{
    cout << "Command tutorial" << endl
         << "================" << endl
         << "logout" << endl
         << "board" << endl
         << "board [board id]" << endl
         << "addboard [board id]" << endl
         << "delboard [board id]" << endl
         << "post [post id]" << endl;
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

void Viewer::render_post(const Post &target_post)
{
    cout << "Post ID: " << target_post.bsid << endl
         << "Title: " << target_post.get_title() << endl
         << "Author: " << target_post.author_id << endl
         << endl
         << "---" << endl
         << endl
         << target_post.get_content() << endl;
}

void Viewer::render_login_success()
{
    cout << "Login success!" << endl;
}

void Viewer::render_login_fail()
{
    cout << "Login failed." << endl;
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

void Viewer::render_post_not_found()
{
    cout << "Post not found." << endl;
}

void Viewer::render_add_post_failed()
{
    cout << "Add post failed." << endl;
}
