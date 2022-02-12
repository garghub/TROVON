static struct msi2500_frame_buf *msi2500_get_next_fill_buf(
struct msi2500_dev *dev)
{
unsigned long flags;
struct msi2500_frame_buf *buf = NULL;
spin_lock_irqsave(&dev->queued_bufs_lock, flags);
if (list_empty(&dev->queued_bufs))
goto leave;
buf = list_entry(dev->queued_bufs.next, struct msi2500_frame_buf, list);
list_del(&buf->list);
leave:
spin_unlock_irqrestore(&dev->queued_bufs_lock, flags);
return buf;
}
static int msi2500_convert_stream(struct msi2500_dev *dev, u8 *dst, u8 *src,
unsigned int src_len)
{
unsigned int i, j, transactions, dst_len = 0;
u32 sample[3];
transactions = src_len / 1024;
for (i = 0; i < transactions; i++) {
sample[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 |
src[0] << 0;
if (i == 0 && dev->next_sample != sample[0]) {
dev_dbg_ratelimited(dev->dev,
"%d samples lost, %d %08x:%08x\n",
sample[0] - dev->next_sample,
src_len, dev->next_sample,
sample[0]);
}
dev_dbg_ratelimited(dev->dev, "%*ph\n", 12, &src[4]);
src += 16;
switch (dev->pixelformat) {
case V4L2_SDR_FMT_CU8:
{
s8 *s8src = (s8 *)src;
u8 *u8dst = (u8 *)dst;
for (j = 0; j < 1008; j++)
*u8dst++ = *s8src++ + 128;
src += 1008;
dst += 1008;
dst_len += 1008;
dev->next_sample = sample[i] + 504;
break;
}
case V4L2_SDR_FMT_CU16LE:
{
s16 *s16src = (s16 *)src;
u16 *u16dst = (u16 *)dst;
struct {signed int x:14; } se;
unsigned int utmp;
for (j = 0; j < 1008; j += 2) {
se.x = *s16src++;
utmp = se.x + 8192;
*u16dst++ = utmp << 2 | utmp >> 12;
}
src += 1008;
dst += 1008;
dst_len += 1008;
dev->next_sample = sample[i] + 252;
break;
}
case MSI2500_PIX_FMT_SDR_MSI2500_384:
dev_dbg_ratelimited(dev->dev, "%*ph\n", 24, &src[1000]);
memcpy(dst, src, 984);
src += 984 + 24;
dst += 984;
dst_len += 984;
dev->next_sample = sample[i] + 384;
break;
case V4L2_SDR_FMT_CS8:
memcpy(dst, src, 1008);
src += 1008;
dst += 1008;
dst_len += 1008;
dev->next_sample = sample[i] + 504;
break;
case MSI2500_PIX_FMT_SDR_S12:
memcpy(dst, src, 1008);
src += 1008;
dst += 1008;
dst_len += 1008;
dev->next_sample = sample[i] + 336;
break;
case V4L2_SDR_FMT_CS14LE:
memcpy(dst, src, 1008);
src += 1008;
dst += 1008;
dst_len += 1008;
dev->next_sample = sample[i] + 252;
break;
default:
break;
}
}
if (unlikely(time_is_before_jiffies(dev->jiffies_next))) {
#define MSECS 10000UL
unsigned int msecs = jiffies_to_msecs(jiffies -
dev->jiffies_next + msecs_to_jiffies(MSECS));
unsigned int samples = dev->next_sample - dev->sample;
dev->jiffies_next = jiffies + msecs_to_jiffies(MSECS);
dev->sample = dev->next_sample;
dev_dbg(dev->dev, "size=%u samples=%u msecs=%u sample rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
return dst_len;
}
static void msi2500_isoc_handler(struct urb *urb)
{
struct msi2500_dev *dev = (struct msi2500_dev *)urb->context;
int i, flen, fstatus;
unsigned char *iso_buf = NULL;
struct msi2500_frame_buf *fbuf;
if (unlikely(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN)) {
dev_dbg(dev->dev, "URB (%p) unlinked %ssynchronuously\n",
urb, urb->status == -ENOENT ? "" : "a");
return;
}
if (unlikely(urb->status != 0)) {
dev_dbg(dev->dev, "called with status %d\n", urb->status);
if (++dev->isoc_errors > MAX_ISOC_ERRORS)
dev_dbg(dev->dev, "Too many ISOC errors, bailing out\n");
goto handler_end;
} else {
dev->isoc_errors = 0;
}
for (i = 0; i < urb->number_of_packets; i++) {
void *ptr;
fstatus = urb->iso_frame_desc[i].status;
if (unlikely(fstatus)) {
dev_dbg_ratelimited(dev->dev,
"frame=%d/%d has error %d skipping\n",
i, urb->number_of_packets, fstatus);
continue;
}
flen = urb->iso_frame_desc[i].actual_length;
if (unlikely(flen == 0))
continue;
iso_buf = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
fbuf = msi2500_get_next_fill_buf(dev);
if (unlikely(fbuf == NULL)) {
dev->vb_full++;
dev_dbg_ratelimited(dev->dev,
"videobuf is full, %d packets dropped\n",
dev->vb_full);
continue;
}
ptr = vb2_plane_vaddr(&fbuf->vb.vb2_buf, 0);
flen = msi2500_convert_stream(dev, ptr, iso_buf, flen);
vb2_set_plane_payload(&fbuf->vb.vb2_buf, 0, flen);
vb2_buffer_done(&fbuf->vb.vb2_buf, VB2_BUF_STATE_DONE);
}
handler_end:
i = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(i != 0))
dev_dbg(dev->dev, "Error (%d) re-submitting urb\n", i);
}
static void msi2500_iso_stop(struct msi2500_dev *dev)
{
int i;
dev_dbg(dev->dev, "\n");
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (dev->urbs[i]) {
dev_dbg(dev->dev, "Unlinking URB %p\n", dev->urbs[i]);
usb_kill_urb(dev->urbs[i]);
}
}
}
static void msi2500_iso_free(struct msi2500_dev *dev)
{
int i;
dev_dbg(dev->dev, "\n");
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (dev->urbs[i]) {
dev_dbg(dev->dev, "Freeing URB\n");
if (dev->urbs[i]->transfer_buffer) {
usb_free_coherent(dev->udev,
dev->urbs[i]->transfer_buffer_length,
dev->urbs[i]->transfer_buffer,
dev->urbs[i]->transfer_dma);
}
usb_free_urb(dev->urbs[i]);
dev->urbs[i] = NULL;
}
}
}
static void msi2500_isoc_cleanup(struct msi2500_dev *dev)
{
dev_dbg(dev->dev, "\n");
msi2500_iso_stop(dev);
msi2500_iso_free(dev);
}
static int msi2500_isoc_init(struct msi2500_dev *dev)
{
struct urb *urb;
int i, j, ret;
dev_dbg(dev->dev, "\n");
dev->isoc_errors = 0;
ret = usb_set_interface(dev->udev, 0, 1);
if (ret)
return ret;
for (i = 0; i < MAX_ISO_BUFS; i++) {
urb = usb_alloc_urb(ISO_FRAMES_PER_DESC, GFP_KERNEL);
if (urb == NULL) {
msi2500_isoc_cleanup(dev);
return -ENOMEM;
}
dev->urbs[i] = urb;
dev_dbg(dev->dev, "Allocated URB at 0x%p\n", urb);
urb->interval = 1;
urb->dev = dev->udev;
urb->pipe = usb_rcvisocpipe(dev->udev, 0x81);
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer = usb_alloc_coherent(dev->udev,
ISO_BUFFER_SIZE,
GFP_KERNEL, &urb->transfer_dma);
if (urb->transfer_buffer == NULL) {
dev_err(dev->dev,
"Failed to allocate urb buffer %d\n", i);
msi2500_isoc_cleanup(dev);
return -ENOMEM;
}
urb->transfer_buffer_length = ISO_BUFFER_SIZE;
urb->complete = msi2500_isoc_handler;
urb->context = dev;
urb->start_frame = 0;
urb->number_of_packets = ISO_FRAMES_PER_DESC;
for (j = 0; j < ISO_FRAMES_PER_DESC; j++) {
urb->iso_frame_desc[j].offset = j * ISO_MAX_FRAME_SIZE;
urb->iso_frame_desc[j].length = ISO_MAX_FRAME_SIZE;
}
}
for (i = 0; i < MAX_ISO_BUFS; i++) {
ret = usb_submit_urb(dev->urbs[i], GFP_KERNEL);
if (ret) {
dev_err(dev->dev,
"usb_submit_urb %d failed with error %d\n",
i, ret);
msi2500_isoc_cleanup(dev);
return ret;
}
dev_dbg(dev->dev, "URB 0x%p submitted.\n", dev->urbs[i]);
}
return 0;
}
static void msi2500_cleanup_queued_bufs(struct msi2500_dev *dev)
{
unsigned long flags;
dev_dbg(dev->dev, "\n");
spin_lock_irqsave(&dev->queued_bufs_lock, flags);
while (!list_empty(&dev->queued_bufs)) {
struct msi2500_frame_buf *buf;
buf = list_entry(dev->queued_bufs.next,
struct msi2500_frame_buf, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->queued_bufs_lock, flags);
}
static void msi2500_disconnect(struct usb_interface *intf)
{
struct v4l2_device *v = usb_get_intfdata(intf);
struct msi2500_dev *dev =
container_of(v, struct msi2500_dev, v4l2_dev);
dev_dbg(dev->dev, "\n");
mutex_lock(&dev->vb_queue_lock);
mutex_lock(&dev->v4l2_lock);
dev->udev = NULL;
v4l2_device_disconnect(&dev->v4l2_dev);
video_unregister_device(&dev->vdev);
spi_unregister_master(dev->master);
mutex_unlock(&dev->v4l2_lock);
mutex_unlock(&dev->vb_queue_lock);
v4l2_device_put(&dev->v4l2_dev);
}
static int msi2500_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct msi2500_dev *dev = video_drvdata(file);
dev_dbg(dev->dev, "\n");
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, dev->vdev.name, sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE | V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int msi2500_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers,
unsigned int *nplanes, unsigned int sizes[],
struct device *alloc_devs[])
{
struct msi2500_dev *dev = vb2_get_drv_priv(vq);
dev_dbg(dev->dev, "nbuffers=%d\n", *nbuffers);
*nbuffers = clamp_t(unsigned int, *nbuffers, 8, 32);
*nplanes = 1;
sizes[0] = PAGE_ALIGN(dev->buffersize);
dev_dbg(dev->dev, "nbuffers=%d sizes[0]=%d\n", *nbuffers, sizes[0]);
return 0;
}
static void msi2500_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct msi2500_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
struct msi2500_frame_buf *buf = container_of(vbuf,
struct msi2500_frame_buf,
vb);
unsigned long flags;
if (unlikely(!dev->udev)) {
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
return;
}
spin_lock_irqsave(&dev->queued_bufs_lock, flags);
list_add_tail(&buf->list, &dev->queued_bufs);
spin_unlock_irqrestore(&dev->queued_bufs_lock, flags);
}
static int msi2500_ctrl_msg(struct msi2500_dev *dev, u8 cmd, u32 data)
{
int ret;
u8 request = cmd;
u8 requesttype = USB_DIR_OUT | USB_TYPE_VENDOR;
u16 value = (data >> 0) & 0xffff;
u16 index = (data >> 16) & 0xffff;
msi2500_dbg_usb_control_msg(dev->dev, request, requesttype,
value, index, NULL, 0);
ret = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, 0), request,
requesttype, value, index, NULL, 0, 2000);
if (ret)
dev_err(dev->dev, "failed %d, cmd %02x, data %04x\n",
ret, cmd, data);
return ret;
}
static int msi2500_set_usb_adc(struct msi2500_dev *dev)
{
int ret;
unsigned int f_vco, f_sr, div_n, k, k_cw, div_out;
u32 reg3, reg4, reg7;
struct v4l2_ctrl *bandwidth_auto;
struct v4l2_ctrl *bandwidth;
f_sr = dev->f_adc;
bandwidth_auto = v4l2_ctrl_find(&dev->hdl,
V4L2_CID_RF_TUNER_BANDWIDTH_AUTO);
if (v4l2_ctrl_g_ctrl(bandwidth_auto)) {
bandwidth = v4l2_ctrl_find(&dev->hdl,
V4L2_CID_RF_TUNER_BANDWIDTH);
v4l2_ctrl_s_ctrl(bandwidth, dev->f_adc);
}
switch (dev->pixelformat) {
case V4L2_SDR_FMT_CU8:
reg7 = 0x000c9407;
break;
case V4L2_SDR_FMT_CU16LE:
reg7 = 0x00009407;
break;
case V4L2_SDR_FMT_CS8:
reg7 = 0x000c9407;
break;
case MSI2500_PIX_FMT_SDR_MSI2500_384:
reg7 = 0x0000a507;
break;
case MSI2500_PIX_FMT_SDR_S12:
reg7 = 0x00008507;
break;
case V4L2_SDR_FMT_CS14LE:
reg7 = 0x00009407;
break;
default:
reg7 = 0x000c9407;
break;
}
#define F_REF 24000000
#define DIV_PRE_N 2
#define DIV_LO_OUT 12
reg3 = 0x01000303;
reg4 = 0x00000004;
if (f_sr < 6000000)
reg3 |= 0x1 << 20;
else if (f_sr < 7000000)
reg3 |= 0x5 << 20;
else if (f_sr < 8500000)
reg3 |= 0x9 << 20;
else
reg3 |= 0xd << 20;
for (div_out = 4; div_out < 16; div_out += 2) {
f_vco = f_sr * div_out * DIV_LO_OUT;
dev_dbg(dev->dev, "div_out=%u f_vco=%u\n", div_out, f_vco);
if (f_vco >= 202000000)
break;
}
div_n = div_u64_rem(f_vco, DIV_PRE_N * F_REF, &k);
k_cw = div_u64((u64) k * 0x200000, DIV_PRE_N * F_REF);
reg3 |= div_n << 16;
reg3 |= (div_out / 2 - 1) << 10;
reg3 |= ((k_cw >> 20) & 0x000001) << 15;
reg4 |= ((k_cw >> 0) & 0x0fffff) << 8;
dev_dbg(dev->dev,
"f_sr=%u f_vco=%u div_n=%u k=%u div_out=%u reg3=%08x reg4=%08x\n",
f_sr, f_vco, div_n, k, div_out, reg3, reg4);
ret = msi2500_ctrl_msg(dev, CMD_WREG, 0x00608008);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, 0x00000c05);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, 0x00020000);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, 0x00480102);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, 0x00f38008);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, reg7);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, reg4);
if (ret)
goto err;
ret = msi2500_ctrl_msg(dev, CMD_WREG, reg3);
err:
return ret;
}
static int msi2500_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct msi2500_dev *dev = vb2_get_drv_priv(vq);
int ret;
dev_dbg(dev->dev, "\n");
if (!dev->udev)
return -ENODEV;
if (mutex_lock_interruptible(&dev->v4l2_lock))
return -ERESTARTSYS;
v4l2_subdev_call(dev->v4l2_subdev, core, s_power, 1);
ret = msi2500_set_usb_adc(dev);
ret = msi2500_isoc_init(dev);
if (ret)
msi2500_cleanup_queued_bufs(dev);
ret = msi2500_ctrl_msg(dev, CMD_START_STREAMING, 0);
mutex_unlock(&dev->v4l2_lock);
return ret;
}
static void msi2500_stop_streaming(struct vb2_queue *vq)
{
struct msi2500_dev *dev = vb2_get_drv_priv(vq);
dev_dbg(dev->dev, "\n");
mutex_lock(&dev->v4l2_lock);
if (dev->udev)
msi2500_isoc_cleanup(dev);
msi2500_cleanup_queued_bufs(dev);
msleep(20);
if (!msi2500_ctrl_msg(dev, CMD_STOP_STREAMING, 0)) {
msi2500_ctrl_msg(dev, CMD_WREG, 0x01000003);
}
v4l2_subdev_call(dev->v4l2_subdev, core, s_power, 0);
mutex_unlock(&dev->v4l2_lock);
}
static int msi2500_enum_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct msi2500_dev *dev = video_drvdata(file);
dev_dbg(dev->dev, "index=%d\n", f->index);
if (f->index >= dev->num_formats)
return -EINVAL;
strlcpy(f->description, formats[f->index].name, sizeof(f->description));
f->pixelformat = formats[f->index].pixelformat;
return 0;
}
static int msi2500_g_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct msi2500_dev *dev = video_drvdata(file);
dev_dbg(dev->dev, "pixelformat fourcc %4.4s\n",
(char *)&dev->pixelformat);
f->fmt.sdr.pixelformat = dev->pixelformat;
f->fmt.sdr.buffersize = dev->buffersize;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
return 0;
}
static int msi2500_s_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct msi2500_dev *dev = video_drvdata(file);
struct vb2_queue *q = &dev->vb_queue;
int i;
dev_dbg(dev->dev, "pixelformat fourcc %4.4s\n",
(char *)&f->fmt.sdr.pixelformat);
if (vb2_is_busy(q))
return -EBUSY;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < dev->num_formats; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
dev->pixelformat = formats[i].pixelformat;
dev->buffersize = formats[i].buffersize;
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
dev->pixelformat = formats[0].pixelformat;
dev->buffersize = formats[0].buffersize;
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
return 0;
}
static int msi2500_try_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct msi2500_dev *dev = video_drvdata(file);
int i;
dev_dbg(dev->dev, "pixelformat fourcc %4.4s\n",
(char *)&f->fmt.sdr.pixelformat);
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < dev->num_formats; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
return 0;
}
static int msi2500_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct msi2500_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "index=%d\n", v->index);
if (v->index == 0)
ret = 0;
else if (v->index == 1)
ret = v4l2_subdev_call(dev->v4l2_subdev, tuner, s_tuner, v);
else
ret = -EINVAL;
return ret;
}
static int msi2500_g_tuner(struct file *file, void *priv, struct v4l2_tuner *v)
{
struct msi2500_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "index=%d\n", v->index);
if (v->index == 0) {
strlcpy(v->name, "Mirics MSi2500", sizeof(v->name));
v->type = V4L2_TUNER_ADC;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = 1200000;
v->rangehigh = 15000000;
ret = 0;
} else if (v->index == 1) {
ret = v4l2_subdev_call(dev->v4l2_subdev, tuner, g_tuner, v);
} else {
ret = -EINVAL;
}
return ret;
}
static int msi2500_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct msi2500_dev *dev = video_drvdata(file);
int ret = 0;
dev_dbg(dev->dev, "tuner=%d type=%d\n", f->tuner, f->type);
if (f->tuner == 0) {
f->frequency = dev->f_adc;
ret = 0;
} else if (f->tuner == 1) {
f->type = V4L2_TUNER_RF;
ret = v4l2_subdev_call(dev->v4l2_subdev, tuner, g_frequency, f);
} else {
ret = -EINVAL;
}
return ret;
}
static int msi2500_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct msi2500_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "tuner=%d type=%d frequency=%u\n",
f->tuner, f->type, f->frequency);
if (f->tuner == 0) {
dev->f_adc = clamp_t(unsigned int, f->frequency,
bands[0].rangelow,
bands[0].rangehigh);
dev_dbg(dev->dev, "ADC frequency=%u Hz\n", dev->f_adc);
ret = msi2500_set_usb_adc(dev);
} else if (f->tuner == 1) {
ret = v4l2_subdev_call(dev->v4l2_subdev, tuner, s_frequency, f);
} else {
ret = -EINVAL;
}
return ret;
}
static int msi2500_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
struct msi2500_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "tuner=%d type=%d index=%d\n",
band->tuner, band->type, band->index);
if (band->tuner == 0) {
if (band->index >= ARRAY_SIZE(bands)) {
ret = -EINVAL;
} else {
*band = bands[band->index];
ret = 0;
}
} else if (band->tuner == 1) {
ret = v4l2_subdev_call(dev->v4l2_subdev, tuner,
enum_freq_bands, band);
} else {
ret = -EINVAL;
}
return ret;
}
static void msi2500_video_release(struct v4l2_device *v)
{
struct msi2500_dev *dev = container_of(v, struct msi2500_dev, v4l2_dev);
v4l2_ctrl_handler_free(&dev->hdl);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
}
static int msi2500_transfer_one_message(struct spi_master *master,
struct spi_message *m)
{
struct msi2500_dev *dev = spi_master_get_devdata(master);
struct spi_transfer *t;
int ret = 0;
u32 data;
list_for_each_entry(t, &m->transfers, transfer_list) {
dev_dbg(dev->dev, "msg=%*ph\n", t->len, t->tx_buf);
data = 0x09;
data |= ((u8 *)t->tx_buf)[0] << 8;
data |= ((u8 *)t->tx_buf)[1] << 16;
data |= ((u8 *)t->tx_buf)[2] << 24;
ret = msi2500_ctrl_msg(dev, CMD_WREG, data);
}
m->status = ret;
spi_finalize_current_message(master);
return ret;
}
static int msi2500_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct msi2500_dev *dev;
struct v4l2_subdev *sd;
struct spi_master *master;
int ret;
static struct spi_board_info board_info = {
.modalias = "msi001",
.bus_num = 0,
.chip_select = 0,
.max_speed_hz = 12000000,
};
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err;
}
mutex_init(&dev->v4l2_lock);
mutex_init(&dev->vb_queue_lock);
spin_lock_init(&dev->queued_bufs_lock);
INIT_LIST_HEAD(&dev->queued_bufs);
dev->dev = &intf->dev;
dev->udev = interface_to_usbdev(intf);
dev->f_adc = bands[0].rangelow;
dev->pixelformat = formats[0].pixelformat;
dev->buffersize = formats[0].buffersize;
dev->num_formats = NUM_FORMATS;
if (!msi2500_emulated_fmt)
dev->num_formats -= 2;
dev->vb_queue.type = V4L2_BUF_TYPE_SDR_CAPTURE;
dev->vb_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_READ;
dev->vb_queue.drv_priv = dev;
dev->vb_queue.buf_struct_size = sizeof(struct msi2500_frame_buf);
dev->vb_queue.ops = &msi2500_vb2_ops;
dev->vb_queue.mem_ops = &vb2_vmalloc_memops;
dev->vb_queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&dev->vb_queue);
if (ret) {
dev_err(dev->dev, "Could not initialize vb2 queue\n");
goto err_free_mem;
}
dev->vdev = msi2500_template;
dev->vdev.queue = &dev->vb_queue;
dev->vdev.queue->lock = &dev->vb_queue_lock;
video_set_drvdata(&dev->vdev, dev);
dev->v4l2_dev.release = msi2500_video_release;
ret = v4l2_device_register(&intf->dev, &dev->v4l2_dev);
if (ret) {
dev_err(dev->dev, "Failed to register v4l2-device (%d)\n", ret);
goto err_free_mem;
}
master = spi_alloc_master(dev->dev, 0);
if (master == NULL) {
ret = -ENOMEM;
goto err_unregister_v4l2_dev;
}
dev->master = master;
master->bus_num = 0;
master->num_chipselect = 1;
master->transfer_one_message = msi2500_transfer_one_message;
spi_master_set_devdata(master, dev);
ret = spi_register_master(master);
if (ret) {
spi_master_put(master);
goto err_unregister_v4l2_dev;
}
sd = v4l2_spi_new_subdev(&dev->v4l2_dev, master, &board_info);
dev->v4l2_subdev = sd;
if (sd == NULL) {
dev_err(dev->dev, "cannot get v4l2 subdevice\n");
ret = -ENODEV;
goto err_unregister_master;
}
v4l2_ctrl_handler_init(&dev->hdl, 0);
if (dev->hdl.error) {
ret = dev->hdl.error;
dev_err(dev->dev, "Could not initialize controls\n");
goto err_free_controls;
}
v4l2_ctrl_add_handler(&dev->hdl, sd->ctrl_handler, NULL);
dev->v4l2_dev.ctrl_handler = &dev->hdl;
dev->vdev.v4l2_dev = &dev->v4l2_dev;
dev->vdev.lock = &dev->v4l2_lock;
ret = video_register_device(&dev->vdev, VFL_TYPE_SDR, -1);
if (ret) {
dev_err(dev->dev,
"Failed to register as video device (%d)\n", ret);
goto err_unregister_v4l2_dev;
}
dev_info(dev->dev, "Registered as %s\n",
video_device_node_name(&dev->vdev));
dev_notice(dev->dev,
"SDR API is still slightly experimental and functionality changes may follow\n");
return 0;
err_free_controls:
v4l2_ctrl_handler_free(&dev->hdl);
err_unregister_master:
spi_unregister_master(dev->master);
err_unregister_v4l2_dev:
v4l2_device_unregister(&dev->v4l2_dev);
err_free_mem:
kfree(dev);
err:
return ret;
}
