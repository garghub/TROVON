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
int cpu_suspend(unsigned long arg, int (*fn)(unsigned long))
{
struct mm_struct *mm = current->active_mm;
int ret;
if (!idmap_pgd)
return -EINVAL;
ret = __cpu_suspend(arg, fn);
if (ret == 0) {
cpu_switch_mm(mm->pgd, mm);
local_flush_bp_all();
local_flush_tlb_all();
}
return ret;
}
