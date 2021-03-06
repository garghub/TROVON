static bool should_merge(struct fsnotify_event *old_fsn,
struct fsnotify_event *new_fsn)
{
struct fanotify_event_info *old, *new;
pr_debug("%s: old=%p new=%p\n", __func__, old_fsn, new_fsn);
old = FANOTIFY_E(old_fsn);
new = FANOTIFY_E(new_fsn);
if (old_fsn->inode == new_fsn->inode && old->tgid == new->tgid &&
old->path.mnt == new->path.mnt &&
old->path.dentry == new->path.dentry)
return true;
return false;
}
static int fanotify_merge(struct list_head *list, struct fsnotify_event *event)
{
struct fsnotify_event *test_event;
bool do_merge = false;
pr_debug("%s: list=%p event=%p\n", __func__, list, event);
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (event->mask & FAN_ALL_PERM_EVENTS)
return 0;
#endif
list_for_each_entry_reverse(test_event, list, list) {
if (should_merge(test_event, event)) {
do_merge = true;
break;
}
}
if (!do_merge)
return 0;
test_event->mask |= event->mask;
return 1;
}
static int fanotify_get_response(struct fsnotify_group *group,
struct fanotify_perm_event_info *event)
{
int ret;
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
wait_event(group->fanotify_data.access_waitq, event->response ||
atomic_read(&group->fanotify_data.bypass_perm));
if (!event->response) {
fsnotify_remove_event(group, &event->fae.fse);
return 0;
}
switch (event->response) {
case FAN_ALLOW:
ret = 0;
break;
case FAN_DENY:
default:
ret = -EPERM;
}
event->response = 0;
pr_debug("%s: group=%p event=%p about to return ret=%d\n", __func__,
group, event, ret);
return ret;
}
static bool fanotify_should_send_event(struct fsnotify_mark *inode_mark,
struct fsnotify_mark *vfsmnt_mark,
u32 event_mask,
void *data, int data_type)
{
__u32 marks_mask, marks_ignored_mask;
struct path *path = data;
pr_debug("%s: inode_mark=%p vfsmnt_mark=%p mask=%x data=%p"
" data_type=%d\n", __func__, inode_mark, vfsmnt_mark,
event_mask, data, data_type);
if (data_type != FSNOTIFY_EVENT_PATH)
return false;
if (!S_ISREG(path->dentry->d_inode->i_mode) &&
!S_ISDIR(path->dentry->d_inode->i_mode))
return false;
if (inode_mark && vfsmnt_mark) {
marks_mask = (vfsmnt_mark->mask | inode_mark->mask);
marks_ignored_mask = (vfsmnt_mark->ignored_mask | inode_mark->ignored_mask);
} else if (inode_mark) {
if ((event_mask & FS_EVENT_ON_CHILD) &&
!(inode_mark->mask & FS_EVENT_ON_CHILD))
return false;
marks_mask = inode_mark->mask;
marks_ignored_mask = inode_mark->ignored_mask;
} else if (vfsmnt_mark) {
marks_mask = vfsmnt_mark->mask;
marks_ignored_mask = vfsmnt_mark->ignored_mask;
} else {
BUG();
}
if (S_ISDIR(path->dentry->d_inode->i_mode) &&
(marks_ignored_mask & FS_ISDIR))
return false;
if (event_mask & marks_mask & ~marks_ignored_mask)
return true;
return false;
}
struct fanotify_event_info *fanotify_alloc_event(struct inode *inode, u32 mask,
struct path *path)
{
struct fanotify_event_info *event;
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (mask & FAN_ALL_PERM_EVENTS) {
struct fanotify_perm_event_info *pevent;
pevent = kmem_cache_alloc(fanotify_perm_event_cachep,
GFP_KERNEL);
if (!pevent)
return NULL;
event = &pevent->fae;
pevent->response = 0;
goto init;
}
#endif
event = kmem_cache_alloc(fanotify_event_cachep, GFP_KERNEL);
if (!event)
return NULL;
init: __maybe_unused
fsnotify_init_event(&event->fse, inode, mask);
event->tgid = get_pid(task_tgid(current));
if (path) {
event->path = *path;
path_get(&event->path);
} else {
event->path.mnt = NULL;
event->path.dentry = NULL;
}
return event;
}
static int fanotify_handle_event(struct fsnotify_group *group,
struct inode *inode,
struct fsnotify_mark *inode_mark,
struct fsnotify_mark *fanotify_mark,
u32 mask, void *data, int data_type,
const unsigned char *file_name, u32 cookie)
{
int ret = 0;
struct fanotify_event_info *event;
struct fsnotify_event *fsn_event;
BUILD_BUG_ON(FAN_ACCESS != FS_ACCESS);
BUILD_BUG_ON(FAN_MODIFY != FS_MODIFY);
BUILD_BUG_ON(FAN_CLOSE_NOWRITE != FS_CLOSE_NOWRITE);
BUILD_BUG_ON(FAN_CLOSE_WRITE != FS_CLOSE_WRITE);
BUILD_BUG_ON(FAN_OPEN != FS_OPEN);
BUILD_BUG_ON(FAN_EVENT_ON_CHILD != FS_EVENT_ON_CHILD);
BUILD_BUG_ON(FAN_Q_OVERFLOW != FS_Q_OVERFLOW);
BUILD_BUG_ON(FAN_OPEN_PERM != FS_OPEN_PERM);
BUILD_BUG_ON(FAN_ACCESS_PERM != FS_ACCESS_PERM);
BUILD_BUG_ON(FAN_ONDIR != FS_ISDIR);
if (!fanotify_should_send_event(inode_mark, fanotify_mark, mask, data,
data_type))
return 0;
pr_debug("%s: group=%p inode=%p mask=%x\n", __func__, group, inode,
mask);
event = fanotify_alloc_event(inode, mask, data);
if (unlikely(!event))
return -ENOMEM;
fsn_event = &event->fse;
ret = fsnotify_add_event(group, fsn_event, fanotify_merge);
if (ret) {
BUG_ON(ret == 1 && mask & FAN_ALL_PERM_EVENTS);
fsnotify_destroy_event(group, fsn_event);
return 0;
}
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (mask & FAN_ALL_PERM_EVENTS) {
ret = fanotify_get_response(group, FANOTIFY_PE(fsn_event));
fsnotify_destroy_event(group, fsn_event);
}
#endif
return ret;
}
static void fanotify_free_group_priv(struct fsnotify_group *group)
{
struct user_struct *user;
user = group->fanotify_data.user;
atomic_dec(&user->fanotify_listeners);
free_uid(user);
}
static void fanotify_free_event(struct fsnotify_event *fsn_event)
{
struct fanotify_event_info *event;
event = FANOTIFY_E(fsn_event);
path_put(&event->path);
put_pid(event->tgid);
#ifdef CONFIG_FANOTIFY_ACCESS_PERMISSIONS
if (fsn_event->mask & FAN_ALL_PERM_EVENTS) {
kmem_cache_free(fanotify_perm_event_cachep,
FANOTIFY_PE(fsn_event));
return;
}
#endif
kmem_cache_free(fanotify_event_cachep, event);
}
