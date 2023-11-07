#include <catch2/catch_test_macros.hpp>
#include "version_lib.h"

TEST_CASE("Version test") {
    REQUIRE(version() > 0);
}
