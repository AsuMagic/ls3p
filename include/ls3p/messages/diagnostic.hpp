#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/location.hpp>

namespace ls3p::messages
{

struct CodeDescription
{
    URI href;
};

struct DiagnosticRelatedInformation
{
    Location location;
    std::string message;
};

enum class DiagnosticSeverity : Integer
{
    ERROR = 1,
    WARNING = 2,
    INFORMATION = 3,
    HINT = 4
};

enum class DiagnosticTag : Integer
{
    UNNECESSARY = 1,
    DEPRECATED = 2
};

struct Diagnostic
{
    Range range;
    std::optional<DiagnosticSeverity> severity;
    std::optional<std::variant<Integer, std::string>> code;
    std::optional<CodeDescription> code_description;
    std::optional<std::string> source;
    std::string message;
    std::optional<std::vector<std::string>> tags;
    std::optional<DiagnosticRelatedInformation> related_information;
    std::optional<nlohmann::json> data;
};

}