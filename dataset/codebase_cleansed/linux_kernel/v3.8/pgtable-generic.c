int ptep_set_access_flags(struct vm_area_struct *vma,
unsigned long address, pte_t *ptep,
pte_t entry, int dirty)
{
int changed = !pte_same(*ptep, entry);
if (changed) {
set_pte_at(vma->vm_mm, address, ptep, entry);
flush_tlb_fix_spurious_fault(vma, address);
}
return changed;
}
int pmdp_set_access_flags(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp,
pmd_t entry, int dirty)
{
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
int changed = !pmd_same(*pmdp, entry);
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
if (changed) {
set_pmd_at(vma->vm_mm, address, pmdp, entry);
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
}
return changed;
#else
BUG();
return 0;
#endif
}
int ptep_clear_flush_young(struct vm_area_struct *vma,
unsigned long address, pte_t *ptep)
{
int young;
young = ptep_test_and_clear_young(vma, address, ptep);
if (young)
flush_tlb_page(vma, address);
return young;
}
int pmdp_clear_flush_young(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp)
{
int young;
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
#else
BUG();
#endif
young = pmdp_test_and_clear_young(vma, address, pmdp);
if (young)
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
return young;
}
pte_t ptep_clear_flush(struct vm_area_struct *vma, unsigned long address,
pte_t *ptep)
{
pte_t pte;
pte = ptep_get_and_clear((vma)->vm_mm, address, ptep);
if (pte_accessible(pte))
flush_tlb_page(vma, address);
return pte;
}
pmd_t pmdp_clear_flush(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_t pmd;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
pmd = pmdp_get_and_clear(vma->vm_mm, address, pmdp);
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
return pmd;
}
void pmdp_splitting_flush(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_t pmd = pmd_mksplitting(*pmdp);
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
set_pmd_at(vma->vm_mm, address, pmdp, pmd);
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
}
void pgtable_trans_huge_deposit(struct mm_struct *mm, pgtable_t pgtable)
{
assert_spin_locked(&mm->page_table_lock);
if (!mm->pmd_huge_pte)
INIT_LIST_HEAD(&pgtable->lru);
else
list_add(&pgtable->lru, &mm->pmd_huge_pte->lru);
mm->pmd_huge_pte = pgtable;
}
pgtable_t pgtable_trans_huge_withdraw(struct mm_struct *mm)
{
pgtable_t pgtable;
assert_spin_locked(&mm->page_table_lock);
pgtable = mm->pmd_huge_pte;
if (list_empty(&pgtable->lru))
mm->pmd_huge_pte = NULL;
else {
mm->pmd_huge_pte = list_entry(pgtable->lru.next,
struct page, lru);
list_del(&pgtable->lru);
}
return pgtable;
}
void pmdp_invalidate(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
set_pmd_at(vma->vm_mm, address, pmdp, pmd_mknotpresent(*pmdp));
flush_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
}
