#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<char, char> expected_previous = {
    {'V', 'I'},
    {'X', 'I'},
    {'L', 'X'},
    {'C', 'X'},
    {'D', 'C'},
    {'M', 'C'},
  };

  unordered_map<char, int> values = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

public:
  int romanToInt(string s) {
    int total = 0;
    char previous = '\0';

    for (int i = s.size() - 1; i >= 0; i--) {
      char letter = s[i];
      int value = values[letter];

      if (previous && letter == expected_previous[previous]) {
        total = total - value;
      } else {
        total += value;
      }
      
      previous = letter;
    }

    return total;
  }
};

int main () {
  Solution solution;

  string s = "MCMXCIV";

  cout << solution.romanToInt(s) << endl;
  
  return 0;
}