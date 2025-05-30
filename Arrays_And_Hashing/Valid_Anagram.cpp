#include <iostream>
#include <string>
#include <map>

/*
Given two strings "s" and "t", return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
*/

bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) { //first check if they are the same length
        return false;
    }
    //recommended time complexity is O(n+m), which typically indicates two seperate data structures of some type
    //since all we want is character frequency, we can use a counter using a hashmap
    std::map<char,int> frequencyS;
    std::map<char,int> frequencyT;
    for (int i = 0; i < s.length(); i++) { //for loops to provide counters for all characters
        frequencyS[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++) {
        frequencyT[t[i]]++;
    }
    for (auto i : frequencyS) { //loop through map and use S keys to look up in T. No need to check any other keys as length is already verified.
        if (frequencyS[i.first] != frequencyT[i.first]) {
            return false;
        }
    }
    return true; //false is never reached, so we can verify they are anagrams

}

int main() {
  std::string yes1 = "racecar";
  std::string yes2 = "carrace";
  std::string no = "jar";

  std::cout << isAnagram(yes1,yes2) << std::endl << isAnagram(yes1,no) << std::endl; //should print 1 then 0

  return 0;
}