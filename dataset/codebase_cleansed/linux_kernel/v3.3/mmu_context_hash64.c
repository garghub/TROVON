int __init_new_context(void)
{
int index;
int err;
again:
if (!ida_pre_get(&mmu_context_ida, GFP_KERNEL))
return -ENOMEM;
spin_lock(&mmu_context_lock);
err = ida_get_new_above(&mmu_context_ida, 1, &index);
spin_unlock(&mmu_context_lock);
if (err == -EAGAIN)
goto again;
else if (err)
return err;
if (index > MAX_CONTEXT) {
spin_lock(&mmu_context_lock);
ida_remove(&mmu_context_ida, index);
spin_unlock(&mmu_context_lock);
return -ENOMEM;
}
return index;
}
int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
int index;
index = __init_new_context();
if (index < 0)
return index;
if (slice_mm_new_context(mm))
slice_set_user_psize(mm, mmu_virtual_psize);
subpage_prot_init_new_context(mm);
mm->context.id = index;
#ifdef CONFIG_PPC_ICSWX
mm->context.cop_lockp = kmalloc(sizeof(spinlock_t), GFP_KERNEL);
if (!mm->context.cop_lockp) {
__destroy_context(index);
subpage_prot_free(mm);
mm->context.id = MMU_NO_CONTEXT;
return -ENOMEM;
}
spin_lock_init(mm->context.cop_lockp);
#endif
return 0;
}
void __destroy_context(int context_id)
{
spin_lock(&mmu_context_lock);
ida_remove(&mmu_context_ida, context_id);
spin_unlock(&mmu_context_lock);
}
void destroy_context(struct mm_struct *mm)
{
#ifdef CONFIG_PPC_ICSWX
drop_cop(mm->context.acop, mm);
kfree(mm->context.cop_lockp);
mm->context.cop_lockp = NULL;
#endif
__destroy_context(mm->context.id);
subpage_prot_free(mm);
mm->context.id = MMU_NO_CONTEXT;
}
