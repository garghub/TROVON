void __iomem * __ioremap_at(phys_addr_t pa, void *ea, unsigned long size,
unsigned long flags)
{
unsigned long i;
if ((flags & _PAGE_PRESENT) == 0)
flags |= pgprot_val(PAGE_KERNEL);
if (flags & H_PAGE_4K_PFN)
return NULL;
WARN_ON(pa & ~PAGE_MASK);
WARN_ON(((unsigned long)ea) & ~PAGE_MASK);
WARN_ON(size & ~PAGE_MASK);
for (i = 0; i < size; i += PAGE_SIZE)
if (map_kernel_page((unsigned long)ea+i, pa+i, flags))
return NULL;
return (void __iomem *)ea;
}
void __iounmap_at(void *ea, unsigned long size)
{
WARN_ON(((unsigned long)ea) & ~PAGE_MASK);
WARN_ON(size & ~PAGE_MASK);
unmap_kernel_range((unsigned long)ea, size);
}
void __iomem * __ioremap_caller(phys_addr_t addr, unsigned long size,
unsigned long flags, void *caller)
{
phys_addr_t paligned;
void __iomem *ret;
paligned = addr & PAGE_MASK;
size = PAGE_ALIGN(addr + size) - paligned;
if ((size == 0) || (paligned == 0))
return NULL;
if (slab_is_available()) {
struct vm_struct *area;
area = __get_vm_area_caller(size, VM_IOREMAP,
ioremap_bot, IOREMAP_END,
caller);
if (area == NULL)
return NULL;
area->phys_addr = paligned;
ret = __ioremap_at(paligned, area->addr, size, flags);
if (!ret)
vunmap(area->addr);
} else {
ret = __ioremap_at(paligned, (void *)ioremap_bot, size, flags);
if (ret)
ioremap_bot += size;
}
if (ret)
ret += addr & ~PAGE_MASK;
return ret;
}
void __iomem * __ioremap(phys_addr_t addr, unsigned long size,
unsigned long flags)
{
return __ioremap_caller(addr, size, flags, __builtin_return_address(0));
}
void __iomem * ioremap(phys_addr_t addr, unsigned long size)
{
unsigned long flags = pgprot_val(pgprot_noncached(__pgprot(0)));
void *caller = __builtin_return_address(0);
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iomem * ioremap_wc(phys_addr_t addr, unsigned long size)
{
unsigned long flags = pgprot_val(pgprot_noncached_wc(__pgprot(0)));
void *caller = __builtin_return_address(0);
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iomem * ioremap_prot(phys_addr_t addr, unsigned long size,
unsigned long flags)
{
void *caller = __builtin_return_address(0);
if (flags & _PAGE_WRITE)
flags |= _PAGE_DIRTY;
flags &= ~_PAGE_EXEC;
#if defined(CONFIG_PPC_BOOK3S_64)
flags |= _PAGE_PRIVILEGED;
#else
flags &= ~_PAGE_USER;
#endif
#ifdef _PAGE_BAP_SR
flags |= _PAGE_BAP_SR;
#endif
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iounmap(volatile void __iomem *token)
{
void *addr;
if (!slab_is_available())
return;
addr = (void *) ((unsigned long __force)
PCI_FIX_ADDR(token) & PAGE_MASK);
if ((unsigned long)addr < ioremap_bot) {
printk(KERN_WARNING "Attempt to iounmap early bolted mapping"
" at 0x%p\n", addr);
return;
}
vunmap(addr);
}
void iounmap(volatile void __iomem *token)
{
if (ppc_md.iounmap)
ppc_md.iounmap(token);
else
__iounmap(token);
}
struct page *pgd_page(pgd_t pgd)
{
if (pgd_huge(pgd))
return pte_page(pgd_pte(pgd));
return virt_to_page(pgd_page_vaddr(pgd));
}
struct page *pud_page(pud_t pud)
{
if (pud_huge(pud))
return pte_page(pud_pte(pud));
return virt_to_page(pud_page_vaddr(pud));
}
struct page *pmd_page(pmd_t pmd)
{
if (pmd_trans_huge(pmd) || pmd_huge(pmd))
return pte_page(pmd_pte(pmd));
return virt_to_page(pmd_page_vaddr(pmd));
}
static pte_t *get_from_cache(struct mm_struct *mm)
{
void *pte_frag, *ret;
spin_lock(&mm->page_table_lock);
ret = mm->context.pte_frag;
if (ret) {
pte_frag = ret + PTE_FRAG_SIZE;
if (((unsigned long)pte_frag & ~PAGE_MASK) == 0)
pte_frag = NULL;
mm->context.pte_frag = pte_frag;
}
spin_unlock(&mm->page_table_lock);
return (pte_t *)ret;
}
static pte_t *__alloc_for_cache(struct mm_struct *mm, int kernel)
{
void *ret = NULL;
struct page *page = alloc_page(GFP_KERNEL | __GFP_NOTRACK | __GFP_ZERO);
if (!page)
return NULL;
if (!kernel && !pgtable_page_ctor(page)) {
__free_page(page);
return NULL;
}
ret = page_address(page);
spin_lock(&mm->page_table_lock);
if (likely(!mm->context.pte_frag)) {
set_page_count(page, PTE_FRAG_NR);
mm->context.pte_frag = ret + PTE_FRAG_SIZE;
}
spin_unlock(&mm->page_table_lock);
return (pte_t *)ret;
}
pte_t *pte_fragment_alloc(struct mm_struct *mm, unsigned long vmaddr, int kernel)
{
pte_t *pte;
pte = get_from_cache(mm);
if (pte)
return pte;
return __alloc_for_cache(mm, kernel);
}
void pte_fragment_free(unsigned long *table, int kernel)
{
struct page *page = virt_to_page(table);
if (put_page_testzero(page)) {
if (!kernel)
pgtable_page_dtor(page);
free_hot_cold_page(page, 0);
}
}
void pgtable_free_tlb(struct mmu_gather *tlb, void *table, int shift)
{
unsigned long pgf = (unsigned long)table;
BUG_ON(shift > MAX_PGTABLE_INDEX_SIZE);
pgf |= shift;
tlb_remove_table(tlb, (void *)pgf);
}
void __tlb_remove_table(void *_table)
{
void *table = (void *)((unsigned long)_table & ~MAX_PGTABLE_INDEX_SIZE);
unsigned shift = (unsigned long)_table & MAX_PGTABLE_INDEX_SIZE;
if (!shift)
pte_fragment_free(table, 0);
else {
BUG_ON(shift > MAX_PGTABLE_INDEX_SIZE);
kmem_cache_free(PGT_CACHE(shift), table);
}
}
void pgtable_free_tlb(struct mmu_gather *tlb, void *table, int shift)
{
if (!shift) {
pte_fragment_free(table, 0);
} else {
BUG_ON(shift > MAX_PGTABLE_INDEX_SIZE);
kmem_cache_free(PGT_CACHE(shift), table);
}
}
void __init mmu_partition_table_init(void)
{
unsigned long patb_size = 1UL << PATB_SIZE_SHIFT;
BUILD_BUG_ON_MSG((PATB_SIZE_SHIFT > 36), "Partition table size too large.");
partition_tb = __va(memblock_alloc_base(patb_size, patb_size,
MEMBLOCK_ALLOC_ANYWHERE));
memset((void *)partition_tb, 0, patb_size);
mtspr(SPRN_PTCR, __pa(partition_tb) | (PATB_SIZE_SHIFT - 12));
}
void mmu_partition_table_set_entry(unsigned int lpid, unsigned long dw0,
unsigned long dw1)
{
partition_tb[lpid].patb0 = cpu_to_be64(dw0);
partition_tb[lpid].patb1 = cpu_to_be64(dw1);
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE_5(%0,%1,2,0,0) : :
"r" (TLBIEL_INVAL_SET_LPID), "r" (lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
}
