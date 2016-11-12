# x86-Baseline
A 'boilerplate' of an x86 Operating System and Bootloader written in ASM and C

## Building:
Run `make` in order to build the entire source tree, and `make run` to run the OS in QEMU
Run `make iso` in order to build the GRUB ISO, ready to be written to Boot Media.
Run `make clean` to delete all build files

All build files are located in `build`, with the kernel under `build/bin`, and ISO files under `build/iso`

## Required Tools:
Make sure you have the following apt packages installed to build this project:
```
grub
grub-pc-bin
xorriso
build-essential
nasm
qemu
```