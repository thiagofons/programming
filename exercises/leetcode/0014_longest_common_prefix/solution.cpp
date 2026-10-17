#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    // Find the minimum length of the strings
    int minLen = strs[0].size();

    for (string &s : strs) {
      minLen = min(minLen, (int)s.size());
    }

    // Iterate until reach the minimum size 
    string res;
    for (int i = 0; i < minLen; i++) {
      char ch = strs[0][i];

      // For easch string, compare if is equal
      for (string &s : strs) {
        if (s[i] != ch) return res;
      }

      res.push_back(ch);
    }

    return res;
  }
};

int main () {
  Solution solution;

  vector<string> v = {"flower","flow","flight"};

  cout << solution.longestCommonPrefix(v) << endl;

  return 0;
}