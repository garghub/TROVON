static pte_t *lock_pte_protection(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, int prot_numa, spinlock_t **ptl)
{
pte_t *pte;
spinlock_t *pmdl;
if (!prot_numa)
return pte_offset_map_lock(vma->vm_mm, pmd, addr, ptl);
pmdl = pmd_lock(vma->vm_mm, pmd);
if (unlikely(pmd_trans_huge(*pmd) || pmd_none(*pmd))) {
spin_unlock(pmdl);
return NULL;
}
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, ptl);
spin_unlock(pmdl);
return pte;
}
static unsigned long change_pte_range(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, unsigned long end, pgprot_t newprot,
int dirty_accountable, int prot_numa)
{
struct mm_struct *mm = vma->vm_mm;
pte_t *pte, oldpte;
spinlock_t *ptl;
unsigned long pages = 0;
pte = lock_pte_protection(vma, pmd, addr, prot_numa, &ptl);
if (!pte)
return 0;
arch_enter_lazy_mmu_mode();
do {
oldpte = *pte;
if (pte_present(oldpte)) {
pte_t ptent;
bool preserve_write = prot_numa && pte_write(oldpte);
if (prot_numa) {
struct page *page;
page = vm_normal_page(vma, addr, oldpte);
if (!page || PageKsm(page))
continue;
if (pte_protnone(oldpte))
continue;
}
ptent = ptep_modify_prot_start(mm, addr, pte);
ptent = pte_modify(ptent, newprot);
if (preserve_write)
ptent = pte_mkwrite(ptent);
if (dirty_accountable && pte_dirty(ptent) &&
(pte_soft_dirty(ptent) ||
!(vma->vm_flags & VM_SOFTDIRTY))) {
ptent = pte_mkwrite(ptent);
}
ptep_modify_prot_commit(mm, addr, pte, ptent);
pages++;
} else if (IS_ENABLED(CONFIG_MIGRATION)) {
swp_entry_t entry = pte_to_swp_entry(oldpte);
if (is_write_migration_entry(entry)) {
pte_t newpte;
make_migration_entry_read(&entry);
newpte = swp_entry_to_pte(entry);
if (pte_swp_soft_dirty(oldpte))
newpte = pte_swp_mksoft_dirty(newpte);
set_pte_at(mm, addr, pte, newpte);
pages++;
}
}
} while (pte++, addr += PAGE_SIZE, addr != end);
arch_leave_lazy_mmu_mode();
pte_unmap_unlock(pte - 1, ptl);
return pages;
}
static inline unsigned long change_pmd_range(struct vm_area_struct *vma,
pud_t *pud, unsigned long addr, unsigned long end,
pgprot_t newprot, int dirty_accountable, int prot_numa)
{
pmd_t *pmd;
struct mm_struct *mm = vma->vm_mm;
unsigned long next;
unsigned long pages = 0;
unsigned long nr_huge_updates = 0;
unsigned long mni_start = 0;
pmd = pmd_offset(pud, addr);
do {
unsigned long this_pages;
next = pmd_addr_end(addr, end);
if (!pmd_trans_huge(*pmd) && pmd_none_or_clear_bad(pmd))
continue;
if (!mni_start) {
mni_start = addr;
mmu_notifier_invalidate_range_start(mm, mni_start, end);
}
if (pmd_trans_huge(*pmd)) {
if (next - addr != HPAGE_PMD_SIZE)
split_huge_page_pmd(vma, addr, pmd);
else {
int nr_ptes = change_huge_pmd(vma, pmd, addr,
newprot, prot_numa);
if (nr_ptes) {
if (nr_ptes == HPAGE_PMD_NR) {
pages += HPAGE_PMD_NR;
nr_huge_updates++;
}
continue;
}
}
}
this_pages = change_pte_range(vma, pmd, addr, next, newprot,
dirty_accountable, prot_numa);
pages += this_pages;
} while (pmd++, addr = next, addr != end);
if (mni_start)
mmu_notifier_invalidate_range_end(mm, mni_start, end);
if (nr_huge_updates)
count_vm_numa_events(NUMA_HUGE_PTE_UPDATES, nr_huge_updates);
return pages;
}
static inline unsigned long change_pud_range(struct vm_area_struct *vma,
pgd_t *pgd, unsigned long addr, unsigned long end,
pgprot_t newprot, int dirty_accountable, int prot_numa)
{
pud_t *pud;
unsigned long next;
unsigned long pages = 0;
pud = pud_offset(pgd, addr);
do {
next = pud_addr_end(addr, end);
if (pud_none_or_clear_bad(pud))
continue;
pages += change_pmd_range(vma, pud, addr, next, newprot,
dirty_accountable, prot_numa);
} while (pud++, addr = next, addr != end);
return pages;
}
static unsigned long change_protection_range(struct vm_area_struct *vma,
unsigned long addr, unsigned long end, pgprot_t newprot,
int dirty_accountable, int prot_numa)
{
struct mm_struct *mm = vma->vm_mm;
pgd_t *pgd;
unsigned long next;
unsigned long start = addr;
unsigned long pages = 0;
BUG_ON(addr >= end);
pgd = pgd_offset(mm, addr);
flush_cache_range(vma, addr, end);
set_tlb_flush_pending(mm);
do {
next = pgd_addr_end(addr, end);
if (pgd_none_or_clear_bad(pgd))
continue;
pages += change_pud_range(vma, pgd, addr, next, newprot,
dirty_accountable, prot_numa);
} while (pgd++, addr = next, addr != end);
if (pages)
flush_tlb_range(vma, start, end);
clear_tlb_flush_pending(mm);
return pages;
}
unsigned long change_protection(struct vm_area_struct *vma, unsigned long start,
unsigned long end, pgprot_t newprot,
int dirty_accountable, int prot_numa)
{
unsigned long pages;
if (is_vm_hugetlb_page(vma))
pages = hugetlb_change_protection(vma, start, end, newprot);
else
pages = change_protection_range(vma, start, end, newprot, dirty_accountable, prot_numa);
return pages;
}
int
mprotect_fixup(struct vm_area_struct *vma, struct vm_area_struct **pprev,
unsigned long start, unsigned long end, unsigned long newflags)
{
struct mm_struct *mm = vma->vm_mm;
unsigned long oldflags = vma->vm_flags;
long nrpages = (end - start) >> PAGE_SHIFT;
unsigned long charged = 0;
pgoff_t pgoff;
int error;
int dirty_accountable = 0;
if (newflags == oldflags) {
*pprev = vma;
return 0;
}
if (newflags & VM_WRITE) {
if (!(oldflags & (VM_ACCOUNT|VM_WRITE|VM_HUGETLB|
VM_SHARED|VM_NORESERVE))) {
charged = nrpages;
if (security_vm_enough_memory_mm(mm, charged))
return -ENOMEM;
newflags |= VM_ACCOUNT;
}
}
pgoff = vma->vm_pgoff + ((start - vma->vm_start) >> PAGE_SHIFT);
*pprev = vma_merge(mm, *pprev, start, end, newflags,
vma->anon_vma, vma->vm_file, pgoff, vma_policy(vma),
vma->vm_userfaultfd_ctx);
if (*pprev) {
vma = *pprev;
goto success;
}
*pprev = vma;
if (start != vma->vm_start) {
error = split_vma(mm, vma, start, 1);
if (error)
goto fail;
}
if (end != vma->vm_end) {
error = split_vma(mm, vma, end, 0);
if (error)
goto fail;
}
success:
vma->vm_flags = newflags;
dirty_accountable = vma_wants_writenotify(vma);
vma_set_page_prot(vma);
change_protection(vma, start, end, vma->vm_page_prot,
dirty_accountable, 0);
if ((oldflags & (VM_WRITE | VM_SHARED | VM_LOCKED)) == VM_LOCKED &&
(newflags & VM_WRITE)) {
populate_vma_page_range(vma, start, end, NULL);
}
vm_stat_account(mm, oldflags, vma->vm_file, -nrpages);
vm_stat_account(mm, newflags, vma->vm_file, nrpages);
perf_event_mmap(vma);
return 0;
fail:
vm_unacct_memory(charged);
return error;
}
