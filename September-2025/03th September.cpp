class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            head = curr;
            curr = curr->prev;
        }

        return head;
    }
};