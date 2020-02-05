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
	
}

int main(){
	
	return 0;
}