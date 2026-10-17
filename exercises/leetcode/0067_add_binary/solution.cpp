#include <vector>
#include <iostream>
#include <string>

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
  string addBinary(string a, string b)
  {
    string result = "";

    int i_a = a.size() - 1, i_b = b.size() - 1, carry = 0;

    while (i_a >= 0 && i_b >= 0)
    {
      int val_a = a[i_a] - '0', val_b = b[i_b] - '0';

      int partial = val_a ^ val_b + carry;
      carry = val_a && val_b;

      result += (partial + '0');
    }
  }
};

int main()
{
  Solution s;

  return 0;
}