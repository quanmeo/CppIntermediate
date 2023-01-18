#include <cstdio>

namespace nhq
{
void print(const char* c)
{
    for (; *c != '\0'; c++)
    {
        ::putchar(*c);
    }
}

int str2int(const char* str)
{
    int ret = 0;
    for (; *str != '\0'; str++)
    {
        if (*str < '0' || *str > '9') {
            return -1;
        }
        ret = ret * 10 + *str - '0';
    }

    return ret;
}

int reading()
{
    char arr[4];
    int size = 0;
    int c;
    while((c = ::getchar()) != '\n' && c != EOF && size < 3) {
        arr[size++] = static_cast<char>(c);
    }

    arr[size] = '\0';

    return str2int(arr);
}

int fibonaci(int num)
{
    if (num <= 2) return 1;
    else return fibonaci(num - 1) + fibonaci(num - 2);
}

} // namespace nhq

int main()
{
    ::puts("Type a number:");
    int num = nhq::reading();
    ::printf("The %dth in fibonaci is %d\n", num, nhq::fibonaci(num));
    return 0;
}