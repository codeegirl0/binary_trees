#include "binary_trees.h"

/**
 * sorted_array_to_avl - building AVL 
 * @array: the first element 
 * @size: num  elements 
 * Return: root node or null
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	help_thesata(&tree, array, -1, middle);
	help_thesata(&tree, array, middle, size);

	return (tree);
}

/**
 * help_thesata - helper to build AVL tree 
 * @root: double pointer of root node 
 * @array: the first element
 * @lo: lower  idx
 * @hi: upper index
 */
void help_thesata(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = new;
		else if (array[middle] < (*root)->n)
			(*root)->left = new;
		help_thesata(&new, array, lo, middle);
		help_thesata(&new, array, middle, hi);
	}
}
