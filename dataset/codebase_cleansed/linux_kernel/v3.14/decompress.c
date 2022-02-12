void error(char *x)
{
puts("\n\n");
puts(x);
puts("\n\n -- System halted");
while (1)
;
}
void decompress_kernel(unsigned long boot_heap_start)
{
unsigned long zimage_start, zimage_size;
zimage_start = (unsigned long)(&__image_begin);
zimage_size = (unsigned long)(&__image_end) -
(unsigned long)(&__image_begin);
puts("zimage at: ");
puthex(zimage_start);
puts(" ");
puthex(zimage_size + zimage_start);
puts("\n");
free_mem_ptr = boot_heap_start;
free_mem_end_ptr = boot_heap_start + BOOT_HEAP_SIZE;
puts("Uncompressing Linux at load address ");
puthex(VMLINUX_LOAD_ADDRESS_ULL);
puts("\n");
decompress((char *)zimage_start, zimage_size, 0, 0,
(void *)VMLINUX_LOAD_ADDRESS_ULL, 0, error);
puts("Now, booting the kernel...\n");
}
