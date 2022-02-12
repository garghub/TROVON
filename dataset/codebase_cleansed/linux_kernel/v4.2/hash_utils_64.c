static unsigned long htab_convert_pte_flags(unsigned long pteflags)
{
unsigned long rflags = pteflags & 0x1fa;
if ((pteflags & _PAGE_EXEC) == 0)
rflags |= HPTE_R_N;
if ((pteflags & _PAGE_USER) && !((pteflags & _PAGE_RW) &&
(pteflags & _PAGE_DIRTY)))
rflags |= 1;
return rflags | HPTE_R_C | HPTE_R_M;
}
int htab_bolt_mapping(unsigned long vstart, unsigned long vend,
unsigned long pstart, unsigned long prot,
int psize, int ssize)
{
unsigned long vaddr, paddr;
unsigned int step, shift;
int ret = 0;
shift = mmu_psize_defs[psize].shift;
step = 1 << shift;
prot = htab_convert_pte_flags(prot);
DBG("htab_bolt_mapping(%lx..%lx -> %lx (%lx,%d,%d)\n",
vstart, vend, pstart, prot, psize, ssize);
for (vaddr = vstart, paddr = pstart; vaddr < vend;
vaddr += step, paddr += step) {
unsigned long hash, hpteg;
unsigned long vsid = get_kernel_vsid(vaddr, ssize);
unsigned long vpn = hpt_vpn(vaddr, vsid, ssize);
unsigned long tprot = prot;
if (!vsid)
return -1;
if (overlaps_kernel_text(vaddr, vaddr + step))
tprot &= ~HPTE_R_N;
if (overlaps_kvm_tmp(vaddr, vaddr + step))
tprot &= ~HPTE_R_N;
if ((PHYSICAL_START > MEMORY_START) &&
overlaps_interrupt_vector_text(vaddr, vaddr + step))
tprot &= ~HPTE_R_N;
hash = hpt_hash(vpn, shift, ssize);
hpteg = ((hash & htab_hash_mask) * HPTES_PER_GROUP);
BUG_ON(!ppc_md.hpte_insert);
ret = ppc_md.hpte_insert(hpteg, vpn, paddr, tprot,
HPTE_V_BOLTED, psize, psize, ssize);
if (ret < 0)
break;
#ifdef CONFIG_DEBUG_PAGEALLOC
if ((paddr >> PAGE_SHIFT) < linear_map_hash_count)
linear_map_hash_slots[paddr >> PAGE_SHIFT] = ret | 0x80;
#endif
}
return ret < 0 ? ret : 0;
}
int htab_remove_mapping(unsigned long vstart, unsigned long vend,
int psize, int ssize)
{
unsigned long vaddr;
unsigned int step, shift;
shift = mmu_psize_defs[psize].shift;
step = 1 << shift;
if (!ppc_md.hpte_removebolted) {
printk(KERN_WARNING "Platform doesn't implement "
"hpte_removebolted\n");
return -EINVAL;
}
for (vaddr = vstart; vaddr < vend; vaddr += step)
ppc_md.hpte_removebolted(vaddr, psize, ssize);
return 0;
}
static int __init htab_dt_scan_seg_sizes(unsigned long node,
const char *uname, int depth,
void *data)
{
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
const __be32 *prop;
int size = 0;
if (type == NULL || strcmp(type, "cpu") != 0)
return 0;
prop = of_get_flat_dt_prop(node, "ibm,processor-segment-sizes", &size);
if (prop == NULL)
return 0;
for (; size >= 4; size -= 4, ++prop) {
if (be32_to_cpu(prop[0]) == 40) {
DBG("1T segment support detected\n");
cur_cpu_spec->mmu_features |= MMU_FTR_1T_SEGMENT;
return 1;
}
}
cur_cpu_spec->mmu_features &= ~MMU_FTR_NO_SLBIE_B;
return 0;
}
static void __init htab_init_seg_sizes(void)
{
of_scan_flat_dt(htab_dt_scan_seg_sizes, NULL);
}
static int __init get_idx_from_shift(unsigned int shift)
{
int idx = -1;
switch (shift) {
case 0xc:
idx = MMU_PAGE_4K;
break;
case 0x10:
idx = MMU_PAGE_64K;
break;
case 0x14:
idx = MMU_PAGE_1M;
break;
case 0x18:
idx = MMU_PAGE_16M;
break;
case 0x22:
idx = MMU_PAGE_16G;
break;
}
return idx;
}
static int __init htab_dt_scan_page_sizes(unsigned long node,
const char *uname, int depth,
void *data)
{
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
const __be32 *prop;
int size = 0;
if (type == NULL || strcmp(type, "cpu") != 0)
return 0;
prop = of_get_flat_dt_prop(node, "ibm,segment-page-sizes", &size);
if (!prop)
return 0;
pr_info("Page sizes from device-tree:\n");
size /= 4;
cur_cpu_spec->mmu_features &= ~(MMU_FTR_16M_PAGE);
while(size > 0) {
unsigned int base_shift = be32_to_cpu(prop[0]);
unsigned int slbenc = be32_to_cpu(prop[1]);
unsigned int lpnum = be32_to_cpu(prop[2]);
struct mmu_psize_def *def;
int idx, base_idx;
size -= 3; prop += 3;
base_idx = get_idx_from_shift(base_shift);
if (base_idx < 0) {
prop += lpnum * 2; size -= lpnum * 2;
continue;
}
def = &mmu_psize_defs[base_idx];
if (base_idx == MMU_PAGE_16M)
cur_cpu_spec->mmu_features |= MMU_FTR_16M_PAGE;
def->shift = base_shift;
if (base_shift <= 23)
def->avpnm = 0;
else
def->avpnm = (1 << (base_shift - 23)) - 1;
def->sllp = slbenc;
if (base_idx == MMU_PAGE_4K || base_idx == MMU_PAGE_64K)
def->tlbiel = 1;
else
def->tlbiel = 0;
while (size > 0 && lpnum) {
unsigned int shift = be32_to_cpu(prop[0]);
int penc = be32_to_cpu(prop[1]);
prop += 2; size -= 2;
lpnum--;
idx = get_idx_from_shift(shift);
if (idx < 0)
continue;
if (penc == -1)
pr_err("Invalid penc for base_shift=%d "
"shift=%d\n", base_shift, shift);
def->penc[idx] = penc;
pr_info("base_shift=%d: shift=%d, sllp=0x%04lx,"
" avpnm=0x%08lx, tlbiel=%d, penc=%d\n",
base_shift, shift, def->sllp,
def->avpnm, def->tlbiel, def->penc[idx]);
}
}
return 1;
}
static int __init htab_dt_scan_hugepage_blocks(unsigned long node,
const char *uname, int depth,
void *data) {
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
const __be64 *addr_prop;
const __be32 *page_count_prop;
unsigned int expected_pages;
long unsigned int phys_addr;
long unsigned int block_size;
if (type == NULL || strcmp(type, "memory") != 0)
return 0;
page_count_prop = of_get_flat_dt_prop(node, "ibm,expected#pages", NULL);
if (page_count_prop == NULL)
return 0;
expected_pages = (1 << be32_to_cpu(page_count_prop[0]));
addr_prop = of_get_flat_dt_prop(node, "reg", NULL);
if (addr_prop == NULL)
return 0;
phys_addr = be64_to_cpu(addr_prop[0]);
block_size = be64_to_cpu(addr_prop[1]);
if (block_size != (16 * GB))
return 0;
printk(KERN_INFO "Huge page(16GB) memory: "
"addr = 0x%lX size = 0x%lX pages = %d\n",
phys_addr, block_size, expected_pages);
if (phys_addr + (16 * GB) <= memblock_end_of_DRAM()) {
memblock_reserve(phys_addr, block_size * expected_pages);
add_gpage(phys_addr, block_size, expected_pages);
}
return 0;
}
static void mmu_psize_set_default_penc(void)
{
int bpsize, apsize;
for (bpsize = 0; bpsize < MMU_PAGE_COUNT; bpsize++)
for (apsize = 0; apsize < MMU_PAGE_COUNT; apsize++)
mmu_psize_defs[bpsize].penc[apsize] = -1;
}
static bool might_have_hea(void)
{
#ifdef CONFIG_IBMEBUS
return !cpu_has_feature(CPU_FTR_ARCH_207S);
#else
return false;
#endif
}
static void __init htab_init_page_sizes(void)
{
int rc;
mmu_psize_set_default_penc();
memcpy(mmu_psize_defs, mmu_psize_defaults_old,
sizeof(mmu_psize_defaults_old));
rc = of_scan_flat_dt(htab_dt_scan_page_sizes, NULL);
if (rc != 0)
goto found;
if (mmu_has_feature(MMU_FTR_16M_PAGE))
memcpy(mmu_psize_defs, mmu_psize_defaults_gp,
sizeof(mmu_psize_defaults_gp));
found:
#ifndef CONFIG_DEBUG_PAGEALLOC
if (mmu_psize_defs[MMU_PAGE_16M].shift)
mmu_linear_psize = MMU_PAGE_16M;
else if (mmu_psize_defs[MMU_PAGE_1M].shift)
mmu_linear_psize = MMU_PAGE_1M;
#endif
#ifdef CONFIG_PPC_64K_PAGES
if (mmu_psize_defs[MMU_PAGE_64K].shift) {
mmu_virtual_psize = MMU_PAGE_64K;
mmu_vmalloc_psize = MMU_PAGE_64K;
if (mmu_linear_psize == MMU_PAGE_4K)
mmu_linear_psize = MMU_PAGE_64K;
if (mmu_has_feature(MMU_FTR_CI_LARGE_PAGE)) {
if (!might_have_hea() || !machine_is(pseries))
mmu_io_psize = MMU_PAGE_64K;
} else
mmu_ci_restrictions = 1;
}
#endif
#ifdef CONFIG_SPARSEMEM_VMEMMAP
if (mmu_psize_defs[MMU_PAGE_16M].shift &&
memblock_phys_mem_size() >= 0x40000000)
mmu_vmemmap_psize = MMU_PAGE_16M;
else if (mmu_psize_defs[MMU_PAGE_64K].shift)
mmu_vmemmap_psize = MMU_PAGE_64K;
else
mmu_vmemmap_psize = MMU_PAGE_4K;
#endif
printk(KERN_DEBUG "Page orders: linear mapping = %d, "
"virtual = %d, io = %d"
#ifdef CONFIG_SPARSEMEM_VMEMMAP
", vmemmap = %d"
#endif
"\n",
mmu_psize_defs[mmu_linear_psize].shift,
mmu_psize_defs[mmu_virtual_psize].shift,
mmu_psize_defs[mmu_io_psize].shift
#ifdef CONFIG_SPARSEMEM_VMEMMAP
,mmu_psize_defs[mmu_vmemmap_psize].shift
#endif
);
#ifdef CONFIG_HUGETLB_PAGE
of_scan_flat_dt(htab_dt_scan_hugepage_blocks, NULL);
#endif
}
static int __init htab_dt_scan_pftsize(unsigned long node,
const char *uname, int depth,
void *data)
{
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
const __be32 *prop;
if (type == NULL || strcmp(type, "cpu") != 0)
return 0;
prop = of_get_flat_dt_prop(node, "ibm,pft-size", NULL);
if (prop != NULL) {
ppc64_pft_size = be32_to_cpu(prop[1]);
return 1;
}
return 0;
}
static unsigned long __init htab_get_table_size(void)
{
unsigned long mem_size, rnd_mem_size, pteg_count, psize;
if (ppc64_pft_size == 0)
of_scan_flat_dt(htab_dt_scan_pftsize, NULL);
if (ppc64_pft_size)
return 1UL << ppc64_pft_size;
mem_size = memblock_phys_mem_size();
rnd_mem_size = 1UL << __ilog2(mem_size);
if (rnd_mem_size < mem_size)
rnd_mem_size <<= 1;
psize = mmu_psize_defs[mmu_virtual_psize].shift;
pteg_count = max(rnd_mem_size >> (psize + 1), 1UL << 11);
return pteg_count << 7;
}
int create_section_mapping(unsigned long start, unsigned long end)
{
return htab_bolt_mapping(start, end, __pa(start),
pgprot_val(PAGE_KERNEL), mmu_linear_psize,
mmu_kernel_ssize);
}
int remove_section_mapping(unsigned long start, unsigned long end)
{
return htab_remove_mapping(start, end, mmu_linear_psize,
mmu_kernel_ssize);
}
static void __init htab_finish_init(void)
{
#ifdef CONFIG_PPC_HAS_HASH_64K
patch_branch(ht64_call_hpte_insert1,
ppc_function_entry(ppc_md.hpte_insert),
BRANCH_SET_LINK);
patch_branch(ht64_call_hpte_insert2,
ppc_function_entry(ppc_md.hpte_insert),
BRANCH_SET_LINK);
patch_branch(ht64_call_hpte_remove,
ppc_function_entry(ppc_md.hpte_remove),
BRANCH_SET_LINK);
patch_branch(ht64_call_hpte_updatepp,
ppc_function_entry(ppc_md.hpte_updatepp),
BRANCH_SET_LINK);
#endif
patch_branch(htab_call_hpte_insert1,
ppc_function_entry(ppc_md.hpte_insert),
BRANCH_SET_LINK);
patch_branch(htab_call_hpte_insert2,
ppc_function_entry(ppc_md.hpte_insert),
BRANCH_SET_LINK);
patch_branch(htab_call_hpte_remove,
ppc_function_entry(ppc_md.hpte_remove),
BRANCH_SET_LINK);
patch_branch(htab_call_hpte_updatepp,
ppc_function_entry(ppc_md.hpte_updatepp),
BRANCH_SET_LINK);
}
static void __init htab_initialize(void)
{
unsigned long table;
unsigned long pteg_count;
unsigned long prot;
unsigned long base = 0, size = 0, limit;
struct memblock_region *reg;
DBG(" -> htab_initialize()\n");
htab_init_seg_sizes();
htab_init_page_sizes();
if (mmu_has_feature(MMU_FTR_1T_SEGMENT)) {
mmu_kernel_ssize = MMU_SEGSIZE_1T;
mmu_highuser_ssize = MMU_SEGSIZE_1T;
printk(KERN_INFO "Using 1TB segments\n");
}
htab_size_bytes = htab_get_table_size();
pteg_count = htab_size_bytes >> 7;
htab_hash_mask = pteg_count - 1;
if (firmware_has_feature(FW_FEATURE_LPAR)) {
htab_address = NULL;
_SDR1 = 0;
#ifdef CONFIG_FA_DUMP
if (is_fadump_active() && ppc_md.hpte_clear_all)
ppc_md.hpte_clear_all();
#endif
} else {
if (machine_is(cell))
limit = 0x80000000;
else
limit = MEMBLOCK_ALLOC_ANYWHERE;
table = memblock_alloc_base(htab_size_bytes, htab_size_bytes, limit);
DBG("Hash table allocated at %lx, size: %lx\n", table,
htab_size_bytes);
htab_address = __va(table);
_SDR1 = table + __ilog2(pteg_count) - 11;
memset((void *)table, 0, htab_size_bytes);
mtspr(SPRN_SDR1, _SDR1);
}
prot = pgprot_val(PAGE_KERNEL);
#ifdef CONFIG_DEBUG_PAGEALLOC
linear_map_hash_count = memblock_end_of_DRAM() >> PAGE_SHIFT;
linear_map_hash_slots = __va(memblock_alloc_base(linear_map_hash_count,
1, ppc64_rma_size));
memset(linear_map_hash_slots, 0, linear_map_hash_count);
#endif
for_each_memblock(memory, reg) {
base = (unsigned long)__va(reg->base);
size = reg->size;
DBG("creating mapping for region: %lx..%lx (prot: %lx)\n",
base, size, prot);
#ifdef CONFIG_U3_DART
DBG("DART base: %lx\n", dart_tablebase);
if (dart_tablebase != 0 && dart_tablebase >= base
&& dart_tablebase < (base + size)) {
unsigned long dart_table_end = dart_tablebase + 16 * MB;
if (base != dart_tablebase)
BUG_ON(htab_bolt_mapping(base, dart_tablebase,
__pa(base), prot,
mmu_linear_psize,
mmu_kernel_ssize));
if ((base + size) > dart_table_end)
BUG_ON(htab_bolt_mapping(dart_tablebase+16*MB,
base + size,
__pa(dart_table_end),
prot,
mmu_linear_psize,
mmu_kernel_ssize));
continue;
}
#endif
BUG_ON(htab_bolt_mapping(base, base + size, __pa(base),
prot, mmu_linear_psize, mmu_kernel_ssize));
}
memblock_set_current_limit(MEMBLOCK_ALLOC_ANYWHERE);
if (tce_alloc_start) {
tce_alloc_start = (unsigned long)__va(tce_alloc_start);
tce_alloc_end = (unsigned long)__va(tce_alloc_end);
if (base + size >= tce_alloc_start)
tce_alloc_start = base + size + 1;
BUG_ON(htab_bolt_mapping(tce_alloc_start, tce_alloc_end,
__pa(tce_alloc_start), prot,
mmu_linear_psize, mmu_kernel_ssize));
}
htab_finish_init();
DBG(" <- htab_initialize()\n");
}
void __init early_init_mmu(void)
{
htab_initialize();
slb_initialize();
}
void early_init_mmu_secondary(void)
{
if (!firmware_has_feature(FW_FEATURE_LPAR))
mtspr(SPRN_SDR1, _SDR1);
slb_initialize();
}
unsigned int hash_page_do_lazy_icache(unsigned int pp, pte_t pte, int trap)
{
struct page *page;
if (!pfn_valid(pte_pfn(pte)))
return pp;
page = pte_page(pte);
if (!test_bit(PG_arch_1, &page->flags) && !PageReserved(page)) {
if (trap == 0x400) {
flush_dcache_icache_page(page);
set_bit(PG_arch_1, &page->flags);
} else
pp |= HPTE_R_N;
}
return pp;
}
static unsigned int get_paca_psize(unsigned long addr)
{
u64 lpsizes;
unsigned char *hpsizes;
unsigned long index, mask_index;
if (addr < SLICE_LOW_TOP) {
lpsizes = get_paca()->context.low_slices_psize;
index = GET_LOW_SLICE_INDEX(addr);
return (lpsizes >> (index * 4)) & 0xF;
}
hpsizes = get_paca()->context.high_slices_psize;
index = GET_HIGH_SLICE_INDEX(addr);
mask_index = index & 0x1;
return (hpsizes[index >> 1] >> (mask_index * 4)) & 0xF;
}
unsigned int get_paca_psize(unsigned long addr)
{
return get_paca()->context.user_psize;
}
void demote_segment_4k(struct mm_struct *mm, unsigned long addr)
{
if (get_slice_psize(mm, addr) == MMU_PAGE_4K)
return;
slice_set_range_psize(mm, addr, 1, MMU_PAGE_4K);
copro_flush_all_slbs(mm);
if ((get_paca_psize(addr) != MMU_PAGE_4K) && (current->mm == mm)) {
get_paca()->context = mm->context;
slb_flush_and_rebolt();
}
}
static int subpage_protection(struct mm_struct *mm, unsigned long ea)
{
struct subpage_prot_table *spt = &mm->context.spt;
u32 spp = 0;
u32 **sbpm, *sbpp;
if (ea >= spt->maxaddr)
return 0;
if (ea < 0x100000000UL) {
sbpm = spt->low_prot;
} else {
sbpm = spt->protptrs[ea >> SBP_L3_SHIFT];
if (!sbpm)
return 0;
}
sbpp = sbpm[(ea >> SBP_L2_SHIFT) & (SBP_L2_COUNT - 1)];
if (!sbpp)
return 0;
spp = sbpp[(ea >> PAGE_SHIFT) & (SBP_L1_COUNT - 1)];
spp >>= 30 - 2 * ((ea >> 12) & 0xf);
spp = ((spp & 2) ? _PAGE_USER : 0) | ((spp & 1) ? _PAGE_RW : 0);
return spp;
}
static inline int subpage_protection(struct mm_struct *mm, unsigned long ea)
{
return 0;
}
void hash_failure_debug(unsigned long ea, unsigned long access,
unsigned long vsid, unsigned long trap,
int ssize, int psize, int lpsize, unsigned long pte)
{
if (!printk_ratelimit())
return;
pr_info("mm: Hashing failure ! EA=0x%lx access=0x%lx current=%s\n",
ea, access, current->comm);
pr_info(" trap=0x%lx vsid=0x%lx ssize=%d base psize=%d psize %d pte=0x%lx\n",
trap, vsid, ssize, psize, lpsize, pte);
}
static void check_paca_psize(unsigned long ea, struct mm_struct *mm,
int psize, bool user_region)
{
if (user_region) {
if (psize != get_paca_psize(ea)) {
get_paca()->context = mm->context;
slb_flush_and_rebolt();
}
} else if (get_paca()->vmalloc_sllp !=
mmu_psize_defs[mmu_vmalloc_psize].sllp) {
get_paca()->vmalloc_sllp =
mmu_psize_defs[mmu_vmalloc_psize].sllp;
slb_vmalloc_update();
}
}
int hash_page_mm(struct mm_struct *mm, unsigned long ea,
unsigned long access, unsigned long trap,
unsigned long flags)
{
enum ctx_state prev_state = exception_enter();
pgd_t *pgdir;
unsigned long vsid;
pte_t *ptep;
unsigned hugeshift;
const struct cpumask *tmp;
int rc, user_region = 0;
int psize, ssize;
DBG_LOW("hash_page(ea=%016lx, access=%lx, trap=%lx\n",
ea, access, trap);
trace_hash_fault(ea, access, trap);
switch (REGION_ID(ea)) {
case USER_REGION_ID:
user_region = 1;
if (! mm) {
DBG_LOW(" user region with no mm !\n");
rc = 1;
goto bail;
}
psize = get_slice_psize(mm, ea);
ssize = user_segment_size(ea);
vsid = get_vsid(mm->context.id, ea, ssize);
break;
case VMALLOC_REGION_ID:
vsid = get_kernel_vsid(ea, mmu_kernel_ssize);
if (ea < VMALLOC_END)
psize = mmu_vmalloc_psize;
else
psize = mmu_io_psize;
ssize = mmu_kernel_ssize;
break;
default:
rc = 1;
goto bail;
}
DBG_LOW(" mm=%p, mm->pgdir=%p, vsid=%016lx\n", mm, mm->pgd, vsid);
if (!vsid) {
DBG_LOW("Bad address!\n");
rc = 1;
goto bail;
}
pgdir = mm->pgd;
if (pgdir == NULL) {
rc = 1;
goto bail;
}
tmp = cpumask_of(smp_processor_id());
if (user_region && cpumask_equal(mm_cpumask(mm), tmp))
flags |= HPTE_LOCAL_UPDATE;
#ifndef CONFIG_PPC_64K_PAGES
if (psize != MMU_PAGE_4K)
ea &= ~((1ul << mmu_psize_defs[psize].shift) - 1);
#endif
ptep = __find_linux_pte_or_hugepte(pgdir, ea, &hugeshift);
if (ptep == NULL || !pte_present(*ptep)) {
DBG_LOW(" no PTE !\n");
rc = 1;
goto bail;
}
access |= _PAGE_PRESENT;
if (access & ~pte_val(*ptep)) {
DBG_LOW(" no access !\n");
rc = 1;
goto bail;
}
if (hugeshift) {
if (pmd_trans_huge(*(pmd_t *)ptep))
rc = __hash_page_thp(ea, access, vsid, (pmd_t *)ptep,
trap, flags, ssize, psize);
#ifdef CONFIG_HUGETLB_PAGE
else
rc = __hash_page_huge(ea, access, vsid, ptep, trap,
flags, ssize, hugeshift, psize);
#else
else {
rc = 1;
WARN_ON(1);
}
#endif
if (current->mm == mm)
check_paca_psize(ea, mm, psize, user_region);
goto bail;
}
#ifndef CONFIG_PPC_64K_PAGES
DBG_LOW(" i-pte: %016lx\n", pte_val(*ptep));
#else
DBG_LOW(" i-pte: %016lx %016lx\n", pte_val(*ptep),
pte_val(*(ptep + PTRS_PER_PTE)));
#endif
#ifdef CONFIG_PPC_64K_PAGES
if ((pte_val(*ptep) & _PAGE_4K_PFN) && psize == MMU_PAGE_64K) {
demote_segment_4k(mm, ea);
psize = MMU_PAGE_4K;
}
if (mmu_ci_restrictions && psize == MMU_PAGE_64K &&
(pte_val(*ptep) & _PAGE_NO_CACHE)) {
if (user_region) {
demote_segment_4k(mm, ea);
psize = MMU_PAGE_4K;
} else if (ea < VMALLOC_END) {
printk(KERN_ALERT "Reducing vmalloc segment "
"to 4kB pages because of "
"non-cacheable mapping\n");
psize = mmu_vmalloc_psize = MMU_PAGE_4K;
copro_flush_all_slbs(mm);
}
}
if (current->mm == mm)
check_paca_psize(ea, mm, psize, user_region);
#endif
#ifdef CONFIG_PPC_HAS_HASH_64K
if (psize == MMU_PAGE_64K)
rc = __hash_page_64K(ea, access, vsid, ptep, trap,
flags, ssize);
else
#endif
{
int spp = subpage_protection(mm, ea);
if (access & spp)
rc = -2;
else
rc = __hash_page_4K(ea, access, vsid, ptep, trap,
flags, ssize, spp);
}
if (rc == -1)
hash_failure_debug(ea, access, vsid, trap, ssize, psize,
psize, pte_val(*ptep));
#ifndef CONFIG_PPC_64K_PAGES
DBG_LOW(" o-pte: %016lx\n", pte_val(*ptep));
#else
DBG_LOW(" o-pte: %016lx %016lx\n", pte_val(*ptep),
pte_val(*(ptep + PTRS_PER_PTE)));
#endif
DBG_LOW(" -> rc=%d\n", rc);
bail:
exception_exit(prev_state);
return rc;
}
int hash_page(unsigned long ea, unsigned long access, unsigned long trap,
unsigned long dsisr)
{
unsigned long flags = 0;
struct mm_struct *mm = current->mm;
if (REGION_ID(ea) == VMALLOC_REGION_ID)
mm = &init_mm;
if (dsisr & DSISR_NOHPTE)
flags |= HPTE_NOHPTE_UPDATE;
return hash_page_mm(mm, ea, access, trap, flags);
}
void hash_preload(struct mm_struct *mm, unsigned long ea,
unsigned long access, unsigned long trap)
{
int hugepage_shift;
unsigned long vsid;
pgd_t *pgdir;
pte_t *ptep;
unsigned long flags;
int rc, ssize, update_flags = 0;
BUG_ON(REGION_ID(ea) != USER_REGION_ID);
#ifdef CONFIG_PPC_MM_SLICES
if (unlikely(get_slice_psize(mm, ea) != mm->context.user_psize))
return;
#endif
DBG_LOW("hash_preload(mm=%p, mm->pgdir=%p, ea=%016lx, access=%lx,"
" trap=%lx\n", mm, mm->pgd, ea, access, trap);
pgdir = mm->pgd;
if (pgdir == NULL)
return;
ssize = user_segment_size(ea);
vsid = get_vsid(mm->context.id, ea, ssize);
if (!vsid)
return;
local_irq_save(flags);
ptep = find_linux_pte_or_hugepte(pgdir, ea, &hugepage_shift);
if (!ptep)
goto out_exit;
WARN_ON(hugepage_shift);
#ifdef CONFIG_PPC_64K_PAGES
if (pte_val(*ptep) & (_PAGE_4K_PFN | _PAGE_NO_CACHE))
goto out_exit;
#endif
if (cpumask_equal(mm_cpumask(mm), cpumask_of(smp_processor_id())))
update_flags |= HPTE_LOCAL_UPDATE;
#ifdef CONFIG_PPC_HAS_HASH_64K
if (mm->context.user_psize == MMU_PAGE_64K)
rc = __hash_page_64K(ea, access, vsid, ptep, trap,
update_flags, ssize);
else
#endif
rc = __hash_page_4K(ea, access, vsid, ptep, trap, update_flags,
ssize, subpage_protection(mm, ea));
if (rc == -1)
hash_failure_debug(ea, access, vsid, trap, ssize,
mm->context.user_psize,
mm->context.user_psize,
pte_val(*ptep));
out_exit:
local_irq_restore(flags);
}
void flush_hash_page(unsigned long vpn, real_pte_t pte, int psize, int ssize,
unsigned long flags)
{
unsigned long hash, index, shift, hidx, slot;
int local = flags & HPTE_LOCAL_UPDATE;
DBG_LOW("flush_hash_page(vpn=%016lx)\n", vpn);
pte_iterate_hashed_subpages(pte, psize, vpn, index, shift) {
hash = hpt_hash(vpn, shift, ssize);
hidx = __rpte_to_hidx(pte, index);
if (hidx & _PTEIDX_SECONDARY)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += hidx & _PTEIDX_GROUP_IX;
DBG_LOW(" sub %ld: hash=%lx, hidx=%lx\n", index, slot, hidx);
ppc_md.hpte_invalidate(slot, vpn, psize, psize, ssize, local);
} pte_iterate_hashed_end();
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
if (local && cpu_has_feature(CPU_FTR_TM) &&
current->thread.regs &&
MSR_TM_ACTIVE(current->thread.regs->msr)) {
tm_enable();
tm_abort(TM_CAUSE_TLBI);
}
#endif
}
void flush_hash_hugepage(unsigned long vsid, unsigned long addr,
pmd_t *pmdp, unsigned int psize, int ssize,
unsigned long flags)
{
int i, max_hpte_count, valid;
unsigned long s_addr;
unsigned char *hpte_slot_array;
unsigned long hidx, shift, vpn, hash, slot;
int local = flags & HPTE_LOCAL_UPDATE;
s_addr = addr & HPAGE_PMD_MASK;
hpte_slot_array = get_hpte_slot_array(pmdp);
if (!hpte_slot_array)
return;
if (ppc_md.hugepage_invalidate) {
ppc_md.hugepage_invalidate(vsid, s_addr, hpte_slot_array,
psize, ssize, local);
goto tm_abort;
}
shift = mmu_psize_defs[psize].shift;
max_hpte_count = HPAGE_PMD_SIZE >> shift;
for (i = 0; i < max_hpte_count; i++) {
valid = hpte_valid(hpte_slot_array, i);
if (!valid)
continue;
hidx = hpte_hash_index(hpte_slot_array, i);
addr = s_addr + (i * (1ul << shift));
vpn = hpt_vpn(addr, vsid, ssize);
hash = hpt_hash(vpn, shift, ssize);
if (hidx & _PTEIDX_SECONDARY)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += hidx & _PTEIDX_GROUP_IX;
ppc_md.hpte_invalidate(slot, vpn, psize,
MMU_PAGE_16M, ssize, local);
}
tm_abort:
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
if (local && cpu_has_feature(CPU_FTR_TM) &&
current->thread.regs &&
MSR_TM_ACTIVE(current->thread.regs->msr)) {
tm_enable();
tm_abort(TM_CAUSE_TLBI);
}
#endif
return;
}
void flush_hash_range(unsigned long number, int local)
{
if (ppc_md.flush_hash_range)
ppc_md.flush_hash_range(number, local);
else {
int i;
struct ppc64_tlb_batch *batch =
this_cpu_ptr(&ppc64_tlb_batch);
for (i = 0; i < number; i++)
flush_hash_page(batch->vpn[i], batch->pte[i],
batch->psize, batch->ssize, local);
}
}
void low_hash_fault(struct pt_regs *regs, unsigned long address, int rc)
{
enum ctx_state prev_state = exception_enter();
if (user_mode(regs)) {
#ifdef CONFIG_PPC_SUBPAGE_PROT
if (rc == -2)
_exception(SIGSEGV, regs, SEGV_ACCERR, address);
else
#endif
_exception(SIGBUS, regs, BUS_ADRERR, address);
} else
bad_page_fault(regs, address, SIGBUS);
exception_exit(prev_state);
}
long hpte_insert_repeating(unsigned long hash, unsigned long vpn,
unsigned long pa, unsigned long rflags,
unsigned long vflags, int psize, int ssize)
{
unsigned long hpte_group;
long slot;
repeat:
hpte_group = ((hash & htab_hash_mask) *
HPTES_PER_GROUP) & ~0x7UL;
slot = ppc_md.hpte_insert(hpte_group, vpn, pa, rflags, vflags,
psize, psize, ssize);
if (unlikely(slot == -1)) {
hpte_group = ((~hash & htab_hash_mask) *
HPTES_PER_GROUP) & ~0x7UL;
slot = ppc_md.hpte_insert(hpte_group, vpn, pa, rflags,
vflags | HPTE_V_SECONDARY,
psize, psize, ssize);
if (slot == -1) {
if (mftb() & 0x1)
hpte_group = ((hash & htab_hash_mask) *
HPTES_PER_GROUP)&~0x7UL;
ppc_md.hpte_remove(hpte_group);
goto repeat;
}
}
return slot;
}
static void kernel_map_linear_page(unsigned long vaddr, unsigned long lmi)
{
unsigned long hash;
unsigned long vsid = get_kernel_vsid(vaddr, mmu_kernel_ssize);
unsigned long vpn = hpt_vpn(vaddr, vsid, mmu_kernel_ssize);
unsigned long mode = htab_convert_pte_flags(pgprot_val(PAGE_KERNEL));
long ret;
hash = hpt_hash(vpn, PAGE_SHIFT, mmu_kernel_ssize);
if (!vsid)
return;
ret = hpte_insert_repeating(hash, vpn, __pa(vaddr), mode,
HPTE_V_BOLTED,
mmu_linear_psize, mmu_kernel_ssize);
BUG_ON (ret < 0);
spin_lock(&linear_map_hash_lock);
BUG_ON(linear_map_hash_slots[lmi] & 0x80);
linear_map_hash_slots[lmi] = ret | 0x80;
spin_unlock(&linear_map_hash_lock);
}
static void kernel_unmap_linear_page(unsigned long vaddr, unsigned long lmi)
{
unsigned long hash, hidx, slot;
unsigned long vsid = get_kernel_vsid(vaddr, mmu_kernel_ssize);
unsigned long vpn = hpt_vpn(vaddr, vsid, mmu_kernel_ssize);
hash = hpt_hash(vpn, PAGE_SHIFT, mmu_kernel_ssize);
spin_lock(&linear_map_hash_lock);
BUG_ON(!(linear_map_hash_slots[lmi] & 0x80));
hidx = linear_map_hash_slots[lmi] & 0x7f;
linear_map_hash_slots[lmi] = 0;
spin_unlock(&linear_map_hash_lock);
if (hidx & _PTEIDX_SECONDARY)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += hidx & _PTEIDX_GROUP_IX;
ppc_md.hpte_invalidate(slot, vpn, mmu_linear_psize, mmu_linear_psize,
mmu_kernel_ssize, 0);
}
void __kernel_map_pages(struct page *page, int numpages, int enable)
{
unsigned long flags, vaddr, lmi;
int i;
local_irq_save(flags);
for (i = 0; i < numpages; i++, page++) {
vaddr = (unsigned long)page_address(page);
lmi = __pa(vaddr) >> PAGE_SHIFT;
if (lmi >= linear_map_hash_count)
continue;
if (enable)
kernel_map_linear_page(vaddr, lmi);
else
kernel_unmap_linear_page(vaddr, lmi);
}
local_irq_restore(flags);
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
BUG_ON(first_memblock_base != 0);
ppc64_rma_size = min_t(u64, first_memblock_size, 0x40000000);
memblock_set_current_limit(ppc64_rma_size);
}
