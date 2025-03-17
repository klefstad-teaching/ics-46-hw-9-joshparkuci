#include <iostream>
#include <string>
#include <unordered_set>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg){
    cerr << word1 << " " << word2 << " " << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    // no idea what this means
    int str1_len = str1.length();
    int str2_len = str2.length();
    
    vector<int> v1(str2_len +1);
    vector<int> v2(str2_len +1);

    if (abs(str1_len - str2_len) > d) {
        return false;
    }

    for(int i = 0; i<=str1_len; ++i){
        v1[i] = i;
    }

    for(int i = 0; i<=str2_len; ++i){
        v2[0] = i;

        for(int j = 1; j <= str2_len; ++j){
            int del_cost = v1[j+1] + 1;
            int in_cost = v2[j] + 1;
            // Note: if str1[i-1] == str2[j-1], subcost = v1[j] else subcost = v1[j] +1
            int sub_cost = (str1[i - 1] == str2[j - 1]) ? v1[j - 1] : v1[j - 1] + 1;
            v2[j] = min(del_cost, min(in_cost, sub_cost));
        }
        swap(v1, v2);
    }
    return v1[str2_len] <= d;
}
bool is_adjacent(const string& word1, const string& word2){
    // check if two words are one letter off. NOTE THAT THIS IS TWO CASES
    // cat -> bat  &&  cat -> chat (is this real)
    // NOTE: both of these cases CANNOT occur at the same time as each other
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    unordered_set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string end = ladder.back();
    
        for(string word : word_list){

            if(is_adjacent(end_word, word)){

                if(visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if(word == end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);

    if(!in){
        throw runtime_error("file no open :(");
    }
    string word;
    while(in >> word){
        word_list.insert(word);
    }
    
    in.close();
}
void print_word_ladder(const vector<string>& ladder){
    for (string word : ladder) {
        cout << word << " ";
    }
    cout << endl;
}
void verify_word_ladder(){
    return;
}