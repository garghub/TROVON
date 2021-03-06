static void file_free_rcu(struct rcu_head *head)
{
struct file *f = container_of(head, struct file, f_u.fu_rcuhead);
put_cred(f->f_cred);
kmem_cache_free(filp_cachep, f);
}
static inline void file_free(struct file *f)
{
percpu_counter_dec(&nr_files);
call_rcu(&f->f_u.fu_rcuhead, file_free_rcu);
}
static long get_nr_files(void)
{
return percpu_counter_read_positive(&nr_files);
}
unsigned long get_max_files(void)
{
return files_stat.max_files;
}
int proc_nr_files(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
files_stat.nr_files = get_nr_files();
return proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
}
int proc_nr_files(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return -ENOSYS;
}
struct file *get_empty_filp(void)
{
const struct cred *cred = current_cred();
static long old_max;
struct file *f;
int error;
if (get_nr_files() >= files_stat.max_files && !capable(CAP_SYS_ADMIN)) {
if (percpu_counter_sum_positive(&nr_files) >= files_stat.max_files)
goto over;
}
f = kmem_cache_zalloc(filp_cachep, GFP_KERNEL);
if (unlikely(!f))
return ERR_PTR(-ENOMEM);
percpu_counter_inc(&nr_files);
f->f_cred = get_cred(cred);
error = security_file_alloc(f);
if (unlikely(error)) {
file_free(f);
return ERR_PTR(error);
}
atomic_long_set(&f->f_count, 1);
rwlock_init(&f->f_owner.lock);
spin_lock_init(&f->f_lock);
mutex_init(&f->f_pos_lock);
eventpoll_init_file(f);
return f;
over:
if (get_nr_files() > old_max) {
pr_info("VFS: file-max limit %lu reached\n", get_max_files());
old_max = get_nr_files();
}
return ERR_PTR(-ENFILE);
}
struct file *alloc_file(const struct path *path, fmode_t mode,
const struct file_operations *fop)
{
struct file *file;
file = get_empty_filp();
if (IS_ERR(file))
return file;
file->f_path = *path;
file->f_inode = path->dentry->d_inode;
file->f_mapping = path->dentry->d_inode->i_mapping;
if ((mode & FMODE_READ) &&
likely(fop->read || fop->read_iter))
mode |= FMODE_CAN_READ;
if ((mode & FMODE_WRITE) &&
likely(fop->write || fop->write_iter))
mode |= FMODE_CAN_WRITE;
file->f_mode = mode;
file->f_op = fop;
if ((mode & (FMODE_READ | FMODE_WRITE)) == FMODE_READ)
i_readcount_inc(path->dentry->d_inode);
return file;
}
static void __fput(struct file *file)
{
struct dentry *dentry = file->f_path.dentry;
struct vfsmount *mnt = file->f_path.mnt;
struct inode *inode = file->f_inode;
might_sleep();
fsnotify_close(file);
eventpoll_release(file);
locks_remove_file(file);
if (unlikely(file->f_flags & FASYNC)) {
if (file->f_op->fasync)
file->f_op->fasync(-1, file, 0);
}
ima_file_free(file);
if (file->f_op->release)
file->f_op->release(inode, file);
security_file_free(file);
if (unlikely(S_ISCHR(inode->i_mode) && inode->i_cdev != NULL &&
!(file->f_mode & FMODE_PATH))) {
cdev_put(inode->i_cdev);
}
fops_put(file->f_op);
put_pid(file->f_owner.pid);
if ((file->f_mode & (FMODE_READ | FMODE_WRITE)) == FMODE_READ)
i_readcount_dec(inode);
if (file->f_mode & FMODE_WRITER) {
put_write_access(inode);
__mnt_drop_write(mnt);
}
file->f_path.dentry = NULL;
file->f_path.mnt = NULL;
file->f_inode = NULL;
file_free(file);
dput(dentry);
mntput(mnt);
}
static void delayed_fput(struct work_struct *unused)
{
struct llist_node *node = llist_del_all(&delayed_fput_list);
struct llist_node *next;
for (; node; node = next) {
next = llist_next(node);
__fput(llist_entry(node, struct file, f_u.fu_llist));
}
}
static void ____fput(struct callback_head *work)
{
__fput(container_of(work, struct file, f_u.fu_rcuhead));
}
void flush_delayed_fput(void)
{
delayed_fput(NULL);
}
void fput(struct file *file)
{
if (atomic_long_dec_and_test(&file->f_count)) {
struct task_struct *task = current;
if (likely(!in_interrupt() && !(task->flags & PF_KTHREAD))) {
init_task_work(&file->f_u.fu_rcuhead, ____fput);
if (!task_work_add(task, &file->f_u.fu_rcuhead, true))
return;
}
if (llist_add(&file->f_u.fu_llist, &delayed_fput_list))
schedule_delayed_work(&delayed_fput_work, 1);
}
}
void __fput_sync(struct file *file)
{
if (atomic_long_dec_and_test(&file->f_count)) {
struct task_struct *task = current;
BUG_ON(!(task->flags & PF_KTHREAD));
__fput(file);
}
}
void put_filp(struct file *file)
{
if (atomic_long_dec_and_test(&file->f_count)) {
security_file_free(file);
file_free(file);
}
}
void __init files_init(void)
{
filp_cachep = kmem_cache_create("filp", sizeof(struct file), 0,
SLAB_HWCACHE_ALIGN | SLAB_PANIC, NULL);
percpu_counter_init(&nr_files, 0, GFP_KERNEL);
}
void __init files_maxfiles_init(void)
{
unsigned long n;
unsigned long memreserve = (totalram_pages - nr_free_pages()) * 3/2;
memreserve = min(memreserve, totalram_pages - 1);
n = ((totalram_pages - memreserve) * (PAGE_SIZE / 1024)) / 10;
files_stat.max_files = max_t(unsigned long, n, NR_FILE);
}
