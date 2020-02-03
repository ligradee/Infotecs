#include<iostream>
#include "Primes_test.h"
 
 void print_menu(){
 	std::cout << std::endl;
 	std::cout << "            ///  MENU:  ///" << std::endl;
 	std::cout << std::endl;
 	std::cout << "3. Find the sequence of Prime numbers (by default in the range up to 100.)." << std::endl;
 	std::cout << "  " << "3.1 - Find the sequence of Prime numbers in a range with a specified maximum." << std::endl;
 	std::cout << "  " << "3.2 - Find for a sequence of Prime numbers with a specified numbers count." << std::endl;
 	std::cout << "4. Printing numbers to the console (by default all numbers)." << std::endl;
 	std::cout << "  " << "4.1 - Printing only the sequence 'Primes with a prime subscript' to the console." << std::endl;
 	std::cout << "  " << "4.2 - Printing only the sequence 'Sophie Germain Primes' to the console." << std::endl;
 	std::cout << "5. Printing numbers in the file (by default all numbers)." << std::endl;
 	std::cout << "  " << "5.1 - Printing only the sequence 'Primes with a prime subscript' in the file." << std::endl;
 	std::cout << "  " << "5.2 - Printing only the sequence 'Sophie Germain Primes' in the file." << std::endl;
 	std::cout << "6. Insert a number into a container." << std::endl;
 	std::cout << "7. To clean the container." << std::endl;
 	std::cout << std::endl;
 	std::cout << "Choose the act you need:" << std::endl;
 }
 void print_main_menu(){
 	std::cout << "            ///  MENU:  ///" << std::endl;
 	std::cout << std::endl;
 	std::cout << "0. Exit." << std::endl;
 	std::cout << "1. Create an empty container." << std::endl;
 	std::cout << "2. Create a container of Prime numbers with maximum boarder." << std::endl;
 	std::cout << std::endl;
 	std::cout << "Choose the act you need:" << std::endl;
 }
 
 int main(){
 	print_menu();
 	return 0;

 }
