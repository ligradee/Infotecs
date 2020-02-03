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
 void menu(){
 	uint32_t flag = 3;
 	std::cout << "		  HI!   " << std::endl;
 	print_main_menu();
 	std::cin >> flag;
 	if (flag == 0){
 		std::cout << "	Goodbye!   " << std::endl;
 		exit(0);
 	}
 	Primes numbers;
 	if (flag == 1){
 	std::cout << "	Good! Container created." << std::endl;
 	}
 	if (flag == 2){
 		std::cout << "Enter the maximum range limit: " << std::endl;
 			uint32_t max;
 			try{
 				std::cin >> max;
 				new(&numbers) Primes(max);
 			}
 			catch(std::invalid_argument){
 				std::cout << "The maximum must be greater 1." << std::endl;
 				std::cout << "Enter the maximum range limit again: " << std::endl;
 				std::cin >> max;
 				Primes numbers(max);
 				std::cout << numbers.size();
 			}
 		std::cout << "	Good! Container created. " << std::endl;
 	}
 	if((flag != 0) && (flag != 1) && (flag != 2)){
 		std::cout << " Container don't create." << std::endl;
 		std::cout << " Choose the act you need:" << std::endl;
 		std::cin >> flag;
 	}
 	print_menu();
 	std::cin >> flag;
 	while(flag != 0){
 		switch(flag){
 			case 3:{
 				uint32_t flag_res = 0;
 				std::cout << "If you want to perform a standard action enter 0 otherwise enter the action number." << std::endl;
 				std::cin >> flag_res;
 				if (flag_res == 0){
 				numbers.find();
 				std::cout << numbers.size() << std::endl;
 				}
 				if (flag_res == 1){
 					uint32_t max;
 					std::cout << "Enter the maximum range limit:" << std::endl;
 					std::cin >> max;
 					if (max > 1){
 						numbers.find(max, 1);
 					}
 					else{
 						while(max < 1){
 						std::cout << "The maximum must be greater 1." << std::endl;
 						std::cout << "Enter the maximum range limit again: " << std::endl;
 						std::cin >> max;
 						}
 						numbers.find(max,1);
 					}
 				}
 				if (flag_res == 2){
 					uint32_t max_count;
 					std::cout << "Enter the maximum numbers count." << std::endl;
 					std::cin >> max_count;
 					if (max_count > 0){
 						numbers.find(max_count, 2);
 					}
 					else{
 						while(max_count < 1){
 						std::cout << "The maximum numbers count must be greater 0." << std::endl;
 						std::cout << "Enter the maximum numbers count again: " << std::endl;
 						std::cin >> max_count;
 						}
 						numbers.find(max_count,2);
 					}
 				}
 				if((flag_res != 0) && (flag_res != 1) && (flag_res !=2)){
 					try{
 						uint32_t max;
 						std::cout << "Enter the maximum." << std::endl;
 						std::cin >> max;
 						numbers.find(max, flag_res);
 					}
 					catch(std::invalid_argument){
 						std::cout << "There is no such command." << std::endl;
 					}
 				}
 				break;
 			}

 			case 4:{
 				uint32_t flag_res = 0;
 				std::cout << "If you want to perform a standard action enter 0, otherwise enter the action number." << std::endl;
 				std::cin >> flag_res;
 				try{
 					numbers.print(flag_res);
 				}
 				catch(std::invalid_argument){
 						std::cout << "There is no such command." << std::endl;
 				}
 				break;
 			}
 			case 5:{
 				uint32_t flag_res = 0;
 				std::string name_file;
 				std::cout << "Enter name file." << std::endl;
 				std::cin >> name_file;
 				std::cout << "If you want to perform a standard action enter 0, otherwise enter the action number." << std::endl;
 				std::cin >> flag_res;
 				try{
 					numbers.print(flag_res, name_file);
 				}
 				catch(std::invalid_argument){
 						std::cout << "There is no such command." << std::endl;
 				}
 				break;
 			}
 			case 6:{
 				uint32_t num;
 				std::cout << "Enter a number." << std::endl;
 				std::cin >> num;
 				numbers.insert(num);
 				break;
 			}
 			case 7:{
 				numbers.clean();
 				break;
 			}
 			break;
 		}
 		std::cout << std::endl;
 		std::cout << "Enter the number of the selected action:" << std::endl;
 		std::cin >> flag;
	}
}

 int main(){
 	menu();
 	return 0;

 }
