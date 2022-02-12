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
static void fill_balloon(struct virtio_balloon *vb, size_t num)
{
struct balloon_dev_info *vb_dev_info = &vb->vb_dev_info;
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
adjust_managed_page_count(page, -1);
}
if (vb->num_pfns != 0)
tell_host(vb, vb->inflate_vq);
mutex_unlock(&vb->balloon_lock);
}
static void release_pages_by_pfn(const u32 pfns[], unsigned int num)
{
unsigned int i;
for (i = 0; i < num; i += VIRTIO_BALLOON_PAGES_PER_PAGE) {
struct page *page = balloon_pfn_to_page(pfns[i]);
adjust_managed_page_count(page, 1);
put_page(page);
}
}
static void leak_balloon(struct virtio_balloon *vb, size_t num)
{
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
if (vb->num_pfns != 0)
tell_host(vb, vb->deflate_vq);
mutex_unlock(&vb->balloon_lock);
release_pages_by_pfn(vb->pfns, vb->num_pfns);
}
static inline void update_stat(struct virtio_balloon *vb, int idx,
u16 tag, u64 val)
{
BUG_ON(idx >= VIRTIO_BALLOON_S_NR);
vb->stats[idx].tag = tag;
vb->stats[idx].val = val;
}
static void update_balloon_stats(struct virtio_balloon *vb)
{
unsigned long events[NR_VM_EVENT_ITEMS];
struct sysinfo i;
int idx = 0;
all_vm_events(events);
si_meminfo(&i);
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
}
static void stats_request(struct virtqueue *vq)
{
struct virtio_balloon *vb = vq->vdev->priv;
vb->need_stats_update = 1;
wake_up(&vb->config_change);
}
static void stats_handle_request(struct virtio_balloon *vb)
{
struct virtqueue *vq;
struct scatterlist sg;
unsigned int len;
vb->need_stats_update = 0;
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
wake_up(&vb->config_change);
}
static inline s64 towards_target(struct virtio_balloon *vb)
{
__le32 v;
s64 target;
virtio_cread(vb->vdev, struct virtio_balloon_config, num_pages, &v);
target = le32_to_cpu(v);
return target - vb->num_pages;
}
static void update_balloon_size(struct virtio_balloon *vb)
{
__le32 actual = cpu_to_le32(vb->num_pages);
virtio_cwrite(vb->vdev, struct virtio_balloon_config, actual,
&actual);
}
static int balloon(void *_vballoon)
{
struct virtio_balloon *vb = _vballoon;
set_freezable();
while (!kthread_should_stop()) {
s64 diff;
try_to_freeze();
wait_event_interruptible(vb->config_change,
(diff = towards_target(vb)) != 0
|| vb->need_stats_update
|| kthread_should_stop()
|| freezing(current));
if (vb->need_stats_update)
stats_handle_request(vb);
if (diff > 0)
fill_balloon(vb, diff);
else if (diff < 0)
leak_balloon(vb, -diff);
update_balloon_size(vb);
cond_resched();
}
return 0;
}
static int init_vqs(struct virtio_balloon *vb)
{
struct virtqueue *vqs[3];
vq_callback_t *callbacks[] = { balloon_ack, balloon_ack, stats_request };
const char *names[] = { "inflate", "deflate", "stats" };
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
vdev->priv = vb = kmalloc(sizeof(*vb), GFP_KERNEL);
if (!vb) {
err = -ENOMEM;
goto out;
}
vb->num_pages = 0;
mutex_init(&vb->balloon_lock);
init_waitqueue_head(&vb->config_change);
init_waitqueue_head(&vb->acked);
vb->vdev = vdev;
vb->need_stats_update = 0;
balloon_devinfo_init(&vb->vb_dev_info);
#ifdef CONFIG_BALLOON_COMPACTION
vb->vb_dev_info.migratepage = virtballoon_migratepage;
#endif
err = init_vqs(vb);
if (err)
goto out_free_vb;
vb->thread = kthread_run(balloon, vb, "vballoon");
if (IS_ERR(vb->thread)) {
err = PTR_ERR(vb->thread);
goto out_del_vqs;
}
return 0;
out_del_vqs:
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
kthread_stop(vb->thread);
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
fill_balloon(vb, towards_target(vb));
update_balloon_size(vb);
return 0;
}
