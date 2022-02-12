static void mincore_hugetlb_page_range(struct vm_area_struct *vma,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
#ifdef CONFIG_HUGETLB_PAGE
struct hstate *h;
h = hstate_vma(vma);
while (1) {
unsigned char present;
pte_t *ptep;
ptep = huge_pte_offset(current->mm,
addr & huge_page_mask(h));
present = ptep && !huge_pte_none(huge_ptep_get(ptep));
while (1) {
*vec = present;
vec++;
addr += PAGE_SIZE;
if (addr == end)
return;
if (!(addr & ~huge_page_mask(h)))
break;
}
}
#else
BUG();
#endif
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
page = find_get_page(swap_address_space(swp), swp.val);
}
} else
page = find_get_page(mapping, pgoff);
#else
page = find_get_page(mapping, pgoff);
#endif
if (page) {
present = PageUptodate(page);
page_cache_release(page);
}
return present;
}
static void mincore_unmapped_range(struct vm_area_struct *vma,
unsigned long addr, unsigned long end,
unsigned char *vec)
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
}
static void mincore_pte_range(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
unsigned long next;
spinlock_t *ptl;
pte_t *ptep;
ptep = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
do {
pte_t pte = *ptep;
pgoff_t pgoff;
next = addr + PAGE_SIZE;
if (pte_none(pte))
mincore_unmapped_range(vma, addr, next, vec);
else if (pte_present(pte))
*vec = 1;
else if (pte_file(pte)) {
pgoff = pte_to_pgoff(pte);
*vec = mincore_page(vma->vm_file->f_mapping, pgoff);
} else {
swp_entry_t entry = pte_to_swp_entry(pte);
if (non_swap_entry(entry)) {
*vec = 1;
} else {
#ifdef CONFIG_SWAP
pgoff = entry.val;
*vec = mincore_page(swap_address_space(entry),
pgoff);
#else
WARN_ON(1);
*vec = 1;
#endif
}
}
vec++;
} while (ptep++, addr = next, addr != end);
pte_unmap_unlock(ptep - 1, ptl);
}
static void mincore_pmd_range(struct vm_area_struct *vma, pud_t *pud,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
unsigned long next;
pmd_t *pmd;
pmd = pmd_offset(pud, addr);
do {
next = pmd_addr_end(addr, end);
if (pmd_trans_huge(*pmd)) {
if (mincore_huge_pmd(vma, pmd, addr, next, vec)) {
vec += (next - addr) >> PAGE_SHIFT;
continue;
}
}
if (pmd_none_or_trans_huge_or_clear_bad(pmd))
mincore_unmapped_range(vma, addr, next, vec);
else
mincore_pte_range(vma, pmd, addr, next, vec);
vec += (next - addr) >> PAGE_SHIFT;
} while (pmd++, addr = next, addr != end);
}
static void mincore_pud_range(struct vm_area_struct *vma, pgd_t *pgd,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
unsigned long next;
pud_t *pud;
pud = pud_offset(pgd, addr);
do {
next = pud_addr_end(addr, end);
if (pud_none_or_clear_bad(pud))
mincore_unmapped_range(vma, addr, next, vec);
else
mincore_pmd_range(vma, pud, addr, next, vec);
vec += (next - addr) >> PAGE_SHIFT;
} while (pud++, addr = next, addr != end);
}
static void mincore_page_range(struct vm_area_struct *vma,
unsigned long addr, unsigned long end,
unsigned char *vec)
{
unsigned long next;
pgd_t *pgd;
pgd = pgd_offset(vma->vm_mm, addr);
do {
next = pgd_addr_end(addr, end);
if (pgd_none_or_clear_bad(pgd))
mincore_unmapped_range(vma, addr, next, vec);
else
mincore_pud_range(vma, pgd, addr, next, vec);
vec += (next - addr) >> PAGE_SHIFT;
} while (pgd++, addr = next, addr != end);
}
static long do_mincore(unsigned long addr, unsigned long pages, unsigned char *vec)
{
struct vm_area_struct *vma;
unsigned long end;
vma = find_vma(current->mm, addr);
if (!vma || addr < vma->vm_start)
return -ENOMEM;
end = min(vma->vm_end, addr + (pages << PAGE_SHIFT));
if (is_vm_hugetlb_page(vma))
mincore_hugetlb_page_range(vma, addr, end, vec);
else
mincore_page_range(vma, addr, end, vec);
return (end - addr) >> PAGE_SHIFT;
}
