static inline void io_remap_pte_range(struct mm_struct *mm, pte_t * pte, unsigned long address, unsigned long size,
unsigned long offset, pgprot_t prot, int space)
{
unsigned long end;
address &= ~PMD_MASK;
end = address + size;
if (end > PMD_SIZE)
end = PMD_SIZE;
do {
set_pte_at(mm, address, pte, mk_pte_io(offset, prot, space));
address += PAGE_SIZE;
offset += PAGE_SIZE;
pte++;
} while (address < end);
}
static inline int io_remap_pmd_range(struct mm_struct *mm, pmd_t * pmd, unsigned long address, unsigned long size,
unsigned long offset, pgprot_t prot, int space)
{
unsigned long end;
address &= ~PGDIR_MASK;
end = address + size;
if (end > PGDIR_SIZE)
end = PGDIR_SIZE;
offset -= address;
do {
pte_t *pte = pte_alloc_map(mm, NULL, pmd, address);
if (!pte)
return -ENOMEM;
io_remap_pte_range(mm, pte, address, end - address, address + offset, prot, space);
address = (address + PMD_SIZE) & PMD_MASK;
pmd++;
} while (address < end);
return 0;
}
int io_remap_pfn_range(struct vm_area_struct *vma, unsigned long from,
unsigned long pfn, unsigned long size, pgprot_t prot)
{
int error = 0;
pgd_t * dir;
unsigned long beg = from;
unsigned long end = from + size;
struct mm_struct *mm = vma->vm_mm;
int space = GET_IOSPACE(pfn);
unsigned long offset = GET_PFN(pfn) << PAGE_SHIFT;
vma->vm_flags |= VM_IO | VM_RESERVED | VM_PFNMAP;
vma->vm_pgoff = (offset >> PAGE_SHIFT) |
((unsigned long)space << 28UL);
offset -= from;
dir = pgd_offset(mm, from);
flush_cache_range(vma, beg, end);
while (from < end) {
pmd_t *pmd = pmd_alloc(mm, dir, from);
error = -ENOMEM;
if (!pmd)
break;
error = io_remap_pmd_range(mm, pmd, from, end - from, offset + from, prot, space);
if (error)
break;
from = (from + PGDIR_SIZE) & PGDIR_MASK;
dir++;
}
flush_tlb_range(vma, beg, end);
return error;
}
