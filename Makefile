ISO_FILE=Rhineheart.iso

.PHONY: all
.PHONY: kernel
.PHONY: qemu
.PHONY: iso
.PHONY: clean

ifneq (, $(shell which grub2-mkrescue 2> /dev/null))
  GRUB_MKRESCUE = grub2-mkrescue
else ifneq (, $(shell which grub-mkrescue 2> /dev/null))
  GRUB_MKRESCUE = grub-mkrescue
else
    $(error "Cannot find grub-mkrescue or grub2-mkrescue")
endif

all: Rhineheart Qemu

Rhineheart:
	make -C Rhineheart all

Qemu: $(ISO_FILE)
	qemu-system-x86_64 -cdrom $(ISO_FILE) -serial stdio -m 1024M

clean:
	make -C Rhineheart clean
	rm -rf iso
	rm -rf $(ISO_FILE)

iso: $(ISO_FILE)

$(ISO_FILE): Rhineheart
	mkdir -p iso/boot/grub
	cp grub.cfg iso/boot/grub/
	cp Rhineheart/Rhineheart iso/boot/
	$(GRUB_MKRESCUE) -o $(ISO_FILE) iso
