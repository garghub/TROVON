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
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("ptesync": : :"memory");
}
static inline void _tlbiel_pid(unsigned long pid, unsigned long ric)
{
int set;
for (set = 0; set < POWER9_TLB_SETS_RADIX ; set++) {
__tlbiel_pid(pid, set, ric);
}
asm volatile(PPC_INVALIDATE_ERAT "; isync" : : :"memory");
}
static inline void _tlbie_pid(unsigned long pid, unsigned long ric)
{
unsigned long rb,rs,prs,r;
rb = PPC_BIT(53);
rs = pid << PPC_BITLSHIFT(31);
prs = 1;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
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
asm volatile(PPC_TLBIEL(%0, %4, %3, %2, %1)
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
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
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
void radix__local_flush_tlb_page_psize(struct mm_struct *mm, unsigned long vmaddr,
int psize)
{
unsigned long pid;
unsigned long ap = mmu_get_ap(psize);
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
radix__local_flush_tlb_page_psize(vma ? vma->vm_mm : NULL, vmaddr,
mmu_virtual_psize);
}
void radix__flush_tlb_mm(struct mm_struct *mm)
{
unsigned long pid;
preempt_disable();
pid = mm->context.id;
if (unlikely(pid == MMU_NO_CONTEXT))
goto no_context;
if (!mm_is_thread_local(mm)) {
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
if (!mm_is_thread_local(mm)) {
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
void radix__flush_tlb_page_psize(struct mm_struct *mm, unsigned long vmaddr,
int psize)
{
unsigned long pid;
unsigned long ap = mmu_get_ap(psize);
preempt_disable();
pid = mm ? mm->context.id : 0;
if (unlikely(pid == MMU_NO_CONTEXT))
goto bail;
if (!mm_is_thread_local(mm)) {
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
radix__flush_tlb_page_psize(vma ? vma->vm_mm : NULL, vmaddr,
mmu_virtual_psize);
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
static int radix_get_mmu_psize(int page_size)
{
int psize;
if (page_size == (1UL << mmu_psize_defs[mmu_virtual_psize].shift))
psize = mmu_virtual_psize;
else if (page_size == (1UL << mmu_psize_defs[MMU_PAGE_2M].shift))
psize = MMU_PAGE_2M;
else if (page_size == (1UL << mmu_psize_defs[MMU_PAGE_1G].shift))
psize = MMU_PAGE_1G;
else
return -1;
return psize;
}
void radix__tlb_flush(struct mmu_gather *tlb)
{
int psize = 0;
struct mm_struct *mm = tlb->mm;
int page_size = tlb->page_size;
psize = radix_get_mmu_psize(page_size);
if (psize != -1 && !tlb->fullmm && !tlb->need_flush_all)
radix__flush_tlb_range_psize(mm, tlb->start, tlb->end, psize);
else
radix__flush_tlb_mm(mm);
}
void radix__flush_tlb_range_psize(struct mm_struct *mm, unsigned long start,
unsigned long end, int psize)
{
unsigned long pid;
unsigned long addr;
int local = mm_is_thread_local(mm);
unsigned long ap = mmu_get_ap(psize);
int lock_tlbie = !mmu_has_feature(MMU_FTR_LOCKLESS_TLBIE);
unsigned long page_size = 1UL << mmu_psize_defs[psize].shift;
preempt_disable();
pid = mm ? mm->context.id : 0;
if (unlikely(pid == MMU_NO_CONTEXT))
goto err_out;
if (end == TLB_FLUSH_ALL ||
(end - start) > tlb_single_page_flush_ceiling * page_size) {
if (local)
_tlbiel_pid(pid, RIC_FLUSH_TLB);
else
_tlbie_pid(pid, RIC_FLUSH_TLB);
goto err_out;
}
for (addr = start; addr < end; addr += page_size) {
if (local)
_tlbiel_va(addr, pid, ap, RIC_FLUSH_TLB);
else {
if (lock_tlbie)
raw_spin_lock(&native_tlbie_lock);
_tlbie_va(addr, pid, ap, RIC_FLUSH_TLB);
if (lock_tlbie)
raw_spin_unlock(&native_tlbie_lock);
}
}
err_out:
preempt_enable();
}
void radix__flush_tlb_lpid_va(unsigned long lpid, unsigned long gpa,
unsigned long page_size)
{
unsigned long rb,rs,prs,r;
unsigned long ap;
unsigned long ric = RIC_FLUSH_TLB;
ap = mmu_get_ap(radix_get_mmu_psize(page_size));
rb = gpa & ~(PPC_BITMASK(52, 63));
rb |= ap << PPC_BITLSHIFT(58);
rs = lpid & ((1UL << 32) - 1);
prs = 0;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void radix__flush_tlb_lpid(unsigned long lpid)
{
unsigned long rb,rs,prs,r;
unsigned long ric = RIC_FLUSH_ALL;
rb = 0x2 << PPC_BITLSHIFT(53);
rs = lpid & ((1UL << 32) - 1);
prs = 0;
r = 1;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(rs) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void radix__flush_pmd_tlb_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
radix__flush_tlb_range_psize(vma->vm_mm, start, end, MMU_PAGE_2M);
}
void radix__flush_tlb_all(void)
{
unsigned long rb,prs,r,rs;
unsigned long ric = RIC_FLUSH_ALL;
rb = 0x3 << PPC_BITLSHIFT(53);
prs = 0;
r = 1;
rs = 1 & ((1UL << 32) - 1);
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(1), "i"(ric), "r"(rs) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(r), "i"(prs), "i"(ric), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync": : :"memory");
}
void radix__flush_tlb_pte_p9_dd1(unsigned long old_pte, struct mm_struct *mm,
unsigned long address)
{
if (!cpu_has_feature(CPU_FTR_POWER9_DD1)) {
VM_WARN_ON(1);
return;
}
if (old_pte & _PAGE_LARGE)
radix__flush_tlb_page_psize(mm, address, MMU_PAGE_2M);
else
radix__flush_tlb_page_psize(mm, address, mmu_virtual_psize);
}
