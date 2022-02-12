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
static int msg_insert(struct msg_msg *msg, struct mqueue_inode_info *info)
{
struct rb_node **p, *parent = NULL;
struct posix_msg_tree_node *leaf;
p = &info->msg_tree.rb_node;
while (*p) {
parent = *p;
leaf = rb_entry(parent, struct posix_msg_tree_node, rb_node);
if (likely(leaf->priority == msg->m_type))
goto insert_msg;
else if (msg->m_type < leaf->priority)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
if (info->node_cache) {
leaf = info->node_cache;
info->node_cache = NULL;
} else {
leaf = kmalloc(sizeof(*leaf), GFP_ATOMIC);
if (!leaf)
return -ENOMEM;
INIT_LIST_HEAD(&leaf->msg_list);
}
leaf->priority = msg->m_type;
rb_link_node(&leaf->rb_node, parent, p);
rb_insert_color(&leaf->rb_node, &info->msg_tree);
insert_msg:
info->attr.mq_curmsgs++;
info->qsize += msg->m_ts;
list_add_tail(&msg->m_list, &leaf->msg_list);
return 0;
}
static inline struct msg_msg *msg_get(struct mqueue_inode_info *info)
{
struct rb_node **p, *parent = NULL;
struct posix_msg_tree_node *leaf;
struct msg_msg *msg;
try_again:
p = &info->msg_tree.rb_node;
while (*p) {
parent = *p;
p = &(*p)->rb_right;
}
if (!parent) {
if (info->attr.mq_curmsgs) {
pr_warn_once("Inconsistency in POSIX message queue, "
"no tree element, but supposedly messages "
"should exist!\n");
info->attr.mq_curmsgs = 0;
}
return NULL;
}
leaf = rb_entry(parent, struct posix_msg_tree_node, rb_node);
if (unlikely(list_empty(&leaf->msg_list))) {
pr_warn_once("Inconsistency in POSIX message queue, "
"empty leaf node but we haven't implemented "
"lazy leaf delete!\n");
rb_erase(&leaf->rb_node, &info->msg_tree);
if (info->node_cache) {
kfree(leaf);
} else {
info->node_cache = leaf;
}
goto try_again;
} else {
msg = list_first_entry(&leaf->msg_list,
struct msg_msg, m_list);
list_del(&msg->m_list);
if (list_empty(&leaf->msg_list)) {
rb_erase(&leaf->rb_node, &info->msg_tree);
if (info->node_cache) {
kfree(leaf);
} else {
info->node_cache = leaf;
}
}
}
info->attr.mq_curmsgs--;
info->qsize -= msg->m_ts;
return msg;
}
static struct inode *mqueue_get_inode(struct super_block *sb,
struct ipc_namespace *ipc_ns, umode_t mode,
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
unsigned long mq_bytes, mq_treesize;
inode->i_fop = &mqueue_file_operations;
inode->i_size = FILENT_SIZE;
info = MQUEUE_I(inode);
spin_lock_init(&info->lock);
init_waitqueue_head(&info->wait_q);
INIT_LIST_HEAD(&info->e_wait_q[0].list);
INIT_LIST_HEAD(&info->e_wait_q[1].list);
info->notify_owner = NULL;
info->notify_user_ns = NULL;
info->qsize = 0;
info->user = NULL;
info->msg_tree = RB_ROOT;
info->node_cache = NULL;
memset(&info->attr, 0, sizeof(info->attr));
info->attr.mq_maxmsg = min(ipc_ns->mq_msg_max,
ipc_ns->mq_msg_default);
info->attr.mq_msgsize = min(ipc_ns->mq_msgsize_max,
ipc_ns->mq_msgsize_default);
if (attr) {
info->attr.mq_maxmsg = attr->mq_maxmsg;
info->attr.mq_msgsize = attr->mq_msgsize;
}
mq_treesize = info->attr.mq_maxmsg * sizeof(struct msg_msg) +
min_t(unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof(struct posix_msg_tree_node);
mq_bytes = mq_treesize + (info->attr.mq_maxmsg *
info->attr.mq_msgsize);
spin_lock(&mq_lock);
if (u->mq_bytes + mq_bytes < u->mq_bytes ||
u->mq_bytes + mq_bytes > rlimit(RLIMIT_MSGQUEUE)) {
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
sb->s_blocksize = PAGE_CACHE_SIZE;
sb->s_blocksize_bits = PAGE_CACHE_SHIFT;
sb->s_magic = MQUEUE_MAGIC;
sb->s_op = &mqueue_super_ops;
inode = mqueue_get_inode(sb, ns, S_IFDIR | S_ISVTX | S_IRWXUGO, NULL);
if (IS_ERR(inode))
return PTR_ERR(inode);
sb->s_root = d_make_root(inode);
if (!sb->s_root)
return -ENOMEM;
return 0;
}
static struct dentry *mqueue_mount(struct file_system_type *fs_type,
int flags, const char *dev_name,
void *data)
{
if (!(flags & MS_KERNMOUNT)) {
struct ipc_namespace *ns = current->nsproxy->ipc_ns;
if (!ns_capable(ns->user_ns, CAP_SYS_ADMIN))
return ERR_PTR(-EPERM);
data = ns;
}
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
unsigned long mq_bytes, mq_treesize;
struct ipc_namespace *ipc_ns;
struct msg_msg *msg;
clear_inode(inode);
if (S_ISDIR(inode->i_mode))
return;
ipc_ns = get_ns_from_inode(inode);
info = MQUEUE_I(inode);
spin_lock(&info->lock);
while ((msg = msg_get(info)) != NULL)
free_msg(msg);
kfree(info->node_cache);
spin_unlock(&info->lock);
mq_treesize = info->attr.mq_maxmsg * sizeof(struct msg_msg) +
min_t(unsigned int, info->attr.mq_maxmsg, MQ_PRIO_MAX) *
sizeof(struct posix_msg_tree_node);
mq_bytes = mq_treesize + (info->attr.mq_maxmsg *
info->attr.mq_msgsize);
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
umode_t mode, bool excl)
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
struct inode *inode = d_inode(dentry);
dir->i_ctime = dir->i_mtime = dir->i_atime = CURRENT_TIME;
dir->i_size -= DIRENT_SIZE;
drop_nlink(inode);
dput(dentry);
return 0;
}
static ssize_t mqueue_read_file(struct file *filp, char __user *u_data,
size_t count, loff_t *off)
{
struct mqueue_inode_info *info = MQUEUE_I(file_inode(filp));
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
file_inode(filp)->i_atime = file_inode(filp)->i_ctime = CURRENT_TIME;
return ret;
}
static int mqueue_flush_file(struct file *filp, fl_owner_t id)
{
struct mqueue_inode_info *info = MQUEUE_I(file_inode(filp));
spin_lock(&info->lock);
if (task_tgid(current) == info->notify_owner)
remove_notification(info);
spin_unlock(&info->lock);
return 0;
}
static unsigned int mqueue_poll_file(struct file *filp, struct poll_table_struct *poll_tab)
{
struct mqueue_inode_info *info = MQUEUE_I(file_inode(filp));
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
__set_current_state(TASK_INTERRUPTIBLE);
spin_unlock(&info->lock);
time = schedule_hrtimeout_range_clock(timeout, 0,
HRTIMER_MODE_ABS, CLOCK_REALTIME);
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
static inline void set_cookie(struct sk_buff *skb, char code)
{
((char *)skb->data)[NOTIFY_COOKIE_LEN-1] = code;
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
rcu_read_lock();
sig_i.si_pid = task_tgid_nr_ns(current,
ns_of_pid(info->notify_owner));
sig_i.si_uid = from_kuid_munged(info->notify_user_ns, current_uid());
rcu_read_unlock();
kill_pid_info(info->notify.sigev_signo,
&sig_i, info->notify_owner);
break;
case SIGEV_THREAD:
set_cookie(info->notify_cookie, NOTIFY_WOKENUP);
netlink_sendskb(info->notify_sock, info->notify_cookie);
break;
}
put_pid(info->notify_owner);
put_user_ns(info->notify_user_ns);
info->notify_owner = NULL;
info->notify_user_ns = NULL;
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
put_user_ns(info->notify_user_ns);
info->notify_owner = NULL;
info->notify_user_ns = NULL;
}
static int mq_attr_ok(struct ipc_namespace *ipc_ns, struct mq_attr *attr)
{
int mq_treesize;
unsigned long total_size;
if (attr->mq_maxmsg <= 0 || attr->mq_msgsize <= 0)
return -EINVAL;
if (capable(CAP_SYS_RESOURCE)) {
if (attr->mq_maxmsg > HARD_MSGMAX ||
attr->mq_msgsize > HARD_MSGSIZEMAX)
return -EINVAL;
} else {
if (attr->mq_maxmsg > ipc_ns->mq_msg_max ||
attr->mq_msgsize > ipc_ns->mq_msgsize_max)
return -EINVAL;
}
if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
return -EOVERFLOW;
mq_treesize = attr->mq_maxmsg * sizeof(struct msg_msg) +
min_t(unsigned int, attr->mq_maxmsg, MQ_PRIO_MAX) *
sizeof(struct posix_msg_tree_node);
total_size = attr->mq_maxmsg * attr->mq_msgsize;
if (total_size + mq_treesize < total_size)
return -EOVERFLOW;
return 0;
}
static struct file *do_create(struct ipc_namespace *ipc_ns, struct inode *dir,
struct path *path, int oflag, umode_t mode,
struct mq_attr *attr)
{
const struct cred *cred = current_cred();
int ret;
if (attr) {
ret = mq_attr_ok(ipc_ns, attr);
if (ret)
return ERR_PTR(ret);
path->dentry->d_fsdata = attr;
} else {
struct mq_attr def_attr;
def_attr.mq_maxmsg = min(ipc_ns->mq_msg_max,
ipc_ns->mq_msg_default);
def_attr.mq_msgsize = min(ipc_ns->mq_msgsize_max,
ipc_ns->mq_msgsize_default);
ret = mq_attr_ok(ipc_ns, &def_attr);
if (ret)
return ERR_PTR(ret);
}
mode &= ~current_umask();
ret = vfs_create(dir, path->dentry, mode, true);
path->dentry->d_fsdata = NULL;
if (ret)
return ERR_PTR(ret);
return dentry_open(path, oflag, cred);
}
static struct file *do_open(struct path *path, int oflag)
{
static const int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
MAY_READ | MAY_WRITE };
int acc;
if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY))
return ERR_PTR(-EINVAL);
acc = oflag2acc[oflag & O_ACCMODE];
if (inode_permission(d_inode(path->dentry), acc))
return ERR_PTR(-EACCES);
return dentry_open(path, oflag, current_cred());
}
static inline void pipelined_send(struct wake_q_head *wake_q,
struct mqueue_inode_info *info,
struct msg_msg *message,
struct ext_wait_queue *receiver)
{
receiver->msg = message;
list_del(&receiver->list);
wake_q_add(wake_q, receiver->task);
receiver->state = STATE_READY;
}
static inline void pipelined_receive(struct wake_q_head *wake_q,
struct mqueue_inode_info *info)
{
struct ext_wait_queue *sender = wq_get_first_waiter(info, SEND);
if (!sender) {
wake_up_interruptible(&info->wait_q);
return;
}
if (msg_insert(sender->msg, info))
return;
list_del(&sender->list);
wake_q_add(wake_q, sender->task);
sender->state = STATE_READY;
}
int mq_init_ns(struct ipc_namespace *ns)
{
ns->mq_queues_count = 0;
ns->mq_queues_max = DFLT_QUEUESMAX;
ns->mq_msg_max = DFLT_MSGMAX;
ns->mq_msgsize_max = DFLT_MSGSIZEMAX;
ns->mq_msg_default = DFLT_MSG;
ns->mq_msgsize_default = DFLT_MSGSIZE;
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
