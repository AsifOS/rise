#ifndef __RISE_EFI_H__
#define __RISE_EFI_H__

// Predefined macro to indicate that Rise EFI is being used.

#ifndef _RISE_EFI
#define _RISE_EFI
#endif    // _RISE_EFI

#ifdef __cplusplus
extern "C" {
#endif    // __cplusplus

// Architecture specific includes.

#if defined(_M_X64) || defined(__x86_64__) || defined(__amd64__) 
#include <x86_64/efibind.h>
#else 
#error Rise EFI : Unsupported architecutre
#endif

// Common includes.

#include <efidef.h>
#include <efiapi.h>

#ifdef __cplusplus
}
#endif    // __cplusplus

#endif    // __RISE_EFI_H__