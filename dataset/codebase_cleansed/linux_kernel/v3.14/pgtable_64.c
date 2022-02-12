static void *early_alloc_pgtable(unsigned long size)
{
void *pt;
if (init_bootmem_done)
pt = __alloc_bootmem(size, size, __pa(MAX_DMA_ADDRESS));
else
pt = __va(memblock_alloc_base(size, size,
__pa(MAX_DMA_ADDRESS)));
memset(pt, 0, size);
return pt;
}
int map_kernel_page(unsigned long ea, unsigned long pa, int flags)
{
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
if (slab_is_available()) {
pgdp = pgd_offset_k(ea);
pudp = pud_alloc(&init_mm, pgdp, ea);
if (!pudp)
return -ENOMEM;
pmdp = pmd_alloc(&init_mm, pudp, ea);
if (!pmdp)
return -ENOMEM;
ptep = pte_alloc_kernel(pmdp, ea);
if (!ptep)
return -ENOMEM;
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
} else {
#ifdef CONFIG_PPC_MMU_NOHASH
pgdp = pgd_offset_k(ea);
#ifdef PUD_TABLE_SIZE
if (pgd_none(*pgdp)) {
pudp = early_alloc_pgtable(PUD_TABLE_SIZE);
BUG_ON(pudp == NULL);
pgd_populate(&init_mm, pgdp, pudp);
}
#endif
pudp = pud_offset(pgdp, ea);
if (pud_none(*pudp)) {
pmdp = early_alloc_pgtable(PMD_TABLE_SIZE);
BUG_ON(pmdp == NULL);
pud_populate(&init_mm, pudp, pmdp);
}
pmdp = pmd_offset(pudp, ea);
if (!pmd_present(*pmdp)) {
ptep = early_alloc_pgtable(PAGE_SIZE);
BUG_ON(ptep == NULL);
pmd_populate_kernel(&init_mm, pmdp, ptep);
}
ptep = pte_offset_kernel(pmdp, ea);
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
#else
if (htab_bolt_mapping(ea, ea + PAGE_SIZE, pa, flags,
mmu_io_psize, mmu_kernel_ssize)) {
printk(KERN_ERR "Failed to do bolted mapping IO "
"memory at %016lx !\n", pa);
return -ENOMEM;
}
#endif
}
#ifdef CONFIG_PPC_BOOK3E_64
mb();
#else
smp_wmb();
#endif
return 0;
}
void __iomem * __ioremap_at(phys_addr_t pa, void *ea, unsigned long size,
unsigned long flags)
{
unsigned long i;
if ((flags & _PAGE_PRESENT) == 0)
flags |= pgprot_val(PAGE_KERNEL);
if (flags & _PAGE_NO_CACHE)
flags &= ~_PAGE_COHERENT;
if (flags & _PAGE_4K_PFN)
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
if (mem_init_done) {
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
unsigned long flags = _PAGE_NO_CACHE | _PAGE_GUARDED;
void *caller = __builtin_return_address(0);
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iomem * ioremap_wc(phys_addr_t addr, unsigned long size)
{
unsigned long flags = _PAGE_NO_CACHE;
void *caller = __builtin_return_address(0);
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iomem * ioremap_prot(phys_addr_t addr, unsigned long size,
unsigned long flags)
{
void *caller = __builtin_return_address(0);
if (flags & _PAGE_RW)
flags |= _PAGE_DIRTY;
flags &= ~(_PAGE_USER | _PAGE_EXEC);
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
if (!mem_init_done)
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
struct page *pmd_page(pmd_t pmd)
{
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
if (pmd_trans_huge(pmd))
return pfn_to_page(pmd_pfn(pmd));
#endif
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
struct page *page = alloc_page(GFP_KERNEL | __GFP_NOTRACK |
__GFP_REPEAT | __GFP_ZERO);
if (!page)
return NULL;
if (!kernel && !pgtable_page_ctor(page)) {
__free_page(page);
return NULL;
}
ret = page_address(page);
spin_lock(&mm->page_table_lock);
if (likely(!mm->context.pte_frag)) {
atomic_set(&page->_count, PTE_FRAG_NR);
mm->context.pte_frag = ret + PTE_FRAG_SIZE;
}
spin_unlock(&mm->page_table_lock);
return (pte_t *)ret;
}
pte_t *page_table_alloc(struct mm_struct *mm, unsigned long vmaddr, int kernel)
{
pte_t *pte;
pte = get_from_cache(mm);
if (pte)
return pte;
return __alloc_for_cache(mm, kernel);
}
void page_table_free(struct mm_struct *mm, unsigned long *table, int kernel)
{
struct page *page = virt_to_page(table);
if (put_page_testzero(page)) {
if (!kernel)
pgtable_page_dtor(page);
free_hot_cold_page(page, 0);
}
}
static void page_table_free_rcu(void *table)
{
struct page *page = virt_to_page(table);
if (put_page_testzero(page)) {
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
page_table_free_rcu(table);
else {
BUG_ON(shift > MAX_PGTABLE_INDEX_SIZE);
kmem_cache_free(PGT_CACHE(shift), table);
}
}
void pgtable_free_tlb(struct mmu_gather *tlb, void *table, int shift)
{
if (!shift) {
struct page *page = virt_to_page(table);
if (put_page_testzero(page)) {
pgtable_page_dtor(page);
free_hot_cold_page(page, 0);
}
} else {
BUG_ON(shift > MAX_PGTABLE_INDEX_SIZE);
kmem_cache_free(PGT_CACHE(shift), table);
}
}
int pmdp_set_access_flags(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp, pmd_t entry, int dirty)
{
int changed;
#ifdef CONFIG_DEBUG_VM
WARN_ON(!pmd_trans_huge(*pmdp));
assert_spin_locked(&vma->vm_mm->page_table_lock);
#endif
changed = !pmd_same(*(pmdp), entry);
if (changed) {
__ptep_set_access_flags(pmdp_ptep(pmdp), pmd_pte(entry));
}
return changed;
}
unsigned long pmd_hugepage_update(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp, unsigned long clr,
unsigned long set)
{
unsigned long old, tmp;
#ifdef CONFIG_DEBUG_VM
WARN_ON(!pmd_trans_huge(*pmdp));
assert_spin_locked(&mm->page_table_lock);
#endif
#ifdef PTE_ATOMIC_UPDATES
__asm__ __volatile__(
"1: ldarx %0,0,%3\n\
andi. %1,%0,%6\n\
bne- 1b \n\
andc %1,%0,%4 \n\
or %1,%1,%7\n\
stdcx. %1,0,%3 \n\
bne- 1b"
: "=&r" (old), "=&r" (tmp), "=m" (*pmdp)
: "r" (pmdp), "r" (clr), "m" (*pmdp), "i" (_PAGE_BUSY), "r" (set)
: "cc" );
#else
old = pmd_val(*pmdp);
*pmdp = __pmd((old & ~clr) | set);
#endif
if (old & _PAGE_HASHPTE)
hpte_do_hugepage_flush(mm, addr, pmdp);
return old;
}
pmd_t pmdp_clear_flush(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_t pmd;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
if (pmd_trans_huge(*pmdp)) {
pmd = pmdp_get_and_clear(vma->vm_mm, address, pmdp);
} else {
pmd = *pmdp;
pmd_clear(pmdp);
kick_all_cpus_sync();
flush_tlb_pmd_range(vma->vm_mm, &pmd, address);
}
return pmd;
}
int pmdp_test_and_clear_young(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp)
{
return __pmdp_test_and_clear_young(vma->vm_mm, address, pmdp);
}
int pmdp_clear_flush_young(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp)
{
return __pmdp_test_and_clear_young(vma->vm_mm, address, pmdp);
}
void pmdp_splitting_flush(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp)
{
unsigned long old, tmp;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
#ifdef CONFIG_DEBUG_VM
WARN_ON(!pmd_trans_huge(*pmdp));
assert_spin_locked(&vma->vm_mm->page_table_lock);
#endif
#ifdef PTE_ATOMIC_UPDATES
__asm__ __volatile__(
"1: ldarx %0,0,%3\n\
andi. %1,%0,%6\n\
bne- 1b \n\
ori %1,%0,%4 \n\
stdcx. %1,0,%3 \n\
bne- 1b"
: "=&r" (old), "=&r" (tmp), "=m" (*pmdp)
: "r" (pmdp), "i" (_PAGE_SPLITTING), "m" (*pmdp), "i" (_PAGE_BUSY)
: "cc" );
#else
old = pmd_val(*pmdp);
*pmdp = __pmd(old | _PAGE_SPLITTING);
#endif
if (!(old & _PAGE_SPLITTING)) {
if (old & _PAGE_HASHPTE)
hpte_do_hugepage_flush(vma->vm_mm, address, pmdp);
}
}
void pgtable_trans_huge_deposit(struct mm_struct *mm, pmd_t *pmdp,
pgtable_t pgtable)
{
pgtable_t *pgtable_slot;
assert_spin_locked(&mm->page_table_lock);
pgtable_slot = (pgtable_t *)pmdp + PTRS_PER_PMD;
*pgtable_slot = pgtable;
smp_wmb();
}
pgtable_t pgtable_trans_huge_withdraw(struct mm_struct *mm, pmd_t *pmdp)
{
pgtable_t pgtable;
pgtable_t *pgtable_slot;
assert_spin_locked(&mm->page_table_lock);
pgtable_slot = (pgtable_t *)pmdp + PTRS_PER_PMD;
pgtable = *pgtable_slot;
*pgtable_slot = NULL;
memset(pgtable, 0, PTE_FRAG_SIZE);
return pgtable;
}
void set_pmd_at(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp, pmd_t pmd)
{
#ifdef CONFIG_DEBUG_VM
WARN_ON(pmd_val(*pmdp) & _PAGE_PRESENT);
assert_spin_locked(&mm->page_table_lock);
WARN_ON(!pmd_trans_huge(pmd));
#endif
return set_pte_at(mm, addr, pmdp_ptep(pmdp), pmd_pte(pmd));
}
void pmdp_invalidate(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_hugepage_update(vma->vm_mm, address, pmdp, _PAGE_PRESENT, 0);
}
void hpte_do_hugepage_flush(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp)
{
int ssize, i;
unsigned long s_addr;
int max_hpte_count;
unsigned int psize, valid;
unsigned char *hpte_slot_array;
unsigned long hidx, vpn, vsid, hash, shift, slot;
s_addr = addr & HPAGE_PMD_MASK;
hpte_slot_array = get_hpte_slot_array(pmdp);
if (!hpte_slot_array)
return;
psize = get_slice_psize(mm, s_addr);
if (ppc_md.hugepage_invalidate)
return ppc_md.hugepage_invalidate(mm, hpte_slot_array,
s_addr, psize);
shift = mmu_psize_defs[psize].shift;
max_hpte_count = HPAGE_PMD_SIZE >> shift;
for (i = 0; i < max_hpte_count; i++) {
valid = hpte_valid(hpte_slot_array, i);
if (!valid)
continue;
hidx = hpte_hash_index(hpte_slot_array, i);
addr = s_addr + (i * (1ul << shift));
if (!is_kernel_addr(addr)) {
ssize = user_segment_size(addr);
vsid = get_vsid(mm->context.id, addr, ssize);
WARN_ON(vsid == 0);
} else {
vsid = get_kernel_vsid(addr, mmu_kernel_ssize);
ssize = mmu_kernel_ssize;
}
vpn = hpt_vpn(addr, vsid, ssize);
hash = hpt_hash(vpn, shift, ssize);
if (hidx & _PTEIDX_SECONDARY)
hash = ~hash;
slot = (hash & htab_hash_mask) * HPTES_PER_GROUP;
slot += hidx & _PTEIDX_GROUP_IX;
ppc_md.hpte_invalidate(slot, vpn, psize,
MMU_PAGE_16M, ssize, 0);
}
}
static pmd_t pmd_set_protbits(pmd_t pmd, pgprot_t pgprot)
{
pmd_val(pmd) |= pgprot_val(pgprot);
return pmd;
}
pmd_t pfn_pmd(unsigned long pfn, pgprot_t pgprot)
{
pmd_t pmd;
pmd_val(pmd) = pfn << PTE_RPN_SHIFT;
pmd_val(pmd) |= _PAGE_THP_HUGE;
pmd = pmd_set_protbits(pmd, pgprot);
return pmd;
}
pmd_t mk_pmd(struct page *page, pgprot_t pgprot)
{
return pfn_pmd(page_to_pfn(page), pgprot);
}
pmd_t pmd_modify(pmd_t pmd, pgprot_t newprot)
{
pmd_val(pmd) &= _HPAGE_CHG_MASK;
pmd = pmd_set_protbits(pmd, newprot);
return pmd;
}
void update_mmu_cache_pmd(struct vm_area_struct *vma, unsigned long addr,
pmd_t *pmd)
{
return;
}
pmd_t pmdp_get_and_clear(struct mm_struct *mm,
unsigned long addr, pmd_t *pmdp)
{
pmd_t old_pmd;
pgtable_t pgtable;
unsigned long old;
pgtable_t *pgtable_slot;
old = pmd_hugepage_update(mm, addr, pmdp, ~0UL, 0);
old_pmd = __pmd(old);
pgtable_slot = (pgtable_t *)pmdp + PTRS_PER_PMD;
pgtable = *pgtable_slot;
memset(pgtable, 0, PTE_FRAG_SIZE);
return old_pmd;
}
int has_transparent_hugepage(void)
{
if (!mmu_has_feature(MMU_FTR_16M_PAGE))
return 0;
if (mmu_psize_defs[MMU_PAGE_16M].shift != PMD_SHIFT)
return 0;
if (mmu_psize_defs[MMU_PAGE_64K].shift &&
(mmu_psize_defs[MMU_PAGE_64K].penc[MMU_PAGE_16M] == -1))
return 0;
if (mmu_psize_defs[MMU_PAGE_4K].penc[MMU_PAGE_16M] == -1)
return 0;
return 1;
}
