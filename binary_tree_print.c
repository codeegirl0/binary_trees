#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * toprint_t - Storing level in  array 
 * @tree: node to print pointer
 * @offset: printed Offset 
 * @depth: Depth node
 * @s: the buffer
 *
 * Return: length  process
 */
static int toprint_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int thewidth, left, is_left, right, j;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	thewidth = sprintf(b, "(%03d)", tree->n);
	left = toprint_t(tree->left, offset, depth + 1, s);
	right = toprint_t(tree->right, offset + left + thewidth, depth + 1, s);
	for (j = 0; j < thewidth; j++)
		s[depth][offset + left + j] = b[j];
	if (depth && is_left)
	{
		for (j = 0; j < thewidth + right; j++)
			s[depth - 1][offset + left + thewidth / 2 + j] = '-';
		s[depth - 1][offset + left + thewidth / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (j = 0; j < left + thewidth; j++)
			s[depth - 1][offset - thewidth / 2 + j] = '-';
		s[depth - 1][offset + left + thewidth / 2] = '.';
	}
	return (left + thewidth + right);
}

/**
 * _theheightfunc - Measuring  height 
 *
 * @tree:node to measure 
 *
 * Return:  height at node
 */
static size_t _theheightfunc(const binary_tree_t *tree)
{
	size_t height_r;
	size_t height_l;

	height_l = tree->left ? 1 + _theheightfunc(tree->left) : 0;
	height_r = tree->right ? 1 + _theheightfunc(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - printing tree
 * @tree:  root node to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, n, j;

	if (!tree)
		return;
	height = _theheightfunc(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (n = 0; n < height + 1; n++)
	{
		s[n] = malloc(sizeof(**s) * 255);
		if (!s[n])
			return;
		memset(s[n], 32, 255);
	}
	toprint_t(tree, 0, 0, s);
	for (n = 0; n < height + 1; n++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[n][j] != ' ')
				break;
			s[n][j] = '\0';
		}
		printf("%s\n", s[n]);
		free(s[n]);
	}
	free(s);
}