#include "binary_trees.h"

/**
 * binary_tree_is_heap - checking root
 * @tree:  root node to check
 *
 * Return: 1 if valid or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (help_thebtih(tree));
}

/**
 * help_thebtih - checking valid Binary Heap
 * @tree: root node in tree to check
 *
 * Return: 1 if valid Binary Heap or 0
 */
int help_thebtih(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (help_thebtih(tree->left) &&
		help_thebtih(tree->right));
}

/**
 * binary_tree_is_complete - checking complete
 * @tree: root node to check
 *
 * Return: 1 if complete or 0
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
 * help_thbtic - checking complete
 * @tree: root node to check
 * @index: node index
 * @size: number  nodes
 *
 * Return: 1 if complete or 0
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
 * binary_tree_size - measuring size 
 * @tree: measured tree 
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
