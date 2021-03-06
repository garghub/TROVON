static void sh4_flush_icache_range(void *args)
{
struct flusher_data *data = args;
unsigned long start, end;
unsigned long flags, v;
int i;
start = data->addr1;
end = data->addr2;
if (((end - start) >> PAGE_SHIFT) >= MAX_ICACHE_PAGES) {
local_flush_cache_all(NULL);
return;
}
start &= ~(L1_CACHE_BYTES-1);
end += L1_CACHE_BYTES-1;
end &= ~(L1_CACHE_BYTES-1);
local_irq_save(flags);
jump_to_uncached();
for (v = start; v < end; v += L1_CACHE_BYTES) {
unsigned long icacheaddr;
int j, n;
__ocbwb(v);
icacheaddr = CACHE_IC_ADDRESS_ARRAY | (v &
cpu_data->icache.entry_mask);
n = boot_cpu_data.icache.n_aliases;
for (i = 0; i < cpu_data->icache.ways; i++) {
for (j = 0; j < n; j++)
__raw_writel(0, icacheaddr + (j * PAGE_SIZE));
icacheaddr += cpu_data->icache.way_incr;
}
}
back_to_cached();
local_irq_restore(flags);
}
static inline void flush_cache_one(unsigned long start, unsigned long phys)
{
unsigned long flags, exec_offset = 0;
if ((boot_cpu_data.flags & CPU_HAS_P2_FLUSH_BUG) ||
(start < CACHE_OC_ADDRESS_ARRAY))
exec_offset = cached_to_uncached;
local_irq_save(flags);
__flush_cache_one(start, phys, exec_offset);
local_irq_restore(flags);
}
static void sh4_flush_dcache_page(void *arg)
{
struct page *page = arg;
unsigned long addr = (unsigned long)page_address(page);
#ifndef CONFIG_SMP
struct address_space *mapping = page_mapping(page);
if (mapping && !mapping_mapped(mapping))
clear_bit(PG_dcache_clean, &page->flags);
else
#endif
flush_cache_one(CACHE_OC_ADDRESS_ARRAY |
(addr & shm_align_mask), page_to_phys(page));
wmb();
}
static void flush_icache_all(void)
{
unsigned long flags, ccr;
local_irq_save(flags);
jump_to_uncached();
ccr = __raw_readl(CCR);
ccr |= CCR_CACHE_ICI;
__raw_writel(ccr, CCR);
back_to_cached();
local_irq_restore(flags);
}
static void flush_dcache_all(void)
{
unsigned long addr, end_addr, entry_offset;
end_addr = CACHE_OC_ADDRESS_ARRAY +
(current_cpu_data.dcache.sets <<
current_cpu_data.dcache.entry_shift) *
current_cpu_data.dcache.ways;
entry_offset = 1 << current_cpu_data.dcache.entry_shift;
for (addr = CACHE_OC_ADDRESS_ARRAY; addr < end_addr; ) {
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
__raw_writel(0, addr); addr += entry_offset;
}
}
static void sh4_flush_cache_all(void *unused)
{
flush_dcache_all();
flush_icache_all();
}
static void sh4_flush_cache_mm(void *arg)
{
struct mm_struct *mm = arg;
if (cpu_context(smp_processor_id(), mm) == NO_CONTEXT)
return;
flush_dcache_all();
}
static void sh4_flush_cache_page(void *args)
{
struct flusher_data *data = args;
struct vm_area_struct *vma;
struct page *page;
unsigned long address, pfn, phys;
int map_coherent = 0;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
void *vaddr;
vma = data->vma;
address = data->addr1 & PAGE_MASK;
pfn = data->addr2;
phys = pfn << PAGE_SHIFT;
page = pfn_to_page(pfn);
if (cpu_context(smp_processor_id(), vma->vm_mm) == NO_CONTEXT)
return;
pgd = pgd_offset(vma->vm_mm, address);
pud = pud_offset(pgd, address);
pmd = pmd_offset(pud, address);
pte = pte_offset_kernel(pmd, address);
if (!(pte_val(*pte) & _PAGE_PRESENT))
return;
if ((vma->vm_mm == current->active_mm))
vaddr = NULL;
else {
map_coherent = (current_cpu_data.dcache.n_aliases &&
test_bit(PG_dcache_clean, &page->flags) &&
page_mapped(page));
if (map_coherent)
vaddr = kmap_coherent(page, address);
else
vaddr = kmap_atomic(page);
address = (unsigned long)vaddr;
}
flush_cache_one(CACHE_OC_ADDRESS_ARRAY |
(address & shm_align_mask), phys);
if (vma->vm_flags & VM_EXEC)
flush_icache_all();
if (vaddr) {
if (map_coherent)
kunmap_coherent(vaddr);
else
kunmap_atomic(vaddr);
}
}
static void sh4_flush_cache_range(void *args)
{
struct flusher_data *data = args;
struct vm_area_struct *vma;
unsigned long start, end;
vma = data->vma;
start = data->addr1;
end = data->addr2;
if (cpu_context(smp_processor_id(), vma->vm_mm) == NO_CONTEXT)
return;
if (boot_cpu_data.dcache.n_aliases == 0)
return;
flush_dcache_all();
if (vma->vm_flags & VM_EXEC)
flush_icache_all();
}
static void __flush_cache_one(unsigned long addr, unsigned long phys,
unsigned long exec_offset)
{
int way_count;
unsigned long base_addr = addr;
struct cache_info *dcache;
unsigned long way_incr;
unsigned long a, ea, p;
unsigned long temp_pc;
dcache = &boot_cpu_data.dcache;
way_count = dcache->ways;
way_incr = dcache->way_incr;
asm volatile("mov.l 1f, %0\n\t"
"add %1, %0\n\t"
"jmp @%0\n\t"
"nop\n\t"
".balign 4\n\t"
"1: .long 2f\n\t"
"2:\n" : "=&r" (temp_pc) : "r" (exec_offset));
do {
ea = base_addr + PAGE_SIZE;
a = base_addr;
p = phys;
do {
*(volatile unsigned long *)a = p;
*(volatile unsigned long *)(a+32) = p;
a += 64;
p += 64;
} while (a < ea);
base_addr += way_incr;
} while (--way_count != 0);
}
void __init sh4_cache_init(void)
{
printk("PVR=%08x CVR=%08x PRR=%08x\n",
__raw_readl(CCN_PVR),
__raw_readl(CCN_CVR),
__raw_readl(CCN_PRR));
local_flush_icache_range = sh4_flush_icache_range;
local_flush_dcache_page = sh4_flush_dcache_page;
local_flush_cache_all = sh4_flush_cache_all;
local_flush_cache_mm = sh4_flush_cache_mm;
local_flush_cache_dup_mm = sh4_flush_cache_mm;
local_flush_cache_page = sh4_flush_cache_page;
local_flush_cache_range = sh4_flush_cache_range;
sh4__flush_region_init();
}
