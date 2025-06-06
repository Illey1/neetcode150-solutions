#include <iostream>
#include <vector>
#include <unordered_map>
/*
Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.
*/

std::vector<int> twoSum(std::vector<int> nums, int target) {
  std::unordered_map<int,int> sum; //hashmap for constant look up. we will fill this with every element we iterate over. key is the value from nums, index is the value in the hashmap
  for (int i = 0; i < nums.size(); i++) {
    int difference = target - nums[i]; // since the answer is guaranteed, we just need to find the value of the index we're finding. target - anyindex will return a valid index's value
    if (sum.find(difference) != sum.end()) { // check if the difference is already in the map. if it is, return its index, along with the current
      return {sum[difference], i};
    }
    sum[nums[i]] = i; // if not, add it to the map, mapping the value to the key
  }
}

int main() {
  std::vector<int> test{1,2,3,4,5,6};
  std::vector<int> printed_solution = twoSum(test,4);
  for ( int i : printed_solution) {
    std::cout << i << " "; // will print 0 2, which are the indices that contain 1 and 3, which equal 4.
  }
  return 0;
}