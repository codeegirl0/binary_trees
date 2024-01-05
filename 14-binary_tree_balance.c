#include "binary_trees.h"

/**
 * binary_tree_balance - measuring balance
 * @tree: root pointer
 *
 * Return: the balance or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_r, height_l;

	if (!tree)
		return (0);
	height_l = tree->left ? (int)binary_tree_height(tree->left) : -1;
	height_r = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (height_l - height_r);
}

/**
 * binary_tree_height - measuring hight
 * @tree: tree of height
 *
 * Return: height num
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
