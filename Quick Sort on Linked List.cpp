class Solution {
  public:
    Node* split(Node* head) {
        Node* fast = head;
        Node* slow = head;
        Node* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = nullptr;
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        Node* mid = split(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
        return merge(left, right);
    }

    Node* quickSort(Node* head) {
        return mergeSort(head);
    }
};
