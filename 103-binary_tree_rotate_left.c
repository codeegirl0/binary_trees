#include "binary_trees.h"

/**
 * binary_tree_rotate_left - do  left-rotation 
 * @tree: root pointer
 *
 * Return:  new root node or null
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);
	tmp = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		tmp->right = tree->left;
		tree->left->parent = tmp;
	}
	else
		tmp->right = NULL;
	tmp->parent = tree;
	tree->left = tmp;
	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}
