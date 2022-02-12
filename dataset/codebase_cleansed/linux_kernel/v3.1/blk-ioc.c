static void cfq_dtor(struct io_context *ioc)
{
if (!hlist_empty(&ioc->cic_list)) {
struct cfq_io_context *cic;
cic = hlist_entry(ioc->cic_list.first, struct cfq_io_context,
cic_list);
cic->dtor(ioc);
}
}
int put_io_context(struct io_context *ioc)
{
if (ioc == NULL)
return 1;
BUG_ON(atomic_long_read(&ioc->refcount) == 0);
if (atomic_long_dec_and_test(&ioc->refcount)) {
rcu_read_lock();
cfq_dtor(ioc);
rcu_read_unlock();
kmem_cache_free(iocontext_cachep, ioc);
return 1;
}
return 0;
}
static void cfq_exit(struct io_context *ioc)
{
rcu_read_lock();
if (!hlist_empty(&ioc->cic_list)) {
struct cfq_io_context *cic;
cic = hlist_entry(ioc->cic_list.first, struct cfq_io_context,
cic_list);
cic->exit(ioc);
}
rcu_read_unlock();
}
void exit_io_context(struct task_struct *task)
{
struct io_context *ioc;
task_lock(task);
ioc = task->io_context;
task->io_context = NULL;
task_unlock(task);
if (atomic_dec_and_test(&ioc->nr_tasks))
cfq_exit(ioc);
put_io_context(ioc);
}
struct io_context *alloc_io_context(gfp_t gfp_flags, int node)
{
struct io_context *ioc;
ioc = kmem_cache_alloc_node(iocontext_cachep, gfp_flags, node);
if (ioc) {
atomic_long_set(&ioc->refcount, 1);
atomic_set(&ioc->nr_tasks, 1);
spin_lock_init(&ioc->lock);
ioc->ioprio_changed = 0;
ioc->ioprio = 0;
ioc->last_waited = 0;
ioc->nr_batch_requests = 0;
INIT_RADIX_TREE(&ioc->radix_root, GFP_ATOMIC | __GFP_HIGH);
INIT_HLIST_HEAD(&ioc->cic_list);
ioc->ioc_data = NULL;
#if defined(CONFIG_BLK_CGROUP) || defined(CONFIG_BLK_CGROUP_MODULE)
ioc->cgroup_changed = 0;
#endif
}
return ioc;
}
struct io_context *current_io_context(gfp_t gfp_flags, int node)
{
struct task_struct *tsk = current;
struct io_context *ret;
ret = tsk->io_context;
if (likely(ret))
return ret;
ret = alloc_io_context(gfp_flags, node);
if (ret) {
smp_wmb();
tsk->io_context = ret;
}
return ret;
}
struct io_context *get_io_context(gfp_t gfp_flags, int node)
{
struct io_context *ioc = NULL;
do {
ioc = current_io_context(gfp_flags, node);
if (unlikely(!ioc))
break;
} while (!atomic_long_inc_not_zero(&ioc->refcount));
return ioc;
}
static int __init blk_ioc_init(void)
{
iocontext_cachep = kmem_cache_create("blkdev_ioc",
sizeof(struct io_context), 0, SLAB_PANIC, NULL);
return 0;
}
