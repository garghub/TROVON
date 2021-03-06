int cx23885_vbi_fmt(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
if (dev->tvnorm & V4L2_STD_525_60) {
f->fmt.vbi.samples_per_line = VBI_LINE_LENGTH;
f->fmt.vbi.sampling_rate = 27000000;
f->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
f->fmt.vbi.offset = 0;
f->fmt.vbi.flags = 0;
f->fmt.vbi.start[0] = 10;
f->fmt.vbi.count[0] = 17;
f->fmt.vbi.start[1] = 263 + 10 + 1;
f->fmt.vbi.count[1] = 17;
} else if (dev->tvnorm & V4L2_STD_625_50) {
f->fmt.vbi.sampling_rate = 35468950;
f->fmt.vbi.start[0] = 7 - 1;
f->fmt.vbi.start[1] = 319 - 1;
}
return 0;
}
int cx23885_vbi_irq(struct cx23885_dev *dev, u32 status)
{
u32 count;
int handled = 0;
if (status & VID_BC_MSK_VBI_RISCI1) {
dprintk(1, "%s() VID_BC_MSK_VBI_RISCI1\n", __func__);
spin_lock(&dev->slock);
count = cx_read(VID_A_GPCNT);
cx23885_video_wakeup(dev, &dev->vbiq, count);
spin_unlock(&dev->slock);
handled++;
}
if (status & VID_BC_MSK_VBI_RISCI2) {
dprintk(1, "%s() VID_BC_MSK_VBI_RISCI2\n", __func__);
dprintk(2, "stopper vbi\n");
spin_lock(&dev->slock);
cx23885_restart_vbi_queue(dev, &dev->vbiq);
spin_unlock(&dev->slock);
handled++;
}
return handled;
}
static int cx23885_start_vbi_dma(struct cx23885_dev *dev,
struct cx23885_dmaqueue *q,
struct cx23885_buffer *buf)
{
dprintk(1, "%s()\n", __func__);
cx23885_sram_channel_setup(dev, &dev->sram_channels[SRAM_CH02],
buf->vb.width, buf->risc.dma);
cx_write(VID_A_GPCNT_CTL, 3);
cx_write(VID_A_VBI_CTRL, 3);
cx_write(VBI_A_GPCNT_CTL, 3);
q->count = 1;
cx23885_irq_add_enable(dev, 0x01);
cx_set(VID_A_INT_MSK, 0x000022);
cx_set(DEV_CNTRL2, (1<<5));
cx_set(VID_A_DMA_CTL, 0x22);
return 0;
}
int cx23885_restart_vbi_queue(struct cx23885_dev *dev,
struct cx23885_dmaqueue *q)
{
struct cx23885_buffer *buf;
struct list_head *item;
if (list_empty(&q->active))
return 0;
buf = list_entry(q->active.next, struct cx23885_buffer, vb.queue);
dprintk(2, "restart_queue [%p/%d]: restart dma\n",
buf, buf->vb.i);
cx23885_start_vbi_dma(dev, q, buf);
list_for_each(item, &q->active) {
buf = list_entry(item, struct cx23885_buffer, vb.queue);
buf->count = q->count++;
}
mod_timer(&q->timeout, jiffies + (BUFFER_TIMEOUT / 30));
return 0;
}
void cx23885_vbi_timeout(unsigned long data)
{
struct cx23885_dev *dev = (struct cx23885_dev *)data;
struct cx23885_dmaqueue *q = &dev->vbiq;
struct cx23885_buffer *buf;
unsigned long flags;
cx_clear(VID_A_DMA_CTL, 0x22);
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&q->active)) {
buf = list_entry(q->active.next, struct cx23885_buffer,
vb.queue);
list_del(&buf->vb.queue);
buf->vb.state = VIDEOBUF_ERROR;
wake_up(&buf->vb.done);
printk("%s/0: [%p/%d] timeout - dma=0x%08lx\n", dev->name,
buf, buf->vb.i, (unsigned long)buf->risc.dma);
}
cx23885_restart_vbi_queue(dev, q);
spin_unlock_irqrestore(&dev->slock, flags);
}
static int
vbi_setup(struct videobuf_queue *q, unsigned int *count, unsigned int *size)
{
*size = VBI_LINE_COUNT * VBI_LINE_LENGTH * 2;
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
struct cx23885_fh *fh = q->priv_data;
struct cx23885_dev *dev = fh->dev;
struct cx23885_buffer *buf = container_of(vb,
struct cx23885_buffer, vb);
struct videobuf_dmabuf *dma = videobuf_to_dma(&buf->vb);
unsigned int size;
int rc;
size = VBI_LINE_COUNT * VBI_LINE_LENGTH * 2;
if (0 != buf->vb.baddr && buf->vb.bsize < size)
return -EINVAL;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
buf->vb.width = VBI_LINE_LENGTH;
buf->vb.height = VBI_LINE_COUNT;
buf->vb.size = size;
buf->vb.field = V4L2_FIELD_SEQ_TB;
rc = videobuf_iolock(q, &buf->vb, NULL);
if (0 != rc)
goto fail;
cx23885_risc_vbibuffer(dev->pci, &buf->risc,
dma->sglist,
0, buf->vb.width * buf->vb.height,
buf->vb.width, 0,
buf->vb.height);
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
cx23885_free_buffer(q, buf);
return rc;
}
static void
vbi_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct cx23885_buffer *buf =
container_of(vb, struct cx23885_buffer, vb);
struct cx23885_buffer *prev;
struct cx23885_fh *fh = vq->priv_data;
struct cx23885_dev *dev = fh->dev;
struct cx23885_dmaqueue *q = &dev->vbiq;
buf->risc.jmp[0] = cpu_to_le32(RISC_JUMP | RISC_IRQ1 | RISC_CNT_INC);
buf->risc.jmp[1] = cpu_to_le32(q->stopper.dma);
buf->risc.jmp[2] = cpu_to_le32(0);
if (list_empty(&q->active)) {
list_add_tail(&buf->vb.queue, &q->active);
cx23885_start_vbi_dma(dev, q, buf);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
mod_timer(&q->timeout, jiffies + (BUFFER_TIMEOUT / 30));
dprintk(2, "[%p/%d] vbi_queue - first active\n",
buf, buf->vb.i);
} else {
prev = list_entry(q->active.prev, struct cx23885_buffer,
vb.queue);
list_add_tail(&buf->vb.queue, &q->active);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
prev->risc.jmp[2] = cpu_to_le32(0);
dprintk(2, "[%p/%d] buffer_queue - append to active\n",
buf, buf->vb.i);
}
}
static void vbi_release(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct cx23885_buffer *buf =
container_of(vb, struct cx23885_buffer, vb);
cx23885_free_buffer(q, buf);
}
