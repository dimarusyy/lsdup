#include <doctest/doctest.h>
#include "dir_lookup.h"

namespace fs = std::filesystem;

TEST_CASE("Lookup TMP dir")
{
    CHECK_NOTHROW( dir_lookup_t dl(fs::temp_directory_path().string()) );
}

TEST_CASE("Lookup wrong dir")
{
    CHECK_THROWS_AS(dir_lookup_t dl("jahgdfjhd"), std::exception);
}