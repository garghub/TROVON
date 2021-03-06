static int native_register_process_table(unsigned long base, unsigned long pg_sz,
unsigned long table_size)
{
unsigned long patb1 = base | table_size | PATB_GR;
partition_tb->patb1 = cpu_to_be64(patb1);
return 0;
}
static __ref void *early_alloc_pgtable(unsigned long size)
{
void *pt;
pt = __va(memblock_alloc_base(size, size, MEMBLOCK_ALLOC_ANYWHERE));
memset(pt, 0, size);
return pt;
}
int radix__map_kernel_page(unsigned long ea, unsigned long pa,
pgprot_t flags,
unsigned int map_page_size)
{
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
BUILD_BUG_ON(TASK_SIZE_USER64 > RADIX_PGTABLE_RANGE);
if (slab_is_available()) {
pgdp = pgd_offset_k(ea);
pudp = pud_alloc(&init_mm, pgdp, ea);
if (!pudp)
return -ENOMEM;
if (map_page_size == PUD_SIZE) {
ptep = (pte_t *)pudp;
goto set_the_pte;
}
pmdp = pmd_alloc(&init_mm, pudp, ea);
if (!pmdp)
return -ENOMEM;
if (map_page_size == PMD_SIZE) {
ptep = pmdp_ptep(pmdp);
goto set_the_pte;
}
ptep = pte_alloc_kernel(pmdp, ea);
if (!ptep)
return -ENOMEM;
} else {
pgdp = pgd_offset_k(ea);
if (pgd_none(*pgdp)) {
pudp = early_alloc_pgtable(PUD_TABLE_SIZE);
BUG_ON(pudp == NULL);
pgd_populate(&init_mm, pgdp, pudp);
}
pudp = pud_offset(pgdp, ea);
if (map_page_size == PUD_SIZE) {
ptep = (pte_t *)pudp;
goto set_the_pte;
}
if (pud_none(*pudp)) {
pmdp = early_alloc_pgtable(PMD_TABLE_SIZE);
BUG_ON(pmdp == NULL);
pud_populate(&init_mm, pudp, pmdp);
}
pmdp = pmd_offset(pudp, ea);
if (map_page_size == PMD_SIZE) {
ptep = pmdp_ptep(pmdp);
goto set_the_pte;
}
if (!pmd_present(*pmdp)) {
ptep = early_alloc_pgtable(PAGE_SIZE);
BUG_ON(ptep == NULL);
pmd_populate_kernel(&init_mm, pmdp, ptep);
}
ptep = pte_offset_kernel(pmdp, ea);
}
set_the_pte:
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT, flags));
smp_wmb();
return 0;
}
static void __init radix_init_pgtable(void)
{
int loop_count;
u64 base, end, start_addr;
unsigned long rts_field;
struct memblock_region *reg;
unsigned long linear_page_size;
mmu_slb_size = 0;
loop_count = 0;
for_each_memblock(memory, reg) {
start_addr = reg->base;
redo:
if (loop_count < 1 && mmu_psize_defs[MMU_PAGE_1G].shift)
linear_page_size = PUD_SIZE;
else if (loop_count < 2 && mmu_psize_defs[MMU_PAGE_2M].shift)
linear_page_size = PMD_SIZE;
else
linear_page_size = PAGE_SIZE;
base = _ALIGN_UP(start_addr, linear_page_size);
end = _ALIGN_DOWN(reg->base + reg->size, linear_page_size);
pr_info("Mapping range 0x%lx - 0x%lx with 0x%lx\n",
(unsigned long)base, (unsigned long)end,
linear_page_size);
while (base < end) {
radix__map_kernel_page((unsigned long)__va(base),
base, PAGE_KERNEL_X,
linear_page_size);
base += linear_page_size;
}
if (end < reg->base + reg->size) {
start_addr = end;
loop_count++;
goto redo;
}
}
BUILD_BUG_ON_MSG((PRTB_SIZE_SHIFT > 36), "Process table size too large.");
process_tb = early_alloc_pgtable(1UL << PRTB_SIZE_SHIFT);
rts_field = radix__get_tree_size();
process_tb->prtb0 = cpu_to_be64(rts_field | __pa(init_mm.pgd) | RADIX_PGD_INDEX_SIZE);
register_process_table(__pa(process_tb), 0, PRTB_SIZE_SHIFT - 12);
pr_info("Process table %p and radix root for kernel: %p\n", process_tb, init_mm.pgd);
}
static void __init radix_init_partition_table(void)
{
unsigned long rts_field, dw0;
mmu_partition_table_init();
rts_field = radix__get_tree_size();
dw0 = rts_field | __pa(init_mm.pgd) | RADIX_PGD_INDEX_SIZE | PATB_HR;
mmu_partition_table_set_entry(0, dw0, 0);
pr_info("Initializing Radix MMU\n");
pr_info("Partition table %p\n", partition_tb);
}
void __init radix_init_native(void)
{
register_process_table = native_register_process_table;
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
case 0x15:
idx = MMU_PAGE_2M;
break;
case 0x1e:
idx = MMU_PAGE_1G;
break;
}
return idx;
}
static int __init radix_dt_scan_page_sizes(unsigned long node,
const char *uname, int depth,
void *data)
{
int size = 0;
int shift, idx;
unsigned int ap;
const __be32 *prop;
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
if (type == NULL || strcmp(type, "cpu") != 0)
return 0;
prop = of_get_flat_dt_prop(node, "ibm,processor-radix-AP-encodings", &size);
if (!prop)
return 0;
pr_info("Page sizes from device-tree:\n");
for (; size >= 4; size -= 4, ++prop) {
struct mmu_psize_def *def;
shift = be32_to_cpu(prop[0]) & ~(0xe << 28);
ap = be32_to_cpu(prop[0]) >> 29;
pr_info("Page size shift = %d AP=0x%x\n", shift, ap);
idx = get_idx_from_shift(shift);
if (idx < 0)
continue;
def = &mmu_psize_defs[idx];
def->shift = shift;
def->ap = ap;
}
cur_cpu_spec->mmu_features &= ~MMU_FTR_NO_SLBIE_B;
return 1;
}
void __init radix__early_init_devtree(void)
{
int rc;
rc = of_scan_flat_dt(radix_dt_scan_page_sizes, NULL);
if (rc != 0)
goto found;
mmu_psize_defs[MMU_PAGE_4K].shift = 12;
mmu_psize_defs[MMU_PAGE_4K].ap = 0x0;
mmu_psize_defs[MMU_PAGE_64K].shift = 16;
mmu_psize_defs[MMU_PAGE_64K].ap = 0x5;
found:
#ifdef CONFIG_SPARSEMEM_VMEMMAP
if (mmu_psize_defs[MMU_PAGE_2M].shift) {
mmu_vmemmap_psize = MMU_PAGE_2M;
}
#endif
return;
}
static void update_hid_for_radix(void)
{
unsigned long hid0;
unsigned long rb = 3UL << PPC_BITLSHIFT(53);
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(1), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
hid0 = mfspr(SPRN_HID0);
hid0 |= HID0_POWER9_RADIX;
mtspr(SPRN_HID0, hid0);
asm volatile("isync": : :"memory");
while (!(mfspr(SPRN_HID0) & HID0_POWER9_RADIX))
cpu_relax();
}
static void radix_init_amor(void)
{
mtspr(SPRN_AMOR, (3ul << 62));
}
static void radix_init_iamr(void)
{
unsigned long iamr;
if (cpu_has_feature(CPU_FTR_POWER9_DD1))
iamr = 0;
else
iamr = (1ul << 62);
mtspr(SPRN_IAMR, iamr);
}
void __init radix__early_init_mmu(void)
{
unsigned long lpcr;
#ifdef CONFIG_PPC_64K_PAGES
mmu_virtual_psize = MMU_PAGE_64K;
#else
mmu_virtual_psize = MMU_PAGE_4K;
#endif
#ifdef CONFIG_SPARSEMEM_VMEMMAP
mmu_vmemmap_psize = mmu_virtual_psize;
#endif
__pte_index_size = RADIX_PTE_INDEX_SIZE;
__pmd_index_size = RADIX_PMD_INDEX_SIZE;
__pud_index_size = RADIX_PUD_INDEX_SIZE;
__pgd_index_size = RADIX_PGD_INDEX_SIZE;
__pmd_cache_index = RADIX_PMD_INDEX_SIZE;
__pte_table_size = RADIX_PTE_TABLE_SIZE;
__pmd_table_size = RADIX_PMD_TABLE_SIZE;
__pud_table_size = RADIX_PUD_TABLE_SIZE;
__pgd_table_size = RADIX_PGD_TABLE_SIZE;
__pmd_val_bits = RADIX_PMD_VAL_BITS;
__pud_val_bits = RADIX_PUD_VAL_BITS;
__pgd_val_bits = RADIX_PGD_VAL_BITS;
__kernel_virt_start = RADIX_KERN_VIRT_START;
__kernel_virt_size = RADIX_KERN_VIRT_SIZE;
__vmalloc_start = RADIX_VMALLOC_START;
__vmalloc_end = RADIX_VMALLOC_END;
vmemmap = (struct page *)RADIX_VMEMMAP_BASE;
ioremap_bot = IOREMAP_BASE;
#ifdef CONFIG_PCI
pci_io_base = ISA_IO_BASE;
#endif
__pte_frag_nr = H_PTE_FRAG_NR;
__pte_frag_size_shift = H_PTE_FRAG_SIZE_SHIFT;
if (!firmware_has_feature(FW_FEATURE_LPAR)) {
radix_init_native();
if (cpu_has_feature(CPU_FTR_POWER9_DD1))
update_hid_for_radix();
lpcr = mfspr(SPRN_LPCR);
mtspr(SPRN_LPCR, lpcr | LPCR_UPRT | LPCR_HR);
radix_init_partition_table();
radix_init_amor();
}
memblock_set_current_limit(MEMBLOCK_ALLOC_ANYWHERE);
radix_init_iamr();
radix_init_pgtable();
}
void radix__early_init_mmu_secondary(void)
{
unsigned long lpcr;
if (!firmware_has_feature(FW_FEATURE_LPAR)) {
if (cpu_has_feature(CPU_FTR_POWER9_DD1))
update_hid_for_radix();
lpcr = mfspr(SPRN_LPCR);
mtspr(SPRN_LPCR, lpcr | LPCR_UPRT | LPCR_HR);
mtspr(SPRN_PTCR,
__pa(partition_tb) | (PATB_SIZE_SHIFT - 12));
radix_init_amor();
}
radix_init_iamr();
}
void radix__mmu_cleanup_all(void)
{
unsigned long lpcr;
if (!firmware_has_feature(FW_FEATURE_LPAR)) {
lpcr = mfspr(SPRN_LPCR);
mtspr(SPRN_LPCR, lpcr & ~LPCR_UPRT);
mtspr(SPRN_PTCR, 0);
radix__flush_tlb_all();
}
}
void radix__setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
BUG_ON(first_memblock_base != 0);
ppc64_rma_size = min_t(u64, first_memblock_size, 0x40000000);
memblock_set_current_limit(first_memblock_base + first_memblock_size);
}
int __meminit radix__vmemmap_create_mapping(unsigned long start,
unsigned long page_size,
unsigned long phys)
{
unsigned long flags = _PAGE_PRESENT | _PAGE_ACCESSED | _PAGE_KERNEL_RW;
BUG_ON(radix__map_kernel_page(start, phys, __pgprot(flags), page_size));
return 0;
}
void radix__vmemmap_remove_mapping(unsigned long start, unsigned long page_size)
{
}
unsigned long radix__pmd_hugepage_update(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp, unsigned long clr,
unsigned long set)
{
unsigned long old;
#ifdef CONFIG_DEBUG_VM
WARN_ON(!radix__pmd_trans_huge(*pmdp));
assert_spin_locked(&mm->page_table_lock);
#endif
old = radix__pte_update(mm, addr, (pte_t *)pmdp, clr, set, 1);
trace_hugepage_update(addr, old, clr, set);
return old;
}
pmd_t radix__pmdp_collapse_flush(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_t pmd;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
VM_BUG_ON(radix__pmd_trans_huge(*pmdp));
pmd = *pmdp;
pmd_clear(pmdp);
kick_all_cpus_sync();
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
return pmd;
}
void radix__pgtable_trans_huge_deposit(struct mm_struct *mm, pmd_t *pmdp,
pgtable_t pgtable)
{
struct list_head *lh = (struct list_head *) pgtable;
assert_spin_locked(pmd_lockptr(mm, pmdp));
if (!pmd_huge_pte(mm, pmdp))
INIT_LIST_HEAD(lh);
else
list_add(lh, (struct list_head *) pmd_huge_pte(mm, pmdp));
pmd_huge_pte(mm, pmdp) = pgtable;
}
pgtable_t radix__pgtable_trans_huge_withdraw(struct mm_struct *mm, pmd_t *pmdp)
{
pte_t *ptep;
pgtable_t pgtable;
struct list_head *lh;
assert_spin_locked(pmd_lockptr(mm, pmdp));
pgtable = pmd_huge_pte(mm, pmdp);
lh = (struct list_head *) pgtable;
if (list_empty(lh))
pmd_huge_pte(mm, pmdp) = NULL;
else {
pmd_huge_pte(mm, pmdp) = (pgtable_t) lh->next;
list_del(lh);
}
ptep = (pte_t *) pgtable;
*ptep = __pte(0);
ptep++;
*ptep = __pte(0);
return pgtable;
}
pmd_t radix__pmdp_huge_get_and_clear(struct mm_struct *mm,
unsigned long addr, pmd_t *pmdp)
{
pmd_t old_pmd;
unsigned long old;
old = radix__pmd_hugepage_update(mm, addr, pmdp, ~0UL, 0);
old_pmd = __pmd(old);
kick_all_cpus_sync();
return old_pmd;
}
int radix__has_transparent_hugepage(void)
{
if (mmu_psize_defs[MMU_PAGE_2M].shift == PMD_SHIFT)
return 1;
return 0;
}
