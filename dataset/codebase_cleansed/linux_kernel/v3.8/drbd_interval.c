static inline
sector_t interval_end(struct rb_node *node)
{
struct drbd_interval *this = rb_entry(node, struct drbd_interval, rb);
return this->end;
}
static inline sector_t
compute_subtree_last(struct drbd_interval *node)
{
sector_t max = node->sector + (node->size >> 9);
if (node->rb.rb_left) {
sector_t left = interval_end(node->rb.rb_left);
if (left > max)
max = left;
}
if (node->rb.rb_right) {
sector_t right = interval_end(node->rb.rb_right);
if (right > max)
max = right;
}
return max;
}
static void augment_propagate(struct rb_node *rb, struct rb_node *stop)
{
while (rb != stop) {
struct drbd_interval *node = rb_entry(rb, struct drbd_interval, rb);
sector_t subtree_last = compute_subtree_last(node);
if (node->end == subtree_last)
break;
node->end = subtree_last;
rb = rb_parent(&node->rb);
}
}
static void augment_copy(struct rb_node *rb_old, struct rb_node *rb_new)
{
struct drbd_interval *old = rb_entry(rb_old, struct drbd_interval, rb);
struct drbd_interval *new = rb_entry(rb_new, struct drbd_interval, rb);
new->end = old->end;
}
static void augment_rotate(struct rb_node *rb_old, struct rb_node *rb_new)
{
struct drbd_interval *old = rb_entry(rb_old, struct drbd_interval, rb);
struct drbd_interval *new = rb_entry(rb_new, struct drbd_interval, rb);
new->end = old->end;
old->end = compute_subtree_last(old);
}
bool
drbd_insert_interval(struct rb_root *root, struct drbd_interval *this)
{
struct rb_node **new = &root->rb_node, *parent = NULL;
BUG_ON(!IS_ALIGNED(this->size, 512));
while (*new) {
struct drbd_interval *here =
rb_entry(*new, struct drbd_interval, rb);
parent = *new;
if (this->sector < here->sector)
new = &(*new)->rb_left;
else if (this->sector > here->sector)
new = &(*new)->rb_right;
else if (this < here)
new = &(*new)->rb_left;
else if (this > here)
new = &(*new)->rb_right;
else
return false;
}
rb_link_node(&this->rb, parent, new);
rb_insert_augmented(&this->rb, root, &augment_callbacks);
return true;
}
bool
drbd_contains_interval(struct rb_root *root, sector_t sector,
struct drbd_interval *interval)
{
struct rb_node *node = root->rb_node;
while (node) {
struct drbd_interval *here =
rb_entry(node, struct drbd_interval, rb);
if (sector < here->sector)
node = node->rb_left;
else if (sector > here->sector)
node = node->rb_right;
else if (interval < here)
node = node->rb_left;
else if (interval > here)
node = node->rb_right;
else
return true;
}
return false;
}
void
drbd_remove_interval(struct rb_root *root, struct drbd_interval *this)
{
rb_erase_augmented(&this->rb, root, &augment_callbacks);
}
struct drbd_interval *
drbd_find_overlap(struct rb_root *root, sector_t sector, unsigned int size)
{
struct rb_node *node = root->rb_node;
struct drbd_interval *overlap = NULL;
sector_t end = sector + (size >> 9);
BUG_ON(!IS_ALIGNED(size, 512));
while (node) {
struct drbd_interval *here =
rb_entry(node, struct drbd_interval, rb);
if (node->rb_left &&
sector < interval_end(node->rb_left)) {
node = node->rb_left;
} else if (here->sector < end &&
sector < here->sector + (here->size >> 9)) {
overlap = here;
break;
} else if (sector >= here->sector) {
node = node->rb_right;
} else
break;
}
return overlap;
}
struct drbd_interval *
drbd_next_overlap(struct drbd_interval *i, sector_t sector, unsigned int size)
{
sector_t end = sector + (size >> 9);
struct rb_node *node;
for (;;) {
node = rb_next(&i->rb);
if (!node)
return NULL;
i = rb_entry(node, struct drbd_interval, rb);
if (i->sector >= end)
return NULL;
if (sector < i->sector + (i->size >> 9))
return i;
}
}
