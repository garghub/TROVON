static const struct cx8800_fmt* format_by_fourcc(unsigned int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fourcc)
return formats+i;
return NULL;
}
int cx88_video_mux(struct cx88_core *core, unsigned int input)
{
dprintk(1,"video_mux: %d [vmux=%d,gpio=0x%x,0x%x,0x%x,0x%x]\n",
input, INPUT(input).vmux,
INPUT(input).gpio0,INPUT(input).gpio1,
INPUT(input).gpio2,INPUT(input).gpio3);
core->input = input;
cx_andor(MO_INPUT_FORMAT, 0x03 << 14, INPUT(input).vmux << 14);
cx_write(MO_GP3_IO, INPUT(input).gpio3);
cx_write(MO_GP0_IO, INPUT(input).gpio0);
cx_write(MO_GP1_IO, INPUT(input).gpio1);
cx_write(MO_GP2_IO, INPUT(input).gpio2);
switch (INPUT(input).type) {
case CX88_VMUX_SVIDEO:
cx_set(MO_AFECFG_IO, 0x00000001);
cx_set(MO_INPUT_FORMAT, 0x00010010);
cx_set(MO_FILTER_EVEN, 0x00002020);
cx_set(MO_FILTER_ODD, 0x00002020);
break;
default:
cx_clear(MO_AFECFG_IO, 0x00000001);
cx_clear(MO_INPUT_FORMAT, 0x00010010);
cx_clear(MO_FILTER_EVEN, 0x00002020);
cx_clear(MO_FILTER_ODD, 0x00002020);
break;
}
if (INPUT(input).audioroute) {
if (core->sd_wm8775) {
call_all(core, audio, s_routing,
INPUT(input).audioroute, 0, 0);
}
if (INPUT(input).type != CX88_VMUX_TELEVISION &&
INPUT(input).type != CX88_VMUX_CABLE) {
core->tvaudio = WW_I2SADC;
cx88_set_tvaudio(core);
} else {
cx_write(AUD_I2SCNTL, 0x0);
cx_clear(AUD_CTL, EN_I2SIN_ENABLE);
}
}
return 0;
}
static int start_video_dma(struct cx8800_dev *dev,
struct cx88_dmaqueue *q,
struct cx88_buffer *buf)
{
struct cx88_core *core = dev->core;
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH21],
buf->bpl, buf->risc.dma);
cx88_set_scale(core, core->width, core->height, core->field);
cx_write(MO_COLOR_CTRL, dev->fmt->cxformat | ColorFormatGamma);
cx_write(MO_VIDY_GPCNTRL,GP_COUNT_CONTROL_RESET);
q->count = 0;
cx_set(MO_PCI_INTMSK, core->pci_irqmask | PCI_INT_VIDINT);
cx_set(MO_VID_INTMSK, 0x0f0011);
cx_set(VID_CAPTURE_CONTROL,0x06);
cx_set(MO_DEV_CNTRL2, (1<<5));
cx_set(MO_VID_DMACNTRL, 0x11);
return 0;
}
static int stop_video_dma(struct cx8800_dev *dev)
{
struct cx88_core *core = dev->core;
cx_clear(MO_VID_DMACNTRL, 0x11);
cx_clear(VID_CAPTURE_CONTROL,0x06);
cx_clear(MO_PCI_INTMSK, PCI_INT_VIDINT);
cx_clear(MO_VID_INTMSK, 0x0f0011);
return 0;
}
static int restart_video_queue(struct cx8800_dev *dev,
struct cx88_dmaqueue *q)
{
struct cx88_core *core = dev->core;
struct cx88_buffer *buf;
if (!list_empty(&q->active)) {
buf = list_entry(q->active.next, struct cx88_buffer, list);
dprintk(2,"restart_queue [%p/%d]: restart dma\n",
buf, buf->vb.vb2_buf.index);
start_video_dma(dev, q, buf);
}
return 0;
}
static int queue_setup(struct vb2_queue *q,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct cx8800_dev *dev = q->drv_priv;
struct cx88_core *core = dev->core;
*num_planes = 1;
sizes[0] = (dev->fmt->depth * core->width * core->height) >> 3;
alloc_ctxs[0] = dev->alloc_ctx;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx8800_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_core *core = dev->core;
struct cx88_buffer *buf = container_of(vbuf, struct cx88_buffer, vb);
struct sg_table *sgt = vb2_dma_sg_plane_desc(vb, 0);
buf->bpl = core->width * dev->fmt->depth >> 3;
if (vb2_plane_size(vb, 0) < core->height * buf->bpl)
return -EINVAL;
vb2_set_plane_payload(vb, 0, core->height * buf->bpl);
switch (core->field) {
case V4L2_FIELD_TOP:
cx88_risc_buffer(dev->pci, &buf->risc,
sgt->sgl, 0, UNSET,
buf->bpl, 0, core->height);
break;
case V4L2_FIELD_BOTTOM:
cx88_risc_buffer(dev->pci, &buf->risc,
sgt->sgl, UNSET, 0,
buf->bpl, 0, core->height);
break;
case V4L2_FIELD_SEQ_TB:
cx88_risc_buffer(dev->pci, &buf->risc,
sgt->sgl,
0, buf->bpl * (core->height >> 1),
buf->bpl, 0,
core->height >> 1);
break;
case V4L2_FIELD_SEQ_BT:
cx88_risc_buffer(dev->pci, &buf->risc,
sgt->sgl,
buf->bpl * (core->height >> 1), 0,
buf->bpl, 0,
core->height >> 1);
break;
case V4L2_FIELD_INTERLACED:
default:
cx88_risc_buffer(dev->pci, &buf->risc,
sgt->sgl, 0, buf->bpl,
buf->bpl, buf->bpl,
core->height >> 1);
break;
}
dprintk(2,"[%p/%d] buffer_prepare - %dx%d %dbpp \"%s\" - dma=0x%08lx\n",
buf, buf->vb.vb2_buf.index,
core->width, core->height, dev->fmt->depth, dev->fmt->name,
(unsigned long)buf->risc.dma);
return 0;
}
static void buffer_finish(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx8800_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vbuf, struct cx88_buffer, vb);
struct cx88_riscmem *risc = &buf->risc;
if (risc->cpu)
pci_free_consistent(dev->pci, risc->size, risc->cpu, risc->dma);
memset(risc, 0, sizeof(*risc));
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx8800_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vbuf, struct cx88_buffer, vb);
struct cx88_buffer *prev;
struct cx88_core *core = dev->core;
struct cx88_dmaqueue *q = &dev->vidq;
buf->risc.cpu[1] = cpu_to_le32(buf->risc.dma + 8);
buf->risc.jmp[0] = cpu_to_le32(RISC_JUMP | RISC_CNT_INC);
buf->risc.jmp[1] = cpu_to_le32(buf->risc.dma + 8);
if (list_empty(&q->active)) {
list_add_tail(&buf->list, &q->active);
dprintk(2,"[%p/%d] buffer_queue - first active\n",
buf, buf->vb.vb2_buf.index);
} else {
buf->risc.cpu[0] |= cpu_to_le32(RISC_IRQ1);
prev = list_entry(q->active.prev, struct cx88_buffer, list);
list_add_tail(&buf->list, &q->active);
prev->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
dprintk(2, "[%p/%d] buffer_queue - append to active\n",
buf, buf->vb.vb2_buf.index);
}
}
static int start_streaming(struct vb2_queue *q, unsigned int count)
{
struct cx8800_dev *dev = q->drv_priv;
struct cx88_dmaqueue *dmaq = &dev->vidq;
struct cx88_buffer *buf = list_entry(dmaq->active.next,
struct cx88_buffer, list);
start_video_dma(dev, dmaq, buf);
return 0;
}
static void stop_streaming(struct vb2_queue *q)
{
struct cx8800_dev *dev = q->drv_priv;
struct cx88_core *core = dev->core;
struct cx88_dmaqueue *dmaq = &dev->vidq;
unsigned long flags;
cx_clear(MO_VID_DMACNTRL, 0x11);
cx_clear(VID_CAPTURE_CONTROL, 0x06);
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&dmaq->active)) {
struct cx88_buffer *buf = list_entry(dmaq->active.next,
struct cx88_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static int radio_open(struct file *file)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
int ret = v4l2_fh_open(file);
if (ret)
return ret;
cx_write(MO_GP3_IO, core->board.radio.gpio3);
cx_write(MO_GP0_IO, core->board.radio.gpio0);
cx_write(MO_GP1_IO, core->board.radio.gpio1);
cx_write(MO_GP2_IO, core->board.radio.gpio2);
if (core->board.radio.audioroute) {
if (core->sd_wm8775) {
call_all(core, audio, s_routing,
core->board.radio.audioroute, 0, 0);
}
core->tvaudio = WW_I2SADC;
cx88_set_tvaudio(core);
} else {
core->tvaudio = WW_FM;
cx88_set_tvaudio(core);
cx88_set_stereo(core, V4L2_TUNER_MODE_STEREO, 1);
}
call_all(core, tuner, s_radio);
return 0;
}
static int cx8800_s_vid_ctrl(struct v4l2_ctrl *ctrl)
{
struct cx88_core *core =
container_of(ctrl->handler, struct cx88_core, video_hdl);
const struct cx88_ctrl *cc = ctrl->priv;
u32 value, mask;
mask = cc->mask;
switch (ctrl->id) {
case V4L2_CID_SATURATION:
value = ((ctrl->val - cc->off) << cc->shift) & cc->mask;
if (core->tvnorm & V4L2_STD_SECAM) {
value = value << 8 | value;
} else {
value = (value * 0x5a) / 0x7f << 8 | value;
}
mask = 0xffff;
break;
case V4L2_CID_SHARPNESS:
value = (ctrl->val < 1 ? 0 : ((ctrl->val + 3) << 7));
cx_andor(MO_FILTER_EVEN, mask, value);
break;
case V4L2_CID_CHROMA_AGC:
value = ((ctrl->val - cc->off) << cc->shift) & cc->mask;
break;
default:
value = ((ctrl->val - cc->off) << cc->shift) & cc->mask;
break;
}
dprintk(1, "set_control id=0x%X(%s) ctrl=0x%02x, reg=0x%02x val=0x%02x (mask 0x%02x)%s\n",
ctrl->id, ctrl->name, ctrl->val, cc->reg, value,
mask, cc->sreg ? " [shadowed]" : "");
if (cc->sreg)
cx_sandor(cc->sreg, cc->reg, mask, value);
else
cx_andor(cc->reg, mask, value);
return 0;
}
static int cx8800_s_aud_ctrl(struct v4l2_ctrl *ctrl)
{
struct cx88_core *core =
container_of(ctrl->handler, struct cx88_core, audio_hdl);
const struct cx88_ctrl *cc = ctrl->priv;
u32 value,mask;
if (core->sd_wm8775) {
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
wm8775_s_ctrl(core, ctrl->id, ctrl->val);
break;
case V4L2_CID_AUDIO_VOLUME:
wm8775_s_ctrl(core, ctrl->id, (ctrl->val) ?
(0x90 + ctrl->val) << 8 : 0);
break;
case V4L2_CID_AUDIO_BALANCE:
wm8775_s_ctrl(core, ctrl->id, ctrl->val << 9);
break;
default:
break;
}
}
mask = cc->mask;
switch (ctrl->id) {
case V4L2_CID_AUDIO_BALANCE:
value = (ctrl->val < 0x40) ? (0x7f - ctrl->val) : (ctrl->val - 0x40);
break;
case V4L2_CID_AUDIO_VOLUME:
value = 0x3f - (ctrl->val & 0x3f);
break;
default:
value = ((ctrl->val - cc->off) << cc->shift) & cc->mask;
break;
}
dprintk(1,"set_control id=0x%X(%s) ctrl=0x%02x, reg=0x%02x val=0x%02x (mask 0x%02x)%s\n",
ctrl->id, ctrl->name, ctrl->val, cc->reg, value,
mask, cc->sreg ? " [shadowed]" : "");
if (cc->sreg)
cx_sandor(cc->sreg, cc->reg, mask, value);
else
cx_andor(cc->reg, mask, value);
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
f->fmt.pix.width = core->width;
f->fmt.pix.height = core->height;
f->fmt.pix.field = core->field;
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
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
const struct cx8800_fmt *fmt;
enum v4l2_field field;
unsigned int maxw, maxh;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (NULL == fmt)
return -EINVAL;
maxw = norm_maxw(core->tvnorm);
maxh = norm_maxh(core->tvnorm);
field = f->fmt.pix.field;
switch (field) {
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_SEQ_BT:
case V4L2_FIELD_SEQ_TB:
break;
default:
field = (f->fmt.pix.height > maxh / 2)
? V4L2_FIELD_INTERLACED
: V4L2_FIELD_BOTTOM;
break;
}
if (V4L2_FIELD_HAS_T_OR_B(field))
maxh /= 2;
v4l_bound_align_image(&f->fmt.pix.width, 48, maxw, 2,
&f->fmt.pix.height, 32, maxh, 0, 0);
f->fmt.pix.field = field;
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
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
int err = vidioc_try_fmt_vid_cap (file,priv,f);
if (0 != err)
return err;
if (vb2_is_busy(&dev->vb2_vidq) || vb2_is_busy(&dev->vb2_vbiq))
return -EBUSY;
if (core->dvbdev && vb2_is_busy(&core->dvbdev->vb2_mpegq))
return -EBUSY;
dev->fmt = format_by_fourcc(f->fmt.pix.pixelformat);
core->width = f->fmt.pix.width;
core->height = f->fmt.pix.height;
core->field = f->fmt.pix.field;
return 0;
}
void cx88_querycap(struct file *file, struct cx88_core *core,
struct v4l2_capability *cap)
{
struct video_device *vdev = video_devdata(file);
strlcpy(cap->card, core->board.name, sizeof(cap->card));
cap->device_caps = V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
if (UNSET != core->board.tuner_type)
cap->device_caps |= V4L2_CAP_TUNER;
switch (vdev->vfl_type) {
case VFL_TYPE_RADIO:
cap->device_caps = V4L2_CAP_RADIO | V4L2_CAP_TUNER;
break;
case VFL_TYPE_GRABBER:
cap->device_caps |= V4L2_CAP_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
cap->device_caps |= V4L2_CAP_VBI_CAPTURE;
break;
}
cap->capabilities = cap->device_caps | V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_VBI_CAPTURE | V4L2_CAP_DEVICE_CAPS;
if (core->board.radio.type == CX88_RADIO)
cap->capabilities |= V4L2_CAP_RADIO;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
strcpy(cap->driver, "cx8800");
sprintf(cap->bus_info, "PCI:%s", pci_name(dev->pci));
cx88_querycap(file, core, cap);
return 0;
}
static int vidioc_enum_fmt_vid_cap (struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (unlikely(f->index >= ARRAY_SIZE(formats)))
return -EINVAL;
strlcpy(f->description,formats[f->index].name,sizeof(f->description));
f->pixelformat = formats[f->index].fourcc;
return 0;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *tvnorm)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
*tvnorm = core->tvnorm;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id tvnorms)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
return cx88_set_tvnorm(core, tvnorms);
}
int cx88_enum_input (struct cx88_core *core,struct v4l2_input *i)
{
static const char * const iname[] = {
[ CX88_VMUX_COMPOSITE1 ] = "Composite1",
[ CX88_VMUX_COMPOSITE2 ] = "Composite2",
[ CX88_VMUX_COMPOSITE3 ] = "Composite3",
[ CX88_VMUX_COMPOSITE4 ] = "Composite4",
[ CX88_VMUX_SVIDEO ] = "S-Video",
[ CX88_VMUX_TELEVISION ] = "Television",
[ CX88_VMUX_CABLE ] = "Cable TV",
[ CX88_VMUX_DVB ] = "DVB",
[ CX88_VMUX_DEBUG ] = "for debug only",
};
unsigned int n = i->index;
if (n >= 4)
return -EINVAL;
if (0 == INPUT(n).type)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(i->name,iname[INPUT(n).type]);
if ((CX88_VMUX_TELEVISION == INPUT(n).type) ||
(CX88_VMUX_CABLE == INPUT(n).type)) {
i->type = V4L2_INPUT_TYPE_TUNER;
}
i->std = CX88_NORMS;
return 0;
}
static int vidioc_enum_input (struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
return cx88_enum_input (core,i);
}
static int vidioc_g_input (struct file *file, void *priv, unsigned int *i)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
*i = core->input;
return 0;
}
static int vidioc_s_input (struct file *file, void *priv, unsigned int i)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (i >= 4)
return -EINVAL;
if (0 == INPUT(i).type)
return -EINVAL;
cx88_newstation(core);
cx88_video_mux(core,i);
return 0;
}
static int vidioc_g_tuner (struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
u32 reg;
if (unlikely(UNSET == core->board.tuner_type))
return -EINVAL;
if (0 != t->index)
return -EINVAL;
strcpy(t->name, "Television");
t->capability = V4L2_TUNER_CAP_NORM;
t->rangehigh = 0xffffffffUL;
call_all(core, tuner, g_tuner, t);
cx88_get_stereo(core ,t);
reg = cx_read(MO_DEVICE_STATUS);
t->signal = (reg & (1<<5)) ? 0xffff : 0x0000;
return 0;
}
static int vidioc_s_tuner (struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (UNSET == core->board.tuner_type)
return -EINVAL;
if (0 != t->index)
return -EINVAL;
cx88_set_stereo(core, t->audmode, 1);
return 0;
}
static int vidioc_g_frequency (struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (unlikely(UNSET == core->board.tuner_type))
return -EINVAL;
if (f->tuner)
return -EINVAL;
f->frequency = core->freq;
call_all(core, tuner, g_frequency, f);
return 0;
}
int cx88_set_freq (struct cx88_core *core,
const struct v4l2_frequency *f)
{
struct v4l2_frequency new_freq = *f;
if (unlikely(UNSET == core->board.tuner_type))
return -EINVAL;
if (unlikely(f->tuner != 0))
return -EINVAL;
cx88_newstation(core);
call_all(core, tuner, s_frequency, f);
call_all(core, tuner, g_frequency, &new_freq);
core->freq = new_freq.frequency;
msleep (10);
cx88_set_tvaudio(core);
return 0;
}
static int vidioc_s_frequency (struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
return cx88_set_freq(core, f);
}
static int vidioc_g_register (struct file *file, void *fh,
struct v4l2_dbg_register *reg)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
reg->val = cx_read(reg->reg & 0xfffffc);
reg->size = 4;
return 0;
}
static int vidioc_s_register (struct file *file, void *fh,
const struct v4l2_dbg_register *reg)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
cx_write(reg->reg & 0xfffffc, reg->val);
return 0;
}
static int radio_g_tuner (struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (unlikely(t->index > 0))
return -EINVAL;
strcpy(t->name, "Radio");
call_all(core, tuner, g_tuner, t);
return 0;
}
static int radio_s_tuner (struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct cx8800_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (0 != t->index)
return -EINVAL;
call_all(core, tuner, s_tuner, t);
return 0;
}
static void cx8800_vid_irq(struct cx8800_dev *dev)
{
struct cx88_core *core = dev->core;
u32 status, mask, count;
status = cx_read(MO_VID_INTSTAT);
mask = cx_read(MO_VID_INTMSK);
if (0 == (status & mask))
return;
cx_write(MO_VID_INTSTAT, status);
if (irq_debug || (status & mask & ~0xff))
cx88_print_irqbits(core->name, "irq vid",
cx88_vid_irqs, ARRAY_SIZE(cx88_vid_irqs),
status, mask);
if (status & (1 << 16)) {
printk(KERN_WARNING "%s/0: video risc op code error\n",core->name);
cx_clear(MO_VID_DMACNTRL, 0x11);
cx_clear(VID_CAPTURE_CONTROL, 0x06);
cx88_sram_channel_dump(core, &cx88_sram_channels[SRAM_CH21]);
}
if (status & 0x01) {
spin_lock(&dev->slock);
count = cx_read(MO_VIDY_GPCNT);
cx88_wakeup(core, &dev->vidq, count);
spin_unlock(&dev->slock);
}
if (status & 0x08) {
spin_lock(&dev->slock);
count = cx_read(MO_VBI_GPCNT);
cx88_wakeup(core, &dev->vbiq, count);
spin_unlock(&dev->slock);
}
}
static irqreturn_t cx8800_irq(int irq, void *dev_id)
{
struct cx8800_dev *dev = dev_id;
struct cx88_core *core = dev->core;
u32 status;
int loop, handled = 0;
for (loop = 0; loop < 10; loop++) {
status = cx_read(MO_PCI_INTSTAT) &
(core->pci_irqmask | PCI_INT_VIDINT);
if (0 == status)
goto out;
cx_write(MO_PCI_INTSTAT, status);
handled = 1;
if (status & core->pci_irqmask)
cx88_core_irq(core,status);
if (status & PCI_INT_VIDINT)
cx8800_vid_irq(dev);
}
if (10 == loop) {
printk(KERN_WARNING "%s/0: irq loop -- clearing mask\n",
core->name);
cx_write(MO_PCI_INTMSK,0);
}
out:
return IRQ_RETVAL(handled);
}
static void cx8800_unregister_video(struct cx8800_dev *dev)
{
video_unregister_device(&dev->radio_dev);
video_unregister_device(&dev->vbi_dev);
video_unregister_device(&dev->video_dev);
}
static int cx8800_initdev(struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
struct cx8800_dev *dev;
struct cx88_core *core;
struct vb2_queue *q;
int err;
int i;
dev = kzalloc(sizeof(*dev),GFP_KERNEL);
if (NULL == dev)
return -ENOMEM;
dev->pci = pci_dev;
if (pci_enable_device(pci_dev)) {
err = -EIO;
goto fail_free;
}
core = cx88_core_get(dev->pci);
if (NULL == core) {
err = -EINVAL;
goto fail_free;
}
dev->core = core;
dev->pci_rev = pci_dev->revision;
pci_read_config_byte(pci_dev, PCI_LATENCY_TIMER, &dev->pci_lat);
printk(KERN_INFO "%s/0: found at %s, rev: %d, irq: %d, "
"latency: %d, mmio: 0x%llx\n", core->name,
pci_name(pci_dev), dev->pci_rev, pci_dev->irq,
dev->pci_lat,(unsigned long long)pci_resource_start(pci_dev,0));
pci_set_master(pci_dev);
err = pci_set_dma_mask(pci_dev,DMA_BIT_MASK(32));
if (err) {
printk("%s/0: Oops: no 32bit PCI DMA ???\n",core->name);
goto fail_core;
}
dev->alloc_ctx = vb2_dma_sg_init_ctx(&pci_dev->dev);
if (IS_ERR(dev->alloc_ctx)) {
err = PTR_ERR(dev->alloc_ctx);
goto fail_core;
}
spin_lock_init(&dev->slock);
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vbiq.active);
err = request_irq(pci_dev->irq, cx8800_irq,
IRQF_SHARED, core->name, dev);
if (err < 0) {
printk(KERN_ERR "%s/0: can't get IRQ %d\n",
core->name,pci_dev->irq);
goto fail_core;
}
cx_set(MO_PCI_INTMSK, core->pci_irqmask);
for (i = 0; i < CX8800_AUD_CTLS; i++) {
const struct cx88_ctrl *cc = &cx8800_aud_ctls[i];
struct v4l2_ctrl *vc;
vc = v4l2_ctrl_new_std(&core->audio_hdl, &cx8800_ctrl_aud_ops,
cc->id, cc->minimum, cc->maximum, cc->step, cc->default_value);
if (vc == NULL) {
err = core->audio_hdl.error;
goto fail_core;
}
vc->priv = (void *)cc;
}
for (i = 0; i < CX8800_VID_CTLS; i++) {
const struct cx88_ctrl *cc = &cx8800_vid_ctls[i];
struct v4l2_ctrl *vc;
vc = v4l2_ctrl_new_std(&core->video_hdl, &cx8800_ctrl_vid_ops,
cc->id, cc->minimum, cc->maximum, cc->step, cc->default_value);
if (vc == NULL) {
err = core->video_hdl.error;
goto fail_core;
}
vc->priv = (void *)cc;
if (vc->id == V4L2_CID_CHROMA_AGC)
core->chroma_agc = vc;
}
v4l2_ctrl_add_handler(&core->video_hdl, &core->audio_hdl, NULL);
if (core->board.audio_chip == CX88_AUDIO_WM8775) {
struct i2c_board_info wm8775_info = {
.type = "wm8775",
.addr = 0x36 >> 1,
.platform_data = &core->wm8775_data,
};
struct v4l2_subdev *sd;
if (core->boardnr == CX88_BOARD_HAUPPAUGE_NOVASPLUS_S1)
core->wm8775_data.is_nova_s = true;
else
core->wm8775_data.is_nova_s = false;
sd = v4l2_i2c_new_subdev_board(&core->v4l2_dev, &core->i2c_adap,
&wm8775_info, NULL);
if (sd != NULL) {
core->sd_wm8775 = sd;
sd->grp_id = WM8775_GID;
}
}
if (core->board.audio_chip == CX88_AUDIO_TVAUDIO) {
v4l2_i2c_new_subdev(&core->v4l2_dev, &core->i2c_adap,
"tvaudio", 0, I2C_ADDRS(0xb0 >> 1));
}
switch (core->boardnr) {
case CX88_BOARD_DVICO_FUSIONHDTV_5_GOLD:
case CX88_BOARD_DVICO_FUSIONHDTV_7_GOLD: {
static const struct i2c_board_info rtc_info = {
I2C_BOARD_INFO("isl1208", 0x6f)
};
request_module("rtc-isl1208");
core->i2c_rtc = i2c_new_device(&core->i2c_adap, &rtc_info);
}
case CX88_BOARD_DVICO_FUSIONHDTV_5_PCI_NANO:
request_module("ir-kbd-i2c");
}
pci_set_drvdata(pci_dev, dev);
dev->fmt = format_by_fourcc(V4L2_PIX_FMT_BGR24);
core->v4ldev = dev;
mutex_lock(&core->lock);
cx88_set_tvnorm(core, core->tvnorm);
v4l2_ctrl_handler_setup(&core->video_hdl);
v4l2_ctrl_handler_setup(&core->audio_hdl);
cx88_video_mux(core, 0);
q = &dev->vb2_vidq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct cx88_buffer);
q->ops = &cx8800_video_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &core->lock;
err = vb2_queue_init(q);
if (err < 0)
goto fail_unreg;
q = &dev->vb2_vbiq;
q->type = V4L2_BUF_TYPE_VBI_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct cx88_buffer);
q->ops = &cx8800_vbi_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &core->lock;
err = vb2_queue_init(q);
if (err < 0)
goto fail_unreg;
cx88_vdev_init(core, dev->pci, &dev->video_dev,
&cx8800_video_template, "video");
video_set_drvdata(&dev->video_dev, dev);
dev->video_dev.ctrl_handler = &core->video_hdl;
dev->video_dev.queue = &dev->vb2_vidq;
err = video_register_device(&dev->video_dev, VFL_TYPE_GRABBER,
video_nr[core->nr]);
if (err < 0) {
printk(KERN_ERR "%s/0: can't register video device\n",
core->name);
goto fail_unreg;
}
printk(KERN_INFO "%s/0: registered device %s [v4l2]\n",
core->name, video_device_node_name(&dev->video_dev));
cx88_vdev_init(core, dev->pci, &dev->vbi_dev,
&cx8800_vbi_template, "vbi");
video_set_drvdata(&dev->vbi_dev, dev);
dev->vbi_dev.queue = &dev->vb2_vbiq;
err = video_register_device(&dev->vbi_dev, VFL_TYPE_VBI,
vbi_nr[core->nr]);
if (err < 0) {
printk(KERN_ERR "%s/0: can't register vbi device\n",
core->name);
goto fail_unreg;
}
printk(KERN_INFO "%s/0: registered device %s\n",
core->name, video_device_node_name(&dev->vbi_dev));
if (core->board.radio.type == CX88_RADIO) {
cx88_vdev_init(core, dev->pci, &dev->radio_dev,
&cx8800_radio_template, "radio");
video_set_drvdata(&dev->radio_dev, dev);
dev->radio_dev.ctrl_handler = &core->audio_hdl;
err = video_register_device(&dev->radio_dev, VFL_TYPE_RADIO,
radio_nr[core->nr]);
if (err < 0) {
printk(KERN_ERR "%s/0: can't register radio device\n",
core->name);
goto fail_unreg;
}
printk(KERN_INFO "%s/0: registered device %s\n",
core->name, video_device_node_name(&dev->radio_dev));
}
if (core->board.tuner_type != UNSET) {
core->kthread = kthread_run(cx88_audio_thread, core, "cx88 tvaudio");
if (IS_ERR(core->kthread)) {
err = PTR_ERR(core->kthread);
printk(KERN_ERR "%s/0: failed to create cx88 audio thread, err=%d\n",
core->name, err);
}
}
mutex_unlock(&core->lock);
return 0;
fail_unreg:
cx8800_unregister_video(dev);
free_irq(pci_dev->irq, dev);
mutex_unlock(&core->lock);
fail_core:
vb2_dma_sg_cleanup_ctx(dev->alloc_ctx);
core->v4ldev = NULL;
cx88_core_put(core,dev->pci);
fail_free:
kfree(dev);
return err;
}
static void cx8800_finidev(struct pci_dev *pci_dev)
{
struct cx8800_dev *dev = pci_get_drvdata(pci_dev);
struct cx88_core *core = dev->core;
if (core->kthread) {
kthread_stop(core->kthread);
core->kthread = NULL;
}
if (core->ir)
cx88_ir_stop(core);
cx88_shutdown(core);
free_irq(pci_dev->irq, dev);
cx8800_unregister_video(dev);
pci_disable_device(pci_dev);
core->v4ldev = NULL;
cx88_core_put(core,dev->pci);
vb2_dma_sg_cleanup_ctx(dev->alloc_ctx);
kfree(dev);
}
static int cx8800_suspend(struct pci_dev *pci_dev, pm_message_t state)
{
struct cx8800_dev *dev = pci_get_drvdata(pci_dev);
struct cx88_core *core = dev->core;
unsigned long flags;
spin_lock_irqsave(&dev->slock, flags);
if (!list_empty(&dev->vidq.active)) {
printk("%s/0: suspend video\n", core->name);
stop_video_dma(dev);
}
if (!list_empty(&dev->vbiq.active)) {
printk("%s/0: suspend vbi\n", core->name);
cx8800_stop_vbi_dma(dev);
}
spin_unlock_irqrestore(&dev->slock, flags);
if (core->ir)
cx88_ir_stop(core);
cx88_shutdown(core);
pci_save_state(pci_dev);
if (0 != pci_set_power_state(pci_dev, pci_choose_state(pci_dev, state))) {
pci_disable_device(pci_dev);
dev->state.disabled = 1;
}
return 0;
}
static int cx8800_resume(struct pci_dev *pci_dev)
{
struct cx8800_dev *dev = pci_get_drvdata(pci_dev);
struct cx88_core *core = dev->core;
unsigned long flags;
int err;
if (dev->state.disabled) {
err=pci_enable_device(pci_dev);
if (err) {
printk(KERN_ERR "%s/0: can't enable device\n",
core->name);
return err;
}
dev->state.disabled = 0;
}
err= pci_set_power_state(pci_dev, PCI_D0);
if (err) {
printk(KERN_ERR "%s/0: can't set power state\n", core->name);
pci_disable_device(pci_dev);
dev->state.disabled = 1;
return err;
}
pci_restore_state(pci_dev);
cx88_reset(core);
if (core->ir)
cx88_ir_start(core);
cx_set(MO_PCI_INTMSK, core->pci_irqmask);
spin_lock_irqsave(&dev->slock, flags);
if (!list_empty(&dev->vidq.active)) {
printk("%s/0: resume video\n", core->name);
restart_video_queue(dev,&dev->vidq);
}
if (!list_empty(&dev->vbiq.active)) {
printk("%s/0: resume vbi\n", core->name);
cx8800_restart_vbi_queue(dev,&dev->vbiq);
}
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
}
