static int vring_add_indirect(struct vring_virtqueue *vq,
struct scatterlist sg[],
unsigned int out,
unsigned int in,
gfp_t gfp)
{
struct vring_desc *desc;
unsigned head;
int i;
desc = kmalloc((out + in) * sizeof(struct vring_desc), gfp);
if (!desc)
return -ENOMEM;
for (i = 0; i < out; i++) {
desc[i].flags = VRING_DESC_F_NEXT;
desc[i].addr = sg_phys(sg);
desc[i].len = sg->length;
desc[i].next = i+1;
sg++;
}
for (; i < (out + in); i++) {
desc[i].flags = VRING_DESC_F_NEXT|VRING_DESC_F_WRITE;
desc[i].addr = sg_phys(sg);
desc[i].len = sg->length;
desc[i].next = i+1;
sg++;
}
desc[i-1].flags &= ~VRING_DESC_F_NEXT;
desc[i-1].next = 0;
vq->num_free--;
head = vq->free_head;
vq->vring.desc[head].flags = VRING_DESC_F_INDIRECT;
vq->vring.desc[head].addr = virt_to_phys(desc);
vq->vring.desc[head].len = i * sizeof(struct vring_desc);
vq->free_head = vq->vring.desc[head].next;
return head;
}
int virtqueue_add_buf_gfp(struct virtqueue *_vq,
struct scatterlist sg[],
unsigned int out,
unsigned int in,
void *data,
gfp_t gfp)
{
struct vring_virtqueue *vq = to_vvq(_vq);
unsigned int i, avail, uninitialized_var(prev);
int head;
START_USE(vq);
BUG_ON(data == NULL);
if (vq->indirect && (out + in) > 1 && vq->num_free) {
head = vring_add_indirect(vq, sg, out, in, gfp);
if (likely(head >= 0))
goto add_head;
}
BUG_ON(out + in > vq->vring.num);
BUG_ON(out + in == 0);
if (vq->num_free < out + in) {
pr_debug("Can't add buf len %i - avail = %i\n",
out + in, vq->num_free);
if (out)
vq->notify(&vq->vq);
END_USE(vq);
return -ENOSPC;
}
vq->num_free -= out + in;
head = vq->free_head;
for (i = vq->free_head; out; i = vq->vring.desc[i].next, out--) {
vq->vring.desc[i].flags = VRING_DESC_F_NEXT;
vq->vring.desc[i].addr = sg_phys(sg);
vq->vring.desc[i].len = sg->length;
prev = i;
sg++;
}
for (; in; i = vq->vring.desc[i].next, in--) {
vq->vring.desc[i].flags = VRING_DESC_F_NEXT|VRING_DESC_F_WRITE;
vq->vring.desc[i].addr = sg_phys(sg);
vq->vring.desc[i].len = sg->length;
prev = i;
sg++;
}
vq->vring.desc[prev].flags &= ~VRING_DESC_F_NEXT;
vq->free_head = i;
add_head:
vq->data[head] = data;
avail = (vq->vring.avail->idx + vq->num_added++) % vq->vring.num;
vq->vring.avail->ring[avail] = head;
pr_debug("Added buffer head %i to %p\n", head, vq);
END_USE(vq);
return vq->num_free;
}
void virtqueue_kick(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 new, old;
START_USE(vq);
virtio_wmb();
old = vq->vring.avail->idx;
new = vq->vring.avail->idx = old + vq->num_added;
vq->num_added = 0;
virtio_mb();
if (vq->event ?
vring_need_event(vring_avail_event(&vq->vring), new, old) :
!(vq->vring.used->flags & VRING_USED_F_NO_NOTIFY))
vq->notify(&vq->vq);
END_USE(vq);
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
vq->num_free++;
}
vq->vring.desc[i].next = vq->free_head;
vq->free_head = head;
vq->num_free++;
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
virtio_rmb();
i = vq->vring.used->ring[vq->last_used_idx%vq->vring.num].id;
*len = vq->vring.used->ring[vq->last_used_idx%vq->vring.num].len;
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
virtio_mb();
}
END_USE(vq);
return ret;
}
void virtqueue_disable_cb(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
vq->vring.avail->flags |= VRING_AVAIL_F_NO_INTERRUPT;
}
bool virtqueue_enable_cb(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
START_USE(vq);
vq->vring.avail->flags &= ~VRING_AVAIL_F_NO_INTERRUPT;
vring_used_event(&vq->vring) = vq->last_used_idx;
virtio_mb();
if (unlikely(more_used(vq))) {
END_USE(vq);
return false;
}
END_USE(vq);
return true;
}
bool virtqueue_enable_cb_delayed(struct virtqueue *_vq)
{
struct vring_virtqueue *vq = to_vvq(_vq);
u16 bufs;
START_USE(vq);
vq->vring.avail->flags &= ~VRING_AVAIL_F_NO_INTERRUPT;
bufs = (u16)(vq->vring.avail->idx - vq->last_used_idx) * 3 / 4;
vring_used_event(&vq->vring) = vq->last_used_idx + bufs;
virtio_mb();
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
BUG_ON(vq->num_free != vq->vring.num);
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
struct virtqueue *vring_new_virtqueue(unsigned int num,
unsigned int vring_align,
struct virtio_device *vdev,
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
vq->notify = notify;
vq->broken = false;
vq->last_used_idx = 0;
vq->num_added = 0;
list_add_tail(&vq->vq.list, &vdev->vqs);
#ifdef DEBUG
vq->in_use = false;
#endif
vq->indirect = virtio_has_feature(vdev, VIRTIO_RING_F_INDIRECT_DESC);
vq->event = virtio_has_feature(vdev, VIRTIO_RING_F_EVENT_IDX);
if (!callback)
vq->vring.avail->flags |= VRING_AVAIL_F_NO_INTERRUPT;
vq->num_free = num;
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
