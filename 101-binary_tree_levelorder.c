#include "binary_trees.h"

/**
 * binary_tree_levelorder - travering tree
 * @tree: traversed tree
 * @func:  function to call node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t maxlevel, level;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		help_thebtlo(tree, func, level);
}

/**
 * help_thebtlo -  post order traverser
 * @tree:  traversed tree
 * @func:  function to call node
 * @level:  level of  tree
 */
void help_thebtlo(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		help_thebtlo(tree->left, func, level - 1);
		help_thebtlo(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measuring  height 
 * @tree: tree measured
 *
 * Return: height or null
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
