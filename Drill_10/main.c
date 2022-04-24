#include <stdio.h>
#include <stdlib.h>

void print_out(char* p, int x){
    printf("p is \"%s\" and x is %i\n", p, x);
    }

int main()
{
    // 1
    printf("Hello, world!\n");

    // 2
    char first[] = "Hello";
    char second[] = "World!";

    printf("%s %s\n", first, second);

    // 3
    print_out("foo",7);
    print_out("DE-IK", 100);
    print_out("big", 30);

    return 0;
}
