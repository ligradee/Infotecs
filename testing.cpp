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

}

int main(){
	
	return 0;
}