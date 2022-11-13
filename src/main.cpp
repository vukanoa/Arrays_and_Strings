#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* URLify */
	std::cout << "\n\t==============\n";
	std::cout << "\t=== URLify ===\n";
	std::cout << "\t==============\n\n";
	
	std::string s = "Mr Luke Smith    ";
	// std::string s = "Mr Kevin Smith    ";
	// std::string s = "Mr s a b      ";

	int true_length = s.length();
	
	std::cout << "\n\tBefore: \"" << s << "\"\n\n";
	URLify(s, true_length);
	std::cout << "\tAfter:  \"" << s << "\"\n\n";



	return 0;
}
