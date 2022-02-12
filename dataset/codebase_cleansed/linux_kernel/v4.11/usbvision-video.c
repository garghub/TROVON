static inline struct usb_usbvision *cd_to_usbvision(struct device *cd)
{
struct video_device *vdev = to_video_device(cd);
return video_get_drvdata(vdev);
}
static ssize_t show_version(struct device *cd,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%s\n", USBVISION_VERSION_STRING);
}
static ssize_t show_model(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
return sprintf(buf, "%s\n",
usbvision_device_data[usbvision->dev_model].model_string);
}
static ssize_t show_hue(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
s32 val = v4l2_ctrl_g_ctrl(v4l2_ctrl_find(&usbvision->hdl,
V4L2_CID_HUE));
return sprintf(buf, "%d\n", val);
}
static ssize_t show_contrast(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
s32 val = v4l2_ctrl_g_ctrl(v4l2_ctrl_find(&usbvision->hdl,
V4L2_CID_CONTRAST));
return sprintf(buf, "%d\n", val);
}
static ssize_t show_brightness(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
s32 val = v4l2_ctrl_g_ctrl(v4l2_ctrl_find(&usbvision->hdl,
V4L2_CID_BRIGHTNESS));
return sprintf(buf, "%d\n", val);
}
static ssize_t show_saturation(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
s32 val = v4l2_ctrl_g_ctrl(v4l2_ctrl_find(&usbvision->hdl,
V4L2_CID_SATURATION));
return sprintf(buf, "%d\n", val);
}
static ssize_t show_streaming(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
return sprintf(buf, "%s\n",
YES_NO(usbvision->streaming == stream_on ? 1 : 0));
}
static ssize_t show_compression(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
return sprintf(buf, "%s\n",
YES_NO(usbvision->isoc_mode == ISOC_MODE_COMPRESS));
}
static ssize_t show_device_bridge(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct video_device *vdev = to_video_device(cd);
struct usb_usbvision *usbvision = video_get_drvdata(vdev);
return sprintf(buf, "%d\n", usbvision->bridge_type);
}
static void usbvision_create_sysfs(struct video_device *vdev)
{
int res;
if (!vdev)
return;
do {
res = device_create_file(&vdev->dev, &dev_attr_version);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_model);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_hue);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_contrast);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_brightness);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_saturation);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_streaming);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_compression);
if (res < 0)
break;
res = device_create_file(&vdev->dev, &dev_attr_bridge);
if (res >= 0)
return;
} while (0);
dev_err(&vdev->dev, "%s error: %d\n", __func__, res);
}
static void usbvision_remove_sysfs(struct video_device *vdev)
{
if (vdev) {
device_remove_file(&vdev->dev, &dev_attr_version);
device_remove_file(&vdev->dev, &dev_attr_model);
device_remove_file(&vdev->dev, &dev_attr_hue);
device_remove_file(&vdev->dev, &dev_attr_contrast);
device_remove_file(&vdev->dev, &dev_attr_brightness);
device_remove_file(&vdev->dev, &dev_attr_saturation);
device_remove_file(&vdev->dev, &dev_attr_streaming);
device_remove_file(&vdev->dev, &dev_attr_compression);
device_remove_file(&vdev->dev, &dev_attr_bridge);
}
}
static int usbvision_v4l2_open(struct file *file)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int err_code = 0;
PDEBUG(DBG_IO, "open");
if (mutex_lock_interruptible(&usbvision->v4l2_lock))
return -ERESTARTSYS;
if (usbvision->user) {
err_code = -EBUSY;
} else {
err_code = v4l2_fh_open(file);
if (err_code)
goto unlock;
err_code = usbvision_scratch_alloc(usbvision);
if (isoc_mode == ISOC_MODE_COMPRESS) {
err_code = usbvision_decompress_alloc(usbvision);
}
if (err_code) {
usbvision_scratch_free(usbvision);
usbvision_decompress_free(usbvision);
}
}
if (!err_code) {
if (!usbvision->initialized) {
int setup_ok = 0;
setup_ok = usbvision_setup(usbvision, isoc_mode);
if (setup_ok)
usbvision->initialized = 1;
else
err_code = -EBUSY;
}
if (!err_code) {
usbvision_begin_streaming(usbvision);
err_code = usbvision_init_isoc(usbvision);
usbvision_muxsel(usbvision, 0);
usbvision_empty_framequeues(usbvision);
usbvision->user++;
}
}
unlock:
mutex_unlock(&usbvision->v4l2_lock);
PDEBUG(DBG_IO, "success");
return err_code;
}
static int usbvision_v4l2_close(struct file *file)
{
struct usb_usbvision *usbvision = video_drvdata(file);
PDEBUG(DBG_IO, "close");
mutex_lock(&usbvision->v4l2_lock);
usbvision_audio_off(usbvision);
usbvision_restart_isoc(usbvision);
usbvision_stop_isoc(usbvision);
usbvision_decompress_free(usbvision);
usbvision_frames_free(usbvision);
usbvision_empty_framequeues(usbvision);
usbvision_scratch_free(usbvision);
usbvision->user--;
mutex_unlock(&usbvision->v4l2_lock);
if (usbvision->remove_pending) {
printk(KERN_INFO "%s: Final disconnect\n", __func__);
usbvision_release(usbvision);
return 0;
}
PDEBUG(DBG_IO, "success");
return v4l2_fh_release(file);
}
static int vidioc_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int err_code;
err_code = usbvision_read_reg(usbvision, reg->reg&0xff);
if (err_code < 0) {
dev_err(&usbvision->vdev.dev,
"%s: VIDIOC_DBG_G_REGISTER failed: error %d\n",
__func__, err_code);
return err_code;
}
reg->val = err_code;
reg->size = 1;
return 0;
}
static int vidioc_s_register(struct file *file, void *priv,
const struct v4l2_dbg_register *reg)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int err_code;
err_code = usbvision_write_reg(usbvision, reg->reg & 0xff, reg->val);
if (err_code < 0) {
dev_err(&usbvision->vdev.dev,
"%s: VIDIOC_DBG_S_REGISTER failed: error %d\n",
__func__, err_code);
return err_code;
}
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *vc)
{
struct usb_usbvision *usbvision = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
strlcpy(vc->driver, "USBVision", sizeof(vc->driver));
strlcpy(vc->card,
usbvision_device_data[usbvision->dev_model].model_string,
sizeof(vc->card));
usb_make_path(usbvision->dev, vc->bus_info, sizeof(vc->bus_info));
vc->device_caps = usbvision->have_tuner ? V4L2_CAP_TUNER : 0;
if (vdev->vfl_type == VFL_TYPE_GRABBER)
vc->device_caps |= V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
else
vc->device_caps |= V4L2_CAP_RADIO;
vc->capabilities = vc->device_caps | V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE | V4L2_CAP_STREAMING | V4L2_CAP_DEVICE_CAPS;
if (usbvision_device_data[usbvision->dev_model].radio)
vc->capabilities |= V4L2_CAP_RADIO;
return 0;
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *vi)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int chan;
if (vi->index >= usbvision->video_inputs)
return -EINVAL;
if (usbvision->have_tuner)
chan = vi->index;
else
chan = vi->index + 1;
switch (chan) {
case 0:
if (usbvision_device_data[usbvision->dev_model].video_channels == 4) {
strcpy(vi->name, "White Video Input");
} else {
strcpy(vi->name, "Television");
vi->type = V4L2_INPUT_TYPE_TUNER;
vi->tuner = chan;
vi->std = USBVISION_NORMS;
}
break;
case 1:
vi->type = V4L2_INPUT_TYPE_CAMERA;
if (usbvision_device_data[usbvision->dev_model].video_channels == 4)
strcpy(vi->name, "Green Video Input");
else
strcpy(vi->name, "Composite Video Input");
vi->std = USBVISION_NORMS;
break;
case 2:
vi->type = V4L2_INPUT_TYPE_CAMERA;
if (usbvision_device_data[usbvision->dev_model].video_channels == 4)
strcpy(vi->name, "Yellow Video Input");
else
strcpy(vi->name, "S-Video Input");
vi->std = USBVISION_NORMS;
break;
case 3:
vi->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(vi->name, "Red Video Input");
vi->std = USBVISION_NORMS;
break;
}
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *input)
{
struct usb_usbvision *usbvision = video_drvdata(file);
*input = usbvision->ctl_input;
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int input)
{
struct usb_usbvision *usbvision = video_drvdata(file);
if (input >= usbvision->video_inputs)
return -EINVAL;
usbvision_muxsel(usbvision, input);
usbvision_set_input(usbvision);
usbvision_set_output(usbvision,
usbvision->curwidth,
usbvision->curheight);
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id id)
{
struct usb_usbvision *usbvision = video_drvdata(file);
usbvision->tvnorm_id = id;
call_all(usbvision, video, s_std, usbvision->tvnorm_id);
usbvision_muxsel(usbvision, usbvision->ctl_input);
return 0;
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct usb_usbvision *usbvision = video_drvdata(file);
*id = usbvision->tvnorm_id;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *vt)
{
struct usb_usbvision *usbvision = video_drvdata(file);
if (vt->index)
return -EINVAL;
if (vt->type == V4L2_TUNER_RADIO)
strcpy(vt->name, "Radio");
else
strcpy(vt->name, "Television");
call_all(usbvision, tuner, g_tuner, vt);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *vt)
{
struct usb_usbvision *usbvision = video_drvdata(file);
if (vt->index)
return -EINVAL;
call_all(usbvision, tuner, s_tuner, vt);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *freq)
{
struct usb_usbvision *usbvision = video_drvdata(file);
if (freq->tuner)
return -EINVAL;
if (freq->type == V4L2_TUNER_RADIO)
freq->frequency = usbvision->radio_freq;
else
freq->frequency = usbvision->tv_freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *freq)
{
struct usb_usbvision *usbvision = video_drvdata(file);
struct v4l2_frequency new_freq = *freq;
if (freq->tuner)
return -EINVAL;
call_all(usbvision, tuner, s_frequency, freq);
call_all(usbvision, tuner, g_frequency, &new_freq);
if (freq->type == V4L2_TUNER_RADIO)
usbvision->radio_freq = new_freq.frequency;
else
usbvision->tv_freq = new_freq.frequency;
return 0;
}
static int vidioc_reqbufs(struct file *file,
void *priv, struct v4l2_requestbuffers *vr)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int ret;
RESTRICT_TO_RANGE(vr->count, 1, USBVISION_NUMFRAMES);
if (vr->memory != V4L2_MEMORY_MMAP)
return -EINVAL;
if (usbvision->streaming == stream_on) {
ret = usbvision_stream_interrupt(usbvision);
if (ret)
return ret;
}
usbvision_frames_free(usbvision);
usbvision_empty_framequeues(usbvision);
vr->count = usbvision_frames_alloc(usbvision, vr->count);
usbvision->cur_frame = NULL;
return 0;
}
static int vidioc_querybuf(struct file *file,
void *priv, struct v4l2_buffer *vb)
{
struct usb_usbvision *usbvision = video_drvdata(file);
struct usbvision_frame *frame;
if (vb->index >= usbvision->num_frames)
return -EINVAL;
vb->flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
frame = &usbvision->frame[vb->index];
if (frame->grabstate >= frame_state_ready)
vb->flags |= V4L2_BUF_FLAG_QUEUED;
if (frame->grabstate >= frame_state_done)
vb->flags |= V4L2_BUF_FLAG_DONE;
if (frame->grabstate == frame_state_unused)
vb->flags |= V4L2_BUF_FLAG_MAPPED;
vb->memory = V4L2_MEMORY_MMAP;
vb->m.offset = vb->index * PAGE_ALIGN(usbvision->max_frame_size);
vb->memory = V4L2_MEMORY_MMAP;
vb->field = V4L2_FIELD_NONE;
vb->length = usbvision->curwidth *
usbvision->curheight *
usbvision->palette.bytes_per_pixel;
vb->timestamp = usbvision->frame[vb->index].timestamp;
vb->sequence = usbvision->frame[vb->index].sequence;
return 0;
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *vb)
{
struct usb_usbvision *usbvision = video_drvdata(file);
struct usbvision_frame *frame;
unsigned long lock_flags;
if (vb->index >= usbvision->num_frames)
return -EINVAL;
frame = &usbvision->frame[vb->index];
if (frame->grabstate != frame_state_unused)
return -EAGAIN;
frame->grabstate = frame_state_ready;
frame->scanstate = scan_state_scanning;
frame->scanlength = 0;
vb->flags &= ~V4L2_BUF_FLAG_DONE;
frame->v4l2_format = usbvision->palette;
spin_lock_irqsave(&usbvision->queue_lock, lock_flags);
list_add_tail(&usbvision->frame[vb->index].frame, &usbvision->inqueue);
spin_unlock_irqrestore(&usbvision->queue_lock, lock_flags);
return 0;
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *vb)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int ret;
struct usbvision_frame *f;
unsigned long lock_flags;
if (list_empty(&(usbvision->outqueue))) {
if (usbvision->streaming == stream_idle)
return -EINVAL;
ret = wait_event_interruptible
(usbvision->wait_frame,
!list_empty(&(usbvision->outqueue)));
if (ret)
return ret;
}
spin_lock_irqsave(&usbvision->queue_lock, lock_flags);
f = list_entry(usbvision->outqueue.next,
struct usbvision_frame, frame);
list_del(usbvision->outqueue.next);
spin_unlock_irqrestore(&usbvision->queue_lock, lock_flags);
f->grabstate = frame_state_unused;
vb->memory = V4L2_MEMORY_MMAP;
vb->flags = V4L2_BUF_FLAG_MAPPED |
V4L2_BUF_FLAG_QUEUED |
V4L2_BUF_FLAG_DONE |
V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
vb->index = f->index;
vb->sequence = f->sequence;
vb->timestamp = f->timestamp;
vb->field = V4L2_FIELD_NONE;
vb->bytesused = f->scanlength;
return 0;
}
static int vidioc_streamon(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct usb_usbvision *usbvision = video_drvdata(file);
usbvision->streaming = stream_on;
call_all(usbvision, video, s_stream, 1);
return 0;
}
static int vidioc_streamoff(struct file *file,
void *priv, enum v4l2_buf_type type)
{
struct usb_usbvision *usbvision = video_drvdata(file);
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (usbvision->streaming == stream_on) {
usbvision_stream_interrupt(usbvision);
call_all(usbvision, video, s_stream, 0);
}
usbvision_empty_framequeues(usbvision);
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *vfd)
{
if (vfd->index >= USBVISION_SUPPORTED_PALETTES - 1)
return -EINVAL;
strcpy(vfd->description, usbvision_v4l2_format[vfd->index].desc);
vfd->pixelformat = usbvision_v4l2_format[vfd->index].format;
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *vf)
{
struct usb_usbvision *usbvision = video_drvdata(file);
vf->fmt.pix.width = usbvision->curwidth;
vf->fmt.pix.height = usbvision->curheight;
vf->fmt.pix.pixelformat = usbvision->palette.format;
vf->fmt.pix.bytesperline =
usbvision->curwidth * usbvision->palette.bytes_per_pixel;
vf->fmt.pix.sizeimage = vf->fmt.pix.bytesperline * usbvision->curheight;
vf->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
vf->fmt.pix.field = V4L2_FIELD_NONE;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *vf)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int format_idx;
for (format_idx = 0; format_idx < USBVISION_SUPPORTED_PALETTES; format_idx++) {
if (vf->fmt.pix.pixelformat ==
usbvision_v4l2_format[format_idx].format) {
usbvision->palette = usbvision_v4l2_format[format_idx];
break;
}
}
if (format_idx == USBVISION_SUPPORTED_PALETTES)
return -EINVAL;
RESTRICT_TO_RANGE(vf->fmt.pix.width, MIN_FRAME_WIDTH, MAX_FRAME_WIDTH);
RESTRICT_TO_RANGE(vf->fmt.pix.height, MIN_FRAME_HEIGHT, MAX_FRAME_HEIGHT);
vf->fmt.pix.bytesperline = vf->fmt.pix.width*
usbvision->palette.bytes_per_pixel;
vf->fmt.pix.sizeimage = vf->fmt.pix.bytesperline*vf->fmt.pix.height;
vf->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
vf->fmt.pix.field = V4L2_FIELD_NONE;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *vf)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int ret;
ret = vidioc_try_fmt_vid_cap(file, priv, vf);
if (ret)
return ret;
if (usbvision->streaming == stream_on) {
ret = usbvision_stream_interrupt(usbvision);
if (ret)
return ret;
}
usbvision_frames_free(usbvision);
usbvision_empty_framequeues(usbvision);
usbvision->cur_frame = NULL;
usbvision_set_output(usbvision, vf->fmt.pix.width, vf->fmt.pix.height);
return 0;
}
static ssize_t usbvision_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int noblock = file->f_flags & O_NONBLOCK;
unsigned long lock_flags;
int ret, i;
struct usbvision_frame *frame;
PDEBUG(DBG_IO, "%s: %ld bytes, noblock=%d", __func__,
(unsigned long)count, noblock);
if (!USBVISION_IS_OPERATIONAL(usbvision) || (buf == NULL))
return -EFAULT;
if (!usbvision->num_frames) {
usbvision_frames_free(usbvision);
usbvision_empty_framequeues(usbvision);
usbvision_frames_alloc(usbvision, USBVISION_NUMFRAMES);
}
if (usbvision->streaming != stream_on) {
usbvision->streaming = stream_on;
call_all(usbvision, video, s_stream, 1);
}
for (i = 0; i < usbvision->num_frames; i++) {
frame = &usbvision->frame[i];
if (frame->grabstate == frame_state_unused) {
frame->grabstate = frame_state_ready;
frame->scanstate = scan_state_scanning;
frame->scanlength = 0;
frame->v4l2_format = usbvision->palette;
spin_lock_irqsave(&usbvision->queue_lock, lock_flags);
list_add_tail(&frame->frame, &usbvision->inqueue);
spin_unlock_irqrestore(&usbvision->queue_lock,
lock_flags);
}
}
if (list_empty(&(usbvision->outqueue))) {
if (noblock)
return -EAGAIN;
ret = wait_event_interruptible
(usbvision->wait_frame,
!list_empty(&(usbvision->outqueue)));
if (ret)
return ret;
}
spin_lock_irqsave(&usbvision->queue_lock, lock_flags);
frame = list_entry(usbvision->outqueue.next,
struct usbvision_frame, frame);
list_del(usbvision->outqueue.next);
spin_unlock_irqrestore(&usbvision->queue_lock, lock_flags);
if (frame->grabstate == frame_state_error) {
frame->bytes_read = 0;
return 0;
}
PDEBUG(DBG_IO, "%s: frmx=%d, bytes_read=%ld, scanlength=%ld",
__func__,
frame->index, frame->bytes_read, frame->scanlength);
if ((count + frame->bytes_read) > (unsigned long)frame->scanlength)
count = frame->scanlength - frame->bytes_read;
if (copy_to_user(buf, frame->data + frame->bytes_read, count))
return -EFAULT;
frame->bytes_read += count;
PDEBUG(DBG_IO, "%s: {copy} count used=%ld, new bytes_read=%ld",
__func__,
(unsigned long)count, frame->bytes_read);
#if 1
frame->bytes_read = 0;
frame->grabstate = frame_state_unused;
#else
if (frame->bytes_read >= frame->scanlength) {
frame->bytes_read = 0;
frame->grabstate = frame_state_unused;
}
#endif
return count;
}
static ssize_t usbvision_v4l2_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int res;
if (mutex_lock_interruptible(&usbvision->v4l2_lock))
return -ERESTARTSYS;
res = usbvision_read(file, buf, count, ppos);
mutex_unlock(&usbvision->v4l2_lock);
return res;
}
static int usbvision_mmap(struct file *file, struct vm_area_struct *vma)
{
unsigned long size = vma->vm_end - vma->vm_start,
start = vma->vm_start;
void *pos;
u32 i;
struct usb_usbvision *usbvision = video_drvdata(file);
PDEBUG(DBG_MMAP, "mmap");
if (!USBVISION_IS_OPERATIONAL(usbvision))
return -EFAULT;
if (!(vma->vm_flags & VM_WRITE) ||
size != PAGE_ALIGN(usbvision->max_frame_size)) {
return -EINVAL;
}
for (i = 0; i < usbvision->num_frames; i++) {
if (((PAGE_ALIGN(usbvision->max_frame_size)*i) >> PAGE_SHIFT) ==
vma->vm_pgoff)
break;
}
if (i == usbvision->num_frames) {
PDEBUG(DBG_MMAP,
"mmap: user supplied mapping address is out of range");
return -EINVAL;
}
vma->vm_flags |= VM_IO | VM_DONTEXPAND | VM_DONTDUMP;
pos = usbvision->frame[i].data;
while (size > 0) {
if (vm_insert_page(vma, start, vmalloc_to_page(pos))) {
PDEBUG(DBG_MMAP, "mmap: vm_insert_page failed");
return -EAGAIN;
}
start += PAGE_SIZE;
pos += PAGE_SIZE;
size -= PAGE_SIZE;
}
return 0;
}
static int usbvision_v4l2_mmap(struct file *file, struct vm_area_struct *vma)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int res;
if (mutex_lock_interruptible(&usbvision->v4l2_lock))
return -ERESTARTSYS;
res = usbvision_mmap(file, vma);
mutex_unlock(&usbvision->v4l2_lock);
return res;
}
static int usbvision_radio_open(struct file *file)
{
struct usb_usbvision *usbvision = video_drvdata(file);
int err_code = 0;
PDEBUG(DBG_IO, "%s:", __func__);
if (mutex_lock_interruptible(&usbvision->v4l2_lock))
return -ERESTARTSYS;
err_code = v4l2_fh_open(file);
if (err_code)
goto out;
if (usbvision->user) {
dev_err(&usbvision->rdev.dev,
"%s: Someone tried to open an already opened USBVision Radio!\n",
__func__);
err_code = -EBUSY;
} else {
err_code = usbvision_set_alternate(usbvision);
if (err_code < 0) {
usbvision->last_error = err_code;
err_code = -EBUSY;
goto out;
}
usbvision->radio = 1;
call_all(usbvision, tuner, s_radio);
usbvision_set_audio(usbvision, USBVISION_AUDIO_RADIO);
usbvision->user++;
}
out:
mutex_unlock(&usbvision->v4l2_lock);
return err_code;
}
static int usbvision_radio_close(struct file *file)
{
struct usb_usbvision *usbvision = video_drvdata(file);
PDEBUG(DBG_IO, "");
mutex_lock(&usbvision->v4l2_lock);
usbvision->iface_alt = 0;
usb_set_interface(usbvision->dev, usbvision->iface,
usbvision->iface_alt);
usbvision_audio_off(usbvision);
usbvision->radio = 0;
usbvision->user--;
mutex_unlock(&usbvision->v4l2_lock);
if (usbvision->remove_pending) {
printk(KERN_INFO "%s: Final disconnect\n", __func__);
v4l2_fh_release(file);
usbvision_release(usbvision);
return 0;
}
PDEBUG(DBG_IO, "success");
return v4l2_fh_release(file);
}
static void usbvision_vdev_init(struct usb_usbvision *usbvision,
struct video_device *vdev,
const struct video_device *vdev_template,
const char *name)
{
struct usb_device *usb_dev = usbvision->dev;
if (usb_dev == NULL) {
dev_err(&usbvision->dev->dev,
"%s: usbvision->dev is not set\n", __func__);
return;
}
*vdev = *vdev_template;
vdev->lock = &usbvision->v4l2_lock;
vdev->v4l2_dev = &usbvision->v4l2_dev;
snprintf(vdev->name, sizeof(vdev->name), "%s", name);
video_set_drvdata(vdev, usbvision);
}
static void usbvision_unregister_video(struct usb_usbvision *usbvision)
{
if (video_is_registered(&usbvision->rdev)) {
PDEBUG(DBG_PROBE, "unregister %s [v4l2]",
video_device_node_name(&usbvision->rdev));
video_unregister_device(&usbvision->rdev);
}
if (video_is_registered(&usbvision->vdev)) {
PDEBUG(DBG_PROBE, "unregister %s [v4l2]",
video_device_node_name(&usbvision->vdev));
video_unregister_device(&usbvision->vdev);
}
}
static int usbvision_register_video(struct usb_usbvision *usbvision)
{
int res = -ENOMEM;
usbvision_vdev_init(usbvision, &usbvision->vdev,
&usbvision_video_template, "USBVision Video");
if (!usbvision->have_tuner) {
v4l2_disable_ioctl(&usbvision->vdev, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(&usbvision->vdev, VIDIOC_S_TUNER);
v4l2_disable_ioctl(&usbvision->vdev, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(&usbvision->vdev, VIDIOC_S_TUNER);
}
if (video_register_device(&usbvision->vdev, VFL_TYPE_GRABBER, video_nr) < 0)
goto err_exit;
printk(KERN_INFO "USBVision[%d]: registered USBVision Video device %s [v4l2]\n",
usbvision->nr, video_device_node_name(&usbvision->vdev));
if (usbvision_device_data[usbvision->dev_model].radio) {
usbvision_vdev_init(usbvision, &usbvision->rdev,
&usbvision_radio_template, "USBVision Radio");
if (video_register_device(&usbvision->rdev, VFL_TYPE_RADIO, radio_nr) < 0)
goto err_exit;
printk(KERN_INFO "USBVision[%d]: registered USBVision Radio device %s [v4l2]\n",
usbvision->nr, video_device_node_name(&usbvision->rdev));
}
return 0;
err_exit:
dev_err(&usbvision->dev->dev,
"USBVision[%d]: video_register_device() failed\n",
usbvision->nr);
usbvision_unregister_video(usbvision);
return res;
}
static struct usb_usbvision *usbvision_alloc(struct usb_device *dev,
struct usb_interface *intf)
{
struct usb_usbvision *usbvision;
usbvision = kzalloc(sizeof(struct usb_usbvision), GFP_KERNEL);
if (usbvision == NULL)
return NULL;
usbvision->dev = dev;
if (v4l2_device_register(&intf->dev, &usbvision->v4l2_dev))
goto err_free;
if (v4l2_ctrl_handler_init(&usbvision->hdl, 4))
goto err_unreg;
usbvision->v4l2_dev.ctrl_handler = &usbvision->hdl;
mutex_init(&usbvision->v4l2_lock);
usbvision->ctrl_urb = usb_alloc_urb(USBVISION_URB_FRAMES, GFP_KERNEL);
if (usbvision->ctrl_urb == NULL)
goto err_unreg;
return usbvision;
err_unreg:
v4l2_ctrl_handler_free(&usbvision->hdl);
v4l2_device_unregister(&usbvision->v4l2_dev);
err_free:
kfree(usbvision);
return NULL;
}
static void usbvision_release(struct usb_usbvision *usbvision)
{
PDEBUG(DBG_PROBE, "");
usbvision->initialized = 0;
usbvision_remove_sysfs(&usbvision->vdev);
usbvision_unregister_video(usbvision);
kfree(usbvision->alt_max_pkt_size);
usb_free_urb(usbvision->ctrl_urb);
v4l2_ctrl_handler_free(&usbvision->hdl);
v4l2_device_unregister(&usbvision->v4l2_dev);
kfree(usbvision);
PDEBUG(DBG_PROBE, "success");
}
static void usbvision_configure_video(struct usb_usbvision *usbvision)
{
int model;
if (usbvision == NULL)
return;
model = usbvision->dev_model;
usbvision->palette = usbvision_v4l2_format[2];
if (usbvision_device_data[usbvision->dev_model].vin_reg2_override) {
usbvision->vin_reg2_preset =
usbvision_device_data[usbvision->dev_model].vin_reg2;
} else {
usbvision->vin_reg2_preset = 0;
}
usbvision->tvnorm_id = usbvision_device_data[model].video_norm;
usbvision->video_inputs = usbvision_device_data[model].video_channels;
usbvision->ctl_input = 0;
usbvision->radio_freq = 87.5 * 16000;
usbvision->tv_freq = 400 * 16;
if (usbvision_device_data[model].audio_channels > 0)
usbvision_audio_off(usbvision);
usbvision_power_on(usbvision);
usbvision_i2c_register(usbvision);
}
static int usbvision_probe(struct usb_interface *intf,
const struct usb_device_id *devid)
{
struct usb_device *dev = usb_get_dev(interface_to_usbdev(intf));
struct usb_interface *uif;
__u8 ifnum = intf->altsetting->desc.bInterfaceNumber;
const struct usb_host_interface *interface;
struct usb_usbvision *usbvision = NULL;
const struct usb_endpoint_descriptor *endpoint;
int model, i, ret;
PDEBUG(DBG_PROBE, "VID=%#04x, PID=%#04x, ifnum=%u",
dev->descriptor.idVendor,
dev->descriptor.idProduct, ifnum);
model = devid->driver_info;
if (model < 0 || model >= usbvision_device_data_size) {
PDEBUG(DBG_PROBE, "model out of bounds %d", model);
ret = -ENODEV;
goto err_usb;
}
printk(KERN_INFO "%s: %s found\n", __func__,
usbvision_device_data[model].model_string);
if (usbvision_device_data[model].interface >= 0)
interface = &dev->actconfig->interface[usbvision_device_data[model].interface]->altsetting[0];
else if (ifnum < dev->actconfig->desc.bNumInterfaces)
interface = &dev->actconfig->interface[ifnum]->altsetting[0];
else {
dev_err(&intf->dev, "interface %d is invalid, max is %d\n",
ifnum, dev->actconfig->desc.bNumInterfaces - 1);
ret = -ENODEV;
goto err_usb;
}
if (interface->desc.bNumEndpoints < 2) {
dev_err(&intf->dev, "interface %d has %d endpoints, but must have minimum 2\n",
ifnum, interface->desc.bNumEndpoints);
ret = -ENODEV;
goto err_usb;
}
endpoint = &interface->endpoint[1].desc;
if (!usb_endpoint_xfer_isoc(endpoint)) {
dev_err(&intf->dev, "%s: interface %d. has non-ISO endpoint!\n",
__func__, ifnum);
dev_err(&intf->dev, "%s: Endpoint attributes %d",
__func__, endpoint->bmAttributes);
ret = -ENODEV;
goto err_usb;
}
if (usb_endpoint_dir_out(endpoint)) {
dev_err(&intf->dev, "%s: interface %d. has ISO OUT endpoint!\n",
__func__, ifnum);
ret = -ENODEV;
goto err_usb;
}
usbvision = usbvision_alloc(dev, intf);
if (usbvision == NULL) {
dev_err(&intf->dev, "%s: couldn't allocate USBVision struct\n", __func__);
ret = -ENOMEM;
goto err_usb;
}
if (dev->descriptor.bNumConfigurations > 1)
usbvision->bridge_type = BRIDGE_NT1004;
else if (model == DAZZLE_DVC_90_REV_1_SECAM)
usbvision->bridge_type = BRIDGE_NT1005;
else
usbvision->bridge_type = BRIDGE_NT1003;
PDEBUG(DBG_PROBE, "bridge_type %d", usbvision->bridge_type);
uif = dev->actconfig->interface[0];
usbvision->num_alt = uif->num_altsetting;
PDEBUG(DBG_PROBE, "Alternate settings: %i", usbvision->num_alt);
usbvision->alt_max_pkt_size = kmalloc(32 * usbvision->num_alt, GFP_KERNEL);
if (usbvision->alt_max_pkt_size == NULL) {
dev_err(&intf->dev, "usbvision: out of memory!\n");
ret = -ENOMEM;
goto err_pkt;
}
for (i = 0; i < usbvision->num_alt; i++) {
u16 tmp = le16_to_cpu(uif->altsetting[i].endpoint[1].desc.
wMaxPacketSize);
usbvision->alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
PDEBUG(DBG_PROBE, "Alternate setting %i, max size= %i", i,
usbvision->alt_max_pkt_size[i]);
}
usbvision->nr = usbvision_nr++;
spin_lock_init(&usbvision->queue_lock);
init_waitqueue_head(&usbvision->wait_frame);
init_waitqueue_head(&usbvision->wait_stream);
usbvision->have_tuner = usbvision_device_data[model].tuner;
if (usbvision->have_tuner)
usbvision->tuner_type = usbvision_device_data[model].tuner_type;
usbvision->dev_model = model;
usbvision->remove_pending = 0;
usbvision->iface = ifnum;
usbvision->iface_alt = 0;
usbvision->video_endp = endpoint->bEndpointAddress;
usbvision->isoc_packet_size = 0;
usbvision->usb_bandwidth = 0;
usbvision->user = 0;
usbvision->streaming = stream_off;
usbvision_configure_video(usbvision);
usbvision_register_video(usbvision);
usbvision_create_sysfs(&usbvision->vdev);
PDEBUG(DBG_PROBE, "success");
return 0;
err_pkt:
usbvision_release(usbvision);
err_usb:
usb_put_dev(dev);
return ret;
}
static void usbvision_disconnect(struct usb_interface *intf)
{
struct usb_usbvision *usbvision = to_usbvision(usb_get_intfdata(intf));
PDEBUG(DBG_PROBE, "");
if (usbvision == NULL) {
pr_err("%s: usb_get_intfdata() failed\n", __func__);
return;
}
mutex_lock(&usbvision->v4l2_lock);
usbvision_stop_isoc(usbvision);
v4l2_device_disconnect(&usbvision->v4l2_dev);
usbvision_i2c_unregister(usbvision);
usbvision->remove_pending = 1;
usb_put_dev(usbvision->dev);
usbvision->dev = NULL;
mutex_unlock(&usbvision->v4l2_lock);
if (usbvision->user) {
printk(KERN_INFO "%s: In use, disconnect pending\n",
__func__);
wake_up_interruptible(&usbvision->wait_frame);
wake_up_interruptible(&usbvision->wait_stream);
} else {
usbvision_release(usbvision);
}
PDEBUG(DBG_PROBE, "success");
}
static int __init usbvision_init(void)
{
int err_code;
PDEBUG(DBG_PROBE, "");
PDEBUG(DBG_IO, "IO debugging is enabled [video]");
PDEBUG(DBG_PROBE, "PROBE debugging is enabled [video]");
PDEBUG(DBG_MMAP, "MMAP debugging is enabled [video]");
if (isoc_mode != ISOC_MODE_COMPRESS) {
usbvision_v4l2_format[6].supported = 0;
usbvision_v4l2_format[7].supported = 0;
}
err_code = usb_register(&usbvision_driver);
if (err_code == 0) {
printk(KERN_INFO DRIVER_DESC " : " USBVISION_VERSION_STRING "\n");
PDEBUG(DBG_PROBE, "success");
}
return err_code;
}
static void __exit usbvision_exit(void)
{
PDEBUG(DBG_PROBE, "");
usb_deregister(&usbvision_driver);
PDEBUG(DBG_PROBE, "success");
}
