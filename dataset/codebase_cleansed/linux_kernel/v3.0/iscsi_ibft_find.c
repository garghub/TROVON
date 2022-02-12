static int __init acpi_find_ibft(struct acpi_table_header *header)
{
ibft_addr = (struct acpi_table_ibft *)header;
return 0;
}
static int __init find_ibft_in_mem(void)
{
unsigned long pos;
unsigned int len = 0;
void *virt;
int i;
for (pos = IBFT_START; pos < IBFT_END; pos += 16) {
if (pos == VGA_MEM)
pos += VGA_SIZE;
virt = isa_bus_to_virt(pos);
for (i = 0; i < ARRAY_SIZE(ibft_signs); i++) {
if (memcmp(virt, ibft_signs[i].sign, IBFT_SIGN_LEN) ==
0) {
unsigned long *addr =
(unsigned long *)isa_bus_to_virt(pos + 4);
len = *addr;
if (pos + len <= (IBFT_END-1)) {
ibft_addr = (struct acpi_table_ibft *)virt;
goto done;
}
}
}
}
done:
return len;
}
unsigned long __init find_ibft_region(unsigned long *sizep)
{
#ifdef CONFIG_ACPI
int i;
#endif
ibft_addr = NULL;
#ifdef CONFIG_ACPI
for (i = 0; i < ARRAY_SIZE(ibft_signs) && !ibft_addr; i++)
acpi_table_parse(ibft_signs[i].sign, acpi_find_ibft);
#endif
if (!ibft_addr && !efi_enabled)
find_ibft_in_mem();
if (ibft_addr) {
*sizep = PAGE_ALIGN(ibft_addr->header.length);
return (u64)isa_virt_to_bus(ibft_addr);
}
*sizep = 0;
return 0;
}
