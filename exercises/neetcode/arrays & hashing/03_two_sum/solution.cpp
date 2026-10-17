#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i], diff = target - num;

      if (map.count(num) > 0)
      {
        if (i < map[i])
          return {i, map[i]};
        else
          return {map[i], i};
      }

      map[diff] = i;
    }

    return {};
  }
};
