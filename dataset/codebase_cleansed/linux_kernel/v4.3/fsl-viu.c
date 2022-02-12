struct viu_fmt *format_by_fourcc(int fourcc)
{
int i;
for (i = 0; i < NUM_FORMATS; i++) {
if (formats[i].pixelformat == fourcc)
return formats + i;
}
dprintk(0, "unknown pixelformat:'%4.4s'\n", (char *)&fourcc);
return NULL;
}
void viu_start_dma(struct viu_dev *dev)
{
struct viu_reg *vr = dev->vr;
dev->field = 0;
out_be32(&vr->status_cfg, SOFT_RST);
out_be32(&vr->status_cfg, INT_FIELD_EN);
}
void viu_stop_dma(struct viu_dev *dev)
{
struct viu_reg *vr = dev->vr;
int cnt = 100;
u32 status_cfg;
out_be32(&vr->status_cfg, 0);
status_cfg = in_be32(&vr->status_cfg);
if (status_cfg & 0x3f0000)
out_be32(&vr->status_cfg, status_cfg & 0x3f0000);
if (status_cfg & DMA_ACT) {
do {
status_cfg = in_be32(&vr->status_cfg);
if (status_cfg & INT_DMA_END_STATUS)
break;
} while (cnt--);
if (cnt < 0) {
out_be32(&vr->status_cfg, SOFT_RST);
out_be32(&vr->status_cfg, 0);
} else {
out_be32(&vr->status_cfg, status_cfg & 0x3f0000);
}
}
dev->field = 0;
}
static int restart_video_queue(struct viu_dmaqueue *vidq)
{
struct viu_buf *buf, *prev;
dprintk(1, "%s vidq=0x%08lx\n", __func__, (unsigned long)vidq);
if (!list_empty(&vidq->active)) {
buf = list_entry(vidq->active.next, struct viu_buf, vb.queue);
dprintk(2, "restart_queue [%p/%d]: restart dma\n",
buf, buf->vb.i);
viu_stop_dma(vidq->dev);
list_for_each_entry_safe(buf, prev, &vidq->active, vb.queue) {
list_del(&buf->vb.queue);
buf->vb.state = VIDEOBUF_ERROR;
wake_up(&buf->vb.done);
}
mod_timer(&vidq->timeout, jiffies+BUFFER_TIMEOUT);
return 0;
}
prev = NULL;
for (;;) {
if (list_empty(&vidq->queued))
return 0;
buf = list_entry(vidq->queued.next, struct viu_buf, vb.queue);
if (prev == NULL) {
list_move_tail(&buf->vb.queue, &vidq->active);
dprintk(1, "Restarting video dma\n");
viu_stop_dma(vidq->dev);
viu_start_dma(vidq->dev);
buf->vb.state = VIDEOBUF_ACTIVE;
mod_timer(&vidq->timeout, jiffies+BUFFER_TIMEOUT);
dprintk(2, "[%p/%d] restart_queue - first active\n",
buf, buf->vb.i);
} else if (prev->vb.width == buf->vb.width &&
prev->vb.height == buf->vb.height &&
prev->fmt == buf->fmt) {
list_move_tail(&buf->vb.queue, &vidq->active);
buf->vb.state = VIDEOBUF_ACTIVE;
dprintk(2, "[%p/%d] restart_queue - move to active\n",
buf, buf->vb.i);
} else {
return 0;
}
prev = buf;
}
}
static void viu_vid_timeout(unsigned long data)
{
struct viu_dev *dev = (struct viu_dev *)data;
struct viu_buf *buf;
struct viu_dmaqueue *vidq = &dev->vidq;
while (!list_empty(&vidq->active)) {
buf = list_entry(vidq->active.next, struct viu_buf, vb.queue);
list_del(&buf->vb.queue);
buf->vb.state = VIDEOBUF_ERROR;
wake_up(&buf->vb.done);
dprintk(1, "viu/0: [%p/%d] timeout\n", buf, buf->vb.i);
}
restart_video_queue(vidq);
}
static int buffer_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct viu_fh *fh = vq->priv_data;
*size = fh->width * fh->height * fh->fmt->depth >> 3;
if (*count == 0)
*count = 32;
while (*size * *count > VIU_VID_MEM_LIMIT * 1024 * 1024)
(*count)--;
dprintk(1, "%s, count=%d, size=%d\n", __func__, *count, *size);
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct viu_buf *buf)
{
struct videobuf_buffer *vb = &buf->vb;
void *vaddr = NULL;
BUG_ON(in_interrupt());
videobuf_waiton(vq, &buf->vb, 0, 0);
if (vq->int_ops && vq->int_ops->vaddr)
vaddr = vq->int_ops->vaddr(vb);
if (vaddr)
videobuf_dma_contig_free(vq, &buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
inline int buffer_activate(struct viu_dev *dev, struct viu_buf *buf)
{
struct viu_reg *vr = dev->vr;
int bpp;
reg_val.field_base_addr = videobuf_to_dma_contig(&buf->vb);
dprintk(1, "buffer_activate [%p/%d]: dma addr 0x%lx\n",
buf, buf->vb.i, (unsigned long)reg_val.field_base_addr);
reg_val.status_cfg = 0;
bpp = buf->fmt->depth >> 3;
switch (bpp) {
case 2:
reg_val.status_cfg &= ~MODE_32BIT;
reg_val.dma_inc = buf->vb.width * 2;
break;
case 4:
reg_val.status_cfg |= MODE_32BIT;
reg_val.dma_inc = buf->vb.width * 4;
break;
default:
dprintk(0, "doesn't support color depth(%d)\n",
bpp * 8);
return -EINVAL;
}
reg_val.picture_count = (buf->vb.height / 2) << 16 |
buf->vb.width;
reg_val.status_cfg |= DMA_ACT | INT_DMA_END_EN | INT_FIELD_EN;
buf->vb.state = VIDEOBUF_ACTIVE;
dev->capfield = buf->vb.field;
if (!V4L2_FIELD_HAS_BOTH(buf->vb.field))
reg_val.dma_inc = 0;
out_be32(&vr->dma_inc, reg_val.dma_inc);
out_be32(&vr->picture_count, reg_val.picture_count);
out_be32(&vr->field_base_addr, reg_val.field_base_addr);
mod_timer(&dev->vidq.timeout, jiffies + BUFFER_TIMEOUT);
return 0;
}
static int buffer_prepare(struct videobuf_queue *vq,
struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct viu_fh *fh = vq->priv_data;
struct viu_buf *buf = container_of(vb, struct viu_buf, vb);
int rc;
BUG_ON(fh->fmt == NULL);
if (fh->width < 48 || fh->width > norm_maxw() ||
fh->height < 32 || fh->height > norm_maxh())
return -EINVAL;
buf->vb.size = (fh->width * fh->height * fh->fmt->depth) >> 3;
if (buf->vb.baddr != 0 && buf->vb.bsize < buf->vb.size)
return -EINVAL;
if (buf->fmt != fh->fmt ||
buf->vb.width != fh->width ||
buf->vb.height != fh->height ||
buf->vb.field != field) {
buf->fmt = fh->fmt;
buf->vb.width = fh->width;
buf->vb.height = fh->height;
buf->vb.field = field;
}
if (buf->vb.state == VIDEOBUF_NEEDS_INIT) {
rc = videobuf_iolock(vq, &buf->vb, NULL);
if (rc != 0)
goto fail;
buf->vb.width = fh->width;
buf->vb.height = fh->height;
buf->vb.field = field;
buf->fmt = fh->fmt;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(vq, buf);
return rc;
}
static void buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct viu_buf *buf = container_of(vb, struct viu_buf, vb);
struct viu_fh *fh = vq->priv_data;
struct viu_dev *dev = fh->dev;
struct viu_dmaqueue *vidq = &dev->vidq;
struct viu_buf *prev;
if (!list_empty(&vidq->queued)) {
dprintk(1, "adding vb queue=0x%08lx\n",
(unsigned long)&buf->vb.queue);
dprintk(1, "vidq pointer 0x%p, queued 0x%p\n",
vidq, &vidq->queued);
dprintk(1, "dev %p, queued: self %p, next %p, head %p\n",
dev, &vidq->queued, vidq->queued.next,
vidq->queued.prev);
list_add_tail(&buf->vb.queue, &vidq->queued);
buf->vb.state = VIDEOBUF_QUEUED;
dprintk(2, "[%p/%d] buffer_queue - append to queued\n",
buf, buf->vb.i);
} else if (list_empty(&vidq->active)) {
dprintk(1, "adding vb active=0x%08lx\n",
(unsigned long)&buf->vb.queue);
list_add_tail(&buf->vb.queue, &vidq->active);
buf->vb.state = VIDEOBUF_ACTIVE;
mod_timer(&vidq->timeout, jiffies+BUFFER_TIMEOUT);
dprintk(2, "[%p/%d] buffer_queue - first active\n",
buf, buf->vb.i);
buffer_activate(dev, buf);
} else {
dprintk(1, "adding vb queue2=0x%08lx\n",
(unsigned long)&buf->vb.queue);
prev = list_entry(vidq->active.prev, struct viu_buf, vb.queue);
if (prev->vb.width == buf->vb.width &&
prev->vb.height == buf->vb.height &&
prev->fmt == buf->fmt) {
list_add_tail(&buf->vb.queue, &vidq->active);
buf->vb.state = VIDEOBUF_ACTIVE;
dprintk(2, "[%p/%d] buffer_queue - append to active\n",
buf, buf->vb.i);
} else {
list_add_tail(&buf->vb.queue, &vidq->queued);
buf->vb.state = VIDEOBUF_QUEUED;
dprintk(2, "[%p/%d] buffer_queue - first queued\n",
buf, buf->vb.i);
}
}
}
static void buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct viu_buf *buf = container_of(vb, struct viu_buf, vb);
struct viu_fh *fh = vq->priv_data;
struct viu_dev *dev = (struct viu_dev *)fh->dev;
viu_stop_dma(dev);
free_buffer(vq, buf);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strcpy(cap->driver, "viu");
strcpy(cap->card, "viu");
strcpy(cap->bus_info, "platform:viu");
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING |
V4L2_CAP_VIDEO_OVERLAY |
V4L2_CAP_READWRITE;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
int index = f->index;
if (f->index >= NUM_FORMATS)
return -EINVAL;
f->pixelformat = formats[index].fourcc;
return 0;
}
static int vidioc_g_fmt_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct viu_fh *fh = priv;
f->fmt.pix.width = fh->width;
f->fmt.pix.height = fh->height;
f->fmt.pix.field = fh->vb_vidq.field;
f->fmt.pix.pixelformat = fh->fmt->pixelformat;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fh->fmt->depth) >> 3;
f->fmt.pix.sizeimage = fh->sizeimage;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_try_fmt_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct viu_fmt *fmt;
unsigned int maxw, maxh;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (!fmt) {
dprintk(1, "Fourcc format (0x%08x) invalid.",
f->fmt.pix.pixelformat);
return -EINVAL;
}
maxw = norm_maxw();
maxh = norm_maxh();
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
if (f->fmt.pix.height < 32)
f->fmt.pix.height = 32;
if (f->fmt.pix.height > maxh)
f->fmt.pix.height = maxh;
if (f->fmt.pix.width < 48)
f->fmt.pix.width = 48;
if (f->fmt.pix.width > maxw)
f->fmt.pix.width = maxw;
f->fmt.pix.width &= ~0x03;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_s_fmt_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct viu_fh *fh = priv;
int ret;
ret = vidioc_try_fmt_cap(file, fh, f);
if (ret < 0)
return ret;
fh->fmt = format_by_fourcc(f->fmt.pix.pixelformat);
fh->width = f->fmt.pix.width;
fh->height = f->fmt.pix.height;
fh->sizeimage = f->fmt.pix.sizeimage;
fh->vb_vidq.field = f->fmt.pix.field;
fh->type = f->type;
return 0;
}
static int vidioc_g_fmt_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct viu_fh *fh = priv;
f->fmt.win = fh->win;
return 0;
}
static int verify_preview(struct viu_dev *dev, struct v4l2_window *win)
{
enum v4l2_field field;
int maxw, maxh;
if (dev->ovbuf.base == NULL)
return -EINVAL;
if (dev->ovfmt == NULL)
return -EINVAL;
if (win->w.width < 48 || win->w.height < 32)
return -EINVAL;
field = win->field;
maxw = dev->crop_current.width;
maxh = dev->crop_current.height;
if (field == V4L2_FIELD_ANY) {
field = (win->w.height > maxh/2)
? V4L2_FIELD_INTERLACED
: V4L2_FIELD_TOP;
}
switch (field) {
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
maxh = maxh / 2;
break;
case V4L2_FIELD_INTERLACED:
break;
default:
return -EINVAL;
}
win->field = field;
if (win->w.width > maxw)
win->w.width = maxw;
if (win->w.height > maxh)
win->w.height = maxh;
return 0;
}
inline void viu_activate_overlay(struct viu_reg *viu_reg)
{
struct viu_reg *vr = viu_reg;
out_be32(&vr->field_base_addr, reg_val.field_base_addr);
out_be32(&vr->dma_inc, reg_val.dma_inc);
out_be32(&vr->picture_count, reg_val.picture_count);
}
static int viu_setup_preview(struct viu_dev *dev, struct viu_fh *fh)
{
int bpp;
dprintk(1, "%s %dx%d\n", __func__,
fh->win.w.width, fh->win.w.height);
reg_val.status_cfg = 0;
reg_val.picture_count = (fh->win.w.height / 2) << 16 |
fh->win.w.width;
bpp = dev->ovfmt->depth / 8;
switch (bpp) {
case 2:
reg_val.status_cfg &= ~MODE_32BIT;
reg_val.dma_inc = fh->win.w.width * 2;
break;
case 4:
reg_val.status_cfg |= MODE_32BIT;
reg_val.dma_inc = fh->win.w.width * 4;
break;
default:
dprintk(0, "device doesn't support color depth(%d)\n",
bpp * 8);
return -EINVAL;
}
dev->ovfield = fh->win.field;
if (!V4L2_FIELD_HAS_BOTH(dev->ovfield))
reg_val.dma_inc = 0;
reg_val.status_cfg |= DMA_ACT | INT_DMA_END_EN | INT_FIELD_EN;
reg_val.field_base_addr = (u32)dev->ovbuf.base;
return 0;
}
static int vidioc_s_fmt_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct viu_fh *fh = priv;
struct viu_dev *dev = (struct viu_dev *)fh->dev;
unsigned long flags;
int err;
err = verify_preview(dev, &f->fmt.win);
if (err)
return err;
fh->win = f->fmt.win;
spin_lock_irqsave(&dev->slock, flags);
viu_setup_preview(dev, fh);
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
}
static int vidioc_try_fmt_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
return 0;
}
static int vidioc_overlay(struct file *file, void *priv, unsigned int on)
{
struct viu_fh *fh = priv;
struct viu_dev *dev = (struct viu_dev *)fh->dev;
unsigned long flags;
if (on) {
spin_lock_irqsave(&dev->slock, flags);
viu_activate_overlay(dev->vr);
dev->ovenable = 1;
viu_start_dma(dev);
spin_unlock_irqrestore(&dev->slock, flags);
} else {
viu_stop_dma(dev);
dev->ovenable = 0;
}
return 0;
}
int vidioc_g_fbuf(struct file *file, void *priv, struct v4l2_framebuffer *arg)
{
struct viu_fh *fh = priv;
struct viu_dev *dev = fh->dev;
struct v4l2_framebuffer *fb = arg;
*fb = dev->ovbuf;
fb->capability = V4L2_FBUF_CAP_LIST_CLIPPING;
return 0;
}
int vidioc_s_fbuf(struct file *file, void *priv, const struct v4l2_framebuffer *arg)
{
struct viu_fh *fh = priv;
struct viu_dev *dev = fh->dev;
const struct v4l2_framebuffer *fb = arg;
struct viu_fmt *fmt;
if (!capable(CAP_SYS_ADMIN) && !capable(CAP_SYS_RAWIO))
return -EPERM;
fmt = format_by_fourcc(fb->fmt.pixelformat);
if (fmt == NULL)
return -EINVAL;
dev->ovbuf = *fb;
dev->ovfmt = fmt;
if (dev->ovbuf.fmt.bytesperline == 0) {
dev->ovbuf.fmt.bytesperline =
dev->ovbuf.fmt.width * fmt->depth / 8;
}
return 0;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct viu_fh *fh = priv;
return videobuf_reqbufs(&fh->vb_vidq, p);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct viu_fh *fh = priv;
return videobuf_querybuf(&fh->vb_vidq, p);
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct viu_fh *fh = priv;
return videobuf_qbuf(&fh->vb_vidq, p);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct viu_fh *fh = priv;
return videobuf_dqbuf(&fh->vb_vidq, p,
file->f_flags & O_NONBLOCK);
}
static int vidioc_streamon(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct viu_fh *fh = priv;
struct viu_dev *dev = fh->dev;
if (fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (fh->type != i)
return -EINVAL;
if (dev->ovenable)
dev->ovenable = 0;
viu_start_dma(fh->dev);
return videobuf_streamon(&fh->vb_vidq);
}
static int vidioc_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct viu_fh *fh = priv;
if (fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (fh->type != i)
return -EINVAL;
viu_stop_dma(fh->dev);
return videobuf_streamoff(&fh->vb_vidq);
}
static int vidioc_querystd(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct viu_fh *fh = priv;
decoder_call(fh->dev, video, querystd, std_id);
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id id)
{
struct viu_fh *fh = priv;
fh->dev->std = id;
decoder_call(fh->dev, video, s_std, id);
return 0;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct viu_fh *fh = priv;
*std_id = fh->dev->std;
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
struct viu_fh *fh = priv;
if (inp->index != 0)
return -EINVAL;
inp->type = V4L2_INPUT_TYPE_CAMERA;
inp->std = fh->dev->vdev->tvnorms;
strcpy(inp->name, "Camera");
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct viu_fh *fh = priv;
if (i)
return -EINVAL;
decoder_call(fh->dev, video, s_routing, i, 0, 0);
return 0;
}
inline void viu_activate_next_buf(struct viu_dev *dev,
struct viu_dmaqueue *viuq)
{
struct viu_dmaqueue *vidq = viuq;
struct viu_buf *buf;
if (!list_empty(&vidq->active)) {
buf = list_entry(vidq->active.next, struct viu_buf,
vb.queue);
dprintk(1, "start another queued buffer: 0x%p\n", buf);
buffer_activate(dev, buf);
} else if (!list_empty(&vidq->queued)) {
buf = list_entry(vidq->queued.next, struct viu_buf,
vb.queue);
list_del(&buf->vb.queue);
dprintk(1, "start another queued buffer: 0x%p\n", buf);
list_add_tail(&buf->vb.queue, &vidq->active);
buf->vb.state = VIDEOBUF_ACTIVE;
buffer_activate(dev, buf);
}
}
inline void viu_default_settings(struct viu_reg *viu_reg)
{
struct viu_reg *vr = viu_reg;
out_be32(&vr->luminance, 0x9512A254);
out_be32(&vr->chroma_r, 0x03310000);
out_be32(&vr->chroma_g, 0x06600F38);
out_be32(&vr->chroma_b, 0x00000409);
out_be32(&vr->alpha, 0x000000ff);
out_be32(&vr->req_alarm, 0x00000090);
dprintk(1, "status reg: 0x%08x, field base: 0x%08x\n",
in_be32(&vr->status_cfg), in_be32(&vr->field_base_addr));
}
static void viu_overlay_intr(struct viu_dev *dev, u32 status)
{
struct viu_reg *vr = dev->vr;
if (status & INT_DMA_END_STATUS)
dev->dma_done = 1;
if (status & INT_FIELD_STATUS) {
if (dev->dma_done) {
u32 addr = reg_val.field_base_addr;
dev->dma_done = 0;
if (status & FIELD_NO)
addr += reg_val.dma_inc;
out_be32(&vr->field_base_addr, addr);
out_be32(&vr->dma_inc, reg_val.dma_inc);
out_be32(&vr->status_cfg,
(status & 0xffc0ffff) |
(status & INT_ALL_STATUS) |
reg_val.status_cfg);
} else if (status & INT_VSYNC_STATUS) {
out_be32(&vr->status_cfg,
(status & 0xffc0ffff) |
(status & INT_ALL_STATUS) |
reg_val.status_cfg);
}
}
}
static void viu_capture_intr(struct viu_dev *dev, u32 status)
{
struct viu_dmaqueue *vidq = &dev->vidq;
struct viu_reg *vr = dev->vr;
struct viu_buf *buf;
int field_num;
int need_two;
int dma_done = 0;
field_num = status & FIELD_NO;
need_two = V4L2_FIELD_HAS_BOTH(dev->capfield);
if (status & INT_DMA_END_STATUS) {
dma_done = 1;
if (((field_num == 0) && (dev->field == 0)) ||
(field_num && (dev->field == 1)))
dev->field++;
}
if (status & INT_FIELD_STATUS) {
dprintk(1, "irq: field %d, done %d\n",
!!field_num, dma_done);
if (unlikely(dev->first)) {
if (field_num == 0) {
dev->first = 0;
dprintk(1, "activate first buf\n");
viu_activate_next_buf(dev, vidq);
} else
dprintk(1, "wait field 0\n");
return;
}
if (!list_empty(&vidq->active)) {
u32 addr = reg_val.field_base_addr;
if (field_num && need_two) {
addr += reg_val.dma_inc;
dprintk(1, "field 1, 0x%lx, dev field %d\n",
(unsigned long)addr, dev->field);
}
out_be32(&vr->field_base_addr, addr);
out_be32(&vr->dma_inc, reg_val.dma_inc);
out_be32(&vr->status_cfg,
(status & 0xffc0ffff) |
(status & INT_ALL_STATUS) |
reg_val.status_cfg);
return;
}
}
if (dma_done && field_num && (dev->field == 2)) {
dev->field = 0;
buf = list_entry(vidq->active.next,
struct viu_buf, vb.queue);
dprintk(1, "viu/0: [%p/%d] 0x%lx/0x%lx: dma complete\n",
buf, buf->vb.i,
(unsigned long)videobuf_to_dma_contig(&buf->vb),
(unsigned long)in_be32(&vr->field_base_addr));
if (waitqueue_active(&buf->vb.done)) {
list_del(&buf->vb.queue);
v4l2_get_timestamp(&buf->vb.ts);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
wake_up(&buf->vb.done);
}
viu_activate_next_buf(dev, vidq);
}
}
static irqreturn_t viu_intr(int irq, void *dev_id)
{
struct viu_dev *dev = (struct viu_dev *)dev_id;
struct viu_reg *vr = dev->vr;
u32 status;
u32 error;
status = in_be32(&vr->status_cfg);
if (status & INT_ERROR_STATUS) {
dev->irqs.error_irq++;
error = status & ERR_MASK;
if (error)
dprintk(1, "Err: error(%d), times:%d!\n",
error >> 4, dev->irqs.error_irq);
out_be32(&vr->status_cfg,
(status & 0xffc0ffff) | INT_ERROR_STATUS);
}
if (status & INT_DMA_END_STATUS) {
dev->irqs.dma_end_irq++;
dev->dma_done = 1;
dprintk(2, "VIU DMA end interrupt times: %d\n",
dev->irqs.dma_end_irq);
}
if (status & INT_HSYNC_STATUS)
dev->irqs.hsync_irq++;
if (status & INT_FIELD_STATUS) {
dev->irqs.field_irq++;
dprintk(2, "VIU field interrupt times: %d\n",
dev->irqs.field_irq);
}
if (status & INT_VSTART_STATUS)
dev->irqs.vstart_irq++;
if (status & INT_VSYNC_STATUS) {
dev->irqs.vsync_irq++;
dprintk(2, "VIU vsync interrupt times: %d\n",
dev->irqs.vsync_irq);
}
status = in_be32(&vr->status_cfg);
out_be32(&vr->status_cfg,
(status & 0xffc0ffff) | (status & INT_ALL_STATUS));
if (dev->ovenable) {
viu_overlay_intr(dev, status);
return IRQ_HANDLED;
}
viu_capture_intr(dev, status);
return IRQ_HANDLED;
}
static int viu_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct viu_dev *dev = video_get_drvdata(vdev);
struct viu_fh *fh;
struct viu_reg *vr;
int minor = vdev->minor;
u32 status_cfg;
dprintk(1, "viu: open (minor=%d)\n", minor);
dev->users++;
if (dev->users > 1) {
dev->users--;
return -EBUSY;
}
vr = dev->vr;
dprintk(1, "open minor=%d type=%s users=%d\n", minor,
v4l2_type_names[V4L2_BUF_TYPE_VIDEO_CAPTURE], dev->users);
if (mutex_lock_interruptible(&dev->lock)) {
dev->users--;
return -ERESTARTSYS;
}
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (!fh) {
dev->users--;
mutex_unlock(&dev->lock);
return -ENOMEM;
}
v4l2_fh_init(&fh->fh, vdev);
file->private_data = fh;
fh->dev = dev;
fh->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
fh->fmt = format_by_fourcc(V4L2_PIX_FMT_RGB32);
fh->width = norm_maxw();
fh->height = norm_maxh();
dev->crop_current.width = fh->width;
dev->crop_current.height = fh->height;
dprintk(1, "Open: fh=0x%08lx, dev=0x%08lx, dev->vidq=0x%08lx\n",
(unsigned long)fh, (unsigned long)dev,
(unsigned long)&dev->vidq);
dprintk(1, "Open: list_empty queued=%d\n",
list_empty(&dev->vidq.queued));
dprintk(1, "Open: list_empty active=%d\n",
list_empty(&dev->vidq.active));
viu_default_settings(vr);
status_cfg = in_be32(&vr->status_cfg);
out_be32(&vr->status_cfg,
status_cfg & ~(INT_VSYNC_EN | INT_HSYNC_EN |
INT_FIELD_EN | INT_VSTART_EN |
INT_DMA_END_EN | INT_ERROR_EN | INT_ECC_EN));
status_cfg = in_be32(&vr->status_cfg);
out_be32(&vr->status_cfg, status_cfg | INT_ALL_STATUS);
spin_lock_init(&fh->vbq_lock);
videobuf_queue_dma_contig_init(&fh->vb_vidq, &viu_video_qops,
dev->dev, &fh->vbq_lock,
fh->type, V4L2_FIELD_INTERLACED,
sizeof(struct viu_buf), fh,
&fh->dev->lock);
v4l2_fh_add(&fh->fh);
mutex_unlock(&dev->lock);
return 0;
}
static ssize_t viu_read(struct file *file, char __user *data, size_t count,
loff_t *ppos)
{
struct viu_fh *fh = file->private_data;
struct viu_dev *dev = fh->dev;
int ret = 0;
dprintk(2, "%s\n", __func__);
if (dev->ovenable)
dev->ovenable = 0;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
viu_start_dma(dev);
ret = videobuf_read_stream(&fh->vb_vidq, data, count,
ppos, 0, file->f_flags & O_NONBLOCK);
mutex_unlock(&dev->lock);
return ret;
}
return 0;
}
static unsigned int viu_poll(struct file *file, struct poll_table_struct *wait)
{
struct viu_fh *fh = file->private_data;
struct videobuf_queue *q = &fh->vb_vidq;
struct viu_dev *dev = fh->dev;
unsigned long req_events = poll_requested_events(wait);
unsigned int res = v4l2_ctrl_poll(file, wait);
if (V4L2_BUF_TYPE_VIDEO_CAPTURE != fh->type)
return POLLERR;
if (!(req_events & (POLLIN | POLLRDNORM)))
return res;
mutex_lock(&dev->lock);
res |= videobuf_poll_stream(file, q, wait);
mutex_unlock(&dev->lock);
return res;
}
static int viu_release(struct file *file)
{
struct viu_fh *fh = file->private_data;
struct viu_dev *dev = fh->dev;
int minor = video_devdata(file)->minor;
mutex_lock(&dev->lock);
viu_stop_dma(dev);
videobuf_stop(&fh->vb_vidq);
videobuf_mmap_free(&fh->vb_vidq);
v4l2_fh_del(&fh->fh);
v4l2_fh_exit(&fh->fh);
mutex_unlock(&dev->lock);
kfree(fh);
dev->users--;
dprintk(1, "close (minor=%d, users=%d)\n",
minor, dev->users);
return 0;
}
void viu_reset(struct viu_reg *reg)
{
out_be32(&reg->status_cfg, 0);
out_be32(&reg->luminance, 0x9512a254);
out_be32(&reg->chroma_r, 0x03310000);
out_be32(&reg->chroma_g, 0x06600f38);
out_be32(&reg->chroma_b, 0x00000409);
out_be32(&reg->field_base_addr, 0);
out_be32(&reg->dma_inc, 0);
out_be32(&reg->picture_count, 0x01e002d0);
out_be32(&reg->req_alarm, 0x00000090);
out_be32(&reg->alpha, 0x000000ff);
}
static int viu_mmap(struct file *file, struct vm_area_struct *vma)
{
struct viu_fh *fh = file->private_data;
struct viu_dev *dev = fh->dev;
int ret;
dprintk(1, "mmap called, vma=0x%08lx\n", (unsigned long)vma);
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
ret = videobuf_mmap_mapper(&fh->vb_vidq, vma);
mutex_unlock(&dev->lock);
dprintk(1, "vma start=0x%08lx, size=%ld, ret=%d\n",
(unsigned long)vma->vm_start,
(unsigned long)vma->vm_end-(unsigned long)vma->vm_start,
ret);
return ret;
}
static int viu_of_probe(struct platform_device *op)
{
struct viu_dev *viu_dev;
struct video_device *vdev;
struct resource r;
struct viu_reg __iomem *viu_regs;
struct i2c_adapter *ad;
int ret, viu_irq;
struct clk *clk;
ret = of_address_to_resource(op->dev.of_node, 0, &r);
if (ret) {
dev_err(&op->dev, "Can't parse device node resource\n");
return -ENODEV;
}
viu_irq = irq_of_parse_and_map(op->dev.of_node, 0);
if (viu_irq == NO_IRQ) {
dev_err(&op->dev, "Error while mapping the irq\n");
return -EINVAL;
}
if (!devm_request_mem_region(&op->dev, r.start,
sizeof(struct viu_reg), DRV_NAME)) {
dev_err(&op->dev, "Error while requesting mem region\n");
ret = -EBUSY;
goto err;
}
viu_regs = devm_ioremap(&op->dev, r.start, sizeof(struct viu_reg));
if (!viu_regs) {
dev_err(&op->dev, "Can't map register set\n");
ret = -ENOMEM;
goto err;
}
viu_dev = devm_kzalloc(&op->dev, sizeof(struct viu_dev), GFP_ATOMIC);
if (!viu_dev) {
dev_err(&op->dev, "Can't allocate private structure\n");
ret = -ENOMEM;
goto err;
}
viu_dev->vr = viu_regs;
viu_dev->irq = viu_irq;
viu_dev->dev = &op->dev;
INIT_LIST_HEAD(&viu_dev->vidq.active);
INIT_LIST_HEAD(&viu_dev->vidq.queued);
snprintf(viu_dev->v4l2_dev.name,
sizeof(viu_dev->v4l2_dev.name), "%s", "VIU");
ret = v4l2_device_register(viu_dev->dev, &viu_dev->v4l2_dev);
if (ret < 0) {
dev_err(&op->dev, "v4l2_device_register() failed: %d\n", ret);
goto err;
}
ad = i2c_get_adapter(0);
v4l2_ctrl_handler_init(&viu_dev->hdl, 5);
if (viu_dev->hdl.error) {
ret = viu_dev->hdl.error;
dev_err(&op->dev, "couldn't register control\n");
goto err_vdev;
}
viu_dev->v4l2_dev.ctrl_handler = &viu_dev->hdl;
viu_dev->decoder = v4l2_i2c_new_subdev(&viu_dev->v4l2_dev, ad,
"saa7113", VIU_VIDEO_DECODER_ADDR, NULL);
viu_dev->vidq.timeout.function = viu_vid_timeout;
viu_dev->vidq.timeout.data = (unsigned long)viu_dev;
init_timer(&viu_dev->vidq.timeout);
viu_dev->std = V4L2_STD_NTSC_M;
viu_dev->first = 1;
vdev = video_device_alloc();
if (vdev == NULL) {
ret = -ENOMEM;
goto err_vdev;
}
*vdev = viu_template;
vdev->v4l2_dev = &viu_dev->v4l2_dev;
viu_dev->vdev = vdev;
mutex_init(&viu_dev->lock);
viu_dev->vdev->lock = &viu_dev->lock;
spin_lock_init(&viu_dev->slock);
video_set_drvdata(viu_dev->vdev, viu_dev);
mutex_lock(&viu_dev->lock);
ret = video_register_device(viu_dev->vdev, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
video_device_release(viu_dev->vdev);
goto err_vdev;
}
clk = devm_clk_get(&op->dev, "ipg");
if (IS_ERR(clk)) {
dev_err(&op->dev, "failed to lookup the clock!\n");
ret = PTR_ERR(clk);
goto err_clk;
}
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(&op->dev, "failed to enable the clock!\n");
goto err_clk;
}
viu_dev->clk = clk;
viu_reset(viu_dev->vr);
if (request_irq(viu_dev->irq, viu_intr, 0, "viu", (void *)viu_dev)) {
dev_err(&op->dev, "Request VIU IRQ failed.\n");
ret = -ENODEV;
goto err_irq;
}
mutex_unlock(&viu_dev->lock);
dev_info(&op->dev, "Freescale VIU Video Capture Board\n");
return ret;
err_irq:
clk_disable_unprepare(viu_dev->clk);
err_clk:
video_unregister_device(viu_dev->vdev);
err_vdev:
v4l2_ctrl_handler_free(&viu_dev->hdl);
mutex_unlock(&viu_dev->lock);
i2c_put_adapter(ad);
v4l2_device_unregister(&viu_dev->v4l2_dev);
err:
irq_dispose_mapping(viu_irq);
return ret;
}
static int viu_of_remove(struct platform_device *op)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&op->dev);
struct viu_dev *dev = container_of(v4l2_dev, struct viu_dev, v4l2_dev);
struct v4l2_subdev *sdev = list_entry(v4l2_dev->subdevs.next,
struct v4l2_subdev, list);
struct i2c_client *client = v4l2_get_subdevdata(sdev);
free_irq(dev->irq, (void *)dev);
irq_dispose_mapping(dev->irq);
clk_disable_unprepare(dev->clk);
v4l2_ctrl_handler_free(&dev->hdl);
video_unregister_device(dev->vdev);
i2c_put_adapter(client->adapter);
v4l2_device_unregister(&dev->v4l2_dev);
return 0;
}
static int viu_suspend(struct platform_device *op, pm_message_t state)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&op->dev);
struct viu_dev *dev = container_of(v4l2_dev, struct viu_dev, v4l2_dev);
clk_disable(dev->clk);
return 0;
}
static int viu_resume(struct platform_device *op)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&op->dev);
struct viu_dev *dev = container_of(v4l2_dev, struct viu_dev, v4l2_dev);
clk_enable(dev->clk);
return 0;
}
