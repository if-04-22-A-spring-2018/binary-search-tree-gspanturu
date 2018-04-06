/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Panturu Gloria Sara
 * Due Date:		April 6, 2018
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdlib.h>
#include "general.h"

struct Node{
  int element;
  int depth;
  Bst left;
  Bst right;
};

Bst new_bst()
{
  Bst tree = 0;
  return tree;
}
void delete_bst(Bst bst)
{
  if (bst == 0) {
    return;
  }
  delete_bst(bst->right);
  delete_bst(bst->left);
  sfree(bst);
}

int get_depth(Bst bst)
{
  if (bst == 0)
  {
  return 0;
  }
  else if (bst->left == 0 && bst->right== 0 && bst!= 0) {
    return 1;
  }
    int depth_left = get_depth(bst->left) +1;
    int depth_right = get_depth(bst->right) +1;
    if (depth_right > depth_left) {
        return depth_right;
      }
    else return depth_left;
}

void add(Bst* bst, int value)
{
  Bst &copy_tree = *bst;
  if (copy_tree == 0) {
    copy_tree= (struct Node*) malloc(sizeof(struct Node));
    copy_tree->element = value;
    copy_tree->right = 0;
    copy_tree->left = 0;
    copy_tree->depth++;
    bst= &copy_tree;
  }
  else if(value <= copy_tree->element) {
    if (copy_tree->left == 0) {
      Bst new_bst = (Node*)malloc(sizeof(struct Node));
      new_bst->element = value;
      new_bst->right = 0;
      new_bst->left = 0;
      copy_tree->left = new_bst;
      copy_tree->depth++;
      bst = &copy_tree;
    }
    else
    {
      add(&copy_tree->left, value);
    }
  }
  else{
    if(copy_tree->right == 0) {
      Bst new_bst = (Node*)malloc(sizeof(struct Node));
      new_bst->element = value;
      new_bst->left = 0;
      new_bst->right = 0;
      copy_tree->right = new_bst;
      copy_tree->depth++;
      bst = &copy_tree;
    }
    else{
      add(&copy_tree->right, value);
    }
  }
}


int root_value(Bst bst)
{
  if(bst == 0)
  {
    return 0;
  }
  return bst->element;
}


int traverse_pre_order(Bst bst, int *elements, int start)
{
  if(bst == 0)
  {
    return 0;
  }
  int elements_count = 0;
  elements[start] = bst->element;
  elements_count += traverse_pre_order(bst->left, elements, start+1);
  elements_count+= traverse_pre_order(bst->right, elements, start+elements_count+1);
  return elements_count+1;
}


int traverse_in_order(Bst bst, int *elements, int start)
{
  if(bst == 0)
  {
    return 0;
  }
  int elements_count = 0;
  elements_count+= traverse_in_order(bst->left, elements, start);
  elements[start+elements_count] = bst->element;
  elements_count+= traverse_in_order(bst->right, elements,start+elements_count+1);
  return elements_count+1;
}


int traverse_post_order(Bst bst, int *elements, int start)
{
  if(bst == 0)
  {
    return 0;
  }
  int elements_count = 0;
  elements_count+= traverse_post_order(bst->left, elements, start);
  elements_count+= traverse_post_order(bst->right, elements, start+elements_count);
  elements[start+elements_count]=bst->element;
  return elements_count+1;
}


bool are_equal(Bst bst1, Bst bst2)
{
  if ((bst1 == 0 && bst2==0) || bst1 == bst2) {
    return true;
  }
    int array_bst1[20];
    int array_bst2[20];
    int length_bst1 = traverse_in_order(bst1, array_bst1, 0 );
    int length_bst2 = traverse_in_order(bst2, array_bst2, 0 );

    if (length_bst1 == length_bst2 ) {
      for (int i = 0; i < length_bst1; i++)
      {
        if (array_bst1[i] != array_bst2[i]) {
          return false;
        }
      }
      return true;
    }
     return false;
}


void most_left_longest_branch(Bst bst, Bst* branch)
{
if (bst != 0) {
  add(branch, bst->element);
  if (get_depth(bst->left) >= get_depth(bst->right)) {
    most_left_longest_branch(bst->left,branch);
  }
  else  most_left_longest_branch(bst->right,branch);
  }
}

int get_number_of_subtrees(Bst bst)
{
  if (bst == 0) {
    return -1;
  }
  int number_of_subtrees = get_number_of_subtrees(bst->left)+1 + get_number_of_subtrees(bst->right)+1;
  return number_of_subtrees;
}


Bst left_subtree (Bst root)
{
  return root->left;
}
Bst right_subtree (Bst root)
{
  return root->right;
}
