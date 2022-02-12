static inline struct scatterlist *sg_next_chained(struct scatterlist *sg,
unsigned int *count)
{
return sg_next(sg);
}
static inline struct scatterlist *sg_next_arr(struct scatterlist *sg,
unsigned int *count)
{
if (--(*count) == 0)
return NULL;
return sg + 1;
}
int virtqueue_add_sgs(struct virtqueue *_vq,
struct scatterlist *sgs[],
unsigned int out_sgs,
unsigned int in_sgs,
void *data,
gfp_t gfp)
{
unsigned int i, total_out, total_in;
for (i = total_out = total_in = 0; i < out_sgs; i++) {
struct scatterlist *sg;
for (sg = sgs[i]; sg; sg = sg_next(sg))
total_out++;
}
for (; i < out_sgs + in_sgs; i++) {
struct scatterlist *sg;
for (sg = sgs[i]; sg; sg = sg_next(sg))
total_in++;
}
return virtqueue_add(_vq, sgs, sg_next_chained,
total_out, total_in, out_sgs, in_sgs, data, gfp);
}
int virtqueue_add_outbuf(struct virtqueue *vq,
struct scatterlist sg[], unsigned int num,
void *data,
gfp_t gfp)
{
return virtqueue_add(vq, &sg, sg_next_arr, num, 0, 1, 0, data, gfp);
}
int virtqueue_add_inbuf(struct virtqueue *vq,
struct scatterlist sg[], unsigned int num,
void *data,
gfp_t gfp)
{
return virtqueue_add(vq, &sg, sg_next_arr, 0, num, 0, 1, data, gfp);
}
bool virtqueue_kick_prepare(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 new, old;
bool needs_kick;
START_USE(vq);
virtio_mb(vq->weak_barriers);
old = vq->vring.avail->idx - vq->num_added;
new = vq->vring.avail->idx;
vq->num_added = 0;
#ifdef DEBUG
if (vq->last_add_time_valid) {
WARN_ON(ktime_to_ms(ktime_sub(ktime_get(),
vq->last_add_time)) > 100);
}
vq->last_add_time_valid = false;
#endif
if (vq->event) {
needs_kick = vring_need_event(vring_avail_event(&vq->vring),
new, old);
} else {
needs_kick = !(vq->vring.used->flags & VRING_USED_F_NO_NOTIFY);
}
END_USE(vq);
return needs_kick;
}
void virtqueue_notify(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
vq->notify(_vq);
}
void virtqueue_kick(struct virtqueue *vq)
{
if (virtqueue_kick_prepare(vq))
virtqueue_notify(vq);
}
static void detach_buf(struct vring_virtqueue *vq, unsigned int head)
{
unsigned int i;
vq->data[head] = NULL;
i = head;
if (vq->vring.desc[i].flags & VRING_DESC_F_INDIRECT)
kfree(phys_to_virt(vq->vring.desc[i].addr));
while (vq->vring.desc[i].flags & VRING_DESC_F_NEXT) {
i = vq->vring.desc[i].next;
vq->vq.num_free++;
}
vq->vring.desc[i].next = vq->free_head;
vq->free_head = head;
vq->vq.num_free++;
}
static inline bool more_used(const struct vring_virtqueue *vq)
{
return vq->last_used_idx != vq->vring.used->idx;
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
i = vq->vring.used->ring[last_used].id;
*len = vq->vring.used->ring[last_used].len;
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
if (!(vq->vring.avail->flags & VRING_AVAIL_F_NO_INTERRUPT)) {
vring_used_event(&vq->vring) = vq->last_used_idx;
virtio_mb(vq->weak_barriers);
}
#ifdef DEBUG
vq->last_add_time_valid = false;
#endif
END_USE(vq);
return ret;
}
void virtqueue_disable_cb(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
vq->vring.avail->flags |= VRING_AVAIL_F_NO_INTERRUPT;
}
unsigned virtqueue_enable_cb_prepare(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 last_used_idx;
START_USE(vq);
vq->vring.avail->flags &= ~VRING_AVAIL_F_NO_INTERRUPT;
vring_used_event(&vq->vring) = last_used_idx = vq->last_used_idx;
END_USE(vq);
return last_used_idx;
}
bool virtqueue_poll(struct virtqueue *_vq, unsigned last_used_idx)
{
struct vring_virtqueue *vq = to_vvq(_vq);
virtio_mb(vq->weak_barriers);
return (u16)last_used_idx != vq->vring.used->idx;
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
vq->vring.avail->flags &= ~VRING_AVAIL_F_NO_INTERRUPT;
bufs = (u16)(vq->vring.avail->idx - vq->last_used_idx) * 3 / 4;
vring_used_event(&vq->vring) = vq->last_used_idx + bufs;
virtio_mb(vq->weak_barriers);
if (unlikely((u16)(vq->vring.used->idx - vq->last_used_idx) > bufs)) {
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
vq->vring.avail->idx--;
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
void (*notify)(struct virtqueue *),
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
vq->num_added = 0;
list_add_tail(&vq->vq.list, &vdev->vqs);
#ifdef DEBUG
vq->in_use = false;
vq->last_add_time_valid = false;
#endif
vq->indirect = virtio_has_feature(vdev, VIRTIO_RING_F_INDIRECT_DESC);
vq->event = virtio_has_feature(vdev, VIRTIO_RING_F_EVENT_IDX);
if (!callback)
vq->vring.avail->flags |= VRING_AVAIL_F_NO_INTERRUPT;
vq->free_head = 0;
for (i = 0; i < num-1; i++) {
vq->vring.desc[i].next = i+1;
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
default:
clear_bit(i, vdev->features);
}
}
}
unsigned int virtqueue_get_vring_size(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
return vq->vring.num;
}
