#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
      // Middle is calculated summing from the start instead of the average
      // between start and end
      //
      // middle = (start + end) / 2           <= wrong
      // middle = start + (end - start) / 2   <= right
      //
      int middle = start + (end - start) / 2;

      if (nums[middle] == target)
        return middle;
      else if (nums[middle] < target)
        start = middle + 1;
      else if (nums[middle] > target)
        end = middle - 1;
    }

    return start;
  }
};

int main()
{
  Solution s;

  vector<int> nums = {1, 3, 5, 6};
  int target = 0;

  cout << s.searchInsert(nums, target) << endl;

  return 0;
}