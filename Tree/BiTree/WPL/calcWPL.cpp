#include "BiTree.h"
#include <iostream>
using namespace std;

int calWPL(BiTree T, int deep)
{
    // NULL
    if (!T) return 0;
    // 叶子
    if (!T->lchild && !T->rchild) return deep * (T->data - '0');
    // 根wpl = (左子树wpl + root.data) + (右子树wpl + root.data) 如果子树存在的情况下
    int left = 0, right = 0;
    if (T->lchild) left = calWPL(T->lchild, deep + 1);
    if (T->rchild) right = calWPL(T->rchild, deep + 1);
    return left + right;
}

int calWPL2(BiTree T, int deep)
{
    static int wpl = 0;
    if (!T) return 0;
    if (!T->lchild && !T->rchild) wpl += deep * (T->data - '0');
    if (T->lchild) calWPL2(T->lchild, deep + 1);
    if (T->lchild) calWPL2(T->rchild, deep + 1);
    return wpl;
}
#define MAXSIZE 100
int calWPL3(BiTree T)
{
    BiTNode* q[MAXSIZE];
    int f = 0, r = 0;
    int wpl = 0, deep = 0;
    BiTNode* lastNode;
    BiTNode* newlastNode;
    lastNode = T;
    newlastNode = NULL;
    q[r++] = lastNode;
    while (f != r) {
        BiTNode* p = q[f++];
        if (!p->lchild && !p->rchild) wpl += deep * (p->data - '0');
        if (p->lchild) q[r++] = p->lchild, newlastNode = p->lchild;
        if (p->rchild) q[r++] = p->rchild, newlastNode = p->rchild;
        if (p == lastNode) lastNode = newlastNode, deep++;
    }
    return wpl;
}
int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();
    LevelOrder(root);
    printf("\n");
    printf("%d", calWPL(root, 0));
    printf("\n");
    printf("%d", calWPL2(root, 0));
    printf("\n");
    printf("%d", calWPL3(root));
    return 0;
}
