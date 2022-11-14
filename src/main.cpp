#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* One away */
	std::cout << "\n\t================\n";
	std::cout << "\t=== ONE AWAY ===\n";
	std::cout << "\t================\n\n";

	/* Example 1 */
	std::string s = "pale";
	std::string t = "ple";
	
	/* Example 2 */
	// std::string s = "pales";
	// std::string t = "pale";

	/* Example 3 */
	// std::string s = "pale";
	// std::string t = "bale";

	/* Example 4 */
	// std::string s = "pale";
	// std::string t = "bake";

	/* Example 5 */
	// std::string s = "palest";
	// std::string t = "pal";


	std::cout << "\n\tString 1: " << s << "\n";
	std::cout << "\tString 2: " << t << "\n";

	if (one_away(s, t))
		std::cout << "\n\tThese two strings are INDEED one edit away!\n\n";
	else
		std::cout << "\n\tThese two strings are NOT one edit away!\n\n";

	return 0;
}
