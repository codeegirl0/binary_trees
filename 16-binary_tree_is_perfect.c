#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checking perfect
 * @tree: root pointer
 *
 * Return: 1 if perfect or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t nodes = 0;
	size_t power = 0;
	size_t height = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)_power_rec(2, height + 1);
	return (power - 1 == nodes);
}

/**
 *_power_rec - traverse x to y
 *@x: the exponentiate
 *@y: the power
 *Return: x or -1 or 0
 */

int _power_rec(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _power_rec(x, y - 1));

}

/**
 * binary_tree_size - measuring size
 * @tree: tree of size
 *
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - measuring height
 * @tree: tree of the height 
 *
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
