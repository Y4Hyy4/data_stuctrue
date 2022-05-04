#include "BiTree.h"
#include <iostream>
#include <queue>
using namespace std;

BiTree CreateByOrder(char* preOrder, char* inOrder, int len)
{
    if (len == 0) {
        return NULL;
    }
    if (len == 1) {
        BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode*));
        p->data = *(preOrder);
        p->lchild = p->rchild = NULL;
        return p;
    }
    int i = 0;
    for (; i < len; i++) {
        if (*(inOrder + i) == *(preOrder)) break;
    }
    BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode*));
    p->data = *(preOrder);
    p->lchild = CreateByOrder(preOrder + 1, inOrder, i);
    p->rchild = CreateByOrder(preOrder + i + 1, inOrder + i + 1, len - i - 1);
    return p;
}

int main(int argc, char const* argv[])
{
    char* preOrder = (char*)"ABDCE";
    char* inOrder = (char*)"BDAEC";
    int len = 0;
    while (*(preOrder + len)) len++;
    BiTree root = CreateByOrder(preOrder, inOrder, len);
    LevelOrder(root);
    return 0;
}
