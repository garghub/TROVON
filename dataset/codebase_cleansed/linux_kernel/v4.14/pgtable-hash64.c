int __meminit hash__vmemmap_create_mapping(unsigned long start,
unsigned long page_size,
unsigned long phys)
{
int rc = htab_bolt_mapping(start, start + page_size, phys,
pgprot_val(PAGE_KERNEL),
mmu_vmemmap_psize, mmu_kernel_ssize);
if (rc < 0) {
int rc2 = htab_remove_mapping(start, start + page_size,
mmu_vmemmap_psize,
mmu_kernel_ssize);
BUG_ON(rc2 && (rc2 != -ENOENT));
}
return rc;
}
void hash__vmemmap_remove_mapping(unsigned long start,
unsigned long page_size)
{
int rc = htab_remove_mapping(start, start + page_size,
mmu_vmemmap_psize,
mmu_kernel_ssize);
BUG_ON((rc < 0) && (rc != -ENOENT));
WARN_ON(rc == -ENOENT);
}
int hash__map_kernel_page(unsigned long ea, unsigned long pa, unsigned long flags)
{
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
BUILD_BUG_ON(TASK_SIZE_USER64 > H_PGTABLE_RANGE);
if (slab_is_available()) {
pgdp = pgd_offset_k(ea);
pudp = pud_alloc(&init_mm, pgdp, ea);
if (!pudp)
return -ENOMEM;
pmdp = pmd_alloc(&init_mm, pudp, ea);
if (!pmdp)
return -ENOMEM;
ptep = pte_alloc_kernel(pmdp, ea);
if (!ptep)
return -ENOMEM;
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
} else {
if (htab_bolt_mapping(ea, ea + PAGE_SIZE, pa, flags,
mmu_io_psize, mmu_kernel_ssize)) {
printk(KERN_ERR "Failed to do bolted mapping IO "
"memory at %016lx !\n", pa);
return -ENOMEM;
}
}
smp_wmb();
return 0;
}
unsigned long hash__pmd_hugepage_update(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp, unsigned long clr,
unsigned long set)
{
__be64 old_be, tmp;
unsigned long old;
#ifdef CONFIG_DEBUG_VM
WARN_ON(!hash__pmd_trans_huge(*pmdp) && !pmd_devmap(*pmdp));
assert_spin_locked(&mm->page_table_lock);
#endif
__asm__ __volatile__(
"1: ldarx %0,0,%3\n\
and. %1,%0,%6\n\
bne- 1b \n\
andc %1,%0,%4 \n\
or %1,%1,%7\n\
stdcx. %1,0,%3 \n\
bne- 1b"
: "=&r" (old_be), "=&r" (tmp), "=m" (*pmdp)
: "r" (pmdp), "r" (cpu_to_be64(clr)), "m" (*pmdp),
"r" (cpu_to_be64(H_PAGE_BUSY)), "r" (cpu_to_be64(set))
: "cc" );
old = be64_to_cpu(old_be);
trace_hugepage_update(addr, old, clr, set);
if (old & H_PAGE_HASHPTE)
hpte_do_hugepage_flush(mm, addr, pmdp, old);
return old;
}
pmd_t hash__pmdp_collapse_flush(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_t pmd;
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
VM_BUG_ON(pmd_trans_huge(*pmdp));
VM_BUG_ON(pmd_devmap(*pmdp));
pmd = *pmdp;
pmd_clear(pmdp);
serialize_against_pte_lookup(vma->vm_mm);
flush_tlb_pmd_range(vma->vm_mm, &pmd, address);
return pmd;
}
void hash__pgtable_trans_huge_deposit(struct mm_struct *mm, pmd_t *pmdp,
pgtable_t pgtable)
{
pgtable_t *pgtable_slot;
assert_spin_locked(&mm->page_table_lock);
pgtable_slot = (pgtable_t *)pmdp + PTRS_PER_PMD;
*pgtable_slot = pgtable;
smp_wmb();
}
pgtable_t hash__pgtable_trans_huge_withdraw(struct mm_struct *mm, pmd_t *pmdp)
{
pgtable_t pgtable;
pgtable_t *pgtable_slot;
assert_spin_locked(&mm->page_table_lock);
pgtable_slot = (pgtable_t *)pmdp + PTRS_PER_PMD;
pgtable = *pgtable_slot;
*pgtable_slot = NULL;
memset(pgtable, 0, PTE_FRAG_SIZE);
return pgtable;
}
void hash__pmdp_huge_split_prepare(struct vm_area_struct *vma,
unsigned long address, pmd_t *pmdp)
{
VM_BUG_ON(address & ~HPAGE_PMD_MASK);
VM_BUG_ON(REGION_ID(address) != USER_REGION_ID);
VM_BUG_ON(pmd_devmap(*pmdp));
pmd_hugepage_update(vma->vm_mm, address, pmdp, 0, _PAGE_PRIVILEGED);
}
void hpte_do_hugepage_flush(struct mm_struct *mm, unsigned long addr,
pmd_t *pmdp, unsigned long old_pmd)
{
int ssize;
unsigned int psize;
unsigned long vsid;
unsigned long flags = 0;
#ifdef CONFIG_DEBUG_VM
psize = get_slice_psize(mm, addr);
BUG_ON(psize == MMU_PAGE_16M);
#endif
if (old_pmd & H_PAGE_COMBO)
psize = MMU_PAGE_4K;
else
psize = MMU_PAGE_64K;
if (!is_kernel_addr(addr)) {
ssize = user_segment_size(addr);
vsid = get_vsid(mm->context.id, addr, ssize);
WARN_ON(vsid == 0);
} else {
vsid = get_kernel_vsid(addr, mmu_kernel_ssize);
ssize = mmu_kernel_ssize;
}
if (mm_is_thread_local(mm))
flags |= HPTE_LOCAL_UPDATE;
return flush_hash_hugepage(vsid, addr, pmdp, psize, ssize, flags);
}
pmd_t hash__pmdp_huge_get_and_clear(struct mm_struct *mm,
unsigned long addr, pmd_t *pmdp)
{
pmd_t old_pmd;
pgtable_t pgtable;
unsigned long old;
pgtable_t *pgtable_slot;
old = pmd_hugepage_update(mm, addr, pmdp, ~0UL, 0);
old_pmd = __pmd(old);
pgtable_slot = (pgtable_t *)pmdp + PTRS_PER_PMD;
pgtable = *pgtable_slot;
memset(pgtable, 0, PTE_FRAG_SIZE);
serialize_against_pte_lookup(mm);
return old_pmd;
}
int hash__has_transparent_hugepage(void)
{
if (!mmu_has_feature(MMU_FTR_16M_PAGE))
return 0;
if (mmu_psize_defs[MMU_PAGE_16M].shift != PMD_SHIFT)
return 0;
if (mmu_psize_defs[MMU_PAGE_64K].shift &&
(mmu_psize_defs[MMU_PAGE_64K].penc[MMU_PAGE_16M] == -1))
return 0;
if (mmu_psize_defs[MMU_PAGE_4K].penc[MMU_PAGE_16M] == -1)
return 0;
return 1;
}
static bool hash__change_memory_range(unsigned long start, unsigned long end,
unsigned long newpp)
{
unsigned long idx;
unsigned int step, shift;
shift = mmu_psize_defs[mmu_linear_psize].shift;
step = 1 << shift;
start = ALIGN_DOWN(start, step);
end = ALIGN(end, step);
if (start >= end)
return false;
pr_debug("Changing page protection on range 0x%lx-0x%lx, to 0x%lx, step 0x%x\n",
start, end, newpp, step);
for (idx = start; idx < end; idx += step)
mmu_hash_ops.hpte_updateboltedpp(newpp, idx, mmu_linear_psize,
mmu_kernel_ssize);
return true;
}
void hash__mark_rodata_ro(void)
{
unsigned long start, end;
start = (unsigned long)_stext;
end = (unsigned long)__init_begin;
WARN_ON(!hash__change_memory_range(start, end, PP_RXXX));
}
void hash__mark_initmem_nx(void)
{
unsigned long start, end, pp;
start = (unsigned long)__init_begin;
end = (unsigned long)__init_end;
pp = htab_convert_pte_flags(pgprot_val(PAGE_KERNEL));
WARN_ON(!hash__change_memory_range(start, end, pp));
}
