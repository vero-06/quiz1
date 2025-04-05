#include <iostream>

bool is_power_of_2(int);

int main() {

    //PROBLEM 1 PART 1: power of 2 loop
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    bool result = is_power_of_2(num);
    if (result == true) {
        printf("%d is a power of 2", num);
    } else {
        printf("%d is not a power of 2", num);
    }
    return 0;




}

//loop
bool is_power_of_2(int num) {
    while (num!=1) {
        if (num%2==0) {
        num = num/2;
        } else {
            return false;
        }
    }
    return true;
}

//non-loop