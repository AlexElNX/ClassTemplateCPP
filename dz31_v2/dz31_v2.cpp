#include <iostream>
#include "Array.h"

int main()
{

    Array<int> arr(5);
    Array<int> arr2(2);


    std::cout << "Array 1:\n";
    arr.printArray();
    std::cout << "\n\n\n";

    arr.addElement(10);
    std::cout << "Array 1:\n";
    arr.printArray();
    std::cout << "\n\n\n";
;

    std::cout << "\n\nSpecified element: " << arr[5] << "\n\n";
    arr.setSize(10, 2);
    arr.addElement(11);
    arr.addElement(12);
    arr.addElement(13);
    arr.addElement(14);
    std::cout << "Array 1:\n";
    arr.printArray();
    std::cout << "\n\n\n";

    std::cout << "Upper bound: " << arr.getUpperBound() << std::endl;
    arr.removeAll();

    arr.printArray();
    std::cout << "\n\n\n";

    std::cout << "Capacity: " << arr.getCapacity() << std::endl;
    arr.addElement(1);
    arr.addElement(2);
    arr.addElement(3);
    arr.freeExtra();
    std::cout << "Capacity: " << arr.getCapacity() << std::endl;

    std::cout << "Array 1:\n";
    arr.printArray();
    std::cout << "\n\n\n\n";

    arr2.addElement(777);
    arr2.addElement(888);
    arr2.addElement(999);

    std::cout << "Array 2:\n";
    arr2.printArray();
    std::cout << "\n\n\n\n";

    arr.append(arr, arr2);

    arr.printArray();
    std::cout << "\n\n\n\n";

    arr.insterAt(6, 50);
    arr.printArray();
    std::cout << "\n\n\n\n";


    arr.getData();
    if (arr.setAt(2, 999) == -1) return -1;
    std::cout << "\n\n\n\n";
    arr.printArray();

    arr.removeAt(2);
    std::cout << "\n\n\n\n";
    arr.printArray();

    arr.setSize(20, 5);
    std::cout << "\n\n\n\n";
    arr.printArray();
    

   
}
