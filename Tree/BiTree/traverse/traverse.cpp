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
    stack<BiTNode*> st;
    BiTNode* cur = T;
    while (cur || !st.empty()) {
        if (cur) {
            visit(*cur);
            st.push(cur);
            cur = cur->lchild;
        } else {
            cur = st.top(), st.pop();
            cur = cur->rchild;
        }
    }
}

void InOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> st;
    BiTNode* cur = T;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(cur);
            cur = cur->lchild;
        } else {
            cur = st.top(), st.pop();
            visit(*cur);
            cur = cur->rchild;
        }
    }
}

void PostOrder2(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> st;
    BiTNode* pre = NULL;
    BiTNode* cur = T;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(cur);
            cur = cur->lchild;
        } else {
            cur = st.top();
            if (cur->rchild && pre != cur->rchild) {
                cur = cur->rchild;
            } else {
                visit(*cur);
                st.pop();
                pre = cur;
                cur = NULL;
            }
        }
    }
}

void LevelOrder(BiTree T)
{
    if (!T) return;
    queue<BiTNode*> q;
    BiTNode* cur = T;
    q.push(T);
    while (!q.empty()) {
        cur = q.front(), q.pop();
        visit(*cur);
        if (cur->lchild) q.push(cur->lchild);
        if (cur->rchild) q.push(cur->rchild);
    }
}

void InvertLevel(BiTree T)
{
    if (!T) return;
    stack<BiTNode*> st;
    queue<BiTNode*> q;
    BiTNode* cur = T;
    q.push(T);
    while (!q.empty()) {
        cur = q.front(), q.pop();
        st.push(cur);
        if (cur->lchild) q.push(cur->lchild);
        if (cur->rchild) q.push(cur->rchild);
    }
    while (!st.empty()) {
        cur = st.top(), st.pop();
        visit(*cur);
    }
}

void PreKthNode(BiTree T, int k)
{
    if (!T) return;
    stack<BiTNode*> st;
    BiTNode* cur = T;
    int cnt = 0;
    while (cur || !st.empty()) {
        if (cur) {
            cnt++;
            if (cnt == k) {
                visit(*cur);
                return;
            }
            st.push(cur);
            cur = cur->lchild;
        } else {
            cur = st.top(), st.pop();
            cur = cur->rchild;
        }
    }
}
int preKthCnt = 0;
ElemType PreKthNode2(BiTree T, int k)
{
    if (!T) return '#';
    preKthCnt++;
    if (preKthCnt == k) return T->data;
    ElemType ch = PreKthNode2(T->lchild, k);
    if (ch != '#') return ch;
    return PreKthNode2(T->rchild, k);
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

    printf("InvertLevel:\t");
    InvertLevel(root);
    printf("\n");

    printf("PreKthNode:\t");
    PreKthNode(root, 3);
    printf("\n");

    printf("PreKthNode2:\t");
    printf("%c", PreKthNode2(root, 3));
    printf("\n");

    return 0;
}
