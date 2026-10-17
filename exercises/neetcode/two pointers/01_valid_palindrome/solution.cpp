#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {
    int start = 0, end = s.size() - 1;

    while (start < end)
    {
      if (!isalnum(s[start]))
      {
        start++;
        continue;
      }
      if (!isalnum(s[end]))
      {
        end--;
        continue;
      }

      if (tolower(s[start]) != tolower(s[end]))
        return false;

      start++;
      end--;
    }

    return true;
  }
};

int main()
{
  Solution solution;

  string s = "Was it a car or a cat I saw?";

  cout << (solution.isPalindrome(s) ? "true" : "false") << endl;

  return 0;
}