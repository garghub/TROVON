static int comp_tree_refs(struct btrfs_delayed_tree_ref *ref2,
struct btrfs_delayed_tree_ref *ref1, int type)
{
if (type == BTRFS_TREE_BLOCK_REF_KEY) {
if (ref1->root < ref2->root)
return -1;
if (ref1->root > ref2->root)
return 1;
} else {
if (ref1->parent < ref2->parent)
return -1;
if (ref1->parent > ref2->parent)
return 1;
}
return 0;
}
static int comp_data_refs(struct btrfs_delayed_data_ref *ref2,
struct btrfs_delayed_data_ref *ref1)
{
if (ref1->node.type == BTRFS_EXTENT_DATA_REF_KEY) {
if (ref1->root < ref2->root)
return -1;
if (ref1->root > ref2->root)
return 1;
if (ref1->objectid < ref2->objectid)
return -1;
if (ref1->objectid > ref2->objectid)
return 1;
if (ref1->offset < ref2->offset)
return -1;
if (ref1->offset > ref2->offset)
return 1;
} else {
if (ref1->parent < ref2->parent)
return -1;
if (ref1->parent > ref2->parent)
return 1;
}
return 0;
}
static struct btrfs_delayed_ref_head *htree_insert(struct rb_root *root,
struct rb_node *node)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent_node = NULL;
struct btrfs_delayed_ref_head *entry;
struct btrfs_delayed_ref_head *ins;
u64 bytenr;
ins = rb_entry(node, struct btrfs_delayed_ref_head, href_node);
bytenr = ins->node.bytenr;
while (*p) {
parent_node = *p;
entry = rb_entry(parent_node, struct btrfs_delayed_ref_head,
href_node);
if (bytenr < entry->node.bytenr)
p = &(*p)->rb_left;
else if (bytenr > entry->node.bytenr)
p = &(*p)->rb_right;
else
return entry;
}
rb_link_node(node, parent_node, p);
rb_insert_color(node, root);
return NULL;
}
static struct btrfs_delayed_ref_head *
find_ref_head(struct rb_root *root, u64 bytenr,
int return_bigger)
{
struct rb_node *n;
struct btrfs_delayed_ref_head *entry;
n = root->rb_node;
entry = NULL;
while (n) {
entry = rb_entry(n, struct btrfs_delayed_ref_head, href_node);
if (bytenr < entry->node.bytenr)
n = n->rb_left;
else if (bytenr > entry->node.bytenr)
n = n->rb_right;
else
return entry;
}
if (entry && return_bigger) {
if (bytenr > entry->node.bytenr) {
n = rb_next(&entry->href_node);
if (!n)
n = rb_first(root);
entry = rb_entry(n, struct btrfs_delayed_ref_head,
href_node);
return entry;
}
return entry;
}
return NULL;
}
int btrfs_delayed_ref_lock(struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_head *head)
{
struct btrfs_delayed_ref_root *delayed_refs;
delayed_refs = &trans->transaction->delayed_refs;
assert_spin_locked(&delayed_refs->lock);
if (mutex_trylock(&head->mutex))
return 0;
atomic_inc(&head->node.refs);
spin_unlock(&delayed_refs->lock);
mutex_lock(&head->mutex);
spin_lock(&delayed_refs->lock);
if (!head->node.in_tree) {
mutex_unlock(&head->mutex);
btrfs_put_delayed_ref(&head->node);
return -EAGAIN;
}
btrfs_put_delayed_ref(&head->node);
return 0;
}
static inline void drop_delayed_ref(struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_root *delayed_refs,
struct btrfs_delayed_ref_head *head,
struct btrfs_delayed_ref_node *ref)
{
if (btrfs_delayed_ref_is_head(ref)) {
head = btrfs_delayed_node_to_head(ref);
rb_erase(&head->href_node, &delayed_refs->href_root);
} else {
assert_spin_locked(&head->lock);
list_del(&ref->list);
}
ref->in_tree = 0;
btrfs_put_delayed_ref(ref);
atomic_dec(&delayed_refs->num_entries);
if (trans->delayed_ref_updates)
trans->delayed_ref_updates--;
}
int btrfs_check_delayed_seq(struct btrfs_fs_info *fs_info,
struct btrfs_delayed_ref_root *delayed_refs,
u64 seq)
{
struct seq_list *elem;
int ret = 0;
spin_lock(&fs_info->tree_mod_seq_lock);
if (!list_empty(&fs_info->tree_mod_seq_list)) {
elem = list_first_entry(&fs_info->tree_mod_seq_list,
struct seq_list, list);
if (seq >= elem->seq) {
pr_debug("holding back delayed_ref %#x.%x, lowest is %#x.%x (%p)\n",
(u32)(seq >> 32), (u32)seq,
(u32)(elem->seq >> 32), (u32)elem->seq,
delayed_refs);
ret = 1;
}
}
spin_unlock(&fs_info->tree_mod_seq_lock);
return ret;
}
struct btrfs_delayed_ref_head *
btrfs_select_ref_head(struct btrfs_trans_handle *trans)
{
struct btrfs_delayed_ref_root *delayed_refs;
struct btrfs_delayed_ref_head *head;
u64 start;
bool loop = false;
delayed_refs = &trans->transaction->delayed_refs;
again:
start = delayed_refs->run_delayed_start;
head = find_ref_head(&delayed_refs->href_root, start, 1);
if (!head && !loop) {
delayed_refs->run_delayed_start = 0;
start = 0;
loop = true;
head = find_ref_head(&delayed_refs->href_root, start, 1);
if (!head)
return NULL;
} else if (!head && loop) {
return NULL;
}
while (head->processing) {
struct rb_node *node;
node = rb_next(&head->href_node);
if (!node) {
if (loop)
return NULL;
delayed_refs->run_delayed_start = 0;
start = 0;
loop = true;
goto again;
}
head = rb_entry(node, struct btrfs_delayed_ref_head,
href_node);
}
head->processing = 1;
WARN_ON(delayed_refs->num_heads_ready == 0);
delayed_refs->num_heads_ready--;
delayed_refs->run_delayed_start = head->node.bytenr +
head->node.num_bytes;
return head;
}
static int
add_delayed_ref_tail_merge(struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_root *root,
struct btrfs_delayed_ref_head *href,
struct btrfs_delayed_ref_node *ref)
{
struct btrfs_delayed_ref_node *exist;
int mod;
int ret = 0;
spin_lock(&href->lock);
if (list_empty(&href->ref_list))
goto add_tail;
exist = list_entry(href->ref_list.prev, struct btrfs_delayed_ref_node,
list);
if (exist->type != ref->type || exist->no_quota != ref->no_quota ||
exist->seq != ref->seq)
goto add_tail;
if ((exist->type == BTRFS_TREE_BLOCK_REF_KEY ||
exist->type == BTRFS_SHARED_BLOCK_REF_KEY) &&
comp_tree_refs(btrfs_delayed_node_to_tree_ref(exist),
btrfs_delayed_node_to_tree_ref(ref),
ref->type))
goto add_tail;
if ((exist->type == BTRFS_EXTENT_DATA_REF_KEY ||
exist->type == BTRFS_SHARED_DATA_REF_KEY) &&
comp_data_refs(btrfs_delayed_node_to_data_ref(exist),
btrfs_delayed_node_to_data_ref(ref)))
goto add_tail;
ret = 1;
if (exist->action == ref->action) {
mod = ref->ref_mod;
} else {
if (exist->ref_mod < ref->ref_mod) {
exist->action = ref->action;
mod = -exist->ref_mod;
exist->ref_mod = ref->ref_mod;
} else
mod = -ref->ref_mod;
}
exist->ref_mod += mod;
if (exist->ref_mod == 0)
drop_delayed_ref(trans, root, href, exist);
spin_unlock(&href->lock);
return ret;
add_tail:
list_add_tail(&ref->list, &href->ref_list);
atomic_inc(&root->num_entries);
trans->delayed_ref_updates++;
spin_unlock(&href->lock);
return ret;
}
static noinline void
update_existing_head_ref(struct btrfs_delayed_ref_root *delayed_refs,
struct btrfs_delayed_ref_node *existing,
struct btrfs_delayed_ref_node *update)
{
struct btrfs_delayed_ref_head *existing_ref;
struct btrfs_delayed_ref_head *ref;
int old_ref_mod;
existing_ref = btrfs_delayed_node_to_head(existing);
ref = btrfs_delayed_node_to_head(update);
BUG_ON(existing_ref->is_data != ref->is_data);
spin_lock(&existing_ref->lock);
if (ref->must_insert_reserved) {
existing_ref->must_insert_reserved = ref->must_insert_reserved;
existing->num_bytes = update->num_bytes;
}
if (ref->extent_op) {
if (!existing_ref->extent_op) {
existing_ref->extent_op = ref->extent_op;
} else {
if (ref->extent_op->update_key) {
memcpy(&existing_ref->extent_op->key,
&ref->extent_op->key,
sizeof(ref->extent_op->key));
existing_ref->extent_op->update_key = 1;
}
if (ref->extent_op->update_flags) {
existing_ref->extent_op->flags_to_set |=
ref->extent_op->flags_to_set;
existing_ref->extent_op->update_flags = 1;
}
btrfs_free_delayed_extent_op(ref->extent_op);
}
}
old_ref_mod = existing_ref->total_ref_mod;
existing->ref_mod += update->ref_mod;
existing_ref->total_ref_mod += update->ref_mod;
if (existing_ref->is_data) {
if (existing_ref->total_ref_mod >= 0 && old_ref_mod < 0)
delayed_refs->pending_csums -= existing->num_bytes;
if (existing_ref->total_ref_mod < 0 && old_ref_mod >= 0)
delayed_refs->pending_csums += existing->num_bytes;
}
spin_unlock(&existing_ref->lock);
}
noinline void
add_delayed_tree_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_head *head_ref,
struct btrfs_delayed_ref_node *ref, u64 bytenr,
u64 num_bytes, u64 parent, u64 ref_root, int level,
int action, int no_quota)
{
struct btrfs_delayed_tree_ref *full_ref;
struct btrfs_delayed_ref_root *delayed_refs;
u64 seq = 0;
int ret;
if (action == BTRFS_ADD_DELAYED_EXTENT)
action = BTRFS_ADD_DELAYED_REF;
if (is_fstree(ref_root))
seq = atomic64_read(&fs_info->tree_mod_seq);
delayed_refs = &trans->transaction->delayed_refs;
atomic_set(&ref->refs, 1);
ref->bytenr = bytenr;
ref->num_bytes = num_bytes;
ref->ref_mod = 1;
ref->action = action;
ref->is_head = 0;
ref->in_tree = 1;
ref->no_quota = no_quota;
ref->seq = seq;
full_ref = btrfs_delayed_node_to_tree_ref(ref);
full_ref->parent = parent;
full_ref->root = ref_root;
if (parent)
ref->type = BTRFS_SHARED_BLOCK_REF_KEY;
else
ref->type = BTRFS_TREE_BLOCK_REF_KEY;
full_ref->level = level;
trace_add_delayed_tree_ref(ref, full_ref, action);
ret = add_delayed_ref_tail_merge(trans, delayed_refs, head_ref, ref);
if (ret > 0)
kmem_cache_free(btrfs_delayed_tree_ref_cachep, full_ref);
}
static noinline void
add_delayed_data_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_head *head_ref,
struct btrfs_delayed_ref_node *ref, u64 bytenr,
u64 num_bytes, u64 parent, u64 ref_root, u64 owner,
u64 offset, int action, int no_quota)
{
struct btrfs_delayed_data_ref *full_ref;
struct btrfs_delayed_ref_root *delayed_refs;
u64 seq = 0;
int ret;
if (action == BTRFS_ADD_DELAYED_EXTENT)
action = BTRFS_ADD_DELAYED_REF;
delayed_refs = &trans->transaction->delayed_refs;
if (is_fstree(ref_root))
seq = atomic64_read(&fs_info->tree_mod_seq);
atomic_set(&ref->refs, 1);
ref->bytenr = bytenr;
ref->num_bytes = num_bytes;
ref->ref_mod = 1;
ref->action = action;
ref->is_head = 0;
ref->in_tree = 1;
ref->no_quota = no_quota;
ref->seq = seq;
full_ref = btrfs_delayed_node_to_data_ref(ref);
full_ref->parent = parent;
full_ref->root = ref_root;
if (parent)
ref->type = BTRFS_SHARED_DATA_REF_KEY;
else
ref->type = BTRFS_EXTENT_DATA_REF_KEY;
full_ref->objectid = owner;
full_ref->offset = offset;
trace_add_delayed_data_ref(ref, full_ref, action);
ret = add_delayed_ref_tail_merge(trans, delayed_refs, head_ref, ref);
if (ret > 0)
kmem_cache_free(btrfs_delayed_data_ref_cachep, full_ref);
}
int btrfs_add_delayed_tree_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
u64 bytenr, u64 num_bytes, u64 parent,
u64 ref_root, int level, int action,
struct btrfs_delayed_extent_op *extent_op,
int no_quota)
{
struct btrfs_delayed_tree_ref *ref;
struct btrfs_delayed_ref_head *head_ref;
struct btrfs_delayed_ref_root *delayed_refs;
struct btrfs_qgroup_extent_record *record = NULL;
if (!is_fstree(ref_root) || !fs_info->quota_enabled)
no_quota = 0;
BUG_ON(extent_op && extent_op->is_data);
ref = kmem_cache_alloc(btrfs_delayed_tree_ref_cachep, GFP_NOFS);
if (!ref)
return -ENOMEM;
head_ref = kmem_cache_alloc(btrfs_delayed_ref_head_cachep, GFP_NOFS);
if (!head_ref)
goto free_ref;
if (fs_info->quota_enabled && is_fstree(ref_root)) {
record = kmalloc(sizeof(*record), GFP_NOFS);
if (!record)
goto free_head_ref;
}
head_ref->extent_op = extent_op;
delayed_refs = &trans->transaction->delayed_refs;
spin_lock(&delayed_refs->lock);
head_ref = add_delayed_ref_head(fs_info, trans, &head_ref->node, record,
bytenr, num_bytes, action, 0);
add_delayed_tree_ref(fs_info, trans, head_ref, &ref->node, bytenr,
num_bytes, parent, ref_root, level, action,
no_quota);
spin_unlock(&delayed_refs->lock);
return 0;
free_head_ref:
kmem_cache_free(btrfs_delayed_ref_head_cachep, head_ref);
free_ref:
kmem_cache_free(btrfs_delayed_tree_ref_cachep, ref);
return -ENOMEM;
}
int btrfs_add_delayed_data_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
u64 bytenr, u64 num_bytes,
u64 parent, u64 ref_root,
u64 owner, u64 offset, int action,
struct btrfs_delayed_extent_op *extent_op,
int no_quota)
{
struct btrfs_delayed_data_ref *ref;
struct btrfs_delayed_ref_head *head_ref;
struct btrfs_delayed_ref_root *delayed_refs;
struct btrfs_qgroup_extent_record *record = NULL;
if (!is_fstree(ref_root) || !fs_info->quota_enabled)
no_quota = 0;
BUG_ON(extent_op && !extent_op->is_data);
ref = kmem_cache_alloc(btrfs_delayed_data_ref_cachep, GFP_NOFS);
if (!ref)
return -ENOMEM;
head_ref = kmem_cache_alloc(btrfs_delayed_ref_head_cachep, GFP_NOFS);
if (!head_ref) {
kmem_cache_free(btrfs_delayed_data_ref_cachep, ref);
return -ENOMEM;
}
if (fs_info->quota_enabled && is_fstree(ref_root)) {
record = kmalloc(sizeof(*record), GFP_NOFS);
if (!record) {
kmem_cache_free(btrfs_delayed_data_ref_cachep, ref);
kmem_cache_free(btrfs_delayed_ref_head_cachep,
head_ref);
return -ENOMEM;
}
}
head_ref->extent_op = extent_op;
delayed_refs = &trans->transaction->delayed_refs;
spin_lock(&delayed_refs->lock);
head_ref = add_delayed_ref_head(fs_info, trans, &head_ref->node, record,
bytenr, num_bytes, action, 1);
add_delayed_data_ref(fs_info, trans, head_ref, &ref->node, bytenr,
num_bytes, parent, ref_root, owner, offset,
action, no_quota);
spin_unlock(&delayed_refs->lock);
return 0;
}
int btrfs_add_delayed_extent_op(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
u64 bytenr, u64 num_bytes,
struct btrfs_delayed_extent_op *extent_op)
{
struct btrfs_delayed_ref_head *head_ref;
struct btrfs_delayed_ref_root *delayed_refs;
head_ref = kmem_cache_alloc(btrfs_delayed_ref_head_cachep, GFP_NOFS);
if (!head_ref)
return -ENOMEM;
head_ref->extent_op = extent_op;
delayed_refs = &trans->transaction->delayed_refs;
spin_lock(&delayed_refs->lock);
add_delayed_ref_head(fs_info, trans, &head_ref->node, NULL, bytenr,
num_bytes, BTRFS_UPDATE_DELAYED_HEAD,
extent_op->is_data);
spin_unlock(&delayed_refs->lock);
return 0;
}
struct btrfs_delayed_ref_head *
btrfs_find_delayed_ref_head(struct btrfs_trans_handle *trans, u64 bytenr)
{
struct btrfs_delayed_ref_root *delayed_refs;
delayed_refs = &trans->transaction->delayed_refs;
return find_ref_head(&delayed_refs->href_root, bytenr, 0);
}
void btrfs_delayed_ref_exit(void)
{
if (btrfs_delayed_ref_head_cachep)
kmem_cache_destroy(btrfs_delayed_ref_head_cachep);
if (btrfs_delayed_tree_ref_cachep)
kmem_cache_destroy(btrfs_delayed_tree_ref_cachep);
if (btrfs_delayed_data_ref_cachep)
kmem_cache_destroy(btrfs_delayed_data_ref_cachep);
if (btrfs_delayed_extent_op_cachep)
kmem_cache_destroy(btrfs_delayed_extent_op_cachep);
}
int btrfs_delayed_ref_init(void)
{
btrfs_delayed_ref_head_cachep = kmem_cache_create(
"btrfs_delayed_ref_head",
sizeof(struct btrfs_delayed_ref_head), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!btrfs_delayed_ref_head_cachep)
goto fail;
btrfs_delayed_tree_ref_cachep = kmem_cache_create(
"btrfs_delayed_tree_ref",
sizeof(struct btrfs_delayed_tree_ref), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!btrfs_delayed_tree_ref_cachep)
goto fail;
btrfs_delayed_data_ref_cachep = kmem_cache_create(
"btrfs_delayed_data_ref",
sizeof(struct btrfs_delayed_data_ref), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!btrfs_delayed_data_ref_cachep)
goto fail;
btrfs_delayed_extent_op_cachep = kmem_cache_create(
"btrfs_delayed_extent_op",
sizeof(struct btrfs_delayed_extent_op), 0,
SLAB_RECLAIM_ACCOUNT | SLAB_MEM_SPREAD, NULL);
if (!btrfs_delayed_extent_op_cachep)
goto fail;
return 0;
fail:
btrfs_delayed_ref_exit();
return -ENOMEM;
}
