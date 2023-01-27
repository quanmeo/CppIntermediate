#include "Database.h"
#include <fstream>
#include <cstdio>

namespace nhq
{
    void Database::print() const noexcept
    {
        std::puts("Beautiful Chart Bitches!");
        std::puts("------------------------");
        std::puts("");

        for (const Record& rec : data)
        {
            rec.print();
        }
    }

    void Database::add(const char* name, int value) noexcept
    {
        data.emplace_back(name, value);
    }

    void Database::save(const char* filename) noexcept
    {
        std::puts(__func__);
        std::ofstream ofs(filename, std::ios::binary);
        if (ofs)
        {
            const int size = data.size();

            ofs.write(reinterpret_cast<const char*>(&size), sizeof size);

            for (Record& rec : data)
            {
                rec.Save(ofs);
            }

            data.clear();
        }
    }

    void Database::load(const char* filename) noexcept
    {
        std::puts(__func__);
        std::ifstream ifs(filename, std::ios::binary);
        if (ifs)
        {
            int size;
            ifs.read(reinterpret_cast<char*>(&size), sizeof size);

            data.resize(size);

            for (Record& rec : data)
            {
                rec.Load(ifs);
            }
        }
    }

} // namespace nhq
