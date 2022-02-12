static unsigned long change_pte_range(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, unsigned long end, pgprot_t newprot,
int dirty_accountable, int prot_numa)
{
struct mm_struct *mm = vma->vm_mm;
pte_t *pte, oldpte;
spinlock_t *ptl;
unsigned long pages = 0;
int target_node = NUMA_NO_NODE;
if (pmd_trans_unstable(pmd))
return 0;
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
if (prot_numa && !(vma->vm_flags & VM_SHARED) &&
atomic_read(&vma->vm_mm->mm_users) == 1)
target_node = numa_node_id();
flush_tlb_batched_pending(vma->vm_mm);
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
if (target_node == page_to_nid(page))
continue;
}
ptent = ptep_modify_prot_start(mm, addr, pte);
ptent = pte_modify(ptent, newprot);
if (preserve_write)
ptent = pte_mk_savedwrite(ptent);
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
if (!pmd_trans_huge(*pmd) && !pmd_devmap(*pmd)
&& pmd_none_or_clear_bad(pmd))
continue;
if (!mni_start) {
mni_start = addr;
mmu_notifier_invalidate_range_start(mm, mni_start, end);
}
if (pmd_trans_huge(*pmd) || pmd_devmap(*pmd)) {
if (next - addr != HPAGE_PMD_SIZE) {
__split_huge_pmd(vma, pmd, addr, false, NULL);
} else {
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
p4d_t *p4d, unsigned long addr, unsigned long end,
pgprot_t newprot, int dirty_accountable, int prot_numa)
{
pud_t *pud;
unsigned long next;
unsigned long pages = 0;
pud = pud_offset(p4d, addr);
do {
next = pud_addr_end(addr, end);
if (pud_none_or_clear_bad(pud))
continue;
pages += change_pmd_range(vma, pud, addr, next, newprot,
dirty_accountable, prot_numa);
} while (pud++, addr = next, addr != end);
return pages;
}
static inline unsigned long change_p4d_range(struct vm_area_struct *vma,
pgd_t *pgd, unsigned long addr, unsigned long end,
pgprot_t newprot, int dirty_accountable, int prot_numa)
{
p4d_t *p4d;
unsigned long next;
unsigned long pages = 0;
p4d = p4d_offset(pgd, addr);
do {
next = p4d_addr_end(addr, end);
if (p4d_none_or_clear_bad(p4d))
continue;
pages += change_pud_range(vma, p4d, addr, next, newprot,
dirty_accountable, prot_numa);
} while (p4d++, addr = next, addr != end);
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
inc_tlb_flush_pending(mm);
do {
next = pgd_addr_end(addr, end);
if (pgd_none_or_clear_bad(pgd))
continue;
pages += change_p4d_range(vma, pgd, addr, next, newprot,
dirty_accountable, prot_numa);
} while (pgd++, addr = next, addr != end);
if (pages)
flush_tlb_range(vma, start, end);
dec_tlb_flush_pending(mm);
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
if (!may_expand_vm(mm, newflags, nrpages) &&
may_expand_vm(mm, oldflags, nrpages))
return -ENOMEM;
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
VM_WARN_ON((vma->vm_flags ^ newflags) & ~VM_SOFTDIRTY);
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
dirty_accountable = vma_wants_writenotify(vma, vma->vm_page_prot);
vma_set_page_prot(vma);
change_protection(vma, start, end, vma->vm_page_prot,
dirty_accountable, 0);
if ((oldflags & (VM_WRITE | VM_SHARED | VM_LOCKED)) == VM_LOCKED &&
(newflags & VM_WRITE)) {
populate_vma_page_range(vma, start, end, NULL);
}
vm_stat_account(mm, oldflags, -nrpages);
vm_stat_account(mm, newflags, nrpages);
perf_event_mmap(vma);
return 0;
fail:
vm_unacct_memory(charged);
return error;
}
static int do_mprotect_pkey(unsigned long start, size_t len,
unsigned long prot, int pkey)
{
unsigned long nstart, end, tmp, reqprot;
struct vm_area_struct *vma, *prev;
int error = -EINVAL;
const int grows = prot & (PROT_GROWSDOWN|PROT_GROWSUP);
const bool rier = (current->personality & READ_IMPLIES_EXEC) &&
(prot & PROT_READ);
prot &= ~(PROT_GROWSDOWN|PROT_GROWSUP);
if (grows == (PROT_GROWSDOWN|PROT_GROWSUP))
return -EINVAL;
if (start & ~PAGE_MASK)
return -EINVAL;
if (!len)
return 0;
len = PAGE_ALIGN(len);
end = start + len;
if (end <= start)
return -ENOMEM;
if (!arch_validate_prot(prot))
return -EINVAL;
reqprot = prot;
if (down_write_killable(&current->mm->mmap_sem))
return -EINTR;
error = -EINVAL;
if ((pkey != -1) && !mm_pkey_is_allocated(current->mm, pkey))
goto out;
vma = find_vma(current->mm, start);
error = -ENOMEM;
if (!vma)
goto out;
prev = vma->vm_prev;
if (unlikely(grows & PROT_GROWSDOWN)) {
if (vma->vm_start >= end)
goto out;
start = vma->vm_start;
error = -EINVAL;
if (!(vma->vm_flags & VM_GROWSDOWN))
goto out;
} else {
if (vma->vm_start > start)
goto out;
if (unlikely(grows & PROT_GROWSUP)) {
end = vma->vm_end;
error = -EINVAL;
if (!(vma->vm_flags & VM_GROWSUP))
goto out;
}
}
if (start > vma->vm_start)
prev = vma;
for (nstart = start ; ; ) {
unsigned long mask_off_old_flags;
unsigned long newflags;
int new_vma_pkey;
if (rier && (vma->vm_flags & VM_MAYEXEC))
prot |= PROT_EXEC;
mask_off_old_flags = VM_READ | VM_WRITE | VM_EXEC |
ARCH_VM_PKEY_FLAGS;
new_vma_pkey = arch_override_mprotect_pkey(vma, prot, pkey);
newflags = calc_vm_prot_bits(prot, new_vma_pkey);
newflags |= (vma->vm_flags & ~mask_off_old_flags);
if ((newflags & ~(newflags >> 4)) & (VM_READ | VM_WRITE | VM_EXEC)) {
error = -EACCES;
goto out;
}
error = security_file_mprotect(vma, reqprot, prot);
if (error)
goto out;
tmp = vma->vm_end;
if (tmp > end)
tmp = end;
error = mprotect_fixup(vma, &prev, nstart, tmp, newflags);
if (error)
goto out;
nstart = tmp;
if (nstart < prev->vm_end)
nstart = prev->vm_end;
if (nstart >= end)
goto out;
vma = prev->vm_next;
if (!vma || vma->vm_start != nstart) {
error = -ENOMEM;
goto out;
}
prot = reqprot;
}
out:
up_write(&current->mm->mmap_sem);
return error;
}
