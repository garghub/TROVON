static inline u32 ib_fmr_hash(u64 first_page)
{
return jhash_2words((u32) first_page, (u32) (first_page >> 32), 0) &
(IB_FMR_HASH_SIZE - 1);
}
static inline struct ib_pool_fmr *ib_fmr_cache_lookup(struct ib_fmr_pool *pool,
u64 *page_list,
int page_list_len,
u64 io_virtual_address)
{
struct hlist_head *bucket;
struct ib_pool_fmr *fmr;
if (!pool->cache_bucket)
return NULL;
bucket = pool->cache_bucket + ib_fmr_hash(*page_list);
hlist_for_each_entry(fmr, bucket, cache_node)
if (io_virtual_address == fmr->io_virtual_address &&
page_list_len == fmr->page_list_len &&
!memcmp(page_list, fmr->page_list,
page_list_len * sizeof *page_list))
return fmr;
return NULL;
}
static void ib_fmr_batch_release(struct ib_fmr_pool *pool)
{
int ret;
struct ib_pool_fmr *fmr;
LIST_HEAD(unmap_list);
LIST_HEAD(fmr_list);
spin_lock_irq(&pool->pool_lock);
list_for_each_entry(fmr, &pool->dirty_list, list) {
hlist_del_init(&fmr->cache_node);
fmr->remap_count = 0;
list_add_tail(&fmr->fmr->list, &fmr_list);
#ifdef DEBUG
if (fmr->ref_count !=0) {
printk(KERN_WARNING PFX "Unmapping FMR 0x%08x with ref count %d\n",
fmr, fmr->ref_count);
}
#endif
}
list_splice_init(&pool->dirty_list, &unmap_list);
pool->dirty_len = 0;
spin_unlock_irq(&pool->pool_lock);
if (list_empty(&unmap_list)) {
return;
}
ret = ib_unmap_fmr(&fmr_list);
if (ret)
printk(KERN_WARNING PFX "ib_unmap_fmr returned %d\n", ret);
spin_lock_irq(&pool->pool_lock);
list_splice(&unmap_list, &pool->free_list);
spin_unlock_irq(&pool->pool_lock);
}
static int ib_fmr_cleanup_thread(void *pool_ptr)
{
struct ib_fmr_pool *pool = pool_ptr;
do {
if (atomic_read(&pool->flush_ser) - atomic_read(&pool->req_ser) < 0) {
ib_fmr_batch_release(pool);
atomic_inc(&pool->flush_ser);
wake_up_interruptible(&pool->force_wait);
if (pool->flush_function)
pool->flush_function(pool, pool->flush_arg);
}
set_current_state(TASK_INTERRUPTIBLE);
if (atomic_read(&pool->flush_ser) - atomic_read(&pool->req_ser) >= 0 &&
!kthread_should_stop())
schedule();
__set_current_state(TASK_RUNNING);
} while (!kthread_should_stop());
return 0;
}
struct ib_fmr_pool *ib_create_fmr_pool(struct ib_pd *pd,
struct ib_fmr_pool_param *params)
{
struct ib_device *device;
struct ib_fmr_pool *pool;
int i;
int ret;
int max_remaps;
if (!params)
return ERR_PTR(-EINVAL);
device = pd->device;
if (!device->alloc_fmr || !device->dealloc_fmr ||
!device->map_phys_fmr || !device->unmap_fmr) {
printk(KERN_INFO PFX "Device %s does not support FMRs\n",
device->name);
return ERR_PTR(-ENOSYS);
}
if (!device->attrs.max_map_per_fmr)
max_remaps = IB_FMR_MAX_REMAPS;
else
max_remaps = device->attrs.max_map_per_fmr;
pool = kmalloc(sizeof *pool, GFP_KERNEL);
if (!pool) {
printk(KERN_WARNING PFX "couldn't allocate pool struct\n");
return ERR_PTR(-ENOMEM);
}
pool->cache_bucket = NULL;
pool->flush_function = params->flush_function;
pool->flush_arg = params->flush_arg;
INIT_LIST_HEAD(&pool->free_list);
INIT_LIST_HEAD(&pool->dirty_list);
if (params->cache) {
pool->cache_bucket =
kmalloc(IB_FMR_HASH_SIZE * sizeof *pool->cache_bucket,
GFP_KERNEL);
if (!pool->cache_bucket) {
printk(KERN_WARNING PFX "Failed to allocate cache in pool\n");
ret = -ENOMEM;
goto out_free_pool;
}
for (i = 0; i < IB_FMR_HASH_SIZE; ++i)
INIT_HLIST_HEAD(pool->cache_bucket + i);
}
pool->pool_size = 0;
pool->max_pages = params->max_pages_per_fmr;
pool->max_remaps = max_remaps;
pool->dirty_watermark = params->dirty_watermark;
pool->dirty_len = 0;
spin_lock_init(&pool->pool_lock);
atomic_set(&pool->req_ser, 0);
atomic_set(&pool->flush_ser, 0);
init_waitqueue_head(&pool->force_wait);
pool->thread = kthread_run(ib_fmr_cleanup_thread,
pool,
"ib_fmr(%s)",
device->name);
if (IS_ERR(pool->thread)) {
printk(KERN_WARNING PFX "couldn't start cleanup thread\n");
ret = PTR_ERR(pool->thread);
goto out_free_pool;
}
{
struct ib_pool_fmr *fmr;
struct ib_fmr_attr fmr_attr = {
.max_pages = params->max_pages_per_fmr,
.max_maps = pool->max_remaps,
.page_shift = params->page_shift
};
int bytes_per_fmr = sizeof *fmr;
if (pool->cache_bucket)
bytes_per_fmr += params->max_pages_per_fmr * sizeof (u64);
for (i = 0; i < params->pool_size; ++i) {
fmr = kmalloc(bytes_per_fmr, GFP_KERNEL);
if (!fmr) {
printk(KERN_WARNING PFX "failed to allocate fmr "
"struct for FMR %d\n", i);
goto out_fail;
}
fmr->pool = pool;
fmr->remap_count = 0;
fmr->ref_count = 0;
INIT_HLIST_NODE(&fmr->cache_node);
fmr->fmr = ib_alloc_fmr(pd, params->access, &fmr_attr);
if (IS_ERR(fmr->fmr)) {
printk(KERN_WARNING PFX "fmr_create failed "
"for FMR %d\n", i);
kfree(fmr);
goto out_fail;
}
list_add_tail(&fmr->list, &pool->free_list);
++pool->pool_size;
}
}
return pool;
out_free_pool:
kfree(pool->cache_bucket);
kfree(pool);
return ERR_PTR(ret);
out_fail:
ib_destroy_fmr_pool(pool);
return ERR_PTR(-ENOMEM);
}
void ib_destroy_fmr_pool(struct ib_fmr_pool *pool)
{
struct ib_pool_fmr *fmr;
struct ib_pool_fmr *tmp;
LIST_HEAD(fmr_list);
int i;
kthread_stop(pool->thread);
ib_fmr_batch_release(pool);
i = 0;
list_for_each_entry_safe(fmr, tmp, &pool->free_list, list) {
if (fmr->remap_count) {
INIT_LIST_HEAD(&fmr_list);
list_add_tail(&fmr->fmr->list, &fmr_list);
ib_unmap_fmr(&fmr_list);
}
ib_dealloc_fmr(fmr->fmr);
list_del(&fmr->list);
kfree(fmr);
++i;
}
if (i < pool->pool_size)
printk(KERN_WARNING PFX "pool still has %d regions registered\n",
pool->pool_size - i);
kfree(pool->cache_bucket);
kfree(pool);
}
int ib_flush_fmr_pool(struct ib_fmr_pool *pool)
{
int serial;
struct ib_pool_fmr *fmr, *next;
spin_lock_irq(&pool->pool_lock);
list_for_each_entry_safe(fmr, next, &pool->free_list, list) {
if (fmr->remap_count > 0)
list_move(&fmr->list, &pool->dirty_list);
}
spin_unlock_irq(&pool->pool_lock);
serial = atomic_inc_return(&pool->req_ser);
wake_up_process(pool->thread);
if (wait_event_interruptible(pool->force_wait,
atomic_read(&pool->flush_ser) - serial >= 0))
return -EINTR;
return 0;
}
struct ib_pool_fmr *ib_fmr_pool_map_phys(struct ib_fmr_pool *pool_handle,
u64 *page_list,
int list_len,
u64 io_virtual_address)
{
struct ib_fmr_pool *pool = pool_handle;
struct ib_pool_fmr *fmr;
unsigned long flags;
int result;
if (list_len < 1 || list_len > pool->max_pages)
return ERR_PTR(-EINVAL);
spin_lock_irqsave(&pool->pool_lock, flags);
fmr = ib_fmr_cache_lookup(pool,
page_list,
list_len,
io_virtual_address);
if (fmr) {
++fmr->ref_count;
if (fmr->ref_count == 1) {
list_del(&fmr->list);
}
spin_unlock_irqrestore(&pool->pool_lock, flags);
return fmr;
}
if (list_empty(&pool->free_list)) {
spin_unlock_irqrestore(&pool->pool_lock, flags);
return ERR_PTR(-EAGAIN);
}
fmr = list_entry(pool->free_list.next, struct ib_pool_fmr, list);
list_del(&fmr->list);
hlist_del_init(&fmr->cache_node);
spin_unlock_irqrestore(&pool->pool_lock, flags);
result = ib_map_phys_fmr(fmr->fmr, page_list, list_len,
io_virtual_address);
if (result) {
spin_lock_irqsave(&pool->pool_lock, flags);
list_add(&fmr->list, &pool->free_list);
spin_unlock_irqrestore(&pool->pool_lock, flags);
printk(KERN_WARNING PFX "fmr_map returns %d\n", result);
return ERR_PTR(result);
}
++fmr->remap_count;
fmr->ref_count = 1;
if (pool->cache_bucket) {
fmr->io_virtual_address = io_virtual_address;
fmr->page_list_len = list_len;
memcpy(fmr->page_list, page_list, list_len * sizeof(*page_list));
spin_lock_irqsave(&pool->pool_lock, flags);
hlist_add_head(&fmr->cache_node,
pool->cache_bucket + ib_fmr_hash(fmr->page_list[0]));
spin_unlock_irqrestore(&pool->pool_lock, flags);
}
return fmr;
}
int ib_fmr_pool_unmap(struct ib_pool_fmr *fmr)
{
struct ib_fmr_pool *pool;
unsigned long flags;
pool = fmr->pool;
spin_lock_irqsave(&pool->pool_lock, flags);
--fmr->ref_count;
if (!fmr->ref_count) {
if (fmr->remap_count < pool->max_remaps) {
list_add_tail(&fmr->list, &pool->free_list);
} else {
list_add_tail(&fmr->list, &pool->dirty_list);
if (++pool->dirty_len >= pool->dirty_watermark) {
atomic_inc(&pool->req_ser);
wake_up_process(pool->thread);
}
}
}
#ifdef DEBUG
if (fmr->ref_count < 0)
printk(KERN_WARNING PFX "FMR %p has ref count %d < 0\n",
fmr, fmr->ref_count);
#endif
spin_unlock_irqrestore(&pool->pool_lock, flags);
return 0;
}
