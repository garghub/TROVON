static inline __u32 inotify_arg_to_mask(u32 arg)
{
__u32 mask;
mask = (FS_IN_IGNORED | FS_EVENT_ON_CHILD | FS_UNMOUNT);
mask |= (arg & (IN_ALL_EVENTS | IN_ONESHOT | IN_EXCL_UNLINK));
return mask;
}
static inline u32 inotify_mask_to_arg(__u32 mask)
{
return mask & (IN_ALL_EVENTS | IN_ISDIR | IN_UNMOUNT | IN_IGNORED |
IN_Q_OVERFLOW);
}
static unsigned int inotify_poll(struct file *file, poll_table *wait)
{
struct fsnotify_group *group = file->private_data;
int ret = 0;
poll_wait(file, &group->notification_waitq, wait);
mutex_lock(&group->notification_mutex);
if (!fsnotify_notify_queue_is_empty(group))
ret = POLLIN | POLLRDNORM;
mutex_unlock(&group->notification_mutex);
return ret;
}
static int round_event_name_len(struct fsnotify_event *fsn_event)
{
struct inotify_event_info *event;
event = INOTIFY_E(fsn_event);
if (!event->name_len)
return 0;
return roundup(event->name_len + 1, sizeof(struct inotify_event));
}
static struct fsnotify_event *get_one_event(struct fsnotify_group *group,
size_t count)
{
size_t event_size = sizeof(struct inotify_event);
struct fsnotify_event *event;
if (fsnotify_notify_queue_is_empty(group))
return NULL;
event = fsnotify_peek_notify_event(group);
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
event_size += round_event_name_len(event);
if (event_size > count)
return ERR_PTR(-EINVAL);
fsnotify_remove_notify_event(group);
return event;
}
static ssize_t copy_event_to_user(struct fsnotify_group *group,
struct fsnotify_event *fsn_event,
char __user *buf)
{
struct inotify_event inotify_event;
struct inotify_event_info *event;
size_t event_size = sizeof(struct inotify_event);
size_t name_len;
size_t pad_name_len;
pr_debug("%s: group=%p event=%p\n", __func__, group, fsn_event);
event = INOTIFY_E(fsn_event);
name_len = event->name_len;
pad_name_len = round_event_name_len(fsn_event);
inotify_event.len = pad_name_len;
inotify_event.mask = inotify_mask_to_arg(fsn_event->mask);
inotify_event.wd = event->wd;
inotify_event.cookie = event->sync_cookie;
if (copy_to_user(buf, &inotify_event, event_size))
return -EFAULT;
buf += event_size;
if (pad_name_len) {
if (copy_to_user(buf, event->name, name_len))
return -EFAULT;
buf += name_len;
if (clear_user(buf, pad_name_len - name_len))
return -EFAULT;
event_size += pad_name_len;
}
return event_size;
}
static ssize_t inotify_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
struct fsnotify_group *group;
struct fsnotify_event *kevent;
char __user *start;
int ret;
DEFINE_WAIT(wait);
start = buf;
group = file->private_data;
while (1) {
prepare_to_wait(&group->notification_waitq, &wait, TASK_INTERRUPTIBLE);
mutex_lock(&group->notification_mutex);
kevent = get_one_event(group, count);
mutex_unlock(&group->notification_mutex);
pr_debug("%s: group=%p kevent=%p\n", __func__, group, kevent);
if (kevent) {
ret = PTR_ERR(kevent);
if (IS_ERR(kevent))
break;
ret = copy_event_to_user(group, kevent, buf);
fsnotify_destroy_event(group, kevent);
if (ret < 0)
break;
buf += ret;
count -= ret;
continue;
}
ret = -EAGAIN;
if (file->f_flags & O_NONBLOCK)
break;
ret = -ERESTARTSYS;
if (signal_pending(current))
break;
if (start != buf)
break;
schedule();
}
finish_wait(&group->notification_waitq, &wait);
if (start != buf && ret != -EFAULT)
ret = buf - start;
return ret;
}
static int inotify_release(struct inode *ignored, struct file *file)
{
struct fsnotify_group *group = file->private_data;
pr_debug("%s: group=%p\n", __func__, group);
fsnotify_destroy_group(group);
return 0;
}
static long inotify_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct fsnotify_group *group;
struct fsnotify_event *fsn_event;
void __user *p;
int ret = -ENOTTY;
size_t send_len = 0;
group = file->private_data;
p = (void __user *) arg;
pr_debug("%s: group=%p cmd=%u\n", __func__, group, cmd);
switch (cmd) {
case FIONREAD:
mutex_lock(&group->notification_mutex);
list_for_each_entry(fsn_event, &group->notification_list,
list) {
send_len += sizeof(struct inotify_event);
send_len += round_event_name_len(fsn_event);
}
mutex_unlock(&group->notification_mutex);
ret = put_user(send_len, (int __user *) p);
break;
}
return ret;
}
static int inotify_find_inode(const char __user *dirname, struct path *path, unsigned flags)
{
int error;
error = user_path_at(AT_FDCWD, dirname, flags, path);
if (error)
return error;
error = inode_permission(path->dentry->d_inode, MAY_READ);
if (error)
path_put(path);
return error;
}
static int inotify_add_to_idr(struct idr *idr, spinlock_t *idr_lock,
struct inotify_inode_mark *i_mark)
{
int ret;
idr_preload(GFP_KERNEL);
spin_lock(idr_lock);
ret = idr_alloc_cyclic(idr, i_mark, 1, 0, GFP_NOWAIT);
if (ret >= 0) {
i_mark->wd = ret;
fsnotify_get_mark(&i_mark->fsn_mark);
}
spin_unlock(idr_lock);
idr_preload_end();
return ret < 0 ? ret : 0;
}
static struct inotify_inode_mark *inotify_idr_find_locked(struct fsnotify_group *group,
int wd)
{
struct idr *idr = &group->inotify_data.idr;
spinlock_t *idr_lock = &group->inotify_data.idr_lock;
struct inotify_inode_mark *i_mark;
assert_spin_locked(idr_lock);
i_mark = idr_find(idr, wd);
if (i_mark) {
struct fsnotify_mark *fsn_mark = &i_mark->fsn_mark;
fsnotify_get_mark(fsn_mark);
BUG_ON(atomic_read(&fsn_mark->refcnt) < 2);
}
return i_mark;
}
static struct inotify_inode_mark *inotify_idr_find(struct fsnotify_group *group,
int wd)
{
struct inotify_inode_mark *i_mark;
spinlock_t *idr_lock = &group->inotify_data.idr_lock;
spin_lock(idr_lock);
i_mark = inotify_idr_find_locked(group, wd);
spin_unlock(idr_lock);
return i_mark;
}
static void do_inotify_remove_from_idr(struct fsnotify_group *group,
struct inotify_inode_mark *i_mark)
{
struct idr *idr = &group->inotify_data.idr;
spinlock_t *idr_lock = &group->inotify_data.idr_lock;
int wd = i_mark->wd;
assert_spin_locked(idr_lock);
idr_remove(idr, wd);
fsnotify_put_mark(&i_mark->fsn_mark);
}
static void inotify_remove_from_idr(struct fsnotify_group *group,
struct inotify_inode_mark *i_mark)
{
spinlock_t *idr_lock = &group->inotify_data.idr_lock;
struct inotify_inode_mark *found_i_mark = NULL;
int wd;
spin_lock(idr_lock);
wd = i_mark->wd;
if (wd == -1) {
WARN_ONCE(1, "%s: i_mark=%p i_mark->wd=%d i_mark->group=%p"
" i_mark->inode=%p\n", __func__, i_mark, i_mark->wd,
i_mark->fsn_mark.group, i_mark->fsn_mark.i.inode);
goto out;
}
found_i_mark = inotify_idr_find_locked(group, wd);
if (unlikely(!found_i_mark)) {
WARN_ONCE(1, "%s: i_mark=%p i_mark->wd=%d i_mark->group=%p"
" i_mark->inode=%p\n", __func__, i_mark, i_mark->wd,
i_mark->fsn_mark.group, i_mark->fsn_mark.i.inode);
goto out;
}
if (unlikely(found_i_mark != i_mark)) {
WARN_ONCE(1, "%s: i_mark=%p i_mark->wd=%d i_mark->group=%p "
"mark->inode=%p found_i_mark=%p found_i_mark->wd=%d "
"found_i_mark->group=%p found_i_mark->inode=%p\n",
__func__, i_mark, i_mark->wd, i_mark->fsn_mark.group,
i_mark->fsn_mark.i.inode, found_i_mark, found_i_mark->wd,
found_i_mark->fsn_mark.group,
found_i_mark->fsn_mark.i.inode);
goto out;
}
if (unlikely(atomic_read(&i_mark->fsn_mark.refcnt) < 3)) {
printk(KERN_ERR "%s: i_mark=%p i_mark->wd=%d i_mark->group=%p"
" i_mark->inode=%p\n", __func__, i_mark, i_mark->wd,
i_mark->fsn_mark.group, i_mark->fsn_mark.i.inode);
BUG();
}
do_inotify_remove_from_idr(group, i_mark);
out:
if (found_i_mark)
fsnotify_put_mark(&found_i_mark->fsn_mark);
i_mark->wd = -1;
spin_unlock(idr_lock);
}
void inotify_ignored_and_remove_idr(struct fsnotify_mark *fsn_mark,
struct fsnotify_group *group)
{
struct inotify_inode_mark *i_mark;
inotify_handle_event(group, NULL, fsn_mark, NULL, FS_IN_IGNORED,
NULL, FSNOTIFY_EVENT_NONE, NULL, 0);
i_mark = container_of(fsn_mark, struct inotify_inode_mark, fsn_mark);
inotify_remove_from_idr(group, i_mark);
atomic_dec(&group->inotify_data.user->inotify_watches);
}
static void inotify_free_mark(struct fsnotify_mark *fsn_mark)
{
struct inotify_inode_mark *i_mark;
i_mark = container_of(fsn_mark, struct inotify_inode_mark, fsn_mark);
kmem_cache_free(inotify_inode_mark_cachep, i_mark);
}
static int inotify_update_existing_watch(struct fsnotify_group *group,
struct inode *inode,
u32 arg)
{
struct fsnotify_mark *fsn_mark;
struct inotify_inode_mark *i_mark;
__u32 old_mask, new_mask;
__u32 mask;
int add = (arg & IN_MASK_ADD);
int ret;
mask = inotify_arg_to_mask(arg);
fsn_mark = fsnotify_find_inode_mark(group, inode);
if (!fsn_mark)
return -ENOENT;
i_mark = container_of(fsn_mark, struct inotify_inode_mark, fsn_mark);
spin_lock(&fsn_mark->lock);
old_mask = fsn_mark->mask;
if (add)
fsnotify_set_mark_mask_locked(fsn_mark, (fsn_mark->mask | mask));
else
fsnotify_set_mark_mask_locked(fsn_mark, mask);
new_mask = fsn_mark->mask;
spin_unlock(&fsn_mark->lock);
if (old_mask != new_mask) {
int dropped = (old_mask & ~new_mask);
int do_inode = (new_mask & ~inode->i_fsnotify_mask);
if (dropped || do_inode)
fsnotify_recalc_inode_mask(inode);
}
ret = i_mark->wd;
fsnotify_put_mark(fsn_mark);
return ret;
}
static int inotify_new_watch(struct fsnotify_group *group,
struct inode *inode,
u32 arg)
{
struct inotify_inode_mark *tmp_i_mark;
__u32 mask;
int ret;
struct idr *idr = &group->inotify_data.idr;
spinlock_t *idr_lock = &group->inotify_data.idr_lock;
mask = inotify_arg_to_mask(arg);
tmp_i_mark = kmem_cache_alloc(inotify_inode_mark_cachep, GFP_KERNEL);
if (unlikely(!tmp_i_mark))
return -ENOMEM;
fsnotify_init_mark(&tmp_i_mark->fsn_mark, inotify_free_mark);
tmp_i_mark->fsn_mark.mask = mask;
tmp_i_mark->wd = -1;
ret = -ENOSPC;
if (atomic_read(&group->inotify_data.user->inotify_watches) >= inotify_max_user_watches)
goto out_err;
ret = inotify_add_to_idr(idr, idr_lock, tmp_i_mark);
if (ret)
goto out_err;
ret = fsnotify_add_mark_locked(&tmp_i_mark->fsn_mark, group, inode,
NULL, 0);
if (ret) {
inotify_remove_from_idr(group, tmp_i_mark);
goto out_err;
}
atomic_inc(&group->inotify_data.user->inotify_watches);
ret = tmp_i_mark->wd;
out_err:
fsnotify_put_mark(&tmp_i_mark->fsn_mark);
return ret;
}
static int inotify_update_watch(struct fsnotify_group *group, struct inode *inode, u32 arg)
{
int ret = 0;
mutex_lock(&group->mark_mutex);
ret = inotify_update_existing_watch(group, inode, arg);
if (ret == -ENOENT)
ret = inotify_new_watch(group, inode, arg);
mutex_unlock(&group->mark_mutex);
return ret;
}
static struct fsnotify_group *inotify_new_group(unsigned int max_events)
{
struct fsnotify_group *group;
struct inotify_event_info *oevent;
group = fsnotify_alloc_group(&inotify_fsnotify_ops);
if (IS_ERR(group))
return group;
oevent = kmalloc(sizeof(struct inotify_event_info), GFP_KERNEL);
if (unlikely(!oevent)) {
fsnotify_destroy_group(group);
return ERR_PTR(-ENOMEM);
}
group->overflow_event = &oevent->fse;
fsnotify_init_event(group->overflow_event, NULL, FS_Q_OVERFLOW);
oevent->wd = -1;
oevent->sync_cookie = 0;
oevent->name_len = 0;
group->max_events = max_events;
spin_lock_init(&group->inotify_data.idr_lock);
idr_init(&group->inotify_data.idr);
group->inotify_data.user = get_current_user();
if (atomic_inc_return(&group->inotify_data.user->inotify_devs) >
inotify_max_user_instances) {
fsnotify_destroy_group(group);
return ERR_PTR(-EMFILE);
}
return group;
}
static int __init inotify_user_setup(void)
{
BUILD_BUG_ON(IN_ACCESS != FS_ACCESS);
BUILD_BUG_ON(IN_MODIFY != FS_MODIFY);
BUILD_BUG_ON(IN_ATTRIB != FS_ATTRIB);
BUILD_BUG_ON(IN_CLOSE_WRITE != FS_CLOSE_WRITE);
BUILD_BUG_ON(IN_CLOSE_NOWRITE != FS_CLOSE_NOWRITE);
BUILD_BUG_ON(IN_OPEN != FS_OPEN);
BUILD_BUG_ON(IN_MOVED_FROM != FS_MOVED_FROM);
BUILD_BUG_ON(IN_MOVED_TO != FS_MOVED_TO);
BUILD_BUG_ON(IN_CREATE != FS_CREATE);
BUILD_BUG_ON(IN_DELETE != FS_DELETE);
BUILD_BUG_ON(IN_DELETE_SELF != FS_DELETE_SELF);
BUILD_BUG_ON(IN_MOVE_SELF != FS_MOVE_SELF);
BUILD_BUG_ON(IN_UNMOUNT != FS_UNMOUNT);
BUILD_BUG_ON(IN_Q_OVERFLOW != FS_Q_OVERFLOW);
BUILD_BUG_ON(IN_IGNORED != FS_IN_IGNORED);
BUILD_BUG_ON(IN_EXCL_UNLINK != FS_EXCL_UNLINK);
BUILD_BUG_ON(IN_ISDIR != FS_ISDIR);
BUILD_BUG_ON(IN_ONESHOT != FS_IN_ONESHOT);
BUG_ON(hweight32(ALL_INOTIFY_BITS) != 21);
inotify_inode_mark_cachep = KMEM_CACHE(inotify_inode_mark, SLAB_PANIC);
inotify_max_queued_events = 16384;
inotify_max_user_instances = 128;
inotify_max_user_watches = 8192;
return 0;
}
