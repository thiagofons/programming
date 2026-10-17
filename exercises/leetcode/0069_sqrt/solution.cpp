#include <iostream>
#include <math.h>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x == 0 || x == 1)
      return x;

    int start = 1, end = x, mid = -1;

    while (start <= end)
    {
      mid = start + (end - start) / 2;

      if ((long)mid * mid > (long)x)
        end = mid - 1;
      else if (mid * mid == x)
        return mid;
      else
        start = mid + 1;
    }
    return round(end);
  }
};

int main()
{
  Solution s;

  int x = 8;

  cout << s.mySqrt(x) << endl;

  return 0;
}