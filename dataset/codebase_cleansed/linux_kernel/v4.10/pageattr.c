static int change_page_range(pte_t *ptep, pgtable_t token, unsigned long addr,
void *data)
{
struct page_change_data *cdata = data;
pte_t pte = *ptep;
pte = clear_pte_bit(pte, cdata->clear_mask);
pte = set_pte_bit(pte, cdata->set_mask);
set_pte(ptep, pte);
return 0;
}
static int __change_memory_common(unsigned long start, unsigned long size,
pgprot_t set_mask, pgprot_t clear_mask)
{
struct page_change_data data;
int ret;
data.set_mask = set_mask;
data.clear_mask = clear_mask;
ret = apply_to_page_range(&init_mm, start, size, change_page_range,
&data);
flush_tlb_kernel_range(start, start + size);
return ret;
}
static int change_memory_common(unsigned long addr, int numpages,
pgprot_t set_mask, pgprot_t clear_mask)
{
unsigned long start = addr;
unsigned long size = PAGE_SIZE*numpages;
unsigned long end = start + size;
struct vm_struct *area;
if (!PAGE_ALIGNED(addr)) {
start &= PAGE_MASK;
end = start + size;
WARN_ON_ONCE(1);
}
area = find_vm_area((void *)addr);
if (!area ||
end > (unsigned long)area->addr + area->size ||
!(area->flags & VM_ALLOC))
return -EINVAL;
if (!numpages)
return 0;
return __change_memory_common(start, size, set_mask, clear_mask);
}
int set_memory_ro(unsigned long addr, int numpages)
{
return change_memory_common(addr, numpages,
__pgprot(PTE_RDONLY),
__pgprot(PTE_WRITE));
}
int set_memory_rw(unsigned long addr, int numpages)
{
return change_memory_common(addr, numpages,
__pgprot(PTE_WRITE),
__pgprot(PTE_RDONLY));
}
int set_memory_nx(unsigned long addr, int numpages)
{
return change_memory_common(addr, numpages,
__pgprot(PTE_PXN),
__pgprot(0));
}
int set_memory_x(unsigned long addr, int numpages)
{
return change_memory_common(addr, numpages,
__pgprot(0),
__pgprot(PTE_PXN));
}
void __kernel_map_pages(struct page *page, int numpages, int enable)
{
unsigned long addr = (unsigned long) page_address(page);
if (enable)
__change_memory_common(addr, PAGE_SIZE * numpages,
__pgprot(PTE_VALID),
__pgprot(0));
else
__change_memory_common(addr, PAGE_SIZE * numpages,
__pgprot(0),
__pgprot(PTE_VALID));
}
bool kernel_page_present(struct page *page)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
unsigned long addr = (unsigned long)page_address(page);
pgd = pgd_offset_k(addr);
if (pgd_none(*pgd))
return false;
pud = pud_offset(pgd, addr);
if (pud_none(*pud))
return false;
if (pud_sect(*pud))
return true;
pmd = pmd_offset(pud, addr);
if (pmd_none(*pmd))
return false;
if (pmd_sect(*pmd))
return true;
pte = pte_offset_kernel(pmd, addr);
return pte_valid(*pte);
}
