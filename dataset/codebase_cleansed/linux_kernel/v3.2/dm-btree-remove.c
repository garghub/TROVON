static void node_shift(struct node *n, int shift)
{
uint32_t nr_entries = le32_to_cpu(n->header.nr_entries);
uint32_t value_size = le32_to_cpu(n->header.value_size);
if (shift < 0) {
shift = -shift;
BUG_ON(shift > nr_entries);
BUG_ON((void *) key_ptr(n, shift) >= value_ptr(n, shift, value_size));
memmove(key_ptr(n, 0),
key_ptr(n, shift),
(nr_entries - shift) * sizeof(__le64));
memmove(value_ptr(n, 0, value_size),
value_ptr(n, shift, value_size),
(nr_entries - shift) * value_size);
} else {
BUG_ON(nr_entries + shift > le32_to_cpu(n->header.max_entries));
memmove(key_ptr(n, shift),
key_ptr(n, 0),
nr_entries * sizeof(__le64));
memmove(value_ptr(n, shift, value_size),
value_ptr(n, 0, value_size),
nr_entries * value_size);
}
}
static void node_copy(struct node *left, struct node *right, int shift)
{
uint32_t nr_left = le32_to_cpu(left->header.nr_entries);
uint32_t value_size = le32_to_cpu(left->header.value_size);
BUG_ON(value_size != le32_to_cpu(right->header.value_size));
if (shift < 0) {
shift = -shift;
BUG_ON(nr_left + shift > le32_to_cpu(left->header.max_entries));
memcpy(key_ptr(left, nr_left),
key_ptr(right, 0),
shift * sizeof(__le64));
memcpy(value_ptr(left, nr_left, value_size),
value_ptr(right, 0, value_size),
shift * value_size);
} else {
BUG_ON(shift > le32_to_cpu(right->header.max_entries));
memcpy(key_ptr(right, 0),
key_ptr(left, nr_left - shift),
shift * sizeof(__le64));
memcpy(value_ptr(right, 0, value_size),
value_ptr(left, nr_left - shift, value_size),
shift * value_size);
}
}
static void delete_at(struct node *n, unsigned index)
{
unsigned nr_entries = le32_to_cpu(n->header.nr_entries);
unsigned nr_to_copy = nr_entries - (index + 1);
uint32_t value_size = le32_to_cpu(n->header.value_size);
BUG_ON(index >= nr_entries);
if (nr_to_copy) {
memmove(key_ptr(n, index),
key_ptr(n, index + 1),
nr_to_copy * sizeof(__le64));
memmove(value_ptr(n, index, value_size),
value_ptr(n, index + 1, value_size),
nr_to_copy * value_size);
}
n->header.nr_entries = cpu_to_le32(nr_entries - 1);
}
static unsigned del_threshold(struct node *n)
{
return le32_to_cpu(n->header.max_entries) / 3;
}
static unsigned merge_threshold(struct node *n)
{
return 2 * (le32_to_cpu(n->header.max_entries) / 3) + 1;
}
static int init_child(struct dm_btree_info *info, struct node *parent,
unsigned index, struct child *result)
{
int r, inc;
dm_block_t root;
result->index = index;
root = value64(parent, index);
r = dm_tm_shadow_block(info->tm, root, &btree_node_validator,
&result->block, &inc);
if (r)
return r;
result->n = dm_block_data(result->block);
if (inc)
inc_children(info->tm, result->n, &le64_type);
*((__le64 *) value_ptr(parent, index, sizeof(__le64))) =
cpu_to_le64(dm_block_location(result->block));
return 0;
}
static int exit_child(struct dm_btree_info *info, struct child *c)
{
return dm_tm_unlock(info->tm, c->block);
}
static void shift(struct node *left, struct node *right, int count)
{
if (!count)
return;
if (count > 0) {
node_shift(right, count);
node_copy(left, right, count);
} else {
node_copy(left, right, count);
node_shift(right, count);
}
left->header.nr_entries =
cpu_to_le32(le32_to_cpu(left->header.nr_entries) - count);
BUG_ON(le32_to_cpu(left->header.nr_entries) > le32_to_cpu(left->header.max_entries));
right->header.nr_entries =
cpu_to_le32(le32_to_cpu(right->header.nr_entries) + count);
BUG_ON(le32_to_cpu(right->header.nr_entries) > le32_to_cpu(right->header.max_entries));
}
static void __rebalance2(struct dm_btree_info *info, struct node *parent,
struct child *l, struct child *r)
{
struct node *left = l->n;
struct node *right = r->n;
uint32_t nr_left = le32_to_cpu(left->header.nr_entries);
uint32_t nr_right = le32_to_cpu(right->header.nr_entries);
if (nr_left + nr_right <= merge_threshold(left)) {
node_copy(left, right, -nr_right);
left->header.nr_entries = cpu_to_le32(nr_left + nr_right);
delete_at(parent, r->index);
dm_tm_dec(info->tm, dm_block_location(r->block));
} else {
unsigned target_left = (nr_left + nr_right) / 2;
unsigned shift_ = nr_left - target_left;
BUG_ON(le32_to_cpu(left->header.max_entries) <= nr_left - shift_);
BUG_ON(le32_to_cpu(right->header.max_entries) <= nr_right + shift_);
shift(left, right, nr_left - target_left);
*key_ptr(parent, r->index) = right->keys[0];
}
}
static int rebalance2(struct shadow_spine *s, struct dm_btree_info *info,
unsigned left_index)
{
int r;
struct node *parent;
struct child left, right;
parent = dm_block_data(shadow_current(s));
r = init_child(info, parent, left_index, &left);
if (r)
return r;
r = init_child(info, parent, left_index + 1, &right);
if (r) {
exit_child(info, &left);
return r;
}
__rebalance2(info, parent, &left, &right);
r = exit_child(info, &left);
if (r) {
exit_child(info, &right);
return r;
}
return exit_child(info, &right);
}
static void __rebalance3(struct dm_btree_info *info, struct node *parent,
struct child *l, struct child *c, struct child *r)
{
struct node *left = l->n;
struct node *center = c->n;
struct node *right = r->n;
uint32_t nr_left = le32_to_cpu(left->header.nr_entries);
uint32_t nr_center = le32_to_cpu(center->header.nr_entries);
uint32_t nr_right = le32_to_cpu(right->header.nr_entries);
uint32_t max_entries = le32_to_cpu(left->header.max_entries);
unsigned target;
BUG_ON(left->header.max_entries != center->header.max_entries);
BUG_ON(center->header.max_entries != right->header.max_entries);
if (((nr_left + nr_center + nr_right) / 2) < merge_threshold(center)) {
unsigned shift = min(max_entries - nr_left, nr_center);
BUG_ON(nr_left + shift > max_entries);
node_copy(left, center, -shift);
left->header.nr_entries = cpu_to_le32(nr_left + shift);
if (shift != nr_center) {
shift = nr_center - shift;
BUG_ON((nr_right + shift) >= max_entries);
node_shift(right, shift);
node_copy(center, right, shift);
right->header.nr_entries = cpu_to_le32(nr_right + shift);
}
*key_ptr(parent, r->index) = right->keys[0];
delete_at(parent, c->index);
r->index--;
dm_tm_dec(info->tm, dm_block_location(c->block));
__rebalance2(info, parent, l, r);
return;
}
target = (nr_left + nr_center + nr_right) / 3;
BUG_ON(target > max_entries);
shift(left, center, nr_left - target);
shift(center, right, target - nr_right);
*key_ptr(parent, c->index) = center->keys[0];
*key_ptr(parent, r->index) = right->keys[0];
}
static int rebalance3(struct shadow_spine *s, struct dm_btree_info *info,
unsigned left_index)
{
int r;
struct node *parent = dm_block_data(shadow_current(s));
struct child left, center, right;
r = init_child(info, parent, left_index, &left);
if (r)
return r;
r = init_child(info, parent, left_index + 1, &center);
if (r) {
exit_child(info, &left);
return r;
}
r = init_child(info, parent, left_index + 2, &right);
if (r) {
exit_child(info, &left);
exit_child(info, &center);
return r;
}
__rebalance3(info, parent, &left, &center, &right);
r = exit_child(info, &left);
if (r) {
exit_child(info, &center);
exit_child(info, &right);
return r;
}
r = exit_child(info, &center);
if (r) {
exit_child(info, &right);
return r;
}
r = exit_child(info, &right);
if (r)
return r;
return 0;
}
static int get_nr_entries(struct dm_transaction_manager *tm,
dm_block_t b, uint32_t *result)
{
int r;
struct dm_block *block;
struct node *n;
r = dm_tm_read_lock(tm, b, &btree_node_validator, &block);
if (r)
return r;
n = dm_block_data(block);
*result = le32_to_cpu(n->header.nr_entries);
return dm_tm_unlock(tm, block);
}
static int rebalance_children(struct shadow_spine *s,
struct dm_btree_info *info, uint64_t key)
{
int i, r, has_left_sibling, has_right_sibling;
uint32_t child_entries;
struct node *n;
n = dm_block_data(shadow_current(s));
if (le32_to_cpu(n->header.nr_entries) == 1) {
struct dm_block *child;
dm_block_t b = value64(n, 0);
r = dm_tm_read_lock(info->tm, b, &btree_node_validator, &child);
if (r)
return r;
memcpy(n, dm_block_data(child),
dm_bm_block_size(dm_tm_get_bm(info->tm)));
r = dm_tm_unlock(info->tm, child);
if (r)
return r;
dm_tm_dec(info->tm, dm_block_location(child));
return 0;
}
i = lower_bound(n, key);
if (i < 0)
return -ENODATA;
r = get_nr_entries(info->tm, value64(n, i), &child_entries);
if (r)
return r;
if (child_entries > del_threshold(n))
return 0;
has_left_sibling = i > 0;
has_right_sibling = i < (le32_to_cpu(n->header.nr_entries) - 1);
if (!has_left_sibling)
r = rebalance2(s, info, i);
else if (!has_right_sibling)
r = rebalance2(s, info, i - 1);
else
r = rebalance3(s, info, i - 1);
return r;
}
static int do_leaf(struct node *n, uint64_t key, unsigned *index)
{
int i = lower_bound(n, key);
if ((i < 0) ||
(i >= le32_to_cpu(n->header.nr_entries)) ||
(le64_to_cpu(n->keys[i]) != key))
return -ENODATA;
*index = i;
return 0;
}
static int remove_raw(struct shadow_spine *s, struct dm_btree_info *info,
struct dm_btree_value_type *vt, dm_block_t root,
uint64_t key, unsigned *index)
{
int i = *index, r;
struct node *n;
for (;;) {
r = shadow_step(s, root, vt);
if (r < 0)
break;
if (shadow_has_parent(s)) {
__le64 location = cpu_to_le64(dm_block_location(shadow_current(s)));
memcpy(value_ptr(dm_block_data(shadow_parent(s)), i, sizeof(__le64)),
&location, sizeof(__le64));
}
n = dm_block_data(shadow_current(s));
if (le32_to_cpu(n->header.flags) & LEAF_NODE)
return do_leaf(n, key, index);
r = rebalance_children(s, info, key);
if (r)
break;
n = dm_block_data(shadow_current(s));
if (le32_to_cpu(n->header.flags) & LEAF_NODE)
return do_leaf(n, key, index);
i = lower_bound(n, key);
root = value64(n, i);
}
return r;
}
int dm_btree_remove(struct dm_btree_info *info, dm_block_t root,
uint64_t *keys, dm_block_t *new_root)
{
unsigned level, last_level = info->levels - 1;
int index = 0, r = 0;
struct shadow_spine spine;
struct node *n;
init_shadow_spine(&spine, info);
for (level = 0; level < info->levels; level++) {
r = remove_raw(&spine, info,
(level == last_level ?
&info->value_type : &le64_type),
root, keys[level], (unsigned *)&index);
if (r < 0)
break;
n = dm_block_data(shadow_current(&spine));
if (level != last_level) {
root = value64(n, index);
continue;
}
BUG_ON(index < 0 || index >= le32_to_cpu(n->header.nr_entries));
if (info->value_type.dec)
info->value_type.dec(info->value_type.context,
value_ptr(n, index, info->value_type.size));
delete_at(n, index);
}
*new_root = shadow_root(&spine);
exit_shadow_spine(&spine);
return r;
}
