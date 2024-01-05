#include "binary_trees.h"

/**
 * array_to_bst - building search form
 * @array: first element 
 * @size: elements num
 * Return: root node or null
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int j;
	bst_t *root = NULL;

	for (j = 0; j < size; j++)
		bst_insert(&root, array[j]);

	return (root);
}
