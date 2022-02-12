static unsigned long map_addr(unsigned long phys)
{
static unsigned long dm_base = 0xFFFFFFFF;
int offset;
offset = phys - dm_base;
if ((offset < 0) || (offset >= MMCU_DIRECTMAPn_ADDR_SCALE)) {
dm_base = phys & ~(MMCU_DIRECTMAPn_ADDR_SCALE - 1);
metag_out32(dm_base, MMCU_DIRECTMAP3_ADDR);
offset = phys - dm_base;
}
return DM3_BASE + offset;
}
static inline unsigned long __get_mmu_base(void)
{
unsigned long base_phys;
unsigned int stride;
if (is_global_space(PAGE_OFFSET))
stride = 4;
else
stride = hard_processor_id();
base_phys = metag_in32(MMCU_TABLE_PHYS_ADDR);
base_phys += (0x800 * stride);
return base_phys;
}
static unsigned long pgd_entry_addr(unsigned long virt)
{
unsigned long pgd_phys;
unsigned long pgd_virt;
if (!mmu_base_phys)
mmu_base_phys = __get_mmu_base();
if (is_global_space(virt)) {
virt &= ~0x80000000;
}
pgd_phys = mmu_base_phys + ((virt >> PGDIR_SHIFT) * 4);
pgd_virt = map_addr(pgd_phys);
return pgd_virt;
}
static unsigned long pgtable_entry_addr(unsigned long virt)
{
unsigned long pgtable_phys;
unsigned long pgtable_virt, pte_virt;
pgtable_phys = metag_in32(pgd_entry_addr(virt)) & MMCU_ENTRY_ADDR_BITS;
pgtable_virt = map_addr(pgtable_phys);
pte_virt = pgtable_virt + ((virt >> PAGE_SHIFT) & 0x3FF) * 4;
return pte_virt;
}
unsigned long mmu_read_first_level_page(unsigned long vaddr)
{
return metag_in32(pgd_entry_addr(vaddr));
}
unsigned long mmu_read_second_level_page(unsigned long vaddr)
{
return metag_in32(pgtable_entry_addr(vaddr));
}
unsigned long mmu_get_base(void)
{
static unsigned long __base;
if (!__base)
__base = pgd_entry_addr(0);
return __base;
}
void __init mmu_init(unsigned long mem_end)
{
unsigned long entry, addr;
pgd_t *p_swapper_pg_dir;
addr = PAGE_OFFSET;
entry = pgd_index(PAGE_OFFSET);
p_swapper_pg_dir = pgd_offset_k(0) + entry;
while (addr <= META_MEMORY_LIMIT) {
unsigned long pgd_entry;
pgd_entry = mmu_read_first_level_page(addr);
pgd_val(*p_swapper_pg_dir) = pgd_entry;
p_swapper_pg_dir++;
addr += PGDIR_SIZE;
}
}
