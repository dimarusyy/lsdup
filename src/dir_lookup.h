#pragma once

#include <sstream>
#include <filesystem>
#include <list>
#include <map>
#include <cassert>

#include "hasher.h"

namespace fs = std::filesystem;

class dir_lookup_t final
{
public:
    explicit dir_lookup_t(std::string path)
        : _lookup_path(path)
    {
        if (!fs::exists(_lookup_path))
        {
            std::stringstream ss;
            ss << "Directory [" << _lookup_path.string() << "] doesn't exist";
            throw std::runtime_error(ss.str());
        }
    }

    std::map<std::size_t /*group id*/, std::list<fs::path>> lsdup()
    {
        // traverse directory
        for (auto &p : fs::directory_iterator(_lookup_path))
        {
            if (p.is_regular_file())
            {
                std::error_code ec;
                auto fsize = fs::file_size(p, ec);
                if (!ec)
                {
                    _files_by_size[fsize].push_back(p.path());
                }
            }
        }

        std::map<std::size_t /*group id*/, std::list<fs::path>> rc;

        //
        std::size_t group_id = 1;
        for (auto &p : _files_by_size)
        {
            assert(p.second.size() != 0);
            if (p.second.size() < 2)
                continue;

            // need to read file content
            std::map<hasher::hash_t, std::list<fs::path>> file_by_hash;
            for (auto &file_path : p.second)
            {
                auto hash = hasher::hash(file_path);
                file_by_hash[hash].push_back(file_path);
            }

            for (auto &fbh : file_by_hash)
            {
                assert(fbh.second.size() != 0);
                if (fbh.second.size() < 2)
                    continue;

                for (auto &path : fbh.second)
                    rc[group_id].push_back(path);
                group_id++;
            }
        }

        return rc;
    }

private:
    fs::path _lookup_path;
    std::map<std::uintmax_t /*filesize*/, std::list<fs::path>> _files_by_size;
};