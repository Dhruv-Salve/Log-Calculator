#include "a1.h"
int main()
{
    calc c1;
    calcUI u1;
    u1.infoblock();
    u1.notesblock();
    bool procces = c1.accept();
    c1.operationidentify(procces);
    return 0;
}
