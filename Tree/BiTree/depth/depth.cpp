#include "BiTree.h"
#include <iostream>
#include <queue>

using namespace std;

int Depth1(BiTree T)
{
    if (!T) return 0;
    int depth = 0;
    queue<BiTNode*> q;
    BiTNode* cur = T;
    q.push(cur);
    while (!q.empty()) {
        depth++;
        int cnt = 0;
        int size = q.size();
        while (cnt < size) {
            cur = q.front(), q.pop();
            cnt++;
            if (cur->lchild) q.push(cur->lchild);
            if (cur->rchild) q.push(cur->rchild);
        }
    }
    return depth;
}

int Depth2(BiTree T)
{
    if (!T) return 0;
    int lDepth = Depth2(T->lchild);
    int rDepth = Depth2(T->rchild);
    return lDepth > rDepth ? lDepth + 1 : rDepth + 1;
}
int main(int argc, char const* argv[])
{
    BiTree root = CreateTree();

    printf("Depth1:\t");
    printf("%d", Depth1(root));
    printf("\n");

    printf("Depth2:\t");
    printf("%d", Depth2(root));
    printf("\n");

    return 0;
}
