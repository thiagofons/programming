#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
  void printVector(vector<int> &v)
  {
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
  }

public:
  vector<int> plusOne(vector<int> &digits)
  {
    int size = digits.size();
    int i = size - 1;

    if (digits[i] < 9)
    {
      digits[i]++;
      return digits;
    }

    digits[i--] = 0;
    while (i >= 0)
    {
      if (digits[i] < 9)
      {
        digits[i]++;
        break;
      }

      digits[i--] = 0;
    }

    if (i >= 0)
      return digits;

    vector<int> newDigits(size + 1, 0);
    newDigits[0] = 1;

    return newDigits;
  }
};

int main()
{
  Solution s;

  vector<int> v = {8, 9, 9, 9};

  vector<int> result = s.plusOne(v);

  for (int i : result)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}