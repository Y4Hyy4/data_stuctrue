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
    BiTNode* cur = T;
    while (cur || !stack.empty()) {
        if (cur) {
            visit(*cur);
            stack.push(cur);
            cur = cur->lchild;
        } else {
            cur = stack.top(), stack.pop();
            cur = cur->rchild;
        }
    }
}

void InOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> stack;
    BiTNode* cur = T;
    while (cur || !stack.empty()) {
        if (cur) {
            stack.push(cur);
            cur = cur->lchild;
        } else {
            cur = stack.top(), stack.pop();
            visit(*cur);
            cur = cur->rchild;
        }
    }
}

void PostOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> stack;
    BiTNode* pre = NULL;
    BiTNode* cur = T;
    while (cur || !stack.empty()) {
        if (cur) {
            stack.push(cur);
            cur = cur->lchild;
        } else {
            cur = stack.top();
            if (cur->rchild && pre != cur->rchild) {
                cur = cur->rchild;
            } else {
                visit(*cur);
                stack.pop();
                pre = cur;
                cur = NULL;
            }
        }
    }
}

void LevelOrder(BiTree T)
{
    if (!T) return;
    queue<BiTNode*> queue;
    BiTNode* cur = T;
    queue.push(T);
    while (!queue.empty()) {
        cur = queue.front(), queue.pop();
        visit(*cur);
        if (cur->lchild) queue.push(cur->lchild);
        if (cur->rchild) queue.push(cur->rchild);
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
