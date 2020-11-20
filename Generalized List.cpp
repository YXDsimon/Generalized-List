#include <iostream>
using namespace std;
typedef struct GLNode
{
    bool tag;
    union
    {
        int value;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} * GList, GLNode;
int main()
{

    return 0;
}