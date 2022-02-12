static const char *virtio_get_driver_name(struct dma_fence *f)
{
return "virtio_gpu";
}
static const char *virtio_get_timeline_name(struct dma_fence *f)
{
return "controlq";
}
static bool virtio_enable_signaling(struct dma_fence *f)
{
return true;
}
static bool virtio_signaled(struct dma_fence *f)
{
struct virtio_gpu_fence *fence = to_virtio_fence(f);
if (atomic64_read(&fence->drv->last_seq) >= fence->seq)
return true;
return false;
}
static void virtio_fence_value_str(struct dma_fence *f, char *str, int size)
{
struct virtio_gpu_fence *fence = to_virtio_fence(f);
snprintf(str, size, "%llu", fence->seq);
}
static void virtio_timeline_value_str(struct dma_fence *f, char *str, int size)
{
struct virtio_gpu_fence *fence = to_virtio_fence(f);
snprintf(str, size, "%llu", (u64)atomic64_read(&fence->drv->last_seq));
}
int virtio_gpu_fence_emit(struct virtio_gpu_device *vgdev,
struct virtio_gpu_ctrl_hdr *cmd_hdr,
struct virtio_gpu_fence **fence)
{
struct virtio_gpu_fence_driver *drv = &vgdev->fence_drv;
unsigned long irq_flags;
*fence = kmalloc(sizeof(struct virtio_gpu_fence), GFP_ATOMIC);
if ((*fence) == NULL)
return -ENOMEM;
spin_lock_irqsave(&drv->lock, irq_flags);
(*fence)->drv = drv;
(*fence)->seq = ++drv->sync_seq;
dma_fence_init(&(*fence)->f, &virtio_fence_ops, &drv->lock,
drv->context, (*fence)->seq);
dma_fence_get(&(*fence)->f);
list_add_tail(&(*fence)->node, &drv->fences);
spin_unlock_irqrestore(&drv->lock, irq_flags);
cmd_hdr->flags |= cpu_to_le32(VIRTIO_GPU_FLAG_FENCE);
cmd_hdr->fence_id = cpu_to_le64((*fence)->seq);
return 0;
}
void virtio_gpu_fence_event_process(struct virtio_gpu_device *vgdev,
u64 last_seq)
{
struct virtio_gpu_fence_driver *drv = &vgdev->fence_drv;
struct virtio_gpu_fence *fence, *tmp;
unsigned long irq_flags;
spin_lock_irqsave(&drv->lock, irq_flags);
atomic64_set(&vgdev->fence_drv.last_seq, last_seq);
list_for_each_entry_safe(fence, tmp, &drv->fences, node) {
if (last_seq < fence->seq)
continue;
dma_fence_signal_locked(&fence->f);
list_del(&fence->node);
dma_fence_put(&fence->f);
}
spin_unlock_irqrestore(&drv->lock, irq_flags);
}
