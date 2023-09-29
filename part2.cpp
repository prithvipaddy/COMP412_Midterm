#include <iostream>

// Node class to represent elements in the list
class Node 
{
public:
    std::string data;
    Node* next;

    Node(std::string value) : data(value), next(nullptr) {}
};

// List class to manage the linked list
class List 
{
private:
    Node* head;

public:
    List() : head(nullptr) {}

    // Function to add a new element to the list
    void addElement(std::string value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the elements in the list
    void displayList() 
    {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    //function to check if the user wants to add or display the list at any point
    void addOrDisplay()
    {
        bool flagInput = true, flagDisplay = true;
        std::string opt;
        while (flagInput)
        {
            try{
            std::cout << "Would you like to add an element to the linked list? (Y/N): " << std::endl;
            std::cin >> opt;
            if(opt == "Y" || opt == "y")
            {
                flagInput = true;
                std::string val;
                std::cout << "Enter the element to add: " << std::endl;
                std::cin >> val;
                addElement(val);
            }
            else if(opt == "N" || opt == "n")
            {
                flagInput = false;
            }
            else
                throw opt;
        }
        catch(std::string opt)
        {
            std::cout << "The input recieved doesn't match any of the options. " << std::endl;
        }}
        while (flagDisplay)
        {
            try{
            std::cout << "Would you like to view the current list? (Y/N): " << std::endl;
            std::cin >> opt;
            if(opt == "Y" || opt == "y")
            {
                flagDisplay = true;
                displayList();
            }
            else if(opt == "N" || opt == "n")
            {
                flagDisplay = false;
            }
            else
                throw opt;
        }
        catch(std::string opt)
        {
            std::cout << "The input recieved doesn't match any of the options. " << std::endl;
        }}


    }

    List createCopy() 
    {
        List copyList;
        // Using the default assignment operator
        copyList = *this;
        return copyList;
    }

    // Destructor to free memory when the list is destroyed
    ~List() 
    {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() 
{    
    List myList;
    bool flag = true;
    std::string opt;
    
    myList.addOrDisplay();

    while (flag)
    {
        try{
        std::cout << "Would you like to exit the program? (Y/N): " << std::endl;
        std::cin >> opt;
        if(opt == "Y" || opt == "y")
        {
            flag = false;
        }
        else if(opt == "N" || opt == "n")
        {
            flag = true;
            myList.addOrDisplay();
        }
        else
            throw opt;
    }
    catch(std::string opt)
    {
        std::cout << "The input recieved doesn't match any of the options. " << std::endl;
    }}

    // Display the elements in the list
    std::cout << "The final list: "; 
    myList.displayList();
    
    List copyList = myList.createCopy();

    std::cout << "The copied list: " ;
    copyList.displayList();

    std::cout << "Exiting..." << std::endl;
    return 0;
}
