#include "BoardManager.h"

BoardManager::BoardManager() : viewer(this)
{
}

void BoardManager::start()
{
    viewer.render_menu();
}
