static inline struct vfsmount *next_peer(struct vfsmount *p)
{
return list_entry(p->mnt_share.next, struct vfsmount, mnt_share);
}
static inline struct vfsmount *first_slave(struct vfsmount *p)
{
return list_entry(p->mnt_slave_list.next, struct vfsmount, mnt_slave);
}
static inline struct vfsmount *next_slave(struct vfsmount *p)
{
return list_entry(p->mnt_slave.next, struct vfsmount, mnt_slave);
}
static bool is_path_reachable(struct vfsmount *mnt, struct dentry *dentry,
const struct path *root)
{
while (mnt != root->mnt && mnt->mnt_parent != mnt) {
dentry = mnt->mnt_mountpoint;
mnt = mnt->mnt_parent;
}
return mnt == root->mnt && is_subdir(dentry, root->dentry);
}
static struct vfsmount *get_peer_under_root(struct vfsmount *mnt,
struct mnt_namespace *ns,
const struct path *root)
{
struct vfsmount *m = mnt;
do {
if (m->mnt_ns == ns && is_path_reachable(m, m->mnt_root, root))
return m;
m = next_peer(m);
} while (m != mnt);
return NULL;
}
int get_dominating_id(struct vfsmount *mnt, const struct path *root)
{
struct vfsmount *m;
for (m = mnt->mnt_master; m != NULL; m = m->mnt_master) {
struct vfsmount *d = get_peer_under_root(m, mnt->mnt_ns, root);
if (d)
return d->mnt_group_id;
}
return 0;
}
static int do_make_slave(struct vfsmount *mnt)
{
struct vfsmount *peer_mnt = mnt, *master = mnt->mnt_master;
struct vfsmount *slave_mnt;
while ((peer_mnt = next_peer(peer_mnt)) != mnt &&
peer_mnt->mnt_root != mnt->mnt_root) ;
if (peer_mnt == mnt) {
peer_mnt = next_peer(mnt);
if (peer_mnt == mnt)
peer_mnt = NULL;
}
if (IS_MNT_SHARED(mnt) && list_empty(&mnt->mnt_share))
mnt_release_group_id(mnt);
list_del_init(&mnt->mnt_share);
mnt->mnt_group_id = 0;
if (peer_mnt)
master = peer_mnt;
if (master) {
list_for_each_entry(slave_mnt, &mnt->mnt_slave_list, mnt_slave)
slave_mnt->mnt_master = master;
list_move(&mnt->mnt_slave, &master->mnt_slave_list);
list_splice(&mnt->mnt_slave_list, master->mnt_slave_list.prev);
INIT_LIST_HEAD(&mnt->mnt_slave_list);
} else {
struct list_head *p = &mnt->mnt_slave_list;
while (!list_empty(p)) {
slave_mnt = list_first_entry(p,
struct vfsmount, mnt_slave);
list_del_init(&slave_mnt->mnt_slave);
slave_mnt->mnt_master = NULL;
}
}
mnt->mnt_master = master;
CLEAR_MNT_SHARED(mnt);
return 0;
}
void change_mnt_propagation(struct vfsmount *mnt, int type)
{
if (type == MS_SHARED) {
set_mnt_shared(mnt);
return;
}
do_make_slave(mnt);
if (type != MS_SLAVE) {
list_del_init(&mnt->mnt_slave);
mnt->mnt_master = NULL;
if (type == MS_UNBINDABLE)
mnt->mnt_flags |= MNT_UNBINDABLE;
else
mnt->mnt_flags &= ~MNT_UNBINDABLE;
}
}
static struct vfsmount *propagation_next(struct vfsmount *m,
struct vfsmount *origin)
{
if (!IS_MNT_NEW(m) && !list_empty(&m->mnt_slave_list))
return first_slave(m);
while (1) {
struct vfsmount *next;
struct vfsmount *master = m->mnt_master;
if (master == origin->mnt_master) {
next = next_peer(m);
return ((next == origin) ? NULL : next);
} else if (m->mnt_slave.next != &master->mnt_slave_list)
return next_slave(m);
m = master;
}
}
static struct vfsmount *get_source(struct vfsmount *dest,
struct vfsmount *last_dest,
struct vfsmount *last_src,
int *type)
{
struct vfsmount *p_last_src = NULL;
struct vfsmount *p_last_dest = NULL;
while (last_dest != dest->mnt_master) {
p_last_dest = last_dest;
p_last_src = last_src;
last_dest = last_dest->mnt_master;
last_src = last_src->mnt_master;
}
if (p_last_dest) {
do {
p_last_dest = next_peer(p_last_dest);
} while (IS_MNT_NEW(p_last_dest));
if (dest == p_last_dest) {
*type = CL_MAKE_SHARED;
return p_last_src;
}
}
*type = CL_SLAVE;
if (IS_MNT_SHARED(dest))
*type |= CL_MAKE_SHARED;
return last_src;
}
int propagate_mnt(struct vfsmount *dest_mnt, struct dentry *dest_dentry,
struct vfsmount *source_mnt, struct list_head *tree_list)
{
struct vfsmount *m, *child;
int ret = 0;
struct vfsmount *prev_dest_mnt = dest_mnt;
struct vfsmount *prev_src_mnt = source_mnt;
LIST_HEAD(tmp_list);
LIST_HEAD(umount_list);
for (m = propagation_next(dest_mnt, dest_mnt); m;
m = propagation_next(m, dest_mnt)) {
int type;
struct vfsmount *source;
if (IS_MNT_NEW(m))
continue;
source = get_source(m, prev_dest_mnt, prev_src_mnt, &type);
if (!(child = copy_tree(source, source->mnt_root, type))) {
ret = -ENOMEM;
list_splice(tree_list, tmp_list.prev);
goto out;
}
if (is_subdir(dest_dentry, m->mnt_root)) {
mnt_set_mountpoint(m, dest_dentry, child);
list_add_tail(&child->mnt_hash, tree_list);
} else {
list_add_tail(&child->mnt_hash, &tmp_list);
}
prev_dest_mnt = m;
prev_src_mnt = child;
}
out:
br_write_lock(vfsmount_lock);
while (!list_empty(&tmp_list)) {
child = list_first_entry(&tmp_list, struct vfsmount, mnt_hash);
umount_tree(child, 0, &umount_list);
}
br_write_unlock(vfsmount_lock);
release_mounts(&umount_list);
return ret;
}
static inline int do_refcount_check(struct vfsmount *mnt, int count)
{
int mycount = mnt_get_count(mnt) - mnt->mnt_ghosts;
return (mycount > count);
}
int propagate_mount_busy(struct vfsmount *mnt, int refcnt)
{
struct vfsmount *m, *child;
struct vfsmount *parent = mnt->mnt_parent;
int ret = 0;
if (mnt == parent)
return do_refcount_check(mnt, refcnt);
if (!list_empty(&mnt->mnt_mounts) || do_refcount_check(mnt, refcnt))
return 1;
for (m = propagation_next(parent, parent); m;
m = propagation_next(m, parent)) {
child = __lookup_mnt(m, mnt->mnt_mountpoint, 0);
if (child && list_empty(&child->mnt_mounts) &&
(ret = do_refcount_check(child, 1)))
break;
}
return ret;
}
static void __propagate_umount(struct vfsmount *mnt)
{
struct vfsmount *parent = mnt->mnt_parent;
struct vfsmount *m;
BUG_ON(parent == mnt);
for (m = propagation_next(parent, parent); m;
m = propagation_next(m, parent)) {
struct vfsmount *child = __lookup_mnt(m,
mnt->mnt_mountpoint, 0);
if (child && list_empty(&child->mnt_mounts))
list_move_tail(&child->mnt_hash, &mnt->mnt_hash);
}
}
int propagate_umount(struct list_head *list)
{
struct vfsmount *mnt;
list_for_each_entry(mnt, list, mnt_hash)
__propagate_umount(mnt);
return 0;
}
