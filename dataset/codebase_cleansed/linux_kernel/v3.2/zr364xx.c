static int send_control_msg(struct usb_device *udev, u8 request, u16 value,
u16 index, unsigned char *cp, u16 size)
{
int status;
unsigned char *transfer_buffer = kmalloc(size, GFP_KERNEL);
if (!transfer_buffer) {
dev_err(&udev->dev, "kmalloc(%d) failed\n", size);
return -ENOMEM;
}
memcpy(transfer_buffer, cp, size);
status = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
request,
USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, value, index,
transfer_buffer, size, CTRL_TIMEOUT);
kfree(transfer_buffer);
if (status < 0)
dev_err(&udev->dev,
"Failed sending control message, error %d.\n", status);
return status;
}
static int buffer_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct zr364xx_camera *cam = vq->priv_data;
*size = cam->width * cam->height * (cam->fmt->depth >> 3);
if (*count == 0)
*count = ZR364XX_DEF_BUFS;
if (*size * *count > ZR364XX_DEF_BUFS * 1024 * 1024)
*count = (ZR364XX_DEF_BUFS * 1024 * 1024) / *size;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct zr364xx_buffer *buf)
{
_DBG("%s\n", __func__);
if (in_interrupt())
BUG();
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct zr364xx_camera *cam = vq->priv_data;
struct zr364xx_buffer *buf = container_of(vb, struct zr364xx_buffer,
vb);
int rc;
DBG("%s, field=%d, fmt name = %s\n", __func__, field, cam->fmt != NULL ?
cam->fmt->name : "");
if (cam->fmt == NULL)
return -EINVAL;
buf->vb.size = cam->width * cam->height * (cam->fmt->depth >> 3);
if (buf->vb.baddr != 0 && buf->vb.bsize < buf->vb.size) {
DBG("invalid buffer prepare\n");
return -EINVAL;
}
buf->fmt = cam->fmt;
buf->vb.width = cam->width;
buf->vb.height = cam->height;
buf->vb.field = field;
if (buf->vb.state == VIDEOBUF_NEEDS_INIT) {
rc = videobuf_iolock(vq, &buf->vb, NULL);
if (rc < 0)
goto fail;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
free_buffer(vq, buf);
return rc;
}
static void buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct zr364xx_buffer *buf = container_of(vb, struct zr364xx_buffer,
vb);
struct zr364xx_camera *cam = vq->priv_data;
_DBG("%s\n", __func__);
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &cam->vidq.active);
}
static void buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct zr364xx_buffer *buf = container_of(vb, struct zr364xx_buffer,
vb);
_DBG("%s\n", __func__);
free_buffer(vq, buf);
}
static ssize_t zr364xx_read(struct file *file, char __user *buf, size_t count,
loff_t * ppos)
{
struct zr364xx_camera *cam = video_drvdata(file);
_DBG("%s\n", __func__);
if (!buf)
return -EINVAL;
if (!count)
return -EINVAL;
if (cam->type == V4L2_BUF_TYPE_VIDEO_CAPTURE &&
zr364xx_vidioc_streamon(file, cam, cam->type) == 0) {
DBG("%s: reading %d bytes at pos %d.\n", __func__, (int) count,
(int) *ppos);
return videobuf_read_one(&cam->vb_vidq, buf, count, ppos,
file->f_flags & O_NONBLOCK);
}
return 0;
}
static void zr364xx_fillbuff(struct zr364xx_camera *cam,
struct zr364xx_buffer *buf,
int jpgsize)
{
int pos = 0;
struct timeval ts;
const char *tmpbuf;
char *vbuf = videobuf_to_vmalloc(&buf->vb);
unsigned long last_frame;
struct zr364xx_framei *frm;
if (!vbuf)
return;
last_frame = cam->last_frame;
if (last_frame != -1) {
frm = &cam->buffer.frame[last_frame];
tmpbuf = (const char *)cam->buffer.frame[last_frame].lpvbits;
switch (buf->fmt->fourcc) {
case V4L2_PIX_FMT_JPEG:
buf->vb.size = jpgsize;
memcpy(vbuf, tmpbuf, buf->vb.size);
break;
default:
printk(KERN_DEBUG KBUILD_MODNAME ": unknown format?\n");
}
cam->last_frame = -1;
} else {
printk(KERN_ERR KBUILD_MODNAME ": =======no frame\n");
return;
}
DBG("%s: Buffer 0x%08lx size= %d\n", __func__,
(unsigned long)vbuf, pos);
buf->vb.field_count = cam->frame_count * 2;
do_gettimeofday(&ts);
buf->vb.ts = ts;
buf->vb.state = VIDEOBUF_DONE;
}
static int zr364xx_got_frame(struct zr364xx_camera *cam, int jpgsize)
{
struct zr364xx_dmaqueue *dma_q = &cam->vidq;
struct zr364xx_buffer *buf;
unsigned long flags = 0;
int rc = 0;
DBG("wakeup: %p\n", &dma_q);
spin_lock_irqsave(&cam->slock, flags);
if (list_empty(&dma_q->active)) {
DBG("No active queue to serve\n");
rc = -1;
goto unlock;
}
buf = list_entry(dma_q->active.next,
struct zr364xx_buffer, vb.queue);
if (!waitqueue_active(&buf->vb.done)) {
rc = -1;
goto unlock;
}
list_del(&buf->vb.queue);
do_gettimeofday(&buf->vb.ts);
DBG("[%p/%d] wakeup\n", buf, buf->vb.i);
zr364xx_fillbuff(cam, buf, jpgsize);
wake_up(&buf->vb.done);
DBG("wakeup [buf/i] [%p/%d]\n", buf, buf->vb.i);
unlock:
spin_unlock_irqrestore(&cam->slock, flags);
return rc;
}
static int zr364xx_read_video_callback(struct zr364xx_camera *cam,
struct zr364xx_pipeinfo *pipe_info,
struct urb *purb)
{
unsigned char *pdest;
unsigned char *psrc;
s32 idx = -1;
struct zr364xx_framei *frm;
int i = 0;
unsigned char *ptr = NULL;
_DBG("buffer to user\n");
idx = cam->cur_frame;
frm = &cam->buffer.frame[idx];
if (cam->method == METHOD0) {
u16 *buf = (u16 *)pipe_info->transfer_buffer;
for (i = 0; i < purb->actual_length/2; i++)
swab16s(buf + i);
}
if (!cam->b_acquire) {
frm->ulState = ZR364XX_READ_IDLE;
return -EINVAL;
}
psrc = (u8 *)pipe_info->transfer_buffer;
ptr = pdest = frm->lpvbits;
if (frm->ulState == ZR364XX_READ_IDLE) {
frm->ulState = ZR364XX_READ_FRAME;
frm->cur_size = 0;
_DBG("jpeg header, ");
memcpy(ptr, header1, sizeof(header1));
ptr += sizeof(header1);
header3 = 0;
memcpy(ptr, &header3, 1);
ptr++;
memcpy(ptr, psrc, 64);
ptr += 64;
header3 = 1;
memcpy(ptr, &header3, 1);
ptr++;
memcpy(ptr, psrc + 64, 64);
ptr += 64;
memcpy(ptr, header2, sizeof(header2));
ptr += sizeof(header2);
memcpy(ptr, psrc + 128,
purb->actual_length - 128);
ptr += purb->actual_length - 128;
_DBG("header : %d %d %d %d %d %d %d %d %d\n",
psrc[0], psrc[1], psrc[2],
psrc[3], psrc[4], psrc[5],
psrc[6], psrc[7], psrc[8]);
frm->cur_size = ptr - pdest;
} else {
if (frm->cur_size + purb->actual_length > MAX_FRAME_SIZE) {
dev_info(&cam->udev->dev,
"%s: buffer (%d bytes) too small to hold "
"frame data. Discarding frame data.\n",
__func__, MAX_FRAME_SIZE);
} else {
pdest += frm->cur_size;
memcpy(pdest, psrc, purb->actual_length);
frm->cur_size += purb->actual_length;
}
}
if (purb->actual_length < pipe_info->transfer_size) {
_DBG("****************Buffer[%d]full*************\n", idx);
cam->last_frame = cam->cur_frame;
cam->cur_frame++;
if (cam->cur_frame == cam->buffer.dwFrames)
cam->cur_frame = 0;
ptr = pdest = frm->lpvbits;
ptr += frm->cur_size - 2;
while (ptr > pdest) {
if (*ptr == 0xFF && *(ptr + 1) == 0xD9
&& *(ptr + 2) == 0xFF)
break;
ptr--;
}
if (ptr == pdest)
DBG("No EOI marker\n");
while (ptr > pdest) {
if (*ptr == 0xFF && *(ptr + 1) == 0xFF
&& *(ptr + 2) == 0xFF)
break;
ptr--;
}
if (ptr != pdest) {
DBG("Bogus frame ? %d\n", ++(cam->nb));
} else if (cam->b_acquire) {
if (cam->skip)
cam->skip--;
else {
_DBG("jpeg(%lu): %d %d %d %d %d %d %d %d\n",
frm->cur_size,
pdest[0], pdest[1], pdest[2], pdest[3],
pdest[4], pdest[5], pdest[6], pdest[7]);
zr364xx_got_frame(cam, frm->cur_size);
}
}
cam->frame_count++;
frm->ulState = ZR364XX_READ_IDLE;
frm->cur_size = 0;
}
return 0;
}
static int res_get(struct zr364xx_camera *cam)
{
mutex_lock(&cam->lock);
if (cam->resources) {
mutex_unlock(&cam->lock);
return 0;
}
cam->resources = 1;
_DBG("res: get\n");
mutex_unlock(&cam->lock);
return 1;
}
static inline int res_check(struct zr364xx_camera *cam)
{
return cam->resources;
}
static void res_free(struct zr364xx_camera *cam)
{
mutex_lock(&cam->lock);
cam->resources = 0;
mutex_unlock(&cam->lock);
_DBG("res: put\n");
}
static int zr364xx_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct zr364xx_camera *cam = video_drvdata(file);
strlcpy(cap->driver, DRIVER_DESC, sizeof(cap->driver));
strlcpy(cap->card, cam->udev->product, sizeof(cap->card));
strlcpy(cap->bus_info, dev_name(&cam->udev->dev),
sizeof(cap->bus_info));
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
return 0;
}
static int zr364xx_vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
strcpy(i->name, DRIVER_DESC " Camera");
i->type = V4L2_INPUT_TYPE_CAMERA;
return 0;
}
static int zr364xx_vidioc_g_input(struct file *file, void *priv,
unsigned int *i)
{
*i = 0;
return 0;
}
static int zr364xx_vidioc_s_input(struct file *file, void *priv,
unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int zr364xx_vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *c)
{
struct zr364xx_camera *cam;
if (file == NULL)
return -ENODEV;
cam = video_drvdata(file);
switch (c->id) {
case V4L2_CID_BRIGHTNESS:
c->type = V4L2_CTRL_TYPE_INTEGER;
strcpy(c->name, "Brightness");
c->minimum = 0;
c->maximum = 127;
c->step = 1;
c->default_value = cam->mode.brightness;
c->flags = 0;
break;
default:
return -EINVAL;
}
return 0;
}
static int zr364xx_vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *c)
{
struct zr364xx_camera *cam;
int temp;
if (file == NULL)
return -ENODEV;
cam = video_drvdata(file);
switch (c->id) {
case V4L2_CID_BRIGHTNESS:
cam->mode.brightness = c->value;
mutex_lock(&cam->lock);
send_control_msg(cam->udev, 1, 0x2001, 0, NULL, 0);
temp = (0x60 << 8) + 127 - cam->mode.brightness;
send_control_msg(cam->udev, 1, temp, 0, NULL, 0);
mutex_unlock(&cam->lock);
break;
default:
return -EINVAL;
}
return 0;
}
static int zr364xx_vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *c)
{
struct zr364xx_camera *cam;
if (file == NULL)
return -ENODEV;
cam = video_drvdata(file);
switch (c->id) {
case V4L2_CID_BRIGHTNESS:
c->value = cam->mode.brightness;
break;
default:
return -EINVAL;
}
return 0;
}
static int zr364xx_vidioc_enum_fmt_vid_cap(struct file *file,
void *priv, struct v4l2_fmtdesc *f)
{
if (f->index > 0)
return -EINVAL;
f->flags = V4L2_FMT_FLAG_COMPRESSED;
strcpy(f->description, formats[0].name);
f->pixelformat = formats[0].fourcc;
return 0;
}
static char *decode_fourcc(__u32 pixelformat, char *buf)
{
buf[0] = pixelformat & 0xff;
buf[1] = (pixelformat >> 8) & 0xff;
buf[2] = (pixelformat >> 16) & 0xff;
buf[3] = (pixelformat >> 24) & 0xff;
buf[4] = '\0';
return buf;
}
static int zr364xx_vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct zr364xx_camera *cam = video_drvdata(file);
char pixelformat_name[5];
if (cam == NULL)
return -ENODEV;
if (f->fmt.pix.pixelformat != V4L2_PIX_FMT_JPEG) {
DBG("%s: unsupported pixelformat V4L2_PIX_FMT_%s\n", __func__,
decode_fourcc(f->fmt.pix.pixelformat, pixelformat_name));
return -EINVAL;
}
if (!(f->fmt.pix.width == 160 && f->fmt.pix.height == 120) &&
!(f->fmt.pix.width == 640 && f->fmt.pix.height == 480)) {
f->fmt.pix.width = 320;
f->fmt.pix.height = 240;
}
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.bytesperline = f->fmt.pix.width * 2;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = 0;
f->fmt.pix.priv = 0;
DBG("%s: V4L2_PIX_FMT_%s (%d) ok!\n", __func__,
decode_fourcc(f->fmt.pix.pixelformat, pixelformat_name),
f->fmt.pix.field);
return 0;
}
static int zr364xx_vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct zr364xx_camera *cam;
if (file == NULL)
return -ENODEV;
cam = video_drvdata(file);
f->fmt.pix.pixelformat = formats[0].fourcc;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.width = cam->width;
f->fmt.pix.height = cam->height;
f->fmt.pix.bytesperline = f->fmt.pix.width * 2;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = 0;
f->fmt.pix.priv = 0;
return 0;
}
static int zr364xx_vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct zr364xx_camera *cam = video_drvdata(file);
struct videobuf_queue *q = &cam->vb_vidq;
char pixelformat_name[5];
int ret = zr364xx_vidioc_try_fmt_vid_cap(file, cam, f);
int i;
if (ret < 0)
return ret;
mutex_lock(&q->vb_lock);
if (videobuf_queue_is_busy(&cam->vb_vidq)) {
DBG("%s queue busy\n", __func__);
ret = -EBUSY;
goto out;
}
if (res_check(cam)) {
DBG("%s can't change format after started\n", __func__);
ret = -EBUSY;
goto out;
}
cam->width = f->fmt.pix.width;
cam->height = f->fmt.pix.height;
dev_info(&cam->udev->dev, "%s: %dx%d mode selected\n", __func__,
cam->width, cam->height);
f->fmt.pix.bytesperline = f->fmt.pix.width * 2;
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
f->fmt.pix.colorspace = 0;
f->fmt.pix.priv = 0;
cam->vb_vidq.field = f->fmt.pix.field;
cam->mode.color = V4L2_PIX_FMT_JPEG;
if (f->fmt.pix.width == 160 && f->fmt.pix.height == 120)
mode = 1;
else if (f->fmt.pix.width == 640 && f->fmt.pix.height == 480)
mode = 2;
else
mode = 0;
m0d1[0] = mode;
m1[2].value = 0xf000 + mode;
m2[1].value = 0xf000 + mode;
if (cam->method == METHOD3) {
switch (mode) {
case 1:
m2[1].value = 0xf000 + 4;
break;
case 2:
m2[1].value = 0xf000 + 0;
break;
default:
m2[1].value = 0xf000 + 1;
break;
}
}
header2[437] = cam->height / 256;
header2[438] = cam->height % 256;
header2[439] = cam->width / 256;
header2[440] = cam->width % 256;
for (i = 0; init[cam->method][i].size != -1; i++) {
ret =
send_control_msg(cam->udev, 1, init[cam->method][i].value,
0, init[cam->method][i].bytes,
init[cam->method][i].size);
if (ret < 0) {
dev_err(&cam->udev->dev,
"error during resolution change sequence: %d\n", i);
goto out;
}
}
mdelay(100);
cam->skip = 2;
ret = 0;
out:
mutex_unlock(&q->vb_lock);
DBG("%s: V4L2_PIX_FMT_%s (%d) ok!\n", __func__,
decode_fourcc(f->fmt.pix.pixelformat, pixelformat_name),
f->fmt.pix.field);
return ret;
}
static int zr364xx_vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
int rc;
struct zr364xx_camera *cam = video_drvdata(file);
rc = videobuf_reqbufs(&cam->vb_vidq, p);
return rc;
}
static int zr364xx_vidioc_querybuf(struct file *file,
void *priv,
struct v4l2_buffer *p)
{
int rc;
struct zr364xx_camera *cam = video_drvdata(file);
rc = videobuf_querybuf(&cam->vb_vidq, p);
return rc;
}
static int zr364xx_vidioc_qbuf(struct file *file,
void *priv,
struct v4l2_buffer *p)
{
int rc;
struct zr364xx_camera *cam = video_drvdata(file);
_DBG("%s\n", __func__);
rc = videobuf_qbuf(&cam->vb_vidq, p);
return rc;
}
static int zr364xx_vidioc_dqbuf(struct file *file,
void *priv,
struct v4l2_buffer *p)
{
int rc;
struct zr364xx_camera *cam = video_drvdata(file);
_DBG("%s\n", __func__);
rc = videobuf_dqbuf(&cam->vb_vidq, p, file->f_flags & O_NONBLOCK);
return rc;
}
static void read_pipe_completion(struct urb *purb)
{
struct zr364xx_pipeinfo *pipe_info;
struct zr364xx_camera *cam;
int pipe;
pipe_info = purb->context;
_DBG("%s %p, status %d\n", __func__, purb, purb->status);
if (pipe_info == NULL) {
printk(KERN_ERR KBUILD_MODNAME ": no context!\n");
return;
}
cam = pipe_info->cam;
if (cam == NULL) {
printk(KERN_ERR KBUILD_MODNAME ": no context!\n");
return;
}
if (purb->status == -ESHUTDOWN) {
DBG("%s, err shutdown\n", __func__);
pipe_info->err_count++;
return;
}
if (pipe_info->state == 0) {
DBG("exiting USB pipe\n");
return;
}
if (purb->actual_length < 0 ||
purb->actual_length > pipe_info->transfer_size) {
dev_err(&cam->udev->dev, "wrong number of bytes\n");
return;
}
if (purb->status == 0)
zr364xx_read_video_callback(cam, pipe_info, purb);
else {
pipe_info->err_count++;
DBG("%s: failed URB %d\n", __func__, purb->status);
}
pipe = usb_rcvbulkpipe(cam->udev, cam->read_endpoint);
usb_fill_bulk_urb(pipe_info->stream_urb, cam->udev,
pipe,
pipe_info->transfer_buffer,
pipe_info->transfer_size,
read_pipe_completion, pipe_info);
if (pipe_info->state != 0) {
purb->status = usb_submit_urb(pipe_info->stream_urb,
GFP_ATOMIC);
if (purb->status)
dev_err(&cam->udev->dev,
"error submitting urb (error=%i)\n",
purb->status);
} else
DBG("read pipe complete state 0\n");
}
static int zr364xx_start_readpipe(struct zr364xx_camera *cam)
{
int pipe;
int retval;
struct zr364xx_pipeinfo *pipe_info = cam->pipe;
pipe = usb_rcvbulkpipe(cam->udev, cam->read_endpoint);
DBG("%s: start pipe IN x%x\n", __func__, cam->read_endpoint);
pipe_info->state = 1;
pipe_info->err_count = 0;
pipe_info->stream_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!pipe_info->stream_urb) {
dev_err(&cam->udev->dev, "ReadStream: Unable to alloc URB\n");
return -ENOMEM;
}
usb_fill_bulk_urb(pipe_info->stream_urb, cam->udev,
pipe,
pipe_info->transfer_buffer,
pipe_info->transfer_size,
read_pipe_completion, pipe_info);
DBG("submitting URB %p\n", pipe_info->stream_urb);
retval = usb_submit_urb(pipe_info->stream_urb, GFP_KERNEL);
if (retval) {
printk(KERN_ERR KBUILD_MODNAME ": start read pipe failed\n");
return retval;
}
return 0;
}
static void zr364xx_stop_readpipe(struct zr364xx_camera *cam)
{
struct zr364xx_pipeinfo *pipe_info;
if (cam == NULL) {
printk(KERN_ERR KBUILD_MODNAME ": invalid device\n");
return;
}
DBG("stop read pipe\n");
pipe_info = cam->pipe;
if (pipe_info) {
if (pipe_info->state != 0)
pipe_info->state = 0;
if (pipe_info->stream_urb) {
usb_kill_urb(pipe_info->stream_urb);
usb_free_urb(pipe_info->stream_urb);
pipe_info->stream_urb = NULL;
}
}
return;
}
static int zr364xx_start_acquire(struct zr364xx_camera *cam)
{
int j;
DBG("start acquire\n");
cam->last_frame = -1;
cam->cur_frame = 0;
for (j = 0; j < FRAMES; j++) {
cam->buffer.frame[j].ulState = ZR364XX_READ_IDLE;
cam->buffer.frame[j].cur_size = 0;
}
cam->b_acquire = 1;
return 0;
}
static inline int zr364xx_stop_acquire(struct zr364xx_camera *cam)
{
cam->b_acquire = 0;
return 0;
}
static int zr364xx_vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct zr364xx_camera *cam = video_drvdata(file);
int j;
int res;
DBG("%s\n", __func__);
if (cam->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_err(&cam->udev->dev, "invalid fh type0\n");
return -EINVAL;
}
if (cam->type != type) {
dev_err(&cam->udev->dev, "invalid fh type1\n");
return -EINVAL;
}
if (!res_get(cam)) {
dev_err(&cam->udev->dev, "stream busy\n");
return -EBUSY;
}
cam->last_frame = -1;
cam->cur_frame = 0;
cam->frame_count = 0;
for (j = 0; j < FRAMES; j++) {
cam->buffer.frame[j].ulState = ZR364XX_READ_IDLE;
cam->buffer.frame[j].cur_size = 0;
}
res = videobuf_streamon(&cam->vb_vidq);
if (res == 0) {
zr364xx_start_acquire(cam);
} else {
res_free(cam);
}
return res;
}
static int zr364xx_vidioc_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
int res;
struct zr364xx_camera *cam = video_drvdata(file);
DBG("%s\n", __func__);
if (cam->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_err(&cam->udev->dev, "invalid fh type0\n");
return -EINVAL;
}
if (cam->type != type) {
dev_err(&cam->udev->dev, "invalid fh type1\n");
return -EINVAL;
}
zr364xx_stop_acquire(cam);
res = videobuf_streamoff(&cam->vb_vidq);
if (res < 0)
return res;
res_free(cam);
return 0;
}
static int zr364xx_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct zr364xx_camera *cam = video_drvdata(file);
struct usb_device *udev = cam->udev;
int i, err;
DBG("%s\n", __func__);
mutex_lock(&cam->open_lock);
if (cam->users) {
err = -EBUSY;
goto out;
}
for (i = 0; init[cam->method][i].size != -1; i++) {
err =
send_control_msg(udev, 1, init[cam->method][i].value,
0, init[cam->method][i].bytes,
init[cam->method][i].size);
if (err < 0) {
dev_err(&cam->udev->dev,
"error during open sequence: %d\n", i);
goto out;
}
}
cam->skip = 2;
cam->users++;
file->private_data = vdev;
cam->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
cam->fmt = formats;
videobuf_queue_vmalloc_init(&cam->vb_vidq, &zr364xx_video_qops,
NULL, &cam->slock,
cam->type,
V4L2_FIELD_NONE,
sizeof(struct zr364xx_buffer), cam, NULL);
mdelay(100);
err = 0;
out:
mutex_unlock(&cam->open_lock);
DBG("%s: %d\n", __func__, err);
return err;
}
static void zr364xx_destroy(struct zr364xx_camera *cam)
{
unsigned long i;
if (!cam) {
printk(KERN_ERR KBUILD_MODNAME ", %s: no device\n", __func__);
return;
}
mutex_lock(&cam->open_lock);
if (cam->vdev)
video_unregister_device(cam->vdev);
cam->vdev = NULL;
if (cam->b_acquire)
zr364xx_stop_acquire(cam);
zr364xx_stop_readpipe(cam);
for (i = 0; i < FRAMES; i++) {
if (cam->buffer.frame[i].lpvbits) {
DBG("vfree %p\n", cam->buffer.frame[i].lpvbits);
vfree(cam->buffer.frame[i].lpvbits);
}
cam->buffer.frame[i].lpvbits = NULL;
}
kfree(cam->pipe->transfer_buffer);
cam->pipe->transfer_buffer = NULL;
mutex_unlock(&cam->open_lock);
kfree(cam);
cam = NULL;
}
static int zr364xx_release(struct file *file)
{
struct zr364xx_camera *cam;
struct usb_device *udev;
int i, err;
DBG("%s\n", __func__);
cam = video_drvdata(file);
if (!cam)
return -ENODEV;
mutex_lock(&cam->open_lock);
udev = cam->udev;
if (res_check(cam)) {
if (cam->b_acquire)
zr364xx_stop_acquire(cam);
videobuf_streamoff(&cam->vb_vidq);
res_free(cam);
}
cam->users--;
file->private_data = NULL;
for (i = 0; i < 2; i++) {
err =
send_control_msg(udev, 1, init[cam->method][i].value,
0, init[cam->method][i].bytes,
init[cam->method][i].size);
if (err < 0) {
dev_err(&udev->dev, "error during release sequence\n");
goto out;
}
}
mdelay(100);
err = 0;
out:
mutex_unlock(&cam->open_lock);
return err;
}
static int zr364xx_mmap(struct file *file, struct vm_area_struct *vma)
{
struct zr364xx_camera *cam = video_drvdata(file);
int ret;
if (cam == NULL) {
DBG("%s: cam == NULL\n", __func__);
return -ENODEV;
}
DBG("mmap called, vma=0x%08lx\n", (unsigned long)vma);
ret = videobuf_mmap_mapper(&cam->vb_vidq, vma);
DBG("vma start=0x%08lx, size=%ld, ret=%d\n",
(unsigned long)vma->vm_start,
(unsigned long)vma->vm_end - (unsigned long)vma->vm_start, ret);
return ret;
}
static unsigned int zr364xx_poll(struct file *file,
struct poll_table_struct *wait)
{
struct zr364xx_camera *cam = video_drvdata(file);
struct videobuf_queue *q = &cam->vb_vidq;
_DBG("%s\n", __func__);
if (cam->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return POLLERR;
return videobuf_poll_stream(file, q, wait);
}
static int zr364xx_board_init(struct zr364xx_camera *cam)
{
struct zr364xx_pipeinfo *pipe = cam->pipe;
unsigned long i;
DBG("board init: %p\n", cam);
memset(pipe, 0, sizeof(*pipe));
pipe->cam = cam;
pipe->transfer_size = BUFFER_SIZE;
pipe->transfer_buffer = kzalloc(pipe->transfer_size,
GFP_KERNEL);
if (pipe->transfer_buffer == NULL) {
DBG("out of memory!\n");
return -ENOMEM;
}
cam->b_acquire = 0;
cam->frame_count = 0;
for (i = 0; i < FRAMES; i++) {
cam->buffer.frame[i].lpvbits = vmalloc(MAX_FRAME_SIZE);
DBG("valloc %p, idx %lu, pdata %p\n",
&cam->buffer.frame[i], i,
cam->buffer.frame[i].lpvbits);
if (cam->buffer.frame[i].lpvbits == NULL) {
printk(KERN_INFO KBUILD_MODNAME ": out of memory. "
"Using less frames\n");
break;
}
}
if (i == 0) {
printk(KERN_INFO KBUILD_MODNAME ": out of memory. Aborting\n");
kfree(cam->pipe->transfer_buffer);
cam->pipe->transfer_buffer = NULL;
return -ENOMEM;
} else
cam->buffer.dwFrames = i;
for (i = 0; i < FRAMES; i++) {
cam->buffer.frame[i].ulState = ZR364XX_READ_IDLE;
cam->buffer.frame[i].cur_size = 0;
}
cam->cur_frame = 0;
cam->last_frame = -1;
zr364xx_start_readpipe(cam);
DBG(": board initialized\n");
return 0;
}
static int zr364xx_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct zr364xx_camera *cam = NULL;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int err;
int i;
DBG("probing...\n");
dev_info(&intf->dev, DRIVER_DESC " compatible webcam plugged\n");
dev_info(&intf->dev, "model %04x:%04x detected\n",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
cam = kzalloc(sizeof(struct zr364xx_camera), GFP_KERNEL);
if (cam == NULL) {
dev_err(&udev->dev, "cam: out of memory !\n");
return -ENOMEM;
}
cam->method = id->driver_info;
cam->vdev = video_device_alloc();
if (cam->vdev == NULL) {
dev_err(&udev->dev, "cam->vdev: out of memory !\n");
kfree(cam);
cam = NULL;
return -ENOMEM;
}
memcpy(cam->vdev, &zr364xx_template, sizeof(zr364xx_template));
cam->vdev->parent = &intf->dev;
video_set_drvdata(cam->vdev, cam);
if (debug)
cam->vdev->debug = V4L2_DEBUG_IOCTL | V4L2_DEBUG_IOCTL_ARG;
cam->udev = udev;
switch (mode) {
case 1:
dev_info(&udev->dev, "160x120 mode selected\n");
cam->width = 160;
cam->height = 120;
break;
case 2:
dev_info(&udev->dev, "640x480 mode selected\n");
cam->width = 640;
cam->height = 480;
break;
default:
dev_info(&udev->dev, "320x240 mode selected\n");
cam->width = 320;
cam->height = 240;
break;
}
m0d1[0] = mode;
m1[2].value = 0xf000 + mode;
m2[1].value = 0xf000 + mode;
if (cam->method == METHOD3) {
switch (mode) {
case 1:
m2[1].value = 0xf000 + 4;
break;
case 2:
m2[1].value = 0xf000 + 0;
break;
default:
m2[1].value = 0xf000 + 1;
break;
}
}
header2[437] = cam->height / 256;
header2[438] = cam->height % 256;
header2[439] = cam->width / 256;
header2[440] = cam->width % 256;
cam->users = 0;
cam->nb = 0;
cam->mode.brightness = 64;
mutex_init(&cam->lock);
mutex_init(&cam->open_lock);
DBG("dev: %p, udev %p interface %p\n", cam, cam->udev, intf);
iface_desc = intf->cur_altsetting;
DBG("num endpoints %d\n", iface_desc->desc.bNumEndpoints);
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (!cam->read_endpoint && usb_endpoint_is_bulk_in(endpoint)) {
cam->read_endpoint = endpoint->bEndpointAddress;
}
}
if (!cam->read_endpoint) {
dev_err(&intf->dev, "Could not find bulk-in endpoint\n");
video_device_release(cam->vdev);
kfree(cam);
cam = NULL;
return -ENOMEM;
}
INIT_LIST_HEAD(&cam->vidq.active);
cam->vidq.cam = cam;
err = video_register_device(cam->vdev, VFL_TYPE_GRABBER, -1);
if (err) {
dev_err(&udev->dev, "video_register_device failed\n");
video_device_release(cam->vdev);
kfree(cam);
cam = NULL;
return err;
}
usb_set_intfdata(intf, cam);
err = zr364xx_board_init(cam);
if (err) {
spin_lock_init(&cam->slock);
return err;
}
spin_lock_init(&cam->slock);
dev_info(&udev->dev, DRIVER_DESC " controlling device %s\n",
video_device_node_name(cam->vdev));
return 0;
}
static void zr364xx_disconnect(struct usb_interface *intf)
{
struct zr364xx_camera *cam = usb_get_intfdata(intf);
videobuf_mmap_free(&cam->vb_vidq);
usb_set_intfdata(intf, NULL);
dev_info(&intf->dev, DRIVER_DESC " webcam unplugged\n");
zr364xx_destroy(cam);
}
static int __init zr364xx_init(void)
{
int retval;
retval = usb_register(&zr364xx_driver);
if (retval)
printk(KERN_ERR KBUILD_MODNAME ": usb_register failed!\n");
else
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_DESC "\n");
return retval;
}
static void __exit zr364xx_exit(void)
{
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_DESC " module unloaded\n");
usb_deregister(&zr364xx_driver);
}
