static struct cx23885_fmt *format_by_fourcc(unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fourcc)
return formats+i;
return NULL;
}
void cx23885_video_wakeup(struct cx23885_dev *dev,
struct cx23885_dmaqueue *q, u32 count)
{
struct cx23885_buffer *buf;
if (list_empty(&q->active))
return;
buf = list_entry(q->active.next,
struct cx23885_buffer, queue);
buf->vb.v4l2_buf.sequence = q->count++;
v4l2_get_timestamp(&buf->vb.v4l2_buf.timestamp);
dprintk(2, "[%p/%d] wakeup reg=%d buf=%d\n", buf, buf->vb.v4l2_buf.index,
count, q->count);
list_del(&buf->queue);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_DONE);
}
int cx23885_set_tvnorm(struct cx23885_dev *dev, v4l2_std_id norm)
{
dprintk(1, "%s(norm = 0x%08x) name: [%s]\n",
__func__,
(unsigned int)norm,
v4l2_norm_to_name(norm));
if (dev->tvnorm != norm) {
if (vb2_is_busy(&dev->vb2_vidq) || vb2_is_busy(&dev->vb2_vbiq) ||
vb2_is_busy(&dev->vb2_mpegq))
return -EBUSY;
}
dev->tvnorm = norm;
call_all(dev, video, s_std, norm);
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
vfd->lock = &dev->lock;
snprintf(vfd->name, sizeof(vfd->name), "%s (%s)",
cx23885_boards[dev->board].name, type);
video_set_drvdata(vfd, dev);
return vfd;
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
(dev->board == CX23885_BOARD_HAUPPAUGE_IMPACTVCBE) ||
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
q->count = 0;
cx23885_irq_add_enable(dev, 0x01);
cx_set(VID_A_INT_MSK, 0x000011);
cx_set(DEV_CNTRL2, (1<<5));
cx_set(VID_A_DMA_CTL, 0x11);
return 0;
}
static int queue_setup(struct vb2_queue *q, const struct v4l2_format *fmt,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct cx23885_dev *dev = q->drv_priv;
*num_planes = 1;
sizes[0] = (dev->fmt->depth * dev->width * dev->height) >> 3;
alloc_ctxs[0] = dev->alloc_ctx;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct cx23885_dev *dev = vb->vb2_queue->drv_priv;
struct cx23885_buffer *buf =
container_of(vb, struct cx23885_buffer, vb);
u32 line0_offset, line1_offset;
struct sg_table *sgt = vb2_dma_sg_plane_desc(vb, 0);
int field_tff;
buf->bpl = (dev->width * dev->fmt->depth) >> 3;
if (vb2_plane_size(vb, 0) < dev->height * buf->bpl)
return -EINVAL;
vb2_set_plane_payload(vb, 0, dev->height * buf->bpl);
switch (dev->field) {
case V4L2_FIELD_TOP:
cx23885_risc_buffer(dev->pci, &buf->risc,
sgt->sgl, 0, UNSET,
buf->bpl, 0, dev->height);
break;
case V4L2_FIELD_BOTTOM:
cx23885_risc_buffer(dev->pci, &buf->risc,
sgt->sgl, UNSET, 0,
buf->bpl, 0, dev->height);
break;
case V4L2_FIELD_INTERLACED:
if (dev->tvnorm & V4L2_STD_525_60)
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
sgt->sgl, line0_offset,
line1_offset,
buf->bpl, buf->bpl,
dev->height >> 1);
break;
case V4L2_FIELD_SEQ_TB:
cx23885_risc_buffer(dev->pci, &buf->risc,
sgt->sgl,
0, buf->bpl * (dev->height >> 1),
buf->bpl, 0,
dev->height >> 1);
break;
case V4L2_FIELD_SEQ_BT:
cx23885_risc_buffer(dev->pci, &buf->risc,
sgt->sgl,
buf->bpl * (dev->height >> 1), 0,
buf->bpl, 0,
dev->height >> 1);
break;
default:
BUG();
}
dprintk(2, "[%p/%d] buffer_init - %dx%d %dbpp \"%s\" - dma=0x%08lx\n",
buf, buf->vb.v4l2_buf.index,
dev->width, dev->height, dev->fmt->depth, dev->fmt->name,
(unsigned long)buf->risc.dma);
return 0;
}
static void buffer_finish(struct vb2_buffer *vb)
{
struct cx23885_buffer *buf = container_of(vb,
struct cx23885_buffer, vb);
cx23885_free_buffer(vb->vb2_queue->drv_priv, buf);
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct cx23885_dev *dev = vb->vb2_queue->drv_priv;
struct cx23885_buffer *buf = container_of(vb,
struct cx23885_buffer, vb);
struct cx23885_buffer *prev;
struct cx23885_dmaqueue *q = &dev->vidq;
unsigned long flags;
buf->risc.cpu[1] = cpu_to_le32(buf->risc.dma + 12);
buf->risc.jmp[0] = cpu_to_le32(RISC_JUMP | RISC_CNT_INC);
buf->risc.jmp[1] = cpu_to_le32(buf->risc.dma + 12);
buf->risc.jmp[2] = cpu_to_le32(0);
spin_lock_irqsave(&dev->slock, flags);
if (list_empty(&q->active)) {
list_add_tail(&buf->queue, &q->active);
dprintk(2, "[%p/%d] buffer_queue - first active\n",
buf, buf->vb.v4l2_buf.index);
} else {
buf->risc.cpu[0] |= cpu_to_le32(RISC_IRQ1);
prev = list_entry(q->active.prev, struct cx23885_buffer,
queue);
list_add_tail(&buf->queue, &q->active);
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
dprintk(2, "[%p/%d] buffer_queue - append to active\n",
buf, buf->vb.v4l2_buf.index);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static int cx23885_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct cx23885_dev *dev = q->drv_priv;
struct cx23885_dmaqueue *dmaq = &dev->vidq;
struct cx23885_buffer *buf = list_entry(dmaq->active.next,
struct cx23885_buffer, queue);
cx23885_start_video_dma(dev, dmaq, buf);
return 0;
}
static void cx23885_stop_streaming(struct vb2_queue *q)
{
struct cx23885_dev *dev = q->drv_priv;
struct cx23885_dmaqueue *dmaq = &dev->vidq;
unsigned long flags;
cx_clear(VID_A_DMA_CTL, 0x11);
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&dmaq->active)) {
struct cx23885_buffer *buf = list_entry(dmaq->active.next,
struct cx23885_buffer, queue);
list_del(&buf->queue);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_dev *dev = video_drvdata(file);
f->fmt.pix.width = dev->width;
f->fmt.pix.height = dev->height;
f->fmt.pix.field = dev->field;
f->fmt.pix.pixelformat = dev->fmt->fourcc;
f->fmt.pix.bytesperline =
(f->fmt.pix.width * dev->fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_dev *dev = video_drvdata(file);
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
case V4L2_FIELD_SEQ_TB:
case V4L2_FIELD_SEQ_BT:
break;
default:
field = V4L2_FIELD_INTERLACED;
break;
}
f->fmt.pix.field = field;
v4l_bound_align_image(&f->fmt.pix.width, 48, maxw, 2,
&f->fmt.pix.height, 32, maxh, 0, 0);
f->fmt.pix.bytesperline =
(f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage =
f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx23885_dev *dev = video_drvdata(file);
struct v4l2_mbus_framefmt mbus_fmt;
int err;
dprintk(2, "%s()\n", __func__);
err = vidioc_try_fmt_vid_cap(file, priv, f);
if (0 != err)
return err;
if (vb2_is_busy(&dev->vb2_vidq) || vb2_is_busy(&dev->vb2_vbiq) ||
vb2_is_busy(&dev->vb2_mpegq))
return -EBUSY;
dev->fmt = format_by_fourcc(f->fmt.pix.pixelformat);
dev->width = f->fmt.pix.width;
dev->height = f->fmt.pix.height;
dev->field = f->fmt.pix.field;
dprintk(2, "%s() width=%d height=%d field=%d\n", __func__,
dev->width, dev->height, dev->field);
v4l2_fill_mbus_format(&mbus_fmt, &f->fmt.pix, MEDIA_BUS_FMT_FIXED);
call_all(dev, video, s_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
f->fmt.pix.field = dev->field;
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct cx23885_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
strcpy(cap->driver, "cx23885");
strlcpy(cap->card, cx23885_boards[dev->board].name,
sizeof(cap->card));
sprintf(cap->bus_info, "PCIe:%s", pci_name(dev->pci));
cap->device_caps = V4L2_CAP_READWRITE | V4L2_CAP_STREAMING | V4L2_CAP_AUDIO;
if (dev->tuner_type != TUNER_ABSENT)
cap->device_caps |= V4L2_CAP_TUNER;
if (vdev->vfl_type == VFL_TYPE_VBI)
cap->device_caps |= V4L2_CAP_VBI_CAPTURE;
else
cap->device_caps |= V4L2_CAP_VIDEO_CAPTURE;
cap->capabilities = cap->device_caps | V4L2_CAP_VBI_CAPTURE |
V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_DEVICE_CAPS;
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
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct cx23885_dev *dev = video_drvdata(file);
dprintk(1, "%s()\n", __func__);
*id = dev->tvnorm;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id tvnorms)
{
struct cx23885_dev *dev = video_drvdata(file);
dprintk(1, "%s()\n", __func__);
return cx23885_set_tvnorm(dev, tvnorms);
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
i->std = CX23885_NORMS;
if ((CX23885_VMUX_TELEVISION == INPUT(n)->type) ||
(CX23885_VMUX_CABLE == INPUT(n)->type)) {
i->type = V4L2_INPUT_TYPE_TUNER;
i->audioset = 4;
} else {
i->audioset = 3;
}
if (dev->input == n) {
call_all(dev, video, g_input_status, &i->status);
}
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx23885_dev *dev = video_drvdata(file);
dprintk(1, "%s()\n", __func__);
return cx23885_enum_input(dev, i);
}
int cx23885_get_input(struct file *file, void *priv, unsigned int *i)
{
struct cx23885_dev *dev = video_drvdata(file);
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
struct cx23885_dev *dev = video_drvdata(file);
dprintk(1, "%s(%d)\n", __func__, i);
if (i >= MAX_CX23885_INPUT) {
dprintk(1, "%s() -EINVAL\n", __func__);
return -EINVAL;
}
if (INPUT(i)->type == 0)
return -EINVAL;
cx23885_video_mux(dev, i);
cx23885_audio_mux(dev, i);
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
return cx23885_set_input(file, priv, i);
}
static int vidioc_log_status(struct file *file, void *priv)
{
struct cx23885_dev *dev = video_drvdata(file);
call_all(dev, core, log_status);
return 0;
}
static int cx23885_query_audinput(struct file *file, void *priv,
struct v4l2_audio *i)
{
struct cx23885_dev *dev = video_drvdata(file);
static const char *iname[] = {
[0] = "Baseband L/R 1",
[1] = "Baseband L/R 2",
[2] = "TV",
};
unsigned int n;
dprintk(1, "%s()\n", __func__);
n = i->index;
if (n >= 3)
return -EINVAL;
memset(i, 0, sizeof(*i));
i->index = n;
strcpy(i->name, iname[n]);
i->capability = V4L2_AUDCAP_STEREO;
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
struct cx23885_dev *dev = video_drvdata(file);
if ((CX23885_VMUX_TELEVISION == INPUT(dev->input)->type) ||
(CX23885_VMUX_CABLE == INPUT(dev->input)->type))
i->index = 2;
else
i->index = dev->audinput;
dprintk(1, "%s(input=%d)\n", __func__, i->index);
return cx23885_query_audinput(file, priv, i);
}
static int vidioc_s_audinput(struct file *file, void *priv,
const struct v4l2_audio *i)
{
struct cx23885_dev *dev = video_drvdata(file);
if ((CX23885_VMUX_TELEVISION == INPUT(dev->input)->type) ||
(CX23885_VMUX_CABLE == INPUT(dev->input)->type)) {
return i->index != 2 ? -EINVAL : 0;
}
if (i->index > 1)
return -EINVAL;
dprintk(1, "%s(%d)\n", __func__, i->index);
dev->audinput = i->index;
cx23885_flatiron_mux(dev, dev->audinput + 1);
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx23885_dev *dev = video_drvdata(file);
if (dev->tuner_type == TUNER_ABSENT)
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
struct cx23885_dev *dev = video_drvdata(file);
if (dev->tuner_type == TUNER_ABSENT)
return -EINVAL;
if (0 != t->index)
return -EINVAL;
call_all(dev, tuner, s_tuner, t);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cx23885_dev *dev = video_drvdata(file);
if (dev->tuner_type == TUNER_ABSENT)
return -EINVAL;
f->type = V4L2_TUNER_ANALOG_TV;
f->frequency = dev->freq;
call_all(dev, tuner, g_frequency, f);
return 0;
}
static int cx23885_set_freq(struct cx23885_dev *dev, const struct v4l2_frequency *f)
{
struct v4l2_ctrl *mute;
int old_mute_val = 1;
if (dev->tuner_type == TUNER_ABSENT)
return -EINVAL;
if (unlikely(f->tuner != 0))
return -EINVAL;
dev->freq = f->frequency;
mute = v4l2_ctrl_find(&dev->ctrl_handler, V4L2_CID_AUDIO_MUTE);
if (mute) {
old_mute_val = v4l2_ctrl_g_ctrl(mute);
if (!old_mute_val)
v4l2_ctrl_s_ctrl(mute, 1);
}
call_all(dev, tuner, s_frequency, f);
msleep(100);
if (old_mute_val == 0)
v4l2_ctrl_s_ctrl(mute, old_mute_val);
return 0;
}
static int cx23885_set_freq_via_ops(struct cx23885_dev *dev,
const struct v4l2_frequency *f)
{
struct v4l2_ctrl *mute;
int old_mute_val = 1;
struct vb2_dvb_frontend *vfe;
struct dvb_frontend *fe;
struct analog_parameters params = {
.mode = V4L2_TUNER_ANALOG_TV,
.audmode = V4L2_TUNER_MODE_STEREO,
.std = dev->tvnorm,
.frequency = f->frequency
};
dev->freq = f->frequency;
mute = v4l2_ctrl_find(&dev->ctrl_handler, V4L2_CID_AUDIO_MUTE);
if (mute) {
old_mute_val = v4l2_ctrl_g_ctrl(mute);
if (!old_mute_val)
v4l2_ctrl_s_ctrl(mute, 1);
}
dprintk(1, "%s() frequency=%d tuner=%d std=0x%llx\n", __func__,
params.frequency, f->tuner, params.std);
vfe = vb2_dvb_get_frontend(&dev->ts2.frontends, 1);
if (!vfe) {
return -EINVAL;
}
fe = vfe->dvb.frontend;
if ((dev->board == CX23885_BOARD_HAUPPAUGE_HVR1850) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1255) ||
(dev->board == CX23885_BOARD_HAUPPAUGE_HVR1255_22111))
fe = &dev->ts1.analog_fe;
if (fe && fe->ops.tuner_ops.set_analog_params) {
call_all(dev, video, s_std, dev->tvnorm);
fe->ops.tuner_ops.set_analog_params(fe, &params);
}
else
printk(KERN_ERR "%s() No analog tuner, aborting\n", __func__);
msleep(100);
if (old_mute_val == 0)
v4l2_ctrl_s_ctrl(mute, old_mute_val);
return 0;
}
int cx23885_set_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct cx23885_dev *dev = video_drvdata(file);
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
}
if (dev->video_dev) {
if (video_is_registered(dev->video_dev))
video_unregister_device(dev->video_dev);
else
video_device_release(dev->video_dev);
dev->video_dev = NULL;
}
if (dev->audio_dev)
cx23885_audio_unregister(dev);
}
int cx23885_video_register(struct cx23885_dev *dev)
{
struct vb2_queue *q;
int err;
dprintk(1, "%s()\n", __func__);
cx23885_vbi_template = cx23885_video_template;
strcpy(cx23885_vbi_template.name, "cx23885-vbi");
dev->tvnorm = V4L2_STD_NTSC_M;
dev->fmt = format_by_fourcc(V4L2_PIX_FMT_YUYV);
dev->field = V4L2_FIELD_INTERLACED;
dev->width = 720;
dev->height = norm_maxh(dev->tvnorm);
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vbiq.active);
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
if ((dev->board == CX23885_BOARD_LEADTEK_WINFAST_PXTV1200) ||
(dev->board == CX23885_BOARD_LEADTEK_WINFAST_PXPVR2200)) {
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
mutex_lock(&dev->lock);
cx23885_set_tvnorm(dev, dev->tvnorm);
cx23885_video_mux(dev, 0);
cx23885_audio_mux(dev, 0);
mutex_unlock(&dev->lock);
q = &dev->vb2_vidq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct cx23885_buffer);
q->ops = &cx23885_video_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &dev->lock;
err = vb2_queue_init(q);
if (err < 0)
goto fail_unreg;
q = &dev->vb2_vbiq;
q->type = V4L2_BUF_TYPE_VBI_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct cx23885_buffer);
q->ops = &cx23885_vbi_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &dev->lock;
err = vb2_queue_init(q);
if (err < 0)
goto fail_unreg;
dev->video_dev = cx23885_vdev_init(dev, dev->pci,
&cx23885_video_template, "video");
dev->video_dev->queue = &dev->vb2_vidq;
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
dev->vbi_dev->queue = &dev->vb2_vbiq;
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
return 0;
fail_unreg:
cx23885_video_unregister(dev);
return err;
}
