static const struct cx25821_fmt *cx25821_format_by_fourcc(unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fourcc)
return formats + i;
return NULL;
}
void cx25821_video_wakeup(struct cx25821_dev *dev, struct cx25821_dmaqueue *q,
u32 count)
{
struct cx25821_buffer *buf;
int bc;
for (bc = 0;; bc++) {
if (list_empty(&q->active)) {
dprintk(1, "bc=%d (=0: active empty)\n", bc);
break;
}
buf = list_entry(q->active.next, struct cx25821_buffer,
vb.queue);
if ((s16) (count - buf->count) < 0)
break;
v4l2_get_timestamp(&buf->vb.ts);
buf->vb.state = VIDEOBUF_DONE;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
if (list_empty(&q->active))
del_timer(&q->timeout);
else
mod_timer(&q->timeout, jiffies + BUFFER_TIMEOUT);
if (bc != 1)
pr_err("%s: %d buffers handled (should be 1)\n", __func__, bc);
}
int cx25821_start_video_dma(struct cx25821_dev *dev,
struct cx25821_dmaqueue *q,
struct cx25821_buffer *buf,
const struct sram_channel *channel)
{
int tmp = 0;
cx25821_sram_channel_setup(dev, channel, buf->bpl, buf->risc.dma);
cx_write(channel->gpcnt_ctl, 3);
q->count = 1;
cx_set(PCI_INT_MSK, cx_read(PCI_INT_MSK) | (1 << channel->i));
cx_set(channel->int_msk, 0x11);
cx_write(channel->dma_ctl, 0x11);
tmp = cx_read(VID_CH_MODE_SEL);
cx_write(VID_CH_MODE_SEL, tmp & 0xFFFFFE00);
return 0;
}
static int cx25821_restart_video_queue(struct cx25821_dev *dev,
struct cx25821_dmaqueue *q,
const struct sram_channel *channel)
{
struct cx25821_buffer *buf, *prev;
struct list_head *item;
if (!list_empty(&q->active)) {
buf = list_entry(q->active.next, struct cx25821_buffer,
vb.queue);
cx25821_start_video_dma(dev, q, buf, channel);
list_for_each(item, &q->active) {
buf = list_entry(item, struct cx25821_buffer, vb.queue);
buf->count = q->count++;
}
mod_timer(&q->timeout, jiffies + BUFFER_TIMEOUT);
return 0;
}
prev = NULL;
for (;;) {
if (list_empty(&q->queued))
return 0;
buf = list_entry(q->queued.next, struct cx25821_buffer,
vb.queue);
if (NULL == prev) {
list_move_tail(&buf->vb.queue, &q->active);
cx25821_start_video_dma(dev, q, buf, channel);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
mod_timer(&q->timeout, jiffies + BUFFER_TIMEOUT);
} else if (prev->vb.width == buf->vb.width &&
prev->vb.height == buf->vb.height &&
prev->fmt == buf->fmt) {
list_move_tail(&buf->vb.queue, &q->active);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
prev->risc.jmp[2] = cpu_to_le32(0);
} else {
return 0;
}
prev = buf;
}
}
static void cx25821_vid_timeout(unsigned long data)
{
struct cx25821_data *timeout_data = (struct cx25821_data *)data;
struct cx25821_dev *dev = timeout_data->dev;
const struct sram_channel *channel = timeout_data->channel;
struct cx25821_dmaqueue *q = &dev->channels[channel->i].dma_vidq;
struct cx25821_buffer *buf;
unsigned long flags;
cx_clear(channel->dma_ctl, 0x11);
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&q->active)) {
buf = list_entry(q->active.next, struct cx25821_buffer,
vb.queue);
list_del(&buf->vb.queue);
buf->vb.state = VIDEOBUF_ERROR;
wake_up(&buf->vb.done);
}
cx25821_restart_video_queue(dev, q, channel);
spin_unlock_irqrestore(&dev->slock, flags);
}
int cx25821_video_irq(struct cx25821_dev *dev, int chan_num, u32 status)
{
u32 count = 0;
int handled = 0;
u32 mask;
const struct sram_channel *channel = dev->channels[chan_num].sram_channels;
mask = cx_read(channel->int_msk);
if (0 == (status & mask))
return handled;
cx_write(channel->int_stat, status);
if (status & (1 << 16)) {
pr_warn("%s, %s: video risc op code error\n",
dev->name, channel->name);
cx_clear(channel->dma_ctl, 0x11);
cx25821_sram_channel_dump(dev, channel);
}
if (status & FLD_VID_DST_RISC1) {
spin_lock(&dev->slock);
count = cx_read(channel->gpcnt);
cx25821_video_wakeup(dev, &dev->channels[channel->i].dma_vidq,
count);
spin_unlock(&dev->slock);
handled++;
}
if (status & 0x10) {
dprintk(2, "stopper video\n");
spin_lock(&dev->slock);
cx25821_restart_video_queue(dev,
&dev->channels[channel->i].dma_vidq, channel);
spin_unlock(&dev->slock);
handled++;
}
return handled;
}
static int cx25821_buffer_setup(struct videobuf_queue *q, unsigned int *count,
unsigned int *size)
{
struct cx25821_channel *chan = q->priv_data;
*size = chan->fmt->depth * chan->width * chan->height >> 3;
if (0 == *count)
*count = 32;
if (*size * *count > vid_limit * 1024 * 1024)
*count = (vid_limit * 1024 * 1024) / *size;
return 0;
}
static int cx25821_buffer_prepare(struct videobuf_queue *q, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct cx25821_channel *chan = q->priv_data;
struct cx25821_dev *dev = chan->dev;
struct cx25821_buffer *buf =
container_of(vb, struct cx25821_buffer, vb);
int rc, init_buffer = 0;
u32 line0_offset;
struct videobuf_dmabuf *dma = videobuf_to_dma(&buf->vb);
int bpl_local = LINE_SIZE_D1;
BUG_ON(NULL == chan->fmt);
if (chan->width < 48 || chan->width > 720 ||
chan->height < 32 || chan->height > 576)
return -EINVAL;
buf->vb.size = (chan->width * chan->height * chan->fmt->depth) >> 3;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
if (buf->fmt != chan->fmt ||
buf->vb.width != chan->width ||
buf->vb.height != chan->height || buf->vb.field != field) {
buf->fmt = chan->fmt;
buf->vb.width = chan->width;
buf->vb.height = chan->height;
buf->vb.field = field;
init_buffer = 1;
}
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
init_buffer = 1;
rc = videobuf_iolock(q, &buf->vb, NULL);
if (0 != rc) {
printk(KERN_DEBUG pr_fmt("videobuf_iolock failed!\n"));
goto fail;
}
}
dprintk(1, "init_buffer=%d\n", init_buffer);
if (init_buffer) {
if (chan->pixel_formats == PIXEL_FRMT_411)
buf->bpl = (buf->fmt->depth * buf->vb.width) >> 3;
else
buf->bpl = (buf->fmt->depth >> 3) * (buf->vb.width);
if (chan->pixel_formats == PIXEL_FRMT_411) {
bpl_local = buf->bpl;
} else {
bpl_local = buf->bpl;
if (chan->use_cif_resolution) {
if (dev->tvnorm & V4L2_STD_625_50)
bpl_local = 352 << 1;
else
bpl_local = chan->cif_width << 1;
}
}
switch (buf->vb.field) {
case V4L2_FIELD_TOP:
cx25821_risc_buffer(dev->pci, &buf->risc,
dma->sglist, 0, UNSET,
buf->bpl, 0, buf->vb.height);
break;
case V4L2_FIELD_BOTTOM:
cx25821_risc_buffer(dev->pci, &buf->risc,
dma->sglist, UNSET, 0,
buf->bpl, 0, buf->vb.height);
break;
case V4L2_FIELD_INTERLACED:
line0_offset = 0;
dprintk(1, "top field first\n");
cx25821_risc_buffer(dev->pci, &buf->risc,
dma->sglist, line0_offset,
bpl_local, bpl_local, bpl_local,
buf->vb.height >> 1);
break;
case V4L2_FIELD_SEQ_TB:
cx25821_risc_buffer(dev->pci, &buf->risc,
dma->sglist,
0, buf->bpl * (buf->vb.height >> 1),
buf->bpl, 0, buf->vb.height >> 1);
break;
case V4L2_FIELD_SEQ_BT:
cx25821_risc_buffer(dev->pci, &buf->risc,
dma->sglist,
buf->bpl * (buf->vb.height >> 1), 0,
buf->bpl, 0, buf->vb.height >> 1);
break;
default:
BUG();
}
}
dprintk(2, "[%p/%d] buffer_prep - %dx%d %dbpp \"%s\" - dma=0x%08lx\n",
buf, buf->vb.i, chan->width, chan->height, chan->fmt->depth,
chan->fmt->name, (unsigned long)buf->risc.dma);
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
cx25821_free_buffer(q, buf);
return rc;
}
static void cx25821_buffer_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct cx25821_buffer *buf =
container_of(vb, struct cx25821_buffer, vb);
cx25821_free_buffer(q, buf);
}
static int cx25821_video_mmap(struct file *file, struct vm_area_struct *vma)
{
struct cx25821_channel *chan = video_drvdata(file);
return videobuf_mmap_mapper(&chan->vidq, vma);
}
static void buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct cx25821_buffer *buf =
container_of(vb, struct cx25821_buffer, vb);
struct cx25821_buffer *prev;
struct cx25821_channel *chan = vq->priv_data;
struct cx25821_dev *dev = chan->dev;
struct cx25821_dmaqueue *q = &dev->channels[chan->id].dma_vidq;
buf->risc.jmp[0] = cpu_to_le32(RISC_JUMP | RISC_IRQ1 | RISC_CNT_INC);
buf->risc.jmp[1] = cpu_to_le32(q->stopper.dma);
buf->risc.jmp[2] = cpu_to_le32(0);
dprintk(2, "jmp to stopper (0x%x)\n", buf->risc.jmp[1]);
if (!list_empty(&q->queued)) {
list_add_tail(&buf->vb.queue, &q->queued);
buf->vb.state = VIDEOBUF_QUEUED;
dprintk(2, "[%p/%d] buffer_queue - append to queued\n", buf,
buf->vb.i);
} else if (list_empty(&q->active)) {
list_add_tail(&buf->vb.queue, &q->active);
cx25821_start_video_dma(dev, q, buf, chan->sram_channels);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
mod_timer(&q->timeout, jiffies + BUFFER_TIMEOUT);
dprintk(2, "[%p/%d] buffer_queue - first active, buf cnt = %d, q->count = %d\n",
buf, buf->vb.i, buf->count, q->count);
} else {
prev = list_entry(q->active.prev, struct cx25821_buffer,
vb.queue);
if (prev->vb.width == buf->vb.width
&& prev->vb.height == buf->vb.height
&& prev->fmt == buf->fmt) {
list_add_tail(&buf->vb.queue, &q->active);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
prev->risc.jmp[2] = cpu_to_le32(0);
dprintk(2, "[%p/%d] buffer_queue - append to active, buf->count=%d\n",
buf, buf->vb.i, buf->count);
} else {
list_add_tail(&buf->vb.queue, &q->queued);
buf->vb.state = VIDEOBUF_QUEUED;
dprintk(2, "[%p/%d] buffer_queue - first queued\n", buf,
buf->vb.i);
}
}
if (list_empty(&q->active))
dprintk(2, "active queue empty!\n");
}
static ssize_t video_read(struct file *file, char __user * data, size_t count,
loff_t *ppos)
{
struct v4l2_fh *fh = file->private_data;
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
int err = 0;
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
if (chan->streaming_fh && chan->streaming_fh != fh) {
err = -EBUSY;
goto unlock;
}
chan->streaming_fh = fh;
err = videobuf_read_one(&chan->vidq, data, count, ppos,
file->f_flags & O_NONBLOCK);
unlock:
mutex_unlock(&dev->lock);
return err;
}
static unsigned int video_poll(struct file *file,
struct poll_table_struct *wait)
{
struct cx25821_channel *chan = video_drvdata(file);
unsigned long req_events = poll_requested_events(wait);
unsigned int res = v4l2_ctrl_poll(file, wait);
if (req_events & (POLLIN | POLLRDNORM))
res |= videobuf_poll_stream(file, &chan->vidq, wait);
return res;
}
static int video_release(struct file *file)
{
struct cx25821_channel *chan = video_drvdata(file);
struct v4l2_fh *fh = file->private_data;
struct cx25821_dev *dev = chan->dev;
const struct sram_channel *sram_ch =
dev->channels[0].sram_channels;
mutex_lock(&dev->lock);
cx_write(sram_ch->dma_ctl, 0);
if (chan->streaming_fh == fh) {
videobuf_queue_cancel(&chan->vidq);
chan->streaming_fh = NULL;
}
if (chan->vidq.read_buf) {
cx25821_buffer_release(&chan->vidq, chan->vidq.read_buf);
kfree(chan->vidq.read_buf);
}
videobuf_mmap_free(&chan->vidq);
mutex_unlock(&dev->lock);
return v4l2_fh_release(file);
}
static int cx25821_vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (unlikely(f->index >= ARRAY_SIZE(formats)))
return -EINVAL;
strlcpy(f->description, formats[f->index].name, sizeof(f->description));
f->pixelformat = formats[f->index].fourcc;
return 0;
}
static int cx25821_vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx25821_channel *chan = video_drvdata(file);
f->fmt.pix.width = chan->width;
f->fmt.pix.height = chan->height;
f->fmt.pix.field = chan->vidq.field;
f->fmt.pix.pixelformat = chan->fmt->fourcc;
f->fmt.pix.bytesperline = (chan->width * chan->fmt->depth) >> 3;
f->fmt.pix.sizeimage = chan->height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int cx25821_vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
const struct cx25821_fmt *fmt;
enum v4l2_field field = f->fmt.pix.field;
unsigned int maxh;
unsigned w;
fmt = cx25821_format_by_fourcc(f->fmt.pix.pixelformat);
if (NULL == fmt)
return -EINVAL;
maxh = (dev->tvnorm & V4L2_STD_625_50) ? 576 : 480;
w = f->fmt.pix.width;
if (field != V4L2_FIELD_BOTTOM)
field = V4L2_FIELD_TOP;
if (w < 352) {
w = 176;
f->fmt.pix.height = maxh / 4;
} else if (w < 720) {
w = 352;
f->fmt.pix.height = maxh / 2;
} else {
w = 720;
f->fmt.pix.height = maxh;
field = V4L2_FIELD_INTERLACED;
}
f->fmt.pix.field = field;
f->fmt.pix.width = w;
f->fmt.pix.bytesperline = (f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
int pix_format = PIXEL_FRMT_422;
int err;
err = cx25821_vidioc_try_fmt_vid_cap(file, priv, f);
if (0 != err)
return err;
chan->fmt = cx25821_format_by_fourcc(f->fmt.pix.pixelformat);
chan->vidq.field = f->fmt.pix.field;
chan->width = f->fmt.pix.width;
chan->height = f->fmt.pix.height;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_Y41P)
pix_format = PIXEL_FRMT_411;
else
pix_format = PIXEL_FRMT_422;
cx25821_set_pixel_format(dev, SRAM_CH00, pix_format);
if (chan->width == 320 || chan->width == 352)
chan->use_cif_resolution = 1;
else
chan->use_cif_resolution = 0;
chan->cif_width = chan->width;
medusa_set_resolution(dev, chan->width, SRAM_CH00);
return 0;
}
static int vidioc_streamon(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct cx25821_channel *chan = video_drvdata(file);
if (i != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (chan->streaming_fh && chan->streaming_fh != priv)
return -EBUSY;
chan->streaming_fh = priv;
return videobuf_streamon(&chan->vidq);
}
static int vidioc_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct cx25821_channel *chan = video_drvdata(file);
if (i != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (chan->streaming_fh && chan->streaming_fh != priv)
return -EBUSY;
if (chan->streaming_fh == NULL)
return 0;
chan->streaming_fh = NULL;
return videobuf_streamoff(&chan->vidq);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
int ret_val = 0;
struct cx25821_channel *chan = video_drvdata(file);
ret_val = videobuf_dqbuf(&chan->vidq, p, file->f_flags & O_NONBLOCK);
p->sequence = chan->dma_vidq.count;
return ret_val;
}
static int vidioc_log_status(struct file *file, void *priv)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
const struct sram_channel *sram_ch = chan->sram_channels;
u32 tmp = 0;
tmp = cx_read(sram_ch->dma_ctl);
pr_info("Video input 0 is %s\n",
(tmp & 0x11) ? "streaming" : "stopped");
return 0;
}
static int cx25821_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
const u32 cap_input = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
const u32 cap_output = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_READWRITE;
strcpy(cap->driver, "cx25821");
strlcpy(cap->card, cx25821_boards[dev->board].name, sizeof(cap->card));
sprintf(cap->bus_info, "PCIe:%s", pci_name(dev->pci));
if (chan->id >= VID_CHANNEL_NUM)
cap->device_caps = cap_output;
else
cap->device_caps = cap_input;
cap->capabilities = cap_input | cap_output | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int cx25821_vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct cx25821_channel *chan = video_drvdata(file);
return videobuf_reqbufs(&chan->vidq, p);
}
static int cx25821_vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx25821_channel *chan = video_drvdata(file);
return videobuf_querybuf(&chan->vidq, p);
}
static int cx25821_vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct cx25821_channel *chan = video_drvdata(file);
return videobuf_qbuf(&chan->vidq, p);
}
static int cx25821_vidioc_g_std(struct file *file, void *priv, v4l2_std_id *tvnorms)
{
struct cx25821_channel *chan = video_drvdata(file);
*tvnorms = chan->dev->tvnorm;
return 0;
}
static int cx25821_vidioc_s_std(struct file *file, void *priv,
v4l2_std_id tvnorms)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
if (dev->tvnorm == tvnorms)
return 0;
dev->tvnorm = tvnorms;
chan->width = 720;
chan->height = (dev->tvnorm & V4L2_STD_625_50) ? 576 : 480;
medusa_set_videostandard(dev);
return 0;
}
static int cx25821_vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
i->std = CX25821_NORMS;
strcpy(i->name, "Composite");
return 0;
}
static int cx25821_vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int cx25821_vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
return i ? -EINVAL : 0;
}
static int cx25821_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct cx25821_channel *chan =
container_of(ctrl->handler, struct cx25821_channel, hdl);
struct cx25821_dev *dev = chan->dev;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
medusa_set_brightness(dev, ctrl->val, chan->id);
break;
case V4L2_CID_HUE:
medusa_set_hue(dev, ctrl->val, chan->id);
break;
case V4L2_CID_CONTRAST:
medusa_set_contrast(dev, ctrl->val, chan->id);
break;
case V4L2_CID_SATURATION:
medusa_set_saturation(dev, ctrl->val, chan->id);
break;
default:
return -EINVAL;
}
return 0;
}
static int cx25821_vidioc_enum_output(struct file *file, void *priv,
struct v4l2_output *o)
{
if (o->index)
return -EINVAL;
o->type = V4L2_INPUT_TYPE_CAMERA;
o->std = CX25821_NORMS;
strcpy(o->name, "Composite");
return 0;
}
static int cx25821_vidioc_g_output(struct file *file, void *priv, unsigned int *o)
{
*o = 0;
return 0;
}
static int cx25821_vidioc_s_output(struct file *file, void *priv, unsigned int o)
{
return o ? -EINVAL : 0;
}
static int cx25821_vidioc_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
const struct cx25821_fmt *fmt;
fmt = cx25821_format_by_fourcc(f->fmt.pix.pixelformat);
if (NULL == fmt)
return -EINVAL;
f->fmt.pix.width = 720;
f->fmt.pix.height = (dev->tvnorm & V4L2_STD_625_50) ? 576 : 480;
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
f->fmt.pix.bytesperline = (f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx25821_channel *chan = video_drvdata(file);
int err;
err = cx25821_vidioc_try_fmt_vid_out(file, priv, f);
if (0 != err)
return err;
chan->fmt = cx25821_format_by_fourcc(f->fmt.pix.pixelformat);
chan->vidq.field = f->fmt.pix.field;
chan->width = f->fmt.pix.width;
chan->height = f->fmt.pix.height;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_Y41P)
chan->pixel_formats = PIXEL_FRMT_411;
else
chan->pixel_formats = PIXEL_FRMT_422;
return 0;
}
static ssize_t video_write(struct file *file, const char __user *data, size_t count,
loff_t *ppos)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
struct v4l2_fh *fh = file->private_data;
int err = 0;
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
if (chan->streaming_fh && chan->streaming_fh != fh) {
err = -EBUSY;
goto unlock;
}
if (!chan->streaming_fh) {
err = cx25821_vidupstream_init(chan, chan->pixel_formats);
if (err)
goto unlock;
chan->streaming_fh = fh;
}
err = cx25821_write_frame(chan, data, count);
count -= err;
*ppos += err;
unlock:
mutex_unlock(&dev->lock);
return err;
}
static int video_out_release(struct file *file)
{
struct cx25821_channel *chan = video_drvdata(file);
struct cx25821_dev *dev = chan->dev;
struct v4l2_fh *fh = file->private_data;
mutex_lock(&dev->lock);
if (chan->streaming_fh == fh) {
cx25821_stop_upstream_video(chan);
chan->streaming_fh = NULL;
}
mutex_unlock(&dev->lock);
return v4l2_fh_release(file);
}
void cx25821_video_unregister(struct cx25821_dev *dev, int chan_num)
{
cx_clear(PCI_INT_MSK, 1);
if (video_is_registered(&dev->channels[chan_num].vdev)) {
video_unregister_device(&dev->channels[chan_num].vdev);
v4l2_ctrl_handler_free(&dev->channels[chan_num].hdl);
btcx_riscmem_free(dev->pci,
&dev->channels[chan_num].dma_vidq.stopper);
}
}
int cx25821_video_register(struct cx25821_dev *dev)
{
int err;
int i;
dev->tvnorm = V4L2_STD_NTSC_M;
spin_lock_init(&dev->slock);
for (i = 0; i < MAX_VID_CHANNEL_NUM - 1; ++i) {
struct cx25821_channel *chan = &dev->channels[i];
struct video_device *vdev = &chan->vdev;
struct v4l2_ctrl_handler *hdl = &chan->hdl;
bool is_output = i > SRAM_CH08;
if (i == SRAM_CH08)
continue;
if (!is_output) {
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &cx25821_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 10000, 1, 6200);
v4l2_ctrl_new_std(hdl, &cx25821_ctrl_ops,
V4L2_CID_CONTRAST, 0, 10000, 1, 5000);
v4l2_ctrl_new_std(hdl, &cx25821_ctrl_ops,
V4L2_CID_SATURATION, 0, 10000, 1, 5000);
v4l2_ctrl_new_std(hdl, &cx25821_ctrl_ops,
V4L2_CID_HUE, 0, 10000, 1, 5000);
if (hdl->error) {
err = hdl->error;
goto fail_unreg;
}
err = v4l2_ctrl_handler_setup(hdl);
if (err)
goto fail_unreg;
} else {
chan->out = &dev->vid_out_data[i - SRAM_CH09];
chan->out->chan = chan;
}
cx25821_risc_stopper(dev->pci, &chan->dma_vidq.stopper,
chan->sram_channels->dma_ctl, 0x11, 0);
chan->sram_channels = &cx25821_sram_channels[i];
chan->width = 720;
if (dev->tvnorm & V4L2_STD_625_50)
chan->height = 576;
else
chan->height = 480;
if (chan->pixel_formats == PIXEL_FRMT_411)
chan->fmt = cx25821_format_by_fourcc(V4L2_PIX_FMT_Y41P);
else
chan->fmt = cx25821_format_by_fourcc(V4L2_PIX_FMT_YUYV);
cx_write(chan->sram_channels->int_stat, 0xffffffff);
INIT_LIST_HEAD(&chan->dma_vidq.active);
INIT_LIST_HEAD(&chan->dma_vidq.queued);
chan->timeout_data.dev = dev;
chan->timeout_data.channel = &cx25821_sram_channels[i];
chan->dma_vidq.timeout.function = cx25821_vid_timeout;
chan->dma_vidq.timeout.data = (unsigned long)&chan->timeout_data;
init_timer(&chan->dma_vidq.timeout);
if (!is_output)
videobuf_queue_sg_init(&chan->vidq, &cx25821_video_qops, &dev->pci->dev,
&dev->slock, V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_INTERLACED, sizeof(struct cx25821_buffer),
chan, &dev->lock);
*vdev = is_output ? cx25821_video_out_device : cx25821_video_device;
vdev->v4l2_dev = &dev->v4l2_dev;
if (!is_output)
vdev->ctrl_handler = hdl;
else
vdev->vfl_dir = VFL_DIR_TX;
vdev->lock = &dev->lock;
snprintf(vdev->name, sizeof(vdev->name), "%s #%d", dev->name, i);
video_set_drvdata(vdev, chan);
err = video_register_device(vdev, VFL_TYPE_GRABBER,
video_nr[dev->nr]);
if (err < 0)
goto fail_unreg;
}
cx_set(PCI_INT_MSK, 0xff);
return 0;
fail_unreg:
while (i >= 0)
cx25821_video_unregister(dev, i--);
return err;
}
