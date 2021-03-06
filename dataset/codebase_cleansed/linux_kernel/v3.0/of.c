static void *of_try_claim(unsigned long size)
{
unsigned long addr = 0;
if (claim_base == 0)
claim_base = _ALIGN_UP((unsigned long)_end, ONE_MB);
for(; claim_base < RAM_END; claim_base += ONE_MB) {
#ifdef DEBUG
printf(" trying: 0x%08lx\n\r", claim_base);
#endif
addr = (unsigned long)of_claim(claim_base, size, 0);
if ((void *)addr != (void *)-1)
break;
}
if (addr == 0)
return NULL;
claim_base = PAGE_ALIGN(claim_base + size);
return (void *)addr;
}
static void of_image_hdr(const void *hdr)
{
const Elf64_Ehdr *elf64 = hdr;
if (elf64->e_ident[EI_CLASS] == ELFCLASS64) {
if (claim_base < PROG_START)
claim_base = PROG_START;
}
}
void platform_init(unsigned long a1, unsigned long a2, void *promptr)
{
platform_ops.image_hdr = of_image_hdr;
platform_ops.malloc = of_try_claim;
platform_ops.exit = of_exit;
platform_ops.vmlinux_alloc = of_vmlinux_alloc;
dt_ops.finddevice = of_finddevice;
dt_ops.getprop = of_getprop;
dt_ops.setprop = of_setprop;
of_console_init();
of_init(promptr);
loader_info.promptr = promptr;
if (a1 && a2 && a2 != 0xdeadbeef) {
loader_info.initrd_addr = a1;
loader_info.initrd_size = a2;
}
}
