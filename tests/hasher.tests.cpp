#include <doctest/doctest.h>

#include <filesystem>
namespace fs = std::filesystem;

#include "hasher.h"

TEST_CASE("hash file")
{
    hasher::hash_t expected_hash{ 2335832566078450278, 16306248214709452722 };
    fs::path file_path(fs::current_path() / "input" / "test-hash.txt");
    auto hash = hasher::hash(file_path);
    CHECK_EQ(expected_hash, hash);
}

TEST_CASE("compare hash of 2 identical files")
{
    fs::path f1(fs::current_path() / "input" / "test-hash.txt");
    fs::path f2(fs::current_path() / "input" / "test-hash.txt.copy");
    
    auto hash1 = hasher::hash(f1);
    auto hash2 = hasher::hash(f2);
    
    CHECK_EQ(hash1, hash2);
}

TEST_CASE("compare hash of 2 different files")
{
    fs::path f1(fs::current_path() / "input" / "test-hash.txt");
    fs::path f2(fs::current_path() / "input" / "test-hash.txt.different");

    auto hash1 = hasher::hash(f1);
    auto hash2 = hasher::hash(f2);

    CHECK_NE(hash1, hash2);
}