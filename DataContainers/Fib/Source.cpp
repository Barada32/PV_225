#include <iostream>
#include <chrono>
#include <ctime>

long fibonacci(unsigned n)
{
	if (n < 2) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	auto start = std::chrono::steady_clock::now();
	time_t t_start = time(NULL);
	clock_t c_start = clock();
	std::cout << "f(42) = " << fibonacci(42) << '\n';
	auto end = std::chrono::steady_clock::now();
	time_t t_end = time(NULL);
	clock_t c_end = clock();
	std::chrono::duration<double> elapsed_seconds = end  - start;
	std::cout << "elapsed time chrono:  " << elapsed_seconds.count() << "s\n";
	std::cout << "elapsed time time():  " << t_end - t_start << "s\n";
	std::cout << "elapsed time clock(): " << double(c_end-c_start)/CLOCKS_PER_SEC << "s\n";
}