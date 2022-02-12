static inline void r4k_on_each_cpu(void (*func) (void *info), void *info)
{
preempt_disable();
#if !defined(CONFIG_MIPS_MT_SMP) && !defined(CONFIG_MIPS_MT_SMTC)
smp_call_function(func, info, 1);
#endif
func(info);
preempt_enable();
}
static void cache_noop(void) {}
static inline void r4k_blast_dcache_page_dc32(unsigned long addr)
{
R4600_HIT_CACHEOP_WAR_IMPL;
blast_dcache32_page(addr);
}
static inline void r4k_blast_dcache_page_dc64(unsigned long addr)
{
R4600_HIT_CACHEOP_WAR_IMPL;
blast_dcache64_page(addr);
}
static void r4k_blast_dcache_page_setup(void)
{
unsigned long dc_lsize = cpu_dcache_line_size();
if (dc_lsize == 0)
r4k_blast_dcache_page = (void *)cache_noop;
else if (dc_lsize == 16)
r4k_blast_dcache_page = blast_dcache16_page;
else if (dc_lsize == 32)
r4k_blast_dcache_page = r4k_blast_dcache_page_dc32;
else if (dc_lsize == 64)
r4k_blast_dcache_page = r4k_blast_dcache_page_dc64;
}
static void r4k_blast_dcache_page_indexed_setup(void)
{
unsigned long dc_lsize = cpu_dcache_line_size();
if (dc_lsize == 0)
r4k_blast_dcache_page_indexed = (void *)cache_noop;
else if (dc_lsize == 16)
r4k_blast_dcache_page_indexed = blast_dcache16_page_indexed;
else if (dc_lsize == 32)
r4k_blast_dcache_page_indexed = blast_dcache32_page_indexed;
else if (dc_lsize == 64)
r4k_blast_dcache_page_indexed = blast_dcache64_page_indexed;
}
static void r4k_blast_dcache_setup(void)
{
unsigned long dc_lsize = cpu_dcache_line_size();
if (dc_lsize == 0)
r4k_blast_dcache = (void *)cache_noop;
else if (dc_lsize == 16)
r4k_blast_dcache = blast_dcache16;
else if (dc_lsize == 32)
r4k_blast_dcache = blast_dcache32;
else if (dc_lsize == 64)
r4k_blast_dcache = blast_dcache64;
}
static inline void blast_r4600_v1_icache32(void)
{
unsigned long flags;
local_irq_save(flags);
blast_icache32();
local_irq_restore(flags);
}
static inline void tx49_blast_icache32(void)
{
unsigned long start = INDEX_BASE;
unsigned long end = start + current_cpu_data.icache.waysize;
unsigned long ws_inc = 1UL << current_cpu_data.icache.waybit;
unsigned long ws_end = current_cpu_data.icache.ways <<
current_cpu_data.icache.waybit;
unsigned long ws, addr;
CACHE32_UNROLL32_ALIGN2;
for (ws = 0; ws < ws_end; ws += ws_inc)
for (addr = start + 0x400; addr < end; addr += 0x400 * 2)
cache32_unroll32(addr|ws, Index_Invalidate_I);
CACHE32_UNROLL32_ALIGN;
for (ws = 0; ws < ws_end; ws += ws_inc)
for (addr = start; addr < end; addr += 0x400 * 2)
cache32_unroll32(addr|ws, Index_Invalidate_I);
}
static inline void blast_icache32_r4600_v1_page_indexed(unsigned long page)
{
unsigned long flags;
local_irq_save(flags);
blast_icache32_page_indexed(page);
local_irq_restore(flags);
}
static inline void tx49_blast_icache32_page_indexed(unsigned long page)
{
unsigned long indexmask = current_cpu_data.icache.waysize - 1;
unsigned long start = INDEX_BASE + (page & indexmask);
unsigned long end = start + PAGE_SIZE;
unsigned long ws_inc = 1UL << current_cpu_data.icache.waybit;
unsigned long ws_end = current_cpu_data.icache.ways <<
current_cpu_data.icache.waybit;
unsigned long ws, addr;
CACHE32_UNROLL32_ALIGN2;
for (ws = 0; ws < ws_end; ws += ws_inc)
for (addr = start + 0x400; addr < end; addr += 0x400 * 2)
cache32_unroll32(addr|ws, Index_Invalidate_I);
CACHE32_UNROLL32_ALIGN;
for (ws = 0; ws < ws_end; ws += ws_inc)
for (addr = start; addr < end; addr += 0x400 * 2)
cache32_unroll32(addr|ws, Index_Invalidate_I);
}
static void r4k_blast_icache_page_setup(void)
{
unsigned long ic_lsize = cpu_icache_line_size();
if (ic_lsize == 0)
r4k_blast_icache_page = (void *)cache_noop;
else if (ic_lsize == 16)
r4k_blast_icache_page = blast_icache16_page;
else if (ic_lsize == 32 && current_cpu_type() == CPU_LOONGSON2)
r4k_blast_icache_page = loongson2_blast_icache32_page;
else if (ic_lsize == 32)
r4k_blast_icache_page = blast_icache32_page;
else if (ic_lsize == 64)
r4k_blast_icache_page = blast_icache64_page;
}
static void r4k_blast_icache_page_indexed_setup(void)
{
unsigned long ic_lsize = cpu_icache_line_size();
if (ic_lsize == 0)
r4k_blast_icache_page_indexed = (void *)cache_noop;
else if (ic_lsize == 16)
r4k_blast_icache_page_indexed = blast_icache16_page_indexed;
else if (ic_lsize == 32) {
if (R4600_V1_INDEX_ICACHEOP_WAR && cpu_is_r4600_v1_x())
r4k_blast_icache_page_indexed =
blast_icache32_r4600_v1_page_indexed;
else if (TX49XX_ICACHE_INDEX_INV_WAR)
r4k_blast_icache_page_indexed =
tx49_blast_icache32_page_indexed;
else if (current_cpu_type() == CPU_LOONGSON2)
r4k_blast_icache_page_indexed =
loongson2_blast_icache32_page_indexed;
else
r4k_blast_icache_page_indexed =
blast_icache32_page_indexed;
} else if (ic_lsize == 64)
r4k_blast_icache_page_indexed = blast_icache64_page_indexed;
}
static void r4k_blast_icache_setup(void)
{
unsigned long ic_lsize = cpu_icache_line_size();
if (ic_lsize == 0)
r4k_blast_icache = (void *)cache_noop;
else if (ic_lsize == 16)
r4k_blast_icache = blast_icache16;
else if (ic_lsize == 32) {
if (R4600_V1_INDEX_ICACHEOP_WAR && cpu_is_r4600_v1_x())
r4k_blast_icache = blast_r4600_v1_icache32;
else if (TX49XX_ICACHE_INDEX_INV_WAR)
r4k_blast_icache = tx49_blast_icache32;
else if (current_cpu_type() == CPU_LOONGSON2)
r4k_blast_icache = loongson2_blast_icache32;
else
r4k_blast_icache = blast_icache32;
} else if (ic_lsize == 64)
r4k_blast_icache = blast_icache64;
}
static void r4k_blast_scache_page_setup(void)
{
unsigned long sc_lsize = cpu_scache_line_size();
if (scache_size == 0)
r4k_blast_scache_page = (void *)cache_noop;
else if (sc_lsize == 16)
r4k_blast_scache_page = blast_scache16_page;
else if (sc_lsize == 32)
r4k_blast_scache_page = blast_scache32_page;
else if (sc_lsize == 64)
r4k_blast_scache_page = blast_scache64_page;
else if (sc_lsize == 128)
r4k_blast_scache_page = blast_scache128_page;
}
static void r4k_blast_scache_page_indexed_setup(void)
{
unsigned long sc_lsize = cpu_scache_line_size();
if (scache_size == 0)
r4k_blast_scache_page_indexed = (void *)cache_noop;
else if (sc_lsize == 16)
r4k_blast_scache_page_indexed = blast_scache16_page_indexed;
else if (sc_lsize == 32)
r4k_blast_scache_page_indexed = blast_scache32_page_indexed;
else if (sc_lsize == 64)
r4k_blast_scache_page_indexed = blast_scache64_page_indexed;
else if (sc_lsize == 128)
r4k_blast_scache_page_indexed = blast_scache128_page_indexed;
}
static void r4k_blast_scache_setup(void)
{
unsigned long sc_lsize = cpu_scache_line_size();
if (scache_size == 0)
r4k_blast_scache = (void *)cache_noop;
else if (sc_lsize == 16)
r4k_blast_scache = blast_scache16;
else if (sc_lsize == 32)
r4k_blast_scache = blast_scache32;
else if (sc_lsize == 64)
r4k_blast_scache = blast_scache64;
else if (sc_lsize == 128)
r4k_blast_scache = blast_scache128;
}
static inline void local_r4k___flush_cache_all(void * args)
{
switch (current_cpu_type()) {
case CPU_LOONGSON2:
case CPU_R4000SC:
case CPU_R4000MC:
case CPU_R4400SC:
case CPU_R4400MC:
case CPU_R10000:
case CPU_R12000:
case CPU_R14000:
r4k_blast_scache();
break;
default:
r4k_blast_dcache();
r4k_blast_icache();
break;
}
}
static void r4k___flush_cache_all(void)
{
r4k_on_each_cpu(local_r4k___flush_cache_all, NULL);
}
static inline int has_valid_asid(const struct mm_struct *mm)
{
#if defined(CONFIG_MIPS_MT_SMP) || defined(CONFIG_MIPS_MT_SMTC)
int i;
for_each_online_cpu(i)
if (cpu_context(i, mm))
return 1;
return 0;
#else
return cpu_context(smp_processor_id(), mm);
#endif
}
static void r4k__flush_cache_vmap(void)
{
r4k_blast_dcache();
}
static void r4k__flush_cache_vunmap(void)
{
r4k_blast_dcache();
}
static inline void local_r4k_flush_cache_range(void * args)
{
struct vm_area_struct *vma = args;
int exec = vma->vm_flags & VM_EXEC;
if (!(has_valid_asid(vma->vm_mm)))
return;
r4k_blast_dcache();
if (exec)
r4k_blast_icache();
}
static void r4k_flush_cache_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
int exec = vma->vm_flags & VM_EXEC;
if (cpu_has_dc_aliases || (exec && !cpu_has_ic_fills_f_dc))
r4k_on_each_cpu(local_r4k_flush_cache_range, vma);
}
static inline void local_r4k_flush_cache_mm(void * args)
{
struct mm_struct *mm = args;
if (!has_valid_asid(mm))
return;
if (current_cpu_type() == CPU_R4000SC ||
current_cpu_type() == CPU_R4000MC ||
current_cpu_type() == CPU_R4400SC ||
current_cpu_type() == CPU_R4400MC) {
r4k_blast_scache();
return;
}
r4k_blast_dcache();
}
static void r4k_flush_cache_mm(struct mm_struct *mm)
{
if (!cpu_has_dc_aliases)
return;
r4k_on_each_cpu(local_r4k_flush_cache_mm, mm);
}
static inline void local_r4k_flush_cache_page(void *args)
{
struct flush_cache_page_args *fcp_args = args;
struct vm_area_struct *vma = fcp_args->vma;
unsigned long addr = fcp_args->addr;
struct page *page = pfn_to_page(fcp_args->pfn);
int exec = vma->vm_flags & VM_EXEC;
struct mm_struct *mm = vma->vm_mm;
int map_coherent = 0;
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
void *vaddr;
if (!has_valid_asid(mm))
return;
addr &= PAGE_MASK;
pgdp = pgd_offset(mm, addr);
pudp = pud_offset(pgdp, addr);
pmdp = pmd_offset(pudp, addr);
ptep = pte_offset(pmdp, addr);
if (!(pte_present(*ptep)))
return;
if ((mm == current->active_mm) && (pte_val(*ptep) & _PAGE_VALID))
vaddr = NULL;
else {
map_coherent = (cpu_has_dc_aliases &&
page_mapped(page) && !Page_dcache_dirty(page));
if (map_coherent)
vaddr = kmap_coherent(page, addr);
else
vaddr = kmap_atomic(page);
addr = (unsigned long)vaddr;
}
if (cpu_has_dc_aliases || (exec && !cpu_has_ic_fills_f_dc)) {
r4k_blast_dcache_page(addr);
if (exec && !cpu_icache_snoops_remote_store)
r4k_blast_scache_page(addr);
}
if (exec) {
if (vaddr && cpu_has_vtag_icache && mm == current->active_mm) {
int cpu = smp_processor_id();
if (cpu_context(cpu, mm) != 0)
drop_mmu_context(mm, cpu);
} else
r4k_blast_icache_page(addr);
}
if (vaddr) {
if (map_coherent)
kunmap_coherent();
else
kunmap_atomic(vaddr);
}
}
static void r4k_flush_cache_page(struct vm_area_struct *vma,
unsigned long addr, unsigned long pfn)
{
struct flush_cache_page_args args;
args.vma = vma;
args.addr = addr;
args.pfn = pfn;
r4k_on_each_cpu(local_r4k_flush_cache_page, &args);
}
static inline void local_r4k_flush_data_cache_page(void * addr)
{
r4k_blast_dcache_page((unsigned long) addr);
}
static void r4k_flush_data_cache_page(unsigned long addr)
{
if (in_atomic())
local_r4k_flush_data_cache_page((void *)addr);
else
r4k_on_each_cpu(local_r4k_flush_data_cache_page, (void *) addr);
}
static inline void local_r4k_flush_icache_range(unsigned long start, unsigned long end)
{
if (!cpu_has_ic_fills_f_dc) {
if (end - start >= dcache_size) {
r4k_blast_dcache();
} else {
R4600_HIT_CACHEOP_WAR_IMPL;
protected_blast_dcache_range(start, end);
}
}
if (end - start > icache_size)
r4k_blast_icache();
else {
switch (boot_cpu_type()) {
case CPU_LOONGSON2:
protected_loongson2_blast_icache_range(start, end);
break;
default:
protected_blast_icache_range(start, end);
break;
}
}
}
static inline void local_r4k_flush_icache_range_ipi(void *args)
{
struct flush_icache_range_args *fir_args = args;
unsigned long start = fir_args->start;
unsigned long end = fir_args->end;
local_r4k_flush_icache_range(start, end);
}
static void r4k_flush_icache_range(unsigned long start, unsigned long end)
{
struct flush_icache_range_args args;
args.start = start;
args.end = end;
r4k_on_each_cpu(local_r4k_flush_icache_range_ipi, &args);
instruction_hazard();
}
static void r4k_dma_cache_wback_inv(unsigned long addr, unsigned long size)
{
BUG_ON(size == 0);
preempt_disable();
if (cpu_has_inclusive_pcaches) {
if (size >= scache_size)
r4k_blast_scache();
else
blast_scache_range(addr, addr + size);
preempt_enable();
__sync();
return;
}
if (cpu_has_safe_index_cacheops && size >= dcache_size) {
r4k_blast_dcache();
} else {
R4600_HIT_CACHEOP_WAR_IMPL;
blast_dcache_range(addr, addr + size);
}
preempt_enable();
bc_wback_inv(addr, size);
__sync();
}
static void r4k_dma_cache_inv(unsigned long addr, unsigned long size)
{
BUG_ON(size == 0);
preempt_disable();
if (cpu_has_inclusive_pcaches) {
if (size >= scache_size)
r4k_blast_scache();
else {
blast_inv_scache_range(addr, addr + size);
}
preempt_enable();
__sync();
return;
}
if (cpu_has_safe_index_cacheops && size >= dcache_size) {
r4k_blast_dcache();
} else {
R4600_HIT_CACHEOP_WAR_IMPL;
blast_inv_dcache_range(addr, addr + size);
}
preempt_enable();
bc_inv(addr, size);
__sync();
}
static void local_r4k_flush_cache_sigtramp(void * arg)
{
unsigned long ic_lsize = cpu_icache_line_size();
unsigned long dc_lsize = cpu_dcache_line_size();
unsigned long sc_lsize = cpu_scache_line_size();
unsigned long addr = (unsigned long) arg;
R4600_HIT_CACHEOP_WAR_IMPL;
if (dc_lsize)
protected_writeback_dcache_line(addr & ~(dc_lsize - 1));
if (!cpu_icache_snoops_remote_store && scache_size)
protected_writeback_scache_line(addr & ~(sc_lsize - 1));
if (ic_lsize)
protected_flush_icache_line(addr & ~(ic_lsize - 1));
if (MIPS4K_ICACHE_REFILL_WAR) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set mips3\n\t"
#ifdef CONFIG_32BIT
"la $at,1f\n\t"
#endif
#ifdef CONFIG_64BIT
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if (MIPS_CACHE_SYNC_WAR)
__asm__ __volatile__ ("sync");
}
static void r4k_flush_cache_sigtramp(unsigned long addr)
{
r4k_on_each_cpu(local_r4k_flush_cache_sigtramp, (void *) addr);
}
static void r4k_flush_icache_all(void)
{
if (cpu_has_vtag_icache)
r4k_blast_icache();
}
static inline void local_r4k_flush_kernel_vmap_range(void *args)
{
struct flush_kernel_vmap_range_args *vmra = args;
unsigned long vaddr = vmra->vaddr;
int size = vmra->size;
if (cpu_has_safe_index_cacheops && size >= dcache_size)
r4k_blast_dcache();
else {
R4600_HIT_CACHEOP_WAR_IMPL;
blast_dcache_range(vaddr, vaddr + size);
}
}
static void r4k_flush_kernel_vmap_range(unsigned long vaddr, int size)
{
struct flush_kernel_vmap_range_args args;
args.vaddr = (unsigned long) vaddr;
args.size = size;
r4k_on_each_cpu(local_r4k_flush_kernel_vmap_range, &args);
}
static inline void rm7k_erratum31(void)
{
const unsigned long ic_lsize = 32;
unsigned long addr;
write_c0_taglo(0);
write_c0_taghi(0);
for (addr = INDEX_BASE; addr <= INDEX_BASE + 4096; addr += ic_lsize) {
__asm__ __volatile__ (
".set push\n\t"
".set noreorder\n\t"
".set mips3\n\t"
"cache\t%1, 0(%0)\n\t"
"cache\t%1, 0x1000(%0)\n\t"
"cache\t%1, 0x2000(%0)\n\t"
"cache\t%1, 0x3000(%0)\n\t"
"cache\t%2, 0(%0)\n\t"
"cache\t%2, 0x1000(%0)\n\t"
"cache\t%2, 0x2000(%0)\n\t"
"cache\t%2, 0x3000(%0)\n\t"
"cache\t%1, 0(%0)\n\t"
"cache\t%1, 0x1000(%0)\n\t"
"cache\t%1, 0x2000(%0)\n\t"
"cache\t%1, 0x3000(%0)\n\t"
".set pop\n"
:
: "r" (addr), "i" (Index_Store_Tag_I), "i" (Fill));
}
}
static inline void alias_74k_erratum(struct cpuinfo_mips *c)
{
unsigned int imp = c->processor_id & PRID_IMP_MASK;
unsigned int rev = c->processor_id & PRID_REV_MASK;
switch (imp) {
case PRID_IMP_74K:
if (rev <= PRID_REV_ENCODE_332(2, 4, 0))
c->dcache.flags |= MIPS_CACHE_VTAG;
if (rev == PRID_REV_ENCODE_332(2, 4, 0))
write_c0_config6(read_c0_config6() | MIPS_CONF6_SYND);
break;
case PRID_IMP_1074K:
if (rev <= PRID_REV_ENCODE_332(1, 1, 0)) {
c->dcache.flags |= MIPS_CACHE_VTAG;
write_c0_config6(read_c0_config6() | MIPS_CONF6_SYND);
}
break;
default:
BUG();
}
}
static void probe_pcache(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
unsigned int config = read_c0_config();
unsigned int prid = read_c0_prid();
unsigned long config1;
unsigned int lsize;
switch (current_cpu_type()) {
case CPU_R4600:
case CPU_R4700:
case CPU_R5000:
case CPU_NEVADA:
icache_size = 1 << (12 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 2;
c->icache.waybit = __ffs(icache_size/2);
dcache_size = 1 << (12 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 2;
c->dcache.waybit= __ffs(dcache_size/2);
c->options |= MIPS_CPU_CACHE_CDEX_P;
break;
case CPU_R5432:
case CPU_R5500:
icache_size = 1 << (12 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 2;
c->icache.waybit= 0;
dcache_size = 1 << (12 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 2;
c->dcache.waybit = 0;
c->options |= MIPS_CPU_CACHE_CDEX_P | MIPS_CPU_PREFETCH;
break;
case CPU_TX49XX:
icache_size = 1 << (12 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 4;
c->icache.waybit= 0;
dcache_size = 1 << (12 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 4;
c->dcache.waybit = 0;
c->options |= MIPS_CPU_CACHE_CDEX_P;
c->options |= MIPS_CPU_PREFETCH;
break;
case CPU_R4000PC:
case CPU_R4000SC:
case CPU_R4000MC:
case CPU_R4400PC:
case CPU_R4400SC:
case CPU_R4400MC:
case CPU_R4300:
icache_size = 1 << (12 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 1;
c->icache.waybit = 0;
dcache_size = 1 << (12 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 1;
c->dcache.waybit = 0;
c->options |= MIPS_CPU_CACHE_CDEX_P;
break;
case CPU_R10000:
case CPU_R12000:
case CPU_R14000:
icache_size = 1 << (12 + ((config & R10K_CONF_IC) >> 29));
c->icache.linesz = 64;
c->icache.ways = 2;
c->icache.waybit = 0;
dcache_size = 1 << (12 + ((config & R10K_CONF_DC) >> 26));
c->dcache.linesz = 32;
c->dcache.ways = 2;
c->dcache.waybit = 0;
c->options |= MIPS_CPU_PREFETCH;
break;
case CPU_VR4133:
write_c0_config(config & ~VR41_CONF_P4K);
case CPU_VR4131:
if (c->processor_id == 0x0c80U || c->processor_id == 0x0c81U ||
c->processor_id == 0x0c82U) {
config |= 0x00400000U;
if (c->processor_id == 0x0c80U)
config |= VR41_CONF_BP;
write_c0_config(config);
} else
c->options |= MIPS_CPU_CACHE_CDEX_P;
icache_size = 1 << (10 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 2;
c->icache.waybit = __ffs(icache_size/2);
dcache_size = 1 << (10 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 2;
c->dcache.waybit = __ffs(dcache_size/2);
break;
case CPU_VR41XX:
case CPU_VR4111:
case CPU_VR4121:
case CPU_VR4122:
case CPU_VR4181:
case CPU_VR4181A:
icache_size = 1 << (10 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 1;
c->icache.waybit = 0;
dcache_size = 1 << (10 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 1;
c->dcache.waybit = 0;
c->options |= MIPS_CPU_CACHE_CDEX_P;
break;
case CPU_RM7000:
rm7k_erratum31();
icache_size = 1 << (12 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
c->icache.ways = 4;
c->icache.waybit = __ffs(icache_size / c->icache.ways);
dcache_size = 1 << (12 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
c->dcache.ways = 4;
c->dcache.waybit = __ffs(dcache_size / c->dcache.ways);
c->options |= MIPS_CPU_CACHE_CDEX_P;
c->options |= MIPS_CPU_PREFETCH;
break;
case CPU_LOONGSON2:
icache_size = 1 << (12 + ((config & CONF_IC) >> 9));
c->icache.linesz = 16 << ((config & CONF_IB) >> 5);
if (prid & 0x3)
c->icache.ways = 4;
else
c->icache.ways = 2;
c->icache.waybit = 0;
dcache_size = 1 << (12 + ((config & CONF_DC) >> 6));
c->dcache.linesz = 16 << ((config & CONF_DB) >> 4);
if (prid & 0x3)
c->dcache.ways = 4;
else
c->dcache.ways = 2;
c->dcache.waybit = 0;
break;
default:
if (!(config & MIPS_CONF_M))
panic("Don't know how to probe P-caches on this cpu.");
config1 = read_c0_config1();
lsize = (config1 >> 19) & 7;
if (lsize == 7)
panic("Invalid icache line size");
c->icache.linesz = lsize ? 2 << lsize : 0;
c->icache.sets = 32 << (((config1 >> 22) + 1) & 7);
c->icache.ways = 1 + ((config1 >> 16) & 7);
icache_size = c->icache.sets *
c->icache.ways *
c->icache.linesz;
c->icache.waybit = __ffs(icache_size/c->icache.ways);
if (config & 0x8)
c->icache.flags |= MIPS_CACHE_VTAG;
c->dcache.flags = 0;
lsize = (config1 >> 10) & 7;
if (lsize == 7)
panic("Invalid dcache line size");
c->dcache.linesz = lsize ? 2 << lsize : 0;
c->dcache.sets = 32 << (((config1 >> 13) + 1) & 7);
c->dcache.ways = 1 + ((config1 >> 7) & 7);
dcache_size = c->dcache.sets *
c->dcache.ways *
c->dcache.linesz;
c->dcache.waybit = __ffs(dcache_size/c->dcache.ways);
c->options |= MIPS_CPU_PREFETCH;
break;
}
if ((prid & PRID_IMP_MASK) == PRID_IMP_R4000 &&
(prid & PRID_REV_MASK) < PRID_REV_R4400 &&
!(config & CONF_SC) && c->icache.linesz != 16 &&
PAGE_SIZE <= 0x8000)
panic("Improper R4000SC processor configuration detected");
c->icache.waysize = icache_size / c->icache.ways;
c->dcache.waysize = dcache_size / c->dcache.ways;
c->icache.sets = c->icache.linesz ?
icache_size / (c->icache.linesz * c->icache.ways) : 0;
c->dcache.sets = c->dcache.linesz ?
dcache_size / (c->dcache.linesz * c->dcache.ways) : 0;
switch (current_cpu_type()) {
case CPU_20KC:
case CPU_25KF:
case CPU_SB1:
case CPU_SB1A:
case CPU_XLR:
c->dcache.flags |= MIPS_CACHE_PINDEX;
break;
case CPU_R10000:
case CPU_R12000:
case CPU_R14000:
break;
case CPU_M14KC:
case CPU_M14KEC:
case CPU_24K:
case CPU_34K:
case CPU_74K:
case CPU_1004K:
case CPU_INTERAPTIV:
case CPU_PROAPTIV:
if (current_cpu_type() == CPU_74K)
alias_74k_erratum(c);
if ((read_c0_config7() & (1 << 16))) {
c->dcache.flags |= MIPS_CACHE_PINDEX;
break;
}
default:
if (c->dcache.waysize > PAGE_SIZE)
c->dcache.flags |= MIPS_CACHE_ALIASES;
}
switch (current_cpu_type()) {
case CPU_20KC:
c->icache.flags |= MIPS_CACHE_VTAG;
break;
case CPU_ALCHEMY:
c->icache.flags |= MIPS_CACHE_IC_F_DC;
break;
case CPU_LOONGSON2:
c->icache.ways = 1;
}
printk("Primary instruction cache %ldkB, %s, %s, linesize %d bytes.\n",
icache_size >> 10,
c->icache.flags & MIPS_CACHE_VTAG ? "VIVT" : "VIPT",
way_string[c->icache.ways], c->icache.linesz);
printk("Primary data cache %ldkB, %s, %s, %s, linesize %d bytes\n",
dcache_size >> 10, way_string[c->dcache.ways],
(c->dcache.flags & MIPS_CACHE_PINDEX) ? "PIPT" : "VIPT",
(c->dcache.flags & MIPS_CACHE_ALIASES) ?
"cache aliases" : "no aliases",
c->dcache.linesz);
}
static int probe_scache(void)
{
unsigned long flags, addr, begin, end, pow2;
unsigned int config = read_c0_config();
struct cpuinfo_mips *c = &current_cpu_data;
if (config & CONF_SC)
return 0;
begin = (unsigned long) &_stext;
begin &= ~((4 * 1024 * 1024) - 1);
end = begin + (4 * 1024 * 1024);
local_irq_save(flags);
pow2 = (64 * 1024);
for (addr = begin; addr < end; addr = (begin + pow2)) {
unsigned long *p = (unsigned long *) addr;
__asm__ __volatile__("nop" : : "r" (*p));
pow2 <<= 1;
}
write_c0_taglo(0);
write_c0_taghi(0);
__asm__ __volatile__("nop; nop; nop; nop;");
cache_op(Index_Store_Tag_I, begin);
cache_op(Index_Store_Tag_D, begin);
cache_op(Index_Store_Tag_SD, begin);
pow2 = (128 * 1024);
for (addr = begin + (128 * 1024); addr < end; addr = begin + pow2) {
cache_op(Index_Load_Tag_SD, addr);
__asm__ __volatile__("nop; nop; nop; nop;");
if (!read_c0_taglo())
break;
pow2 <<= 1;
}
local_irq_restore(flags);
addr -= begin;
scache_size = addr;
c->scache.linesz = 16 << ((config & R4K_CONF_SB) >> 22);
c->scache.ways = 1;
c->dcache.waybit = 0;
return 1;
}
static void __init loongson2_sc_init(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
scache_size = 512*1024;
c->scache.linesz = 32;
c->scache.ways = 4;
c->scache.waybit = 0;
c->scache.waysize = scache_size / (c->scache.ways);
c->scache.sets = scache_size / (c->scache.linesz * c->scache.ways);
pr_info("Unified secondary cache %ldkB %s, linesize %d bytes.\n",
scache_size >> 10, way_string[c->scache.ways], c->scache.linesz);
c->options |= MIPS_CPU_INCLUSIVE_CACHES;
}
static void setup_scache(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
unsigned int config = read_c0_config();
int sc_present = 0;
switch (current_cpu_type()) {
case CPU_R4000SC:
case CPU_R4000MC:
case CPU_R4400SC:
case CPU_R4400MC:
sc_present = run_uncached(probe_scache);
if (sc_present)
c->options |= MIPS_CPU_CACHE_CDEX_S;
break;
case CPU_R10000:
case CPU_R12000:
case CPU_R14000:
scache_size = 0x80000 << ((config & R10K_CONF_SS) >> 16);
c->scache.linesz = 64 << ((config >> 13) & 1);
c->scache.ways = 2;
c->scache.waybit= 0;
sc_present = 1;
break;
case CPU_R5000:
case CPU_NEVADA:
#ifdef CONFIG_R5000_CPU_SCACHE
r5k_sc_init();
#endif
return;
case CPU_RM7000:
#ifdef CONFIG_RM7000_CPU_SCACHE
rm7k_sc_init();
#endif
return;
case CPU_LOONGSON2:
loongson2_sc_init();
return;
case CPU_XLP:
return;
default:
if (c->isa_level & (MIPS_CPU_ISA_M32R1 | MIPS_CPU_ISA_M32R2 |
MIPS_CPU_ISA_M64R1 | MIPS_CPU_ISA_M64R2)) {
#ifdef CONFIG_MIPS_CPU_SCACHE
if (mips_sc_init ()) {
scache_size = c->scache.ways * c->scache.sets * c->scache.linesz;
printk("MIPS secondary cache %ldkB, %s, linesize %d bytes.\n",
scache_size >> 10,
way_string[c->scache.ways], c->scache.linesz);
}
#else
if (!(c->scache.flags & MIPS_CACHE_NOT_PRESENT))
panic("Dunno how to handle MIPS32 / MIPS64 second level cache");
#endif
return;
}
sc_present = 0;
}
if (!sc_present)
return;
c->scache.waysize = scache_size / c->scache.ways;
c->scache.sets = scache_size / (c->scache.linesz * c->scache.ways);
printk("Unified secondary cache %ldkB %s, linesize %d bytes.\n",
scache_size >> 10, way_string[c->scache.ways], c->scache.linesz);
c->options |= MIPS_CPU_INCLUSIVE_CACHES;
}
void au1x00_fixup_config_od(void)
{
switch (read_c0_prid()) {
case 0x00030100:
case 0x00030201:
case 0x00030202:
case 0x01030200:
case 0x02030200:
case 0x02030201:
case 0x02030202:
set_c0_config(1 << 19);
break;
}
}
static void nxp_pr4450_fixup_config(void)
{
unsigned long config0;
config0 = read_c0_config();
config0 &= ~(0x7 | (7 << 25) | (7 << 28));
config0 |= (((_page_cachable_default >> _CACHE_SHIFT) << 0) |
((_page_cachable_default >> _CACHE_SHIFT) << 25) |
((_page_cachable_default >> _CACHE_SHIFT) << 28));
write_c0_config(config0);
NXP_BARRIER();
}
static int __init cca_setup(char *str)
{
get_option(&str, &cca);
return 0;
}
static void coherency_setup(void)
{
if (cca < 0 || cca > 7)
cca = read_c0_config() & CONF_CM_CMASK;
_page_cachable_default = cca << _CACHE_SHIFT;
pr_debug("Using cache attribute %d\n", cca);
change_c0_config(CONF_CM_CMASK, cca);
switch (current_cpu_type()) {
case CPU_R4000PC:
case CPU_R4000SC:
case CPU_R4000MC:
case CPU_R4400PC:
case CPU_R4400SC:
case CPU_R4400MC:
clear_c0_config(CONF_CU);
break;
case CPU_ALCHEMY:
au1x00_fixup_config_od();
break;
case PRID_IMP_PR4450:
nxp_pr4450_fixup_config();
break;
}
}
static void r4k_cache_error_setup(void)
{
extern char __weak except_vec2_generic;
extern char __weak except_vec2_sb1;
switch (current_cpu_type()) {
case CPU_SB1:
case CPU_SB1A:
set_uncached_handler(0x100, &except_vec2_sb1, 0x80);
break;
default:
set_uncached_handler(0x100, &except_vec2_generic, 0x80);
break;
}
}
void r4k_cache_init(void)
{
extern void build_clear_page(void);
extern void build_copy_page(void);
struct cpuinfo_mips *c = &current_cpu_data;
probe_pcache();
setup_scache();
r4k_blast_dcache_page_setup();
r4k_blast_dcache_page_indexed_setup();
r4k_blast_dcache_setup();
r4k_blast_icache_page_setup();
r4k_blast_icache_page_indexed_setup();
r4k_blast_icache_setup();
r4k_blast_scache_page_setup();
r4k_blast_scache_page_indexed_setup();
r4k_blast_scache_setup();
if (c->dcache.linesz)
shm_align_mask = max_t( unsigned long,
c->dcache.sets * c->dcache.linesz - 1,
PAGE_SIZE - 1);
else
shm_align_mask = PAGE_SIZE-1;
__flush_cache_vmap = r4k__flush_cache_vmap;
__flush_cache_vunmap = r4k__flush_cache_vunmap;
flush_cache_all = cache_noop;
__flush_cache_all = r4k___flush_cache_all;
flush_cache_mm = r4k_flush_cache_mm;
flush_cache_page = r4k_flush_cache_page;
flush_cache_range = r4k_flush_cache_range;
__flush_kernel_vmap_range = r4k_flush_kernel_vmap_range;
flush_cache_sigtramp = r4k_flush_cache_sigtramp;
flush_icache_all = r4k_flush_icache_all;
local_flush_data_cache_page = local_r4k_flush_data_cache_page;
flush_data_cache_page = r4k_flush_data_cache_page;
flush_icache_range = r4k_flush_icache_range;
local_flush_icache_range = local_r4k_flush_icache_range;
#if defined(CONFIG_DMA_NONCOHERENT)
if (coherentio) {
_dma_cache_wback_inv = (void *)cache_noop;
_dma_cache_wback = (void *)cache_noop;
_dma_cache_inv = (void *)cache_noop;
} else {
_dma_cache_wback_inv = r4k_dma_cache_wback_inv;
_dma_cache_wback = r4k_dma_cache_wback_inv;
_dma_cache_inv = r4k_dma_cache_inv;
}
#endif
build_clear_page();
build_copy_page();
local_r4k___flush_cache_all(NULL);
coherency_setup();
board_cache_error_setup = r4k_cache_error_setup;
}
