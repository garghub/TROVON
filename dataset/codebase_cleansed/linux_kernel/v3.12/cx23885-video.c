static struct cx23885_fmt *format_by_fourcc(unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fourcc)
return formats+i;
printk(KERN_ERR "%s(%c%c%c%c) NOT FOUND\n", __func__,
(fourcc & 0xff),
((fourcc >> 8) & 0xff),
((fourcc >> 16) & 0xff),
((fourcc >> 24) & 0xff)
);
return NULL;
}
void cx23885_video_wakeup(struct cx23885_dev *dev,
struct cx23885_dmaqueue *q, u32 count)
{
struct cx23885_buffer *buf;
int bc;
for (bc = 0;; bc++) {
if (list_empty(&q->active))
break;
buf = list_entry(q->active.next,
struct cx23885_buffer, vb.queue);
if ((s16) (count - buf->count) < 0)
break;
v4l2_get_timestamp(&buf->vb.ts);
dprintk(2, "[%p/%d] wakeup reg=%d buf=%d\n", buf, buf->vb.i,
count, buf->count);
buf->vb.state = VIDEOBUF_DONE;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
if (list_empty(&q->active))
del_timer(&q->timeout);
else
mod_timer(&q->timeout, jiffies+BUFFER_TIMEOUT);
if (bc != 1)
printk(KERN_ERR "%s: %d buffers handled (should be 1)\n",
__func__, bc);
}
int cx23885_set_tvnorm(struct cx23885_dev *dev, v4l2_std_id norm)
{
dprintk(1, "%s(norm = 0x%08x) name: [%s]\n",
__func__,
(unsigned int)norm,
v4l2_norm_to_name(norm));
dev->tvnorm = norm;
call_all(dev, core, s_std, norm);
return 0;
}
static struct video_device *cx23885_vdev_init(struct cx23885_dev *dev,
struct pci_dev *pci,
struct video_device *template,
char *type)
{
struct video_device *vfd;
dprintk(1, "%s()\n", __func__);
vfd = video_device_alloc();
if (NULL == vfd)
return NULL;
*vfd = *template;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->release = video_device_release;
snprintf(vfd->name, sizeof(vfd->name), "%s (%s)",
cx23885_boards[dev->board].name, type);
video_set_drvdata(vfd, dev);
return vfd;
}
static int cx23885_ctrl_query(struct v4l2_queryctrl *qctrl)
{
int i;
if (qctrl->id < V4L2_CID_BASE ||
qctrl->id >= V4L2_CID_LASTP1)
return -EINVAL;
for (i = 0; i < CX23885_CTLS; i++)
if (cx23885_ctls[i].v.id == qctrl->id)
break;
if (i == CX23885_CTLS) {
*qctrl = no_ctl;
return 0;
}
*qctrl = cx23885_ctls[i].v;
return 0;
}
static int res_get(struct cx23885_dev *dev, struct cx23885_fh *fh,
unsigned int bit)
{
dprintk(1, "%s()\n", __func__);
if (fh->resources & bit)
return 1;
mutex_lock(&dev->lock);
if (dev->resources & bit) {
mutex_unlock(&dev->lock);
return 0;
}
fh->resources |= bit;
dev->resources |= bit;
dprintk(1, "res: get %d\n", bit);
mutex_unlock(&dev->lock);
return 1;
}
static int res_check(struct cx23885_fh *fh, unsigned int bit)
{
return fh->resources & bit;
}
static int res_locked(struct cx23885_dev *dev, unsigned int bit)
{
return dev->resources & bit;
}
static void res_free(struct cx23885_dev *dev, struct cx23885_fh *fh,
unsigned int bits)
{
BUG_ON((fh->resources & bits) != bits);
dprintk(1, "%s()\n", __func__);
mutex_lock(&dev->lock);
fh->resources &= ~bits;
dev->resources &= ~bits;
dprintk(1, "res: put %d\n", bits);
mutex_unlock(&dev->lock);
}
int cx23885_flatiron_write(struct cx23885_dev *dev, u8 reg, u8 data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = { .addr = 0x98 >> 1,
.flags = 0, .buf = buf, .len = 2 };
return i2c_transfer(&dev->i2c_bus[2].i2c_adap, &msg, 1);
}
u8 cx23885_flatiron_read(struct cx23885_dev *dev, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{ .addr = 0x98 >> 1, .flags = 0, .buf = b0, .len = 1 },
{ .addr = 0x98 >> 1, .flags = I2C_M_RD, .buf = b1, .len = 1 }
};
ret = i2c_transfer(&dev->i2c_bus[2].i2c_adap, &msg[0], 2);
if (ret != 2)
printk(KERN_ERR "%s() error\n", __func__);
return b1[0];
}
static void cx23885_flatiron_dump(struct cx23885_dev *dev)
{
int i;
dprintk(1, "Flatiron dump\n");
for (i = 0; i < 0x24; i++) {
dprintk(1, "FI[%02x] = %02x\n", i,
cx23885_flatiron_read(dev, i));
}
}
static int cx23885_flatiron_mux(struct cx23885_dev *dev, int input)
{
u8 val;
dprintk(1, "%s(input = %d)\n", __func__, input);
if (input == 1)
val = cx23885_flatiron_read(dev, CH_PWR_CTRL1) & ~FLD_CH_SEL;
else if (input == 2)
val = cx23885_flatiron_read(dev, CH_PWR_CTRL1) | FLD_CH_SEL;
else
return -EINVAL;
val |= 0x20;
cx23885_flatiron_write(dev, CH_PWR_CTRL1, val);
cx23885_flatiron_write(dev, CH_PWR_CTRL2, 0);
if (video_debug)
cx23885_flatiron_dump(dev);
return 0;
}
static int cx23885_video_mux(struct cx23885_dev *dev, unsigned int input)
{
dprintk(1, "%s() video_mux: %d [vmux=%d, gpio=0x%x,0x%x,0x%x,0x%x]\n",
__func__,
input, INPUT(input)->vmux,
INPUT(input)->gpio0, INPUT(input)->gpio1,
INPUT(input)->gpio2, INPUT(input)->gpio3);
dev->input = input;
if (dev->board == CX23885_BOARD_MYGICA_X8506 ||
dev->board == CX23885_BOARD_MAGICPRO_PROHDTVE2 ||
dev->board == CX23885_BOARD_MYGICA_X8507) {
if (INPUT(input)->type == CX23885_VMUX_TELEVISION)
cx23885_gpio_clear(dev, GPIO_0);
}
v4l2_subdev_call(dev->sd_cx25840, video, s_routing,
INPUT(input)->vmux, 0, 0);
if ((dev->board == CX23885_BOARD_HAUPPAUGE_HVR1800) ||
(dev->board == CX23885_BOARD_MPX885) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1250) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1255) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1255_22111) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1850) ||
(dev->board == CX23885_BOARD_MYGICA_X8507) ||
(dev->board == CX23885_BOARD_AVERMEDIA_HC81R)) {
v4l2_subdev_call(dev->sd_cx25840, audio, s_routing,
INPUT(input)->amux, 0, 0);
if (INPUT(input)->amux == CX25840_AUDIO7)
cx23885_flatiron_mux(dev, 1);
else if (INPUT(input)->amux == CX25840_AUDIO6)
cx23885_flatiron_mux(dev, 2);
}
return 0;
}
static int cx23885_audio_mux(struct cx23885_dev *dev, unsigned int input)
{
dprintk(1, "%s(input=%d)\n", __func__, input);
if (INPUT(input)->amux == CX25840_AUDIO7)
cx23885_flatiron_mux(dev, 1);
else if (INPUT(input)->amux == CX25840_AUDIO6)
cx23885_flatiron_mux(dev, 2);
else {
cx23885_flatiron_mux(dev, 1);
}
return 0;
}
static int cx23885_start_video_dma(struct cx23885_dev *dev,
struct cx23885_dmaqueue *q,
struct cx23885_buffer *buf)
{
dprintk(1, "%s()\n", __func__);
cx_clear(VID_A_DMA_CTL, 0x11);
cx23885_sram_channel_setup(dev, &dev->sram_channels[SRAM_CH01],
buf->bpl, buf->risc.dma);
cx_write(VID_A_GPCNT_CTL, 3);
q->count = 1;
cx23885_irq_add_enable(dev, 0x01);
cx_set(VID_A_INT_MSK, 0x000011);
cx_set(DEV_CNTRL2, (1<<5));
cx_set(VID_A_DMA_CTL, 0x11);
return 0;
}
static int cx23885_restart_video_queue(struct cx23885_dev *dev,
struct cx23885_dmaqueue *q)
{
struct cx23885_buffer *buf, *prev;
struct list_head *item;
dprintk(1, "%s()\n", __func__);
if (!list_empty(&q->active)) {
buf = list_entry(q->active.next, struct cx23885_buffer,
vb.queue);
dprintk(2, "restart_queue [%p/%d]: restart dma\n",
buf, buf->vb.i);
cx23885_start_video_dma(dev, q, buf);
list_for_each(item, &q->active) {
buf = list_entry(item, struct cx23885_buffer,
vb.queue);
buf->count = q->count++;
}
mod_timer(&q->timeout, jiffies+BUFFER_TIMEOUT);
return 0;
}
prev = NULL;
for (;;) {
if (list_empty(&q->queued))
return 0;
buf = list_entry(q->queued.next, struct cx23885_buffer,
vb.queue);
if (NULL == prev) {
list_move_tail(&buf->vb.queue, &q->active);
cx23885_start_video_dma(dev, q, buf);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
mod_timer(&q->timeout, jiffies+BUFFER_TIMEOUT);
dprintk(2, "[%p/%d] restart_queue - first active\n",
buf, buf->vb.i);
} else if (prev->vb.width == buf->vb.width &&
prev->vb.height == buf->vb.height &&
prev->fmt == buf->fmt) {
list_move_tail(&buf->vb.queue, &q->active);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
prev->risc.jmp[2] = cpu_to_le32(0);
dprintk(2, "[%p/%d] restart_queue - move to active\n",
buf, buf->vb.i);
} else {
return 0;
}
prev = buf;
}
}
static int buffer_setup(struct videobuf_queue *q, unsigned int *count,
unsigned int *size)
{
struct cx23885_fh *fh = q->priv_data;
*size = fh->fmt->depth*fh->width*fh->height >> 3;
if (0 == *count)
*count = 32;
if (*size * *count > vid_limit * 1024 * 1024)
*count = (vid_limit * 1024 * 1024) / *size;
return 0;
}
static int buffer_prepare(struct videobuf_queue *q, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct cx23885_fh *fh = q->priv_data;
struct cx23885_dev *dev = fh->dev;
struct cx23885_buffer *buf =
container_of(vb, struct cx23885_buffer, vb);
int rc, init_buffer = 0;
u32 line0_offset, line1_offset;
struct videobuf_dmabuf *dma = videobuf_to_dma(&buf->vb);
int field_tff;
BUG_ON(NULL == fh->fmt);
if (fh->width < 48 || fh->width > norm_maxw(dev->tvnorm) ||
fh->height < 32 || fh->height > norm_maxh(dev->tvnorm))
return -EINVAL;
buf->vb.size = (fh->width * fh->height * fh->fmt->depth) >> 3;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
if (buf->fmt != fh->fmt ||
buf->vb.width != fh->width ||
buf->vb.height != fh->height ||
buf->vb.field != field) {
buf->fmt = fh->fmt;
buf->vb.width = fh->width;
buf->vb.height = fh->height;
buf->vb.field = field;
init_buffer = 1;
}
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
init_buffer = 1;
rc = videobuf_iolock(q, &buf->vb, NULL);
if (0 != rc)
goto fail;
}
if (init_buffer) {
buf->bpl = buf->vb.width * buf->fmt->depth >> 3;
switch (buf->vb.field) {
case V4L2_FIELD_TOP:
cx23885_risc_buffer(dev->pci, &buf->risc,
dma->sglist, 0, UNSET,
buf->bpl, 0, buf->vb.height);
break;
case V4L2_FIELD_BOTTOM:
cx23885_risc_buffer(dev->pci, &buf->risc,
dma->sglist, UNSET, 0,
buf->bpl, 0, buf->vb.height);
break;
case V4L2_FIELD_INTERLACED:
if (dev->tvnorm & V4L2_STD_NTSC)
field_tff = 1;
else
field_tff = 0;
if (cx23885_boards[dev->board].force_bff)
field_tff = 0;
if (field_tff) {
dprintk(1, "%s() Creating TFF/NTSC risc\n",
__func__);
line0_offset = buf->bpl;
line1_offset = 0;
} else {
dprintk(1, "%s() Creating BFF/PAL/SECAM risc\n",
__func__);
line0_offset = 0;
line1_offset = buf->bpl;
}
cx23885_risc_buffer(dev->pci, &buf->risc,
dma->sglist, line0_offset,
line1_offset,
buf->bpl, buf->bpl,
buf->vb.height >> 1);
break;
case V4L2_FIELD_SEQ_TB:
cx23885_risc_buffer(dev->pci, &buf->risc,
dma->sglist,
0, buf->bpl * (buf->vb.height >> 1),
buf->bpl, 0,
buf->vb.height >> 1);
break;
case V4L2_FIELD_SEQ_BT:
cx23885_risc_buffer(dev->pci, &buf->risc,
dma->sglist,
buf->bpl * (buf->vb.height >> 1), 0,
buf->bpl, 0,
buf->vb.height >> 1);
break;
default:
BUG();
}
}
dprintk(2, "[%p/%d] buffer_prep - %dx%d %dbpp \"%s\" - dma=0x%08lx\n",
buf, buf->vb.i,
fh->width, fh->height, fh->fmt->depth, fh->fmt->name,
(unsigned long)buf->risc.dma);
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
cx23885_free_buffer(q, buf);
return rc;
}
static void buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct cx23885_buffer *buf = container_of(vb,
struct cx23885_buffer, vb);
struct cx23885_buffer *prev;
struct cx23885_fh *fh = vq->priv_data;
struct cx23885_dev *dev = fh->dev;
struct cx23885_dmaqueue *q = &dev->vidq;
buf->risc.jmp[0] = cpu_to_le32(RISC_JUMP | RISC_IRQ1 | RISC_CNT_INC);
buf->risc.jmp[1] = cpu_to_le32(q->stopper.dma);
buf->risc.jmp[2] = cpu_to_le32(0);
if (!list_empty(&q->queued)) {
list_add_tail(&buf->vb.queue, &q->queued);
buf->vb.state = VIDEOBUF_QUEUED;
dprintk(2, "[%p/%d] buffer_queue - append to queued\n",
buf, buf->vb.i);
} else if (list_empty(&q->active)) {
list_add_tail(&buf->vb.queue, &q->active);
cx23885_start_video_dma(dev, q, buf);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
mod_timer(&q->timeout, jiffies+BUFFER_TIMEOUT);
dprintk(2, "[%p/%d] buffer_queue - first active\n",
buf, buf->vb.i);
} else {
prev = list_entry(q->active.prev, struct cx23885_buffer,
vb.queue);
if (prev->vb.width == buf->vb.width &&
prev->vb.height == buf->vb.height &&
prev->fmt == buf->fmt) {
list_add_tail(&buf->vb.queue, &q->active);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->count = q->count++;
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
prev->risc.jmp[2] = cpu_to_le32(0);
dprintk(2, "[%p/%d] buffer_queue - append to active\n",
buf, buf->vb.i);
} else {
list_add_tail(&buf->vb.queue, &q->queued);
buf->vb.state = VIDEOBUF_QUEUED;
dprintk(2, "[%p/%d] buffer_queue - first queued\n",
buf, buf->vb.i);
}
}
}
static void buffer_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct cx23885_buffer *buf = container_of(vb,
struct cx23885_buffer, vb);
cx23885_free_buffer(q, buf);
}
static struct videobuf_queue *get_queue(struct cx23885_fh *fh)
{
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return &fh->vidq;
case V4L2_BUF_TYPE_VBI_CAPTURE:
return &fh->vbiq;
default:
BUG();
return NULL;
}
}
static int get_resource(struct cx23885_fh *fh)
{
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return RESOURCE_VIDEO;
case V4L2_BUF_TYPE_VBI_CAPTURE:
return RESOURCE_VBI;
default:
BUG();
return 0;
}
}
static int video_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct cx23885_dev *dev = video_drvdata(file);
struct cx23885_fh *fh;
enum v4l2_buf_type type = 0;
int radio = 0;
switch (vdev->vfl_type) {
case VFL_TYPE_GRABBER:
type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
type = V4L2_BUF_TYPE_VBI_CAPTURE;
break;
case VFL_TYPE_RADIO:
radio = 1;
break;
}
dprintk(1, "open dev=%s radio=%d type=%s\n",
video_device_node_name(vdev), radio, v4l2_type_names[type]);
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (NULL == fh)
return -ENOMEM;
file->private_data = fh;
fh->dev = dev;
fh->radio = radio;
fh->type = type;
fh->width = 320;
fh->height = 240;
fh->fmt = format_by_fourcc(V4L2_PIX_FMT_YUYV);
videobuf_queue_sg_init(&fh->vidq, &cx23885_video_qops,
&dev->pci->dev, &dev->slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_INTERLACED,
sizeof(struct cx23885_buffer),
fh, NULL);
videobuf_queue_sg_init(&fh->vbiq, &cx23885_vbi_qops,
&dev->pci->dev, &dev->slock,
V4L2_BUF_TYPE_VBI_CAPTURE,
V4L2_FIELD_SEQ_TB,
sizeof(struct cx23885_buffer),
fh, NULL);
dprintk(1, "post videobuf_queue_init()\n");
return 0;
}
static ssize_t video_read(struct file *file, char __user *data,
size_t count, loff_t *ppos)
{
struct cx23885_fh *fh = file->private_data;
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
if (res_locked(fh->dev, RESOURCE_VIDEO))
return -EBUSY;
return videobuf_read_one(&fh->vidq, data, count, ppos,
file->f_flags & O_NONBLOCK);
case V4L2_BUF_TYPE_VBI_CAPTURE:
if (!res_get(fh->dev, fh, RESOURCE_VBI))
return -EBUSY;
return videobuf_read_stream(&fh->vbiq, data, count, ppos, 1,
file->f_flags & O_NONBLOCK);
default:
BUG();
return 0;
}
}
static unsigned int video_poll(struct file *file,
struct poll_table_struct *wait)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_buffer *buf;
unsigned int rc = POLLERR;
if (V4L2_BUF_TYPE_VBI_CAPTURE == fh->type) {
if (!res_get(fh->dev, fh, RESOURCE_VBI))
return POLLERR;
return videobuf_poll_stream(file, &fh->vbiq, wait);
}
mutex_lock(&fh->vidq.vb_lock);
if (res_check(fh, RESOURCE_VIDEO)) {
if (list_empty(&fh->vidq.stream))
goto done;
buf = list_entry(fh->vidq.stream.next,
struct cx23885_buffer, vb.stream);
} else {
buf = (struct cx23885_buffer *)fh->vidq.read_buf;
if (NULL == buf)
goto done;
}
poll_wait(file, &buf->vb.done, wait);
if (buf->vb.state == VIDEOBUF_DONE ||
buf->vb.state == VIDEOBUF_ERROR)
rc = POLLIN|POLLRDNORM;
else
rc = 0;
done:
mutex_unlock(&fh->vidq.vb_lock);
return rc;
}
static int video_release(struct file *file)
{
struct cx23885_fh *fh = file->private_data;
struct cx23885_dev *dev = fh->dev;
if (res_check(fh, RESOURCE_OVERLAY)) {
res_free(dev, fh, RESOURCE_OVERLAY);
}
if (res_check(fh, RESOURCE_VIDEO)) {
videobuf_queue_cancel(&fh->vidq);
res_free(dev, fh, RESOURCE_VIDEO);
}
if (fh->vidq.read_buf) {
buffer_release(&fh->vidq, fh->vidq.read_buf);
kfree(fh->vidq.read_buf);
}
if (res_check(fh, RESOURCE_VBI)) {
if (fh->vbiq.streaming)
videobuf_streamoff(&fh->vbiq);
if (fh->vbiq.reading)
videobuf_read_stop(&fh->vbiq);
res_free(dev, fh, RESOURCE_VBI);
}
videobuf_mmap_free(&fh->vidq);
videobuf_mmap_free(&fh->vbiq);
file->private_data = NULL;
kfree(fh);
return 0;
}
static int video_mmap(struct file *file, struct vm_area_struct *vma)
{
struct cx23885_fh *fh = file->private_data;
return videobuf_mmap_mapper(get_queue(fh), vma);
}
int cx23885_get_control(struct cx23885_dev *dev,
struct v4l2_control *ctl)
{
dprintk(1, "%s() calling cx25840(VIDIOC_G_CTRL)\n", __func__);
call_all(dev, core, g_ctrl, ctl);
return 0;
}
int cx23885_set_control(struct cx23885_dev *dev,
struct v4l2_control *ctl)
{
dprintk(1, "%s() calling cx25840(VIDIOC_S_CTRL)\n", __func__);
call_all(dev, core, s_ctrl, ctl);
return 0;
}
static void init_controls(struct cx23885_dev *dev)
{
struct v4l2_control ctrl;
int i;
for (i = 0; i < CX23885_CTLS; i++) {
ctrl.id = cx23885_ctls[i].v.id;
ctrl.value = cx23885_ctls[i].v.default_value;
cx23885_set_control(dev, &ctrl);
}
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_fh *fh = priv;
f->fmt.pix.width = fh->width;
f->fmt.pix.height = fh->height;
f->fmt.pix.field = fh->vidq.field;
f->fmt.pix.pixelformat = fh->fmt->fourcc;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fh->fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
struct cx23885_fmt *fmt;
enum v4l2_field field;
unsigned int maxw, maxh;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (NULL == fmt)
return -EINVAL;
field = f->fmt.pix.field;
maxw = norm_maxw(dev->tvnorm);
maxh = norm_maxh(dev->tvnorm);
if (V4L2_FIELD_ANY == field) {
field = (f->fmt.pix.height > maxh/2)
? V4L2_FIELD_INTERLACED
: V4L2_FIELD_BOTTOM;
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
f->fmt.pix.field = field;
v4l_bound_align_image(&f->fmt.pix.width, 48, maxw, 2,
&f->fmt.pix.height, 32, maxh, 0, 0);
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
struct v4l2_mbus_framefmt mbus_fmt;
int err;
dprintk(2, "%s()\n", __func__);
err = vidioc_try_fmt_vid_cap(file, priv, f);
if (0 != err)
return err;
fh->fmt = format_by_fourcc(f->fmt.pix.pixelformat);
fh->width = f->fmt.pix.width;
fh->height = f->fmt.pix.height;
fh->vidq.field = f->fmt.pix.field;
dprintk(2, "%s() width=%d height=%d field=%d\n", __func__,
fh->width, fh->height, fh->vidq.field);
v4l2_fill_mbus_format(&mbus_fmt, &f->fmt.pix, V4L2_MBUS_FMT_FIXED);
call_all(dev, video, s_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
strcpy(cap->driver, "cx23885");
strlcpy(cap->card, cx23885_boards[dev->board].name,
sizeof(cap->card));
sprintf(cap->bus_info, "PCIe:%s", pci_name(dev->pci));
cap->capabilities =
V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING |
V4L2_CAP_VBI_CAPTURE;
if (UNSET != dev->tuner_type)
cap->capabilities |= V4L2_CAP_TUNER;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (unlikely(f->index >= ARRAY_SIZE(formats)))
return -EINVAL;
strlcpy(f->description, formats[f->index].name,
sizeof(f->description));
f->pixelformat = formats[f->index].fourcc;
return 0;
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct cx23885_fh *fh = priv;
return videobuf_reqbufs(get_queue(fh), p);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx23885_fh *fh = priv;
return videobuf_querybuf(get_queue(fh), p);
}
static int vidioc_qbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx23885_fh *fh = priv;
return videobuf_qbuf(get_queue(fh), p);
}
static int vidioc_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct cx23885_fh *fh = priv;
return videobuf_dqbuf(get_queue(fh), p,
file->f_flags & O_NONBLOCK);
}
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type i)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
dprintk(1, "%s()\n", __func__);
if ((fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) &&
(fh->type != V4L2_BUF_TYPE_VBI_CAPTURE))
return -EINVAL;
if (unlikely(i != fh->type))
return -EINVAL;
if (unlikely(!res_get(dev, fh, get_resource(fh))))
return -EBUSY;
if ((fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) &&
((cx_read(VID_A_DMA_CTL) & 0x11) == 0))
return -EINVAL;
return videobuf_streamon(get_queue(fh));
}
static int vidioc_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
int err, res;
dprintk(1, "%s()\n", __func__);
if ((fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) &&
(fh->type != V4L2_BUF_TYPE_VBI_CAPTURE))
return -EINVAL;
if (i != fh->type)
return -EINVAL;
res = get_resource(fh);
err = videobuf_streamoff(get_queue(fh));
if (err < 0)
return err;
res_free(dev, fh, res);
return 0;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
dprintk(1, "%s()\n", __func__);
*id = dev->tvnorm;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id tvnorms)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
dprintk(1, "%s()\n", __func__);
mutex_lock(&dev->lock);
cx23885_set_tvnorm(dev, tvnorms);
mutex_unlock(&dev->lock);
return 0;
}
int cx23885_enum_input(struct cx23885_dev *dev, struct v4l2_input *i)
{
static const char *iname[] = {
[CX23885_VMUX_COMPOSITE1] = "Composite1",
[CX23885_VMUX_COMPOSITE2] = "Composite2",
[CX23885_VMUX_COMPOSITE3] = "Composite3",
[CX23885_VMUX_COMPOSITE4] = "Composite4",
[CX23885_VMUX_SVIDEO] = "S-Video",
[CX23885_VMUX_COMPONENT] = "Component",
[CX23885_VMUX_TELEVISION] = "Television",
[CX23885_VMUX_CABLE] = "Cable TV",
[CX23885_VMUX_DVB] = "DVB",
[CX23885_VMUX_DEBUG] = "for debug only",
};
unsigned int n;
dprintk(1, "%s()\n", __func__);
n = i->index;
if (n >= MAX_CX23885_INPUT)
return -EINVAL;
if (0 == INPUT(n)->type)
return -EINVAL;
i->index = n;
i->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(i->name, iname[INPUT(n)->type]);
if ((CX23885_VMUX_TELEVISION == INPUT(n)->type) ||
(CX23885_VMUX_CABLE == INPUT(n)->type)) {
i->type = V4L2_INPUT_TYPE_TUNER;
i->std = CX23885_NORMS;
}
if (INPUT(n)->type != CX23885_VMUX_TELEVISION)
i->audioset = 0x3;
if (dev->input == n) {
call_all(dev, video, g_input_status, &i->status);
}
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
dprintk(1, "%s()\n", __func__);
return cx23885_enum_input(dev, i);
}
int cx23885_get_input(struct file *file, void *priv, unsigned int *i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
*i = dev->input;
dprintk(1, "%s() returns %d\n", __func__, *i);
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
return cx23885_get_input(file, priv, i);
}
int cx23885_set_input(struct file *file, void *priv, unsigned int i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
dprintk(1, "%s(%d)\n", __func__, i);
if (i >= MAX_CX23885_INPUT) {
dprintk(1, "%s() -EINVAL\n", __func__);
return -EINVAL;
}
if (INPUT(i)->type == 0)
return -EINVAL;
mutex_lock(&dev->lock);
cx23885_video_mux(dev, i);
cx23885_audio_mux(dev, i);
mutex_unlock(&dev->lock);
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
return cx23885_set_input(file, priv, i);
}
static int vidioc_log_status(struct file *file, void *priv)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
printk(KERN_INFO
"%s/0: ============ START LOG STATUS ============\n",
dev->name);
call_all(dev, core, log_status);
printk(KERN_INFO
"%s/0: ============= END LOG STATUS =============\n",
dev->name);
return 0;
}
static int cx23885_query_audinput(struct file *file, void *priv,
struct v4l2_audio *i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
static const char *iname[] = {
[0] = "Baseband L/R 1",
[1] = "Baseband L/R 2",
};
unsigned int n;
dprintk(1, "%s()\n", __func__);
n = i->index;
if (n >= 2)
return -EINVAL;
memset(i, 0, sizeof(*i));
i->index = n;
strcpy(i->name, iname[n]);
i->capability = V4L2_AUDCAP_STEREO;
i->mode = V4L2_AUDMODE_AVL;
return 0;
}
static int vidioc_enum_audinput(struct file *file, void *priv,
struct v4l2_audio *i)
{
return cx23885_query_audinput(file, priv, i);
}
static int vidioc_g_audinput(struct file *file, void *priv,
struct v4l2_audio *i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
i->index = dev->audinput;
dprintk(1, "%s(input=%d)\n", __func__, i->index);
return cx23885_query_audinput(file, priv, i);
}
static int vidioc_s_audinput(struct file *file, void *priv,
const struct v4l2_audio *i)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
if (i->index >= 2)
return -EINVAL;
dprintk(1, "%s(%d)\n", __func__, i->index);
dev->audinput = i->index;
cx23885_flatiron_mux(dev, dev->audinput + 1);
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qctrl)
{
qctrl->id = v4l2_ctrl_next(ctrl_classes, qctrl->id);
if (unlikely(qctrl->id == 0))
return -EINVAL;
return cx23885_ctrl_query(qctrl);
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctl)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
return cx23885_get_control(dev, ctl);
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctl)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
return cx23885_set_control(dev, ctl);
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
if (unlikely(UNSET == dev->tuner_type))
return -EINVAL;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Television");
call_all(dev, tuner, g_tuner, t);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)priv)->dev;
if (UNSET == dev->tuner_type)
return -EINVAL;
if (0 != t->index)
return -EINVAL;
call_all(dev, tuner, s_tuner, t);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
if (unlikely(UNSET == dev->tuner_type))
return -EINVAL;
f->type = fh->radio ? V4L2_TUNER_RADIO : V4L2_TUNER_ANALOG_TV;
f->frequency = dev->freq;
call_all(dev, tuner, g_frequency, f);
return 0;
}
static int cx23885_set_freq(struct cx23885_dev *dev, const struct v4l2_frequency *f)
{
struct v4l2_control ctrl;
if (unlikely(UNSET == dev->tuner_type))
return -EINVAL;
if (unlikely(f->tuner != 0))
return -EINVAL;
mutex_lock(&dev->lock);
dev->freq = f->frequency;
ctrl.id = V4L2_CID_AUDIO_MUTE;
ctrl.value = 1;
cx23885_set_control(dev, &ctrl);
call_all(dev, tuner, s_frequency, f);
msleep(100);
ctrl.value = 0;
cx23885_set_control(dev, &ctrl);
mutex_unlock(&dev->lock);
return 0;
}
static int cx23885_set_freq_via_ops(struct cx23885_dev *dev,
const struct v4l2_frequency *f)
{
struct v4l2_control ctrl;
struct videobuf_dvb_frontend *vfe;
struct dvb_frontend *fe;
struct analog_parameters params = {
.mode = V4L2_TUNER_ANALOG_TV,
.audmode = V4L2_TUNER_MODE_STEREO,
.std = dev->tvnorm,
.frequency = f->frequency
};
mutex_lock(&dev->lock);
dev->freq = f->frequency;
ctrl.id = V4L2_CID_AUDIO_MUTE;
ctrl.value = 1;
cx23885_set_control(dev, &ctrl);
dprintk(1, "%s() frequency=%d tuner=%d std=0x%llx\n", __func__,
params.frequency, f->tuner, params.std);
vfe = videobuf_dvb_get_frontend(&dev->ts2.frontends, 1);
if (!vfe) {
mutex_unlock(&dev->lock);
return -EINVAL;
}
fe = vfe->dvb.frontend;
if ((dev->board == CX23885_BOARD_HAUPPAUGE_HVR1850) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1255) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1255_22111))
fe = &dev->ts1.analog_fe;
if (fe && fe->ops.tuner_ops.set_analog_params) {
call_all(dev, core, s_std, dev->tvnorm);
fe->ops.tuner_ops.set_analog_params(fe, &params);
}
else
printk(KERN_ERR "%s() No analog tuner, aborting\n", __func__);
msleep(100);
ctrl.value = 0;
cx23885_set_control(dev, &ctrl);
mutex_unlock(&dev->lock);
return 0;
}
int cx23885_set_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct cx23885_fh *fh = priv;
struct cx23885_dev *dev = fh->dev;
int ret;
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
ret = cx23885_set_freq_via_ops(dev, f);
break;
default:
ret = cx23885_set_freq(dev, f);
}
return ret;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
return cx23885_set_frequency(file, priv, f);
}
static void cx23885_vid_timeout(unsigned long data)
{
struct cx23885_dev *dev = (struct cx23885_dev *)data;
struct cx23885_dmaqueue *q = &dev->vidq;
struct cx23885_buffer *buf;
unsigned long flags;
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&q->active)) {
buf = list_entry(q->active.next,
struct cx23885_buffer, vb.queue);
list_del(&buf->vb.queue);
buf->vb.state = VIDEOBUF_ERROR;
wake_up(&buf->vb.done);
printk(KERN_ERR "%s: [%p/%d] timeout - dma=0x%08lx\n",
dev->name, buf, buf->vb.i,
(unsigned long)buf->risc.dma);
}
cx23885_restart_video_queue(dev, q);
spin_unlock_irqrestore(&dev->slock, flags);
}
int cx23885_video_irq(struct cx23885_dev *dev, u32 status)
{
u32 mask, count;
int handled = 0;
mask = cx_read(VID_A_INT_MSK);
if (0 == (status & mask))
return handled;
cx_write(VID_A_INT_STAT, status);
if ((status & VID_BC_MSK_OPC_ERR) ||
(status & VID_BC_MSK_SYNC) ||
(status & VID_BC_MSK_OF)) {
if (status & VID_BC_MSK_OPC_ERR) {
dprintk(7, " (VID_BC_MSK_OPC_ERR 0x%08x)\n",
VID_BC_MSK_OPC_ERR);
printk(KERN_WARNING "%s: video risc op code error\n",
dev->name);
cx23885_sram_channel_dump(dev,
&dev->sram_channels[SRAM_CH01]);
}
if (status & VID_BC_MSK_SYNC)
dprintk(7, " (VID_BC_MSK_SYNC 0x%08x) "
"video lines miss-match\n",
VID_BC_MSK_SYNC);
if (status & VID_BC_MSK_OF)
dprintk(7, " (VID_BC_MSK_OF 0x%08x) fifo overflow\n",
VID_BC_MSK_OF);
}
if (status & VID_BC_MSK_RISCI1) {
spin_lock(&dev->slock);
count = cx_read(VID_A_GPCNT);
cx23885_video_wakeup(dev, &dev->vidq, count);
spin_unlock(&dev->slock);
handled++;
}
if (status & VID_BC_MSK_RISCI2) {
dprintk(2, "stopper video\n");
spin_lock(&dev->slock);
cx23885_restart_video_queue(dev, &dev->vidq);
spin_unlock(&dev->slock);
handled++;
}
handled += cx23885_vbi_irq(dev, status);
return handled;
}
void cx23885_video_unregister(struct cx23885_dev *dev)
{
dprintk(1, "%s()\n", __func__);
cx23885_irq_remove(dev, 0x01);
if (dev->vbi_dev) {
if (video_is_registered(dev->vbi_dev))
video_unregister_device(dev->vbi_dev);
else
video_device_release(dev->vbi_dev);
dev->vbi_dev = NULL;
btcx_riscmem_free(dev->pci, &dev->vbiq.stopper);
}
if (dev->video_dev) {
if (video_is_registered(dev->video_dev))
video_unregister_device(dev->video_dev);
else
video_device_release(dev->video_dev);
dev->video_dev = NULL;
btcx_riscmem_free(dev->pci, &dev->vidq.stopper);
}
if (dev->audio_dev)
cx23885_audio_unregister(dev);
}
int cx23885_video_register(struct cx23885_dev *dev)
{
int err;
dprintk(1, "%s()\n", __func__);
spin_lock_init(&dev->slock);
cx23885_vbi_template = cx23885_video_template;
strcpy(cx23885_vbi_template.name, "cx23885-vbi");
dev->tvnorm = V4L2_STD_NTSC_M;
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vidq.queued);
dev->vidq.timeout.function = cx23885_vid_timeout;
dev->vidq.timeout.data = (unsigned long)dev;
init_timer(&dev->vidq.timeout);
cx23885_risc_stopper(dev->pci, &dev->vidq.stopper,
VID_A_DMA_CTL, 0x11, 0x00);
INIT_LIST_HEAD(&dev->vbiq.active);
INIT_LIST_HEAD(&dev->vbiq.queued);
dev->vbiq.timeout.function = cx23885_vbi_timeout;
dev->vbiq.timeout.data = (unsigned long)dev;
init_timer(&dev->vbiq.timeout);
cx23885_risc_stopper(dev->pci, &dev->vbiq.stopper,
VID_A_DMA_CTL, 0x22, 0x00);
cx23885_irq_add_enable(dev, 0x01);
if ((TUNER_ABSENT != dev->tuner_type) &&
((dev->tuner_bus == 0) || (dev->tuner_bus == 1))) {
struct v4l2_subdev *sd = NULL;
if (dev->tuner_addr)
sd = v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[dev->tuner_bus].i2c_adap,
"tuner", dev->tuner_addr, NULL);
else
sd = v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[dev->tuner_bus].i2c_adap,
"tuner", 0, v4l2_i2c_tuner_addrs(ADDRS_TV));
if (sd) {
struct tuner_setup tun_setup;
memset(&tun_setup, 0, sizeof(tun_setup));
tun_setup.mode_mask = T_ANALOG_TV;
tun_setup.type = dev->tuner_type;
tun_setup.addr = v4l2_i2c_subdev_addr(sd);
tun_setup.tuner_callback = cx23885_tuner_callback;
v4l2_subdev_call(sd, tuner, s_type_addr, &tun_setup);
if (dev->board == CX23885_BOARD_LEADTEK_WINFAST_PXTV1200) {
struct xc2028_ctrl ctrl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64
};
struct v4l2_priv_tun_config cfg = {
.tuner = dev->tuner_type,
.priv = &ctrl
};
v4l2_subdev_call(sd, tuner, s_config, &cfg);
}
if (dev->board == CX23885_BOARD_AVERMEDIA_HC81R) {
struct xc2028_ctrl ctrl = {
.fname = "xc3028L-v36.fw",
.max_len = 64
};
struct v4l2_priv_tun_config cfg = {
.tuner = dev->tuner_type,
.priv = &ctrl
};
v4l2_subdev_call(sd, tuner, s_config, &cfg);
}
}
}
dev->video_dev = cx23885_vdev_init(dev, dev->pci,
&cx23885_video_template, "video");
err = video_register_device(dev->video_dev, VFL_TYPE_GRABBER,
video_nr[dev->nr]);
if (err < 0) {
printk(KERN_INFO "%s: can't register video device\n",
dev->name);
goto fail_unreg;
}
printk(KERN_INFO "%s: registered device %s [v4l2]\n",
dev->name, video_device_node_name(dev->video_dev));
dev->vbi_dev = cx23885_vdev_init(dev, dev->pci,
&cx23885_vbi_template, "vbi");
err = video_register_device(dev->vbi_dev, VFL_TYPE_VBI,
vbi_nr[dev->nr]);
if (err < 0) {
printk(KERN_INFO "%s: can't register vbi device\n",
dev->name);
goto fail_unreg;
}
printk(KERN_INFO "%s: registered device %s\n",
dev->name, video_device_node_name(dev->vbi_dev));
dev->audio_dev = cx23885_audio_register(dev);
mutex_lock(&dev->lock);
cx23885_set_tvnorm(dev, dev->tvnorm);
init_controls(dev);
cx23885_video_mux(dev, 0);
cx23885_audio_mux(dev, 0);
mutex_unlock(&dev->lock);
return 0;
fail_unreg:
cx23885_video_unregister(dev);
return err;
}
