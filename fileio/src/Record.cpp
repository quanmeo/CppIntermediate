#include "Record.h"
#include <cstdio>

namespace nhq
{

    Record::Record(const char *name, unsigned score)
        : mScore(score)
    {
        copy(name);
    }

    Record::Record()
    : Record("Default", 0U)
    {}

    Record::Record(const Record &r)
        : Record(r.mName, r.mScore)
    {
    }

    Record& Record::operator=(const Record& r)
    {
        mScore = r.mScore;
        copy(r.mName);

        return *this;
    }

    void Record::copy(const char *name) noexcept
    {
        unsigned size = 0U;
        for (; *name != '\0' && size < LENGTH_OF_NAME - 1; name++)
        {
            mName[size++] = *name;
        }

        mName[size] = '\0';
    }

    void Record::print() const
    {
        bool empty = false;
        for (unsigned idx = 0U; idx < LENGTH_OF_NAME; idx++)
        {
            if (mName[idx] == '\0')
            {
                empty = true;
            }

            if (empty)
            {
                std::putchar((int)' ');
            }
            else
            {
                std::putchar((int)mName[idx]);
            }
        }
        std::putchar((int)'|');

        for (unsigned idx = 0U; idx < mScore; idx++)
        {
            std::putchar((int)'=');
        }
        std::putchar((int)'\n');
    }

    void Record::Save(std::ofstream& ofs)
    {
        ofs.write(mName, sizeof mName);
        ofs.write(reinterpret_cast<char*>(&mScore), sizeof mScore);
    }

    void Record::Load(std::ifstream& ifs)
    {
        ifs.read(mName, sizeof mName);
        ifs.read(reinterpret_cast<char*>(&mScore), sizeof mScore);
    }

    

} // namespace nhq