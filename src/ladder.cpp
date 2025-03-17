#include <iostream>
#include <string>
#include <unordered_set>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg){
    cerr << word1 << " " << word2 << " " << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int size1 = str1.size();
    int size2 = str2.size();
    string longer, shorter;
    if(size1 > size2){
        longer = str1;
        shorter = str2;
    }else{
        longer = str2;
        shorter = str1;
    }
    if(longer.size() - shorter.size() > 1){
        return false;
    }
    int count = 0;
    for(int i = 0, j = 0; i < shorter.size() && j < longer.size(); ++i, ++j){
        if(count >d) return false;
        if(shorter[i] != longer[j]){
            ++count;
            ++j;
        }
    }
   
    return count <= d;
}
bool is_adjacent(const string& word1, const string& word2) {

    if(word1.size() != word2.size()){
        return edit_distance_within(word1, word2, 1);
    }else{
        int count = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                ++count;
            }
        }
        return count <= 1;
    }
    return false;
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last = ladder.back();

        for(const string& word : word_list){

            if(is_adjacent(last, word)){
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