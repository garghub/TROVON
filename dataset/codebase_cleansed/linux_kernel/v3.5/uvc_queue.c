static int uvc_queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vq);
struct uvc_streaming *stream =
container_of(queue, struct uvc_streaming, queue);
if (*nbuffers > UVC_MAX_VIDEO_BUFFERS)
*nbuffers = UVC_MAX_VIDEO_BUFFERS;
*nplanes = 1;
sizes[0] = stream->ctrl.dwMaxVideoFrameSize;
return 0;
}
static int uvc_buffer_prepare(struct vb2_buffer *vb)
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vb->vb2_queue);
struct uvc_buffer *buf = container_of(vb, struct uvc_buffer, buf);
if (vb->v4l2_buf.type == V4L2_BUF_TYPE_VIDEO_OUTPUT &&
vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0)) {
uvc_trace(UVC_TRACE_CAPTURE, "[E] Bytes used out of bounds.\n");
return -EINVAL;
}
if (unlikely(queue->flags & UVC_QUEUE_DISCONNECTED))
return -ENODEV;
buf->state = UVC_BUF_STATE_QUEUED;
buf->error = 0;
buf->mem = vb2_plane_vaddr(vb, 0);
buf->length = vb2_plane_size(vb, 0);
if (vb->v4l2_buf.type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
buf->bytesused = 0;
else
buf->bytesused = vb2_get_plane_payload(vb, 0);
return 0;
}
static void uvc_buffer_queue(struct vb2_buffer *vb)
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vb->vb2_queue);
struct uvc_buffer *buf = container_of(vb, struct uvc_buffer, buf);
unsigned long flags;
spin_lock_irqsave(&queue->irqlock, flags);
if (likely(!(queue->flags & UVC_QUEUE_DISCONNECTED))) {
list_add_tail(&buf->queue, &queue->irqqueue);
} else {
buf->state = UVC_BUF_STATE_ERROR;
vb2_buffer_done(&buf->buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&queue->irqlock, flags);
}
static int uvc_buffer_finish(struct vb2_buffer *vb)
{
struct uvc_video_queue *queue = vb2_get_drv_priv(vb->vb2_queue);
struct uvc_streaming *stream =
container_of(queue, struct uvc_streaming, queue);
struct uvc_buffer *buf = container_of(vb, struct uvc_buffer, buf);
uvc_video_clock_update(stream, &vb->v4l2_buf, buf);
return 0;
}
void uvc_queue_init(struct uvc_video_queue *queue, enum v4l2_buf_type type,
int drop_corrupted)
{
queue->queue.type = type;
queue->queue.io_modes = VB2_MMAP | VB2_USERPTR;
queue->queue.drv_priv = queue;
queue->queue.buf_struct_size = sizeof(struct uvc_buffer);
queue->queue.ops = &uvc_queue_qops;
queue->queue.mem_ops = &vb2_vmalloc_memops;
vb2_queue_init(&queue->queue);
mutex_init(&queue->mutex);
spin_lock_init(&queue->irqlock);
INIT_LIST_HEAD(&queue->irqqueue);
queue->flags = drop_corrupted ? UVC_QUEUE_DROP_CORRUPTED : 0;
}
int uvc_alloc_buffers(struct uvc_video_queue *queue,
struct v4l2_requestbuffers *rb)
{
int ret;
mutex_lock(&queue->mutex);
ret = vb2_reqbufs(&queue->queue, rb);
mutex_unlock(&queue->mutex);
return ret ? ret : rb->count;
}
void uvc_free_buffers(struct uvc_video_queue *queue)
{
mutex_lock(&queue->mutex);
vb2_queue_release(&queue->queue);
mutex_unlock(&queue->mutex);
}
int uvc_query_buffer(struct uvc_video_queue *queue, struct v4l2_buffer *buf)
{
int ret;
mutex_lock(&queue->mutex);
ret = vb2_querybuf(&queue->queue, buf);
mutex_unlock(&queue->mutex);
return ret;
}
int uvc_queue_buffer(struct uvc_video_queue *queue, struct v4l2_buffer *buf)
{
int ret;
mutex_lock(&queue->mutex);
ret = vb2_qbuf(&queue->queue, buf);
mutex_unlock(&queue->mutex);
return ret;
}
int uvc_dequeue_buffer(struct uvc_video_queue *queue, struct v4l2_buffer *buf,
int nonblocking)
{
int ret;
mutex_lock(&queue->mutex);
ret = vb2_dqbuf(&queue->queue, buf, nonblocking);
mutex_unlock(&queue->mutex);
return ret;
}
int uvc_queue_mmap(struct uvc_video_queue *queue, struct vm_area_struct *vma)
{
int ret;
mutex_lock(&queue->mutex);
ret = vb2_mmap(&queue->queue, vma);
mutex_unlock(&queue->mutex);
return ret;
}
unsigned long uvc_queue_get_unmapped_area(struct uvc_video_queue *queue,
unsigned long pgoff)
{
unsigned long ret;
mutex_lock(&queue->mutex);
ret = vb2_get_unmapped_area(&queue->queue, 0, 0, pgoff, 0);
mutex_unlock(&queue->mutex);
return ret;
}
unsigned int uvc_queue_poll(struct uvc_video_queue *queue, struct file *file,
poll_table *wait)
{
unsigned int ret;
mutex_lock(&queue->mutex);
ret = vb2_poll(&queue->queue, file, wait);
mutex_unlock(&queue->mutex);
return ret;
}
int uvc_queue_allocated(struct uvc_video_queue *queue)
{
int allocated;
mutex_lock(&queue->mutex);
allocated = vb2_is_busy(&queue->queue);
mutex_unlock(&queue->mutex);
return allocated;
}
int uvc_queue_enable(struct uvc_video_queue *queue, int enable)
{
unsigned long flags;
int ret;
mutex_lock(&queue->mutex);
if (enable) {
ret = vb2_streamon(&queue->queue, queue->queue.type);
if (ret < 0)
goto done;
queue->buf_used = 0;
} else {
ret = vb2_streamoff(&queue->queue, queue->queue.type);
if (ret < 0)
goto done;
spin_lock_irqsave(&queue->irqlock, flags);
INIT_LIST_HEAD(&queue->irqqueue);
spin_unlock_irqrestore(&queue->irqlock, flags);
}
done:
mutex_unlock(&queue->mutex);
return ret;
}
void uvc_queue_cancel(struct uvc_video_queue *queue, int disconnect)
{
struct uvc_buffer *buf;
unsigned long flags;
spin_lock_irqsave(&queue->irqlock, flags);
while (!list_empty(&queue->irqqueue)) {
buf = list_first_entry(&queue->irqqueue, struct uvc_buffer,
queue);
list_del(&buf->queue);
buf->state = UVC_BUF_STATE_ERROR;
vb2_buffer_done(&buf->buf, VB2_BUF_STATE_ERROR);
}
if (disconnect)
queue->flags |= UVC_QUEUE_DISCONNECTED;
spin_unlock_irqrestore(&queue->irqlock, flags);
}
struct uvc_buffer *uvc_queue_next_buffer(struct uvc_video_queue *queue,
struct uvc_buffer *buf)
{
struct uvc_buffer *nextbuf;
unsigned long flags;
if ((queue->flags & UVC_QUEUE_DROP_CORRUPTED) && buf->error) {
buf->error = 0;
buf->state = UVC_BUF_STATE_QUEUED;
vb2_set_plane_payload(&buf->buf, 0, 0);
return buf;
}
spin_lock_irqsave(&queue->irqlock, flags);
list_del(&buf->queue);
if (!list_empty(&queue->irqqueue))
nextbuf = list_first_entry(&queue->irqqueue, struct uvc_buffer,
queue);
else
nextbuf = NULL;
spin_unlock_irqrestore(&queue->irqlock, flags);
buf->state = buf->error ? VB2_BUF_STATE_ERROR : UVC_BUF_STATE_DONE;
vb2_set_plane_payload(&buf->buf, 0, buf->bytesused);
vb2_buffer_done(&buf->buf, VB2_BUF_STATE_DONE);
return nextbuf;
}
