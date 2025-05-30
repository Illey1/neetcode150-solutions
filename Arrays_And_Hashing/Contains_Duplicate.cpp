#include <vector>
#include <set>
#include <iostream>

/*
Given an integer array "nums", return true if any value appears more than once in the array, otherwise return false.
*/

bool hasDuplicate(std::vector<int>& nums) {
  std::set<int> duplicates; //load vector into set
  for (int i = 0; i < nums.size(); i++) {
    if (duplicates.count(nums[i]) != 0) { //check if value is in the set, if yes, return true
      return true;
    } else {
      duplicates.insert(nums[i]); //since we did not return true, we add the value
    }
  }
  return false;
}

int main () {
  std::vector<int> yes = {1,2,3,4,6,5,6};
  std::vector<int> no = {1,2,3,4,5,6};

  std::cout << hasDuplicate(yes) << std::endl; //should print 1
  std::cout << hasDuplicate(no) << std::endl;  //should print 0

  return 0;
}