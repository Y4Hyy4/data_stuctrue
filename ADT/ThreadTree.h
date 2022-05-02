#ifndef TREADTREE_H
#define TREADTREE_H

typedef char ElemType;

// ltag = 0 => lchild ~ lchild
// ltag = 1 => lchild ~ preNode
// rtag = 0 => rchild ~ rchild
// rtag = 1 => rchild ~ postNode
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild;
    struct ThreadNode *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void InThread(ThreadTree &p, ThreadNode *&pre);

#endif // TREADTREE_H
