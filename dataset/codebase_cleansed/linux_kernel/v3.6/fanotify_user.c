static struct fsnotify_event *get_one_event(struct fsnotify_group *group,
size_t count)
{
BUG_ON(!mutex_is_locked(&group->notification_mutex));
pr_debug("%s: group=%p count=%zd\n", __func__, group, count);
if (fsnotify_notify_queue_is_empty(group))
return NULL;
if (FAN_EVENT_METADATA_LEN > count)
return ERR_PTR(-EINVAL);
return fsnotify_remove_notify_event(group);
}
static int create_fd(struct fsnotify_group *group, struct fsnotify_event *event)
{
int client_fd;
struct file *new_file;
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
client_fd = get_unused_fd();
if (client_fd < 0)
return client_fd;
if (event->data_type != FSNOTIFY_EVENT_PATH) {
WARN_ON(1);
put_unused_fd(client_fd);
return -EINVAL;
}
if (event->path.dentry && event->path.mnt)
new_file = dentry_open(&event->path,
group->fanotify_data.f_flags | FMODE_NONOTIFY,
current_cred());
else
new_file = ERR_PTR(-EOVERFLOW);
if (IS_ERR(new_file)) {
put_unused_fd(client_fd);
client_fd = PTR_ERR(new_file);
} else {
fd_install(client_fd, new_file);
}
return client_fd;
}
static int fill_event_metadata(struct fsnotify_group *group,
struct fanotify_event_metadata *metadata,
struct fsnotify_event *event)
{
int ret = 0;
pr_debug("%s: group=%p metadata=%p event=%p\n", __func__,
group, metadata, event);
metadata->event_len = FAN_EVENT_METADATA_LEN;
metadata->metadata_len = FAN_EVENT_METADATA_LEN;
metadata->vers = FANOTIFY_METADATA_VERSION;
metadata->mask = event->mask & FAN_ALL_OUTGOING_EVENTS;
metadata->pid = pid_vnr(event->tgid);
if (unlikely(event->mask & FAN_Q_OVERFLOW))
metadata->fd = FAN_NOFD;
else {
metadata->fd = create_fd(group, event);
if (metadata->fd < 0)
ret = metadata->fd;
}
return ret;
}
static struct fanotify_response_event *dequeue_re(struct fsnotify_group *group,
__s32 fd)
{
struct fanotify_response_event *re, *return_re = NULL;
mutex_lock(&group->fanotify_data.access_mutex);
list_for_each_entry(re, &group->fanotify_data.access_list, list) {
if (re->fd != fd)
continue;
list_del_init(&re->list);
return_re = re;
break;
}
mutex_unlock(&group->fanotify_data.access_mutex);
pr_debug("%s: found return_re=%p\n", __func__, return_re);
return return_re;
}
static int process_access_response(struct fsnotify_group *group,
struct fanotify_response *response_struct)
{
struct fanotify_response_event *re;
__s32 fd = response_struct->fd;
__u32 response = response_struct->response;
pr_debug("%s: group=%p fd=%d response=%d\n", __func__, group,
fd, response);
switch (response) {
case FAN_ALLOW:
case FAN_DENY:
break;
default:
return -EINVAL;
}
if (fd < 0)
return -EINVAL;
re = dequeue_re(group, fd);
if (!re)
return -ENOENT;
re->event->response = response;
wake_up(&group->fanotify_data.access_waitq);
kmem_cache_free(fanotify_response_event_cache, re);
return 0;
}
static int prepare_for_access_response(struct fsnotify_group *group,
struct fsnotify_event *event,
__s32 fd)
{
struct fanotify_response_event *re;
if (!(event->mask & FAN_ALL_PERM_EVENTS))
return 0;
re = kmem_cache_alloc(fanotify_response_event_cache, GFP_KERNEL);
if (!re)
return -ENOMEM;
re->event = event;
re->fd = fd;
mutex_lock(&group->fanotify_data.access_mutex);
if (atomic_read(&group->fanotify_data.bypass_perm)) {
mutex_unlock(&group->fanotify_data.access_mutex);
kmem_cache_free(fanotify_response_event_cache, re);
event->response = FAN_ALLOW;
return 0;
}
list_add_tail(&re->list, &group->fanotify_data.access_list);
mutex_unlock(&group->fanotify_data.access_mutex);
return 0;
}
static void remove_access_response(struct fsnotify_group *group,
struct fsnotify_event *event,
__s32 fd)
{
struct fanotify_response_event *re;
if (!(event->mask & FAN_ALL_PERM_EVENTS))
return;
re = dequeue_re(group, fd);
if (!re)
return;
BUG_ON(re->event != event);
kmem_cache_free(fanotify_response_event_cache, re);
return;
}
static int prepare_for_access_response(struct fsnotify_group *group,
struct fsnotify_event *event,
__s32 fd)
{
return 0;
}
static void remove_access_response(struct fsnotify_group *group,
struct fsnotify_event *event,
__s32 fd)
{
return;
}
static ssize_t copy_event_to_user(struct fsnotify_group *group,
struct fsnotify_event *event,
char __user *buf)
{
struct fanotify_event_metadata fanotify_event_metadata;
int fd, ret;
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
ret = fill_event_metadata(group, &fanotify_event_metadata, event);
if (ret < 0)
goto out;
fd = fanotify_event_metadata.fd;
ret = prepare_for_access_response(group, event, fd);
if (ret)
goto out_close_fd;
ret = -EFAULT;
if (copy_to_user(buf, &fanotify_event_metadata,
fanotify_event_metadata.event_len))
goto out_kill_access_response;
return fanotify_event_metadata.event_len;
out_kill_access_response:
remove_access_response(group, event, fd);
out_close_fd:
if (fd != FAN_NOFD)
sys_close(fd);
out:
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (event->mask & FAN_ALL_PERM_EVENTS) {
event->response = FAN_DENY;
wake_up(&group->fanotify_data.access_waitq);
}
#endif
return ret;
}
static unsigned int fanotify_poll(struct file *file, poll_table *wait)
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
static ssize_t fanotify_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
struct fsnotify_group *group;
struct fsnotify_event *kevent;
char __user *start;
int ret;
DEFINE_WAIT(wait);
start = buf;
group = file->private_data;
pr_debug("%s: group=%p\n", __func__, group);
while (1) {
prepare_to_wait(&group->notification_waitq, &wait, TASK_INTERRUPTIBLE);
mutex_lock(&group->notification_mutex);
kevent = get_one_event(group, count);
mutex_unlock(&group->notification_mutex);
if (kevent) {
ret = PTR_ERR(kevent);
if (IS_ERR(kevent))
break;
ret = copy_event_to_user(group, kevent, buf);
fsnotify_put_event(kevent);
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
static ssize_t fanotify_write(struct file *file, const char __user *buf, size_t count, loff_t *pos)
{
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
struct fanotify_response response = { .fd = -1, .response = -1 };
struct fsnotify_group *group;
int ret;
group = file->private_data;
if (count > sizeof(response))
count = sizeof(response);
pr_debug("%s: group=%p count=%zu\n", __func__, group, count);
if (copy_from_user(&response, buf, count))
return -EFAULT;
ret = process_access_response(group, &response);
if (ret < 0)
count = ret;
return count;
#else
return -EINVAL;
#endif
}
static int fanotify_release(struct inode *ignored, struct file *file)
{
struct fsnotify_group *group = file->private_data;
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
struct fanotify_response_event *re, *lre;
mutex_lock(&group->fanotify_data.access_mutex);
atomic_inc(&group->fanotify_data.bypass_perm);
list_for_each_entry_safe(re, lre, &group->fanotify_data.access_list, list) {
pr_debug("%s: found group=%p re=%p event=%p\n", __func__, group,
re, re->event);
list_del_init(&re->list);
re->event->response = FAN_ALLOW;
kmem_cache_free(fanotify_response_event_cache, re);
}
mutex_unlock(&group->fanotify_data.access_mutex);
wake_up(&group->fanotify_data.access_waitq);
#endif
fsnotify_put_group(group);
return 0;
}
static long fanotify_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct fsnotify_group *group;
struct fsnotify_event_holder *holder;
void __user *p;
int ret = -ENOTTY;
size_t send_len = 0;
group = file->private_data;
p = (void __user *) arg;
switch (cmd) {
case FIONREAD:
mutex_lock(&group->notification_mutex);
list_for_each_entry(holder, &group->notification_list, event_list)
send_len += FAN_EVENT_METADATA_LEN;
mutex_unlock(&group->notification_mutex);
ret = put_user(send_len, (int __user *) p);
break;
}
return ret;
}
static void fanotify_free_mark(struct fsnotify_mark *fsn_mark)
{
kmem_cache_free(fanotify_mark_cache, fsn_mark);
}
static int fanotify_find_path(int dfd, const char __user *filename,
struct path *path, unsigned int flags)
{
int ret;
pr_debug("%s: dfd=%d filename=%p flags=%x\n", __func__,
dfd, filename, flags);
if (filename == NULL) {
struct file *file;
int fput_needed;
ret = -EBADF;
file = fget_light(dfd, &fput_needed);
if (!file)
goto out;
ret = -ENOTDIR;
if ((flags & FAN_MARK_ONLYDIR) &&
!(S_ISDIR(file->f_path.dentry->d_inode->i_mode))) {
fput_light(file, fput_needed);
goto out;
}
*path = file->f_path;
path_get(path);
fput_light(file, fput_needed);
} else {
unsigned int lookup_flags = 0;
if (!(flags & FAN_MARK_DONT_FOLLOW))
lookup_flags |= LOOKUP_FOLLOW;
if (flags & FAN_MARK_ONLYDIR)
lookup_flags |= LOOKUP_DIRECTORY;
ret = user_path_at(dfd, filename, lookup_flags, path);
if (ret)
goto out;
}
ret = inode_permission(path->dentry->d_inode, MAY_READ);
if (ret)
path_put(path);
out:
return ret;
}
static __u32 fanotify_mark_remove_from_mask(struct fsnotify_mark *fsn_mark,
__u32 mask,
unsigned int flags)
{
__u32 oldmask;
spin_lock(&fsn_mark->lock);
if (!(flags & FAN_MARK_IGNORED_MASK)) {
oldmask = fsn_mark->mask;
fsnotify_set_mark_mask_locked(fsn_mark, (oldmask & ~mask));
} else {
oldmask = fsn_mark->ignored_mask;
fsnotify_set_mark_ignored_mask_locked(fsn_mark, (oldmask & ~mask));
}
spin_unlock(&fsn_mark->lock);
if (!(oldmask & ~mask))
fsnotify_destroy_mark(fsn_mark);
return mask & oldmask;
}
static int fanotify_remove_vfsmount_mark(struct fsnotify_group *group,
struct vfsmount *mnt, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark = NULL;
__u32 removed;
fsn_mark = fsnotify_find_vfsmount_mark(group, mnt);
if (!fsn_mark)
return -ENOENT;
removed = fanotify_mark_remove_from_mask(fsn_mark, mask, flags);
fsnotify_put_mark(fsn_mark);
if (removed & real_mount(mnt)->mnt_fsnotify_mask)
fsnotify_recalc_vfsmount_mask(mnt);
return 0;
}
static int fanotify_remove_inode_mark(struct fsnotify_group *group,
struct inode *inode, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark = NULL;
__u32 removed;
fsn_mark = fsnotify_find_inode_mark(group, inode);
if (!fsn_mark)
return -ENOENT;
removed = fanotify_mark_remove_from_mask(fsn_mark, mask, flags);
fsnotify_put_mark(fsn_mark);
if (removed & inode->i_fsnotify_mask)
fsnotify_recalc_inode_mask(inode);
return 0;
}
static __u32 fanotify_mark_add_to_mask(struct fsnotify_mark *fsn_mark,
__u32 mask,
unsigned int flags)
{
__u32 oldmask = -1;
spin_lock(&fsn_mark->lock);
if (!(flags & FAN_MARK_IGNORED_MASK)) {
oldmask = fsn_mark->mask;
fsnotify_set_mark_mask_locked(fsn_mark, (oldmask | mask));
} else {
__u32 tmask = fsn_mark->ignored_mask | mask;
fsnotify_set_mark_ignored_mask_locked(fsn_mark, tmask);
if (flags & FAN_MARK_IGNORED_SURV_MODIFY)
fsn_mark->flags |= FSNOTIFY_MARK_FLAG_IGNORED_SURV_MODIFY;
}
if (!(flags & FAN_MARK_ONDIR)) {
__u32 tmask = fsn_mark->ignored_mask | FAN_ONDIR;
fsnotify_set_mark_ignored_mask_locked(fsn_mark, tmask);
}
spin_unlock(&fsn_mark->lock);
return mask & ~oldmask;
}
static int fanotify_add_vfsmount_mark(struct fsnotify_group *group,
struct vfsmount *mnt, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark;
__u32 added;
int ret = 0;
fsn_mark = fsnotify_find_vfsmount_mark(group, mnt);
if (!fsn_mark) {
if (atomic_read(&group->num_marks) > group->fanotify_data.max_marks)
return -ENOSPC;
fsn_mark = kmem_cache_alloc(fanotify_mark_cache, GFP_KERNEL);
if (!fsn_mark)
return -ENOMEM;
fsnotify_init_mark(fsn_mark, fanotify_free_mark);
ret = fsnotify_add_mark(fsn_mark, group, NULL, mnt, 0);
if (ret)
goto err;
}
added = fanotify_mark_add_to_mask(fsn_mark, mask, flags);
if (added & ~real_mount(mnt)->mnt_fsnotify_mask)
fsnotify_recalc_vfsmount_mask(mnt);
err:
fsnotify_put_mark(fsn_mark);
return ret;
}
static int fanotify_add_inode_mark(struct fsnotify_group *group,
struct inode *inode, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark;
__u32 added;
int ret = 0;
pr_debug("%s: group=%p inode=%p\n", __func__, group, inode);
if ((flags & FAN_MARK_IGNORED_MASK) &&
!(flags & FAN_MARK_IGNORED_SURV_MODIFY) &&
(atomic_read(&inode->i_writecount) > 0))
return 0;
fsn_mark = fsnotify_find_inode_mark(group, inode);
if (!fsn_mark) {
if (atomic_read(&group->num_marks) > group->fanotify_data.max_marks)
return -ENOSPC;
fsn_mark = kmem_cache_alloc(fanotify_mark_cache, GFP_KERNEL);
if (!fsn_mark)
return -ENOMEM;
fsnotify_init_mark(fsn_mark, fanotify_free_mark);
ret = fsnotify_add_mark(fsn_mark, group, inode, NULL, 0);
if (ret)
goto err;
}
added = fanotify_mark_add_to_mask(fsn_mark, mask, flags);
if (added & ~inode->i_fsnotify_mask)
fsnotify_recalc_inode_mask(inode);
err:
fsnotify_put_mark(fsn_mark);
return ret;
}
SYSCALL_DEFINE(fanotify_mark)(int fanotify_fd, unsigned int flags,
__u64 mask, int dfd,
const char __user * pathname)
{
struct inode *inode = NULL;
struct vfsmount *mnt = NULL;
struct fsnotify_group *group;
struct file *filp;
struct path path;
int ret, fput_needed;
pr_debug("%s: fanotify_fd=%d flags=%x dfd=%d pathname=%p mask=%llx\n",
__func__, fanotify_fd, flags, dfd, pathname, mask);
if (mask & ((__u64)0xffffffff << 32))
return -EINVAL;
if (flags & ~FAN_ALL_MARK_FLAGS)
return -EINVAL;
switch (flags & (FAN_MARK_ADD | FAN_MARK_REMOVE | FAN_MARK_FLUSH)) {
case FAN_MARK_ADD:
case FAN_MARK_REMOVE:
if (!mask)
return -EINVAL;
case FAN_MARK_FLUSH:
break;
default:
return -EINVAL;
}
if (mask & FAN_ONDIR) {
flags |= FAN_MARK_ONDIR;
mask &= ~FAN_ONDIR;
}
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (mask & ~(FAN_ALL_EVENTS | FAN_ALL_PERM_EVENTS | FAN_EVENT_ON_CHILD))
#else
if (mask & ~(FAN_ALL_EVENTS | FAN_EVENT_ON_CHILD))
#endif
return -EINVAL;
filp = fget_light(fanotify_fd, &fput_needed);
if (unlikely(!filp))
return -EBADF;
ret = -EINVAL;
if (unlikely(filp->f_op != &fanotify_fops))
goto fput_and_out;
group = filp->private_data;
ret = -EINVAL;
if (mask & FAN_ALL_PERM_EVENTS &&
group->priority == FS_PRIO_0)
goto fput_and_out;
ret = fanotify_find_path(dfd, pathname, &path, flags);
if (ret)
goto fput_and_out;
if (!(flags & FAN_MARK_MOUNT))
inode = path.dentry->d_inode;
else
mnt = path.mnt;
switch (flags & (FAN_MARK_ADD | FAN_MARK_REMOVE | FAN_MARK_FLUSH)) {
case FAN_MARK_ADD:
if (flags & FAN_MARK_MOUNT)
ret = fanotify_add_vfsmount_mark(group, mnt, mask, flags);
else
ret = fanotify_add_inode_mark(group, inode, mask, flags);
break;
case FAN_MARK_REMOVE:
if (flags & FAN_MARK_MOUNT)
ret = fanotify_remove_vfsmount_mark(group, mnt, mask, flags);
else
ret = fanotify_remove_inode_mark(group, inode, mask, flags);
break;
case FAN_MARK_FLUSH:
if (flags & FAN_MARK_MOUNT)
fsnotify_clear_vfsmount_marks_by_group(group);
else
fsnotify_clear_inode_marks_by_group(group);
break;
default:
ret = -EINVAL;
}
path_put(&path);
fput_and_out:
fput_light(filp, fput_needed);
return ret;
}
asmlinkage long SyS_fanotify_mark(long fanotify_fd, long flags, __u64 mask,
long dfd, long pathname)
{
return SYSC_fanotify_mark((int) fanotify_fd, (unsigned int) flags,
mask, (int) dfd,
(const char __user *) pathname);
}
static int __init fanotify_user_setup(void)
{
fanotify_mark_cache = KMEM_CACHE(fsnotify_mark, SLAB_PANIC);
fanotify_response_event_cache = KMEM_CACHE(fanotify_response_event,
SLAB_PANIC);
return 0;
}
