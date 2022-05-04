#include "BiTree.h"
#include <iostream>
using namespace std;

BiTree CreateTree() {
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
void visit(BiTNode node) {
    printf("%c", node.data);
}