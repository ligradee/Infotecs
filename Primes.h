#ifndef PRIMES_H
#define PRIMES_H
#include <set>
#include <iostream>
class Primes
{

private:
	std::set<int> numbers;
	uint32_t max;
	
public:
	Primes(uint32_t max_value){
		max = max_value;
		for (int i = 1; i <= max; i++){
			if (isPrime(i) == 1){
				array.insert(i);
			}
		}
	}

	Primes(){
		max = 0;
	}

	bool isPrime(int n){
		if (n > 1){
			for (int i = 2; i < n; i++){
				if(n % i == 0){
					return false;
				}
			}
			return true;
		}
		else
			return false;
	}


	uint32_t size(){
		return array.size();
	}

}
#endif
