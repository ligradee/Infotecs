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

	void SITUATION_WITH_SIZE(){
		std::cout << "	~~~~~~~    SIZE TEST  ~~~~~~~" << std::endl;
		new(&num) Primes;
		SIZE_TEST(0);
		num.insert(2);
		SIZE_TEST(1);
		new(&num) Primes(30);
		SIZE_TEST(10);
	}

	void CLEAN_TEST(){
		std::cout << "	~~~~~~~    CLEAN TEST  ~~~~~~~" << std::endl;
		new(&num) Primes;
		if(num.size() == 0){
			num.insert(2);
		}
		if(num.size() > 0){
			num.clean();
		}
		SIZE_TEST(0);
		new(&num) Primes(1000);
		num.clean();
		SIZE_TEST(0);
		num.clean();
		SIZE_TEST(0);
	}

	void SITUATION_WITH_OPERATOR(){
		std::cout << "	~~~~~~~    OPERATOR[] TEST  ~~~~~~~" << std::endl;
		new(&num) Primes;
		num.insert(2);
		OPERATOR_TEST(0, 2);
		num.insert(3);
		OPERATOR_TEST(1 , 3);
		num.insert(5);
		OPERATOR_TEST(2, 5);
		new(&num) Primes(30);
		OPERATOR_TEST(9, 29);
		OPERATOR_TEST(6, 17);
		OPERATOR_TEST(8, 23);
	}

	void SITUATION_WITH_FIND() {
		std::cout << "	~~~~~~~    FIND TEST  ~~~~~~~" << std::endl;
	    Primes test(100);
	    num.find();
    	FIND_TEST(test);
    	num.clean();
	    new (&test) Primes(60);
    	num.find(60, 1);
	    FIND_TEST(test);
    	new (&test) Primes(100);
	    num.find(100, 1);
    	FIND_TEST(test);
	    new (&test) Primes(72);
    	num.find(20,2);
    	FIND_TEST(test);
    	new (&test) Primes(175);
    	num.find(40,2);
    	FIND_TEST(test);
	};

	void RUN_ALL_TESTS() {
		TestPrimes test;
		test.EMPTY_CONSTRUCTOR_TEST();
		test.BORDER_CONSTRUCTOR_TEST();
		test.COPY_CONSTRUCTOR_TEST();
		test.MOVING_CONTAINER_TEST();
		test.INSERT_TEST();
		test.SITUATION_WITH_SIZE();
		test.CLEAN_TEST();
		test.SITUATION_WITH_OPERATOR();
		test.ERASE_TEST();
		test.SITUATION_WITH_FIND();
		double precentage = test.count_test / 33 * 100;
		std::cout << "\nResult of all tests: " << test.count_test << "/37 (" << (uint32_t)precentage << "%)\n\n";
	}


	void FIND_TEST(Primes &test){
		uint32_t count = 0;
		for(uint32_t i = 0; i < num.size(); i++){
			if (num[i] == test[i]) count++;
		}
		SIZE_TEST(count);
	}

}

int main(){
	RUN_ALL_TESTS();
	return 0;
}