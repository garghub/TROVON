static inline void print_err_status(struct stk1160 *dev,
int packet, int status)
{
char *errmsg = "Unknown";
switch (status) {
case -ENOENT:
errmsg = "unlinked synchronuously";
break;
case -ECONNRESET:
errmsg = "unlinked asynchronuously";
break;
case -ENOSR:
errmsg = "Buffer error (overrun)";
break;
case -EPIPE:
errmsg = "Stalled (device not responding)";
break;
case -EOVERFLOW:
errmsg = "Babble (bad cable?)";
break;
case -EPROTO:
errmsg = "Bit-stuff error (bad cable?)";
break;
case -EILSEQ:
errmsg = "CRC/Timeout (could be anything)";
break;
case -ETIME:
errmsg = "Device does not respond";
break;
}
if (packet < 0)
printk_ratelimited(KERN_WARNING "URB status %d [%s].\n",
status, errmsg);
else
printk_ratelimited(KERN_INFO "URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
static inline
struct stk1160_buffer *stk1160_next_buffer(struct stk1160 *dev)
{
struct stk1160_buffer *buf = NULL;
unsigned long flags = 0;
WARN_ON(dev->isoc_ctl.buf);
spin_lock_irqsave(&dev->buf_lock, flags);
if (!list_empty(&dev->avail_bufs)) {
buf = list_first_entry(&dev->avail_bufs,
struct stk1160_buffer, list);
list_del(&buf->list);
}
spin_unlock_irqrestore(&dev->buf_lock, flags);
return buf;
}
static inline
void stk1160_buffer_done(struct stk1160 *dev)
{
struct stk1160_buffer *buf = dev->isoc_ctl.buf;
buf->vb.sequence = dev->sequence++;
buf->vb.field = V4L2_FIELD_INTERLACED;
buf->vb.vb2_buf.planes[0].bytesused = buf->bytesused;
v4l2_get_timestamp(&buf->vb.timestamp);
vb2_set_plane_payload(&buf->vb.vb2_buf, 0, buf->bytesused);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_DONE);
dev->isoc_ctl.buf = NULL;
}
static inline
void stk1160_copy_video(struct stk1160 *dev, u8 *src, int len)
{
int linesdone, lineoff, lencopy;
int bytesperline = dev->width * 2;
struct stk1160_buffer *buf = dev->isoc_ctl.buf;
u8 *dst = buf->mem;
int remain;
len -= 4;
src += 4;
remain = len;
linesdone = buf->pos / bytesperline;
lineoff = buf->pos % bytesperline;
if (!buf->odd)
dst += bytesperline;
dst += linesdone * bytesperline * 2 + lineoff;
if (remain < (bytesperline - lineoff))
lencopy = remain;
else
lencopy = bytesperline - lineoff;
if (lencopy > buf->bytesused - buf->length) {
lencopy = buf->bytesused - buf->length;
remain = lencopy;
}
if (lencopy == 0 || remain == 0)
return;
if (lencopy < 0) {
stk1160_dbg("copy skipped: negative lencopy\n");
return;
}
if ((unsigned long)dst + lencopy >
(unsigned long)buf->mem + buf->length) {
printk_ratelimited(KERN_WARNING "stk1160: buffer overflow detected\n");
return;
}
memcpy(dst, src, lencopy);
buf->bytesused += lencopy;
buf->pos += lencopy;
remain -= lencopy;
while (remain > 0) {
dst += lencopy + bytesperline;
src += lencopy;
if (remain < bytesperline)
lencopy = remain;
else
lencopy = bytesperline;
if (lencopy > buf->bytesused - buf->length) {
lencopy = buf->bytesused - buf->length;
remain = lencopy;
}
if (lencopy == 0 || remain == 0)
return;
if (lencopy < 0) {
printk_ratelimited(KERN_WARNING "stk1160: negative lencopy detected\n");
return;
}
if ((unsigned long)dst + lencopy >
(unsigned long)buf->mem + buf->length) {
printk_ratelimited(KERN_WARNING "stk1160: buffer overflow detected\n");
return;
}
memcpy(dst, src, lencopy);
remain -= lencopy;
buf->bytesused += lencopy;
buf->pos += lencopy;
}
}
static void stk1160_process_isoc(struct stk1160 *dev, struct urb *urb)
{
int i, len, status;
u8 *p;
if (!dev) {
stk1160_warn("%s called with null device\n", __func__);
return;
}
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
return;
}
for (i = 0; i < urb->number_of_packets; i++) {
status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
continue;
}
p = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
len = urb->iso_frame_desc[i].actual_length;
if (len <= 4)
continue;
if (p[0] == 0xc0) {
if (dev->isoc_ctl.buf != NULL)
stk1160_buffer_done(dev);
dev->isoc_ctl.buf = stk1160_next_buffer(dev);
if (dev->isoc_ctl.buf == NULL)
return;
}
if (dev->isoc_ctl.buf == NULL)
continue;
if (p[0] == 0xc0 || p[0] == 0x80) {
dev->isoc_ctl.buf->odd = *p & 0x40;
dev->isoc_ctl.buf->pos = 0;
continue;
}
stk1160_copy_video(dev, p, len);
}
}
static void stk1160_isoc_irq(struct urb *urb)
{
int i, rc;
struct stk1160 *dev = urb->context;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
stk1160_err("urb error! status %d\n", urb->status);
return;
}
stk1160_process_isoc(dev, urb);
for (i = 0; i < urb->number_of_packets; i++) {
urb->iso_frame_desc[i].status = 0;
urb->iso_frame_desc[i].actual_length = 0;
}
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (rc)
stk1160_err("urb re-submit failed (%d)\n", rc);
}
void stk1160_cancel_isoc(struct stk1160 *dev)
{
int i, num_bufs = dev->isoc_ctl.num_bufs;
if (!num_bufs)
return;
stk1160_dbg("killing %d urbs...\n", num_bufs);
for (i = 0; i < num_bufs; i++) {
usb_kill_urb(dev->isoc_ctl.urb[i]);
}
stk1160_dbg("all urbs killed\n");
}
void stk1160_free_isoc(struct stk1160 *dev)
{
struct urb *urb;
int i, num_bufs = dev->isoc_ctl.num_bufs;
stk1160_dbg("freeing %d urb buffers...\n", num_bufs);
for (i = 0; i < num_bufs; i++) {
urb = dev->isoc_ctl.urb[i];
if (urb) {
if (dev->isoc_ctl.transfer_buffer[i]) {
#ifndef CONFIG_DMA_NONCOHERENT
usb_free_coherent(dev->udev,
urb->transfer_buffer_length,
dev->isoc_ctl.transfer_buffer[i],
urb->transfer_dma);
#else
kfree(dev->isoc_ctl.transfer_buffer[i]);
#endif
}
usb_free_urb(urb);
dev->isoc_ctl.urb[i] = NULL;
}
dev->isoc_ctl.transfer_buffer[i] = NULL;
}
kfree(dev->isoc_ctl.urb);
kfree(dev->isoc_ctl.transfer_buffer);
dev->isoc_ctl.urb = NULL;
dev->isoc_ctl.transfer_buffer = NULL;
dev->isoc_ctl.num_bufs = 0;
stk1160_dbg("all urb buffers freed\n");
}
void stk1160_uninit_isoc(struct stk1160 *dev)
{
stk1160_cancel_isoc(dev);
stk1160_free_isoc(dev);
}
int stk1160_alloc_isoc(struct stk1160 *dev)
{
struct urb *urb;
int i, j, k, sb_size, max_packets, num_bufs;
if (dev->isoc_ctl.num_bufs)
stk1160_uninit_isoc(dev);
stk1160_dbg("allocating urbs...\n");
num_bufs = STK1160_NUM_BUFS;
max_packets = STK1160_NUM_PACKETS;
sb_size = max_packets * dev->max_pkt_size;
dev->isoc_ctl.buf = NULL;
dev->isoc_ctl.max_pkt_size = dev->max_pkt_size;
dev->isoc_ctl.urb = kzalloc(sizeof(void *)*num_bufs, GFP_KERNEL);
if (!dev->isoc_ctl.urb) {
stk1160_err("out of memory for urb array\n");
return -ENOMEM;
}
dev->isoc_ctl.transfer_buffer = kzalloc(sizeof(void *)*num_bufs,
GFP_KERNEL);
if (!dev->isoc_ctl.transfer_buffer) {
stk1160_err("out of memory for usb transfers\n");
kfree(dev->isoc_ctl.urb);
return -ENOMEM;
}
for (i = 0; i < num_bufs; i++) {
urb = usb_alloc_urb(max_packets, GFP_KERNEL);
if (!urb) {
stk1160_err("cannot alloc urb[%d]\n", i);
goto free_i_bufs;
}
dev->isoc_ctl.urb[i] = urb;
#ifndef CONFIG_DMA_NONCOHERENT
dev->isoc_ctl.transfer_buffer[i] = usb_alloc_coherent(dev->udev,
sb_size, GFP_KERNEL, &urb->transfer_dma);
#else
dev->isoc_ctl.transfer_buffer[i] = kmalloc(sb_size, GFP_KERNEL);
#endif
if (!dev->isoc_ctl.transfer_buffer[i]) {
stk1160_err("cannot alloc %d bytes for tx[%d] buffer\n",
sb_size, i);
if (i < STK1160_MIN_BUFS)
goto free_i_bufs;
goto nomore_tx_bufs;
}
memset(dev->isoc_ctl.transfer_buffer[i], 0, sb_size);
urb->dev = dev->udev;
urb->pipe = usb_rcvisocpipe(dev->udev, STK1160_EP_VIDEO);
urb->transfer_buffer = dev->isoc_ctl.transfer_buffer[i];
urb->transfer_buffer_length = sb_size;
urb->complete = stk1160_isoc_irq;
urb->context = dev;
urb->interval = 1;
urb->start_frame = 0;
urb->number_of_packets = max_packets;
#ifndef CONFIG_DMA_NONCOHERENT
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
#else
urb->transfer_flags = URB_ISO_ASAP;
#endif
k = 0;
for (j = 0; j < max_packets; j++) {
urb->iso_frame_desc[j].offset = k;
urb->iso_frame_desc[j].length =
dev->isoc_ctl.max_pkt_size;
k += dev->isoc_ctl.max_pkt_size;
}
}
stk1160_dbg("%d urbs allocated\n", num_bufs);
dev->isoc_ctl.num_bufs = num_bufs;
return 0;
nomore_tx_bufs:
usb_free_urb(dev->isoc_ctl.urb[i]);
dev->isoc_ctl.urb[i] = NULL;
stk1160_warn("%d urbs allocated. Trying to continue...\n", i - 1);
dev->isoc_ctl.num_bufs = i - 1;
return 0;
free_i_bufs:
dev->isoc_ctl.num_bufs = i+1;
stk1160_free_isoc(dev);
return -ENOMEM;
}
