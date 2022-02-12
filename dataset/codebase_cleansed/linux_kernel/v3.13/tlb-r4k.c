static inline void flush_itlb(void)
{
switch (current_cpu_type()) {
case CPU_LOONGSON2:
write_c0_diag(4);
break;
default:
break;
}
}
static inline void flush_itlb_vm(struct vm_area_struct *vma)
{
if (vma->vm_flags & VM_EXEC)
flush_itlb();
}
void local_flush_tlb_all(void)
{
unsigned long flags;
unsigned long old_ctx;
int entry;
ENTER_CRITICAL(flags);
old_ctx = read_c0_entryhi();
write_c0_entrylo0(0);
write_c0_entrylo1(0);
entry = read_c0_wired();
while (entry < current_cpu_data.tlbsize) {
write_c0_entryhi(UNIQUE_ENTRYHI(entry));
write_c0_index(entry);
mtc0_tlbw_hazard();
tlb_write_indexed();
entry++;
}
tlbw_use_hazard();
write_c0_entryhi(old_ctx);
flush_itlb();
EXIT_CRITICAL(flags);
}
void local_flush_tlb_mm(struct mm_struct *mm)
{
int cpu;
preempt_disable();
cpu = smp_processor_id();
if (cpu_context(cpu, mm) != 0) {
drop_mmu_context(mm, cpu);
}
preempt_enable();
}
void local_flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
int cpu = smp_processor_id();
if (cpu_context(cpu, mm) != 0) {
unsigned long size, flags;
ENTER_CRITICAL(flags);
start = round_down(start, PAGE_SIZE << 1);
end = round_up(end, PAGE_SIZE << 1);
size = (end - start) >> (PAGE_SHIFT + 1);
if (size <= current_cpu_data.tlbsize/2) {
int oldpid = read_c0_entryhi();
int newpid = cpu_asid(cpu, mm);
while (start < end) {
int idx;
write_c0_entryhi(start | newpid);
start += (PAGE_SIZE << 1);
mtc0_tlbw_hazard();
tlb_probe();
tlb_probe_hazard();
idx = read_c0_index();
write_c0_entrylo0(0);
write_c0_entrylo1(0);
if (idx < 0)
continue;
write_c0_entryhi(UNIQUE_ENTRYHI(idx));
mtc0_tlbw_hazard();
tlb_write_indexed();
}
tlbw_use_hazard();
write_c0_entryhi(oldpid);
} else {
drop_mmu_context(mm, cpu);
}
flush_itlb();
EXIT_CRITICAL(flags);
}
}
void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
unsigned long size, flags;
ENTER_CRITICAL(flags);
size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
size = (size + 1) >> 1;
if (size <= current_cpu_data.tlbsize / 2) {
int pid = read_c0_entryhi();
start &= (PAGE_MASK << 1);
end += ((PAGE_SIZE << 1) - 1);
end &= (PAGE_MASK << 1);
while (start < end) {
int idx;
write_c0_entryhi(start);
start += (PAGE_SIZE << 1);
mtc0_tlbw_hazard();
tlb_probe();
tlb_probe_hazard();
idx = read_c0_index();
write_c0_entrylo0(0);
write_c0_entrylo1(0);
if (idx < 0)
continue;
write_c0_entryhi(UNIQUE_ENTRYHI(idx));
mtc0_tlbw_hazard();
tlb_write_indexed();
}
tlbw_use_hazard();
write_c0_entryhi(pid);
} else {
local_flush_tlb_all();
}
flush_itlb();
EXIT_CRITICAL(flags);
}
void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
int cpu = smp_processor_id();
if (cpu_context(cpu, vma->vm_mm) != 0) {
unsigned long flags;
int oldpid, newpid, idx;
newpid = cpu_asid(cpu, vma->vm_mm);
page &= (PAGE_MASK << 1);
ENTER_CRITICAL(flags);
oldpid = read_c0_entryhi();
write_c0_entryhi(page | newpid);
mtc0_tlbw_hazard();
tlb_probe();
tlb_probe_hazard();
idx = read_c0_index();
write_c0_entrylo0(0);
write_c0_entrylo1(0);
if (idx < 0)
goto finish;
write_c0_entryhi(UNIQUE_ENTRYHI(idx));
mtc0_tlbw_hazard();
tlb_write_indexed();
tlbw_use_hazard();
finish:
write_c0_entryhi(oldpid);
flush_itlb_vm(vma);
EXIT_CRITICAL(flags);
}
}
void local_flush_tlb_one(unsigned long page)
{
unsigned long flags;
int oldpid, idx;
ENTER_CRITICAL(flags);
oldpid = read_c0_entryhi();
page &= (PAGE_MASK << 1);
write_c0_entryhi(page);
mtc0_tlbw_hazard();
tlb_probe();
tlb_probe_hazard();
idx = read_c0_index();
write_c0_entrylo0(0);
write_c0_entrylo1(0);
if (idx >= 0) {
write_c0_entryhi(UNIQUE_ENTRYHI(idx));
mtc0_tlbw_hazard();
tlb_write_indexed();
tlbw_use_hazard();
}
write_c0_entryhi(oldpid);
flush_itlb();
EXIT_CRITICAL(flags);
}
void __update_tlb(struct vm_area_struct * vma, unsigned long address, pte_t pte)
{
unsigned long flags;
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
int idx, pid;
if (current->active_mm != vma->vm_mm)
return;
ENTER_CRITICAL(flags);
pid = read_c0_entryhi() & ASID_MASK;
address &= (PAGE_MASK << 1);
write_c0_entryhi(address | pid);
pgdp = pgd_offset(vma->vm_mm, address);
mtc0_tlbw_hazard();
tlb_probe();
tlb_probe_hazard();
pudp = pud_offset(pgdp, address);
pmdp = pmd_offset(pudp, address);
idx = read_c0_index();
#ifdef CONFIG_MIPS_HUGE_TLB_SUPPORT
if (pmd_huge(*pmdp)) {
unsigned long lo;
write_c0_pagemask(PM_HUGE_MASK);
ptep = (pte_t *)pmdp;
lo = pte_to_entrylo(pte_val(*ptep));
write_c0_entrylo0(lo);
write_c0_entrylo1(lo + (HPAGE_SIZE >> 7));
mtc0_tlbw_hazard();
if (idx < 0)
tlb_write_random();
else
tlb_write_indexed();
tlbw_use_hazard();
write_c0_pagemask(PM_DEFAULT_MASK);
} else
#endif
{
ptep = pte_offset_map(pmdp, address);
#if defined(CONFIG_64BIT_PHYS_ADDR) && defined(CONFIG_CPU_MIPS32)
write_c0_entrylo0(ptep->pte_high);
ptep++;
write_c0_entrylo1(ptep->pte_high);
#else
write_c0_entrylo0(pte_to_entrylo(pte_val(*ptep++)));
write_c0_entrylo1(pte_to_entrylo(pte_val(*ptep)));
#endif
mtc0_tlbw_hazard();
if (idx < 0)
tlb_write_random();
else
tlb_write_indexed();
}
tlbw_use_hazard();
flush_itlb_vm(vma);
EXIT_CRITICAL(flags);
}
void add_wired_entry(unsigned long entrylo0, unsigned long entrylo1,
unsigned long entryhi, unsigned long pagemask)
{
unsigned long flags;
unsigned long wired;
unsigned long old_pagemask;
unsigned long old_ctx;
ENTER_CRITICAL(flags);
old_ctx = read_c0_entryhi();
old_pagemask = read_c0_pagemask();
wired = read_c0_wired();
write_c0_wired(wired + 1);
write_c0_index(wired);
tlbw_use_hazard();
write_c0_pagemask(pagemask);
write_c0_entryhi(entryhi);
write_c0_entrylo0(entrylo0);
write_c0_entrylo1(entrylo1);
mtc0_tlbw_hazard();
tlb_write_indexed();
tlbw_use_hazard();
write_c0_entryhi(old_ctx);
tlbw_use_hazard();
write_c0_pagemask(old_pagemask);
local_flush_tlb_all();
EXIT_CRITICAL(flags);
}
int __init has_transparent_hugepage(void)
{
unsigned int mask;
unsigned long flags;
ENTER_CRITICAL(flags);
write_c0_pagemask(PM_HUGE_MASK);
back_to_back_c0_hazard();
mask = read_c0_pagemask();
write_c0_pagemask(PM_DEFAULT_MASK);
EXIT_CRITICAL(flags);
return mask == PM_HUGE_MASK;
}
static int __init set_ntlb(char *str)
{
get_option(&str, &ntlb);
return 1;
}
void tlb_init(void)
{
write_c0_pagemask(PM_DEFAULT_MASK);
write_c0_wired(0);
if (current_cpu_type() == CPU_R10000 ||
current_cpu_type() == CPU_R12000 ||
current_cpu_type() == CPU_R14000)
write_c0_framemask(0);
if (cpu_has_rixi) {
u32 pg = PG_RIE | PG_XIE;
#ifdef CONFIG_64BIT
pg |= PG_ELPA;
#endif
write_c0_pagegrain(pg);
}
local_flush_tlb_all();
if (ntlb) {
if (ntlb > 1 && ntlb <= current_cpu_data.tlbsize) {
int wired = current_cpu_data.tlbsize - ntlb;
write_c0_wired(wired);
write_c0_index(wired-1);
printk("Restricting TLB to %d entries\n", ntlb);
} else
printk("Ignoring invalid argument ntlb=%d\n", ntlb);
}
build_tlb_refill_handler();
}
