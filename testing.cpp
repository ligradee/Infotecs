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
}

int main(){
	
	return 0;
}