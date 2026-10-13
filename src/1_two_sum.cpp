#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];

      if (map.count(num)) return  {i, map[num]};

      int diff = target - num;

      map[diff] = i;
    }

    return {};
  }
};

int main () {
  Solution s;

  vector<int> nums = {3,3};
  int target = 6;

  vector<int> v = s.twoSum(nums, target);

  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}