static int alloc_context_id(int min_id, int max_id)
{
int index, err;
again:
if (!ida_pre_get(&mmu_context_ida, GFP_KERNEL))
return -ENOMEM;
spin_lock(&mmu_context_lock);
err = ida_get_new_above(&mmu_context_ida, min_id, &index);
spin_unlock(&mmu_context_lock);
if (err == -EAGAIN)
goto again;
else if (err)
return err;
if (index > max_id) {
spin_lock(&mmu_context_lock);
ida_remove(&mmu_context_ida, index);
spin_unlock(&mmu_context_lock);
return -ENOMEM;
}
return index;
}
void hash__reserve_context_id(int id)
{
int rc, result = 0;
do {
if (!ida_pre_get(&mmu_context_ida, GFP_KERNEL))
break;
spin_lock(&mmu_context_lock);
rc = ida_get_new_above(&mmu_context_ida, id, &result);
spin_unlock(&mmu_context_lock);
} while (rc == -EAGAIN);
WARN(result != id, "mmu: Failed to reserve context id %d (rc %d)\n", id, result);
}
int hash__alloc_context_id(void)
{
unsigned long max;
if (mmu_has_feature(MMU_FTR_68_BIT_VA))
max = MAX_USER_CONTEXT;
else
max = MAX_USER_CONTEXT_65BIT_VA;
return alloc_context_id(MIN_USER_CONTEXT, max);
}
static int hash__init_new_context(struct mm_struct *mm)
{
int index;
index = hash__alloc_context_id();
if (index < 0)
return index;
mm->context.addr_limit = DEFAULT_MAP_WINDOW_USER64;
if (mm->context.id == 0)
slice_set_user_psize(mm, mmu_virtual_psize);
subpage_prot_init_new_context(mm);
return index;
}
static int radix__init_new_context(struct mm_struct *mm)
{
unsigned long rts_field;
int index, max_id;
max_id = (1 << mmu_pid_bits) - 1;
index = alloc_context_id(mmu_base_pid, max_id);
if (index < 0)
return index;
rts_field = radix__get_tree_size();
process_tb[index].prtb0 = cpu_to_be64(rts_field | __pa(mm->pgd) | RADIX_PGD_INDEX_SIZE);
asm volatile("ptesync;isync" : : : "memory");
mm->context.npu_context = NULL;
return index;
}
int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
int index;
if (radix_enabled())
index = radix__init_new_context(mm);
else
index = hash__init_new_context(mm);
if (index < 0)
return index;
mm->context.id = index;
#ifdef CONFIG_PPC_64K_PAGES
mm->context.pte_frag = NULL;
#endif
#ifdef CONFIG_SPAPR_TCE_IOMMU
mm_iommu_init(mm);
#endif
atomic_set(&mm->context.active_cpus, 0);
return 0;
}
void __destroy_context(int context_id)
{
spin_lock(&mmu_context_lock);
ida_remove(&mmu_context_ida, context_id);
spin_unlock(&mmu_context_lock);
}
static void destroy_pagetable_page(struct mm_struct *mm)
{
int count;
void *pte_frag;
struct page *page;
pte_frag = mm->context.pte_frag;
if (!pte_frag)
return;
page = virt_to_page(pte_frag);
count = ((unsigned long)pte_frag & ~PAGE_MASK) >> PTE_FRAG_SIZE_SHIFT;
if (page_ref_sub_and_test(page, PTE_FRAG_NR - count)) {
pgtable_page_dtor(page);
free_hot_cold_page(page, 0);
}
}
static inline void destroy_pagetable_page(struct mm_struct *mm)
{
return;
}
void destroy_context(struct mm_struct *mm)
{
#ifdef CONFIG_SPAPR_TCE_IOMMU
WARN_ON_ONCE(!list_empty(&mm->context.iommu_group_mem_list));
#endif
if (radix_enabled()) {
process_tb[mm->context.id].prtb0 = 0;
} else
subpage_prot_free(mm);
destroy_pagetable_page(mm);
__destroy_context(mm->context.id);
mm->context.id = MMU_NO_CONTEXT;
}
void radix__switch_mmu_context(struct mm_struct *prev, struct mm_struct *next)
{
if (cpu_has_feature(CPU_FTR_POWER9_DD1)) {
isync();
mtspr(SPRN_PID, next->context.id);
isync();
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
} else {
mtspr(SPRN_PID, next->context.id);
isync();
}
}
