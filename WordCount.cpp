// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(pair<string, int> a : table[i]){
			total = total + a.second;
		}
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	int total = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(pair<string, int> a : table[i]){
			total++;
		}
	}
	return total;
}

int WordCount::getWordCount(std::string word) const {
	string validWord = makeValidWord(word);
	if(validWord != ""){
		size_t bucketIndex = hash(validWord);
		for(pair<string, int> a : table[bucketIndex]){
			if(a.first == validWord){
				return a.second;
			}
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string validWord = makeValidWord(word);
	if(validWord != ""){
		size_t bucketIndex = hash(validWord);
		for(size_t i = 0; i < table[bucketIndex].size(); i++){
			if(table[bucketIndex][i].first == validWord){
				table[bucketIndex][i].second++;
				return table[bucketIndex][i].second;
			}
		}
		pair<string, int> newWord{validWord, 1};
		table[bucketIndex].push_back(newWord);
		return 1;
	}
	return 0;
}

int WordCount::decrWordCount(std::string word) { 
	string validWord = makeValidWord(word); 
	if(validWord != ""){ 
		size_t bucketIndex = hash(validWord); 
		for(size_t i = 0; i < table[bucketIndex].size(); i++){ 
			if(table[bucketIndex][i].first == validWord){ 
				if(table[bucketIndex][i].second == 1){ 
					table[bucketIndex].erase(table[bucketIndex].begin()+i); 
					return 0; } 
				else{
					table[bucketIndex][i].second--; 
					return table[bucketIndex][i].second; 
				}
			} 
		} 
	}
	return -1;
}

bool WordCount::isWordChar(char c) {
    int charVal = int(c);
    if ((charVal >= 65 && charVal <= 90) || (charVal >= 97 && charVal <= 122)) {
        return true;
    }
    return false;
}

std::string WordCount::makeValidWord(std::string word) {
	string final = "";
	for(size_t i = 0; i < word.length(); i++){
		char curr = word[i];
		if(isWordChar(curr)||curr == '-' || curr == '\''){
			if(isWordChar(curr)){
				if (curr >= 65 && curr <= 90) {  
    				curr = curr + 32;            
				}
			}
			final += curr;
		}
	}

	string clearedF = "";
	for (size_t i = 0; i < final.length(); i++) {
		char curr = final[i];
		if (isWordChar(curr)) {
			clearedF += curr;
		} 
		else if (curr == '-' || curr == '\'') {
			if (i > 0 && i < final.length() - 1 && isWordChar(final[i - 1]) && isWordChar(final[i + 1])) {
			clearedF += curr;
		}
}
	}
	return clearedF;
}
