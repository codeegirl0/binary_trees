#include "binary_trees.h"

/**
 * binary_tree_node - creating the binary tree node
 * @parent: pointerof parent
 * @value: the value 
 *
 * Return: new val pointer of null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
