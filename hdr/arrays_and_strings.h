#ifndef _ARRAYS_AND_STRINGS_H_
#define _ARRAYS_AND_STRINGS_H_

#include <iostream>

static const int N = 5;

// Problems
bool unique_characters_1(std::string s); // Time O(1),   Space O(1) w/  Assumption
bool unique_characters_2(std::string s); // Time O(n),   Space O(n) w/o Assumption
bool unique_characters_3(std::string s); // Time O(n^2), Space O(1) w/  Constraint
/* TODO  Time O(n * logn), Space O(1), HeapSort */
// bool unique_characters_4(std::string s);

bool        check_permutation     (std::string  s, std::string t);
void        URLify                (std::string& s, int true_length);
bool        palindrome_permutation(std::string  s);
bool        one_away              (std::string  s, std::string t);
std::string string_compression    (std::string  s);
void        rotate_matrix         (int **matrix);

// Utility functions
void print_matrix(int **matrix);


#endif // _ARRAYS_AND_STRINGS_H_
