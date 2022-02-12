void ulist_init(struct ulist *ulist)
{
ulist->nnodes = 0;
ulist->nodes = ulist->int_nodes;
ulist->nodes_alloced = ULIST_SIZE;
ulist->root = RB_ROOT;
}
void ulist_fini(struct ulist *ulist)
{
if (ulist->nodes_alloced > ULIST_SIZE)
kfree(ulist->nodes);
ulist->nodes_alloced = 0;
ulist->root = RB_ROOT;
}
void ulist_reinit(struct ulist *ulist)
{
ulist_fini(ulist);
ulist_init(ulist);
}
struct ulist *ulist_alloc(gfp_t gfp_mask)
{
struct ulist *ulist = kmalloc(sizeof(*ulist), gfp_mask);
if (!ulist)
return NULL;
ulist_init(ulist);
return ulist;
}
void ulist_free(struct ulist *ulist)
{
if (!ulist)
return;
ulist_fini(ulist);
kfree(ulist);
}
static struct ulist_node *ulist_rbtree_search(struct ulist *ulist, u64 val)
{
struct rb_node *n = ulist->root.rb_node;
struct ulist_node *u = NULL;
while (n) {
u = rb_entry(n, struct ulist_node, rb_node);
if (u->val < val)
n = n->rb_right;
else if (u->val > val)
n = n->rb_left;
else
return u;
}
return NULL;
}
static int ulist_rbtree_insert(struct ulist *ulist, struct ulist_node *ins)
{
struct rb_node **p = &ulist->root.rb_node;
struct rb_node *parent = NULL;
struct ulist_node *cur = NULL;
while (*p) {
parent = *p;
cur = rb_entry(parent, struct ulist_node, rb_node);
if (cur->val < ins->val)
p = &(*p)->rb_right;
else if (cur->val > ins->val)
p = &(*p)->rb_left;
else
return -EEXIST;
}
rb_link_node(&ins->rb_node, parent, p);
rb_insert_color(&ins->rb_node, &ulist->root);
return 0;
}
int ulist_add(struct ulist *ulist, u64 val, u64 aux, gfp_t gfp_mask)
{
return ulist_add_merge(ulist, val, aux, NULL, gfp_mask);
}
int ulist_add_merge(struct ulist *ulist, u64 val, u64 aux,
u64 *old_aux, gfp_t gfp_mask)
{
int ret = 0;
struct ulist_node *node = NULL;
node = ulist_rbtree_search(ulist, val);
if (node) {
if (old_aux)
*old_aux = node->aux;
return 0;
}
if (ulist->nnodes >= ulist->nodes_alloced) {
u64 new_alloced = ulist->nodes_alloced + 128;
struct ulist_node *new_nodes;
void *old = NULL;
int i;
for (i = 0; i < ulist->nnodes; i++)
rb_erase(&ulist->nodes[i].rb_node, &ulist->root);
if (ulist->nodes_alloced > ULIST_SIZE)
old = ulist->nodes;
new_nodes = krealloc(old, sizeof(*new_nodes) * new_alloced,
gfp_mask);
if (!new_nodes)
return -ENOMEM;
if (!old)
memcpy(new_nodes, ulist->int_nodes,
sizeof(ulist->int_nodes));
ulist->nodes = new_nodes;
ulist->nodes_alloced = new_alloced;
for (i = 0; i < ulist->nnodes; i++) {
ret = ulist_rbtree_insert(ulist, &ulist->nodes[i]);
if (ret < 0)
return ret;
}
}
ulist->nodes[ulist->nnodes].val = val;
ulist->nodes[ulist->nnodes].aux = aux;
ret = ulist_rbtree_insert(ulist, &ulist->nodes[ulist->nnodes]);
BUG_ON(ret);
++ulist->nnodes;
return 1;
}
struct ulist_node *ulist_next(struct ulist *ulist, struct ulist_iterator *uiter)
{
if (ulist->nnodes == 0)
return NULL;
if (uiter->i < 0 || uiter->i >= ulist->nnodes)
return NULL;
return &ulist->nodes[uiter->i++];
}
