#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> map;

    for (int i = 0; i < s.size(); i++)
    {
      if (map.count(s[i]) == 0)
      {
        map[s[i]] = 1;
        continue;
      }

      map[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
      if (map.count(t[i]) == 0 || map[t[i]] == 0)
        return false;

      map[t[i]]--;
    }

    return true;
  }
};
