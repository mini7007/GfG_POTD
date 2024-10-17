class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Dummy nodes to simplify the logic
        Node* dummyA = new Node(0);  // Head for the first list
        Node* dummyB = new Node(0);  // Head for the second list

        Node* a = dummyA;
        Node* b = dummyB;
        Node* curr = head;
        bool toggle = true;  // To alternate between the two lists

        // Traverse the original list and alternate nodes between a and b
        while (curr) {
            if (toggle) {
                a->next = curr;
                a = a->next;
            } else {
                b->next = curr;
                b = b->next;
            }
            toggle = !toggle;
            curr = curr->next;
        }

        // Terminate both lists
        a->next = nullptr;
        b->next = nullptr;

        // Return the heads of the two lists (excluding dummy nodes)
        return {dummyA->next, dummyB->next};
    }
};
