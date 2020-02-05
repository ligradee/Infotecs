#ifndef PRIMES_H
#define PRIMES_H
#include <set>
#include <iostream>
#include <iterator>
#include <utility>
#include <fstream>
#include <exception>
/*! \brief This is class-container of the prime numbers */
class Primes
{

private:
	std::set<uint32_t> numbers;
	std::set<uint32_t>::iterator it;
	uint32_t max;
	
public:
	/*! An upboard constructor */
	Primes(uint32_t max_value){
		if(max_value < 2){
			throw std::invalid_argument("You cannot create a container with this border.");
		}
		max = max_value;
		for (uint32_t i = 1; i <= max; i++){
			if (isPrime(i) == 1){
				numbers.insert(i);
			}
		}
	}

	/*! An empty constructor */
	Primes(){
		max = 0;
	}

	/*! Copy constructor */
	Primes(const Primes &primes): max(primes.max), numbers(primes.numbers){
	}

	/*! Moving constructor */
	Primes(Primes&& primes): max(primes.max), numbers(primes.numbers){
		primes.max = 0;
		primes.numbers.clear();
	}

	/*! Method checks: this number is prime or not */
	bool isPrime(const uint32_t n) const{
		if (n > 1){
			for (uint32_t i = 2; i < n; i++){
				if(n % i == 0){
					return false;
				}
			}
			return true;
		}
		else
			return false;
	}

	/*! Method outputs the container into given file */
	void print(const uint32_t flag, const std::string name_file){
		std::ofstream num;
		num.open(name_file);
		uint32_t i = 1;
		if (flag == 0){
			if (size() == 0){
				std::cout << "This container is empty" << std::endl;
			}
			else{
				for (it = numbers.begin(); it != numbers.end(); ++it){
					num << *it << std::endl;
				}
			}	
		}
		if (flag == 1){
			if (size() == 0){
				std::cout << "This container is empty" << std::endl;
			}
			else{
				for (it = numbers.begin(); it != numbers.end(); ++it){
					auto super_prime = [this](uint32_t i){ if(isPrime(i) == 1){return 1;} return 0;};
					if (super_prime(i) == 1) num << *it << std::endl;
					i++;
				}
			}
		}
		if (flag == 2){
			if (size() == 0){
				std::cout << "This container is empty" << std::endl;
			}
			else{
				for (it = numbers.begin(); it != numbers.end(); ++it){
					auto sophies_prime = [this](){ if(isPrime(2*(*it)+1) == 1){return 1;} return 0;};
					if (sophies_prime() == 1) num << *it << std::endl;
				}
			}
		}
		if ((flag != 0) && (flag != 1) && (flag != 2)){
			throw std::invalid_argument("There is no such command.");
		}
		num.close();
	}

	/*! Method outputs the container on display */
	void print(const uint32_t flag){
		uint32_t i = 1;
		if (flag == 0){
			if (size() == 0){
				std::cout << "This container is empty" << std::endl;
			}
			else{
				for (it = numbers.begin(); it != numbers.end(); ++it){
					std::cout << *it << " ";
				}
			}
		}
		if (flag == 1){
			if (size() == 0){
				std::cout << "This container is empty" << std::endl;
			}
			else{
				for (it = numbers.begin(); it != numbers.end(); ++it){
					auto super_prime = [this](uint32_t i){ if(isPrime(i) == 1){return 1;} return 0;};
					if (super_prime(i) == 1) std::cout << *it << " ";
					i++;
				}
			}
		}
		if (flag == 2){
			if (size() == 0){
				std::cout << "This container is empty" << std::endl;
			}
			else{
				for (it = numbers.begin(); it != numbers.end(); ++it){
					auto sophies_prime = [this](){ if(isPrime(2*(*it)+1) == 1){return 1;} return 0;};
					if (sophies_prime() == 1) std::cout << *it << " ";
				}
			}
		}
		if ((flag != 0) && (flag != 1) && (flag != 2)){ 
			throw std::invalid_argument("There is no such command.");
		}
	}

	/*! Method memorizes default sequence of prime numbers */
	void find(){
		max = 100;
		numbers.clear();
		for (uint32_t i = 1; i <= max; i++){
			if (isPrime(i) == 1){
				numbers.insert(i);
			}
		}
	}

	/*! Method selects a sequence with the boards you gave */
	void find(const uint32_t max_value, const uint32_t flag){
		if (flag == 1){
			max = max_value;
			numbers.clear();
			for (uint32_t i = 1; i <= max; i++){
				if (isPrime(i) == 1){
					numbers.insert(i);
				}
			}
		}
		if (flag == 2){
			max = 0;
			uint32_t max_count = max_value;
			numbers.clear();
			uint32_t count = 0;
			uint32_t i = 1;
			while (count < max_count){
				if (isPrime(i) == 1){
					numbers.insert(i);
					count++;
				}
				i++;
			}
		}
		if((flag != 1) && (flag == 2)){
			throw std::invalid_argument("There is no such command.");
		}
	}

	std::pair<std::set<uint32_t>::iterator,bool> insert(const uint32_t& value){
		if ((max == 0) & (isPrime(value) == 1)){
			numbers.insert(value);
			it = numbers.find(value);
			return std::make_pair(it, 0);
		}
		else{
			std::cout << "The number don't insert." << std::endl;
			it = numbers.begin();
			return std::make_pair(it, 1);
		}
	}

	/*! Method for popping values from the container */
	size_t erase(const uint32_t &value) {
	return nums.erase(value);
	}

	/*! Iterator begin */
	std::set<uint32_t>::iterator begin(){
		return it = numbers.begin();
	}

	/*! Iterator end */
	std::set<uint32_t>::iterator end(){
		return it = numbers.end();
	}
	
	/* Operator helps us to take values */
	uint32_t operator[](const uint32_t index){
		if ((index < 0) || (index > numbers.size())){
			throw std::invalid_argument("Invalid argument");
		}
		it = numbers.begin();
		for(uint32_t i = 0; i < index; i++){
			it++;
		}
		return *it;
	}

	/*! Returns container size */
	uint32_t size() const{
		return numbers.size();
	}

	/*! Clean method */
	void clean(){
		numbers.clear();
	}

};
#endif
