#include <algorithm>
#include "User.h"

using std::find;

User::User(string user_id, string pass, Privilege pri)
    : id(user_id),
      passwd(pass),
      privilege(pri) {}

void User::add_post(Post *p)
{
    my_post_list.push_back(p);
}

void User::delete_post(Post *p)
{
    my_post_list.erase(find(my_post_list.begin(), my_post_list.end(), p));
}
