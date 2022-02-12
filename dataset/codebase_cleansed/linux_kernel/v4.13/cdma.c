static void host1x_pushbuffer_destroy(struct push_buffer *pb)
{
struct host1x_cdma *cdma = pb_to_cdma(pb);
struct host1x *host1x = cdma_to_host1x(cdma);
if (!pb->phys)
return;
if (host1x->domain) {
iommu_unmap(host1x->domain, pb->dma, pb->alloc_size);
free_iova(&host1x->iova, iova_pfn(&host1x->iova, pb->dma));
}
dma_free_wc(host1x->dev, pb->alloc_size, pb->mapped, pb->phys);
pb->mapped = NULL;
pb->phys = 0;
}
static int host1x_pushbuffer_init(struct push_buffer *pb)
{
struct host1x_cdma *cdma = pb_to_cdma(pb);
struct host1x *host1x = cdma_to_host1x(cdma);
struct iova *alloc;
u32 size;
int err;
pb->mapped = NULL;
pb->phys = 0;
pb->size = HOST1X_PUSHBUFFER_SLOTS * 8;
size = pb->size + 4;
pb->fence = pb->size - 8;
pb->pos = 0;
if (host1x->domain) {
unsigned long shift;
size = iova_align(&host1x->iova, size);
pb->mapped = dma_alloc_wc(host1x->dev, size, &pb->phys,
GFP_KERNEL);
if (!pb->mapped)
return -ENOMEM;
shift = iova_shift(&host1x->iova);
alloc = alloc_iova(&host1x->iova, size >> shift,
host1x->iova_end >> shift, true);
if (!alloc) {
err = -ENOMEM;
goto iommu_free_mem;
}
pb->dma = iova_dma_addr(&host1x->iova, alloc);
err = iommu_map(host1x->domain, pb->dma, pb->phys, size,
IOMMU_READ);
if (err)
goto iommu_free_iova;
} else {
pb->mapped = dma_alloc_wc(host1x->dev, size, &pb->phys,
GFP_KERNEL);
if (!pb->mapped)
return -ENOMEM;
pb->dma = pb->phys;
}
pb->alloc_size = size;
host1x_hw_pushbuffer_init(host1x, pb);
return 0;
iommu_free_iova:
__free_iova(&host1x->iova, alloc);
iommu_free_mem:
dma_free_wc(host1x->dev, pb->alloc_size, pb->mapped, pb->phys);
return err;
}
static void host1x_pushbuffer_push(struct push_buffer *pb, u32 op1, u32 op2)
{
u32 *p = (u32 *)((void *)pb->mapped + pb->pos);
WARN_ON(pb->pos == pb->fence);
*(p++) = op1;
*(p++) = op2;
pb->pos = (pb->pos + 8) & (pb->size - 1);
}
static void host1x_pushbuffer_pop(struct push_buffer *pb, unsigned int slots)
{
pb->fence = (pb->fence + slots * 8) & (pb->size - 1);
}
static u32 host1x_pushbuffer_space(struct push_buffer *pb)
{
return ((pb->fence - pb->pos) & (pb->size - 1)) / 8;
}
unsigned int host1x_cdma_wait_locked(struct host1x_cdma *cdma,
enum cdma_event event)
{
for (;;) {
struct push_buffer *pb = &cdma->push_buffer;
unsigned int space;
switch (event) {
case CDMA_EVENT_SYNC_QUEUE_EMPTY:
space = list_empty(&cdma->sync_queue) ? 1 : 0;
break;
case CDMA_EVENT_PUSH_BUFFER_SPACE:
space = host1x_pushbuffer_space(pb);
break;
default:
WARN_ON(1);
return -EINVAL;
}
if (space)
return space;
trace_host1x_wait_cdma(dev_name(cdma_to_channel(cdma)->dev),
event);
if (cdma->event != CDMA_EVENT_NONE) {
mutex_unlock(&cdma->lock);
schedule();
mutex_lock(&cdma->lock);
continue;
}
cdma->event = event;
mutex_unlock(&cdma->lock);
down(&cdma->sem);
mutex_lock(&cdma->lock);
}
return 0;
}
static void cdma_start_timer_locked(struct host1x_cdma *cdma,
struct host1x_job *job)
{
struct host1x *host = cdma_to_host1x(cdma);
if (cdma->timeout.client) {
return;
}
cdma->timeout.client = job->client;
cdma->timeout.syncpt = host1x_syncpt_get(host, job->syncpt_id);
cdma->timeout.syncpt_val = job->syncpt_end;
cdma->timeout.start_ktime = ktime_get();
schedule_delayed_work(&cdma->timeout.wq,
msecs_to_jiffies(job->timeout));
}
static void stop_cdma_timer_locked(struct host1x_cdma *cdma)
{
cancel_delayed_work(&cdma->timeout.wq);
cdma->timeout.client = 0;
}
static void update_cdma_locked(struct host1x_cdma *cdma)
{
bool signal = false;
struct host1x *host1x = cdma_to_host1x(cdma);
struct host1x_job *job, *n;
if (!cdma->running)
return;
list_for_each_entry_safe(job, n, &cdma->sync_queue, list) {
struct host1x_syncpt *sp =
host1x_syncpt_get(host1x, job->syncpt_id);
if (!host1x_syncpt_is_expired(sp, job->syncpt_end)) {
if (job->timeout)
cdma_start_timer_locked(cdma, job);
break;
}
if (cdma->timeout.client)
stop_cdma_timer_locked(cdma);
host1x_job_unpin(job);
if (job->num_slots) {
struct push_buffer *pb = &cdma->push_buffer;
host1x_pushbuffer_pop(pb, job->num_slots);
if (cdma->event == CDMA_EVENT_PUSH_BUFFER_SPACE)
signal = true;
}
list_del(&job->list);
host1x_job_put(job);
}
if (cdma->event == CDMA_EVENT_SYNC_QUEUE_EMPTY &&
list_empty(&cdma->sync_queue))
signal = true;
if (signal) {
cdma->event = CDMA_EVENT_NONE;
up(&cdma->sem);
}
}
void host1x_cdma_update_sync_queue(struct host1x_cdma *cdma,
struct device *dev)
{
struct host1x *host1x = cdma_to_host1x(cdma);
u32 restart_addr, syncpt_incrs, syncpt_val;
struct host1x_job *job = NULL;
syncpt_val = host1x_syncpt_load(cdma->timeout.syncpt);
dev_dbg(dev, "%s: starting cleanup (thresh %d)\n",
__func__, syncpt_val);
dev_dbg(dev, "%s: skip completed buffers still in sync_queue\n",
__func__);
list_for_each_entry(job, &cdma->sync_queue, list) {
if (syncpt_val < job->syncpt_end)
break;
host1x_job_dump(dev, job);
}
dev_dbg(dev, "%s: perform CPU incr on pending same ctx buffers\n",
__func__);
if (!list_empty(&cdma->sync_queue))
restart_addr = job->first_get;
else
restart_addr = cdma->last_pos;
list_for_each_entry_from(job, &cdma->sync_queue, list) {
if (job->client != cdma->timeout.client)
break;
job->timeout = 0;
syncpt_incrs = job->syncpt_end - syncpt_val;
dev_dbg(dev, "%s: CPU incr (%d)\n", __func__, syncpt_incrs);
host1x_job_dump(dev, job);
host1x_hw_cdma_timeout_cpu_incr(host1x, cdma, job->first_get,
syncpt_incrs, job->syncpt_end,
job->num_slots);
syncpt_val += syncpt_incrs;
}
list_for_each_entry_from(job, &cdma->sync_queue, list)
if (job->client == cdma->timeout.client)
job->timeout = min_t(unsigned int, job->timeout, 500);
dev_dbg(dev, "%s: finished sync_queue modification\n", __func__);
host1x_hw_cdma_resume(host1x, cdma, restart_addr);
}
int host1x_cdma_init(struct host1x_cdma *cdma)
{
int err;
mutex_init(&cdma->lock);
sema_init(&cdma->sem, 0);
INIT_LIST_HEAD(&cdma->sync_queue);
cdma->event = CDMA_EVENT_NONE;
cdma->running = false;
cdma->torndown = false;
err = host1x_pushbuffer_init(&cdma->push_buffer);
if (err)
return err;
return 0;
}
int host1x_cdma_deinit(struct host1x_cdma *cdma)
{
struct push_buffer *pb = &cdma->push_buffer;
struct host1x *host1x = cdma_to_host1x(cdma);
if (cdma->running) {
pr_warn("%s: CDMA still running\n", __func__);
return -EBUSY;
}
host1x_pushbuffer_destroy(pb);
host1x_hw_cdma_timeout_destroy(host1x, cdma);
return 0;
}
int host1x_cdma_begin(struct host1x_cdma *cdma, struct host1x_job *job)
{
struct host1x *host1x = cdma_to_host1x(cdma);
mutex_lock(&cdma->lock);
if (job->timeout) {
if (!cdma->timeout.initialized) {
int err;
err = host1x_hw_cdma_timeout_init(host1x, cdma,
job->syncpt_id);
if (err) {
mutex_unlock(&cdma->lock);
return err;
}
}
}
if (!cdma->running)
host1x_hw_cdma_start(host1x, cdma);
cdma->slots_free = 0;
cdma->slots_used = 0;
cdma->first_get = cdma->push_buffer.pos;
trace_host1x_cdma_begin(dev_name(job->channel->dev));
return 0;
}
void host1x_cdma_push(struct host1x_cdma *cdma, u32 op1, u32 op2)
{
struct host1x *host1x = cdma_to_host1x(cdma);
struct push_buffer *pb = &cdma->push_buffer;
u32 slots_free = cdma->slots_free;
if (host1x_debug_trace_cmdbuf)
trace_host1x_cdma_push(dev_name(cdma_to_channel(cdma)->dev),
op1, op2);
if (slots_free == 0) {
host1x_hw_cdma_flush(host1x, cdma);
slots_free = host1x_cdma_wait_locked(cdma,
CDMA_EVENT_PUSH_BUFFER_SPACE);
}
cdma->slots_free = slots_free - 1;
cdma->slots_used++;
host1x_pushbuffer_push(pb, op1, op2);
}
void host1x_cdma_end(struct host1x_cdma *cdma,
struct host1x_job *job)
{
struct host1x *host1x = cdma_to_host1x(cdma);
bool idle = list_empty(&cdma->sync_queue);
host1x_hw_cdma_flush(host1x, cdma);
job->first_get = cdma->first_get;
job->num_slots = cdma->slots_used;
host1x_job_get(job);
list_add_tail(&job->list, &cdma->sync_queue);
if (job->timeout && idle)
cdma_start_timer_locked(cdma, job);
trace_host1x_cdma_end(dev_name(job->channel->dev));
mutex_unlock(&cdma->lock);
}
void host1x_cdma_update(struct host1x_cdma *cdma)
{
mutex_lock(&cdma->lock);
update_cdma_locked(cdma);
mutex_unlock(&cdma->lock);
}
