#include "Board.h"

Board::Board(string id) : id(id)
{
    post_list.push_back(Post(post_list.size(), "The very origin post", "root"));
}
