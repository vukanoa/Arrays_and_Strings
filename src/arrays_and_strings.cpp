#include <unordered_set>
#include <map>
#include "arrays_and_strings.h"

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

