IDIR=../
CC=gcc
CCFLAGS=-I$(IDIR) -O2 -pipe -Wall -Wextra \
	-std=gnu2x \
	-Wall \
	-Wextra \
	-Werror \
	-fno-pic \
	-mno-sse \
	-mno-sse2 \
	-mno-mmx \
	-g \
	-mno-80387 \
	-mno-red-zone  \
	-mcmodel=kernel \
	-ffreestanding \
	-fno-stack-protector


CFLAGS=-I$(IDIR) -O2 -w \
	-std=gnu2x \
	-g \
	-ffreestanding \
	-fno-stack-protector


ODIR=object
LDIR=library

LIBS=

LD              = ld
QEMU            = qemu-system-x86_64
QEMUFLAGS       = -m 1G -enable-kvm -cpu host
LDINTERNALFLAGS := -Tlinker.ld -static -nostdlib -no-pie
INTERNALCFLAGS  := -I. -ffreestanding -fno-stack-protector   \
	-fno-pic -fomit-frame-pointer -mno-80387 -mno-mmx -mno-3dnow -mno-sse \
	-mno-sse2 -masm=intel -mcmodel=kernel


ISO_DIR = iso
ISO_BOOT = $(ISO_DIR)/boot
GRUB_CONFIG = $(ISO_BOOT)/grub/grub.cfg



_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Rheinheart.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


_ASOBJ = boot.asm.o
ASOBJ = $(patsubst %,$(ODIR)/%,$(_ASOBJ))



$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
$(ODIR)/%.asm.o: %.asm $(DEPS)
	nasm -f elf64 -o $@ $<


LDHARDFLAGS := $(LDFLAGS)        \
	-static                   \
	-no-pie                   \
	-z max-page-size=0x1000  \
	-T link.ld

all: Rheinheart GRUB QEMU


Rheinheart: $(ASOBJ) $(OBJ)
	$(LD) $(LDHARDFLAGS) $(OBJ) $(ASOBJ) -o iso/boot/Rheinheart.elf

GRUB:
	grub-mkrescue -o Rheinheart.iso iso

QEMU:
	qemu-system-x86_64 -cdrom Rheinheart.iso

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~ 
