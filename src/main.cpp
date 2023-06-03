#include <iostream>
#include <vector>

#include "LinkedList.hpp"

int main()
{
    std::vector<int> list1_data{1,3,5,7};

    // Transform vector to ListNode pointer structure
    ListNode* list1 = vector2ListNode(list1_data);

    // Get size of ListNode
    std::cout << "Detected Linked List of size = " << list1->size() << std::endl;

    // Insert new elements
    try {
        list1->insert(14,1);
        list1->insert(15,1);
        list1->insert(10,2);
        list1->insert(12,0);
        list1->insert(120,18);
        list1->insert(120,8);
    } catch (ListNodeException& e) {
        std::cout << "Caught exception " << e.what() << std::endl;
    }

    // Get size after inserting elements
    std::cout << "Detected Linked List of size = " << list1->size() << std::endl;

    // Convert to string
    std::cout << "List 1 = " << list1->toString() << std::endl;


    std::vector<int> list2_data{2,4,6,8};
    ListNode* list2 = vector2ListNode(list2_data);

    ListNode* list3 = mergeTwoList(list1, list2);

    std::cout << "List 3 = " << list3->toString() << std::endl;

    std::cout << "List 1 before remove = " << list1->toString() << std::endl;
    list1->remove(2);
    std::cout << "List 1 after remove = " << list1->toString() << std::endl;


}