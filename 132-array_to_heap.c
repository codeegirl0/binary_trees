#include "binary_trees.h"

/**
 * array_to_heap - building  Max Heap tree 
 * @array: first element 
 * @size:  number element 
 * Return: root node  created or null
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int j;
	heap_t *root = NULL;

	for (j = 0; j < size; j++)
		heap_insert(&root, array[j]);

	return (root);
}
