#include "binary_trees.h"

/**
 * binary_tree_is_bst - checking search
 * @tree: a root pointer
 *
 * Return: 1 if bst or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (help_thebtib(tree, INT_MIN, INT_MAX));
}

/**
 * help_thebtib - checking validity
 * @tree: root pointer
 * @min: the Lower  
 * @max: the Upper  
 *
 * Return: 1 if BST or 0
 */
int help_thebtib(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	return (help_thebtib(tree->left, min, tree->n - 1) &&
		help_thebtib(tree->right, tree->n + 1, max));
}
