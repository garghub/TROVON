int __init sh64_tlb_init(void)
{
cpu_data->dtlb.entries = 64;
cpu_data->dtlb.step = 0x10;
cpu_data->dtlb.first = DTLB_FIXED | cpu_data->dtlb.step;
cpu_data->dtlb.next = cpu_data->dtlb.first;
cpu_data->dtlb.last = DTLB_FIXED |
((cpu_data->dtlb.entries - 1) *
cpu_data->dtlb.step);
cpu_data->itlb.entries = 64;
cpu_data->itlb.step = 0x10;
cpu_data->itlb.first = ITLB_FIXED | cpu_data->itlb.step;
cpu_data->itlb.next = cpu_data->itlb.first;
cpu_data->itlb.last = ITLB_FIXED |
((cpu_data->itlb.entries - 1) *
cpu_data->itlb.step);
return 0;
}
unsigned long long sh64_next_free_dtlb_entry(void)
{
return cpu_data->dtlb.next;
}
unsigned long long sh64_get_wired_dtlb_entry(void)
{
unsigned long long entry = sh64_next_free_dtlb_entry();
cpu_data->dtlb.first += cpu_data->dtlb.step;
cpu_data->dtlb.next += cpu_data->dtlb.step;
return entry;
}
int sh64_put_wired_dtlb_entry(unsigned long long entry)
{
__flush_tlb_slot(entry);
if (entry <= DTLB_FIXED)
return -EINVAL;
if (entry < (cpu_data->dtlb.first - cpu_data->dtlb.step))
return -EINVAL;
cpu_data->dtlb.first -= cpu_data->dtlb.step;
cpu_data->dtlb.next = entry;
return 0;
}
void sh64_setup_tlb_slot(unsigned long long config_addr, unsigned long eaddr,
unsigned long asid, unsigned long paddr)
{
unsigned long long pteh, ptel;
pteh = neff_sign_extend(eaddr);
pteh &= PAGE_MASK;
pteh |= (asid << PTEH_ASID_SHIFT) | PTEH_VALID;
ptel = neff_sign_extend(paddr);
ptel &= PAGE_MASK;
ptel |= (_PAGE_CACHABLE | _PAGE_READ | _PAGE_WRITE);
asm volatile("putcfg %0, 1, %1\n\t"
"putcfg %0, 0, %2\n"
: : "r" (config_addr), "r" (ptel), "r" (pteh));
}
void tlb_wire_entry(struct vm_area_struct *vma, unsigned long addr, pte_t pte)
{
unsigned long long entry;
unsigned long paddr, flags;
BUG_ON(dtlb_entry == ARRAY_SIZE(dtlb_entries));
local_irq_save(flags);
entry = sh64_get_wired_dtlb_entry();
dtlb_entries[dtlb_entry++] = entry;
paddr = pte_val(pte) & _PAGE_FLAGS_HARDWARE_MASK;
paddr &= ~PAGE_MASK;
sh64_setup_tlb_slot(entry, addr, get_asid(), paddr);
local_irq_restore(flags);
}
void tlb_unwire_entry(void)
{
unsigned long long entry;
unsigned long flags;
BUG_ON(!dtlb_entry);
local_irq_save(flags);
entry = dtlb_entries[dtlb_entry--];
sh64_teardown_tlb_slot(entry);
sh64_put_wired_dtlb_entry(entry);
local_irq_restore(flags);
}
