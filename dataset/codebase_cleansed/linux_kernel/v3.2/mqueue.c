static inline struct mqueue_inode_info *MQUEUE_I(struct inode *inode)
{
return container_of(inode, struct mqueue_inode_info, vfs_inode);
}
static inline struct ipc_namespace *__get_ns_from_inode(struct inode *inode)
{
return get_ipc_ns(inode->i_sb->s_fs_info);
}
static struct ipc_namespace *get_ns_from_inode(struct inode *inode)
{
struct ipc_namespace *ns;
spin_lock(&mq_lock);
ns = __get_ns_from_inode(inode);
spin_unlock(&mq_lock);
return ns;
}
static struct inode *mqueue_get_inode(struct super_block *sb,
struct ipc_namespace *ipc_ns, int mode,
struct mq_attr *attr)
{
struct user_struct *u = current_user();
struct inode *inode;
int ret = -ENOMEM;
inode = new_inode(sb);
if (!inode)
goto err;
inode->i_ino = get_next_ino();
inode->i_mode = mode;
inode->i_uid = current_fsuid();
inode->i_gid = current_fsgid();
inode->i_mtime = inode->i_ctime = inode->i_atime = CURRENT_TIME;
if (S_ISREG(mode)) {
struct mqueue_inode_info *info;
struct task_struct *p = current;
unsigned long mq_bytes, mq_msg_tblsz;
inode->i_fop = &mqueue_file_operations;
inode->i_size = FILENT_SIZE;
info = MQUEUE_I(inode);
spin_lock_init(&info->lock);
init_waitqueue_head(&info->wait_q);
INIT_LIST_HEAD(&info->e_wait_q[0].list);
INIT_LIST_HEAD(&info->e_wait_q[1].list);
info->notify_owner = NULL;
info->qsize = 0;
info->user = NULL;
memset(&info->attr, 0, sizeof(info->attr));
info->attr.mq_maxmsg = ipc_ns->mq_msg_max;
info->attr.mq_msgsize = ipc_ns->mq_msgsize_max;
if (attr) {
info->attr.mq_maxmsg = attr->mq_maxmsg;
info->attr.mq_msgsize = attr->mq_msgsize;
}
mq_msg_tblsz = info->attr.mq_maxmsg * sizeof(struct msg_msg *);
info->messages = kmalloc(mq_msg_tblsz, GFP_KERNEL);
if (!info->messages)
goto out_inode;
mq_bytes = (mq_msg_tblsz +
(info->attr.mq_maxmsg * info->attr.mq_msgsize));
spin_lock(&mq_lock);
if (u->mq_bytes + mq_bytes < u->mq_bytes ||
u->mq_bytes + mq_bytes > task_rlimit(p, RLIMIT_MSGQUEUE)) {
spin_unlock(&mq_lock);
ret = -EMFILE;
goto out_inode;
}
u->mq_bytes += mq_bytes;
spin_unlock(&mq_lock);
info->user = get_uid(u);
} else if (S_ISDIR(mode)) {
inc_nlink(inode);
inode->i_size = 2 * DIRENT_SIZE;
inode->i_op = &mqueue_dir_inode_operations;
inode->i_fop = &simple_dir_operations;
}
return inode;
out_inode:
iput(inode);
err:
return ERR_PTR(ret);
}
static int mqueue_fill_super(struct super_block *sb, void *data, int silent)
{
struct inode *inode;
struct ipc_namespace *ns = data;
int error;
sb->s_blocksize = PAGE_CACHE_SIZE;
sb->s_blocksize_bits = PAGE_CACHE_SHIFT;
sb->s_magic = MQUEUE_MAGIC;
sb->s_op = &mqueue_super_ops;
inode = mqueue_get_inode(sb, ns, S_IFDIR | S_ISVTX | S_IRWXUGO,
NULL);
if (IS_ERR(inode)) {
error = PTR_ERR(inode);
goto out;
}
sb->s_root = d_alloc_root(inode);
if (!sb->s_root) {
iput(inode);
error = -ENOMEM;
goto out;
}
error = 0;
out:
return error;
}
static struct dentry *mqueue_mount(struct file_system_type *fs_type,
int flags, const char *dev_name,
void *data)
{
if (!(flags & MS_KERNMOUNT))
data = current->nsproxy->ipc_ns;
return mount_ns(fs_type, flags, data, mqueue_fill_super);
}
static void init_once(void *foo)
{
struct mqueue_inode_info *p = (struct mqueue_inode_info *) foo;
inode_init_once(&p->vfs_inode);
}
static struct inode *mqueue_alloc_inode(struct super_block *sb)
{
struct mqueue_inode_info *ei;
ei = kmem_cache_alloc(mqueue_inode_cachep, GFP_KERNEL);
if (!ei)
return NULL;
return &ei->vfs_inode;
}
static void mqueue_i_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
INIT_LIST_HEAD(&inode->i_dentry);
kmem_cache_free(mqueue_inode_cachep, MQUEUE_I(inode));
}
static void mqueue_destroy_inode(struct inode *inode)
{
call_rcu(&inode->i_rcu, mqueue_i_callback);
}
static void mqueue_evict_inode(struct inode *inode)
{
struct mqueue_inode_info *info;
struct user_struct *user;
unsigned long mq_bytes;
int i;
struct ipc_namespace *ipc_ns;
end_writeback(inode);
if (S_ISDIR(inode->i_mode))
return;
ipc_ns = get_ns_from_inode(inode);
info = MQUEUE_I(inode);
spin_lock(&info->lock);
for (i = 0; i < info->attr.mq_curmsgs; i++)
free_msg(info->messages[i]);
kfree(info->messages);
spin_unlock(&info->lock);
mq_bytes = info->attr.mq_maxmsg * (sizeof(struct msg_msg *)
+ info->attr.mq_msgsize);
user = info->user;
if (user) {
spin_lock(&mq_lock);
user->mq_bytes -= mq_bytes;
if (ipc_ns)
ipc_ns->mq_queues_count--;
spin_unlock(&mq_lock);
free_uid(user);
}
if (ipc_ns)
put_ipc_ns(ipc_ns);
}
static int mqueue_create(struct inode *dir, struct dentry *dentry,
int mode, struct nameidata *nd)
{
struct inode *inode;
struct mq_attr *attr = dentry->d_fsdata;
int error;
struct ipc_namespace *ipc_ns;
spin_lock(&mq_lock);
ipc_ns = __get_ns_from_inode(dir);
if (!ipc_ns) {
error = -EACCES;
goto out_unlock;
}
if (ipc_ns->mq_queues_count >= ipc_ns->mq_queues_max &&
!capable(CAP_SYS_RESOURCE)) {
error = -ENOSPC;
goto out_unlock;
}
ipc_ns->mq_queues_count++;
spin_unlock(&mq_lock);
inode = mqueue_get_inode(dir->i_sb, ipc_ns, mode, attr);
if (IS_ERR(inode)) {
error = PTR_ERR(inode);
spin_lock(&mq_lock);
ipc_ns->mq_queues_count--;
goto out_unlock;
}
put_ipc_ns(ipc_ns);
dir->i_size += DIRENT_SIZE;
dir->i_ctime = dir->i_mtime = dir->i_atime = CURRENT_TIME;
d_instantiate(dentry, inode);
dget(dentry);
return 0;
out_unlock:
spin_unlock(&mq_lock);
if (ipc_ns)
put_ipc_ns(ipc_ns);
return error;
}
static int mqueue_unlink(struct inode *dir, struct dentry *dentry)
{
struct inode *inode = dentry->d_inode;
dir->i_ctime = dir->i_mtime = dir->i_atime = CURRENT_TIME;
dir->i_size -= DIRENT_SIZE;
drop_nlink(inode);
dput(dentry);
return 0;
}
static ssize_t mqueue_read_file(struct file *filp, char __user *u_data,
size_t count, loff_t *off)
{
struct mqueue_inode_info *info = MQUEUE_I(filp->f_path.dentry->d_inode);
char buffer[FILENT_SIZE];
ssize_t ret;
spin_lock(&info->lock);
snprintf(buffer, sizeof(buffer),
"QSIZE:%-10lu NOTIFY:%-5d SIGNO:%-5d NOTIFY_PID:%-6d\n",
info->qsize,
info->notify_owner ? info->notify.sigev_notify : 0,
(info->notify_owner &&
info->notify.sigev_notify == SIGEV_SIGNAL) ?
info->notify.sigev_signo : 0,
pid_vnr(info->notify_owner));
spin_unlock(&info->lock);
buffer[sizeof(buffer)-1] = '\0';
ret = simple_read_from_buffer(u_data, count, off, buffer,
strlen(buffer));
if (ret <= 0)
return ret;
filp->f_path.dentry->d_inode->i_atime = filp->f_path.dentry->d_inode->i_ctime = CURRENT_TIME;
return ret;
}
static int mqueue_flush_file(struct file *filp, fl_owner_t id)
{
struct mqueue_inode_info *info = MQUEUE_I(filp->f_path.dentry->d_inode);
spin_lock(&info->lock);
if (task_tgid(current) == info->notify_owner)
remove_notification(info);
spin_unlock(&info->lock);
return 0;
}
static unsigned int mqueue_poll_file(struct file *filp, struct poll_table_struct *poll_tab)
{
struct mqueue_inode_info *info = MQUEUE_I(filp->f_path.dentry->d_inode);
int retval = 0;
poll_wait(filp, &info->wait_q, poll_tab);
spin_lock(&info->lock);
if (info->attr.mq_curmsgs)
retval = POLLIN | POLLRDNORM;
if (info->attr.mq_curmsgs < info->attr.mq_maxmsg)
retval |= POLLOUT | POLLWRNORM;
spin_unlock(&info->lock);
return retval;
}
static void wq_add(struct mqueue_inode_info *info, int sr,
struct ext_wait_queue *ewp)
{
struct ext_wait_queue *walk;
ewp->task = current;
list_for_each_entry(walk, &info->e_wait_q[sr].list, list) {
if (walk->task->static_prio <= current->static_prio) {
list_add_tail(&ewp->list, &walk->list);
return;
}
}
list_add_tail(&ewp->list, &info->e_wait_q[sr].list);
}
static int wq_sleep(struct mqueue_inode_info *info, int sr,
ktime_t *timeout, struct ext_wait_queue *ewp)
{
int retval;
signed long time;
wq_add(info, sr, ewp);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock(&info->lock);
time = schedule_hrtimeout_range_clock(timeout, 0,
HRTIMER_MODE_ABS, CLOCK_REALTIME);
while (ewp->state == STATE_PENDING)
cpu_relax();
if (ewp->state == STATE_READY) {
retval = 0;
goto out;
}
spin_lock(&info->lock);
if (ewp->state == STATE_READY) {
retval = 0;
goto out_unlock;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
if (time == 0) {
retval = -ETIMEDOUT;
break;
}
}
list_del(&ewp->list);
out_unlock:
spin_unlock(&info->lock);
out:
return retval;
}
static struct ext_wait_queue *wq_get_first_waiter(
struct mqueue_inode_info *info, int sr)
{
struct list_head *ptr;
ptr = info->e_wait_q[sr].list.prev;
if (ptr == &info->e_wait_q[sr].list)
return NULL;
return list_entry(ptr, struct ext_wait_queue, list);
}
static void msg_insert(struct msg_msg *ptr, struct mqueue_inode_info *info)
{
int k;
k = info->attr.mq_curmsgs - 1;
while (k >= 0 && info->messages[k]->m_type >= ptr->m_type) {
info->messages[k + 1] = info->messages[k];
k--;
}
info->attr.mq_curmsgs++;
info->qsize += ptr->m_ts;
info->messages[k + 1] = ptr;
}
static inline struct msg_msg *msg_get(struct mqueue_inode_info *info)
{
info->qsize -= info->messages[--info->attr.mq_curmsgs]->m_ts;
return info->messages[info->attr.mq_curmsgs];
}
static inline void set_cookie(struct sk_buff *skb, char code)
{
((char*)skb->data)[NOTIFY_COOKIE_LEN-1] = code;
}
static void __do_notify(struct mqueue_inode_info *info)
{
if (info->notify_owner &&
info->attr.mq_curmsgs == 1) {
struct siginfo sig_i;
switch (info->notify.sigev_notify) {
case SIGEV_NONE:
break;
case SIGEV_SIGNAL:
sig_i.si_signo = info->notify.sigev_signo;
sig_i.si_errno = 0;
sig_i.si_code = SI_MESGQ;
sig_i.si_value = info->notify.sigev_value;
sig_i.si_pid = task_tgid_nr_ns(current,
ns_of_pid(info->notify_owner));
sig_i.si_uid = current_uid();
kill_pid_info(info->notify.sigev_signo,
&sig_i, info->notify_owner);
break;
case SIGEV_THREAD:
set_cookie(info->notify_cookie, NOTIFY_WOKENUP);
netlink_sendskb(info->notify_sock, info->notify_cookie);
break;
}
put_pid(info->notify_owner);
info->notify_owner = NULL;
}
wake_up(&info->wait_q);
}
static int prepare_timeout(const struct timespec __user *u_abs_timeout,
ktime_t *expires, struct timespec *ts)
{
if (copy_from_user(ts, u_abs_timeout, sizeof(struct timespec)))
return -EFAULT;
if (!timespec_valid(ts))
return -EINVAL;
*expires = timespec_to_ktime(*ts);
return 0;
}
static void remove_notification(struct mqueue_inode_info *info)
{
if (info->notify_owner != NULL &&
info->notify.sigev_notify == SIGEV_THREAD) {
set_cookie(info->notify_cookie, NOTIFY_REMOVED);
netlink_sendskb(info->notify_sock, info->notify_cookie);
}
put_pid(info->notify_owner);
info->notify_owner = NULL;
}
static int mq_attr_ok(struct ipc_namespace *ipc_ns, struct mq_attr *attr)
{
if (attr->mq_maxmsg <= 0 || attr->mq_msgsize <= 0)
return 0;
if (capable(CAP_SYS_RESOURCE)) {
if (attr->mq_maxmsg > HARD_MSGMAX)
return 0;
} else {
if (attr->mq_maxmsg > ipc_ns->mq_msg_max ||
attr->mq_msgsize > ipc_ns->mq_msgsize_max)
return 0;
}
if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
return 0;
if ((unsigned long)(attr->mq_maxmsg * (attr->mq_msgsize
+ sizeof (struct msg_msg *))) <
(unsigned long)(attr->mq_maxmsg * attr->mq_msgsize))
return 0;
return 1;
}
static struct file *do_create(struct ipc_namespace *ipc_ns, struct dentry *dir,
struct dentry *dentry, int oflag, mode_t mode,
struct mq_attr *attr)
{
const struct cred *cred = current_cred();
struct file *result;
int ret;
if (attr) {
if (!mq_attr_ok(ipc_ns, attr)) {
ret = -EINVAL;
goto out;
}
dentry->d_fsdata = attr;
}
mode &= ~current_umask();
ret = mnt_want_write(ipc_ns->mq_mnt);
if (ret)
goto out;
ret = vfs_create(dir->d_inode, dentry, mode, NULL);
dentry->d_fsdata = NULL;
if (ret)
goto out_drop_write;
result = dentry_open(dentry, ipc_ns->mq_mnt, oflag, cred);
mnt_drop_write(ipc_ns->mq_mnt);
return result;
out_drop_write:
mnt_drop_write(ipc_ns->mq_mnt);
out:
dput(dentry);
mntput(ipc_ns->mq_mnt);
return ERR_PTR(ret);
}
static struct file *do_open(struct ipc_namespace *ipc_ns,
struct dentry *dentry, int oflag)
{
int ret;
const struct cred *cred = current_cred();
static const int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
MAY_READ | MAY_WRITE };
if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY)) {
ret = -EINVAL;
goto err;
}
if (inode_permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE])) {
ret = -EACCES;
goto err;
}
return dentry_open(dentry, ipc_ns->mq_mnt, oflag, cred);
err:
dput(dentry);
mntput(ipc_ns->mq_mnt);
return ERR_PTR(ret);
}
static inline void pipelined_send(struct mqueue_inode_info *info,
struct msg_msg *message,
struct ext_wait_queue *receiver)
{
receiver->msg = message;
list_del(&receiver->list);
receiver->state = STATE_PENDING;
wake_up_process(receiver->task);
smp_wmb();
receiver->state = STATE_READY;
}
static inline void pipelined_receive(struct mqueue_inode_info *info)
{
struct ext_wait_queue *sender = wq_get_first_waiter(info, SEND);
if (!sender) {
wake_up_interruptible(&info->wait_q);
return;
}
msg_insert(sender->msg, info);
list_del(&sender->list);
sender->state = STATE_PENDING;
wake_up_process(sender->task);
smp_wmb();
sender->state = STATE_READY;
}
int mq_init_ns(struct ipc_namespace *ns)
{
ns->mq_queues_count = 0;
ns->mq_queues_max = DFLT_QUEUESMAX;
ns->mq_msg_max = DFLT_MSGMAX;
ns->mq_msgsize_max = DFLT_MSGSIZEMAX;
ns->mq_mnt = kern_mount_data(&mqueue_fs_type, ns);
if (IS_ERR(ns->mq_mnt)) {
int err = PTR_ERR(ns->mq_mnt);
ns->mq_mnt = NULL;
return err;
}
return 0;
}
void mq_clear_sbinfo(struct ipc_namespace *ns)
{
ns->mq_mnt->mnt_sb->s_fs_info = NULL;
}
void mq_put_mnt(struct ipc_namespace *ns)
{
kern_unmount(ns->mq_mnt);
}
static int __init init_mqueue_fs(void)
{
int error;
mqueue_inode_cachep = kmem_cache_create("mqueue_inode_cache",
sizeof(struct mqueue_inode_info), 0,
SLAB_HWCACHE_ALIGN, init_once);
if (mqueue_inode_cachep == NULL)
return -ENOMEM;
mq_sysctl_table = mq_register_sysctl_table();
error = register_filesystem(&mqueue_fs_type);
if (error)
goto out_sysctl;
spin_lock_init(&mq_lock);
error = mq_init_ns(&init_ipc_ns);
if (error)
goto out_filesystem;
return 0;
out_filesystem:
unregister_filesystem(&mqueue_fs_type);
out_sysctl:
if (mq_sysctl_table)
unregister_sysctl_table(mq_sysctl_table);
kmem_cache_destroy(mqueue_inode_cachep);
return error;
}
