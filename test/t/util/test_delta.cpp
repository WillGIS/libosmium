#include "catch.hpp"

#include <cstdint>
#include <vector>

#include <osmium/util/delta.hpp>

TEST_CASE("delta encode int") {
    osmium::util::DeltaEncode<int> x;

    REQUIRE(x.update(17) == 17);
    REQUIRE(x.value() == 17);
    REQUIRE(x.update(10) == -7);
    REQUIRE(x.value() == 10);
    REQUIRE(x.update(-10) == -20);
    REQUIRE(x.value() == -10);
    x.clear();
    REQUIRE(x.value() == 0);
}

TEST_CASE("delta encode int with int32") {
    osmium::util::DeltaEncode<int, int32_t> x;

    REQUIRE(x.update(17) == 17);
    REQUIRE(x.value() == 17);
    REQUIRE(x.update(10) == -7);
    REQUIRE(x.value() == 10);
    REQUIRE(x.update(-10) == -20);
    REQUIRE(x.value() == -10);
    x.clear();
    REQUIRE(x.value() == 0);
}

TEST_CASE("delta decode int") {
    osmium::util::DeltaDecode<int> x;

    REQUIRE(x.update(17) == 17);
    REQUIRE(x.update(10) == 27);
    REQUIRE(x.update(-40) == -13);
    x.clear();
    REQUIRE(x.update(17) == 17);
}

TEST_CASE("delta decode int with int32") {
    osmium::util::DeltaDecode<int, int32_t> x;

    REQUIRE(x.update(17) == 17);
    REQUIRE(x.update(10) == 27);
    REQUIRE(x.update(-40) == -13);
    x.clear();
    REQUIRE(x.update(17) == 17);
}

TEST_CASE("delta encode unsigned int") {
    osmium::util::DeltaEncode<unsigned int> x;

    REQUIRE(x.update(17) == 17);
    REQUIRE(x.update(10) == -7);
    REQUIRE(x.update(0) == -10);
}

TEST_CASE("delta decode unsigned int") {
    osmium::util::DeltaDecode<unsigned int> x;

    REQUIRE(x.update(17) == 17);
    REQUIRE(x.update(10) == 27);
    REQUIRE(x.update(-15) == 12);
}

TEST_CASE("delta encode and decode") {
    const std::vector<int> a = { 5, -9, 22, 13, 0, 23 };

    osmium::util::DeltaEncode<int, int> de;
    std::vector<int> b;
    b.reserve(a.size());
    for (int x : a) {
        b.push_back(de.update(x));
    }

    osmium::util::DeltaDecode<int, int> dd;
    std::vector<int> c;
    c.reserve(b.size());
    for (int x : b) {
        c.push_back(dd.update(x));
    }

    REQUIRE(a == c);
}

