#pragma once
#include <boost/iostreams/device/mapped_file.hpp>
#include "MurmurHash3.h"

#include <array>
#include <filesystem>

namespace fs = std::filesystem;

namespace hasher
{
    using hash_t = std::array<uint64_t, 2>;

    static constexpr uint32_t SEED = 0u;

    inline hash_t hash(fs::path path)
    {
        boost::iostreams::mapped_file mmap(path.string(), boost::iostreams::mapped_file::readonly);
        hash_t hash_value;
        MurmurHash3_x64_128(mmap.const_data(), static_cast<int>(mmap.size()), SEED, hash_value.data());

        return hash_value;
    }
};