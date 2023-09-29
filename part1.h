#ifndef PART1_H_
#define PART1_H_

class Node 
{
public:
    std::string data;
    Node* next;

    Node(std::string value) : data(value), next(nullptr) {}
};

class List
{
private:
    Node* head;
public:
    List() : head(nullptr) {}
    void addElement(std::string value);
    void displayList();
    void addOrDisplay();
    // Destructor to free memory when the list is destroyed
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};


#endif
