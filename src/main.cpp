#include <time.h>
#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* String Rotation */
	std::cout << "\n\t=======================\n";
	std::cout << "\t=== STRING ROTATION ===\n";
	std::cout << "\t=======================\n\n";

	/* Example 1 */
	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";

	/* Example 2 */
	// std::string s1 = "waterbottle";
	// std::string s2 = "erbottletaw";

	if (string_rotation(s1, s2))
		std::cout << "\n\tString \"" << s2 << "\" is INDEED a rotation of a String \"" << s1 << "\"\n\n";
	else
		std::cout << "\n\tString \"" << s2 << "\" is NOT a rotation of a String \"" << s1 << "\"\n\n";


	return 0;
}
