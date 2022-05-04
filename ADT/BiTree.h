#ifndef BITREE_H
#define BITREE_H

typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

BiTree CreateTree();
void visit(BiTNode node);

// traverse
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void PreOrder2(BiTree T);
void InOrder2(BiTree T);
void PostOrder2(BiTree T);
void LevelOrder(BiTree T);
void InvertLevel(BiTree T);
// depth
int Depth1(BiTree T);
int Depth2(BiTree T);
// create_by_order
BiTree CreateByOrder(char* preOrder, char* inOrder, int len);

#endif // _BITREE_H
