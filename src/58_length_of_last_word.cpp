#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int i = s.size() - 1, count = 0;

    while (i >= 0)
    {
      cout << s[i] << endl;

      if (s[i--] == ' ')
      {
        if (count > 0)
          break;

        continue;
      }
      count++;
    }

    return count;
  }
};

int main()
{
  Solution solution;

  string s = "luffy is still joyboy";

  cout << solution.lengthOfLastWord(s) << endl;

  return 0;
}