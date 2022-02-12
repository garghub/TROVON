static void
free_buffer(struct videobuf_queue *vq, struct au0828_buffer *buf)
{
struct au0828_fh *fh = vq->priv_data;
struct au0828_dev *dev = fh->dev;
unsigned long flags = 0;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->slock, flags);
if (dev->isoc_ctl.vbi_buf == buf)
dev->isoc_ctl.vbi_buf = NULL;
spin_unlock_irqrestore(&dev->slock, flags);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int
vbi_setup(struct videobuf_queue *q, unsigned int *count, unsigned int *size)
{
struct au0828_fh *fh = q->priv_data;
struct au0828_dev *dev = fh->dev;
*size = dev->vbi_width * dev->vbi_height * 2;
if (0 == *count)
*count = vbibufs;
if (*count < 2)
*count = 2;
if (*count > 32)
*count = 32;
return 0;
}
static int
vbi_prepare(struct videobuf_queue *q, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct au0828_fh *fh = q->priv_data;
struct au0828_dev *dev = fh->dev;
struct au0828_buffer *buf = container_of(vb, struct au0828_buffer, vb);
int rc = 0;
buf->vb.size = dev->vbi_width * dev->vbi_height * 2;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
buf->vb.width = dev->vbi_width;
buf->vb.height = dev->vbi_height;
buf->vb.field = field;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
rc = videobuf_iolock(q, &buf->vb, NULL);
if (rc < 0)
goto fail;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(q, buf);
return rc;
}
static void
vbi_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct au0828_buffer *buf = container_of(vb,
struct au0828_buffer,
vb);
struct au0828_fh *fh = vq->priv_data;
struct au0828_dev *dev = fh->dev;
struct au0828_dmaqueue *vbiq = &dev->vbiq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vbiq->active);
}
static void vbi_release(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct au0828_buffer *buf = container_of(vb, struct au0828_buffer, vb);
free_buffer(q, buf);
}
