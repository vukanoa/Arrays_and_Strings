#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* Check Permutation */
	std::cout << "\n\t=========================\n";
	std::cout << "\t=== CHECK PERMUTATION ===\n";
	std::cout << "\t=========================\n\n";

	/* Example 1 */
	// std::string first  = "action";
	// std::string second = "cniota";

	/* Example 2 */
	std::string first  = "action";
	std::string second = "statue";

	// std::cout << "\n\tString_1: \"" << first  << "\"\n";
	// std::cout << "\n\tString_2: \"" << second << "\"\n\n";

	if (check_permutation(first, second))
		std::cout << "\n\tThese Strings are INDEED permutations!\n\n";
	else
		std::cout << "\n\tThese Strings are NOT permutations!\n\n";
	


	return 0;
}
