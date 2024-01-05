#include "binary_trees.h"

/**
 * binary_tree_is_root - checking roots
 * @node: the node
 *
 * Return: 1 if node is a root or 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
