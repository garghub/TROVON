static inline void print_err_status(struct au0828_dev *dev,
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
if (packet < 0) {
au0828_isocdbg("URB status %d [%s].\n", status, errmsg);
} else {
au0828_isocdbg("URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static int check_dev(struct au0828_dev *dev)
{
if (dev->dev_state & DEV_DISCONNECTED) {
printk(KERN_INFO "v4l2 ioctl: device not present\n");
return -ENODEV;
}
if (dev->dev_state & DEV_MISCONFIGURED) {
printk(KERN_INFO "v4l2 ioctl: device is misconfigured; "
"close and open it again\n");
return -EIO;
}
return 0;
}
static void au0828_irq_callback(struct urb *urb)
{
struct au0828_dmaqueue *dma_q = urb->context;
struct au0828_dev *dev = container_of(dma_q, struct au0828_dev, vidq);
unsigned long flags = 0;
int i;
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
au0828_isocdbg("au0828_irq_callback called: status kill\n");
return;
default:
au0828_isocdbg("urb completition error %d.\n", urb->status);
break;
}
spin_lock_irqsave(&dev->slock, flags);
dev->isoc_ctl.isoc_copy(dev, urb);
spin_unlock_irqrestore(&dev->slock, flags);
for (i = 0; i < urb->number_of_packets; i++) {
urb->iso_frame_desc[i].status = 0;
urb->iso_frame_desc[i].actual_length = 0;
}
urb->status = 0;
urb->status = usb_submit_urb(urb, GFP_ATOMIC);
if (urb->status) {
au0828_isocdbg("urb resubmit failed (error=%i)\n",
urb->status);
}
}
static void au0828_uninit_isoc(struct au0828_dev *dev)
{
struct urb *urb;
int i;
au0828_isocdbg("au0828: called au0828_uninit_isoc\n");
dev->isoc_ctl.nfields = -1;
for (i = 0; i < dev->isoc_ctl.num_bufs; i++) {
urb = dev->isoc_ctl.urb[i];
if (urb) {
if (!irqs_disabled())
usb_kill_urb(urb);
else
usb_unlink_urb(urb);
if (dev->isoc_ctl.transfer_buffer[i]) {
usb_free_coherent(dev->usbdev,
urb->transfer_buffer_length,
dev->isoc_ctl.transfer_buffer[i],
urb->transfer_dma);
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
}
static int au0828_init_isoc(struct au0828_dev *dev, int max_packets,
int num_bufs, int max_pkt_size,
int (*isoc_copy) (struct au0828_dev *dev, struct urb *urb))
{
struct au0828_dmaqueue *dma_q = &dev->vidq;
int i;
int sb_size, pipe;
struct urb *urb;
int j, k;
int rc;
au0828_isocdbg("au0828: called au0828_prepare_isoc\n");
au0828_uninit_isoc(dev);
dev->isoc_ctl.isoc_copy = isoc_copy;
dev->isoc_ctl.num_bufs = num_bufs;
dev->isoc_ctl.urb = kzalloc(sizeof(void *)*num_bufs, GFP_KERNEL);
if (!dev->isoc_ctl.urb) {
au0828_isocdbg("cannot alloc memory for usb buffers\n");
return -ENOMEM;
}
dev->isoc_ctl.transfer_buffer = kzalloc(sizeof(void *)*num_bufs,
GFP_KERNEL);
if (!dev->isoc_ctl.transfer_buffer) {
au0828_isocdbg("cannot allocate memory for usb transfer\n");
kfree(dev->isoc_ctl.urb);
return -ENOMEM;
}
dev->isoc_ctl.max_pkt_size = max_pkt_size;
dev->isoc_ctl.buf = NULL;
sb_size = max_packets * dev->isoc_ctl.max_pkt_size;
for (i = 0; i < dev->isoc_ctl.num_bufs; i++) {
urb = usb_alloc_urb(max_packets, GFP_KERNEL);
if (!urb) {
au0828_isocdbg("cannot alloc isoc_ctl.urb %i\n", i);
au0828_uninit_isoc(dev);
return -ENOMEM;
}
dev->isoc_ctl.urb[i] = urb;
dev->isoc_ctl.transfer_buffer[i] = usb_alloc_coherent(dev->usbdev,
sb_size, GFP_KERNEL, &urb->transfer_dma);
if (!dev->isoc_ctl.transfer_buffer[i]) {
printk("unable to allocate %i bytes for transfer"
" buffer %i%s\n",
sb_size, i,
in_interrupt() ? " while in int" : "");
au0828_uninit_isoc(dev);
return -ENOMEM;
}
memset(dev->isoc_ctl.transfer_buffer[i], 0, sb_size);
pipe = usb_rcvisocpipe(dev->usbdev,
dev->isoc_in_endpointaddr),
usb_fill_int_urb(urb, dev->usbdev, pipe,
dev->isoc_ctl.transfer_buffer[i], sb_size,
au0828_irq_callback, dma_q, 1);
urb->number_of_packets = max_packets;
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
k = 0;
for (j = 0; j < max_packets; j++) {
urb->iso_frame_desc[j].offset = k;
urb->iso_frame_desc[j].length =
dev->isoc_ctl.max_pkt_size;
k += dev->isoc_ctl.max_pkt_size;
}
}
init_waitqueue_head(&dma_q->wq);
for (i = 0; i < dev->isoc_ctl.num_bufs; i++) {
rc = usb_submit_urb(dev->isoc_ctl.urb[i], GFP_ATOMIC);
if (rc) {
au0828_isocdbg("submit of urb %i failed (error=%i)\n",
i, rc);
au0828_uninit_isoc(dev);
return rc;
}
}
return 0;
}
static inline void buffer_filled(struct au0828_dev *dev,
struct au0828_dmaqueue *dma_q,
struct au0828_buffer *buf)
{
au0828_isocdbg("[%p/%d] wakeup\n", buf, buf->vb.i);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
v4l2_get_timestamp(&buf->vb.ts);
dev->isoc_ctl.buf = NULL;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
static inline void vbi_buffer_filled(struct au0828_dev *dev,
struct au0828_dmaqueue *dma_q,
struct au0828_buffer *buf)
{
au0828_isocdbg("[%p/%d] wakeup\n", buf, buf->vb.i);
buf->vb.state = VIDEOBUF_DONE;
buf->vb.field_count++;
v4l2_get_timestamp(&buf->vb.ts);
dev->isoc_ctl.vbi_buf = NULL;
list_del(&buf->vb.queue);
wake_up(&buf->vb.done);
}
static void au0828_copy_video(struct au0828_dev *dev,
struct au0828_dmaqueue *dma_q,
struct au0828_buffer *buf,
unsigned char *p,
unsigned char *outp, unsigned long len)
{
void *fieldstart, *startwrite, *startread;
int linesdone, currlinedone, offset, lencopy, remain;
int bytesperline = dev->width << 1;
if (len == 0)
return;
if (dma_q->pos + len > buf->vb.size)
len = buf->vb.size - dma_q->pos;
startread = p;
remain = len;
if (buf->top_field)
fieldstart = outp;
else
fieldstart = outp + bytesperline;
linesdone = dma_q->pos / bytesperline;
currlinedone = dma_q->pos % bytesperline;
offset = linesdone * bytesperline * 2 + currlinedone;
startwrite = fieldstart + offset;
lencopy = bytesperline - currlinedone;
lencopy = lencopy > remain ? remain : lencopy;
if ((char *)startwrite + lencopy > (char *)outp + buf->vb.size) {
au0828_isocdbg("Overflow of %zi bytes past buffer end (1)\n",
((char *)startwrite + lencopy) -
((char *)outp + buf->vb.size));
remain = (char *)outp + buf->vb.size - (char *)startwrite;
lencopy = remain;
}
if (lencopy <= 0)
return;
memcpy(startwrite, startread, lencopy);
remain -= lencopy;
while (remain > 0) {
startwrite += lencopy + bytesperline;
startread += lencopy;
if (bytesperline > remain)
lencopy = remain;
else
lencopy = bytesperline;
if ((char *)startwrite + lencopy > (char *)outp +
buf->vb.size) {
au0828_isocdbg("Overflow %zi bytes past buf end (2)\n",
((char *)startwrite + lencopy) -
((char *)outp + buf->vb.size));
lencopy = remain = (char *)outp + buf->vb.size -
(char *)startwrite;
}
if (lencopy <= 0)
break;
memcpy(startwrite, startread, lencopy);
remain -= lencopy;
}
if (offset > 1440) {
if (outp[0] < 0x60 && outp[1440] < 0x60)
dev->greenscreen_detected = 1;
}
dma_q->pos += len;
}
static inline void get_next_buf(struct au0828_dmaqueue *dma_q,
struct au0828_buffer **buf)
{
struct au0828_dev *dev = container_of(dma_q, struct au0828_dev, vidq);
if (list_empty(&dma_q->active)) {
au0828_isocdbg("No active queue to serve\n");
dev->isoc_ctl.buf = NULL;
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next, struct au0828_buffer, vb.queue);
dev->isoc_ctl.buf = *buf;
return;
}
static void au0828_copy_vbi(struct au0828_dev *dev,
struct au0828_dmaqueue *dma_q,
struct au0828_buffer *buf,
unsigned char *p,
unsigned char *outp, unsigned long len)
{
unsigned char *startwrite, *startread;
int bytesperline;
int i, j = 0;
if (dev == NULL) {
au0828_isocdbg("dev is null\n");
return;
}
if (dma_q == NULL) {
au0828_isocdbg("dma_q is null\n");
return;
}
if (buf == NULL)
return;
if (p == NULL) {
au0828_isocdbg("p is null\n");
return;
}
if (outp == NULL) {
au0828_isocdbg("outp is null\n");
return;
}
bytesperline = dev->vbi_width;
if (dma_q->pos + len > buf->vb.size)
len = buf->vb.size - dma_q->pos;
startread = p;
startwrite = outp + (dma_q->pos / 2);
if (buf->top_field == 0)
startwrite += bytesperline * dev->vbi_height;
for (i = 0; i < len; i += 2)
startwrite[j++] = startread[i+1];
dma_q->pos += len;
}
static inline void vbi_get_next_buf(struct au0828_dmaqueue *dma_q,
struct au0828_buffer **buf)
{
struct au0828_dev *dev = container_of(dma_q, struct au0828_dev, vbiq);
char *outp;
if (list_empty(&dma_q->active)) {
au0828_isocdbg("No active queue to serve\n");
dev->isoc_ctl.vbi_buf = NULL;
*buf = NULL;
return;
}
*buf = list_entry(dma_q->active.next, struct au0828_buffer, vb.queue);
outp = videobuf_to_vmalloc(&(*buf)->vb);
memset(outp, 0x00, (*buf)->vb.size);
dev->isoc_ctl.vbi_buf = *buf;
return;
}
static inline int au0828_isoc_copy(struct au0828_dev *dev, struct urb *urb)
{
struct au0828_buffer *buf;
struct au0828_buffer *vbi_buf;
struct au0828_dmaqueue *dma_q = urb->context;
struct au0828_dmaqueue *vbi_dma_q = &dev->vbiq;
unsigned char *outp = NULL;
unsigned char *vbioutp = NULL;
int i, len = 0, rc = 1;
unsigned char *p;
unsigned char fbyte;
unsigned int vbi_field_size;
unsigned int remain, lencopy;
if (!dev)
return 0;
if ((dev->dev_state & DEV_DISCONNECTED) ||
(dev->dev_state & DEV_MISCONFIGURED))
return 0;
if (urb->status < 0) {
print_err_status(dev, -1, urb->status);
if (urb->status == -ENOENT)
return 0;
}
buf = dev->isoc_ctl.buf;
if (buf != NULL)
outp = videobuf_to_vmalloc(&buf->vb);
vbi_buf = dev->isoc_ctl.vbi_buf;
if (vbi_buf != NULL)
vbioutp = videobuf_to_vmalloc(&vbi_buf->vb);
for (i = 0; i < urb->number_of_packets; i++) {
int status = urb->iso_frame_desc[i].status;
if (status < 0) {
print_err_status(dev, i, status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
if (urb->iso_frame_desc[i].actual_length <= 0)
continue;
if (urb->iso_frame_desc[i].actual_length >
dev->max_pkt_size) {
au0828_isocdbg("packet bigger than packet size");
continue;
}
p = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
fbyte = p[0];
len = urb->iso_frame_desc[i].actual_length - 4;
p += 4;
if (fbyte & 0x80) {
len -= 4;
p += 4;
au0828_isocdbg("Video frame %s\n",
(fbyte & 0x40) ? "odd" : "even");
if (fbyte & 0x40) {
if (vbi_buf != NULL)
vbi_buffer_filled(dev,
vbi_dma_q,
vbi_buf);
vbi_get_next_buf(vbi_dma_q, &vbi_buf);
if (vbi_buf == NULL)
vbioutp = NULL;
else
vbioutp = videobuf_to_vmalloc(
&vbi_buf->vb);
if (buf != NULL)
buffer_filled(dev, dma_q, buf);
get_next_buf(dma_q, &buf);
if (buf == NULL)
outp = NULL;
else
outp = videobuf_to_vmalloc(&buf->vb);
if (dev->vid_timeout_running)
mod_timer(&dev->vid_timeout,
jiffies + (HZ / 10));
if (dev->vbi_timeout_running)
mod_timer(&dev->vbi_timeout,
jiffies + (HZ / 10));
}
if (buf != NULL) {
if (fbyte & 0x40)
buf->top_field = 1;
else
buf->top_field = 0;
}
if (vbi_buf != NULL) {
if (fbyte & 0x40)
vbi_buf->top_field = 1;
else
vbi_buf->top_field = 0;
}
dev->vbi_read = 0;
vbi_dma_q->pos = 0;
dma_q->pos = 0;
}
vbi_field_size = dev->vbi_width * dev->vbi_height * 2;
if (dev->vbi_read < vbi_field_size) {
remain = vbi_field_size - dev->vbi_read;
if (len < remain)
lencopy = len;
else
lencopy = remain;
if (vbi_buf != NULL)
au0828_copy_vbi(dev, vbi_dma_q, vbi_buf, p,
vbioutp, len);
len -= lencopy;
p += lencopy;
dev->vbi_read += lencopy;
}
if (dev->vbi_read >= vbi_field_size && buf != NULL)
au0828_copy_video(dev, dma_q, buf, p, outp, len);
}
return rc;
}
static int
buffer_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct au0828_fh *fh = vq->priv_data;
*size = (fh->dev->width * fh->dev->height * 16 + 7) >> 3;
if (0 == *count)
*count = AU0828_DEF_BUF;
if (*count < AU0828_MIN_BUF)
*count = AU0828_MIN_BUF;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct au0828_buffer *buf)
{
struct au0828_fh *fh = vq->priv_data;
struct au0828_dev *dev = fh->dev;
unsigned long flags = 0;
if (in_interrupt())
BUG();
spin_lock_irqsave(&dev->slock, flags);
if (dev->isoc_ctl.buf == buf)
dev->isoc_ctl.buf = NULL;
spin_unlock_irqrestore(&dev->slock, flags);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int
buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct au0828_fh *fh = vq->priv_data;
struct au0828_buffer *buf = container_of(vb, struct au0828_buffer, vb);
struct au0828_dev *dev = fh->dev;
int rc = 0, urb_init = 0;
buf->vb.size = (fh->dev->width * fh->dev->height * 16 + 7) >> 3;
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
buf->vb.width = dev->width;
buf->vb.height = dev->height;
buf->vb.field = field;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
rc = videobuf_iolock(vq, &buf->vb, NULL);
if (rc < 0) {
printk(KERN_INFO "videobuf_iolock failed\n");
goto fail;
}
}
if (!dev->isoc_ctl.num_bufs)
urb_init = 1;
if (urb_init) {
rc = au0828_init_isoc(dev, AU0828_ISO_PACKETS_PER_URB,
AU0828_MAX_ISO_BUFS, dev->max_pkt_size,
au0828_isoc_copy);
if (rc < 0) {
printk(KERN_INFO "au0828_init_isoc failed\n");
goto fail;
}
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(vq, buf);
return rc;
}
static void
buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct au0828_buffer *buf = container_of(vb,
struct au0828_buffer,
vb);
struct au0828_fh *fh = vq->priv_data;
struct au0828_dev *dev = fh->dev;
struct au0828_dmaqueue *vidq = &dev->vidq;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &vidq->active);
}
static void buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct au0828_buffer *buf = container_of(vb,
struct au0828_buffer,
vb);
free_buffer(vq, buf);
}
static int au0828_i2s_init(struct au0828_dev *dev)
{
au0828_writereg(dev, AU0828_AUDIOCTRL_50C, 0x01);
return 0;
}
static int au0828_analog_stream_enable(struct au0828_dev *d)
{
dprintk(1, "au0828_analog_stream_enable called\n");
au0828_writereg(d, AU0828_SENSORCTRL_VBI_103, 0x00);
au0828_writereg(d, 0x106, 0x00);
au0828_writereg(d, 0x110, 0x00);
au0828_writereg(d, 0x111, 0x00);
au0828_writereg(d, 0x114, 0xa0);
au0828_writereg(d, 0x115, 0x05);
au0828_writereg(d, 0x112, 0x00);
au0828_writereg(d, 0x113, 0x00);
au0828_writereg(d, 0x116, 0xf2);
au0828_writereg(d, 0x117, 0x00);
au0828_writereg(d, AU0828_SENSORCTRL_100, 0xb3);
return 0;
}
int au0828_analog_stream_disable(struct au0828_dev *d)
{
dprintk(1, "au0828_analog_stream_disable called\n");
au0828_writereg(d, AU0828_SENSORCTRL_100, 0x0);
return 0;
}
static void au0828_analog_stream_reset(struct au0828_dev *dev)
{
dprintk(1, "au0828_analog_stream_reset called\n");
au0828_writereg(dev, AU0828_SENSORCTRL_100, 0x0);
mdelay(30);
au0828_writereg(dev, AU0828_SENSORCTRL_100, 0xb3);
}
static int au0828_stream_interrupt(struct au0828_dev *dev)
{
int ret = 0;
dev->stream_state = STREAM_INTERRUPT;
if (dev->dev_state == DEV_DISCONNECTED)
return -ENODEV;
else if (ret) {
dev->dev_state = DEV_MISCONFIGURED;
dprintk(1, "%s device is misconfigured!\n", __func__);
return ret;
}
return 0;
}
void au0828_analog_unregister(struct au0828_dev *dev)
{
dprintk(1, "au0828_release_resources called\n");
mutex_lock(&au0828_sysfs_lock);
if (dev->vdev)
video_unregister_device(dev->vdev);
if (dev->vbi_dev)
video_unregister_device(dev->vbi_dev);
mutex_unlock(&au0828_sysfs_lock);
}
static int res_get(struct au0828_fh *fh, unsigned int bit)
{
struct au0828_dev *dev = fh->dev;
if (fh->resources & bit)
return 1;
if (dev->resources & bit) {
return 0;
}
fh->resources |= bit;
dev->resources |= bit;
dprintk(1, "res: get %d\n", bit);
return 1;
}
static int res_check(struct au0828_fh *fh, unsigned int bit)
{
return fh->resources & bit;
}
static int res_locked(struct au0828_dev *dev, unsigned int bit)
{
return dev->resources & bit;
}
static void res_free(struct au0828_fh *fh, unsigned int bits)
{
struct au0828_dev *dev = fh->dev;
BUG_ON((fh->resources & bits) != bits);
fh->resources &= ~bits;
dev->resources &= ~bits;
dprintk(1, "res: put %d\n", bits);
}
static int get_ressource(struct au0828_fh *fh)
{
switch (fh->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return AU0828_RESOURCE_VIDEO;
case V4L2_BUF_TYPE_VBI_CAPTURE:
return AU0828_RESOURCE_VBI;
default:
BUG();
return 0;
}
}
static void au0828_vid_buffer_timeout(unsigned long data)
{
struct au0828_dev *dev = (struct au0828_dev *) data;
struct au0828_dmaqueue *dma_q = &dev->vidq;
struct au0828_buffer *buf;
unsigned char *vid_data;
unsigned long flags = 0;
spin_lock_irqsave(&dev->slock, flags);
buf = dev->isoc_ctl.buf;
if (buf != NULL) {
vid_data = videobuf_to_vmalloc(&buf->vb);
memset(vid_data, 0x00, buf->vb.size);
buffer_filled(dev, dma_q, buf);
}
get_next_buf(dma_q, &buf);
if (dev->vid_timeout_running == 1)
mod_timer(&dev->vid_timeout, jiffies + (HZ / 10));
spin_unlock_irqrestore(&dev->slock, flags);
}
static void au0828_vbi_buffer_timeout(unsigned long data)
{
struct au0828_dev *dev = (struct au0828_dev *) data;
struct au0828_dmaqueue *dma_q = &dev->vbiq;
struct au0828_buffer *buf;
unsigned char *vbi_data;
unsigned long flags = 0;
spin_lock_irqsave(&dev->slock, flags);
buf = dev->isoc_ctl.vbi_buf;
if (buf != NULL) {
vbi_data = videobuf_to_vmalloc(&buf->vb);
memset(vbi_data, 0x00, buf->vb.size);
vbi_buffer_filled(dev, dma_q, buf);
}
vbi_get_next_buf(dma_q, &buf);
if (dev->vbi_timeout_running == 1)
mod_timer(&dev->vbi_timeout, jiffies + (HZ / 10));
spin_unlock_irqrestore(&dev->slock, flags);
}
static int au0828_v4l2_open(struct file *filp)
{
int ret = 0;
struct video_device *vdev = video_devdata(filp);
struct au0828_dev *dev = video_drvdata(filp);
struct au0828_fh *fh;
int type;
switch (vdev->vfl_type) {
case VFL_TYPE_GRABBER:
type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case VFL_TYPE_VBI:
type = V4L2_BUF_TYPE_VBI_CAPTURE;
break;
default:
return -EINVAL;
}
fh = kzalloc(sizeof(struct au0828_fh), GFP_KERNEL);
if (NULL == fh) {
dprintk(1, "Failed allocate au0828_fh struct!\n");
return -ENOMEM;
}
fh->type = type;
fh->dev = dev;
filp->private_data = fh;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE && dev->users == 0) {
ret = usb_set_interface(dev->usbdev, 0, 5);
if (ret < 0) {
printk(KERN_INFO "Au0828 can't set alternate to 5!\n");
return -EBUSY;
}
dev->width = NTSC_STD_W;
dev->height = NTSC_STD_H;
dev->frame_size = dev->width * dev->height * 2;
dev->field_size = dev->width * dev->height;
dev->bytesperline = dev->width * 2;
au0828_analog_stream_enable(dev);
au0828_analog_stream_reset(dev);
au0828_i2s_init(dev);
dev->stream_state = STREAM_OFF;
dev->dev_state |= DEV_INITIALIZED;
}
dev->users++;
videobuf_queue_vmalloc_init(&fh->vb_vidq, &au0828_video_qops,
NULL, &dev->slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_INTERLACED,
sizeof(struct au0828_buffer), fh,
&dev->lock);
dev->vbi_width = 720;
dev->vbi_height = 1;
videobuf_queue_vmalloc_init(&fh->vb_vbiq, &au0828_vbi_qops,
NULL, &dev->slock,
V4L2_BUF_TYPE_VBI_CAPTURE,
V4L2_FIELD_SEQ_TB,
sizeof(struct au0828_buffer), fh,
&dev->lock);
return ret;
}
static int au0828_v4l2_close(struct file *filp)
{
int ret;
struct au0828_fh *fh = filp->private_data;
struct au0828_dev *dev = fh->dev;
if (res_check(fh, AU0828_RESOURCE_VIDEO)) {
dev->vid_timeout_running = 0;
del_timer_sync(&dev->vid_timeout);
videobuf_stop(&fh->vb_vidq);
res_free(fh, AU0828_RESOURCE_VIDEO);
}
if (res_check(fh, AU0828_RESOURCE_VBI)) {
dev->vbi_timeout_running = 0;
del_timer_sync(&dev->vbi_timeout);
videobuf_stop(&fh->vb_vbiq);
res_free(fh, AU0828_RESOURCE_VBI);
}
if (dev->users == 1) {
if (dev->dev_state & DEV_DISCONNECTED) {
au0828_analog_unregister(dev);
kfree(dev);
return 0;
}
au0828_analog_stream_disable(dev);
au0828_uninit_isoc(dev);
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_power, 0);
ret = usb_set_interface(dev->usbdev, 0, 0);
if (ret < 0)
printk(KERN_INFO "Au0828 can't set alternate to 0!\n");
}
videobuf_mmap_free(&fh->vb_vidq);
videobuf_mmap_free(&fh->vb_vbiq);
kfree(fh);
dev->users--;
wake_up_interruptible_nr(&dev->open, 1);
return 0;
}
static ssize_t au0828_v4l2_read(struct file *filp, char __user *buf,
size_t count, loff_t *pos)
{
struct au0828_fh *fh = filp->private_data;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (res_locked(dev, AU0828_RESOURCE_VIDEO))
return -EBUSY;
return videobuf_read_stream(&fh->vb_vidq, buf, count, pos, 0,
filp->f_flags & O_NONBLOCK);
}
if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
if (!res_get(fh, AU0828_RESOURCE_VBI))
return -EBUSY;
if (dev->vbi_timeout_running == 0) {
dev->vbi_timeout_running = 1;
mod_timer(&dev->vbi_timeout, jiffies + (HZ / 10));
}
return videobuf_read_stream(&fh->vb_vbiq, buf, count, pos, 0,
filp->f_flags & O_NONBLOCK);
}
return 0;
}
static unsigned int au0828_v4l2_poll(struct file *filp, poll_table *wait)
{
struct au0828_fh *fh = filp->private_data;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
if (!res_get(fh, AU0828_RESOURCE_VIDEO))
return POLLERR;
return videobuf_poll_stream(filp, &fh->vb_vidq, wait);
} else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
if (!res_get(fh, AU0828_RESOURCE_VBI))
return POLLERR;
return videobuf_poll_stream(filp, &fh->vb_vbiq, wait);
} else {
return POLLERR;
}
}
static int au0828_v4l2_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct au0828_fh *fh = filp->private_data;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_mmap_mapper(&fh->vb_vidq, vma);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_mmap_mapper(&fh->vb_vbiq, vma);
return rc;
}
static int au0828_set_format(struct au0828_dev *dev, unsigned int cmd,
struct v4l2_format *format)
{
int ret;
int width = format->fmt.pix.width;
int height = format->fmt.pix.height;
if (format->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (format->fmt.pix.pixelformat != V4L2_PIX_FMT_UYVY)
return -EINVAL;
if (width != 720)
width = 720;
if (height != 480)
height = 480;
format->fmt.pix.width = width;
format->fmt.pix.height = height;
format->fmt.pix.pixelformat = V4L2_PIX_FMT_UYVY;
format->fmt.pix.bytesperline = width * 2;
format->fmt.pix.sizeimage = width * height * 2;
format->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
format->fmt.pix.field = V4L2_FIELD_INTERLACED;
if (cmd == VIDIOC_TRY_FMT)
return 0;
dev->width = width;
dev->height = height;
dev->frame_size = width * height * 2;
dev->field_size = width * height;
dev->bytesperline = width * 2;
if (dev->stream_state == STREAM_ON) {
dprintk(1, "VIDIOC_SET_FMT: interrupting stream!\n");
ret = au0828_stream_interrupt(dev);
if (ret != 0) {
dprintk(1, "error interrupting video stream!\n");
return ret;
}
}
ret = usb_set_interface(dev->usbdev, 0, 5);
if (ret < 0) {
printk(KERN_INFO "Au0828 can't set alt setting to 5!\n");
return -EBUSY;
}
au0828_analog_stream_enable(dev);
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, queryctrl, qc);
if (qc->type)
return 0;
else
return -EINVAL;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
strlcpy(cap->driver, "au0828", sizeof(cap->driver));
strlcpy(cap->card, dev->board.name, sizeof(cap->card));
strlcpy(cap->bus_info, dev->v4l2_dev.name, sizeof(cap->bus_info));
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_VBI_CAPTURE |
V4L2_CAP_AUDIO |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING |
V4L2_CAP_TUNER;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index)
return -EINVAL;
f->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
strcpy(f->description, "Packed YUV2");
f->flags = 0;
f->pixelformat = V4L2_PIX_FMT_UYVY;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
f->fmt.pix.width = dev->width;
f->fmt.pix.height = dev->height;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_UYVY;
f->fmt.pix.bytesperline = dev->bytesperline;
f->fmt.pix.sizeimage = dev->frame_size;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
return au0828_set_format(dev, VIDIOC_TRY_FMT, f);
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (videobuf_queue_is_busy(&fh->vb_vidq)) {
printk(KERN_INFO "%s queue busy\n", __func__);
rc = -EBUSY;
goto out;
}
rc = au0828_set_format(dev, VIDIOC_S_FMT, f);
out:
return rc;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id * norm)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
if (dev->dvb.frontend && dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl)
dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl(dev->dvb.frontend, 1);
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_std, *norm);
dev->std_set_in_tuner_core = 1;
if (dev->dvb.frontend && dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl)
dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl(dev->dvb.frontend, 0);
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *input)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
unsigned int tmp;
static const char *inames[] = {
[AU0828_VMUX_UNDEFINED] = "Undefined",
[AU0828_VMUX_COMPOSITE] = "Composite",
[AU0828_VMUX_SVIDEO] = "S-Video",
[AU0828_VMUX_CABLE] = "Cable TV",
[AU0828_VMUX_TELEVISION] = "Television",
[AU0828_VMUX_DVB] = "DVB",
[AU0828_VMUX_DEBUG] = "tv debug"
};
tmp = input->index;
if (tmp >= AU0828_MAX_INPUT)
return -EINVAL;
if (AUVI_INPUT(tmp).type == 0)
return -EINVAL;
input->index = tmp;
strcpy(input->name, inames[AUVI_INPUT(tmp).type]);
if ((AUVI_INPUT(tmp).type == AU0828_VMUX_TELEVISION) ||
(AUVI_INPUT(tmp).type == AU0828_VMUX_CABLE))
input->type |= V4L2_INPUT_TYPE_TUNER;
else
input->type |= V4L2_INPUT_TYPE_CAMERA;
input->std = dev->vdev->tvnorms;
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
*i = dev->ctrl_input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int index)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int i;
dprintk(1, "VIDIOC_S_INPUT in function %s, input=%d\n", __func__,
index);
if (index >= AU0828_MAX_INPUT)
return -EINVAL;
if (AUVI_INPUT(index).type == 0)
return -EINVAL;
dev->ctrl_input = index;
switch (AUVI_INPUT(index).type) {
case AU0828_VMUX_SVIDEO:
dev->input_type = AU0828_VMUX_SVIDEO;
break;
case AU0828_VMUX_COMPOSITE:
dev->input_type = AU0828_VMUX_COMPOSITE;
break;
case AU0828_VMUX_TELEVISION:
dev->input_type = AU0828_VMUX_TELEVISION;
break;
default:
dprintk(1, "VIDIOC_S_INPUT unknown input type set [%d]\n",
AUVI_INPUT(index).type);
break;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, video, s_routing,
AUVI_INPUT(index).vmux, 0, 0);
for (i = 0; i < AU0828_MAX_INPUT; i++) {
int enable = 0;
if (AUVI_INPUT(i).audio_setup == NULL)
continue;
if (i == index)
enable = 1;
else
enable = 0;
if (enable) {
(AUVI_INPUT(i).audio_setup)(dev, enable);
} else {
if ((AUVI_INPUT(i).audio_setup) !=
((AUVI_INPUT(index).audio_setup))) {
(AUVI_INPUT(i).audio_setup)(dev, enable);
}
}
}
v4l2_device_call_all(&dev->v4l2_dev, 0, audio, s_routing,
AUVI_INPUT(index).amux, 0, 0);
return 0;
}
static int vidioc_g_audio(struct file *file, void *priv, struct v4l2_audio *a)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
unsigned int index = a->index;
if (a->index > 1)
return -EINVAL;
index = dev->ctrl_ainput;
if (index == 0)
strcpy(a->name, "Television");
else
strcpy(a->name, "Line in");
a->capability = V4L2_AUDCAP_STEREO;
a->index = index;
return 0;
}
static int vidioc_s_audio(struct file *file, void *priv, const struct v4l2_audio *a)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
if (a->index != dev->ctrl_ainput)
return -EINVAL;
return 0;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_ctrl, ctrl);
return 0;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_ctrl, ctrl);
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv, struct v4l2_tuner *t)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
if (t->index != 0)
return -EINVAL;
strcpy(t->name, "Auvitek tuner");
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, g_tuner, t);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *t)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
if (t->index != 0)
return -EINVAL;
t->type = V4L2_TUNER_ANALOG_TV;
if (dev->dvb.frontend && dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl)
dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl(dev->dvb.frontend, 1);
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_tuner, t);
if (dev->dvb.frontend && dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl)
dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl(dev->dvb.frontend, 0);
dprintk(1, "VIDIOC_S_TUNER: signal = %x, afc = %x\n", t->signal,
t->afc);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *freq)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
freq->type = V4L2_TUNER_ANALOG_TV;
freq->frequency = dev->ctrl_freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *freq)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
if (freq->tuner != 0)
return -EINVAL;
if (freq->type != V4L2_TUNER_ANALOG_TV)
return -EINVAL;
dev->ctrl_freq = freq->frequency;
if (dev->dvb.frontend && dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl)
dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl(dev->dvb.frontend, 1);
if (dev->std_set_in_tuner_core == 0) {
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_std,
dev->vdev->tvnorms);
dev->std_set_in_tuner_core = 1;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, freq);
if (dev->dvb.frontend && dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl)
dev->dvb.frontend->ops.analog_ops.i2c_gate_ctrl(dev->dvb.frontend, 0);
au0828_analog_stream_reset(dev);
return 0;
}
static int vidioc_g_fmt_vbi_cap(struct file *file, void *priv,
struct v4l2_format *format)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
format->fmt.vbi.samples_per_line = dev->vbi_width;
format->fmt.vbi.sample_format = V4L2_PIX_FMT_GREY;
format->fmt.vbi.offset = 0;
format->fmt.vbi.flags = 0;
format->fmt.vbi.sampling_rate = 6750000 * 4 / 2;
format->fmt.vbi.count[0] = dev->vbi_height;
format->fmt.vbi.count[1] = dev->vbi_height;
format->fmt.vbi.start[0] = 21;
format->fmt.vbi.start[1] = 284;
return 0;
}
static int vidioc_g_chip_ident(struct file *file, void *priv,
struct v4l2_dbg_chip_ident *chip)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
chip->ident = V4L2_IDENT_NONE;
chip->revision = 0;
if (v4l2_chip_match_host(&chip->match)) {
chip->ident = V4L2_IDENT_AU0828;
return 0;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_chip_ident, chip);
if (chip->ident == V4L2_IDENT_NONE)
return -EINVAL;
return 0;
}
static int vidioc_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *cc)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
if (cc->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
cc->bounds.left = 0;
cc->bounds.top = 0;
cc->bounds.width = dev->width;
cc->bounds.height = dev->height;
cc->defrect = cc->bounds;
cc->pixelaspect.numerator = 54;
cc->pixelaspect.denominator = 59;
return 0;
}
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc = -EINVAL;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (unlikely(type != fh->type))
return -EINVAL;
dprintk(1, "vidioc_streamon fh=%p t=%d fh->res=%d dev->res=%d\n",
fh, type, fh->resources, dev->resources);
if (unlikely(!res_get(fh, get_ressource(fh))))
return -EBUSY;
if (type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
au0828_analog_stream_enable(dev);
v4l2_device_call_all(&dev->v4l2_dev, 0, video, s_stream, 1);
}
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
rc = videobuf_streamon(&fh->vb_vidq);
dev->vid_timeout_running = 1;
mod_timer(&dev->vid_timeout, jiffies + (HZ / 10));
} else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
rc = videobuf_streamon(&fh->vb_vbiq);
dev->vbi_timeout_running = 1;
mod_timer(&dev->vbi_timeout, jiffies + (HZ / 10));
}
return rc;
}
static int vidioc_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc;
int i;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
fh->type != V4L2_BUF_TYPE_VBI_CAPTURE)
return -EINVAL;
if (type != fh->type)
return -EINVAL;
dprintk(1, "vidioc_streamoff fh=%p t=%d fh->res=%d dev->res=%d\n",
fh, type, fh->resources, dev->resources);
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev->vid_timeout_running = 0;
del_timer_sync(&dev->vid_timeout);
v4l2_device_call_all(&dev->v4l2_dev, 0, video, s_stream, 0);
rc = au0828_stream_interrupt(dev);
if (rc != 0)
return rc;
for (i = 0; i < AU0828_MAX_INPUT; i++) {
if (AUVI_INPUT(i).audio_setup == NULL)
continue;
(AUVI_INPUT(i).audio_setup)(dev, 0);
}
if (res_check(fh, AU0828_RESOURCE_VIDEO)) {
videobuf_streamoff(&fh->vb_vidq);
res_free(fh, AU0828_RESOURCE_VIDEO);
}
} else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE) {
dev->vbi_timeout_running = 0;
del_timer_sync(&dev->vbi_timeout);
if (res_check(fh, AU0828_RESOURCE_VBI)) {
videobuf_streamoff(&fh->vb_vbiq);
res_free(fh, AU0828_RESOURCE_VBI);
}
}
return 0;
}
static int vidioc_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
switch (reg->match.type) {
case V4L2_CHIP_MATCH_I2C_DRIVER:
v4l2_device_call_all(&dev->v4l2_dev, 0, core, g_register, reg);
return 0;
default:
if (!v4l2_chip_match_host(&reg->match))
return -EINVAL;
}
reg->val = au0828_read(dev, reg->reg);
return 0;
}
static int vidioc_s_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
switch (reg->match.type) {
case V4L2_CHIP_MATCH_I2C_DRIVER:
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_register, reg);
return 0;
default:
if (!v4l2_chip_match_host(&reg->match))
return -EINVAL;
}
return au0828_writereg(dev, reg->reg, reg->val);
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *rb)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_reqbufs(&fh->vb_vidq, rb);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_reqbufs(&fh->vb_vbiq, rb);
return rc;
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_querybuf(&fh->vb_vidq, b);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_querybuf(&fh->vb_vbiq, b);
return rc;
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_qbuf(&fh->vb_vidq, b);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_qbuf(&fh->vb_vbiq, b);
return rc;
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct au0828_fh *fh = priv;
struct au0828_dev *dev = fh->dev;
int rc;
rc = check_dev(dev);
if (rc < 0)
return rc;
if (dev->greenscreen_detected == 1) {
dprintk(1, "Detected green frame. Resetting stream...\n");
au0828_analog_stream_reset(dev);
dev->greenscreen_detected = 0;
}
if (fh->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
rc = videobuf_dqbuf(&fh->vb_vidq, b, file->f_flags & O_NONBLOCK);
else if (fh->type == V4L2_BUF_TYPE_VBI_CAPTURE)
rc = videobuf_dqbuf(&fh->vb_vbiq, b, file->f_flags & O_NONBLOCK);
return rc;
}
int au0828_analog_register(struct au0828_dev *dev,
struct usb_interface *interface)
{
int retval = -ENOMEM;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i, ret;
dprintk(1, "au0828_analog_register called!\n");
retval = usb_set_interface(dev->usbdev,
interface->cur_altsetting->desc.bInterfaceNumber, 5);
if (retval != 0) {
printk(KERN_INFO "Failure setting usb interface0 to as5\n");
return retval;
}
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
endpoint = &iface_desc->endpoint[i].desc;
if (((endpoint->bEndpointAddress & USB_ENDPOINT_DIR_MASK)
== USB_DIR_IN) &&
((endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK)
== USB_ENDPOINT_XFER_ISOC)) {
u16 tmp = le16_to_cpu(endpoint->wMaxPacketSize);
dev->max_pkt_size = (tmp & 0x07ff) *
(((tmp & 0x1800) >> 11) + 1);
dev->isoc_in_endpointaddr = endpoint->bEndpointAddress;
}
}
if (!(dev->isoc_in_endpointaddr)) {
printk(KERN_INFO "Could not locate isoc endpoint\n");
kfree(dev);
return -ENODEV;
}
init_waitqueue_head(&dev->open);
spin_lock_init(&dev->slock);
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vidq.queued);
INIT_LIST_HEAD(&dev->vbiq.active);
INIT_LIST_HEAD(&dev->vbiq.queued);
dev->vid_timeout.function = au0828_vid_buffer_timeout;
dev->vid_timeout.data = (unsigned long) dev;
init_timer(&dev->vid_timeout);
dev->vbi_timeout.function = au0828_vbi_buffer_timeout;
dev->vbi_timeout.data = (unsigned long) dev;
init_timer(&dev->vbi_timeout);
dev->width = NTSC_STD_W;
dev->height = NTSC_STD_H;
dev->field_size = dev->width * dev->height;
dev->frame_size = dev->field_size << 1;
dev->bytesperline = dev->width << 1;
dev->ctrl_ainput = 0;
dev->vdev = video_device_alloc();
if (NULL == dev->vdev) {
dprintk(1, "Can't allocate video_device.\n");
return -ENOMEM;
}
dev->vbi_dev = video_device_alloc();
if (NULL == dev->vbi_dev) {
dprintk(1, "Can't allocate vbi_device.\n");
ret = -ENOMEM;
goto err_vdev;
}
*dev->vdev = au0828_video_template;
dev->vdev->parent = &dev->usbdev->dev;
dev->vdev->lock = &dev->lock;
strcpy(dev->vdev->name, "au0828a video");
*dev->vbi_dev = au0828_video_template;
dev->vbi_dev->parent = &dev->usbdev->dev;
dev->vbi_dev->lock = &dev->lock;
strcpy(dev->vbi_dev->name, "au0828a vbi");
video_set_drvdata(dev->vdev, dev);
retval = video_register_device(dev->vdev, VFL_TYPE_GRABBER, -1);
if (retval != 0) {
dprintk(1, "unable to register video device (error = %d).\n",
retval);
ret = -ENODEV;
goto err_vbi_dev;
}
video_set_drvdata(dev->vbi_dev, dev);
retval = video_register_device(dev->vbi_dev, VFL_TYPE_VBI, -1);
if (retval != 0) {
dprintk(1, "unable to register vbi device (error = %d).\n",
retval);
ret = -ENODEV;
goto err_vbi_dev;
}
dprintk(1, "%s completed!\n", __func__);
return 0;
err_vbi_dev:
video_device_release(dev->vbi_dev);
err_vdev:
video_device_release(dev->vdev);
return ret;
}
