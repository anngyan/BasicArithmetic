#include <iostream>

int add(int a, int b) {
    int carry = 0;
    while(b != 0) {
        carry = a & b;
        // std::cout << carry << std::endl;
        a = a ^ b;
        // std::cout << a << std::endl;
        b = carry << 1;
        // std::cout << b << std::endl << std::endl;
    }

    return a;
}

int mul(int a, int b) {
    int product = 0;
    int sign = 1;
    
    if((a >= 0 && b >=0) || (a < 0 && b < 0)) {
        sign = 1;
    }
    else {
        sign = -1;
    }

    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;

    while (b > 0) {
        product = add(product, a);
        b = add(b, -1);
    }

    if(sign == -1) {
        product = -product;
    }
    return product;
}

int divide(int a, int b) {
    int quantity = 0;
    int sign = 1;

    if((a >= 0 && b >=0) || (a < 0 && b < 0)) {
        sign = 1;
    }
    else {
        sign = -1;
    }

    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;

    while (a >= b) {
        quantity = add(quantity, 1);
        a = add(a, -b);
    }
    
    quantity = mul(quantity, sign);
    return quantity;
}

int main() {

    int a = 0, b = 0;
    std::cout << "Input the first integer: ";
    std::cin >> a;
    std::cout << "Input the second integer: "; 
    std::cin >> b;

    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a * b = " << mul(a, b) << std::endl;
    std::cout << "a / b = " << divide(a, b) << std::endl;

    return 0;
}
