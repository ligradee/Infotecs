#ifndef PRIMES_H
#define PRIMES_H
#include <set>
#include <iostream>
#include <iterator>
#include <utility>
#include <fstream>
class Primes
{

private:
	std::set<uint32_t> numbers;
	std::set<uint32_t>::iterator it;
	uint32_t max;
	
public:
	Primes(uint32_t max_value){
		max = max_value;
		for (uint32_t i = 1; i <= max; i++){
			if (isPrime(i) == 1){
				numbers.insert(i);
			}
		}
	}

	Primes(){
		max = 0;
	}

	bool isPrime(uint32_t n){
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

	void print(){
		std::ofstream num;
		num.open("Print.txt");
		for (it = numbers.begin(); it != numbers.end(); ++it){
			num << *it << std::endl;
		}
		num.close();
	}

	void print(){
		for (it = numbers.begin(); it != numbers.end(); ++it){
			std::cout << *it << " ";
		}
	}

	void find(){
		max = 100;
		numbers.clear();
		for (uint32_t i = 1; i <= max; i++){
			if (isPrime(i) == 1){
				numbers.insert(i);
			}
		}
	}

	void find(uint32_t max_value, std::string flag){
		if (flag == "i"){
			max = max_value;
			numbers.clear();
			for (uint32_t i = 1; i <= max; i++){
				if (isPrime(i) == 1){
					numbers.insert(i);
				}
			}
		}
		if (flag == "ii"){
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
	}

	std::pair<std::set<uint32_t>::iterator,bool> insert(const uint32_t& value){
		if ((max == 0) & (isPrime(value) == 1)){
			numbers.insert(value);
			it = numbers.find(value);
			return std::make_pair(it, 0);
		}
		else
			it = numbers.begin();
			return std::make_pair(it, 1);
	}

	std::set<uint32_t>::iterator begin(){
		return it = numbers.begin();
	}

	std::set<uint32_t>::iterator end(){
		return it = numbers.end();
	}
	
	uint32_t operator[](uint32_t index){
		it = numbers.begin();
		for(uint32_t i = 0; i < index; i++){
			it++;
		}
		return *it;
	}

	uint32_t size(){
		return numbers.size();
	}

};
#endif
