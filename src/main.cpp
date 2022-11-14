#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* Palindrome Permutation */
	std::cout << "\n\t==============================\n";
	std::cout << "\t=== PALINDROME PERMUTATION ===\n";
	std::cout << "\t==============================\n\n";

	std::string s = "Tact Coa";
	// std::string s = "Tact Coal";
	// std::string s = "Tact Ca";
	// std::string s = "anavolimilovana";
	// std::string s = "chsStrTrch";
	// std::string s = "bamararabaam";
	// std::string s = "soap";

	if (palindrome_permutation(s))
		std::cout << "\n\tAt least one permutation of a String: \"" << s << "\" is INDEED a palindrome!\n\n";
	else
		std::cout << "\n\tPermutations of a String: \"" << s << "\" are NOT a palindrome!\n\n";

	return 0;
}
