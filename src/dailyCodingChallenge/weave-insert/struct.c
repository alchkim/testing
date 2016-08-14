#include <stdio.h>

struct test {
    int bill;
};

main() {
    struct test a;
    a.bill = 5;
    printf("%d\n", a.bill);
}