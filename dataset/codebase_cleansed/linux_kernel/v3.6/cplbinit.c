void __init generate_cplb_tables_cpu(unsigned int cpu)
{
int i_d, i_i;
unsigned long addr;
struct cplb_entry *d_tbl = dcplb_tbl[cpu];
struct cplb_entry *i_tbl = icplb_tbl[cpu];
printk(KERN_INFO "NOMPU: setting up cplb tables\n");
i_d = i_i = 0;
#ifdef CONFIG_DEBUG_HUNT_FOR_ZERO
d_tbl[i_d].addr = 0;
d_tbl[i_d++].data = SDRAM_OOPS | PAGE_SIZE_1KB;
i_tbl[i_i].addr = 0;
i_tbl[i_i++].data = SDRAM_OOPS | PAGE_SIZE_1KB;
#endif
addr = 0;
for (; addr < memory_start; addr += 4 * 1024 * 1024) {
d_tbl[i_d].addr = addr;
d_tbl[i_d++].data = SDRAM_DGENERIC | PAGE_SIZE_4MB;
i_tbl[i_i].addr = addr;
i_tbl[i_i++].data = SDRAM_IGENERIC | PAGE_SIZE_4MB;
}
#ifdef CONFIG_ROMKERNEL
#ifdef CONFIG_BF60x
addr = CONFIG_ROM_BASE & ~(16 * 1024 * 1024 - 1);
d_tbl[i_d].addr = addr;
d_tbl[i_d++].data = SDRAM_DGENERIC | PAGE_SIZE_16MB;
i_tbl[i_i].addr = addr;
i_tbl[i_i++].data = SDRAM_IGENERIC | PAGE_SIZE_16MB;
#else
addr = CONFIG_ROM_BASE & ~(4 * 1024 * 1024 - 1);
d_tbl[i_d].addr = addr;
d_tbl[i_d++].data = SDRAM_DGENERIC | PAGE_SIZE_4MB;
i_tbl[i_i].addr = addr;
i_tbl[i_i++].data = SDRAM_IGENERIC | PAGE_SIZE_4MB;
#endif
#endif
if (cpu == 0) {
if (L1_DATA_A_LENGTH || L1_DATA_B_LENGTH) {
d_tbl[i_d].addr = L1_DATA_A_START;
d_tbl[i_d++].data = L1_DMEMORY | PAGE_SIZE_4MB;
}
i_tbl[i_i].addr = L1_CODE_START;
i_tbl[i_i++].data = L1_IMEMORY | PAGE_SIZE_4MB;
}
#ifdef CONFIG_SMP
else {
if (L1_DATA_A_LENGTH || L1_DATA_B_LENGTH) {
d_tbl[i_d].addr = COREB_L1_DATA_A_START;
d_tbl[i_d++].data = L1_DMEMORY | PAGE_SIZE_4MB;
}
i_tbl[i_i].addr = COREB_L1_CODE_START;
i_tbl[i_i++].data = L1_IMEMORY | PAGE_SIZE_4MB;
}
#endif
first_switched_dcplb = i_d;
first_switched_icplb = i_i;
BUG_ON(first_switched_dcplb > MAX_CPLBS);
BUG_ON(first_switched_icplb > MAX_CPLBS);
while (i_d < MAX_CPLBS)
d_tbl[i_d++].data = 0;
while (i_i < MAX_CPLBS)
i_tbl[i_i++].data = 0;
}
void __init generate_cplb_tables_all(void)
{
unsigned long uncached_end;
int i_d, i_i;
i_d = 0;
#ifdef CONFIG_MTD_UCLINUX
uncached_end = memory_mtd_start + mtd_size;
#else
uncached_end = memory_end;
#endif
if ((DMA_UNCACHED_REGION >= 1 * 1024 * 1024) || !DMA_UNCACHED_REGION ||
((_ramend - uncached_end) >= 1 * 1024 * 1024))
dcplb_bounds[i_d].eaddr = uncached_end;
else
dcplb_bounds[i_d].eaddr = uncached_end & ~(1 * 1024 * 1024 - 1);
dcplb_bounds[i_d++].data = SDRAM_DGENERIC;
if (DMA_UNCACHED_REGION) {
dcplb_bounds[i_d].eaddr = _ramend;
dcplb_bounds[i_d++].data = SDRAM_DNON_CHBL;
}
if (_ramend != physical_mem_end) {
dcplb_bounds[i_d].eaddr = physical_mem_end;
dcplb_bounds[i_d++].data = (reserved_mem_dcache_on ?
SDRAM_DGENERIC : SDRAM_DNON_CHBL);
}
dcplb_bounds[i_d].eaddr = ASYNC_BANK0_BASE;
dcplb_bounds[i_d++].data = 0;
dcplb_bounds[i_d].eaddr = ASYNC_BANK3_BASE + ASYNC_BANK3_SIZE;
dcplb_bounds[i_d++].data = SDRAM_EBIU;
dcplb_bounds[i_d].eaddr = BOOT_ROM_START;
dcplb_bounds[i_d++].data = 0;
dcplb_bounds[i_d].eaddr = BOOT_ROM_START + BOOT_ROM_LENGTH;
dcplb_bounds[i_d++].data = SDRAM_DGENERIC;
if (L2_LENGTH) {
dcplb_bounds[i_d].eaddr = L2_START;
dcplb_bounds[i_d++].data = 0;
dcplb_bounds[i_d].eaddr = L2_START + L2_LENGTH;
dcplb_bounds[i_d++].data = L2_DMEMORY;
}
dcplb_nr_bounds = i_d;
BUG_ON(dcplb_nr_bounds > ARRAY_SIZE(dcplb_bounds));
i_i = 0;
icplb_bounds[i_i].eaddr = uncached_end;
icplb_bounds[i_i++].data = SDRAM_IGENERIC;
if (_ramend != physical_mem_end) {
if (DMA_UNCACHED_REGION) {
icplb_bounds[i_i].eaddr = _ramend;
icplb_bounds[i_i++].data = 0;
}
icplb_bounds[i_i].eaddr = physical_mem_end;
icplb_bounds[i_i++].data = (reserved_mem_icache_on ?
SDRAM_IGENERIC : SDRAM_INON_CHBL);
}
icplb_bounds[i_i].eaddr = ASYNC_BANK0_BASE;
icplb_bounds[i_i++].data = 0;
icplb_bounds[i_i].eaddr = ASYNC_BANK3_BASE + ASYNC_BANK3_SIZE;
icplb_bounds[i_i++].data = SDRAM_EBIU;
icplb_bounds[i_i].eaddr = BOOT_ROM_START;
icplb_bounds[i_i++].data = 0;
icplb_bounds[i_i].eaddr = BOOT_ROM_START + BOOT_ROM_LENGTH;
icplb_bounds[i_i++].data = SDRAM_IGENERIC;
if (L2_LENGTH) {
icplb_bounds[i_i].eaddr = L2_START;
icplb_bounds[i_i++].data = 0;
icplb_bounds[i_i].eaddr = L2_START + L2_LENGTH;
icplb_bounds[i_i++].data = L2_IMEMORY;
}
icplb_nr_bounds = i_i;
BUG_ON(icplb_nr_bounds > ARRAY_SIZE(icplb_bounds));
}
