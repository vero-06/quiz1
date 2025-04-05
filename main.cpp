#include <iostream>

bool is_power_of_2_loop(int);
bool is_power_of_2_nonloop(int);
bool prime(int);

int main() {

    //PROBLEM 1 PART 1: power of 2 loop
    int num;
    std::cout << "Enter a number to see if it is a power of 2: ";
    std::cin >> num;
    bool result = is_power_of_2_loop(num);
    if (result == true) {
        printf("%d is a power of 2 (loop method used)\n", num);
    } else {
        printf("%d is not a power of 2 (loop method used)\n", num);
    }
    //PROBLEM 1 PART 2: power of 2 nonloop
    bool answer = is_power_of_2_nonloop(num);
    if (answer == true) {
        printf("%d is a power of 2 (nonloop method used)\n", num);
    } else {
        printf("%d is not a power of 2 (nonloop method used)\n", num);
    }

    //PROBLEM 2
    int val;
    std::cout << "Enter a number to see if it is a prime number: ";
    std::cin >> val;
    bool result2 = prime(val);
    if (result2 == true) {
        printf("PASS\n", val);
    } else {
        printf("FAIL\n", val);
    }

    //PROBLEM 3


    return 0;
}

//loop
bool is_power_of_2_loop(int num) {
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
bool is_power_of_2_nonloop(int num) {
    if (num==1) {
        return true;
    } if (num%2==0) {
        return is_power_of_2_nonloop(num/2);
    }
    return false;
}

//prime
bool prime(int num) {
    if (num==1 || num==2) {
        return true;
    } else if (num<=0) {
        return false;
    } else {
        for (int i=2; i<=num; ++i) {
            if (num%i==0) {
                return false;
            } else {
                return true;
            }
        }
    }
}