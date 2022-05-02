#include "ThreadTree.h"
#include <iostream>
using namespace std;

ThreadTree CreateTree()
{
    ThreadNode* pA = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pB = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pC = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pD = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pE = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pF = (ThreadNode*)malloc(sizeof(ThreadNode));
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';
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
void visit(ThreadNode node)
{
    printf("%c", node.data);
}