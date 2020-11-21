#include <iostream>
#include <queue>
#define ELEM char
using namespace std;
template <class T>
class BTNode
{
protected:
    T elem;
    BTNode *Lchild = NULL;
    BTNode *Rchild = NULL;
    BTNode *Parent = NULL;

public:
    BTNode(T e)
    {
        elem = e;
    }
    BTNode<T> *lchild()
    {
        if (!Lchild)
            return NULL;
        return Lchild;
    }
    BTNode<T> *rchild()
    {
        if (!Rchild)
            return NULL;
        return Rchild;
    }
    void LInsert(BTNode<T> &child)
    {
        Lchild = &child;
        child.Parent = this;
    }
    void RInsert(BTNode<T> &child)
    {
        Rchild = &child;
        child.Parent = this;
    }
    void PreorderPrint()
    {
        cout << elem << endl;
        if (Lchild)
            Lchild->PreorderPrint();
        if (Rchild)
            Rchild->PreorderPrint();
    }
    void HierachyPrint()
    {
        queue<BTNode<char> *> Q;
        Q.push(this);
        while (!Q.empty())
        {
            BTNode<char> *node = Q.front();
            Q.pop();
            cout << node->elem << endl;
            if (node->lchild())
                Q.push(node->lchild());
            if (node->rchild())
                Q.push(node->rchild());
        }
    }
};

int main()
{
    BTNode<char> A('A'), B('B'), C('C'), D('D'), E('E'), F('F'), G('G');
    A.LInsert(B);
    A.RInsert(C);
    C.LInsert(F);
    B.LInsert(D);
    B.RInsert(E);
    E.RInsert(G);
    A.HierachyPrint();
    return 0;
}