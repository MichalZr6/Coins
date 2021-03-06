//https://www.spoj.com/problems/COINS/

#include <iostream>
#include <map>

#define MAX_SIZE 100000000

static std::map<unsigned int, unsigned int> dp;

unsigned int set_dp(unsigned int n)
{
	if (n == 1)
		return 1;
	else if (n <= 11)
		return n;
	else if (n < MAX_SIZE && dp[n] != 0)
		return dp[n];
	else
	{
		if (n < MAX_SIZE)
		{
			dp[n] = set_dp(n / 4) + set_dp(n / 2) + set_dp(n / 3);
			return dp[n];
		}
		else
		{
			return set_dp(n / 4) + set_dp(n / 2) + set_dp(n / 3);
		}
	}
}

int main()
{
	int value, ntests = 0;
	while (ntests < 10 && std::cin >> value)
	{
		if (value < 0 || value > 1000000000)
			continue;
		std::cout << set_dp(value) << std::endl;
		ntests++;
	}

	return 0;
}
