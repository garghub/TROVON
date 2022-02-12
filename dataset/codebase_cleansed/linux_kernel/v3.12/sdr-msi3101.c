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
static u32 msi3101_convert_sample_504(struct msi3101_state *s, u16 x)
{
u32 msb, exponent, fraction, sign;
if (!x)
return 0;
if (x & (1 << 7)) {
x = -x;
x &= 0x7f;
sign = 1 << 31;
} else {
sign = 0 << 31;
}
msb = __fls(x);
fraction = ror32(x, (msb - I2F_FRAC_BITS) & 0x1f) & I2F_MASK;
exponent = (127 + msb) << I2F_FRAC_BITS;
return (fraction + exponent) | sign;
}
static int msi3101_convert_stream_504(struct msi3101_state *s, u32 *dst,
u8 *src, unsigned int src_len)
{
int i, j, i_max, dst_len = 0;
u16 sample[2];
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
for (j = 0; j < 1008; j += 2) {
sample[0] = src[j + 0];
sample[1] = src[j + 1];
*dst++ = msi3101_convert_sample_504(s, sample[0]);
*dst++ = msi3101_convert_sample_504(s, sample[1]);
}
dst_len += 504 * 2 * 4;
src += 1008;
}
if ((s->jiffies + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
s->next_sample = sample_num[i_max - 1] + 504;
return dst_len;
}
static u32 msi3101_convert_sample_384(struct msi3101_state *s, u16 x, int shift)
{
u32 msb, exponent, fraction, sign;
s->sample_ctrl_bit[shift]++;
if (!x)
return 0;
if (shift == 3)
shift = 2;
if (x & (1 << 9)) {
x |= ~0U << 10;
x <<= shift;
x = -x;
x &= 0x7ff;
sign = 1 << 31;
} else {
x <<= shift;
sign = 0 << 31;
}
msb = __fls(x);
fraction = ror32(x, (msb - I2F_FRAC_BITS) & 0x1f) & I2F_MASK;
exponent = (127 + msb) << I2F_FRAC_BITS;
return (fraction + exponent) | sign;
}
static int msi3101_convert_stream_384(struct msi3101_state *s, u32 *dst,
u8 *src, unsigned int src_len)
{
int i, j, k, l, i_max, dst_len = 0;
u16 sample[4];
u32 bits;
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
for (j = 0; j < 6; j++) {
bits = src[160 + 3] << 24 | src[160 + 2] << 16 | src[160 + 1] << 8 | src[160 + 0] << 0;
for (k = 0; k < 16; k++) {
for (l = 0; l < 10; l += 5) {
sample[0] = (src[l + 0] & 0xff) >> 0 | (src[l + 1] & 0x03) << 8;
sample[1] = (src[l + 1] & 0xfc) >> 2 | (src[l + 2] & 0x0f) << 6;
sample[2] = (src[l + 2] & 0xf0) >> 4 | (src[l + 3] & 0x3f) << 4;
sample[3] = (src[l + 3] & 0xc0) >> 6 | (src[l + 4] & 0xff) << 2;
*dst++ = msi3101_convert_sample_384(s, sample[0], (bits >> (2 * k)) & 0x3);
*dst++ = msi3101_convert_sample_384(s, sample[1], (bits >> (2 * k)) & 0x3);
*dst++ = msi3101_convert_sample_384(s, sample[2], (bits >> (2 * k)) & 0x3);
*dst++ = msi3101_convert_sample_384(s, sample[3], (bits >> (2 * k)) & 0x3);
}
src += 10;
}
dev_dbg_ratelimited(&s->udev->dev,
"sample control bits %08x\n", bits);
src += 4;
}
dst_len += 384 * 2 * 4;
src += 24;
}
if ((s->jiffies + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies = jiffies_now;
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
static u32 msi3101_convert_sample_336(struct msi3101_state *s, u16 x)
{
u32 msb, exponent, fraction, sign;
if (!x)
return 0;
if (x & (1 << 11)) {
x = -x;
x &= 0x7ff;
sign = 1 << 31;
} else {
sign = 0 << 31;
}
msb = __fls(x);
fraction = ror32(x, (msb - I2F_FRAC_BITS) & 0x1f) & I2F_MASK;
exponent = (127 + msb) << I2F_FRAC_BITS;
return (fraction + exponent) | sign;
}
static int msi3101_convert_stream_336(struct msi3101_state *s, u32 *dst,
u8 *src, unsigned int src_len)
{
int i, j, i_max, dst_len = 0;
u16 sample[2];
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
for (j = 0; j < 1008; j += 3) {
sample[0] = (src[j + 0] & 0xff) >> 0 | (src[j + 1] & 0x0f) << 8;
sample[1] = (src[j + 1] & 0xf0) >> 4 | (src[j + 2] & 0xff) << 4;
*dst++ = msi3101_convert_sample_336(s, sample[0]);
*dst++ = msi3101_convert_sample_336(s, sample[1]);
}
dst_len += 336 * 2 * 4;
src += 1008;
}
if ((s->jiffies + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
s->next_sample = sample_num[i_max - 1] + 336;
return dst_len;
}
static u32 msi3101_convert_sample_252(struct msi3101_state *s, u16 x)
{
u32 msb, exponent, fraction, sign;
if (!x)
return 0;
if (x & (1 << 13)) {
x = -x;
x &= 0x1fff;
sign = 1 << 31;
} else {
sign = 0 << 31;
}
msb = __fls(x);
fraction = ror32(x, (msb - I2F_FRAC_BITS) & 0x1f) & I2F_MASK;
exponent = (127 + msb) << I2F_FRAC_BITS;
return (fraction + exponent) | sign;
}
static int msi3101_convert_stream_252(struct msi3101_state *s, u32 *dst,
u8 *src, unsigned int src_len)
{
int i, j, i_max, dst_len = 0;
u16 sample[2];
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
for (j = 0; j < 1008; j += 4) {
sample[0] = src[j + 0] >> 0 | src[j + 1] << 8;
sample[1] = src[j + 2] >> 0 | src[j + 3] << 8;
*dst++ = msi3101_convert_sample_252(s, sample[0]);
*dst++ = msi3101_convert_sample_252(s, sample[1]);
}
dst_len += 252 * 2 * 4;
src += 1008;
}
if ((s->jiffies + msecs_to_jiffies(10000)) <= jiffies) {
unsigned long jiffies_now = jiffies;
unsigned long msecs = jiffies_to_msecs(jiffies_now) - jiffies_to_msecs(s->jiffies);
unsigned int samples = sample_num[i_max - 1] - s->sample;
s->jiffies = jiffies_now;
s->sample = sample_num[i_max - 1];
dev_dbg(&s->udev->dev,
"slen=%d samples=%u msecs=%lu sampling rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
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
if (urb->status == -ENOENT || urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN) {
dev_dbg(&s->udev->dev, "URB (%p) unlinked %ssynchronuously\n",
urb, urb->status == -ENOENT ? "" : "a");
return;
}
if (urb->status != 0) {
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
if (fstatus) {
dev_dbg_ratelimited(&s->udev->dev,
"frame=%d/%d has error %d skipping\n",
i, urb->number_of_packets, fstatus);
goto skip;
}
flen = urb->iso_frame_desc[i].actual_length;
if (flen == 0)
goto skip;
iso_buf = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
fbuf = msi3101_get_next_fill_buf(s);
if (fbuf == NULL) {
s->vb_full++;
dev_dbg_ratelimited(&s->udev->dev,
"videobuf is full, %d packets dropped\n",
s->vb_full);
goto skip;
}
ptr = vb2_plane_vaddr(&fbuf->vb, 0);
flen = s->convert_stream(s, ptr, iso_buf, flen);
vb2_set_plane_payload(&fbuf->vb, 0, flen);
vb2_buffer_done(&fbuf->vb, VB2_BUF_STATE_DONE);
skip:
;
}
handler_end:
i = usb_submit_urb(urb, GFP_ATOMIC);
if (i != 0)
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
if (ret < 0)
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
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
cap->device_caps = V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int msi3101_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt, unsigned int *nbuffers,
unsigned int *nplanes, unsigned int sizes[], void *alloc_ctxs[])
{
struct msi3101_state *s = vb2_get_drv_priv(vq);
dev_dbg(&s->udev->dev, "%s: *nbuffers=%d\n", __func__, *nbuffers);
*nbuffers = 32;
*nplanes = 1;
sizes[0] = PAGE_ALIGN(3 * 504 * 2 * 4);
dev_dbg(&s->udev->dev, "%s: nbuffers=%d sizes[0]=%d\n",
__func__, *nbuffers, sizes[0]);
return 0;
}
static int msi3101_buf_prepare(struct vb2_buffer *vb)
{
struct msi3101_state *s = vb2_get_drv_priv(vb->vb2_queue);
if (!s->udev)
return -ENODEV;
return 0;
}
static void msi3101_buf_queue(struct vb2_buffer *vb)
{
struct msi3101_state *s = vb2_get_drv_priv(vb->vb2_queue);
struct msi3101_frame_buf *buf =
container_of(vb, struct msi3101_frame_buf, vb);
unsigned long flags = 0;
if (!s->udev) {
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
static int msi3101_tuner_write(struct msi3101_state *s, u32 data)
{
return msi3101_ctrl_msg(s, CMD_WREG, data << 8 | 0x09);
}
static int msi3101_set_usb_adc(struct msi3101_state *s)
{
int ret, div_n, div_m, div_r_out, f_sr, f_vco, fract;
u32 reg3, reg4, reg7;
f_sr = s->ctrl_sampling_rate->val64;
if (f_sr < 6000000) {
s->convert_stream = msi3101_convert_stream_252;
reg7 = 0x00009407;
} else if (f_sr < 8000000) {
s->convert_stream = msi3101_convert_stream_336;
reg7 = 0x00008507;
} else if (f_sr < 9000000) {
s->convert_stream = msi3101_convert_stream_384;
reg7 = 0x0000a507;
} else {
s->convert_stream = msi3101_convert_stream_504;
reg7 = 0x000c9407;
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
static int msi3101_set_tuner(struct msi3101_state *s)
{
int ret, i, len;
unsigned int n, m, thresh, frac, vco_step, tmp, f_if1;
u32 reg;
u64 f_vco, tmp64;
u8 mode, filter_mode, lo_div;
const struct msi3101_gain *gain_lut;
static const struct {
u32 rf;
u8 mode;
u8 lo_div;
} band_lut[] = {
{ 50000000, 0xe1, 16},
{108000000, 0x42, 32},
{330000000, 0x44, 16},
{960000000, 0x48, 4},
{ ~0U, 0x50, 2},
};
static const struct {
u32 freq;
u8 filter_mode;
} if_freq_lut[] = {
{ 0, 0x03},
{ 450000, 0x02},
{1620000, 0x01},
{2048000, 0x00},
};
static const struct {
u32 freq;
u8 val;
} bandwidth_lut[] = {
{ 200000, 0x00},
{ 300000, 0x01},
{ 600000, 0x02},
{1536000, 0x03},
{5000000, 0x04},
{6000000, 0x05},
{7000000, 0x06},
{8000000, 0x07},
};
unsigned int f_rf = s->ctrl_tuner_rf->val64;
unsigned int bandwidth = s->ctrl_tuner_bw->val;
unsigned int f_if = s->ctrl_tuner_if->val;
int gain = s->ctrl_tuner_gain->val;
dev_dbg(&s->udev->dev,
"%s: f_rf=%d bandwidth=%d f_if=%d gain=%d\n",
__func__, f_rf, bandwidth, f_if, gain);
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(band_lut); i++) {
if (f_rf <= band_lut[i].rf) {
mode = band_lut[i].mode;
lo_div = band_lut[i].lo_div;
break;
}
}
if (i == ARRAY_SIZE(band_lut))
goto err;
if ((mode >> 0) & 0x1)
f_if1 = 5 * F_REF;
else
f_if1 = 0;
for (i = 0; i < ARRAY_SIZE(if_freq_lut); i++) {
if (f_if == if_freq_lut[i].freq) {
filter_mode = if_freq_lut[i].filter_mode;
break;
}
}
if (i == ARRAY_SIZE(if_freq_lut))
goto err;
for (i = 0; i < ARRAY_SIZE(bandwidth_lut); i++) {
if (bandwidth == bandwidth_lut[i].freq) {
bandwidth = bandwidth_lut[i].val;
break;
}
}
if (i == ARRAY_SIZE(bandwidth_lut))
goto err;
#define F_OUT_STEP 1
#define R_REF 4
f_vco = (f_rf + f_if + f_if1) * lo_div;
tmp64 = f_vco;
m = do_div(tmp64, F_REF * R_REF);
n = (unsigned int) tmp64;
vco_step = F_OUT_STEP * lo_div;
thresh = (F_REF * R_REF) / vco_step;
frac = 1ul * thresh * m / (F_REF * R_REF);
tmp = gcd(thresh, frac);
thresh /= tmp;
frac /= tmp;
tmp = DIV_ROUND_UP(thresh, 4095);
thresh = DIV_ROUND_CLOSEST(thresh, tmp);
frac = DIV_ROUND_CLOSEST(frac, tmp);
tmp = 1ul * F_REF * R_REF * n;
tmp += 1ul * F_REF * R_REF * frac / thresh;
tmp /= lo_div;
dev_dbg(&s->udev->dev,
"%s: rf=%u:%u n=%d thresh=%d frac=%d\n",
__func__, f_rf, tmp, n, thresh, frac);
ret = msi3101_tuner_write(s, 0x00000e);
if (ret)
goto err;
ret = msi3101_tuner_write(s, 0x000003);
if (ret)
goto err;
reg = 0 << 0;
reg |= mode << 4;
reg |= filter_mode << 12;
reg |= bandwidth << 14;
reg |= 0x02 << 17;
reg |= 0x00 << 20;
ret = msi3101_tuner_write(s, reg);
if (ret)
goto err;
reg = 5 << 0;
reg |= thresh << 4;
reg |= 1 << 19;
reg |= 1 << 21;
ret = msi3101_tuner_write(s, reg);
if (ret)
goto err;
reg = 2 << 0;
reg |= frac << 4;
reg |= n << 16;
ret = msi3101_tuner_write(s, reg);
if (ret)
goto err;
if (f_rf < 120000000) {
gain_lut = msi3101_gain_lut_120;
len = ARRAY_SIZE(msi3101_gain_lut_120);
} else if (f_rf < 245000000) {
gain_lut = msi3101_gain_lut_245;
len = ARRAY_SIZE(msi3101_gain_lut_120);
} else {
gain_lut = msi3101_gain_lut_1000;
len = ARRAY_SIZE(msi3101_gain_lut_1000);
}
for (i = 0; i < len; i++) {
if (gain_lut[i].tot >= gain)
break;
}
if (i == len)
goto err;
dev_dbg(&s->udev->dev,
"%s: gain tot=%d baseband=%d lna=%d mixer=%d\n",
__func__, gain_lut[i].tot, gain_lut[i].baseband,
gain_lut[i].lna, gain_lut[i].mixer);
reg = 1 << 0;
reg |= gain_lut[i].baseband << 4;
reg |= 0 << 10;
reg |= gain_lut[i].mixer << 12;
reg |= gain_lut[i].lna << 13;
reg |= 4 << 14;
reg |= 0 << 17;
ret = msi3101_tuner_write(s, reg);
if (ret)
goto err;
reg = 6 << 0;
reg |= 63 << 4;
reg |= 4095 << 10;
ret = msi3101_tuner_write(s, reg);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->udev->dev, "%s: failed %d\n", __func__, ret);
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
ret = msi3101_set_usb_adc(s);
ret = msi3101_isoc_init(s);
if (ret)
msi3101_cleanup_queued_bufs(s);
ret = msi3101_ctrl_msg(s, CMD_START_STREAMING, 0);
mutex_unlock(&s->v4l2_lock);
return ret;
}
static int msi3101_stop_streaming(struct vb2_queue *vq)
{
struct msi3101_state *s = vb2_get_drv_priv(vq);
dev_dbg(&s->udev->dev, "%s:\n", __func__);
if (mutex_lock_interruptible(&s->v4l2_lock))
return -ERESTARTSYS;
if (s->udev)
msi3101_isoc_cleanup(s);
msi3101_cleanup_queued_bufs(s);
msleep(20);
msi3101_ctrl_msg(s, CMD_STOP_STREAMING, 0);
mutex_unlock(&s->v4l2_lock);
return 0;
}
static int msi3101_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
strlcpy(i->name, "SDR data", sizeof(i->name));
i->type = V4L2_INPUT_TYPE_CAMERA;
return 0;
}
static int msi3101_g_input(struct file *file, void *fh, unsigned int *i)
{
*i = 0;
return 0;
}
static int msi3101_s_input(struct file *file, void *fh, unsigned int i)
{
return i ? -EINVAL : 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct msi3101_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "%s:\n", __func__);
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv, struct v4l2_tuner *v)
{
struct msi3101_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "%s:\n", __func__);
strcpy(v->name, "SDR RX");
v->capability = V4L2_TUNER_CAP_LOW;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct msi3101_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "%s: frequency=%lu Hz (%u)\n",
__func__, f->frequency * 625UL / 10UL, f->frequency);
return v4l2_ctrl_s_ctrl_int64(s->ctrl_tuner_rf,
f->frequency * 625UL / 10UL);
}
static int msi3101_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct msi3101_state *s =
container_of(ctrl->handler, struct msi3101_state,
ctrl_handler);
int ret;
dev_dbg(&s->udev->dev,
"%s: id=%d name=%s val=%d min=%d max=%d step=%d\n",
__func__, ctrl->id, ctrl->name, ctrl->val,
ctrl->minimum, ctrl->maximum, ctrl->step);
switch (ctrl->id) {
case MSI3101_CID_SAMPLING_MODE:
case MSI3101_CID_SAMPLING_RATE:
case MSI3101_CID_SAMPLING_RESOLUTION:
ret = 0;
break;
case MSI3101_CID_TUNER_RF:
case MSI3101_CID_TUNER_BW:
case MSI3101_CID_TUNER_IF:
case MSI3101_CID_TUNER_GAIN:
ret = msi3101_set_tuner(s);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void msi3101_video_release(struct v4l2_device *v)
{
struct msi3101_state *s =
container_of(v, struct msi3101_state, v4l2_dev);
v4l2_ctrl_handler_free(&s->ctrl_handler);
v4l2_device_unregister(&s->v4l2_dev);
kfree(s);
}
static int msi3101_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct msi3101_state *s = NULL;
int ret;
static const char * const ctrl_sampling_mode_qmenu_strings[] = {
"Quadrature Sampling",
NULL,
};
static const struct v4l2_ctrl_config ctrl_sampling_mode = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_SAMPLING_MODE,
.type = V4L2_CTRL_TYPE_MENU,
.flags = V4L2_CTRL_FLAG_INACTIVE,
.name = "Sampling Mode",
.qmenu = ctrl_sampling_mode_qmenu_strings,
};
static const struct v4l2_ctrl_config ctrl_sampling_rate = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_SAMPLING_RATE,
.type = V4L2_CTRL_TYPE_INTEGER64,
.name = "Sampling Rate",
.min = 500000,
.max = 12000000,
.def = 2048000,
.step = 1,
};
static const struct v4l2_ctrl_config ctrl_sampling_resolution = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_SAMPLING_RESOLUTION,
.type = V4L2_CTRL_TYPE_INTEGER,
.flags = V4L2_CTRL_FLAG_INACTIVE,
.name = "Sampling Resolution",
.min = 10,
.max = 10,
.def = 10,
.step = 1,
};
static const struct v4l2_ctrl_config ctrl_tuner_rf = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_TUNER_RF,
.type = V4L2_CTRL_TYPE_INTEGER64,
.name = "Tuner RF",
.min = 40000000,
.max = 2000000000,
.def = 100000000,
.step = 1,
};
static const struct v4l2_ctrl_config ctrl_tuner_bw = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_TUNER_BW,
.type = V4L2_CTRL_TYPE_INTEGER,
.name = "Tuner BW",
.min = 200000,
.max = 8000000,
.def = 600000,
.step = 1,
};
static const struct v4l2_ctrl_config ctrl_tuner_if = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_TUNER_IF,
.type = V4L2_CTRL_TYPE_INTEGER,
.flags = V4L2_CTRL_FLAG_INACTIVE,
.name = "Tuner IF",
.min = 0,
.max = 2048000,
.def = 0,
.step = 1,
};
static const struct v4l2_ctrl_config ctrl_tuner_gain = {
.ops = &msi3101_ctrl_ops,
.id = MSI3101_CID_TUNER_GAIN,
.type = V4L2_CTRL_TYPE_INTEGER,
.name = "Tuner Gain",
.min = 0,
.max = 102,
.def = 0,
.step = 1,
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
s->vb_queue.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
s->vb_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_READ;
s->vb_queue.drv_priv = s;
s->vb_queue.buf_struct_size = sizeof(struct msi3101_frame_buf);
s->vb_queue.ops = &msi3101_vb2_ops;
s->vb_queue.mem_ops = &vb2_vmalloc_memops;
s->vb_queue.timestamp_type = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&s->vb_queue);
if (ret < 0) {
dev_err(&s->udev->dev, "Could not initialize vb2 queue\n");
goto err_free_mem;
}
s->vdev = msi3101_template;
s->vdev.queue = &s->vb_queue;
s->vdev.queue->lock = &s->vb_queue_lock;
set_bit(V4L2_FL_USE_FH_PRIO, &s->vdev.flags);
video_set_drvdata(&s->vdev, s);
v4l2_ctrl_handler_init(&s->ctrl_handler, 7);
v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_sampling_mode, NULL);
s->ctrl_sampling_rate = v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_sampling_rate, NULL);
v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_sampling_resolution, NULL);
s->ctrl_tuner_rf = v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_tuner_rf, NULL);
s->ctrl_tuner_bw = v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_tuner_bw, NULL);
s->ctrl_tuner_if = v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_tuner_if, NULL);
s->ctrl_tuner_gain = v4l2_ctrl_new_custom(&s->ctrl_handler, &ctrl_tuner_gain, NULL);
if (s->ctrl_handler.error) {
ret = s->ctrl_handler.error;
dev_err(&s->udev->dev, "Could not initialize controls\n");
goto err_free_controls;
}
s->v4l2_dev.release = msi3101_video_release;
ret = v4l2_device_register(&intf->dev, &s->v4l2_dev);
if (ret) {
dev_err(&s->udev->dev,
"Failed to register v4l2-device (%d)\n", ret);
goto err_free_controls;
}
s->v4l2_dev.ctrl_handler = &s->ctrl_handler;
s->vdev.v4l2_dev = &s->v4l2_dev;
s->vdev.lock = &s->v4l2_lock;
ret = video_register_device(&s->vdev, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
dev_err(&s->udev->dev,
"Failed to register as video device (%d)\n",
ret);
goto err_unregister_v4l2_dev;
}
dev_info(&s->udev->dev, "Registered as %s\n",
video_device_node_name(&s->vdev));
return 0;
err_unregister_v4l2_dev:
v4l2_device_unregister(&s->v4l2_dev);
err_free_controls:
v4l2_ctrl_handler_free(&s->ctrl_handler);
err_free_mem:
kfree(s);
return ret;
}
