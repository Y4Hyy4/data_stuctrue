#include "ThreadTree.h"
#include <iostream>
using namespace std;

ThreadTree CreateThreadTree()
{
    ThreadNode* pA = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pB = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pC = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pD = (ThreadNode*)malloc(sizeof(ThreadNode));
    ThreadNode* pE = (ThreadNode*)malloc(sizeof(ThreadNode));
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pA->ltag = pA->rtag = 0;
    pB->ltag = pB->rtag = 0;
    pC->ltag = pC->rtag = 0;
    pD->ltag = pD->rtag = 0;
    pE->ltag = pE->rtag = 0;
    pA->lchild = pB;
    pA->rchild = pC;
    pB->lchild = NULL;
    pB->rchild = pD;
    pD->lchild = pD->rchild = NULL;
    pE->lchild = pE->rchild = NULL;
    pC->lchild = pE;
    pC->rchild = NULL;
    pE->lchild = pE->rchild = NULL;
    return pA;
}
void visit(ThreadNode node)
{
    printf("%c", node.data);
}