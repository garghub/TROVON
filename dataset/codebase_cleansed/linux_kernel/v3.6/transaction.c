void put_transaction(struct btrfs_transaction *transaction)
{
WARN_ON(atomic_read(&transaction->use_count) == 0);
if (atomic_dec_and_test(&transaction->use_count)) {
BUG_ON(!list_empty(&transaction->list));
WARN_ON(transaction->delayed_refs.root.rb_node);
memset(transaction, 0, sizeof(*transaction));
kmem_cache_free(btrfs_transaction_cachep, transaction);
}
}
static noinline void switch_commit_root(struct btrfs_root *root)
{
free_extent_buffer(root->commit_root);
root->commit_root = btrfs_root_node(root);
}
static noinline int join_transaction(struct btrfs_root *root, int nofail)
{
struct btrfs_transaction *cur_trans;
struct btrfs_fs_info *fs_info = root->fs_info;
spin_lock(&fs_info->trans_lock);
loop:
if (fs_info->fs_state & BTRFS_SUPER_FLAG_ERROR) {
spin_unlock(&fs_info->trans_lock);
return -EROFS;
}
if (fs_info->trans_no_join) {
if (!nofail) {
spin_unlock(&fs_info->trans_lock);
return -EBUSY;
}
}
cur_trans = fs_info->running_transaction;
if (cur_trans) {
if (cur_trans->aborted) {
spin_unlock(&fs_info->trans_lock);
return cur_trans->aborted;
}
atomic_inc(&cur_trans->use_count);
atomic_inc(&cur_trans->num_writers);
cur_trans->num_joined++;
spin_unlock(&fs_info->trans_lock);
return 0;
}
spin_unlock(&fs_info->trans_lock);
cur_trans = kmem_cache_alloc(btrfs_transaction_cachep, GFP_NOFS);
if (!cur_trans)
return -ENOMEM;
spin_lock(&fs_info->trans_lock);
if (fs_info->running_transaction) {
kmem_cache_free(btrfs_transaction_cachep, cur_trans);
cur_trans = fs_info->running_transaction;
goto loop;
} else if (fs_info->fs_state & BTRFS_SUPER_FLAG_ERROR) {
spin_unlock(&fs_info->trans_lock);
kmem_cache_free(btrfs_transaction_cachep, cur_trans);
return -EROFS;
}
atomic_set(&cur_trans->num_writers, 1);
cur_trans->num_joined = 0;
init_waitqueue_head(&cur_trans->writer_wait);
init_waitqueue_head(&cur_trans->commit_wait);
cur_trans->in_commit = 0;
cur_trans->blocked = 0;
atomic_set(&cur_trans->use_count, 2);
cur_trans->commit_done = 0;
cur_trans->start_time = get_seconds();
cur_trans->delayed_refs.root = RB_ROOT;
cur_trans->delayed_refs.num_entries = 0;
cur_trans->delayed_refs.num_heads_ready = 0;
cur_trans->delayed_refs.num_heads = 0;
cur_trans->delayed_refs.flushing = 0;
cur_trans->delayed_refs.run_delayed_start = 0;
smp_mb();
if (!list_empty(&fs_info->tree_mod_seq_list)) {
printk(KERN_ERR "btrfs: tree_mod_seq_list not empty when "
"creating a fresh transaction\n");
WARN_ON(1);
}
if (!RB_EMPTY_ROOT(&fs_info->tree_mod_log)) {
printk(KERN_ERR "btrfs: tree_mod_log rb tree not empty when "
"creating a fresh transaction\n");
WARN_ON(1);
}
atomic_set(&fs_info->tree_mod_seq, 0);
spin_lock_init(&cur_trans->commit_lock);
spin_lock_init(&cur_trans->delayed_refs.lock);
INIT_LIST_HEAD(&cur_trans->pending_snapshots);
list_add_tail(&cur_trans->list, &fs_info->trans_list);
extent_io_tree_init(&cur_trans->dirty_pages,
fs_info->btree_inode->i_mapping);
fs_info->generation++;
cur_trans->transid = fs_info->generation;
fs_info->running_transaction = cur_trans;
cur_trans->aborted = 0;
spin_unlock(&fs_info->trans_lock);
return 0;
}
static int record_root_in_trans(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
if (root->ref_cows && root->last_trans < trans->transid) {
WARN_ON(root == root->fs_info->extent_root);
WARN_ON(root->commit_root != root->node);
root->in_trans_setup = 1;
smp_wmb();
spin_lock(&root->fs_info->fs_roots_radix_lock);
if (root->last_trans == trans->transid) {
spin_unlock(&root->fs_info->fs_roots_radix_lock);
return 0;
}
radix_tree_tag_set(&root->fs_info->fs_roots_radix,
(unsigned long)root->root_key.objectid,
BTRFS_ROOT_TRANS_TAG);
spin_unlock(&root->fs_info->fs_roots_radix_lock);
root->last_trans = trans->transid;
btrfs_init_reloc_root(trans, root);
smp_wmb();
root->in_trans_setup = 0;
}
return 0;
}
int btrfs_record_root_in_trans(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
if (!root->ref_cows)
return 0;
smp_rmb();
if (root->last_trans == trans->transid &&
!root->in_trans_setup)
return 0;
mutex_lock(&root->fs_info->reloc_mutex);
record_root_in_trans(trans, root);
mutex_unlock(&root->fs_info->reloc_mutex);
return 0;
}
static void wait_current_trans(struct btrfs_root *root)
{
struct btrfs_transaction *cur_trans;
spin_lock(&root->fs_info->trans_lock);
cur_trans = root->fs_info->running_transaction;
if (cur_trans && cur_trans->blocked) {
atomic_inc(&cur_trans->use_count);
spin_unlock(&root->fs_info->trans_lock);
wait_event(root->fs_info->transaction_wait,
!cur_trans->blocked);
put_transaction(cur_trans);
} else {
spin_unlock(&root->fs_info->trans_lock);
}
}
static int may_wait_transaction(struct btrfs_root *root, int type)
{
if (root->fs_info->log_root_recovering)
return 0;
if (type == TRANS_USERSPACE)
return 1;
if (type == TRANS_START &&
!atomic_read(&root->fs_info->open_ioctl_trans))
return 1;
return 0;
}
static struct btrfs_trans_handle *start_transaction(struct btrfs_root *root,
u64 num_items, int type)
{
struct btrfs_trans_handle *h;
struct btrfs_transaction *cur_trans;
u64 num_bytes = 0;
int ret;
u64 qgroup_reserved = 0;
if (root->fs_info->fs_state & BTRFS_SUPER_FLAG_ERROR)
return ERR_PTR(-EROFS);
if (current->journal_info) {
WARN_ON(type != TRANS_JOIN && type != TRANS_JOIN_NOLOCK);
h = current->journal_info;
h->use_count++;
h->orig_rsv = h->block_rsv;
h->block_rsv = NULL;
goto got_it;
}
if (num_items > 0 && root != root->fs_info->chunk_root) {
if (root->fs_info->quota_enabled &&
is_fstree(root->root_key.objectid)) {
qgroup_reserved = num_items * root->leafsize;
ret = btrfs_qgroup_reserve(root, qgroup_reserved);
if (ret)
return ERR_PTR(ret);
}
num_bytes = btrfs_calc_trans_metadata_size(root, num_items);
ret = btrfs_block_rsv_add(root,
&root->fs_info->trans_block_rsv,
num_bytes);
if (ret)
return ERR_PTR(ret);
}
again:
h = kmem_cache_alloc(btrfs_trans_handle_cachep, GFP_NOFS);
if (!h)
return ERR_PTR(-ENOMEM);
sb_start_intwrite(root->fs_info->sb);
if (may_wait_transaction(root, type))
wait_current_trans(root);
do {
ret = join_transaction(root, type == TRANS_JOIN_NOLOCK);
if (ret == -EBUSY)
wait_current_trans(root);
} while (ret == -EBUSY);
if (ret < 0) {
sb_end_intwrite(root->fs_info->sb);
kmem_cache_free(btrfs_trans_handle_cachep, h);
return ERR_PTR(ret);
}
cur_trans = root->fs_info->running_transaction;
h->transid = cur_trans->transid;
h->transaction = cur_trans;
h->blocks_used = 0;
h->bytes_reserved = 0;
h->root = root;
h->delayed_ref_updates = 0;
h->use_count = 1;
h->adding_csums = 0;
h->block_rsv = NULL;
h->orig_rsv = NULL;
h->aborted = 0;
h->qgroup_reserved = qgroup_reserved;
h->delayed_ref_elem.seq = 0;
INIT_LIST_HEAD(&h->qgroup_ref_list);
smp_mb();
if (cur_trans->blocked && may_wait_transaction(root, type)) {
btrfs_commit_transaction(h, root);
goto again;
}
if (num_bytes) {
trace_btrfs_space_reservation(root->fs_info, "transaction",
h->transid, num_bytes, 1);
h->block_rsv = &root->fs_info->trans_block_rsv;
h->bytes_reserved = num_bytes;
}
got_it:
btrfs_record_root_in_trans(h, root);
if (!current->journal_info && type != TRANS_USERSPACE)
current->journal_info = h;
return h;
}
struct btrfs_trans_handle *btrfs_start_transaction(struct btrfs_root *root,
int num_items)
{
return start_transaction(root, num_items, TRANS_START);
}
struct btrfs_trans_handle *btrfs_join_transaction(struct btrfs_root *root)
{
return start_transaction(root, 0, TRANS_JOIN);
}
struct btrfs_trans_handle *btrfs_join_transaction_nolock(struct btrfs_root *root)
{
return start_transaction(root, 0, TRANS_JOIN_NOLOCK);
}
struct btrfs_trans_handle *btrfs_start_ioctl_transaction(struct btrfs_root *root)
{
return start_transaction(root, 0, TRANS_USERSPACE);
}
static noinline void wait_for_commit(struct btrfs_root *root,
struct btrfs_transaction *commit)
{
wait_event(commit->commit_wait, commit->commit_done);
}
int btrfs_wait_for_commit(struct btrfs_root *root, u64 transid)
{
struct btrfs_transaction *cur_trans = NULL, *t;
int ret;
ret = 0;
if (transid) {
if (transid <= root->fs_info->last_trans_committed)
goto out;
spin_lock(&root->fs_info->trans_lock);
list_for_each_entry(t, &root->fs_info->trans_list, list) {
if (t->transid == transid) {
cur_trans = t;
atomic_inc(&cur_trans->use_count);
break;
}
if (t->transid > transid)
break;
}
spin_unlock(&root->fs_info->trans_lock);
ret = -EINVAL;
if (!cur_trans)
goto out;
} else {
spin_lock(&root->fs_info->trans_lock);
list_for_each_entry_reverse(t, &root->fs_info->trans_list,
list) {
if (t->in_commit) {
if (t->commit_done)
break;
cur_trans = t;
atomic_inc(&cur_trans->use_count);
break;
}
}
spin_unlock(&root->fs_info->trans_lock);
if (!cur_trans)
goto out;
}
wait_for_commit(root, cur_trans);
put_transaction(cur_trans);
ret = 0;
out:
return ret;
}
void btrfs_throttle(struct btrfs_root *root)
{
if (!atomic_read(&root->fs_info->open_ioctl_trans))
wait_current_trans(root);
}
static int should_end_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int ret;
ret = btrfs_block_rsv_check(root, &root->fs_info->global_block_rsv, 5);
return ret ? 1 : 0;
}
int btrfs_should_end_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
struct btrfs_transaction *cur_trans = trans->transaction;
int updates;
int err;
smp_mb();
if (cur_trans->blocked || cur_trans->delayed_refs.flushing)
return 1;
updates = trans->delayed_ref_updates;
trans->delayed_ref_updates = 0;
if (updates) {
err = btrfs_run_delayed_refs(trans, root, updates);
if (err)
return err;
}
return should_end_transaction(trans, root);
}
static int __btrfs_end_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root, int throttle, int lock)
{
struct btrfs_transaction *cur_trans = trans->transaction;
struct btrfs_fs_info *info = root->fs_info;
int count = 0;
int err = 0;
if (--trans->use_count) {
trans->block_rsv = trans->orig_rsv;
return 0;
}
err = btrfs_delayed_refs_qgroup_accounting(trans, info);
btrfs_trans_release_metadata(trans, root);
trans->block_rsv = NULL;
WARN_ON(trans->root != root);
if (trans->qgroup_reserved) {
btrfs_qgroup_free(root, trans->qgroup_reserved);
trans->qgroup_reserved = 0;
}
while (count < 2) {
unsigned long cur = trans->delayed_ref_updates;
trans->delayed_ref_updates = 0;
if (cur &&
trans->transaction->delayed_refs.num_heads_ready > 64) {
trans->delayed_ref_updates = 0;
btrfs_run_delayed_refs(trans, root, cur);
} else {
break;
}
count++;
}
btrfs_trans_release_metadata(trans, root);
trans->block_rsv = NULL;
sb_end_intwrite(root->fs_info->sb);
if (lock && !atomic_read(&root->fs_info->open_ioctl_trans) &&
should_end_transaction(trans, root)) {
trans->transaction->blocked = 1;
smp_wmb();
}
if (lock && cur_trans->blocked && !cur_trans->in_commit) {
if (throttle) {
trans->use_count++;
return btrfs_commit_transaction(trans, root);
} else {
wake_up_process(info->transaction_kthread);
}
}
WARN_ON(cur_trans != info->running_transaction);
WARN_ON(atomic_read(&cur_trans->num_writers) < 1);
atomic_dec(&cur_trans->num_writers);
smp_mb();
if (waitqueue_active(&cur_trans->writer_wait))
wake_up(&cur_trans->writer_wait);
put_transaction(cur_trans);
if (current->journal_info == trans)
current->journal_info = NULL;
if (throttle)
btrfs_run_delayed_iputs(root);
if (trans->aborted ||
root->fs_info->fs_state & BTRFS_SUPER_FLAG_ERROR) {
err = -EIO;
}
assert_qgroups_uptodate(trans);
memset(trans, 0, sizeof(*trans));
kmem_cache_free(btrfs_trans_handle_cachep, trans);
return err;
}
int btrfs_end_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int ret;
ret = __btrfs_end_transaction(trans, root, 0, 1);
if (ret)
return ret;
return 0;
}
int btrfs_end_transaction_throttle(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int ret;
ret = __btrfs_end_transaction(trans, root, 1, 1);
if (ret)
return ret;
return 0;
}
int btrfs_end_transaction_nolock(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int ret;
ret = __btrfs_end_transaction(trans, root, 0, 0);
if (ret)
return ret;
return 0;
}
int btrfs_end_transaction_dmeta(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
return __btrfs_end_transaction(trans, root, 1, 1);
}
int btrfs_write_marked_extents(struct btrfs_root *root,
struct extent_io_tree *dirty_pages, int mark)
{
int err = 0;
int werr = 0;
struct address_space *mapping = root->fs_info->btree_inode->i_mapping;
u64 start = 0;
u64 end;
while (!find_first_extent_bit(dirty_pages, start, &start, &end,
mark)) {
convert_extent_bit(dirty_pages, start, end, EXTENT_NEED_WAIT, mark,
GFP_NOFS);
err = filemap_fdatawrite_range(mapping, start, end);
if (err)
werr = err;
cond_resched();
start = end + 1;
}
if (err)
werr = err;
return werr;
}
int btrfs_wait_marked_extents(struct btrfs_root *root,
struct extent_io_tree *dirty_pages, int mark)
{
int err = 0;
int werr = 0;
struct address_space *mapping = root->fs_info->btree_inode->i_mapping;
u64 start = 0;
u64 end;
while (!find_first_extent_bit(dirty_pages, start, &start, &end,
EXTENT_NEED_WAIT)) {
clear_extent_bits(dirty_pages, start, end, EXTENT_NEED_WAIT, GFP_NOFS);
err = filemap_fdatawait_range(mapping, start, end);
if (err)
werr = err;
cond_resched();
start = end + 1;
}
if (err)
werr = err;
return werr;
}
int btrfs_write_and_wait_marked_extents(struct btrfs_root *root,
struct extent_io_tree *dirty_pages, int mark)
{
int ret;
int ret2;
ret = btrfs_write_marked_extents(root, dirty_pages, mark);
ret2 = btrfs_wait_marked_extents(root, dirty_pages, mark);
if (ret)
return ret;
if (ret2)
return ret2;
return 0;
}
int btrfs_write_and_wait_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
if (!trans || !trans->transaction) {
struct inode *btree_inode;
btree_inode = root->fs_info->btree_inode;
return filemap_write_and_wait(btree_inode->i_mapping);
}
return btrfs_write_and_wait_marked_extents(root,
&trans->transaction->dirty_pages,
EXTENT_DIRTY);
}
static int update_cowonly_root(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
int ret;
u64 old_root_bytenr;
u64 old_root_used;
struct btrfs_root *tree_root = root->fs_info->tree_root;
old_root_used = btrfs_root_used(&root->root_item);
btrfs_write_dirty_block_groups(trans, root);
while (1) {
old_root_bytenr = btrfs_root_bytenr(&root->root_item);
if (old_root_bytenr == root->node->start &&
old_root_used == btrfs_root_used(&root->root_item))
break;
btrfs_set_root_node(&root->root_item, root->node);
ret = btrfs_update_root(trans, tree_root,
&root->root_key,
&root->root_item);
if (ret)
return ret;
old_root_used = btrfs_root_used(&root->root_item);
ret = btrfs_write_dirty_block_groups(trans, root);
if (ret)
return ret;
}
if (root != root->fs_info->extent_root)
switch_commit_root(root);
return 0;
}
static noinline int commit_cowonly_roots(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct list_head *next;
struct extent_buffer *eb;
int ret;
ret = btrfs_run_delayed_refs(trans, root, (unsigned long)-1);
if (ret)
return ret;
eb = btrfs_lock_root_node(fs_info->tree_root);
ret = btrfs_cow_block(trans, fs_info->tree_root, eb, NULL,
0, &eb);
btrfs_tree_unlock(eb);
free_extent_buffer(eb);
if (ret)
return ret;
ret = btrfs_run_delayed_refs(trans, root, (unsigned long)-1);
if (ret)
return ret;
ret = btrfs_run_dev_stats(trans, root->fs_info);
BUG_ON(ret);
ret = btrfs_run_qgroups(trans, root->fs_info);
BUG_ON(ret);
ret = btrfs_run_delayed_refs(trans, root, (unsigned long)-1);
BUG_ON(ret);
while (!list_empty(&fs_info->dirty_cowonly_roots)) {
next = fs_info->dirty_cowonly_roots.next;
list_del_init(next);
root = list_entry(next, struct btrfs_root, dirty_list);
ret = update_cowonly_root(trans, root);
if (ret)
return ret;
}
down_write(&fs_info->extent_commit_sem);
switch_commit_root(fs_info->extent_root);
up_write(&fs_info->extent_commit_sem);
return 0;
}
int btrfs_add_dead_root(struct btrfs_root *root)
{
spin_lock(&root->fs_info->trans_lock);
list_add(&root->root_list, &root->fs_info->dead_roots);
spin_unlock(&root->fs_info->trans_lock);
return 0;
}
static noinline int commit_fs_roots(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
struct btrfs_root *gang[8];
struct btrfs_fs_info *fs_info = root->fs_info;
int i;
int ret;
int err = 0;
spin_lock(&fs_info->fs_roots_radix_lock);
while (1) {
ret = radix_tree_gang_lookup_tag(&fs_info->fs_roots_radix,
(void **)gang, 0,
ARRAY_SIZE(gang),
BTRFS_ROOT_TRANS_TAG);
if (ret == 0)
break;
for (i = 0; i < ret; i++) {
root = gang[i];
radix_tree_tag_clear(&fs_info->fs_roots_radix,
(unsigned long)root->root_key.objectid,
BTRFS_ROOT_TRANS_TAG);
spin_unlock(&fs_info->fs_roots_radix_lock);
btrfs_free_log(trans, root);
btrfs_update_reloc_root(trans, root);
btrfs_orphan_commit_root(trans, root);
btrfs_save_ino_cache(root, trans);
root->force_cow = 0;
smp_wmb();
if (root->commit_root != root->node) {
mutex_lock(&root->fs_commit_mutex);
switch_commit_root(root);
btrfs_unpin_free_ino(root);
mutex_unlock(&root->fs_commit_mutex);
btrfs_set_root_node(&root->root_item,
root->node);
}
err = btrfs_update_root(trans, fs_info->tree_root,
&root->root_key,
&root->root_item);
spin_lock(&fs_info->fs_roots_radix_lock);
if (err)
break;
}
}
spin_unlock(&fs_info->fs_roots_radix_lock);
return err;
}
int btrfs_defrag_root(struct btrfs_root *root, int cacheonly)
{
struct btrfs_fs_info *info = root->fs_info;
struct btrfs_trans_handle *trans;
int ret;
unsigned long nr;
if (xchg(&root->defrag_running, 1))
return 0;
while (1) {
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans))
return PTR_ERR(trans);
ret = btrfs_defrag_leaves(trans, root, cacheonly);
nr = trans->blocks_used;
btrfs_end_transaction(trans, root);
btrfs_btree_balance_dirty(info->tree_root, nr);
cond_resched();
if (btrfs_fs_closing(root->fs_info) || ret != -EAGAIN)
break;
}
root->defrag_running = 0;
return ret;
}
static noinline int create_pending_snapshot(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info,
struct btrfs_pending_snapshot *pending)
{
struct btrfs_key key;
struct btrfs_root_item *new_root_item;
struct btrfs_root *tree_root = fs_info->tree_root;
struct btrfs_root *root = pending->root;
struct btrfs_root *parent_root;
struct btrfs_block_rsv *rsv;
struct inode *parent_inode;
struct dentry *parent;
struct dentry *dentry;
struct extent_buffer *tmp;
struct extent_buffer *old;
struct timespec cur_time = CURRENT_TIME;
int ret;
u64 to_reserve = 0;
u64 index = 0;
u64 objectid;
u64 root_flags;
uuid_le new_uuid;
rsv = trans->block_rsv;
new_root_item = kmalloc(sizeof(*new_root_item), GFP_NOFS);
if (!new_root_item) {
ret = pending->error = -ENOMEM;
goto fail;
}
ret = btrfs_find_free_objectid(tree_root, &objectid);
if (ret) {
pending->error = ret;
goto fail;
}
btrfs_reloc_pre_snapshot(trans, pending, &to_reserve);
if (to_reserve > 0) {
ret = btrfs_block_rsv_add_noflush(root, &pending->block_rsv,
to_reserve);
if (ret) {
pending->error = ret;
goto fail;
}
}
ret = btrfs_qgroup_inherit(trans, fs_info, root->root_key.objectid,
objectid, pending->inherit);
kfree(pending->inherit);
if (ret) {
pending->error = ret;
goto fail;
}
key.objectid = objectid;
key.offset = (u64)-1;
key.type = BTRFS_ROOT_ITEM_KEY;
trans->block_rsv = &pending->block_rsv;
dentry = pending->dentry;
parent = dget_parent(dentry);
parent_inode = parent->d_inode;
parent_root = BTRFS_I(parent_inode)->root;
record_root_in_trans(trans, parent_root);
ret = btrfs_set_inode_index(parent_inode, &index);
BUG_ON(ret);
ret = btrfs_insert_dir_item(trans, parent_root,
dentry->d_name.name, dentry->d_name.len,
parent_inode, &key,
BTRFS_FT_DIR, index);
if (ret == -EEXIST) {
pending->error = -EEXIST;
dput(parent);
goto fail;
} else if (ret) {
goto abort_trans_dput;
}
btrfs_i_size_write(parent_inode, parent_inode->i_size +
dentry->d_name.len * 2);
parent_inode->i_mtime = parent_inode->i_ctime = CURRENT_TIME;
ret = btrfs_update_inode(trans, parent_root, parent_inode);
if (ret)
goto abort_trans_dput;
ret = btrfs_run_delayed_items(trans, root);
if (ret) {
dput(parent);
goto fail;
}
record_root_in_trans(trans, root);
btrfs_set_root_last_snapshot(&root->root_item, trans->transid);
memcpy(new_root_item, &root->root_item, sizeof(*new_root_item));
btrfs_check_and_init_root_item(new_root_item);
root_flags = btrfs_root_flags(new_root_item);
if (pending->readonly)
root_flags |= BTRFS_ROOT_SUBVOL_RDONLY;
else
root_flags &= ~BTRFS_ROOT_SUBVOL_RDONLY;
btrfs_set_root_flags(new_root_item, root_flags);
btrfs_set_root_generation_v2(new_root_item,
trans->transid);
uuid_le_gen(&new_uuid);
memcpy(new_root_item->uuid, new_uuid.b, BTRFS_UUID_SIZE);
memcpy(new_root_item->parent_uuid, root->root_item.uuid,
BTRFS_UUID_SIZE);
new_root_item->otime.sec = cpu_to_le64(cur_time.tv_sec);
new_root_item->otime.nsec = cpu_to_le32(cur_time.tv_nsec);
btrfs_set_root_otransid(new_root_item, trans->transid);
memset(&new_root_item->stime, 0, sizeof(new_root_item->stime));
memset(&new_root_item->rtime, 0, sizeof(new_root_item->rtime));
btrfs_set_root_stransid(new_root_item, 0);
btrfs_set_root_rtransid(new_root_item, 0);
old = btrfs_lock_root_node(root);
ret = btrfs_cow_block(trans, root, old, NULL, 0, &old);
if (ret) {
btrfs_tree_unlock(old);
free_extent_buffer(old);
goto abort_trans_dput;
}
btrfs_set_lock_blocking(old);
ret = btrfs_copy_root(trans, root, old, &tmp, objectid);
btrfs_tree_unlock(old);
free_extent_buffer(old);
if (ret)
goto abort_trans_dput;
root->force_cow = 1;
smp_wmb();
btrfs_set_root_node(new_root_item, tmp);
key.offset = trans->transid;
ret = btrfs_insert_root(trans, tree_root, &key, new_root_item);
btrfs_tree_unlock(tmp);
free_extent_buffer(tmp);
if (ret)
goto abort_trans_dput;
ret = btrfs_add_root_ref(trans, tree_root, objectid,
parent_root->root_key.objectid,
btrfs_ino(parent_inode), index,
dentry->d_name.name, dentry->d_name.len);
dput(parent);
if (ret)
goto fail;
key.offset = (u64)-1;
pending->snap = btrfs_read_fs_root_no_name(root->fs_info, &key);
if (IS_ERR(pending->snap)) {
ret = PTR_ERR(pending->snap);
goto abort_trans;
}
ret = btrfs_reloc_post_snapshot(trans, pending);
if (ret)
goto abort_trans;
ret = 0;
fail:
kfree(new_root_item);
trans->block_rsv = rsv;
btrfs_block_rsv_release(root, &pending->block_rsv, (u64)-1);
return ret;
abort_trans_dput:
dput(parent);
abort_trans:
btrfs_abort_transaction(trans, root, ret);
goto fail;
}
static noinline int create_pending_snapshots(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info)
{
struct btrfs_pending_snapshot *pending;
struct list_head *head = &trans->transaction->pending_snapshots;
list_for_each_entry(pending, head, list)
create_pending_snapshot(trans, fs_info, pending);
return 0;
}
static void update_super_roots(struct btrfs_root *root)
{
struct btrfs_root_item *root_item;
struct btrfs_super_block *super;
super = root->fs_info->super_copy;
root_item = &root->fs_info->chunk_root->root_item;
super->chunk_root = root_item->bytenr;
super->chunk_root_generation = root_item->generation;
super->chunk_root_level = root_item->level;
root_item = &root->fs_info->tree_root->root_item;
super->root = root_item->bytenr;
super->generation = root_item->generation;
super->root_level = root_item->level;
if (btrfs_test_opt(root, SPACE_CACHE))
super->cache_generation = root_item->generation;
}
int btrfs_transaction_in_commit(struct btrfs_fs_info *info)
{
int ret = 0;
spin_lock(&info->trans_lock);
if (info->running_transaction)
ret = info->running_transaction->in_commit;
spin_unlock(&info->trans_lock);
return ret;
}
int btrfs_transaction_blocked(struct btrfs_fs_info *info)
{
int ret = 0;
spin_lock(&info->trans_lock);
if (info->running_transaction)
ret = info->running_transaction->blocked;
spin_unlock(&info->trans_lock);
return ret;
}
static void wait_current_trans_commit_start(struct btrfs_root *root,
struct btrfs_transaction *trans)
{
wait_event(root->fs_info->transaction_blocked_wait, trans->in_commit);
}
static void wait_current_trans_commit_start_and_unblock(struct btrfs_root *root,
struct btrfs_transaction *trans)
{
wait_event(root->fs_info->transaction_wait,
trans->commit_done || (trans->in_commit && !trans->blocked));
}
static void do_async_commit(struct work_struct *work)
{
struct btrfs_async_commit *ac =
container_of(work, struct btrfs_async_commit, work.work);
btrfs_commit_transaction(ac->newtrans, ac->root);
kfree(ac);
}
int btrfs_commit_transaction_async(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
int wait_for_unblock)
{
struct btrfs_async_commit *ac;
struct btrfs_transaction *cur_trans;
ac = kmalloc(sizeof(*ac), GFP_NOFS);
if (!ac)
return -ENOMEM;
INIT_DELAYED_WORK(&ac->work, do_async_commit);
ac->root = root;
ac->newtrans = btrfs_join_transaction(root);
if (IS_ERR(ac->newtrans)) {
int err = PTR_ERR(ac->newtrans);
kfree(ac);
return err;
}
cur_trans = trans->transaction;
atomic_inc(&cur_trans->use_count);
btrfs_end_transaction(trans, root);
schedule_delayed_work(&ac->work, 0);
if (wait_for_unblock)
wait_current_trans_commit_start_and_unblock(root, cur_trans);
else
wait_current_trans_commit_start(root, cur_trans);
if (current->journal_info == trans)
current->journal_info = NULL;
put_transaction(cur_trans);
return 0;
}
static void cleanup_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root, int err)
{
struct btrfs_transaction *cur_trans = trans->transaction;
WARN_ON(trans->use_count > 1);
btrfs_abort_transaction(trans, root, err);
spin_lock(&root->fs_info->trans_lock);
list_del_init(&cur_trans->list);
if (cur_trans == root->fs_info->running_transaction) {
root->fs_info->running_transaction = NULL;
root->fs_info->trans_no_join = 0;
}
spin_unlock(&root->fs_info->trans_lock);
btrfs_cleanup_one_transaction(trans->transaction, root);
put_transaction(cur_trans);
put_transaction(cur_trans);
trace_btrfs_transaction_commit(root);
btrfs_scrub_continue(root);
if (current->journal_info == trans)
current->journal_info = NULL;
kmem_cache_free(btrfs_trans_handle_cachep, trans);
}
int btrfs_commit_transaction(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
unsigned long joined = 0;
struct btrfs_transaction *cur_trans = trans->transaction;
struct btrfs_transaction *prev_trans = NULL;
DEFINE_WAIT(wait);
int ret = -EIO;
int should_grow = 0;
unsigned long now = get_seconds();
int flush_on_commit = btrfs_test_opt(root, FLUSHONCOMMIT);
btrfs_run_ordered_operations(root, 0);
if (cur_trans->aborted)
goto cleanup_transaction;
ret = btrfs_run_delayed_refs(trans, root, 0);
if (ret)
goto cleanup_transaction;
btrfs_trans_release_metadata(trans, root);
trans->block_rsv = NULL;
cur_trans = trans->transaction;
cur_trans->delayed_refs.flushing = 1;
ret = btrfs_run_delayed_refs(trans, root, 0);
if (ret)
goto cleanup_transaction;
spin_lock(&cur_trans->commit_lock);
if (cur_trans->in_commit) {
spin_unlock(&cur_trans->commit_lock);
atomic_inc(&cur_trans->use_count);
ret = btrfs_end_transaction(trans, root);
wait_for_commit(root, cur_trans);
put_transaction(cur_trans);
return ret;
}
trans->transaction->in_commit = 1;
trans->transaction->blocked = 1;
spin_unlock(&cur_trans->commit_lock);
wake_up(&root->fs_info->transaction_blocked_wait);
spin_lock(&root->fs_info->trans_lock);
if (cur_trans->list.prev != &root->fs_info->trans_list) {
prev_trans = list_entry(cur_trans->list.prev,
struct btrfs_transaction, list);
if (!prev_trans->commit_done) {
atomic_inc(&prev_trans->use_count);
spin_unlock(&root->fs_info->trans_lock);
wait_for_commit(root, prev_trans);
put_transaction(prev_trans);
} else {
spin_unlock(&root->fs_info->trans_lock);
}
} else {
spin_unlock(&root->fs_info->trans_lock);
}
if (!btrfs_test_opt(root, SSD) &&
(now < cur_trans->start_time || now - cur_trans->start_time < 1))
should_grow = 1;
do {
int snap_pending = 0;
joined = cur_trans->num_joined;
if (!list_empty(&trans->transaction->pending_snapshots))
snap_pending = 1;
WARN_ON(cur_trans != trans->transaction);
if (flush_on_commit || snap_pending) {
btrfs_start_delalloc_inodes(root, 1);
btrfs_wait_ordered_extents(root, 0, 1);
}
ret = btrfs_run_delayed_items(trans, root);
if (ret)
goto cleanup_transaction;
btrfs_delayed_refs_qgroup_accounting(trans, root->fs_info);
btrfs_run_ordered_operations(root, 1);
prepare_to_wait(&cur_trans->writer_wait, &wait,
TASK_UNINTERRUPTIBLE);
if (atomic_read(&cur_trans->num_writers) > 1)
schedule_timeout(MAX_SCHEDULE_TIMEOUT);
else if (should_grow)
schedule_timeout(1);
finish_wait(&cur_trans->writer_wait, &wait);
} while (atomic_read(&cur_trans->num_writers) > 1 ||
(should_grow && cur_trans->num_joined != joined));
spin_lock(&root->fs_info->trans_lock);
root->fs_info->trans_no_join = 1;
spin_unlock(&root->fs_info->trans_lock);
wait_event(cur_trans->writer_wait,
atomic_read(&cur_trans->num_writers) == 1);
mutex_lock(&root->fs_info->reloc_mutex);
ret = btrfs_run_delayed_items(trans, root);
if (ret) {
mutex_unlock(&root->fs_info->reloc_mutex);
goto cleanup_transaction;
}
ret = create_pending_snapshots(trans, root->fs_info);
if (ret) {
mutex_unlock(&root->fs_info->reloc_mutex);
goto cleanup_transaction;
}
ret = btrfs_run_delayed_refs(trans, root, (unsigned long)-1);
if (ret) {
mutex_unlock(&root->fs_info->reloc_mutex);
goto cleanup_transaction;
}
btrfs_assert_delayed_root_empty(root);
WARN_ON(cur_trans != trans->transaction);
btrfs_scrub_pause(root);
mutex_lock(&root->fs_info->tree_log_mutex);
ret = commit_fs_roots(trans, root);
if (ret) {
mutex_unlock(&root->fs_info->tree_log_mutex);
mutex_unlock(&root->fs_info->reloc_mutex);
goto cleanup_transaction;
}
btrfs_free_log_root_tree(trans, root->fs_info);
ret = commit_cowonly_roots(trans, root);
if (ret) {
mutex_unlock(&root->fs_info->tree_log_mutex);
mutex_unlock(&root->fs_info->reloc_mutex);
goto cleanup_transaction;
}
btrfs_prepare_extent_commit(trans, root);
cur_trans = root->fs_info->running_transaction;
btrfs_set_root_node(&root->fs_info->tree_root->root_item,
root->fs_info->tree_root->node);
switch_commit_root(root->fs_info->tree_root);
btrfs_set_root_node(&root->fs_info->chunk_root->root_item,
root->fs_info->chunk_root->node);
switch_commit_root(root->fs_info->chunk_root);
assert_qgroups_uptodate(trans);
update_super_roots(root);
if (!root->fs_info->log_root_recovering) {
btrfs_set_super_log_root(root->fs_info->super_copy, 0);
btrfs_set_super_log_root_level(root->fs_info->super_copy, 0);
}
memcpy(root->fs_info->super_for_commit, root->fs_info->super_copy,
sizeof(*root->fs_info->super_copy));
trans->transaction->blocked = 0;
spin_lock(&root->fs_info->trans_lock);
root->fs_info->running_transaction = NULL;
root->fs_info->trans_no_join = 0;
spin_unlock(&root->fs_info->trans_lock);
mutex_unlock(&root->fs_info->reloc_mutex);
wake_up(&root->fs_info->transaction_wait);
ret = btrfs_write_and_wait_transaction(trans, root);
if (ret) {
btrfs_error(root->fs_info, ret,
"Error while writing out transaction.");
mutex_unlock(&root->fs_info->tree_log_mutex);
goto cleanup_transaction;
}
ret = write_ctree_super(trans, root, 0);
if (ret) {
mutex_unlock(&root->fs_info->tree_log_mutex);
goto cleanup_transaction;
}
mutex_unlock(&root->fs_info->tree_log_mutex);
btrfs_finish_extent_commit(trans, root);
cur_trans->commit_done = 1;
root->fs_info->last_trans_committed = cur_trans->transid;
wake_up(&cur_trans->commit_wait);
spin_lock(&root->fs_info->trans_lock);
list_del_init(&cur_trans->list);
spin_unlock(&root->fs_info->trans_lock);
put_transaction(cur_trans);
put_transaction(cur_trans);
sb_end_intwrite(root->fs_info->sb);
trace_btrfs_transaction_commit(root);
btrfs_scrub_continue(root);
if (current->journal_info == trans)
current->journal_info = NULL;
kmem_cache_free(btrfs_trans_handle_cachep, trans);
if (current != root->fs_info->transaction_kthread)
btrfs_run_delayed_iputs(root);
return ret;
cleanup_transaction:
btrfs_trans_release_metadata(trans, root);
trans->block_rsv = NULL;
btrfs_printk(root->fs_info, "Skipping commit of aborted transaction.\n");
if (current->journal_info == trans)
current->journal_info = NULL;
cleanup_transaction(trans, root, ret);
return ret;
}
int btrfs_clean_old_snapshots(struct btrfs_root *root)
{
LIST_HEAD(list);
struct btrfs_fs_info *fs_info = root->fs_info;
spin_lock(&fs_info->trans_lock);
list_splice_init(&fs_info->dead_roots, &list);
spin_unlock(&fs_info->trans_lock);
while (!list_empty(&list)) {
int ret;
root = list_entry(list.next, struct btrfs_root, root_list);
list_del(&root->root_list);
btrfs_kill_all_delayed_nodes(root);
if (btrfs_header_backref_rev(root->node) <
BTRFS_MIXED_BACKREF_REV)
ret = btrfs_drop_snapshot(root, NULL, 0, 0);
else
ret =btrfs_drop_snapshot(root, NULL, 1, 0);
BUG_ON(ret < 0);
}
return 0;
}
