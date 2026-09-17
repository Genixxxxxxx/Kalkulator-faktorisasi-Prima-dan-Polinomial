#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getIntegerInput() {
    int value;
    while (true) {
    	system("cls");
    	std::cout << "Pilih operasi yang ingin dilakukan: \n";
        std::cout << "1. Faktorisasi prima\n";
        std::cout << "2. Penyelesaian persamaan kuadrat \n";
        std::cout << "3. Keluar\n";
        std::cout << "Masukkan pilihan (1, 2, atau 3): ";
        std::cin >> value;

        // Check if the input is a valid integer
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        } else if (std::cin.peek() != '\n') {
            // If there's extra input that isn't part of the integer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the input
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
            return value; // Valid integer, break out of the loop
        }
    }
}

int BgetIntegerInput() {
    int apa;
    while (true) {
    	system("cls");
    	cout << "Masukkan bilangan yang ingin difaktorisasi: ";
    	cin >> apa;

        // Check if the input is a valid integer
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        } else if (std::cin.peek() != '\n') {
            // If there's extra input that isn't part of the integer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the input
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
            return apa; // Valid integer, break out of the loop
        }
    }
}

void getThreeDoubles(double &d1, double &d2, double &d3) {
	system("cls");
    std::cout << "Masukkan nilai a, b, dan c (dalam persamaan ax^2 + bx + c = 0): \n";
    double value;
    for (int i = 0; i < 3; ++i) {
        while (true) {
            std::cout << "Masukkan angka ke-" << (i + 1) << ": ";
            std::cin >> value;

            if (std::cin.fail() || (i == 0 && value == 0)) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                system("cls");
                std::cout << "Masukkan nilai a, b, dan c (dalam persamaan ax^2 + bx + c = 0): \n";
                i = -1;
                break;
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard trailing input
                std::cout << "Masukkan nilai a, b, dan c (dalam persamaan ax^2 + bx + c = 0): \n";
                system("cls");
                i = -1;
                break;
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character
                if (i == 0) d1 = value;
                if (i == 1) d2 = value;
                if (i == 2) d3 = value;
                break; // Valid double input, move to next one
            }
        }
    }
}

// Fungsi untuk melakukan faktorisasi prima
std::vector<int> primeFactorization(int n) {
    std::vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) { 
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

// Fungsi untuk menyelesaikan persamaan kuadrat menggunakan rumus abc
void solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Akar-akar persamaan kuadrat adalah: " << root1 << " dan " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "Akar persamaan kuadrat adalah: " << root << std::endl;
    } else {
        std::cout << "Persamaan tidak memiliki akar real." << std::endl;
    }
}

int main() {
    while (true) {
    	system("cls");
        std::cout << "Pilih operasi yang ingin dilakukan: \n";
        std::cout << "1. Faktorisasi prima\n";
        std::cout << "2. Penyelesaian persamaan kuadrat \n";
        std::cout << "3. Keluar\n";
        std::cout << "Masukkan pilihan (1, 2, atau 3): ";
        int choice = getIntegerInput();
        
        if (choice == 1) {
            std::cout << "Masukkan bilangan yang ingin difaktorisasi: ";
            int number = BgetIntegerInput();
            std::vector<int> factors = primeFactorization(number);
            std::cout << "Faktor prima dari " << number << " adalah: ";
            for (int factor : factors) {
                std::cout << factor << " ";
            }
            std::cout << std::endl;
            system("PAUSE");
        } else if (choice == 2) {
            double a, b, c;
            std::cout << "Masukkan nilai a, b, dan c (dalam persamaan ax^2 + bx + c = 0): ";
            getThreeDoubles(a,b,c);
            solveQuadraticEquation(a, b, c);
            system("PAUSE");
        } else if (choice == 3) {
            std::cout << "Keluar dari program." << std::endl;
            break;
        } else {
            std::cout << "Pilihan tidak valid!" << std::endl;
        }
        std::cout << std::endl;
        
    }

    return 0;
}

