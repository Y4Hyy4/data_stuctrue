#include "BiTree.h"
#include <iostream>
#include <queue>
using namespace std;

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