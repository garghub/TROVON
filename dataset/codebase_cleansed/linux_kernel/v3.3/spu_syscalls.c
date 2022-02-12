static inline struct spufs_calls *spufs_calls_get(void)
{
struct spufs_calls *calls = NULL;
rcu_read_lock();
calls = rcu_dereference(spufs_calls);
if (calls && !try_module_get(calls->owner))
calls = NULL;
rcu_read_unlock();
return calls;
}
static inline void spufs_calls_put(struct spufs_calls *calls)
{
BUG_ON(calls != spufs_calls);
module_put(spufs_calls->owner);
}
static inline struct spufs_calls *spufs_calls_get(void)
{
return spufs_calls;
}
static inline void spufs_calls_put(struct spufs_calls *calls) { }
asmlinkage long sys_spu_run(int fd, __u32 __user *unpc, __u32 __user *ustatus)
{
long ret;
struct file *filp;
int fput_needed;
struct spufs_calls *calls;
calls = spufs_calls_get();
if (!calls)
return -ENOSYS;
ret = -EBADF;
filp = fget_light(fd, &fput_needed);
if (filp) {
ret = calls->spu_run(filp, unpc, ustatus);
fput_light(filp, fput_needed);
}
spufs_calls_put(calls);
return ret;
}
int elf_coredump_extra_notes_size(void)
{
struct spufs_calls *calls;
int ret;
calls = spufs_calls_get();
if (!calls)
return 0;
ret = calls->coredump_extra_notes_size();
spufs_calls_put(calls);
return ret;
}
int elf_coredump_extra_notes_write(struct file *file, loff_t *foffset)
{
struct spufs_calls *calls;
int ret;
calls = spufs_calls_get();
if (!calls)
return 0;
ret = calls->coredump_extra_notes_write(file, foffset);
spufs_calls_put(calls);
return ret;
}
void notify_spus_active(void)
{
struct spufs_calls *calls;
calls = spufs_calls_get();
if (!calls)
return;
calls->notify_spus_active();
spufs_calls_put(calls);
return;
}
int register_spu_syscalls(struct spufs_calls *calls)
{
if (spufs_calls)
return -EBUSY;
rcu_assign_pointer(spufs_calls, calls);
return 0;
}
void unregister_spu_syscalls(struct spufs_calls *calls)
{
BUG_ON(spufs_calls->owner != calls->owner);
rcu_assign_pointer(spufs_calls, NULL);
synchronize_rcu();
}
