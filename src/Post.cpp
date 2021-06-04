#include <algorithm>
#include "Post.h"

using std::find_if;

void Post::add_comment(Comment &&c)
{
    //if not first +-, set to c
    if (find_if(
            comment_list.begin(), comment_list.end(),
            [&c](Comment _c)
            {
                return (_c.author == c.author) &&
                       (_c.weight == Weight::push || _c.weight == Weight::dislike);
            }) !=
        comment_list.end())
    {
        c.weight = Weight::comment;
    }
    comment_list.push_back(c);
}
