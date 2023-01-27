#ifndef __RECORD_H__
#define __RECORD_H__

#include <fstream>

namespace nhq
{
    class Record
    {

        static constexpr unsigned LENGTH_OF_NAME = 10U;

    private:
        unsigned mScore;
        char mName[LENGTH_OF_NAME];

    private:
        void copy(const char *name) noexcept;

    public:
        Record(const char *name, unsigned score);

        Record();

        Record(const Record &r);

        Record& operator=(const Record& r);

        Record& operator=(Record&& r) = default;

        ~Record() = default;

    public:
        void print() const;
        void Save(std::ofstream& ofs);
        void Load(std::ifstream& ifs);
        static constexpr unsigned getMaxLength() { return Record::LENGTH_OF_NAME; }
    };
} // namespace nhq

#endif // __RECORD_H__