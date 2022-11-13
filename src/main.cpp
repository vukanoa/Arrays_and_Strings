#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* Unique Characters */
	std::cout << "\n\t=========================\n";
	std::cout << "\t=== UNIQUE CHARACTERS ===\n";
	std::cout << "\t=========================\n\n";

	/* Example 1 */
	std::string s = "algorithm";

	/* Example 2 */
	// std::string s = "manacher";

	if (unique_characters_1(s))
	// if (unique_characters_2(s))
	// if (unique_characters_3(s))
		std::cout << "\n\tThe String: \"" << s << "\" is INDEED consisted of unique characters!\n\n";
	else
		std::cout << "\n\tThe String: \"" << s << "\" is NOT consisted of unique characters!\n\n";


	return 0;
}
