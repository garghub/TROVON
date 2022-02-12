void use_mm(struct mm_struct *mm)
{
struct mm_struct *active_mm;
struct task_struct *tsk = current;
task_lock(tsk);
active_mm = tsk->active_mm;
if (active_mm != mm) {
atomic_inc(&mm->mm_count);
tsk->active_mm = mm;
}
tsk->mm = mm;
switch_mm(active_mm, mm, tsk);
task_unlock(tsk);
if (active_mm != mm)
mmdrop(active_mm);
}
void unuse_mm(struct mm_struct *mm)
{
struct task_struct *tsk = current;
task_lock(tsk);
sync_mm_rss(mm);
tsk->mm = NULL;
enter_lazy_tlb(mm, tsk);
task_unlock(tsk);
}
