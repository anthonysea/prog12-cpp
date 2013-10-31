/* Programming 12 Test, using string methods
 *
 */

#include <iostream>
#include <string>


std::string reverseWord(std::string input)
{
	std::string newWord;
	for (int x = input.length(); x >= 0; x--)
	{
		newWord.append(input.substr(x, 1));
	}
	return newWord;
}


int countWords(std::string& input, int lenOfStr = 4)
{
	unsigned int count(0);
	unsigned int total(0);
	std::string rstring;
	int placement(0);

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
		{
			count++;
			rstring.append(input.substr(i, 1));

		} else if (input[i] == ' ')
		{
			count = 0;
			rstring.clear();
		}
		if (count == 4)
		{
			total++;
			placement = i - 3;
			input.replace(placement, 4, reverseWord(rstring));
			placement = 0;
	
		}
	}
	return total;
}





int main()
{
	std::string input;
	getline(std::cin, input);
	std::cout << "total: " << countWords(input) << std::endl;
	std::cout << "reverse: " << input << std::endl;
	getline(std::cin, input);
}

