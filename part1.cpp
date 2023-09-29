#include <iostream>

#include "part1.h"

// Function to add a new element to the list
void List::addElement(std::string value) 
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to display the elements in the list
void List::displayList() 
{
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

//function to check if the user wants to add or display the list at any point
void List::addOrDisplay()
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



