static inline struct radix_tree_node *entry_to_node(void *ptr)
{
return (void *)((unsigned long)ptr & ~RADIX_TREE_INTERNAL_NODE);
}
static inline void *node_to_entry(void *ptr)
{
return (void *)((unsigned long)ptr | RADIX_TREE_INTERNAL_NODE);
}
static inline bool is_sibling_entry(struct radix_tree_node *parent, void *node)
{
void **ptr = node;
return (parent->slots <= ptr) &&
(ptr < parent->slots + RADIX_TREE_MAP_SIZE);
}
static inline bool is_sibling_entry(struct radix_tree_node *parent, void *node)
{
return false;
}
static inline unsigned long get_slot_offset(struct radix_tree_node *parent,
void **slot)
{
return slot - parent->slots;
}
static unsigned int radix_tree_descend(struct radix_tree_node *parent,
struct radix_tree_node **nodep, unsigned long index)
{
unsigned int offset = (index >> parent->shift) & RADIX_TREE_MAP_MASK;
void **entry = rcu_dereference_raw(parent->slots[offset]);
#ifdef CONFIG_RADIX_TREE_MULTIORDER
if (radix_tree_is_internal_node(entry)) {
if (is_sibling_entry(parent, entry)) {
void **sibentry = (void **) entry_to_node(entry);
offset = get_slot_offset(parent, sibentry);
entry = rcu_dereference_raw(*sibentry);
}
}
#endif
*nodep = (void *)entry;
return offset;
}
static inline gfp_t root_gfp_mask(struct radix_tree_root *root)
{
return root->gfp_mask & __GFP_BITS_MASK;
}
static inline void tag_set(struct radix_tree_node *node, unsigned int tag,
int offset)
{
__set_bit(offset, node->tags[tag]);
}
static inline void tag_clear(struct radix_tree_node *node, unsigned int tag,
int offset)
{
__clear_bit(offset, node->tags[tag]);
}
static inline int tag_get(struct radix_tree_node *node, unsigned int tag,
int offset)
{
return test_bit(offset, node->tags[tag]);
}
static inline void root_tag_set(struct radix_tree_root *root, unsigned int tag)
{
root->gfp_mask |= (__force gfp_t)(1 << (tag + __GFP_BITS_SHIFT));
}
static inline void root_tag_clear(struct radix_tree_root *root, unsigned tag)
{
root->gfp_mask &= (__force gfp_t)~(1 << (tag + __GFP_BITS_SHIFT));
}
static inline void root_tag_clear_all(struct radix_tree_root *root)
{
root->gfp_mask &= __GFP_BITS_MASK;
}
static inline int root_tag_get(struct radix_tree_root *root, unsigned int tag)
{
return (__force int)root->gfp_mask & (1 << (tag + __GFP_BITS_SHIFT));
}
static inline unsigned root_tags_get(struct radix_tree_root *root)
{
return (__force unsigned)root->gfp_mask >> __GFP_BITS_SHIFT;
}
static inline int any_tag_set(struct radix_tree_node *node, unsigned int tag)
{
unsigned idx;
for (idx = 0; idx < RADIX_TREE_TAG_LONGS; idx++) {
if (node->tags[tag][idx])
return 1;
}
return 0;
}
static __always_inline unsigned long
radix_tree_find_next_bit(struct radix_tree_node *node, unsigned int tag,
unsigned long offset)
{
const unsigned long *addr = node->tags[tag];
if (offset < RADIX_TREE_MAP_SIZE) {
unsigned long tmp;
addr += offset / BITS_PER_LONG;
tmp = *addr >> (offset % BITS_PER_LONG);
if (tmp)
return __ffs(tmp) + offset;
offset = (offset + BITS_PER_LONG) & ~(BITS_PER_LONG - 1);
while (offset < RADIX_TREE_MAP_SIZE) {
tmp = *++addr;
if (tmp)
return __ffs(tmp) + offset;
offset += BITS_PER_LONG;
}
}
return RADIX_TREE_MAP_SIZE;
}
static unsigned int iter_offset(const struct radix_tree_iter *iter)
{
return (iter->index >> iter_shift(iter)) & RADIX_TREE_MAP_MASK;
}
static inline unsigned long shift_maxindex(unsigned int shift)
{
return (RADIX_TREE_MAP_SIZE << shift) - 1;
}
static inline unsigned long node_maxindex(struct radix_tree_node *node)
{
return shift_maxindex(node->shift);
}
static void dump_node(struct radix_tree_node *node, unsigned long index)
{
unsigned long i;
pr_debug("radix node: %p offset %d indices %lu-%lu parent %p tags %lx %lx %lx shift %d count %d exceptional %d\n",
node, node->offset, index, index | node_maxindex(node),
node->parent,
node->tags[0][0], node->tags[1][0], node->tags[2][0],
node->shift, node->count, node->exceptional);
for (i = 0; i < RADIX_TREE_MAP_SIZE; i++) {
unsigned long first = index | (i << node->shift);
unsigned long last = first | ((1UL << node->shift) - 1);
void *entry = node->slots[i];
if (!entry)
continue;
if (entry == RADIX_TREE_RETRY) {
pr_debug("radix retry offset %ld indices %lu-%lu parent %p\n",
i, first, last, node);
} else if (!radix_tree_is_internal_node(entry)) {
pr_debug("radix entry %p offset %ld indices %lu-%lu parent %p\n",
entry, i, first, last, node);
} else if (is_sibling_entry(node, entry)) {
pr_debug("radix sblng %p offset %ld indices %lu-%lu parent %p val %p\n",
entry, i, first, last, node,
*(void **)entry_to_node(entry));
} else {
dump_node(entry_to_node(entry), first);
}
}
}
static void radix_tree_dump(struct radix_tree_root *root)
{
pr_debug("radix root: %p rnode %p tags %x\n",
root, root->rnode,
root->gfp_mask >> __GFP_BITS_SHIFT);
if (!radix_tree_is_internal_node(root->rnode))
return;
dump_node(entry_to_node(root->rnode), 0);
}
static struct radix_tree_node *
radix_tree_node_alloc(struct radix_tree_root *root,
struct radix_tree_node *parent,
unsigned int shift, unsigned int offset,
unsigned int count, unsigned int exceptional)
{
struct radix_tree_node *ret = NULL;
gfp_t gfp_mask = root_gfp_mask(root);
if (!gfpflags_allow_blocking(gfp_mask) && !in_interrupt()) {
struct radix_tree_preload *rtp;
ret = kmem_cache_alloc(radix_tree_node_cachep,
gfp_mask | __GFP_NOWARN);
if (ret)
goto out;
rtp = this_cpu_ptr(&radix_tree_preloads);
if (rtp->nr) {
ret = rtp->nodes;
rtp->nodes = ret->private_data;
ret->private_data = NULL;
rtp->nr--;
}
kmemleak_update_trace(ret);
goto out;
}
ret = kmem_cache_alloc(radix_tree_node_cachep, gfp_mask);
out:
BUG_ON(radix_tree_is_internal_node(ret));
if (ret) {
ret->parent = parent;
ret->shift = shift;
ret->offset = offset;
ret->count = count;
ret->exceptional = exceptional;
}
return ret;
}
static void radix_tree_node_rcu_free(struct rcu_head *head)
{
struct radix_tree_node *node =
container_of(head, struct radix_tree_node, rcu_head);
memset(node->slots, 0, sizeof(node->slots));
memset(node->tags, 0, sizeof(node->tags));
INIT_LIST_HEAD(&node->private_list);
kmem_cache_free(radix_tree_node_cachep, node);
}
static inline void
radix_tree_node_free(struct radix_tree_node *node)
{
call_rcu(&node->rcu_head, radix_tree_node_rcu_free);
}
static int __radix_tree_preload(gfp_t gfp_mask, unsigned nr)
{
struct radix_tree_preload *rtp;
struct radix_tree_node *node;
int ret = -ENOMEM;
gfp_mask &= ~__GFP_ACCOUNT;
preempt_disable();
rtp = this_cpu_ptr(&radix_tree_preloads);
while (rtp->nr < nr) {
preempt_enable();
node = kmem_cache_alloc(radix_tree_node_cachep, gfp_mask);
if (node == NULL)
goto out;
preempt_disable();
rtp = this_cpu_ptr(&radix_tree_preloads);
if (rtp->nr < nr) {
node->private_data = rtp->nodes;
rtp->nodes = node;
rtp->nr++;
} else {
kmem_cache_free(radix_tree_node_cachep, node);
}
}
ret = 0;
out:
return ret;
}
int radix_tree_preload(gfp_t gfp_mask)
{
WARN_ON_ONCE(!gfpflags_allow_blocking(gfp_mask));
return __radix_tree_preload(gfp_mask, RADIX_TREE_PRELOAD_SIZE);
}
int radix_tree_maybe_preload(gfp_t gfp_mask)
{
if (gfpflags_allow_blocking(gfp_mask))
return __radix_tree_preload(gfp_mask, RADIX_TREE_PRELOAD_SIZE);
preempt_disable();
return 0;
}
int radix_tree_split_preload(unsigned int old_order, unsigned int new_order,
gfp_t gfp_mask)
{
unsigned top = 1 << (old_order % RADIX_TREE_MAP_SHIFT);
unsigned layers = (old_order / RADIX_TREE_MAP_SHIFT) -
(new_order / RADIX_TREE_MAP_SHIFT);
unsigned nr = 0;
WARN_ON_ONCE(!gfpflags_allow_blocking(gfp_mask));
BUG_ON(new_order >= old_order);
while (layers--)
nr = nr * RADIX_TREE_MAP_SIZE + 1;
return __radix_tree_preload(gfp_mask, top * nr);
}
int radix_tree_maybe_preload_order(gfp_t gfp_mask, int order)
{
unsigned long nr_subtrees;
int nr_nodes, subtree_height;
if (!gfpflags_allow_blocking(gfp_mask)) {
preempt_disable();
return 0;
}
nr_subtrees = 1 << order;
for (subtree_height = 0; nr_subtrees > RADIX_TREE_MAP_SIZE;
subtree_height++)
nr_subtrees >>= RADIX_TREE_MAP_SHIFT;
nr_nodes = RADIX_TREE_MAX_PATH;
nr_nodes += RADIX_TREE_MAX_PATH - subtree_height;
nr_nodes--;
nr_nodes += nr_subtrees * height_to_maxnodes[subtree_height];
return __radix_tree_preload(gfp_mask, nr_nodes);
}
static unsigned radix_tree_load_root(struct radix_tree_root *root,
struct radix_tree_node **nodep, unsigned long *maxindex)
{
struct radix_tree_node *node = rcu_dereference_raw(root->rnode);
*nodep = node;
if (likely(radix_tree_is_internal_node(node))) {
node = entry_to_node(node);
*maxindex = node_maxindex(node);
return node->shift + RADIX_TREE_MAP_SHIFT;
}
*maxindex = 0;
return 0;
}
static int radix_tree_extend(struct radix_tree_root *root,
unsigned long index, unsigned int shift)
{
struct radix_tree_node *slot;
unsigned int maxshift;
int tag;
maxshift = shift;
while (index > shift_maxindex(maxshift))
maxshift += RADIX_TREE_MAP_SHIFT;
slot = root->rnode;
if (!slot)
goto out;
do {
struct radix_tree_node *node = radix_tree_node_alloc(root,
NULL, shift, 0, 1, 0);
if (!node)
return -ENOMEM;
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++) {
if (root_tag_get(root, tag))
tag_set(node, tag, 0);
}
BUG_ON(shift > BITS_PER_LONG);
if (radix_tree_is_internal_node(slot)) {
entry_to_node(slot)->parent = node;
} else if (radix_tree_exceptional_entry(slot)) {
node->exceptional = 1;
}
node->slots[0] = slot;
slot = node_to_entry(node);
rcu_assign_pointer(root->rnode, slot);
shift += RADIX_TREE_MAP_SHIFT;
} while (shift <= maxshift);
out:
return maxshift + RADIX_TREE_MAP_SHIFT;
}
static inline void radix_tree_shrink(struct radix_tree_root *root,
radix_tree_update_node_t update_node,
void *private)
{
for (;;) {
struct radix_tree_node *node = root->rnode;
struct radix_tree_node *child;
if (!radix_tree_is_internal_node(node))
break;
node = entry_to_node(node);
if (node->count != 1)
break;
child = node->slots[0];
if (!child)
break;
if (!radix_tree_is_internal_node(child) && node->shift)
break;
if (radix_tree_is_internal_node(child))
entry_to_node(child)->parent = NULL;
root->rnode = child;
node->count = 0;
if (!radix_tree_is_internal_node(child)) {
node->slots[0] = RADIX_TREE_RETRY;
if (update_node)
update_node(node, private);
}
WARN_ON_ONCE(!list_empty(&node->private_list));
radix_tree_node_free(node);
}
}
static void delete_node(struct radix_tree_root *root,
struct radix_tree_node *node,
radix_tree_update_node_t update_node, void *private)
{
do {
struct radix_tree_node *parent;
if (node->count) {
if (node == entry_to_node(root->rnode))
radix_tree_shrink(root, update_node, private);
return;
}
parent = node->parent;
if (parent) {
parent->slots[node->offset] = NULL;
parent->count--;
} else {
root_tag_clear_all(root);
root->rnode = NULL;
}
WARN_ON_ONCE(!list_empty(&node->private_list));
radix_tree_node_free(node);
node = parent;
} while (node);
}
int __radix_tree_create(struct radix_tree_root *root, unsigned long index,
unsigned order, struct radix_tree_node **nodep,
void ***slotp)
{
struct radix_tree_node *node = NULL, *child;
void **slot = (void **)&root->rnode;
unsigned long maxindex;
unsigned int shift, offset = 0;
unsigned long max = index | ((1UL << order) - 1);
shift = radix_tree_load_root(root, &child, &maxindex);
if (order > 0 && max == ((1UL << order) - 1))
max++;
if (max > maxindex) {
int error = radix_tree_extend(root, max, shift);
if (error < 0)
return error;
shift = error;
child = root->rnode;
}
while (shift > order) {
shift -= RADIX_TREE_MAP_SHIFT;
if (child == NULL) {
child = radix_tree_node_alloc(root, node, shift,
offset, 0, 0);
if (!child)
return -ENOMEM;
rcu_assign_pointer(*slot, node_to_entry(child));
if (node)
node->count++;
} else if (!radix_tree_is_internal_node(child))
break;
node = entry_to_node(child);
offset = radix_tree_descend(node, &child, index);
slot = &node->slots[offset];
}
if (nodep)
*nodep = node;
if (slotp)
*slotp = slot;
return 0;
}
static void radix_tree_free_nodes(struct radix_tree_node *node)
{
unsigned offset = 0;
struct radix_tree_node *child = entry_to_node(node);
for (;;) {
void *entry = child->slots[offset];
if (radix_tree_is_internal_node(entry) &&
!is_sibling_entry(child, entry)) {
child = entry_to_node(entry);
offset = 0;
continue;
}
offset++;
while (offset == RADIX_TREE_MAP_SIZE) {
struct radix_tree_node *old = child;
offset = child->offset + 1;
child = child->parent;
WARN_ON_ONCE(!list_empty(&old->private_list));
radix_tree_node_free(old);
if (old == entry_to_node(node))
return;
}
}
}
static inline int insert_entries(struct radix_tree_node *node, void **slot,
void *item, unsigned order, bool replace)
{
struct radix_tree_node *child;
unsigned i, n, tag, offset, tags = 0;
if (node) {
if (order > node->shift)
n = 1 << (order - node->shift);
else
n = 1;
offset = get_slot_offset(node, slot);
} else {
n = 1;
offset = 0;
}
if (n > 1) {
offset = offset & ~(n - 1);
slot = &node->slots[offset];
}
child = node_to_entry(slot);
for (i = 0; i < n; i++) {
if (slot[i]) {
if (replace) {
node->count--;
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tag_get(node, tag, offset + i))
tags |= 1 << tag;
} else
return -EEXIST;
}
}
for (i = 0; i < n; i++) {
struct radix_tree_node *old = slot[i];
if (i) {
rcu_assign_pointer(slot[i], child);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tags & (1 << tag))
tag_clear(node, tag, offset + i);
} else {
rcu_assign_pointer(slot[i], item);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tags & (1 << tag))
tag_set(node, tag, offset);
}
if (radix_tree_is_internal_node(old) &&
!is_sibling_entry(node, old) &&
(old != RADIX_TREE_RETRY))
radix_tree_free_nodes(old);
if (radix_tree_exceptional_entry(old))
node->exceptional--;
}
if (node) {
node->count += n;
if (radix_tree_exceptional_entry(item))
node->exceptional += n;
}
return n;
}
static inline int insert_entries(struct radix_tree_node *node, void **slot,
void *item, unsigned order, bool replace)
{
if (*slot)
return -EEXIST;
rcu_assign_pointer(*slot, item);
if (node) {
node->count++;
if (radix_tree_exceptional_entry(item))
node->exceptional++;
}
return 1;
}
int __radix_tree_insert(struct radix_tree_root *root, unsigned long index,
unsigned order, void *item)
{
struct radix_tree_node *node;
void **slot;
int error;
BUG_ON(radix_tree_is_internal_node(item));
error = __radix_tree_create(root, index, order, &node, &slot);
if (error)
return error;
error = insert_entries(node, slot, item, order, false);
if (error < 0)
return error;
if (node) {
unsigned offset = get_slot_offset(node, slot);
BUG_ON(tag_get(node, 0, offset));
BUG_ON(tag_get(node, 1, offset));
BUG_ON(tag_get(node, 2, offset));
} else {
BUG_ON(root_tags_get(root));
}
return 0;
}
void *__radix_tree_lookup(struct radix_tree_root *root, unsigned long index,
struct radix_tree_node **nodep, void ***slotp)
{
struct radix_tree_node *node, *parent;
unsigned long maxindex;
void **slot;
restart:
parent = NULL;
slot = (void **)&root->rnode;
radix_tree_load_root(root, &node, &maxindex);
if (index > maxindex)
return NULL;
while (radix_tree_is_internal_node(node)) {
unsigned offset;
if (node == RADIX_TREE_RETRY)
goto restart;
parent = entry_to_node(node);
offset = radix_tree_descend(parent, &node, index);
slot = parent->slots + offset;
}
if (nodep)
*nodep = parent;
if (slotp)
*slotp = slot;
return node;
}
void **radix_tree_lookup_slot(struct radix_tree_root *root, unsigned long index)
{
void **slot;
if (!__radix_tree_lookup(root, index, NULL, &slot))
return NULL;
return slot;
}
void *radix_tree_lookup(struct radix_tree_root *root, unsigned long index)
{
return __radix_tree_lookup(root, index, NULL, NULL);
}
static inline int slot_count(struct radix_tree_node *node,
void **slot)
{
int n = 1;
#ifdef CONFIG_RADIX_TREE_MULTIORDER
void *ptr = node_to_entry(slot);
unsigned offset = get_slot_offset(node, slot);
int i;
for (i = 1; offset + i < RADIX_TREE_MAP_SIZE; i++) {
if (node->slots[offset + i] != ptr)
break;
n++;
}
#endif
return n;
}
static void replace_slot(struct radix_tree_root *root,
struct radix_tree_node *node,
void **slot, void *item,
bool warn_typeswitch)
{
void *old = rcu_dereference_raw(*slot);
int count, exceptional;
WARN_ON_ONCE(radix_tree_is_internal_node(item));
count = !!item - !!old;
exceptional = !!radix_tree_exceptional_entry(item) -
!!radix_tree_exceptional_entry(old);
WARN_ON_ONCE(warn_typeswitch && (count || exceptional));
if (node) {
node->count += count;
if (exceptional) {
exceptional *= slot_count(node, slot);
node->exceptional += exceptional;
}
}
rcu_assign_pointer(*slot, item);
}
static inline void delete_sibling_entries(struct radix_tree_node *node,
void **slot)
{
#ifdef CONFIG_RADIX_TREE_MULTIORDER
bool exceptional = radix_tree_exceptional_entry(*slot);
void *ptr = node_to_entry(slot);
unsigned offset = get_slot_offset(node, slot);
int i;
for (i = 1; offset + i < RADIX_TREE_MAP_SIZE; i++) {
if (node->slots[offset + i] != ptr)
break;
node->slots[offset + i] = NULL;
node->count--;
if (exceptional)
node->exceptional--;
}
#endif
}
void __radix_tree_replace(struct radix_tree_root *root,
struct radix_tree_node *node,
void **slot, void *item,
radix_tree_update_node_t update_node, void *private)
{
if (!item)
delete_sibling_entries(node, slot);
replace_slot(root, node, slot, item,
!node && slot != (void **)&root->rnode);
if (!node)
return;
if (update_node)
update_node(node, private);
delete_node(root, node, update_node, private);
}
void radix_tree_replace_slot(struct radix_tree_root *root,
void **slot, void *item)
{
replace_slot(root, NULL, slot, item, true);
}
void radix_tree_iter_replace(struct radix_tree_root *root,
const struct radix_tree_iter *iter, void **slot, void *item)
{
__radix_tree_replace(root, iter->node, slot, item, NULL, NULL);
}
int radix_tree_join(struct radix_tree_root *root, unsigned long index,
unsigned order, void *item)
{
struct radix_tree_node *node;
void **slot;
int error;
BUG_ON(radix_tree_is_internal_node(item));
error = __radix_tree_create(root, index, order, &node, &slot);
if (!error)
error = insert_entries(node, slot, item, order, true);
if (error > 0)
error = 0;
return error;
}
int radix_tree_split(struct radix_tree_root *root, unsigned long index,
unsigned order)
{
struct radix_tree_node *parent, *node, *child;
void **slot;
unsigned int offset, end;
unsigned n, tag, tags = 0;
if (!__radix_tree_lookup(root, index, &parent, &slot))
return -ENOENT;
if (!parent)
return -ENOENT;
offset = get_slot_offset(parent, slot);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tag_get(parent, tag, offset))
tags |= 1 << tag;
for (end = offset + 1; end < RADIX_TREE_MAP_SIZE; end++) {
if (!is_sibling_entry(parent, parent->slots[end]))
break;
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tags & (1 << tag))
tag_set(parent, tag, end);
rcu_assign_pointer(parent->slots[end], RADIX_TREE_RETRY);
}
rcu_assign_pointer(parent->slots[offset], RADIX_TREE_RETRY);
parent->exceptional -= (end - offset);
if (order == parent->shift)
return 0;
if (order > parent->shift) {
while (offset < end)
offset += insert_entries(parent, &parent->slots[offset],
RADIX_TREE_RETRY, order, true);
return 0;
}
node = parent;
for (;;) {
if (node->shift > order) {
child = radix_tree_node_alloc(root, node,
node->shift - RADIX_TREE_MAP_SHIFT,
offset, 0, 0);
if (!child)
goto nomem;
if (node != parent) {
node->count++;
node->slots[offset] = node_to_entry(child);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tags & (1 << tag))
tag_set(node, tag, offset);
}
node = child;
offset = 0;
continue;
}
n = insert_entries(node, &node->slots[offset],
RADIX_TREE_RETRY, order, false);
BUG_ON(n > RADIX_TREE_MAP_SIZE);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
if (tags & (1 << tag))
tag_set(node, tag, offset);
offset += n;
while (offset == RADIX_TREE_MAP_SIZE) {
if (node == parent)
break;
offset = node->offset;
child = node;
node = node->parent;
rcu_assign_pointer(node->slots[offset],
node_to_entry(child));
offset++;
}
if ((node == parent) && (offset == end))
return 0;
}
nomem:
WARN_ON(1);
return -ENOMEM;
}
void *radix_tree_tag_set(struct radix_tree_root *root,
unsigned long index, unsigned int tag)
{
struct radix_tree_node *node, *parent;
unsigned long maxindex;
radix_tree_load_root(root, &node, &maxindex);
BUG_ON(index > maxindex);
while (radix_tree_is_internal_node(node)) {
unsigned offset;
parent = entry_to_node(node);
offset = radix_tree_descend(parent, &node, index);
BUG_ON(!node);
if (!tag_get(parent, tag, offset))
tag_set(parent, tag, offset);
}
if (!root_tag_get(root, tag))
root_tag_set(root, tag);
return node;
}
static void node_tag_clear(struct radix_tree_root *root,
struct radix_tree_node *node,
unsigned int tag, unsigned int offset)
{
while (node) {
if (!tag_get(node, tag, offset))
return;
tag_clear(node, tag, offset);
if (any_tag_set(node, tag))
return;
offset = node->offset;
node = node->parent;
}
if (root_tag_get(root, tag))
root_tag_clear(root, tag);
}
static void node_tag_set(struct radix_tree_root *root,
struct radix_tree_node *node,
unsigned int tag, unsigned int offset)
{
while (node) {
if (tag_get(node, tag, offset))
return;
tag_set(node, tag, offset);
offset = node->offset;
node = node->parent;
}
if (!root_tag_get(root, tag))
root_tag_set(root, tag);
}
void radix_tree_iter_tag_set(struct radix_tree_root *root,
const struct radix_tree_iter *iter, unsigned int tag)
{
node_tag_set(root, iter->node, tag, iter_offset(iter));
}
void *radix_tree_tag_clear(struct radix_tree_root *root,
unsigned long index, unsigned int tag)
{
struct radix_tree_node *node, *parent;
unsigned long maxindex;
int uninitialized_var(offset);
radix_tree_load_root(root, &node, &maxindex);
if (index > maxindex)
return NULL;
parent = NULL;
while (radix_tree_is_internal_node(node)) {
parent = entry_to_node(node);
offset = radix_tree_descend(parent, &node, index);
}
if (node)
node_tag_clear(root, parent, tag, offset);
return node;
}
int radix_tree_tag_get(struct radix_tree_root *root,
unsigned long index, unsigned int tag)
{
struct radix_tree_node *node, *parent;
unsigned long maxindex;
if (!root_tag_get(root, tag))
return 0;
radix_tree_load_root(root, &node, &maxindex);
if (index > maxindex)
return 0;
if (node == NULL)
return 0;
while (radix_tree_is_internal_node(node)) {
unsigned offset;
parent = entry_to_node(node);
offset = radix_tree_descend(parent, &node, index);
if (!node)
return 0;
if (!tag_get(parent, tag, offset))
return 0;
if (node == RADIX_TREE_RETRY)
break;
}
return 1;
}
static inline void __set_iter_shift(struct radix_tree_iter *iter,
unsigned int shift)
{
#ifdef CONFIG_RADIX_TREE_MULTIORDER
iter->shift = shift;
#endif
}
static void set_iter_tags(struct radix_tree_iter *iter,
struct radix_tree_node *node, unsigned offset,
unsigned tag)
{
unsigned tag_long = offset / BITS_PER_LONG;
unsigned tag_bit = offset % BITS_PER_LONG;
iter->tags = node->tags[tag][tag_long] >> tag_bit;
if (tag_long < RADIX_TREE_TAG_LONGS - 1) {
if (tag_bit)
iter->tags |= node->tags[tag][tag_long + 1] <<
(BITS_PER_LONG - tag_bit);
iter->next_index = __radix_tree_iter_add(iter, BITS_PER_LONG);
}
}
static void **skip_siblings(struct radix_tree_node **nodep,
void **slot, struct radix_tree_iter *iter)
{
void *sib = node_to_entry(slot - 1);
while (iter->index < iter->next_index) {
*nodep = rcu_dereference_raw(*slot);
if (*nodep && *nodep != sib)
return slot;
slot++;
iter->index = __radix_tree_iter_add(iter, 1);
iter->tags >>= 1;
}
*nodep = NULL;
return NULL;
}
void ** __radix_tree_next_slot(void **slot, struct radix_tree_iter *iter,
unsigned flags)
{
unsigned tag = flags & RADIX_TREE_ITER_TAG_MASK;
struct radix_tree_node *node = rcu_dereference_raw(*slot);
slot = skip_siblings(&node, slot, iter);
while (radix_tree_is_internal_node(node)) {
unsigned offset;
unsigned long next_index;
if (node == RADIX_TREE_RETRY)
return slot;
node = entry_to_node(node);
iter->node = node;
iter->shift = node->shift;
if (flags & RADIX_TREE_ITER_TAGGED) {
offset = radix_tree_find_next_bit(node, tag, 0);
if (offset == RADIX_TREE_MAP_SIZE)
return NULL;
slot = &node->slots[offset];
iter->index = __radix_tree_iter_add(iter, offset);
set_iter_tags(iter, node, offset, tag);
node = rcu_dereference_raw(*slot);
} else {
offset = 0;
slot = &node->slots[0];
for (;;) {
node = rcu_dereference_raw(*slot);
if (node)
break;
slot++;
offset++;
if (offset == RADIX_TREE_MAP_SIZE)
return NULL;
}
iter->index = __radix_tree_iter_add(iter, offset);
}
if ((flags & RADIX_TREE_ITER_CONTIG) && (offset > 0))
goto none;
next_index = (iter->index | shift_maxindex(iter->shift)) + 1;
if (next_index < iter->next_index)
iter->next_index = next_index;
}
return slot;
none:
iter->next_index = 0;
return NULL;
}
static void **skip_siblings(struct radix_tree_node **nodep,
void **slot, struct radix_tree_iter *iter)
{
return slot;
}
void **radix_tree_iter_resume(void **slot, struct radix_tree_iter *iter)
{
struct radix_tree_node *node;
slot++;
iter->index = __radix_tree_iter_add(iter, 1);
node = rcu_dereference_raw(*slot);
skip_siblings(&node, slot, iter);
iter->next_index = iter->index;
iter->tags = 0;
return NULL;
}
void **radix_tree_next_chunk(struct radix_tree_root *root,
struct radix_tree_iter *iter, unsigned flags)
{
unsigned tag = flags & RADIX_TREE_ITER_TAG_MASK;
struct radix_tree_node *node, *child;
unsigned long index, offset, maxindex;
if ((flags & RADIX_TREE_ITER_TAGGED) && !root_tag_get(root, tag))
return NULL;
index = iter->next_index;
if (!index && iter->index)
return NULL;
restart:
radix_tree_load_root(root, &child, &maxindex);
if (index > maxindex)
return NULL;
if (!child)
return NULL;
if (!radix_tree_is_internal_node(child)) {
iter->index = index;
iter->next_index = maxindex + 1;
iter->tags = 1;
iter->node = NULL;
__set_iter_shift(iter, 0);
return (void **)&root->rnode;
}
do {
node = entry_to_node(child);
offset = radix_tree_descend(node, &child, index);
if ((flags & RADIX_TREE_ITER_TAGGED) ?
!tag_get(node, tag, offset) : !child) {
if (flags & RADIX_TREE_ITER_CONTIG)
return NULL;
if (flags & RADIX_TREE_ITER_TAGGED)
offset = radix_tree_find_next_bit(node, tag,
offset + 1);
else
while (++offset < RADIX_TREE_MAP_SIZE) {
void *slot = node->slots[offset];
if (is_sibling_entry(node, slot))
continue;
if (slot)
break;
}
index &= ~node_maxindex(node);
index += offset << node->shift;
if (!index)
return NULL;
if (offset == RADIX_TREE_MAP_SIZE)
goto restart;
child = rcu_dereference_raw(node->slots[offset]);
}
if (!child)
goto restart;
if (child == RADIX_TREE_RETRY)
break;
} while (radix_tree_is_internal_node(child));
iter->index = (index &~ node_maxindex(node)) | (offset << node->shift);
iter->next_index = (index | node_maxindex(node)) + 1;
iter->node = node;
__set_iter_shift(iter, node->shift);
if (flags & RADIX_TREE_ITER_TAGGED)
set_iter_tags(iter, node, offset, tag);
return node->slots + offset;
}
unsigned int
radix_tree_gang_lookup(struct radix_tree_root *root, void **results,
unsigned long first_index, unsigned int max_items)
{
struct radix_tree_iter iter;
void **slot;
unsigned int ret = 0;
if (unlikely(!max_items))
return 0;
radix_tree_for_each_slot(slot, root, &iter, first_index) {
results[ret] = rcu_dereference_raw(*slot);
if (!results[ret])
continue;
if (radix_tree_is_internal_node(results[ret])) {
slot = radix_tree_iter_retry(&iter);
continue;
}
if (++ret == max_items)
break;
}
return ret;
}
unsigned int
radix_tree_gang_lookup_slot(struct radix_tree_root *root,
void ***results, unsigned long *indices,
unsigned long first_index, unsigned int max_items)
{
struct radix_tree_iter iter;
void **slot;
unsigned int ret = 0;
if (unlikely(!max_items))
return 0;
radix_tree_for_each_slot(slot, root, &iter, first_index) {
results[ret] = slot;
if (indices)
indices[ret] = iter.index;
if (++ret == max_items)
break;
}
return ret;
}
unsigned int
radix_tree_gang_lookup_tag(struct radix_tree_root *root, void **results,
unsigned long first_index, unsigned int max_items,
unsigned int tag)
{
struct radix_tree_iter iter;
void **slot;
unsigned int ret = 0;
if (unlikely(!max_items))
return 0;
radix_tree_for_each_tagged(slot, root, &iter, first_index, tag) {
results[ret] = rcu_dereference_raw(*slot);
if (!results[ret])
continue;
if (radix_tree_is_internal_node(results[ret])) {
slot = radix_tree_iter_retry(&iter);
continue;
}
if (++ret == max_items)
break;
}
return ret;
}
unsigned int
radix_tree_gang_lookup_tag_slot(struct radix_tree_root *root, void ***results,
unsigned long first_index, unsigned int max_items,
unsigned int tag)
{
struct radix_tree_iter iter;
void **slot;
unsigned int ret = 0;
if (unlikely(!max_items))
return 0;
radix_tree_for_each_tagged(slot, root, &iter, first_index, tag) {
results[ret] = slot;
if (++ret == max_items)
break;
}
return ret;
}
void __radix_tree_delete_node(struct radix_tree_root *root,
struct radix_tree_node *node,
radix_tree_update_node_t update_node,
void *private)
{
delete_node(root, node, update_node, private);
}
void *radix_tree_delete_item(struct radix_tree_root *root,
unsigned long index, void *item)
{
struct radix_tree_node *node;
unsigned int offset;
void **slot;
void *entry;
int tag;
entry = __radix_tree_lookup(root, index, &node, &slot);
if (!entry)
return NULL;
if (item && entry != item)
return NULL;
if (!node) {
root_tag_clear_all(root);
root->rnode = NULL;
return entry;
}
offset = get_slot_offset(node, slot);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
node_tag_clear(root, node, tag, offset);
__radix_tree_replace(root, node, slot, NULL, NULL, NULL);
return entry;
}
void *radix_tree_delete(struct radix_tree_root *root, unsigned long index)
{
return radix_tree_delete_item(root, index, NULL);
}
void radix_tree_clear_tags(struct radix_tree_root *root,
struct radix_tree_node *node,
void **slot)
{
if (node) {
unsigned int tag, offset = get_slot_offset(node, slot);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
node_tag_clear(root, node, tag, offset);
} else {
root->gfp_mask &= __GFP_BITS_MASK;
}
}
int radix_tree_tagged(struct radix_tree_root *root, unsigned int tag)
{
return root_tag_get(root, tag);
}
static void
radix_tree_node_ctor(void *arg)
{
struct radix_tree_node *node = arg;
memset(node, 0, sizeof(*node));
INIT_LIST_HEAD(&node->private_list);
}
static __init unsigned long __maxindex(unsigned int height)
{
unsigned int width = height * RADIX_TREE_MAP_SHIFT;
int shift = RADIX_TREE_INDEX_BITS - width;
if (shift < 0)
return ~0UL;
if (shift >= BITS_PER_LONG)
return 0UL;
return ~0UL >> shift;
}
static __init void radix_tree_init_maxnodes(void)
{
unsigned long height_to_maxindex[RADIX_TREE_MAX_PATH + 1];
unsigned int i, j;
for (i = 0; i < ARRAY_SIZE(height_to_maxindex); i++)
height_to_maxindex[i] = __maxindex(i);
for (i = 0; i < ARRAY_SIZE(height_to_maxnodes); i++) {
for (j = i; j > 0; j--)
height_to_maxnodes[i] += height_to_maxindex[j - 1] + 1;
}
}
static int radix_tree_cpu_dead(unsigned int cpu)
{
struct radix_tree_preload *rtp;
struct radix_tree_node *node;
rtp = &per_cpu(radix_tree_preloads, cpu);
while (rtp->nr) {
node = rtp->nodes;
rtp->nodes = node->private_data;
kmem_cache_free(radix_tree_node_cachep, node);
rtp->nr--;
}
return 0;
}
void __init radix_tree_init(void)
{
int ret;
radix_tree_node_cachep = kmem_cache_create("radix_tree_node",
sizeof(struct radix_tree_node), 0,
SLAB_PANIC | SLAB_RECLAIM_ACCOUNT,
radix_tree_node_ctor);
radix_tree_init_maxnodes();
ret = cpuhp_setup_state_nocalls(CPUHP_RADIX_DEAD, "lib/radix:dead",
NULL, radix_tree_cpu_dead);
WARN_ON(ret < 0);
}
