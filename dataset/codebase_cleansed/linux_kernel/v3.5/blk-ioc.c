void get_io_context(struct io_context *ioc)
{
BUG_ON(atomic_long_read(&ioc->refcount) <= 0);
atomic_long_inc(&ioc->refcount);
}
static void icq_free_icq_rcu(struct rcu_head *head)
{
struct io_cq *icq = container_of(head, struct io_cq, __rcu_head);
kmem_cache_free(icq->__rcu_icq_cache, icq);
}
static void ioc_exit_icq(struct io_cq *icq)
{
struct elevator_type *et = icq->q->elevator->type;
if (icq->flags & ICQ_EXITED)
return;
if (et->ops.elevator_exit_icq_fn)
et->ops.elevator_exit_icq_fn(icq);
icq->flags |= ICQ_EXITED;
}
static void ioc_destroy_icq(struct io_cq *icq)
{
struct io_context *ioc = icq->ioc;
struct request_queue *q = icq->q;
struct elevator_type *et = q->elevator->type;
lockdep_assert_held(&ioc->lock);
lockdep_assert_held(q->queue_lock);
radix_tree_delete(&ioc->icq_tree, icq->q->id);
hlist_del_init(&icq->ioc_node);
list_del_init(&icq->q_node);
if (rcu_dereference_raw(ioc->icq_hint) == icq)
rcu_assign_pointer(ioc->icq_hint, NULL);
ioc_exit_icq(icq);
icq->__rcu_icq_cache = et->icq_cache;
call_rcu(&icq->__rcu_head, icq_free_icq_rcu);
}
static void ioc_release_fn(struct work_struct *work)
{
struct io_context *ioc = container_of(work, struct io_context,
release_work);
unsigned long flags;
spin_lock_irqsave_nested(&ioc->lock, flags, 1);
while (!hlist_empty(&ioc->icq_list)) {
struct io_cq *icq = hlist_entry(ioc->icq_list.first,
struct io_cq, ioc_node);
struct request_queue *q = icq->q;
if (spin_trylock(q->queue_lock)) {
ioc_destroy_icq(icq);
spin_unlock(q->queue_lock);
} else {
spin_unlock_irqrestore(&ioc->lock, flags);
cpu_relax();
spin_lock_irqsave_nested(&ioc->lock, flags, 1);
}
}
spin_unlock_irqrestore(&ioc->lock, flags);
kmem_cache_free(iocontext_cachep, ioc);
}
void put_io_context(struct io_context *ioc)
{
unsigned long flags;
bool free_ioc = false;
if (ioc == NULL)
return;
BUG_ON(atomic_long_read(&ioc->refcount) <= 0);
if (atomic_long_dec_and_test(&ioc->refcount)) {
spin_lock_irqsave(&ioc->lock, flags);
if (!hlist_empty(&ioc->icq_list))
schedule_work(&ioc->release_work);
else
free_ioc = true;
spin_unlock_irqrestore(&ioc->lock, flags);
}
if (free_ioc)
kmem_cache_free(iocontext_cachep, ioc);
}
void put_io_context_active(struct io_context *ioc)
{
struct hlist_node *n;
unsigned long flags;
struct io_cq *icq;
if (!atomic_dec_and_test(&ioc->active_ref)) {
put_io_context(ioc);
return;
}
retry:
spin_lock_irqsave_nested(&ioc->lock, flags, 1);
hlist_for_each_entry(icq, n, &ioc->icq_list, ioc_node) {
if (icq->flags & ICQ_EXITED)
continue;
if (spin_trylock(icq->q->queue_lock)) {
ioc_exit_icq(icq);
spin_unlock(icq->q->queue_lock);
} else {
spin_unlock_irqrestore(&ioc->lock, flags);
cpu_relax();
goto retry;
}
}
spin_unlock_irqrestore(&ioc->lock, flags);
put_io_context(ioc);
}
void exit_io_context(struct task_struct *task)
{
struct io_context *ioc;
task_lock(task);
ioc = task->io_context;
task->io_context = NULL;
task_unlock(task);
atomic_dec(&ioc->nr_tasks);
put_io_context_active(ioc);
}
void ioc_clear_queue(struct request_queue *q)
{
lockdep_assert_held(q->queue_lock);
while (!list_empty(&q->icq_list)) {
struct io_cq *icq = list_entry(q->icq_list.next,
struct io_cq, q_node);
struct io_context *ioc = icq->ioc;
spin_lock(&ioc->lock);
ioc_destroy_icq(icq);
spin_unlock(&ioc->lock);
}
}
int create_task_io_context(struct task_struct *task, gfp_t gfp_flags, int node)
{
struct io_context *ioc;
int ret;
ioc = kmem_cache_alloc_node(iocontext_cachep, gfp_flags | __GFP_ZERO,
node);
if (unlikely(!ioc))
return -ENOMEM;
atomic_long_set(&ioc->refcount, 1);
atomic_set(&ioc->active_ref, 1);
spin_lock_init(&ioc->lock);
INIT_RADIX_TREE(&ioc->icq_tree, GFP_ATOMIC | __GFP_HIGH);
INIT_HLIST_HEAD(&ioc->icq_list);
INIT_WORK(&ioc->release_work, ioc_release_fn);
task_lock(task);
if (!task->io_context &&
(task == current || !(task->flags & PF_EXITING)))
task->io_context = ioc;
else
kmem_cache_free(iocontext_cachep, ioc);
ret = task->io_context ? 0 : -EBUSY;
task_unlock(task);
return ret;
}
struct io_context *get_task_io_context(struct task_struct *task,
gfp_t gfp_flags, int node)
{
struct io_context *ioc;
might_sleep_if(gfp_flags & __GFP_WAIT);
do {
task_lock(task);
ioc = task->io_context;
if (likely(ioc)) {
get_io_context(ioc);
task_unlock(task);
return ioc;
}
task_unlock(task);
} while (!create_task_io_context(task, gfp_flags, node));
return NULL;
}
struct io_cq *ioc_lookup_icq(struct io_context *ioc, struct request_queue *q)
{
struct io_cq *icq;
lockdep_assert_held(q->queue_lock);
rcu_read_lock();
icq = rcu_dereference(ioc->icq_hint);
if (icq && icq->q == q)
goto out;
icq = radix_tree_lookup(&ioc->icq_tree, q->id);
if (icq && icq->q == q)
rcu_assign_pointer(ioc->icq_hint, icq);
else
icq = NULL;
out:
rcu_read_unlock();
return icq;
}
struct io_cq *ioc_create_icq(struct io_context *ioc, struct request_queue *q,
gfp_t gfp_mask)
{
struct elevator_type *et = q->elevator->type;
struct io_cq *icq;
icq = kmem_cache_alloc_node(et->icq_cache, gfp_mask | __GFP_ZERO,
q->node);
if (!icq)
return NULL;
if (radix_tree_preload(gfp_mask) < 0) {
kmem_cache_free(et->icq_cache, icq);
return NULL;
}
icq->ioc = ioc;
icq->q = q;
INIT_LIST_HEAD(&icq->q_node);
INIT_HLIST_NODE(&icq->ioc_node);
spin_lock_irq(q->queue_lock);
spin_lock(&ioc->lock);
if (likely(!radix_tree_insert(&ioc->icq_tree, q->id, icq))) {
hlist_add_head(&icq->ioc_node, &ioc->icq_list);
list_add(&icq->q_node, &q->icq_list);
if (et->ops.elevator_init_icq_fn)
et->ops.elevator_init_icq_fn(icq);
} else {
kmem_cache_free(et->icq_cache, icq);
icq = ioc_lookup_icq(ioc, q);
if (!icq)
printk(KERN_ERR "cfq: icq link failed!\n");
}
spin_unlock(&ioc->lock);
spin_unlock_irq(q->queue_lock);
radix_tree_preload_end();
return icq;
}
static int __init blk_ioc_init(void)
{
iocontext_cachep = kmem_cache_create("blkdev_ioc",
sizeof(struct io_context), 0, SLAB_PANIC, NULL);
return 0;
}
