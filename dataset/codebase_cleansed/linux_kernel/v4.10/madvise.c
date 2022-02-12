static int madvise_need_mmap_write(int behavior)
{
switch (behavior) {
case MADV_REMOVE:
case MADV_WILLNEED:
case MADV_DONTNEED:
case MADV_FREE:
return 0;
default:
return 1;
}
}
static long madvise_behavior(struct vm_area_struct *vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end, int behavior)
{
struct mm_struct *mm = vma->vm_mm;
int error = 0;
pgoff_t pgoff;
unsigned long new_flags = vma->vm_flags;
switch (behavior) {
case MADV_NORMAL:
new_flags = new_flags & ~VM_RAND_READ & ~VM_SEQ_READ;
break;
case MADV_SEQUENTIAL:
new_flags = (new_flags & ~VM_RAND_READ) | VM_SEQ_READ;
break;
case MADV_RANDOM:
new_flags = (new_flags & ~VM_SEQ_READ) | VM_RAND_READ;
break;
case MADV_DONTFORK:
new_flags |= VM_DONTCOPY;
break;
case MADV_DOFORK:
if (vma->vm_flags & VM_IO) {
error = -EINVAL;
goto out;
}
new_flags &= ~VM_DONTCOPY;
break;
case MADV_DONTDUMP:
new_flags |= VM_DONTDUMP;
break;
case MADV_DODUMP:
if (new_flags & VM_SPECIAL) {
error = -EINVAL;
goto out;
}
new_flags &= ~VM_DONTDUMP;
break;
case MADV_MERGEABLE:
case MADV_UNMERGEABLE:
error = ksm_madvise(vma, start, end, behavior, &new_flags);
if (error)
goto out;
break;
case MADV_HUGEPAGE:
case MADV_NOHUGEPAGE:
error = hugepage_madvise(vma, &new_flags, behavior);
if (error)
goto out;
break;
}
if (new_flags == vma->vm_flags) {
*prev = vma;
goto out;
}
pgoff = vma->vm_pgoff + ((start - vma->vm_start) >> PAGE_SHIFT);
*prev = vma_merge(mm, *prev, start, end, new_flags, vma->anon_vma,
vma->vm_file, pgoff, vma_policy(vma),
vma->vm_userfaultfd_ctx);
if (*prev) {
vma = *prev;
goto success;
}
*prev = vma;
if (start != vma->vm_start) {
error = split_vma(mm, vma, start, 1);
if (error)
goto out;
}
if (end != vma->vm_end) {
error = split_vma(mm, vma, end, 0);
if (error)
goto out;
}
success:
vma->vm_flags = new_flags;
out:
if (error == -ENOMEM)
error = -EAGAIN;
return error;
}
static int swapin_walk_pmd_entry(pmd_t *pmd, unsigned long start,
unsigned long end, struct mm_walk *walk)
{
pte_t *orig_pte;
struct vm_area_struct *vma = walk->private;
unsigned long index;
if (pmd_none_or_trans_huge_or_clear_bad(pmd))
return 0;
for (index = start; index != end; index += PAGE_SIZE) {
pte_t pte;
swp_entry_t entry;
struct page *page;
spinlock_t *ptl;
orig_pte = pte_offset_map_lock(vma->vm_mm, pmd, start, &ptl);
pte = *(orig_pte + ((index - start) / PAGE_SIZE));
pte_unmap_unlock(orig_pte, ptl);
if (pte_present(pte) || pte_none(pte))
continue;
entry = pte_to_swp_entry(pte);
if (unlikely(non_swap_entry(entry)))
continue;
page = read_swap_cache_async(entry, GFP_HIGHUSER_MOVABLE,
vma, index);
if (page)
put_page(page);
}
return 0;
}
static void force_swapin_readahead(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
struct mm_walk walk = {
.mm = vma->vm_mm,
.pmd_entry = swapin_walk_pmd_entry,
.private = vma,
};
walk_page_range(start, end, &walk);
lru_add_drain();
}
static void force_shm_swapin_readahead(struct vm_area_struct *vma,
unsigned long start, unsigned long end,
struct address_space *mapping)
{
pgoff_t index;
struct page *page;
swp_entry_t swap;
for (; start < end; start += PAGE_SIZE) {
index = ((start - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
page = find_get_entry(mapping, index);
if (!radix_tree_exceptional_entry(page)) {
if (page)
put_page(page);
continue;
}
swap = radix_to_swp_entry(page);
page = read_swap_cache_async(swap, GFP_HIGHUSER_MOVABLE,
NULL, 0);
if (page)
put_page(page);
}
lru_add_drain();
}
static long madvise_willneed(struct vm_area_struct *vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end)
{
struct file *file = vma->vm_file;
#ifdef CONFIG_SWAP
if (!file) {
*prev = vma;
force_swapin_readahead(vma, start, end);
return 0;
}
if (shmem_mapping(file->f_mapping)) {
*prev = vma;
force_shm_swapin_readahead(vma, start, end,
file->f_mapping);
return 0;
}
#else
if (!file)
return -EBADF;
#endif
if (IS_DAX(file_inode(file))) {
return 0;
}
*prev = vma;
start = ((start - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
if (end > vma->vm_end)
end = vma->vm_end;
end = ((end - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
force_page_cache_readahead(file->f_mapping, file, start, end - start);
return 0;
}
static int madvise_free_pte_range(pmd_t *pmd, unsigned long addr,
unsigned long end, struct mm_walk *walk)
{
struct mmu_gather *tlb = walk->private;
struct mm_struct *mm = tlb->mm;
struct vm_area_struct *vma = walk->vma;
spinlock_t *ptl;
pte_t *orig_pte, *pte, ptent;
struct page *page;
int nr_swap = 0;
unsigned long next;
next = pmd_addr_end(addr, end);
if (pmd_trans_huge(*pmd))
if (madvise_free_huge_pmd(tlb, vma, pmd, addr, next))
goto next;
if (pmd_trans_unstable(pmd))
return 0;
tlb_remove_check_page_size_change(tlb, PAGE_SIZE);
orig_pte = pte = pte_offset_map_lock(mm, pmd, addr, &ptl);
arch_enter_lazy_mmu_mode();
for (; addr != end; pte++, addr += PAGE_SIZE) {
ptent = *pte;
if (pte_none(ptent))
continue;
if (!pte_present(ptent)) {
swp_entry_t entry;
entry = pte_to_swp_entry(ptent);
if (non_swap_entry(entry))
continue;
nr_swap--;
free_swap_and_cache(entry);
pte_clear_not_present_full(mm, addr, pte, tlb->fullmm);
continue;
}
page = vm_normal_page(vma, addr, ptent);
if (!page)
continue;
if (PageTransCompound(page)) {
if (page_mapcount(page) != 1)
goto out;
get_page(page);
if (!trylock_page(page)) {
put_page(page);
goto out;
}
pte_unmap_unlock(orig_pte, ptl);
if (split_huge_page(page)) {
unlock_page(page);
put_page(page);
pte_offset_map_lock(mm, pmd, addr, &ptl);
goto out;
}
put_page(page);
unlock_page(page);
pte = pte_offset_map_lock(mm, pmd, addr, &ptl);
pte--;
addr -= PAGE_SIZE;
continue;
}
VM_BUG_ON_PAGE(PageTransCompound(page), page);
if (PageSwapCache(page) || PageDirty(page)) {
if (!trylock_page(page))
continue;
if (page_mapcount(page) != 1) {
unlock_page(page);
continue;
}
if (PageSwapCache(page) && !try_to_free_swap(page)) {
unlock_page(page);
continue;
}
ClearPageDirty(page);
unlock_page(page);
}
if (pte_young(ptent) || pte_dirty(ptent)) {
ptent = ptep_get_and_clear_full(mm, addr, pte,
tlb->fullmm);
ptent = pte_mkold(ptent);
ptent = pte_mkclean(ptent);
set_pte_at(mm, addr, pte, ptent);
if (PageActive(page))
deactivate_page(page);
tlb_remove_tlb_entry(tlb, pte, addr);
}
}
out:
if (nr_swap) {
if (current->mm == mm)
sync_mm_rss(mm);
add_mm_counter(mm, MM_SWAPENTS, nr_swap);
}
arch_leave_lazy_mmu_mode();
pte_unmap_unlock(orig_pte, ptl);
cond_resched();
next:
return 0;
}
static void madvise_free_page_range(struct mmu_gather *tlb,
struct vm_area_struct *vma,
unsigned long addr, unsigned long end)
{
struct mm_walk free_walk = {
.pmd_entry = madvise_free_pte_range,
.mm = vma->vm_mm,
.private = tlb,
};
tlb_start_vma(tlb, vma);
walk_page_range(addr, end, &free_walk);
tlb_end_vma(tlb, vma);
}
static int madvise_free_single_vma(struct vm_area_struct *vma,
unsigned long start_addr, unsigned long end_addr)
{
unsigned long start, end;
struct mm_struct *mm = vma->vm_mm;
struct mmu_gather tlb;
if (vma->vm_flags & (VM_LOCKED|VM_HUGETLB|VM_PFNMAP))
return -EINVAL;
if (!vma_is_anonymous(vma))
return -EINVAL;
start = max(vma->vm_start, start_addr);
if (start >= vma->vm_end)
return -EINVAL;
end = min(vma->vm_end, end_addr);
if (end <= vma->vm_start)
return -EINVAL;
lru_add_drain();
tlb_gather_mmu(&tlb, mm, start, end);
update_hiwater_rss(mm);
mmu_notifier_invalidate_range_start(mm, start, end);
madvise_free_page_range(&tlb, vma, start, end);
mmu_notifier_invalidate_range_end(mm, start, end);
tlb_finish_mmu(&tlb, start, end);
return 0;
}
static long madvise_free(struct vm_area_struct *vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end)
{
*prev = vma;
return madvise_free_single_vma(vma, start, end);
}
static long madvise_dontneed(struct vm_area_struct *vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end)
{
*prev = vma;
if (vma->vm_flags & (VM_LOCKED|VM_HUGETLB|VM_PFNMAP))
return -EINVAL;
zap_page_range(vma, start, end - start, NULL);
return 0;
}
static long madvise_remove(struct vm_area_struct *vma,
struct vm_area_struct **prev,
unsigned long start, unsigned long end)
{
loff_t offset;
int error;
struct file *f;
*prev = NULL;
if (vma->vm_flags & VM_LOCKED)
return -EINVAL;
f = vma->vm_file;
if (!f || !f->f_mapping || !f->f_mapping->host) {
return -EINVAL;
}
if ((vma->vm_flags & (VM_SHARED|VM_WRITE)) != (VM_SHARED|VM_WRITE))
return -EACCES;
offset = (loff_t)(start - vma->vm_start)
+ ((loff_t)vma->vm_pgoff << PAGE_SHIFT);
get_file(f);
up_read(&current->mm->mmap_sem);
error = vfs_fallocate(f,
FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE,
offset, end - start);
fput(f);
down_read(&current->mm->mmap_sem);
return error;
}
static int madvise_hwpoison(int bhv, unsigned long start, unsigned long end)
{
struct page *p;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
for (; start < end; start += PAGE_SIZE <<
compound_order(compound_head(p))) {
int ret;
ret = get_user_pages_fast(start, 1, 0, &p);
if (ret != 1)
return ret;
if (PageHWPoison(p)) {
put_page(p);
continue;
}
if (bhv == MADV_SOFT_OFFLINE) {
pr_info("Soft offlining page %#lx at %#lx\n",
page_to_pfn(p), start);
ret = soft_offline_page(p, MF_COUNT_INCREASED);
if (ret)
return ret;
continue;
}
pr_info("Injecting memory failure for page %#lx at %#lx\n",
page_to_pfn(p), start);
ret = memory_failure(page_to_pfn(p), 0, MF_COUNT_INCREASED);
if (ret)
return ret;
}
return 0;
}
static long
madvise_vma(struct vm_area_struct *vma, struct vm_area_struct **prev,
unsigned long start, unsigned long end, int behavior)
{
switch (behavior) {
case MADV_REMOVE:
return madvise_remove(vma, prev, start, end);
case MADV_WILLNEED:
return madvise_willneed(vma, prev, start, end);
case MADV_FREE:
if (get_nr_swap_pages() > 0)
return madvise_free(vma, prev, start, end);
case MADV_DONTNEED:
return madvise_dontneed(vma, prev, start, end);
default:
return madvise_behavior(vma, prev, start, end, behavior);
}
}
static bool
madvise_behavior_valid(int behavior)
{
switch (behavior) {
case MADV_DOFORK:
case MADV_DONTFORK:
case MADV_NORMAL:
case MADV_SEQUENTIAL:
case MADV_RANDOM:
case MADV_REMOVE:
case MADV_WILLNEED:
case MADV_DONTNEED:
case MADV_FREE:
#ifdef CONFIG_KSM
case MADV_MERGEABLE:
case MADV_UNMERGEABLE:
#endif
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
case MADV_HUGEPAGE:
case MADV_NOHUGEPAGE:
#endif
case MADV_DONTDUMP:
case MADV_DODUMP:
return true;
default:
return false;
}
}
