static int is_io_mapping_possible(resource_size_t base, unsigned long size)
{
#if !defined(CONFIG_X86_PAE) && defined(CONFIG_PHYS_ADDR_T_64BIT)
if (base + size > 0x100000000ULL)
return 0;
#endif
return 1;
}
int iomap_create_wc(resource_size_t base, unsigned long size, pgprot_t *prot)
{
unsigned long flag = _PAGE_CACHE_WC;
int ret;
if (!is_io_mapping_possible(base, size))
return -EINVAL;
ret = io_reserve_memtype(base, base + size, &flag);
if (ret)
return ret;
*prot = __pgprot(__PAGE_KERNEL | flag);
return 0;
}
void iomap_free(resource_size_t base, unsigned long size)
{
io_free_memtype(base, base + size);
}
void *kmap_atomic_prot_pfn(unsigned long pfn, pgprot_t prot)
{
unsigned long vaddr;
int idx, type;
pagefault_disable();
type = kmap_atomic_idx_push();
idx = type + KM_TYPE_NR * smp_processor_id();
vaddr = __fix_to_virt(FIX_KMAP_BEGIN + idx);
set_pte(kmap_pte - idx, pfn_pte(pfn, prot));
arch_flush_lazy_mmu_mode();
return (void *)vaddr;
}
void __iomem *
iomap_atomic_prot_pfn(unsigned long pfn, pgprot_t prot)
{
if (!pat_enabled && pgprot_val(prot) == pgprot_val(PAGE_KERNEL_WC))
prot = PAGE_KERNEL_UC_MINUS;
return (void __force __iomem *) kmap_atomic_prot_pfn(pfn, prot);
}
void
iounmap_atomic(void __iomem *kvaddr)
{
unsigned long vaddr = (unsigned long) kvaddr & PAGE_MASK;
if (vaddr >= __fix_to_virt(FIX_KMAP_END) &&
vaddr <= __fix_to_virt(FIX_KMAP_BEGIN)) {
int idx, type;
type = kmap_atomic_idx();
idx = type + KM_TYPE_NR * smp_processor_id();
#ifdef CONFIG_DEBUG_HIGHMEM
WARN_ON_ONCE(vaddr != __fix_to_virt(FIX_KMAP_BEGIN + idx));
#endif
kpte_clear_flush(kmap_pte-idx, vaddr);
kmap_atomic_idx_pop();
}
pagefault_enable();
}
