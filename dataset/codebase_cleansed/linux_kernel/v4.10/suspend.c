int cpu_suspend(unsigned long arg, int (*fn)(unsigned long))
{
struct mm_struct *mm = current->active_mm;
u32 __mpidr = cpu_logical_map(smp_processor_id());
int ret;
if (!idmap_pgd)
return -EINVAL;
ret = __cpu_suspend(arg, fn, __mpidr);
if (ret == 0) {
cpu_switch_mm(mm->pgd, mm);
local_flush_bp_all();
local_flush_tlb_all();
}
return ret;
}
int cpu_suspend(unsigned long arg, int (*fn)(unsigned long))
{
u32 __mpidr = cpu_logical_map(smp_processor_id());
return __cpu_suspend(arg, fn, __mpidr);
}
void __cpu_suspend_save(u32 *ptr, u32 ptrsz, u32 sp, u32 *save_ptr)
{
u32 *ctx = ptr;
*save_ptr = virt_to_phys(ptr);
*ptr++ = virt_to_phys(idmap_pgd);
*ptr++ = sp;
*ptr++ = virt_to_phys(cpu_do_resume);
cpu_do_suspend(ptr);
flush_cache_louis();
__cpuc_flush_dcache_area(ctx, ptrsz);
__cpuc_flush_dcache_area(save_ptr, sizeof(*save_ptr));
outer_clean_range(*save_ptr, *save_ptr + ptrsz);
outer_clean_range(virt_to_phys(save_ptr),
virt_to_phys(save_ptr) + sizeof(*save_ptr));
}
static int cpu_suspend_alloc_sp(void)
{
void *ctx_ptr;
ctx_ptr = kcalloc(mpidr_hash_size(), sizeof(u32), GFP_KERNEL);
if (WARN_ON(!ctx_ptr))
return -ENOMEM;
sleep_save_sp.save_ptr_stash = ctx_ptr;
sleep_save_sp.save_ptr_stash_phys = virt_to_phys(ctx_ptr);
sync_cache_w(&sleep_save_sp);
return 0;
}
