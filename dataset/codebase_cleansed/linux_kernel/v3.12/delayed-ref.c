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
static int comp_entry(struct btrfs_delayed_ref_node *ref2,
struct btrfs_delayed_ref_node *ref1,
bool compare_seq)
{
if (ref1->bytenr < ref2->bytenr)
return -1;
if (ref1->bytenr > ref2->bytenr)
return 1;
if (ref1->is_head && ref2->is_head)
return 0;
if (ref2->is_head)
return -1;
if (ref1->is_head)
return 1;
if (ref1->type < ref2->type)
return -1;
if (ref1->type > ref2->type)
return 1;
if (compare_seq) {
if (ref1->seq < ref2->seq)
return -1;
if (ref1->seq > ref2->seq)
return 1;
}
if (ref1->type == BTRFS_TREE_BLOCK_REF_KEY ||
ref1->type == BTRFS_SHARED_BLOCK_REF_KEY) {
return comp_tree_refs(btrfs_delayed_node_to_tree_ref(ref2),
btrfs_delayed_node_to_tree_ref(ref1),
ref1->type);
} else if (ref1->type == BTRFS_EXTENT_DATA_REF_KEY ||
ref1->type == BTRFS_SHARED_DATA_REF_KEY) {
return comp_data_refs(btrfs_delayed_node_to_data_ref(ref2),
btrfs_delayed_node_to_data_ref(ref1));
}
BUG();
return 0;
}
static struct btrfs_delayed_ref_node *tree_insert(struct rb_root *root,
struct rb_node *node)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent_node = NULL;
struct btrfs_delayed_ref_node *entry;
struct btrfs_delayed_ref_node *ins;
int cmp;
ins = rb_entry(node, struct btrfs_delayed_ref_node, rb_node);
while (*p) {
parent_node = *p;
entry = rb_entry(parent_node, struct btrfs_delayed_ref_node,
rb_node);
cmp = comp_entry(entry, ins, 1);
if (cmp < 0)
p = &(*p)->rb_left;
else if (cmp > 0)
p = &(*p)->rb_right;
else
return entry;
}
rb_link_node(node, parent_node, p);
rb_insert_color(node, root);
return NULL;
}
static struct btrfs_delayed_ref_node *find_ref_head(struct rb_root *root,
u64 bytenr,
struct btrfs_delayed_ref_node **last,
int return_bigger)
{
struct rb_node *n;
struct btrfs_delayed_ref_node *entry;
int cmp = 0;
again:
n = root->rb_node;
entry = NULL;
while (n) {
entry = rb_entry(n, struct btrfs_delayed_ref_node, rb_node);
WARN_ON(!entry->in_tree);
if (last)
*last = entry;
if (bytenr < entry->bytenr)
cmp = -1;
else if (bytenr > entry->bytenr)
cmp = 1;
else if (!btrfs_delayed_ref_is_head(entry))
cmp = 1;
else
cmp = 0;
if (cmp < 0)
n = n->rb_left;
else if (cmp > 0)
n = n->rb_right;
else
return entry;
}
if (entry && return_bigger) {
if (cmp > 0) {
n = rb_next(&entry->rb_node);
if (!n)
n = rb_first(root);
entry = rb_entry(n, struct btrfs_delayed_ref_node,
rb_node);
bytenr = entry->bytenr;
return_bigger = 0;
goto again;
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
struct btrfs_delayed_ref_node *ref)
{
rb_erase(&ref->rb_node, &delayed_refs->root);
ref->in_tree = 0;
btrfs_put_delayed_ref(ref);
delayed_refs->num_entries--;
if (trans->delayed_ref_updates)
trans->delayed_ref_updates--;
}
static int merge_ref(struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_root *delayed_refs,
struct btrfs_delayed_ref_node *ref, u64 seq)
{
struct rb_node *node;
int merged = 0;
int mod = 0;
int done = 0;
node = rb_prev(&ref->rb_node);
while (node) {
struct btrfs_delayed_ref_node *next;
next = rb_entry(node, struct btrfs_delayed_ref_node, rb_node);
node = rb_prev(node);
if (next->bytenr != ref->bytenr)
break;
if (seq && next->seq >= seq)
break;
if (comp_entry(ref, next, 0))
continue;
if (ref->action == next->action) {
mod = next->ref_mod;
} else {
if (ref->ref_mod < next->ref_mod) {
struct btrfs_delayed_ref_node *tmp;
tmp = ref;
ref = next;
next = tmp;
done = 1;
}
mod = -next->ref_mod;
}
merged++;
drop_delayed_ref(trans, delayed_refs, next);
ref->ref_mod += mod;
if (ref->ref_mod == 0) {
drop_delayed_ref(trans, delayed_refs, ref);
break;
} else {
WARN_ON(ref->type == BTRFS_TREE_BLOCK_REF_KEY ||
ref->type == BTRFS_SHARED_BLOCK_REF_KEY);
}
if (done)
break;
node = rb_prev(&ref->rb_node);
}
return merged;
}
void btrfs_merge_delayed_refs(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info,
struct btrfs_delayed_ref_root *delayed_refs,
struct btrfs_delayed_ref_head *head)
{
struct rb_node *node;
u64 seq = 0;
spin_lock(&fs_info->tree_mod_seq_lock);
if (!list_empty(&fs_info->tree_mod_seq_list)) {
struct seq_list *elem;
elem = list_first_entry(&fs_info->tree_mod_seq_list,
struct seq_list, list);
seq = elem->seq;
}
spin_unlock(&fs_info->tree_mod_seq_lock);
node = rb_prev(&head->node.rb_node);
while (node) {
struct btrfs_delayed_ref_node *ref;
ref = rb_entry(node, struct btrfs_delayed_ref_node,
rb_node);
if (ref->bytenr != head->node.bytenr)
break;
if (seq && ref->seq >= seq)
break;
if (merge_ref(trans, delayed_refs, ref, seq))
node = rb_prev(&head->node.rb_node);
else
node = rb_prev(node);
}
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
int btrfs_find_ref_cluster(struct btrfs_trans_handle *trans,
struct list_head *cluster, u64 start)
{
int count = 0;
struct btrfs_delayed_ref_root *delayed_refs;
struct rb_node *node;
struct btrfs_delayed_ref_node *ref;
struct btrfs_delayed_ref_head *head;
delayed_refs = &trans->transaction->delayed_refs;
if (start == 0) {
node = rb_first(&delayed_refs->root);
} else {
ref = NULL;
find_ref_head(&delayed_refs->root, start + 1, &ref, 1);
if (ref) {
node = &ref->rb_node;
} else
node = rb_first(&delayed_refs->root);
}
again:
while (node && count < 32) {
ref = rb_entry(node, struct btrfs_delayed_ref_node, rb_node);
if (btrfs_delayed_ref_is_head(ref)) {
head = btrfs_delayed_node_to_head(ref);
if (list_empty(&head->cluster)) {
list_add_tail(&head->cluster, cluster);
delayed_refs->run_delayed_start =
head->node.bytenr;
count++;
WARN_ON(delayed_refs->num_heads_ready == 0);
delayed_refs->num_heads_ready--;
} else if (count) {
break;
}
}
node = rb_next(node);
}
if (count) {
return 0;
} else if (start) {
start = 0;
node = rb_first(&delayed_refs->root);
goto again;
}
return 1;
}
void btrfs_release_ref_cluster(struct list_head *cluster)
{
struct list_head *pos, *q;
list_for_each_safe(pos, q, cluster)
list_del_init(pos);
}
static noinline void
update_existing_ref(struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_root *delayed_refs,
struct btrfs_delayed_ref_node *existing,
struct btrfs_delayed_ref_node *update)
{
if (update->action != existing->action) {
existing->ref_mod--;
if (existing->ref_mod == 0)
drop_delayed_ref(trans, delayed_refs, existing);
else
WARN_ON(existing->type == BTRFS_TREE_BLOCK_REF_KEY ||
existing->type == BTRFS_SHARED_BLOCK_REF_KEY);
} else {
WARN_ON(existing->type == BTRFS_TREE_BLOCK_REF_KEY ||
existing->type == BTRFS_SHARED_BLOCK_REF_KEY);
existing->ref_mod += update->ref_mod;
}
}
static noinline void
update_existing_head_ref(struct btrfs_delayed_ref_node *existing,
struct btrfs_delayed_ref_node *update)
{
struct btrfs_delayed_ref_head *existing_ref;
struct btrfs_delayed_ref_head *ref;
existing_ref = btrfs_delayed_node_to_head(existing);
ref = btrfs_delayed_node_to_head(update);
BUG_ON(existing_ref->is_data != ref->is_data);
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
existing->ref_mod += update->ref_mod;
}
static noinline void add_delayed_ref_head(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_node *ref,
u64 bytenr, u64 num_bytes,
int action, int is_data)
{
struct btrfs_delayed_ref_node *existing;
struct btrfs_delayed_ref_head *head_ref = NULL;
struct btrfs_delayed_ref_root *delayed_refs;
int count_mod = 1;
int must_insert_reserved = 0;
if (action == BTRFS_UPDATE_DELAYED_HEAD)
count_mod = 0;
else if (action == BTRFS_DROP_DELAYED_REF)
count_mod = -1;
if (action == BTRFS_ADD_DELAYED_EXTENT)
must_insert_reserved = 1;
else
must_insert_reserved = 0;
delayed_refs = &trans->transaction->delayed_refs;
atomic_set(&ref->refs, 1);
ref->bytenr = bytenr;
ref->num_bytes = num_bytes;
ref->ref_mod = count_mod;
ref->type = 0;
ref->action = 0;
ref->is_head = 1;
ref->in_tree = 1;
ref->seq = 0;
head_ref = btrfs_delayed_node_to_head(ref);
head_ref->must_insert_reserved = must_insert_reserved;
head_ref->is_data = is_data;
INIT_LIST_HEAD(&head_ref->cluster);
mutex_init(&head_ref->mutex);
trace_add_delayed_ref_head(ref, head_ref, action);
existing = tree_insert(&delayed_refs->root, &ref->rb_node);
if (existing) {
update_existing_head_ref(existing, ref);
kmem_cache_free(btrfs_delayed_ref_head_cachep, head_ref);
} else {
delayed_refs->num_heads++;
delayed_refs->num_heads_ready++;
delayed_refs->num_entries++;
trans->delayed_ref_updates++;
}
}
static noinline void add_delayed_tree_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_node *ref,
u64 bytenr, u64 num_bytes, u64 parent,
u64 ref_root, int level, int action,
int for_cow)
{
struct btrfs_delayed_ref_node *existing;
struct btrfs_delayed_tree_ref *full_ref;
struct btrfs_delayed_ref_root *delayed_refs;
u64 seq = 0;
if (action == BTRFS_ADD_DELAYED_EXTENT)
action = BTRFS_ADD_DELAYED_REF;
delayed_refs = &trans->transaction->delayed_refs;
atomic_set(&ref->refs, 1);
ref->bytenr = bytenr;
ref->num_bytes = num_bytes;
ref->ref_mod = 1;
ref->action = action;
ref->is_head = 0;
ref->in_tree = 1;
if (need_ref_seq(for_cow, ref_root))
seq = btrfs_get_tree_mod_seq(fs_info, &trans->delayed_ref_elem);
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
existing = tree_insert(&delayed_refs->root, &ref->rb_node);
if (existing) {
update_existing_ref(trans, delayed_refs, existing, ref);
kmem_cache_free(btrfs_delayed_tree_ref_cachep, full_ref);
} else {
delayed_refs->num_entries++;
trans->delayed_ref_updates++;
}
}
static noinline void add_delayed_data_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
struct btrfs_delayed_ref_node *ref,
u64 bytenr, u64 num_bytes, u64 parent,
u64 ref_root, u64 owner, u64 offset,
int action, int for_cow)
{
struct btrfs_delayed_ref_node *existing;
struct btrfs_delayed_data_ref *full_ref;
struct btrfs_delayed_ref_root *delayed_refs;
u64 seq = 0;
if (action == BTRFS_ADD_DELAYED_EXTENT)
action = BTRFS_ADD_DELAYED_REF;
delayed_refs = &trans->transaction->delayed_refs;
atomic_set(&ref->refs, 1);
ref->bytenr = bytenr;
ref->num_bytes = num_bytes;
ref->ref_mod = 1;
ref->action = action;
ref->is_head = 0;
ref->in_tree = 1;
if (need_ref_seq(for_cow, ref_root))
seq = btrfs_get_tree_mod_seq(fs_info, &trans->delayed_ref_elem);
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
existing = tree_insert(&delayed_refs->root, &ref->rb_node);
if (existing) {
update_existing_ref(trans, delayed_refs, existing, ref);
kmem_cache_free(btrfs_delayed_data_ref_cachep, full_ref);
} else {
delayed_refs->num_entries++;
trans->delayed_ref_updates++;
}
}
int btrfs_add_delayed_tree_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
u64 bytenr, u64 num_bytes, u64 parent,
u64 ref_root, int level, int action,
struct btrfs_delayed_extent_op *extent_op,
int for_cow)
{
struct btrfs_delayed_tree_ref *ref;
struct btrfs_delayed_ref_head *head_ref;
struct btrfs_delayed_ref_root *delayed_refs;
BUG_ON(extent_op && extent_op->is_data);
ref = kmem_cache_alloc(btrfs_delayed_tree_ref_cachep, GFP_NOFS);
if (!ref)
return -ENOMEM;
head_ref = kmem_cache_alloc(btrfs_delayed_ref_head_cachep, GFP_NOFS);
if (!head_ref) {
kmem_cache_free(btrfs_delayed_tree_ref_cachep, ref);
return -ENOMEM;
}
head_ref->extent_op = extent_op;
delayed_refs = &trans->transaction->delayed_refs;
spin_lock(&delayed_refs->lock);
add_delayed_ref_head(fs_info, trans, &head_ref->node, bytenr,
num_bytes, action, 0);
add_delayed_tree_ref(fs_info, trans, &ref->node, bytenr,
num_bytes, parent, ref_root, level, action,
for_cow);
spin_unlock(&delayed_refs->lock);
if (need_ref_seq(for_cow, ref_root))
btrfs_qgroup_record_ref(trans, &ref->node, extent_op);
return 0;
}
int btrfs_add_delayed_data_ref(struct btrfs_fs_info *fs_info,
struct btrfs_trans_handle *trans,
u64 bytenr, u64 num_bytes,
u64 parent, u64 ref_root,
u64 owner, u64 offset, int action,
struct btrfs_delayed_extent_op *extent_op,
int for_cow)
{
struct btrfs_delayed_data_ref *ref;
struct btrfs_delayed_ref_head *head_ref;
struct btrfs_delayed_ref_root *delayed_refs;
BUG_ON(extent_op && !extent_op->is_data);
ref = kmem_cache_alloc(btrfs_delayed_data_ref_cachep, GFP_NOFS);
if (!ref)
return -ENOMEM;
head_ref = kmem_cache_alloc(btrfs_delayed_ref_head_cachep, GFP_NOFS);
if (!head_ref) {
kmem_cache_free(btrfs_delayed_data_ref_cachep, ref);
return -ENOMEM;
}
head_ref->extent_op = extent_op;
delayed_refs = &trans->transaction->delayed_refs;
spin_lock(&delayed_refs->lock);
add_delayed_ref_head(fs_info, trans, &head_ref->node, bytenr,
num_bytes, action, 1);
add_delayed_data_ref(fs_info, trans, &ref->node, bytenr,
num_bytes, parent, ref_root, owner, offset,
action, for_cow);
spin_unlock(&delayed_refs->lock);
if (need_ref_seq(for_cow, ref_root))
btrfs_qgroup_record_ref(trans, &ref->node, extent_op);
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
add_delayed_ref_head(fs_info, trans, &head_ref->node, bytenr,
num_bytes, BTRFS_UPDATE_DELAYED_HEAD,
extent_op->is_data);
spin_unlock(&delayed_refs->lock);
return 0;
}
struct btrfs_delayed_ref_head *
btrfs_find_delayed_ref_head(struct btrfs_trans_handle *trans, u64 bytenr)
{
struct btrfs_delayed_ref_node *ref;
struct btrfs_delayed_ref_root *delayed_refs;
delayed_refs = &trans->transaction->delayed_refs;
ref = find_ref_head(&delayed_refs->root, bytenr, NULL, 0);
if (ref)
return btrfs_delayed_node_to_head(ref);
return NULL;
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
