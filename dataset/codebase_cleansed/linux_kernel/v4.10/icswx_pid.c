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
int get_cop_pid(struct mm_struct *mm)
{
int pid;
if (mm->context.cop_pid == COP_PID_NONE) {
pid = new_cop_pid(&cop_ida, COP_PID_MIN, COP_PID_MAX,
&mmu_context_acop_lock);
if (pid >= 0)
mm->context.cop_pid = pid;
}
return mm->context.cop_pid;
}
int disable_cop_pid(struct mm_struct *mm)
{
int free_pid = COP_PID_NONE;
if ((!mm->context.acop) && (mm->context.cop_pid != COP_PID_NONE)) {
free_pid = mm->context.cop_pid;
mm->context.cop_pid = COP_PID_NONE;
}
return free_pid;
}
void free_cop_pid(int free_pid)
{
spin_lock(&mmu_context_acop_lock);
ida_remove(&cop_ida, free_pid);
spin_unlock(&mmu_context_acop_lock);
}
