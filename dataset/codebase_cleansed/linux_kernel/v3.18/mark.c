void fsnotify_get_mark(struct fsnotify_mark *mark)
{
atomic_inc(&mark->refcnt);
}
void fsnotify_put_mark(struct fsnotify_mark *mark)
{
if (atomic_dec_and_test(&mark->refcnt)) {
if (mark->group)
fsnotify_put_group(mark->group);
mark->free_mark(mark);
}
}
void fsnotify_destroy_mark_locked(struct fsnotify_mark *mark,
struct fsnotify_group *group)
{
struct inode *inode = NULL;
BUG_ON(!mutex_is_locked(&group->mark_mutex));
spin_lock(&mark->lock);
if (!(mark->flags & FSNOTIFY_MARK_FLAG_ALIVE)) {
spin_unlock(&mark->lock);
return;
}
mark->flags &= ~FSNOTIFY_MARK_FLAG_ALIVE;
if (mark->flags & FSNOTIFY_MARK_FLAG_INODE) {
inode = mark->i.inode;
fsnotify_destroy_inode_mark(mark);
} else if (mark->flags & FSNOTIFY_MARK_FLAG_VFSMOUNT)
fsnotify_destroy_vfsmount_mark(mark);
else
BUG();
list_del_init(&mark->g_list);
spin_unlock(&mark->lock);
if (inode && (mark->flags & FSNOTIFY_MARK_FLAG_OBJECT_PINNED))
iput(inode);
mutex_unlock(&group->mark_mutex);
spin_lock(&destroy_lock);
list_add(&mark->destroy_list, &destroy_list);
spin_unlock(&destroy_lock);
wake_up(&destroy_waitq);
if (group->ops->freeing_mark)
group->ops->freeing_mark(mark, group);
atomic_dec(&group->num_marks);
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
}
void fsnotify_destroy_mark(struct fsnotify_mark *mark,
struct fsnotify_group *group)
{
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
fsnotify_destroy_mark_locked(mark, group);
mutex_unlock(&group->mark_mutex);
}
void fsnotify_set_mark_mask_locked(struct fsnotify_mark *mark, __u32 mask)
{
assert_spin_locked(&mark->lock);
mark->mask = mask;
if (mark->flags & FSNOTIFY_MARK_FLAG_INODE)
fsnotify_set_inode_mark_mask_locked(mark, mask);
}
void fsnotify_set_mark_ignored_mask_locked(struct fsnotify_mark *mark, __u32 mask)
{
assert_spin_locked(&mark->lock);
mark->ignored_mask = mask;
}
int fsnotify_compare_groups(struct fsnotify_group *a, struct fsnotify_group *b)
{
if (a == b)
return 0;
if (!a)
return 1;
if (!b)
return -1;
if (a->priority < b->priority)
return 1;
if (a->priority > b->priority)
return -1;
if (a < b)
return 1;
return -1;
}
int fsnotify_add_mark_locked(struct fsnotify_mark *mark,
struct fsnotify_group *group, struct inode *inode,
struct vfsmount *mnt, int allow_dups)
{
int ret = 0;
BUG_ON(inode && mnt);
BUG_ON(!inode && !mnt);
BUG_ON(!mutex_is_locked(&group->mark_mutex));
spin_lock(&mark->lock);
mark->flags |= FSNOTIFY_MARK_FLAG_ALIVE;
fsnotify_get_group(group);
mark->group = group;
list_add(&mark->g_list, &group->marks_list);
atomic_inc(&group->num_marks);
fsnotify_get_mark(mark);
if (inode) {
ret = fsnotify_add_inode_mark(mark, group, inode, allow_dups);
if (ret)
goto err;
} else if (mnt) {
ret = fsnotify_add_vfsmount_mark(mark, group, mnt, allow_dups);
if (ret)
goto err;
} else {
BUG();
}
fsnotify_set_mark_mask_locked(mark, mark->mask);
spin_unlock(&mark->lock);
if (inode)
__fsnotify_update_child_dentry_flags(inode);
return ret;
err:
mark->flags &= ~FSNOTIFY_MARK_FLAG_ALIVE;
list_del_init(&mark->g_list);
fsnotify_put_group(group);
mark->group = NULL;
atomic_dec(&group->num_marks);
spin_unlock(&mark->lock);
spin_lock(&destroy_lock);
list_add(&mark->destroy_list, &destroy_list);
spin_unlock(&destroy_lock);
wake_up(&destroy_waitq);
return ret;
}
int fsnotify_add_mark(struct fsnotify_mark *mark, struct fsnotify_group *group,
struct inode *inode, struct vfsmount *mnt, int allow_dups)
{
int ret;
mutex_lock(&group->mark_mutex);
ret = fsnotify_add_mark_locked(mark, group, inode, mnt, allow_dups);
mutex_unlock(&group->mark_mutex);
return ret;
}
void fsnotify_clear_marks_by_group_flags(struct fsnotify_group *group,
unsigned int flags)
{
struct fsnotify_mark *lmark, *mark;
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
list_for_each_entry_safe(mark, lmark, &group->marks_list, g_list) {
if (mark->flags & flags) {
fsnotify_get_mark(mark);
fsnotify_destroy_mark_locked(mark, group);
fsnotify_put_mark(mark);
}
}
mutex_unlock(&group->mark_mutex);
}
void fsnotify_clear_marks_by_group(struct fsnotify_group *group)
{
fsnotify_clear_marks_by_group_flags(group, (unsigned int)-1);
}
void fsnotify_duplicate_mark(struct fsnotify_mark *new, struct fsnotify_mark *old)
{
assert_spin_locked(&old->lock);
new->i.inode = old->i.inode;
new->m.mnt = old->m.mnt;
if (old->group)
fsnotify_get_group(old->group);
new->group = old->group;
new->mask = old->mask;
new->free_mark = old->free_mark;
}
void fsnotify_init_mark(struct fsnotify_mark *mark,
void (*free_mark)(struct fsnotify_mark *mark))
{
memset(mark, 0, sizeof(*mark));
spin_lock_init(&mark->lock);
atomic_set(&mark->refcnt, 1);
mark->free_mark = free_mark;
}
static int fsnotify_mark_destroy(void *ignored)
{
struct fsnotify_mark *mark, *next;
struct list_head private_destroy_list;
for (;;) {
spin_lock(&destroy_lock);
list_replace_init(&destroy_list, &private_destroy_list);
spin_unlock(&destroy_lock);
synchronize_srcu(&fsnotify_mark_srcu);
list_for_each_entry_safe(mark, next, &private_destroy_list, destroy_list) {
list_del_init(&mark->destroy_list);
fsnotify_put_mark(mark);
}
wait_event_interruptible(destroy_waitq, !list_empty(&destroy_list));
}
return 0;
}
static int __init fsnotify_mark_init(void)
{
struct task_struct *thread;
thread = kthread_run(fsnotify_mark_destroy, NULL,
"fsnotify_mark");
if (IS_ERR(thread))
panic("unable to start fsnotify mark destruction thread.");
return 0;
}
