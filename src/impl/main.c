#include <efi.h>
#include <debug.h>

EFI_STATUS efi_main(_In_ EFI_HANDLE ImageHandle, _In_ EFI_SYSTEM_TABLE 
    *SystemTable) 
{
    // Clear the screen buffer.

    SystemTable -> ConOut -> Reset(SystemTable -> ConOut, 1);

    // Set text color.

    SystemTable -> ConOut -> SetAttribute(SystemTable -> ConOut, EFI_CYAN);

    // Write to the screen.

    SystemTable -> ConOut -> 
        OutputString(SystemTable -> ConOut, L"Hit a key...");

    // Clear keyboard input buffer.1

    EFI_STATUS status = SystemTable -> ConIn -> Reset(SystemTable -> ConIn, 1);

    EFIPrintStatus(SystemTable -> ConOut, status);

    EFI_INPUT_KEY key;

    while(SystemTable -> ConIn -> ReadKeyStroke(SystemTable -> ConIn, &key) == EFI_NOT_READY);

    return EFI_SUCCESS;
}