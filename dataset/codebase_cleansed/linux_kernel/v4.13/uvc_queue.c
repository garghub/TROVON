static int uvc_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vq);
struct uvc_video *video = container_of(queue, struct uvc_video, queue);
if (*nbuffers > UVC_MAX_VIDEO_BUFFERS)
*nbuffers = UVC_MAX_VIDEO_BUFFERS;
*nplanes = 1;
sizes[0] = video->imagesize;
return 0;
}
static int uvc_buffer_prepare(struct vb2_buffer *vb)
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct uvc_buffer *buf = container_of(vbuf, struct uvc_buffer, buf);
if (vb->type == V4L2_BUF_TYPE_VIDEO_OUTPUT &&
vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0)) {
uvc_trace(UVC_TRACE_CAPTURE, "[E] Bytes used out of bounds.\n");
return -EINVAL;
}
if (unlikely(queue->flags & UVC_QUEUE_DISCONNECTED))
return -ENODEV;
buf->state = UVC_BUF_STATE_QUEUED;
buf->mem = vb2_plane_vaddr(vb, 0);
buf->length = vb2_plane_size(vb, 0);
if (vb->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
buf->bytesused = 0;
else
buf->bytesused = vb2_get_plane_payload(vb, 0);
return 0;
}
static void uvc_buffer_queue(struct vb2_buffer *vb)
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct uvc_buffer *buf = container_of(vbuf, struct uvc_buffer, buf);
unsigned long flags;
spin_lock_irqsave(&queue->irqlock, flags);
if (likely(!(queue->flags & UVC_QUEUE_DISCONNECTED))) {
list_add_tail(&buf->queue, &queue->irqqueue);
} else {
buf->state = UVC_BUF_STATE_ERROR;
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&queue->irqlock, flags);
}
int uvcg_queue_init(struct uvc_video_queue *queue, enum v4l2_buf_type type,
struct mutex *lock)
{
int ret;
queue->queue.type = type;
queue->queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
queue->queue.drv_priv = queue;
queue->queue.buf_struct_size = sizeof(struct uvc_buffer);
queue->queue.ops = &uvc_queue_qops;
queue->queue.lock = lock;
queue->queue.mem_ops = &vb2_vmalloc_memops;
queue->queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC
| V4L2_BUF_FLAG_TSTAMP_SRC_EOF;
ret = vb2_queue_init(&queue->queue);
if (ret)
return ret;
spin_lock_init(&queue->irqlock);
INIT_LIST_HEAD(&queue->irqqueue);
queue->flags = 0;
return 0;
}
void uvcg_free_buffers(struct uvc_video_queue *queue)
{
vb2_queue_release(&queue->queue);
}
int uvcg_alloc_buffers(struct uvc_video_queue *queue,
struct v4l2_requestbuffers *rb)
{
int ret;
ret = vb2_reqbufs(&queue->queue, rb);
return ret ? ret : rb->count;
}
int uvcg_query_buffer(struct uvc_video_queue *queue, struct v4l2_buffer *buf)
{
return vb2_querybuf(&queue->queue, buf);
}
int uvcg_queue_buffer(struct uvc_video_queue *queue, struct v4l2_buffer *buf)
{
unsigned long flags;
int ret;
ret = vb2_qbuf(&queue->queue, buf);
if (ret < 0)
return ret;
spin_lock_irqsave(&queue->irqlock, flags);
ret = (queue->flags & UVC_QUEUE_PAUSED) != 0;
queue->flags &= ~UVC_QUEUE_PAUSED;
spin_unlock_irqrestore(&queue->irqlock, flags);
return ret;
}
int uvcg_dequeue_buffer(struct uvc_video_queue *queue, struct v4l2_buffer *buf,
int nonblocking)
{
return vb2_dqbuf(&queue->queue, buf, nonblocking);
}
unsigned int uvcg_queue_poll(struct uvc_video_queue *queue, struct file *file,
poll_table *wait)
{
return vb2_poll(&queue->queue, file, wait);
}
int uvcg_queue_mmap(struct uvc_video_queue *queue, struct vm_area_struct *vma)
{
return vb2_mmap(&queue->queue, vma);
}
unsigned long uvcg_queue_get_unmapped_area(struct uvc_video_queue *queue,
unsigned long pgoff)
{
return vb2_get_unmapped_area(&queue->queue, 0, 0, pgoff, 0);
}
void uvcg_queue_cancel(struct uvc_video_queue *queue, int disconnect)
{
struct uvc_buffer *buf;
unsigned long flags;
spin_lock_irqsave(&queue->irqlock, flags);
while (!list_empty(&queue->irqqueue)) {
buf = list_first_entry(&queue->irqqueue, struct uvc_buffer,
queue);
list_del(&buf->queue);
buf->state = UVC_BUF_STATE_ERROR;
vb2_buffer_done(&buf->buf.vb2_buf, VB2_BUF_STATE_ERROR);
}
if (disconnect)
queue->flags |= UVC_QUEUE_DISCONNECTED;
spin_unlock_irqrestore(&queue->irqlock, flags);
}
int uvcg_queue_enable(struct uvc_video_queue *queue, int enable)
{
unsigned long flags;
int ret = 0;
if (enable) {
ret = vb2_streamon(&queue->queue, queue->queue.type);
if (ret < 0)
return ret;
queue->sequence = 0;
queue->buf_used = 0;
} else {
ret = vb2_streamoff(&queue->queue, queue->queue.type);
if (ret < 0)
return ret;
spin_lock_irqsave(&queue->irqlock, flags);
INIT_LIST_HEAD(&queue->irqqueue);
queue->flags &= ~UVC_QUEUE_DISCONNECTED;
spin_unlock_irqrestore(&queue->irqlock, flags);
}
return ret;
}
struct uvc_buffer *uvcg_queue_next_buffer(struct uvc_video_queue *queue,
struct uvc_buffer *buf)
{
struct uvc_buffer *nextbuf;
if ((queue->flags & UVC_QUEUE_DROP_INCOMPLETE) &&
buf->length != buf->bytesused) {
buf->state = UVC_BUF_STATE_QUEUED;
vb2_set_plane_payload(&buf->buf.vb2_buf, 0, 0);
return buf;
}
list_del(&buf->queue);
if (!list_empty(&queue->irqqueue))
nextbuf = list_first_entry(&queue->irqqueue, struct uvc_buffer,
queue);
else
nextbuf = NULL;
buf->buf.field = V4L2_FIELD_NONE;
buf->buf.sequence = queue->sequence++;
buf->buf.vb2_buf.timestamp = ktime_get_ns();
vb2_set_plane_payload(&buf->buf.vb2_buf, 0, buf->bytesused);
vb2_buffer_done(&buf->buf.vb2_buf, VB2_BUF_STATE_DONE);
return nextbuf;
}
struct uvc_buffer *uvcg_queue_head(struct uvc_video_queue *queue)
{
struct uvc_buffer *buf = NULL;
if (!list_empty(&queue->irqqueue))
buf = list_first_entry(&queue->irqqueue, struct uvc_buffer,
queue);
else
queue->flags |= UVC_QUEUE_PAUSED;
return buf;
}
