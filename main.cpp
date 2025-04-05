#include <iostream>

bool is_power_of_2_loop(int);
bool is_power_of_2_nonloop(int);
void test_power();
bool prime(int);
void test();
class Fraction;


int main() {

    //PROBLEM 1 PART 1: power of 2 loop
    int num;
    test_power();
    bool result = is_power_of_2_loop(num);
    if (result == true) {
        printf("%d is a power of 2\n", num);
    } else {
        printf("%d is not a power of 2\n", num);
    }
    //PROBLEM 1 PART 2: power of 2 nonloop
    bool answer = is_power_of_2_nonloop(num);
    if (answer == true) {
        printf("%d is a power of 2\n", num);
    } else {
        printf("%d is not a power of 2\n", num);
    }

    //PROBLEM 2
    int val;
    bool result2 = prime(val);
    if (result2 == true) {
        printf("PASS\n", val);
    } else {
        printf("FAIL\n", val);
    }

    //PROBLEM 3
    int numerator;
    int denominator;
    test();

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

//used Google to help me make the test (I didn't know how)
void test_power() {
    bool result1, result2;
    int test_values[] = {1,2,3,4,5,6,7,8,15,16,31,32,33,100};
    bool correct[] = {false,true,false,true,false,false,false,true,false,true,false,true,false,false};
        for (int i=0;i<14;i++) {
            result1 = is_power_of_2_loop(test_values[i]);
            result2 = is_power_of_2_nonloop(test_values[i]);
            if (result1 == correct[i] && result2 ==correct[i]) {
                std::cout << "PASS" << std::endl;
            } else {
                std::cout << "FAIL" << std::endl;
            }
        }
    return;
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
    return false;
}

class Fraction {
    public:
    int numerator;
    int denominator;


    Fraction(int numerator, int denominator) {
        to_string();
    }

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    bool operator == (Fraction && other) {
        return this->numerator == other.numerator && this->denominator == other.denominator;
    }

    Fraction reduce(Fraction in) {
        int divider = 2;
        while (divider <= in.numerator && divider <= in.denominator) {
            if (in.numerator % divider == 0 && in.denominator % divider == 0) {
                in.numerator/=divider;
                in.denominator/=divider;
                continue;
            }
            divider++;
        }
        return in;
    }
};

void test () {
    Fraction inputs [3] = {Fraction (1,2), Fraction (2,4), Fraction (4,2)};
    Fraction outputs [3] = {Fraction(1,2), Fraction(2,1), Fraction (3,4)};
}
