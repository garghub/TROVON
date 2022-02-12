static struct mmal_fmt *get_format(struct v4l2_format *f)
{
struct mmal_fmt *fmt;
unsigned int k;
for (k = 0; k < ARRAY_SIZE(formats); k++) {
fmt = &formats[k];
if (fmt->fourcc == f->fmt.pix.pixelformat)
return fmt;
}
return NULL;
}
static int queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_ctxs[])
{
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vq);
unsigned long size;
if (!dev->capture.port) {
v4l2_err(&dev->v4l2_dev,
"%s: capture port not configured\n", __func__);
return -EINVAL;
}
size = dev->capture.port->current_buffer.size;
if (size == 0) {
v4l2_err(&dev->v4l2_dev,
"%s: capture port buffer size is zero\n", __func__);
return -EINVAL;
}
if (*nbuffers < (dev->capture.port->current_buffer.num + 2))
*nbuffers = (dev->capture.port->current_buffer.num + 2);
*nplanes = 1;
sizes[0] = size;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev, "%s: dev:%p\n",
__func__, dev);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
unsigned long size;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev, "%s: dev:%p\n",
__func__, dev);
BUG_ON(!dev->capture.port);
BUG_ON(!dev->capture.fmt);
size = dev->capture.stride * dev->capture.height;
if (vb2_plane_size(vb, 0) < size) {
v4l2_err(&dev->v4l2_dev,
"%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
return 0;
}
static inline bool is_capturing(struct bm2835_mmal_dev *dev)
{
return dev->capture.camera_port ==
&dev->
component[MMAL_COMPONENT_CAMERA]->output[MMAL_CAMERA_PORT_CAPTURE];
}
static void buffer_cb(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_port *port,
int status,
struct mmal_buffer *buf,
unsigned long length, u32 mmal_flags, s64 dts, s64 pts)
{
struct bm2835_mmal_dev *dev = port->cb_ctx;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s: status:%d, buf:%p, length:%lu, flags %u, pts %lld\n",
__func__, status, buf, length, mmal_flags, pts);
if (status != 0) {
if (buf) {
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
return;
} else if (length == 0) {
if (buf) {
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
pr_debug("Empty buffer");
} else if (dev->capture.frame_count) {
if (is_capturing(dev)) {
pr_debug("Grab another frame");
vchiq_mmal_port_parameter_set(
instance,
dev->capture.
camera_port,
MMAL_PARAMETER_CAPTURE,
&dev->capture.
frame_count,
sizeof(dev->capture.frame_count));
}
} else {
complete(&dev->capture.frame_cmplt);
}
} else {
if (dev->capture.frame_count) {
if (dev->capture.vc_start_timestamp != -1 &&
pts != 0) {
struct timeval timestamp;
s64 runtime_us = pts -
dev->capture.vc_start_timestamp;
u32 div = 0;
u32 rem = 0;
div =
div_u64_rem(runtime_us, USEC_PER_SEC, &rem);
timestamp.tv_sec =
dev->capture.kernel_start_ts.tv_sec + div;
timestamp.tv_usec =
dev->capture.kernel_start_ts.tv_usec + rem;
if (timestamp.tv_usec >=
USEC_PER_SEC) {
timestamp.tv_sec++;
timestamp.tv_usec -=
USEC_PER_SEC;
}
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Convert start time %d.%06d and %llu "
"with offset %llu to %d.%06d\n",
(int)dev->capture.kernel_start_ts.
tv_sec,
(int)dev->capture.kernel_start_ts.
tv_usec,
dev->capture.vc_start_timestamp, pts,
(int)timestamp.tv_sec,
(int)timestamp.tv_usec);
buf->vb.vb2_buf.timestamp = timestamp.tv_sec * 1000000000ULL +
timestamp.tv_usec * 1000ULL;
} else {
buf->vb.vb2_buf.timestamp = ktime_get_ns();
}
vb2_set_plane_payload(&buf->vb.vb2_buf, 0, length);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_DONE);
if (mmal_flags & MMAL_BUFFER_HEADER_FLAG_EOS &&
is_capturing(dev)) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Grab another frame as buffer has EOS");
vchiq_mmal_port_parameter_set(
instance,
dev->capture.
camera_port,
MMAL_PARAMETER_CAPTURE,
&dev->capture.
frame_count,
sizeof(dev->capture.frame_count));
}
} else {
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
complete(&dev->capture.frame_cmplt);
}
}
}
static int enable_camera(struct bm2835_mmal_dev *dev)
{
int ret;
if (!dev->camera_use_count) {
ret = vchiq_mmal_port_parameter_set(
dev->instance,
&dev->component[MMAL_COMPONENT_CAMERA]->control,
MMAL_PARAMETER_CAMERA_NUM, &dev->camera_num,
sizeof(dev->camera_num));
if (ret < 0) {
v4l2_err(&dev->v4l2_dev,
"Failed setting camera num, ret %d\n", ret);
return -EINVAL;
}
ret = vchiq_mmal_component_enable(
dev->instance,
dev->component[MMAL_COMPONENT_CAMERA]);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev,
"Failed enabling camera, ret %d\n", ret);
return -EINVAL;
}
}
dev->camera_use_count++;
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev, "enabled camera (refcount %d)\n",
dev->camera_use_count);
return 0;
}
static int disable_camera(struct bm2835_mmal_dev *dev)
{
int ret;
if (!dev->camera_use_count) {
v4l2_err(&dev->v4l2_dev,
"Disabled the camera when already disabled\n");
return -EINVAL;
}
dev->camera_use_count--;
if (!dev->camera_use_count) {
unsigned int i = 0xFFFFFFFF;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Disabling camera\n");
ret =
vchiq_mmal_component_disable(
dev->instance,
dev->component[MMAL_COMPONENT_CAMERA]);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev,
"Failed disabling camera, ret %d\n", ret);
return -EINVAL;
}
vchiq_mmal_port_parameter_set(
dev->instance,
&dev->component[MMAL_COMPONENT_CAMERA]->control,
MMAL_PARAMETER_CAMERA_NUM, &i,
sizeof(i));
}
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Camera refcount now %d\n", dev->camera_use_count);
return 0;
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vb2 = to_vb2_v4l2_buffer(vb);
struct mmal_buffer *buf = container_of(vb2, struct mmal_buffer, vb);
int ret;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s: dev:%p buf:%p\n", __func__, dev, buf);
buf->buffer = vb2_plane_vaddr(&buf->vb.vb2_buf, 0);
buf->buffer_size = vb2_plane_size(&buf->vb.vb2_buf, 0);
ret = vchiq_mmal_submit_buffer(dev->instance, dev->capture.port, buf);
if (ret < 0)
v4l2_err(&dev->v4l2_dev, "%s: error submitting buffer\n",
__func__);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vq);
int ret;
int parameter_size;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev, "%s: dev:%p\n",
__func__, dev);
if (!dev->capture.port)
return -EINVAL;
if (enable_camera(dev) < 0) {
v4l2_err(&dev->v4l2_dev, "Failed to enable camera\n");
return -EINVAL;
}
dev->capture.frame_count = 1;
if (!dev->component[MMAL_COMPONENT_PREVIEW]->enabled)
msleep(300);
if (dev->capture.camera_port != dev->capture.port
&& dev->capture.camera_port) {
ret = vchiq_mmal_port_enable(dev->instance,
dev->capture.camera_port, NULL);
if (ret) {
v4l2_err(&dev->v4l2_dev,
"Failed to enable encode tunnel - error %d\n",
ret);
return -1;
}
}
parameter_size = sizeof(dev->capture.vc_start_timestamp);
if (vchiq_mmal_port_parameter_get(dev->instance,
dev->capture.camera_port,
MMAL_PARAMETER_SYSTEM_TIME,
&dev->capture.vc_start_timestamp,
&parameter_size)) {
v4l2_err(&dev->v4l2_dev,
"Failed to get VC start time - update your VC f/w\n");
dev->capture.vc_start_timestamp = -1;
} else
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Start time %lld size %d\n",
dev->capture.vc_start_timestamp, parameter_size);
v4l2_get_timestamp(&dev->capture.kernel_start_ts);
dev->capture.port->cb_ctx = dev;
ret =
vchiq_mmal_port_enable(dev->instance, dev->capture.port, buffer_cb);
if (ret) {
v4l2_err(&dev->v4l2_dev,
"Failed to enable capture port - error %d. "
"Disabling camera port again\n", ret);
vchiq_mmal_port_disable(dev->instance,
dev->capture.camera_port);
if (disable_camera(dev) < 0) {
v4l2_err(&dev->v4l2_dev, "Failed to disable camera\n");
return -EINVAL;
}
return -1;
}
vchiq_mmal_port_parameter_set(dev->instance,
dev->capture.camera_port,
MMAL_PARAMETER_CAPTURE,
&dev->capture.frame_count,
sizeof(dev->capture.frame_count));
return 0;
}
static void stop_streaming(struct vb2_queue *vq)
{
int ret;
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vq);
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev, "%s: dev:%p\n",
__func__, dev);
init_completion(&dev->capture.frame_cmplt);
dev->capture.frame_count = 0;
if (!dev->capture.port) {
v4l2_err(&dev->v4l2_dev,
"no capture port - stream not started?\n");
return;
}
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev, "stopping capturing\n");
vchiq_mmal_port_parameter_set(dev->instance,
dev->capture.camera_port,
MMAL_PARAMETER_CAPTURE,
&dev->capture.frame_count,
sizeof(dev->capture.frame_count));
ret = wait_for_completion_timeout(&dev->capture.frame_cmplt, HZ);
if (ret <= 0)
v4l2_err(&dev->v4l2_dev,
"error %d waiting for frame completion\n", ret);
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"disabling connection\n");
ret = vchiq_mmal_port_disable(dev->instance, dev->capture.camera_port);
if (!ret && dev->capture.camera_port != dev->capture.port) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"disabling port\n");
ret = vchiq_mmal_port_disable(dev->instance, dev->capture.port);
} else if (dev->capture.camera_port != dev->capture.port) {
v4l2_err(&dev->v4l2_dev, "port_disable failed, error %d\n",
ret);
}
if (disable_camera(dev) < 0)
v4l2_err(&dev->v4l2_dev, "Failed to disable camera\n");
}
static void bm2835_mmal_lock(struct vb2_queue *vq)
{
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vq);
mutex_lock(&dev->mutex);
}
static void bm2835_mmal_unlock(struct vb2_queue *vq)
{
struct bm2835_mmal_dev *dev = vb2_get_drv_priv(vq);
mutex_unlock(&dev->mutex);
}
static int set_overlay_params(struct bm2835_mmal_dev *dev,
struct vchiq_mmal_port *port)
{
struct mmal_parameter_displayregion prev_config = {
.set = MMAL_DISPLAY_SET_LAYER | MMAL_DISPLAY_SET_ALPHA |
MMAL_DISPLAY_SET_DEST_RECT | MMAL_DISPLAY_SET_FULLSCREEN,
.layer = PREVIEW_LAYER,
.alpha = dev->overlay.global_alpha,
.fullscreen = 0,
.dest_rect = {
.x = dev->overlay.w.left,
.y = dev->overlay.w.top,
.width = dev->overlay.w.width,
.height = dev->overlay.w.height,
},
};
return vchiq_mmal_port_parameter_set(dev->instance, port,
MMAL_PARAMETER_DISPLAYREGION,
&prev_config, sizeof(prev_config));
}
static int vidioc_enum_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct mmal_fmt *fmt;
if (f->index >= ARRAY_SIZE(formats))
return -EINVAL;
fmt = &formats[f->index];
strlcpy(f->description, fmt->name, sizeof(f->description));
f->pixelformat = fmt->fourcc;
f->flags = fmt->flags;
return 0;
}
static int vidioc_g_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
f->fmt.win = dev->overlay;
return 0;
}
static int vidioc_try_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
f->fmt.win.field = V4L2_FIELD_NONE;
f->fmt.win.chromakey = 0;
f->fmt.win.clips = NULL;
f->fmt.win.clipcount = 0;
f->fmt.win.bitmap = NULL;
v4l_bound_align_image(&f->fmt.win.w.width, MIN_WIDTH, dev->max_width, 1,
&f->fmt.win.w.height, MIN_HEIGHT, dev->max_height,
1, 0);
v4l_bound_align_image(&f->fmt.win.w.left, MIN_WIDTH, dev->max_width, 1,
&f->fmt.win.w.top, MIN_HEIGHT, dev->max_height,
1, 0);
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Overlay: Now w/h %dx%d l/t %dx%d\n",
f->fmt.win.w.width, f->fmt.win.w.height,
f->fmt.win.w.left, f->fmt.win.w.top);
v4l2_dump_win_format(1,
bcm2835_v4l2_debug,
&dev->v4l2_dev,
&f->fmt.win,
__func__);
return 0;
}
static int vidioc_s_fmt_vid_overlay(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
vidioc_try_fmt_vid_overlay(file, priv, f);
dev->overlay = f->fmt.win;
if (dev->component[MMAL_COMPONENT_PREVIEW]->enabled) {
set_overlay_params(dev,
&dev->component[MMAL_COMPONENT_PREVIEW]->input[0]);
}
return 0;
}
static int vidioc_overlay(struct file *file, void *f, unsigned int on)
{
int ret;
struct bm2835_mmal_dev *dev = video_drvdata(file);
struct vchiq_mmal_port *src;
struct vchiq_mmal_port *dst;
if ((on && dev->component[MMAL_COMPONENT_PREVIEW]->enabled) ||
(!on && !dev->component[MMAL_COMPONENT_PREVIEW]->enabled))
return 0;
src =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_PREVIEW];
if (!on) {
ret = vchiq_mmal_port_disable(dev->instance, src);
if (!ret)
ret =
vchiq_mmal_port_connect_tunnel(dev->instance, src,
NULL);
if (ret >= 0)
ret = vchiq_mmal_component_disable(
dev->instance,
dev->component[MMAL_COMPONENT_PREVIEW]);
disable_camera(dev);
return ret;
}
dst = &dev->component[MMAL_COMPONENT_PREVIEW]->input[0];
ret = vchiq_mmal_port_set_format(dev->instance, src);
if (ret < 0)
goto error;
ret = set_overlay_params(dev, dst);
if (ret < 0)
goto error;
if (enable_camera(dev) < 0)
goto error;
ret = vchiq_mmal_component_enable(
dev->instance,
dev->component[MMAL_COMPONENT_PREVIEW]);
if (ret < 0)
goto error;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev, "connecting %p to %p\n",
src, dst);
ret = vchiq_mmal_port_connect_tunnel(dev->instance, src, dst);
if (!ret)
ret = vchiq_mmal_port_enable(dev->instance, src, NULL);
error:
return ret;
}
static int vidioc_g_fbuf(struct file *file, void *fh,
struct v4l2_framebuffer *a)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
struct vchiq_mmal_port *preview_port =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_PREVIEW];
a->capability = V4L2_FBUF_CAP_EXTERNOVERLAY |
V4L2_FBUF_CAP_GLOBAL_ALPHA;
a->flags = V4L2_FBUF_FLAG_OVERLAY;
a->fmt.width = preview_port->es.video.width;
a->fmt.height = preview_port->es.video.height;
a->fmt.pixelformat = V4L2_PIX_FMT_YUV420;
a->fmt.bytesperline = preview_port->es.video.width;
a->fmt.sizeimage = (preview_port->es.video.width *
preview_port->es.video.height * 3) >> 1;
a->fmt.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
if (inp->index != 0)
return -EINVAL;
inp->type = V4L2_INPUT_TYPE_CAMERA;
sprintf(inp->name, "Camera %u", inp->index);
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
u32 major;
u32 minor;
vchiq_mmal_version(dev->instance, &major, &minor);
strcpy(cap->driver, "bm2835 mmal");
snprintf(cap->card, sizeof(cap->card), "mmal service %d.%d",
major, minor);
snprintf(cap->bus_info, sizeof(cap->bus_info),
"platform:%s", dev->v4l2_dev.name);
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OVERLAY |
V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct mmal_fmt *fmt;
if (f->index >= ARRAY_SIZE(formats))
return -EINVAL;
fmt = &formats[f->index];
strlcpy(f->description, fmt->name, sizeof(f->description));
f->pixelformat = fmt->fourcc;
f->flags = fmt->flags;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
f->fmt.pix.width = dev->capture.width;
f->fmt.pix.height = dev->capture.height;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.pixelformat = dev->capture.fmt->fourcc;
f->fmt.pix.bytesperline = dev->capture.stride;
f->fmt.pix.sizeimage = dev->capture.buffersize;
if (dev->capture.fmt->fourcc == V4L2_PIX_FMT_RGB24)
f->fmt.pix.colorspace = V4L2_COLORSPACE_SRGB;
else if (dev->capture.fmt->fourcc == V4L2_PIX_FMT_JPEG)
f->fmt.pix.colorspace = V4L2_COLORSPACE_JPEG;
else
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.priv = 0;
v4l2_dump_pix_format(1, bcm2835_v4l2_debug, &dev->v4l2_dev, &f->fmt.pix,
__func__);
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
struct mmal_fmt *mfmt;
mfmt = get_format(f);
if (!mfmt) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Fourcc format (0x%08x) unknown.\n",
f->fmt.pix.pixelformat);
f->fmt.pix.pixelformat = formats[0].fourcc;
mfmt = get_format(f);
}
f->fmt.pix.field = V4L2_FIELD_NONE;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Clipping/aligning %dx%d format %08X\n",
f->fmt.pix.width, f->fmt.pix.height, f->fmt.pix.pixelformat);
v4l_bound_align_image(&f->fmt.pix.width, MIN_WIDTH, dev->max_width, 1,
&f->fmt.pix.height, MIN_HEIGHT, dev->max_height,
1, 0);
f->fmt.pix.bytesperline = f->fmt.pix.width * mfmt->ybbp;
f->fmt.pix.sizeimage = ((f->fmt.pix.height + 15) & ~15) *
(((f->fmt.pix.width + 31) & ~31) * mfmt->depth) >> 3;
if ((mfmt->flags & V4L2_FMT_FLAG_COMPRESSED) &&
f->fmt.pix.sizeimage < MIN_BUFFER_SIZE)
f->fmt.pix.sizeimage = MIN_BUFFER_SIZE;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_RGB24)
f->fmt.pix.colorspace = V4L2_COLORSPACE_SRGB;
else if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_JPEG)
f->fmt.pix.colorspace = V4L2_COLORSPACE_JPEG;
else
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
f->fmt.pix.priv = 0;
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Now %dx%d format %08X\n",
f->fmt.pix.width, f->fmt.pix.height, f->fmt.pix.pixelformat);
v4l2_dump_pix_format(1, bcm2835_v4l2_debug, &dev->v4l2_dev, &f->fmt.pix,
__func__);
return 0;
}
static int mmal_setup_components(struct bm2835_mmal_dev *dev,
struct v4l2_format *f)
{
int ret;
struct vchiq_mmal_port *port = NULL, *camera_port = NULL;
struct vchiq_mmal_component *encode_component = NULL;
struct mmal_fmt *mfmt = get_format(f);
BUG_ON(!mfmt);
if (dev->capture.encode_component) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"vid_cap - disconnect previous tunnel\n");
vchiq_mmal_port_connect_tunnel(dev->instance,
dev->capture.camera_port, NULL);
dev->capture.camera_port = NULL;
ret = vchiq_mmal_component_disable(dev->instance,
dev->capture.
encode_component);
if (ret)
v4l2_err(&dev->v4l2_dev,
"Failed to disable encode component %d\n",
ret);
dev->capture.encode_component = NULL;
}
switch (mfmt->mmal_component) {
case MMAL_COMPONENT_CAMERA:
if (f->fmt.pix.width <= max_video_width
&& f->fmt.pix.height <= max_video_height)
camera_port = port =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_VIDEO];
else
camera_port = port =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_CAPTURE];
break;
case MMAL_COMPONENT_IMAGE_ENCODE:
encode_component = dev->component[MMAL_COMPONENT_IMAGE_ENCODE];
port = &dev->component[MMAL_COMPONENT_IMAGE_ENCODE]->output[0];
camera_port =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_CAPTURE];
break;
case MMAL_COMPONENT_VIDEO_ENCODE:
encode_component = dev->component[MMAL_COMPONENT_VIDEO_ENCODE];
port = &dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->output[0];
camera_port =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_VIDEO];
break;
default:
break;
}
if (!port)
return -EINVAL;
if (encode_component)
camera_port->format.encoding = MMAL_ENCODING_OPAQUE;
else
camera_port->format.encoding = mfmt->mmal;
if (dev->rgb_bgr_swapped) {
if (camera_port->format.encoding == MMAL_ENCODING_RGB24)
camera_port->format.encoding = MMAL_ENCODING_BGR24;
else if (camera_port->format.encoding == MMAL_ENCODING_BGR24)
camera_port->format.encoding = MMAL_ENCODING_RGB24;
}
camera_port->format.encoding_variant = 0;
camera_port->es.video.width = f->fmt.pix.width;
camera_port->es.video.height = f->fmt.pix.height;
camera_port->es.video.crop.x = 0;
camera_port->es.video.crop.y = 0;
camera_port->es.video.crop.width = f->fmt.pix.width;
camera_port->es.video.crop.height = f->fmt.pix.height;
camera_port->es.video.frame_rate.num = 0;
camera_port->es.video.frame_rate.den = 1;
camera_port->es.video.color_space = MMAL_COLOR_SPACE_JPEG_JFIF;
ret = vchiq_mmal_port_set_format(dev->instance, camera_port);
if (!ret
&& camera_port ==
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_VIDEO]) {
bool overlay_enabled =
!!dev->component[MMAL_COMPONENT_PREVIEW]->enabled;
struct vchiq_mmal_port *preview_port =
&dev->component[MMAL_COMPONENT_CAMERA]->
output[MMAL_CAMERA_PORT_PREVIEW];
if (overlay_enabled) {
ret =
vchiq_mmal_port_disable(dev->instance,
preview_port);
if (!ret)
ret =
vchiq_mmal_port_connect_tunnel(
dev->instance,
preview_port,
NULL);
}
preview_port->es.video.width = f->fmt.pix.width;
preview_port->es.video.height = f->fmt.pix.height;
preview_port->es.video.crop.x = 0;
preview_port->es.video.crop.y = 0;
preview_port->es.video.crop.width = f->fmt.pix.width;
preview_port->es.video.crop.height = f->fmt.pix.height;
preview_port->es.video.frame_rate.num =
dev->capture.timeperframe.denominator;
preview_port->es.video.frame_rate.den =
dev->capture.timeperframe.numerator;
ret = vchiq_mmal_port_set_format(dev->instance, preview_port);
if (overlay_enabled) {
ret = vchiq_mmal_port_connect_tunnel(
dev->instance,
preview_port,
&dev->component[MMAL_COMPONENT_PREVIEW]->input[0]);
if (!ret)
ret = vchiq_mmal_port_enable(dev->instance,
preview_port,
NULL);
}
}
if (ret) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"%s failed to set format %dx%d %08X\n", __func__,
f->fmt.pix.width, f->fmt.pix.height,
f->fmt.pix.pixelformat);
dev->capture.port = NULL;
} else {
if (encode_component) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"vid_cap - set up encode comp\n");
camera_port->current_buffer.size =
camera_port->recommended_buffer.size;
camera_port->current_buffer.num =
camera_port->recommended_buffer.num;
ret =
vchiq_mmal_port_connect_tunnel(
dev->instance,
camera_port,
&encode_component->input[0]);
if (ret) {
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev,
"%s failed to create connection\n",
__func__);
dev->capture.port = NULL;
} else {
port->es.video.width = f->fmt.pix.width;
port->es.video.height = f->fmt.pix.height;
port->es.video.crop.x = 0;
port->es.video.crop.y = 0;
port->es.video.crop.width = f->fmt.pix.width;
port->es.video.crop.height = f->fmt.pix.height;
port->es.video.frame_rate.num =
dev->capture.timeperframe.denominator;
port->es.video.frame_rate.den =
dev->capture.timeperframe.numerator;
port->format.encoding = mfmt->mmal;
port->format.encoding_variant = 0;
switch (mfmt->mmal_component) {
case MMAL_COMPONENT_VIDEO_ENCODE:
port->format.bitrate =
dev->capture.encode_bitrate;
break;
case MMAL_COMPONENT_IMAGE_ENCODE:
break;
default:
break;
}
ret = vchiq_mmal_port_set_format(dev->instance,
port);
if (ret)
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev,
"%s failed to set format %dx%d fmt %08X\n",
__func__,
f->fmt.pix.width,
f->fmt.pix.height,
f->fmt.pix.pixelformat
);
}
if (!ret) {
ret = vchiq_mmal_component_enable(
dev->instance,
encode_component);
if (ret) {
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev,
"%s Failed to enable encode components\n",
__func__);
}
}
if (!ret) {
port->current_buffer.num = 1;
port->current_buffer.size =
f->fmt.pix.sizeimage;
if (port->format.encoding ==
MMAL_ENCODING_JPEG) {
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev,
"JPG - buf size now %d was %d\n",
f->fmt.pix.sizeimage,
port->current_buffer.size);
port->current_buffer.size =
(f->fmt.pix.sizeimage <
(100 << 10))
? (100 << 10) : f->fmt.pix.
sizeimage;
}
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev,
"vid_cap - cur_buf.size set to %d\n",
f->fmt.pix.sizeimage);
port->current_buffer.alignment = 0;
}
} else {
camera_port->current_buffer.num = 1;
camera_port->current_buffer.size = f->fmt.pix.sizeimage;
camera_port->current_buffer.alignment = 0;
}
if (!ret) {
dev->capture.fmt = mfmt;
dev->capture.stride = f->fmt.pix.bytesperline;
dev->capture.width = camera_port->es.video.crop.width;
dev->capture.height = camera_port->es.video.crop.height;
dev->capture.buffersize = port->current_buffer.size;
dev->capture.port = port;
dev->capture.camera_port = camera_port;
dev->capture.encode_component = encode_component;
v4l2_dbg(1, bcm2835_v4l2_debug,
&dev->v4l2_dev,
"Set dev->capture.fmt %08X, %dx%d, stride %d, size %d",
port->format.encoding,
dev->capture.width, dev->capture.height,
dev->capture.stride, dev->capture.buffersize);
}
}
return ret;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
struct bm2835_mmal_dev *dev = video_drvdata(file);
struct mmal_fmt *mfmt;
ret = vidioc_try_fmt_vid_cap(file, priv, f);
if (ret) {
v4l2_err(&dev->v4l2_dev,
"vid_cap - vidioc_try_fmt_vid_cap failed\n");
return ret;
}
if (vb2_is_busy(&dev->capture.vb_vidq)) {
v4l2_info(&dev->v4l2_dev, "%s device busy\n", __func__);
return -EBUSY;
}
mfmt = get_format(f);
if (!mfmt) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"Fourcc format (0x%08x) unknown.\n",
f->fmt.pix.pixelformat);
f->fmt.pix.pixelformat = formats[0].fourcc;
mfmt = get_format(f);
}
ret = mmal_setup_components(dev, f);
if (ret != 0) {
v4l2_err(&dev->v4l2_dev,
"%s: failed to setup mmal components: %d\n",
__func__, ret);
ret = -EINVAL;
}
return ret;
}
static int vidioc_enum_framesizes(struct file *file, void *fh,
struct v4l2_frmsizeenum *fsize)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
static const struct v4l2_frmsize_stepwise sizes = {
MIN_WIDTH, 0, 2,
MIN_HEIGHT, 0, 2
};
int i;
if (fsize->index)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fsize->pixel_format)
break;
if (i == ARRAY_SIZE(formats))
return -EINVAL;
fsize->type = V4L2_FRMSIZE_TYPE_STEPWISE;
fsize->stepwise = sizes;
fsize->stepwise.max_width = dev->max_width;
fsize->stepwise.max_height = dev->max_height;
return 0;
}
static int vidioc_enum_frameintervals(struct file *file, void *priv,
struct v4l2_frmivalenum *fival)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
int i;
if (fival->index)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(formats); i++)
if (formats[i].fourcc == fival->pixel_format)
break;
if (i == ARRAY_SIZE(formats))
return -EINVAL;
if (fival->width < MIN_WIDTH || fival->width > dev->max_width ||
fival->height < MIN_HEIGHT || fival->height > dev->max_height)
return -EINVAL;
fival->type = V4L2_FRMIVAL_TYPE_CONTINUOUS;
fival->stepwise.min = tpf_min;
fival->stepwise.max = tpf_max;
fival->stepwise.step = (struct v4l2_fract) {1, 1};
return 0;
}
static int vidioc_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *parm)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
parm->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
parm->parm.capture.timeperframe = dev->capture.timeperframe;
parm->parm.capture.readbuffers = 1;
return 0;
}
static int vidioc_s_parm(struct file *file, void *priv,
struct v4l2_streamparm *parm)
{
struct bm2835_mmal_dev *dev = video_drvdata(file);
struct v4l2_fract tpf;
struct mmal_parameter_rational fps_param;
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
tpf = parm->parm.capture.timeperframe;
tpf = tpf.denominator ? tpf : tpf_default;
tpf = FRACT_CMP(tpf, <, tpf_min) ? tpf_min : tpf;
tpf = FRACT_CMP(tpf, >, tpf_max) ? tpf_max : tpf;
dev->capture.timeperframe = tpf;
parm->parm.capture.timeperframe = tpf;
parm->parm.capture.readbuffers = 1;
parm->parm.capture.capability = V4L2_CAP_TIMEPERFRAME;
fps_param.num = 0;
fps_param.den = 1;
set_framerate_params(dev);
return 0;
}
static int get_num_cameras(struct vchiq_mmal_instance *instance,
unsigned int resolutions[][2], int num_resolutions)
{
int ret;
struct vchiq_mmal_component *cam_info_component;
struct mmal_parameter_camera_info_t cam_info = {0};
int param_size = sizeof(cam_info);
int i;
ret = vchiq_mmal_component_init(instance, "camera_info",
&cam_info_component);
if (ret < 0)
return 1;
if (vchiq_mmal_port_parameter_get(instance,
&cam_info_component->control,
MMAL_PARAMETER_CAMERA_INFO,
&cam_info,
&param_size)) {
pr_info("Failed to get camera info\n");
}
for (i = 0;
i < min_t(unsigned int, cam_info.num_cameras, num_resolutions);
i++) {
resolutions[i][0] = cam_info.cameras[i].max_width;
resolutions[i][1] = cam_info.cameras[i].max_height;
}
vchiq_mmal_component_finalise(instance,
cam_info_component);
return cam_info.num_cameras;
}
static int set_camera_parameters(struct vchiq_mmal_instance *instance,
struct vchiq_mmal_component *camera,
struct bm2835_mmal_dev *dev)
{
int ret;
struct mmal_parameter_camera_config cam_config = {
.max_stills_w = dev->max_width,
.max_stills_h = dev->max_height,
.stills_yuv422 = 1,
.one_shot_stills = 1,
.max_preview_video_w = (max_video_width > 1920) ?
max_video_width : 1920,
.max_preview_video_h = (max_video_height > 1088) ?
max_video_height : 1088,
.num_preview_video_frames = 3,
.stills_capture_circular_buffer_height = 0,
.fast_preview_resume = 0,
.use_stc_timestamp = MMAL_PARAM_TIMESTAMP_MODE_RAW_STC
};
ret = vchiq_mmal_port_parameter_set(instance, &camera->control,
MMAL_PARAMETER_CAMERA_CONFIG,
&cam_config, sizeof(cam_config));
return ret;
}
static int __init mmal_init(struct bm2835_mmal_dev *dev)
{
int ret;
struct mmal_es_format_local *format;
u32 bool_true = 1;
u32 supported_encodings[MAX_SUPPORTED_ENCODINGS];
int param_size;
struct vchiq_mmal_component *camera;
ret = vchiq_mmal_init(&dev->instance);
if (ret < 0)
return ret;
ret = vchiq_mmal_component_init(dev->instance, "ril.camera",
&dev->component[MMAL_COMPONENT_CAMERA]);
if (ret < 0)
goto unreg_mmal;
camera = dev->component[MMAL_COMPONENT_CAMERA];
if (camera->outputs < MMAL_CAMERA_PORT_COUNT) {
ret = -EINVAL;
goto unreg_camera;
}
ret = set_camera_parameters(dev->instance,
camera,
dev);
if (ret < 0)
goto unreg_camera;
dev->rgb_bgr_swapped = true;
param_size = sizeof(supported_encodings);
ret = vchiq_mmal_port_parameter_get(dev->instance,
&camera->output[MMAL_CAMERA_PORT_CAPTURE],
MMAL_PARAMETER_SUPPORTED_ENCODINGS,
&supported_encodings,
&param_size);
if (ret == 0) {
int i;
for (i = 0; i < param_size / sizeof(u32); i++) {
if (supported_encodings[i] == MMAL_ENCODING_BGR24) {
break;
}
if (supported_encodings[i] == MMAL_ENCODING_RGB24) {
dev->rgb_bgr_swapped = false;
break;
}
}
}
format = &camera->output[MMAL_CAMERA_PORT_PREVIEW].format;
format->encoding = MMAL_ENCODING_OPAQUE;
format->encoding_variant = MMAL_ENCODING_I420;
format->es->video.width = 1024;
format->es->video.height = 768;
format->es->video.crop.x = 0;
format->es->video.crop.y = 0;
format->es->video.crop.width = 1024;
format->es->video.crop.height = 768;
format->es->video.frame_rate.num = 0;
format->es->video.frame_rate.den = 1;
format = &camera->output[MMAL_CAMERA_PORT_VIDEO].format;
format->encoding = MMAL_ENCODING_OPAQUE;
format->encoding_variant = MMAL_ENCODING_I420;
format->es->video.width = 1024;
format->es->video.height = 768;
format->es->video.crop.x = 0;
format->es->video.crop.y = 0;
format->es->video.crop.width = 1024;
format->es->video.crop.height = 768;
format->es->video.frame_rate.num = 0;
format->es->video.frame_rate.den = 1;
vchiq_mmal_port_parameter_set(dev->instance,
&camera->output[MMAL_CAMERA_PORT_VIDEO],
MMAL_PARAMETER_NO_IMAGE_PADDING,
&bool_true, sizeof(bool_true));
format = &camera->output[MMAL_CAMERA_PORT_CAPTURE].format;
format->encoding = MMAL_ENCODING_OPAQUE;
format->es->video.width = 2592;
format->es->video.height = 1944;
format->es->video.crop.x = 0;
format->es->video.crop.y = 0;
format->es->video.crop.width = 2592;
format->es->video.crop.height = 1944;
format->es->video.frame_rate.num = 0;
format->es->video.frame_rate.den = 1;
dev->capture.width = format->es->video.width;
dev->capture.height = format->es->video.height;
dev->capture.fmt = &formats[0];
dev->capture.encode_component = NULL;
dev->capture.timeperframe = tpf_default;
dev->capture.enc_profile = V4L2_MPEG_VIDEO_H264_PROFILE_HIGH;
dev->capture.enc_level = V4L2_MPEG_VIDEO_H264_LEVEL_4_0;
vchiq_mmal_port_parameter_set(dev->instance,
&camera->output[MMAL_CAMERA_PORT_CAPTURE],
MMAL_PARAMETER_NO_IMAGE_PADDING,
&bool_true, sizeof(bool_true));
ret = vchiq_mmal_component_init(
dev->instance, "ril.video_render",
&dev->component[MMAL_COMPONENT_PREVIEW]);
if (ret < 0)
goto unreg_camera;
if (dev->component[MMAL_COMPONENT_PREVIEW]->inputs < 1) {
ret = -EINVAL;
pr_debug("too few input ports %d needed %d\n",
dev->component[MMAL_COMPONENT_PREVIEW]->inputs, 1);
goto unreg_preview;
}
ret = vchiq_mmal_component_init(
dev->instance, "ril.image_encode",
&dev->component[MMAL_COMPONENT_IMAGE_ENCODE]);
if (ret < 0)
goto unreg_preview;
if (dev->component[MMAL_COMPONENT_IMAGE_ENCODE]->inputs < 1) {
ret = -EINVAL;
v4l2_err(&dev->v4l2_dev, "too few input ports %d needed %d\n",
dev->component[MMAL_COMPONENT_IMAGE_ENCODE]->inputs,
1);
goto unreg_image_encoder;
}
ret = vchiq_mmal_component_init(dev->instance, "ril.video_encode",
&dev->
component[MMAL_COMPONENT_VIDEO_ENCODE]);
if (ret < 0)
goto unreg_image_encoder;
if (dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->inputs < 1) {
ret = -EINVAL;
v4l2_err(&dev->v4l2_dev, "too few input ports %d needed %d\n",
dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->inputs,
1);
goto unreg_vid_encoder;
}
{
struct vchiq_mmal_port *encoder_port =
&dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->output[0];
encoder_port->format.encoding = MMAL_ENCODING_H264;
ret = vchiq_mmal_port_set_format(dev->instance,
encoder_port);
}
{
unsigned int enable = 1;
vchiq_mmal_port_parameter_set(
dev->instance,
&dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->control,
MMAL_PARAMETER_VIDEO_IMMUTABLE_INPUT,
&enable, sizeof(enable));
vchiq_mmal_port_parameter_set(dev->instance,
&dev->component[MMAL_COMPONENT_VIDEO_ENCODE]->control,
MMAL_PARAMETER_MINIMISE_FRAGMENTATION,
&enable,
sizeof(enable));
}
ret = bm2835_mmal_set_all_camera_controls(dev);
if (ret < 0)
goto unreg_vid_encoder;
return 0;
unreg_vid_encoder:
pr_err("Cleanup: Destroy video encoder\n");
vchiq_mmal_component_finalise(
dev->instance,
dev->component[MMAL_COMPONENT_VIDEO_ENCODE]);
unreg_image_encoder:
pr_err("Cleanup: Destroy image encoder\n");
vchiq_mmal_component_finalise(
dev->instance,
dev->component[MMAL_COMPONENT_IMAGE_ENCODE]);
unreg_preview:
pr_err("Cleanup: Destroy video render\n");
vchiq_mmal_component_finalise(dev->instance,
dev->component[MMAL_COMPONENT_PREVIEW]);
unreg_camera:
pr_err("Cleanup: Destroy camera\n");
vchiq_mmal_component_finalise(dev->instance,
dev->component[MMAL_COMPONENT_CAMERA]);
unreg_mmal:
vchiq_mmal_finalise(dev->instance);
return ret;
}
static int __init bm2835_mmal_init_device(struct bm2835_mmal_dev *dev,
struct video_device *vfd)
{
int ret;
*vfd = vdev_template;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->lock = &dev->mutex;
vfd->queue = &dev->capture.vb_vidq;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd,
VFL_TYPE_GRABBER,
video_nr[dev->camera_num]);
if (ret < 0)
return ret;
v4l2_info(vfd->v4l2_dev,
"V4L2 device registered as %s - stills mode > %dx%d\n",
video_device_node_name(vfd),
max_video_width, max_video_height);
return 0;
}
static void bcm2835_cleanup_instance(struct bm2835_mmal_dev *dev)
{
if (!dev)
return;
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->vdev));
video_unregister_device(&dev->vdev);
if (dev->capture.encode_component) {
v4l2_dbg(1, bcm2835_v4l2_debug, &dev->v4l2_dev,
"mmal_exit - disconnect tunnel\n");
vchiq_mmal_port_connect_tunnel(dev->instance,
dev->capture.camera_port, NULL);
vchiq_mmal_component_disable(dev->instance,
dev->capture.encode_component);
}
vchiq_mmal_component_disable(dev->instance,
dev->component[MMAL_COMPONENT_CAMERA]);
vchiq_mmal_component_finalise(dev->instance,
dev->
component[MMAL_COMPONENT_VIDEO_ENCODE]);
vchiq_mmal_component_finalise(dev->instance,
dev->
component[MMAL_COMPONENT_IMAGE_ENCODE]);
vchiq_mmal_component_finalise(dev->instance,
dev->component[MMAL_COMPONENT_PREVIEW]);
vchiq_mmal_component_finalise(dev->instance,
dev->component[MMAL_COMPONENT_CAMERA]);
v4l2_ctrl_handler_free(&dev->ctrl_handler);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
}
static int __init bm2835_mmal_init(void)
{
int ret;
struct bm2835_mmal_dev *dev;
struct vb2_queue *q;
int camera;
unsigned int num_cameras;
struct vchiq_mmal_instance *instance;
unsigned int resolutions[MAX_BCM2835_CAMERAS][2];
int i;
ret = vchiq_mmal_init(&instance);
if (ret < 0)
return ret;
num_cameras = get_num_cameras(instance,
resolutions,
MAX_BCM2835_CAMERAS);
if (num_cameras > MAX_BCM2835_CAMERAS)
num_cameras = MAX_BCM2835_CAMERAS;
for (camera = 0; camera < num_cameras; camera++) {
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto cleanup_gdev;
}
dev->camera_num = camera;
dev->max_width = resolutions[camera][0];
dev->max_height = resolutions[camera][1];
dev->overlay.w.left = 150;
dev->overlay.w.top = 50;
dev->overlay.w.width = 1024;
dev->overlay.w.height = 768;
dev->overlay.clipcount = 0;
dev->overlay.field = V4L2_FIELD_NONE;
dev->overlay.global_alpha = 255;
dev->capture.fmt = &formats[3];
snprintf(dev->v4l2_dev.name, sizeof(dev->v4l2_dev.name),
"%s", BM2835_MMAL_MODULE_NAME);
ret = v4l2_device_register(NULL, &dev->v4l2_dev);
if (ret)
goto free_dev;
ret = bm2835_mmal_init_controls(dev, &dev->ctrl_handler);
if (ret < 0)
goto unreg_dev;
dev->v4l2_dev.ctrl_handler = &dev->ctrl_handler;
dev->instance = instance;
ret = mmal_init(dev);
if (ret < 0)
goto unreg_dev;
q = &dev->capture.vb_vidq;
memset(q, 0, sizeof(*q));
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_READ;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct mmal_buffer);
q->ops = &bm2835_mmal_video_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(q);
if (ret < 0)
goto unreg_dev;
mutex_init(&dev->mutex);
ret = bm2835_mmal_init_device(dev, &dev->vdev);
if (ret < 0)
goto unreg_dev;
ret = mmal_setup_components(dev, &default_v4l2_format);
if (ret < 0) {
v4l2_err(&dev->v4l2_dev,
"%s: could not setup components\n", __func__);
goto unreg_dev;
}
v4l2_info(&dev->v4l2_dev,
"Broadcom 2835 MMAL video capture ver %s loaded.\n",
BM2835_MMAL_VERSION);
gdev[camera] = dev;
}
return 0;
unreg_dev:
v4l2_ctrl_handler_free(&dev->ctrl_handler);
v4l2_device_unregister(&dev->v4l2_dev);
free_dev:
kfree(dev);
cleanup_gdev:
for (i = 0; i < camera; i++) {
bcm2835_cleanup_instance(gdev[i]);
gdev[i] = NULL;
}
pr_info("%s: error %d while loading driver\n",
BM2835_MMAL_MODULE_NAME, ret);
return ret;
}
static void __exit bm2835_mmal_exit(void)
{
int camera;
struct vchiq_mmal_instance *instance = gdev[0]->instance;
for (camera = 0; camera < MAX_BCM2835_CAMERAS; camera++) {
bcm2835_cleanup_instance(gdev[camera]);
gdev[camera] = NULL;
}
vchiq_mmal_finalise(instance);
}
