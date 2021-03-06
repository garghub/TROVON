static int do_adjust_pte(struct vm_area_struct *vma, unsigned long address,
unsigned long pfn, pte_t *ptep)
{
pte_t entry = *ptep;
int ret;
ret = pte_present(entry);
if (ret && (pte_val(entry) & L_PTE_MT_MASK) != shared_pte_mask) {
flush_cache_page(vma, address, pfn);
outer_flush_range((pfn << PAGE_SHIFT),
(pfn << PAGE_SHIFT) + PAGE_SIZE);
pte_val(entry) &= ~L_PTE_MT_MASK;
pte_val(entry) |= shared_pte_mask;
set_pte_at(vma->vm_mm, address, ptep, entry);
flush_tlb_page(vma, address);
}
return ret;
}
static inline void do_pte_lock(spinlock_t *ptl)
{
spin_lock_nested(ptl, SINGLE_DEPTH_NESTING);
}
static inline void do_pte_unlock(spinlock_t *ptl)
{
spin_unlock(ptl);
}
static inline void do_pte_lock(spinlock_t *ptl) {}
static inline void do_pte_unlock(spinlock_t *ptl) {}
static int adjust_pte(struct vm_area_struct *vma, unsigned long address,
unsigned long pfn)
{
spinlock_t *ptl;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
int ret;
pgd = pgd_offset(vma->vm_mm, address);
if (pgd_none_or_clear_bad(pgd))
return 0;
pud = pud_offset(pgd, address);
if (pud_none_or_clear_bad(pud))
return 0;
pmd = pmd_offset(pud, address);
if (pmd_none_or_clear_bad(pmd))
return 0;
ptl = pte_lockptr(vma->vm_mm, pmd);
pte = pte_offset_map(pmd, address);
do_pte_lock(ptl);
ret = do_adjust_pte(vma, address, pfn, pte);
do_pte_unlock(ptl);
pte_unmap(pte);
return ret;
}
static void
make_coherent(struct address_space *mapping, struct vm_area_struct *vma,
unsigned long addr, pte_t *ptep, unsigned long pfn)
{
struct mm_struct *mm = vma->vm_mm;
struct vm_area_struct *mpnt;
struct prio_tree_iter iter;
unsigned long offset;
pgoff_t pgoff;
int aliases = 0;
pgoff = vma->vm_pgoff + ((addr - vma->vm_start) >> PAGE_SHIFT);
flush_dcache_mmap_lock(mapping);
vma_prio_tree_foreach(mpnt, &iter, &mapping->i_mmap, pgoff, pgoff) {
if (mpnt->vm_mm != mm || mpnt == vma)
continue;
if (!(mpnt->vm_flags & VM_MAYSHARE))
continue;
offset = (pgoff - mpnt->vm_pgoff) << PAGE_SHIFT;
aliases += adjust_pte(mpnt, mpnt->vm_start + offset, pfn);
}
flush_dcache_mmap_unlock(mapping);
if (aliases)
do_adjust_pte(vma, addr, pfn, ptep);
}
void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr,
pte_t *ptep)
{
unsigned long pfn = pte_pfn(*ptep);
struct address_space *mapping;
struct page *page;
if (!pfn_valid(pfn))
return;
page = pfn_to_page(pfn);
if (page == ZERO_PAGE(0))
return;
mapping = page_mapping(page);
if (!test_and_set_bit(PG_dcache_clean, &page->flags))
__flush_dcache_page(mapping, page);
if (mapping) {
if (cache_is_vivt())
make_coherent(mapping, vma, addr, ptep, pfn);
else if (vma->vm_flags & VM_EXEC)
__flush_icache_all();
}
}
static int __init check_writebuffer(unsigned long *p1, unsigned long *p2)
{
register unsigned long zero = 0, one = 1, val;
local_irq_disable();
mb();
*p1 = one;
mb();
*p2 = zero;
mb();
val = *p1;
mb();
local_irq_enable();
return val != zero;
}
void __init check_writebuffer_bugs(void)
{
struct page *page;
const char *reason;
unsigned long v = 1;
printk(KERN_INFO "CPU: Testing write buffer coherency: ");
page = alloc_page(GFP_KERNEL);
if (page) {
unsigned long *p1, *p2;
pgprot_t prot = __pgprot_modify(PAGE_KERNEL,
L_PTE_MT_MASK, L_PTE_MT_BUFFERABLE);
p1 = vmap(&page, 1, VM_IOREMAP, prot);
p2 = vmap(&page, 1, VM_IOREMAP, prot);
if (p1 && p2) {
v = check_writebuffer(p1, p2);
reason = "enabling work-around";
} else {
reason = "unable to map memory\n";
}
vunmap(p1);
vunmap(p2);
put_page(page);
} else {
reason = "unable to grab page\n";
}
if (v) {
printk("failed, %s\n", reason);
shared_pte_mask = L_PTE_MT_UNCACHED;
} else {
printk("ok\n");
}
}
