static bool vring_use_dma_api(struct virtio_device *vdev)
{
if (!virtio_has_iommu_quirk(vdev))
return true;
if (xen_domain())
return true;
return false;
}
static inline struct device *vring_dma_dev(const struct vring_virtqueue *vq)
{
return vq->vq.vdev->dev.parent;
}
static dma_addr_t vring_map_one_sg(const struct vring_virtqueue *vq,
struct scatterlist *sg,
enum dma_data_direction direction)
{
if (!vring_use_dma_api(vq->vq.vdev))
return (dma_addr_t)sg_phys(sg);
return dma_map_page(vring_dma_dev(vq),
sg_page(sg), sg->offset, sg->length,
direction);
}
static dma_addr_t vring_map_single(const struct vring_virtqueue *vq,
void *cpu_addr, size_t size,
enum dma_data_direction direction)
{
if (!vring_use_dma_api(vq->vq.vdev))
return (dma_addr_t)virt_to_phys(cpu_addr);
return dma_map_single(vring_dma_dev(vq),
cpu_addr, size, direction);
}
static void vring_unmap_one(const struct vring_virtqueue *vq,
struct vring_desc *desc)
{
u16 flags;
if (!vring_use_dma_api(vq->vq.vdev))
return;
flags = virtio16_to_cpu(vq->vq.vdev, desc->flags);
if (flags & VRING_DESC_F_INDIRECT) {
dma_unmap_single(vring_dma_dev(vq),
virtio64_to_cpu(vq->vq.vdev, desc->addr),
virtio32_to_cpu(vq->vq.vdev, desc->len),
(flags & VRING_DESC_F_WRITE) ?
DMA_FROM_DEVICE : DMA_TO_DEVICE);
} else {
dma_unmap_page(vring_dma_dev(vq),
virtio64_to_cpu(vq->vq.vdev, desc->addr),
virtio32_to_cpu(vq->vq.vdev, desc->len),
(flags & VRING_DESC_F_WRITE) ?
DMA_FROM_DEVICE : DMA_TO_DEVICE);
}
}
static int vring_mapping_error(const struct vring_virtqueue *vq,
dma_addr_t addr)
{
if (!vring_use_dma_api(vq->vq.vdev))
return 0;
return dma_mapping_error(vring_dma_dev(vq), addr);
}
static struct vring_desc *alloc_indirect(struct virtqueue *_vq,
unsigned int total_sg, gfp_t gfp)
{
struct vring_desc *desc;
unsigned int i;
gfp &= ~__GFP_HIGHMEM;
desc = kmalloc(total_sg * sizeof(struct vring_desc), gfp);
if (!desc)
return NULL;
for (i = 0; i < total_sg; i++)
desc[i].next = cpu_to_virtio16(_vq->vdev, i + 1);
return desc;
}
static inline int virtqueue_add(struct virtqueue *_vq,
struct scatterlist *sgs[],
unsigned int total_sg,
unsigned int out_sgs,
unsigned int in_sgs,
void *data,
gfp_t gfp)
{
struct vring_virtqueue *vq = to_vvq(_vq);
struct scatterlist *sg;
struct vring_desc *desc;
unsigned int i, n, avail, descs_used, uninitialized_var(prev), err_idx;
int head;
bool indirect;
START_USE(vq);
BUG_ON(data == NULL);
if (unlikely(vq->broken)) {
END_USE(vq);
return -EIO;
}
#ifdef DEBUG
{
ktime_t now = ktime_get();
if (vq->last_add_time_valid)
WARN_ON(ktime_to_ms(ktime_sub(now, vq->last_add_time))
> 100);
vq->last_add_time = now;
vq->last_add_time_valid = true;
}
#endif
BUG_ON(total_sg > vq->vring.num);
BUG_ON(total_sg == 0);
head = vq->free_head;
if (vq->indirect && total_sg > 1 && vq->vq.num_free)
desc = alloc_indirect(_vq, total_sg, gfp);
else
desc = NULL;
if (desc) {
indirect = true;
i = 0;
descs_used = 1;
} else {
indirect = false;
desc = vq->vring.desc;
i = head;
descs_used = total_sg;
}
if (vq->vq.num_free < descs_used) {
pr_debug("Can't add buf len %i - avail = %i\n",
descs_used, vq->vq.num_free);
if (out_sgs)
vq->notify(&vq->vq);
if (indirect)
kfree(desc);
END_USE(vq);
return -ENOSPC;
}
for (n = 0; n < out_sgs; n++) {
for (sg = sgs[n]; sg; sg = sg_next(sg)) {
dma_addr_t addr = vring_map_one_sg(vq, sg, DMA_TO_DEVICE);
if (vring_mapping_error(vq, addr))
goto unmap_release;
desc[i].flags = cpu_to_virtio16(_vq->vdev, VRING_DESC_F_NEXT);
desc[i].addr = cpu_to_virtio64(_vq->vdev, addr);
desc[i].len = cpu_to_virtio32(_vq->vdev, sg->length);
prev = i;
i = virtio16_to_cpu(_vq->vdev, desc[i].next);
}
}
for (; n < (out_sgs + in_sgs); n++) {
for (sg = sgs[n]; sg; sg = sg_next(sg)) {
dma_addr_t addr = vring_map_one_sg(vq, sg, DMA_FROM_DEVICE);
if (vring_mapping_error(vq, addr))
goto unmap_release;
desc[i].flags = cpu_to_virtio16(_vq->vdev, VRING_DESC_F_NEXT | VRING_DESC_F_WRITE);
desc[i].addr = cpu_to_virtio64(_vq->vdev, addr);
desc[i].len = cpu_to_virtio32(_vq->vdev, sg->length);
prev = i;
i = virtio16_to_cpu(_vq->vdev, desc[i].next);
}
}
desc[prev].flags &= cpu_to_virtio16(_vq->vdev, ~VRING_DESC_F_NEXT);
if (indirect) {
dma_addr_t addr = vring_map_single(
vq, desc, total_sg * sizeof(struct vring_desc),
DMA_TO_DEVICE);
if (vring_mapping_error(vq, addr))
goto unmap_release;
vq->vring.desc[head].flags = cpu_to_virtio16(_vq->vdev, VRING_DESC_F_INDIRECT);
vq->vring.desc[head].addr = cpu_to_virtio64(_vq->vdev, addr);
vq->vring.desc[head].len = cpu_to_virtio32(_vq->vdev, total_sg * sizeof(struct vring_desc));
}
vq->vq.num_free -= descs_used;
if (indirect)
vq->free_head = virtio16_to_cpu(_vq->vdev, vq->vring.desc[head].next);
else
vq->free_head = i;
vq->desc_state[head].data = data;
if (indirect)
vq->desc_state[head].indir_desc = desc;
avail = vq->avail_idx_shadow & (vq->vring.num - 1);
vq->vring.avail->ring[avail] = cpu_to_virtio16(_vq->vdev, head);
virtio_wmb(vq->weak_barriers);
vq->avail_idx_shadow++;
vq->vring.avail->idx = cpu_to_virtio16(_vq->vdev, vq->avail_idx_shadow);
vq->num_added++;
pr_debug("Added buffer head %i to %p\n", head, vq);
END_USE(vq);
if (unlikely(vq->num_added == (1 << 16) - 1))
virtqueue_kick(_vq);
return 0;
unmap_release:
err_idx = i;
i = head;
for (n = 0; n < total_sg; n++) {
if (i == err_idx)
break;
vring_unmap_one(vq, &desc[i]);
i = vq->vring.desc[i].next;
}
vq->vq.num_free += total_sg;
if (indirect)
kfree(desc);
END_USE(vq);
return -EIO;
}
int virtqueue_add_sgs(struct virtqueue *_vq,
struct scatterlist *sgs[],
unsigned int out_sgs,
unsigned int in_sgs,
void *data,
gfp_t gfp)
{
unsigned int i, total_sg = 0;
for (i = 0; i < out_sgs + in_sgs; i++) {
struct scatterlist *sg;
for (sg = sgs[i]; sg; sg = sg_next(sg))
total_sg++;
}
return virtqueue_add(_vq, sgs, total_sg, out_sgs, in_sgs, data, gfp);
}
int virtqueue_add_outbuf(struct virtqueue *vq,
struct scatterlist *sg, unsigned int num,
void *data,
gfp_t gfp)
{
return virtqueue_add(vq, &sg, num, 1, 0, data, gfp);
}
int virtqueue_add_inbuf(struct virtqueue *vq,
struct scatterlist *sg, unsigned int num,
void *data,
gfp_t gfp)
{
return virtqueue_add(vq, &sg, num, 0, 1, data, gfp);
}
bool virtqueue_kick_prepare(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 new, old;
bool needs_kick;
START_USE(vq);
virtio_mb(vq->weak_barriers);
old = vq->avail_idx_shadow - vq->num_added;
new = vq->avail_idx_shadow;
vq->num_added = 0;
#ifdef DEBUG
if (vq->last_add_time_valid) {
WARN_ON(ktime_to_ms(ktime_sub(ktime_get(),
vq->last_add_time)) > 100);
}
vq->last_add_time_valid = false;
#endif
if (vq->event) {
needs_kick = vring_need_event(virtio16_to_cpu(_vq->vdev, vring_avail_event(&vq->vring)),
new, old);
} else {
needs_kick = !(vq->vring.used->flags & cpu_to_virtio16(_vq->vdev, VRING_USED_F_NO_NOTIFY));
}
END_USE(vq);
return needs_kick;
}
bool virtqueue_notify(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
if (unlikely(vq->broken))
return false;
if (!vq->notify(_vq)) {
vq->broken = true;
return false;
}
return true;
}
bool virtqueue_kick(struct virtqueue *vq)
{
if (virtqueue_kick_prepare(vq))
return virtqueue_notify(vq);
return true;
}
static void detach_buf(struct vring_virtqueue *vq, unsigned int head)
{
unsigned int i, j;
u16 nextflag = cpu_to_virtio16(vq->vq.vdev, VRING_DESC_F_NEXT);
vq->desc_state[head].data = NULL;
i = head;
while (vq->vring.desc[i].flags & nextflag) {
vring_unmap_one(vq, &vq->vring.desc[i]);
i = virtio16_to_cpu(vq->vq.vdev, vq->vring.desc[i].next);
vq->vq.num_free++;
}
vring_unmap_one(vq, &vq->vring.desc[i]);
vq->vring.desc[i].next = cpu_to_virtio16(vq->vq.vdev, vq->free_head);
vq->free_head = head;
vq->vq.num_free++;
if (vq->desc_state[head].indir_desc) {
struct vring_desc *indir_desc = vq->desc_state[head].indir_desc;
u32 len = virtio32_to_cpu(vq->vq.vdev, vq->vring.desc[head].len);
BUG_ON(!(vq->vring.desc[head].flags &
cpu_to_virtio16(vq->vq.vdev, VRING_DESC_F_INDIRECT)));
BUG_ON(len == 0 || len % sizeof(struct vring_desc));
for (j = 0; j < len / sizeof(struct vring_desc); j++)
vring_unmap_one(vq, &indir_desc[j]);
kfree(vq->desc_state[head].indir_desc);
vq->desc_state[head].indir_desc = NULL;
}
}
static inline bool more_used(const struct vring_virtqueue *vq)
{
return vq->last_used_idx != virtio16_to_cpu(vq->vq.vdev, vq->vring.used->idx);
}
void *virtqueue_get_buf(struct virtqueue *_vq, unsigned int *len)
{
struct vring_virtqueue *vq = to_vvq(_vq);
void *ret;
unsigned int i;
u16 last_used;
START_USE(vq);
if (unlikely(vq->broken)) {
END_USE(vq);
return NULL;
}
if (!more_used(vq)) {
pr_debug("No more buffers in queue\n");
END_USE(vq);
return NULL;
}
virtio_rmb(vq->weak_barriers);
last_used = (vq->last_used_idx & (vq->vring.num - 1));
i = virtio32_to_cpu(_vq->vdev, vq->vring.used->ring[last_used].id);
*len = virtio32_to_cpu(_vq->vdev, vq->vring.used->ring[last_used].len);
if (unlikely(i >= vq->vring.num)) {
BAD_RING(vq, "id %u out of range\n", i);
return NULL;
}
if (unlikely(!vq->desc_state[i].data)) {
BAD_RING(vq, "id %u is not a head!\n", i);
return NULL;
}
ret = vq->desc_state[i].data;
detach_buf(vq, i);
vq->last_used_idx++;
if (!(vq->avail_flags_shadow & VRING_AVAIL_F_NO_INTERRUPT))
virtio_store_mb(vq->weak_barriers,
&vring_used_event(&vq->vring),
cpu_to_virtio16(_vq->vdev, vq->last_used_idx));
#ifdef DEBUG
vq->last_add_time_valid = false;
#endif
END_USE(vq);
return ret;
}
void virtqueue_disable_cb(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
if (!(vq->avail_flags_shadow & VRING_AVAIL_F_NO_INTERRUPT)) {
vq->avail_flags_shadow |= VRING_AVAIL_F_NO_INTERRUPT;
if (!vq->event)
vq->vring.avail->flags = cpu_to_virtio16(_vq->vdev, vq->avail_flags_shadow);
}
}
unsigned virtqueue_enable_cb_prepare(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 last_used_idx;
START_USE(vq);
if (vq->avail_flags_shadow & VRING_AVAIL_F_NO_INTERRUPT) {
vq->avail_flags_shadow &= ~VRING_AVAIL_F_NO_INTERRUPT;
if (!vq->event)
vq->vring.avail->flags = cpu_to_virtio16(_vq->vdev, vq->avail_flags_shadow);
}
vring_used_event(&vq->vring) = cpu_to_virtio16(_vq->vdev, last_used_idx = vq->last_used_idx);
END_USE(vq);
return last_used_idx;
}
bool virtqueue_poll(struct virtqueue *_vq, unsigned last_used_idx)
{
struct vring_virtqueue *vq = to_vvq(_vq);
virtio_mb(vq->weak_barriers);
return (u16)last_used_idx != virtio16_to_cpu(_vq->vdev, vq->vring.used->idx);
}
bool virtqueue_enable_cb(struct virtqueue *_vq)
{
unsigned last_used_idx = virtqueue_enable_cb_prepare(_vq);
return !virtqueue_poll(_vq, last_used_idx);
}
bool virtqueue_enable_cb_delayed(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 bufs;
START_USE(vq);
if (vq->avail_flags_shadow & VRING_AVAIL_F_NO_INTERRUPT) {
vq->avail_flags_shadow &= ~VRING_AVAIL_F_NO_INTERRUPT;
if (!vq->event)
vq->vring.avail->flags = cpu_to_virtio16(_vq->vdev, vq->avail_flags_shadow);
}
bufs = (u16)(vq->avail_idx_shadow - vq->last_used_idx) * 3 / 4;
virtio_store_mb(vq->weak_barriers,
&vring_used_event(&vq->vring),
cpu_to_virtio16(_vq->vdev, vq->last_used_idx + bufs));
if (unlikely((u16)(virtio16_to_cpu(_vq->vdev, vq->vring.used->idx) - vq->last_used_idx) > bufs)) {
END_USE(vq);
return false;
}
END_USE(vq);
return true;
}
void *virtqueue_detach_unused_buf(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
unsigned int i;
void *buf;
START_USE(vq);
for (i = 0; i < vq->vring.num; i++) {
if (!vq->desc_state[i].data)
continue;
buf = vq->desc_state[i].data;
detach_buf(vq, i);
vq->avail_idx_shadow--;
vq->vring.avail->idx = cpu_to_virtio16(_vq->vdev, vq->avail_idx_shadow);
END_USE(vq);
return buf;
}
BUG_ON(vq->vq.num_free != vq->vring.num);
END_USE(vq);
return NULL;
}
irqreturn_t vring_interrupt(int irq, void *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
if (!more_used(vq)) {
pr_debug("virtqueue interrupt with no work for %p\n", vq);
return IRQ_NONE;
}
if (unlikely(vq->broken))
return IRQ_HANDLED;
pr_debug("virtqueue callback for %p (%p)\n", vq, vq->vq.callback);
if (vq->vq.callback)
vq->vq.callback(&vq->vq);
return IRQ_HANDLED;
}
struct virtqueue *__vring_new_virtqueue(unsigned int index,
struct vring vring,
struct virtio_device *vdev,
bool weak_barriers,
bool (*notify)(struct virtqueue *),
void (*callback)(struct virtqueue *),
const char *name)
{
unsigned int i;
struct vring_virtqueue *vq;
vq = kmalloc(sizeof(*vq) + vring.num * sizeof(struct vring_desc_state),
GFP_KERNEL);
if (!vq)
return NULL;
vq->vring = vring;
vq->vq.callback = callback;
vq->vq.vdev = vdev;
vq->vq.name = name;
vq->vq.num_free = vring.num;
vq->vq.index = index;
vq->we_own_ring = false;
vq->queue_dma_addr = 0;
vq->queue_size_in_bytes = 0;
vq->notify = notify;
vq->weak_barriers = weak_barriers;
vq->broken = false;
vq->last_used_idx = 0;
vq->avail_flags_shadow = 0;
vq->avail_idx_shadow = 0;
vq->num_added = 0;
list_add_tail(&vq->vq.list, &vdev->vqs);
#ifdef DEBUG
vq->in_use = false;
vq->last_add_time_valid = false;
#endif
vq->indirect = virtio_has_feature(vdev, VIRTIO_RING_F_INDIRECT_DESC);
vq->event = virtio_has_feature(vdev, VIRTIO_RING_F_EVENT_IDX);
if (!callback) {
vq->avail_flags_shadow |= VRING_AVAIL_F_NO_INTERRUPT;
if (!vq->event)
vq->vring.avail->flags = cpu_to_virtio16(vdev, vq->avail_flags_shadow);
}
vq->free_head = 0;
for (i = 0; i < vring.num-1; i++)
vq->vring.desc[i].next = cpu_to_virtio16(vdev, i + 1);
memset(vq->desc_state, 0, vring.num * sizeof(struct vring_desc_state));
return &vq->vq;
}
static void *vring_alloc_queue(struct virtio_device *vdev, size_t size,
dma_addr_t *dma_handle, gfp_t flag)
{
if (vring_use_dma_api(vdev)) {
return dma_alloc_coherent(vdev->dev.parent, size,
dma_handle, flag);
} else {
void *queue = alloc_pages_exact(PAGE_ALIGN(size), flag);
if (queue) {
phys_addr_t phys_addr = virt_to_phys(queue);
*dma_handle = (dma_addr_t)phys_addr;
if (WARN_ON_ONCE(*dma_handle != phys_addr)) {
free_pages_exact(queue, PAGE_ALIGN(size));
return NULL;
}
}
return queue;
}
}
static void vring_free_queue(struct virtio_device *vdev, size_t size,
void *queue, dma_addr_t dma_handle)
{
if (vring_use_dma_api(vdev)) {
dma_free_coherent(vdev->dev.parent, size, queue, dma_handle);
} else {
free_pages_exact(queue, PAGE_ALIGN(size));
}
}
struct virtqueue *vring_create_virtqueue(
unsigned int index,
unsigned int num,
unsigned int vring_align,
struct virtio_device *vdev,
bool weak_barriers,
bool may_reduce_num,
bool (*notify)(struct virtqueue *),
void (*callback)(struct virtqueue *),
const char *name)
{
struct virtqueue *vq;
void *queue = NULL;
dma_addr_t dma_addr;
size_t queue_size_in_bytes;
struct vring vring;
if (num & (num - 1)) {
dev_warn(&vdev->dev, "Bad virtqueue length %u\n", num);
return NULL;
}
for (; num && vring_size(num, vring_align) > PAGE_SIZE; num /= 2) {
queue = vring_alloc_queue(vdev, vring_size(num, vring_align),
&dma_addr,
GFP_KERNEL|__GFP_NOWARN|__GFP_ZERO);
if (queue)
break;
}
if (!num)
return NULL;
if (!queue) {
queue = vring_alloc_queue(vdev, vring_size(num, vring_align),
&dma_addr, GFP_KERNEL|__GFP_ZERO);
}
if (!queue)
return NULL;
queue_size_in_bytes = vring_size(num, vring_align);
vring_init(&vring, num, queue, vring_align);
vq = __vring_new_virtqueue(index, vring, vdev, weak_barriers,
notify, callback, name);
if (!vq) {
vring_free_queue(vdev, queue_size_in_bytes, queue,
dma_addr);
return NULL;
}
to_vvq(vq)->queue_dma_addr = dma_addr;
to_vvq(vq)->queue_size_in_bytes = queue_size_in_bytes;
to_vvq(vq)->we_own_ring = true;
return vq;
}
struct virtqueue *vring_new_virtqueue(unsigned int index,
unsigned int num,
unsigned int vring_align,
struct virtio_device *vdev,
bool weak_barriers,
void *pages,
bool (*notify)(struct virtqueue *vq),
void (*callback)(struct virtqueue *vq),
const char *name)
{
struct vring vring;
vring_init(&vring, num, pages, vring_align);
return __vring_new_virtqueue(index, vring, vdev, weak_barriers,
notify, callback, name);
}
void vring_del_virtqueue(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
if (vq->we_own_ring) {
vring_free_queue(vq->vq.vdev, vq->queue_size_in_bytes,
vq->vring.desc, vq->queue_dma_addr);
}
list_del(&_vq->list);
kfree(vq);
}
void vring_transport_features(struct virtio_device *vdev)
{
unsigned int i;
for (i = VIRTIO_TRANSPORT_F_START; i < VIRTIO_TRANSPORT_F_END; i++) {
switch (i) {
case VIRTIO_RING_F_INDIRECT_DESC:
break;
case VIRTIO_RING_F_EVENT_IDX:
break;
case VIRTIO_F_VERSION_1:
break;
case VIRTIO_F_IOMMU_PLATFORM:
break;
default:
__virtio_clear_bit(vdev, i);
}
}
}
unsigned int virtqueue_get_vring_size(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
return vq->vring.num;
}
bool virtqueue_is_broken(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
return vq->broken;
}
void virtio_break_device(struct virtio_device *dev)
{
struct virtqueue *_vq;
list_for_each_entry(_vq, &dev->vqs, list) {
struct vring_virtqueue *vq = to_vvq(_vq);
vq->broken = true;
}
}
dma_addr_t virtqueue_get_desc_addr(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
BUG_ON(!vq->we_own_ring);
return vq->queue_dma_addr;
}
dma_addr_t virtqueue_get_avail_addr(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
BUG_ON(!vq->we_own_ring);
return vq->queue_dma_addr +
((char *)vq->vring.avail - (char *)vq->vring.desc);
}
dma_addr_t virtqueue_get_used_addr(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
BUG_ON(!vq->we_own_ring);
return vq->queue_dma_addr +
((char *)vq->vring.used - (char *)vq->vring.desc);
}
const struct vring *virtqueue_get_vring(struct virtqueue *vq)
{
return &to_vvq(vq)->vring;
}
