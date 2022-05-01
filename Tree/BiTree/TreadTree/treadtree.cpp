#include "ThreadTree.h"
#include <iostream>

using namespace std;

void InThread(ThreadTree& p, ThreadNode*& pre) {
    if (!p) return;
    InThread(p->lchild, pre);
    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
    InThread(p->rchild, pre);
}

int main(int argc, char const* argv[]) {

    return 0;
}
