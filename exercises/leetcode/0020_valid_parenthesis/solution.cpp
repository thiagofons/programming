#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
private:
  unordered_map<char, char> pairs = {
      {')', '('},
      {'}', '{'},
      {']', '['}};

public:
  bool isValid(string s)
  {
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
      char c = s[i];

      switch (c)
      {
      case '(':
      case '{':
      case '[':
        st.push(c);
        break;
      case ')':
      case '}':
      case ']':
        if (st.empty())
          return false;

        char top = st.top();

        if (pairs[c] != top)
        {
          return false;
        }

        st.pop();
        break;
      }
    }

    return st.size() == 0;
  }
};

int main()
{
  Solution solution;

  string s = "]";

  cout << (solution.isValid(s) ? "true" : "false") << endl;

  return 0;
}