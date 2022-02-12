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
flush_pmd_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
}
return changed;
}
int pmdp_test_and_clear_young(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp)
{
return __pmdp_test_and_clear_young(vma->vm_mm, address, pmdp);
}
void set_pmd_at(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp, pmd_t pmd)
{
#ifdef CONFIG_DEBUG_VM
WARN_ON(pte_present(pmd_pte(*pmdp)) && !pte_protnone(pmd_pte(*pmdp)));
assert_spin_locked(&mm->page_table_lock);
WARN_ON(!pmd_trans_huge(pmd));
#endif
trace_hugepage_set_pmd(addr, pmd_val(pmd));
return set_pte_at(mm, addr, pmdp_ptep(pmdp), pmd_pte(pmd));
}
void pmdp_invalidate(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_hugepage_update(vma->vm_mm, address, pmdp, _PAGE_PRESENT, 0);
flush_pmd_tlb_range(vma, address, address + HPAGE_PMD_SIZE);
kick_all_cpus_sync();
}
static pmd_t pmd_set_protbits(pmd_t pmd, pgprot_t pgprot)
{
return __pmd(pmd_val(pmd) | pgprot_val(pgprot));
}
pmd_t pfn_pmd(unsigned long pfn, pgprot_t pgprot)
{
unsigned long pmdv;
pmdv = (pfn << PAGE_SHIFT) & PTE_RPN_MASK;
return pmd_set_protbits(__pmd(pmdv), pgprot);
}
pmd_t mk_pmd(struct page *page, pgprot_t pgprot)
{
return pfn_pmd(page_to_pfn(page), pgprot);
}
pmd_t pmd_modify(pmd_t pmd, pgprot_t newprot)
{
unsigned long pmdv;
pmdv = pmd_val(pmd);
pmdv &= _HPAGE_CHG_MASK;
return pmd_set_protbits(__pmd(pmdv), newprot);
}
void update_mmu_cache_pmd(struct vm_area_struct *vma, unsigned long addr,
pmd_t *pmd)
{
return;
}
