CC=gcc
SHARED_FLAGS = -fno-builtin -O2 -nostdinc -nostdlib -ffreestanding -g -Wall -Wextra \
               -Werror -I../ -MMD -mno-red-zone -mcmodel=kernel -fno-pie -std=c2x
CFLAGS = $(SHARED_FLAGS)
ASFLAGS = $(SHARED_FLAGS) -Wa,--divide

OBJS := Nexus.o
OBJS += Rhineheart.o
OBJS += core/driver/screen/screen.o

DFILES = $(patsubst %.o,%.d,$(OBJS))

all: Rhineheart

Rhineheart: $(OBJS)
	$(CC) -z max-page-size=0x1000 $(CFLAGS) -no-pie -Wl,--build-id=none -T Rhineheart.ld -o $@ $(OBJS)

clean:
	find -name "*~" -delete
	rm -rf $(OBJS) $(DFILES) Rhineheart

$(OBJS): Makefile
-include $(DFILES)
