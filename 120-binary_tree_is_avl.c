#include "binary_trees.h"

/**
 * binary_tree_is_avl - finding avl
 * @tree: root node pointer
 *
 * Return: 1 if avl or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (help_thebtia(tree, INT_MIN, INT_MAX));
}

/**
 * help_thebtia - help find avl
 * @tree: root node 
 * @min: minimum 
 * @max: maximum 
 *
 * Return: 1 if avl or 0
 */
int help_thebtia(const binary_tree_t *tree, int min, int max)
{
	int path_r, path_l;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (help_thebtia(tree->left, min, tree->n - 1) &&
		help_thebtia(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - measuring
 * @tree: measured tree 
 * Return: height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r = 0;
	size_t height_l = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
