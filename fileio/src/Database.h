#ifndef __DATABASE_H__
#define __DATEBASE_H__

#include "Record.h"
#include <vector>

namespace nhq
{
    class Database
    {
    private:
        std::vector<Record> data;

    public:

        void print() const noexcept;

        void add(const char* name, int value) noexcept;

        void save(const char* filename) noexcept;

        void load(const char* filename) noexcept;
    };
} // namespace nhq

#endif // __DATABASE_H__