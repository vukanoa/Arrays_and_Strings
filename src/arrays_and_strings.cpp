#include <unordered_set>
#include <map>
#include "arrays_and_strings.h"

/* ASCII */
#define UPPERCASE_A 65
#define UPPERCASE_Z 90
#define LOWERCASE_A 97
#define LOWERCASE_Z 122


/*
	If it's not only lowercase English letters then we could use a
	bit-vector only if it's ASCII(not extended ASCII(256))

	Max single dataType is "long double" which is 16B on 64-bit architecture
	16B = 128 bits
*/

/* ======================================================================== */
/* === Assumption: String is consisted of only lowecase English letters === */
/* ======================================================================== */

/* Time  Complexity O(1) if we know it's only ASCII 128 or under */
/* Space Complexity O(1) if we know it's only ASCII 128 or under */
bool
unique_characters_1(std::string s)
{
	// Assume that we use only use lowercase English letters
	if (s.length() > 27)
		return false; // Then it's sure there are repeating characters
	
	int bit_vector = 0;
	for (unsigned i = 0; i < s.length(); i++)
	{
		int char_value = s[i] - 'a';

		if (bit_vector & (1 << char_value))
			return false;

		bit_vector |= (1 << char_value);
	}

	return true;
}


/* ========================================================================= */
/* === Assumption: String is consisted of all possible characters(UTF-8) === */
/* ========================================================================= */

/* Time  Complexity O(n) */
/*
	Space Complexity O(min(n, u))
	
	where 'u' is a number of unique characters in the string. If the string is
	indeed consisted of unique characters then 'u' will be equal to 'n'
*/
bool
unique_characters_2(std::string s)
{
	std::unordered_set<char> uset;

	for (auto x: s)
	{
		if (uset.find(x) == uset.end())
			uset.insert(x);
		else
			return false;
	}

	return true;
}


/* ========================================================================= */
/* === Constraint: We aren't allowed to use an additional data structure === */
/* ========================================================================= */

/* Time  Complexity O(n^2) */
/* Space Complexity O(1)   */
bool
unique_characters_3(std::string s)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (i != j && s[i] == s[j])
				return false;
		}
	}

	return true;
}


/*
	When is one string a permuration of another?
	1. They have to be of the same length
	2. They cannot have different characters
	3. They have to have the same number of each character
*/
/* Time  Complexity O(n) */
/* Space Complexity O(n) */
bool
check_permutation(std::string s, std::string t)
{
	// Check if they are of the same length
	if (s.length() != t.length())
		return false;
	
	std::map<char, int> map;

	// Fill the Hash Table
	for(auto x : s)
		map[x]++;
	
	// Iterate through t and check if they are the same
	for(auto x : t)
	{
		if (map.find(x) == map.end() || map[x] <= 0)
			return false;

		map[x]--;
	}

	return true;
}


/* Time  Complexity O(n) */
/* Space Complexity O(1) */
void
URLify(std::string& s, int true_length)
{
	int n = s.length();

	int j = n - 1;
	int i = n - 1;
	while(j > 0)
	{
		// Find first non-blank character from the back
		if (j == n - 1)
		{
			while (s[j] == ' ')
				j--;
		}
		
		if (s[j] == ' ')
		{
			s[i--] = '0';
			s[i--] = '2';
			s[i--] = '%';
			j--;
		}
		else
			s[i--] = s[j--];
	}
}


/* Time  Complexity O(n) */
/* Space Complexity O(1) */ // Assuming English Alphabet
bool
palindrome_permutation(std::string s)
{
	if (s.empty())
		return true; // Empty string is indeed a palindrome

	int bit_vector = 0;

	/* Case-insensitive --> 'A' <==> 'a' */
	for (auto x : s)
	{
		// Ignore non-letter characters
		if (x < UPPERCASE_A || (x > UPPERCASE_Z && x < LOWERCASE_A) || x > LOWERCASE_Z)
			continue;

		if (UPPERCASE_A <= x && x <= UPPERCASE_Z) // Uppercase letter
		{
			int mask = 1 << (x - UPPERCASE_A);

			if (bit_vector & mask) // If odd number of occurrence
				bit_vector ^= (1 << (x - UPPERCASE_A)); // Now it's even
			else
				bit_vector |= (1 << (x - UPPERCASE_A)); // Now it's odd
		}
		else // Lowercase letter
		{
			int mask = 1 << (x - LOWERCASE_A);

			if (bit_vector & mask) // If odd number of occurrence
				bit_vector ^= mask; // Now it's even
			else
				bit_vector |= mask; // Now it's odd
		}
	}

	return (bit_vector & (bit_vector - 1)) == 0;
}


/* Time  Complexity O(n) */
/* Space Complexity O(1) */
bool
one_away(std::string s, std::string t)
{
	int first  = s.length();
	int second = t.length();
	if (first - second > 1 || second - first > 1)
		return false;
	

	bool difference_exist = false;
	int i = 0;
	int j = 0;

	if (first > second)
	{
		while (i < second && j < second)
		{
			if (s[i] == t[j])
			{
				i++;
				j++;
			}
			else if (s[i] != t[j])
			{
				if (difference_exist)
					return false;

				difference_exist = true;
				i++;
			}
		}
	}
	else if (first < second)
	{
		while (i < first && j < first)
		{
			if (s[i] == t[j])
			{
				i++;
				j++;
			}
			else if (s[i] != t[j])
			{
				if (difference_exist)
					return false;

				difference_exist = true;
				j++;
			}
		}
	}
	else // Equal length
	{
		for (int i = 0; i < first; i++)
		{
			if (s[i] == t[i])
				continue;
			else if (s[i] != t[i])
			{
				if (difference_exist)
					return false;

				difference_exist = true;
			}
		}
	}

	return true;
}


std::string
string_compression(std::string  s)
{
	if (s.empty())
		return s;
	
	size_t twice_the_length = s.size() * 2;
	std::string compressed(twice_the_length, ' ');

	int x = 0;
	int count = 1;
	unsigned compressed_size = 1;

	// Put the first letter
	compressed[x++] = s[0];

	for (unsigned i = 1; i < s.length(); i++)
	{
		if (s[i] != s[i - 1])
		{
			compressed[x++] = count + '0';
			count = 1;
			compressed[x++] = s[i];

			compressed_size += 2;
		}
		else
			count++;
	}
	
	// Fill the last count
	compressed[x++] = count + '0';
	compressed_size++;
	compressed.resize(compressed_size);

	if (compressed_size < s.size())
		return compressed;

	return s;
}
