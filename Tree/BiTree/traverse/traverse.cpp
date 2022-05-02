#include "BiTree.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void PreOrder(BiTree T)
{
    if (!T) return;
    visit(*T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

void InOrder(BiTree T)
{
    if (!T) return;
    InOrder(T->lchild);
    visit(*T);
    InOrder(T->rchild);
}

void PostOrder(BiTree T)
{
    if (!T) return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(*T);
}

void PreOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> stack;
    BiTNode* p = T;
    while (p || !stack.empty()) {
        if (p) {
            visit(*p);
            stack.push(p);
            p = p->lchild;
        } else {
            p = stack.top(), stack.pop();
            p = p->rchild;
        }
    }
}

void InOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> stack;
    BiTNode* p = T;
    while (p || !stack.empty()) {
        if (p) {
            stack.push(p);
            p = p->lchild;
        } else {
            p = stack.top(), stack.pop();
            visit(*p);
            p = p->rchild;
        }
    }
}

void PostOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> stack;
    BiTNode* r = NULL;
    BiTNode* p = T;
    while (p || !stack.empty()) {
        if (p) {
            stack.push(p);
            p = p->lchild;
        } else {
            p = stack.top();
            if (p->rchild && r != p->rchild) {
                p = p->rchild;
            } else {
                visit(*p);
                stack.pop();
                r = p;
                p = NULL;
            }
        }
    }
}

void LevelOrder(BiTree T)
{
    if (!T) return;
    queue<BiTNode*> queue;
    BiTNode* p = T;
    queue.push(T);
    while (!queue.empty()) {
        p = queue.front(), queue.pop();
        visit(*p);
        if (p->lchild) queue.push(p->lchild);
        if (p->rchild) queue.push(p->rchild);
    }
}


int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();
    printf("PreOrder:\t");
    PreOrder(root);
    printf("\n");

    printf("InOrder:\t");
    InOrder(root);
    printf("\n");

    printf("PostOrder:\t");
    PostOrder(root);
    printf("\n");

    printf("PreOrder2:\t");
    PreOrder2(root);
    printf("\n");

    printf("InOrder2:\t");
    InOrder2(root);
    printf("\n");

    printf("PostOrder2:\t");
    PostOrder2(root);
    printf("\n");

    printf("LevelOrder:\t");
    LevelOrder(root);
    printf("\n");

    return 0;
}
