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

ThreadTree CreateThreadTree();
void visit(ThreadNode p);

void InThread(ThreadTree &T, ThreadNode *&pre);
ThreadNode *FirstNode(ThreadTree T);
ThreadNode *NextNode(ThreadNode *p);
ThreadNode *LastNode(ThreadTree T);
ThreadNode *PreNode(ThreadNode *p);
void InOrder(ThreadTree T);


#endif // TREADTREE_H
