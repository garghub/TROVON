static void file_free_rcu(struct rcu_head *head)
{
struct file *f = container_of(head, struct file, f_u.fu_rcuhead);
put_cred(f->f_cred);
kmem_cache_free(filp_cachep, f);
}
static inline void file_free(struct file *f)
{
percpu_counter_dec(&nr_files);
file_check_state(f);
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
int proc_nr_files(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
files_stat.nr_files = get_nr_files();
return proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
}
int proc_nr_files(ctl_table *table, int write,
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
INIT_LIST_HEAD(&f->f_u.fu_list);
atomic_long_set(&f->f_count, 1);
rwlock_init(&f->f_owner.lock);
spin_lock_init(&f->f_lock);
eventpoll_init_file(f);
return f;
over:
if (get_nr_files() > old_max) {
pr_info("VFS: file-max limit %lu reached\n", get_max_files());
old_max = get_nr_files();
}
return ERR_PTR(-ENFILE);
}
struct file *alloc_file(struct path *path, fmode_t mode,
const struct file_operations *fop)
{
struct file *file;
file = get_empty_filp();
if (IS_ERR(file))
return file;
file->f_path = *path;
file->f_inode = path->dentry->d_inode;
file->f_mapping = path->dentry->d_inode->i_mapping;
file->f_mode = mode;
file->f_op = fop;
if ((mode & FMODE_WRITE) && !special_file(path->dentry->d_inode->i_mode)) {
file_take_write(file);
WARN_ON(mnt_clone_write(path->mnt));
}
if ((mode & (FMODE_READ | FMODE_WRITE)) == FMODE_READ)
i_readcount_inc(path->dentry->d_inode);
return file;
}
static void drop_file_write_access(struct file *file)
{
struct vfsmount *mnt = file->f_path.mnt;
struct dentry *dentry = file->f_path.dentry;
struct inode *inode = dentry->d_inode;
put_write_access(inode);
if (special_file(inode->i_mode))
return;
if (file_check_writeable(file) != 0)
return;
__mnt_drop_write(mnt);
file_release_write(file);
}
static void __fput(struct file *file)
{
struct dentry *dentry = file->f_path.dentry;
struct vfsmount *mnt = file->f_path.mnt;
struct inode *inode = dentry->d_inode;
might_sleep();
fsnotify_close(file);
eventpoll_release(file);
locks_remove_flock(file);
if (unlikely(file->f_flags & FASYNC)) {
if (file->f_op && file->f_op->fasync)
file->f_op->fasync(-1, file, 0);
}
ima_file_free(file);
if (file->f_op && file->f_op->release)
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
if (file->f_mode & FMODE_WRITE)
drop_file_write_access(file);
file->f_path.dentry = NULL;
file->f_path.mnt = NULL;
file->f_inode = NULL;
file_free(file);
dput(dentry);
mntput(mnt);
}
static void delayed_fput(struct work_struct *unused)
{
LIST_HEAD(head);
spin_lock_irq(&delayed_fput_lock);
list_splice_init(&delayed_fput_list, &head);
spin_unlock_irq(&delayed_fput_lock);
while (!list_empty(&head)) {
struct file *f = list_first_entry(&head, struct file, f_u.fu_list);
list_del_init(&f->f_u.fu_list);
__fput(f);
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
unsigned long flags;
file_sb_list_del(file);
if (likely(!in_interrupt() && !(task->flags & PF_KTHREAD))) {
init_task_work(&file->f_u.fu_rcuhead, ____fput);
if (!task_work_add(task, &file->f_u.fu_rcuhead, true))
return;
}
spin_lock_irqsave(&delayed_fput_lock, flags);
list_add(&file->f_u.fu_list, &delayed_fput_list);
schedule_work(&delayed_fput_work);
spin_unlock_irqrestore(&delayed_fput_lock, flags);
}
}
void __fput_sync(struct file *file)
{
if (atomic_long_dec_and_test(&file->f_count)) {
struct task_struct *task = current;
file_sb_list_del(file);
BUG_ON(!(task->flags & PF_KTHREAD));
__fput(file);
}
}
void put_filp(struct file *file)
{
if (atomic_long_dec_and_test(&file->f_count)) {
security_file_free(file);
file_sb_list_del(file);
file_free(file);
}
}
static inline int file_list_cpu(struct file *file)
{
#ifdef CONFIG_SMP
return file->f_sb_list_cpu;
#else
return smp_processor_id();
#endif
}
static inline void __file_sb_list_add(struct file *file, struct super_block *sb)
{
struct list_head *list;
#ifdef CONFIG_SMP
int cpu;
cpu = smp_processor_id();
file->f_sb_list_cpu = cpu;
list = per_cpu_ptr(sb->s_files, cpu);
#else
list = &sb->s_files;
#endif
list_add(&file->f_u.fu_list, list);
}
void file_sb_list_add(struct file *file, struct super_block *sb)
{
lg_local_lock(&files_lglock);
__file_sb_list_add(file, sb);
lg_local_unlock(&files_lglock);
}
void file_sb_list_del(struct file *file)
{
if (!list_empty(&file->f_u.fu_list)) {
lg_local_lock_cpu(&files_lglock, file_list_cpu(file));
list_del_init(&file->f_u.fu_list);
lg_local_unlock_cpu(&files_lglock, file_list_cpu(file));
}
}
void mark_files_ro(struct super_block *sb)
{
struct file *f;
lg_global_lock(&files_lglock);
do_file_list_for_each_entry(sb, f) {
if (!S_ISREG(file_inode(f)->i_mode))
continue;
if (!file_count(f))
continue;
if (!(f->f_mode & FMODE_WRITE))
continue;
spin_lock(&f->f_lock);
f->f_mode &= ~FMODE_WRITE;
spin_unlock(&f->f_lock);
if (file_check_writeable(f) != 0)
continue;
__mnt_drop_write(f->f_path.mnt);
file_release_write(f);
} while_file_list_for_each_entry;
lg_global_unlock(&files_lglock);
}
void __init files_init(unsigned long mempages)
{
unsigned long n;
filp_cachep = kmem_cache_create("filp", sizeof(struct file), 0,
SLAB_HWCACHE_ALIGN | SLAB_PANIC, NULL);
n = (mempages * (PAGE_SIZE / 1024)) / 10;
files_stat.max_files = max_t(unsigned long, n, NR_FILE);
files_defer_init();
lg_lock_init(&files_lglock, "files_lglock");
percpu_counter_init(&nr_files, 0);
}
