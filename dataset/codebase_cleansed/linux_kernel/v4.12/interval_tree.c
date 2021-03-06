static inline int node_is_left_child(struct interval_node *node)
{
return node == node->in_parent->in_left;
}
static inline int node_is_right_child(struct interval_node *node)
{
return node == node->in_parent->in_right;
}
static inline int node_is_red(struct interval_node *node)
{
return node->in_color == INTERVAL_RED;
}
static inline int node_is_black(struct interval_node *node)
{
return node->in_color == INTERVAL_BLACK;
}
static inline int extent_compare(struct interval_node_extent *e1,
struct interval_node_extent *e2)
{
int rc;
if (e1->start == e2->start) {
if (e1->end < e2->end)
rc = -1;
else if (e1->end > e2->end)
rc = 1;
else
rc = 0;
} else {
if (e1->start < e2->start)
rc = -1;
else
rc = 1;
}
return rc;
}
static inline int extent_equal(struct interval_node_extent *e1,
struct interval_node_extent *e2)
{
return (e1->start == e2->start) && (e1->end == e2->end);
}
static inline int extent_overlapped(struct interval_node_extent *e1,
struct interval_node_extent *e2)
{
return (e1->start <= e2->end) && (e2->start <= e1->end);
}
static inline int node_equal(struct interval_node *n1, struct interval_node *n2)
{
return extent_equal(&n1->in_extent, &n2->in_extent);
}
static struct interval_node *interval_first(struct interval_node *node)
{
if (!node)
return NULL;
while (node->in_left)
node = node->in_left;
return node;
}
static struct interval_node *interval_next(struct interval_node *node)
{
if (!node)
return NULL;
if (node->in_right)
return interval_first(node->in_right);
while (node->in_parent && node_is_right_child(node))
node = node->in_parent;
return node->in_parent;
}
static void __rotate_change_maxhigh(struct interval_node *node,
struct interval_node *rotate)
{
__u64 left_max, right_max;
rotate->in_max_high = node->in_max_high;
left_max = node->in_left ? node->in_left->in_max_high : 0;
right_max = node->in_right ? node->in_right->in_max_high : 0;
node->in_max_high = max(interval_high(node),
max(left_max, right_max));
}
static void __rotate_left(struct interval_node *node,
struct interval_node **root)
{
struct interval_node *right = node->in_right;
struct interval_node *parent = node->in_parent;
node->in_right = right->in_left;
if (node->in_right)
right->in_left->in_parent = node;
right->in_left = node;
right->in_parent = parent;
if (parent) {
if (node_is_left_child(node))
parent->in_left = right;
else
parent->in_right = right;
} else {
*root = right;
}
node->in_parent = right;
__rotate_change_maxhigh(node, right);
}
static void __rotate_right(struct interval_node *node,
struct interval_node **root)
{
struct interval_node *left = node->in_left;
struct interval_node *parent = node->in_parent;
node->in_left = left->in_right;
if (node->in_left)
left->in_right->in_parent = node;
left->in_right = node;
left->in_parent = parent;
if (parent) {
if (node_is_right_child(node))
parent->in_right = left;
else
parent->in_left = left;
} else {
*root = left;
}
node->in_parent = left;
__rotate_change_maxhigh(node, left);
}
static void interval_insert_color(struct interval_node *node,
struct interval_node **root)
{
struct interval_node *parent, *gparent;
while ((parent = node->in_parent) && node_is_red(parent)) {
gparent = parent->in_parent;
if (node_is_left_child(parent)) {
struct interval_node *uncle;
uncle = gparent->in_right;
if (uncle && node_is_red(uncle)) {
uncle->in_color = INTERVAL_BLACK;
parent->in_color = INTERVAL_BLACK;
gparent->in_color = INTERVAL_RED;
node = gparent;
continue;
}
if (parent->in_right == node) {
__rotate_left(parent, root);
interval_swap(node, parent);
}
parent->in_color = INTERVAL_BLACK;
gparent->in_color = INTERVAL_RED;
__rotate_right(gparent, root);
} else {
struct interval_node *uncle;
uncle = gparent->in_left;
if (uncle && node_is_red(uncle)) {
uncle->in_color = INTERVAL_BLACK;
parent->in_color = INTERVAL_BLACK;
gparent->in_color = INTERVAL_RED;
node = gparent;
continue;
}
if (node_is_left_child(node)) {
__rotate_right(parent, root);
interval_swap(node, parent);
}
parent->in_color = INTERVAL_BLACK;
gparent->in_color = INTERVAL_RED;
__rotate_left(gparent, root);
}
}
(*root)->in_color = INTERVAL_BLACK;
}
struct interval_node *interval_insert(struct interval_node *node,
struct interval_node **root)
{
struct interval_node **p, *parent = NULL;
LASSERT(!interval_is_intree(node));
p = root;
while (*p) {
parent = *p;
if (node_equal(parent, node))
return parent;
if (parent->in_max_high < interval_high(node))
parent->in_max_high = interval_high(node);
if (extent_compare(&node->in_extent, &parent->in_extent) < 0)
p = &parent->in_left;
else
p = &parent->in_right;
}
node->in_parent = parent;
node->in_color = INTERVAL_RED;
node->in_left = NULL;
node->in_right = NULL;
*p = node;
interval_insert_color(node, root);
node->in_intree = 1;
return NULL;
}
static inline int node_is_black_or_0(struct interval_node *node)
{
return !node || node_is_black(node);
}
static void interval_erase_color(struct interval_node *node,
struct interval_node *parent,
struct interval_node **root)
{
struct interval_node *tmp;
while (node_is_black_or_0(node) && node != *root) {
if (parent->in_left == node) {
tmp = parent->in_right;
if (node_is_red(tmp)) {
tmp->in_color = INTERVAL_BLACK;
parent->in_color = INTERVAL_RED;
__rotate_left(parent, root);
tmp = parent->in_right;
}
if (node_is_black_or_0(tmp->in_left) &&
node_is_black_or_0(tmp->in_right)) {
tmp->in_color = INTERVAL_RED;
node = parent;
parent = node->in_parent;
} else {
if (node_is_black_or_0(tmp->in_right)) {
struct interval_node *o_left;
o_left = tmp->in_left;
if (o_left)
o_left->in_color = INTERVAL_BLACK;
tmp->in_color = INTERVAL_RED;
__rotate_right(tmp, root);
tmp = parent->in_right;
}
tmp->in_color = parent->in_color;
parent->in_color = INTERVAL_BLACK;
if (tmp->in_right)
tmp->in_right->in_color = INTERVAL_BLACK;
__rotate_left(parent, root);
node = *root;
break;
}
} else {
tmp = parent->in_left;
if (node_is_red(tmp)) {
tmp->in_color = INTERVAL_BLACK;
parent->in_color = INTERVAL_RED;
__rotate_right(parent, root);
tmp = parent->in_left;
}
if (node_is_black_or_0(tmp->in_left) &&
node_is_black_or_0(tmp->in_right)) {
tmp->in_color = INTERVAL_RED;
node = parent;
parent = node->in_parent;
} else {
if (node_is_black_or_0(tmp->in_left)) {
struct interval_node *o_right;
o_right = tmp->in_right;
if (o_right)
o_right->in_color = INTERVAL_BLACK;
tmp->in_color = INTERVAL_RED;
__rotate_left(tmp, root);
tmp = parent->in_left;
}
tmp->in_color = parent->in_color;
parent->in_color = INTERVAL_BLACK;
if (tmp->in_left)
tmp->in_left->in_color = INTERVAL_BLACK;
__rotate_right(parent, root);
node = *root;
break;
}
}
}
if (node)
node->in_color = INTERVAL_BLACK;
}
static void update_maxhigh(struct interval_node *node,
__u64 old_maxhigh)
{
__u64 left_max, right_max;
while (node) {
left_max = node->in_left ? node->in_left->in_max_high : 0;
right_max = node->in_right ? node->in_right->in_max_high : 0;
node->in_max_high = max(interval_high(node),
max(left_max, right_max));
if (node->in_max_high >= old_maxhigh)
break;
node = node->in_parent;
}
}
void interval_erase(struct interval_node *node,
struct interval_node **root)
{
struct interval_node *child, *parent;
int color;
LASSERT(interval_is_intree(node));
node->in_intree = 0;
if (!node->in_left) {
child = node->in_right;
} else if (!node->in_right) {
child = node->in_left;
} else {
struct interval_node *old = node;
node = interval_next(node);
child = node->in_right;
parent = node->in_parent;
color = node->in_color;
if (child)
child->in_parent = parent;
if (parent == old)
parent->in_right = child;
else
parent->in_left = child;
node->in_color = old->in_color;
node->in_right = old->in_right;
node->in_left = old->in_left;
node->in_parent = old->in_parent;
if (old->in_parent) {
if (node_is_left_child(old))
old->in_parent->in_left = node;
else
old->in_parent->in_right = node;
} else {
*root = node;
}
old->in_left->in_parent = node;
if (old->in_right)
old->in_right->in_parent = node;
update_maxhigh(child ? : parent, node->in_max_high);
update_maxhigh(node, old->in_max_high);
if (parent == old)
parent = node;
goto color;
}
parent = node->in_parent;
color = node->in_color;
if (child)
child->in_parent = parent;
if (parent) {
if (node_is_left_child(node))
parent->in_left = child;
else
parent->in_right = child;
} else {
*root = child;
}
update_maxhigh(child ? : parent, node->in_max_high);
color:
if (color == INTERVAL_BLACK)
interval_erase_color(child, parent, root);
}
static inline int interval_may_overlap(struct interval_node *node,
struct interval_node_extent *ext)
{
return (ext->start <= node->in_max_high &&
ext->end >= interval_low(node));
}
enum interval_iter interval_search(struct interval_node *node,
struct interval_node_extent *ext,
interval_callback_t func,
void *data)
{
enum interval_iter rc = INTERVAL_ITER_CONT;
struct interval_node *parent;
LASSERT(ext);
LASSERT(func);
while (node) {
if (ext->end < interval_low(node)) {
if (node->in_left) {
node = node->in_left;
continue;
}
} else if (interval_may_overlap(node, ext)) {
if (extent_overlapped(ext, &node->in_extent)) {
rc = func(node, data);
if (rc == INTERVAL_ITER_STOP)
break;
}
if (node->in_left) {
node = node->in_left;
continue;
}
if (node->in_right) {
node = node->in_right;
continue;
}
}
parent = node->in_parent;
while (parent) {
if (node_is_left_child(node) &&
parent->in_right) {
node = parent->in_right;
break;
}
node = parent;
parent = parent->in_parent;
}
if (!parent || !interval_may_overlap(parent, ext))
break;
}
return rc;
}
