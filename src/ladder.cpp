#include <iostream>
#include <string>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg){
    cerr << word1 << " " << word2 << " " << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    return true;
}
bool is_adjacent(const string& word1, const string& word2){
    return false;
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    vector<string> v;
    v.push_back("apple");
    return v;
}
void load_words(set<string> & word_list, const string& file_name){
    return;
}
void print_word_ladder(const vector<string>& ladder){
    cout << "word ladder" << endl;
}
void verify_word_ladder(){
    return;
}