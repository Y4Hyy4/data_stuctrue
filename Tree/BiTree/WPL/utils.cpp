#include "BiTree.h"
#include <iostream>
#include <queue>
using namespace std;

BiTree CreateTree()
{
    BiTNode* pA = (BiTNode*)malloc(sizeof(BiTNode));
    BiTNode* pB = (BiTNode*)malloc(sizeof(BiTNode));
    BiTNode* pC = (BiTNode*)malloc(sizeof(BiTNode));
    BiTNode* pD = (BiTNode*)malloc(sizeof(BiTNode));
    BiTNode* pE = (BiTNode*)malloc(sizeof(BiTNode));
    BiTNode* pF = (BiTNode*)malloc(sizeof(BiTNode));
    pA->data = '1';
    pB->data = '2';
    pC->data = '3';
    pD->data = '4';
    pE->data = '5';
    pF->data = '6';
    pA->lchild = pB;
    pA->rchild = pC;
    pB->lchild = pD;
    pB->rchild = pE;
    pD->lchild = pD->rchild = NULL;
    pE->lchild = pE->rchild = NULL;
    pC->lchild = pF;
    pC->rchild = NULL;
    pF->lchild = pF->rchild = NULL;
    return pA;
}

void visit(BiTNode node)
{
    printf("%c", node.data);
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