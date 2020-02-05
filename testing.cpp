#include <iostream>
#include "Primes_test.h"
class TestPrimes {

public:
	Primes num;
	uint32_t count_test;
	void SIZE_TEST(uint32_t expected){
		uint32_t size = num.size();
		if(size == expected){
			std::cout << "Test passed." << std::endl;
			count_test++;
		}
		else{
			std::cout << "Test don't passed." << std::endl;
		}
	}

	void OPERATOR_TEST(uint32_t index, uint32_t expected){
		if (num[index] == expected){
			std::cout << "Test passed." << std::endl;
			count_test++;
		}
		else{
			std::cout << "Test don't passed." << std::endl;
		}
	}
	void EMPTY_CONSTRUCTOR_TEST() {
		std::cout << "	~~~~~~~    EMPTY CONSTRUCTOR TEST  ~~~~~~~" << std::endl;
		new(&num) Primes;
    	SIZE_TEST(0);
	}

	void BORDER_CONSTRUCTOR_TEST() {
		std::cout << "	~~~~~~~    BORDER CONSTRUCTOR TEST  ~~~~~~~" << std::endl;
		new(&num) Primes(10);
		SIZE_TEST(4);
		new(&num) Primes(20);
		SIZE_TEST(8);
		new(&num) Primes(30);
		SIZE_TEST(10);
		new(&num) Primes(40);
		SIZE_TEST(12);
		new(&num) Primes(50);
		SIZE_TEST(15);
	}

	void COPY_CONSTRUCTOR_TEST(){
		std::cout << "	~~~~~~~    COPY CONSTRUCTOR TEST  ~~~~~~~" << std::endl;
		new(&num) Primes(50);
		Primes test1 = num;
		FIND_TEST(test1);
		new(&num) Primes;
		Primes test2 = num;
		FIND_TEST(test2);
	}

	void MOVING_CONTAINER_TEST(){
		std::cout << "	~~~~~~~    MOVING CONTAINER TEST  ~~~~~~~" << std::endl;
		new(&num) Primes(50);
		uint32_t size = num.size();
		Primes test = std::move(num);
		if((test.size() == size) && (num.size() == 0)){
			std::cout << "Test passed." << std::endl;
			count_test++;
		}
		else{
			std::cout << "Test don't passed." << std::endl;
		}
		new(&num) Primes;
		size = num.size();
		Primes test2 = std::move(num);
		if((test2.size() == size) && (num.size() == 0)){
			std::cout << "Test passed." << std::endl;
			count_test++;
		}
		else{
			std::cout << "Test don't passed." << std::endl;
		}
		
	}
	void INSERT_TEST() {
		std::cout << "	~~~~~~~    INSERT TEST  ~~~~~~~" << std::endl;
		new(&num) Primes;
		num.insert(2);
		OPERATOR_TEST(0, 2);
		num.insert(5);
		OPERATOR_TEST(1, 5);
		num.insert(7);
		OPERATOR_TEST(2, 7);
		num.insert(11);
		OPERATOR_TEST(3, 11);
		num.insert(17);
		OPERATOR_TEST(4,17);
	}

	void ERASE_TEST() {
		std::cout << "	~~~~~~~    ERASE TEST  ~~~~~~~" << std::endl;
		new(&num) Primes(20);
		num.erase(2);
		SIZE_TEST(7);
		num.erase(5);
		SIZE_TEST(6);
		num.erase(7);
		SIZE_TEST(5);
		num.erase(11);
		SIZE_TEST(4);
		num.erase(17);
		SIZE_TEST(3);
	}
}

int main(){
	
	return 0;
}