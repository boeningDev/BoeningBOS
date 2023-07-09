#!/bin/bash
cd iso
cd boot
rm kernel
cd ..
cd ..
cp kernel iso/boot
genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso
