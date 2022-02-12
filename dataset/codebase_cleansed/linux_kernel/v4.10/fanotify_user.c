static struct fsnotify_event *get_one_event(struct fsnotify_group *group,
size_t count)
{
assert_spin_locked(&group->notification_lock);
pr_debug("%s: group=%p count=%zd\n", __func__, group, count);
if (fsnotify_notify_queue_is_empty(group))
return NULL;
if (FAN_EVENT_METADATA_LEN > count)
return ERR_PTR(-EINVAL);
return fsnotify_remove_first_event(group);
}
static int create_fd(struct fsnotify_group *group,
struct fanotify_event_info *event,
struct file **file)
{
int client_fd;
struct file *new_file;
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
client_fd = get_unused_fd_flags(group->fanotify_data.f_flags);
if (client_fd < 0)
return client_fd;
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
*file = new_file;
}
return client_fd;
}
static int fill_event_metadata(struct fsnotify_group *group,
struct fanotify_event_metadata *metadata,
struct fsnotify_event *fsn_event,
struct file **file)
{
int ret = 0;
struct fanotify_event_info *event;
pr_debug("%s: group=%p metadata=%p event=%p\n", __func__,
group, metadata, fsn_event);
*file = NULL;
event = container_of(fsn_event, struct fanotify_event_info, fse);
metadata->event_len = FAN_EVENT_METADATA_LEN;
metadata->metadata_len = FAN_EVENT_METADATA_LEN;
metadata->vers = FANOTIFY_METADATA_VERSION;
metadata->reserved = 0;
metadata->mask = fsn_event->mask & FAN_ALL_OUTGOING_EVENTS;
metadata->pid = pid_vnr(event->tgid);
if (unlikely(fsn_event->mask & FAN_Q_OVERFLOW))
metadata->fd = FAN_NOFD;
else {
metadata->fd = create_fd(group, event, file);
if (metadata->fd < 0)
ret = metadata->fd;
}
return ret;
}
static struct fanotify_perm_event_info *dequeue_event(
struct fsnotify_group *group, int fd)
{
struct fanotify_perm_event_info *event, *return_e = NULL;
spin_lock(&group->notification_lock);
list_for_each_entry(event, &group->fanotify_data.access_list,
fae.fse.list) {
if (event->fd != fd)
continue;
list_del_init(&event->fae.fse.list);
return_e = event;
break;
}
spin_unlock(&group->notification_lock);
pr_debug("%s: found return_re=%p\n", __func__, return_e);
return return_e;
}
static int process_access_response(struct fsnotify_group *group,
struct fanotify_response *response_struct)
{
struct fanotify_perm_event_info *event;
int fd = response_struct->fd;
int response = response_struct->response;
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
event = dequeue_event(group, fd);
if (!event)
return -ENOENT;
event->response = response;
wake_up(&group->fanotify_data.access_waitq);
return 0;
}
static ssize_t copy_event_to_user(struct fsnotify_group *group,
struct fsnotify_event *event,
char __user *buf)
{
struct fanotify_event_metadata fanotify_event_metadata;
struct file *f;
int fd, ret;
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
ret = fill_event_metadata(group, &fanotify_event_metadata, event, &f);
if (ret < 0)
return ret;
fd = fanotify_event_metadata.fd;
ret = -EFAULT;
if (copy_to_user(buf, &fanotify_event_metadata,
fanotify_event_metadata.event_len))
goto out_close_fd;
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (event->mask & FAN_ALL_PERM_EVENTS)
FANOTIFY_PE(event)->fd = fd;
#endif
if (fd != FAN_NOFD)
fd_install(fd, f);
return fanotify_event_metadata.event_len;
out_close_fd:
if (fd != FAN_NOFD) {
put_unused_fd(fd);
fput(f);
}
return ret;
}
static unsigned int fanotify_poll(struct file *file, poll_table *wait)
{
struct fsnotify_group *group = file->private_data;
int ret = 0;
poll_wait(file, &group->notification_waitq, wait);
spin_lock(&group->notification_lock);
if (!fsnotify_notify_queue_is_empty(group))
ret = POLLIN | POLLRDNORM;
spin_unlock(&group->notification_lock);
return ret;
}
static ssize_t fanotify_read(struct file *file, char __user *buf,
size_t count, loff_t *pos)
{
struct fsnotify_group *group;
struct fsnotify_event *kevent;
char __user *start;
int ret;
DEFINE_WAIT_FUNC(wait, woken_wake_function);
start = buf;
group = file->private_data;
pr_debug("%s: group=%p\n", __func__, group);
add_wait_queue(&group->notification_waitq, &wait);
while (1) {
spin_lock(&group->notification_lock);
kevent = get_one_event(group, count);
spin_unlock(&group->notification_lock);
if (IS_ERR(kevent)) {
ret = PTR_ERR(kevent);
break;
}
if (!kevent) {
ret = -EAGAIN;
if (file->f_flags & O_NONBLOCK)
break;
ret = -ERESTARTSYS;
if (signal_pending(current))
break;
if (start != buf)
break;
wait_woken(&wait, TASK_INTERRUPTIBLE, MAX_SCHEDULE_TIMEOUT);
continue;
}
ret = copy_event_to_user(group, kevent, buf);
if (!(kevent->mask & FAN_ALL_PERM_EVENTS)) {
fsnotify_destroy_event(group, kevent);
if (ret < 0)
break;
} else {
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (ret < 0) {
FANOTIFY_PE(kevent)->response = FAN_DENY;
wake_up(&group->fanotify_data.access_waitq);
break;
}
spin_lock(&group->notification_lock);
list_add_tail(&kevent->list,
&group->fanotify_data.access_list);
spin_unlock(&group->notification_lock);
#endif
}
buf += ret;
count -= ret;
}
remove_wait_queue(&group->notification_waitq, &wait);
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
struct fanotify_perm_event_info *event, *next;
struct fsnotify_event *fsn_event;
fsnotify_group_stop_queueing(group);
spin_lock(&group->notification_lock);
list_for_each_entry_safe(event, next, &group->fanotify_data.access_list,
fae.fse.list) {
pr_debug("%s: found group=%p event=%p\n", __func__, group,
event);
list_del_init(&event->fae.fse.list);
event->response = FAN_ALLOW;
}
while (!fsnotify_notify_queue_is_empty(group)) {
fsn_event = fsnotify_remove_first_event(group);
if (!(fsn_event->mask & FAN_ALL_PERM_EVENTS)) {
spin_unlock(&group->notification_lock);
fsnotify_destroy_event(group, fsn_event);
spin_lock(&group->notification_lock);
} else
FANOTIFY_PE(fsn_event)->response = FAN_ALLOW;
}
spin_unlock(&group->notification_lock);
wake_up(&group->fanotify_data.access_waitq);
#endif
fsnotify_destroy_group(group);
return 0;
}
static long fanotify_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct fsnotify_group *group;
struct fsnotify_event *fsn_event;
void __user *p;
int ret = -ENOTTY;
size_t send_len = 0;
group = file->private_data;
p = (void __user *) arg;
switch (cmd) {
case FIONREAD:
spin_lock(&group->notification_lock);
list_for_each_entry(fsn_event, &group->notification_list, list)
send_len += FAN_EVENT_METADATA_LEN;
spin_unlock(&group->notification_lock);
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
struct fd f = fdget(dfd);
ret = -EBADF;
if (!f.file)
goto out;
ret = -ENOTDIR;
if ((flags & FAN_MARK_ONLYDIR) &&
!(S_ISDIR(file_inode(f.file)->i_mode))) {
fdput(f);
goto out;
}
*path = f.file->f_path;
path_get(path);
fdput(f);
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
unsigned int flags,
int *destroy)
{
__u32 oldmask = 0;
spin_lock(&fsn_mark->lock);
if (!(flags & FAN_MARK_IGNORED_MASK)) {
__u32 tmask = fsn_mark->mask & ~mask;
if (flags & FAN_MARK_ONDIR)
tmask &= ~FAN_ONDIR;
oldmask = fsn_mark->mask;
fsnotify_set_mark_mask_locked(fsn_mark, tmask);
} else {
__u32 tmask = fsn_mark->ignored_mask & ~mask;
if (flags & FAN_MARK_ONDIR)
tmask &= ~FAN_ONDIR;
fsnotify_set_mark_ignored_mask_locked(fsn_mark, tmask);
}
*destroy = !(fsn_mark->mask | fsn_mark->ignored_mask);
spin_unlock(&fsn_mark->lock);
return mask & oldmask;
}
static int fanotify_remove_vfsmount_mark(struct fsnotify_group *group,
struct vfsmount *mnt, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark = NULL;
__u32 removed;
int destroy_mark;
mutex_lock(&group->mark_mutex);
fsn_mark = fsnotify_find_vfsmount_mark(group, mnt);
if (!fsn_mark) {
mutex_unlock(&group->mark_mutex);
return -ENOENT;
}
removed = fanotify_mark_remove_from_mask(fsn_mark, mask, flags,
&destroy_mark);
if (destroy_mark)
fsnotify_detach_mark(fsn_mark);
mutex_unlock(&group->mark_mutex);
if (destroy_mark)
fsnotify_free_mark(fsn_mark);
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
int destroy_mark;
mutex_lock(&group->mark_mutex);
fsn_mark = fsnotify_find_inode_mark(group, inode);
if (!fsn_mark) {
mutex_unlock(&group->mark_mutex);
return -ENOENT;
}
removed = fanotify_mark_remove_from_mask(fsn_mark, mask, flags,
&destroy_mark);
if (destroy_mark)
fsnotify_detach_mark(fsn_mark);
mutex_unlock(&group->mark_mutex);
if (destroy_mark)
fsnotify_free_mark(fsn_mark);
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
__u32 tmask = fsn_mark->mask | mask;
if (flags & FAN_MARK_ONDIR)
tmask |= FAN_ONDIR;
oldmask = fsn_mark->mask;
fsnotify_set_mark_mask_locked(fsn_mark, tmask);
} else {
__u32 tmask = fsn_mark->ignored_mask | mask;
if (flags & FAN_MARK_ONDIR)
tmask |= FAN_ONDIR;
fsnotify_set_mark_ignored_mask_locked(fsn_mark, tmask);
if (flags & FAN_MARK_IGNORED_SURV_MODIFY)
fsn_mark->flags |= FSNOTIFY_MARK_FLAG_IGNORED_SURV_MODIFY;
}
spin_unlock(&fsn_mark->lock);
return mask & ~oldmask;
}
static struct fsnotify_mark *fanotify_add_new_mark(struct fsnotify_group *group,
struct inode *inode,
struct vfsmount *mnt)
{
struct fsnotify_mark *mark;
int ret;
if (atomic_read(&group->num_marks) > group->fanotify_data.max_marks)
return ERR_PTR(-ENOSPC);
mark = kmem_cache_alloc(fanotify_mark_cache, GFP_KERNEL);
if (!mark)
return ERR_PTR(-ENOMEM);
fsnotify_init_mark(mark, fanotify_free_mark);
ret = fsnotify_add_mark_locked(mark, group, inode, mnt, 0);
if (ret) {
fsnotify_put_mark(mark);
return ERR_PTR(ret);
}
return mark;
}
static int fanotify_add_vfsmount_mark(struct fsnotify_group *group,
struct vfsmount *mnt, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark;
__u32 added;
mutex_lock(&group->mark_mutex);
fsn_mark = fsnotify_find_vfsmount_mark(group, mnt);
if (!fsn_mark) {
fsn_mark = fanotify_add_new_mark(group, NULL, mnt);
if (IS_ERR(fsn_mark)) {
mutex_unlock(&group->mark_mutex);
return PTR_ERR(fsn_mark);
}
}
added = fanotify_mark_add_to_mask(fsn_mark, mask, flags);
mutex_unlock(&group->mark_mutex);
if (added & ~real_mount(mnt)->mnt_fsnotify_mask)
fsnotify_recalc_vfsmount_mask(mnt);
fsnotify_put_mark(fsn_mark);
return 0;
}
static int fanotify_add_inode_mark(struct fsnotify_group *group,
struct inode *inode, __u32 mask,
unsigned int flags)
{
struct fsnotify_mark *fsn_mark;
__u32 added;
pr_debug("%s: group=%p inode=%p\n", __func__, group, inode);
if ((flags & FAN_MARK_IGNORED_MASK) &&
!(flags & FAN_MARK_IGNORED_SURV_MODIFY) &&
(atomic_read(&inode->i_writecount) > 0))
return 0;
mutex_lock(&group->mark_mutex);
fsn_mark = fsnotify_find_inode_mark(group, inode);
if (!fsn_mark) {
fsn_mark = fanotify_add_new_mark(group, inode, NULL);
if (IS_ERR(fsn_mark)) {
mutex_unlock(&group->mark_mutex);
return PTR_ERR(fsn_mark);
}
}
added = fanotify_mark_add_to_mask(fsn_mark, mask, flags);
mutex_unlock(&group->mark_mutex);
if (added & ~inode->i_fsnotify_mask)
fsnotify_recalc_inode_mask(inode);
fsnotify_put_mark(fsn_mark);
return 0;
}
static int __init fanotify_user_setup(void)
{
fanotify_mark_cache = KMEM_CACHE(fsnotify_mark, SLAB_PANIC);
fanotify_event_cachep = KMEM_CACHE(fanotify_event_info, SLAB_PANIC);
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
fanotify_perm_event_cachep = KMEM_CACHE(fanotify_perm_event_info,
SLAB_PANIC);
#endif
return 0;
}
