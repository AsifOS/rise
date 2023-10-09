#ifndef __RISE_EFIBIND_H__
#define __RISE_EFIBIND_H__

#ifndef __MSC_VER

// If the compiler is not Microsoft C compiler, define the SAL annotations 
// explicitely.

#define _In_
#define _Out_
#endif    // __MSC_VER

#include <stdint.h>

#ifndef VOID
#define VOID void
#endif    // VOID

// To define EFI error codes.

// We need the mask because the EFI status has ranges which signifies the 
// usage of those codes either by the main UEFI specs. or the OEM. We are 
// using UEFI Runtime defined in the specification, not OEM specific code.
// The UEFI error code range is from 0x8000000000000000 to 0x9FFFFFFFFFFFFFFF 
// (For a 64-bit architecture).

#define EFI_ERROR_MASK   0x8000000000000000
#define EFIERR(a)        (EFI_ERROR_MASK | a)

// UEFI specs. warnings start from 0.

#define EFIWARN(a)       (a)

// Basic EFI integer types with various widths.

typedef char           CHAR8;
typedef uint_least16_t CHAR16;
typedef int8_t         INT8;
typedef uint8_t        UINT8;

typedef int16_t        INT16;
typedef uint16_t       UINT16;

typedef int32_t        INT32;
typedef uint32_t       UINT32;

typedef int64_t        INT64;
typedef uint64_t       UINT64;

// Some EFI data types depend on the architecture byte width. Those definitons 
// will use these.

#define INTN  INT64
#define UINTN UINT64

#endif    // __RISE_EFIBIND_H__