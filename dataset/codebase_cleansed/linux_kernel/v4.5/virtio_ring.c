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
unsigned int i, n, avail, descs_used, uninitialized_var(prev);
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
vq->vring.desc[head].flags = cpu_to_virtio16(_vq->vdev, VRING_DESC_F_INDIRECT);
vq->vring.desc[head].addr = cpu_to_virtio64(_vq->vdev, virt_to_phys(desc));
kmemleak_ignore(desc);
vq->vring.desc[head].len = cpu_to_virtio32(_vq->vdev, total_sg * sizeof(struct vring_desc));
i = 0;
descs_used = 1;
indirect = true;
} else {
desc = vq->vring.desc;
i = head;
descs_used = total_sg;
indirect = false;
}
if (vq->vq.num_free < descs_used) {
pr_debug("Can't add buf len %i - avail = %i\n",
descs_used, vq->vq.num_free);
if (out_sgs)
vq->notify(&vq->vq);
END_USE(vq);
return -ENOSPC;
}
vq->vq.num_free -= descs_used;
for (n = 0; n < out_sgs; n++) {
for (sg = sgs[n]; sg; sg = sg_next(sg)) {
desc[i].flags = cpu_to_virtio16(_vq->vdev, VRING_DESC_F_NEXT);
desc[i].addr = cpu_to_virtio64(_vq->vdev, sg_phys(sg));
desc[i].len = cpu_to_virtio32(_vq->vdev, sg->length);
prev = i;
i = virtio16_to_cpu(_vq->vdev, desc[i].next);
}
}
for (; n < (out_sgs + in_sgs); n++) {
for (sg = sgs[n]; sg; sg = sg_next(sg)) {
desc[i].flags = cpu_to_virtio16(_vq->vdev, VRING_DESC_F_NEXT | VRING_DESC_F_WRITE);
desc[i].addr = cpu_to_virtio64(_vq->vdev, sg_phys(sg));
desc[i].len = cpu_to_virtio32(_vq->vdev, sg->length);
prev = i;
i = virtio16_to_cpu(_vq->vdev, desc[i].next);
}
}
desc[prev].flags &= cpu_to_virtio16(_vq->vdev, ~VRING_DESC_F_NEXT);
if (indirect)
vq->free_head = virtio16_to_cpu(_vq->vdev, vq->vring.desc[head].next);
else
vq->free_head = i;
vq->data[head] = data;
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
unsigned int i;
vq->data[head] = NULL;
i = head;
if (vq->vring.desc[i].flags & cpu_to_virtio16(vq->vq.vdev, VRING_DESC_F_INDIRECT))
kfree(phys_to_virt(virtio64_to_cpu(vq->vq.vdev, vq->vring.desc[i].addr)));
while (vq->vring.desc[i].flags & cpu_to_virtio16(vq->vq.vdev, VRING_DESC_F_NEXT)) {
i = virtio16_to_cpu(vq->vq.vdev, vq->vring.desc[i].next);
vq->vq.num_free++;
}
vq->vring.desc[i].next = cpu_to_virtio16(vq->vq.vdev, vq->free_head);
vq->free_head = head;
vq->vq.num_free++;
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
if (unlikely(!vq->data[i])) {
BAD_RING(vq, "id %u is not a head!\n", i);
return NULL;
}
ret = vq->data[i];
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
if (!vq->data[i])
continue;
buf = vq->data[i];
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
struct virtqueue *vring_new_virtqueue(unsigned int index,
unsigned int num,
unsigned int vring_align,
struct virtio_device *vdev,
bool weak_barriers,
void *pages,
bool (*notify)(struct virtqueue *),
void (*callback)(struct virtqueue *),
const char *name)
{
struct vring_virtqueue *vq;
unsigned int i;
if (num & (num - 1)) {
dev_warn(&vdev->dev, "Bad virtqueue length %u\n", num);
return NULL;
}
vq = kmalloc(sizeof(*vq) + sizeof(void *)*num, GFP_KERNEL);
if (!vq)
return NULL;
vring_init(&vq->vring, num, pages, vring_align);
vq->vq.callback = callback;
vq->vq.vdev = vdev;
vq->vq.name = name;
vq->vq.num_free = num;
vq->vq.index = index;
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
vq->vring.avail->flags = cpu_to_virtio16(vdev, vq->avail_flags_shadow);
}
vq->free_head = 0;
for (i = 0; i < num-1; i++) {
vq->vring.desc[i].next = cpu_to_virtio16(vdev, i + 1);
vq->data[i] = NULL;
}
vq->data[i] = NULL;
return &vq->vq;
}
void vring_del_virtqueue(struct virtqueue *vq)
{
list_del(&vq->list);
kfree(to_vvq(vq));
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
void *virtqueue_get_avail(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
return vq->vring.avail;
}
void *virtqueue_get_used(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
return vq->vring.used;
}
