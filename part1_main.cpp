#include <iostream>

#include "part1.h"

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
    std::cout << "Exiting..." << std::endl;

    return 0;
}
