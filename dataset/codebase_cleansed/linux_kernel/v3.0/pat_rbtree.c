static int is_node_overlap(struct memtype *node, u64 start, u64 end)
{
if (node->start >= end || node->end <= start)
return 0;
return 1;
}
static u64 get_subtree_max_end(struct rb_node *node)
{
u64 ret = 0;
if (node) {
struct memtype *data = container_of(node, struct memtype, rb);
ret = data->subtree_max_end;
}
return ret;
}
static void memtype_rb_augment_cb(struct rb_node *node, void *__unused)
{
struct memtype *data;
u64 max_end, child_max_end;
if (!node)
return;
data = container_of(node, struct memtype, rb);
max_end = data->end;
child_max_end = get_subtree_max_end(node->rb_right);
if (child_max_end > max_end)
max_end = child_max_end;
child_max_end = get_subtree_max_end(node->rb_left);
if (child_max_end > max_end)
max_end = child_max_end;
data->subtree_max_end = max_end;
}
static struct memtype *memtype_rb_lowest_match(struct rb_root *root,
u64 start, u64 end)
{
struct rb_node *node = root->rb_node;
struct memtype *last_lower = NULL;
while (node) {
struct memtype *data = container_of(node, struct memtype, rb);
if (get_subtree_max_end(node->rb_left) > start) {
node = node->rb_left;
} else if (is_node_overlap(data, start, end)) {
last_lower = data;
break;
} else if (start >= data->start) {
node = node->rb_right;
} else {
break;
}
}
return last_lower;
}
static struct memtype *memtype_rb_exact_match(struct rb_root *root,
u64 start, u64 end)
{
struct memtype *match;
match = memtype_rb_lowest_match(root, start, end);
while (match != NULL && match->start < end) {
struct rb_node *node;
if (match->start == start && match->end == end)
return match;
node = rb_next(&match->rb);
if (node)
match = container_of(node, struct memtype, rb);
else
match = NULL;
}
return NULL;
}
static int memtype_rb_check_conflict(struct rb_root *root,
u64 start, u64 end,
unsigned long reqtype, unsigned long *newtype)
{
struct rb_node *node;
struct memtype *match;
int found_type = reqtype;
match = memtype_rb_lowest_match(&memtype_rbroot, start, end);
if (match == NULL)
goto success;
if (match->type != found_type && newtype == NULL)
goto failure;
dprintk("Overlap at 0x%Lx-0x%Lx\n", match->start, match->end);
found_type = match->type;
node = rb_next(&match->rb);
while (node) {
match = container_of(node, struct memtype, rb);
if (match->start >= end)
goto success;
if (is_node_overlap(match, start, end) &&
match->type != found_type) {
goto failure;
}
node = rb_next(&match->rb);
}
success:
if (newtype)
*newtype = found_type;
return 0;
failure:
printk(KERN_INFO "%s:%d conflicting memory types "
"%Lx-%Lx %s<->%s\n", current->comm, current->pid, start,
end, cattr_name(found_type), cattr_name(match->type));
return -EBUSY;
}
static void memtype_rb_insert(struct rb_root *root, struct memtype *newdata)
{
struct rb_node **node = &(root->rb_node);
struct rb_node *parent = NULL;
while (*node) {
struct memtype *data = container_of(*node, struct memtype, rb);
parent = *node;
if (newdata->start <= data->start)
node = &((*node)->rb_left);
else if (newdata->start > data->start)
node = &((*node)->rb_right);
}
rb_link_node(&newdata->rb, parent, node);
rb_insert_color(&newdata->rb, root);
rb_augment_insert(&newdata->rb, memtype_rb_augment_cb, NULL);
}
int rbt_memtype_check_insert(struct memtype *new, unsigned long *ret_type)
{
int err = 0;
err = memtype_rb_check_conflict(&memtype_rbroot, new->start, new->end,
new->type, ret_type);
if (!err) {
if (ret_type)
new->type = *ret_type;
new->subtree_max_end = new->end;
memtype_rb_insert(&memtype_rbroot, new);
}
return err;
}
struct memtype *rbt_memtype_erase(u64 start, u64 end)
{
struct rb_node *deepest;
struct memtype *data;
data = memtype_rb_exact_match(&memtype_rbroot, start, end);
if (!data)
goto out;
deepest = rb_augment_erase_begin(&data->rb);
rb_erase(&data->rb, &memtype_rbroot);
rb_augment_erase_end(deepest, memtype_rb_augment_cb, NULL);
out:
return data;
}
struct memtype *rbt_memtype_lookup(u64 addr)
{
struct memtype *data;
data = memtype_rb_lowest_match(&memtype_rbroot, addr, addr + PAGE_SIZE);
return data;
}
int rbt_memtype_copy_nth_element(struct memtype *out, loff_t pos)
{
struct rb_node *node;
int i = 1;
node = rb_first(&memtype_rbroot);
while (node && pos != i) {
node = rb_next(node);
i++;
}
if (node) {
struct memtype *this = container_of(node, struct memtype, rb);
*out = *this;
return 0;
} else {
return 1;
}
}
