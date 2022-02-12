static struct rb_node *tree_insert(struct rb_root *root, u64 bytenr,
struct rb_node *node)
{
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
struct btrfs_leaf_ref *entry;
while (*p) {
parent = *p;
entry = rb_entry(parent, struct btrfs_leaf_ref, rb_node);
if (bytenr < entry->bytenr)
p = &(*p)->rb_left;
else if (bytenr > entry->bytenr)
p = &(*p)->rb_right;
else
return parent;
}
entry = rb_entry(node, struct btrfs_leaf_ref, rb_node);
rb_link_node(node, parent, p);
rb_insert_color(node, root);
return NULL;
}
static struct rb_node *tree_search(struct rb_root *root, u64 bytenr)
{
struct rb_node *n = root->rb_node;
struct btrfs_leaf_ref *entry;
while (n) {
entry = rb_entry(n, struct btrfs_leaf_ref, rb_node);
WARN_ON(!entry->in_tree);
if (bytenr < entry->bytenr)
n = n->rb_left;
else if (bytenr > entry->bytenr)
n = n->rb_right;
else
return n;
}
return NULL;
}
