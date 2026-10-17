#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool hasDuplicate(vector<int> &nums)
  {
    unordered_set<int> set;

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];

      if (set.count(num) > 0)
        return true;

      set.insert(num);
    }
    return false;
  }
};