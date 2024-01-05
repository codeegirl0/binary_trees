#include "binary_trees.h"

/**
 * binary_tree_preorder - pre order traversal func
 * @tree: traversed tree
 * @func: to call func
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
