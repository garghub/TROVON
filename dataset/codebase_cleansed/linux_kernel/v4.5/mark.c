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
u32 fsnotify_recalc_mask(struct hlist_head *head)
{
u32 new_mask = 0;
struct fsnotify_mark *mark;
hlist_for_each_entry(mark, head, obj_list)
new_mask |= mark->mask;
return new_mask;
}
void fsnotify_detach_mark(struct fsnotify_mark *mark)
{
struct inode *inode = NULL;
struct fsnotify_group *group = mark->group;
BUG_ON(!mutex_is_locked(&group->mark_mutex));
spin_lock(&mark->lock);
if (!(mark->flags & FSNOTIFY_MARK_FLAG_ATTACHED)) {
spin_unlock(&mark->lock);
return;
}
mark->flags &= ~FSNOTIFY_MARK_FLAG_ATTACHED;
if (mark->flags & FSNOTIFY_MARK_FLAG_INODE) {
inode = mark->inode;
fsnotify_destroy_inode_mark(mark);
} else if (mark->flags & FSNOTIFY_MARK_FLAG_VFSMOUNT)
fsnotify_destroy_vfsmount_mark(mark);
else
BUG();
list_del_init(&mark->g_list);
spin_unlock(&mark->lock);
if (inode && (mark->flags & FSNOTIFY_MARK_FLAG_OBJECT_PINNED))
iput(inode);
atomic_dec(&group->num_marks);
}
void fsnotify_free_mark(struct fsnotify_mark *mark)
{
struct fsnotify_group *group = mark->group;
spin_lock(&mark->lock);
if (!(mark->flags & FSNOTIFY_MARK_FLAG_ALIVE)) {
spin_unlock(&mark->lock);
return;
}
mark->flags &= ~FSNOTIFY_MARK_FLAG_ALIVE;
spin_unlock(&mark->lock);
spin_lock(&destroy_lock);
list_add(&mark->g_list, &destroy_list);
spin_unlock(&destroy_lock);
queue_delayed_work(system_unbound_wq, &reaper_work,
FSNOTIFY_REAPER_DELAY);
if (group->ops->freeing_mark)
group->ops->freeing_mark(mark, group);
}
void fsnotify_destroy_mark(struct fsnotify_mark *mark,
struct fsnotify_group *group)
{
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
fsnotify_detach_mark(mark);
mutex_unlock(&group->mark_mutex);
fsnotify_free_mark(mark);
}
void fsnotify_destroy_marks(struct hlist_head *head, spinlock_t *lock)
{
struct fsnotify_mark *mark;
while (1) {
spin_lock(lock);
if (hlist_empty(head)) {
spin_unlock(lock);
break;
}
mark = hlist_entry(head->first, struct fsnotify_mark, obj_list);
hlist_del_init_rcu(&mark->obj_list);
fsnotify_get_mark(mark);
spin_unlock(lock);
fsnotify_destroy_mark(mark, mark->group);
fsnotify_put_mark(mark);
}
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
int fsnotify_add_mark_list(struct hlist_head *head, struct fsnotify_mark *mark,
int allow_dups)
{
struct fsnotify_mark *lmark, *last = NULL;
int cmp;
if (hlist_empty(head)) {
hlist_add_head_rcu(&mark->obj_list, head);
return 0;
}
hlist_for_each_entry(lmark, head, obj_list) {
last = lmark;
if ((lmark->group == mark->group) && !allow_dups)
return -EEXIST;
cmp = fsnotify_compare_groups(lmark->group, mark->group);
if (cmp >= 0) {
hlist_add_before_rcu(&mark->obj_list, &lmark->obj_list);
return 0;
}
}
BUG_ON(last == NULL);
hlist_add_behind_rcu(&mark->obj_list, &last->obj_list);
return 0;
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
mark->flags |= FSNOTIFY_MARK_FLAG_ALIVE | FSNOTIFY_MARK_FLAG_ATTACHED;
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
list_add(&mark->g_list, &destroy_list);
spin_unlock(&destroy_lock);
queue_delayed_work(system_unbound_wq, &reaper_work,
FSNOTIFY_REAPER_DELAY);
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
struct fsnotify_mark *fsnotify_find_mark(struct hlist_head *head,
struct fsnotify_group *group)
{
struct fsnotify_mark *mark;
hlist_for_each_entry(mark, head, obj_list) {
if (mark->group == group) {
fsnotify_get_mark(mark);
return mark;
}
}
return NULL;
}
void fsnotify_clear_marks_by_group_flags(struct fsnotify_group *group,
unsigned int flags)
{
struct fsnotify_mark *lmark, *mark;
LIST_HEAD(to_free);
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
list_for_each_entry_safe(mark, lmark, &group->marks_list, g_list) {
if (mark->flags & flags)
list_move(&mark->g_list, &to_free);
}
mutex_unlock(&group->mark_mutex);
while (1) {
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
if (list_empty(&to_free)) {
mutex_unlock(&group->mark_mutex);
break;
}
mark = list_first_entry(&to_free, struct fsnotify_mark, g_list);
fsnotify_get_mark(mark);
fsnotify_detach_mark(mark);
mutex_unlock(&group->mark_mutex);
fsnotify_free_mark(mark);
fsnotify_put_mark(mark);
}
}
void fsnotify_clear_marks_by_group(struct fsnotify_group *group)
{
fsnotify_clear_marks_by_group_flags(group, (unsigned int)-1);
}
void fsnotify_duplicate_mark(struct fsnotify_mark *new, struct fsnotify_mark *old)
{
assert_spin_locked(&old->lock);
new->inode = old->inode;
new->mnt = old->mnt;
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
static void fsnotify_mark_destroy(struct work_struct *work)
{
struct fsnotify_mark *mark, *next;
struct list_head private_destroy_list;
spin_lock(&destroy_lock);
list_replace_init(&destroy_list, &private_destroy_list);
spin_unlock(&destroy_lock);
synchronize_srcu(&fsnotify_mark_srcu);
list_for_each_entry_safe(mark, next, &private_destroy_list, g_list) {
list_del_init(&mark->g_list);
fsnotify_put_mark(mark);
}
}
