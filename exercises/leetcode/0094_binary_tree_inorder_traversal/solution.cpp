#include <leetcode/tree_node.hpp>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
private:
  void aux(TreeNode *root, vector<int> &v)
  {
    if (!root)
      return;

    aux(root->left, v);
    v.push_back(root->val);
    aux(root->right, v);
  }

public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> v;

    aux(root, v);

    return v;
  }
};