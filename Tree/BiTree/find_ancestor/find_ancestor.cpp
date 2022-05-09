#include "BiTree.h"
#include <iostream>
#include <stack>
using namespace std;

bool find_ancestor(BiTree T, ElemType e)
{
    if (!T) return false;
    if (T->data == e) {
        return true;
    }
    if (find_ancestor(T->lchild, e) || find_ancestor(T->rchild, e)) {
        visit(*T);
        return true;
    } else return false;
}

void find_ancestor2(BiTree T, ElemType e)
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
    find_ancestor(root, 'E');
    printf("\n");
    find_ancestor(root, 'F');
    printf("\n");

    find_ancestor2(root, 'E');
    printf("\n");
    find_ancestor2(root, 'F');
    
    return 0;
}
