#include <iostream>
#include "Array.h"

int main()
{

    Array<int> arr(10);
    Array<int> arr2(2);



    arr.printArray();
    std::cout << "\n\n\n";

    arr.addElement(10);

;


    std::cout << "\n\nSpecified element: " << arr[10] << "\n\n";
    //arr.setSize(10, 2);
    arr.addElement(11);
    arr.addElement(12);
    arr.addElement(13);
    arr.addElement(14);
    arr.printArray();
    std::cout << "\n\n\n";

    std::cout << "Upper bound: " << arr.getUpperBound() << std::endl;

    arr.removeAll();

    arr.printArray();
    std::cout << "\n\n\n";
    
    std::cout << "Capacity: " << arr.getCapacity() << std::endl;
    arr.freeExtra(5);

    std::cout << "Capacity: " << arr.getCapacity() << std::endl;

    arr.printArray();
    std::cout << "\n\n\n\n";



    arr.Append(arr, arr2);
    arr.printArray();

    arr.getData();
    if (arr.setAt(2, 999) == -1) return -1;

    std::cout << "\n\n\n\n";
    arr.printArray();

    arr.removeAt(2);
    std::cout << "\n\n\n\n";
    arr.printArray();


    arr.setSize(26 + 1, 1);
    std::cout << "\n\n\n\n";
    arr.printArray();
    

   
}
