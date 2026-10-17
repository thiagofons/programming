#include <iostream>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 1)
      return n;

    long int a = 1, b = 1, curr;

    for (int i = 2; i <= n; i++)
    {
      curr = a + b;
      b = a;
      a = curr;
    }

    return curr;
  }
};

int main()
{
  Solution s;

  int n = 44;

  cout << s.climbStairs(n) << endl;

  return 0;
}