static inline struct mount *next_peer(struct mount *p)
{
return list_entry(p->mnt_share.next, struct mount, mnt_share);
}
static inline struct mount *first_slave(struct mount *p)
{
return list_entry(p->mnt_slave_list.next, struct mount, mnt_slave);
}
static inline struct mount *next_slave(struct mount *p)
{
return list_entry(p->mnt_slave.next, struct mount, mnt_slave);
}
static struct mount *get_peer_under_root(struct mount *mnt,
struct mnt_namespace *ns,
const struct path *root)
{
struct mount *m = mnt;
do {
if (m->mnt_ns == ns && is_path_reachable(m, m->mnt.mnt_root, root))
return m;
m = next_peer(m);
} while (m != mnt);
return NULL;
}
int get_dominating_id(struct mount *mnt, const struct path *root)
{
struct mount *m;
for (m = mnt->mnt_master; m != NULL; m = m->mnt_master) {
struct mount *d = get_peer_under_root(m, mnt->mnt_ns, root);
if (d)
return d->mnt_group_id;
}
return 0;
}
static int do_make_slave(struct mount *mnt)
{
struct mount *master, *slave_mnt;
if (list_empty(&mnt->mnt_share)) {
if (IS_MNT_SHARED(mnt)) {
mnt_release_group_id(mnt);
CLEAR_MNT_SHARED(mnt);
}
master = mnt->mnt_master;
if (!master) {
struct list_head *p = &mnt->mnt_slave_list;
while (!list_empty(p)) {
slave_mnt = list_first_entry(p,
struct mount, mnt_slave);
list_del_init(&slave_mnt->mnt_slave);
slave_mnt->mnt_master = NULL;
}
return 0;
}
} else {
struct mount *m;
for (m = master = next_peer(mnt); m != mnt; m = next_peer(m)) {
if (m->mnt.mnt_root == mnt->mnt.mnt_root) {
master = m;
break;
}
}
list_del_init(&mnt->mnt_share);
mnt->mnt_group_id = 0;
CLEAR_MNT_SHARED(mnt);
}
list_for_each_entry(slave_mnt, &mnt->mnt_slave_list, mnt_slave)
slave_mnt->mnt_master = master;
list_move(&mnt->mnt_slave, &master->mnt_slave_list);
list_splice(&mnt->mnt_slave_list, master->mnt_slave_list.prev);
INIT_LIST_HEAD(&mnt->mnt_slave_list);
mnt->mnt_master = master;
return 0;
}
void change_mnt_propagation(struct mount *mnt, int type)
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
mnt->mnt.mnt_flags |= MNT_UNBINDABLE;
else
mnt->mnt.mnt_flags &= ~MNT_UNBINDABLE;
}
}
static struct mount *propagation_next(struct mount *m,
struct mount *origin)
{
if (!IS_MNT_NEW(m) && !list_empty(&m->mnt_slave_list))
return first_slave(m);
while (1) {
struct mount *master = m->mnt_master;
if (master == origin->mnt_master) {
struct mount *next = next_peer(m);
return (next == origin) ? NULL : next;
} else if (m->mnt_slave.next != &master->mnt_slave_list)
return next_slave(m);
m = master;
}
}
static struct mount *next_group(struct mount *m, struct mount *origin)
{
while (1) {
while (1) {
struct mount *next;
if (!IS_MNT_NEW(m) && !list_empty(&m->mnt_slave_list))
return first_slave(m);
next = next_peer(m);
if (m->mnt_group_id == origin->mnt_group_id) {
if (next == origin)
return NULL;
} else if (m->mnt_slave.next != &next->mnt_slave)
break;
m = next;
}
while (1) {
struct mount *master = m->mnt_master;
if (m->mnt_slave.next != &master->mnt_slave_list)
return next_slave(m);
m = next_peer(master);
if (master->mnt_group_id == origin->mnt_group_id)
break;
if (master->mnt_slave.next == &m->mnt_slave)
break;
m = master;
}
if (m == origin)
return NULL;
}
}
static inline bool peers(struct mount *m1, struct mount *m2)
{
return m1->mnt_group_id == m2->mnt_group_id && m1->mnt_group_id;
}
static int propagate_one(struct mount *m)
{
struct mount *child;
int type;
if (IS_MNT_NEW(m))
return 0;
if (!is_subdir(mp->m_dentry, m->mnt.mnt_root))
return 0;
if (peers(m, last_dest)) {
type = CL_MAKE_SHARED;
} else {
struct mount *n, *p;
bool done;
for (n = m; ; n = p) {
p = n->mnt_master;
if (p == dest_master || IS_MNT_MARKED(p))
break;
}
do {
struct mount *parent = last_source->mnt_parent;
if (last_source == first_source)
break;
done = parent->mnt_master == p;
if (done && peers(n, parent))
break;
last_source = last_source->mnt_master;
} while (!done);
type = CL_SLAVE;
if (IS_MNT_SHARED(m))
type |= CL_MAKE_SHARED;
}
if (m->mnt_ns->user_ns != user_ns)
type |= CL_UNPRIVILEGED;
child = copy_tree(last_source, last_source->mnt.mnt_root, type);
if (IS_ERR(child))
return PTR_ERR(child);
child->mnt.mnt_flags &= ~MNT_LOCKED;
mnt_set_mountpoint(m, mp, child);
last_dest = m;
last_source = child;
if (m->mnt_master != dest_master) {
read_seqlock_excl(&mount_lock);
SET_MNT_MARK(m->mnt_master);
read_sequnlock_excl(&mount_lock);
}
hlist_add_head(&child->mnt_hash, list);
return count_mounts(m->mnt_ns, child);
}
int propagate_mnt(struct mount *dest_mnt, struct mountpoint *dest_mp,
struct mount *source_mnt, struct hlist_head *tree_list)
{
struct mount *m, *n;
int ret = 0;
user_ns = current->nsproxy->mnt_ns->user_ns;
last_dest = dest_mnt;
first_source = source_mnt;
last_source = source_mnt;
mp = dest_mp;
list = tree_list;
dest_master = dest_mnt->mnt_master;
for (n = next_peer(dest_mnt); n != dest_mnt; n = next_peer(n)) {
ret = propagate_one(n);
if (ret)
goto out;
}
for (m = next_group(dest_mnt, dest_mnt); m;
m = next_group(m, dest_mnt)) {
n = m;
do {
ret = propagate_one(n);
if (ret)
goto out;
n = next_peer(n);
} while (n != m);
}
out:
read_seqlock_excl(&mount_lock);
hlist_for_each_entry(n, tree_list, mnt_hash) {
m = n->mnt_parent;
if (m->mnt_master != dest_mnt->mnt_master)
CLEAR_MNT_MARK(m->mnt_master);
}
read_sequnlock_excl(&mount_lock);
return ret;
}
static struct mount *find_topper(struct mount *mnt)
{
struct mount *child;
if (!list_is_singular(&mnt->mnt_mounts))
return NULL;
child = list_first_entry(&mnt->mnt_mounts, struct mount, mnt_child);
if (child->mnt_mountpoint != mnt->mnt.mnt_root)
return NULL;
return child;
}
static inline int do_refcount_check(struct mount *mnt, int count)
{
return mnt_get_count(mnt) > count;
}
int propagate_mount_busy(struct mount *mnt, int refcnt)
{
struct mount *m, *child, *topper;
struct mount *parent = mnt->mnt_parent;
if (mnt == parent)
return do_refcount_check(mnt, refcnt);
if (!list_empty(&mnt->mnt_mounts) || do_refcount_check(mnt, refcnt))
return 1;
for (m = propagation_next(parent, parent); m;
m = propagation_next(m, parent)) {
int count = 1;
child = __lookup_mnt(&m->mnt, mnt->mnt_mountpoint);
if (!child)
continue;
topper = find_topper(child);
if (topper)
count += 1;
else if (!list_empty(&child->mnt_mounts))
continue;
if (do_refcount_check(child, count))
return 1;
}
return 0;
}
void propagate_mount_unlock(struct mount *mnt)
{
struct mount *parent = mnt->mnt_parent;
struct mount *m, *child;
BUG_ON(parent == mnt);
for (m = propagation_next(parent, parent); m;
m = propagation_next(m, parent)) {
child = __lookup_mnt(&m->mnt, mnt->mnt_mountpoint);
if (child)
child->mnt.mnt_flags &= ~MNT_LOCKED;
}
}
static void mark_umount_candidates(struct mount *mnt)
{
struct mount *parent = mnt->mnt_parent;
struct mount *m;
BUG_ON(parent == mnt);
for (m = propagation_next(parent, parent); m;
m = propagation_next(m, parent)) {
struct mount *child = __lookup_mnt(&m->mnt,
mnt->mnt_mountpoint);
if (!child || (child->mnt.mnt_flags & MNT_UMOUNT))
continue;
if (!IS_MNT_LOCKED(child) || IS_MNT_MARKED(m)) {
SET_MNT_MARK(child);
}
}
}
static void __propagate_umount(struct mount *mnt)
{
struct mount *parent = mnt->mnt_parent;
struct mount *m;
BUG_ON(parent == mnt);
for (m = propagation_next(parent, parent); m;
m = propagation_next(m, parent)) {
struct mount *topper;
struct mount *child = __lookup_mnt(&m->mnt,
mnt->mnt_mountpoint);
if (!child || !IS_MNT_MARKED(child))
continue;
CLEAR_MNT_MARK(child);
topper = find_topper(child);
if (topper)
mnt_change_mountpoint(child->mnt_parent, child->mnt_mp,
topper);
if (list_empty(&child->mnt_mounts)) {
list_del_init(&child->mnt_child);
child->mnt.mnt_flags |= MNT_UMOUNT;
list_move_tail(&child->mnt_list, &mnt->mnt_list);
}
}
}
int propagate_umount(struct list_head *list)
{
struct mount *mnt;
list_for_each_entry_reverse(mnt, list, mnt_list)
mark_umount_candidates(mnt);
list_for_each_entry(mnt, list, mnt_list)
__propagate_umount(mnt);
return 0;
}
