static inline bool check_pmd(struct page_vma_mapped_walk *pvmw)
{
pmd_t pmde;
pmde = READ_ONCE(*pvmw->pmd);
return pmd_present(pmde) && !pmd_trans_huge(pmde);
}
static inline bool not_found(struct page_vma_mapped_walk *pvmw)
{
page_vma_mapped_walk_done(pvmw);
return false;
}
static bool map_pte(struct page_vma_mapped_walk *pvmw)
{
pvmw->pte = pte_offset_map(pvmw->pmd, pvmw->address);
if (!(pvmw->flags & PVMW_SYNC)) {
if (pvmw->flags & PVMW_MIGRATION) {
if (!is_swap_pte(*pvmw->pte))
return false;
} else {
if (!pte_present(*pvmw->pte))
return false;
}
}
pvmw->ptl = pte_lockptr(pvmw->vma->vm_mm, pvmw->pmd);
spin_lock(pvmw->ptl);
return true;
}
static bool check_pte(struct page_vma_mapped_walk *pvmw)
{
if (pvmw->flags & PVMW_MIGRATION) {
#ifdef CONFIG_MIGRATION
swp_entry_t entry;
if (!is_swap_pte(*pvmw->pte))
return false;
entry = pte_to_swp_entry(*pvmw->pte);
if (!is_migration_entry(entry))
return false;
if (migration_entry_to_page(entry) - pvmw->page >=
hpage_nr_pages(pvmw->page)) {
return false;
}
if (migration_entry_to_page(entry) < pvmw->page)
return false;
#else
WARN_ON_ONCE(1);
#endif
} else {
if (!pte_present(*pvmw->pte))
return false;
if (pte_page(*pvmw->pte) - pvmw->page >=
hpage_nr_pages(pvmw->page)) {
return false;
}
if (pte_page(*pvmw->pte) < pvmw->page)
return false;
}
return true;
}
bool page_vma_mapped_walk(struct page_vma_mapped_walk *pvmw)
{
struct mm_struct *mm = pvmw->vma->vm_mm;
struct page *page = pvmw->page;
pgd_t *pgd;
p4d_t *p4d;
pud_t *pud;
if (pvmw->pmd && !pvmw->pte)
return not_found(pvmw);
if (pvmw->pte)
goto next_pte;
if (unlikely(PageHuge(pvmw->page))) {
pvmw->pte = huge_pte_offset(mm, pvmw->address);
if (!pvmw->pte)
return false;
pvmw->ptl = huge_pte_lockptr(page_hstate(page), mm, pvmw->pte);
spin_lock(pvmw->ptl);
if (!check_pte(pvmw))
return not_found(pvmw);
return true;
}
restart:
pgd = pgd_offset(mm, pvmw->address);
if (!pgd_present(*pgd))
return false;
p4d = p4d_offset(pgd, pvmw->address);
if (!p4d_present(*p4d))
return false;
pud = pud_offset(p4d, pvmw->address);
if (!pud_present(*pud))
return false;
pvmw->pmd = pmd_offset(pud, pvmw->address);
if (pmd_trans_huge(*pvmw->pmd)) {
pvmw->ptl = pmd_lock(mm, pvmw->pmd);
if (!pmd_present(*pvmw->pmd))
return not_found(pvmw);
if (likely(pmd_trans_huge(*pvmw->pmd))) {
if (pvmw->flags & PVMW_MIGRATION)
return not_found(pvmw);
if (pmd_page(*pvmw->pmd) != page)
return not_found(pvmw);
return true;
} else {
spin_unlock(pvmw->ptl);
pvmw->ptl = NULL;
}
} else {
if (!check_pmd(pvmw))
return false;
}
if (!map_pte(pvmw))
goto next_pte;
while (1) {
if (check_pte(pvmw))
return true;
next_pte:
if (!PageTransHuge(pvmw->page) || PageHuge(pvmw->page))
return not_found(pvmw);
do {
pvmw->address += PAGE_SIZE;
if (pvmw->address >= pvmw->vma->vm_end ||
pvmw->address >=
__vma_address(pvmw->page, pvmw->vma) +
hpage_nr_pages(pvmw->page) * PAGE_SIZE)
return not_found(pvmw);
if (pvmw->address % PMD_SIZE == 0) {
pte_unmap(pvmw->pte);
if (pvmw->ptl) {
spin_unlock(pvmw->ptl);
pvmw->ptl = NULL;
}
goto restart;
} else {
pvmw->pte++;
}
} while (pte_none(*pvmw->pte));
if (!pvmw->ptl) {
pvmw->ptl = pte_lockptr(mm, pvmw->pmd);
spin_lock(pvmw->ptl);
}
}
}
int page_mapped_in_vma(struct page *page, struct vm_area_struct *vma)
{
struct page_vma_mapped_walk pvmw = {
.page = page,
.vma = vma,
.flags = PVMW_SYNC,
};
unsigned long start, end;
start = __vma_address(page, vma);
end = start + PAGE_SIZE * (hpage_nr_pages(page) - 1);
if (unlikely(end < vma->vm_start || start >= vma->vm_end))
return 0;
pvmw.address = max(start, vma->vm_start);
if (!page_vma_mapped_walk(&pvmw))
return 0;
page_vma_mapped_walk_done(&pvmw);
return 1;
}
