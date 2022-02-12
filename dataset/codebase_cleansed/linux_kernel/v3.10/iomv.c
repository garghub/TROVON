void *sn_io_addr(unsigned long port)
{
if (!IS_RUNNING_ON_SIMULATOR()) {
if (IS_LEGACY_VGA_IOPORT(port))
return (__ia64_mk_io_addr(port));
if (port < (64 * 1024))
return NULL;
if (SN_ACPI_BASE_SUPPORT())
return (__ia64_mk_io_addr(port));
else
return ((void *)(port | __IA64_UNCACHED_OFFSET));
} else {
unsigned long addr;
addr = (is_shub2() ? 0xc00000028c000000UL : 0xc0000087cc000000UL) | ((port >> 2) << 12);
if ((port >= 0x1f0 && port <= 0x1f7) || port == 0x3f6 || port == 0x3f7)
addr |= port;
return (void *)addr;
}
}
void __sn_mmiowb(void)
{
volatile unsigned long *adr = pda->pio_write_status_addr;
unsigned long val = pda->pio_write_status_val;
while ((*adr & SH_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK) != val)
cpu_relax();
}
