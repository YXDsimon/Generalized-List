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
                    return tp->getdepth();
                else
                    return 0;
            }
            if (tp)
                return max(1 + hp->getdepth(), tp->getdepth());
            else
                return 1 + hp->getdepth();
        }
    }
} * GList, a(0, 'a'), b(0, 'b'), c(0, 'c'), d(0, 'd'), e(0, 'e');

int main()
{
    GList = new GLNode(1, &a);
    a.tp = new GLNode(1, &b);
    b.tp = &c;
    c.tp = new GLNode(1, &d);
    d.tp = &e;
    cout << GList->getdepth() << endl;
    return 0;
}