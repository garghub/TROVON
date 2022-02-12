static unsigned long mmu_node_start(struct mmu_rb_node *node)
{
return node->addr & PAGE_MASK;
}
static unsigned long mmu_node_last(struct mmu_rb_node *node)
{
return PAGE_ALIGN(node->addr + node->len) - 1;
}
int hfi1_mmu_rb_register(void *ops_arg, struct mm_struct *mm,
struct mmu_rb_ops *ops,
struct workqueue_struct *wq,
struct mmu_rb_handler **handler)
{
struct mmu_rb_handler *handlr;
int ret;
handlr = kmalloc(sizeof(*handlr), GFP_KERNEL);
if (!handlr)
return -ENOMEM;
handlr->root = RB_ROOT_CACHED;
handlr->ops = ops;
handlr->ops_arg = ops_arg;
INIT_HLIST_NODE(&handlr->mn.hlist);
spin_lock_init(&handlr->lock);
handlr->mn.ops = &mn_opts;
handlr->mm = mm;
INIT_WORK(&handlr->del_work, handle_remove);
INIT_LIST_HEAD(&handlr->del_list);
INIT_LIST_HEAD(&handlr->lru_list);
handlr->wq = wq;
ret = mmu_notifier_register(&handlr->mn, handlr->mm);
if (ret) {
kfree(handlr);
return ret;
}
*handler = handlr;
return 0;
}
void hfi1_mmu_rb_unregister(struct mmu_rb_handler *handler)
{
struct mmu_rb_node *rbnode;
struct rb_node *node;
unsigned long flags;
struct list_head del_list;
mmu_notifier_unregister(&handler->mn, handler->mm);
flush_work(&handler->del_work);
INIT_LIST_HEAD(&del_list);
spin_lock_irqsave(&handler->lock, flags);
while ((node = rb_first_cached(&handler->root))) {
rbnode = rb_entry(node, struct mmu_rb_node, node);
rb_erase_cached(node, &handler->root);
list_move(&rbnode->list, &del_list);
}
spin_unlock_irqrestore(&handler->lock, flags);
do_remove(handler, &del_list);
kfree(handler);
}
int hfi1_mmu_rb_insert(struct mmu_rb_handler *handler,
struct mmu_rb_node *mnode)
{
struct mmu_rb_node *node;
unsigned long flags;
int ret = 0;
trace_hfi1_mmu_rb_insert(mnode->addr, mnode->len);
spin_lock_irqsave(&handler->lock, flags);
node = __mmu_rb_search(handler, mnode->addr, mnode->len);
if (node) {
ret = -EINVAL;
goto unlock;
}
__mmu_int_rb_insert(mnode, &handler->root);
list_add(&mnode->list, &handler->lru_list);
ret = handler->ops->insert(handler->ops_arg, mnode);
if (ret) {
__mmu_int_rb_remove(mnode, &handler->root);
list_del(&mnode->list);
}
unlock:
spin_unlock_irqrestore(&handler->lock, flags);
return ret;
}
static struct mmu_rb_node *__mmu_rb_search(struct mmu_rb_handler *handler,
unsigned long addr,
unsigned long len)
{
struct mmu_rb_node *node = NULL;
trace_hfi1_mmu_rb_search(addr, len);
if (!handler->ops->filter) {
node = __mmu_int_rb_iter_first(&handler->root, addr,
(addr + len) - 1);
} else {
for (node = __mmu_int_rb_iter_first(&handler->root, addr,
(addr + len) - 1);
node;
node = __mmu_int_rb_iter_next(node, addr,
(addr + len) - 1)) {
if (handler->ops->filter(node, addr, len))
return node;
}
}
return node;
}
bool hfi1_mmu_rb_remove_unless_exact(struct mmu_rb_handler *handler,
unsigned long addr, unsigned long len,
struct mmu_rb_node **rb_node)
{
struct mmu_rb_node *node;
unsigned long flags;
bool ret = false;
spin_lock_irqsave(&handler->lock, flags);
node = __mmu_rb_search(handler, addr, len);
if (node) {
if (node->addr == addr && node->len == len)
goto unlock;
__mmu_int_rb_remove(node, &handler->root);
list_del(&node->list);
ret = true;
}
unlock:
spin_unlock_irqrestore(&handler->lock, flags);
*rb_node = node;
return ret;
}
void hfi1_mmu_rb_evict(struct mmu_rb_handler *handler, void *evict_arg)
{
struct mmu_rb_node *rbnode, *ptr;
struct list_head del_list;
unsigned long flags;
bool stop = false;
INIT_LIST_HEAD(&del_list);
spin_lock_irqsave(&handler->lock, flags);
list_for_each_entry_safe_reverse(rbnode, ptr, &handler->lru_list,
list) {
if (handler->ops->evict(handler->ops_arg, rbnode, evict_arg,
&stop)) {
__mmu_int_rb_remove(rbnode, &handler->root);
list_move(&rbnode->list, &del_list);
}
if (stop)
break;
}
spin_unlock_irqrestore(&handler->lock, flags);
while (!list_empty(&del_list)) {
rbnode = list_first_entry(&del_list, struct mmu_rb_node, list);
list_del(&rbnode->list);
handler->ops->remove(handler->ops_arg, rbnode);
}
}
void hfi1_mmu_rb_remove(struct mmu_rb_handler *handler,
struct mmu_rb_node *node)
{
unsigned long flags;
trace_hfi1_mmu_rb_remove(node->addr, node->len);
spin_lock_irqsave(&handler->lock, flags);
__mmu_int_rb_remove(node, &handler->root);
list_del(&node->list);
spin_unlock_irqrestore(&handler->lock, flags);
handler->ops->remove(handler->ops_arg, node);
}
static inline void mmu_notifier_range_start(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
mmu_notifier_mem_invalidate(mn, mm, start, end);
}
static void mmu_notifier_mem_invalidate(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start, unsigned long end)
{
struct mmu_rb_handler *handler =
container_of(mn, struct mmu_rb_handler, mn);
struct rb_root_cached *root = &handler->root;
struct mmu_rb_node *node, *ptr = NULL;
unsigned long flags;
bool added = false;
spin_lock_irqsave(&handler->lock, flags);
for (node = __mmu_int_rb_iter_first(root, start, end - 1);
node; node = ptr) {
ptr = __mmu_int_rb_iter_next(node, start, end - 1);
trace_hfi1_mmu_mem_invalidate(node->addr, node->len);
if (handler->ops->invalidate(handler->ops_arg, node)) {
__mmu_int_rb_remove(node, root);
list_move(&node->list, &handler->del_list);
added = true;
}
}
spin_unlock_irqrestore(&handler->lock, flags);
if (added)
queue_work(handler->wq, &handler->del_work);
}
static void do_remove(struct mmu_rb_handler *handler,
struct list_head *del_list)
{
struct mmu_rb_node *node;
while (!list_empty(del_list)) {
node = list_first_entry(del_list, struct mmu_rb_node, list);
list_del(&node->list);
handler->ops->remove(handler->ops_arg, node);
}
}
static void handle_remove(struct work_struct *work)
{
struct mmu_rb_handler *handler = container_of(work,
struct mmu_rb_handler,
del_work);
struct list_head del_list;
unsigned long flags;
spin_lock_irqsave(&handler->lock, flags);
list_replace_init(&handler->del_list, &del_list);
spin_unlock_irqrestore(&handler->lock, flags);
do_remove(handler, &del_list);
}
