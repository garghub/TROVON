void __update_tlb(struct vm_area_struct *vma, unsigned long address, pte_t pte)
{
unsigned long flags, pteval, vpn;
if (vma && current->active_mm != vma->vm_mm)
return;
local_irq_save(flags);
vpn = (address & MMU_VPN_MASK) | get_asid();
__raw_writel(vpn, MMU_PTEH);
pteval = pte.pte_low;
#ifdef CONFIG_X2TLB
__raw_writel(pte.pte_high, MMU_PTEA);
#else
if (cpu_data->flags & CPU_HAS_PTEA) {
__raw_writel(copy_ptea_attributes(pteval), MMU_PTEA);
}
#endif
pteval &= _PAGE_FLAGS_HARDWARE_MASK;
#ifdef CONFIG_CACHE_WRITETHROUGH
pteval |= _PAGE_WT;
#endif
__raw_writel(pteval, MMU_PTEL);
asm volatile("ldtlb": : : "memory");
local_irq_restore(flags);
}
void local_flush_tlb_one(unsigned long asid, unsigned long page)
{
unsigned long addr, data;
addr = MMU_UTLB_ADDRESS_ARRAY | MMU_PAGE_ASSOC_BIT;
data = page | asid;
jump_to_uncached();
__raw_writel(data, addr);
back_to_cached();
}
void local_flush_tlb_all(void)
{
unsigned long flags, status;
int i;
local_irq_save(flags);
jump_to_uncached();
status = __raw_readl(MMUCR);
status = ((status & MMUCR_URB) >> MMUCR_URB_SHIFT);
if (status == 0)
status = MMUCR_URB_NENTRIES;
for (i = 0; i < status; i++)
__raw_writel(0x0, MMU_UTLB_ADDRESS_ARRAY | (i << 8));
for (i = 0; i < 4; i++)
__raw_writel(0x0, MMU_ITLB_ADDRESS_ARRAY | (i << 8));
back_to_cached();
ctrl_barrier();
local_irq_restore(flags);
}
