__ref pte_t *pte_alloc_one_kernel(struct mm_struct *mm, unsigned long address)
{
pte_t *pte;
if (slab_is_available()) {
pte = (pte_t *)__get_free_page(GFP_KERNEL|__GFP_ZERO);
} else {
pte = __va(memblock_alloc(PAGE_SIZE, PAGE_SIZE));
if (pte)
clear_page(pte);
}
return pte;
}
pgtable_t pte_alloc_one(struct mm_struct *mm, unsigned long address)
{
struct page *ptepage;
gfp_t flags = GFP_KERNEL | __GFP_ZERO | __GFP_ACCOUNT;
ptepage = alloc_pages(flags, 0);
if (!ptepage)
return NULL;
if (!pgtable_page_ctor(ptepage)) {
__free_page(ptepage);
return NULL;
}
return ptepage;
}
void __iomem *
ioremap(phys_addr_t addr, unsigned long size)
{
return __ioremap_caller(addr, size, _PAGE_NO_CACHE | _PAGE_GUARDED,
__builtin_return_address(0));
}
void __iomem *
ioremap_wc(phys_addr_t addr, unsigned long size)
{
return __ioremap_caller(addr, size, _PAGE_NO_CACHE,
__builtin_return_address(0));
}
void __iomem *
ioremap_prot(phys_addr_t addr, unsigned long size, unsigned long flags)
{
if ((flags & (_PAGE_RW | _PAGE_RO)) != _PAGE_RO)
flags |= _PAGE_DIRTY | _PAGE_HWWRITE;
flags &= ~(_PAGE_USER | _PAGE_EXEC);
#ifdef _PAGE_BAP_SR
flags |= _PAGE_BAP_SR;
#endif
return __ioremap_caller(addr, size, flags, __builtin_return_address(0));
}
void __iomem *
__ioremap(phys_addr_t addr, unsigned long size, unsigned long flags)
{
return __ioremap_caller(addr, size, flags, __builtin_return_address(0));
}
void __iomem *
__ioremap_caller(phys_addr_t addr, unsigned long size, unsigned long flags,
void *caller)
{
unsigned long v, i;
phys_addr_t p;
int err;
if ((flags & _PAGE_PRESENT) == 0)
flags |= pgprot_val(PAGE_KERNEL);
if (flags & _PAGE_NO_CACHE)
flags &= ~_PAGE_COHERENT;
p = addr & PAGE_MASK;
size = PAGE_ALIGN(addr + size) - p;
if (p < 16*1024*1024)
p += _ISA_MEM_BASE;
#ifndef CONFIG_CRASH_DUMP
if (slab_is_available() && (p < virt_to_phys(high_memory)) &&
!(__allow_ioremap_reserved && memblock_is_region_reserved(p, size))) {
printk("__ioremap(): phys addr 0x%llx is RAM lr %ps\n",
(unsigned long long)p, __builtin_return_address(0));
return NULL;
}
#endif
if (size == 0)
return NULL;
v = p_block_mapped(p);
if (v)
goto out;
if (slab_is_available()) {
struct vm_struct *area;
area = get_vm_area_caller(size, VM_IOREMAP, caller);
if (area == 0)
return NULL;
area->phys_addr = p;
v = (unsigned long) area->addr;
} else {
v = (ioremap_bot -= size);
}
err = 0;
for (i = 0; i < size && err == 0; i += PAGE_SIZE)
err = map_kernel_page(v+i, p+i, flags);
if (err) {
if (slab_is_available())
vunmap((void *)v);
return NULL;
}
out:
return (void __iomem *) (v + ((unsigned long)addr & ~PAGE_MASK));
}
void iounmap(volatile void __iomem *addr)
{
if (v_block_mapped((unsigned long)addr))
return;
if (addr > high_memory && (unsigned long) addr < ioremap_bot)
vunmap((void *) (PAGE_MASK & (unsigned long)addr));
}
int map_kernel_page(unsigned long va, phys_addr_t pa, int flags)
{
pmd_t *pd;
pte_t *pg;
int err = -ENOMEM;
pd = pmd_offset(pud_offset(pgd_offset_k(va), va), va);
pg = pte_alloc_kernel(pd, va);
if (pg != 0) {
err = 0;
BUG_ON((pte_val(*pg) & (_PAGE_PRESENT | _PAGE_HASHPTE)) &&
flags);
set_pte_at(&init_mm, va, pg, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
}
smp_wmb();
return err;
}
void __init __mapin_ram_chunk(unsigned long offset, unsigned long top)
{
unsigned long v, s, f;
phys_addr_t p;
int ktext;
s = offset;
v = PAGE_OFFSET + s;
p = memstart_addr + s;
for (; s < top; s += PAGE_SIZE) {
ktext = ((char *)v >= _stext && (char *)v < etext) ||
((char *)v >= _sinittext && (char *)v < _einittext);
f = ktext ? pgprot_val(PAGE_KERNEL_TEXT) : pgprot_val(PAGE_KERNEL);
map_kernel_page(v, p, f);
#ifdef CONFIG_PPC_STD_MMU_32
if (ktext)
hash_preload(&init_mm, v, 0, 0x300);
#endif
v += PAGE_SIZE;
p += PAGE_SIZE;
}
}
void __init mapin_ram(void)
{
unsigned long s, top;
#ifndef CONFIG_WII
top = total_lowmem;
s = mmu_mapin_ram(top);
__mapin_ram_chunk(s, top);
#else
if (!wii_hole_size) {
s = mmu_mapin_ram(total_lowmem);
__mapin_ram_chunk(s, total_lowmem);
} else {
top = wii_hole_start;
s = mmu_mapin_ram(top);
__mapin_ram_chunk(s, top);
top = memblock_end_of_DRAM();
s = wii_mmu_mapin_mem2(top);
__mapin_ram_chunk(s, top);
}
#endif
}
int
get_pteptr(struct mm_struct *mm, unsigned long addr, pte_t **ptep, pmd_t **pmdp)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
int retval = 0;
pgd = pgd_offset(mm, addr & PAGE_MASK);
if (pgd) {
pud = pud_offset(pgd, addr & PAGE_MASK);
if (pud && pud_present(*pud)) {
pmd = pmd_offset(pud, addr & PAGE_MASK);
if (pmd_present(*pmd)) {
pte = pte_offset_map(pmd, addr & PAGE_MASK);
if (pte) {
retval = 1;
*ptep = pte;
if (pmdp)
*pmdp = pmd;
}
}
}
}
return(retval);
}
static int __change_page_attr(struct page *page, pgprot_t prot)
{
pte_t *kpte;
pmd_t *kpmd;
unsigned long address;
BUG_ON(PageHighMem(page));
address = (unsigned long)page_address(page);
if (v_block_mapped(address))
return 0;
if (!get_pteptr(&init_mm, address, &kpte, &kpmd))
return -EINVAL;
__set_pte_at(&init_mm, address, kpte, mk_pte(page, prot), 0);
wmb();
flush_tlb_page(NULL, address);
pte_unmap(kpte);
return 0;
}
static int change_page_attr(struct page *page, int numpages, pgprot_t prot)
{
int i, err = 0;
unsigned long flags;
local_irq_save(flags);
for (i = 0; i < numpages; i++, page++) {
err = __change_page_attr(page, prot);
if (err)
break;
}
local_irq_restore(flags);
return err;
}
void __kernel_map_pages(struct page *page, int numpages, int enable)
{
if (PageHighMem(page))
return;
change_page_attr(page, numpages, enable ? PAGE_KERNEL : __pgprot(0));
}
void __set_fixmap (enum fixed_addresses idx, phys_addr_t phys, pgprot_t flags)
{
unsigned long address = __fix_to_virt(idx);
if (idx >= __end_of_fixed_addresses) {
BUG();
return;
}
map_kernel_page(address, phys, pgprot_val(flags));
fixmaps++;
}
