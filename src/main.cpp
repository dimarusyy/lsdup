#include <cstdlib>
#include <iostream>
#include "dir_lookup.h"

static void usage()
{
    std::cerr << "Usage: \n"
        << "\tlsdup <directory>\n";
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage();
        return EXIT_FAILURE;
    }

    try
    {
        dir_lookup_t dl{ argv[1] };
        auto rc = dl.lsdup();
        for (auto& p : rc)
        {
            std::cout << "[" << "group #" << p.first << "]\n";
            for (auto& file : p.second)
                std::cout << file.string() << "\n";
            std::cout << "\n";
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error : " << ex.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "unexpected exception\n";
    }

    return EXIT_SUCCESS;
}