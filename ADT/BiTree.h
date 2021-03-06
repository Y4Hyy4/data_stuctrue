#ifndef BITREE_H
#define BITREE_H

typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode, * BiTree;

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
void PreKthNode(BiTree T);
// depth
int Depth1(BiTree T);
int Depth2(BiTree T);
// create_by_order
BiTree CreateByOrder(char* preOrder, char* inOrder, int len);
// swap_child
void SwapChild(BiTree& T, int k);
// delete_by_value
void DelTree(BiTree& T);
void DelByValue(BiTree& T, ElemType e, bool is_left, BiTNode*& pre);
void DelByValue2(BiTree& T, ElemType e);
// find_ancestor
bool findAncestor(BiTree T, ElemType e);
void findAncestor2(BiTree T, ElemType e);
BiTNode * findLCA(BiTree T, BiTNode* p, BiTNode* q);
// WPL
int calWPL(BiTree T, int deep);
int calWPL2(BiTree T, int deep);
int calWPL3(BiTree T);

#endif // _BITREE_H
