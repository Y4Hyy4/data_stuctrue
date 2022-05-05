#include "BiTree.h"
#include <iostream>
using namespace std;

void SwapChild(BiTree& T)
{
    if (!T) return;
    if (T->lchild) SwapChild(T->lchild);
    if (T->rchild) SwapChild(T->rchild);
    BiTNode *tmp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = tmp;
}

int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();
    LevelOrder(root);
    printf("\n");
    SwapChild(root);
    LevelOrder(root);
    return 0;
}
