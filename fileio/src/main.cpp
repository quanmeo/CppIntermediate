#include <cstdio>
#include <fstream>
#include "Record.h"
#include "Database.h"

char name[10];
int score = 0;

namespace nhq
{
    void print(const char* msg)
    {
        for (; *msg != 0; msg++)
        {
            std::putchar(*msg);
        }
    }

    void read(char *buf, int size)
    {
        const char* bufEnd = buf + size;
        for (char c = std::getchar(); c != 13 && c != 10 && buf < bufEnd; c = std::getchar(), buf++)
        {
            *buf = c;
        }
        *buf = '\0';
    }

    int str2int(const char* s)
    {
        const char* p = s;
        for (; *p >= '0' && *p <= '9'; p++);
        p--;

        int val = 0;
        int place = 1;

        for (; p >= s; p--)
        {
            val += (*p - '0') * place;
            place *= 10;
        }

        return val;
    }

} // namespace nhq

int main()
{
    nhq::Database data;
    bool quit = false;
    char buf[256];
    char buf2[256];

    do
    {
        nhq::print("(l)oad (s)ave (a)dd (q)uit (p)rint? ");
        nhq::read(buf, sizeof buf);

        switch (buf[0])
        {
        case 'l':
            nhq::print("Type filename:");
            nhq::read(buf, sizeof buf);
            data.load(buf);
            break;
        case 's':
            nhq::print("Type filename:");
            nhq::read(buf, sizeof buf);
            data.save(buf);
            break;
        case 'a':
            nhq::print("Type name:");
            nhq::read(buf, sizeof buf);
            nhq::print("Type value:");
            nhq::read(buf2, sizeof buf2);

            data.add(buf, nhq::str2int(buf2));
            break;
        case 'p':
            data.print();
            break;
        case 'q':
            quit = true;
            break;
        default:
            break;
        }
    } while (!quit);

    return 0;
}