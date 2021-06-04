#include <algorithm>
#include <string>
#include "Board.h"

Board::Board(string id) : id(id)
{
    post_list.push_back(
        Post(std::to_string(post_list.size()), "The very origin post", "root",
             "麥當勞的蘋果派 是我偶爾想到就會想吃一下的味道\n"
             "\n"
             "最近跟朋友吃麥當勞\n"
             "\n"
             "兩位好朋友都表示蘋果派跟屎一樣\n"
             "\n"
             "朋友說吃起來油耗味很重\n"
             "\n"
             "這我倒是從來沒感受到過\n"
             "\n"
             "我想其他不喜歡的人應該是因為肉桂味(？)\n"
             "\n"
             "(我吃肉桂派覺得噁心但很喜歡吉拿棒\n"
             "不知道我這樣算不算討厭肉桂)\n"
             "\n"
             "各位喜歡麥當勞的蘋果派嗎\n"
             "\n"
             "不過一路看他從25到28 現在漲到32了…"));
}

vector<Post>::iterator Board::find_post(string post_id)
{
    auto comp = [&post_id](Post &p)
    { return p.bsid == post_id; };
    return std::find_if(post_list.begin(), post_list.end(), comp);
}
