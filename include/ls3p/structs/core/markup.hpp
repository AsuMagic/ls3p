#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>

namespace ls3p::structs::core
{

namespace markup_kind
{

static constexpr std::string_view
    PLAIN_TEXT = "plaintext",
    MARKDOWN = "markdown";

}

/// \see markup_kind
using MarkupKind = std::string;

struct MarkupContent
{
    MarkupKind kind;

    std::string value;

    LS3P_ARCHIVE(MarkupContent)
    {
        archive
            ("kind", kind)
            ("value", value);
    }
};

struct MarkdownClientCapabilities
{
    std::string parser;
    std::optional<std::string> version;

    LS3P_ARCHIVE(MarkdownClientCapabilities)
    {
        archive
            ("parser", parser)
            ("version", version);
    }
};

}