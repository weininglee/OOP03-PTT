#include "BoardManager.h"

BoardManager::BoardManager() : viewer(this)
{
    user_list.push_back(Admin("root", "root"));
    board_list.push_back(Board("hello_world"));
    board_list.push_back(Board("8========D"));
}

void BoardManager::start()
{
    viewer.start();
}

void BoardManager::login(string user_id, string passwd)
{
    bool valid = false;
    for (auto &user : user_list)
    {
        if (user.verify(user_id, passwd))
        {
            valid = true;
            current_user = &user;
        }
    }
    if (valid)
    {
        viewer.render_login_success();
        viewer.render_board_list();
    }
    else
    {
        viewer.render_login_fail();
        viewer.render_menu();
    }
}

void BoardManager::logout()
{
    current_user = nullptr;
    viewer.render_menu();
}

void BoardManager::add_board(string board_id)
{
    if (current_user->privilege == Privilege::Admin)
    {
        board_list.push_back(Board(board_id));
    }
    else
    {
        viewer.render_permission_denied();
    }
}

void BoardManager::select_board(string board_id)
{
}

void BoardManager::delete_board(string board_id)
{
    if (current_user->privilege == Privilege::Admin)
    {
        for (int i = 0; i < board_list.size(); i++)
        {
            if (board_list[i].get_id() == board_id)
            {
                board_list.erase(board_list.begin() + i);
                return;
            }
        }
        viewer.render_board_not_found();
    }
    else
    {
        viewer.render_permission_denied();
    }
}
