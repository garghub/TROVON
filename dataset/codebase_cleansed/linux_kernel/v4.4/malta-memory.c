static void free_init_pages_eva_malta(void *begin, void *end)
{
free_init_pages("unused kernel", __pa_symbol((unsigned long *)begin),
__pa_symbol((unsigned long *)end));
}
void __init fw_meminit(void)
{
bool eva = config_enabled(CONFIG_EVA);
free_init_pages_eva = eva ? free_init_pages_eva_malta : NULL;
}
void __init prom_free_prom_memory(void)
{
unsigned long addr;
int i;
for (i = 0; i < boot_mem_map.nr_map; i++) {
if (boot_mem_map.map[i].type != BOOT_MEM_ROM_DATA)
continue;
addr = boot_mem_map.map[i].addr;
free_init_pages("YAMON memory",
addr, addr + boot_mem_map.map[i].size);
}
}
phys_addr_t mips_cdmm_phys_base(void)
{
return 0x1fc10000;
}
