#include "ThreadTree.h"
#include <iostream>

using namespace std;

void InThread(ThreadTree& T, ThreadNode*& pre)
{
    if (!T) return;

    InThread(T->lchild, pre);

    // visit(*T);
    if (T->lchild == NULL) {
        T->ltag = 1;
        T->lchild = pre;
    }

    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
        pre->rchild = T;
    }
    pre = T;

    InThread(T->rchild, pre);
}

ThreadNode* FirstNode(ThreadTree T)
{
    while (T->ltag == 0) T = T->lchild;
    return T;
}
ThreadNode* NextNode(ThreadNode* p)
{
    if (p->rtag == 0) return FirstNode(p->rchild);
    else return p->rchild;
}
ThreadNode* LastNode(ThreadTree T)
{
    while (T->rtag == 0) T = T->rchild;
    return T;
}
ThreadNode* PreNode(ThreadNode* p)
{
    if (p->ltag == 0) return LastNode(p->lchild);
    else return p->lchild;
}
void InOrder(ThreadTree T)
{
    for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p)) {
        visit(*p);
    }
}

int main(int argc, char const* argv[])
{
    ThreadTree root = CreateThreadTree();
    ThreadNode* pre = NULL;
    InThread(root, pre);
    pre->rchild = NULL;
    pre->rtag = 1;

    InOrder(root);

    return 0;
}
