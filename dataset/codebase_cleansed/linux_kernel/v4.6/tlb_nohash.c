static inline int mmu_get_tsize(int psize)
{
return mmu_psize_defs[psize].enc;
}
static inline int mmu_get_tsize(int psize)
{
return 0;
}
void local_flush_tlb_mm(struct mm_struct *mm)
{
unsigned int pid;
preempt_disable();
pid = mm->context.id;
if (pid != MMU_NO_CONTEXT)
_tlbil_pid(pid);
preempt_enable();
}
void __local_flush_tlb_page(struct mm_struct *mm, unsigned long vmaddr,
int tsize, int ind)
{
unsigned int pid;
preempt_disable();
pid = mm ? mm->context.id : 0;
if (pid != MMU_NO_CONTEXT)
_tlbil_va(vmaddr, pid, tsize, ind);
preempt_enable();
}
void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long vmaddr)
{
__local_flush_tlb_page(vma ? vma->vm_mm : NULL, vmaddr,
mmu_get_tsize(mmu_virtual_psize), 0);
}
static int mm_is_core_local(struct mm_struct *mm)
{
return cpumask_subset(mm_cpumask(mm),
topology_sibling_cpumask(smp_processor_id()));
}
static void do_flush_tlb_mm_ipi(void *param)
{
struct tlb_flush_param *p = param;
_tlbil_pid(p ? p->pid : 0);
}
static void do_flush_tlb_page_ipi(void *param)
{
struct tlb_flush_param *p = param;
_tlbil_va(p->addr, p->pid, p->tsize, p->ind);
}
void flush_tlb_mm(struct mm_struct *mm)
{
unsigned int pid;
preempt_disable();
pid = mm->context.id;
if (unlikely(pid == MMU_NO_CONTEXT))
goto no_context;
if (!mm_is_core_local(mm)) {
struct tlb_flush_param p = { .pid = pid };
smp_call_function_many(mm_cpumask(mm),
do_flush_tlb_mm_ipi, &p, 1);
}
_tlbil_pid(pid);
no_context:
preempt_enable();
}
void __flush_tlb_page(struct mm_struct *mm, unsigned long vmaddr,
int tsize, int ind)
{
struct cpumask *cpu_mask;
unsigned int pid;
if (unlikely(WARN_ON(!mm)))
return;
preempt_disable();
pid = mm->context.id;
if (unlikely(pid == MMU_NO_CONTEXT))
goto bail;
cpu_mask = mm_cpumask(mm);
if (!mm_is_core_local(mm)) {
if (mmu_has_feature(MMU_FTR_USE_TLBIVAX_BCAST)) {
int lock = mmu_has_feature(MMU_FTR_LOCK_BCAST_INVAL);
if (lock)
raw_spin_lock(&tlbivax_lock);
_tlbivax_bcast(vmaddr, pid, tsize, ind);
if (lock)
raw_spin_unlock(&tlbivax_lock);
goto bail;
} else {
struct tlb_flush_param p = {
.pid = pid,
.addr = vmaddr,
.tsize = tsize,
.ind = ind,
};
smp_call_function_many(cpu_mask,
do_flush_tlb_page_ipi, &p, 1);
}
}
_tlbil_va(vmaddr, pid, tsize, ind);
bail:
preempt_enable();
}
void flush_tlb_page(struct vm_area_struct *vma, unsigned long vmaddr)
{
#ifdef CONFIG_HUGETLB_PAGE
if (vma && is_vm_hugetlb_page(vma))
flush_hugetlb_page(vma, vmaddr);
#endif
__flush_tlb_page(vma ? vma->vm_mm : NULL, vmaddr,
mmu_get_tsize(mmu_virtual_psize), 0);
}
void __init early_init_mmu_47x(void)
{
#ifdef CONFIG_SMP
unsigned long root = of_get_flat_dt_root();
if (of_get_flat_dt_prop(root, "cooperative-partition", NULL))
mmu_clear_feature(MMU_FTR_USE_TLBIVAX_BCAST);
#endif
}
void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
#ifdef CONFIG_SMP
preempt_disable();
smp_call_function(do_flush_tlb_mm_ipi, NULL, 1);
_tlbil_pid(0);
preempt_enable();
#else
_tlbil_pid(0);
#endif
}
void flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
flush_tlb_mm(vma->vm_mm);
}
void tlb_flush(struct mmu_gather *tlb)
{
flush_tlb_mm(tlb->mm);
}
void tlb_flush_pgtable(struct mmu_gather *tlb, unsigned long address)
{
int tsize = mmu_psize_defs[mmu_pte_psize].enc;
if (book3e_htw_mode != PPC_HTW_NONE) {
unsigned long start = address & PMD_MASK;
unsigned long end = address + PMD_SIZE;
unsigned long size = 1UL << mmu_psize_defs[mmu_pte_psize].shift;
while (start < end) {
__flush_tlb_page(tlb->mm, start, tsize, 1);
start += size;
}
} else {
unsigned long rmask = 0xf000000000000000ul;
unsigned long rid = (address & rmask) | 0x1000000000000000ul;
unsigned long vpte = address & ~rmask;
#ifdef CONFIG_PPC_64K_PAGES
vpte = (vpte >> (PAGE_SHIFT - 4)) & ~0xfffful;
#else
vpte = (vpte >> (PAGE_SHIFT - 3)) & ~0xffful;
#endif
vpte |= rid;
__flush_tlb_page(tlb->mm, vpte, tsize, 0);
}
}
static void setup_page_sizes(void)
{
unsigned int tlb0cfg;
unsigned int tlb0ps;
unsigned int eptcfg;
int i, psize;
#ifdef CONFIG_PPC_FSL_BOOK3E
unsigned int mmucfg = mfspr(SPRN_MMUCFG);
int fsl_mmu = mmu_has_feature(MMU_FTR_TYPE_FSL_E);
if (fsl_mmu && (mmucfg & MMUCFG_MAVN) == MMUCFG_MAVN_V1) {
unsigned int tlb1cfg = mfspr(SPRN_TLB1CFG);
unsigned int min_pg, max_pg;
min_pg = (tlb1cfg & TLBnCFG_MINSIZE) >> TLBnCFG_MINSIZE_SHIFT;
max_pg = (tlb1cfg & TLBnCFG_MAXSIZE) >> TLBnCFG_MAXSIZE_SHIFT;
for (psize = 0; psize < MMU_PAGE_COUNT; ++psize) {
struct mmu_psize_def *def;
unsigned int shift;
def = &mmu_psize_defs[psize];
shift = def->shift;
if (shift == 0 || shift & 1)
continue;
shift = (shift - 10) >> 1;
if ((shift >= min_pg) && (shift <= max_pg))
def->flags |= MMU_PAGE_SIZE_DIRECT;
}
goto out;
}
if (fsl_mmu && (mmucfg & MMUCFG_MAVN) == MMUCFG_MAVN_V2) {
u32 tlb1cfg, tlb1ps;
tlb0cfg = mfspr(SPRN_TLB0CFG);
tlb1cfg = mfspr(SPRN_TLB1CFG);
tlb1ps = mfspr(SPRN_TLB1PS);
eptcfg = mfspr(SPRN_EPTCFG);
if ((tlb1cfg & TLBnCFG_IND) && (tlb0cfg & TLBnCFG_PT))
book3e_htw_mode = PPC_HTW_E6500;
if (eptcfg != 2)
book3e_htw_mode = PPC_HTW_NONE;
for (psize = 0; psize < MMU_PAGE_COUNT; ++psize) {
struct mmu_psize_def *def = &mmu_psize_defs[psize];
if (tlb1ps & (1U << (def->shift - 10))) {
def->flags |= MMU_PAGE_SIZE_DIRECT;
if (book3e_htw_mode && psize == MMU_PAGE_2M)
def->flags |= MMU_PAGE_SIZE_INDIRECT;
}
}
goto out;
}
#endif
tlb0cfg = mfspr(SPRN_TLB0CFG);
tlb0ps = mfspr(SPRN_TLB0PS);
eptcfg = mfspr(SPRN_EPTCFG);
for (psize = 0; psize < MMU_PAGE_COUNT; ++psize) {
struct mmu_psize_def *def = &mmu_psize_defs[psize];
if (tlb0ps & (1U << (def->shift - 10)))
def->flags |= MMU_PAGE_SIZE_DIRECT;
}
if ((tlb0cfg & TLBnCFG_IND) == 0 ||
(tlb0cfg & TLBnCFG_PT) == 0)
goto out;
book3e_htw_mode = PPC_HTW_IBM;
for (i = 0; i < 3; i++) {
unsigned int ps, sps;
sps = eptcfg & 0x1f;
eptcfg >>= 5;
ps = eptcfg & 0x1f;
eptcfg >>= 5;
if (!ps || !sps)
continue;
for (psize = 0; psize < MMU_PAGE_COUNT; psize++) {
struct mmu_psize_def *def = &mmu_psize_defs[psize];
if (ps == (def->shift - 10))
def->flags |= MMU_PAGE_SIZE_INDIRECT;
if (sps == (def->shift - 10))
def->ind = ps + 10;
}
}
out:
pr_info("MMU: Supported page sizes\n");
for (psize = 0; psize < MMU_PAGE_COUNT; ++psize) {
struct mmu_psize_def *def = &mmu_psize_defs[psize];
const char *__page_type_names[] = {
"unsupported",
"direct",
"indirect",
"direct & indirect"
};
if (def->flags == 0) {
def->shift = 0;
continue;
}
pr_info(" %8ld KB as %s\n", 1ul << (def->shift - 10),
__page_type_names[def->flags & 0x3]);
}
}
static void setup_mmu_htw(void)
{
switch (book3e_htw_mode) {
case PPC_HTW_IBM:
patch_exception(0x1c0, exc_data_tlb_miss_htw_book3e);
patch_exception(0x1e0, exc_instruction_tlb_miss_htw_book3e);
break;
#ifdef CONFIG_PPC_FSL_BOOK3E
case PPC_HTW_E6500:
extlb_level_exc = EX_TLB_SIZE;
patch_exception(0x1c0, exc_data_tlb_miss_e6500_book3e);
patch_exception(0x1e0, exc_instruction_tlb_miss_e6500_book3e);
break;
#endif
}
pr_info("MMU: Book3E HW tablewalk %s\n",
book3e_htw_mode != PPC_HTW_NONE ? "enabled" : "not supported");
}
static void early_init_this_mmu(void)
{
unsigned int mas4;
mas4 = 0x4 << MAS4_WIMGED_SHIFT;
switch (book3e_htw_mode) {
case PPC_HTW_E6500:
mas4 |= MAS4_INDD;
mas4 |= BOOK3E_PAGESZ_2M << MAS4_TSIZED_SHIFT;
mas4 |= MAS4_TLBSELD(1);
mmu_pte_psize = MMU_PAGE_2M;
break;
case PPC_HTW_IBM:
mas4 |= MAS4_INDD;
#ifdef CONFIG_PPC_64K_PAGES
mas4 |= BOOK3E_PAGESZ_256M << MAS4_TSIZED_SHIFT;
mmu_pte_psize = MMU_PAGE_256M;
#else
mas4 |= BOOK3E_PAGESZ_1M << MAS4_TSIZED_SHIFT;
mmu_pte_psize = MMU_PAGE_1M;
#endif
break;
case PPC_HTW_NONE:
#ifdef CONFIG_PPC_64K_PAGES
mas4 |= BOOK3E_PAGESZ_64K << MAS4_TSIZED_SHIFT;
#else
mas4 |= BOOK3E_PAGESZ_4K << MAS4_TSIZED_SHIFT;
#endif
mmu_pte_psize = mmu_virtual_psize;
break;
}
mtspr(SPRN_MAS4, mas4);
#ifdef CONFIG_PPC_FSL_BOOK3E
if (mmu_has_feature(MMU_FTR_TYPE_FSL_E)) {
unsigned int num_cams;
int __maybe_unused cpu = smp_processor_id();
bool map = true;
num_cams = (mfspr(SPRN_TLB1CFG) & TLBnCFG_N_ENTRY) / 4;
#ifdef CONFIG_SMP
if (hweight32(get_tensr()) > 1)
map = false;
#endif
if (map)
linear_map_top = map_mem_in_cams(linear_map_top,
num_cams, false);
}
#endif
mb();
}
static void __init early_init_mmu_global(void)
{
mmu_linear_psize = MMU_PAGE_1G;
if (mmu_has_feature(MMU_FTR_TYPE_FSL_E))
mmu_vmemmap_psize = MMU_PAGE_4K;
else
mmu_vmemmap_psize = MMU_PAGE_16M;
setup_page_sizes();
setup_mmu_htw();
#ifdef CONFIG_PPC_FSL_BOOK3E
if (mmu_has_feature(MMU_FTR_TYPE_FSL_E)) {
if (book3e_htw_mode == PPC_HTW_NONE) {
extlb_level_exc = EX_TLB_SIZE;
patch_exception(0x1c0, exc_data_tlb_miss_bolted_book3e);
patch_exception(0x1e0,
exc_instruction_tlb_miss_bolted_book3e);
}
}
#endif
linear_map_top = memblock_end_of_DRAM();
}
static void __init early_mmu_set_memory_limit(void)
{
#ifdef CONFIG_PPC_FSL_BOOK3E
if (mmu_has_feature(MMU_FTR_TYPE_FSL_E)) {
memblock_enforce_memory_limit(linear_map_top);
}
#endif
memblock_set_current_limit(linear_map_top);
}
void __init early_init_mmu(void)
{
early_init_mmu_global();
early_init_this_mmu();
early_mmu_set_memory_limit();
}
void early_init_mmu_secondary(void)
{
early_init_this_mmu();
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
#ifdef CONFIG_PPC_FSL_BOOK3E
if (mmu_has_feature(MMU_FTR_TYPE_FSL_E)) {
unsigned long linear_sz;
unsigned int num_cams;
num_cams = (mfspr(SPRN_TLB1CFG) & TLBnCFG_N_ENTRY) / 4;
linear_sz = map_mem_in_cams(first_memblock_size, num_cams,
true);
ppc64_rma_size = min_t(u64, linear_sz, 0x40000000);
} else
#endif
ppc64_rma_size = min_t(u64, first_memblock_size, 0x40000000);
memblock_set_current_limit(first_memblock_base + ppc64_rma_size);
}
void __init early_init_mmu(void)
{
#ifdef CONFIG_PPC_47x
early_init_mmu_47x();
#endif
}
