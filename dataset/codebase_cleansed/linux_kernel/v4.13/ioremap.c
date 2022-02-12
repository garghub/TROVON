static inline bool arc_uncached_addr_space(phys_addr_t paddr)
{
if (is_isa_arcompact()) {
if (paddr >= ARC_UNCACHED_ADDR_SPACE)
return true;
} else if (paddr >= perip_base && paddr <= perip_end) {
return true;
}
return false;
}
void __iomem *ioremap(phys_addr_t paddr, unsigned long size)
{
phys_addr_t end;
end = paddr + size - 1;
if (!size || (end < paddr))
return NULL;
if (arc_uncached_addr_space(paddr))
return (void __iomem *)(u32)paddr;
return ioremap_prot(paddr, size, PAGE_KERNEL_NO_CACHE);
}
void __iomem *ioremap_prot(phys_addr_t paddr, unsigned long size,
unsigned long flags)
{
unsigned long vaddr;
struct vm_struct *area;
phys_addr_t off, end;
pgprot_t prot = __pgprot(flags);
end = paddr + size - 1;
if ((!size) || (end < paddr))
return NULL;
if (!slab_is_available())
return NULL;
prot = pgprot_noncached(prot);
off = paddr & ~PAGE_MASK;
paddr &= PAGE_MASK;
size = PAGE_ALIGN(end + 1) - paddr;
area = get_vm_area(size, VM_IOREMAP);
if (!area)
return NULL;
area->phys_addr = paddr;
vaddr = (unsigned long)area->addr;
if (ioremap_page_range(vaddr, vaddr + size, paddr, prot)) {
vunmap((void __force *)vaddr);
return NULL;
}
return (void __iomem *)(off + (char __iomem *)vaddr);
}
void iounmap(const void __iomem *addr)
{
if (arc_uncached_addr_space((phys_addr_t)(u32)addr))
return;
vfree((void *)(PAGE_MASK & (unsigned long __force)addr));
}
