static bool event_compare(struct fsnotify_event *old, struct fsnotify_event *new)
{
if ((old->mask == new->mask) &&
(old->to_tell == new->to_tell) &&
(old->data_type == new->data_type) &&
(old->name_len == new->name_len)) {
switch (old->data_type) {
case (FSNOTIFY_EVENT_INODE):
if (!old->name_len ||
!strcmp(old->file_name, new->file_name))
return true;
break;
case (FSNOTIFY_EVENT_PATH):
if ((old->path.mnt == new->path.mnt) &&
(old->path.dentry == new->path.dentry))
return true;
break;
case (FSNOTIFY_EVENT_NONE):
if (old->mask & FS_Q_OVERFLOW)
return true;
else if (old->mask & FS_IN_IGNORED)
return false;
return true;
};
}
return false;
}
static struct fsnotify_event *inotify_merge(struct list_head *list,
struct fsnotify_event *event)
{
struct fsnotify_event_holder *last_holder;
struct fsnotify_event *last_event;
spin_lock(&event->lock);
last_holder = list_entry(list->prev, struct fsnotify_event_holder, event_list);
last_event = last_holder->event;
if (event_compare(last_event, event))
fsnotify_get_event(last_event);
else
last_event = NULL;
spin_unlock(&event->lock);
return last_event;
}
static int inotify_handle_event(struct fsnotify_group *group,
struct fsnotify_mark *inode_mark,
struct fsnotify_mark *vfsmount_mark,
struct fsnotify_event *event)
{
struct inotify_inode_mark *i_mark;
struct inode *to_tell;
struct inotify_event_private_data *event_priv;
struct fsnotify_event_private_data *fsn_event_priv;
struct fsnotify_event *added_event;
int wd, ret = 0;
BUG_ON(vfsmount_mark);
pr_debug("%s: group=%p event=%p to_tell=%p mask=%x\n", __func__, group,
event, event->to_tell, event->mask);
to_tell = event->to_tell;
i_mark = container_of(inode_mark, struct inotify_inode_mark,
fsn_mark);
wd = i_mark->wd;
event_priv = kmem_cache_alloc(event_priv_cachep, GFP_KERNEL);
if (unlikely(!event_priv))
return -ENOMEM;
fsn_event_priv = &event_priv->fsnotify_event_priv_data;
fsnotify_get_group(group);
fsn_event_priv->group = group;
event_priv->wd = wd;
added_event = fsnotify_add_notify_event(group, event, fsn_event_priv, inotify_merge);
if (added_event) {
inotify_free_event_priv(fsn_event_priv);
if (!IS_ERR(added_event))
fsnotify_put_event(added_event);
else
ret = PTR_ERR(added_event);
}
if (inode_mark->mask & IN_ONESHOT)
fsnotify_destroy_mark(inode_mark, group);
return ret;
}
static void inotify_freeing_mark(struct fsnotify_mark *fsn_mark, struct fsnotify_group *group)
{
inotify_ignored_and_remove_idr(fsn_mark, group);
}
static bool inotify_should_send_event(struct fsnotify_group *group, struct inode *inode,
struct fsnotify_mark *inode_mark,
struct fsnotify_mark *vfsmount_mark,
__u32 mask, void *data, int data_type)
{
if ((inode_mark->mask & FS_EXCL_UNLINK) &&
(data_type == FSNOTIFY_EVENT_PATH)) {
struct path *path = data;
if (d_unlinked(path->dentry))
return false;
}
return true;
}
static int idr_callback(int id, void *p, void *data)
{
struct fsnotify_mark *fsn_mark;
struct inotify_inode_mark *i_mark;
static bool warned = false;
if (warned)
return 0;
warned = true;
fsn_mark = p;
i_mark = container_of(fsn_mark, struct inotify_inode_mark, fsn_mark);
WARN(1, "inotify closing but id=%d for fsn_mark=%p in group=%p still in "
"idr. Probably leaking memory\n", id, p, data);
if (fsn_mark)
printk(KERN_WARNING "fsn_mark->group=%p inode=%p wd=%d\n",
fsn_mark->group, fsn_mark->i.inode, i_mark->wd);
return 0;
}
static void inotify_free_group_priv(struct fsnotify_group *group)
{
idr_for_each(&group->inotify_data.idr, idr_callback, group);
idr_remove_all(&group->inotify_data.idr);
idr_destroy(&group->inotify_data.idr);
atomic_dec(&group->inotify_data.user->inotify_devs);
free_uid(group->inotify_data.user);
}
void inotify_free_event_priv(struct fsnotify_event_private_data *fsn_event_priv)
{
struct inotify_event_private_data *event_priv;
event_priv = container_of(fsn_event_priv, struct inotify_event_private_data,
fsnotify_event_priv_data);
fsnotify_put_group(fsn_event_priv->group);
kmem_cache_free(event_priv_cachep, event_priv);
}
