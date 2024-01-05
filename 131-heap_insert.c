#include "binary_trees.h"

/**
 * heap_insert - inserting value 
 * @root: double pointer of root 
 * @value:  value to store 
 *
 * Return: created node or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, myleafs, mysub, thebit, leveling, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	myleafs = size;
	for (leveling = 0, mysub = 1; myleafs >= mysub; mysub *= 2, leveling++)
		myleafs -= mysub;
	for (thebit = 1 << (leveling - 1); thebit != 1; thebit >>= 1)
		tree = myleafs & thebit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	myleafs & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measuring  size 
 * @tree: measured tree 
 *
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
