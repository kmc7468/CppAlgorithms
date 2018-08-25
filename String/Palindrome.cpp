#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main()
{
	std::string string;
	std::cin >> string;

	std::transform(string.begin(), string.end(), string.begin(), ::tolower);

	for (std::size_t i = 0; i < string.length() / 2; ++i)
	{
		if (string[i] != string[string.length() - i - 1])
		{
			std::cout << "Word \"" << string << "\" isn't Palindrome.\n";
			return 0;
		}
	}

	std::cout << "Word \"" << string << "\" is Palindrome.\n";
	return 0;
}