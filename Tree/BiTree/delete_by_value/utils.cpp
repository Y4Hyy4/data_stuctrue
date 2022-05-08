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
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'B'; // test Del
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
void visit(BiTNode node) {
    printf("%c", node.data);
}