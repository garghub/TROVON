static inline void flush_itlb(void)
{
switch (current_cpu_type()) {
case CPU_LOONGSON2:
case CPU_LOONGSON3:
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
int entry, ftlbhighset;
local_irq_save(flags);
old_ctx = read_c0_entryhi();
htw_stop();
write_c0_entrylo0(0);
write_c0_entrylo1(0);
entry = read_c0_wired();
if (cpu_has_tlbinv) {
if (current_cpu_data.tlbsizevtlb) {
write_c0_index(0);
mtc0_tlbw_hazard();
tlbinvf();
}
ftlbhighset = current_cpu_data.tlbsizevtlb +
current_cpu_data.tlbsizeftlbsets;
for (entry = current_cpu_data.tlbsizevtlb;
entry < ftlbhighset;
entry++) {
write_c0_index(entry);
mtc0_tlbw_hazard();
tlbinvf();
}
} else {
while (entry < current_cpu_data.tlbsize) {
write_c0_entryhi(UNIQUE_ENTRYHI(entry));
write_c0_index(entry);
mtc0_tlbw_hazard();
tlb_write_indexed();
entry++;
}
}
tlbw_use_hazard();
write_c0_entryhi(old_ctx);
htw_start();
flush_itlb();
local_irq_restore(flags);
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
local_irq_save(flags);
start = round_down(start, PAGE_SIZE << 1);
end = round_up(end, PAGE_SIZE << 1);
size = (end - start) >> (PAGE_SHIFT + 1);
if (size <= (current_cpu_data.tlbsizeftlbsets ?
current_cpu_data.tlbsize / 8 :
current_cpu_data.tlbsize / 2)) {
int oldpid = read_c0_entryhi();
int newpid = cpu_asid(cpu, mm);
htw_stop();
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
htw_start();
} else {
drop_mmu_context(mm, cpu);
}
flush_itlb();
local_irq_restore(flags);
}
}
void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
unsigned long size, flags;
local_irq_save(flags);
size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
size = (size + 1) >> 1;
if (size <= (current_cpu_data.tlbsizeftlbsets ?
current_cpu_data.tlbsize / 8 :
current_cpu_data.tlbsize / 2)) {
int pid = read_c0_entryhi();
start &= (PAGE_MASK << 1);
end += ((PAGE_SIZE << 1) - 1);
end &= (PAGE_MASK << 1);
htw_stop();
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
htw_start();
} else {
local_flush_tlb_all();
}
flush_itlb();
local_irq_restore(flags);
}
void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
int cpu = smp_processor_id();
if (cpu_context(cpu, vma->vm_mm) != 0) {
unsigned long flags;
int oldpid, newpid, idx;
newpid = cpu_asid(cpu, vma->vm_mm);
page &= (PAGE_MASK << 1);
local_irq_save(flags);
oldpid = read_c0_entryhi();
htw_stop();
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
htw_start();
flush_itlb_vm(vma);
local_irq_restore(flags);
}
}
void local_flush_tlb_one(unsigned long page)
{
unsigned long flags;
int oldpid, idx;
local_irq_save(flags);
oldpid = read_c0_entryhi();
htw_stop();
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
htw_start();
flush_itlb();
local_irq_restore(flags);
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
local_irq_save(flags);
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
local_irq_restore(flags);
}
void add_wired_entry(unsigned long entrylo0, unsigned long entrylo1,
unsigned long entryhi, unsigned long pagemask)
{
unsigned long flags;
unsigned long wired;
unsigned long old_pagemask;
unsigned long old_ctx;
local_irq_save(flags);
old_ctx = read_c0_entryhi();
htw_stop();
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
htw_start();
write_c0_pagemask(old_pagemask);
local_flush_tlb_all();
local_irq_restore(flags);
}
int __init has_transparent_hugepage(void)
{
unsigned int mask;
unsigned long flags;
local_irq_save(flags);
write_c0_pagemask(PM_HUGE_MASK);
back_to_back_c0_hazard();
mask = read_c0_pagemask();
write_c0_pagemask(PM_DEFAULT_MASK);
local_irq_restore(flags);
return mask == PM_HUGE_MASK;
}
__init int add_temporary_entry(unsigned long entrylo0, unsigned long entrylo1,
unsigned long entryhi, unsigned long pagemask)
{
int ret = 0;
unsigned long flags;
unsigned long wired;
unsigned long old_pagemask;
unsigned long old_ctx;
local_irq_save(flags);
old_ctx = read_c0_entryhi();
old_pagemask = read_c0_pagemask();
wired = read_c0_wired();
if (--temp_tlb_entry < wired) {
printk(KERN_WARNING
"No TLB space left for add_temporary_entry\n");
ret = -ENOSPC;
goto out;
}
write_c0_index(temp_tlb_entry);
write_c0_pagemask(pagemask);
write_c0_entryhi(entryhi);
write_c0_entrylo0(entrylo0);
write_c0_entrylo1(entrylo1);
mtc0_tlbw_hazard();
tlb_write_indexed();
tlbw_use_hazard();
write_c0_entryhi(old_ctx);
write_c0_pagemask(old_pagemask);
out:
local_irq_restore(flags);
return ret;
}
static int __init set_ntlb(char *str)
{
get_option(&str, &ntlb);
return 1;
}
static void r4k_tlb_configure(void)
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
temp_tlb_entry = current_cpu_data.tlbsize - 1;
local_flush_tlb_all();
}
void tlb_init(void)
{
r4k_tlb_configure();
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
static int r4k_tlb_pm_notifier(struct notifier_block *self, unsigned long cmd,
void *v)
{
switch (cmd) {
case CPU_PM_ENTER_FAILED:
case CPU_PM_EXIT:
r4k_tlb_configure();
break;
}
return NOTIFY_OK;
}
static int __init r4k_tlb_init_pm(void)
{
return cpu_pm_register_notifier(&r4k_tlb_pm_notifier_block);
}
