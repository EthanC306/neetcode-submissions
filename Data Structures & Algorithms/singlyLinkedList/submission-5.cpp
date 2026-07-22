struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode *cursor = head;
        for(int i = 0; i < index; i++){
            cursor = cursor -> next;
        }
        return cursor->val;
    }

    void insertHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    
    if(tail == nullptr){
        tail = newNode;
    }
    size++;
    }

    void insertTail(int val) {
        ListNode *newNode = new ListNode(val);

        if(tail == nullptr){ tail = newNode; head = newNode; }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    bool remove(int index) {
    if (index < 0 || index >= size) {   // out of range
        return false;
    }

    if (index == 0) {                   // removing the head
        ListNode *target = head;
        head = head->next;
        if (tail == target) {           // list had one node — tail dies too
            tail = nullptr;
        }
        delete target;
        size--;
        return true;
    }

    ListNode *previous = head;
    for (int i = 0; i < index - 1; i++) {
        previous = previous->next;
    }
    ListNode *target = previous->next;
    previous->next = target->next;

    if (tail == target) {
        tail = previous;
    }
    delete target;
    size--;
    return true;
}

    vector<int> getValues() {
        vector<int> values;
        ListNode *cursor = head;

       while(cursor != nullptr){
        values.push_back(cursor->val);
        cursor = cursor->next;
       }
       return values;
    }
private:
    ListNode *head;
    ListNode *tail;
    int size;
};