#ifndef BITREE_H
#define BITREE_H

#define ElemType char

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode, * BiTree;

BiTree CreateTree();
void visit(BiTNode node);

void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void PreOrder2(BiTree T);
void InOrder2(BiTree T);
void PostOrder2(BiTree T);
void LevelOrder(BiTree T);
#endif // BITREE_H
