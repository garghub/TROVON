static int walk_pte_range(pmd_t *pmd, unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
pte_t *pte;
int err = 0;
pte = pte_offset_map(pmd, addr);
for (;;) {
err = walk->pte_entry(pte, addr, addr + PAGE_SIZE, walk);
if (err)
break;
addr += PAGE_SIZE;
if (addr == end)
break;
pte++;
}
pte_unmap(pte);
return err;
}
static int walk_pmd_range(pud_t *pud, unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
pmd_t *pmd;
unsigned long next;
int err = 0;
pmd = pmd_offset(pud, addr);
do {
again:
next = pmd_addr_end(addr, end);
if (pmd_none(*pmd) || !walk->vma) {
if (walk->pte_hole)
err = walk->pte_hole(addr, next, walk);
if (err)
break;
continue;
}
if (walk->pmd_entry)
err = walk->pmd_entry(pmd, addr, next, walk);
if (err)
break;
if (!walk->pte_entry)
continue;
split_huge_page_pmd_mm(walk->mm, addr, pmd);
if (pmd_trans_unstable(pmd))
goto again;
err = walk_pte_range(pmd, addr, next, walk);
if (err)
break;
} while (pmd++, addr = next, addr != end);
return err;
}
static int walk_pud_range(pgd_t *pgd, unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
pud_t *pud;
unsigned long next;
int err = 0;
pud = pud_offset(pgd, addr);
do {
next = pud_addr_end(addr, end);
if (pud_none_or_clear_bad(pud)) {
if (walk->pte_hole)
err = walk->pte_hole(addr, next, walk);
if (err)
break;
continue;
}
if (walk->pmd_entry || walk->pte_entry)
err = walk_pmd_range(pud, addr, next, walk);
if (err)
break;
} while (pud++, addr = next, addr != end);
return err;
}
static int walk_pgd_range(unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
pgd_t *pgd;
unsigned long next;
int err = 0;
pgd = pgd_offset(walk->mm, addr);
do {
next = pgd_addr_end(addr, end);
if (pgd_none_or_clear_bad(pgd)) {
if (walk->pte_hole)
err = walk->pte_hole(addr, next, walk);
if (err)
break;
continue;
}
if (walk->pmd_entry || walk->pte_entry)
err = walk_pud_range(pgd, addr, next, walk);
if (err)
break;
} while (pgd++, addr = next, addr != end);
return err;
}
static unsigned long hugetlb_entry_end(struct hstate *h, unsigned long addr,
unsigned long end)
{
unsigned long boundary = (addr & huge_page_mask(h)) + huge_page_size(h);
return boundary < end ? boundary : end;
}
static int walk_hugetlb_range(unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
struct hstate *h = hstate_vma(vma);
unsigned long next;
unsigned long hmask = huge_page_mask(h);
pte_t *pte;
int err = 0;
do {
next = hugetlb_entry_end(h, addr, end);
pte = huge_pte_offset(walk->mm, addr & hmask);
if (pte && walk->hugetlb_entry)
err = walk->hugetlb_entry(pte, hmask, addr, next, walk);
if (err)
break;
} while (addr = next, addr != end);
return err;
}
static int walk_hugetlb_range(unsigned long addr, unsigned long end,
struct mm_walk *walk)
{
return 0;
}
static int walk_page_test(unsigned long start, unsigned long end,
struct mm_walk *walk)
{
struct vm_area_struct *vma = walk->vma;
if (walk->test_walk)
return walk->test_walk(start, end, walk);
if (vma->vm_flags & VM_PFNMAP) {
int err = 1;
if (walk->pte_hole)
err = walk->pte_hole(start, end, walk);
return err ? err : 1;
}
return 0;
}
static int __walk_page_range(unsigned long start, unsigned long end,
struct mm_walk *walk)
{
int err = 0;
struct vm_area_struct *vma = walk->vma;
if (vma && is_vm_hugetlb_page(vma)) {
if (walk->hugetlb_entry)
err = walk_hugetlb_range(start, end, walk);
} else
err = walk_pgd_range(start, end, walk);
return err;
}
int walk_page_range(unsigned long start, unsigned long end,
struct mm_walk *walk)
{
int err = 0;
unsigned long next;
struct vm_area_struct *vma;
if (start >= end)
return -EINVAL;
if (!walk->mm)
return -EINVAL;
VM_BUG_ON_MM(!rwsem_is_locked(&walk->mm->mmap_sem), walk->mm);
vma = find_vma(walk->mm, start);
do {
if (!vma) {
walk->vma = NULL;
next = end;
} else if (start < vma->vm_start) {
walk->vma = NULL;
next = min(end, vma->vm_start);
} else {
walk->vma = vma;
next = min(end, vma->vm_end);
vma = vma->vm_next;
err = walk_page_test(start, next, walk);
if (err > 0) {
err = 0;
continue;
}
if (err < 0)
break;
}
if (walk->vma || walk->pte_hole)
err = __walk_page_range(start, next, walk);
if (err)
break;
} while (start = next, start < end);
return err;
}
int walk_page_vma(struct vm_area_struct *vma, struct mm_walk *walk)
{
int err;
if (!walk->mm)
return -EINVAL;
VM_BUG_ON(!rwsem_is_locked(&walk->mm->mmap_sem));
VM_BUG_ON(!vma);
walk->vma = vma;
err = walk_page_test(vma->vm_start, vma->vm_end, walk);
if (err > 0)
return 0;
if (err < 0)
return err;
return __walk_page_range(vma->vm_start, vma->vm_end, walk);
}
