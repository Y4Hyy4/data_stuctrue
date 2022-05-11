#include "BiTree.h"
#include <iostream>
using namespace std;

// 后序遍历，假设T是p，q的公共祖先
// 如果右孩子结点不是p,q的公共祖先，左孩子也不是p,q的公共祖先
// 那么如果T就是p,q的公共祖先

// 假设T是最近公共祖先
// 1. p, q不在T的同一子树中
// 2. p = T, q在某一子树中
// 3. q = T, p在某一子树中

BiTNode* findLCA(BiTree T, BiTNode* p, BiTNode* q)
{
    if (!T || T == p || T == q) return T;

    BiTNode* left = findLCA(T->lchild, p, q);
    BiTNode* right = findLCA(T->rchild, p, q);

    if(left && right) return T;
    if(left) return left;
    if(right) return right;
    return NULL;
}

int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();
    LevelOrder(root);
    return 0;
}
