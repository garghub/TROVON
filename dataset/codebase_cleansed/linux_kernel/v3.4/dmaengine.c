static struct dma_chan *dev_to_dma_chan(struct device *dev)
{
struct dma_chan_dev *chan_dev;
chan_dev = container_of(dev, typeof(*chan_dev), device);
return chan_dev->chan;
}
static ssize_t show_memcpy_count(struct device *dev, struct device_attribute *attr, char *buf)
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
static ssize_t show_bytes_transferred(struct device *dev, struct device_attribute *attr,
char *buf)
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
static ssize_t show_in_use(struct device *dev, struct device_attribute *attr, char *buf)
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
__dma_device_satisfies_mask(struct dma_device *device, dma_cap_mask_t *want)
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
printk(KERN_ERR "dma_sync_wait_timeout!\n");
return DMA_ERROR;
}
} while (status == DMA_IN_PROGRESS);
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
pr_err("dmaengine: initialization failure\n");
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
static struct dma_chan *nth_chan(enum dma_transaction_type cap, int n)
{
struct dma_device *device;
struct dma_chan *chan;
struct dma_chan *ret = NULL;
struct dma_chan *min = NULL;
list_for_each_entry(device, &dma_device_list, global_node) {
if (!dma_has_cap(cap, device->cap_mask) ||
dma_has_cap(DMA_PRIVATE, device->cap_mask))
continue;
list_for_each_entry(chan, &device->channels, device_node) {
if (!chan->client_count)
continue;
if (!min)
min = chan;
else if (chan->table_count < min->table_count)
min = chan;
if (n-- == 0) {
ret = chan;
break;
}
}
if (ret)
break;
}
if (!ret)
ret = min;
if (ret)
ret->table_count++;
return ret;
}
static void dma_channel_rebalance(void)
{
struct dma_chan *chan;
struct dma_device *device;
int cpu;
int cap;
int n;
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
n = 0;
for_each_dma_cap_mask(cap, dma_cap_mask_all)
for_each_online_cpu(cpu) {
if (num_possible_cpus() > 1)
chan = nth_chan(cap, n++);
else
chan = nth_chan(cap, -1);
per_cpu_ptr(channel_table[cap], cpu)->chan = chan;
}
}
static struct dma_chan *private_candidate(dma_cap_mask_t *mask, struct dma_device *dev,
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
struct dma_chan *__dma_request_channel(dma_cap_mask_t *mask, dma_filter_fn fn, void *fn_param)
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
pr_debug("%s: %s module removed\n", __func__,
dma_chan_name(chan));
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
pr_debug("%s: %s (%s)\n", __func__, chan ? "success" : "fail",
chan ? dma_chan_name(chan) : NULL);
return chan;
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
pr_err("%s: failed to get %s: (%d)\n",
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
#if defined(CONFIG_ASYNC_MEMSET) || defined(CONFIG_ASYNC_MEMSET_MODULE)
if (!dma_has_cap(DMA_MEMSET, device->cap_mask))
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
idr_retry:
if (!idr_pre_get(&dma_idr, GFP_KERNEL))
return -ENOMEM;
mutex_lock(&dma_list_mutex);
rc = idr_get_new(&dma_idr, NULL, &device->dev_id);
mutex_unlock(&dma_list_mutex);
if (rc == -EAGAIN)
goto idr_retry;
else if (rc != 0)
return rc;
return 0;
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
BUG_ON(dma_has_cap(DMA_MEMSET, device->cap_mask) &&
!device->device_prep_dma_memset);
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
dma_cookie_t
dma_async_memcpy_buf_to_buf(struct dma_chan *chan, void *dest,
void *src, size_t len)
{
struct dma_device *dev = chan->device;
struct dma_async_tx_descriptor *tx;
dma_addr_t dma_dest, dma_src;
dma_cookie_t cookie;
unsigned long flags;
dma_src = dma_map_single(dev->dev, src, len, DMA_TO_DEVICE);
dma_dest = dma_map_single(dev->dev, dest, len, DMA_FROM_DEVICE);
flags = DMA_CTRL_ACK |
DMA_COMPL_SRC_UNMAP_SINGLE |
DMA_COMPL_DEST_UNMAP_SINGLE;
tx = dev->device_prep_dma_memcpy(chan, dma_dest, dma_src, len, flags);
if (!tx) {
dma_unmap_single(dev->dev, dma_src, len, DMA_TO_DEVICE);
dma_unmap_single(dev->dev, dma_dest, len, DMA_FROM_DEVICE);
return -ENOMEM;
}
tx->callback = NULL;
cookie = tx->tx_submit(tx);
preempt_disable();
__this_cpu_add(chan->local->bytes_transferred, len);
__this_cpu_inc(chan->local->memcpy_count);
preempt_enable();
return cookie;
}
dma_cookie_t
dma_async_memcpy_buf_to_pg(struct dma_chan *chan, struct page *page,
unsigned int offset, void *kdata, size_t len)
{
struct dma_device *dev = chan->device;
struct dma_async_tx_descriptor *tx;
dma_addr_t dma_dest, dma_src;
dma_cookie_t cookie;
unsigned long flags;
dma_src = dma_map_single(dev->dev, kdata, len, DMA_TO_DEVICE);
dma_dest = dma_map_page(dev->dev, page, offset, len, DMA_FROM_DEVICE);
flags = DMA_CTRL_ACK | DMA_COMPL_SRC_UNMAP_SINGLE;
tx = dev->device_prep_dma_memcpy(chan, dma_dest, dma_src, len, flags);
if (!tx) {
dma_unmap_single(dev->dev, dma_src, len, DMA_TO_DEVICE);
dma_unmap_page(dev->dev, dma_dest, len, DMA_FROM_DEVICE);
return -ENOMEM;
}
tx->callback = NULL;
cookie = tx->tx_submit(tx);
preempt_disable();
__this_cpu_add(chan->local->bytes_transferred, len);
__this_cpu_inc(chan->local->memcpy_count);
preempt_enable();
return cookie;
}
dma_cookie_t
dma_async_memcpy_pg_to_pg(struct dma_chan *chan, struct page *dest_pg,
unsigned int dest_off, struct page *src_pg, unsigned int src_off,
size_t len)
{
struct dma_device *dev = chan->device;
struct dma_async_tx_descriptor *tx;
dma_addr_t dma_dest, dma_src;
dma_cookie_t cookie;
unsigned long flags;
dma_src = dma_map_page(dev->dev, src_pg, src_off, len, DMA_TO_DEVICE);
dma_dest = dma_map_page(dev->dev, dest_pg, dest_off, len,
DMA_FROM_DEVICE);
flags = DMA_CTRL_ACK;
tx = dev->device_prep_dma_memcpy(chan, dma_dest, dma_src, len, flags);
if (!tx) {
dma_unmap_page(dev->dev, dma_src, len, DMA_TO_DEVICE);
dma_unmap_page(dev->dev, dma_dest, len, DMA_FROM_DEVICE);
return -ENOMEM;
}
tx->callback = NULL;
cookie = tx->tx_submit(tx);
preempt_disable();
__this_cpu_add(chan->local->bytes_transferred, len);
__this_cpu_inc(chan->local->memcpy_count);
preempt_enable();
return cookie;
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
return DMA_SUCCESS;
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
return class_register(&dma_devclass);
}
