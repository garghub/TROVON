static long kptr_obfuscate(long v, int type)
{
return (v ^ cookies[type][0]) * cookies[type][1];
}
static int kcmp_ptr(void *v1, void *v2, enum kcmp_type type)
{
long t1, t2;
t1 = kptr_obfuscate((long)v1, type);
t2 = kptr_obfuscate((long)v2, type);
return (t1 < t2) | ((t1 > t2) << 1);
}
static struct file *
get_file_raw_ptr(struct task_struct *task, unsigned int idx)
{
struct file *file = NULL;
task_lock(task);
rcu_read_lock();
if (task->files)
file = fcheck_files(task->files, idx);
rcu_read_unlock();
task_unlock(task);
return file;
}
static void kcmp_unlock(struct mutex *m1, struct mutex *m2)
{
if (likely(m2 != m1))
mutex_unlock(m2);
mutex_unlock(m1);
}
static int kcmp_lock(struct mutex *m1, struct mutex *m2)
{
int err;
if (m2 > m1)
swap(m1, m2);
err = mutex_lock_killable(m1);
if (!err && likely(m1 != m2)) {
err = mutex_lock_killable_nested(m2, SINGLE_DEPTH_NESTING);
if (err)
mutex_unlock(m1);
}
return err;
}
static __init int kcmp_cookies_init(void)
{
int i;
get_random_bytes(cookies, sizeof(cookies));
for (i = 0; i < KCMP_TYPES; i++)
cookies[i][1] |= (~(~0UL >> 1) | 1);
return 0;
}
