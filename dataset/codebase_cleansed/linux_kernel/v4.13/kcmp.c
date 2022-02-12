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
static int kcmp_epoll_target(struct task_struct *task1,
struct task_struct *task2,
unsigned long idx1,
struct kcmp_epoll_slot __user *uslot)
{
struct file *filp, *filp_epoll, *filp_tgt;
struct kcmp_epoll_slot slot;
struct files_struct *files;
if (copy_from_user(&slot, uslot, sizeof(slot)))
return -EFAULT;
filp = get_file_raw_ptr(task1, idx1);
if (!filp)
return -EBADF;
files = get_files_struct(task2);
if (!files)
return -EBADF;
spin_lock(&files->file_lock);
filp_epoll = fcheck_files(files, slot.efd);
if (filp_epoll)
get_file(filp_epoll);
else
filp_tgt = ERR_PTR(-EBADF);
spin_unlock(&files->file_lock);
put_files_struct(files);
if (filp_epoll) {
filp_tgt = get_epoll_tfile_raw_ptr(filp_epoll, slot.tfd, slot.toff);
fput(filp_epoll);
} else
if (IS_ERR(filp_tgt))
return PTR_ERR(filp_tgt);
return kcmp_ptr(filp, filp_tgt, KCMP_FILE);
}
static int kcmp_epoll_target(struct task_struct *task1,
struct task_struct *task2,
unsigned long idx1,
struct kcmp_epoll_slot __user *uslot)
{
return -EOPNOTSUPP;
}
static __init int kcmp_cookies_init(void)
{
int i;
get_random_bytes(cookies, sizeof(cookies));
for (i = 0; i < KCMP_TYPES; i++)
cookies[i][1] |= (~(~0UL >> 1) | 1);
return 0;
}
