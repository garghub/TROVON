static void *early_alloc_pgtable(unsigned long size)
{
void *pt;
if (init_bootmem_done)
pt = __alloc_bootmem(size, size, __pa(MAX_DMA_ADDRESS));
else
pt = __va(memblock_alloc_base(size, size,
__pa(MAX_DMA_ADDRESS)));
memset(pt, 0, size);
return pt;
}
int map_kernel_page(unsigned long ea, unsigned long pa, int flags)
{
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
if (slab_is_available()) {
pgdp = pgd_offset_k(ea);
pudp = pud_alloc(&init_mm, pgdp, ea);
if (!pudp)
return -ENOMEM;
pmdp = pmd_alloc(&init_mm, pudp, ea);
if (!pmdp)
return -ENOMEM;
ptep = pte_alloc_kernel(pmdp, ea);
if (!ptep)
return -ENOMEM;
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
} else {
#ifdef CONFIG_PPC_MMU_NOHASH
pgdp = pgd_offset_k(ea);
#ifdef PUD_TABLE_SIZE
if (pgd_none(*pgdp)) {
pudp = early_alloc_pgtable(PUD_TABLE_SIZE);
BUG_ON(pudp == NULL);
pgd_populate(&init_mm, pgdp, pudp);
}
#endif
pudp = pud_offset(pgdp, ea);
if (pud_none(*pudp)) {
pmdp = early_alloc_pgtable(PMD_TABLE_SIZE);
BUG_ON(pmdp == NULL);
pud_populate(&init_mm, pudp, pmdp);
}
pmdp = pmd_offset(pudp, ea);
if (!pmd_present(*pmdp)) {
ptep = early_alloc_pgtable(PAGE_SIZE);
BUG_ON(ptep == NULL);
pmd_populate_kernel(&init_mm, pmdp, ptep);
}
ptep = pte_offset_kernel(pmdp, ea);
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
#else
if (htab_bolt_mapping(ea, ea + PAGE_SIZE, pa, flags,
mmu_io_psize, mmu_kernel_ssize)) {
printk(KERN_ERR "Failed to do bolted mapping IO "
"memory at %016lx !\n", pa);
return -ENOMEM;
}
#endif
}
return 0;
}
void __iomem * __ioremap_at(phys_addr_t pa, void *ea, unsigned long size,
unsigned long flags)
{
unsigned long i;
if ((flags & _PAGE_PRESENT) == 0)
flags |= pgprot_val(PAGE_KERNEL);
if (flags & _PAGE_NO_CACHE)
flags &= ~_PAGE_COHERENT;
if (flags & _PAGE_4K_PFN)
return NULL;
WARN_ON(pa & ~PAGE_MASK);
WARN_ON(((unsigned long)ea) & ~PAGE_MASK);
WARN_ON(size & ~PAGE_MASK);
for (i = 0; i < size; i += PAGE_SIZE)
if (map_kernel_page((unsigned long)ea+i, pa+i, flags))
return NULL;
return (void __iomem *)ea;
}
void __iounmap_at(void *ea, unsigned long size)
{
WARN_ON(((unsigned long)ea) & ~PAGE_MASK);
WARN_ON(size & ~PAGE_MASK);
unmap_kernel_range((unsigned long)ea, size);
}
void __iomem * __ioremap_caller(phys_addr_t addr, unsigned long size,
unsigned long flags, void *caller)
{
phys_addr_t paligned;
void __iomem *ret;
paligned = addr & PAGE_MASK;
size = PAGE_ALIGN(addr + size) - paligned;
if ((size == 0) || (paligned == 0))
return NULL;
if (mem_init_done) {
struct vm_struct *area;
area = __get_vm_area_caller(size, VM_IOREMAP,
ioremap_bot, IOREMAP_END,
caller);
if (area == NULL)
return NULL;
area->phys_addr = paligned;
ret = __ioremap_at(paligned, area->addr, size, flags);
if (!ret)
vunmap(area->addr);
} else {
ret = __ioremap_at(paligned, (void *)ioremap_bot, size, flags);
if (ret)
ioremap_bot += size;
}
if (ret)
ret += addr & ~PAGE_MASK;
return ret;
}
void __iomem * __ioremap(phys_addr_t addr, unsigned long size,
unsigned long flags)
{
return __ioremap_caller(addr, size, flags, __builtin_return_address(0));
}
void __iomem * ioremap(phys_addr_t addr, unsigned long size)
{
unsigned long flags = _PAGE_NO_CACHE | _PAGE_GUARDED;
void *caller = __builtin_return_address(0);
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iomem * ioremap_wc(phys_addr_t addr, unsigned long size)
{
unsigned long flags = _PAGE_NO_CACHE;
void *caller = __builtin_return_address(0);
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iomem * ioremap_prot(phys_addr_t addr, unsigned long size,
unsigned long flags)
{
void *caller = __builtin_return_address(0);
if (flags & _PAGE_RW)
flags |= _PAGE_DIRTY;
flags &= ~(_PAGE_USER | _PAGE_EXEC);
#ifdef _PAGE_BAP_SR
flags |= _PAGE_BAP_SR;
#endif
if (ppc_md.ioremap)
return ppc_md.ioremap(addr, size, flags, caller);
return __ioremap_caller(addr, size, flags, caller);
}
void __iounmap(volatile void __iomem *token)
{
void *addr;
if (!mem_init_done)
return;
addr = (void *) ((unsigned long __force)
PCI_FIX_ADDR(token) & PAGE_MASK);
if ((unsigned long)addr < ioremap_bot) {
printk(KERN_WARNING "Attempt to iounmap early bolted mapping"
" at 0x%p\n", addr);
return;
}
vunmap(addr);
}
void iounmap(volatile void __iomem *token)
{
if (ppc_md.iounmap)
ppc_md.iounmap(token);
else
__iounmap(token);
}
