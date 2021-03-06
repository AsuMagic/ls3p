#include <catch2/catch.hpp>

#include <ls3p/structs/common.hpp>
#include <nlohmann/json.hpp>
#include <variant>

using nlohmann::json;
using namespace ls3p::structs;

TEST_CASE("Test std::optional<> parsing", "[parsing]")
{
    std::optional<int> value;
    ls3p::util::FromArchiver{json::parse(R"({ "value": 123 })")}("value", value);
    REQUIRE(value.has_value());
    REQUIRE(value.value() == 123);

    ls3p::util::FromArchiver{json::parse(R"({})")}("value", value);
    REQUIRE(!value.has_value());
}

TEST_CASE("Test std::variant<> parsing", "[parsing]")
{
    std::variant<std::monostate, int, std::string> value;

    ls3p::util::FromArchiver{json::parse(R"({ "value": 123 })")}("value", value);
    REQUIRE(std::holds_alternative<int>(value));
    REQUIRE(std::get<int>(value) == 123);

    ls3p::util::FromArchiver{json::parse(R"({ "value": "hello" })")}("value", value);
    REQUIRE(std::holds_alternative<std::string>(value));
    REQUIRE(std::get<std::string>(value) == "hello");

    ls3p::util::FromArchiver{json::parse(R"({ "value": null })")}("value", value);
    REQUIRE(std::holds_alternative<std::monostate>(value));
}