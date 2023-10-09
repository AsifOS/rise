default_target : build

CC          := x86_64-w64-mingw32-gcc
TARGET_ARCH := x86_64

SRC_DIR   := src/impl
OBJ_DIR   := bin/build
DEPS_DIR  := bin/build/deps

SRC_FILES := $(shell find $(SRC_DIR)/ -name *.c)
OBJ_FILES := $(patsubst %.c, $(OBJ_DIR)/%.c.obj, $(notdir $(SRC_FILES)))

INCLUDE   := src/include/

CFLAGS := -Wall -Werror -mabi=ms -ffreestanding -MMD -MF
LFLAGS := -Wall -Werror -mabi=ms -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e efi_main


ifneq ($(findstring build_i386, $(MAKECMDGOALS)), ) 
	CC          := i386-w64-mingw32-gcc
	TARGET_ARCH := i386
endif

ifneq ($(findstring debug, $(MAKECMDGOALS)), )
	CFLAGS := -D_UEFI_DEBUG $(CFLAGS)
endif

OUTPUT_DIR := bin/target/$(TARGET_ARCH)

.PHONY  : 
.SILENT : 

debug : build
build : create BOOTX64.EFI

BOOTX64.EFI : $(OBJ_FILES)
	@echo $(OBJ_FILES)
	@echo "Linking and generating BOOTX64.EFI..."
	$(CC) $(LFLAGS) $^ -o $(OUTPUT_DIR)/BOOTX64.EFI

$(OBJ_FILES) : $(OBJ_DIR)/%.c.obj : $(SRC_DIR)/%.c
	@echo "Compiling C translation '$(notdir $<)', generating object '$@'..."
	$(CC) $(CFLAGS) $(patsubst %.c.obj, $(DEPS_DIR)/%.d, $(notdir $@)) -I$(INCLUDE) -c $< -o $@

create : 
	mkdir -p bin/{build/deps,target/$(TARGET_ARCH)}

clean : 
	rm -rf bin

# Inlcude all the header file dependencies.

-include $(wildcard $(DEPS_DIR)/*.d)