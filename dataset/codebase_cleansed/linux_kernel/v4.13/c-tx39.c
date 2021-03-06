static void tx39h_flush_icache_all(void)
{
unsigned long flags, config;
local_irq_save(flags);
config = read_c0_conf();
write_c0_conf(config & ~TX39_CONF_ICE);
TX39_STOP_STREAMING();
blast_icache16();
write_c0_conf(config);
local_irq_restore(flags);
}
static void tx39h_dma_cache_wback_inv(unsigned long addr, unsigned long size)
{
BUG_ON(size == 0);
iob();
blast_inv_dcache_range(addr, addr + size);
}
static inline void tx39_blast_dcache_page(unsigned long addr)
{
if (current_cpu_type() != CPU_TX3912)
blast_dcache16_page(addr);
}
static inline void tx39_blast_dcache_page_indexed(unsigned long addr)
{
blast_dcache16_page_indexed(addr);
}
static inline void tx39_blast_dcache(void)
{
blast_dcache16();
}
static inline void tx39_blast_icache_page(unsigned long addr)
{
unsigned long flags, config;
local_irq_save(flags);
config = read_c0_conf();
write_c0_conf(config & ~TX39_CONF_ICE);
TX39_STOP_STREAMING();
blast_icache16_page(addr);
write_c0_conf(config);
local_irq_restore(flags);
}
static inline void tx39_blast_icache_page_indexed(unsigned long addr)
{
unsigned long flags, config;
local_irq_save(flags);
config = read_c0_conf();
write_c0_conf(config & ~TX39_CONF_ICE);
TX39_STOP_STREAMING();
blast_icache16_page_indexed(addr);
write_c0_conf(config);
local_irq_restore(flags);
}
static inline void tx39_blast_icache(void)
{
unsigned long flags, config;
local_irq_save(flags);
config = read_c0_conf();
write_c0_conf(config & ~TX39_CONF_ICE);
TX39_STOP_STREAMING();
blast_icache16();
write_c0_conf(config);
local_irq_restore(flags);
}
static void tx39__flush_cache_vmap(void)
{
tx39_blast_dcache();
}
static void tx39__flush_cache_vunmap(void)
{
tx39_blast_dcache();
}
static inline void tx39_flush_cache_all(void)
{
if (!cpu_has_dc_aliases)
return;
tx39_blast_dcache();
}
static inline void tx39___flush_cache_all(void)
{
tx39_blast_dcache();
tx39_blast_icache();
}
static void tx39_flush_cache_mm(struct mm_struct *mm)
{
if (!cpu_has_dc_aliases)
return;
if (cpu_context(smp_processor_id(), mm) != 0)
tx39_blast_dcache();
}
static void tx39_flush_cache_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
if (!cpu_has_dc_aliases)
return;
if (!(cpu_context(smp_processor_id(), vma->vm_mm)))
return;
tx39_blast_dcache();
}
static void tx39_flush_cache_page(struct vm_area_struct *vma, unsigned long page, unsigned long pfn)
{
int exec = vma->vm_flags & VM_EXEC;
struct mm_struct *mm = vma->vm_mm;
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
if (cpu_context(smp_processor_id(), mm) == 0)
return;
page &= PAGE_MASK;
pgdp = pgd_offset(mm, page);
pudp = pud_offset(pgdp, page);
pmdp = pmd_offset(pudp, page);
ptep = pte_offset(pmdp, page);
if (!(pte_val(*ptep) & _PAGE_PRESENT))
return;
if ((mm == current->active_mm) && (pte_val(*ptep) & _PAGE_VALID)) {
if (cpu_has_dc_aliases || exec)
tx39_blast_dcache_page(page);
if (exec)
tx39_blast_icache_page(page);
return;
}
if (cpu_has_dc_aliases || exec)
tx39_blast_dcache_page_indexed(page);
if (exec)
tx39_blast_icache_page_indexed(page);
}
static void local_tx39_flush_data_cache_page(void * addr)
{
tx39_blast_dcache_page((unsigned long)addr);
}
static void tx39_flush_data_cache_page(unsigned long addr)
{
tx39_blast_dcache_page(addr);
}
static void tx39_flush_icache_range(unsigned long start, unsigned long end)
{
if (end - start > dcache_size)
tx39_blast_dcache();
else
protected_blast_dcache_range(start, end);
if (end - start > icache_size)
tx39_blast_icache();
else {
unsigned long flags, config;
local_irq_save(flags);
config = read_c0_conf();
write_c0_conf(config & ~TX39_CONF_ICE);
TX39_STOP_STREAMING();
protected_blast_icache_range(start, end);
write_c0_conf(config);
local_irq_restore(flags);
}
}
static void tx39_flush_kernel_vmap_range(unsigned long vaddr, int size)
{
BUG();
}
static void tx39_dma_cache_wback_inv(unsigned long addr, unsigned long size)
{
unsigned long end;
if (((size | addr) & (PAGE_SIZE - 1)) == 0) {
end = addr + size;
do {
tx39_blast_dcache_page(addr);
addr += PAGE_SIZE;
} while(addr != end);
} else if (size > dcache_size) {
tx39_blast_dcache();
} else {
blast_dcache_range(addr, addr + size);
}
}
static void tx39_dma_cache_inv(unsigned long addr, unsigned long size)
{
unsigned long end;
if (((size | addr) & (PAGE_SIZE - 1)) == 0) {
end = addr + size;
do {
tx39_blast_dcache_page(addr);
addr += PAGE_SIZE;
} while(addr != end);
} else if (size > dcache_size) {
tx39_blast_dcache();
} else {
blast_inv_dcache_range(addr, addr + size);
}
}
static void tx39_flush_cache_sigtramp(unsigned long addr)
{
unsigned long ic_lsize = current_cpu_data.icache.linesz;
unsigned long dc_lsize = current_cpu_data.dcache.linesz;
unsigned long config;
unsigned long flags;
protected_writeback_dcache_line(addr & ~(dc_lsize - 1));
local_irq_save(flags);
config = read_c0_conf();
write_c0_conf(config & ~TX39_CONF_ICE);
TX39_STOP_STREAMING();
protected_flush_icache_line(addr & ~(ic_lsize - 1));
write_c0_conf(config);
local_irq_restore(flags);
}
static __init void tx39_probe_cache(void)
{
unsigned long config;
config = read_c0_conf();
icache_size = 1 << (10 + ((config & TX39_CONF_ICS_MASK) >>
TX39_CONF_ICS_SHIFT));
dcache_size = 1 << (10 + ((config & TX39_CONF_DCS_MASK) >>
TX39_CONF_DCS_SHIFT));
current_cpu_data.icache.linesz = 16;
switch (current_cpu_type()) {
case CPU_TX3912:
current_cpu_data.icache.ways = 1;
current_cpu_data.dcache.ways = 1;
current_cpu_data.dcache.linesz = 4;
break;
case CPU_TX3927:
current_cpu_data.icache.ways = 2;
current_cpu_data.dcache.ways = 2;
current_cpu_data.dcache.linesz = 16;
break;
case CPU_TX3922:
default:
current_cpu_data.icache.ways = 1;
current_cpu_data.dcache.ways = 1;
current_cpu_data.dcache.linesz = 16;
break;
}
}
void tx39_cache_init(void)
{
extern void build_clear_page(void);
extern void build_copy_page(void);
unsigned long config;
config = read_c0_conf();
config &= ~TX39_CONF_WBON;
write_c0_conf(config);
tx39_probe_cache();
switch (current_cpu_type()) {
case CPU_TX3912:
__flush_cache_vmap = tx39__flush_cache_vmap;
__flush_cache_vunmap = tx39__flush_cache_vunmap;
flush_cache_all = tx39h_flush_icache_all;
__flush_cache_all = tx39h_flush_icache_all;
flush_cache_mm = (void *) tx39h_flush_icache_all;
flush_cache_range = (void *) tx39h_flush_icache_all;
flush_cache_page = (void *) tx39h_flush_icache_all;
flush_icache_range = (void *) tx39h_flush_icache_all;
local_flush_icache_range = (void *) tx39h_flush_icache_all;
flush_cache_sigtramp = (void *) tx39h_flush_icache_all;
local_flush_data_cache_page = (void *) tx39h_flush_icache_all;
flush_data_cache_page = (void *) tx39h_flush_icache_all;
_dma_cache_wback_inv = tx39h_dma_cache_wback_inv;
shm_align_mask = PAGE_SIZE - 1;
break;
case CPU_TX3922:
case CPU_TX3927:
default:
__flush_cache_vmap = tx39__flush_cache_vmap;
__flush_cache_vunmap = tx39__flush_cache_vunmap;
flush_cache_all = tx39_flush_cache_all;
__flush_cache_all = tx39___flush_cache_all;
flush_cache_mm = tx39_flush_cache_mm;
flush_cache_range = tx39_flush_cache_range;
flush_cache_page = tx39_flush_cache_page;
flush_icache_range = tx39_flush_icache_range;
local_flush_icache_range = tx39_flush_icache_range;
__flush_kernel_vmap_range = tx39_flush_kernel_vmap_range;
flush_cache_sigtramp = tx39_flush_cache_sigtramp;
local_flush_data_cache_page = local_tx39_flush_data_cache_page;
flush_data_cache_page = tx39_flush_data_cache_page;
_dma_cache_wback_inv = tx39_dma_cache_wback_inv;
_dma_cache_wback = tx39_dma_cache_wback_inv;
_dma_cache_inv = tx39_dma_cache_inv;
shm_align_mask = max_t(unsigned long,
(dcache_size / current_cpu_data.dcache.ways) - 1,
PAGE_SIZE - 1);
break;
}
__flush_icache_user_range = flush_icache_range;
__local_flush_icache_user_range = local_flush_icache_range;
current_cpu_data.icache.waysize = icache_size / current_cpu_data.icache.ways;
current_cpu_data.dcache.waysize = dcache_size / current_cpu_data.dcache.ways;
current_cpu_data.icache.sets =
current_cpu_data.icache.waysize / current_cpu_data.icache.linesz;
current_cpu_data.dcache.sets =
current_cpu_data.dcache.waysize / current_cpu_data.dcache.linesz;
if (current_cpu_data.dcache.waysize > PAGE_SIZE)
current_cpu_data.dcache.flags |= MIPS_CACHE_ALIASES;
current_cpu_data.icache.waybit = 0;
current_cpu_data.dcache.waybit = 0;
printk("Primary instruction cache %ldkB, linesize %d bytes\n",
icache_size >> 10, current_cpu_data.icache.linesz);
printk("Primary data cache %ldkB, linesize %d bytes\n",
dcache_size >> 10, current_cpu_data.dcache.linesz);
build_clear_page();
build_copy_page();
tx39h_flush_icache_all();
}
