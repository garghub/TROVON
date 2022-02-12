static inline struct s2255_dev *to_s2255_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct s2255_dev, v4l2_dev);
}
static int norm_maxw(struct s2255_vc *vc)
{
return (vc->std & V4L2_STD_525_60) ?
LINE_SZ_4CIFS_NTSC : LINE_SZ_4CIFS_PAL;
}
static int norm_maxh(struct s2255_vc *vc)
{
return (vc->std & V4L2_STD_525_60) ?
(NUM_LINES_1CIFS_NTSC * 2) : (NUM_LINES_1CIFS_PAL * 2);
}
static int norm_minw(struct s2255_vc *vc)
{
return (vc->std & V4L2_STD_525_60) ?
LINE_SZ_1CIFS_NTSC : LINE_SZ_1CIFS_PAL;
}
static int norm_minh(struct s2255_vc *vc)
{
return (vc->std & V4L2_STD_525_60) ?
(NUM_LINES_1CIFS_NTSC) : (NUM_LINES_1CIFS_PAL);
}
static void planar422p_to_yuv_packed(const unsigned char *in,
unsigned char *out,
int width, int height,
int fmt)
{
unsigned char *pY;
unsigned char *pCb;
unsigned char *pCr;
unsigned long size = height * width;
unsigned int i;
pY = (unsigned char *)in;
pCr = (unsigned char *)in + height * width;
pCb = (unsigned char *)in + height * width + (height * width / 2);
for (i = 0; i < size * 2; i += 4) {
out[i] = (fmt == V4L2_PIX_FMT_YUYV) ? *pY++ : *pCr++;
out[i + 1] = (fmt == V4L2_PIX_FMT_YUYV) ? *pCr++ : *pY++;
out[i + 2] = (fmt == V4L2_PIX_FMT_YUYV) ? *pY++ : *pCb++;
out[i + 3] = (fmt == V4L2_PIX_FMT_YUYV) ? *pCb++ : *pY++;
}
return;
}
static void s2255_reset_dsppower(struct s2255_dev *dev)
{
s2255_vendor_req(dev, 0x40, 0x0000, 0x0001, NULL, 0, 1);
msleep(20);
s2255_vendor_req(dev, 0x50, 0x0000, 0x0000, NULL, 0, 1);
msleep(600);
s2255_vendor_req(dev, 0x10, 0x0000, 0x0000, NULL, 0, 1);
return;
}
static void s2255_timer(unsigned long user_data)
{
struct s2255_fw *data = (struct s2255_fw *)user_data;
if (usb_submit_urb(data->fw_urb, GFP_ATOMIC) < 0) {
pr_err("s2255: can't submit urb\n");
atomic_set(&data->fw_state, S2255_FW_FAILED);
wake_up(&data->wait_fw);
return;
}
}
static void s2255_fwchunk_complete(struct urb *urb)
{
struct s2255_fw *data = urb->context;
struct usb_device *udev = urb->dev;
int len;
if (urb->status) {
dev_err(&udev->dev, "URB failed with status %d\n", urb->status);
atomic_set(&data->fw_state, S2255_FW_FAILED);
wake_up(&data->wait_fw);
return;
}
if (data->fw_urb == NULL) {
s2255_dev_err(&udev->dev, "disconnected\n");
atomic_set(&data->fw_state, S2255_FW_FAILED);
wake_up(&data->wait_fw);
return;
}
#define CHUNK_SIZE 512
if (data->fw_loaded < data->fw_size) {
len = (data->fw_loaded + CHUNK_SIZE) > data->fw_size ?
data->fw_size % CHUNK_SIZE : CHUNK_SIZE;
if (len < CHUNK_SIZE)
memset(data->pfw_data, 0, CHUNK_SIZE);
memcpy(data->pfw_data,
(char *) data->fw->data + data->fw_loaded, len);
usb_fill_bulk_urb(data->fw_urb, udev, usb_sndbulkpipe(udev, 2),
data->pfw_data, CHUNK_SIZE,
s2255_fwchunk_complete, data);
if (usb_submit_urb(data->fw_urb, GFP_ATOMIC) < 0) {
dev_err(&udev->dev, "failed submit URB\n");
atomic_set(&data->fw_state, S2255_FW_FAILED);
wake_up(&data->wait_fw);
return;
}
data->fw_loaded += len;
} else
atomic_set(&data->fw_state, S2255_FW_LOADED_DSPWAIT);
return;
}
static void s2255_got_frame(struct s2255_vc *vc, int jpgsize)
{
struct s2255_buffer *buf;
struct s2255_dev *dev = to_s2255_dev(vc->vdev.v4l2_dev);
unsigned long flags = 0;
spin_lock_irqsave(&vc->qlock, flags);
if (list_empty(&vc->buf_list)) {
dprintk(dev, 1, "No active queue to serve\n");
spin_unlock_irqrestore(&vc->qlock, flags);
return;
}
buf = list_entry(vc->buf_list.next,
struct s2255_buffer, list);
list_del(&buf->list);
v4l2_get_timestamp(&buf->vb.timestamp);
buf->vb.field = vc->field;
buf->vb.sequence = vc->frame_count;
spin_unlock_irqrestore(&vc->qlock, flags);
s2255_fillbuff(vc, buf, jpgsize);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_DONE);
dprintk(dev, 2, "%s: [buf] [%p]\n", __func__, buf);
}
static const struct s2255_fmt *format_by_fourcc(int fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
if (-1 == formats[i].fourcc)
continue;
if (!jpeg_enable && ((formats[i].fourcc == V4L2_PIX_FMT_JPEG) ||
(formats[i].fourcc == V4L2_PIX_FMT_MJPEG)))
continue;
if (formats[i].fourcc == fourcc)
return formats + i;
}
return NULL;
}
static void s2255_fillbuff(struct s2255_vc *vc,
struct s2255_buffer *buf, int jpgsize)
{
int pos = 0;
const char *tmpbuf;
char *vbuf = vb2_plane_vaddr(&buf->vb.vb2_buf, 0);
unsigned long last_frame;
struct s2255_dev *dev = vc->dev;
if (!vbuf)
return;
last_frame = vc->last_frame;
if (last_frame != -1) {
tmpbuf =
(const char *)vc->buffer.frame[last_frame].lpvbits;
switch (vc->fmt->fourcc) {
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_UYVY:
planar422p_to_yuv_packed((const unsigned char *)tmpbuf,
vbuf, vc->width,
vc->height,
vc->fmt->fourcc);
break;
case V4L2_PIX_FMT_GREY:
memcpy(vbuf, tmpbuf, vc->width * vc->height);
break;
case V4L2_PIX_FMT_JPEG:
case V4L2_PIX_FMT_MJPEG:
vb2_set_plane_payload(&buf->vb.vb2_buf, 0, jpgsize);
memcpy(vbuf, tmpbuf, jpgsize);
break;
case V4L2_PIX_FMT_YUV422P:
memcpy(vbuf, tmpbuf,
vc->width * vc->height * 2);
break;
default:
pr_info("s2255: unknown format?\n");
}
vc->last_frame = -1;
} else {
pr_err("s2255: =======no frame\n");
return;
}
dprintk(dev, 2, "s2255fill at : Buffer 0x%08lx size= %d\n",
(unsigned long)vbuf, pos);
}
static int queue_setup(struct vb2_queue *vq, const void *parg,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct s2255_vc *vc = vb2_get_drv_priv(vq);
if (*nbuffers < S2255_MIN_BUFS)
*nbuffers = S2255_MIN_BUFS;
*nplanes = 1;
sizes[0] = vc->width * vc->height * (vc->fmt->depth >> 3);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct s2255_vc *vc = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct s2255_buffer *buf = container_of(vbuf, struct s2255_buffer, vb);
int w = vc->width;
int h = vc->height;
unsigned long size;
dprintk(vc->dev, 4, "%s\n", __func__);
if (vc->fmt == NULL)
return -EINVAL;
if ((w < norm_minw(vc)) ||
(w > norm_maxw(vc)) ||
(h < norm_minh(vc)) ||
(h > norm_maxh(vc))) {
dprintk(vc->dev, 4, "invalid buffer prepare\n");
return -EINVAL;
}
size = w * h * (vc->fmt->depth >> 3);
if (vb2_plane_size(vb, 0) < size) {
dprintk(vc->dev, 4, "invalid buffer prepare\n");
return -EINVAL;
}
vb2_set_plane_payload(&buf->vb.vb2_buf, 0, size);
return 0;
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct s2255_buffer *buf = container_of(vbuf, struct s2255_buffer, vb);
struct s2255_vc *vc = vb2_get_drv_priv(vb->vb2_queue);
unsigned long flags = 0;
dprintk(vc->dev, 1, "%s\n", __func__);
spin_lock_irqsave(&vc->qlock, flags);
list_add_tail(&buf->list, &vc->buf_list);
spin_unlock_irqrestore(&vc->qlock, flags);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct s2255_vc *vc = video_drvdata(file);
struct s2255_dev *dev = vc->dev;
strlcpy(cap->driver, "s2255", sizeof(cap->driver));
strlcpy(cap->card, "s2255", sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
int index = f->index;
if (index >= ARRAY_SIZE(formats))
return -EINVAL;
if (!jpeg_enable && ((formats[index].fourcc == V4L2_PIX_FMT_JPEG) ||
(formats[index].fourcc == V4L2_PIX_FMT_MJPEG)))
return -EINVAL;
strlcpy(f->description, formats[index].name, sizeof(f->description));
f->pixelformat = formats[index].fourcc;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct s2255_vc *vc = video_drvdata(file);
int is_ntsc = vc->std & V4L2_STD_525_60;
f->fmt.pix.width = vc->width;
f->fmt.pix.height = vc->height;
if (f->fmt.pix.height >=
(is_ntsc ? NUM_LINES_1CIFS_NTSC : NUM_LINES_1CIFS_PAL) * 2)
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
else
f->fmt.pix.field = V4L2_FIELD_TOP;
f->fmt.pix.pixelformat = vc->fmt->fourcc;
f->fmt.pix.bytesperline = f->fmt.pix.width * (vc->fmt->depth >> 3);
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.priv = 0;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
const struct s2255_fmt *fmt;
enum v4l2_field field;
struct s2255_vc *vc = video_drvdata(file);
int is_ntsc = vc->std & V4L2_STD_525_60;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (fmt == NULL)
return -EINVAL;
field = f->fmt.pix.field;
dprintk(vc->dev, 50, "%s NTSC: %d suggested width: %d, height: %d\n",
__func__, is_ntsc, f->fmt.pix.width, f->fmt.pix.height);
if (is_ntsc) {
if (f->fmt.pix.height >= NUM_LINES_1CIFS_NTSC * 2) {
f->fmt.pix.height = NUM_LINES_1CIFS_NTSC * 2;
field = V4L2_FIELD_INTERLACED;
} else {
f->fmt.pix.height = NUM_LINES_1CIFS_NTSC;
field = V4L2_FIELD_TOP;
}
if (f->fmt.pix.width >= LINE_SZ_4CIFS_NTSC)
f->fmt.pix.width = LINE_SZ_4CIFS_NTSC;
else if (f->fmt.pix.width >= LINE_SZ_2CIFS_NTSC)
f->fmt.pix.width = LINE_SZ_2CIFS_NTSC;
else if (f->fmt.pix.width >= LINE_SZ_1CIFS_NTSC)
f->fmt.pix.width = LINE_SZ_1CIFS_NTSC;
else
f->fmt.pix.width = LINE_SZ_1CIFS_NTSC;
} else {
if (f->fmt.pix.height >= NUM_LINES_1CIFS_PAL * 2) {
f->fmt.pix.height = NUM_LINES_1CIFS_PAL * 2;
field = V4L2_FIELD_INTERLACED;
} else {
f->fmt.pix.height = NUM_LINES_1CIFS_PAL;
field = V4L2_FIELD_TOP;
}
if (f->fmt.pix.width >= LINE_SZ_4CIFS_PAL)
f->fmt.pix.width = LINE_SZ_4CIFS_PAL;
else if (f->fmt.pix.width >= LINE_SZ_2CIFS_PAL)
f->fmt.pix.width = LINE_SZ_2CIFS_PAL;
else if (f->fmt.pix.width >= LINE_SZ_1CIFS_PAL)
f->fmt.pix.width = LINE_SZ_1CIFS_PAL;
else
f->fmt.pix.width = LINE_SZ_1CIFS_PAL;
}
f->fmt.pix.field = field;
f->fmt.pix.bytesperline = (f->fmt.pix.width * fmt->depth) >> 3;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.priv = 0;
dprintk(vc->dev, 50, "%s: set width %d height %d field %d\n", __func__,
f->fmt.pix.width, f->fmt.pix.height, f->fmt.pix.field);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct s2255_vc *vc = video_drvdata(file);
const struct s2255_fmt *fmt;
struct vb2_queue *q = &vc->vb_vidq;
struct s2255_mode mode;
int ret;
ret = vidioc_try_fmt_vid_cap(file, vc, f);
if (ret < 0)
return ret;
fmt = format_by_fourcc(f->fmt.pix.pixelformat);
if (fmt == NULL)
return -EINVAL;
if (vb2_is_busy(q)) {
dprintk(vc->dev, 1, "queue busy\n");
return -EBUSY;
}
mode = vc->mode;
vc->fmt = fmt;
vc->width = f->fmt.pix.width;
vc->height = f->fmt.pix.height;
vc->field = f->fmt.pix.field;
if (vc->width > norm_minw(vc)) {
if (vc->height > norm_minh(vc)) {
if (vc->cap_parm.capturemode &
V4L2_MODE_HIGHQUALITY)
mode.scale = SCALE_4CIFSI;
else
mode.scale = SCALE_4CIFS;
} else
mode.scale = SCALE_2CIFS;
} else {
mode.scale = SCALE_1CIFS;
}
switch (vc->fmt->fourcc) {
case V4L2_PIX_FMT_GREY:
mode.color &= ~MASK_COLOR;
mode.color |= COLOR_Y8;
break;
case V4L2_PIX_FMT_JPEG:
case V4L2_PIX_FMT_MJPEG:
mode.color &= ~MASK_COLOR;
mode.color |= COLOR_JPG;
mode.color |= (vc->jpegqual << 8);
break;
case V4L2_PIX_FMT_YUV422P:
mode.color &= ~MASK_COLOR;
mode.color |= COLOR_YUVPL;
break;
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_UYVY:
default:
mode.color &= ~MASK_COLOR;
mode.color |= COLOR_YUVPK;
break;
}
if ((mode.color & MASK_COLOR) != (vc->mode.color & MASK_COLOR))
mode.restart = 1;
else if (mode.scale != vc->mode.scale)
mode.restart = 1;
else if (mode.format != vc->mode.format)
mode.restart = 1;
vc->mode = mode;
(void) s2255_set_mode(vc, &mode);
return 0;
}
static int s2255_write_config(struct usb_device *udev, unsigned char *pbuf,
int size)
{
int pipe;
int done;
long retval = -1;
if (udev) {
pipe = usb_sndbulkpipe(udev, S2255_CONFIG_EP);
retval = usb_bulk_msg(udev, pipe, pbuf, size, &done, 500);
}
return retval;
}
static u32 get_transfer_size(struct s2255_mode *mode)
{
int linesPerFrame = LINE_SZ_DEF;
int pixelsPerLine = NUM_LINES_DEF;
u32 outImageSize;
u32 usbInSize;
unsigned int mask_mult;
if (mode == NULL)
return 0;
if (mode->format == FORMAT_NTSC) {
switch (mode->scale) {
case SCALE_4CIFS:
case SCALE_4CIFSI:
linesPerFrame = NUM_LINES_4CIFS_NTSC * 2;
pixelsPerLine = LINE_SZ_4CIFS_NTSC;
break;
case SCALE_2CIFS:
linesPerFrame = NUM_LINES_2CIFS_NTSC;
pixelsPerLine = LINE_SZ_2CIFS_NTSC;
break;
case SCALE_1CIFS:
linesPerFrame = NUM_LINES_1CIFS_NTSC;
pixelsPerLine = LINE_SZ_1CIFS_NTSC;
break;
default:
break;
}
} else if (mode->format == FORMAT_PAL) {
switch (mode->scale) {
case SCALE_4CIFS:
case SCALE_4CIFSI:
linesPerFrame = NUM_LINES_4CIFS_PAL * 2;
pixelsPerLine = LINE_SZ_4CIFS_PAL;
break;
case SCALE_2CIFS:
linesPerFrame = NUM_LINES_2CIFS_PAL;
pixelsPerLine = LINE_SZ_2CIFS_PAL;
break;
case SCALE_1CIFS:
linesPerFrame = NUM_LINES_1CIFS_PAL;
pixelsPerLine = LINE_SZ_1CIFS_PAL;
break;
default:
break;
}
}
outImageSize = linesPerFrame * pixelsPerLine;
if ((mode->color & MASK_COLOR) != COLOR_Y8) {
outImageSize *= 2;
}
usbInSize = outImageSize + PREFIX_SIZE;
mask_mult = 0xffffffffUL - DEF_USB_BLOCK + 1;
if (usbInSize & ~mask_mult)
usbInSize = (usbInSize & mask_mult) + (DEF_USB_BLOCK);
return usbInSize;
}
static void s2255_print_cfg(struct s2255_dev *sdev, struct s2255_mode *mode)
{
struct device *dev = &sdev->udev->dev;
dev_info(dev, "------------------------------------------------\n");
dev_info(dev, "format: %d\nscale %d\n", mode->format, mode->scale);
dev_info(dev, "fdec: %d\ncolor %d\n", mode->fdec, mode->color);
dev_info(dev, "bright: 0x%x\n", mode->bright);
dev_info(dev, "------------------------------------------------\n");
}
static int s2255_set_mode(struct s2255_vc *vc,
struct s2255_mode *mode)
{
int res;
unsigned long chn_rev;
struct s2255_dev *dev = to_s2255_dev(vc->vdev.v4l2_dev);
int i;
__le32 *buffer = dev->cmdbuf;
mutex_lock(&dev->cmdlock);
chn_rev = G_chnmap[vc->idx];
dprintk(dev, 3, "%s channel: %d\n", __func__, vc->idx);
if ((mode->color & MASK_COLOR) == COLOR_JPG) {
mode->color &= ~MASK_COLOR;
mode->color |= COLOR_JPG;
mode->color &= ~MASK_JPG_QUALITY;
mode->color |= (vc->jpegqual << 8);
}
vc->mode = *mode;
vc->req_image_size = get_transfer_size(mode);
dprintk(dev, 1, "%s: reqsize %ld\n", __func__, vc->req_image_size);
buffer[0] = IN_DATA_TOKEN;
buffer[1] = (__le32) cpu_to_le32(chn_rev);
buffer[2] = CMD_SET_MODE;
for (i = 0; i < sizeof(struct s2255_mode) / sizeof(u32); i++)
buffer[3 + i] = cpu_to_le32(((u32 *)&vc->mode)[i]);
vc->setmode_ready = 0;
res = s2255_write_config(dev->udev, (unsigned char *)buffer, 512);
if (debug)
s2255_print_cfg(dev, mode);
if (mode->restart) {
wait_event_timeout(vc->wait_setmode,
(vc->setmode_ready != 0),
msecs_to_jiffies(S2255_SETMODE_TIMEOUT));
if (vc->setmode_ready != 1) {
dprintk(dev, 0, "s2255: no set mode response\n");
res = -EFAULT;
}
}
vc->mode.restart = 0;
dprintk(dev, 1, "%s chn %d, result: %d\n", __func__, vc->idx, res);
mutex_unlock(&dev->cmdlock);
return res;
}
static int s2255_cmd_status(struct s2255_vc *vc, u32 *pstatus)
{
int res;
u32 chn_rev;
struct s2255_dev *dev = to_s2255_dev(vc->vdev.v4l2_dev);
__le32 *buffer = dev->cmdbuf;
mutex_lock(&dev->cmdlock);
chn_rev = G_chnmap[vc->idx];
dprintk(dev, 4, "%s chan %d\n", __func__, vc->idx);
buffer[0] = IN_DATA_TOKEN;
buffer[1] = (__le32) cpu_to_le32(chn_rev);
buffer[2] = CMD_STATUS;
*pstatus = 0;
vc->vidstatus_ready = 0;
res = s2255_write_config(dev->udev, (unsigned char *)buffer, 512);
wait_event_timeout(vc->wait_vidstatus,
(vc->vidstatus_ready != 0),
msecs_to_jiffies(S2255_VIDSTATUS_TIMEOUT));
if (vc->vidstatus_ready != 1) {
dprintk(dev, 0, "s2255: no vidstatus response\n");
res = -EFAULT;
}
*pstatus = vc->vidstatus;
dprintk(dev, 4, "%s, vid status %d\n", __func__, *pstatus);
mutex_unlock(&dev->cmdlock);
return res;
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct s2255_vc *vc = vb2_get_drv_priv(vq);
int j;
vc->last_frame = -1;
vc->bad_payload = 0;
vc->cur_frame = 0;
vc->frame_count = 0;
for (j = 0; j < SYS_FRAMES; j++) {
vc->buffer.frame[j].ulState = S2255_READ_IDLE;
vc->buffer.frame[j].cur_size = 0;
}
return s2255_start_acquire(vc);
}
static void stop_streaming(struct vb2_queue *vq)
{
struct s2255_vc *vc = vb2_get_drv_priv(vq);
struct s2255_buffer *buf, *node;
unsigned long flags;
(void) s2255_stop_acquire(vc);
spin_lock_irqsave(&vc->qlock, flags);
list_for_each_entry_safe(buf, node, &vc->buf_list, list) {
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
dprintk(vc->dev, 2, "[%p/%d] done\n",
buf, buf->vb.vb2_buf.index);
}
spin_unlock_irqrestore(&vc->qlock, flags);
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id i)
{
struct s2255_vc *vc = video_drvdata(file);
struct s2255_mode mode;
struct vb2_queue *q = &vc->vb_vidq;
if (vb2_is_busy(q))
return -EBUSY;
mode = vc->mode;
if (i & V4L2_STD_525_60) {
dprintk(vc->dev, 4, "%s 60 Hz\n", __func__);
if (mode.format != FORMAT_NTSC) {
mode.restart = 1;
mode.format = FORMAT_NTSC;
mode.fdec = FDEC_1;
vc->width = LINE_SZ_4CIFS_NTSC;
vc->height = NUM_LINES_4CIFS_NTSC * 2;
}
} else if (i & V4L2_STD_625_50) {
dprintk(vc->dev, 4, "%s 50 Hz\n", __func__);
if (mode.format != FORMAT_PAL) {
mode.restart = 1;
mode.format = FORMAT_PAL;
mode.fdec = FDEC_1;
vc->width = LINE_SZ_4CIFS_PAL;
vc->height = NUM_LINES_4CIFS_PAL * 2;
}
} else
return -EINVAL;
vc->std = i;
if (mode.restart)
s2255_set_mode(vc, &mode);
return 0;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *i)
{
struct s2255_vc *vc = video_drvdata(file);
*i = vc->std;
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
struct s2255_vc *vc = video_drvdata(file);
struct s2255_dev *dev = vc->dev;
u32 status = 0;
if (inp->index != 0)
return -EINVAL;
inp->type = V4L2_INPUT_TYPE_CAMERA;
inp->std = S2255_NORMS;
inp->status = 0;
if (dev->dsp_fw_ver >= S2255_MIN_DSP_STATUS) {
int rc;
rc = s2255_cmd_status(vc, &status);
dprintk(dev, 4, "s2255_cmd_status rc: %d status %x\n",
rc, status);
if (rc == 0)
inp->status = (status & 0x01) ? 0
: V4L2_IN_ST_NO_SIGNAL;
}
switch (dev->pid) {
case 0x2255:
default:
strlcpy(inp->name, "Composite", sizeof(inp->name));
break;
case 0x2257:
strlcpy(inp->name, (vc->idx < 2) ? "Composite" : "S-Video",
sizeof(inp->name));
break;
}
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
if (i > 0)
return -EINVAL;
return 0;
}
static int s2255_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct s2255_vc *vc =
container_of(ctrl->handler, struct s2255_vc, hdl);
struct s2255_mode mode;
mode = vc->mode;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
mode.bright = ctrl->val;
break;
case V4L2_CID_CONTRAST:
mode.contrast = ctrl->val;
break;
case V4L2_CID_HUE:
mode.hue = ctrl->val;
break;
case V4L2_CID_SATURATION:
mode.saturation = ctrl->val;
break;
case V4L2_CID_S2255_COLORFILTER:
mode.color &= ~MASK_INPUT_TYPE;
mode.color |= !ctrl->val << 16;
break;
case V4L2_CID_JPEG_COMPRESSION_QUALITY:
vc->jpegqual = ctrl->val;
return 0;
default:
return -EINVAL;
}
mode.restart = 0;
s2255_set_mode(vc, &mode);
return 0;
}
static int vidioc_g_jpegcomp(struct file *file, void *priv,
struct v4l2_jpegcompression *jc)
{
struct s2255_vc *vc = video_drvdata(file);
memset(jc, 0, sizeof(*jc));
jc->quality = vc->jpegqual;
dprintk(vc->dev, 2, "%s: quality %d\n", __func__, jc->quality);
return 0;
}
static int vidioc_s_jpegcomp(struct file *file, void *priv,
const struct v4l2_jpegcompression *jc)
{
struct s2255_vc *vc = video_drvdata(file);
if (jc->quality < 0 || jc->quality > 100)
return -EINVAL;
v4l2_ctrl_s_ctrl(vc->jpegqual_ctrl, jc->quality);
dprintk(vc->dev, 2, "%s: quality %d\n", __func__, jc->quality);
return 0;
}
static int vidioc_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *sp)
{
__u32 def_num, def_dem;
struct s2255_vc *vc = video_drvdata(file);
if (sp->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
sp->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
sp->parm.capture.capturemode = vc->cap_parm.capturemode;
sp->parm.capture.readbuffers = S2255_MIN_BUFS;
def_num = (vc->mode.format == FORMAT_NTSC) ? 1001 : 1000;
def_dem = (vc->mode.format == FORMAT_NTSC) ? 30000 : 25000;
sp->parm.capture.timeperframe.denominator = def_dem;
switch (vc->mode.fdec) {
default:
case FDEC_1:
sp->parm.capture.timeperframe.numerator = def_num;
break;
case FDEC_2:
sp->parm.capture.timeperframe.numerator = def_num * 2;
break;
case FDEC_3:
sp->parm.capture.timeperframe.numerator = def_num * 3;
break;
case FDEC_5:
sp->parm.capture.timeperframe.numerator = def_num * 5;
break;
}
dprintk(vc->dev, 4, "%s capture mode, %d timeperframe %d/%d\n",
__func__,
sp->parm.capture.capturemode,
sp->parm.capture.timeperframe.numerator,
sp->parm.capture.timeperframe.denominator);
return 0;
}
static int vidioc_s_parm(struct file *file, void *priv,
struct v4l2_streamparm *sp)
{
struct s2255_vc *vc = video_drvdata(file);
struct s2255_mode mode;
int fdec = FDEC_1;
__u32 def_num, def_dem;
if (sp->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
mode = vc->mode;
if ((vc->cap_parm.capturemode != sp->parm.capture.capturemode)
&& vb2_is_streaming(&vc->vb_vidq))
return -EBUSY;
def_num = (mode.format == FORMAT_NTSC) ? 1001 : 1000;
def_dem = (mode.format == FORMAT_NTSC) ? 30000 : 25000;
if (def_dem != sp->parm.capture.timeperframe.denominator)
sp->parm.capture.timeperframe.numerator = def_num;
else if (sp->parm.capture.timeperframe.numerator <= def_num)
sp->parm.capture.timeperframe.numerator = def_num;
else if (sp->parm.capture.timeperframe.numerator <= (def_num * 2)) {
sp->parm.capture.timeperframe.numerator = def_num * 2;
fdec = FDEC_2;
} else if (sp->parm.capture.timeperframe.numerator <= (def_num * 3)) {
sp->parm.capture.timeperframe.numerator = def_num * 3;
fdec = FDEC_3;
} else {
sp->parm.capture.timeperframe.numerator = def_num * 5;
fdec = FDEC_5;
}
mode.fdec = fdec;
sp->parm.capture.timeperframe.denominator = def_dem;
sp->parm.capture.readbuffers = S2255_MIN_BUFS;
s2255_set_mode(vc, &mode);
dprintk(vc->dev, 4, "%s capture mode, %d timeperframe %d/%d, fdec %d\n",
__func__,
sp->parm.capture.capturemode,
sp->parm.capture.timeperframe.numerator,
sp->parm.capture.timeperframe.denominator, fdec);
return 0;
}
static int vidioc_enum_framesizes(struct file *file, void *priv,
struct v4l2_frmsizeenum *fe)
{
struct s2255_vc *vc = video_drvdata(file);
int is_ntsc = vc->std & V4L2_STD_525_60;
const struct s2255_fmt *fmt;
if (fe->index >= NUM_SIZE_ENUMS)
return -EINVAL;
fmt = format_by_fourcc(fe->pixel_format);
if (fmt == NULL)
return -EINVAL;
fe->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fe->discrete = is_ntsc ? ntsc_sizes[fe->index] : pal_sizes[fe->index];
return 0;
}
static int vidioc_enum_frameintervals(struct file *file, void *priv,
struct v4l2_frmivalenum *fe)
{
struct s2255_vc *vc = video_drvdata(file);
const struct s2255_fmt *fmt;
const struct v4l2_frmsize_discrete *sizes;
int is_ntsc = vc->std & V4L2_STD_525_60;
#define NUM_FRAME_ENUMS 4
int frm_dec[NUM_FRAME_ENUMS] = {1, 2, 3, 5};
int i;
if (fe->index >= NUM_FRAME_ENUMS)
return -EINVAL;
fmt = format_by_fourcc(fe->pixel_format);
if (fmt == NULL)
return -EINVAL;
sizes = is_ntsc ? ntsc_sizes : pal_sizes;
for (i = 0; i < NUM_SIZE_ENUMS; i++, sizes++)
if (fe->width == sizes->width &&
fe->height == sizes->height)
break;
if (i == NUM_SIZE_ENUMS)
return -EINVAL;
fe->type = V4L2_FRMIVAL_TYPE_DISCRETE;
fe->discrete.denominator = is_ntsc ? 30000 : 25000;
fe->discrete.numerator = (is_ntsc ? 1001 : 1000) * frm_dec[fe->index];
dprintk(vc->dev, 4, "%s discrete %d/%d\n", __func__,
fe->discrete.numerator,
fe->discrete.denominator);
return 0;
}
static int s2255_open(struct file *file)
{
struct s2255_vc *vc = video_drvdata(file);
struct s2255_dev *dev = vc->dev;
int state;
int rc = 0;
rc = v4l2_fh_open(file);
if (rc != 0)
return rc;
dprintk(dev, 1, "s2255: %s\n", __func__);
state = atomic_read(&dev->fw_data->fw_state);
switch (state) {
case S2255_FW_DISCONNECTING:
return -ENODEV;
case S2255_FW_FAILED:
s2255_dev_err(&dev->udev->dev,
"firmware load failed. retrying.\n");
s2255_fwload_start(dev, 1);
wait_event_timeout(dev->fw_data->wait_fw,
((atomic_read(&dev->fw_data->fw_state)
== S2255_FW_SUCCESS) ||
(atomic_read(&dev->fw_data->fw_state)
== S2255_FW_DISCONNECTING)),
msecs_to_jiffies(S2255_LOAD_TIMEOUT));
state = atomic_read(&dev->fw_data->fw_state);
break;
case S2255_FW_NOTLOADED:
case S2255_FW_LOADED_DSPWAIT:
pr_info("%s waiting for firmware load\n", __func__);
wait_event_timeout(dev->fw_data->wait_fw,
((atomic_read(&dev->fw_data->fw_state)
== S2255_FW_SUCCESS) ||
(atomic_read(&dev->fw_data->fw_state)
== S2255_FW_DISCONNECTING)),
msecs_to_jiffies(S2255_LOAD_TIMEOUT));
state = atomic_read(&dev->fw_data->fw_state);
break;
case S2255_FW_SUCCESS:
default:
break;
}
switch (state) {
case S2255_FW_SUCCESS:
break;
case S2255_FW_FAILED:
pr_info("2255 firmware load failed.\n");
return -ENODEV;
case S2255_FW_DISCONNECTING:
pr_info("%s: disconnecting\n", __func__);
return -ENODEV;
case S2255_FW_LOADED_DSPWAIT:
case S2255_FW_NOTLOADED:
pr_info("%s: firmware not loaded, please retry\n",
__func__);
atomic_set(&dev->fw_data->fw_state,
S2255_FW_FAILED);
return -EAGAIN;
default:
pr_info("%s: unknown state\n", __func__);
return -EFAULT;
}
if (!vc->configured) {
vc->fmt = &formats[0];
s2255_set_mode(vc, &vc->mode);
vc->configured = 1;
}
return 0;
}
static void s2255_destroy(struct s2255_dev *dev)
{
dprintk(dev, 1, "%s", __func__);
s2255_board_shutdown(dev);
del_timer_sync(&dev->timer);
if (dev->fw_data->fw_urb) {
usb_kill_urb(dev->fw_data->fw_urb);
usb_free_urb(dev->fw_data->fw_urb);
dev->fw_data->fw_urb = NULL;
}
release_firmware(dev->fw_data->fw);
kfree(dev->fw_data->pfw_data);
kfree(dev->fw_data);
s2255_reset_dsppower(dev);
mutex_destroy(&dev->lock);
usb_put_dev(dev->udev);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev->cmdbuf);
kfree(dev);
}
static void s2255_video_device_release(struct video_device *vdev)
{
struct s2255_dev *dev = to_s2255_dev(vdev->v4l2_dev);
struct s2255_vc *vc =
container_of(vdev, struct s2255_vc, vdev);
dprintk(dev, 4, "%s, chnls: %d\n", __func__,
atomic_read(&dev->num_channels));
v4l2_ctrl_handler_free(&vc->hdl);
if (atomic_dec_and_test(&dev->num_channels))
s2255_destroy(dev);
return;
}
static int s2255_probe_v4l(struct s2255_dev *dev)
{
int ret;
int i;
int cur_nr = video_nr;
struct s2255_vc *vc;
struct vb2_queue *q;
ret = v4l2_device_register(&dev->interface->dev, &dev->v4l2_dev);
if (ret)
return ret;
for (i = 0; i < MAX_CHANNELS; i++) {
vc = &dev->vc[i];
INIT_LIST_HEAD(&vc->buf_list);
v4l2_ctrl_handler_init(&vc->hdl, 6);
v4l2_ctrl_new_std(&vc->hdl, &s2255_ctrl_ops,
V4L2_CID_BRIGHTNESS, -127, 127, 1, DEF_BRIGHT);
v4l2_ctrl_new_std(&vc->hdl, &s2255_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, DEF_CONTRAST);
v4l2_ctrl_new_std(&vc->hdl, &s2255_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, DEF_SATURATION);
v4l2_ctrl_new_std(&vc->hdl, &s2255_ctrl_ops,
V4L2_CID_HUE, 0, 255, 1, DEF_HUE);
vc->jpegqual_ctrl = v4l2_ctrl_new_std(&vc->hdl,
&s2255_ctrl_ops,
V4L2_CID_JPEG_COMPRESSION_QUALITY,
0, 100, 1, S2255_DEF_JPEG_QUAL);
if (dev->dsp_fw_ver >= S2255_MIN_DSP_COLORFILTER &&
(dev->pid != 0x2257 || vc->idx <= 1))
v4l2_ctrl_new_custom(&vc->hdl, &color_filter_ctrl,
NULL);
if (vc->hdl.error) {
ret = vc->hdl.error;
v4l2_ctrl_handler_free(&vc->hdl);
dev_err(&dev->udev->dev, "couldn't register control\n");
break;
}
q = &vc->vb_vidq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_READ | VB2_USERPTR;
q->drv_priv = vc;
q->lock = &vc->vb_lock;
q->buf_struct_size = sizeof(struct s2255_buffer);
q->mem_ops = &vb2_vmalloc_memops;
q->ops = &s2255_video_qops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(q);
if (ret != 0) {
dev_err(&dev->udev->dev,
"%s vb2_queue_init 0x%x\n", __func__, ret);
break;
}
vc->vdev = template;
vc->vdev.queue = q;
vc->vdev.ctrl_handler = &vc->hdl;
vc->vdev.lock = &dev->lock;
vc->vdev.v4l2_dev = &dev->v4l2_dev;
video_set_drvdata(&vc->vdev, vc);
if (video_nr == -1)
ret = video_register_device(&vc->vdev,
VFL_TYPE_GRABBER,
video_nr);
else
ret = video_register_device(&vc->vdev,
VFL_TYPE_GRABBER,
cur_nr + i);
if (ret) {
dev_err(&dev->udev->dev,
"failed to register video device!\n");
break;
}
atomic_inc(&dev->num_channels);
v4l2_info(&dev->v4l2_dev, "V4L2 device registered as %s\n",
video_device_node_name(&vc->vdev));
}
pr_info("Sensoray 2255 V4L driver Revision: %s\n",
S2255_VERSION);
if (atomic_read(&dev->num_channels) == 0) {
v4l2_device_unregister(&dev->v4l2_dev);
return ret;
}
if (atomic_read(&dev->num_channels) != MAX_CHANNELS)
pr_warn("s2255: Not all channels available.\n");
return 0;
}
static int save_frame(struct s2255_dev *dev, struct s2255_pipeinfo *pipe_info)
{
char *pdest;
u32 offset = 0;
int bframe = 0;
char *psrc;
unsigned long copy_size;
unsigned long size;
s32 idx = -1;
struct s2255_framei *frm;
unsigned char *pdata;
struct s2255_vc *vc;
dprintk(dev, 100, "buffer to user\n");
vc = &dev->vc[dev->cc];
idx = vc->cur_frame;
frm = &vc->buffer.frame[idx];
if (frm->ulState == S2255_READ_IDLE) {
int jj;
unsigned int cc;
__le32 *pdword;
int payload;
pdata = (unsigned char *)pipe_info->transfer_buffer;
pdword = (__le32 *)pdata;
for (jj = 0; jj < (pipe_info->cur_transfer_size - 12); jj++) {
switch (*pdword) {
case S2255_MARKER_FRAME:
dprintk(dev, 4, "marker @ offset: %d [%x %x]\n",
jj, pdata[0], pdata[1]);
offset = jj + PREFIX_SIZE;
bframe = 1;
cc = le32_to_cpu(pdword[1]);
if (cc >= MAX_CHANNELS) {
dprintk(dev, 0,
"bad channel\n");
return -EINVAL;
}
dev->cc = G_chnmap[cc];
vc = &dev->vc[dev->cc];
payload = le32_to_cpu(pdword[3]);
if (payload > vc->req_image_size) {
vc->bad_payload++;
return -EINVAL;
}
vc->pkt_size = payload;
vc->jpg_size = le32_to_cpu(pdword[4]);
break;
case S2255_MARKER_RESPONSE:
pdata += DEF_USB_BLOCK;
jj += DEF_USB_BLOCK;
if (le32_to_cpu(pdword[1]) >= MAX_CHANNELS)
break;
cc = G_chnmap[le32_to_cpu(pdword[1])];
if (cc >= MAX_CHANNELS)
break;
vc = &dev->vc[cc];
switch (pdword[2]) {
case S2255_RESPONSE_SETMODE:
vc->setmode_ready = 1;
wake_up(&vc->wait_setmode);
dprintk(dev, 5, "setmode rdy %d\n", cc);
break;
case S2255_RESPONSE_FW:
dev->chn_ready |= (1 << cc);
if ((dev->chn_ready & 0x0f) != 0x0f)
break;
pr_info("s2255: fw loaded\n");
atomic_set(&dev->fw_data->fw_state,
S2255_FW_SUCCESS);
wake_up(&dev->fw_data->wait_fw);
break;
case S2255_RESPONSE_STATUS:
vc->vidstatus = le32_to_cpu(pdword[3]);
vc->vidstatus_ready = 1;
wake_up(&vc->wait_vidstatus);
dprintk(dev, 5, "vstat %x chan %d\n",
le32_to_cpu(pdword[3]), cc);
break;
default:
pr_info("s2255 unknown resp\n");
}
default:
pdata++;
break;
}
if (bframe)
break;
}
if (!bframe)
return -EINVAL;
}
vc = &dev->vc[dev->cc];
idx = vc->cur_frame;
frm = &vc->buffer.frame[idx];
if (!vb2_is_streaming(&vc->vb_vidq)) {
frm->ulState = S2255_READ_IDLE;
return -EINVAL;
}
if (frm->ulState == S2255_READ_IDLE) {
frm->ulState = S2255_READ_FRAME;
frm->cur_size = 0;
}
psrc = (u8 *)pipe_info->transfer_buffer + offset;
if (frm->lpvbits == NULL) {
dprintk(dev, 1, "s2255 frame buffer == NULL.%p %p %d %d",
frm, dev, dev->cc, idx);
return -ENOMEM;
}
pdest = frm->lpvbits + frm->cur_size;
copy_size = (pipe_info->cur_transfer_size - offset);
size = vc->pkt_size - PREFIX_SIZE;
if ((copy_size + frm->cur_size) < vc->req_image_size)
memcpy(pdest, psrc, copy_size);
frm->cur_size += copy_size;
dprintk(dev, 4, "cur_size: %lu, size: %lu\n", frm->cur_size, size);
if (frm->cur_size >= size) {
dprintk(dev, 2, "******[%d]Buffer[%d]full*******\n",
dev->cc, idx);
vc->last_frame = vc->cur_frame;
vc->cur_frame++;
if ((vc->cur_frame == SYS_FRAMES) ||
(vc->cur_frame == vc->buffer.dwFrames))
vc->cur_frame = 0;
if (vb2_is_streaming(&vc->vb_vidq))
s2255_got_frame(vc, vc->jpg_size);
vc->frame_count++;
frm->ulState = S2255_READ_IDLE;
frm->cur_size = 0;
}
return 0;
}
static void s2255_read_video_callback(struct s2255_dev *dev,
struct s2255_pipeinfo *pipe_info)
{
int res;
dprintk(dev, 50, "callback read video\n");
if (dev->cc >= MAX_CHANNELS) {
dev->cc = 0;
dev_err(&dev->udev->dev, "invalid channel\n");
return;
}
res = save_frame(dev, pipe_info);
if (res != 0)
dprintk(dev, 4, "s2255: read callback failed\n");
dprintk(dev, 50, "callback read video done\n");
return;
}
static long s2255_vendor_req(struct s2255_dev *dev, unsigned char Request,
u16 Index, u16 Value, void *TransferBuffer,
s32 TransferBufferLength, int bOut)
{
int r;
if (!bOut) {
r = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
Request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE |
USB_DIR_IN,
Value, Index, TransferBuffer,
TransferBufferLength, HZ * 5);
} else {
r = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, 0),
Request, USB_TYPE_VENDOR | USB_RECIP_DEVICE,
Value, Index, TransferBuffer,
TransferBufferLength, HZ * 5);
}
return r;
}
static int s2255_get_fx2fw(struct s2255_dev *dev)
{
int fw;
int ret;
unsigned char transBuffer[64];
ret = s2255_vendor_req(dev, S2255_VR_FW, 0, 0, transBuffer, 2,
S2255_VR_IN);
if (ret < 0)
dprintk(dev, 2, "get fw error: %x\n", ret);
fw = transBuffer[0] + (transBuffer[1] << 8);
dprintk(dev, 2, "Get FW %x %x\n", transBuffer[0], transBuffer[1]);
return fw;
}
static int s2255_create_sys_buffers(struct s2255_vc *vc)
{
unsigned long i;
unsigned long reqsize;
vc->buffer.dwFrames = SYS_FRAMES;
reqsize = SYS_FRAMES_MAXSIZE;
if (reqsize > SYS_FRAMES_MAXSIZE)
reqsize = SYS_FRAMES_MAXSIZE;
for (i = 0; i < SYS_FRAMES; i++) {
vc->buffer.frame[i].lpvbits = vmalloc(reqsize);
vc->buffer.frame[i].size = reqsize;
if (vc->buffer.frame[i].lpvbits == NULL) {
pr_info("out of memory. using less frames\n");
vc->buffer.dwFrames = i;
break;
}
}
for (i = 0; i < SYS_FRAMES; i++) {
vc->buffer.frame[i].ulState = 0;
vc->buffer.frame[i].cur_size = 0;
}
vc->cur_frame = 0;
vc->last_frame = -1;
return 0;
}
static int s2255_release_sys_buffers(struct s2255_vc *vc)
{
unsigned long i;
for (i = 0; i < SYS_FRAMES; i++) {
vfree(vc->buffer.frame[i].lpvbits);
vc->buffer.frame[i].lpvbits = NULL;
}
return 0;
}
static int s2255_board_init(struct s2255_dev *dev)
{
struct s2255_mode mode_def = DEF_MODEI_NTSC_CONT;
int fw_ver;
int j;
struct s2255_pipeinfo *pipe = &dev->pipe;
dprintk(dev, 4, "board init: %p", dev);
memset(pipe, 0, sizeof(*pipe));
pipe->dev = dev;
pipe->cur_transfer_size = S2255_USB_XFER_SIZE;
pipe->max_transfer_size = S2255_USB_XFER_SIZE;
pipe->transfer_buffer = kzalloc(pipe->max_transfer_size,
GFP_KERNEL);
if (pipe->transfer_buffer == NULL) {
dprintk(dev, 1, "out of memory!\n");
return -ENOMEM;
}
fw_ver = s2255_get_fx2fw(dev);
pr_info("s2255: usb firmware version %d.%d\n",
(fw_ver >> 8) & 0xff,
fw_ver & 0xff);
if (fw_ver < S2255_CUR_USB_FWVER)
pr_info("s2255: newer USB firmware available\n");
for (j = 0; j < MAX_CHANNELS; j++) {
struct s2255_vc *vc = &dev->vc[j];
vc->mode = mode_def;
if (dev->pid == 0x2257 && j > 1)
vc->mode.color |= (1 << 16);
vc->jpegqual = S2255_DEF_JPEG_QUAL;
vc->width = LINE_SZ_4CIFS_NTSC;
vc->height = NUM_LINES_4CIFS_NTSC * 2;
vc->std = V4L2_STD_NTSC_M;
vc->fmt = &formats[0];
vc->mode.restart = 1;
vc->req_image_size = get_transfer_size(&mode_def);
vc->frame_count = 0;
s2255_create_sys_buffers(vc);
}
s2255_start_readpipe(dev);
dprintk(dev, 1, "%s: success\n", __func__);
return 0;
}
static int s2255_board_shutdown(struct s2255_dev *dev)
{
u32 i;
dprintk(dev, 1, "%s: dev: %p", __func__, dev);
for (i = 0; i < MAX_CHANNELS; i++) {
if (vb2_is_streaming(&dev->vc[i].vb_vidq))
s2255_stop_acquire(&dev->vc[i]);
}
s2255_stop_readpipe(dev);
for (i = 0; i < MAX_CHANNELS; i++)
s2255_release_sys_buffers(&dev->vc[i]);
kfree(dev->pipe.transfer_buffer);
return 0;
}
static void read_pipe_completion(struct urb *purb)
{
struct s2255_pipeinfo *pipe_info;
struct s2255_dev *dev;
int status;
int pipe;
pipe_info = purb->context;
if (pipe_info == NULL) {
dev_err(&purb->dev->dev, "no context!\n");
return;
}
dev = pipe_info->dev;
if (dev == NULL) {
dev_err(&purb->dev->dev, "no context!\n");
return;
}
status = purb->status;
if (status == -ESHUTDOWN) {
dprintk(dev, 2, "%s: err shutdown\n", __func__);
pipe_info->err_count++;
return;
}
if (pipe_info->state == 0) {
dprintk(dev, 2, "%s: exiting USB pipe", __func__);
return;
}
if (status == 0)
s2255_read_video_callback(dev, pipe_info);
else {
pipe_info->err_count++;
dprintk(dev, 1, "%s: failed URB %d\n", __func__, status);
}
pipe = usb_rcvbulkpipe(dev->udev, dev->read_endpoint);
usb_fill_bulk_urb(pipe_info->stream_urb, dev->udev,
pipe,
pipe_info->transfer_buffer,
pipe_info->cur_transfer_size,
read_pipe_completion, pipe_info);
if (pipe_info->state != 0) {
if (usb_submit_urb(pipe_info->stream_urb, GFP_ATOMIC))
dev_err(&dev->udev->dev, "error submitting urb\n");
} else {
dprintk(dev, 2, "%s :complete state 0\n", __func__);
}
return;
}
static int s2255_start_readpipe(struct s2255_dev *dev)
{
int pipe;
int retval;
struct s2255_pipeinfo *pipe_info = &dev->pipe;
pipe = usb_rcvbulkpipe(dev->udev, dev->read_endpoint);
dprintk(dev, 2, "%s: IN %d\n", __func__, dev->read_endpoint);
pipe_info->state = 1;
pipe_info->err_count = 0;
pipe_info->stream_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!pipe_info->stream_urb) {
dev_err(&dev->udev->dev,
"ReadStream: Unable to alloc URB\n");
return -ENOMEM;
}
usb_fill_bulk_urb(pipe_info->stream_urb, dev->udev,
pipe,
pipe_info->transfer_buffer,
pipe_info->cur_transfer_size,
read_pipe_completion, pipe_info);
retval = usb_submit_urb(pipe_info->stream_urb, GFP_KERNEL);
if (retval) {
pr_err("s2255: start read pipe failed\n");
return retval;
}
return 0;
}
static int s2255_start_acquire(struct s2255_vc *vc)
{
int res;
unsigned long chn_rev;
int j;
struct s2255_dev *dev = to_s2255_dev(vc->vdev.v4l2_dev);
__le32 *buffer = dev->cmdbuf;
mutex_lock(&dev->cmdlock);
chn_rev = G_chnmap[vc->idx];
vc->last_frame = -1;
vc->bad_payload = 0;
vc->cur_frame = 0;
for (j = 0; j < SYS_FRAMES; j++) {
vc->buffer.frame[j].ulState = 0;
vc->buffer.frame[j].cur_size = 0;
}
buffer[0] = IN_DATA_TOKEN;
buffer[1] = (__le32) cpu_to_le32(chn_rev);
buffer[2] = CMD_START;
res = s2255_write_config(dev->udev, (unsigned char *)buffer, 512);
if (res != 0)
dev_err(&dev->udev->dev, "CMD_START error\n");
dprintk(dev, 2, "start acquire exit[%d] %d\n", vc->idx, res);
mutex_unlock(&dev->cmdlock);
return res;
}
static int s2255_stop_acquire(struct s2255_vc *vc)
{
int res;
unsigned long chn_rev;
struct s2255_dev *dev = to_s2255_dev(vc->vdev.v4l2_dev);
__le32 *buffer = dev->cmdbuf;
mutex_lock(&dev->cmdlock);
chn_rev = G_chnmap[vc->idx];
buffer[0] = IN_DATA_TOKEN;
buffer[1] = (__le32) cpu_to_le32(chn_rev);
buffer[2] = CMD_STOP;
res = s2255_write_config(dev->udev, (unsigned char *)buffer, 512);
if (res != 0)
dev_err(&dev->udev->dev, "CMD_STOP error\n");
dprintk(dev, 4, "%s: chn %d, res %d\n", __func__, vc->idx, res);
mutex_unlock(&dev->cmdlock);
return res;
}
static void s2255_stop_readpipe(struct s2255_dev *dev)
{
struct s2255_pipeinfo *pipe = &dev->pipe;
pipe->state = 0;
if (pipe->stream_urb) {
usb_kill_urb(pipe->stream_urb);
usb_free_urb(pipe->stream_urb);
pipe->stream_urb = NULL;
}
dprintk(dev, 4, "%s", __func__);
return;
}
static void s2255_fwload_start(struct s2255_dev *dev, int reset)
{
if (reset)
s2255_reset_dsppower(dev);
dev->fw_data->fw_size = dev->fw_data->fw->size;
atomic_set(&dev->fw_data->fw_state, S2255_FW_NOTLOADED);
memcpy(dev->fw_data->pfw_data,
dev->fw_data->fw->data, CHUNK_SIZE);
dev->fw_data->fw_loaded = CHUNK_SIZE;
usb_fill_bulk_urb(dev->fw_data->fw_urb, dev->udev,
usb_sndbulkpipe(dev->udev, 2),
dev->fw_data->pfw_data,
CHUNK_SIZE, s2255_fwchunk_complete,
dev->fw_data);
mod_timer(&dev->timer, jiffies + HZ);
}
static int s2255_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct s2255_dev *dev = NULL;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i;
int retval = -ENOMEM;
__le32 *pdata;
int fw_size;
dev = kzalloc(sizeof(struct s2255_dev), GFP_KERNEL);
if (dev == NULL) {
s2255_dev_err(&interface->dev, "out of memory\n");
return -ENOMEM;
}
dev->cmdbuf = kzalloc(S2255_CMDBUF_SIZE, GFP_KERNEL);
if (dev->cmdbuf == NULL) {
s2255_dev_err(&interface->dev, "out of memory\n");
goto errorFWDATA1;
}
atomic_set(&dev->num_channels, 0);
dev->pid = id->idProduct;
dev->fw_data = kzalloc(sizeof(struct s2255_fw), GFP_KERNEL);
if (!dev->fw_data)
goto errorFWDATA1;
mutex_init(&dev->lock);
mutex_init(&dev->cmdlock);
dev->udev = usb_get_dev(interface_to_usbdev(interface));
if (dev->udev == NULL) {
dev_err(&interface->dev, "null usb device\n");
retval = -ENODEV;
goto errorUDEV;
}
dev_dbg(&interface->dev, "dev: %p, udev %p interface %p\n",
dev, dev->udev, interface);
dev->interface = interface;
iface_desc = interface->cur_altsetting;
dev_dbg(&interface->dev, "num EP: %d\n",
iface_desc->desc.bNumEndpoints);
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (!dev->read_endpoint && usb_endpoint_is_bulk_in(endpoint)) {
dev->read_endpoint = endpoint->bEndpointAddress;
}
}
if (!dev->read_endpoint) {
dev_err(&interface->dev, "Could not find bulk-in endpoint\n");
goto errorEP;
}
setup_timer(&dev->timer, s2255_timer, (unsigned long)dev->fw_data);
init_waitqueue_head(&dev->fw_data->wait_fw);
for (i = 0; i < MAX_CHANNELS; i++) {
struct s2255_vc *vc = &dev->vc[i];
vc->idx = i;
vc->dev = dev;
init_waitqueue_head(&vc->wait_setmode);
init_waitqueue_head(&vc->wait_vidstatus);
spin_lock_init(&vc->qlock);
mutex_init(&vc->vb_lock);
}
dev->fw_data->fw_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->fw_data->fw_urb) {
dev_err(&interface->dev, "out of memory!\n");
goto errorFWURB;
}
dev->fw_data->pfw_data = kzalloc(CHUNK_SIZE, GFP_KERNEL);
if (!dev->fw_data->pfw_data) {
dev_err(&interface->dev, "out of memory!\n");
goto errorFWDATA2;
}
if (request_firmware(&dev->fw_data->fw,
FIRMWARE_FILE_NAME, &dev->udev->dev)) {
dev_err(&interface->dev, "sensoray 2255 failed to get firmware\n");
goto errorREQFW;
}
fw_size = dev->fw_data->fw->size;
pdata = (__le32 *) &dev->fw_data->fw->data[fw_size - 8];
if (*pdata != S2255_FW_MARKER) {
dev_err(&interface->dev, "Firmware invalid.\n");
retval = -ENODEV;
goto errorFWMARKER;
} else {
__le32 *pRel;
pRel = (__le32 *) &dev->fw_data->fw->data[fw_size - 4];
pr_info("s2255 dsp fw version %x\n", le32_to_cpu(*pRel));
dev->dsp_fw_ver = le32_to_cpu(*pRel);
if (dev->dsp_fw_ver < S2255_CUR_DSP_FWVER)
pr_info("s2255: f2255usb.bin out of date.\n");
if (dev->pid == 0x2257 &&
dev->dsp_fw_ver < S2255_MIN_DSP_COLORFILTER)
pr_warn("2257 needs firmware %d or above.\n",
S2255_MIN_DSP_COLORFILTER);
}
usb_reset_device(dev->udev);
retval = s2255_board_init(dev);
if (retval)
goto errorBOARDINIT;
s2255_fwload_start(dev, 0);
retval = s2255_probe_v4l(dev);
if (retval)
goto errorBOARDINIT;
dev_info(&interface->dev, "Sensoray 2255 detected\n");
return 0;
errorBOARDINIT:
s2255_board_shutdown(dev);
errorFWMARKER:
release_firmware(dev->fw_data->fw);
errorREQFW:
kfree(dev->fw_data->pfw_data);
errorFWDATA2:
usb_free_urb(dev->fw_data->fw_urb);
errorFWURB:
del_timer_sync(&dev->timer);
errorEP:
usb_put_dev(dev->udev);
errorUDEV:
kfree(dev->fw_data);
mutex_destroy(&dev->lock);
errorFWDATA1:
kfree(dev->cmdbuf);
kfree(dev);
pr_warn("Sensoray 2255 driver load failed: 0x%x\n", retval);
return retval;
}
static void s2255_disconnect(struct usb_interface *interface)
{
struct s2255_dev *dev = to_s2255_dev(usb_get_intfdata(interface));
int i;
int channels = atomic_read(&dev->num_channels);
mutex_lock(&dev->lock);
v4l2_device_disconnect(&dev->v4l2_dev);
mutex_unlock(&dev->lock);
atomic_inc(&dev->num_channels);
for (i = 0; i < channels; i++)
video_unregister_device(&dev->vc[i].vdev);
atomic_set(&dev->fw_data->fw_state, S2255_FW_DISCONNECTING);
wake_up(&dev->fw_data->wait_fw);
for (i = 0; i < MAX_CHANNELS; i++) {
dev->vc[i].setmode_ready = 1;
wake_up(&dev->vc[i].wait_setmode);
dev->vc[i].vidstatus_ready = 1;
wake_up(&dev->vc[i].wait_vidstatus);
}
if (atomic_dec_and_test(&dev->num_channels))
s2255_destroy(dev);
dev_info(&interface->dev, "%s\n", __func__);
}
