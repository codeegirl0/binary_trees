#include "binary_trees.h"

/**
 * binary_tree_is_complete - checking completenss
 * @tree:  root node
 *
 * Return: 1 if complete  or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (help_thbtic(tree, 0, size));
}

/**
 * help_thbtic - checking completetness
 * @tree:  pointer  root
 * @index:  index of check
 * @size: num  nodes of the tree
 *
 * Return: 1 if complete or null
 */
int help_thbtic(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);

	return (help_thbtic(tree->left, 2 * index + 1, size) &&
		help_thbtic(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measuring  size 
 * @tree: tree to measure
 *
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
