#include <iostream>
#include "ladder.h"

using namespace std;

int main(){
    
    set<string> word_list = {"awake", "aware", "ware", "were", "wee", "see", "seep", "sleep"};
    // set<string> word_list;
    // load_words(word_list, "../src/words.txt");
    string begin_word = "awake";
    string end_word = "sleep";
    vector<string> result = generate_word_ladder(begin_word, end_word, word_list);

    print_word_ladder(result);
}
