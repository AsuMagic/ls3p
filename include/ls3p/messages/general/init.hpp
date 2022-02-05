#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/workspaceedit.hpp>
#include <variant>

namespace ls3p::messages::general
{

struct TextDocumentClientCapabilities
{
    // TODO: synchronization
    // TODO: completion
    // TODO: hover
    // TODO: signatureHelp
    // TODO: declaration
    // TODO: definition
    // TODO: typeDefinition
    // TODO: implementation
    // TODO: references
    // TODO: documentHighlight
    // TODO: documentSymbol
    // TODO: codeAction
    // TODO: codeLens
    // TODO: documentLink
    // TODO: colorProvider
    // TODO: formatting
    // TODO: rangeFormatting
    // TODO: onTypeFormatting
    // TODO: rename
    // TODO: publishDiagnostics
    // TODO: foldingRange
    // TODO: selectionRange
    // TODO: linkedEditingRange
    // TODO: callHierarchy
    // TODO: semanticTokens
    // TODO: moniker
};

struct ClientCapabilities
{
    struct Workspace
    {
        std::optional<bool> apply_edit;

        std::optional<core::WorkspaceEdit::ClientCapabilities> workspace_edit;

        // TODO: didChangeConfiguration
        // TODO: didChangeWatchedFiles
        // TODO: symbol
        // TODO: executeCommand
        
        std::optional<bool> workspace_folders;
        std::optional<bool> configuration;

        // TODO: semanticTokens
        // TODO: codeLens

        struct FileOperations
        {
            std::optional<bool> dynamic_registration;

            std::optional<bool> did_create;
            std::optional<bool> will_create;

            std::optional<bool> did_rename;
            std::optional<bool> will_rename;

            std::optional<bool> did_delete;
            std::optional<bool> will_delete;
        };

        std::optional<FileOperations> file_operations;
    };

    std::optional<Workspace> workspace;

    std::optional<TextDocumentClientCapabilities> text_document;

    struct Window
    {
        std::optional<bool> work_done_progress;

        // TODO: showMessage
        // TODO: showDocument
    };
};

struct InitializeParams
{
    public:
    std::optional<int> process_id;

    struct ClientInfo
    {
        std::string name;
        std::optional<std::string> version;
    };

    std::optional<ClientInfo> client_info;

    std::optional<std::string> locale;

    [[deprecated("root_uri is recommended in the LSP")]]
    std::optional<std::variant<std::string, std::monostate>> root_path;

    std::optional<nlohmann::json> initialization_options;

    ClientCapabilities capabilities;

    // TODO: trace

    std::vector<WorkspaceFolder> workspace_folders;
};

}