static int mm_counter(struct page *page)
{
return PageAnon(page) ? MM_ANONPAGES : MM_FILEPAGES;
}
static void zap_pte(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long addr, pte_t *ptep)
{
pte_t pte = *ptep;
struct page *page;
swp_entry_t entry;
if (pte_present(pte)) {
flush_cache_page(vma, addr, pte_pfn(pte));
pte = ptep_clear_flush(vma, addr, ptep);
page = vm_normal_page(vma, addr, pte);
if (page) {
if (pte_dirty(pte))
set_page_dirty(page);
update_hiwater_rss(mm);
dec_mm_counter(mm, mm_counter(page));
page_remove_rmap(page);
page_cache_release(page);
}
} else {
if (!pte_file(pte)) {
update_hiwater_rss(mm);
entry = pte_to_swp_entry(pte);
if (non_swap_entry(entry)) {
if (is_migration_entry(entry)) {
page = migration_entry_to_page(entry);
dec_mm_counter(mm, mm_counter(page));
}
} else {
free_swap_and_cache(entry);
dec_mm_counter(mm, MM_SWAPENTS);
}
}
pte_clear_not_present_full(mm, addr, ptep, 0);
}
}
static int install_file_pte(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long addr, unsigned long pgoff, pgprot_t prot)
{
int err = -ENOMEM;
pte_t *pte, ptfile;
spinlock_t *ptl;
pte = get_locked_pte(mm, addr, &ptl);
if (!pte)
goto out;
ptfile = pgoff_to_pte(pgoff);
if (!pte_none(*pte)) {
if (pte_present(*pte) && pte_soft_dirty(*pte))
pte_file_mksoft_dirty(ptfile);
zap_pte(mm, vma, addr, pte);
}
set_pte_at(mm, addr, pte, ptfile);
pte_unmap_unlock(pte, ptl);
err = 0;
out:
return err;
}
int generic_file_remap_pages(struct vm_area_struct *vma, unsigned long addr,
unsigned long size, pgoff_t pgoff)
{
struct mm_struct *mm = vma->vm_mm;
int err;
do {
err = install_file_pte(mm, vma, addr, pgoff, vma->vm_page_prot);
if (err)
return err;
size -= PAGE_SIZE;
addr += PAGE_SIZE;
pgoff++;
} while (size);
return 0;
}
