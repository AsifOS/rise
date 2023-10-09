#ifndef __RISE_EFIDEF_H__
#define __RISE_EFIDEF_H__

// EFI data types mentioned in the official specification.

typedef UINT8     BOOLEAN;

typedef UINTN     EFI_STATUS;
typedef VOID      *EFI_HANDLE;
typedef VOID      *EFI_EVENT;

// EFI foreground color defines.

#define EFI_BLACK                     0x00
#define EFI_BLUE                      0x01
#define EFI_GREEN                     0x02
#define EFI_CYAN                      0x03
#define EFI_RED                       0x04
#define EFI_MAGENTA                   0x05
#define EFI_BROWN                     0x06
#define EFI_LIGHTGRAY                 0x07
#define EFI_DARKGRAY                  0x08
#define EFI_LIGHTBLUE                 0x09
#define EFI_LIGHTGREEN                0x0A
#define EFI_LIGHTCYAN                 0x0B
#define EFI_LIGHTRED                  0x0C
#define EFI_LIGHTMAGENTA              0x0D
#define EFI_YELLOW                    0x0E
#define EFI_WHITE                     0x0F

// EFI background color defines.

#define EFI_BACKGROUND_BLACK          0x00
#define EFI_BACKGROUND_BLUE           0x10
#define EFI_BACKGROUND_GREEN          0x20
#define EFI_BACKGROUND_CYAN           0x30
#define EFI_BACKGROUND_RED            0x40
#define EFI_BACKGROUND_MAGENTA        0x50
#define EFI_BACKGROUND_BROWN          0x60
#define EFI_BACKGROUND_LIGHTGRAY      0x70

// EFI status success.

#define EFI_SUCCESS 0

// EFI status error codes.

#define EFI_LOAD_ERROR                EFIERR(1)
#define EFI_INVALID_PARAMETER         EFIERR(2)
#define EFI_UNSUPPORTED               EFIERR(3)
#define EFI_BAD_BUFFER_SIZE           EFIERR(4)
#define EFI_BUFFER_TOO_SMALL          EFIERR(5)
#define EFI_NOT_READY                 EFIERR(6)
#define EFI_DEVICE_ERROR              EFIERR(7)
#define EFI_WRITE_PROTECTED           EFIERR(8)
#define EFI_OUT_OF_RESOURCES          EFIERR(9)
#define EFI_VOLUME_CORRUPTED          EFIERR(10)
#define EFI_VOLUME_FULL               EFIERR(11)
#define EFI_NO_MEDIA                  EFIERR(12)
#define EFI_MEDIA_CHANGED             EFIERR(13)
#define EFI_NOT_FOUND                 EFIERR(14)
#define EFI_ACCESS_DENIED             EFIERR(15)
#define EFI_NO_RESPONSE               EFIERR(16)
#define EFI_NO_MAPPING                EFIERR(17)
#define EFI_TIMEOUT                   EFIERR(18)
#define EFI_NOT_STARTED               EFIERR(19)
#define EFI_ALREADY_STARTED           EFIERR(20)
#define EFI_ABORTED                   EFIERR(21)
#define EFI_ICMP_ERROR                EFIERR(22)
#define EFI_TFTP_ERROR                EFIERR(23)
#define EFI_PROTOCOL_ERROR            EFIERR(24)
#define EFI_INCOMPATIBLE_VERSION      EFIERR(25)
#define EFI_SECURITY_VIOLATION        EFIERR(26)
#define EFI_CRC_ERROR                 EFIERR(27)
#define EFI_END_OF_MEDIA              EFIERR(28)
#define EFI_END_OF_FILE               EFIERR(31)
#define EFI_INVALID_LANGUAGE          EFIERR(32)
#define EFI_COMPROMISED_DATA          EFIERR(33)
#define EFI_IP_ADDRESS_CONFLICT       EFIERR(34)
#define EFI_HTTP_ERROR                EFIERR(35)

// EFI status warning codes.

#define EFI_WARN_UNKNOWN_GLYPH        EFIWARN(1)
#define EFI_WARN_DELETE_FAILURE       EFIWARN(2)
#define EFI_WARN_WRITE_FAILURE        EFIWARN(3)
#define EFI_WARN_BUFFER_TOO_SMALL     EFIWARN(4)
#define EFI_WARN_STALE_DATA           EFIWARN(5)
#define EFI_WARN_FILE_SYSTEM          EFIWARN(6)
#define EFI_WARN_RESET_REQUIRED       EFIWARN(7)

#endif    // __RISE_EFIDEF_H__