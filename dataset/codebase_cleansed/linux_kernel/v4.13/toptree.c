struct toptree __ref *toptree_alloc(int level, int id)
{
struct toptree *res;
if (slab_is_available())
res = kzalloc(sizeof(*res), GFP_KERNEL);
else
res = memblock_virt_alloc(sizeof(*res), 8);
if (!res)
return res;
INIT_LIST_HEAD(&res->children);
INIT_LIST_HEAD(&res->sibling);
cpumask_clear(&res->mask);
res->level = level;
res->id = id;
return res;
}
static void toptree_remove(struct toptree *cand)
{
struct toptree *oldparent;
list_del_init(&cand->sibling);
oldparent = cand->parent;
cand->parent = NULL;
toptree_update_mask(oldparent);
}
void __ref toptree_free(struct toptree *cand)
{
struct toptree *child, *tmp;
if (cand->parent)
toptree_remove(cand);
toptree_for_each_child_safe(child, tmp, cand)
toptree_free(child);
if (slab_is_available())
kfree(cand);
else
memblock_free_early((unsigned long)cand, sizeof(*cand));
}
void toptree_update_mask(struct toptree *cand)
{
struct toptree *child;
cpumask_clear(&cand->mask);
list_for_each_entry(child, &cand->children, sibling)
cpumask_or(&cand->mask, &cand->mask, &child->mask);
if (cand->parent)
toptree_update_mask(cand->parent);
}
static int toptree_insert(struct toptree *cand, struct toptree *target)
{
if (!cand || !target)
return -1;
if (target->level != (cand->level + 1))
return -1;
list_add_tail(&cand->sibling, &target->children);
cand->parent = target;
toptree_update_mask(target);
return 0;
}
static void toptree_move_children(struct toptree *cand, struct toptree *target)
{
struct toptree *child, *tmp;
toptree_for_each_child_safe(child, tmp, cand)
toptree_move(child, target);
}
void toptree_unify(struct toptree *cand)
{
struct toptree *child, *tmp, *cand_copy;
if (cand->level < 2)
return;
cand_copy = toptree_alloc(cand->level, 0);
toptree_for_each_child_safe(child, tmp, cand) {
struct toptree *tmpchild;
if (!cpumask_empty(&child->mask)) {
tmpchild = toptree_get_child(cand_copy, child->id);
toptree_move_children(child, tmpchild);
}
toptree_free(child);
}
toptree_move_children(cand_copy, cand);
toptree_free(cand_copy);
toptree_for_each_child(child, cand)
toptree_unify(child);
}
void toptree_move(struct toptree *cand, struct toptree *target)
{
struct toptree *stack_target, *real_insert_point, *ptr, *tmp;
if (cand->level + 1 == target->level) {
toptree_remove(cand);
toptree_insert(cand, target);
return;
}
real_insert_point = NULL;
ptr = cand;
stack_target = NULL;
do {
tmp = stack_target;
stack_target = toptree_alloc(ptr->level + 1,
ptr->parent->id);
toptree_insert(tmp, stack_target);
if (!real_insert_point)
real_insert_point = stack_target;
ptr = ptr->parent;
} while (stack_target->level < (target->level - 1));
toptree_remove(cand);
toptree_insert(cand, real_insert_point);
toptree_insert(stack_target, target);
}
struct toptree *toptree_get_child(struct toptree *cand, int id)
{
struct toptree *child;
toptree_for_each_child(child, cand)
if (child->id == id)
return child;
child = toptree_alloc(cand->level-1, id);
toptree_insert(child, cand);
return child;
}
struct toptree *toptree_first(struct toptree *context, int level)
{
struct toptree *child, *tmp;
if (context->level == level)
return context;
if (!list_empty(&context->children)) {
list_for_each_entry(child, &context->children, sibling) {
tmp = toptree_first(child, level);
if (tmp)
return tmp;
}
}
return NULL;
}
static struct toptree *toptree_next_sibling(struct toptree *cur)
{
if (cur->parent == NULL)
return NULL;
if (cur == list_last_entry(&cur->parent->children,
struct toptree, sibling))
return NULL;
return (struct toptree *) list_next_entry(cur, sibling);
}
struct toptree *toptree_next(struct toptree *cur, struct toptree *context,
int level)
{
struct toptree *cur_context, *tmp;
if (!cur)
return NULL;
if (context->level == level)
return NULL;
tmp = toptree_next_sibling(cur);
if (tmp != NULL)
return tmp;
cur_context = cur;
while (cur_context->level < context->level - 1) {
cur_context = cur_context->parent;
tmp = toptree_next_sibling(cur_context);
if (tmp != NULL) {
tmp = toptree_first(tmp, level);
if (tmp != NULL)
return tmp;
}
}
return NULL;
}
int toptree_count(struct toptree *context, int level)
{
struct toptree *cur;
int cnt = 0;
toptree_for_each(cur, context, level)
cnt++;
return cnt;
}
