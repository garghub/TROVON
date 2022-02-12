struct btrfs_path *btrfs_alloc_path(void)
{
return kmem_cache_zalloc(btrfs_path_cachep, GFP_NOFS);
}
noinline void btrfs_set_path_blocking(struct btrfs_path *p)
{
int i;
for (i = 0; i < BTRFS_MAX_LEVEL; i++) {
if (!p->nodes[i] || !p->locks[i])
continue;
btrfs_set_lock_blocking_rw(p->nodes[i], p->locks[i]);
if (p->locks[i] == BTRFS_READ_LOCK)
p->locks[i] = BTRFS_READ_LOCK_BLOCKING;
else if (p->locks[i] == BTRFS_WRITE_LOCK)
p->locks[i] = BTRFS_WRITE_LOCK_BLOCKING;
}
}
noinline void btrfs_clear_path_blocking(struct btrfs_path *p,
struct extent_buffer *held, int held_rw)
{
int i;
if (held) {
btrfs_set_lock_blocking_rw(held, held_rw);
if (held_rw == BTRFS_WRITE_LOCK)
held_rw = BTRFS_WRITE_LOCK_BLOCKING;
else if (held_rw == BTRFS_READ_LOCK)
held_rw = BTRFS_READ_LOCK_BLOCKING;
}
btrfs_set_path_blocking(p);
for (i = BTRFS_MAX_LEVEL - 1; i >= 0; i--) {
if (p->nodes[i] && p->locks[i]) {
btrfs_clear_lock_blocking_rw(p->nodes[i], p->locks[i]);
if (p->locks[i] == BTRFS_WRITE_LOCK_BLOCKING)
p->locks[i] = BTRFS_WRITE_LOCK;
else if (p->locks[i] == BTRFS_READ_LOCK_BLOCKING)
p->locks[i] = BTRFS_READ_LOCK;
}
}
if (held)
btrfs_clear_lock_blocking_rw(held, held_rw);
}
void btrfs_free_path(struct btrfs_path *p)
{
if (!p)
return;
btrfs_release_path(p);
kmem_cache_free(btrfs_path_cachep, p);
}
noinline void btrfs_release_path(struct btrfs_path *p)
{
int i;
for (i = 0; i < BTRFS_MAX_LEVEL; i++) {
p->slots[i] = 0;
if (!p->nodes[i])
continue;
if (p->locks[i]) {
btrfs_tree_unlock_rw(p->nodes[i], p->locks[i]);
p->locks[i] = 0;
}
free_extent_buffer(p->nodes[i]);
p->nodes[i] = NULL;
}
}
struct extent_buffer *btrfs_root_node(struct btrfs_root *root)
{
struct extent_buffer *eb;
while (1) {
rcu_read_lock();
eb = rcu_dereference(root->node);
if (atomic_inc_not_zero(&eb->refs)) {
rcu_read_unlock();
break;
}
rcu_read_unlock();
synchronize_rcu();
}
return eb;
}
struct extent_buffer *btrfs_lock_root_node(struct btrfs_root *root)
{
struct extent_buffer *eb;
while (1) {
eb = btrfs_root_node(root);
btrfs_tree_lock(eb);
if (eb == root->node)
break;
btrfs_tree_unlock(eb);
free_extent_buffer(eb);
}
return eb;
}
static struct extent_buffer *btrfs_read_lock_root_node(struct btrfs_root *root)
{
struct extent_buffer *eb;
while (1) {
eb = btrfs_root_node(root);
btrfs_tree_read_lock(eb);
if (eb == root->node)
break;
btrfs_tree_read_unlock(eb);
free_extent_buffer(eb);
}
return eb;
}
static void add_root_to_dirty_list(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
if (test_bit(BTRFS_ROOT_DIRTY, &root->state) ||
!test_bit(BTRFS_ROOT_TRACK_DIRTY, &root->state))
return;
spin_lock(&fs_info->trans_lock);
if (!test_and_set_bit(BTRFS_ROOT_DIRTY, &root->state)) {
if (root->objectid == BTRFS_EXTENT_TREE_OBJECTID)
list_move_tail(&root->dirty_list,
&fs_info->dirty_cowonly_roots);
else
list_move(&root->dirty_list,
&fs_info->dirty_cowonly_roots);
}
spin_unlock(&fs_info->trans_lock);
}
int btrfs_copy_root(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct extent_buffer *buf,
struct extent_buffer **cow_ret, u64 new_root_objectid)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *cow;
int ret = 0;
int level;
struct btrfs_disk_key disk_key;
WARN_ON(test_bit(BTRFS_ROOT_REF_COWS, &root->state) &&
trans->transid != fs_info->running_transaction->transid);
WARN_ON(test_bit(BTRFS_ROOT_REF_COWS, &root->state) &&
trans->transid != root->last_trans);
level = btrfs_header_level(buf);
if (level == 0)
btrfs_item_key(buf, &disk_key, 0);
else
btrfs_node_key(buf, &disk_key, 0);
cow = btrfs_alloc_tree_block(trans, root, 0, new_root_objectid,
&disk_key, level, buf->start, 0);
if (IS_ERR(cow))
return PTR_ERR(cow);
copy_extent_buffer_full(cow, buf);
btrfs_set_header_bytenr(cow, cow->start);
btrfs_set_header_generation(cow, trans->transid);
btrfs_set_header_backref_rev(cow, BTRFS_MIXED_BACKREF_REV);
btrfs_clear_header_flag(cow, BTRFS_HEADER_FLAG_WRITTEN |
BTRFS_HEADER_FLAG_RELOC);
if (new_root_objectid == BTRFS_TREE_RELOC_OBJECTID)
btrfs_set_header_flag(cow, BTRFS_HEADER_FLAG_RELOC);
else
btrfs_set_header_owner(cow, new_root_objectid);
write_extent_buffer_fsid(cow, fs_info->fsid);
WARN_ON(btrfs_header_generation(buf) > trans->transid);
if (new_root_objectid == BTRFS_TREE_RELOC_OBJECTID)
ret = btrfs_inc_ref(trans, root, cow, 1);
else
ret = btrfs_inc_ref(trans, root, cow, 0);
if (ret)
return ret;
btrfs_mark_buffer_dirty(cow);
*cow_ret = cow;
return 0;
}
static inline void tree_mod_log_read_lock(struct btrfs_fs_info *fs_info)
{
read_lock(&fs_info->tree_mod_log_lock);
}
static inline void tree_mod_log_read_unlock(struct btrfs_fs_info *fs_info)
{
read_unlock(&fs_info->tree_mod_log_lock);
}
static inline void tree_mod_log_write_lock(struct btrfs_fs_info *fs_info)
{
write_lock(&fs_info->tree_mod_log_lock);
}
static inline void tree_mod_log_write_unlock(struct btrfs_fs_info *fs_info)
{
write_unlock(&fs_info->tree_mod_log_lock);
}
static inline u64 btrfs_inc_tree_mod_seq(struct btrfs_fs_info *fs_info)
{
return atomic64_inc_return(&fs_info->tree_mod_seq);
}
u64 btrfs_get_tree_mod_seq(struct btrfs_fs_info *fs_info,
struct seq_list *elem)
{
tree_mod_log_write_lock(fs_info);
spin_lock(&fs_info->tree_mod_seq_lock);
if (!elem->seq) {
elem->seq = btrfs_inc_tree_mod_seq(fs_info);
list_add_tail(&elem->list, &fs_info->tree_mod_seq_list);
}
spin_unlock(&fs_info->tree_mod_seq_lock);
tree_mod_log_write_unlock(fs_info);
return elem->seq;
}
void btrfs_put_tree_mod_seq(struct btrfs_fs_info *fs_info,
struct seq_list *elem)
{
struct rb_root *tm_root;
struct rb_node *node;
struct rb_node *next;
struct seq_list *cur_elem;
struct tree_mod_elem *tm;
u64 min_seq = (u64)-1;
u64 seq_putting = elem->seq;
if (!seq_putting)
return;
spin_lock(&fs_info->tree_mod_seq_lock);
list_del(&elem->list);
elem->seq = 0;
list_for_each_entry(cur_elem, &fs_info->tree_mod_seq_list, list) {
if (cur_elem->seq < min_seq) {
if (seq_putting > cur_elem->seq) {
spin_unlock(&fs_info->tree_mod_seq_lock);
return;
}
min_seq = cur_elem->seq;
}
}
spin_unlock(&fs_info->tree_mod_seq_lock);
tree_mod_log_write_lock(fs_info);
tm_root = &fs_info->tree_mod_log;
for (node = rb_first(tm_root); node; node = next) {
next = rb_next(node);
tm = rb_entry(node, struct tree_mod_elem, node);
if (tm->seq > min_seq)
continue;
rb_erase(node, tm_root);
kfree(tm);
}
tree_mod_log_write_unlock(fs_info);
}
static noinline int
__tree_mod_log_insert(struct btrfs_fs_info *fs_info, struct tree_mod_elem *tm)
{
struct rb_root *tm_root;
struct rb_node **new;
struct rb_node *parent = NULL;
struct tree_mod_elem *cur;
tm->seq = btrfs_inc_tree_mod_seq(fs_info);
tm_root = &fs_info->tree_mod_log;
new = &tm_root->rb_node;
while (*new) {
cur = rb_entry(*new, struct tree_mod_elem, node);
parent = *new;
if (cur->logical < tm->logical)
new = &((*new)->rb_left);
else if (cur->logical > tm->logical)
new = &((*new)->rb_right);
else if (cur->seq < tm->seq)
new = &((*new)->rb_left);
else if (cur->seq > tm->seq)
new = &((*new)->rb_right);
else
return -EEXIST;
}
rb_link_node(&tm->node, parent, new);
rb_insert_color(&tm->node, tm_root);
return 0;
}
static inline int tree_mod_dont_log(struct btrfs_fs_info *fs_info,
struct extent_buffer *eb) {
smp_mb();
if (list_empty(&(fs_info)->tree_mod_seq_list))
return 1;
if (eb && btrfs_header_level(eb) == 0)
return 1;
tree_mod_log_write_lock(fs_info);
if (list_empty(&(fs_info)->tree_mod_seq_list)) {
tree_mod_log_write_unlock(fs_info);
return 1;
}
return 0;
}
static inline int tree_mod_need_log(const struct btrfs_fs_info *fs_info,
struct extent_buffer *eb)
{
smp_mb();
if (list_empty(&(fs_info)->tree_mod_seq_list))
return 0;
if (eb && btrfs_header_level(eb) == 0)
return 0;
return 1;
}
static struct tree_mod_elem *
alloc_tree_mod_elem(struct extent_buffer *eb, int slot,
enum mod_log_op op, gfp_t flags)
{
struct tree_mod_elem *tm;
tm = kzalloc(sizeof(*tm), flags);
if (!tm)
return NULL;
tm->logical = eb->start;
if (op != MOD_LOG_KEY_ADD) {
btrfs_node_key(eb, &tm->key, slot);
tm->blockptr = btrfs_node_blockptr(eb, slot);
}
tm->op = op;
tm->slot = slot;
tm->generation = btrfs_node_ptr_generation(eb, slot);
RB_CLEAR_NODE(&tm->node);
return tm;
}
static noinline int
tree_mod_log_insert_key(struct btrfs_fs_info *fs_info,
struct extent_buffer *eb, int slot,
enum mod_log_op op, gfp_t flags)
{
struct tree_mod_elem *tm;
int ret;
if (!tree_mod_need_log(fs_info, eb))
return 0;
tm = alloc_tree_mod_elem(eb, slot, op, flags);
if (!tm)
return -ENOMEM;
if (tree_mod_dont_log(fs_info, eb)) {
kfree(tm);
return 0;
}
ret = __tree_mod_log_insert(fs_info, tm);
tree_mod_log_write_unlock(fs_info);
if (ret)
kfree(tm);
return ret;
}
static noinline int
tree_mod_log_insert_move(struct btrfs_fs_info *fs_info,
struct extent_buffer *eb, int dst_slot, int src_slot,
int nr_items)
{
struct tree_mod_elem *tm = NULL;
struct tree_mod_elem **tm_list = NULL;
int ret = 0;
int i;
int locked = 0;
if (!tree_mod_need_log(fs_info, eb))
return 0;
tm_list = kcalloc(nr_items, sizeof(struct tree_mod_elem *), GFP_NOFS);
if (!tm_list)
return -ENOMEM;
tm = kzalloc(sizeof(*tm), GFP_NOFS);
if (!tm) {
ret = -ENOMEM;
goto free_tms;
}
tm->logical = eb->start;
tm->slot = src_slot;
tm->move.dst_slot = dst_slot;
tm->move.nr_items = nr_items;
tm->op = MOD_LOG_MOVE_KEYS;
for (i = 0; i + dst_slot < src_slot && i < nr_items; i++) {
tm_list[i] = alloc_tree_mod_elem(eb, i + dst_slot,
MOD_LOG_KEY_REMOVE_WHILE_MOVING, GFP_NOFS);
if (!tm_list[i]) {
ret = -ENOMEM;
goto free_tms;
}
}
if (tree_mod_dont_log(fs_info, eb))
goto free_tms;
locked = 1;
for (i = 0; i + dst_slot < src_slot && i < nr_items; i++) {
ret = __tree_mod_log_insert(fs_info, tm_list[i]);
if (ret)
goto free_tms;
}
ret = __tree_mod_log_insert(fs_info, tm);
if (ret)
goto free_tms;
tree_mod_log_write_unlock(fs_info);
kfree(tm_list);
return 0;
free_tms:
for (i = 0; i < nr_items; i++) {
if (tm_list[i] && !RB_EMPTY_NODE(&tm_list[i]->node))
rb_erase(&tm_list[i]->node, &fs_info->tree_mod_log);
kfree(tm_list[i]);
}
if (locked)
tree_mod_log_write_unlock(fs_info);
kfree(tm_list);
kfree(tm);
return ret;
}
static inline int
__tree_mod_log_free_eb(struct btrfs_fs_info *fs_info,
struct tree_mod_elem **tm_list,
int nritems)
{
int i, j;
int ret;
for (i = nritems - 1; i >= 0; i--) {
ret = __tree_mod_log_insert(fs_info, tm_list[i]);
if (ret) {
for (j = nritems - 1; j > i; j--)
rb_erase(&tm_list[j]->node,
&fs_info->tree_mod_log);
return ret;
}
}
return 0;
}
static noinline int
tree_mod_log_insert_root(struct btrfs_fs_info *fs_info,
struct extent_buffer *old_root,
struct extent_buffer *new_root,
int log_removal)
{
struct tree_mod_elem *tm = NULL;
struct tree_mod_elem **tm_list = NULL;
int nritems = 0;
int ret = 0;
int i;
if (!tree_mod_need_log(fs_info, NULL))
return 0;
if (log_removal && btrfs_header_level(old_root) > 0) {
nritems = btrfs_header_nritems(old_root);
tm_list = kcalloc(nritems, sizeof(struct tree_mod_elem *),
GFP_NOFS);
if (!tm_list) {
ret = -ENOMEM;
goto free_tms;
}
for (i = 0; i < nritems; i++) {
tm_list[i] = alloc_tree_mod_elem(old_root, i,
MOD_LOG_KEY_REMOVE_WHILE_FREEING, GFP_NOFS);
if (!tm_list[i]) {
ret = -ENOMEM;
goto free_tms;
}
}
}
tm = kzalloc(sizeof(*tm), GFP_NOFS);
if (!tm) {
ret = -ENOMEM;
goto free_tms;
}
tm->logical = new_root->start;
tm->old_root.logical = old_root->start;
tm->old_root.level = btrfs_header_level(old_root);
tm->generation = btrfs_header_generation(old_root);
tm->op = MOD_LOG_ROOT_REPLACE;
if (tree_mod_dont_log(fs_info, NULL))
goto free_tms;
if (tm_list)
ret = __tree_mod_log_free_eb(fs_info, tm_list, nritems);
if (!ret)
ret = __tree_mod_log_insert(fs_info, tm);
tree_mod_log_write_unlock(fs_info);
if (ret)
goto free_tms;
kfree(tm_list);
return ret;
free_tms:
if (tm_list) {
for (i = 0; i < nritems; i++)
kfree(tm_list[i]);
kfree(tm_list);
}
kfree(tm);
return ret;
}
static struct tree_mod_elem *
__tree_mod_log_search(struct btrfs_fs_info *fs_info, u64 start, u64 min_seq,
int smallest)
{
struct rb_root *tm_root;
struct rb_node *node;
struct tree_mod_elem *cur = NULL;
struct tree_mod_elem *found = NULL;
tree_mod_log_read_lock(fs_info);
tm_root = &fs_info->tree_mod_log;
node = tm_root->rb_node;
while (node) {
cur = rb_entry(node, struct tree_mod_elem, node);
if (cur->logical < start) {
node = node->rb_left;
} else if (cur->logical > start) {
node = node->rb_right;
} else if (cur->seq < min_seq) {
node = node->rb_left;
} else if (!smallest) {
if (found)
BUG_ON(found->seq > cur->seq);
found = cur;
node = node->rb_left;
} else if (cur->seq > min_seq) {
if (found)
BUG_ON(found->seq < cur->seq);
found = cur;
node = node->rb_right;
} else {
found = cur;
break;
}
}
tree_mod_log_read_unlock(fs_info);
return found;
}
static struct tree_mod_elem *
tree_mod_log_search_oldest(struct btrfs_fs_info *fs_info, u64 start,
u64 min_seq)
{
return __tree_mod_log_search(fs_info, start, min_seq, 1);
}
static struct tree_mod_elem *
tree_mod_log_search(struct btrfs_fs_info *fs_info, u64 start, u64 min_seq)
{
return __tree_mod_log_search(fs_info, start, min_seq, 0);
}
static noinline int
tree_mod_log_eb_copy(struct btrfs_fs_info *fs_info, struct extent_buffer *dst,
struct extent_buffer *src, unsigned long dst_offset,
unsigned long src_offset, int nr_items)
{
int ret = 0;
struct tree_mod_elem **tm_list = NULL;
struct tree_mod_elem **tm_list_add, **tm_list_rem;
int i;
int locked = 0;
if (!tree_mod_need_log(fs_info, NULL))
return 0;
if (btrfs_header_level(dst) == 0 && btrfs_header_level(src) == 0)
return 0;
tm_list = kcalloc(nr_items * 2, sizeof(struct tree_mod_elem *),
GFP_NOFS);
if (!tm_list)
return -ENOMEM;
tm_list_add = tm_list;
tm_list_rem = tm_list + nr_items;
for (i = 0; i < nr_items; i++) {
tm_list_rem[i] = alloc_tree_mod_elem(src, i + src_offset,
MOD_LOG_KEY_REMOVE, GFP_NOFS);
if (!tm_list_rem[i]) {
ret = -ENOMEM;
goto free_tms;
}
tm_list_add[i] = alloc_tree_mod_elem(dst, i + dst_offset,
MOD_LOG_KEY_ADD, GFP_NOFS);
if (!tm_list_add[i]) {
ret = -ENOMEM;
goto free_tms;
}
}
if (tree_mod_dont_log(fs_info, NULL))
goto free_tms;
locked = 1;
for (i = 0; i < nr_items; i++) {
ret = __tree_mod_log_insert(fs_info, tm_list_rem[i]);
if (ret)
goto free_tms;
ret = __tree_mod_log_insert(fs_info, tm_list_add[i]);
if (ret)
goto free_tms;
}
tree_mod_log_write_unlock(fs_info);
kfree(tm_list);
return 0;
free_tms:
for (i = 0; i < nr_items * 2; i++) {
if (tm_list[i] && !RB_EMPTY_NODE(&tm_list[i]->node))
rb_erase(&tm_list[i]->node, &fs_info->tree_mod_log);
kfree(tm_list[i]);
}
if (locked)
tree_mod_log_write_unlock(fs_info);
kfree(tm_list);
return ret;
}
static inline void
tree_mod_log_eb_move(struct btrfs_fs_info *fs_info, struct extent_buffer *dst,
int dst_offset, int src_offset, int nr_items)
{
int ret;
ret = tree_mod_log_insert_move(fs_info, dst, dst_offset, src_offset,
nr_items);
BUG_ON(ret < 0);
}
static noinline void
tree_mod_log_set_node_key(struct btrfs_fs_info *fs_info,
struct extent_buffer *eb, int slot, int atomic)
{
int ret;
ret = tree_mod_log_insert_key(fs_info, eb, slot,
MOD_LOG_KEY_REPLACE,
atomic ? GFP_ATOMIC : GFP_NOFS);
BUG_ON(ret < 0);
}
static noinline int
tree_mod_log_free_eb(struct btrfs_fs_info *fs_info, struct extent_buffer *eb)
{
struct tree_mod_elem **tm_list = NULL;
int nritems = 0;
int i;
int ret = 0;
if (btrfs_header_level(eb) == 0)
return 0;
if (!tree_mod_need_log(fs_info, NULL))
return 0;
nritems = btrfs_header_nritems(eb);
tm_list = kcalloc(nritems, sizeof(struct tree_mod_elem *), GFP_NOFS);
if (!tm_list)
return -ENOMEM;
for (i = 0; i < nritems; i++) {
tm_list[i] = alloc_tree_mod_elem(eb, i,
MOD_LOG_KEY_REMOVE_WHILE_FREEING, GFP_NOFS);
if (!tm_list[i]) {
ret = -ENOMEM;
goto free_tms;
}
}
if (tree_mod_dont_log(fs_info, eb))
goto free_tms;
ret = __tree_mod_log_free_eb(fs_info, tm_list, nritems);
tree_mod_log_write_unlock(fs_info);
if (ret)
goto free_tms;
kfree(tm_list);
return 0;
free_tms:
for (i = 0; i < nritems; i++)
kfree(tm_list[i]);
kfree(tm_list);
return ret;
}
static noinline void
tree_mod_log_set_root_pointer(struct btrfs_root *root,
struct extent_buffer *new_root_node,
int log_removal)
{
int ret;
ret = tree_mod_log_insert_root(root->fs_info, root->node,
new_root_node, log_removal);
BUG_ON(ret < 0);
}
int btrfs_block_can_be_shared(struct btrfs_root *root,
struct extent_buffer *buf)
{
if (test_bit(BTRFS_ROOT_REF_COWS, &root->state) &&
buf != root->node && buf != root->commit_root &&
(btrfs_header_generation(buf) <=
btrfs_root_last_snapshot(&root->root_item) ||
btrfs_header_flag(buf, BTRFS_HEADER_FLAG_RELOC)))
return 1;
#ifdef BTRFS_COMPAT_EXTENT_TREE_V0
if (test_bit(BTRFS_ROOT_REF_COWS, &root->state) &&
btrfs_header_backref_rev(buf) < BTRFS_MIXED_BACKREF_REV)
return 1;
#endif
return 0;
}
static noinline int update_ref_for_cow(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct extent_buffer *buf,
struct extent_buffer *cow,
int *last_ref)
{
struct btrfs_fs_info *fs_info = root->fs_info;
u64 refs;
u64 owner;
u64 flags;
u64 new_flags = 0;
int ret;
if (btrfs_block_can_be_shared(root, buf)) {
ret = btrfs_lookup_extent_info(trans, fs_info, buf->start,
btrfs_header_level(buf), 1,
&refs, &flags);
if (ret)
return ret;
if (refs == 0) {
ret = -EROFS;
btrfs_handle_fs_error(fs_info, ret, NULL);
return ret;
}
} else {
refs = 1;
if (root->root_key.objectid == BTRFS_TREE_RELOC_OBJECTID ||
btrfs_header_backref_rev(buf) < BTRFS_MIXED_BACKREF_REV)
flags = BTRFS_BLOCK_FLAG_FULL_BACKREF;
else
flags = 0;
}
owner = btrfs_header_owner(buf);
BUG_ON(owner == BTRFS_TREE_RELOC_OBJECTID &&
!(flags & BTRFS_BLOCK_FLAG_FULL_BACKREF));
if (refs > 1) {
if ((owner == root->root_key.objectid ||
root->root_key.objectid == BTRFS_TREE_RELOC_OBJECTID) &&
!(flags & BTRFS_BLOCK_FLAG_FULL_BACKREF)) {
ret = btrfs_inc_ref(trans, root, buf, 1);
BUG_ON(ret);
if (root->root_key.objectid ==
BTRFS_TREE_RELOC_OBJECTID) {
ret = btrfs_dec_ref(trans, root, buf, 0);
BUG_ON(ret);
ret = btrfs_inc_ref(trans, root, cow, 1);
BUG_ON(ret);
}
new_flags |= BTRFS_BLOCK_FLAG_FULL_BACKREF;
} else {
if (root->root_key.objectid ==
BTRFS_TREE_RELOC_OBJECTID)
ret = btrfs_inc_ref(trans, root, cow, 1);
else
ret = btrfs_inc_ref(trans, root, cow, 0);
BUG_ON(ret);
}
if (new_flags != 0) {
int level = btrfs_header_level(buf);
ret = btrfs_set_disk_extent_flags(trans, fs_info,
buf->start,
buf->len,
new_flags, level, 0);
if (ret)
return ret;
}
} else {
if (flags & BTRFS_BLOCK_FLAG_FULL_BACKREF) {
if (root->root_key.objectid ==
BTRFS_TREE_RELOC_OBJECTID)
ret = btrfs_inc_ref(trans, root, cow, 1);
else
ret = btrfs_inc_ref(trans, root, cow, 0);
BUG_ON(ret);
ret = btrfs_dec_ref(trans, root, buf, 1);
BUG_ON(ret);
}
clean_tree_block(fs_info, buf);
*last_ref = 1;
}
return 0;
}
static noinline int __btrfs_cow_block(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct extent_buffer *buf,
struct extent_buffer *parent, int parent_slot,
struct extent_buffer **cow_ret,
u64 search_start, u64 empty_size)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct btrfs_disk_key disk_key;
struct extent_buffer *cow;
int level, ret;
int last_ref = 0;
int unlock_orig = 0;
u64 parent_start = 0;
if (*cow_ret == buf)
unlock_orig = 1;
btrfs_assert_tree_locked(buf);
WARN_ON(test_bit(BTRFS_ROOT_REF_COWS, &root->state) &&
trans->transid != fs_info->running_transaction->transid);
WARN_ON(test_bit(BTRFS_ROOT_REF_COWS, &root->state) &&
trans->transid != root->last_trans);
level = btrfs_header_level(buf);
if (level == 0)
btrfs_item_key(buf, &disk_key, 0);
else
btrfs_node_key(buf, &disk_key, 0);
if ((root->root_key.objectid == BTRFS_TREE_RELOC_OBJECTID) && parent)
parent_start = parent->start;
cow = btrfs_alloc_tree_block(trans, root, parent_start,
root->root_key.objectid, &disk_key, level,
search_start, empty_size);
if (IS_ERR(cow))
return PTR_ERR(cow);
copy_extent_buffer_full(cow, buf);
btrfs_set_header_bytenr(cow, cow->start);
btrfs_set_header_generation(cow, trans->transid);
btrfs_set_header_backref_rev(cow, BTRFS_MIXED_BACKREF_REV);
btrfs_clear_header_flag(cow, BTRFS_HEADER_FLAG_WRITTEN |
BTRFS_HEADER_FLAG_RELOC);
if (root->root_key.objectid == BTRFS_TREE_RELOC_OBJECTID)
btrfs_set_header_flag(cow, BTRFS_HEADER_FLAG_RELOC);
else
btrfs_set_header_owner(cow, root->root_key.objectid);
write_extent_buffer_fsid(cow, fs_info->fsid);
ret = update_ref_for_cow(trans, root, buf, cow, &last_ref);
if (ret) {
btrfs_abort_transaction(trans, ret);
return ret;
}
if (test_bit(BTRFS_ROOT_REF_COWS, &root->state)) {
ret = btrfs_reloc_cow_block(trans, root, buf, cow);
if (ret) {
btrfs_abort_transaction(trans, ret);
return ret;
}
}
if (buf == root->node) {
WARN_ON(parent && parent != buf);
if (root->root_key.objectid == BTRFS_TREE_RELOC_OBJECTID ||
btrfs_header_backref_rev(buf) < BTRFS_MIXED_BACKREF_REV)
parent_start = buf->start;
extent_buffer_get(cow);
tree_mod_log_set_root_pointer(root, cow, 1);
rcu_assign_pointer(root->node, cow);
btrfs_free_tree_block(trans, root, buf, parent_start,
last_ref);
free_extent_buffer(buf);
add_root_to_dirty_list(root);
} else {
WARN_ON(trans->transid != btrfs_header_generation(parent));
tree_mod_log_insert_key(fs_info, parent, parent_slot,
MOD_LOG_KEY_REPLACE, GFP_NOFS);
btrfs_set_node_blockptr(parent, parent_slot,
cow->start);
btrfs_set_node_ptr_generation(parent, parent_slot,
trans->transid);
btrfs_mark_buffer_dirty(parent);
if (last_ref) {
ret = tree_mod_log_free_eb(fs_info, buf);
if (ret) {
btrfs_abort_transaction(trans, ret);
return ret;
}
}
btrfs_free_tree_block(trans, root, buf, parent_start,
last_ref);
}
if (unlock_orig)
btrfs_tree_unlock(buf);
free_extent_buffer_stale(buf);
btrfs_mark_buffer_dirty(cow);
*cow_ret = cow;
return 0;
}
static struct tree_mod_elem *
__tree_mod_log_oldest_root(struct btrfs_fs_info *fs_info,
struct extent_buffer *eb_root, u64 time_seq)
{
struct tree_mod_elem *tm;
struct tree_mod_elem *found = NULL;
u64 root_logical = eb_root->start;
int looped = 0;
if (!time_seq)
return NULL;
while (1) {
tm = tree_mod_log_search_oldest(fs_info, root_logical,
time_seq);
if (!looped && !tm)
return NULL;
if (!tm)
break;
if (tm->op != MOD_LOG_ROOT_REPLACE)
break;
found = tm;
root_logical = tm->old_root.logical;
looped = 1;
}
if (!found)
found = tm;
return found;
}
static void
__tree_mod_log_rewind(struct btrfs_fs_info *fs_info, struct extent_buffer *eb,
u64 time_seq, struct tree_mod_elem *first_tm)
{
u32 n;
struct rb_node *next;
struct tree_mod_elem *tm = first_tm;
unsigned long o_dst;
unsigned long o_src;
unsigned long p_size = sizeof(struct btrfs_key_ptr);
n = btrfs_header_nritems(eb);
tree_mod_log_read_lock(fs_info);
while (tm && tm->seq >= time_seq) {
switch (tm->op) {
case MOD_LOG_KEY_REMOVE_WHILE_FREEING:
BUG_ON(tm->slot < n);
case MOD_LOG_KEY_REMOVE_WHILE_MOVING:
case MOD_LOG_KEY_REMOVE:
btrfs_set_node_key(eb, &tm->key, tm->slot);
btrfs_set_node_blockptr(eb, tm->slot, tm->blockptr);
btrfs_set_node_ptr_generation(eb, tm->slot,
tm->generation);
n++;
break;
case MOD_LOG_KEY_REPLACE:
BUG_ON(tm->slot >= n);
btrfs_set_node_key(eb, &tm->key, tm->slot);
btrfs_set_node_blockptr(eb, tm->slot, tm->blockptr);
btrfs_set_node_ptr_generation(eb, tm->slot,
tm->generation);
break;
case MOD_LOG_KEY_ADD:
n--;
break;
case MOD_LOG_MOVE_KEYS:
o_dst = btrfs_node_key_ptr_offset(tm->slot);
o_src = btrfs_node_key_ptr_offset(tm->move.dst_slot);
memmove_extent_buffer(eb, o_dst, o_src,
tm->move.nr_items * p_size);
break;
case MOD_LOG_ROOT_REPLACE:
break;
}
next = rb_next(&tm->node);
if (!next)
break;
tm = rb_entry(next, struct tree_mod_elem, node);
if (tm->logical != first_tm->logical)
break;
}
tree_mod_log_read_unlock(fs_info);
btrfs_set_header_nritems(eb, n);
}
static struct extent_buffer *
tree_mod_log_rewind(struct btrfs_fs_info *fs_info, struct btrfs_path *path,
struct extent_buffer *eb, u64 time_seq)
{
struct extent_buffer *eb_rewin;
struct tree_mod_elem *tm;
if (!time_seq)
return eb;
if (btrfs_header_level(eb) == 0)
return eb;
tm = tree_mod_log_search(fs_info, eb->start, time_seq);
if (!tm)
return eb;
btrfs_set_path_blocking(path);
btrfs_set_lock_blocking_rw(eb, BTRFS_READ_LOCK);
if (tm->op == MOD_LOG_KEY_REMOVE_WHILE_FREEING) {
BUG_ON(tm->slot != 0);
eb_rewin = alloc_dummy_extent_buffer(fs_info, eb->start);
if (!eb_rewin) {
btrfs_tree_read_unlock_blocking(eb);
free_extent_buffer(eb);
return NULL;
}
btrfs_set_header_bytenr(eb_rewin, eb->start);
btrfs_set_header_backref_rev(eb_rewin,
btrfs_header_backref_rev(eb));
btrfs_set_header_owner(eb_rewin, btrfs_header_owner(eb));
btrfs_set_header_level(eb_rewin, btrfs_header_level(eb));
} else {
eb_rewin = btrfs_clone_extent_buffer(eb);
if (!eb_rewin) {
btrfs_tree_read_unlock_blocking(eb);
free_extent_buffer(eb);
return NULL;
}
}
btrfs_clear_path_blocking(path, NULL, BTRFS_READ_LOCK);
btrfs_tree_read_unlock_blocking(eb);
free_extent_buffer(eb);
extent_buffer_get(eb_rewin);
btrfs_tree_read_lock(eb_rewin);
__tree_mod_log_rewind(fs_info, eb_rewin, time_seq, tm);
WARN_ON(btrfs_header_nritems(eb_rewin) >
BTRFS_NODEPTRS_PER_BLOCK(fs_info));
return eb_rewin;
}
static inline struct extent_buffer *
get_old_root(struct btrfs_root *root, u64 time_seq)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct tree_mod_elem *tm;
struct extent_buffer *eb = NULL;
struct extent_buffer *eb_root;
struct extent_buffer *old;
struct tree_mod_root *old_root = NULL;
u64 old_generation = 0;
u64 logical;
eb_root = btrfs_read_lock_root_node(root);
tm = __tree_mod_log_oldest_root(fs_info, eb_root, time_seq);
if (!tm)
return eb_root;
if (tm->op == MOD_LOG_ROOT_REPLACE) {
old_root = &tm->old_root;
old_generation = tm->generation;
logical = old_root->logical;
} else {
logical = eb_root->start;
}
tm = tree_mod_log_search(fs_info, logical, time_seq);
if (old_root && tm && tm->op != MOD_LOG_KEY_REMOVE_WHILE_FREEING) {
btrfs_tree_read_unlock(eb_root);
free_extent_buffer(eb_root);
old = read_tree_block(fs_info, logical, 0);
if (WARN_ON(IS_ERR(old) || !extent_buffer_uptodate(old))) {
if (!IS_ERR(old))
free_extent_buffer(old);
btrfs_warn(fs_info,
"failed to read tree block %llu from get_old_root",
logical);
} else {
eb = btrfs_clone_extent_buffer(old);
free_extent_buffer(old);
}
} else if (old_root) {
btrfs_tree_read_unlock(eb_root);
free_extent_buffer(eb_root);
eb = alloc_dummy_extent_buffer(fs_info, logical);
} else {
btrfs_set_lock_blocking_rw(eb_root, BTRFS_READ_LOCK);
eb = btrfs_clone_extent_buffer(eb_root);
btrfs_tree_read_unlock_blocking(eb_root);
free_extent_buffer(eb_root);
}
if (!eb)
return NULL;
extent_buffer_get(eb);
btrfs_tree_read_lock(eb);
if (old_root) {
btrfs_set_header_bytenr(eb, eb->start);
btrfs_set_header_backref_rev(eb, BTRFS_MIXED_BACKREF_REV);
btrfs_set_header_owner(eb, btrfs_header_owner(eb_root));
btrfs_set_header_level(eb, old_root->level);
btrfs_set_header_generation(eb, old_generation);
}
if (tm)
__tree_mod_log_rewind(fs_info, eb, time_seq, tm);
else
WARN_ON(btrfs_header_level(eb) != 0);
WARN_ON(btrfs_header_nritems(eb) > BTRFS_NODEPTRS_PER_BLOCK(fs_info));
return eb;
}
int btrfs_old_root_level(struct btrfs_root *root, u64 time_seq)
{
struct tree_mod_elem *tm;
int level;
struct extent_buffer *eb_root = btrfs_root_node(root);
tm = __tree_mod_log_oldest_root(root->fs_info, eb_root, time_seq);
if (tm && tm->op == MOD_LOG_ROOT_REPLACE) {
level = tm->old_root.level;
} else {
level = btrfs_header_level(eb_root);
}
free_extent_buffer(eb_root);
return level;
}
static inline int should_cow_block(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct extent_buffer *buf)
{
if (btrfs_is_testing(root->fs_info))
return 0;
smp_rmb();
if (btrfs_header_generation(buf) == trans->transid &&
!btrfs_header_flag(buf, BTRFS_HEADER_FLAG_WRITTEN) &&
!(root->root_key.objectid != BTRFS_TREE_RELOC_OBJECTID &&
btrfs_header_flag(buf, BTRFS_HEADER_FLAG_RELOC)) &&
!test_bit(BTRFS_ROOT_FORCE_COW, &root->state))
return 0;
return 1;
}
noinline int btrfs_cow_block(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct extent_buffer *buf,
struct extent_buffer *parent, int parent_slot,
struct extent_buffer **cow_ret)
{
struct btrfs_fs_info *fs_info = root->fs_info;
u64 search_start;
int ret;
if (trans->transaction != fs_info->running_transaction)
WARN(1, KERN_CRIT "trans %llu running %llu\n",
trans->transid,
fs_info->running_transaction->transid);
if (trans->transid != fs_info->generation)
WARN(1, KERN_CRIT "trans %llu running %llu\n",
trans->transid, fs_info->generation);
if (!should_cow_block(trans, root, buf)) {
trans->dirty = true;
*cow_ret = buf;
return 0;
}
search_start = buf->start & ~((u64)SZ_1G - 1);
if (parent)
btrfs_set_lock_blocking(parent);
btrfs_set_lock_blocking(buf);
ret = __btrfs_cow_block(trans, root, buf, parent,
parent_slot, cow_ret, search_start, 0);
trace_btrfs_cow_block(root, buf, *cow_ret);
return ret;
}
static int close_blocks(u64 blocknr, u64 other, u32 blocksize)
{
if (blocknr < other && other - (blocknr + blocksize) < 32768)
return 1;
if (blocknr > other && blocknr - (other + blocksize) < 32768)
return 1;
return 0;
}
static int comp_keys(const struct btrfs_disk_key *disk,
const struct btrfs_key *k2)
{
struct btrfs_key k1;
btrfs_disk_key_to_cpu(&k1, disk);
return btrfs_comp_cpu_keys(&k1, k2);
}
int btrfs_comp_cpu_keys(const struct btrfs_key *k1, const struct btrfs_key *k2)
{
if (k1->objectid > k2->objectid)
return 1;
if (k1->objectid < k2->objectid)
return -1;
if (k1->type > k2->type)
return 1;
if (k1->type < k2->type)
return -1;
if (k1->offset > k2->offset)
return 1;
if (k1->offset < k2->offset)
return -1;
return 0;
}
int btrfs_realloc_node(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct extent_buffer *parent,
int start_slot, u64 *last_ret,
struct btrfs_key *progress)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *cur;
u64 blocknr;
u64 gen;
u64 search_start = *last_ret;
u64 last_block = 0;
u64 other;
u32 parent_nritems;
int end_slot;
int i;
int err = 0;
int parent_level;
int uptodate;
u32 blocksize;
int progress_passed = 0;
struct btrfs_disk_key disk_key;
parent_level = btrfs_header_level(parent);
WARN_ON(trans->transaction != fs_info->running_transaction);
WARN_ON(trans->transid != fs_info->generation);
parent_nritems = btrfs_header_nritems(parent);
blocksize = fs_info->nodesize;
end_slot = parent_nritems - 1;
if (parent_nritems <= 1)
return 0;
btrfs_set_lock_blocking(parent);
for (i = start_slot; i <= end_slot; i++) {
int close = 1;
btrfs_node_key(parent, &disk_key, i);
if (!progress_passed && comp_keys(&disk_key, progress) < 0)
continue;
progress_passed = 1;
blocknr = btrfs_node_blockptr(parent, i);
gen = btrfs_node_ptr_generation(parent, i);
if (last_block == 0)
last_block = blocknr;
if (i > 0) {
other = btrfs_node_blockptr(parent, i - 1);
close = close_blocks(blocknr, other, blocksize);
}
if (!close && i < end_slot) {
other = btrfs_node_blockptr(parent, i + 1);
close = close_blocks(blocknr, other, blocksize);
}
if (close) {
last_block = blocknr;
continue;
}
cur = find_extent_buffer(fs_info, blocknr);
if (cur)
uptodate = btrfs_buffer_uptodate(cur, gen, 0);
else
uptodate = 0;
if (!cur || !uptodate) {
if (!cur) {
cur = read_tree_block(fs_info, blocknr, gen);
if (IS_ERR(cur)) {
return PTR_ERR(cur);
} else if (!extent_buffer_uptodate(cur)) {
free_extent_buffer(cur);
return -EIO;
}
} else if (!uptodate) {
err = btrfs_read_buffer(cur, gen);
if (err) {
free_extent_buffer(cur);
return err;
}
}
}
if (search_start == 0)
search_start = last_block;
btrfs_tree_lock(cur);
btrfs_set_lock_blocking(cur);
err = __btrfs_cow_block(trans, root, cur, parent, i,
&cur, search_start,
min(16 * blocksize,
(end_slot - i) * blocksize));
if (err) {
btrfs_tree_unlock(cur);
free_extent_buffer(cur);
break;
}
search_start = cur->start;
last_block = cur->start;
*last_ret = search_start;
btrfs_tree_unlock(cur);
free_extent_buffer(cur);
}
return err;
}
static noinline int generic_bin_search(struct extent_buffer *eb,
unsigned long p, int item_size,
const struct btrfs_key *key,
int max, int *slot)
{
int low = 0;
int high = max;
int mid;
int ret;
struct btrfs_disk_key *tmp = NULL;
struct btrfs_disk_key unaligned;
unsigned long offset;
char *kaddr = NULL;
unsigned long map_start = 0;
unsigned long map_len = 0;
int err;
if (low > high) {
btrfs_err(eb->fs_info,
"%s: low (%d) > high (%d) eb %llu owner %llu level %d",
__func__, low, high, eb->start,
btrfs_header_owner(eb), btrfs_header_level(eb));
return -EINVAL;
}
while (low < high) {
mid = (low + high) / 2;
offset = p + mid * item_size;
if (!kaddr || offset < map_start ||
(offset + sizeof(struct btrfs_disk_key)) >
map_start + map_len) {
err = map_private_extent_buffer(eb, offset,
sizeof(struct btrfs_disk_key),
&kaddr, &map_start, &map_len);
if (!err) {
tmp = (struct btrfs_disk_key *)(kaddr + offset -
map_start);
} else if (err == 1) {
read_extent_buffer(eb, &unaligned,
offset, sizeof(unaligned));
tmp = &unaligned;
} else {
return err;
}
} else {
tmp = (struct btrfs_disk_key *)(kaddr + offset -
map_start);
}
ret = comp_keys(tmp, key);
if (ret < 0)
low = mid + 1;
else if (ret > 0)
high = mid;
else {
*slot = mid;
return 0;
}
}
*slot = low;
return 1;
}
static int bin_search(struct extent_buffer *eb, const struct btrfs_key *key,
int level, int *slot)
{
if (level == 0)
return generic_bin_search(eb,
offsetof(struct btrfs_leaf, items),
sizeof(struct btrfs_item),
key, btrfs_header_nritems(eb),
slot);
else
return generic_bin_search(eb,
offsetof(struct btrfs_node, ptrs),
sizeof(struct btrfs_key_ptr),
key, btrfs_header_nritems(eb),
slot);
}
int btrfs_bin_search(struct extent_buffer *eb, const struct btrfs_key *key,
int level, int *slot)
{
return bin_search(eb, key, level, slot);
}
static void root_add_used(struct btrfs_root *root, u32 size)
{
spin_lock(&root->accounting_lock);
btrfs_set_root_used(&root->root_item,
btrfs_root_used(&root->root_item) + size);
spin_unlock(&root->accounting_lock);
}
static void root_sub_used(struct btrfs_root *root, u32 size)
{
spin_lock(&root->accounting_lock);
btrfs_set_root_used(&root->root_item,
btrfs_root_used(&root->root_item) - size);
spin_unlock(&root->accounting_lock);
}
noinline int balance_level(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int level)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *right = NULL;
struct extent_buffer *mid;
struct extent_buffer *left = NULL;
struct extent_buffer *parent = NULL;
int ret = 0;
int wret;
int pslot;
int orig_slot = path->slots[level];
u64 orig_ptr;
if (level == 0)
return 0;
mid = path->nodes[level];
WARN_ON(path->locks[level] != BTRFS_WRITE_LOCK &&
path->locks[level] != BTRFS_WRITE_LOCK_BLOCKING);
WARN_ON(btrfs_header_generation(mid) != trans->transid);
orig_ptr = btrfs_node_blockptr(mid, orig_slot);
if (level < BTRFS_MAX_LEVEL - 1) {
parent = path->nodes[level + 1];
pslot = path->slots[level + 1];
}
if (!parent) {
struct extent_buffer *child;
if (btrfs_header_nritems(mid) != 1)
return 0;
child = read_node_slot(fs_info, mid, 0);
if (IS_ERR(child)) {
ret = PTR_ERR(child);
btrfs_handle_fs_error(fs_info, ret, NULL);
goto enospc;
}
btrfs_tree_lock(child);
btrfs_set_lock_blocking(child);
ret = btrfs_cow_block(trans, root, child, mid, 0, &child);
if (ret) {
btrfs_tree_unlock(child);
free_extent_buffer(child);
goto enospc;
}
tree_mod_log_set_root_pointer(root, child, 1);
rcu_assign_pointer(root->node, child);
add_root_to_dirty_list(root);
btrfs_tree_unlock(child);
path->locks[level] = 0;
path->nodes[level] = NULL;
clean_tree_block(fs_info, mid);
btrfs_tree_unlock(mid);
free_extent_buffer(mid);
root_sub_used(root, mid->len);
btrfs_free_tree_block(trans, root, mid, 0, 1);
free_extent_buffer_stale(mid);
return 0;
}
if (btrfs_header_nritems(mid) >
BTRFS_NODEPTRS_PER_BLOCK(fs_info) / 4)
return 0;
left = read_node_slot(fs_info, parent, pslot - 1);
if (IS_ERR(left))
left = NULL;
if (left) {
btrfs_tree_lock(left);
btrfs_set_lock_blocking(left);
wret = btrfs_cow_block(trans, root, left,
parent, pslot - 1, &left);
if (wret) {
ret = wret;
goto enospc;
}
}
right = read_node_slot(fs_info, parent, pslot + 1);
if (IS_ERR(right))
right = NULL;
if (right) {
btrfs_tree_lock(right);
btrfs_set_lock_blocking(right);
wret = btrfs_cow_block(trans, root, right,
parent, pslot + 1, &right);
if (wret) {
ret = wret;
goto enospc;
}
}
if (left) {
orig_slot += btrfs_header_nritems(left);
wret = push_node_left(trans, fs_info, left, mid, 1);
if (wret < 0)
ret = wret;
}
if (right) {
wret = push_node_left(trans, fs_info, mid, right, 1);
if (wret < 0 && wret != -ENOSPC)
ret = wret;
if (btrfs_header_nritems(right) == 0) {
clean_tree_block(fs_info, right);
btrfs_tree_unlock(right);
del_ptr(root, path, level + 1, pslot + 1);
root_sub_used(root, right->len);
btrfs_free_tree_block(trans, root, right, 0, 1);
free_extent_buffer_stale(right);
right = NULL;
} else {
struct btrfs_disk_key right_key;
btrfs_node_key(right, &right_key, 0);
tree_mod_log_set_node_key(fs_info, parent,
pslot + 1, 0);
btrfs_set_node_key(parent, &right_key, pslot + 1);
btrfs_mark_buffer_dirty(parent);
}
}
if (btrfs_header_nritems(mid) == 1) {
if (!left) {
ret = -EROFS;
btrfs_handle_fs_error(fs_info, ret, NULL);
goto enospc;
}
wret = balance_node_right(trans, fs_info, mid, left);
if (wret < 0) {
ret = wret;
goto enospc;
}
if (wret == 1) {
wret = push_node_left(trans, fs_info, left, mid, 1);
if (wret < 0)
ret = wret;
}
BUG_ON(wret == 1);
}
if (btrfs_header_nritems(mid) == 0) {
clean_tree_block(fs_info, mid);
btrfs_tree_unlock(mid);
del_ptr(root, path, level + 1, pslot);
root_sub_used(root, mid->len);
btrfs_free_tree_block(trans, root, mid, 0, 1);
free_extent_buffer_stale(mid);
mid = NULL;
} else {
struct btrfs_disk_key mid_key;
btrfs_node_key(mid, &mid_key, 0);
tree_mod_log_set_node_key(fs_info, parent, pslot, 0);
btrfs_set_node_key(parent, &mid_key, pslot);
btrfs_mark_buffer_dirty(parent);
}
if (left) {
if (btrfs_header_nritems(left) > orig_slot) {
extent_buffer_get(left);
path->nodes[level] = left;
path->slots[level + 1] -= 1;
path->slots[level] = orig_slot;
if (mid) {
btrfs_tree_unlock(mid);
free_extent_buffer(mid);
}
} else {
orig_slot -= btrfs_header_nritems(left);
path->slots[level] = orig_slot;
}
}
if (orig_ptr !=
btrfs_node_blockptr(path->nodes[level], path->slots[level]))
BUG();
enospc:
if (right) {
btrfs_tree_unlock(right);
free_extent_buffer(right);
}
if (left) {
if (path->nodes[level] != left)
btrfs_tree_unlock(left);
free_extent_buffer(left);
}
return ret;
}
static noinline int push_nodes_for_insert(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int level)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *right = NULL;
struct extent_buffer *mid;
struct extent_buffer *left = NULL;
struct extent_buffer *parent = NULL;
int ret = 0;
int wret;
int pslot;
int orig_slot = path->slots[level];
if (level == 0)
return 1;
mid = path->nodes[level];
WARN_ON(btrfs_header_generation(mid) != trans->transid);
if (level < BTRFS_MAX_LEVEL - 1) {
parent = path->nodes[level + 1];
pslot = path->slots[level + 1];
}
if (!parent)
return 1;
left = read_node_slot(fs_info, parent, pslot - 1);
if (IS_ERR(left))
left = NULL;
if (left) {
u32 left_nr;
btrfs_tree_lock(left);
btrfs_set_lock_blocking(left);
left_nr = btrfs_header_nritems(left);
if (left_nr >= BTRFS_NODEPTRS_PER_BLOCK(fs_info) - 1) {
wret = 1;
} else {
ret = btrfs_cow_block(trans, root, left, parent,
pslot - 1, &left);
if (ret)
wret = 1;
else {
wret = push_node_left(trans, fs_info,
left, mid, 0);
}
}
if (wret < 0)
ret = wret;
if (wret == 0) {
struct btrfs_disk_key disk_key;
orig_slot += left_nr;
btrfs_node_key(mid, &disk_key, 0);
tree_mod_log_set_node_key(fs_info, parent, pslot, 0);
btrfs_set_node_key(parent, &disk_key, pslot);
btrfs_mark_buffer_dirty(parent);
if (btrfs_header_nritems(left) > orig_slot) {
path->nodes[level] = left;
path->slots[level + 1] -= 1;
path->slots[level] = orig_slot;
btrfs_tree_unlock(mid);
free_extent_buffer(mid);
} else {
orig_slot -=
btrfs_header_nritems(left);
path->slots[level] = orig_slot;
btrfs_tree_unlock(left);
free_extent_buffer(left);
}
return 0;
}
btrfs_tree_unlock(left);
free_extent_buffer(left);
}
right = read_node_slot(fs_info, parent, pslot + 1);
if (IS_ERR(right))
right = NULL;
if (right) {
u32 right_nr;
btrfs_tree_lock(right);
btrfs_set_lock_blocking(right);
right_nr = btrfs_header_nritems(right);
if (right_nr >= BTRFS_NODEPTRS_PER_BLOCK(fs_info) - 1) {
wret = 1;
} else {
ret = btrfs_cow_block(trans, root, right,
parent, pslot + 1,
&right);
if (ret)
wret = 1;
else {
wret = balance_node_right(trans, fs_info,
right, mid);
}
}
if (wret < 0)
ret = wret;
if (wret == 0) {
struct btrfs_disk_key disk_key;
btrfs_node_key(right, &disk_key, 0);
tree_mod_log_set_node_key(fs_info, parent,
pslot + 1, 0);
btrfs_set_node_key(parent, &disk_key, pslot + 1);
btrfs_mark_buffer_dirty(parent);
if (btrfs_header_nritems(mid) <= orig_slot) {
path->nodes[level] = right;
path->slots[level + 1] += 1;
path->slots[level] = orig_slot -
btrfs_header_nritems(mid);
btrfs_tree_unlock(mid);
free_extent_buffer(mid);
} else {
btrfs_tree_unlock(right);
free_extent_buffer(right);
}
return 0;
}
btrfs_tree_unlock(right);
free_extent_buffer(right);
}
return 1;
}
static void reada_for_search(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
int level, int slot, u64 objectid)
{
struct extent_buffer *node;
struct btrfs_disk_key disk_key;
u32 nritems;
u64 search;
u64 target;
u64 nread = 0;
struct extent_buffer *eb;
u32 nr;
u32 blocksize;
u32 nscan = 0;
if (level != 1)
return;
if (!path->nodes[level])
return;
node = path->nodes[level];
search = btrfs_node_blockptr(node, slot);
blocksize = fs_info->nodesize;
eb = find_extent_buffer(fs_info, search);
if (eb) {
free_extent_buffer(eb);
return;
}
target = search;
nritems = btrfs_header_nritems(node);
nr = slot;
while (1) {
if (path->reada == READA_BACK) {
if (nr == 0)
break;
nr--;
} else if (path->reada == READA_FORWARD) {
nr++;
if (nr >= nritems)
break;
}
if (path->reada == READA_BACK && objectid) {
btrfs_node_key(node, &disk_key, nr);
if (btrfs_disk_key_objectid(&disk_key) != objectid)
break;
}
search = btrfs_node_blockptr(node, nr);
if ((search <= target && target - search <= 65536) ||
(search > target && search - target <= 65536)) {
readahead_tree_block(fs_info, search);
nread += blocksize;
}
nscan++;
if ((nread > 65536 || nscan > 32))
break;
}
}
static noinline void reada_for_balance(struct btrfs_fs_info *fs_info,
struct btrfs_path *path, int level)
{
int slot;
int nritems;
struct extent_buffer *parent;
struct extent_buffer *eb;
u64 gen;
u64 block1 = 0;
u64 block2 = 0;
parent = path->nodes[level + 1];
if (!parent)
return;
nritems = btrfs_header_nritems(parent);
slot = path->slots[level + 1];
if (slot > 0) {
block1 = btrfs_node_blockptr(parent, slot - 1);
gen = btrfs_node_ptr_generation(parent, slot - 1);
eb = find_extent_buffer(fs_info, block1);
if (eb && btrfs_buffer_uptodate(eb, gen, 1) != 0)
block1 = 0;
free_extent_buffer(eb);
}
if (slot + 1 < nritems) {
block2 = btrfs_node_blockptr(parent, slot + 1);
gen = btrfs_node_ptr_generation(parent, slot + 1);
eb = find_extent_buffer(fs_info, block2);
if (eb && btrfs_buffer_uptodate(eb, gen, 1) != 0)
block2 = 0;
free_extent_buffer(eb);
}
if (block1)
readahead_tree_block(fs_info, block1);
if (block2)
readahead_tree_block(fs_info, block2);
}
static noinline void unlock_up(struct btrfs_path *path, int level,
int lowest_unlock, int min_write_lock_level,
int *write_lock_level)
{
int i;
int skip_level = level;
int no_skips = 0;
struct extent_buffer *t;
for (i = level; i < BTRFS_MAX_LEVEL; i++) {
if (!path->nodes[i])
break;
if (!path->locks[i])
break;
if (!no_skips && path->slots[i] == 0) {
skip_level = i + 1;
continue;
}
if (!no_skips && path->keep_locks) {
u32 nritems;
t = path->nodes[i];
nritems = btrfs_header_nritems(t);
if (nritems < 1 || path->slots[i] >= nritems - 1) {
skip_level = i + 1;
continue;
}
}
if (skip_level < i && i >= lowest_unlock)
no_skips = 1;
t = path->nodes[i];
if (i >= lowest_unlock && i > skip_level && path->locks[i]) {
btrfs_tree_unlock_rw(t, path->locks[i]);
path->locks[i] = 0;
if (write_lock_level &&
i > min_write_lock_level &&
i <= *write_lock_level) {
*write_lock_level = i - 1;
}
}
}
}
noinline void btrfs_unlock_up_safe(struct btrfs_path *path, int level)
{
int i;
if (path->keep_locks)
return;
for (i = level; i < BTRFS_MAX_LEVEL; i++) {
if (!path->nodes[i])
continue;
if (!path->locks[i])
continue;
btrfs_tree_unlock_rw(path->nodes[i], path->locks[i]);
path->locks[i] = 0;
}
}
static int
read_block_for_search(struct btrfs_root *root, struct btrfs_path *p,
struct extent_buffer **eb_ret, int level, int slot,
const struct btrfs_key *key)
{
struct btrfs_fs_info *fs_info = root->fs_info;
u64 blocknr;
u64 gen;
struct extent_buffer *b = *eb_ret;
struct extent_buffer *tmp;
int ret;
blocknr = btrfs_node_blockptr(b, slot);
gen = btrfs_node_ptr_generation(b, slot);
tmp = find_extent_buffer(fs_info, blocknr);
if (tmp) {
if (btrfs_buffer_uptodate(tmp, gen, 1) > 0) {
*eb_ret = tmp;
return 0;
}
btrfs_set_path_blocking(p);
ret = btrfs_read_buffer(tmp, gen);
if (!ret) {
*eb_ret = tmp;
return 0;
}
free_extent_buffer(tmp);
btrfs_release_path(p);
return -EIO;
}
btrfs_unlock_up_safe(p, level + 1);
btrfs_set_path_blocking(p);
free_extent_buffer(tmp);
if (p->reada != READA_NONE)
reada_for_search(fs_info, p, level, slot, key->objectid);
btrfs_release_path(p);
ret = -EAGAIN;
tmp = read_tree_block(fs_info, blocknr, 0);
if (!IS_ERR(tmp)) {
if (!btrfs_buffer_uptodate(tmp, 0, 0))
ret = -EIO;
free_extent_buffer(tmp);
} else {
ret = PTR_ERR(tmp);
}
return ret;
}
static int
setup_nodes_for_search(struct btrfs_trans_handle *trans,
struct btrfs_root *root, struct btrfs_path *p,
struct extent_buffer *b, int level, int ins_len,
int *write_lock_level)
{
struct btrfs_fs_info *fs_info = root->fs_info;
int ret;
if ((p->search_for_split || ins_len > 0) && btrfs_header_nritems(b) >=
BTRFS_NODEPTRS_PER_BLOCK(fs_info) - 3) {
int sret;
if (*write_lock_level < level + 1) {
*write_lock_level = level + 1;
btrfs_release_path(p);
goto again;
}
btrfs_set_path_blocking(p);
reada_for_balance(fs_info, p, level);
sret = split_node(trans, root, p, level);
btrfs_clear_path_blocking(p, NULL, 0);
BUG_ON(sret > 0);
if (sret) {
ret = sret;
goto done;
}
b = p->nodes[level];
} else if (ins_len < 0 && btrfs_header_nritems(b) <
BTRFS_NODEPTRS_PER_BLOCK(fs_info) / 2) {
int sret;
if (*write_lock_level < level + 1) {
*write_lock_level = level + 1;
btrfs_release_path(p);
goto again;
}
btrfs_set_path_blocking(p);
reada_for_balance(fs_info, p, level);
sret = balance_level(trans, root, p, level);
btrfs_clear_path_blocking(p, NULL, 0);
if (sret) {
ret = sret;
goto done;
}
b = p->nodes[level];
if (!b) {
btrfs_release_path(p);
goto again;
}
BUG_ON(btrfs_header_nritems(b) == 1);
}
return 0;
again:
ret = -EAGAIN;
done:
return ret;
}
static void key_search_validate(struct extent_buffer *b,
const struct btrfs_key *key,
int level)
{
#ifdef CONFIG_BTRFS_ASSERT
struct btrfs_disk_key disk_key;
btrfs_cpu_key_to_disk(&disk_key, key);
if (level == 0)
ASSERT(!memcmp_extent_buffer(b, &disk_key,
offsetof(struct btrfs_leaf, items[0].key),
sizeof(disk_key)));
else
ASSERT(!memcmp_extent_buffer(b, &disk_key,
offsetof(struct btrfs_node, ptrs[0].key),
sizeof(disk_key)));
#endif
}
static int key_search(struct extent_buffer *b, const struct btrfs_key *key,
int level, int *prev_cmp, int *slot)
{
if (*prev_cmp != 0) {
*prev_cmp = bin_search(b, key, level, slot);
return *prev_cmp;
}
key_search_validate(b, key, level);
*slot = 0;
return 0;
}
int btrfs_find_item(struct btrfs_root *fs_root, struct btrfs_path *path,
u64 iobjectid, u64 ioff, u8 key_type,
struct btrfs_key *found_key)
{
int ret;
struct btrfs_key key;
struct extent_buffer *eb;
ASSERT(path);
ASSERT(found_key);
key.type = key_type;
key.objectid = iobjectid;
key.offset = ioff;
ret = btrfs_search_slot(NULL, fs_root, &key, path, 0, 0);
if (ret < 0)
return ret;
eb = path->nodes[0];
if (ret && path->slots[0] >= btrfs_header_nritems(eb)) {
ret = btrfs_next_leaf(fs_root, path);
if (ret)
return ret;
eb = path->nodes[0];
}
btrfs_item_key_to_cpu(eb, found_key, path->slots[0]);
if (found_key->type != key.type ||
found_key->objectid != key.objectid)
return 1;
return 0;
}
int btrfs_search_slot(struct btrfs_trans_handle *trans, struct btrfs_root *root,
const struct btrfs_key *key, struct btrfs_path *p,
int ins_len, int cow)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *b;
int slot;
int ret;
int err;
int level;
int lowest_unlock = 1;
int root_lock;
int write_lock_level = 0;
u8 lowest_level = 0;
int min_write_lock_level;
int prev_cmp;
lowest_level = p->lowest_level;
WARN_ON(lowest_level && ins_len > 0);
WARN_ON(p->nodes[0] != NULL);
BUG_ON(!cow && ins_len);
if (ins_len < 0) {
lowest_unlock = 2;
write_lock_level = 2;
} else if (ins_len > 0) {
write_lock_level = 1;
}
if (!cow)
write_lock_level = -1;
if (cow && (p->keep_locks || p->lowest_level))
write_lock_level = BTRFS_MAX_LEVEL;
min_write_lock_level = write_lock_level;
again:
prev_cmp = -1;
root_lock = BTRFS_READ_LOCK;
level = 0;
if (p->search_commit_root) {
if (p->need_commit_sem)
down_read(&fs_info->commit_root_sem);
b = root->commit_root;
extent_buffer_get(b);
level = btrfs_header_level(b);
if (p->need_commit_sem)
up_read(&fs_info->commit_root_sem);
if (!p->skip_locking)
btrfs_tree_read_lock(b);
} else {
if (p->skip_locking) {
b = btrfs_root_node(root);
level = btrfs_header_level(b);
} else {
b = btrfs_read_lock_root_node(root);
level = btrfs_header_level(b);
if (level <= write_lock_level) {
btrfs_tree_read_unlock(b);
free_extent_buffer(b);
b = btrfs_lock_root_node(root);
root_lock = BTRFS_WRITE_LOCK;
level = btrfs_header_level(b);
}
}
}
p->nodes[level] = b;
if (!p->skip_locking)
p->locks[level] = root_lock;
while (b) {
level = btrfs_header_level(b);
if (cow) {
if (!should_cow_block(trans, root, b)) {
trans->dirty = true;
goto cow_done;
}
if (level > write_lock_level ||
(level + 1 > write_lock_level &&
level + 1 < BTRFS_MAX_LEVEL &&
p->nodes[level + 1])) {
write_lock_level = level + 1;
btrfs_release_path(p);
goto again;
}
btrfs_set_path_blocking(p);
err = btrfs_cow_block(trans, root, b,
p->nodes[level + 1],
p->slots[level + 1], &b);
if (err) {
ret = err;
goto done;
}
}
cow_done:
p->nodes[level] = b;
btrfs_clear_path_blocking(p, NULL, 0);
if (!ins_len && !p->keep_locks) {
int u = level + 1;
if (u < BTRFS_MAX_LEVEL && p->locks[u]) {
btrfs_tree_unlock_rw(p->nodes[u], p->locks[u]);
p->locks[u] = 0;
}
}
ret = key_search(b, key, level, &prev_cmp, &slot);
if (ret < 0)
goto done;
if (level != 0) {
int dec = 0;
if (ret && slot > 0) {
dec = 1;
slot -= 1;
}
p->slots[level] = slot;
err = setup_nodes_for_search(trans, root, p, b, level,
ins_len, &write_lock_level);
if (err == -EAGAIN)
goto again;
if (err) {
ret = err;
goto done;
}
b = p->nodes[level];
slot = p->slots[level];
if (slot == 0 && ins_len &&
write_lock_level < level + 1) {
write_lock_level = level + 1;
btrfs_release_path(p);
goto again;
}
unlock_up(p, level, lowest_unlock,
min_write_lock_level, &write_lock_level);
if (level == lowest_level) {
if (dec)
p->slots[level]++;
goto done;
}
err = read_block_for_search(root, p, &b, level,
slot, key);
if (err == -EAGAIN)
goto again;
if (err) {
ret = err;
goto done;
}
if (!p->skip_locking) {
level = btrfs_header_level(b);
if (level <= write_lock_level) {
err = btrfs_try_tree_write_lock(b);
if (!err) {
btrfs_set_path_blocking(p);
btrfs_tree_lock(b);
btrfs_clear_path_blocking(p, b,
BTRFS_WRITE_LOCK);
}
p->locks[level] = BTRFS_WRITE_LOCK;
} else {
err = btrfs_tree_read_lock_atomic(b);
if (!err) {
btrfs_set_path_blocking(p);
btrfs_tree_read_lock(b);
btrfs_clear_path_blocking(p, b,
BTRFS_READ_LOCK);
}
p->locks[level] = BTRFS_READ_LOCK;
}
p->nodes[level] = b;
}
} else {
p->slots[level] = slot;
if (ins_len > 0 &&
btrfs_leaf_free_space(fs_info, b) < ins_len) {
if (write_lock_level < 1) {
write_lock_level = 1;
btrfs_release_path(p);
goto again;
}
btrfs_set_path_blocking(p);
err = split_leaf(trans, root, key,
p, ins_len, ret == 0);
btrfs_clear_path_blocking(p, NULL, 0);
BUG_ON(err > 0);
if (err) {
ret = err;
goto done;
}
}
if (!p->search_for_split)
unlock_up(p, level, lowest_unlock,
min_write_lock_level, &write_lock_level);
goto done;
}
}
ret = 1;
done:
if (!p->leave_spinning)
btrfs_set_path_blocking(p);
if (ret < 0 && !p->skip_release_on_error)
btrfs_release_path(p);
return ret;
}
int btrfs_search_old_slot(struct btrfs_root *root, const struct btrfs_key *key,
struct btrfs_path *p, u64 time_seq)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *b;
int slot;
int ret;
int err;
int level;
int lowest_unlock = 1;
u8 lowest_level = 0;
int prev_cmp = -1;
lowest_level = p->lowest_level;
WARN_ON(p->nodes[0] != NULL);
if (p->search_commit_root) {
BUG_ON(time_seq);
return btrfs_search_slot(NULL, root, key, p, 0, 0);
}
again:
b = get_old_root(root, time_seq);
level = btrfs_header_level(b);
p->locks[level] = BTRFS_READ_LOCK;
while (b) {
level = btrfs_header_level(b);
p->nodes[level] = b;
btrfs_clear_path_blocking(p, NULL, 0);
btrfs_unlock_up_safe(p, level + 1);
prev_cmp = -1;
ret = key_search(b, key, level, &prev_cmp, &slot);
if (level != 0) {
int dec = 0;
if (ret && slot > 0) {
dec = 1;
slot -= 1;
}
p->slots[level] = slot;
unlock_up(p, level, lowest_unlock, 0, NULL);
if (level == lowest_level) {
if (dec)
p->slots[level]++;
goto done;
}
err = read_block_for_search(root, p, &b, level,
slot, key);
if (err == -EAGAIN)
goto again;
if (err) {
ret = err;
goto done;
}
level = btrfs_header_level(b);
err = btrfs_tree_read_lock_atomic(b);
if (!err) {
btrfs_set_path_blocking(p);
btrfs_tree_read_lock(b);
btrfs_clear_path_blocking(p, b,
BTRFS_READ_LOCK);
}
b = tree_mod_log_rewind(fs_info, p, b, time_seq);
if (!b) {
ret = -ENOMEM;
goto done;
}
p->locks[level] = BTRFS_READ_LOCK;
p->nodes[level] = b;
} else {
p->slots[level] = slot;
unlock_up(p, level, lowest_unlock, 0, NULL);
goto done;
}
}
ret = 1;
done:
if (!p->leave_spinning)
btrfs_set_path_blocking(p);
if (ret < 0)
btrfs_release_path(p);
return ret;
}
int btrfs_search_slot_for_read(struct btrfs_root *root,
const struct btrfs_key *key,
struct btrfs_path *p, int find_higher,
int return_any)
{
int ret;
struct extent_buffer *leaf;
again:
ret = btrfs_search_slot(NULL, root, key, p, 0, 0);
if (ret <= 0)
return ret;
leaf = p->nodes[0];
if (find_higher) {
if (p->slots[0] >= btrfs_header_nritems(leaf)) {
ret = btrfs_next_leaf(root, p);
if (ret <= 0)
return ret;
if (!return_any)
return 1;
return_any = 0;
find_higher = 0;
btrfs_release_path(p);
goto again;
}
} else {
if (p->slots[0] == 0) {
ret = btrfs_prev_leaf(root, p);
if (ret < 0)
return ret;
if (!ret) {
leaf = p->nodes[0];
if (p->slots[0] == btrfs_header_nritems(leaf))
p->slots[0]--;
return 0;
}
if (!return_any)
return 1;
return_any = 0;
find_higher = 1;
btrfs_release_path(p);
goto again;
} else {
--p->slots[0];
}
}
return 0;
}
static void fixup_low_keys(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
struct btrfs_disk_key *key, int level)
{
int i;
struct extent_buffer *t;
for (i = level; i < BTRFS_MAX_LEVEL; i++) {
int tslot = path->slots[i];
if (!path->nodes[i])
break;
t = path->nodes[i];
tree_mod_log_set_node_key(fs_info, t, tslot, 1);
btrfs_set_node_key(t, key, tslot);
btrfs_mark_buffer_dirty(path->nodes[i]);
if (tslot != 0)
break;
}
}
void btrfs_set_item_key_safe(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
const struct btrfs_key *new_key)
{
struct btrfs_disk_key disk_key;
struct extent_buffer *eb;
int slot;
eb = path->nodes[0];
slot = path->slots[0];
if (slot > 0) {
btrfs_item_key(eb, &disk_key, slot - 1);
BUG_ON(comp_keys(&disk_key, new_key) >= 0);
}
if (slot < btrfs_header_nritems(eb) - 1) {
btrfs_item_key(eb, &disk_key, slot + 1);
BUG_ON(comp_keys(&disk_key, new_key) <= 0);
}
btrfs_cpu_key_to_disk(&disk_key, new_key);
btrfs_set_item_key(eb, &disk_key, slot);
btrfs_mark_buffer_dirty(eb);
if (slot == 0)
fixup_low_keys(fs_info, path, &disk_key, 1);
}
static int push_node_left(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info,
struct extent_buffer *dst,
struct extent_buffer *src, int empty)
{
int push_items = 0;
int src_nritems;
int dst_nritems;
int ret = 0;
src_nritems = btrfs_header_nritems(src);
dst_nritems = btrfs_header_nritems(dst);
push_items = BTRFS_NODEPTRS_PER_BLOCK(fs_info) - dst_nritems;
WARN_ON(btrfs_header_generation(src) != trans->transid);
WARN_ON(btrfs_header_generation(dst) != trans->transid);
if (!empty && src_nritems <= 8)
return 1;
if (push_items <= 0)
return 1;
if (empty) {
push_items = min(src_nritems, push_items);
if (push_items < src_nritems) {
if (src_nritems - push_items < 8) {
if (push_items <= 8)
return 1;
push_items -= 8;
}
}
} else
push_items = min(src_nritems - 8, push_items);
ret = tree_mod_log_eb_copy(fs_info, dst, src, dst_nritems, 0,
push_items);
if (ret) {
btrfs_abort_transaction(trans, ret);
return ret;
}
copy_extent_buffer(dst, src,
btrfs_node_key_ptr_offset(dst_nritems),
btrfs_node_key_ptr_offset(0),
push_items * sizeof(struct btrfs_key_ptr));
if (push_items < src_nritems) {
memmove_extent_buffer(src, btrfs_node_key_ptr_offset(0),
btrfs_node_key_ptr_offset(push_items),
(src_nritems - push_items) *
sizeof(struct btrfs_key_ptr));
}
btrfs_set_header_nritems(src, src_nritems - push_items);
btrfs_set_header_nritems(dst, dst_nritems + push_items);
btrfs_mark_buffer_dirty(src);
btrfs_mark_buffer_dirty(dst);
return ret;
}
static int balance_node_right(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info,
struct extent_buffer *dst,
struct extent_buffer *src)
{
int push_items = 0;
int max_push;
int src_nritems;
int dst_nritems;
int ret = 0;
WARN_ON(btrfs_header_generation(src) != trans->transid);
WARN_ON(btrfs_header_generation(dst) != trans->transid);
src_nritems = btrfs_header_nritems(src);
dst_nritems = btrfs_header_nritems(dst);
push_items = BTRFS_NODEPTRS_PER_BLOCK(fs_info) - dst_nritems;
if (push_items <= 0)
return 1;
if (src_nritems < 4)
return 1;
max_push = src_nritems / 2 + 1;
if (max_push >= src_nritems)
return 1;
if (max_push < push_items)
push_items = max_push;
tree_mod_log_eb_move(fs_info, dst, push_items, 0, dst_nritems);
memmove_extent_buffer(dst, btrfs_node_key_ptr_offset(push_items),
btrfs_node_key_ptr_offset(0),
(dst_nritems) *
sizeof(struct btrfs_key_ptr));
ret = tree_mod_log_eb_copy(fs_info, dst, src, 0,
src_nritems - push_items, push_items);
if (ret) {
btrfs_abort_transaction(trans, ret);
return ret;
}
copy_extent_buffer(dst, src,
btrfs_node_key_ptr_offset(0),
btrfs_node_key_ptr_offset(src_nritems - push_items),
push_items * sizeof(struct btrfs_key_ptr));
btrfs_set_header_nritems(src, src_nritems - push_items);
btrfs_set_header_nritems(dst, dst_nritems + push_items);
btrfs_mark_buffer_dirty(src);
btrfs_mark_buffer_dirty(dst);
return ret;
}
static noinline int insert_new_root(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int level)
{
struct btrfs_fs_info *fs_info = root->fs_info;
u64 lower_gen;
struct extent_buffer *lower;
struct extent_buffer *c;
struct extent_buffer *old;
struct btrfs_disk_key lower_key;
BUG_ON(path->nodes[level]);
BUG_ON(path->nodes[level-1] != root->node);
lower = path->nodes[level-1];
if (level == 1)
btrfs_item_key(lower, &lower_key, 0);
else
btrfs_node_key(lower, &lower_key, 0);
c = btrfs_alloc_tree_block(trans, root, 0, root->root_key.objectid,
&lower_key, level, root->node->start, 0);
if (IS_ERR(c))
return PTR_ERR(c);
root_add_used(root, fs_info->nodesize);
memzero_extent_buffer(c, 0, sizeof(struct btrfs_header));
btrfs_set_header_nritems(c, 1);
btrfs_set_header_level(c, level);
btrfs_set_header_bytenr(c, c->start);
btrfs_set_header_generation(c, trans->transid);
btrfs_set_header_backref_rev(c, BTRFS_MIXED_BACKREF_REV);
btrfs_set_header_owner(c, root->root_key.objectid);
write_extent_buffer_fsid(c, fs_info->fsid);
write_extent_buffer_chunk_tree_uuid(c, fs_info->chunk_tree_uuid);
btrfs_set_node_key(c, &lower_key, 0);
btrfs_set_node_blockptr(c, 0, lower->start);
lower_gen = btrfs_header_generation(lower);
WARN_ON(lower_gen != trans->transid);
btrfs_set_node_ptr_generation(c, 0, lower_gen);
btrfs_mark_buffer_dirty(c);
old = root->node;
tree_mod_log_set_root_pointer(root, c, 0);
rcu_assign_pointer(root->node, c);
free_extent_buffer(old);
add_root_to_dirty_list(root);
extent_buffer_get(c);
path->nodes[level] = c;
path->locks[level] = BTRFS_WRITE_LOCK_BLOCKING;
path->slots[level] = 0;
return 0;
}
static void insert_ptr(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info, struct btrfs_path *path,
struct btrfs_disk_key *key, u64 bytenr,
int slot, int level)
{
struct extent_buffer *lower;
int nritems;
int ret;
BUG_ON(!path->nodes[level]);
btrfs_assert_tree_locked(path->nodes[level]);
lower = path->nodes[level];
nritems = btrfs_header_nritems(lower);
BUG_ON(slot > nritems);
BUG_ON(nritems == BTRFS_NODEPTRS_PER_BLOCK(fs_info));
if (slot != nritems) {
if (level)
tree_mod_log_eb_move(fs_info, lower, slot + 1,
slot, nritems - slot);
memmove_extent_buffer(lower,
btrfs_node_key_ptr_offset(slot + 1),
btrfs_node_key_ptr_offset(slot),
(nritems - slot) * sizeof(struct btrfs_key_ptr));
}
if (level) {
ret = tree_mod_log_insert_key(fs_info, lower, slot,
MOD_LOG_KEY_ADD, GFP_NOFS);
BUG_ON(ret < 0);
}
btrfs_set_node_key(lower, key, slot);
btrfs_set_node_blockptr(lower, slot, bytenr);
WARN_ON(trans->transid == 0);
btrfs_set_node_ptr_generation(lower, slot, trans->transid);
btrfs_set_header_nritems(lower, nritems + 1);
btrfs_mark_buffer_dirty(lower);
}
static noinline int split_node(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int level)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *c;
struct extent_buffer *split;
struct btrfs_disk_key disk_key;
int mid;
int ret;
u32 c_nritems;
c = path->nodes[level];
WARN_ON(btrfs_header_generation(c) != trans->transid);
if (c == root->node) {
ret = insert_new_root(trans, root, path, level + 1);
if (ret)
return ret;
} else {
ret = push_nodes_for_insert(trans, root, path, level);
c = path->nodes[level];
if (!ret && btrfs_header_nritems(c) <
BTRFS_NODEPTRS_PER_BLOCK(fs_info) - 3)
return 0;
if (ret < 0)
return ret;
}
c_nritems = btrfs_header_nritems(c);
mid = (c_nritems + 1) / 2;
btrfs_node_key(c, &disk_key, mid);
split = btrfs_alloc_tree_block(trans, root, 0, root->root_key.objectid,
&disk_key, level, c->start, 0);
if (IS_ERR(split))
return PTR_ERR(split);
root_add_used(root, fs_info->nodesize);
memzero_extent_buffer(split, 0, sizeof(struct btrfs_header));
btrfs_set_header_level(split, btrfs_header_level(c));
btrfs_set_header_bytenr(split, split->start);
btrfs_set_header_generation(split, trans->transid);
btrfs_set_header_backref_rev(split, BTRFS_MIXED_BACKREF_REV);
btrfs_set_header_owner(split, root->root_key.objectid);
write_extent_buffer_fsid(split, fs_info->fsid);
write_extent_buffer_chunk_tree_uuid(split, fs_info->chunk_tree_uuid);
ret = tree_mod_log_eb_copy(fs_info, split, c, 0, mid, c_nritems - mid);
if (ret) {
btrfs_abort_transaction(trans, ret);
return ret;
}
copy_extent_buffer(split, c,
btrfs_node_key_ptr_offset(0),
btrfs_node_key_ptr_offset(mid),
(c_nritems - mid) * sizeof(struct btrfs_key_ptr));
btrfs_set_header_nritems(split, c_nritems - mid);
btrfs_set_header_nritems(c, mid);
ret = 0;
btrfs_mark_buffer_dirty(c);
btrfs_mark_buffer_dirty(split);
insert_ptr(trans, fs_info, path, &disk_key, split->start,
path->slots[level + 1] + 1, level + 1);
if (path->slots[level] >= mid) {
path->slots[level] -= mid;
btrfs_tree_unlock(c);
free_extent_buffer(c);
path->nodes[level] = split;
path->slots[level + 1] += 1;
} else {
btrfs_tree_unlock(split);
free_extent_buffer(split);
}
return ret;
}
static int leaf_space_used(struct extent_buffer *l, int start, int nr)
{
struct btrfs_item *start_item;
struct btrfs_item *end_item;
struct btrfs_map_token token;
int data_len;
int nritems = btrfs_header_nritems(l);
int end = min(nritems, start + nr) - 1;
if (!nr)
return 0;
btrfs_init_map_token(&token);
start_item = btrfs_item_nr(start);
end_item = btrfs_item_nr(end);
data_len = btrfs_token_item_offset(l, start_item, &token) +
btrfs_token_item_size(l, start_item, &token);
data_len = data_len - btrfs_token_item_offset(l, end_item, &token);
data_len += sizeof(struct btrfs_item) * nr;
WARN_ON(data_len < 0);
return data_len;
}
noinline int btrfs_leaf_free_space(struct btrfs_fs_info *fs_info,
struct extent_buffer *leaf)
{
int nritems = btrfs_header_nritems(leaf);
int ret;
ret = BTRFS_LEAF_DATA_SIZE(fs_info) - leaf_space_used(leaf, 0, nritems);
if (ret < 0) {
btrfs_crit(fs_info,
"leaf free space ret %d, leaf data size %lu, used %d nritems %d",
ret,
(unsigned long) BTRFS_LEAF_DATA_SIZE(fs_info),
leaf_space_used(leaf, 0, nritems), nritems);
}
return ret;
}
static noinline int __push_leaf_right(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
int data_size, int empty,
struct extent_buffer *right,
int free_space, u32 left_nritems,
u32 min_slot)
{
struct extent_buffer *left = path->nodes[0];
struct extent_buffer *upper = path->nodes[1];
struct btrfs_map_token token;
struct btrfs_disk_key disk_key;
int slot;
u32 i;
int push_space = 0;
int push_items = 0;
struct btrfs_item *item;
u32 nr;
u32 right_nritems;
u32 data_end;
u32 this_item_size;
btrfs_init_map_token(&token);
if (empty)
nr = 0;
else
nr = max_t(u32, 1, min_slot);
if (path->slots[0] >= left_nritems)
push_space += data_size;
slot = path->slots[1];
i = left_nritems - 1;
while (i >= nr) {
item = btrfs_item_nr(i);
if (!empty && push_items > 0) {
if (path->slots[0] > i)
break;
if (path->slots[0] == i) {
int space = btrfs_leaf_free_space(fs_info, left);
if (space + push_space * 2 > free_space)
break;
}
}
if (path->slots[0] == i)
push_space += data_size;
this_item_size = btrfs_item_size(left, item);
if (this_item_size + sizeof(*item) + push_space > free_space)
break;
push_items++;
push_space += this_item_size + sizeof(*item);
if (i == 0)
break;
i--;
}
if (push_items == 0)
goto out_unlock;
WARN_ON(!empty && push_items == left_nritems);
right_nritems = btrfs_header_nritems(right);
push_space = btrfs_item_end_nr(left, left_nritems - push_items);
push_space -= leaf_data_end(fs_info, left);
data_end = leaf_data_end(fs_info, right);
memmove_extent_buffer(right,
BTRFS_LEAF_DATA_OFFSET + data_end - push_space,
BTRFS_LEAF_DATA_OFFSET + data_end,
BTRFS_LEAF_DATA_SIZE(fs_info) - data_end);
copy_extent_buffer(right, left, BTRFS_LEAF_DATA_OFFSET +
BTRFS_LEAF_DATA_SIZE(fs_info) - push_space,
BTRFS_LEAF_DATA_OFFSET + leaf_data_end(fs_info, left),
push_space);
memmove_extent_buffer(right, btrfs_item_nr_offset(push_items),
btrfs_item_nr_offset(0),
right_nritems * sizeof(struct btrfs_item));
copy_extent_buffer(right, left, btrfs_item_nr_offset(0),
btrfs_item_nr_offset(left_nritems - push_items),
push_items * sizeof(struct btrfs_item));
right_nritems += push_items;
btrfs_set_header_nritems(right, right_nritems);
push_space = BTRFS_LEAF_DATA_SIZE(fs_info);
for (i = 0; i < right_nritems; i++) {
item = btrfs_item_nr(i);
push_space -= btrfs_token_item_size(right, item, &token);
btrfs_set_token_item_offset(right, item, push_space, &token);
}
left_nritems -= push_items;
btrfs_set_header_nritems(left, left_nritems);
if (left_nritems)
btrfs_mark_buffer_dirty(left);
else
clean_tree_block(fs_info, left);
btrfs_mark_buffer_dirty(right);
btrfs_item_key(right, &disk_key, 0);
btrfs_set_node_key(upper, &disk_key, slot + 1);
btrfs_mark_buffer_dirty(upper);
if (path->slots[0] >= left_nritems) {
path->slots[0] -= left_nritems;
if (btrfs_header_nritems(path->nodes[0]) == 0)
clean_tree_block(fs_info, path->nodes[0]);
btrfs_tree_unlock(path->nodes[0]);
free_extent_buffer(path->nodes[0]);
path->nodes[0] = right;
path->slots[1] += 1;
} else {
btrfs_tree_unlock(right);
free_extent_buffer(right);
}
return 0;
out_unlock:
btrfs_tree_unlock(right);
free_extent_buffer(right);
return 1;
}
static int push_leaf_right(struct btrfs_trans_handle *trans, struct btrfs_root
*root, struct btrfs_path *path,
int min_data_size, int data_size,
int empty, u32 min_slot)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *left = path->nodes[0];
struct extent_buffer *right;
struct extent_buffer *upper;
int slot;
int free_space;
u32 left_nritems;
int ret;
if (!path->nodes[1])
return 1;
slot = path->slots[1];
upper = path->nodes[1];
if (slot >= btrfs_header_nritems(upper) - 1)
return 1;
btrfs_assert_tree_locked(path->nodes[1]);
right = read_node_slot(fs_info, upper, slot + 1);
if (IS_ERR(right))
return 1;
btrfs_tree_lock(right);
btrfs_set_lock_blocking(right);
free_space = btrfs_leaf_free_space(fs_info, right);
if (free_space < data_size)
goto out_unlock;
ret = btrfs_cow_block(trans, root, right, upper,
slot + 1, &right);
if (ret)
goto out_unlock;
free_space = btrfs_leaf_free_space(fs_info, right);
if (free_space < data_size)
goto out_unlock;
left_nritems = btrfs_header_nritems(left);
if (left_nritems == 0)
goto out_unlock;
if (path->slots[0] == left_nritems && !empty) {
btrfs_tree_unlock(left);
free_extent_buffer(left);
path->nodes[0] = right;
path->slots[0] = 0;
path->slots[1]++;
return 0;
}
return __push_leaf_right(fs_info, path, min_data_size, empty,
right, free_space, left_nritems, min_slot);
out_unlock:
btrfs_tree_unlock(right);
free_extent_buffer(right);
return 1;
}
static noinline int __push_leaf_left(struct btrfs_fs_info *fs_info,
struct btrfs_path *path, int data_size,
int empty, struct extent_buffer *left,
int free_space, u32 right_nritems,
u32 max_slot)
{
struct btrfs_disk_key disk_key;
struct extent_buffer *right = path->nodes[0];
int i;
int push_space = 0;
int push_items = 0;
struct btrfs_item *item;
u32 old_left_nritems;
u32 nr;
int ret = 0;
u32 this_item_size;
u32 old_left_item_size;
struct btrfs_map_token token;
btrfs_init_map_token(&token);
if (empty)
nr = min(right_nritems, max_slot);
else
nr = min(right_nritems - 1, max_slot);
for (i = 0; i < nr; i++) {
item = btrfs_item_nr(i);
if (!empty && push_items > 0) {
if (path->slots[0] < i)
break;
if (path->slots[0] == i) {
int space = btrfs_leaf_free_space(fs_info, right);
if (space + push_space * 2 > free_space)
break;
}
}
if (path->slots[0] == i)
push_space += data_size;
this_item_size = btrfs_item_size(right, item);
if (this_item_size + sizeof(*item) + push_space > free_space)
break;
push_items++;
push_space += this_item_size + sizeof(*item);
}
if (push_items == 0) {
ret = 1;
goto out;
}
WARN_ON(!empty && push_items == btrfs_header_nritems(right));
copy_extent_buffer(left, right,
btrfs_item_nr_offset(btrfs_header_nritems(left)),
btrfs_item_nr_offset(0),
push_items * sizeof(struct btrfs_item));
push_space = BTRFS_LEAF_DATA_SIZE(fs_info) -
btrfs_item_offset_nr(right, push_items - 1);
copy_extent_buffer(left, right, BTRFS_LEAF_DATA_OFFSET +
leaf_data_end(fs_info, left) - push_space,
BTRFS_LEAF_DATA_OFFSET +
btrfs_item_offset_nr(right, push_items - 1),
push_space);
old_left_nritems = btrfs_header_nritems(left);
BUG_ON(old_left_nritems <= 0);
old_left_item_size = btrfs_item_offset_nr(left, old_left_nritems - 1);
for (i = old_left_nritems; i < old_left_nritems + push_items; i++) {
u32 ioff;
item = btrfs_item_nr(i);
ioff = btrfs_token_item_offset(left, item, &token);
btrfs_set_token_item_offset(left, item,
ioff - (BTRFS_LEAF_DATA_SIZE(fs_info) - old_left_item_size),
&token);
}
btrfs_set_header_nritems(left, old_left_nritems + push_items);
if (push_items > right_nritems)
WARN(1, KERN_CRIT "push items %d nr %u\n", push_items,
right_nritems);
if (push_items < right_nritems) {
push_space = btrfs_item_offset_nr(right, push_items - 1) -
leaf_data_end(fs_info, right);
memmove_extent_buffer(right, BTRFS_LEAF_DATA_OFFSET +
BTRFS_LEAF_DATA_SIZE(fs_info) - push_space,
BTRFS_LEAF_DATA_OFFSET +
leaf_data_end(fs_info, right), push_space);
memmove_extent_buffer(right, btrfs_item_nr_offset(0),
btrfs_item_nr_offset(push_items),
(btrfs_header_nritems(right) - push_items) *
sizeof(struct btrfs_item));
}
right_nritems -= push_items;
btrfs_set_header_nritems(right, right_nritems);
push_space = BTRFS_LEAF_DATA_SIZE(fs_info);
for (i = 0; i < right_nritems; i++) {
item = btrfs_item_nr(i);
push_space = push_space - btrfs_token_item_size(right,
item, &token);
btrfs_set_token_item_offset(right, item, push_space, &token);
}
btrfs_mark_buffer_dirty(left);
if (right_nritems)
btrfs_mark_buffer_dirty(right);
else
clean_tree_block(fs_info, right);
btrfs_item_key(right, &disk_key, 0);
fixup_low_keys(fs_info, path, &disk_key, 1);
if (path->slots[0] < push_items) {
path->slots[0] += old_left_nritems;
btrfs_tree_unlock(path->nodes[0]);
free_extent_buffer(path->nodes[0]);
path->nodes[0] = left;
path->slots[1] -= 1;
} else {
btrfs_tree_unlock(left);
free_extent_buffer(left);
path->slots[0] -= push_items;
}
BUG_ON(path->slots[0] < 0);
return ret;
out:
btrfs_tree_unlock(left);
free_extent_buffer(left);
return ret;
}
static int push_leaf_left(struct btrfs_trans_handle *trans, struct btrfs_root
*root, struct btrfs_path *path, int min_data_size,
int data_size, int empty, u32 max_slot)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *right = path->nodes[0];
struct extent_buffer *left;
int slot;
int free_space;
u32 right_nritems;
int ret = 0;
slot = path->slots[1];
if (slot == 0)
return 1;
if (!path->nodes[1])
return 1;
right_nritems = btrfs_header_nritems(right);
if (right_nritems == 0)
return 1;
btrfs_assert_tree_locked(path->nodes[1]);
left = read_node_slot(fs_info, path->nodes[1], slot - 1);
if (IS_ERR(left))
return 1;
btrfs_tree_lock(left);
btrfs_set_lock_blocking(left);
free_space = btrfs_leaf_free_space(fs_info, left);
if (free_space < data_size) {
ret = 1;
goto out;
}
ret = btrfs_cow_block(trans, root, left,
path->nodes[1], slot - 1, &left);
if (ret) {
if (ret == -ENOSPC)
ret = 1;
goto out;
}
free_space = btrfs_leaf_free_space(fs_info, left);
if (free_space < data_size) {
ret = 1;
goto out;
}
return __push_leaf_left(fs_info, path, min_data_size,
empty, left, free_space, right_nritems,
max_slot);
out:
btrfs_tree_unlock(left);
free_extent_buffer(left);
return ret;
}
static noinline void copy_for_split(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
struct extent_buffer *l,
struct extent_buffer *right,
int slot, int mid, int nritems)
{
int data_copy_size;
int rt_data_off;
int i;
struct btrfs_disk_key disk_key;
struct btrfs_map_token token;
btrfs_init_map_token(&token);
nritems = nritems - mid;
btrfs_set_header_nritems(right, nritems);
data_copy_size = btrfs_item_end_nr(l, mid) - leaf_data_end(fs_info, l);
copy_extent_buffer(right, l, btrfs_item_nr_offset(0),
btrfs_item_nr_offset(mid),
nritems * sizeof(struct btrfs_item));
copy_extent_buffer(right, l,
BTRFS_LEAF_DATA_OFFSET + BTRFS_LEAF_DATA_SIZE(fs_info) -
data_copy_size, BTRFS_LEAF_DATA_OFFSET +
leaf_data_end(fs_info, l), data_copy_size);
rt_data_off = BTRFS_LEAF_DATA_SIZE(fs_info) - btrfs_item_end_nr(l, mid);
for (i = 0; i < nritems; i++) {
struct btrfs_item *item = btrfs_item_nr(i);
u32 ioff;
ioff = btrfs_token_item_offset(right, item, &token);
btrfs_set_token_item_offset(right, item,
ioff + rt_data_off, &token);
}
btrfs_set_header_nritems(l, mid);
btrfs_item_key(right, &disk_key, 0);
insert_ptr(trans, fs_info, path, &disk_key, right->start,
path->slots[1] + 1, 1);
btrfs_mark_buffer_dirty(right);
btrfs_mark_buffer_dirty(l);
BUG_ON(path->slots[0] != slot);
if (mid <= slot) {
btrfs_tree_unlock(path->nodes[0]);
free_extent_buffer(path->nodes[0]);
path->nodes[0] = right;
path->slots[0] -= mid;
path->slots[1] += 1;
} else {
btrfs_tree_unlock(right);
free_extent_buffer(right);
}
BUG_ON(path->slots[0] < 0);
}
static noinline int push_for_double_split(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
int data_size)
{
struct btrfs_fs_info *fs_info = root->fs_info;
int ret;
int progress = 0;
int slot;
u32 nritems;
int space_needed = data_size;
slot = path->slots[0];
if (slot < btrfs_header_nritems(path->nodes[0]))
space_needed -= btrfs_leaf_free_space(fs_info, path->nodes[0]);
ret = push_leaf_right(trans, root, path, 1, space_needed, 0, slot);
if (ret < 0)
return ret;
if (ret == 0)
progress++;
nritems = btrfs_header_nritems(path->nodes[0]);
if (path->slots[0] == 0 || path->slots[0] == nritems)
return 0;
if (btrfs_leaf_free_space(fs_info, path->nodes[0]) >= data_size)
return 0;
slot = path->slots[0];
space_needed = data_size;
if (slot > 0)
space_needed -= btrfs_leaf_free_space(fs_info, path->nodes[0]);
ret = push_leaf_left(trans, root, path, 1, space_needed, 0, slot);
if (ret < 0)
return ret;
if (ret == 0)
progress++;
if (progress)
return 0;
return 1;
}
static noinline int split_leaf(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
const struct btrfs_key *ins_key,
struct btrfs_path *path, int data_size,
int extend)
{
struct btrfs_disk_key disk_key;
struct extent_buffer *l;
u32 nritems;
int mid;
int slot;
struct extent_buffer *right;
struct btrfs_fs_info *fs_info = root->fs_info;
int ret = 0;
int wret;
int split;
int num_doubles = 0;
int tried_avoid_double = 0;
l = path->nodes[0];
slot = path->slots[0];
if (extend && data_size + btrfs_item_size_nr(l, slot) +
sizeof(struct btrfs_item) > BTRFS_LEAF_DATA_SIZE(fs_info))
return -EOVERFLOW;
if (data_size && path->nodes[1]) {
int space_needed = data_size;
if (slot < btrfs_header_nritems(l))
space_needed -= btrfs_leaf_free_space(fs_info, l);
wret = push_leaf_right(trans, root, path, space_needed,
space_needed, 0, 0);
if (wret < 0)
return wret;
if (wret) {
space_needed = data_size;
if (slot > 0)
space_needed -= btrfs_leaf_free_space(fs_info,
l);
wret = push_leaf_left(trans, root, path, space_needed,
space_needed, 0, (u32)-1);
if (wret < 0)
return wret;
}
l = path->nodes[0];
if (btrfs_leaf_free_space(fs_info, l) >= data_size)
return 0;
}
if (!path->nodes[1]) {
ret = insert_new_root(trans, root, path, 1);
if (ret)
return ret;
}
again:
split = 1;
l = path->nodes[0];
slot = path->slots[0];
nritems = btrfs_header_nritems(l);
mid = (nritems + 1) / 2;
if (mid <= slot) {
if (nritems == 1 ||
leaf_space_used(l, mid, nritems - mid) + data_size >
BTRFS_LEAF_DATA_SIZE(fs_info)) {
if (slot >= nritems) {
split = 0;
} else {
mid = slot;
if (mid != nritems &&
leaf_space_used(l, mid, nritems - mid) +
data_size > BTRFS_LEAF_DATA_SIZE(fs_info)) {
if (data_size && !tried_avoid_double)
goto push_for_double;
split = 2;
}
}
}
} else {
if (leaf_space_used(l, 0, mid) + data_size >
BTRFS_LEAF_DATA_SIZE(fs_info)) {
if (!extend && data_size && slot == 0) {
split = 0;
} else if ((extend || !data_size) && slot == 0) {
mid = 1;
} else {
mid = slot;
if (mid != nritems &&
leaf_space_used(l, mid, nritems - mid) +
data_size > BTRFS_LEAF_DATA_SIZE(fs_info)) {
if (data_size && !tried_avoid_double)
goto push_for_double;
split = 2;
}
}
}
}
if (split == 0)
btrfs_cpu_key_to_disk(&disk_key, ins_key);
else
btrfs_item_key(l, &disk_key, mid);
right = btrfs_alloc_tree_block(trans, root, 0, root->root_key.objectid,
&disk_key, 0, l->start, 0);
if (IS_ERR(right))
return PTR_ERR(right);
root_add_used(root, fs_info->nodesize);
memzero_extent_buffer(right, 0, sizeof(struct btrfs_header));
btrfs_set_header_bytenr(right, right->start);
btrfs_set_header_generation(right, trans->transid);
btrfs_set_header_backref_rev(right, BTRFS_MIXED_BACKREF_REV);
btrfs_set_header_owner(right, root->root_key.objectid);
btrfs_set_header_level(right, 0);
write_extent_buffer_fsid(right, fs_info->fsid);
write_extent_buffer_chunk_tree_uuid(right, fs_info->chunk_tree_uuid);
if (split == 0) {
if (mid <= slot) {
btrfs_set_header_nritems(right, 0);
insert_ptr(trans, fs_info, path, &disk_key,
right->start, path->slots[1] + 1, 1);
btrfs_tree_unlock(path->nodes[0]);
free_extent_buffer(path->nodes[0]);
path->nodes[0] = right;
path->slots[0] = 0;
path->slots[1] += 1;
} else {
btrfs_set_header_nritems(right, 0);
insert_ptr(trans, fs_info, path, &disk_key,
right->start, path->slots[1], 1);
btrfs_tree_unlock(path->nodes[0]);
free_extent_buffer(path->nodes[0]);
path->nodes[0] = right;
path->slots[0] = 0;
if (path->slots[1] == 0)
fixup_low_keys(fs_info, path, &disk_key, 1);
}
return ret;
}
copy_for_split(trans, fs_info, path, l, right, slot, mid, nritems);
if (split == 2) {
BUG_ON(num_doubles != 0);
num_doubles++;
goto again;
}
return 0;
push_for_double:
push_for_double_split(trans, root, path, data_size);
tried_avoid_double = 1;
if (btrfs_leaf_free_space(fs_info, path->nodes[0]) >= data_size)
return 0;
goto again;
}
static noinline int setup_leaf_for_split(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path, int ins_len)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct btrfs_key key;
struct extent_buffer *leaf;
struct btrfs_file_extent_item *fi;
u64 extent_len = 0;
u32 item_size;
int ret;
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &key, path->slots[0]);
BUG_ON(key.type != BTRFS_EXTENT_DATA_KEY &&
key.type != BTRFS_EXTENT_CSUM_KEY);
if (btrfs_leaf_free_space(fs_info, leaf) >= ins_len)
return 0;
item_size = btrfs_item_size_nr(leaf, path->slots[0]);
if (key.type == BTRFS_EXTENT_DATA_KEY) {
fi = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_file_extent_item);
extent_len = btrfs_file_extent_num_bytes(leaf, fi);
}
btrfs_release_path(path);
path->keep_locks = 1;
path->search_for_split = 1;
ret = btrfs_search_slot(trans, root, &key, path, 0, 1);
path->search_for_split = 0;
if (ret > 0)
ret = -EAGAIN;
if (ret < 0)
goto err;
ret = -EAGAIN;
leaf = path->nodes[0];
if (item_size != btrfs_item_size_nr(leaf, path->slots[0]))
goto err;
if (btrfs_leaf_free_space(fs_info, path->nodes[0]) >= ins_len)
goto err;
if (key.type == BTRFS_EXTENT_DATA_KEY) {
fi = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_file_extent_item);
if (extent_len != btrfs_file_extent_num_bytes(leaf, fi))
goto err;
}
btrfs_set_path_blocking(path);
ret = split_leaf(trans, root, &key, path, ins_len, 1);
if (ret)
goto err;
path->keep_locks = 0;
btrfs_unlock_up_safe(path, 1);
return 0;
err:
path->keep_locks = 0;
return ret;
}
static noinline int split_item(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
const struct btrfs_key *new_key,
unsigned long split_offset)
{
struct extent_buffer *leaf;
struct btrfs_item *item;
struct btrfs_item *new_item;
int slot;
char *buf;
u32 nritems;
u32 item_size;
u32 orig_offset;
struct btrfs_disk_key disk_key;
leaf = path->nodes[0];
BUG_ON(btrfs_leaf_free_space(fs_info, leaf) < sizeof(struct btrfs_item));
btrfs_set_path_blocking(path);
item = btrfs_item_nr(path->slots[0]);
orig_offset = btrfs_item_offset(leaf, item);
item_size = btrfs_item_size(leaf, item);
buf = kmalloc(item_size, GFP_NOFS);
if (!buf)
return -ENOMEM;
read_extent_buffer(leaf, buf, btrfs_item_ptr_offset(leaf,
path->slots[0]), item_size);
slot = path->slots[0] + 1;
nritems = btrfs_header_nritems(leaf);
if (slot != nritems) {
memmove_extent_buffer(leaf, btrfs_item_nr_offset(slot + 1),
btrfs_item_nr_offset(slot),
(nritems - slot) * sizeof(struct btrfs_item));
}
btrfs_cpu_key_to_disk(&disk_key, new_key);
btrfs_set_item_key(leaf, &disk_key, slot);
new_item = btrfs_item_nr(slot);
btrfs_set_item_offset(leaf, new_item, orig_offset);
btrfs_set_item_size(leaf, new_item, item_size - split_offset);
btrfs_set_item_offset(leaf, item,
orig_offset + item_size - split_offset);
btrfs_set_item_size(leaf, item, split_offset);
btrfs_set_header_nritems(leaf, nritems + 1);
write_extent_buffer(leaf, buf,
btrfs_item_ptr_offset(leaf, path->slots[0]),
split_offset);
write_extent_buffer(leaf, buf + split_offset,
btrfs_item_ptr_offset(leaf, slot),
item_size - split_offset);
btrfs_mark_buffer_dirty(leaf);
BUG_ON(btrfs_leaf_free_space(fs_info, leaf) < 0);
kfree(buf);
return 0;
}
int btrfs_split_item(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
const struct btrfs_key *new_key,
unsigned long split_offset)
{
int ret;
ret = setup_leaf_for_split(trans, root, path,
sizeof(struct btrfs_item));
if (ret)
return ret;
ret = split_item(root->fs_info, path, new_key, split_offset);
return ret;
}
int btrfs_duplicate_item(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
const struct btrfs_key *new_key)
{
struct extent_buffer *leaf;
int ret;
u32 item_size;
leaf = path->nodes[0];
item_size = btrfs_item_size_nr(leaf, path->slots[0]);
ret = setup_leaf_for_split(trans, root, path,
item_size + sizeof(struct btrfs_item));
if (ret)
return ret;
path->slots[0]++;
setup_items_for_insert(root, path, new_key, &item_size,
item_size, item_size +
sizeof(struct btrfs_item), 1);
leaf = path->nodes[0];
memcpy_extent_buffer(leaf,
btrfs_item_ptr_offset(leaf, path->slots[0]),
btrfs_item_ptr_offset(leaf, path->slots[0] - 1),
item_size);
return 0;
}
void btrfs_truncate_item(struct btrfs_fs_info *fs_info,
struct btrfs_path *path, u32 new_size, int from_end)
{
int slot;
struct extent_buffer *leaf;
struct btrfs_item *item;
u32 nritems;
unsigned int data_end;
unsigned int old_data_start;
unsigned int old_size;
unsigned int size_diff;
int i;
struct btrfs_map_token token;
btrfs_init_map_token(&token);
leaf = path->nodes[0];
slot = path->slots[0];
old_size = btrfs_item_size_nr(leaf, slot);
if (old_size == new_size)
return;
nritems = btrfs_header_nritems(leaf);
data_end = leaf_data_end(fs_info, leaf);
old_data_start = btrfs_item_offset_nr(leaf, slot);
size_diff = old_size - new_size;
BUG_ON(slot < 0);
BUG_ON(slot >= nritems);
for (i = slot; i < nritems; i++) {
u32 ioff;
item = btrfs_item_nr(i);
ioff = btrfs_token_item_offset(leaf, item, &token);
btrfs_set_token_item_offset(leaf, item,
ioff + size_diff, &token);
}
if (from_end) {
memmove_extent_buffer(leaf, BTRFS_LEAF_DATA_OFFSET +
data_end + size_diff, BTRFS_LEAF_DATA_OFFSET +
data_end, old_data_start + new_size - data_end);
} else {
struct btrfs_disk_key disk_key;
u64 offset;
btrfs_item_key(leaf, &disk_key, slot);
if (btrfs_disk_key_type(&disk_key) == BTRFS_EXTENT_DATA_KEY) {
unsigned long ptr;
struct btrfs_file_extent_item *fi;
fi = btrfs_item_ptr(leaf, slot,
struct btrfs_file_extent_item);
fi = (struct btrfs_file_extent_item *)(
(unsigned long)fi - size_diff);
if (btrfs_file_extent_type(leaf, fi) ==
BTRFS_FILE_EXTENT_INLINE) {
ptr = btrfs_item_ptr_offset(leaf, slot);
memmove_extent_buffer(leaf, ptr,
(unsigned long)fi,
BTRFS_FILE_EXTENT_INLINE_DATA_START);
}
}
memmove_extent_buffer(leaf, BTRFS_LEAF_DATA_OFFSET +
data_end + size_diff, BTRFS_LEAF_DATA_OFFSET +
data_end, old_data_start - data_end);
offset = btrfs_disk_key_offset(&disk_key);
btrfs_set_disk_key_offset(&disk_key, offset + size_diff);
btrfs_set_item_key(leaf, &disk_key, slot);
if (slot == 0)
fixup_low_keys(fs_info, path, &disk_key, 1);
}
item = btrfs_item_nr(slot);
btrfs_set_item_size(leaf, item, new_size);
btrfs_mark_buffer_dirty(leaf);
if (btrfs_leaf_free_space(fs_info, leaf) < 0) {
btrfs_print_leaf(leaf);
BUG();
}
}
void btrfs_extend_item(struct btrfs_fs_info *fs_info, struct btrfs_path *path,
u32 data_size)
{
int slot;
struct extent_buffer *leaf;
struct btrfs_item *item;
u32 nritems;
unsigned int data_end;
unsigned int old_data;
unsigned int old_size;
int i;
struct btrfs_map_token token;
btrfs_init_map_token(&token);
leaf = path->nodes[0];
nritems = btrfs_header_nritems(leaf);
data_end = leaf_data_end(fs_info, leaf);
if (btrfs_leaf_free_space(fs_info, leaf) < data_size) {
btrfs_print_leaf(leaf);
BUG();
}
slot = path->slots[0];
old_data = btrfs_item_end_nr(leaf, slot);
BUG_ON(slot < 0);
if (slot >= nritems) {
btrfs_print_leaf(leaf);
btrfs_crit(fs_info, "slot %d too large, nritems %d",
slot, nritems);
BUG_ON(1);
}
for (i = slot; i < nritems; i++) {
u32 ioff;
item = btrfs_item_nr(i);
ioff = btrfs_token_item_offset(leaf, item, &token);
btrfs_set_token_item_offset(leaf, item,
ioff - data_size, &token);
}
memmove_extent_buffer(leaf, BTRFS_LEAF_DATA_OFFSET +
data_end - data_size, BTRFS_LEAF_DATA_OFFSET +
data_end, old_data - data_end);
data_end = old_data;
old_size = btrfs_item_size_nr(leaf, slot);
item = btrfs_item_nr(slot);
btrfs_set_item_size(leaf, item, old_size + data_size);
btrfs_mark_buffer_dirty(leaf);
if (btrfs_leaf_free_space(fs_info, leaf) < 0) {
btrfs_print_leaf(leaf);
BUG();
}
}
void setup_items_for_insert(struct btrfs_root *root, struct btrfs_path *path,
const struct btrfs_key *cpu_key, u32 *data_size,
u32 total_data, u32 total_size, int nr)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct btrfs_item *item;
int i;
u32 nritems;
unsigned int data_end;
struct btrfs_disk_key disk_key;
struct extent_buffer *leaf;
int slot;
struct btrfs_map_token token;
if (path->slots[0] == 0) {
btrfs_cpu_key_to_disk(&disk_key, cpu_key);
fixup_low_keys(fs_info, path, &disk_key, 1);
}
btrfs_unlock_up_safe(path, 1);
btrfs_init_map_token(&token);
leaf = path->nodes[0];
slot = path->slots[0];
nritems = btrfs_header_nritems(leaf);
data_end = leaf_data_end(fs_info, leaf);
if (btrfs_leaf_free_space(fs_info, leaf) < total_size) {
btrfs_print_leaf(leaf);
btrfs_crit(fs_info, "not enough freespace need %u have %d",
total_size, btrfs_leaf_free_space(fs_info, leaf));
BUG();
}
if (slot != nritems) {
unsigned int old_data = btrfs_item_end_nr(leaf, slot);
if (old_data < data_end) {
btrfs_print_leaf(leaf);
btrfs_crit(fs_info, "slot %d old_data %d data_end %d",
slot, old_data, data_end);
BUG_ON(1);
}
for (i = slot; i < nritems; i++) {
u32 ioff;
item = btrfs_item_nr(i);
ioff = btrfs_token_item_offset(leaf, item, &token);
btrfs_set_token_item_offset(leaf, item,
ioff - total_data, &token);
}
memmove_extent_buffer(leaf, btrfs_item_nr_offset(slot + nr),
btrfs_item_nr_offset(slot),
(nritems - slot) * sizeof(struct btrfs_item));
memmove_extent_buffer(leaf, BTRFS_LEAF_DATA_OFFSET +
data_end - total_data, BTRFS_LEAF_DATA_OFFSET +
data_end, old_data - data_end);
data_end = old_data;
}
for (i = 0; i < nr; i++) {
btrfs_cpu_key_to_disk(&disk_key, cpu_key + i);
btrfs_set_item_key(leaf, &disk_key, slot + i);
item = btrfs_item_nr(slot + i);
btrfs_set_token_item_offset(leaf, item,
data_end - data_size[i], &token);
data_end -= data_size[i];
btrfs_set_token_item_size(leaf, item, data_size[i], &token);
}
btrfs_set_header_nritems(leaf, nritems + nr);
btrfs_mark_buffer_dirty(leaf);
if (btrfs_leaf_free_space(fs_info, leaf) < 0) {
btrfs_print_leaf(leaf);
BUG();
}
}
int btrfs_insert_empty_items(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
const struct btrfs_key *cpu_key, u32 *data_size,
int nr)
{
int ret = 0;
int slot;
int i;
u32 total_size = 0;
u32 total_data = 0;
for (i = 0; i < nr; i++)
total_data += data_size[i];
total_size = total_data + (nr * sizeof(struct btrfs_item));
ret = btrfs_search_slot(trans, root, cpu_key, path, total_size, 1);
if (ret == 0)
return -EEXIST;
if (ret < 0)
return ret;
slot = path->slots[0];
BUG_ON(slot < 0);
setup_items_for_insert(root, path, cpu_key, data_size,
total_data, total_size, nr);
return 0;
}
int btrfs_insert_item(struct btrfs_trans_handle *trans, struct btrfs_root *root,
const struct btrfs_key *cpu_key, void *data,
u32 data_size)
{
int ret = 0;
struct btrfs_path *path;
struct extent_buffer *leaf;
unsigned long ptr;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
ret = btrfs_insert_empty_item(trans, root, path, cpu_key, data_size);
if (!ret) {
leaf = path->nodes[0];
ptr = btrfs_item_ptr_offset(leaf, path->slots[0]);
write_extent_buffer(leaf, data, ptr, data_size);
btrfs_mark_buffer_dirty(leaf);
}
btrfs_free_path(path);
return ret;
}
static void del_ptr(struct btrfs_root *root, struct btrfs_path *path,
int level, int slot)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *parent = path->nodes[level];
u32 nritems;
int ret;
nritems = btrfs_header_nritems(parent);
if (slot != nritems - 1) {
if (level)
tree_mod_log_eb_move(fs_info, parent, slot,
slot + 1, nritems - slot - 1);
memmove_extent_buffer(parent,
btrfs_node_key_ptr_offset(slot),
btrfs_node_key_ptr_offset(slot + 1),
sizeof(struct btrfs_key_ptr) *
(nritems - slot - 1));
} else if (level) {
ret = tree_mod_log_insert_key(fs_info, parent, slot,
MOD_LOG_KEY_REMOVE, GFP_NOFS);
BUG_ON(ret < 0);
}
nritems--;
btrfs_set_header_nritems(parent, nritems);
if (nritems == 0 && parent == root->node) {
BUG_ON(btrfs_header_level(root->node) != 1);
btrfs_set_header_level(root->node, 0);
} else if (slot == 0) {
struct btrfs_disk_key disk_key;
btrfs_node_key(parent, &disk_key, 0);
fixup_low_keys(fs_info, path, &disk_key, level + 1);
}
btrfs_mark_buffer_dirty(parent);
}
static noinline void btrfs_del_leaf(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_path *path,
struct extent_buffer *leaf)
{
WARN_ON(btrfs_header_generation(leaf) != trans->transid);
del_ptr(root, path, 1, path->slots[1]);
btrfs_unlock_up_safe(path, 0);
root_sub_used(root, leaf->len);
extent_buffer_get(leaf);
btrfs_free_tree_block(trans, root, leaf, 0, 1);
free_extent_buffer_stale(leaf);
}
int btrfs_del_items(struct btrfs_trans_handle *trans, struct btrfs_root *root,
struct btrfs_path *path, int slot, int nr)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *leaf;
struct btrfs_item *item;
u32 last_off;
u32 dsize = 0;
int ret = 0;
int wret;
int i;
u32 nritems;
struct btrfs_map_token token;
btrfs_init_map_token(&token);
leaf = path->nodes[0];
last_off = btrfs_item_offset_nr(leaf, slot + nr - 1);
for (i = 0; i < nr; i++)
dsize += btrfs_item_size_nr(leaf, slot + i);
nritems = btrfs_header_nritems(leaf);
if (slot + nr != nritems) {
int data_end = leaf_data_end(fs_info, leaf);
memmove_extent_buffer(leaf, BTRFS_LEAF_DATA_OFFSET +
data_end + dsize,
BTRFS_LEAF_DATA_OFFSET + data_end,
last_off - data_end);
for (i = slot + nr; i < nritems; i++) {
u32 ioff;
item = btrfs_item_nr(i);
ioff = btrfs_token_item_offset(leaf, item, &token);
btrfs_set_token_item_offset(leaf, item,
ioff + dsize, &token);
}
memmove_extent_buffer(leaf, btrfs_item_nr_offset(slot),
btrfs_item_nr_offset(slot + nr),
sizeof(struct btrfs_item) *
(nritems - slot - nr));
}
btrfs_set_header_nritems(leaf, nritems - nr);
nritems -= nr;
if (nritems == 0) {
if (leaf == root->node) {
btrfs_set_header_level(leaf, 0);
} else {
btrfs_set_path_blocking(path);
clean_tree_block(fs_info, leaf);
btrfs_del_leaf(trans, root, path, leaf);
}
} else {
int used = leaf_space_used(leaf, 0, nritems);
if (slot == 0) {
struct btrfs_disk_key disk_key;
btrfs_item_key(leaf, &disk_key, 0);
fixup_low_keys(fs_info, path, &disk_key, 1);
}
if (used < BTRFS_LEAF_DATA_SIZE(fs_info) / 3) {
slot = path->slots[1];
extent_buffer_get(leaf);
btrfs_set_path_blocking(path);
wret = push_leaf_left(trans, root, path, 1, 1,
1, (u32)-1);
if (wret < 0 && wret != -ENOSPC)
ret = wret;
if (path->nodes[0] == leaf &&
btrfs_header_nritems(leaf)) {
wret = push_leaf_right(trans, root, path, 1,
1, 1, 0);
if (wret < 0 && wret != -ENOSPC)
ret = wret;
}
if (btrfs_header_nritems(leaf) == 0) {
path->slots[1] = slot;
btrfs_del_leaf(trans, root, path, leaf);
free_extent_buffer(leaf);
ret = 0;
} else {
if (path->nodes[0] == leaf)
btrfs_mark_buffer_dirty(leaf);
free_extent_buffer(leaf);
}
} else {
btrfs_mark_buffer_dirty(leaf);
}
}
return ret;
}
int btrfs_prev_leaf(struct btrfs_root *root, struct btrfs_path *path)
{
struct btrfs_key key;
struct btrfs_disk_key found_key;
int ret;
btrfs_item_key_to_cpu(path->nodes[0], &key, 0);
if (key.offset > 0) {
key.offset--;
} else if (key.type > 0) {
key.type--;
key.offset = (u64)-1;
} else if (key.objectid > 0) {
key.objectid--;
key.type = (u8)-1;
key.offset = (u64)-1;
} else {
return 1;
}
btrfs_release_path(path);
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
return ret;
btrfs_item_key(path->nodes[0], &found_key, 0);
ret = comp_keys(&found_key, &key);
if (ret <= 0)
return 0;
return 1;
}
int btrfs_search_forward(struct btrfs_root *root, struct btrfs_key *min_key,
struct btrfs_path *path,
u64 min_trans)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct extent_buffer *cur;
struct btrfs_key found_key;
int slot;
int sret;
u32 nritems;
int level;
int ret = 1;
int keep_locks = path->keep_locks;
path->keep_locks = 1;
again:
cur = btrfs_read_lock_root_node(root);
level = btrfs_header_level(cur);
WARN_ON(path->nodes[level]);
path->nodes[level] = cur;
path->locks[level] = BTRFS_READ_LOCK;
if (btrfs_header_generation(cur) < min_trans) {
ret = 1;
goto out;
}
while (1) {
nritems = btrfs_header_nritems(cur);
level = btrfs_header_level(cur);
sret = bin_search(cur, min_key, level, &slot);
if (level == path->lowest_level) {
if (slot >= nritems)
goto find_next_key;
ret = 0;
path->slots[level] = slot;
btrfs_item_key_to_cpu(cur, &found_key, slot);
goto out;
}
if (sret && slot > 0)
slot--;
while (slot < nritems) {
u64 gen;
gen = btrfs_node_ptr_generation(cur, slot);
if (gen < min_trans) {
slot++;
continue;
}
break;
}
find_next_key:
if (slot >= nritems) {
path->slots[level] = slot;
btrfs_set_path_blocking(path);
sret = btrfs_find_next_key(root, path, min_key, level,
min_trans);
if (sret == 0) {
btrfs_release_path(path);
goto again;
} else {
goto out;
}
}
btrfs_node_key_to_cpu(cur, &found_key, slot);
path->slots[level] = slot;
if (level == path->lowest_level) {
ret = 0;
goto out;
}
btrfs_set_path_blocking(path);
cur = read_node_slot(fs_info, cur, slot);
if (IS_ERR(cur)) {
ret = PTR_ERR(cur);
goto out;
}
btrfs_tree_read_lock(cur);
path->locks[level - 1] = BTRFS_READ_LOCK;
path->nodes[level - 1] = cur;
unlock_up(path, level, 1, 0, NULL);
btrfs_clear_path_blocking(path, NULL, 0);
}
out:
path->keep_locks = keep_locks;
if (ret == 0) {
btrfs_unlock_up_safe(path, path->lowest_level + 1);
btrfs_set_path_blocking(path);
memcpy(min_key, &found_key, sizeof(found_key));
}
return ret;
}
static int tree_move_down(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
int *level)
{
struct extent_buffer *eb;
BUG_ON(*level == 0);
eb = read_node_slot(fs_info, path->nodes[*level], path->slots[*level]);
if (IS_ERR(eb))
return PTR_ERR(eb);
path->nodes[*level - 1] = eb;
path->slots[*level - 1] = 0;
(*level)--;
return 0;
}
static int tree_move_next_or_upnext(struct btrfs_path *path,
int *level, int root_level)
{
int ret = 0;
int nritems;
nritems = btrfs_header_nritems(path->nodes[*level]);
path->slots[*level]++;
while (path->slots[*level] >= nritems) {
if (*level == root_level)
return -1;
path->slots[*level] = 0;
free_extent_buffer(path->nodes[*level]);
path->nodes[*level] = NULL;
(*level)++;
path->slots[*level]++;
nritems = btrfs_header_nritems(path->nodes[*level]);
ret = 1;
}
return ret;
}
static int tree_advance(struct btrfs_fs_info *fs_info,
struct btrfs_path *path,
int *level, int root_level,
int allow_down,
struct btrfs_key *key)
{
int ret;
if (*level == 0 || !allow_down) {
ret = tree_move_next_or_upnext(path, level, root_level);
} else {
ret = tree_move_down(fs_info, path, level);
}
if (ret >= 0) {
if (*level == 0)
btrfs_item_key_to_cpu(path->nodes[*level], key,
path->slots[*level]);
else
btrfs_node_key_to_cpu(path->nodes[*level], key,
path->slots[*level]);
}
return ret;
}
static int tree_compare_item(struct btrfs_path *left_path,
struct btrfs_path *right_path,
char *tmp_buf)
{
int cmp;
int len1, len2;
unsigned long off1, off2;
len1 = btrfs_item_size_nr(left_path->nodes[0], left_path->slots[0]);
len2 = btrfs_item_size_nr(right_path->nodes[0], right_path->slots[0]);
if (len1 != len2)
return 1;
off1 = btrfs_item_ptr_offset(left_path->nodes[0], left_path->slots[0]);
off2 = btrfs_item_ptr_offset(right_path->nodes[0],
right_path->slots[0]);
read_extent_buffer(left_path->nodes[0], tmp_buf, off1, len1);
cmp = memcmp_extent_buffer(right_path->nodes[0], tmp_buf, off2, len1);
if (cmp)
return 1;
return 0;
}
int btrfs_compare_trees(struct btrfs_root *left_root,
struct btrfs_root *right_root,
btrfs_changed_cb_t changed_cb, void *ctx)
{
struct btrfs_fs_info *fs_info = left_root->fs_info;
int ret;
int cmp;
struct btrfs_path *left_path = NULL;
struct btrfs_path *right_path = NULL;
struct btrfs_key left_key;
struct btrfs_key right_key;
char *tmp_buf = NULL;
int left_root_level;
int right_root_level;
int left_level;
int right_level;
int left_end_reached;
int right_end_reached;
int advance_left;
int advance_right;
u64 left_blockptr;
u64 right_blockptr;
u64 left_gen;
u64 right_gen;
left_path = btrfs_alloc_path();
if (!left_path) {
ret = -ENOMEM;
goto out;
}
right_path = btrfs_alloc_path();
if (!right_path) {
ret = -ENOMEM;
goto out;
}
tmp_buf = kvmalloc(fs_info->nodesize, GFP_KERNEL);
if (!tmp_buf) {
ret = -ENOMEM;
goto out;
}
left_path->search_commit_root = 1;
left_path->skip_locking = 1;
right_path->search_commit_root = 1;
right_path->skip_locking = 1;
down_read(&fs_info->commit_root_sem);
left_level = btrfs_header_level(left_root->commit_root);
left_root_level = left_level;
left_path->nodes[left_level] = left_root->commit_root;
extent_buffer_get(left_path->nodes[left_level]);
right_level = btrfs_header_level(right_root->commit_root);
right_root_level = right_level;
right_path->nodes[right_level] = right_root->commit_root;
extent_buffer_get(right_path->nodes[right_level]);
up_read(&fs_info->commit_root_sem);
if (left_level == 0)
btrfs_item_key_to_cpu(left_path->nodes[left_level],
&left_key, left_path->slots[left_level]);
else
btrfs_node_key_to_cpu(left_path->nodes[left_level],
&left_key, left_path->slots[left_level]);
if (right_level == 0)
btrfs_item_key_to_cpu(right_path->nodes[right_level],
&right_key, right_path->slots[right_level]);
else
btrfs_node_key_to_cpu(right_path->nodes[right_level],
&right_key, right_path->slots[right_level]);
left_end_reached = right_end_reached = 0;
advance_left = advance_right = 0;
while (1) {
if (advance_left && !left_end_reached) {
ret = tree_advance(fs_info, left_path, &left_level,
left_root_level,
advance_left != ADVANCE_ONLY_NEXT,
&left_key);
if (ret == -1)
left_end_reached = ADVANCE;
else if (ret < 0)
goto out;
advance_left = 0;
}
if (advance_right && !right_end_reached) {
ret = tree_advance(fs_info, right_path, &right_level,
right_root_level,
advance_right != ADVANCE_ONLY_NEXT,
&right_key);
if (ret == -1)
right_end_reached = ADVANCE;
else if (ret < 0)
goto out;
advance_right = 0;
}
if (left_end_reached && right_end_reached) {
ret = 0;
goto out;
} else if (left_end_reached) {
if (right_level == 0) {
ret = changed_cb(left_root, right_root,
left_path, right_path,
&right_key,
BTRFS_COMPARE_TREE_DELETED,
ctx);
if (ret < 0)
goto out;
}
advance_right = ADVANCE;
continue;
} else if (right_end_reached) {
if (left_level == 0) {
ret = changed_cb(left_root, right_root,
left_path, right_path,
&left_key,
BTRFS_COMPARE_TREE_NEW,
ctx);
if (ret < 0)
goto out;
}
advance_left = ADVANCE;
continue;
}
if (left_level == 0 && right_level == 0) {
cmp = btrfs_comp_cpu_keys(&left_key, &right_key);
if (cmp < 0) {
ret = changed_cb(left_root, right_root,
left_path, right_path,
&left_key,
BTRFS_COMPARE_TREE_NEW,
ctx);
if (ret < 0)
goto out;
advance_left = ADVANCE;
} else if (cmp > 0) {
ret = changed_cb(left_root, right_root,
left_path, right_path,
&right_key,
BTRFS_COMPARE_TREE_DELETED,
ctx);
if (ret < 0)
goto out;
advance_right = ADVANCE;
} else {
enum btrfs_compare_tree_result result;
WARN_ON(!extent_buffer_uptodate(left_path->nodes[0]));
ret = tree_compare_item(left_path, right_path,
tmp_buf);
if (ret)
result = BTRFS_COMPARE_TREE_CHANGED;
else
result = BTRFS_COMPARE_TREE_SAME;
ret = changed_cb(left_root, right_root,
left_path, right_path,
&left_key, result, ctx);
if (ret < 0)
goto out;
advance_left = ADVANCE;
advance_right = ADVANCE;
}
} else if (left_level == right_level) {
cmp = btrfs_comp_cpu_keys(&left_key, &right_key);
if (cmp < 0) {
advance_left = ADVANCE;
} else if (cmp > 0) {
advance_right = ADVANCE;
} else {
left_blockptr = btrfs_node_blockptr(
left_path->nodes[left_level],
left_path->slots[left_level]);
right_blockptr = btrfs_node_blockptr(
right_path->nodes[right_level],
right_path->slots[right_level]);
left_gen = btrfs_node_ptr_generation(
left_path->nodes[left_level],
left_path->slots[left_level]);
right_gen = btrfs_node_ptr_generation(
right_path->nodes[right_level],
right_path->slots[right_level]);
if (left_blockptr == right_blockptr &&
left_gen == right_gen) {
advance_left = ADVANCE_ONLY_NEXT;
advance_right = ADVANCE_ONLY_NEXT;
} else {
advance_left = ADVANCE;
advance_right = ADVANCE;
}
}
} else if (left_level < right_level) {
advance_right = ADVANCE;
} else {
advance_left = ADVANCE;
}
}
out:
btrfs_free_path(left_path);
btrfs_free_path(right_path);
kvfree(tmp_buf);
return ret;
}
int btrfs_find_next_key(struct btrfs_root *root, struct btrfs_path *path,
struct btrfs_key *key, int level, u64 min_trans)
{
int slot;
struct extent_buffer *c;
WARN_ON(!path->keep_locks);
while (level < BTRFS_MAX_LEVEL) {
if (!path->nodes[level])
return 1;
slot = path->slots[level] + 1;
c = path->nodes[level];
next:
if (slot >= btrfs_header_nritems(c)) {
int ret;
int orig_lowest;
struct btrfs_key cur_key;
if (level + 1 >= BTRFS_MAX_LEVEL ||
!path->nodes[level + 1])
return 1;
if (path->locks[level + 1]) {
level++;
continue;
}
slot = btrfs_header_nritems(c) - 1;
if (level == 0)
btrfs_item_key_to_cpu(c, &cur_key, slot);
else
btrfs_node_key_to_cpu(c, &cur_key, slot);
orig_lowest = path->lowest_level;
btrfs_release_path(path);
path->lowest_level = level;
ret = btrfs_search_slot(NULL, root, &cur_key, path,
0, 0);
path->lowest_level = orig_lowest;
if (ret < 0)
return ret;
c = path->nodes[level];
slot = path->slots[level];
if (ret == 0)
slot++;
goto next;
}
if (level == 0)
btrfs_item_key_to_cpu(c, key, slot);
else {
u64 gen = btrfs_node_ptr_generation(c, slot);
if (gen < min_trans) {
slot++;
goto next;
}
btrfs_node_key_to_cpu(c, key, slot);
}
return 0;
}
return 1;
}
int btrfs_next_leaf(struct btrfs_root *root, struct btrfs_path *path)
{
return btrfs_next_old_leaf(root, path, 0);
}
int btrfs_next_old_leaf(struct btrfs_root *root, struct btrfs_path *path,
u64 time_seq)
{
int slot;
int level;
struct extent_buffer *c;
struct extent_buffer *next;
struct btrfs_key key;
u32 nritems;
int ret;
int old_spinning = path->leave_spinning;
int next_rw_lock = 0;
nritems = btrfs_header_nritems(path->nodes[0]);
if (nritems == 0)
return 1;
btrfs_item_key_to_cpu(path->nodes[0], &key, nritems - 1);
again:
level = 1;
next = NULL;
next_rw_lock = 0;
btrfs_release_path(path);
path->keep_locks = 1;
path->leave_spinning = 1;
if (time_seq)
ret = btrfs_search_old_slot(root, &key, path, time_seq);
else
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
path->keep_locks = 0;
if (ret < 0)
return ret;
nritems = btrfs_header_nritems(path->nodes[0]);
if (nritems > 0 && path->slots[0] < nritems - 1) {
if (ret == 0)
path->slots[0]++;
ret = 0;
goto done;
}
if (nritems > 0 && ret > 0 && path->slots[0] == nritems - 1) {
ret = 0;
goto done;
}
while (level < BTRFS_MAX_LEVEL) {
if (!path->nodes[level]) {
ret = 1;
goto done;
}
slot = path->slots[level] + 1;
c = path->nodes[level];
if (slot >= btrfs_header_nritems(c)) {
level++;
if (level == BTRFS_MAX_LEVEL) {
ret = 1;
goto done;
}
continue;
}
if (next) {
btrfs_tree_unlock_rw(next, next_rw_lock);
free_extent_buffer(next);
}
next = c;
next_rw_lock = path->locks[level];
ret = read_block_for_search(root, path, &next, level,
slot, &key);
if (ret == -EAGAIN)
goto again;
if (ret < 0) {
btrfs_release_path(path);
goto done;
}
if (!path->skip_locking) {
ret = btrfs_try_tree_read_lock(next);
if (!ret && time_seq) {
free_extent_buffer(next);
btrfs_release_path(path);
cond_resched();
goto again;
}
if (!ret) {
btrfs_set_path_blocking(path);
btrfs_tree_read_lock(next);
btrfs_clear_path_blocking(path, next,
BTRFS_READ_LOCK);
}
next_rw_lock = BTRFS_READ_LOCK;
}
break;
}
path->slots[level] = slot;
while (1) {
level--;
c = path->nodes[level];
if (path->locks[level])
btrfs_tree_unlock_rw(c, path->locks[level]);
free_extent_buffer(c);
path->nodes[level] = next;
path->slots[level] = 0;
if (!path->skip_locking)
path->locks[level] = next_rw_lock;
if (!level)
break;
ret = read_block_for_search(root, path, &next, level,
0, &key);
if (ret == -EAGAIN)
goto again;
if (ret < 0) {
btrfs_release_path(path);
goto done;
}
if (!path->skip_locking) {
ret = btrfs_try_tree_read_lock(next);
if (!ret) {
btrfs_set_path_blocking(path);
btrfs_tree_read_lock(next);
btrfs_clear_path_blocking(path, next,
BTRFS_READ_LOCK);
}
next_rw_lock = BTRFS_READ_LOCK;
}
}
ret = 0;
done:
unlock_up(path, 0, 1, 0, NULL);
path->leave_spinning = old_spinning;
if (!old_spinning)
btrfs_set_path_blocking(path);
return ret;
}
int btrfs_previous_item(struct btrfs_root *root,
struct btrfs_path *path, u64 min_objectid,
int type)
{
struct btrfs_key found_key;
struct extent_buffer *leaf;
u32 nritems;
int ret;
while (1) {
if (path->slots[0] == 0) {
btrfs_set_path_blocking(path);
ret = btrfs_prev_leaf(root, path);
if (ret != 0)
return ret;
} else {
path->slots[0]--;
}
leaf = path->nodes[0];
nritems = btrfs_header_nritems(leaf);
if (nritems == 0)
return 1;
if (path->slots[0] == nritems)
path->slots[0]--;
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
if (found_key.objectid < min_objectid)
break;
if (found_key.type == type)
return 0;
if (found_key.objectid == min_objectid &&
found_key.type < type)
break;
}
return 1;
}
int btrfs_previous_extent_item(struct btrfs_root *root,
struct btrfs_path *path, u64 min_objectid)
{
struct btrfs_key found_key;
struct extent_buffer *leaf;
u32 nritems;
int ret;
while (1) {
if (path->slots[0] == 0) {
btrfs_set_path_blocking(path);
ret = btrfs_prev_leaf(root, path);
if (ret != 0)
return ret;
} else {
path->slots[0]--;
}
leaf = path->nodes[0];
nritems = btrfs_header_nritems(leaf);
if (nritems == 0)
return 1;
if (path->slots[0] == nritems)
path->slots[0]--;
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
if (found_key.objectid < min_objectid)
break;
if (found_key.type == BTRFS_EXTENT_ITEM_KEY ||
found_key.type == BTRFS_METADATA_ITEM_KEY)
return 0;
if (found_key.objectid == min_objectid &&
found_key.type < BTRFS_EXTENT_ITEM_KEY)
break;
}
return 1;
}
