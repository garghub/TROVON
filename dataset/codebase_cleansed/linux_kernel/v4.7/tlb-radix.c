static inline void __tlbiel_pid(unsigned long pid, int set,
unsigned long ric)
{
unsigned long rb,rs,prs,r;
rb = PPC_BIT(53);
rb |= set << PPC_BITLSHIFT(51);
rs = ((unsigned long)pid) << PPC_BITLSHIFT(31);
prs = 1;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(".long 0x7c000224 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
}
static inline void _tlbiel_pid(unsigned long pid, unsigned long ric)
{
int set;
for (set = 0; set < POWER9_TLB_SETS_RADIX ; set++) {
__tlbiel_pid(pid, set, ric);
}
return;
}
static inline void _tlbie_pid(unsigned long pid, unsigned long ric)
{
unsigned long rb,rs,prs,r;
rb = PPC_BIT(53);
rs = pid << PPC_BITLSHIFT(31);
prs = 1;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(".long 0x7c000264 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
static inline void _tlbiel_va(unsigned long va, unsigned long pid,
unsigned long ap, unsigned long ric)
{
unsigned long rb,rs,prs,r;
rb = va & ~(PPC_BITMASK(52, 63));
rb |= ap << PPC_BITLSHIFT(58);
rs = pid << PPC_BITLSHIFT(31);
prs = 1;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(".long 0x7c000224 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
}
static inline void _tlbie_va(unsigned long va, unsigned long pid,
unsigned long ap, unsigned long ric)
{
unsigned long rb,rs,prs,r;
rb = va & ~(PPC_BITMASK(52, 63));
rb |= ap << PPC_BITLSHIFT(58);
rs = pid << PPC_BITLSHIFT(31);
prs = 1;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(".long 0x7c000264 | (%0 << 11) | (%1 << 16) |"
"(%2 << 17) | (%3 << 18) | (%4 << 21)"
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void radix__local_flush_tlb_mm(struct mm_struct *mm)
{
unsigned long pid;
preempt_disable();
pid = mm->context.id;
if (pid != MMU_NO_CONTEXT)
_tlbiel_pid(pid, RIC_FLUSH_ALL);
preempt_enable();
}
void radix__local_flush_tlb_pwc(struct mmu_gather *tlb, unsigned long addr)
{
unsigned long pid;
struct mm_struct *mm = tlb->mm;
preempt_disable();
pid = mm->context.id;
if (pid != MMU_NO_CONTEXT)
_tlbiel_pid(pid, RIC_FLUSH_PWC);
preempt_enable();
}
void radix___local_flush_tlb_page(struct mm_struct *mm, unsigned long vmaddr,
unsigned long ap, int nid)
{
unsigned long pid;
preempt_disable();
pid = mm ? mm->context.id : 0;
if (pid != MMU_NO_CONTEXT)
_tlbiel_va(vmaddr, pid, ap, RIC_FLUSH_TLB);
preempt_enable();
}
void radix__local_flush_tlb_page(struct vm_area_struct *vma, unsigned long vmaddr)
{
#ifdef CONFIG_HUGETLB_PAGE
if (vma && is_vm_hugetlb_page(vma))
return __local_flush_hugetlb_page(vma, vmaddr);
#endif
radix___local_flush_tlb_page(vma ? vma->vm_mm : NULL, vmaddr,
mmu_get_ap(mmu_virtual_psize), 0);
}
static int mm_is_core_local(struct mm_struct *mm)
{
return cpumask_subset(mm_cpumask(mm),
topology_sibling_cpumask(smp_processor_id()));
}
void radix__flush_tlb_mm(struct mm_struct *mm)
{
unsigned long pid;
preempt_disable();
pid = mm->context.id;
if (unlikely(pid == MMU_NO_CONTEXT))
goto no_context;
if (!mm_is_core_local(mm)) {
int lock_tlbie = !mmu_has_feature(MMU_FTR_LOCKLESS_TLBIE);
if (lock_tlbie)
raw_spin_lock(&native_tlbie_lock);
_tlbie_pid(pid, RIC_FLUSH_ALL);
if (lock_tlbie)
raw_spin_unlock(&native_tlbie_lock);
} else
_tlbiel_pid(pid, RIC_FLUSH_ALL);
no_context:
preempt_enable();
}
void radix__flush_tlb_pwc(struct mmu_gather *tlb, unsigned long addr)
{
unsigned long pid;
struct mm_struct *mm = tlb->mm;
preempt_disable();
pid = mm->context.id;
if (unlikely(pid == MMU_NO_CONTEXT))
goto no_context;
if (!mm_is_core_local(mm)) {
int lock_tlbie = !mmu_has_feature(MMU_FTR_LOCKLESS_TLBIE);
if (lock_tlbie)
raw_spin_lock(&native_tlbie_lock);
_tlbie_pid(pid, RIC_FLUSH_PWC);
if (lock_tlbie)
raw_spin_unlock(&native_tlbie_lock);
} else
_tlbiel_pid(pid, RIC_FLUSH_PWC);
no_context:
preempt_enable();
}
void radix___flush_tlb_page(struct mm_struct *mm, unsigned long vmaddr,
unsigned long ap, int nid)
{
unsigned long pid;
preempt_disable();
pid = mm ? mm->context.id : 0;
if (unlikely(pid == MMU_NO_CONTEXT))
goto bail;
if (!mm_is_core_local(mm)) {
int lock_tlbie = !mmu_has_feature(MMU_FTR_LOCKLESS_TLBIE);
if (lock_tlbie)
raw_spin_lock(&native_tlbie_lock);
_tlbie_va(vmaddr, pid, ap, RIC_FLUSH_TLB);
if (lock_tlbie)
raw_spin_unlock(&native_tlbie_lock);
} else
_tlbiel_va(vmaddr, pid, ap, RIC_FLUSH_TLB);
bail:
preempt_enable();
}
void radix__flush_tlb_page(struct vm_area_struct *vma, unsigned long vmaddr)
{
#ifdef CONFIG_HUGETLB_PAGE
if (vma && is_vm_hugetlb_page(vma))
return flush_hugetlb_page(vma, vmaddr);
#endif
radix___flush_tlb_page(vma ? vma->vm_mm : NULL, vmaddr,
mmu_get_ap(mmu_virtual_psize), 0);
}
void radix__flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
int lock_tlbie = !mmu_has_feature(MMU_FTR_LOCKLESS_TLBIE);
if (lock_tlbie)
raw_spin_lock(&native_tlbie_lock);
_tlbie_pid(0, RIC_FLUSH_ALL);
if (lock_tlbie)
raw_spin_unlock(&native_tlbie_lock);
}
void radix__flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
radix__flush_tlb_mm(mm);
}
void radix__tlb_flush(struct mmu_gather *tlb)
{
struct mm_struct *mm = tlb->mm;
radix__flush_tlb_mm(mm);
}
