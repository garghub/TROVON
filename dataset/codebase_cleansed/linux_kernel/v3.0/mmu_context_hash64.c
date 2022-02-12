void switch_cop(struct mm_struct *next)
{
mtspr(SPRN_PID, next->context.cop_pid);
mtspr(SPRN_ACOP, next->context.acop);
}
static int new_cop_pid(struct ida *ida, int min_id, int max_id,
spinlock_t *lock)
{
int index;
int err;
again:
if (!ida_pre_get(ida, GFP_KERNEL))
return -ENOMEM;
spin_lock(lock);
err = ida_get_new_above(ida, min_id, &index);
spin_unlock(lock);
if (err == -EAGAIN)
goto again;
else if (err)
return err;
if (index > max_id) {
spin_lock(lock);
ida_remove(ida, index);
spin_unlock(lock);
return -ENOMEM;
}
return index;
}
static void sync_cop(void *arg)
{
struct mm_struct *mm = arg;
if (mm == current->active_mm)
switch_cop(current->active_mm);
}
int use_cop(unsigned long acop, struct mm_struct *mm)
{
int ret;
if (!cpu_has_feature(CPU_FTR_ICSWX))
return -ENODEV;
if (!mm || !acop)
return -EINVAL;
down_read(&mm->mmap_sem);
spin_lock(mm->context.cop_lockp);
if (mm->context.cop_pid == COP_PID_NONE) {
ret = new_cop_pid(&cop_ida, COP_PID_MIN, COP_PID_MAX,
&mmu_context_acop_lock);
if (ret < 0)
goto out;
mm->context.cop_pid = ret;
}
mm->context.acop |= acop;
sync_cop(mm);
if (atomic_read(&mm->mm_users) > 1)
smp_call_function(sync_cop, mm, 1);
ret = mm->context.cop_pid;
out:
spin_unlock(mm->context.cop_lockp);
up_read(&mm->mmap_sem);
return ret;
}
void drop_cop(unsigned long acop, struct mm_struct *mm)
{
int free_pid = COP_PID_NONE;
if (!cpu_has_feature(CPU_FTR_ICSWX))
return;
if (WARN_ON_ONCE(!mm))
return;
down_read(&mm->mmap_sem);
spin_lock(mm->context.cop_lockp);
mm->context.acop &= ~acop;
if ((!mm->context.acop) && (mm->context.cop_pid != COP_PID_NONE)) {
free_pid = mm->context.cop_pid;
mm->context.cop_pid = COP_PID_NONE;
}
sync_cop(mm);
if (atomic_read(&mm->mm_users) > 1)
smp_call_function(sync_cop, mm, 1);
if (free_pid != COP_PID_NONE) {
spin_lock(&mmu_context_acop_lock);
ida_remove(&cop_ida, free_pid);
spin_unlock(&mmu_context_acop_lock);
}
spin_unlock(mm->context.cop_lockp);
up_read(&mm->mmap_sem);
}
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
