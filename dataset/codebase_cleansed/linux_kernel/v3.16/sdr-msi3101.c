static struct msi3101_frame_buf *msi3101_get_next_fill_buf(
struct msi3101_state *s)
{
unsigned long flags = 0;
struct msi3101_frame_buf *buf = NULL;
spin_lock_irqsave(&s->queued_bufs_lock, flags);
if (list_empty(&s->queued_bufs))
goto leave;
buf = list_entry(s->queued_bufs.next, struct msi3101_frame_buf, list);
list_del(&buf->list);
leave:
spin_unlock_irqrestore(&s->queued_bufs_lock, flags);
return buf;
}
static int msi3101_convert_stream_504(struct msi3101_state *s, u8 *dst,
u8 *src, unsigned int src_len)
{
int i, i_max, dst_len = 0;
u32 sample_num[3];
i_max = src_len / 1024;
for (i = 0; i < i_max; i++) {
sample_num[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 | src[0] << 0;
if (i == 0 && s->next_sample != sample_num[0]) {
dev_dbg_ratelimited(&s->udev->dev,
"%d samples lost, %d %08x:%08x\n",
sample_num[0] - s->next_sample,
src_len, s->next_sample, sample_num[0]);
}
dev_dbg_ratelimited(&s->udev->dev, "%*ph\n", 12, &src[4]);
src += 16;
memcpy(dst, src, 1008);
src += 1008;
dst += 1008;
dst_len += 1008;
}
if ((s->jiffies_next + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies_next);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies_next = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
s->next_sample = sample_num[i_max - 1] + 504;
return dst_len;
}
static int msi3101_convert_stream_504_u8(struct msi3101_state *s, u8 *dst,
u8 *src, unsigned int src_len)
{
int i, j, i_max, dst_len = 0;
u32 sample_num[3];
s8 *s8src;
u8 *u8dst;
i_max = src_len / 1024;
u8dst = (u8 *) dst;
for (i = 0; i < i_max; i++) {
sample_num[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 | src[0] << 0;
if (i == 0 && s->next_sample != sample_num[0]) {
dev_dbg_ratelimited(&s->udev->dev,
"%d samples lost, %d %08x:%08x\n",
sample_num[0] - s->next_sample,
src_len, s->next_sample, sample_num[0]);
}
dev_dbg_ratelimited(&s->udev->dev, "%*ph\n", 12, &src[4]);
src += 16;
s8src = (s8 *) src;
for (j = 0; j < 1008; j++)
*u8dst++ = *s8src++ + 128;
src += 1008;
dst += 1008;
dst_len += 1008;
}
if (unlikely(time_is_before_jiffies(s->jiffies_next))) {
#define MSECS 10000UL
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies_next = jiffies + msecs_to_jiffies(MSECS);
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, MSECS,
samples * 1000UL / MSECS);
}
s->next_sample = sample_num[i_max - 1] + 504;
return dst_len;
}
static int msi3101_convert_stream_384(struct msi3101_state *s, u8 *dst,
u8 *src, unsigned int src_len)
{
int i, i_max, dst_len = 0;
u32 sample_num[3];
i_max = src_len / 1024;
for (i = 0; i < i_max; i++) {
sample_num[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 | src[0] << 0;
if (i == 0 && s->next_sample != sample_num[0]) {
dev_dbg_ratelimited(&s->udev->dev,
"%d samples lost, %d %08x:%08x\n",
sample_num[0] - s->next_sample,
src_len, s->next_sample, sample_num[0]);
}
dev_dbg_ratelimited(&s->udev->dev,
"%*ph %*ph\n", 12, &src[4], 24, &src[1000]);
src += 16;
memcpy(dst, src, 984);
src += 984 + 24;
dst += 984;
dst_len += 984;
}
if ((s->jiffies_next + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies_next);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies_next = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu bits=%d.%d.%d.%d\n",
src_len, samples, msecs,
samples * 1000UL / msecs,
s->sample_ctrl_bit[0], s->sample_ctrl_bit[1],
s->sample_ctrl_bit[2], s->sample_ctrl_bit[3]);
}
s->next_sample = sample_num[i_max - 1] + 384;
return dst_len;
}
static int msi3101_convert_stream_336(struct msi3101_state *s, u8 *dst,
u8 *src, unsigned int src_len)
{
int i, i_max, dst_len = 0;
u32 sample_num[3];
i_max = src_len / 1024;
for (i = 0; i < i_max; i++) {
sample_num[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 | src[0] << 0;
if (i == 0 && s->next_sample != sample_num[0]) {
dev_dbg_ratelimited(&s->udev->dev,
"%d samples lost, %d %08x:%08x\n",
sample_num[0] - s->next_sample,
src_len, s->next_sample, sample_num[0]);
}
dev_dbg_ratelimited(&s->udev->dev, "%*ph\n", 12, &src[4]);
src += 16;
memcpy(dst, src, 1008);
src += 1008;
dst += 1008;
dst_len += 1008;
}
if ((s->jiffies_next + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies_next);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies_next = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
s->next_sample = sample_num[i_max - 1] + 336;
return dst_len;
}
static int msi3101_convert_stream_252(struct msi3101_state *s, u8 *dst,
u8 *src, unsigned int src_len)
{
int i, i_max, dst_len = 0;
u32 sample_num[3];
i_max = src_len / 1024;
for (i = 0; i < i_max; i++) {
sample_num[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 | src[0] << 0;
if (i == 0 && s->next_sample != sample_num[0]) {
dev_dbg_ratelimited(&s->udev->dev,
"%d samples lost, %d %08x:%08x\n",
sample_num[0] - s->next_sample,
src_len, s->next_sample, sample_num[0]);
}
dev_dbg_ratelimited(&s->udev->dev, "%*ph\n", 12, &src[4]);
src += 16;
memcpy(dst, src, 1008);
src += 1008;
dst += 1008;
dst_len += 1008;
}
if ((s->jiffies_next + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies_next);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies_next = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
s->next_sample = sample_num[i_max - 1] + 252;
return dst_len;
}
static int msi3101_convert_stream_252_u16(struct msi3101_state *s, u8 *dst,
u8 *src, unsigned int src_len)
{
int i, j, i_max, dst_len = 0;
u32 sample_num[3];
u16 *u16dst = (u16 *) dst;
struct {signed int x:14;} se;
i_max = src_len / 1024;
for (i = 0; i < i_max; i++) {
sample_num[i] = src[3] << 24 | src[2] << 16 | src[1] << 8 | src[0] << 0;
if (i == 0 && s->next_sample != sample_num[0]) {
dev_dbg_ratelimited(&s->udev->dev,
"%d samples lost, %d %08x:%08x\n",
sample_num[0] - s->next_sample,
src_len, s->next_sample, sample_num[0]);
}
dev_dbg_ratelimited(&s->udev->dev, "%*ph\n", 12, &src[4]);
src += 16;
for (j = 0; j < 1008; j += 4) {
unsigned int usample[2];
int ssample[2];
usample[0] = src[j + 0] >> 0 | src[j + 1] << 8;
usample[1] = src[j + 2] >> 0 | src[j + 3] << 8;
ssample[0] = se.x = usample[0];
ssample[1] = se.x = usample[1];
usample[0] = ssample[0] + 8192;
usample[1] = ssample[1] + 8192;
*u16dst++ = (usample[0] << 2) | (usample[0] >> 12);
*u16dst++ = (usample[1] << 2) | (usample[1] >> 12);
}
src += 1008;
dst += 1008;
dst_len += 1008;
}
if (unlikely(time_is_before_jiffies(s->jiffies_next))) {
#define MSECS 10000UL
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies_next = jiffies + msecs_to_jiffies(MSECS);
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, MSECS,
samples * 1000UL / MSECS);
}
s->next_sample = sample_num[i_max - 1] + 252;
return dst_len;
}
static void msi3101_isoc_handler(struct urb *urb)
{
struct msi3101_state *s = (struct msi3101_state *)urb->context;
int i, flen, fstatus;
unsigned char *iso_buf = NULL;
struct msi3101_frame_buf *fbuf;
if (unlikely(urb->status == -ENOENT || urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN)) {
dev_dbg(&s->udev->dev, "URB (%p) unlinked %ssynchronuously\n",
urb, urb->status == -ENOENT ? "" : "a");
return;
}
if (unlikely(urb->status != 0)) {
dev_dbg(&s->udev->dev,
"msi3101_isoc_handler() called with status %d\n",
urb->status);
if (++s->isoc_errors > MAX_ISOC_ERRORS)
dev_dbg(&s->udev->dev,
"Too many ISOC errors, bailing out\n");
goto handler_end;
} else {
s->isoc_errors = 0;
}
for (i = 0; i < urb->number_of_packets; i++) {
void *ptr;
fstatus = urb->iso_frame_desc[i].status;
if (unlikely(fstatus)) {
dev_dbg_ratelimited(&s->udev->dev,
"frame=%d/%d has error %d skipping\n",
i, urb->number_of_packets, fstatus);
continue;
}
flen = urb->iso_frame_desc[i].actual_length;
if (unlikely(flen == 0))
continue;
iso_buf = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
fbuf = msi3101_get_next_fill_buf(s);
if (unlikely(fbuf == NULL)) {
s->vb_full++;
dev_dbg_ratelimited(&s->udev->dev,
"videobuf is full, %d packets dropped\n",
s->vb_full);
continue;
}
ptr = vb2_plane_vaddr(&fbuf->vb, 0);
flen = s->convert_stream(s, ptr, iso_buf, flen);
vb2_set_plane_payload(&fbuf->vb, 0, flen);
vb2_buffer_done(&fbuf->vb, VB2_BUF_STATE_DONE);
}
handler_end:
i = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(i != 0))
dev_dbg(&s->udev->dev,
"Error (%d) re-submitting urb in msi3101_isoc_handler\n",
i);
}
static void msi3101_iso_stop(struct msi3101_state *s)
{
int i;
dev_dbg(&s->udev->dev, "%s:\n", __func__);
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (s->urbs[i]) {
dev_dbg(&s->udev->dev, "Unlinking URB %p\n",
s->urbs[i]);
usb_kill_urb(s->urbs[i]);
}
}
}
static void msi3101_iso_free(struct msi3101_state *s)
{
int i;
dev_dbg(&s->udev->dev, "%s:\n", __func__);
for (i = 0; i < MAX_ISO_BUFS; i++) {
if (s->urbs[i]) {
dev_dbg(&s->udev->dev, "Freeing URB\n");
if (s->urbs[i]->transfer_buffer) {
usb_free_coherent(s->udev,
s->urbs[i]->transfer_buffer_length,
s->urbs[i]->transfer_buffer,
s->urbs[i]->transfer_dma);
}
usb_free_urb(s->urbs[i]);
s->urbs[i] = NULL;
}
}
}
static void msi3101_isoc_cleanup(struct msi3101_state *s)
{
dev_dbg(&s->udev->dev, "%s:\n", __func__);
msi3101_iso_stop(s);
msi3101_iso_free(s);
}
static int msi3101_isoc_init(struct msi3101_state *s)
{
struct usb_device *udev;
struct urb *urb;
int i, j, ret;
dev_dbg(&s->udev->dev, "%s:\n", __func__);
s->isoc_errors = 0;
udev = s->udev;
ret = usb_set_interface(s->udev, 0, 1);
if (ret)
return ret;
for (i = 0; i < MAX_ISO_BUFS; i++) {
urb = usb_alloc_urb(ISO_FRAMES_PER_DESC, GFP_KERNEL);
if (urb == NULL) {
dev_err(&s->udev->dev,
"Failed to allocate urb %d\n", i);
msi3101_isoc_cleanup(s);
return -ENOMEM;
}
s->urbs[i] = urb;
dev_dbg(&s->udev->dev, "Allocated URB at 0x%p\n", urb);
urb->interval = 1;
urb->dev = udev;
urb->pipe = usb_rcvisocpipe(udev, 0x81);
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer = usb_alloc_coherent(udev, ISO_BUFFER_SIZE,
GFP_KERNEL, &urb->transfer_dma);
if (urb->transfer_buffer == NULL) {
dev_err(&s->udev->dev,
"Failed to allocate urb buffer %d\n",
i);
msi3101_isoc_cleanup(s);
return -ENOMEM;
}
urb->transfer_buffer_length = ISO_BUFFER_SIZE;
urb->complete = msi3101_isoc_handler;
urb->context = s;
urb->start_frame = 0;
urb->number_of_packets = ISO_FRAMES_PER_DESC;
for (j = 0; j < ISO_FRAMES_PER_DESC; j++) {
urb->iso_frame_desc[j].offset = j * ISO_MAX_FRAME_SIZE;
urb->iso_frame_desc[j].length = ISO_MAX_FRAME_SIZE;
}
}
for (i = 0; i < MAX_ISO_BUFS; i++) {
ret = usb_submit_urb(s->urbs[i], GFP_KERNEL);
if (ret) {
dev_err(&s->udev->dev,
"isoc_init() submit_urb %d failed with error %d\n",
i, ret);
msi3101_isoc_cleanup(s);
return ret;
}
dev_dbg(&s->udev->dev, "URB 0x%p submitted.\n", s->urbs[i]);
}
return 0;
}
static void msi3101_cleanup_queued_bufs(struct msi3101_state *s)
{
unsigned long flags = 0;
dev_dbg(&s->udev->dev, "%s:\n", __func__);
spin_lock_irqsave(&s->queued_bufs_lock, flags);
while (!list_empty(&s->queued_bufs)) {
struct msi3101_frame_buf *buf;
buf = list_entry(s->queued_bufs.next, struct msi3101_frame_buf,
list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&s->queued_bufs_lock, flags);
}
static void msi3101_disconnect(struct usb_interface *intf)
{
struct v4l2_device *v = usb_get_intfdata(intf);
struct msi3101_state *s =
container_of(v, struct msi3101_state, v4l2_dev);
dev_dbg(&s->udev->dev, "%s:\n", __func__);
mutex_lock(&s->vb_queue_lock);
mutex_lock(&s->v4l2_lock);
s->udev = NULL;
v4l2_device_disconnect(&s->v4l2_dev);
video_unregister_device(&s->vdev);
spi_unregister_master(s->master);
mutex_unlock(&s->v4l2_lock);
mutex_unlock(&s->vb_queue_lock);
v4l2_device_put(&s->v4l2_dev);
}
static int msi3101_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct msi3101_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "%s:\n", __func__);
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, s->vdev.name, sizeof(cap->card));
usb_make_path(s->udev, cap->bus_info, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE | V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int msi3101_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt, unsigned int *nbuffers,
unsigned int *nplanes, unsigned int sizes[], void *alloc_ctxs[])
{
struct msi3101_state *s = vb2_get_drv_priv(vq);
dev_dbg(&s->udev->dev, "%s: *nbuffers=%d\n", __func__, *nbuffers);
*nbuffers = clamp_t(unsigned int, *nbuffers, 8, 32);
*nplanes = 1;
sizes[0] = PAGE_ALIGN(3 * 504 * 2 * 2);
dev_dbg(&s->udev->dev, "%s: nbuffers=%d sizes[0]=%d\n",
__func__, *nbuffers, sizes[0]);
return 0;
}
static void msi3101_buf_queue(struct vb2_buffer *vb)
{
struct msi3101_state *s = vb2_get_drv_priv(vb->vb2_queue);
struct msi3101_frame_buf *buf =
container_of(vb, struct msi3101_frame_buf, vb);
unsigned long flags = 0;
if (unlikely(!s->udev)) {
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
return;
}
spin_lock_irqsave(&s->queued_bufs_lock, flags);
list_add_tail(&buf->list, &s->queued_bufs);
spin_unlock_irqrestore(&s->queued_bufs_lock, flags);
}
static int msi3101_ctrl_msg(struct msi3101_state *s, u8 cmd, u32 data)
{
int ret;
u8 request = cmd;
u8 requesttype = USB_DIR_OUT | USB_TYPE_VENDOR;
u16 value = (data >> 0) & 0xffff;
u16 index = (data >> 16) & 0xffff;
msi3101_dbg_usb_control_msg(s->udev,
request, requesttype, value, index, NULL, 0);
ret = usb_control_msg(s->udev, usb_sndctrlpipe(s->udev, 0),
request, requesttype, value, index, NULL, 0, 2000);
if (ret)
dev_err(&s->udev->dev, "%s: failed %d, cmd %02x, data %04x\n",
__func__, ret, cmd, data);
return ret;
}
static int msi3101_set_usb_adc(struct msi3101_state *s)
{
int ret, div_n, div_m, div_r_out, f_sr, f_vco, fract;
u32 reg3, reg4, reg7;
struct v4l2_ctrl *bandwidth_auto;
struct v4l2_ctrl *bandwidth;
f_sr = s->f_adc;
bandwidth_auto = v4l2_ctrl_find(&s->hdl, V4L2_CID_RF_TUNER_BANDWIDTH_AUTO);
if (v4l2_ctrl_g_ctrl(bandwidth_auto)) {
bandwidth = v4l2_ctrl_find(&s->hdl, V4L2_CID_RF_TUNER_BANDWIDTH);
v4l2_ctrl_s_ctrl(bandwidth, s->f_adc);
}
switch (s->pixelformat) {
case V4L2_SDR_FMT_CU8:
s->convert_stream = msi3101_convert_stream_504_u8;
reg7 = 0x000c9407;
break;
case V4L2_SDR_FMT_CU16LE:
s->convert_stream = msi3101_convert_stream_252_u16;
reg7 = 0x00009407;
break;
case V4L2_PIX_FMT_SDR_S8:
s->convert_stream = msi3101_convert_stream_504;
reg7 = 0x000c9407;
break;
case V4L2_PIX_FMT_SDR_MSI2500_384:
s->convert_stream = msi3101_convert_stream_384;
reg7 = 0x0000a507;
break;
case V4L2_PIX_FMT_SDR_S12:
s->convert_stream = msi3101_convert_stream_336;
reg7 = 0x00008507;
break;
case V4L2_PIX_FMT_SDR_S14:
s->convert_stream = msi3101_convert_stream_252;
reg7 = 0x00009407;
break;
default:
s->convert_stream = msi3101_convert_stream_504_u8;
reg7 = 0x000c9407;
break;
}
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
for (div_r_out = 4; div_r_out < 16; div_r_out += 2) {
f_vco = f_sr * div_r_out * 12;
dev_dbg(&s->udev->dev, "%s: div_r_out=%d f_vco=%d\n",
__func__, div_r_out, f_vco);
if (f_vco >= 202000000)
break;
}
div_n = f_vco / (F_REF * DIV_R_IN);
div_m = f_vco % (F_REF * DIV_R_IN);
fract = 0x200000ul * div_m / (F_REF * DIV_R_IN);
reg3 |= div_n << 16;
reg3 |= (div_r_out / 2 - 1) << 10;
reg3 |= ((fract >> 20) & 0x000001) << 15;
reg4 |= ((fract >> 0) & 0x0fffff) << 8;
dev_dbg(&s->udev->dev,
"%s: f_sr=%d f_vco=%d div_n=%d div_m=%d div_r_out=%d reg3=%08x reg4=%08x\n",
__func__, f_sr, f_vco, div_n, div_m, div_r_out, reg3, reg4);
ret = msi3101_ctrl_msg(s, CMD_WREG, 0x00608008);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, 0x00000c05);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, 0x00020000);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, 0x00480102);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, 0x00f38008);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, reg7);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, reg4);
if (ret)
goto err;
ret = msi3101_ctrl_msg(s, CMD_WREG, reg3);
if (ret)
goto err;
err:
return ret;
}
static int msi3101_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct msi3101_state *s = vb2_get_drv_priv(vq);
int ret;
dev_dbg(&s->udev->dev, "%s:\n", __func__);
if (!s->udev)
return -ENODEV;
if (mutex_lock_interruptible(&s->v4l2_lock))
return -ERESTARTSYS;
v4l2_subdev_call(s->v4l2_subdev, core, s_power, 1);
ret = msi3101_set_usb_adc(s);
ret = msi3101_isoc_init(s);
if (ret)
msi3101_cleanup_queued_bufs(s);
ret = msi3101_ctrl_msg(s, CMD_START_STREAMING, 0);
mutex_unlock(&s->v4l2_lock);
return ret;
}
static void msi3101_stop_streaming(struct vb2_queue *vq)
{
struct msi3101_state *s = vb2_get_drv_priv(vq);
dev_dbg(&s->udev->dev, "%s:\n", __func__);
mutex_lock(&s->v4l2_lock);
if (s->udev)
msi3101_isoc_cleanup(s);
msi3101_cleanup_queued_bufs(s);
msleep(20);
if (!msi3101_ctrl_msg(s, CMD_STOP_STREAMING, 0)) {
msi3101_ctrl_msg(s, CMD_WREG, 0x01000003);
}
v4l2_subdev_call(s->v4l2_subdev, core, s_power, 0);
mutex_unlock(&s->v4l2_lock);
}
static int msi3101_enum_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct msi3101_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "%s: index=%d\n", __func__, f->index);
if (f->index >= NUM_FORMATS)
return -EINVAL;
strlcpy(f->description, formats[f->index].name, sizeof(f->description));
f->pixelformat = formats[f->index].pixelformat;
return 0;
}
static int msi3101_g_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct msi3101_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "%s: pixelformat fourcc %4.4s\n", __func__,
(char *)&s->pixelformat);
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
f->fmt.sdr.pixelformat = s->pixelformat;
return 0;
}
static int msi3101_s_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct msi3101_state *s = video_drvdata(file);
struct vb2_queue *q = &s->vb_queue;
int i;
dev_dbg(&s->udev->dev, "%s: pixelformat fourcc %4.4s\n", __func__,
(char *)&f->fmt.sdr.pixelformat);
if (vb2_is_busy(q))
return -EBUSY;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < NUM_FORMATS; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
s->pixelformat = f->fmt.sdr.pixelformat;
return 0;
}
}
f->fmt.sdr.pixelformat = formats[0].pixelformat;
s->pixelformat = formats[0].pixelformat;
return 0;
}
static int msi3101_try_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct msi3101_state *s = video_drvdata(file);
int i;
dev_dbg(&s->udev->dev, "%s: pixelformat fourcc %4.4s\n", __func__,
(char *)&f->fmt.sdr.pixelformat);
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < NUM_FORMATS; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat)
return 0;
}
f->fmt.sdr.pixelformat = formats[0].pixelformat;
return 0;
}
static int msi3101_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct msi3101_state *s = video_drvdata(file);
int ret;
dev_dbg(&s->udev->dev, "%s: index=%d\n", __func__, v->index);
if (v->index == 0)
ret = 0;
else if (v->index == 1)
ret = v4l2_subdev_call(s->v4l2_subdev, tuner, s_tuner, v);
else
ret = -EINVAL;
return ret;
}
static int msi3101_g_tuner(struct file *file, void *priv, struct v4l2_tuner *v)
{
struct msi3101_state *s = video_drvdata(file);
int ret;
dev_dbg(&s->udev->dev, "%s: index=%d\n", __func__, v->index);
if (v->index == 0) {
strlcpy(v->name, "Mirics MSi2500", sizeof(v->name));
v->type = V4L2_TUNER_ADC;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = 1200000;
v->rangehigh = 15000000;
ret = 0;
} else if (v->index == 1) {
ret = v4l2_subdev_call(s->v4l2_subdev, tuner, g_tuner, v);
} else {
ret = -EINVAL;
}
return ret;
}
static int msi3101_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct msi3101_state *s = video_drvdata(file);
int ret = 0;
dev_dbg(&s->udev->dev, "%s: tuner=%d type=%d\n",
__func__, f->tuner, f->type);
if (f->tuner == 0) {
f->frequency = s->f_adc;
ret = 0;
} else if (f->tuner == 1) {
f->type = V4L2_TUNER_RF;
ret = v4l2_subdev_call(s->v4l2_subdev, tuner, g_frequency, f);
} else {
ret = -EINVAL;
}
return ret;
}
static int msi3101_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct msi3101_state *s = video_drvdata(file);
int ret;
dev_dbg(&s->udev->dev, "%s: tuner=%d type=%d frequency=%u\n",
__func__, f->tuner, f->type, f->frequency);
if (f->tuner == 0) {
s->f_adc = clamp_t(unsigned int, f->frequency,
bands[0].rangelow,
bands[0].rangehigh);
dev_dbg(&s->udev->dev, "%s: ADC frequency=%u Hz\n",
__func__, s->f_adc);
ret = msi3101_set_usb_adc(s);
} else if (f->tuner == 1) {
ret = v4l2_subdev_call(s->v4l2_subdev, tuner, s_frequency, f);
} else {
ret = -EINVAL;
}
return ret;
}
static int msi3101_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
struct msi3101_state *s = video_drvdata(file);
int ret;
dev_dbg(&s->udev->dev, "%s: tuner=%d type=%d index=%d\n",
__func__, band->tuner, band->type, band->index);
if (band->tuner == 0) {
if (band->index >= ARRAY_SIZE(bands)) {
ret = -EINVAL;
} else {
*band = bands[band->index];
ret = 0;
}
} else if (band->tuner == 1) {
ret = v4l2_subdev_call(s->v4l2_subdev, tuner,
enum_freq_bands, band);
} else {
ret = -EINVAL;
}
return ret;
}
static void msi3101_video_release(struct v4l2_device *v)
{
struct msi3101_state *s =
container_of(v, struct msi3101_state, v4l2_dev);
v4l2_ctrl_handler_free(&s->hdl);
v4l2_device_unregister(&s->v4l2_dev);
kfree(s);
}
static int msi3101_transfer_one_message(struct spi_master *master,
struct spi_message *m)
{
struct msi3101_state *s = spi_master_get_devdata(master);
struct spi_transfer *t;
int ret = 0;
u32 data;
list_for_each_entry(t, &m->transfers, transfer_list) {
dev_dbg(&s->udev->dev, "%s: msg=%*ph\n",
__func__, t->len, t->tx_buf);
data = 0x09;
data |= ((u8 *)t->tx_buf)[0] << 8;
data |= ((u8 *)t->tx_buf)[1] << 16;
data |= ((u8 *)t->tx_buf)[2] << 24;
ret = msi3101_ctrl_msg(s, CMD_WREG, data);
}
m->status = ret;
spi_finalize_current_message(master);
return ret;
}
static int msi3101_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct msi3101_state *s = NULL;
struct v4l2_subdev *sd;
struct spi_master *master;
int ret;
static struct spi_board_info board_info = {
.modalias = "msi001",
.bus_num = 0,
.chip_select = 0,
.max_speed_hz = 12000000,
};
s = kzalloc(sizeof(struct msi3101_state), GFP_KERNEL);
if (s == NULL) {
pr_err("Could not allocate memory for msi3101_state\n");
return -ENOMEM;
}
mutex_init(&s->v4l2_lock);
mutex_init(&s->vb_queue_lock);
spin_lock_init(&s->queued_bufs_lock);
INIT_LIST_HEAD(&s->queued_bufs);
s->udev = udev;
s->f_adc = bands[0].rangelow;
s->pixelformat = V4L2_SDR_FMT_CU8;
s->vb_queue.type = V4L2_BUF_TYPE_SDR_CAPTURE;
s->vb_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_READ;
s->vb_queue.drv_priv = s;
s->vb_queue.buf_struct_size = sizeof(struct msi3101_frame_buf);
s->vb_queue.ops = &msi3101_vb2_ops;
s->vb_queue.mem_ops = &vb2_vmalloc_memops;
s->vb_queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&s->vb_queue);
if (ret) {
dev_err(&s->udev->dev, "Could not initialize vb2 queue\n");
goto err_free_mem;
}
s->vdev = msi3101_template;
s->vdev.queue = &s->vb_queue;
s->vdev.queue->lock = &s->vb_queue_lock;
set_bit(V4L2_FL_USE_FH_PRIO, &s->vdev.flags);
video_set_drvdata(&s->vdev, s);
s->v4l2_dev.release = msi3101_video_release;
ret = v4l2_device_register(&intf->dev, &s->v4l2_dev);
if (ret) {
dev_err(&s->udev->dev,
"Failed to register v4l2-device (%d)\n", ret);
goto err_free_mem;
}
master = spi_alloc_master(&s->udev->dev, 0);
if (master == NULL) {
ret = -ENOMEM;
goto err_unregister_v4l2_dev;
}
s->master = master;
master->bus_num = 0;
master->num_chipselect = 1;
master->transfer_one_message = msi3101_transfer_one_message;
spi_master_set_devdata(master, s);
ret = spi_register_master(master);
if (ret) {
spi_master_put(master);
goto err_unregister_v4l2_dev;
}
sd = v4l2_spi_new_subdev(&s->v4l2_dev, master, &board_info);
s->v4l2_subdev = sd;
if (sd == NULL) {
dev_err(&s->udev->dev, "cannot get v4l2 subdevice\n");
ret = -ENODEV;
goto err_unregister_master;
}
v4l2_ctrl_handler_init(&s->hdl, 0);
if (s->hdl.error) {
ret = s->hdl.error;
dev_err(&s->udev->dev, "Could not initialize controls\n");
goto err_free_controls;
}
v4l2_ctrl_add_handler(&s->hdl, sd->ctrl_handler, NULL);
s->v4l2_dev.ctrl_handler = &s->hdl;
s->vdev.v4l2_dev = &s->v4l2_dev;
s->vdev.lock = &s->v4l2_lock;
ret = video_register_device(&s->vdev, VFL_TYPE_SDR, -1);
if (ret) {
dev_err(&s->udev->dev,
"Failed to register as video device (%d)\n",
ret);
goto err_unregister_v4l2_dev;
}
dev_info(&s->udev->dev, "Registered as %s\n",
video_device_node_name(&s->vdev));
return 0;
err_free_controls:
v4l2_ctrl_handler_free(&s->hdl);
err_unregister_master:
spi_unregister_master(s->master);
err_unregister_v4l2_dev:
v4l2_device_unregister(&s->v4l2_dev);
err_free_mem:
kfree(s);
return ret;
}
