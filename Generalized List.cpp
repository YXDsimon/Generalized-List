#include <iostream>
#define ELEM char
using namespace std;

struct GLNode
{
    bool tag;
    union
    {
        ELEM value;
        struct GLNode *hp;
    };
    struct GLNode *tp;

    GLNode(int Ctag, ELEM Cvalue)
    {
        tag = Ctag;
        value = Cvalue;
    }

    GLNode(int Ctag, GLNode *Chp)
    {
        tag = Ctag;
        hp = Chp;
    }

    GLNode(int Ctag)
    {
        tag = Ctag;
    }

    int getdepth()
    {
        if (tag == 0)
        {
            if (tp)
                return tp->getdepth();
            else
                return 0;
        }
        if (tag == 1)
        {
            if (!hp)
            {
                if (tp)
                    return max(1, tp->getdepth());
                else
                    return 1;
            }
            if (tp)
                return max(1 + hp->getdepth(), tp->getdepth());
            else
                return 1 + hp->getdepth();
        }
    }
} * GList, a(0, 'A'), b(0, 'B'), c(0, 'C'), d(0, 'D'), e(0, 'E');

int main()
{
    GList = new GLNode(1, &a);
    a.tp = new GLNode(1, &b);
    b.tp = &c;
    c.tp = new GLNode(1, &d);
    d.tp = &e;
    GLNode *f = new GLNode(1);         //构建一个空表
    cout << f->getdepth() << endl;     //空表的深度应该为1
    cout << GList->getdepth() << endl; //S=(a,(b,c,(d,e)))
    return 0;
}