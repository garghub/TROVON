void __init prom_meminit(void)
{
u64 base, size;
int bank;
crime_init();
for (bank=0; bank < CRIME_MAXBANKS; bank++) {
u64 bankctl = crime->bank_ctrl[bank];
base = (bankctl & CRIME_MEM_BANK_CONTROL_ADDR) << 25;
if (bank != 0 && base == 0)
continue;
size = (bankctl & CRIME_MEM_BANK_CONTROL_SDRAM_SIZE) ? 128 : 32;
size <<= 20;
if (base + size > (256 << 20))
base += CRIME_HI_MEM_BASE;
printk("CRIME MC: bank %u base 0x%016Lx size %LuMiB\n",
bank, base, size >> 20);
add_memory_region(base, size, BOOT_MEM_RAM);
}
}
void __init prom_free_prom_memory(void)
{
}
