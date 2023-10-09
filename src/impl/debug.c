#include <debug.h>

#ifdef _UEFI_DEBUG

CHAR16 *errmsg[35] = {
    L"Success!",
    L"Load error!",
    L"Parameter invalid!",
    L"Unsupported!",
    L"Bad buffer size!",
    L"Buffer too small!",
    L"Data not ready!",
    L"Physical device error!",
    L"Device cannot be written to!",
    L"Resource run out!",
    L"Inconsistency on the filesystem!",
    L"Volume full!",
    L"No media!",
    L"Medium device changed!",
};

VOID EFIPrintStatus(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut, 
    EFI_STATUS status) 
{
    // Extract the status code. We are following the UEFI specs. So the 
    // codes will reside in the low bits of the status.

    status &= 0xff;

    ConOut -> SetAttribute(ConOut, EFI_CYAN);
    ConOut -> OutputString(ConOut, errmsg[status]);
}

#endif