#ifndef __RISE_DEBUG_H__
#define __RISE_DEBUG_H__

#ifdef _UEFI_DEBUG
#include <efi.h>

VOID EFIPrintStatus(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut, 
    EFI_STATUS status);

#endif

#endif    // __RISE_DEBUG_H__