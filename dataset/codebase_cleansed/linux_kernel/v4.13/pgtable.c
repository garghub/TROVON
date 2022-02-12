static void __iomem *__ioremap(phys_addr_t addr, unsigned long size,
unsigned long flags)
{
unsigned long v, i;
phys_addr_t p;
int err;
p = addr & PAGE_MASK;
size = PAGE_ALIGN(addr + size) - p;
if (mem_init_done &&
p >= memory_start && p < virt_to_phys(high_memory) &&
!(p >= __virt_to_phys((phys_addr_t)__bss_stop) &&
p < __virt_to_phys((phys_addr_t)__bss_stop))) {
pr_warn("__ioremap(): phys addr "PTE_FMT" is RAM lr %pf\n",
(unsigned long)p, __builtin_return_address(0));
return NULL;
}
if (size == 0)
return NULL;
if (mem_init_done) {
struct vm_struct *area;
area = get_vm_area(size, VM_IOREMAP);
if (area == NULL)
return NULL;
v = (unsigned long) area->addr;
} else {
v = (ioremap_bot -= size);
}
if ((flags & _PAGE_PRESENT) == 0)
flags |= _PAGE_KERNEL;
if (flags & _PAGE_NO_CACHE)
flags |= _PAGE_GUARDED;
err = 0;
for (i = 0; i < size && err == 0; i += PAGE_SIZE)
err = map_page(v + i, p + i, flags);
if (err) {
if (mem_init_done)
vfree((void *)v);
return NULL;
}
return (void __iomem *) (v + ((unsigned long)addr & ~PAGE_MASK));
}
void __iomem *ioremap(phys_addr_t addr, unsigned long size)
{
return __ioremap(addr, size, _PAGE_NO_CACHE);
}
void iounmap(void __iomem *addr)
{
if ((__force void *)addr > high_memory &&
(unsigned long) addr < ioremap_bot)
vfree((void *) (PAGE_MASK & (unsigned long) addr));
}
int map_page(unsigned long va, phys_addr_t pa, int flags)
{
pmd_t *pd;
pte_t *pg;
int err = -ENOMEM;
pd = pmd_offset(pgd_offset_k(va), va);
pg = pte_alloc_kernel(pd, va);
if (pg != NULL) {
err = 0;
set_pte_at(&init_mm, va, pg, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
if (unlikely(mem_init_done))
_tlbie(va);
}
return err;
}
void __init mapin_ram(void)
{
unsigned long v, p, s, f;
v = CONFIG_KERNEL_START;
p = memory_start;
for (s = 0; s < lowmem_size; s += PAGE_SIZE) {
f = _PAGE_PRESENT | _PAGE_ACCESSED |
_PAGE_SHARED | _PAGE_HWEXEC;
if ((char *) v < _stext || (char *) v >= _etext)
f |= _PAGE_WRENABLE;
else
f |= _PAGE_USER;
map_page(v, p, f);
v += PAGE_SIZE;
p += PAGE_SIZE;
}
}
static int get_pteptr(struct mm_struct *mm, unsigned long addr, pte_t **ptep)
{
pgd_t *pgd;
pmd_t *pmd;
pte_t *pte;
int retval = 0;
pgd = pgd_offset(mm, addr & PAGE_MASK);
if (pgd) {
pmd = pmd_offset(pgd, addr & PAGE_MASK);
if (pmd_present(*pmd)) {
pte = pte_offset_kernel(pmd, addr & PAGE_MASK);
if (pte) {
retval = 1;
*ptep = pte;
}
}
}
return retval;
}
unsigned long iopa(unsigned long addr)
{
unsigned long pa;
pte_t *pte;
struct mm_struct *mm;
if (addr < TASK_SIZE)
mm = current->mm;
else
mm = &init_mm;
pa = 0;
if (get_pteptr(mm, addr, &pte))
pa = (pte_val(*pte) & PAGE_MASK) | (addr & ~PAGE_MASK);
return pa;
}
__ref pte_t *pte_alloc_one_kernel(struct mm_struct *mm,
unsigned long address)
{
pte_t *pte;
if (mem_init_done) {
pte = (pte_t *)__get_free_page(GFP_KERNEL | __GFP_ZERO);
} else {
pte = (pte_t *)early_get_page();
if (pte)
clear_page(pte);
}
return pte;
}
void __set_fixmap(enum fixed_addresses idx, phys_addr_t phys, pgprot_t flags)
{
unsigned long address = __fix_to_virt(idx);
if (idx >= __end_of_fixed_addresses)
BUG();
map_page(address, phys, pgprot_val(flags));
}
