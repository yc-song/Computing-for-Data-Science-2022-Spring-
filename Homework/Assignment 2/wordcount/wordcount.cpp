#include "wordcount.h"
#include <iostream>
#include <sstream>
#include <map>
#define MAX_WORDS 30

void wordcount(std::string sentences) {
    // store number of total words
    unsigned int total_words = 0;
    std::map<std::string, int> word_count_map;
    std::map<std::string, int>::iterator it;
    std::string s;
    // TODO: calculate word counts
    std::stringstream stream(sentences);
    while (stream >> s) {
        total_words++;
        std::pair<std::map<char, int>::iterator, bool> ret;
        if (ret.second == false) {
            word_count_map[s] ++;
        }
        else { word_count_map.insert(std::pair<std::string, int>(s, 1)); }
    }
    for (it = word_count_map.begin(); it != word_count_map.end(); it++)
    {
        if (it->second == 1) std::cout << "Word \"" << it->first << "\" appears once."<<std::endl;
        else if (it->second ==2) std::cout << "Word \"" << it->first << "\" appears twice." << std::endl;
        else std::cout << "Word \"" << it->first << "\" appears "<<it->second<<" times." << std::endl;

        //std::cout << it->first    // string (key)
        //    << ':'
        //    << it->second   // string's value 
        //    << std::endl;
    }

    std::cout << "Total number of words: " << total_words << std::endl;

    // TODO: print number of appearances for each word
}
