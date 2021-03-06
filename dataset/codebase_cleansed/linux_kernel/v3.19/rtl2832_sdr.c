static int rtl2832_sdr_wr(struct rtl2832_sdr_state *s, u8 reg, const u8 *val,
int len)
{
int ret;
#define MAX_WR_LEN 24
#define MAX_WR_XFER_LEN (MAX_WR_LEN + 1)
u8 buf[MAX_WR_XFER_LEN];
struct i2c_msg msg[1] = {
{
.addr = s->cfg->i2c_addr,
.flags = 0,
.len = 1 + len,
.buf = buf,
}
};
if (WARN_ON(len > MAX_WR_LEN))
return -EINVAL;
buf[0] = reg;
memcpy(&buf[1], val, len);
ret = i2c_transfer(s->i2c, msg, 1);
if (ret == 1) {
ret = 0;
} else {
dev_err(&s->i2c->dev,
"%s: I2C wr failed=%d reg=%02x len=%d\n",
KBUILD_MODNAME, ret, reg, len);
ret = -EREMOTEIO;
}
return ret;
}
static int rtl2832_sdr_rd(struct rtl2832_sdr_state *s, u8 reg, u8 *val, int len)
{
int ret;
struct i2c_msg msg[2] = {
{
.addr = s->cfg->i2c_addr,
.flags = 0,
.len = 1,
.buf = &reg,
}, {
.addr = s->cfg->i2c_addr,
.flags = I2C_M_RD,
.len = len,
.buf = val,
}
};
ret = i2c_transfer(s->i2c, msg, 2);
if (ret == 2) {
ret = 0;
} else {
dev_err(&s->i2c->dev,
"%s: I2C rd failed=%d reg=%02x len=%d\n",
KBUILD_MODNAME, ret, reg, len);
ret = -EREMOTEIO;
}
return ret;
}
static int rtl2832_sdr_wr_regs(struct rtl2832_sdr_state *s, u16 reg,
const u8 *val, int len)
{
int ret;
u8 reg2 = (reg >> 0) & 0xff;
u8 bank = (reg >> 8) & 0xff;
if (bank != s->bank) {
ret = rtl2832_sdr_wr(s, 0x00, &bank, 1);
if (ret)
return ret;
s->bank = bank;
}
return rtl2832_sdr_wr(s, reg2, val, len);
}
static int rtl2832_sdr_rd_regs(struct rtl2832_sdr_state *s, u16 reg, u8 *val,
int len)
{
int ret;
u8 reg2 = (reg >> 0) & 0xff;
u8 bank = (reg >> 8) & 0xff;
if (bank != s->bank) {
ret = rtl2832_sdr_wr(s, 0x00, &bank, 1);
if (ret)
return ret;
s->bank = bank;
}
return rtl2832_sdr_rd(s, reg2, val, len);
}
static int rtl2832_sdr_wr_reg(struct rtl2832_sdr_state *s, u16 reg, u8 val)
{
return rtl2832_sdr_wr_regs(s, reg, &val, 1);
}
static int rtl2832_sdr_wr_reg_mask(struct rtl2832_sdr_state *s, u16 reg,
u8 val, u8 mask)
{
int ret;
u8 tmp;
if (mask != 0xff) {
ret = rtl2832_sdr_rd_regs(s, reg, &tmp, 1);
if (ret)
return ret;
val &= mask;
tmp &= ~mask;
val |= tmp;
}
return rtl2832_sdr_wr_regs(s, reg, &val, 1);
}
static struct rtl2832_sdr_frame_buf *rtl2832_sdr_get_next_fill_buf(
struct rtl2832_sdr_state *s)
{
unsigned long flags;
struct rtl2832_sdr_frame_buf *buf = NULL;
spin_lock_irqsave(&s->queued_bufs_lock, flags);
if (list_empty(&s->queued_bufs))
goto leave;
buf = list_entry(s->queued_bufs.next,
struct rtl2832_sdr_frame_buf, list);
list_del(&buf->list);
leave:
spin_unlock_irqrestore(&s->queued_bufs_lock, flags);
return buf;
}
static unsigned int rtl2832_sdr_convert_stream(struct rtl2832_sdr_state *s,
void *dst, const u8 *src, unsigned int src_len)
{
unsigned int dst_len;
if (s->pixelformat == V4L2_SDR_FMT_CU8) {
memcpy(dst, src, src_len);
dst_len = src_len;
} else if (s->pixelformat == V4L2_SDR_FMT_CU16LE) {
unsigned int i;
u16 *u16dst = dst;
for (i = 0; i < src_len; i++)
*u16dst++ = (src[i] << 8) | (src[i] >> 0);
dst_len = 2 * src_len;
} else {
dst_len = 0;
}
if (unlikely(time_is_before_jiffies(s->jiffies_next))) {
#define MSECS 10000UL
unsigned int msecs = jiffies_to_msecs(jiffies -
s->jiffies_next + msecs_to_jiffies(MSECS));
unsigned int samples = s->sample - s->sample_measured;
s->jiffies_next = jiffies + msecs_to_jiffies(MSECS);
s->sample_measured = s->sample;
dev_dbg(&s->udev->dev,
"slen=%u samples=%u msecs=%u sample rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
s->sample += src_len / 2;
return dst_len;
}
static void rtl2832_sdr_urb_complete(struct urb *urb)
{
struct rtl2832_sdr_state *s = urb->context;
struct rtl2832_sdr_frame_buf *fbuf;
dev_dbg_ratelimited(&s->udev->dev,
"status=%d length=%d/%d errors=%d\n",
urb->status, urb->actual_length,
urb->transfer_buffer_length, urb->error_count);
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_err_ratelimited(&s->udev->dev, "urb failed=%d\n",
urb->status);
break;
}
if (likely(urb->actual_length > 0)) {
void *ptr;
unsigned int len;
fbuf = rtl2832_sdr_get_next_fill_buf(s);
if (unlikely(fbuf == NULL)) {
s->vb_full++;
dev_notice_ratelimited(&s->udev->dev,
"videobuf is full, %d packets dropped\n",
s->vb_full);
goto skip;
}
ptr = vb2_plane_vaddr(&fbuf->vb, 0);
len = rtl2832_sdr_convert_stream(s, ptr, urb->transfer_buffer,
urb->actual_length);
vb2_set_plane_payload(&fbuf->vb, 0, len);
v4l2_get_timestamp(&fbuf->vb.v4l2_buf.timestamp);
fbuf->vb.v4l2_buf.sequence = s->sequence++;
vb2_buffer_done(&fbuf->vb, VB2_BUF_STATE_DONE);
}
skip:
usb_submit_urb(urb, GFP_ATOMIC);
}
static int rtl2832_sdr_kill_urbs(struct rtl2832_sdr_state *s)
{
int i;
for (i = s->urbs_submitted - 1; i >= 0; i--) {
dev_dbg(&s->udev->dev, "kill urb=%d\n", i);
usb_kill_urb(s->urb_list[i]);
}
s->urbs_submitted = 0;
return 0;
}
static int rtl2832_sdr_submit_urbs(struct rtl2832_sdr_state *s)
{
int i, ret;
for (i = 0; i < s->urbs_initialized; i++) {
dev_dbg(&s->udev->dev, "submit urb=%d\n", i);
ret = usb_submit_urb(s->urb_list[i], GFP_ATOMIC);
if (ret) {
dev_err(&s->udev->dev,
"Could not submit urb no. %d - get them all back\n",
i);
rtl2832_sdr_kill_urbs(s);
return ret;
}
s->urbs_submitted++;
}
return 0;
}
static int rtl2832_sdr_free_stream_bufs(struct rtl2832_sdr_state *s)
{
if (s->flags & USB_STATE_URB_BUF) {
while (s->buf_num) {
s->buf_num--;
dev_dbg(&s->udev->dev, "free buf=%d\n", s->buf_num);
usb_free_coherent(s->udev, s->buf_size,
s->buf_list[s->buf_num],
s->dma_addr[s->buf_num]);
}
}
s->flags &= ~USB_STATE_URB_BUF;
return 0;
}
static int rtl2832_sdr_alloc_stream_bufs(struct rtl2832_sdr_state *s)
{
s->buf_num = 0;
s->buf_size = BULK_BUFFER_SIZE;
dev_dbg(&s->udev->dev, "all in all I will use %u bytes for streaming\n",
MAX_BULK_BUFS * BULK_BUFFER_SIZE);
for (s->buf_num = 0; s->buf_num < MAX_BULK_BUFS; s->buf_num++) {
s->buf_list[s->buf_num] = usb_alloc_coherent(s->udev,
BULK_BUFFER_SIZE, GFP_ATOMIC,
&s->dma_addr[s->buf_num]);
if (!s->buf_list[s->buf_num]) {
dev_dbg(&s->udev->dev, "alloc buf=%d failed\n",
s->buf_num);
rtl2832_sdr_free_stream_bufs(s);
return -ENOMEM;
}
dev_dbg(&s->udev->dev, "alloc buf=%d %p (dma %llu)\n",
s->buf_num, s->buf_list[s->buf_num],
(long long)s->dma_addr[s->buf_num]);
s->flags |= USB_STATE_URB_BUF;
}
return 0;
}
static int rtl2832_sdr_free_urbs(struct rtl2832_sdr_state *s)
{
int i;
rtl2832_sdr_kill_urbs(s);
for (i = s->urbs_initialized - 1; i >= 0; i--) {
if (s->urb_list[i]) {
dev_dbg(&s->udev->dev, "free urb=%d\n", i);
usb_free_urb(s->urb_list[i]);
}
}
s->urbs_initialized = 0;
return 0;
}
static int rtl2832_sdr_alloc_urbs(struct rtl2832_sdr_state *s)
{
int i, j;
for (i = 0; i < MAX_BULK_BUFS; i++) {
dev_dbg(&s->udev->dev, "alloc urb=%d\n", i);
s->urb_list[i] = usb_alloc_urb(0, GFP_ATOMIC);
if (!s->urb_list[i]) {
dev_dbg(&s->udev->dev, "failed\n");
for (j = 0; j < i; j++)
usb_free_urb(s->urb_list[j]);
return -ENOMEM;
}
usb_fill_bulk_urb(s->urb_list[i],
s->udev,
usb_rcvbulkpipe(s->udev, 0x81),
s->buf_list[i],
BULK_BUFFER_SIZE,
rtl2832_sdr_urb_complete, s);
s->urb_list[i]->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
s->urb_list[i]->transfer_dma = s->dma_addr[i];
s->urbs_initialized++;
}
return 0;
}
static void rtl2832_sdr_cleanup_queued_bufs(struct rtl2832_sdr_state *s)
{
unsigned long flags;
dev_dbg(&s->udev->dev, "\n");
spin_lock_irqsave(&s->queued_bufs_lock, flags);
while (!list_empty(&s->queued_bufs)) {
struct rtl2832_sdr_frame_buf *buf;
buf = list_entry(s->queued_bufs.next,
struct rtl2832_sdr_frame_buf, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&s->queued_bufs_lock, flags);
}
static void rtl2832_sdr_release_sec(struct dvb_frontend *fe)
{
struct rtl2832_sdr_state *s = fe->sec_priv;
dev_dbg(&s->udev->dev, "\n");
mutex_lock(&s->vb_queue_lock);
mutex_lock(&s->v4l2_lock);
s->udev = NULL;
v4l2_device_disconnect(&s->v4l2_dev);
video_unregister_device(&s->vdev);
mutex_unlock(&s->v4l2_lock);
mutex_unlock(&s->vb_queue_lock);
v4l2_device_put(&s->v4l2_dev);
fe->sec_priv = NULL;
}
static int rtl2832_sdr_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "\n");
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, s->vdev.name, sizeof(cap->card));
usb_make_path(s->udev, cap->bus_info, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE | V4L2_CAP_TUNER;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int rtl2832_sdr_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt, unsigned int *nbuffers,
unsigned int *nplanes, unsigned int sizes[], void *alloc_ctxs[])
{
struct rtl2832_sdr_state *s = vb2_get_drv_priv(vq);
dev_dbg(&s->udev->dev, "nbuffers=%d\n", *nbuffers);
if (vq->num_buffers + *nbuffers < 8)
*nbuffers = 8 - vq->num_buffers;
*nplanes = 1;
sizes[0] = PAGE_ALIGN(s->buffersize);
dev_dbg(&s->udev->dev, "nbuffers=%d sizes[0]=%d\n",
*nbuffers, sizes[0]);
return 0;
}
static int rtl2832_sdr_buf_prepare(struct vb2_buffer *vb)
{
struct rtl2832_sdr_state *s = vb2_get_drv_priv(vb->vb2_queue);
if (!s->udev)
return -ENODEV;
return 0;
}
static void rtl2832_sdr_buf_queue(struct vb2_buffer *vb)
{
struct rtl2832_sdr_state *s = vb2_get_drv_priv(vb->vb2_queue);
struct rtl2832_sdr_frame_buf *buf =
container_of(vb, struct rtl2832_sdr_frame_buf, vb);
unsigned long flags;
if (!s->udev) {
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
return;
}
spin_lock_irqsave(&s->queued_bufs_lock, flags);
list_add_tail(&buf->list, &s->queued_bufs);
spin_unlock_irqrestore(&s->queued_bufs_lock, flags);
}
static int rtl2832_sdr_set_adc(struct rtl2832_sdr_state *s)
{
struct dvb_frontend *fe = s->fe;
int ret;
unsigned int f_sr, f_if;
u8 buf[4], u8tmp1, u8tmp2;
u64 u64tmp;
u32 u32tmp;
dev_dbg(&s->udev->dev, "f_adc=%u\n", s->f_adc);
if (!test_bit(POWER_ON, &s->flags))
return 0;
if (s->f_adc == 0)
return 0;
f_sr = s->f_adc;
ret = rtl2832_sdr_wr_regs(s, 0x13e, "\x00\x00", 2);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x115, "\x00\x00\x00\x00", 4);
if (ret)
goto err;
if (fe->ops.tuner_ops.get_if_frequency)
ret = fe->ops.tuner_ops.get_if_frequency(fe, &f_if);
else
ret = -EINVAL;
if (ret)
goto err;
u64tmp = f_if % s->cfg->xtal;
u64tmp *= 0x400000;
u64tmp = div_u64(u64tmp, s->cfg->xtal);
u64tmp = -u64tmp;
u32tmp = u64tmp & 0x3fffff;
dev_dbg(&s->udev->dev, "f_if=%u if_ctl=%08x\n", f_if, u32tmp);
buf[0] = (u32tmp >> 16) & 0xff;
buf[1] = (u32tmp >> 8) & 0xff;
buf[2] = (u32tmp >> 0) & 0xff;
ret = rtl2832_sdr_wr_regs(s, 0x119, buf, 3);
if (ret)
goto err;
if (f_if) {
u8tmp1 = 0x1a;
u8tmp2 = 0x8d;
} else {
u8tmp1 = 0x1b;
u8tmp2 = 0xcd;
}
ret = rtl2832_sdr_wr_reg(s, 0x1b1, u8tmp1);
if (ret)
goto err;
ret = rtl2832_sdr_wr_reg(s, 0x008, u8tmp2);
if (ret)
goto err;
ret = rtl2832_sdr_wr_reg(s, 0x006, 0x80);
if (ret)
goto err;
u32tmp = div_u64(s->cfg->xtal * 0x400000ULL, f_sr * 4U);
u32tmp <<= 2;
buf[0] = (u32tmp >> 24) & 0xff;
buf[1] = (u32tmp >> 16) & 0xff;
buf[2] = (u32tmp >> 8) & 0xff;
buf[3] = (u32tmp >> 0) & 0xff;
ret = rtl2832_sdr_wr_regs(s, 0x19f, buf, 4);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x11c,
"\xca\xdc\xd7\xd8\xe0\xf2\x0e\x35\x06\x50\x9c\x0d\x71\x11\x14\x71\x74\x19\x41\xa5",
20);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x017, "\x11\x10", 2);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x019, "\x05", 1);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x01a, "\x1b\x16\x0d\x06\x01\xff", 6);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x192, "\x00\xf0\x0f", 3);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x061, "\x60", 1);
if (ret)
goto err;
switch (s->cfg->tuner) {
case RTL2832_TUNER_E4000:
ret = rtl2832_sdr_wr_regs(s, 0x112, "\x5a", 1);
ret = rtl2832_sdr_wr_regs(s, 0x102, "\x40", 1);
ret = rtl2832_sdr_wr_regs(s, 0x103, "\x5a", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c7, "\x30", 1);
ret = rtl2832_sdr_wr_regs(s, 0x104, "\xd0", 1);
ret = rtl2832_sdr_wr_regs(s, 0x105, "\xbe", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c8, "\x18", 1);
ret = rtl2832_sdr_wr_regs(s, 0x106, "\x35", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c9, "\x21", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1ca, "\x21", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1cb, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x107, "\x40", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1cd, "\x10", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1ce, "\x10", 1);
ret = rtl2832_sdr_wr_regs(s, 0x108, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x109, "\x7f", 1);
ret = rtl2832_sdr_wr_regs(s, 0x10a, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x10b, "\x7f", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00e, "\xfc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00e, "\xfc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x011, "\xd4", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1e5, "\xf0", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1d9, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1db, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1dd, "\x14", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1de, "\xec", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1d8, "\x0c", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1e6, "\x02", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1d7, "\x09", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00d, "\x83", 1);
ret = rtl2832_sdr_wr_regs(s, 0x010, "\x49", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00d, "\x87", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00d, "\x85", 1);
ret = rtl2832_sdr_wr_regs(s, 0x013, "\x02", 1);
break;
case RTL2832_TUNER_FC0012:
case RTL2832_TUNER_FC0013:
ret = rtl2832_sdr_wr_regs(s, 0x112, "\x5a", 1);
ret = rtl2832_sdr_wr_regs(s, 0x102, "\x40", 1);
ret = rtl2832_sdr_wr_regs(s, 0x103, "\x5a", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c7, "\x2c", 1);
ret = rtl2832_sdr_wr_regs(s, 0x104, "\xcc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x105, "\xbe", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c8, "\x16", 1);
ret = rtl2832_sdr_wr_regs(s, 0x106, "\x35", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c9, "\x21", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1ca, "\x21", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1cb, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x107, "\x40", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1cd, "\x10", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1ce, "\x10", 1);
ret = rtl2832_sdr_wr_regs(s, 0x108, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x109, "\x7f", 1);
ret = rtl2832_sdr_wr_regs(s, 0x10a, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x10b, "\x7f", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00e, "\xfc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00e, "\xfc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x011, "\xe9\xbf", 2);
ret = rtl2832_sdr_wr_regs(s, 0x1e5, "\xf0", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1d9, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1db, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1dd, "\x11", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1de, "\xef", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1d8, "\x0c", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1e6, "\x02", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1d7, "\x09", 1);
break;
case RTL2832_TUNER_R820T:
ret = rtl2832_sdr_wr_regs(s, 0x112, "\x5a", 1);
ret = rtl2832_sdr_wr_regs(s, 0x102, "\x40", 1);
ret = rtl2832_sdr_wr_regs(s, 0x115, "\x01", 1);
ret = rtl2832_sdr_wr_regs(s, 0x103, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c7, "\x24", 1);
ret = rtl2832_sdr_wr_regs(s, 0x104, "\xcc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x105, "\xbe", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c8, "\x14", 1);
ret = rtl2832_sdr_wr_regs(s, 0x106, "\x35", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1c9, "\x21", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1ca, "\x21", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1cb, "\x00", 1);
ret = rtl2832_sdr_wr_regs(s, 0x107, "\x40", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1cd, "\x10", 1);
ret = rtl2832_sdr_wr_regs(s, 0x1ce, "\x10", 1);
ret = rtl2832_sdr_wr_regs(s, 0x108, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x109, "\x7f", 1);
ret = rtl2832_sdr_wr_regs(s, 0x10a, "\x80", 1);
ret = rtl2832_sdr_wr_regs(s, 0x10b, "\x7f", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00e, "\xfc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x00e, "\xfc", 1);
ret = rtl2832_sdr_wr_regs(s, 0x011, "\xf4", 1);
break;
default:
dev_notice(&s->udev->dev, "Unsupported tuner\n");
}
ret = rtl2832_sdr_wr_reg_mask(s, 0x101, 0x04, 0x04);
if (ret)
goto err;
ret = rtl2832_sdr_wr_reg_mask(s, 0x101, 0x00, 0x04);
if (ret)
goto err;
err:
return ret;
}
static void rtl2832_sdr_unset_adc(struct rtl2832_sdr_state *s)
{
int ret;
dev_dbg(&s->udev->dev, "\n");
ret = rtl2832_sdr_wr_regs(s, 0x061, "\xe0", 1);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x019, "\x20", 1);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x017, "\x11\x10", 2);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x192, "\x00\x0f\xff", 3);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x13e, "\x40\x00", 2);
if (ret)
goto err;
ret = rtl2832_sdr_wr_regs(s, 0x115, "\x06\x3f\xce\xcc", 4);
if (ret)
goto err;
err:
return;
}
static int rtl2832_sdr_set_tuner_freq(struct rtl2832_sdr_state *s)
{
struct dvb_frontend *fe = s->fe;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct v4l2_ctrl *bandwidth_auto;
struct v4l2_ctrl *bandwidth;
if (s->f_tuner == 0)
return 0;
bandwidth_auto = v4l2_ctrl_find(&s->hdl,
V4L2_CID_RF_TUNER_BANDWIDTH_AUTO);
bandwidth = v4l2_ctrl_find(&s->hdl, V4L2_CID_RF_TUNER_BANDWIDTH);
if (v4l2_ctrl_g_ctrl(bandwidth_auto)) {
c->bandwidth_hz = s->f_adc;
v4l2_ctrl_s_ctrl(bandwidth, s->f_adc);
} else {
c->bandwidth_hz = v4l2_ctrl_g_ctrl(bandwidth);
}
c->frequency = s->f_tuner;
c->delivery_system = SYS_DVBT;
dev_dbg(&s->udev->dev, "frequency=%u bandwidth=%d\n",
c->frequency, c->bandwidth_hz);
if (!test_bit(POWER_ON, &s->flags))
return 0;
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
return 0;
}
static int rtl2832_sdr_set_tuner(struct rtl2832_sdr_state *s)
{
struct dvb_frontend *fe = s->fe;
dev_dbg(&s->udev->dev, "\n");
if (fe->ops.tuner_ops.init)
fe->ops.tuner_ops.init(fe);
return 0;
}
static void rtl2832_sdr_unset_tuner(struct rtl2832_sdr_state *s)
{
struct dvb_frontend *fe = s->fe;
dev_dbg(&s->udev->dev, "\n");
if (fe->ops.tuner_ops.sleep)
fe->ops.tuner_ops.sleep(fe);
return;
}
static int rtl2832_sdr_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct rtl2832_sdr_state *s = vb2_get_drv_priv(vq);
int ret;
dev_dbg(&s->udev->dev, "\n");
if (!s->udev)
return -ENODEV;
if (mutex_lock_interruptible(&s->v4l2_lock))
return -ERESTARTSYS;
if (s->d->props->power_ctrl)
s->d->props->power_ctrl(s->d, 1);
if (s->d->props->frontend_ctrl)
s->d->props->frontend_ctrl(s->fe, 1);
set_bit(POWER_ON, &s->flags);
ret = rtl2832_sdr_set_tuner(s);
if (ret)
goto err;
ret = rtl2832_sdr_set_tuner_freq(s);
if (ret)
goto err;
ret = rtl2832_sdr_set_adc(s);
if (ret)
goto err;
ret = rtl2832_sdr_alloc_stream_bufs(s);
if (ret)
goto err;
ret = rtl2832_sdr_alloc_urbs(s);
if (ret)
goto err;
s->sequence = 0;
ret = rtl2832_sdr_submit_urbs(s);
if (ret)
goto err;
err:
mutex_unlock(&s->v4l2_lock);
return ret;
}
static void rtl2832_sdr_stop_streaming(struct vb2_queue *vq)
{
struct rtl2832_sdr_state *s = vb2_get_drv_priv(vq);
dev_dbg(&s->udev->dev, "\n");
mutex_lock(&s->v4l2_lock);
rtl2832_sdr_kill_urbs(s);
rtl2832_sdr_free_urbs(s);
rtl2832_sdr_free_stream_bufs(s);
rtl2832_sdr_cleanup_queued_bufs(s);
rtl2832_sdr_unset_adc(s);
rtl2832_sdr_unset_tuner(s);
clear_bit(POWER_ON, &s->flags);
if (s->d->props->frontend_ctrl)
s->d->props->frontend_ctrl(s->fe, 0);
if (s->d->props->power_ctrl)
s->d->props->power_ctrl(s->d, 0);
mutex_unlock(&s->v4l2_lock);
}
static int rtl2832_sdr_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "index=%d type=%d\n", v->index, v->type);
if (v->index == 0) {
strlcpy(v->name, "ADC: Realtek RTL2832", sizeof(v->name));
v->type = V4L2_TUNER_ADC;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = 300000;
v->rangehigh = 3200000;
} else if (v->index == 1) {
strlcpy(v->name, "RF: <unknown>", sizeof(v->name));
v->type = V4L2_TUNER_RF;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = 50000000;
v->rangehigh = 2000000000;
} else {
return -EINVAL;
}
return 0;
}
static int rtl2832_sdr_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "\n");
if (v->index > 1)
return -EINVAL;
return 0;
}
static int rtl2832_sdr_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "tuner=%d type=%d index=%d\n",
band->tuner, band->type, band->index);
if (band->tuner == 0) {
if (band->index >= ARRAY_SIZE(bands_adc))
return -EINVAL;
*band = bands_adc[band->index];
} else if (band->tuner == 1) {
if (band->index >= ARRAY_SIZE(bands_fm))
return -EINVAL;
*band = bands_fm[band->index];
} else {
return -EINVAL;
}
return 0;
}
static int rtl2832_sdr_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
int ret = 0;
dev_dbg(&s->udev->dev, "tuner=%d type=%d\n",
f->tuner, f->type);
if (f->tuner == 0) {
f->frequency = s->f_adc;
f->type = V4L2_TUNER_ADC;
} else if (f->tuner == 1) {
f->frequency = s->f_tuner;
f->type = V4L2_TUNER_RF;
} else {
return -EINVAL;
}
return ret;
}
static int rtl2832_sdr_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
int ret, band;
dev_dbg(&s->udev->dev, "tuner=%d type=%d frequency=%u\n",
f->tuner, f->type, f->frequency);
#define BAND_ADC_0 ((bands_adc[0].rangehigh + bands_adc[1].rangelow) / 2)
#define BAND_ADC_1 ((bands_adc[1].rangehigh + bands_adc[2].rangelow) / 2)
if (f->tuner == 0 && f->type == V4L2_TUNER_ADC) {
if (f->frequency < BAND_ADC_0)
band = 0;
else if (f->frequency < BAND_ADC_1)
band = 1;
else
band = 2;
s->f_adc = clamp_t(unsigned int, f->frequency,
bands_adc[band].rangelow,
bands_adc[band].rangehigh);
dev_dbg(&s->udev->dev, "ADC frequency=%u Hz\n", s->f_adc);
ret = rtl2832_sdr_set_adc(s);
} else if (f->tuner == 1) {
s->f_tuner = clamp_t(unsigned int, f->frequency,
bands_fm[0].rangelow,
bands_fm[0].rangehigh);
dev_dbg(&s->udev->dev, "RF frequency=%u Hz\n", f->frequency);
ret = rtl2832_sdr_set_tuner_freq(s);
} else {
ret = -EINVAL;
}
return ret;
}
static int rtl2832_sdr_enum_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "\n");
if (f->index >= s->num_formats)
return -EINVAL;
strlcpy(f->description, formats[f->index].name, sizeof(f->description));
f->pixelformat = formats[f->index].pixelformat;
return 0;
}
static int rtl2832_sdr_g_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
dev_dbg(&s->udev->dev, "\n");
f->fmt.sdr.pixelformat = s->pixelformat;
f->fmt.sdr.buffersize = s->buffersize;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
return 0;
}
static int rtl2832_sdr_s_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
struct vb2_queue *q = &s->vb_queue;
int i;
dev_dbg(&s->udev->dev, "pixelformat fourcc %4.4s\n",
(char *)&f->fmt.sdr.pixelformat);
if (vb2_is_busy(q))
return -EBUSY;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < s->num_formats; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
s->pixelformat = formats[i].pixelformat;
s->buffersize = formats[i].buffersize;
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
s->pixelformat = formats[0].pixelformat;
s->buffersize = formats[0].buffersize;
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
return 0;
}
static int rtl2832_sdr_try_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rtl2832_sdr_state *s = video_drvdata(file);
int i;
dev_dbg(&s->udev->dev, "pixelformat fourcc %4.4s\n",
(char *)&f->fmt.sdr.pixelformat);
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < s->num_formats; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
return 0;
}
static int rtl2832_sdr_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct rtl2832_sdr_state *s =
container_of(ctrl->handler, struct rtl2832_sdr_state,
hdl);
struct dvb_frontend *fe = s->fe;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
dev_dbg(&s->udev->dev,
"id=%d name=%s val=%d min=%lld max=%lld step=%lld\n",
ctrl->id, ctrl->name, ctrl->val,
ctrl->minimum, ctrl->maximum, ctrl->step);
switch (ctrl->id) {
case V4L2_CID_RF_TUNER_BANDWIDTH_AUTO:
case V4L2_CID_RF_TUNER_BANDWIDTH:
if (s->bandwidth_auto->val) {
s32 val = s->f_adc + div_u64(s->bandwidth->step, 2);
u32 offset;
val = clamp_t(s32, val, s->bandwidth->minimum,
s->bandwidth->maximum);
offset = val - s->bandwidth->minimum;
offset = s->bandwidth->step *
div_u64(offset, s->bandwidth->step);
s->bandwidth->val = s->bandwidth->minimum + offset;
}
c->bandwidth_hz = s->bandwidth->val;
if (!test_bit(POWER_ON, &s->flags))
return 0;
if (fe->ops.tuner_ops.set_params)
ret = fe->ops.tuner_ops.set_params(fe);
else
ret = 0;
break;
default:
ret = -EINVAL;
}
return ret;
}
static void rtl2832_sdr_video_release(struct v4l2_device *v)
{
struct rtl2832_sdr_state *s =
container_of(v, struct rtl2832_sdr_state, v4l2_dev);
v4l2_ctrl_handler_free(&s->hdl);
v4l2_device_unregister(&s->v4l2_dev);
kfree(s);
}
struct dvb_frontend *rtl2832_sdr_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, const struct rtl2832_config *cfg,
struct v4l2_subdev *sd)
{
int ret;
struct rtl2832_sdr_state *s;
const struct v4l2_ctrl_ops *ops = &rtl2832_sdr_ctrl_ops;
struct dvb_usb_device *d = i2c_get_adapdata(i2c);
s = kzalloc(sizeof(struct rtl2832_sdr_state), GFP_KERNEL);
if (s == NULL) {
dev_err(&d->udev->dev,
"Could not allocate memory for rtl2832_sdr_state\n");
return NULL;
}
s->fe = fe;
s->d = d;
s->udev = d->udev;
s->i2c = i2c;
s->cfg = cfg;
s->f_adc = bands_adc[0].rangelow;
s->f_tuner = bands_fm[0].rangelow;
s->pixelformat = formats[0].pixelformat;
s->buffersize = formats[0].buffersize;
s->num_formats = NUM_FORMATS;
if (!rtl2832_sdr_emulated_fmt)
s->num_formats -= 1;
mutex_init(&s->v4l2_lock);
mutex_init(&s->vb_queue_lock);
spin_lock_init(&s->queued_bufs_lock);
INIT_LIST_HEAD(&s->queued_bufs);
s->vb_queue.type = V4L2_BUF_TYPE_SDR_CAPTURE;
s->vb_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_READ;
s->vb_queue.drv_priv = s;
s->vb_queue.buf_struct_size = sizeof(struct rtl2832_sdr_frame_buf);
s->vb_queue.ops = &rtl2832_sdr_vb2_ops;
s->vb_queue.mem_ops = &vb2_vmalloc_memops;
s->vb_queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&s->vb_queue);
if (ret) {
dev_err(&s->udev->dev, "Could not initialize vb2 queue\n");
goto err_free_mem;
}
switch (s->cfg->tuner) {
case RTL2832_TUNER_E4000:
v4l2_ctrl_handler_init(&s->hdl, 9);
if (sd)
v4l2_ctrl_add_handler(&s->hdl, sd->ctrl_handler, NULL);
break;
case RTL2832_TUNER_R820T:
v4l2_ctrl_handler_init(&s->hdl, 2);
s->bandwidth_auto = v4l2_ctrl_new_std(&s->hdl, ops,
V4L2_CID_RF_TUNER_BANDWIDTH_AUTO,
0, 1, 1, 1);
s->bandwidth = v4l2_ctrl_new_std(&s->hdl, ops,
V4L2_CID_RF_TUNER_BANDWIDTH,
0, 8000000, 100000, 0);
v4l2_ctrl_auto_cluster(2, &s->bandwidth_auto, 0, false);
break;
case RTL2832_TUNER_FC0012:
case RTL2832_TUNER_FC0013:
v4l2_ctrl_handler_init(&s->hdl, 2);
s->bandwidth_auto = v4l2_ctrl_new_std(&s->hdl, ops,
V4L2_CID_RF_TUNER_BANDWIDTH_AUTO,
0, 1, 1, 1);
s->bandwidth = v4l2_ctrl_new_std(&s->hdl, ops,
V4L2_CID_RF_TUNER_BANDWIDTH,
6000000, 8000000, 1000000,
6000000);
v4l2_ctrl_auto_cluster(2, &s->bandwidth_auto, 0, false);
break;
default:
v4l2_ctrl_handler_init(&s->hdl, 0);
dev_notice(&s->udev->dev, "%s: Unsupported tuner\n",
KBUILD_MODNAME);
goto err_free_controls;
}
if (s->hdl.error) {
ret = s->hdl.error;
dev_err(&s->udev->dev, "Could not initialize controls\n");
goto err_free_controls;
}
s->vdev = rtl2832_sdr_template;
s->vdev.queue = &s->vb_queue;
s->vdev.queue->lock = &s->vb_queue_lock;
video_set_drvdata(&s->vdev, s);
s->v4l2_dev.release = rtl2832_sdr_video_release;
ret = v4l2_device_register(&s->udev->dev, &s->v4l2_dev);
if (ret) {
dev_err(&s->udev->dev,
"Failed to register v4l2-device (%d)\n", ret);
goto err_free_controls;
}
s->v4l2_dev.ctrl_handler = &s->hdl;
s->vdev.v4l2_dev = &s->v4l2_dev;
s->vdev.lock = &s->v4l2_lock;
s->vdev.vfl_dir = VFL_DIR_RX;
ret = video_register_device(&s->vdev, VFL_TYPE_SDR, -1);
if (ret) {
dev_err(&s->udev->dev,
"Failed to register as video device (%d)\n",
ret);
goto err_unregister_v4l2_dev;
}
dev_info(&s->udev->dev, "Registered as %s\n",
video_device_node_name(&s->vdev));
fe->sec_priv = s;
fe->ops.release_sec = rtl2832_sdr_release_sec;
dev_info(&s->i2c->dev, "%s: Realtek RTL2832 SDR attached\n",
KBUILD_MODNAME);
dev_notice(&s->udev->dev,
"%s: SDR API is still slightly experimental and functionality changes may follow\n",
KBUILD_MODNAME);
return fe;
err_unregister_v4l2_dev:
v4l2_device_unregister(&s->v4l2_dev);
err_free_controls:
v4l2_ctrl_handler_free(&s->hdl);
err_free_mem:
kfree(s);
return NULL;
}
