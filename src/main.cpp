#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* String Compression */
	std::cout << "\n\t==========================\n";
	std::cout << "\t=== STRING COMPRESSION ===\n";
	std::cout << "\t==========================\n\n";

	/* Example 1 */
	std::string s = "aabcccccaaa";

	/* Example 2 */
	// std::string s = "aabcccccaad";

	/* Example 3 */
	// std::string s = "abcdefgabc";

	/* Example 4 */
	// std::string s = "aabbc";

	/* Example 5 */
	// std::string s = "abc";

	/* Example 6 */
	// std::string s = "aabbccdd";

	/* Example 7 */
	// std::string s = "aabbbcdd";

	/* Example 8 */
	// std::string s = "aabccccd";

	/* Example 9 */
	// std::string s = "aabccccdd";

	/* Example 10 */
	// std::string s = "";

	std::cout << "\n\tOriginal string: \"" << s << "\"\n";

	std::string compressed = string_compression(s);
	if (s.compare(compressed) == 0)
	{
		std::cout << "\n\t---------- WARNING ----------";
		std::cout << "\n\tOriginal string is uncompressible!\n\n";
	}
	else
		std::cout << "\n\tCompressed string: \"" << compressed << "\"\n\n";

	return 0;
}
