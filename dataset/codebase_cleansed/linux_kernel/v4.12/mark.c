void fsnotify_get_mark(struct fsnotify_mark *mark)
{
WARN_ON_ONCE(!atomic_read(&mark->refcnt));
atomic_inc(&mark->refcnt);
}
static bool fsnotify_get_mark_safe(struct fsnotify_mark *mark)
{
return atomic_inc_not_zero(&mark->refcnt);
}
static void __fsnotify_recalc_mask(struct fsnotify_mark_connector *conn)
{
u32 new_mask = 0;
struct fsnotify_mark *mark;
assert_spin_locked(&conn->lock);
hlist_for_each_entry(mark, &conn->list, obj_list) {
if (mark->flags & FSNOTIFY_MARK_FLAG_ATTACHED)
new_mask |= mark->mask;
}
if (conn->flags & FSNOTIFY_OBJ_TYPE_INODE)
conn->inode->i_fsnotify_mask = new_mask;
else if (conn->flags & FSNOTIFY_OBJ_TYPE_VFSMOUNT)
real_mount(conn->mnt)->mnt_fsnotify_mask = new_mask;
}
void fsnotify_recalc_mask(struct fsnotify_mark_connector *conn)
{
if (!conn)
return;
spin_lock(&conn->lock);
__fsnotify_recalc_mask(conn);
spin_unlock(&conn->lock);
if (conn->flags & FSNOTIFY_OBJ_TYPE_INODE)
__fsnotify_update_child_dentry_flags(conn->inode);
}
static void fsnotify_connector_destroy_workfn(struct work_struct *work)
{
struct fsnotify_mark_connector *conn, *free;
spin_lock(&destroy_lock);
conn = connector_destroy_list;
connector_destroy_list = NULL;
spin_unlock(&destroy_lock);
synchronize_srcu(&fsnotify_mark_srcu);
while (conn) {
free = conn;
conn = conn->destroy_next;
kmem_cache_free(fsnotify_mark_connector_cachep, free);
}
}
static struct inode *fsnotify_detach_connector_from_object(
struct fsnotify_mark_connector *conn)
{
struct inode *inode = NULL;
if (conn->flags & FSNOTIFY_OBJ_TYPE_INODE) {
inode = conn->inode;
rcu_assign_pointer(inode->i_fsnotify_marks, NULL);
inode->i_fsnotify_mask = 0;
conn->inode = NULL;
conn->flags &= ~FSNOTIFY_OBJ_TYPE_INODE;
} else if (conn->flags & FSNOTIFY_OBJ_TYPE_VFSMOUNT) {
rcu_assign_pointer(real_mount(conn->mnt)->mnt_fsnotify_marks,
NULL);
real_mount(conn->mnt)->mnt_fsnotify_mask = 0;
conn->mnt = NULL;
conn->flags &= ~FSNOTIFY_OBJ_TYPE_VFSMOUNT;
}
return inode;
}
static void fsnotify_final_mark_destroy(struct fsnotify_mark *mark)
{
struct fsnotify_group *group = mark->group;
if (WARN_ON_ONCE(!group))
return;
group->ops->free_mark(mark);
fsnotify_put_group(group);
}
void fsnotify_put_mark(struct fsnotify_mark *mark)
{
struct fsnotify_mark_connector *conn;
struct inode *inode = NULL;
bool free_conn = false;
if (!mark->connector) {
if (atomic_dec_and_test(&mark->refcnt))
fsnotify_final_mark_destroy(mark);
return;
}
if (!atomic_dec_and_lock(&mark->refcnt, &mark->connector->lock))
return;
conn = mark->connector;
hlist_del_init_rcu(&mark->obj_list);
if (hlist_empty(&conn->list)) {
inode = fsnotify_detach_connector_from_object(conn);
free_conn = true;
} else {
__fsnotify_recalc_mask(conn);
}
mark->connector = NULL;
spin_unlock(&conn->lock);
iput(inode);
if (free_conn) {
spin_lock(&destroy_lock);
conn->destroy_next = connector_destroy_list;
connector_destroy_list = conn;
spin_unlock(&destroy_lock);
queue_work(system_unbound_wq, &connector_reaper_work);
}
spin_lock(&destroy_lock);
list_add(&mark->g_list, &destroy_list);
spin_unlock(&destroy_lock);
queue_delayed_work(system_unbound_wq, &reaper_work,
FSNOTIFY_REAPER_DELAY);
}
bool fsnotify_prepare_user_wait(struct fsnotify_iter_info *iter_info)
{
struct fsnotify_group *group;
if (WARN_ON_ONCE(!iter_info->inode_mark && !iter_info->vfsmount_mark))
return false;
if (iter_info->inode_mark)
group = iter_info->inode_mark->group;
else
group = iter_info->vfsmount_mark->group;
atomic_inc(&group->user_waits);
if (iter_info->inode_mark) {
if (!fsnotify_get_mark_safe(iter_info->inode_mark))
goto out_wait;
}
if (iter_info->vfsmount_mark) {
if (!fsnotify_get_mark_safe(iter_info->vfsmount_mark))
goto out_inode;
}
srcu_read_unlock(&fsnotify_mark_srcu, iter_info->srcu_idx);
return true;
out_inode:
if (iter_info->inode_mark)
fsnotify_put_mark(iter_info->inode_mark);
out_wait:
if (atomic_dec_and_test(&group->user_waits) && group->shutdown)
wake_up(&group->notification_waitq);
return false;
}
void fsnotify_finish_user_wait(struct fsnotify_iter_info *iter_info)
{
struct fsnotify_group *group = NULL;
iter_info->srcu_idx = srcu_read_lock(&fsnotify_mark_srcu);
if (iter_info->inode_mark) {
group = iter_info->inode_mark->group;
fsnotify_put_mark(iter_info->inode_mark);
}
if (iter_info->vfsmount_mark) {
group = iter_info->vfsmount_mark->group;
fsnotify_put_mark(iter_info->vfsmount_mark);
}
if (atomic_dec_and_test(&group->user_waits) && group->shutdown)
wake_up(&group->notification_waitq);
}
void fsnotify_detach_mark(struct fsnotify_mark *mark)
{
struct fsnotify_group *group = mark->group;
WARN_ON_ONCE(!mutex_is_locked(&group->mark_mutex));
WARN_ON_ONCE(!srcu_read_lock_held(&fsnotify_mark_srcu) &&
atomic_read(&mark->refcnt) < 1 +
!!(mark->flags & FSNOTIFY_MARK_FLAG_ATTACHED));
spin_lock(&mark->lock);
if (!(mark->flags & FSNOTIFY_MARK_FLAG_ATTACHED)) {
spin_unlock(&mark->lock);
return;
}
mark->flags &= ~FSNOTIFY_MARK_FLAG_ATTACHED;
list_del_init(&mark->g_list);
spin_unlock(&mark->lock);
atomic_dec(&group->num_marks);
fsnotify_put_mark(mark);
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
static int fsnotify_attach_connector_to_object(
struct fsnotify_mark_connector __rcu **connp,
struct inode *inode,
struct vfsmount *mnt)
{
struct fsnotify_mark_connector *conn;
conn = kmem_cache_alloc(fsnotify_mark_connector_cachep, GFP_KERNEL);
if (!conn)
return -ENOMEM;
spin_lock_init(&conn->lock);
INIT_HLIST_HEAD(&conn->list);
if (inode) {
conn->flags = FSNOTIFY_OBJ_TYPE_INODE;
conn->inode = igrab(inode);
} else {
conn->flags = FSNOTIFY_OBJ_TYPE_VFSMOUNT;
conn->mnt = mnt;
}
if (cmpxchg(connp, NULL, conn)) {
if (inode)
iput(inode);
kmem_cache_free(fsnotify_mark_connector_cachep, conn);
}
return 0;
}
static struct fsnotify_mark_connector *fsnotify_grab_connector(
struct fsnotify_mark_connector __rcu **connp)
{
struct fsnotify_mark_connector *conn;
int idx;
idx = srcu_read_lock(&fsnotify_mark_srcu);
conn = srcu_dereference(*connp, &fsnotify_mark_srcu);
if (!conn)
goto out;
spin_lock(&conn->lock);
if (!(conn->flags & (FSNOTIFY_OBJ_TYPE_INODE |
FSNOTIFY_OBJ_TYPE_VFSMOUNT))) {
spin_unlock(&conn->lock);
srcu_read_unlock(&fsnotify_mark_srcu, idx);
return NULL;
}
out:
srcu_read_unlock(&fsnotify_mark_srcu, idx);
return conn;
}
static int fsnotify_add_mark_list(struct fsnotify_mark *mark,
struct inode *inode, struct vfsmount *mnt,
int allow_dups)
{
struct fsnotify_mark *lmark, *last = NULL;
struct fsnotify_mark_connector *conn;
struct fsnotify_mark_connector __rcu **connp;
int cmp;
int err = 0;
if (WARN_ON(!inode && !mnt))
return -EINVAL;
if (inode)
connp = &inode->i_fsnotify_marks;
else
connp = &real_mount(mnt)->mnt_fsnotify_marks;
restart:
spin_lock(&mark->lock);
conn = fsnotify_grab_connector(connp);
if (!conn) {
spin_unlock(&mark->lock);
err = fsnotify_attach_connector_to_object(connp, inode, mnt);
if (err)
return err;
goto restart;
}
if (hlist_empty(&conn->list)) {
hlist_add_head_rcu(&mark->obj_list, &conn->list);
goto added;
}
hlist_for_each_entry(lmark, &conn->list, obj_list) {
last = lmark;
if ((lmark->group == mark->group) &&
(lmark->flags & FSNOTIFY_MARK_FLAG_ATTACHED) &&
!allow_dups) {
err = -EEXIST;
goto out_err;
}
cmp = fsnotify_compare_groups(lmark->group, mark->group);
if (cmp >= 0) {
hlist_add_before_rcu(&mark->obj_list, &lmark->obj_list);
goto added;
}
}
BUG_ON(last == NULL);
hlist_add_behind_rcu(&mark->obj_list, &last->obj_list);
added:
mark->connector = conn;
out_err:
spin_unlock(&conn->lock);
spin_unlock(&mark->lock);
return err;
}
int fsnotify_add_mark_locked(struct fsnotify_mark *mark, struct inode *inode,
struct vfsmount *mnt, int allow_dups)
{
struct fsnotify_group *group = mark->group;
int ret = 0;
BUG_ON(inode && mnt);
BUG_ON(!inode && !mnt);
BUG_ON(!mutex_is_locked(&group->mark_mutex));
spin_lock(&mark->lock);
mark->flags |= FSNOTIFY_MARK_FLAG_ALIVE | FSNOTIFY_MARK_FLAG_ATTACHED;
list_add(&mark->g_list, &group->marks_list);
atomic_inc(&group->num_marks);
fsnotify_get_mark(mark);
spin_unlock(&mark->lock);
ret = fsnotify_add_mark_list(mark, inode, mnt, allow_dups);
if (ret)
goto err;
if (mark->mask)
fsnotify_recalc_mask(mark->connector);
return ret;
err:
mark->flags &= ~(FSNOTIFY_MARK_FLAG_ALIVE |
FSNOTIFY_MARK_FLAG_ATTACHED);
list_del_init(&mark->g_list);
atomic_dec(&group->num_marks);
fsnotify_put_mark(mark);
return ret;
}
int fsnotify_add_mark(struct fsnotify_mark *mark, struct inode *inode,
struct vfsmount *mnt, int allow_dups)
{
int ret;
struct fsnotify_group *group = mark->group;
mutex_lock(&group->mark_mutex);
ret = fsnotify_add_mark_locked(mark, inode, mnt, allow_dups);
mutex_unlock(&group->mark_mutex);
return ret;
}
struct fsnotify_mark *fsnotify_find_mark(
struct fsnotify_mark_connector __rcu **connp,
struct fsnotify_group *group)
{
struct fsnotify_mark_connector *conn;
struct fsnotify_mark *mark;
conn = fsnotify_grab_connector(connp);
if (!conn)
return NULL;
hlist_for_each_entry(mark, &conn->list, obj_list) {
if (mark->group == group &&
(mark->flags & FSNOTIFY_MARK_FLAG_ATTACHED)) {
fsnotify_get_mark(mark);
spin_unlock(&conn->lock);
return mark;
}
}
spin_unlock(&conn->lock);
return NULL;
}
void fsnotify_clear_marks_by_group(struct fsnotify_group *group,
unsigned int type)
{
struct fsnotify_mark *lmark, *mark;
LIST_HEAD(to_free);
struct list_head *head = &to_free;
if (type == FSNOTIFY_OBJ_ALL_TYPES) {
head = &group->marks_list;
goto clear;
}
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
list_for_each_entry_safe(mark, lmark, &group->marks_list, g_list) {
if (mark->connector->flags & type)
list_move(&mark->g_list, &to_free);
}
mutex_unlock(&group->mark_mutex);
clear:
while (1) {
mutex_lock_nested(&group->mark_mutex, SINGLE_DEPTH_NESTING);
if (list_empty(head)) {
mutex_unlock(&group->mark_mutex);
break;
}
mark = list_first_entry(head, struct fsnotify_mark, g_list);
fsnotify_get_mark(mark);
fsnotify_detach_mark(mark);
mutex_unlock(&group->mark_mutex);
fsnotify_free_mark(mark);
fsnotify_put_mark(mark);
}
}
void fsnotify_destroy_marks(struct fsnotify_mark_connector __rcu **connp)
{
struct fsnotify_mark_connector *conn;
struct fsnotify_mark *mark, *old_mark = NULL;
struct inode *inode;
conn = fsnotify_grab_connector(connp);
if (!conn)
return;
hlist_for_each_entry(mark, &conn->list, obj_list) {
fsnotify_get_mark(mark);
spin_unlock(&conn->lock);
if (old_mark)
fsnotify_put_mark(old_mark);
old_mark = mark;
fsnotify_destroy_mark(mark, mark->group);
spin_lock(&conn->lock);
}
inode = fsnotify_detach_connector_from_object(conn);
spin_unlock(&conn->lock);
if (old_mark)
fsnotify_put_mark(old_mark);
iput(inode);
}
void fsnotify_init_mark(struct fsnotify_mark *mark,
struct fsnotify_group *group)
{
memset(mark, 0, sizeof(*mark));
spin_lock_init(&mark->lock);
atomic_set(&mark->refcnt, 1);
fsnotify_get_group(group);
mark->group = group;
}
static void fsnotify_mark_destroy_workfn(struct work_struct *work)
{
struct fsnotify_mark *mark, *next;
struct list_head private_destroy_list;
spin_lock(&destroy_lock);
list_replace_init(&destroy_list, &private_destroy_list);
spin_unlock(&destroy_lock);
synchronize_srcu(&fsnotify_mark_srcu);
list_for_each_entry_safe(mark, next, &private_destroy_list, g_list) {
list_del_init(&mark->g_list);
fsnotify_final_mark_destroy(mark);
}
}
void fsnotify_wait_marks_destroyed(void)
{
flush_delayed_work(&reaper_work);
}
