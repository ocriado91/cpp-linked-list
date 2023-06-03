#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <exception>

class ListNodeException:public std::exception
{
    public:
        ListNodeException(std::string message): message(message) {};
        const char* what() const throw() {return message.c_str();}
    private:
        std::string message;
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void append(int val) {

        // Find the last element in the list
        ListNode* current = this;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Append the new element to the end of the list
        current->next = new ListNode(val);
    }

    size_t size(){
        ListNode* current = this;
        size_t counter = 0;

        if (current != nullptr) {
            counter++;
        }

        // Check tail of linked list (NOTE: Add extra threshold counter to avoid
        // infinite loop)
        while (current->next != nullptr) {
            // Increment counter
            counter++;
            // Move to next node
            current = current->next;
        }

        return counter;
    }

    void insert(int val, const unsigned int position)
    {

        // Check position value
        if (position > this->size()+1) {
            std::string msg = "ERROR: Position value ("
                + std::to_string(position)
                + ") exceeds the size of list ("
                + std::to_string(this->size()) + ")";
            throw ListNodeException(msg);
            return;
        }

        // Save current pointer
        ListNode* current = this;

        // Create pointer with new value
        ListNode* newNode = new ListNode(val);

        // Check if insert into head position
        if (position == 0) {

            // Create a copy of head
            ListNode* head = new ListNode(current->val);
            head->next = current->next;

            // Transform head attributes
            current->val = val;
            current->next = head;
        } else {

            // Insert into no-head position
            int counter = 0;

            // Element by element until tail element
            while(current != nullptr && counter < 100) {

                // Node from previous position, points to newNode
                if (counter+1 == position) {
                    newNode->next = current->next;
                    current->next = newNode;
                }
                // Increment counter
                counter++;
                // Move to next element
                current = current->next;
            }
        }
    }

    std::string toString(std::string delimiter = ";")
    {
        std::string result = "[";
        ListNode* current = this;
        while (current != nullptr) {
            result += std::to_string(current->val);
            if (current->next != nullptr) {
                result += delimiter;
            }
            current = current->next;
        }

        result += "]";

        return result;
    }

    void remove(unsigned int position)
    {
        // Check position
        if (position > this->size()) {
            std::string msg = "ERROR: Position value ("
                + std::to_string(position)
                + ") exceeds the size of list ("
                + std::to_string(this->size()) + ")";
            throw ListNodeException(msg);
        }
        unsigned int counter = 0;
        ListNode* current = this;
        while (current != nullptr) {

            if (counter+1 == position) {
                current->next = current->next->next;
            }

            // Increment counter
            counter++;
            // Move to the next position
            current = current->next;
        }
    }
};

ListNode* vector2ListNode(std::vector<int>& data)
{
    ListNode* list = nullptr;
    for (auto it: data) {
        if (nullptr == list) {
            list = new ListNode(it);
        } else {
            list->append(it);
        }
    }

    return list;
}

ListNode* mergeTwoList(ListNode* list1, ListNode* list2)
{

    ListNode* mergedList = nullptr;
    while (list1 != nullptr && list2 != nullptr) {

        // Insert first value
        if (mergedList == nullptr) {
            mergedList = new ListNode(list1->val);
            mergedList->append(list2->val);
        } else {
            mergedList->append(list1->val);
            mergedList->append(list2->val);
        }

        // Move lists to next element
        list1 = list1->next;
        list2 = list2->next;
    }

    return mergedList;
}

#endif