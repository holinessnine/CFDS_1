#include <iostream>
// #include "main function"
int main() {

int start, end;

std::cout << "Find prime number within a range:\n";
std::cout << "--------------------------------------\n";
std::cout << "-> The start of the range: ";
std::cin >> start;
std::cout << "-> The end of the range: ";
std::cin >> end;
std::cout << "The prime numbers between " << start << " and " << end << " are:\n";

for (start; start<=end; start++) {
    int check = 0;
    if (start == 1)
        continue;
    for (int i=1; i <= start; i++){
        if (start%i == 0)
            check += 1;
    }
    if (check == 2)
        std::cout << start << " ";
}

std::cout << "\n";
return 0;
}