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
unsigned long siboff = get_slot_offset(parent, entry);
if (siboff < RADIX_TREE_MAP_SIZE) {
offset = siboff;
entry = rcu_dereference_raw(parent->slots[offset]);
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
radix_tree_find_next_bit(const unsigned long *addr,
unsigned long size, unsigned long offset)
{
if (!__builtin_constant_p(size))
return find_next_bit(addr, size, offset);
if (offset < size) {
unsigned long tmp;
addr += offset / BITS_PER_LONG;
tmp = *addr >> (offset % BITS_PER_LONG);
if (tmp)
return __ffs(tmp) + offset;
offset = (offset + BITS_PER_LONG) & ~(BITS_PER_LONG - 1);
while (offset < size) {
tmp = *++addr;
if (tmp)
return __ffs(tmp) + offset;
offset += BITS_PER_LONG;
}
}
return size;
}
static void dump_node(struct radix_tree_node *node, unsigned long index)
{
unsigned long i;
pr_debug("radix node: %p offset %d tags %lx %lx %lx shift %d count %d parent %p\n",
node, node->offset,
node->tags[0][0], node->tags[1][0], node->tags[2][0],
node->shift, node->count, node->parent);
for (i = 0; i < RADIX_TREE_MAP_SIZE; i++) {
unsigned long first = index | (i << node->shift);
unsigned long last = first | ((1UL << node->shift) - 1);
void *entry = node->slots[i];
if (!entry)
continue;
if (is_sibling_entry(node, entry)) {
pr_debug("radix sblng %p offset %ld val %p indices %ld-%ld\n",
entry, i,
*(void **)entry_to_node(entry),
first, last);
} else if (!radix_tree_is_internal_node(entry)) {
pr_debug("radix entry %p offset %ld indices %ld-%ld\n",
entry, i, first, last);
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
radix_tree_node_alloc(struct radix_tree_root *root)
{
struct radix_tree_node *ret = NULL;
gfp_t gfp_mask = root_gfp_mask(root);
if (!gfpflags_allow_blocking(gfp_mask) && !in_interrupt()) {
struct radix_tree_preload *rtp;
ret = kmem_cache_alloc(radix_tree_node_cachep,
gfp_mask | __GFP_ACCOUNT | __GFP_NOWARN);
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
ret = kmem_cache_alloc(radix_tree_node_cachep,
gfp_mask | __GFP_ACCOUNT);
out:
BUG_ON(radix_tree_is_internal_node(ret));
return ret;
}
static void radix_tree_node_rcu_free(struct rcu_head *head)
{
struct radix_tree_node *node =
container_of(head, struct radix_tree_node, rcu_head);
int i;
for (i = 0; i < RADIX_TREE_MAX_TAGS; i++)
tag_clear(node, i, 0);
node->slots[0] = NULL;
node->count = 0;
kmem_cache_free(radix_tree_node_cachep, node);
}
static inline void
radix_tree_node_free(struct radix_tree_node *node)
{
call_rcu(&node->rcu_head, radix_tree_node_rcu_free);
}
static int __radix_tree_preload(gfp_t gfp_mask)
{
struct radix_tree_preload *rtp;
struct radix_tree_node *node;
int ret = -ENOMEM;
preempt_disable();
rtp = this_cpu_ptr(&radix_tree_preloads);
while (rtp->nr < RADIX_TREE_PRELOAD_SIZE) {
preempt_enable();
node = kmem_cache_alloc(radix_tree_node_cachep, gfp_mask);
if (node == NULL)
goto out;
preempt_disable();
rtp = this_cpu_ptr(&radix_tree_preloads);
if (rtp->nr < RADIX_TREE_PRELOAD_SIZE) {
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
return __radix_tree_preload(gfp_mask);
}
int radix_tree_maybe_preload(gfp_t gfp_mask)
{
if (gfpflags_allow_blocking(gfp_mask))
return __radix_tree_preload(gfp_mask);
preempt_disable();
return 0;
}
static inline unsigned long shift_maxindex(unsigned int shift)
{
return (RADIX_TREE_MAP_SIZE << shift) - 1;
}
static inline unsigned long node_maxindex(struct radix_tree_node *node)
{
return shift_maxindex(node->shift);
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
struct radix_tree_node *node = radix_tree_node_alloc(root);
if (!node)
return -ENOMEM;
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++) {
if (root_tag_get(root, tag))
tag_set(node, tag, 0);
}
BUG_ON(shift > BITS_PER_LONG);
node->shift = shift;
node->offset = 0;
node->count = 1;
node->parent = NULL;
if (radix_tree_is_internal_node(slot))
entry_to_node(slot)->parent = node;
node->slots[0] = slot;
slot = node_to_entry(node);
rcu_assign_pointer(root->rnode, slot);
shift += RADIX_TREE_MAP_SHIFT;
} while (shift <= maxshift);
out:
return maxshift + RADIX_TREE_MAP_SHIFT;
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
if (max > maxindex) {
int error = radix_tree_extend(root, max, shift);
if (error < 0)
return error;
shift = error;
child = root->rnode;
if (order == shift)
shift += RADIX_TREE_MAP_SHIFT;
}
while (shift > order) {
shift -= RADIX_TREE_MAP_SHIFT;
if (child == NULL) {
child = radix_tree_node_alloc(root);
if (!child)
return -ENOMEM;
child->shift = shift;
child->offset = offset;
child->parent = node;
rcu_assign_pointer(*slot, node_to_entry(child));
if (node)
node->count++;
} else if (!radix_tree_is_internal_node(child))
break;
node = entry_to_node(child);
offset = radix_tree_descend(node, &child, index);
slot = &node->slots[offset];
}
#ifdef CONFIG_RADIX_TREE_MULTIORDER
if (order > shift) {
unsigned i, n = 1 << (order - shift);
offset = offset & ~(n - 1);
slot = &node->slots[offset];
child = node_to_entry(slot);
for (i = 0; i < n; i++) {
if (slot[i])
return -EEXIST;
}
for (i = 1; i < n; i++) {
rcu_assign_pointer(slot[i], child);
node->count++;
}
}
#endif
if (nodep)
*nodep = node;
if (slotp)
*slotp = slot;
return 0;
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
if (*slot != NULL)
return -EEXIST;
rcu_assign_pointer(*slot, item);
if (node) {
unsigned offset = get_slot_offset(node, slot);
node->count++;
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
offset = radix_tree_find_next_bit(
node->tags[tag],
RADIX_TREE_MAP_SIZE,
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
if ((child == NULL) || (child == RADIX_TREE_RETRY))
goto restart;
} while (radix_tree_is_internal_node(child));
iter->index = (index &~ node_maxindex(node)) | (offset << node->shift);
iter->next_index = (index | node_maxindex(node)) + 1;
__set_iter_shift(iter, node->shift);
if (flags & RADIX_TREE_ITER_TAGGED) {
unsigned tag_long, tag_bit;
tag_long = offset / BITS_PER_LONG;
tag_bit = offset % BITS_PER_LONG;
iter->tags = node->tags[tag][tag_long] >> tag_bit;
if (tag_long < RADIX_TREE_TAG_LONGS - 1) {
if (tag_bit)
iter->tags |= node->tags[tag][tag_long + 1] <<
(BITS_PER_LONG - tag_bit);
iter->next_index = index + BITS_PER_LONG;
}
}
return node->slots + offset;
}
unsigned long radix_tree_range_tag_if_tagged(struct radix_tree_root *root,
unsigned long *first_indexp, unsigned long last_index,
unsigned long nr_to_tag,
unsigned int iftag, unsigned int settag)
{
struct radix_tree_node *parent, *node, *child;
unsigned long maxindex;
unsigned long tagged = 0;
unsigned long index = *first_indexp;
radix_tree_load_root(root, &child, &maxindex);
last_index = min(last_index, maxindex);
if (index > last_index)
return 0;
if (!nr_to_tag)
return 0;
if (!root_tag_get(root, iftag)) {
*first_indexp = last_index + 1;
return 0;
}
if (!radix_tree_is_internal_node(child)) {
*first_indexp = last_index + 1;
root_tag_set(root, settag);
return 1;
}
node = entry_to_node(child);
for (;;) {
unsigned offset = radix_tree_descend(node, &child, index);
if (!child)
goto next;
if (!tag_get(node, iftag, offset))
goto next;
if (radix_tree_is_internal_node(child)) {
node = entry_to_node(child);
continue;
}
tagged++;
tag_set(node, settag, offset);
parent = node;
for (;;) {
offset = parent->offset;
parent = parent->parent;
if (!parent)
break;
if (tag_get(parent, settag, offset))
break;
tag_set(parent, settag, offset);
}
next:
index = ((index >> node->shift) + 1) << node->shift;
if (index > last_index || !index)
break;
offset = (index >> node->shift) & RADIX_TREE_MAP_MASK;
while (offset == 0) {
node = node->parent;
offset = (index >> node->shift) & RADIX_TREE_MAP_MASK;
}
if (is_sibling_entry(node, node->slots[offset]))
goto next;
if (tagged >= nr_to_tag)
break;
}
if (tagged > 0)
root_tag_set(root, settag);
*first_indexp = index;
return tagged;
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
static unsigned long __locate(struct radix_tree_node *slot, void *item,
unsigned long index, struct locate_info *info)
{
unsigned long i;
do {
unsigned int shift = slot->shift;
for (i = (index >> shift) & RADIX_TREE_MAP_MASK;
i < RADIX_TREE_MAP_SIZE;
i++, index += (1UL << shift)) {
struct radix_tree_node *node =
rcu_dereference_raw(slot->slots[i]);
if (node == RADIX_TREE_RETRY)
goto out;
if (!radix_tree_is_internal_node(node)) {
if (node == item) {
info->found_index = index;
info->stop = true;
goto out;
}
continue;
}
node = entry_to_node(node);
if (is_sibling_entry(slot, node))
continue;
slot = node;
break;
}
} while (i < RADIX_TREE_MAP_SIZE);
out:
if ((index == 0) && (i == RADIX_TREE_MAP_SIZE))
info->stop = true;
return index;
}
unsigned long radix_tree_locate_item(struct radix_tree_root *root, void *item)
{
struct radix_tree_node *node;
unsigned long max_index;
unsigned long cur_index = 0;
struct locate_info info = {
.found_index = -1,
.stop = false,
};
do {
rcu_read_lock();
node = rcu_dereference_raw(root->rnode);
if (!radix_tree_is_internal_node(node)) {
rcu_read_unlock();
if (node == item)
info.found_index = 0;
break;
}
node = entry_to_node(node);
max_index = node_maxindex(node);
if (cur_index > max_index) {
rcu_read_unlock();
break;
}
cur_index = __locate(node, item, cur_index, &info);
rcu_read_unlock();
cond_resched();
} while (!info.stop && cur_index <= max_index);
return info.found_index;
}
unsigned long radix_tree_locate_item(struct radix_tree_root *root, void *item)
{
return -1;
}
static inline bool radix_tree_shrink(struct radix_tree_root *root)
{
bool shrunk = false;
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
if (!radix_tree_is_internal_node(child))
node->slots[0] = RADIX_TREE_RETRY;
radix_tree_node_free(node);
shrunk = true;
}
return shrunk;
}
bool __radix_tree_delete_node(struct radix_tree_root *root,
struct radix_tree_node *node)
{
bool deleted = false;
do {
struct radix_tree_node *parent;
if (node->count) {
if (node == entry_to_node(root->rnode))
deleted |= radix_tree_shrink(root);
return deleted;
}
parent = node->parent;
if (parent) {
parent->slots[node->offset] = NULL;
parent->count--;
} else {
root_tag_clear_all(root);
root->rnode = NULL;
}
radix_tree_node_free(node);
deleted = true;
node = parent;
} while (node);
return deleted;
}
static inline void delete_sibling_entries(struct radix_tree_node *node,
void *ptr, unsigned offset)
{
#ifdef CONFIG_RADIX_TREE_MULTIORDER
int i;
for (i = 1; offset + i < RADIX_TREE_MAP_SIZE; i++) {
if (node->slots[offset + i] != ptr)
break;
node->slots[offset + i] = NULL;
node->count--;
}
#endif
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
delete_sibling_entries(node, node_to_entry(slot), offset);
node->slots[offset] = NULL;
node->count--;
__radix_tree_delete_node(root, node);
return entry;
}
void *radix_tree_delete(struct radix_tree_root *root, unsigned long index)
{
return radix_tree_delete_item(root, index, NULL);
}
struct radix_tree_node *radix_tree_replace_clear_tags(
struct radix_tree_root *root,
unsigned long index, void *entry)
{
struct radix_tree_node *node;
void **slot;
__radix_tree_lookup(root, index, &node, &slot);
if (node) {
unsigned int tag, offset = get_slot_offset(node, slot);
for (tag = 0; tag < RADIX_TREE_MAX_TAGS; tag++)
node_tag_clear(root, node, tag, offset);
} else {
root->gfp_mask &= __GFP_BITS_MASK;
}
radix_tree_replace_slot(slot, entry);
return node;
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
static int radix_tree_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
int cpu = (long)hcpu;
struct radix_tree_preload *rtp;
struct radix_tree_node *node;
if (action == CPU_DEAD || action == CPU_DEAD_FROZEN) {
rtp = &per_cpu(radix_tree_preloads, cpu);
while (rtp->nr) {
node = rtp->nodes;
rtp->nodes = node->private_data;
kmem_cache_free(radix_tree_node_cachep, node);
rtp->nr--;
}
}
return NOTIFY_OK;
}
void __init radix_tree_init(void)
{
radix_tree_node_cachep = kmem_cache_create("radix_tree_node",
sizeof(struct radix_tree_node), 0,
SLAB_PANIC | SLAB_RECLAIM_ACCOUNT,
radix_tree_node_ctor);
hotcpu_notifier(radix_tree_callback, 0);
}
