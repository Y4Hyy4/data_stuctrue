#include "BiTree.h"
#include <iostream>
#include <queue>
using namespace std;

// #define __CHANGE__

void DelTree(BiTree& T)
{
    if (!T) return;
    DelTree(T->rchild);
    DelTree(T->lchild);
    free(T);
}
void DelByValue(BiTree& T, ElemType e, bool is_left, BiTNode*& pre)
{
    if (!T) return;
    if (T->data == e) {
        DelTree(T);
        if (pre) {
            if (is_left) pre->lchild = NULL;
            else pre->rchild = NULL;
        }
    } else {
        DelByValue(T->rchild, e, false, T);
        DelByValue(T->lchild, e, true, T);
    }
}

void DelByValue2(BiTree& T, ElemType e)
{
    if (!T) return;
    queue<BiTNode*> q;
    BiTNode* p = T;
    q.push(p);
    while (!q.empty()) {
        p = q.front(), q.pop();
        if (p->lchild) {
            if (p->lchild->data == e) {
                DelTree(p->lchild);
                p->lchild = NULL;
            } else q.push(p->lchild);
        }

        if (p->rchild) {
            if (p->rchild->data == e) {
                DelTree(p->rchild);
                p->rchild = NULL;
            } else q.push(p->rchild);
        }
    }
}

int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();
    LevelOrder(root);
    printf("\n");
    BiTNode* pre = NULL;
#ifndef __CHANGE__
    DelByValue(root, 'B', false, pre);
    LevelOrder(root);
    printf("\n");
    DelByValue2(root, 'C');
    LevelOrder(root);
#endif
#ifdef __CHANGE__
    DelByValue2(root, 'B');
    LevelOrder(root);
    printf("\n");
    DelByValue(root, 'C', false, pre);
    LevelOrder(root);
#endif

    return 0;
}
