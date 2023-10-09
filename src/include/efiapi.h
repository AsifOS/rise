#ifndef __RISE_EFIAPI_H__
#define __RISE_EFIAPI_H__

// Forward reference construct.

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL    EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL   EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;
typedef struct _EFI_INPUT_KEY                     EFI_INPUT_KEY;

/** Function typedefs. */

// EFI Output protocol related typedefs.

typedef EFI_STATUS (*EFI_TEXT_RESET)(_In_ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    *This, _In_ BOOLEAN ExtendedVerification);

typedef EFI_STATUS (*EFI_TEXT_STRING)(_In_ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    *This, _In_ CHAR16 *String);

typedef EFI_STATUS (*EFI_TEXT_TEST_STRING)(_In_ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    *This, _In_ CHAR16 *String);

typedef EFI_STATUS (*EFI_TEXT_QUERY_MODE)(_In_ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    *This, _In_ UINTN ModeNumber, _Out_ UINTN *Columns, _Out_ UINTN *Rows);

typedef EFI_STATUS (*EFI_TEXT_SET_MODE)(_In_ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL 
    *This, _In_ UINTN ModeNumber);

typedef EFI_STATUS (*EFI_TEXT_SET_ATTRIBUTE)(_In_ 
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, _In_ UINTN Attribute);

// EFI Input related typedefs.

typedef EFI_STATUS (*EFI_INPUT_RESET)(_In_ EFI_SIMPLE_TEXT_INPUT_PROTOCOL
    *This, _In_ BOOLEAN ExtendedVerification);

typedef EFI_STATUS (*EFI_INPUT_READ_KEY)(_In_ EFI_SIMPLE_TEXT_INPUT_PROTOCOL
    *This, _Out_ EFI_INPUT_KEY *Key);

/** Struct definitions. */

struct _EFI_INPUT_KEY {
    CHAR16    ScanCode;
    CHAR16    UnicodeChar;
};

typedef struct _EFI_TABLE_HEADER {
    UINT64    Signature;
    UINT32    Revision;
    UINT32    HeaderSize;
    UINT32    CRC32;
    UINT32    Reserved;
} EFI_TABLE_HEADER;

// The EFI Runtime system header table passed to the EFI application entry 
// point.

typedef struct _EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER                    Hdr;
    CHAR16                              *FirmwareVersion;
    UINT32                              FirmwareRevision;
    EFI_HANDLE                          ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL      *ConIn;
    EFI_HANDLE                          ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL     *ConOut;
    EFI_HANDLE                          StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL     *StdErr;
} EFI_SYSTEM_TABLE;

struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET       Reset;
    EFI_INPUT_READ_KEY    ReadKeyStroke;
    EFI_EVENT             WaitForKey;
};

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_TEXT_RESET             Reset;
    EFI_TEXT_STRING            OutputString;
    EFI_TEXT_TEST_STRING       TestString;
    EFI_TEXT_QUERY_MODE        QueryMode;
    EFI_TEXT_SET_MODE          SetMode;
    EFI_TEXT_SET_ATTRIBUTE     SetAttribute;
};

#endif    // __RISE_EFIAPI_H__