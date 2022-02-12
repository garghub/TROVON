static void host_setup(struct cx88_core *core)
{
cx_write(MO_GPHST_SOFT_RST, 1);
udelay(100);
cx_write(MO_GPHST_SOFT_RST, 0);
udelay(100);
cx_write(MO_GPHST_WSC, 0x44444444U);
cx_write(MO_GPHST_XFR, 0);
cx_write(MO_GPHST_WDTH, 15);
cx_write(MO_GPHST_HDSHK, 0);
cx_write(MO_GPHST_MUX16, 0x44448888U);
cx_write(MO_GPHST_MODE, 0);
}
static int wait_ready_gpio0_bit1(struct cx88_core *core, u32 state)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1);
u32 gpio0, need;
need = state ? 2 : 0;
for (;;) {
gpio0 = cx_read(MO_GP0_IO) & 2;
if (need == gpio0)
return 0;
if (time_after(jiffies, timeout))
return -1;
udelay(1);
}
}
static int memory_write(struct cx88_core *core, u32 address, u32 value)
{
cx_writeb(P1_MDATA0, (unsigned int)value);
cx_writeb(P1_MDATA1, (unsigned int)(value >> 8));
cx_writeb(P1_MDATA2, (unsigned int)(value >> 16));
cx_writeb(P1_MDATA3, (unsigned int)(value >> 24));
cx_writeb(P1_MADDR2, (unsigned int)(address >> 16) | 0x40);
cx_writeb(P1_MADDR1, (unsigned int)(address >> 8));
cx_writeb(P1_MADDR0, (unsigned int)address);
cx_read(P1_MDATA0);
cx_read(P1_MADDR0);
return wait_ready_gpio0_bit1(core, 1);
}
static int memory_read(struct cx88_core *core, u32 address, u32 *value)
{
int retval;
u32 val;
cx_writeb(P1_MADDR2, (unsigned int)(address >> 16) & ~0xC0);
cx_writeb(P1_MADDR1, (unsigned int)(address >> 8));
cx_writeb(P1_MADDR0, (unsigned int)address);
cx_read(P1_MADDR0);
retval = wait_ready_gpio0_bit1(core, 1);
cx_writeb(P1_MDATA3, 0);
val = (unsigned char)cx_read(P1_MDATA3) << 24;
cx_writeb(P1_MDATA2, 0);
val |= (unsigned char)cx_read(P1_MDATA2) << 16;
cx_writeb(P1_MDATA1, 0);
val |= (unsigned char)cx_read(P1_MDATA1) << 8;
cx_writeb(P1_MDATA0, 0);
val |= (unsigned char)cx_read(P1_MDATA0);
*value = val;
return retval;
}
static int register_write(struct cx88_core *core, u32 address, u32 value)
{
cx_writeb(P1_RDATA0, (unsigned int)value);
cx_writeb(P1_RDATA1, (unsigned int)(value >> 8));
cx_writeb(P1_RDATA2, (unsigned int)(value >> 16));
cx_writeb(P1_RDATA3, (unsigned int)(value >> 24));
cx_writeb(P1_RADDR0, (unsigned int)address);
cx_writeb(P1_RADDR1, (unsigned int)(address >> 8));
cx_writeb(P1_RRDWR, 1);
cx_read(P1_RDATA0);
cx_read(P1_RADDR0);
return wait_ready_gpio0_bit1(core, 1);
}
static int register_read(struct cx88_core *core, u32 address, u32 *value)
{
int retval;
u32 val;
cx_writeb(P1_RADDR0, (unsigned int)address);
cx_writeb(P1_RADDR1, (unsigned int)(address >> 8));
cx_writeb(P1_RRDWR, 0);
cx_read(P1_RADDR0);
retval = wait_ready_gpio0_bit1(core, 1);
val = (unsigned char)cx_read(P1_RDATA0);
val |= (unsigned char)cx_read(P1_RDATA1) << 8;
val |= (unsigned char)cx_read(P1_RDATA2) << 16;
val |= (unsigned char)cx_read(P1_RDATA3) << 24;
*value = val;
return retval;
}
static int blackbird_mbox_func(void *priv, u32 command, int in,
int out, u32 data[CX2341X_MBOX_MAX_DATA])
{
struct cx8802_dev *dev = priv;
unsigned long timeout;
u32 value, flag, retval;
int i;
dprintk(1, "%s: 0x%X\n", __func__, command);
memory_read(dev->core, dev->mailbox - 4, &value);
if (value != 0x12345678) {
dprintk(0,
"Firmware and/or mailbox pointer not initialized or corrupted\n");
return -EIO;
}
memory_read(dev->core, dev->mailbox, &flag);
if (flag) {
dprintk(0, "ERROR: Mailbox appears to be in use (%x)\n", flag);
return -EIO;
}
flag |= 1;
memory_write(dev->core, dev->mailbox, flag);
memory_write(dev->core, dev->mailbox + 1, command);
memory_write(dev->core, dev->mailbox + 3, IVTV_API_STD_TIMEOUT);
for (i = 0; i < in; i++) {
memory_write(dev->core, dev->mailbox + 4 + i, data[i]);
dprintk(1, "API Input %d = %d\n", i, data[i]);
}
for (; i < CX2341X_MBOX_MAX_DATA; i++)
memory_write(dev->core, dev->mailbox + 4 + i, 0);
flag |= 3;
memory_write(dev->core, dev->mailbox, flag);
timeout = jiffies + msecs_to_jiffies(1000);
for (;;) {
memory_read(dev->core, dev->mailbox, &flag);
if (0 != (flag & 4))
break;
if (time_after(jiffies, timeout)) {
dprintk(0, "ERROR: API Mailbox timeout %x\n", command);
return -EIO;
}
udelay(10);
}
for (i = 0; i < out; i++) {
memory_read(dev->core, dev->mailbox + 4 + i, data + i);
dprintk(1, "API Output %d = %d\n", i, data[i]);
}
memory_read(dev->core, dev->mailbox + 2, &retval);
dprintk(1, "API result = %d\n", retval);
flag = 0;
memory_write(dev->core, dev->mailbox, flag);
return retval;
}
static int blackbird_api_cmd(struct cx8802_dev *dev, u32 command,
u32 inputcnt, u32 outputcnt, ...)
{
u32 data[CX2341X_MBOX_MAX_DATA];
va_list vargs;
int i, err;
va_start(vargs, outputcnt);
for (i = 0; i < inputcnt; i++)
data[i] = va_arg(vargs, int);
err = blackbird_mbox_func(dev, command, inputcnt, outputcnt, data);
for (i = 0; i < outputcnt; i++) {
int *vptr = va_arg(vargs, int *);
*vptr = data[i];
}
va_end(vargs);
return err;
}
static int blackbird_find_mailbox(struct cx8802_dev *dev)
{
u32 signature[4] = {0x12345678, 0x34567812, 0x56781234, 0x78123456};
int signaturecnt = 0;
u32 value;
int i;
for (i = 0; i < BLACKBIRD_FIRM_IMAGE_SIZE; i++) {
memory_read(dev->core, i, &value);
if (value == signature[signaturecnt])
signaturecnt++;
else
signaturecnt = 0;
if (signaturecnt == 4) {
dprintk(1, "Mailbox signature found\n");
return i + 1;
}
}
dprintk(0, "Mailbox signature values not found!\n");
return -EIO;
}
static int blackbird_load_firmware(struct cx8802_dev *dev)
{
static const unsigned char magic[8] = {
0xa7, 0x0d, 0x00, 0x00, 0x66, 0xbb, 0x55, 0xaa
};
const struct firmware *firmware;
int i, retval = 0;
u32 value = 0;
u32 checksum = 0;
__le32 *dataptr;
retval = register_write(dev->core, IVTV_REG_VPU, 0xFFFFFFED);
retval |= register_write(dev->core, IVTV_REG_HW_BLOCKS,
IVTV_CMD_HW_BLOCKS_RST);
retval |= register_write(dev->core, IVTV_REG_ENC_SDRAM_REFRESH,
0x80000640);
retval |= register_write(dev->core, IVTV_REG_ENC_SDRAM_PRECHARGE,
0x1A);
usleep_range(10000, 20000);
retval |= register_write(dev->core, IVTV_REG_APU, 0);
if (retval < 0)
dprintk(0, "Error with register_write\n");
retval = request_firmware(&firmware, CX2341X_FIRM_ENC_FILENAME,
&dev->pci->dev);
if (retval != 0) {
pr_err("Hotplug firmware request failed (%s).\n",
CX2341X_FIRM_ENC_FILENAME);
pr_err("Please fix your hotplug setup, the board will not work without firmware loaded!\n");
return -EIO;
}
if (firmware->size != BLACKBIRD_FIRM_IMAGE_SIZE) {
pr_err("Firmware size mismatch (have %zd, expected %d)\n",
firmware->size, BLACKBIRD_FIRM_IMAGE_SIZE);
release_firmware(firmware);
return -EINVAL;
}
if (memcmp(firmware->data, magic, 8) != 0) {
pr_err("Firmware magic mismatch, wrong file?\n");
release_firmware(firmware);
return -EINVAL;
}
dprintk(1, "Loading firmware ...\n");
dataptr = (__le32 *)firmware->data;
for (i = 0; i < (firmware->size >> 2); i++) {
value = le32_to_cpu(*dataptr);
checksum += ~value;
memory_write(dev->core, i, value);
dataptr++;
}
for (i--; i >= 0; i--) {
memory_read(dev->core, i, &value);
checksum -= ~value;
}
release_firmware(firmware);
if (checksum) {
pr_err("Firmware load might have failed (checksum mismatch).\n");
return -EIO;
}
dprintk(0, "Firmware upload successful.\n");
retval |= register_write(dev->core, IVTV_REG_HW_BLOCKS,
IVTV_CMD_HW_BLOCKS_RST);
retval |= register_read(dev->core, IVTV_REG_SPU, &value);
retval |= register_write(dev->core, IVTV_REG_SPU, value & 0xFFFFFFFE);
usleep_range(10000, 20000);
retval |= register_read(dev->core, IVTV_REG_VPU, &value);
retval |= register_write(dev->core, IVTV_REG_VPU, value & 0xFFFFFFE8);
if (retval < 0)
dprintk(0, "Error with register_write\n");
return 0;
}
static void blackbird_codec_settings(struct cx8802_dev *dev)
{
struct cx88_core *core = dev->core;
blackbird_api_cmd(dev, CX2341X_ENC_SET_FRAME_SIZE, 2, 0,
core->height, core->width);
dev->cxhdl.width = core->width;
dev->cxhdl.height = core->height;
cx2341x_handler_set_50hz(&dev->cxhdl,
dev->core->tvnorm & V4L2_STD_625_50);
cx2341x_handler_setup(&dev->cxhdl);
}
static int blackbird_initialize_codec(struct cx8802_dev *dev)
{
struct cx88_core *core = dev->core;
int version;
int retval;
dprintk(1, "Initialize codec\n");
retval = blackbird_api_cmd(dev, CX2341X_ENC_PING_FW, 0, 0);
if (retval < 0) {
cx_write(MO_SRST_IO, 0);
cx_write(MO_SRST_IO, 1);
retval = blackbird_load_firmware(dev);
if (retval < 0)
return retval;
retval = blackbird_find_mailbox(dev);
if (retval < 0)
return -1;
dev->mailbox = retval;
retval = blackbird_api_cmd(dev, CX2341X_ENC_PING_FW, 0, 0);
if (retval < 0) {
dprintk(0, "ERROR: Firmware ping failed!\n");
return -1;
}
retval = blackbird_api_cmd(dev, CX2341X_ENC_GET_VERSION,
0, 1, &version);
if (retval < 0) {
dprintk(0,
"ERROR: Firmware get encoder version failed!\n");
return -1;
}
dprintk(0, "Firmware version is 0x%08x\n", version);
}
cx_write(MO_PINMUX_IO, 0x88);
cx_clear(MO_INPUT_FORMAT, 0x100);
cx_write(MO_VBOS_CONTROL, 0x84A00);
cx_clear(MO_OUTPUT_FORMAT, 0x0008);
blackbird_codec_settings(dev);
blackbird_api_cmd(dev, CX2341X_ENC_SET_NUM_VSYNC_LINES, 2, 0,
BLACKBIRD_FIELD1_SAA7115, BLACKBIRD_FIELD2_SAA7115);
blackbird_api_cmd(dev, CX2341X_ENC_SET_PLACEHOLDER, 12, 0,
BLACKBIRD_CUSTOM_EXTENSION_USR_DATA,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
return 0;
}
static int blackbird_start_codec(struct cx8802_dev *dev)
{
struct cx88_core *core = dev->core;
u32 reg;
int i;
int lastchange = -1;
int lastval = 0;
for (i = 0; (i < 10) && (i < (lastchange + 4)); i++) {
reg = cx_read(AUD_STATUS);
dprintk(1, "AUD_STATUS:%dL: 0x%x\n", i, reg);
if ((reg & 0x0F) != lastval) {
lastval = reg & 0x0F;
lastchange = i;
}
msleep(100);
}
cx_clear(AUD_VOL_CTL, (1 << 6));
blackbird_api_cmd(dev, CX2341X_ENC_REFRESH_INPUT, 0, 0);
blackbird_api_cmd(dev, CX2341X_ENC_INITIALIZE_INPUT, 0, 0);
cx2341x_handler_set_busy(&dev->cxhdl, 1);
blackbird_api_cmd(dev, CX2341X_ENC_START_CAPTURE, 2, 0,
BLACKBIRD_MPEG_CAPTURE, BLACKBIRD_RAW_BITS_NONE);
return 0;
}
static int blackbird_stop_codec(struct cx8802_dev *dev)
{
blackbird_api_cmd(dev, CX2341X_ENC_STOP_CAPTURE, 3, 0,
BLACKBIRD_END_NOW,
BLACKBIRD_MPEG_CAPTURE,
BLACKBIRD_RAW_BITS_NONE);
cx2341x_handler_set_busy(&dev->cxhdl, 0);
return 0;
}
static int queue_setup(struct vb2_queue *q,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct cx8802_dev *dev = q->drv_priv;
*num_planes = 1;
dev->ts_packet_size = 188 * 4;
dev->ts_packet_count = 32;
sizes[0] = dev->ts_packet_size * dev->ts_packet_count;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx8802_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vbuf, struct cx88_buffer, vb);
return cx8802_buf_prepare(vb->vb2_queue, dev, buf);
}
static void buffer_finish(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx8802_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vbuf, struct cx88_buffer, vb);
struct cx88_riscmem *risc = &buf->risc;
if (risc->cpu)
pci_free_consistent(dev->pci, risc->size, risc->cpu, risc->dma);
memset(risc, 0, sizeof(*risc));
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx8802_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vbuf, struct cx88_buffer, vb);
cx8802_buf_queue(dev, buf);
}
static int start_streaming(struct vb2_queue *q, unsigned int count)
{
struct cx8802_dev *dev = q->drv_priv;
struct cx88_dmaqueue *dmaq = &dev->mpegq;
struct cx8802_driver *drv;
struct cx88_buffer *buf;
unsigned long flags;
int err;
drv = cx8802_get_driver(dev, CX88_MPEG_BLACKBIRD);
if (!drv) {
dprintk(1, "%s: blackbird driver is not loaded\n", __func__);
err = -ENODEV;
goto fail;
}
err = drv->request_acquire(drv);
if (err != 0) {
dprintk(1, "%s: Unable to acquire hardware, %d\n", __func__,
err);
goto fail;
}
if (blackbird_initialize_codec(dev) < 0) {
drv->request_release(drv);
err = -EINVAL;
goto fail;
}
err = blackbird_start_codec(dev);
if (err == 0) {
buf = list_entry(dmaq->active.next, struct cx88_buffer, list);
cx8802_start_dma(dev, dmaq, buf);
return 0;
}
fail:
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&dmaq->active)) {
struct cx88_buffer *buf = list_entry(dmaq->active.next,
struct cx88_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_QUEUED);
}
spin_unlock_irqrestore(&dev->slock, flags);
return err;
}
static void stop_streaming(struct vb2_queue *q)
{
struct cx8802_dev *dev = q->drv_priv;
struct cx88_dmaqueue *dmaq = &dev->mpegq;
struct cx8802_driver *drv = NULL;
unsigned long flags;
cx8802_cancel_buffers(dev);
blackbird_stop_codec(dev);
drv = cx8802_get_driver(dev, CX88_MPEG_BLACKBIRD);
WARN_ON(!drv);
if (drv)
drv->request_release(drv);
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&dmaq->active)) {
struct cx88_buffer *buf = list_entry(dmaq->active.next,
struct cx88_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
strcpy(cap->driver, "cx88_blackbird");
sprintf(cap->bus_info, "PCI:%s", pci_name(dev->pci));
cx88_querycap(file, core, cap);
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
strlcpy(f->description, "MPEG", sizeof(f->description));
f->pixelformat = V4L2_PIX_FMT_MPEG;
f->flags = V4L2_FMT_FLAG_COMPRESSED;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = dev->ts_packet_size * dev->ts_packet_count;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.width = core->width;
f->fmt.pix.height = core->height;
f->fmt.pix.field = core->field;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
unsigned int maxw, maxh;
enum v4l2_field field;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = dev->ts_packet_size * dev->ts_packet_count;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
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
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (vb2_is_busy(&dev->vb2_mpegq))
return -EBUSY;
if (core->v4ldev && (vb2_is_busy(&core->v4ldev->vb2_vidq) ||
vb2_is_busy(&core->v4ldev->vb2_vbiq)))
return -EBUSY;
vidioc_try_fmt_vid_cap(file, priv, f);
core->width = f->fmt.pix.width;
core->height = f->fmt.pix.height;
core->field = f->fmt.pix.field;
cx88_set_scale(core, f->fmt.pix.width, f->fmt.pix.height,
f->fmt.pix.field);
blackbird_api_cmd(dev, CX2341X_ENC_SET_FRAME_SIZE, 2, 0,
f->fmt.pix.height, f->fmt.pix.width);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
bool streaming;
if (unlikely(core->board.tuner_type == UNSET))
return -EINVAL;
if (unlikely(f->tuner != 0))
return -EINVAL;
streaming = vb2_start_streaming_called(&dev->vb2_mpegq);
if (streaming)
blackbird_stop_codec(dev);
cx88_set_freq(core, f);
blackbird_initialize_codec(dev);
cx88_set_scale(core, core->width, core->height, core->field);
if (streaming)
blackbird_start_codec(dev);
return 0;
}
static int vidioc_log_status(struct file *file, void *priv)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
char name[32 + 2];
snprintf(name, sizeof(name), "%s/2", core->name);
call_all(core, core, log_status);
v4l2_ctrl_handler_log_status(&dev->cxhdl.hdl, name);
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
return cx88_enum_input(core, i);
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (unlikely(core->board.tuner_type == UNSET))
return -EINVAL;
if (unlikely(f->tuner != 0))
return -EINVAL;
f->frequency = core->freq;
call_all(core, tuner, g_frequency, f);
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
*i = core->input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (i >= 4)
return -EINVAL;
if (!INPUT(i).type)
return -EINVAL;
cx88_newstation(core);
cx88_video_mux(core, i);
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
u32 reg;
if (unlikely(core->board.tuner_type == UNSET))
return -EINVAL;
if (t->index != 0)
return -EINVAL;
strcpy(t->name, "Television");
t->capability = V4L2_TUNER_CAP_NORM;
t->rangehigh = 0xffffffffUL;
call_all(core, tuner, g_tuner, t);
cx88_get_stereo(core, t);
reg = cx_read(MO_DEVICE_STATUS);
t->signal = (reg & (1 << 5)) ? 0xffff : 0x0000;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *t)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
if (core->board.tuner_type == UNSET)
return -EINVAL;
if (t->index != 0)
return -EINVAL;
cx88_set_stereo(core, t->audmode, 1);
return 0;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *tvnorm)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
*tvnorm = core->tvnorm;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id id)
{
struct cx8802_dev *dev = video_drvdata(file);
struct cx88_core *core = dev->core;
return cx88_set_tvnorm(core, id);
}
static int cx8802_blackbird_advise_acquire(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
int err = 0;
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_HVR1300:
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
cx_clear(MO_GP0_IO, 0x00000080);
udelay(50);
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
cx_set(MO_GP0_IO, 0x00000004);
udelay(1000);
break;
default:
err = -ENODEV;
}
return err;
}
static int cx8802_blackbird_advise_release(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
int err = 0;
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_HVR1300:
break;
default:
err = -ENODEV;
}
return err;
}
static void blackbird_unregister_video(struct cx8802_dev *dev)
{
video_unregister_device(&dev->mpeg_dev);
}
static int blackbird_register_video(struct cx8802_dev *dev)
{
int err;
cx88_vdev_init(dev->core, dev->pci, &dev->mpeg_dev,
&cx8802_mpeg_template, "mpeg");
dev->mpeg_dev.ctrl_handler = &dev->cxhdl.hdl;
video_set_drvdata(&dev->mpeg_dev, dev);
dev->mpeg_dev.queue = &dev->vb2_mpegq;
err = video_register_device(&dev->mpeg_dev, VFL_TYPE_GRABBER, -1);
if (err < 0) {
pr_info("can't register mpeg device\n");
return err;
}
pr_info("registered device %s [mpeg]\n",
video_device_node_name(&dev->mpeg_dev));
return 0;
}
static int cx8802_blackbird_probe(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
struct cx8802_dev *dev = core->dvbdev;
struct vb2_queue *q;
int err;
dprintk(1, "%s\n", __func__);
dprintk(1, " ->being probed by Card=%d Name=%s, PCI %02x:%02x\n",
core->boardnr,
core->name,
core->pci_bus,
core->pci_slot);
err = -ENODEV;
if (!(core->board.mpeg & CX88_MPEG_BLACKBIRD))
goto fail_core;
dev->cxhdl.port = CX2341X_PORT_STREAMING;
dev->cxhdl.width = core->width;
dev->cxhdl.height = core->height;
dev->cxhdl.func = blackbird_mbox_func;
dev->cxhdl.priv = dev;
err = cx2341x_handler_init(&dev->cxhdl, 36);
if (err)
goto fail_core;
v4l2_ctrl_add_handler(&dev->cxhdl.hdl, &core->video_hdl, NULL);
pr_info("cx23416 based mpeg encoder (blackbird reference design)\n");
host_setup(dev->core);
blackbird_initialize_codec(dev);
cx88_set_tvnorm(core, core->tvnorm);
cx88_video_mux(core, 0);
cx2341x_handler_set_50hz(&dev->cxhdl, core->height == 576);
cx2341x_handler_setup(&dev->cxhdl);
q = &dev->vb2_mpegq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct cx88_buffer);
q->ops = &blackbird_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &core->lock;
q->dev = &dev->pci->dev;
err = vb2_queue_init(q);
if (err < 0)
goto fail_core;
blackbird_register_video(dev);
return 0;
fail_core:
return err;
}
static int cx8802_blackbird_remove(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
struct cx8802_dev *dev = core->dvbdev;
blackbird_unregister_video(drv->core->dvbdev);
v4l2_ctrl_handler_free(&dev->cxhdl.hdl);
return 0;
}
static int __init blackbird_init(void)
{
pr_info("cx2388x blackbird driver version %s loaded\n",
CX88_VERSION);
return cx8802_register_driver(&cx8802_blackbird_driver);
}
static void __exit blackbird_fini(void)
{
cx8802_unregister_driver(&cx8802_blackbird_driver);
}
