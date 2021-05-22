#pragma once

class BoardManager;

class Viewer
{

    BoardManager *board_manager;

public:
    Viewer();
    Viewer(BoardManager *);
    void render_menu();
};
