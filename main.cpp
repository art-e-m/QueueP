#include <iostream>
#include "queueP.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    QueueP q;
    q.push(1, 9);
    q.push(3, 3);
    q.push(10, 10);
    q.show();
    return 0;
}
