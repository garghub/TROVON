void *consistent_alloc(gfp_t gfp, size_t size, dma_addr_t *dma_handle)
{
unsigned long order, vaddr;
void *ret;
unsigned int i, err = 0;
struct page *page, *end;
#ifdef CONFIG_MMU
phys_addr_t pa;
struct vm_struct *area;
unsigned long va;
#endif
if (in_interrupt())
BUG();
size = PAGE_ALIGN(size);
order = get_order(size);
vaddr = __get_free_pages(gfp, order);
if (!vaddr)
return NULL;
flush_dcache_range(virt_to_phys((void *)vaddr),
virt_to_phys((void *)vaddr) + size);
#ifndef CONFIG_MMU
ret = (void *)vaddr;
# ifdef CONFIG_XILINX_UNCACHED_SHADOW
ret = (void *)((unsigned) ret | UNCACHED_SHADOW_MASK);
# endif
if ((unsigned int)ret > cpuinfo.dcache_base &&
(unsigned int)ret < cpuinfo.dcache_high)
pr_warn("ERROR: Your cache coherent area is CACHED!!!\n");
*dma_handle = (dma_addr_t)ret;
#else
area = get_vm_area(size, VM_ALLOC);
if (!area) {
free_pages(vaddr, order);
return NULL;
}
va = (unsigned long) area->addr;
ret = (void *)va;
*dma_handle = pa = __virt_to_phys(vaddr);
#endif
page = virt_to_page(vaddr);
end = page + (1 << order);
split_page(page, order);
for (i = 0; i < size && err == 0; i += PAGE_SIZE) {
#ifdef CONFIG_MMU
err = map_page(va + i, pa + i, _PAGE_KERNEL | _PAGE_NO_CACHE);
#endif
SetPageReserved(page);
page++;
}
while (page < end) {
__free_page(page);
page++;
}
if (err) {
free_pages(vaddr, order);
return NULL;
}
return ret;
}
static pte_t *consistent_virt_to_pte(void *vaddr)
{
unsigned long addr = (unsigned long)vaddr;
return pte_offset_kernel(pmd_offset(pgd_offset_k(addr), addr), addr);
}
unsigned long consistent_virt_to_pfn(void *vaddr)
{
pte_t *ptep = consistent_virt_to_pte(vaddr);
if (pte_none(*ptep) || !pte_present(*ptep))
return 0;
return pte_pfn(*ptep);
}
void consistent_free(size_t size, void *vaddr)
{
struct page *page;
if (in_interrupt())
BUG();
size = PAGE_ALIGN(size);
#ifndef CONFIG_MMU
# ifdef CONFIG_XILINX_UNCACHED_SHADOW
vaddr = (void *)((unsigned)vaddr & ~UNCACHED_SHADOW_MASK);
# endif
page = virt_to_page(vaddr);
do {
__free_reserved_page(page);
page++;
} while (size -= PAGE_SIZE);
#else
do {
pte_t *ptep = consistent_virt_to_pte(vaddr);
unsigned long pfn;
if (!pte_none(*ptep) && pte_present(*ptep)) {
pfn = pte_pfn(*ptep);
pte_clear(&init_mm, (unsigned int)vaddr, ptep);
if (pfn_valid(pfn)) {
page = pfn_to_page(pfn);
__free_reserved_page(page);
}
}
vaddr += PAGE_SIZE;
} while (size -= PAGE_SIZE);
flush_tlb_all();
#endif
}
void consistent_sync(void *vaddr, size_t size, int direction)
{
unsigned long start;
unsigned long end;
start = (unsigned long)vaddr;
#ifdef CONFIG_XILINX_UNCACHED_SHADOW
start &= ~UNCACHED_SHADOW_MASK;
#endif
end = start + size;
switch (direction) {
case PCI_DMA_NONE:
BUG();
case PCI_DMA_FROMDEVICE:
invalidate_dcache_range(start, end);
break;
case PCI_DMA_TODEVICE:
flush_dcache_range(start, end);
break;
case PCI_DMA_BIDIRECTIONAL:
flush_dcache_range(start, end);
break;
}
}
void consistent_sync_page(struct page *page, unsigned long offset,
size_t size, int direction)
{
unsigned long start = (unsigned long)page_address(page) + offset;
consistent_sync((void *)start, size, direction);
}
