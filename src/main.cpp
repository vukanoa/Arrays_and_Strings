#include <time.h>
#include "arrays_and_strings.h"

int
main()
{
	/* =============== */
	/* === TESTING === */
	/* =============== */

	/* Rotate Matrix */
	std::cout << "\n\t=====================\n";
	std::cout << "\t=== ROTATE MATRIX ===\n";
	std::cout << "\t=====================\n\n";

	srand(time(NULL));

	int **matrix;
	matrix = new int* [N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];

	/* Change the value of N in arrays_and_strings.h for different Examples */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}

	rotate_matrix(matrix);

	return 0;
}
