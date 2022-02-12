void hpte_need_flush(struct mm_struct *mm, unsigned long addr,
pte_t *ptep, unsigned long pte, int huge)
{
unsigned long vpn;
struct ppc64_tlb_batch *batch = &get_cpu_var(ppc64_tlb_batch);
unsigned long vsid;
unsigned int psize;
int ssize;
real_pte_t rpte;
int i;
i = batch->index;
if (huge) {
#ifdef CONFIG_HUGETLB_PAGE
psize = get_slice_psize(mm, addr);
addr &= ~((1UL << mmu_psize_defs[psize].shift) - 1);
#else
BUG();
psize = pte_pagesize_index(mm, addr, pte);
#endif
} else {
psize = pte_pagesize_index(mm, addr, pte);
addr &= PAGE_MASK;
}
if (!is_kernel_addr(addr)) {
ssize = user_segment_size(addr);
vsid = get_vsid(mm->context.id, addr, ssize);
} else {
vsid = get_kernel_vsid(addr, mmu_kernel_ssize);
ssize = mmu_kernel_ssize;
}
WARN_ON(vsid == 0);
vpn = hpt_vpn(addr, vsid, ssize);
rpte = __real_pte(__pte(pte), ptep);
if (!batch->active) {
flush_hash_page(vpn, rpte, psize, ssize, mm_is_thread_local(mm));
put_cpu_var(ppc64_tlb_batch);
return;
}
if (i != 0 && (mm != batch->mm || batch->psize != psize ||
batch->ssize != ssize)) {
__flush_tlb_pending(batch);
i = 0;
}
if (i == 0) {
batch->mm = mm;
batch->psize = psize;
batch->ssize = ssize;
}
batch->pte[i] = rpte;
batch->vpn[i] = vpn;
batch->index = ++i;
if (i >= PPC64_TLB_BATCH_NR)
__flush_tlb_pending(batch);
put_cpu_var(ppc64_tlb_batch);
}
void __flush_tlb_pending(struct ppc64_tlb_batch *batch)
{
const struct cpumask *tmp;
int i, local = 0;
i = batch->index;
tmp = cpumask_of(smp_processor_id());
if (cpumask_equal(mm_cpumask(batch->mm), tmp))
local = 1;
if (i == 1)
flush_hash_page(batch->vpn[0], batch->pte[0],
batch->psize, batch->ssize, local);
else
flush_hash_range(i, local);
batch->index = 0;
}
void hash__tlb_flush(struct mmu_gather *tlb)
{
struct ppc64_tlb_batch *tlbbatch = &get_cpu_var(ppc64_tlb_batch);
if (tlbbatch->index)
__flush_tlb_pending(tlbbatch);
put_cpu_var(ppc64_tlb_batch);
}
void __flush_hash_table_range(struct mm_struct *mm, unsigned long start,
unsigned long end)
{
bool is_thp;
int hugepage_shift;
unsigned long flags;
start = _ALIGN_DOWN(start, PAGE_SIZE);
end = _ALIGN_UP(end, PAGE_SIZE);
BUG_ON(!mm->pgd);
local_irq_save(flags);
arch_enter_lazy_mmu_mode();
for (; start < end; start += PAGE_SIZE) {
pte_t *ptep = find_linux_pte_or_hugepte(mm->pgd, start, &is_thp,
&hugepage_shift);
unsigned long pte;
if (ptep == NULL)
continue;
pte = pte_val(*ptep);
if (is_thp)
trace_hugepage_invalidate(start, pte);
if (!(pte & H_PAGE_HASHPTE))
continue;
if (unlikely(is_thp))
hpte_do_hugepage_flush(mm, start, (pmd_t *)ptep, pte);
else
hpte_need_flush(mm, start, ptep, pte, hugepage_shift);
}
arch_leave_lazy_mmu_mode();
local_irq_restore(flags);
}
void flush_tlb_pmd_range(struct mm_struct *mm, pmd_t *pmd, unsigned long addr)
{
pte_t *pte;
pte_t *start_pte;
unsigned long flags;
addr = _ALIGN_DOWN(addr, PMD_SIZE);
local_irq_save(flags);
arch_enter_lazy_mmu_mode();
start_pte = pte_offset_map(pmd, addr);
for (pte = start_pte; pte < start_pte + PTRS_PER_PTE; pte++) {
unsigned long pteval = pte_val(*pte);
if (pteval & H_PAGE_HASHPTE)
hpte_need_flush(mm, addr, pte, pteval, 0);
addr += PAGE_SIZE;
}
arch_leave_lazy_mmu_mode();
local_irq_restore(flags);
}
