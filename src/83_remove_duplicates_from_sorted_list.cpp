#include "./lib/ListNode.hpp"

using namespace std;

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *previous = head;
    ListNode *actual = head->next;

    while (actual)
    {
      if (previous->val == actual->val)
      {
        actual = actual->next;
        continue;
      }

      previous->next = actual;
      previous = actual;
      actual = actual->next;
    }

    previous->next = actual;

    return head;
  }
};