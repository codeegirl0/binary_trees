#include "binary_trees.h"

/**
 * array_to_avl - building  AVL tree
 * @array: array start
 * @size: size  array
 *
 * Return: the root node AVL tree or null
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int j;
	avl_t *root = NULL;

	for (j = 0; j < size; j++)
		avl_insert(&root, array[j]);

	return (root);
}
