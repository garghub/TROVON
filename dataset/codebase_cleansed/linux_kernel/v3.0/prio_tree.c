static void get_index(const struct prio_tree_root *root,
const struct prio_tree_node *node,
unsigned long *radix, unsigned long *heap)
{
if (root->raw) {
struct vm_area_struct *vma = prio_tree_entry(
node, struct vm_area_struct, shared.prio_tree_node);
*radix = RADIX_INDEX(vma);
*heap = HEAP_INDEX(vma);
}
else {
*radix = node->start;
*heap = node->last;
}
}
void __init prio_tree_init(void)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(index_bits_to_maxindex) - 1; i++)
index_bits_to_maxindex[i] = (1UL << (i + 1)) - 1;
index_bits_to_maxindex[ARRAY_SIZE(index_bits_to_maxindex) - 1] = ~0UL;
}
static inline unsigned long prio_tree_maxindex(unsigned int bits)
{
return index_bits_to_maxindex[bits - 1];
}
static struct prio_tree_node *prio_tree_expand(struct prio_tree_root *root,
struct prio_tree_node *node, unsigned long max_heap_index)
{
struct prio_tree_node *first = NULL, *prev, *last = NULL;
if (max_heap_index > prio_tree_maxindex(root->index_bits))
root->index_bits++;
while (max_heap_index > prio_tree_maxindex(root->index_bits)) {
root->index_bits++;
if (prio_tree_empty(root))
continue;
if (first == NULL) {
first = root->prio_tree_node;
prio_tree_remove(root, root->prio_tree_node);
INIT_PRIO_TREE_NODE(first);
last = first;
} else {
prev = last;
last = root->prio_tree_node;
prio_tree_remove(root, root->prio_tree_node);
INIT_PRIO_TREE_NODE(last);
prev->left = last;
last->parent = prev;
}
}
INIT_PRIO_TREE_NODE(node);
if (first) {
node->left = first;
first->parent = node;
} else
last = node;
if (!prio_tree_empty(root)) {
last->left = root->prio_tree_node;
last->left->parent = last;
}
root->prio_tree_node = node;
return node;
}
struct prio_tree_node *prio_tree_replace(struct prio_tree_root *root,
struct prio_tree_node *old, struct prio_tree_node *node)
{
INIT_PRIO_TREE_NODE(node);
if (prio_tree_root(old)) {
BUG_ON(root->prio_tree_node != old);
node->parent = node;
root->prio_tree_node = node;
} else {
node->parent = old->parent;
if (old->parent->left == old)
old->parent->left = node;
else
old->parent->right = node;
}
if (!prio_tree_left_empty(old)) {
node->left = old->left;
old->left->parent = node;
}
if (!prio_tree_right_empty(old)) {
node->right = old->right;
old->right->parent = node;
}
return old;
}
struct prio_tree_node *prio_tree_insert(struct prio_tree_root *root,
struct prio_tree_node *node)
{
struct prio_tree_node *cur, *res = node;
unsigned long radix_index, heap_index;
unsigned long r_index, h_index, index, mask;
int size_flag = 0;
get_index(root, node, &radix_index, &heap_index);
if (prio_tree_empty(root) ||
heap_index > prio_tree_maxindex(root->index_bits))
return prio_tree_expand(root, node, heap_index);
cur = root->prio_tree_node;
mask = 1UL << (root->index_bits - 1);
while (mask) {
get_index(root, cur, &r_index, &h_index);
if (r_index == radix_index && h_index == heap_index)
return cur;
if (h_index < heap_index ||
(h_index == heap_index && r_index > radix_index)) {
struct prio_tree_node *tmp = node;
node = prio_tree_replace(root, cur, node);
cur = tmp;
index = r_index;
r_index = radix_index;
radix_index = index;
index = h_index;
h_index = heap_index;
heap_index = index;
}
if (size_flag)
index = heap_index - radix_index;
else
index = radix_index;
if (index & mask) {
if (prio_tree_right_empty(cur)) {
INIT_PRIO_TREE_NODE(node);
cur->right = node;
node->parent = cur;
return res;
} else
cur = cur->right;
} else {
if (prio_tree_left_empty(cur)) {
INIT_PRIO_TREE_NODE(node);
cur->left = node;
node->parent = cur;
return res;
} else
cur = cur->left;
}
mask >>= 1;
if (!mask) {
mask = 1UL << (BITS_PER_LONG - 1);
size_flag = 1;
}
}
BUG();
return NULL;
}
void prio_tree_remove(struct prio_tree_root *root, struct prio_tree_node *node)
{
struct prio_tree_node *cur;
unsigned long r_index, h_index_right, h_index_left;
cur = node;
while (!prio_tree_left_empty(cur) || !prio_tree_right_empty(cur)) {
if (!prio_tree_left_empty(cur))
get_index(root, cur->left, &r_index, &h_index_left);
else {
cur = cur->right;
continue;
}
if (!prio_tree_right_empty(cur))
get_index(root, cur->right, &r_index, &h_index_right);
else {
cur = cur->left;
continue;
}
if (h_index_left >= h_index_right)
cur = cur->left;
else
cur = cur->right;
}
if (prio_tree_root(cur)) {
BUG_ON(root->prio_tree_node != cur);
__INIT_PRIO_TREE_ROOT(root, root->raw);
return;
}
if (cur->parent->right == cur)
cur->parent->right = cur->parent;
else
cur->parent->left = cur->parent;
while (cur != node)
cur = prio_tree_replace(root, cur->parent, cur);
}
static struct prio_tree_node *prio_tree_left(struct prio_tree_iter *iter,
unsigned long *r_index, unsigned long *h_index)
{
if (prio_tree_left_empty(iter->cur))
return NULL;
get_index(iter->root, iter->cur->left, r_index, h_index);
if (iter->r_index <= *h_index) {
iter->cur = iter->cur->left;
iter->mask >>= 1;
if (iter->mask) {
if (iter->size_level)
iter->size_level++;
} else {
if (iter->size_level) {
BUG_ON(!prio_tree_left_empty(iter->cur));
BUG_ON(!prio_tree_right_empty(iter->cur));
iter->size_level++;
iter->mask = ULONG_MAX;
} else {
iter->size_level = 1;
iter->mask = 1UL << (BITS_PER_LONG - 1);
}
}
return iter->cur;
}
return NULL;
}
static struct prio_tree_node *prio_tree_right(struct prio_tree_iter *iter,
unsigned long *r_index, unsigned long *h_index)
{
unsigned long value;
if (prio_tree_right_empty(iter->cur))
return NULL;
if (iter->size_level)
value = iter->value;
else
value = iter->value | iter->mask;
if (iter->h_index < value)
return NULL;
get_index(iter->root, iter->cur->right, r_index, h_index);
if (iter->r_index <= *h_index) {
iter->cur = iter->cur->right;
iter->mask >>= 1;
iter->value = value;
if (iter->mask) {
if (iter->size_level)
iter->size_level++;
} else {
if (iter->size_level) {
BUG_ON(!prio_tree_left_empty(iter->cur));
BUG_ON(!prio_tree_right_empty(iter->cur));
iter->size_level++;
iter->mask = ULONG_MAX;
} else {
iter->size_level = 1;
iter->mask = 1UL << (BITS_PER_LONG - 1);
}
}
return iter->cur;
}
return NULL;
}
static struct prio_tree_node *prio_tree_parent(struct prio_tree_iter *iter)
{
iter->cur = iter->cur->parent;
if (iter->mask == ULONG_MAX)
iter->mask = 1UL;
else if (iter->size_level == 1)
iter->mask = 1UL;
else
iter->mask <<= 1;
if (iter->size_level)
iter->size_level--;
if (!iter->size_level && (iter->value & iter->mask))
iter->value ^= iter->mask;
return iter->cur;
}
static inline int overlap(struct prio_tree_iter *iter,
unsigned long r_index, unsigned long h_index)
{
return iter->h_index >= r_index && iter->r_index <= h_index;
}
static struct prio_tree_node *prio_tree_first(struct prio_tree_iter *iter)
{
struct prio_tree_root *root;
unsigned long r_index, h_index;
INIT_PRIO_TREE_ITER(iter);
root = iter->root;
if (prio_tree_empty(root))
return NULL;
get_index(root, root->prio_tree_node, &r_index, &h_index);
if (iter->r_index > h_index)
return NULL;
iter->mask = 1UL << (root->index_bits - 1);
iter->cur = root->prio_tree_node;
while (1) {
if (overlap(iter, r_index, h_index))
return iter->cur;
if (prio_tree_left(iter, &r_index, &h_index))
continue;
if (prio_tree_right(iter, &r_index, &h_index))
continue;
break;
}
return NULL;
}
struct prio_tree_node *prio_tree_next(struct prio_tree_iter *iter)
{
unsigned long r_index, h_index;
if (iter->cur == NULL)
return prio_tree_first(iter);
repeat:
while (prio_tree_left(iter, &r_index, &h_index))
if (overlap(iter, r_index, h_index))
return iter->cur;
while (!prio_tree_right(iter, &r_index, &h_index)) {
while (!prio_tree_root(iter->cur) &&
iter->cur->parent->right == iter->cur)
prio_tree_parent(iter);
if (prio_tree_root(iter->cur))
return NULL;
prio_tree_parent(iter);
}
if (overlap(iter, r_index, h_index))
return iter->cur;
goto repeat;
}
