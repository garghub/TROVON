static int mincore_hugetlb(pte_t *pte, unsigned long hmask, unsigned long addr,
unsigned long end, struct mm_walk *walk)
{
#ifdef CONFIG_HUGETLB_PAGE
unsigned char present;
unsigned char *vec = walk->private;
present = pte && !huge_pte_none(huge_ptep_get(pte));
for (; addr != end; vec++, addr += PAGE_SIZE)
*vec = present;
walk->private = vec;
#else
BUG();
#endif
return 0;
}
static unsigned char mincore_page(struct address_space *mapping, pgoff_t pgoff)
{
unsigned char present = 0;
struct page *page;
#ifdef CONFIG_SWAP
if (shmem_mapping(mapping)) {
page = find_get_entry(mapping, pgoff);
if (radix_tree_exceptional_entry(page)) {
swp_entry_t swp = radix_to_swp_entry(page);
page = find_get_page(swap_address_space(swp),
swp_offset(swp));
}
} else
page = find_get_page(mapping, pgoff);
#else
page = find_get_page(mapping, pgoff);
#endif
if (page) {
present = PageUptodate(page);
put_page(page);
}
return present;
}
static int __mincore_unmapped_range(unsigned long addr, unsigned long end,
struct vm_area_struct *vma, unsigned char *vec)
{
unsigned long nr = (end - addr) >> PAGE_SHIFT;
int i;
if (vma->vm_file) {
pgoff_t pgoff;
pgoff = linear_page_index(vma, addr);
for (i = 0; i < nr; i++, pgoff++)
vec[i] = mincore_page(vma->vm_file->f_mapping, pgoff);
} else {
for (i = 0; i < nr; i++)
vec[i] = 0;
}
return nr;
}
static int mincore_unmapped_range(unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
walk->private += __mincore_unmapped_range(addr, end,
walk->vma, walk->private);
return 0;
}
static int mincore_pte_range(pmd_t *pmd, unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
spinlock_t *ptl;
struct vm_area_struct *vma = walk->vma;
pte_t *ptep;
unsigned char *vec = walk->private;
int nr = (end - addr) >> PAGE_SHIFT;
ptl = pmd_trans_huge_lock(pmd, vma);
if (ptl) {
memset(vec, 1, nr);
spin_unlock(ptl);
goto out;
}
if (pmd_trans_unstable(pmd)) {
__mincore_unmapped_range(addr, end, vma, vec);
goto out;
}
ptep = pte_offset_map_lock(walk->mm, pmd, addr, &ptl);
for (; addr != end; ptep++, addr += PAGE_SIZE) {
pte_t pte = *ptep;
if (pte_none(pte))
__mincore_unmapped_range(addr, addr + PAGE_SIZE,
vma, vec);
else if (pte_present(pte))
*vec = 1;
else {
swp_entry_t entry = pte_to_swp_entry(pte);
if (non_swap_entry(entry)) {
*vec = 1;
} else {
#ifdef CONFIG_SWAP
*vec = mincore_page(swap_address_space(entry),
swp_offset(entry));
#else
WARN_ON(1);
*vec = 1;
#endif
}
}
vec++;
}
pte_unmap_unlock(ptep - 1, ptl);
out:
walk->private += nr;
cond_resched();
return 0;
}
static long do_mincore(unsigned long addr, unsigned long pages, unsigned char *vec)
{
struct vm_area_struct *vma;
unsigned long end;
int err;
struct mm_walk mincore_walk = {
.pmd_entry = mincore_pte_range,
.pte_hole = mincore_unmapped_range,
.hugetlb_entry = mincore_hugetlb,
.private = vec,
};
vma = find_vma(current->mm, addr);
if (!vma || addr < vma->vm_start)
return -ENOMEM;
mincore_walk.mm = vma->vm_mm;
end = min(vma->vm_end, addr + (pages << PAGE_SHIFT));
err = walk_page_range(addr, end, &mincore_walk);
if (err < 0)
return err;
return (end - addr) >> PAGE_SHIFT;
}
