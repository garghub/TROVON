static struct dma_chan *dev_to_dma_chan(struct device *dev)
{
struct dma_chan_dev *chan_dev;
chan_dev = container_of(dev, typeof(*chan_dev), device);
return chan_dev->chan;
}
static ssize_t memcpy_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dma_chan *chan;
unsigned long count = 0;
int i;
int err;
mutex_lock(&dma_list_mutex);
chan = dev_to_dma_chan(dev);
if (chan) {
for_each_possible_cpu(i)
count += per_cpu_ptr(chan->local, i)->memcpy_count;
err = sprintf(buf, "%lu\n", count);
} else
err = -ENODEV;
mutex_unlock(&dma_list_mutex);
return err;
}
static ssize_t bytes_transferred_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dma_chan *chan;
unsigned long count = 0;
int i;
int err;
mutex_lock(&dma_list_mutex);
chan = dev_to_dma_chan(dev);
if (chan) {
for_each_possible_cpu(i)
count += per_cpu_ptr(chan->local, i)->bytes_transferred;
err = sprintf(buf, "%lu\n", count);
} else
err = -ENODEV;
mutex_unlock(&dma_list_mutex);
return err;
}
static ssize_t in_use_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dma_chan *chan;
int err;
mutex_lock(&dma_list_mutex);
chan = dev_to_dma_chan(dev);
if (chan)
err = sprintf(buf, "%d\n", chan->client_count);
else
err = -ENODEV;
mutex_unlock(&dma_list_mutex);
return err;
}
static void chan_dev_release(struct device *dev)
{
struct dma_chan_dev *chan_dev;
chan_dev = container_of(dev, typeof(*chan_dev), device);
if (atomic_dec_and_test(chan_dev->idr_ref)) {
mutex_lock(&dma_list_mutex);
idr_remove(&dma_idr, chan_dev->dev_id);
mutex_unlock(&dma_list_mutex);
kfree(chan_dev->idr_ref);
}
kfree(chan_dev);
}
static int
__dma_device_satisfies_mask(struct dma_device *device,
const dma_cap_mask_t *want)
{
dma_cap_mask_t has;
bitmap_and(has.bits, want->bits, device->cap_mask.bits,
DMA_TX_TYPE_END);
return bitmap_equal(want->bits, has.bits, DMA_TX_TYPE_END);
}
static struct module *dma_chan_to_owner(struct dma_chan *chan)
{
return chan->device->dev->driver->owner;
}
static void balance_ref_count(struct dma_chan *chan)
{
struct module *owner = dma_chan_to_owner(chan);
while (chan->client_count < dmaengine_ref_count) {
__module_get(owner);
chan->client_count++;
}
}
static int dma_chan_get(struct dma_chan *chan)
{
int err = -ENODEV;
struct module *owner = dma_chan_to_owner(chan);
if (chan->client_count) {
__module_get(owner);
err = 0;
} else if (try_module_get(owner))
err = 0;
if (err == 0)
chan->client_count++;
if (chan->client_count == 1 && err == 0) {
int desc_cnt = chan->device->device_alloc_chan_resources(chan);
if (desc_cnt < 0) {
err = desc_cnt;
chan->client_count = 0;
module_put(owner);
} else if (!dma_has_cap(DMA_PRIVATE, chan->device->cap_mask))
balance_ref_count(chan);
}
return err;
}
static void dma_chan_put(struct dma_chan *chan)
{
if (!chan->client_count)
return;
chan->client_count--;
module_put(dma_chan_to_owner(chan));
if (chan->client_count == 0)
chan->device->device_free_chan_resources(chan);
}
enum dma_status dma_sync_wait(struct dma_chan *chan, dma_cookie_t cookie)
{
enum dma_status status;
unsigned long dma_sync_wait_timeout = jiffies + msecs_to_jiffies(5000);
dma_async_issue_pending(chan);
do {
status = dma_async_is_tx_complete(chan, cookie, NULL, NULL);
if (time_after_eq(jiffies, dma_sync_wait_timeout)) {
pr_err("%s: timeout!\n", __func__);
return DMA_ERROR;
}
if (status != DMA_IN_PROGRESS)
break;
cpu_relax();
} while (1);
return status;
}
static int __init dma_channel_table_init(void)
{
enum dma_transaction_type cap;
int err = 0;
bitmap_fill(dma_cap_mask_all.bits, DMA_TX_TYPE_END);
clear_bit(DMA_INTERRUPT, dma_cap_mask_all.bits);
clear_bit(DMA_PRIVATE, dma_cap_mask_all.bits);
clear_bit(DMA_SLAVE, dma_cap_mask_all.bits);
for_each_dma_cap_mask(cap, dma_cap_mask_all) {
channel_table[cap] = alloc_percpu(struct dma_chan_tbl_ent);
if (!channel_table[cap]) {
err = -ENOMEM;
break;
}
}
if (err) {
pr_err("initialization failure\n");
for_each_dma_cap_mask(cap, dma_cap_mask_all)
if (channel_table[cap])
free_percpu(channel_table[cap]);
}
return err;
}
struct dma_chan *dma_find_channel(enum dma_transaction_type tx_type)
{
return this_cpu_read(channel_table[tx_type]->chan);
}
struct dma_chan *net_dma_find_channel(void)
{
struct dma_chan *chan = dma_find_channel(DMA_MEMCPY);
if (chan && !is_dma_copy_aligned(chan->device, 1, 1, 1))
return NULL;
return chan;
}
void dma_issue_pending_all(void)
{
struct dma_device *device;
struct dma_chan *chan;
rcu_read_lock();
list_for_each_entry_rcu(device, &dma_device_list, global_node) {
if (dma_has_cap(DMA_PRIVATE, device->cap_mask))
continue;
list_for_each_entry(chan, &device->channels, device_node)
if (chan->client_count)
device->device_issue_pending(chan);
}
rcu_read_unlock();
}
static bool dma_chan_is_local(struct dma_chan *chan, int cpu)
{
int node = dev_to_node(chan->device->dev);
return node == -1 || cpumask_test_cpu(cpu, cpumask_of_node(node));
}
static struct dma_chan *min_chan(enum dma_transaction_type cap, int cpu)
{
struct dma_device *device;
struct dma_chan *chan;
struct dma_chan *min = NULL;
struct dma_chan *localmin = NULL;
list_for_each_entry(device, &dma_device_list, global_node) {
if (!dma_has_cap(cap, device->cap_mask) ||
dma_has_cap(DMA_PRIVATE, device->cap_mask))
continue;
list_for_each_entry(chan, &device->channels, device_node) {
if (!chan->client_count)
continue;
if (!min || chan->table_count < min->table_count)
min = chan;
if (dma_chan_is_local(chan, cpu))
if (!localmin ||
chan->table_count < localmin->table_count)
localmin = chan;
}
}
chan = localmin ? localmin : min;
if (chan)
chan->table_count++;
return chan;
}
static void dma_channel_rebalance(void)
{
struct dma_chan *chan;
struct dma_device *device;
int cpu;
int cap;
for_each_dma_cap_mask(cap, dma_cap_mask_all)
for_each_possible_cpu(cpu)
per_cpu_ptr(channel_table[cap], cpu)->chan = NULL;
list_for_each_entry(device, &dma_device_list, global_node) {
if (dma_has_cap(DMA_PRIVATE, device->cap_mask))
continue;
list_for_each_entry(chan, &device->channels, device_node)
chan->table_count = 0;
}
if (!dmaengine_ref_count)
return;
for_each_dma_cap_mask(cap, dma_cap_mask_all)
for_each_online_cpu(cpu) {
chan = min_chan(cap, cpu);
per_cpu_ptr(channel_table[cap], cpu)->chan = chan;
}
}
static struct dma_chan *private_candidate(const dma_cap_mask_t *mask,
struct dma_device *dev,
dma_filter_fn fn, void *fn_param)
{
struct dma_chan *chan;
if (!__dma_device_satisfies_mask(dev, mask)) {
pr_debug("%s: wrong capabilities\n", __func__);
return NULL;
}
if (dev->chancnt > 1 && !dma_has_cap(DMA_PRIVATE, dev->cap_mask))
list_for_each_entry(chan, &dev->channels, device_node) {
if (chan->client_count)
return NULL;
}
list_for_each_entry(chan, &dev->channels, device_node) {
if (chan->client_count) {
pr_debug("%s: %s busy\n",
__func__, dma_chan_name(chan));
continue;
}
if (fn && !fn(chan, fn_param)) {
pr_debug("%s: %s filter said false\n",
__func__, dma_chan_name(chan));
continue;
}
return chan;
}
return NULL;
}
struct dma_chan *dma_get_slave_channel(struct dma_chan *chan)
{
int err = -EBUSY;
mutex_lock(&dma_list_mutex);
if (chan->client_count == 0) {
err = dma_chan_get(chan);
if (err)
pr_debug("%s: failed to get %s: (%d)\n",
__func__, dma_chan_name(chan), err);
} else
chan = NULL;
mutex_unlock(&dma_list_mutex);
return chan;
}
struct dma_chan *dma_get_any_slave_channel(struct dma_device *device)
{
dma_cap_mask_t mask;
struct dma_chan *chan;
int err;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
mutex_lock(&dma_list_mutex);
chan = private_candidate(&mask, device, NULL, NULL);
if (chan) {
err = dma_chan_get(chan);
if (err) {
pr_debug("%s: failed to get %s: (%d)\n",
__func__, dma_chan_name(chan), err);
chan = NULL;
}
}
mutex_unlock(&dma_list_mutex);
return chan;
}
struct dma_chan *__dma_request_channel(const dma_cap_mask_t *mask,
dma_filter_fn fn, void *fn_param)
{
struct dma_device *device, *_d;
struct dma_chan *chan = NULL;
int err;
mutex_lock(&dma_list_mutex);
list_for_each_entry_safe(device, _d, &dma_device_list, global_node) {
chan = private_candidate(mask, device, fn, fn_param);
if (chan) {
dma_cap_set(DMA_PRIVATE, device->cap_mask);
device->privatecnt++;
err = dma_chan_get(chan);
if (err == -ENODEV) {
pr_debug("%s: %s module removed\n",
__func__, dma_chan_name(chan));
list_del_rcu(&device->global_node);
} else if (err)
pr_debug("%s: failed to get %s: (%d)\n",
__func__, dma_chan_name(chan), err);
else
break;
if (--device->privatecnt == 0)
dma_cap_clear(DMA_PRIVATE, device->cap_mask);
chan = NULL;
}
}
mutex_unlock(&dma_list_mutex);
pr_debug("%s: %s (%s)\n",
__func__,
chan ? "success" : "fail",
chan ? dma_chan_name(chan) : NULL);
return chan;
}
struct dma_chan *dma_request_slave_channel_reason(struct device *dev,
const char *name)
{
struct dma_chan *chan;
if (dev->of_node)
return of_dma_request_slave_channel(dev->of_node, name);
if (ACPI_HANDLE(dev)) {
chan = acpi_dma_request_slave_chan_by_name(dev, name);
if (chan)
return chan;
}
return ERR_PTR(-ENODEV);
}
struct dma_chan *dma_request_slave_channel(struct device *dev,
const char *name)
{
struct dma_chan *ch = dma_request_slave_channel_reason(dev, name);
if (IS_ERR(ch))
return NULL;
return ch;
}
void dma_release_channel(struct dma_chan *chan)
{
mutex_lock(&dma_list_mutex);
WARN_ONCE(chan->client_count != 1,
"chan reference count %d != 1\n", chan->client_count);
dma_chan_put(chan);
if (--chan->device->privatecnt == 0)
dma_cap_clear(DMA_PRIVATE, chan->device->cap_mask);
mutex_unlock(&dma_list_mutex);
}
void dmaengine_get(void)
{
struct dma_device *device, *_d;
struct dma_chan *chan;
int err;
mutex_lock(&dma_list_mutex);
dmaengine_ref_count++;
list_for_each_entry_safe(device, _d, &dma_device_list, global_node) {
if (dma_has_cap(DMA_PRIVATE, device->cap_mask))
continue;
list_for_each_entry(chan, &device->channels, device_node) {
err = dma_chan_get(chan);
if (err == -ENODEV) {
list_del_rcu(&device->global_node);
break;
} else if (err)
pr_debug("%s: failed to get %s: (%d)\n",
__func__, dma_chan_name(chan), err);
}
}
if (dmaengine_ref_count == 1)
dma_channel_rebalance();
mutex_unlock(&dma_list_mutex);
}
void dmaengine_put(void)
{
struct dma_device *device;
struct dma_chan *chan;
mutex_lock(&dma_list_mutex);
dmaengine_ref_count--;
BUG_ON(dmaengine_ref_count < 0);
list_for_each_entry(device, &dma_device_list, global_node) {
if (dma_has_cap(DMA_PRIVATE, device->cap_mask))
continue;
list_for_each_entry(chan, &device->channels, device_node)
dma_chan_put(chan);
}
mutex_unlock(&dma_list_mutex);
}
static bool device_has_all_tx_types(struct dma_device *device)
{
#ifdef CONFIG_ASYNC_TX_DMA
if (!dma_has_cap(DMA_INTERRUPT, device->cap_mask))
return false;
#endif
#if defined(CONFIG_ASYNC_MEMCPY) || defined(CONFIG_ASYNC_MEMCPY_MODULE)
if (!dma_has_cap(DMA_MEMCPY, device->cap_mask))
return false;
#endif
#if defined(CONFIG_ASYNC_XOR) || defined(CONFIG_ASYNC_XOR_MODULE)
if (!dma_has_cap(DMA_XOR, device->cap_mask))
return false;
#ifndef CONFIG_ASYNC_TX_DISABLE_XOR_VAL_DMA
if (!dma_has_cap(DMA_XOR_VAL, device->cap_mask))
return false;
#endif
#endif
#if defined(CONFIG_ASYNC_PQ) || defined(CONFIG_ASYNC_PQ_MODULE)
if (!dma_has_cap(DMA_PQ, device->cap_mask))
return false;
#ifndef CONFIG_ASYNC_TX_DISABLE_PQ_VAL_DMA
if (!dma_has_cap(DMA_PQ_VAL, device->cap_mask))
return false;
#endif
#endif
return true;
}
static int get_dma_id(struct dma_device *device)
{
int rc;
mutex_lock(&dma_list_mutex);
rc = idr_alloc(&dma_idr, NULL, 0, 0, GFP_KERNEL);
if (rc >= 0)
device->dev_id = rc;
mutex_unlock(&dma_list_mutex);
return rc < 0 ? rc : 0;
}
int dma_async_device_register(struct dma_device *device)
{
int chancnt = 0, rc;
struct dma_chan* chan;
atomic_t *idr_ref;
if (!device)
return -ENODEV;
BUG_ON(dma_has_cap(DMA_MEMCPY, device->cap_mask) &&
!device->device_prep_dma_memcpy);
BUG_ON(dma_has_cap(DMA_XOR, device->cap_mask) &&
!device->device_prep_dma_xor);
BUG_ON(dma_has_cap(DMA_XOR_VAL, device->cap_mask) &&
!device->device_prep_dma_xor_val);
BUG_ON(dma_has_cap(DMA_PQ, device->cap_mask) &&
!device->device_prep_dma_pq);
BUG_ON(dma_has_cap(DMA_PQ_VAL, device->cap_mask) &&
!device->device_prep_dma_pq_val);
BUG_ON(dma_has_cap(DMA_INTERRUPT, device->cap_mask) &&
!device->device_prep_dma_interrupt);
BUG_ON(dma_has_cap(DMA_SG, device->cap_mask) &&
!device->device_prep_dma_sg);
BUG_ON(dma_has_cap(DMA_CYCLIC, device->cap_mask) &&
!device->device_prep_dma_cyclic);
BUG_ON(dma_has_cap(DMA_SLAVE, device->cap_mask) &&
!device->device_control);
BUG_ON(dma_has_cap(DMA_INTERLEAVE, device->cap_mask) &&
!device->device_prep_interleaved_dma);
BUG_ON(!device->device_alloc_chan_resources);
BUG_ON(!device->device_free_chan_resources);
BUG_ON(!device->device_tx_status);
BUG_ON(!device->device_issue_pending);
BUG_ON(!device->dev);
if (device_has_all_tx_types(device))
dma_cap_set(DMA_ASYNC_TX, device->cap_mask);
idr_ref = kmalloc(sizeof(*idr_ref), GFP_KERNEL);
if (!idr_ref)
return -ENOMEM;
rc = get_dma_id(device);
if (rc != 0) {
kfree(idr_ref);
return rc;
}
atomic_set(idr_ref, 0);
list_for_each_entry(chan, &device->channels, device_node) {
rc = -ENOMEM;
chan->local = alloc_percpu(typeof(*chan->local));
if (chan->local == NULL)
goto err_out;
chan->dev = kzalloc(sizeof(*chan->dev), GFP_KERNEL);
if (chan->dev == NULL) {
free_percpu(chan->local);
chan->local = NULL;
goto err_out;
}
chan->chan_id = chancnt++;
chan->dev->device.class = &dma_devclass;
chan->dev->device.parent = device->dev;
chan->dev->chan = chan;
chan->dev->idr_ref = idr_ref;
chan->dev->dev_id = device->dev_id;
atomic_inc(idr_ref);
dev_set_name(&chan->dev->device, "dma%dchan%d",
device->dev_id, chan->chan_id);
rc = device_register(&chan->dev->device);
if (rc) {
free_percpu(chan->local);
chan->local = NULL;
kfree(chan->dev);
atomic_dec(idr_ref);
goto err_out;
}
chan->client_count = 0;
}
device->chancnt = chancnt;
mutex_lock(&dma_list_mutex);
if (dmaengine_ref_count && !dma_has_cap(DMA_PRIVATE, device->cap_mask))
list_for_each_entry(chan, &device->channels, device_node) {
if (dma_chan_get(chan) == -ENODEV) {
rc = -ENODEV;
mutex_unlock(&dma_list_mutex);
goto err_out;
}
}
list_add_tail_rcu(&device->global_node, &dma_device_list);
if (dma_has_cap(DMA_PRIVATE, device->cap_mask))
device->privatecnt++;
dma_channel_rebalance();
mutex_unlock(&dma_list_mutex);
return 0;
err_out:
if (atomic_read(idr_ref) == 0) {
mutex_lock(&dma_list_mutex);
idr_remove(&dma_idr, device->dev_id);
mutex_unlock(&dma_list_mutex);
kfree(idr_ref);
return rc;
}
list_for_each_entry(chan, &device->channels, device_node) {
if (chan->local == NULL)
continue;
mutex_lock(&dma_list_mutex);
chan->dev->chan = NULL;
mutex_unlock(&dma_list_mutex);
device_unregister(&chan->dev->device);
free_percpu(chan->local);
}
return rc;
}
void dma_async_device_unregister(struct dma_device *device)
{
struct dma_chan *chan;
mutex_lock(&dma_list_mutex);
list_del_rcu(&device->global_node);
dma_channel_rebalance();
mutex_unlock(&dma_list_mutex);
list_for_each_entry(chan, &device->channels, device_node) {
WARN_ONCE(chan->client_count,
"%s called while %d clients hold a reference\n",
__func__, chan->client_count);
mutex_lock(&dma_list_mutex);
chan->dev->chan = NULL;
mutex_unlock(&dma_list_mutex);
device_unregister(&chan->dev->device);
free_percpu(chan->local);
}
}
static struct dmaengine_unmap_pool *__get_unmap_pool(int nr)
{
int order = get_count_order(nr);
switch (order) {
case 0 ... 1:
return &unmap_pool[0];
case 2 ... 4:
return &unmap_pool[1];
case 5 ... 7:
return &unmap_pool[2];
case 8:
return &unmap_pool[3];
default:
BUG();
return NULL;
}
}
static void dmaengine_unmap(struct kref *kref)
{
struct dmaengine_unmap_data *unmap = container_of(kref, typeof(*unmap), kref);
struct device *dev = unmap->dev;
int cnt, i;
cnt = unmap->to_cnt;
for (i = 0; i < cnt; i++)
dma_unmap_page(dev, unmap->addr[i], unmap->len,
DMA_TO_DEVICE);
cnt += unmap->from_cnt;
for (; i < cnt; i++)
dma_unmap_page(dev, unmap->addr[i], unmap->len,
DMA_FROM_DEVICE);
cnt += unmap->bidi_cnt;
for (; i < cnt; i++) {
if (unmap->addr[i] == 0)
continue;
dma_unmap_page(dev, unmap->addr[i], unmap->len,
DMA_BIDIRECTIONAL);
}
mempool_free(unmap, __get_unmap_pool(cnt)->pool);
}
void dmaengine_unmap_put(struct dmaengine_unmap_data *unmap)
{
if (unmap)
kref_put(&unmap->kref, dmaengine_unmap);
}
static void dmaengine_destroy_unmap_pool(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(unmap_pool); i++) {
struct dmaengine_unmap_pool *p = &unmap_pool[i];
if (p->pool)
mempool_destroy(p->pool);
p->pool = NULL;
if (p->cache)
kmem_cache_destroy(p->cache);
p->cache = NULL;
}
}
static int __init dmaengine_init_unmap_pool(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(unmap_pool); i++) {
struct dmaengine_unmap_pool *p = &unmap_pool[i];
size_t size;
size = sizeof(struct dmaengine_unmap_data) +
sizeof(dma_addr_t) * p->size;
p->cache = kmem_cache_create(p->name, size, 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!p->cache)
break;
p->pool = mempool_create_slab_pool(1, p->cache);
if (!p->pool)
break;
}
if (i == ARRAY_SIZE(unmap_pool))
return 0;
dmaengine_destroy_unmap_pool();
return -ENOMEM;
}
struct dmaengine_unmap_data *
dmaengine_get_unmap_data(struct device *dev, int nr, gfp_t flags)
{
struct dmaengine_unmap_data *unmap;
unmap = mempool_alloc(__get_unmap_pool(nr)->pool, flags);
if (!unmap)
return NULL;
memset(unmap, 0, sizeof(*unmap));
kref_init(&unmap->kref);
unmap->dev = dev;
return unmap;
}
dma_cookie_t
dma_async_memcpy_pg_to_pg(struct dma_chan *chan, struct page *dest_pg,
unsigned int dest_off, struct page *src_pg, unsigned int src_off,
size_t len)
{
struct dma_device *dev = chan->device;
struct dma_async_tx_descriptor *tx;
struct dmaengine_unmap_data *unmap;
dma_cookie_t cookie;
unsigned long flags;
unmap = dmaengine_get_unmap_data(dev->dev, 2, GFP_NOWAIT);
if (!unmap)
return -ENOMEM;
unmap->to_cnt = 1;
unmap->from_cnt = 1;
unmap->addr[0] = dma_map_page(dev->dev, src_pg, src_off, len,
DMA_TO_DEVICE);
unmap->addr[1] = dma_map_page(dev->dev, dest_pg, dest_off, len,
DMA_FROM_DEVICE);
unmap->len = len;
flags = DMA_CTRL_ACK;
tx = dev->device_prep_dma_memcpy(chan, unmap->addr[1], unmap->addr[0],
len, flags);
if (!tx) {
dmaengine_unmap_put(unmap);
return -ENOMEM;
}
dma_set_unmap(tx, unmap);
cookie = tx->tx_submit(tx);
dmaengine_unmap_put(unmap);
preempt_disable();
__this_cpu_add(chan->local->bytes_transferred, len);
__this_cpu_inc(chan->local->memcpy_count);
preempt_enable();
return cookie;
}
dma_cookie_t
dma_async_memcpy_buf_to_buf(struct dma_chan *chan, void *dest,
void *src, size_t len)
{
return dma_async_memcpy_pg_to_pg(chan, virt_to_page(dest),
(unsigned long) dest & ~PAGE_MASK,
virt_to_page(src),
(unsigned long) src & ~PAGE_MASK, len);
}
dma_cookie_t
dma_async_memcpy_buf_to_pg(struct dma_chan *chan, struct page *page,
unsigned int offset, void *kdata, size_t len)
{
return dma_async_memcpy_pg_to_pg(chan, page, offset,
virt_to_page(kdata),
(unsigned long) kdata & ~PAGE_MASK, len);
}
void dma_async_tx_descriptor_init(struct dma_async_tx_descriptor *tx,
struct dma_chan *chan)
{
tx->chan = chan;
#ifdef CONFIG_ASYNC_TX_ENABLE_CHANNEL_SWITCH
spin_lock_init(&tx->lock);
#endif
}
enum dma_status
dma_wait_for_async_tx(struct dma_async_tx_descriptor *tx)
{
unsigned long dma_sync_wait_timeout = jiffies + msecs_to_jiffies(5000);
if (!tx)
return DMA_COMPLETE;
while (tx->cookie == -EBUSY) {
if (time_after_eq(jiffies, dma_sync_wait_timeout)) {
pr_err("%s timeout waiting for descriptor submission\n",
__func__);
return DMA_ERROR;
}
cpu_relax();
}
return dma_sync_wait(tx->chan, tx->cookie);
}
void dma_run_dependencies(struct dma_async_tx_descriptor *tx)
{
struct dma_async_tx_descriptor *dep = txd_next(tx);
struct dma_async_tx_descriptor *dep_next;
struct dma_chan *chan;
if (!dep)
return;
txd_clear_next(tx);
chan = dep->chan;
for (; dep; dep = dep_next) {
txd_lock(dep);
txd_clear_parent(dep);
dep_next = txd_next(dep);
if (dep_next && dep_next->chan == chan)
txd_clear_next(dep);
else
dep_next = NULL;
txd_unlock(dep);
dep->tx_submit(dep);
}
chan->device->device_issue_pending(chan);
}
static int __init dma_bus_init(void)
{
int err = dmaengine_init_unmap_pool();
if (err)
return err;
return class_register(&dma_devclass);
}
