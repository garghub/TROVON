static u32 page_to_balloon_pfn(struct page *page)
{
unsigned long pfn = page_to_pfn(page);
BUILD_BUG_ON(PAGE_SHIFT < VIRTIO_BALLOON_PFN_SHIFT);
return pfn * VIRTIO_BALLOON_PAGES_PER_PAGE;
}
static struct page *balloon_pfn_to_page(u32 pfn)
{
BUG_ON(pfn % VIRTIO_BALLOON_PAGES_PER_PAGE);
return pfn_to_page(pfn / VIRTIO_BALLOON_PAGES_PER_PAGE);
}
static void balloon_ack(struct virtqueue *vq)
{
struct virtio_balloon *vb = vq->vdev->priv;
wake_up(&vb->acked);
}
static void tell_host(struct virtio_balloon *vb, struct virtqueue *vq)
{
struct scatterlist sg;
unsigned int len;
sg_init_one(&sg, vb->pfns, sizeof(vb->pfns[0]) * vb->num_pfns);
virtqueue_add_outbuf(vq, &sg, 1, vb, GFP_KERNEL);
virtqueue_kick(vq);
wait_event(vb->acked, virtqueue_get_buf(vq, &len));
}
static void set_page_pfns(u32 pfns[], struct page *page)
{
unsigned int i;
for (i = 0; i < VIRTIO_BALLOON_PAGES_PER_PAGE; i++)
pfns[i] = page_to_balloon_pfn(page) + i;
}
static unsigned fill_balloon(struct virtio_balloon *vb, size_t num)
{
struct balloon_dev_info *vb_dev_info = &vb->vb_dev_info;
unsigned num_allocated_pages;
num = min(num, ARRAY_SIZE(vb->pfns));
mutex_lock(&vb->balloon_lock);
for (vb->num_pfns = 0; vb->num_pfns < num;
vb->num_pfns += VIRTIO_BALLOON_PAGES_PER_PAGE) {
struct page *page = balloon_page_enqueue(vb_dev_info);
if (!page) {
dev_info_ratelimited(&vb->vdev->dev,
"Out of puff! Can't get %u pages\n",
VIRTIO_BALLOON_PAGES_PER_PAGE);
msleep(200);
break;
}
set_page_pfns(vb->pfns + vb->num_pfns, page);
vb->num_pages += VIRTIO_BALLOON_PAGES_PER_PAGE;
if (!virtio_has_feature(vb->vdev,
VIRTIO_BALLOON_F_DEFLATE_ON_OOM))
adjust_managed_page_count(page, -1);
}
num_allocated_pages = vb->num_pfns;
if (vb->num_pfns != 0)
tell_host(vb, vb->inflate_vq);
mutex_unlock(&vb->balloon_lock);
return num_allocated_pages;
}
static void release_pages_balloon(struct virtio_balloon *vb)
{
unsigned int i;
for (i = 0; i < vb->num_pfns; i += VIRTIO_BALLOON_PAGES_PER_PAGE) {
struct page *page = balloon_pfn_to_page(vb->pfns[i]);
if (!virtio_has_feature(vb->vdev,
VIRTIO_BALLOON_F_DEFLATE_ON_OOM))
adjust_managed_page_count(page, 1);
put_page(page);
}
}
static unsigned leak_balloon(struct virtio_balloon *vb, size_t num)
{
unsigned num_freed_pages;
struct page *page;
struct balloon_dev_info *vb_dev_info = &vb->vb_dev_info;
num = min(num, ARRAY_SIZE(vb->pfns));
mutex_lock(&vb->balloon_lock);
for (vb->num_pfns = 0; vb->num_pfns < num;
vb->num_pfns += VIRTIO_BALLOON_PAGES_PER_PAGE) {
page = balloon_page_dequeue(vb_dev_info);
if (!page)
break;
set_page_pfns(vb->pfns + vb->num_pfns, page);
vb->num_pages -= VIRTIO_BALLOON_PAGES_PER_PAGE;
}
num_freed_pages = vb->num_pfns;
if (vb->num_pfns != 0)
tell_host(vb, vb->deflate_vq);
release_pages_balloon(vb);
mutex_unlock(&vb->balloon_lock);
return num_freed_pages;
}
static inline void update_stat(struct virtio_balloon *vb, int idx,
u16 tag, u64 val)
{
BUG_ON(idx >= VIRTIO_BALLOON_S_NR);
vb->stats[idx].tag = cpu_to_virtio16(vb->vdev, tag);
vb->stats[idx].val = cpu_to_virtio64(vb->vdev, val);
}
static void update_balloon_stats(struct virtio_balloon *vb)
{
unsigned long events[NR_VM_EVENT_ITEMS];
struct sysinfo i;
int idx = 0;
long available;
all_vm_events(events);
si_meminfo(&i);
available = si_mem_available();
update_stat(vb, idx++, VIRTIO_BALLOON_S_SWAP_IN,
pages_to_bytes(events[PSWPIN]));
update_stat(vb, idx++, VIRTIO_BALLOON_S_SWAP_OUT,
pages_to_bytes(events[PSWPOUT]));
update_stat(vb, idx++, VIRTIO_BALLOON_S_MAJFLT, events[PGMAJFAULT]);
update_stat(vb, idx++, VIRTIO_BALLOON_S_MINFLT, events[PGFAULT]);
update_stat(vb, idx++, VIRTIO_BALLOON_S_MEMFREE,
pages_to_bytes(i.freeram));
update_stat(vb, idx++, VIRTIO_BALLOON_S_MEMTOT,
pages_to_bytes(i.totalram));
update_stat(vb, idx++, VIRTIO_BALLOON_S_AVAIL,
pages_to_bytes(available));
}
static void stats_request(struct virtqueue *vq)
{
struct virtio_balloon *vb = vq->vdev->priv;
spin_lock(&vb->stop_update_lock);
if (!vb->stop_update)
queue_work(system_freezable_wq, &vb->update_balloon_stats_work);
spin_unlock(&vb->stop_update_lock);
}
static void stats_handle_request(struct virtio_balloon *vb)
{
struct virtqueue *vq;
struct scatterlist sg;
unsigned int len;
update_balloon_stats(vb);
vq = vb->stats_vq;
if (!virtqueue_get_buf(vq, &len))
return;
sg_init_one(&sg, vb->stats, sizeof(vb->stats));
virtqueue_add_outbuf(vq, &sg, 1, vb, GFP_KERNEL);
virtqueue_kick(vq);
}
static void virtballoon_changed(struct virtio_device *vdev)
{
struct virtio_balloon *vb = vdev->priv;
unsigned long flags;
spin_lock_irqsave(&vb->stop_update_lock, flags);
if (!vb->stop_update)
queue_work(system_freezable_wq, &vb->update_balloon_size_work);
spin_unlock_irqrestore(&vb->stop_update_lock, flags);
}
static inline s64 towards_target(struct virtio_balloon *vb)
{
s64 target;
u32 num_pages;
virtio_cread(vb->vdev, struct virtio_balloon_config, num_pages,
&num_pages);
if (!virtio_has_feature(vb->vdev, VIRTIO_F_VERSION_1))
num_pages = le32_to_cpu((__force __le32)num_pages);
target = num_pages;
return target - vb->num_pages;
}
static void update_balloon_size(struct virtio_balloon *vb)
{
u32 actual = vb->num_pages;
if (!virtio_has_feature(vb->vdev, VIRTIO_F_VERSION_1))
actual = (__force u32)cpu_to_le32(actual);
virtio_cwrite(vb->vdev, struct virtio_balloon_config, actual,
&actual);
}
static int virtballoon_oom_notify(struct notifier_block *self,
unsigned long dummy, void *parm)
{
struct virtio_balloon *vb;
unsigned long *freed;
unsigned num_freed_pages;
vb = container_of(self, struct virtio_balloon, nb);
if (!virtio_has_feature(vb->vdev, VIRTIO_BALLOON_F_DEFLATE_ON_OOM))
return NOTIFY_OK;
freed = parm;
num_freed_pages = leak_balloon(vb, oom_pages);
update_balloon_size(vb);
*freed += num_freed_pages;
return NOTIFY_OK;
}
static void update_balloon_stats_func(struct work_struct *work)
{
struct virtio_balloon *vb;
vb = container_of(work, struct virtio_balloon,
update_balloon_stats_work);
stats_handle_request(vb);
}
static void update_balloon_size_func(struct work_struct *work)
{
struct virtio_balloon *vb;
s64 diff;
vb = container_of(work, struct virtio_balloon,
update_balloon_size_work);
diff = towards_target(vb);
if (diff > 0)
diff -= fill_balloon(vb, diff);
else if (diff < 0)
diff += leak_balloon(vb, -diff);
update_balloon_size(vb);
if (diff)
queue_work(system_freezable_wq, work);
}
static int init_vqs(struct virtio_balloon *vb)
{
struct virtqueue *vqs[3];
vq_callback_t *callbacks[] = { balloon_ack, balloon_ack, stats_request };
static const char * const names[] = { "inflate", "deflate", "stats" };
int err, nvqs;
nvqs = virtio_has_feature(vb->vdev, VIRTIO_BALLOON_F_STATS_VQ) ? 3 : 2;
err = vb->vdev->config->find_vqs(vb->vdev, nvqs, vqs, callbacks, names);
if (err)
return err;
vb->inflate_vq = vqs[0];
vb->deflate_vq = vqs[1];
if (virtio_has_feature(vb->vdev, VIRTIO_BALLOON_F_STATS_VQ)) {
struct scatterlist sg;
vb->stats_vq = vqs[2];
sg_init_one(&sg, vb->stats, sizeof vb->stats);
if (virtqueue_add_outbuf(vb->stats_vq, &sg, 1, vb, GFP_KERNEL)
< 0)
BUG();
virtqueue_kick(vb->stats_vq);
}
return 0;
}
static int virtballoon_migratepage(struct balloon_dev_info *vb_dev_info,
struct page *newpage, struct page *page, enum migrate_mode mode)
{
struct virtio_balloon *vb = container_of(vb_dev_info,
struct virtio_balloon, vb_dev_info);
unsigned long flags;
if (!mutex_trylock(&vb->balloon_lock))
return -EAGAIN;
get_page(newpage);
spin_lock_irqsave(&vb_dev_info->pages_lock, flags);
balloon_page_insert(vb_dev_info, newpage);
vb_dev_info->isolated_pages--;
__count_vm_event(BALLOON_MIGRATE);
spin_unlock_irqrestore(&vb_dev_info->pages_lock, flags);
vb->num_pfns = VIRTIO_BALLOON_PAGES_PER_PAGE;
set_page_pfns(vb->pfns, newpage);
tell_host(vb, vb->inflate_vq);
balloon_page_delete(page);
vb->num_pfns = VIRTIO_BALLOON_PAGES_PER_PAGE;
set_page_pfns(vb->pfns, page);
tell_host(vb, vb->deflate_vq);
mutex_unlock(&vb->balloon_lock);
put_page(page);
return MIGRATEPAGE_SUCCESS;
}
static int virtballoon_probe(struct virtio_device *vdev)
{
struct virtio_balloon *vb;
int err;
if (!vdev->config->get) {
dev_err(&vdev->dev, "%s failure: config access disabled\n",
__func__);
return -EINVAL;
}
vdev->priv = vb = kmalloc(sizeof(*vb), GFP_KERNEL);
if (!vb) {
err = -ENOMEM;
goto out;
}
INIT_WORK(&vb->update_balloon_stats_work, update_balloon_stats_func);
INIT_WORK(&vb->update_balloon_size_work, update_balloon_size_func);
spin_lock_init(&vb->stop_update_lock);
vb->stop_update = false;
vb->num_pages = 0;
mutex_init(&vb->balloon_lock);
init_waitqueue_head(&vb->acked);
vb->vdev = vdev;
balloon_devinfo_init(&vb->vb_dev_info);
#ifdef CONFIG_BALLOON_COMPACTION
vb->vb_dev_info.migratepage = virtballoon_migratepage;
#endif
err = init_vqs(vb);
if (err)
goto out_free_vb;
vb->nb.notifier_call = virtballoon_oom_notify;
vb->nb.priority = VIRTBALLOON_OOM_NOTIFY_PRIORITY;
err = register_oom_notifier(&vb->nb);
if (err < 0)
goto out_oom_notify;
virtio_device_ready(vdev);
return 0;
out_oom_notify:
vdev->config->del_vqs(vdev);
out_free_vb:
kfree(vb);
out:
return err;
}
static void remove_common(struct virtio_balloon *vb)
{
while (vb->num_pages)
leak_balloon(vb, vb->num_pages);
update_balloon_size(vb);
vb->vdev->config->reset(vb->vdev);
vb->vdev->config->del_vqs(vb->vdev);
}
static void virtballoon_remove(struct virtio_device *vdev)
{
struct virtio_balloon *vb = vdev->priv;
unregister_oom_notifier(&vb->nb);
spin_lock_irq(&vb->stop_update_lock);
vb->stop_update = true;
spin_unlock_irq(&vb->stop_update_lock);
cancel_work_sync(&vb->update_balloon_size_work);
cancel_work_sync(&vb->update_balloon_stats_work);
remove_common(vb);
kfree(vb);
}
static int virtballoon_freeze(struct virtio_device *vdev)
{
struct virtio_balloon *vb = vdev->priv;
remove_common(vb);
return 0;
}
static int virtballoon_restore(struct virtio_device *vdev)
{
struct virtio_balloon *vb = vdev->priv;
int ret;
ret = init_vqs(vdev->priv);
if (ret)
return ret;
virtio_device_ready(vdev);
if (towards_target(vb))
virtballoon_changed(vdev);
update_balloon_size(vb);
return 0;
}
