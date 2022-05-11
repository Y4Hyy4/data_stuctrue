#include "BiTree.h"
#include <iostream>
#include <stack>
using namespace std;

bool findAncestor(BiTree T, ElemType e)
{
    if (!T) return false;
    if (T->data == e) {
        return true;
    }
    if (findAncestor(T->lchild, e) || findAncestor(T->rchild, e)) {
        visit(*T);
        return true;
    } else return false;
}

void findAncestor2(BiTree T, ElemType e)
{
    if (!T) return;
    stack<BiTNode*> st;
    BiTNode* pre = NULL;
    BiTNode* cur = T;
    while (cur || !st.empty()) {
        if (cur) {
            if (cur->data != e) {
                st.push(cur);
                cur = cur->lchild;
            } else if (cur->data == e) {
                while (!st.empty()) {
                    visit(*st.top());
                    st.pop();
                }
                return;
            }
        } else {
            cur = st.top();
            if (cur->rchild && pre != cur->rchild) {
                cur = cur->rchild;
            } else {
                st.pop();
                pre = cur;
                cur = NULL;
            }
        }
    }
}

int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();
    LevelOrder(root);
    printf("\n");
    bool is_found = false;
    findAncestor(root, 'E');
    printf("\n");
    findAncestor(root, 'F');
    printf("\n");

    findAncestor2(root, 'E');
    printf("\n");
    findAncestor2(root, 'F');
    
    return 0;
}
