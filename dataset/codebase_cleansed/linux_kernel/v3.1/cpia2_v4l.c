static int cpia2_open(struct file *file)
{
struct camera_data *cam = video_drvdata(file);
struct cpia2_fh *fh;
if (!cam) {
ERR("Internal error, camera_data not found!\n");
return -ENODEV;
}
if (!cam->present)
return -ENODEV;
if (cam->open_count == 0) {
if (cpia2_allocate_buffers(cam))
return -ENOMEM;
if (cpia2_reset_camera(cam) < 0)
return -EIO;
cam->APP_len = 0;
cam->COM_len = 0;
}
fh = kmalloc(sizeof(*fh), GFP_KERNEL);
if (!fh)
return -ENOMEM;
file->private_data = fh;
fh->prio = V4L2_PRIORITY_UNSET;
v4l2_prio_open(&cam->prio, &fh->prio);
fh->mmapped = 0;
++cam->open_count;
cpia2_dbg_dump_registers(cam);
return 0;
}
static int cpia2_close(struct file *file)
{
struct video_device *dev = video_devdata(file);
struct camera_data *cam = video_get_drvdata(dev);
struct cpia2_fh *fh = file->private_data;
if (cam->present &&
(cam->open_count == 1 || fh->prio == V4L2_PRIORITY_RECORD)) {
cpia2_usb_stream_stop(cam);
if (cam->open_count == 1) {
cpia2_save_camera_state(cam);
cpia2_set_low_power(cam);
cpia2_free_buffers(cam);
}
}
if (fh->mmapped)
cam->mmapped = 0;
v4l2_prio_close(&cam->prio, fh->prio);
file->private_data = NULL;
kfree(fh);
if (--cam->open_count == 0) {
cpia2_free_buffers(cam);
if (!cam->present) {
video_unregister_device(dev);
kfree(cam);
return 0;
}
}
return 0;
}
static ssize_t cpia2_v4l_read(struct file *file, char __user *buf, size_t count,
loff_t *off)
{
struct camera_data *cam = video_drvdata(file);
int noblock = file->f_flags&O_NONBLOCK;
struct cpia2_fh *fh = file->private_data;
if(!cam)
return -EINVAL;
if(fh->prio != V4L2_PRIORITY_RECORD) {
return -EBUSY;
}
return cpia2_read(cam, buf, count, noblock);
}
static unsigned int cpia2_v4l_poll(struct file *filp, struct poll_table_struct *wait)
{
struct camera_data *cam = video_drvdata(filp);
struct cpia2_fh *fh = filp->private_data;
if(!cam)
return POLLERR;
if(fh->prio != V4L2_PRIORITY_RECORD) {
return POLLERR;
}
return cpia2_poll(cam, filp, wait);
}
static int sync(struct camera_data *cam, int frame_nr)
{
struct framebuf *frame = &cam->buffers[frame_nr];
while (1) {
if (frame->status == FRAME_READY)
return 0;
if (!cam->streaming) {
frame->status = FRAME_READY;
frame->length = 0;
return 0;
}
mutex_unlock(&cam->v4l2_lock);
wait_event_interruptible(cam->wq_stream,
!cam->streaming ||
frame->status == FRAME_READY);
mutex_lock(&cam->v4l2_lock);
if (signal_pending(current))
return -ERESTARTSYS;
if(!cam->present)
return -ENOTTY;
}
}
static long cpia2_default(struct file *file, void *fh, bool valid_prio,
int cmd, void *arg)
{
struct camera_data *cam = video_drvdata(file);
__u32 gpio_val;
if (cmd != CPIA2_CID_GPIO)
return -EINVAL;
gpio_val = *(__u32*) arg;
if (gpio_val &~ 0xFFU)
return -EINVAL;
return cpia2_set_gpio(cam, (unsigned char)gpio_val);
}
static int cpia2_querycap(struct file *file, void *fh, struct v4l2_capability *vc)
{
struct camera_data *cam = video_drvdata(file);
strcpy(vc->driver, "cpia2");
if (cam->params.pnp_id.product == 0x151)
strcpy(vc->card, "QX5 Microscope");
else
strcpy(vc->card, "CPiA2 Camera");
switch (cam->params.pnp_id.device_type) {
case DEVICE_STV_672:
strcat(vc->card, " (672/");
break;
case DEVICE_STV_676:
strcat(vc->card, " (676/");
break;
default:
strcat(vc->card, " (XXX/");
break;
}
switch (cam->params.version.sensor_flags) {
case CPIA2_VP_SENSOR_FLAGS_404:
strcat(vc->card, "404)");
break;
case CPIA2_VP_SENSOR_FLAGS_407:
strcat(vc->card, "407)");
break;
case CPIA2_VP_SENSOR_FLAGS_409:
strcat(vc->card, "409)");
break;
case CPIA2_VP_SENSOR_FLAGS_410:
strcat(vc->card, "410)");
break;
case CPIA2_VP_SENSOR_FLAGS_500:
strcat(vc->card, "500)");
break;
default:
strcat(vc->card, "XXX)");
break;
}
if (usb_make_path(cam->dev, vc->bus_info, sizeof(vc->bus_info)) <0)
memset(vc->bus_info,0, sizeof(vc->bus_info));
vc->capabilities = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
return 0;
}
static int cpia2_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
if (i->index)
return -EINVAL;
strcpy(i->name, "Camera");
i->type = V4L2_INPUT_TYPE_CAMERA;
return 0;
}
static int cpia2_g_input(struct file *file, void *fh, unsigned int *i)
{
*i = 0;
return 0;
}
static int cpia2_s_input(struct file *file, void *fh, unsigned int i)
{
return i ? -EINVAL : 0;
}
static int cpia2_enum_fmt_vid_cap(struct file *file, void *fh,
struct v4l2_fmtdesc *f)
{
int index = f->index;
if (index < 0 || index > 1)
return -EINVAL;
memset(f, 0, sizeof(*f));
f->index = index;
f->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
f->flags = V4L2_FMT_FLAG_COMPRESSED;
switch(index) {
case 0:
strcpy(f->description, "MJPEG");
f->pixelformat = V4L2_PIX_FMT_MJPEG;
break;
case 1:
strcpy(f->description, "JPEG");
f->pixelformat = V4L2_PIX_FMT_JPEG;
break;
default:
return -EINVAL;
}
return 0;
}
static int cpia2_try_fmt_vid_cap(struct file *file, void *fh,
struct v4l2_format *f)
{
struct camera_data *cam = video_drvdata(file);
if (f->fmt.pix.pixelformat != V4L2_PIX_FMT_MJPEG &&
f->fmt.pix.pixelformat != V4L2_PIX_FMT_JPEG)
return -EINVAL;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = cam->frame_size;
f->fmt.pix.colorspace = V4L2_COLORSPACE_JPEG;
f->fmt.pix.priv = 0;
switch (cpia2_match_video_size(f->fmt.pix.width, f->fmt.pix.height)) {
case VIDEOSIZE_VGA:
f->fmt.pix.width = 640;
f->fmt.pix.height = 480;
break;
case VIDEOSIZE_CIF:
f->fmt.pix.width = 352;
f->fmt.pix.height = 288;
break;
case VIDEOSIZE_QVGA:
f->fmt.pix.width = 320;
f->fmt.pix.height = 240;
break;
case VIDEOSIZE_288_216:
f->fmt.pix.width = 288;
f->fmt.pix.height = 216;
break;
case VIDEOSIZE_256_192:
f->fmt.pix.width = 256;
f->fmt.pix.height = 192;
break;
case VIDEOSIZE_224_168:
f->fmt.pix.width = 224;
f->fmt.pix.height = 168;
break;
case VIDEOSIZE_192_144:
f->fmt.pix.width = 192;
f->fmt.pix.height = 144;
break;
case VIDEOSIZE_QCIF:
default:
f->fmt.pix.width = 176;
f->fmt.pix.height = 144;
break;
}
return 0;
}
static int cpia2_s_fmt_vid_cap(struct file *file, void *_fh,
struct v4l2_format *f)
{
struct camera_data *cam = video_drvdata(file);
struct cpia2_fh *fh = _fh;
int err, frame;
err = v4l2_prio_check(&cam->prio, fh->prio);
if (err)
return err;
err = cpia2_try_fmt_vid_cap(file, _fh, f);
if(err != 0)
return err;
err = v4l2_prio_change(&cam->prio, &fh->prio, V4L2_PRIORITY_RECORD);
if(err != 0) {
return err;
}
cam->pixelformat = f->fmt.pix.pixelformat;
cam->params.compression.inhibit_htables = 0;
DBG("Requested width = %d, height = %d\n",
f->fmt.pix.width, f->fmt.pix.height);
if (f->fmt.pix.width != cam->width ||
f->fmt.pix.height != cam->height) {
cam->width = f->fmt.pix.width;
cam->height = f->fmt.pix.height;
cam->params.roi.width = f->fmt.pix.width;
cam->params.roi.height = f->fmt.pix.height;
cpia2_set_format(cam);
}
for (frame = 0; frame < cam->num_frames; ++frame) {
if (cam->buffers[frame].status == FRAME_READING)
if ((err = sync(cam, frame)) < 0)
return err;
cam->buffers[frame].status = FRAME_EMPTY;
}
return 0;
}
static int cpia2_g_fmt_vid_cap(struct file *file, void *fh,
struct v4l2_format *f)
{
struct camera_data *cam = video_drvdata(file);
f->fmt.pix.width = cam->width;
f->fmt.pix.height = cam->height;
f->fmt.pix.pixelformat = cam->pixelformat;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.sizeimage = cam->frame_size;
f->fmt.pix.colorspace = V4L2_COLORSPACE_JPEG;
f->fmt.pix.priv = 0;
return 0;
}
static int cpia2_cropcap(struct file *file, void *fh, struct v4l2_cropcap *c)
{
struct camera_data *cam = video_drvdata(file);
if (c->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
c->bounds.left = 0;
c->bounds.top = 0;
c->bounds.width = cam->width;
c->bounds.height = cam->height;
c->defrect.left = 0;
c->defrect.top = 0;
c->defrect.width = cam->width;
c->defrect.height = cam->height;
c->pixelaspect.numerator = 1;
c->pixelaspect.denominator = 1;
return 0;
}
static int cpia2_queryctrl(struct file *file, void *fh, struct v4l2_queryctrl *c)
{
struct camera_data *cam = video_drvdata(file);
int i;
for(i=0; i<NUM_CONTROLS; ++i) {
if(c->id == controls[i].id) {
memcpy(c, controls+i, sizeof(*c));
break;
}
}
if(i == NUM_CONTROLS)
return -EINVAL;
switch(c->id) {
case V4L2_CID_BRIGHTNESS:
if (cam->params.pnp_id.device_type == DEVICE_STV_672)
c->minimum = 1;
break;
case V4L2_CID_VFLIP:
if(cam->params.pnp_id.device_type == DEVICE_STV_672)
c->flags |= V4L2_CTRL_FLAG_DISABLED;
break;
case CPIA2_CID_FRAMERATE:
if(cam->params.pnp_id.device_type == DEVICE_STV_672 &&
cam->params.version.sensor_flags==CPIA2_VP_SENSOR_FLAGS_500){
for(i=0; i<c->maximum; ++i) {
if(framerate_controls[i].value ==
CPIA2_VP_FRAMERATE_15) {
c->maximum = i;
c->default_value = i;
}
}
}
break;
case CPIA2_CID_FLICKER_MODE:
if(cam->params.pnp_id.device_type != DEVICE_STV_672)
c->flags |= V4L2_CTRL_FLAG_DISABLED;
break;
case CPIA2_CID_LIGHTS:
if(cam->params.pnp_id.product != 0x151)
c->flags |= V4L2_CTRL_FLAG_DISABLED;
break;
default:
break;
}
return 0;
}
static int cpia2_querymenu(struct file *file, void *fh, struct v4l2_querymenu *m)
{
struct camera_data *cam = video_drvdata(file);
switch(m->id) {
case CPIA2_CID_FLICKER_MODE:
if (m->index >= NUM_FLICKER_CONTROLS)
return -EINVAL;
strcpy(m->name, flicker_controls[m->index].name);
break;
case CPIA2_CID_FRAMERATE:
{
int maximum = NUM_FRAMERATE_CONTROLS - 1;
if(cam->params.pnp_id.device_type == DEVICE_STV_672 &&
cam->params.version.sensor_flags==CPIA2_VP_SENSOR_FLAGS_500){
int i;
for(i=0; i<maximum; ++i) {
if(framerate_controls[i].value ==
CPIA2_VP_FRAMERATE_15)
maximum = i;
}
}
if (m->index > maximum)
return -EINVAL;
strcpy(m->name, framerate_controls[m->index].name);
break;
}
case CPIA2_CID_LIGHTS:
if (m->index >= NUM_LIGHTS_CONTROLS)
return -EINVAL;
strcpy(m->name, lights_controls[m->index].name);
break;
default:
return -EINVAL;
}
return 0;
}
static int cpia2_g_ctrl(struct file *file, void *fh, struct v4l2_control *c)
{
struct camera_data *cam = video_drvdata(file);
switch(c->id) {
case V4L2_CID_BRIGHTNESS:
cpia2_do_command(cam, CPIA2_CMD_GET_VP_BRIGHTNESS,
TRANSFER_READ, 0);
c->value = cam->params.color_params.brightness;
break;
case V4L2_CID_CONTRAST:
cpia2_do_command(cam, CPIA2_CMD_GET_CONTRAST,
TRANSFER_READ, 0);
c->value = cam->params.color_params.contrast;
break;
case V4L2_CID_SATURATION:
cpia2_do_command(cam, CPIA2_CMD_GET_VP_SATURATION,
TRANSFER_READ, 0);
c->value = cam->params.color_params.saturation;
break;
case V4L2_CID_HFLIP:
cpia2_do_command(cam, CPIA2_CMD_GET_USER_EFFECTS,
TRANSFER_READ, 0);
c->value = (cam->params.vp_params.user_effects &
CPIA2_VP_USER_EFFECTS_MIRROR) != 0;
break;
case V4L2_CID_VFLIP:
cpia2_do_command(cam, CPIA2_CMD_GET_USER_EFFECTS,
TRANSFER_READ, 0);
c->value = (cam->params.vp_params.user_effects &
CPIA2_VP_USER_EFFECTS_FLIP) != 0;
break;
case CPIA2_CID_TARGET_KB:
c->value = cam->params.vc_params.target_kb;
break;
case CPIA2_CID_GPIO:
cpia2_do_command(cam, CPIA2_CMD_GET_VP_GPIO_DATA,
TRANSFER_READ, 0);
c->value = cam->params.vp_params.gpio_data;
break;
case CPIA2_CID_FLICKER_MODE:
{
int i, mode;
cpia2_do_command(cam, CPIA2_CMD_GET_FLICKER_MODES,
TRANSFER_READ, 0);
if(cam->params.flicker_control.cam_register &
CPIA2_VP_FLICKER_MODES_NEVER_FLICKER) {
mode = NEVER_FLICKER;
} else {
if(cam->params.flicker_control.cam_register &
CPIA2_VP_FLICKER_MODES_50HZ) {
mode = FLICKER_50;
} else {
mode = FLICKER_60;
}
}
for(i=0; i<NUM_FLICKER_CONTROLS; i++) {
if(flicker_controls[i].value == mode) {
c->value = i;
break;
}
}
if(i == NUM_FLICKER_CONTROLS)
return -EINVAL;
break;
}
case CPIA2_CID_FRAMERATE:
{
int maximum = NUM_FRAMERATE_CONTROLS - 1;
int i;
for(i=0; i<= maximum; i++) {
if(cam->params.vp_params.frame_rate ==
framerate_controls[i].value)
break;
}
if(i > maximum)
return -EINVAL;
c->value = i;
break;
}
case CPIA2_CID_USB_ALT:
c->value = cam->params.camera_state.stream_mode;
break;
case CPIA2_CID_LIGHTS:
{
int i;
cpia2_do_command(cam, CPIA2_CMD_GET_VP_GPIO_DATA,
TRANSFER_READ, 0);
for(i=0; i<NUM_LIGHTS_CONTROLS; i++) {
if((cam->params.vp_params.gpio_data&GPIO_LIGHTS_MASK) ==
lights_controls[i].value) {
break;
}
}
if(i == NUM_LIGHTS_CONTROLS)
return -EINVAL;
c->value = i;
break;
}
case CPIA2_CID_RESET_CAMERA:
return -EINVAL;
default:
return -EINVAL;
}
DBG("Get control id:%d, value:%d\n", c->id, c->value);
return 0;
}
static int cpia2_s_ctrl(struct file *file, void *fh, struct v4l2_control *c)
{
struct camera_data *cam = video_drvdata(file);
int i;
int retval = 0;
DBG("Set control id:%d, value:%d\n", c->id, c->value);
for(i=0; i<NUM_CONTROLS; i++) {
if(c->id == controls[i].id) {
if(c->value < controls[i].minimum ||
c->value > controls[i].maximum) {
return -EINVAL;
}
break;
}
}
if(i == NUM_CONTROLS)
return -EINVAL;
switch(c->id) {
case V4L2_CID_BRIGHTNESS:
cpia2_set_brightness(cam, c->value);
break;
case V4L2_CID_CONTRAST:
cpia2_set_contrast(cam, c->value);
break;
case V4L2_CID_SATURATION:
cpia2_set_saturation(cam, c->value);
break;
case V4L2_CID_HFLIP:
cpia2_set_property_mirror(cam, c->value);
break;
case V4L2_CID_VFLIP:
cpia2_set_property_flip(cam, c->value);
break;
case CPIA2_CID_TARGET_KB:
retval = cpia2_set_target_kb(cam, c->value);
break;
case CPIA2_CID_GPIO:
retval = cpia2_set_gpio(cam, c->value);
break;
case CPIA2_CID_FLICKER_MODE:
retval = cpia2_set_flicker_mode(cam,
flicker_controls[c->value].value);
break;
case CPIA2_CID_FRAMERATE:
retval = cpia2_set_fps(cam, framerate_controls[c->value].value);
break;
case CPIA2_CID_USB_ALT:
retval = cpia2_usb_change_streaming_alternate(cam, c->value);
break;
case CPIA2_CID_LIGHTS:
retval = cpia2_set_gpio(cam, lights_controls[c->value].value);
break;
case CPIA2_CID_RESET_CAMERA:
cpia2_usb_stream_pause(cam);
cpia2_reset_camera(cam);
cpia2_usb_stream_resume(cam);
break;
default:
retval = -EINVAL;
}
return retval;
}
static int cpia2_g_jpegcomp(struct file *file, void *fh, struct v4l2_jpegcompression *parms)
{
struct camera_data *cam = video_drvdata(file);
memset(parms, 0, sizeof(*parms));
parms->quality = 80;
parms->jpeg_markers = V4L2_JPEG_MARKER_DQT | V4L2_JPEG_MARKER_DRI;
if(!cam->params.compression.inhibit_htables) {
parms->jpeg_markers |= V4L2_JPEG_MARKER_DHT;
}
parms->APPn = cam->APPn;
parms->APP_len = cam->APP_len;
if(cam->APP_len > 0) {
memcpy(parms->APP_data, cam->APP_data, cam->APP_len);
parms->jpeg_markers |= V4L2_JPEG_MARKER_APP;
}
parms->COM_len = cam->COM_len;
if(cam->COM_len > 0) {
memcpy(parms->COM_data, cam->COM_data, cam->COM_len);
parms->jpeg_markers |= JPEG_MARKER_COM;
}
DBG("G_JPEGCOMP APP_len:%d COM_len:%d\n",
parms->APP_len, parms->COM_len);
return 0;
}
static int cpia2_s_jpegcomp(struct file *file, void *fh, struct v4l2_jpegcompression *parms)
{
struct camera_data *cam = video_drvdata(file);
DBG("S_JPEGCOMP APP_len:%d COM_len:%d\n",
parms->APP_len, parms->COM_len);
cam->params.compression.inhibit_htables =
!(parms->jpeg_markers & V4L2_JPEG_MARKER_DHT);
if(parms->APP_len != 0) {
if(parms->APP_len > 0 &&
parms->APP_len <= sizeof(cam->APP_data) &&
parms->APPn >= 0 && parms->APPn <= 15) {
cam->APPn = parms->APPn;
cam->APP_len = parms->APP_len;
memcpy(cam->APP_data, parms->APP_data, parms->APP_len);
} else {
LOG("Bad APPn Params n=%d len=%d\n",
parms->APPn, parms->APP_len);
return -EINVAL;
}
} else {
cam->APP_len = 0;
}
if(parms->COM_len != 0) {
if(parms->COM_len > 0 &&
parms->COM_len <= sizeof(cam->COM_data)) {
cam->COM_len = parms->COM_len;
memcpy(cam->COM_data, parms->COM_data, parms->COM_len);
} else {
LOG("Bad COM_len=%d\n", parms->COM_len);
return -EINVAL;
}
}
return 0;
}
static int cpia2_reqbufs(struct file *file, void *fh, struct v4l2_requestbuffers *req)
{
struct camera_data *cam = video_drvdata(file);
if(req->type != V4L2_BUF_TYPE_VIDEO_CAPTURE ||
req->memory != V4L2_MEMORY_MMAP)
return -EINVAL;
DBG("REQBUFS requested:%d returning:%d\n", req->count, cam->num_frames);
req->count = cam->num_frames;
memset(&req->reserved, 0, sizeof(req->reserved));
return 0;
}
static int cpia2_querybuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct camera_data *cam = video_drvdata(file);
if(buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE ||
buf->index > cam->num_frames)
return -EINVAL;
buf->m.offset = cam->buffers[buf->index].data - cam->frame_buffer;
buf->length = cam->frame_size;
buf->memory = V4L2_MEMORY_MMAP;
if(cam->mmapped)
buf->flags = V4L2_BUF_FLAG_MAPPED;
else
buf->flags = 0;
switch (cam->buffers[buf->index].status) {
case FRAME_EMPTY:
case FRAME_ERROR:
case FRAME_READING:
buf->bytesused = 0;
buf->flags = V4L2_BUF_FLAG_QUEUED;
break;
case FRAME_READY:
buf->bytesused = cam->buffers[buf->index].length;
buf->timestamp = cam->buffers[buf->index].timestamp;
buf->sequence = cam->buffers[buf->index].seq;
buf->flags = V4L2_BUF_FLAG_DONE;
break;
}
DBG("QUERYBUF index:%d offset:%d flags:%d seq:%d bytesused:%d\n",
buf->index, buf->m.offset, buf->flags, buf->sequence,
buf->bytesused);
return 0;
}
static int cpia2_qbuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct camera_data *cam = video_drvdata(file);
if(buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE ||
buf->memory != V4L2_MEMORY_MMAP ||
buf->index > cam->num_frames)
return -EINVAL;
DBG("QBUF #%d\n", buf->index);
if(cam->buffers[buf->index].status == FRAME_READY)
cam->buffers[buf->index].status = FRAME_EMPTY;
return 0;
}
static int find_earliest_filled_buffer(struct camera_data *cam)
{
int i;
int found = -1;
for (i=0; i<cam->num_frames; i++) {
if(cam->buffers[i].status == FRAME_READY) {
if(found < 0) {
found = i;
} else {
struct timeval *tv1, *tv2;
tv1 = &cam->buffers[i].timestamp;
tv2 = &cam->buffers[found].timestamp;
if(tv1->tv_sec < tv2->tv_sec ||
(tv1->tv_sec == tv2->tv_sec &&
tv1->tv_usec < tv2->tv_usec))
found = i;
}
}
}
return found;
}
static int cpia2_dqbuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct camera_data *cam = video_drvdata(file);
int frame;
if(buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE ||
buf->memory != V4L2_MEMORY_MMAP)
return -EINVAL;
frame = find_earliest_filled_buffer(cam);
if(frame < 0 && file->f_flags&O_NONBLOCK)
return -EAGAIN;
if(frame < 0) {
struct framebuf *cb=cam->curbuff;
mutex_unlock(&cam->v4l2_lock);
wait_event_interruptible(cam->wq_stream,
!cam->present ||
(cb=cam->curbuff)->status == FRAME_READY);
mutex_lock(&cam->v4l2_lock);
if (signal_pending(current))
return -ERESTARTSYS;
if(!cam->present)
return -ENOTTY;
frame = cb->num;
}
buf->index = frame;
buf->bytesused = cam->buffers[buf->index].length;
buf->flags = V4L2_BUF_FLAG_MAPPED | V4L2_BUF_FLAG_DONE;
buf->field = V4L2_FIELD_NONE;
buf->timestamp = cam->buffers[buf->index].timestamp;
buf->sequence = cam->buffers[buf->index].seq;
buf->m.offset = cam->buffers[buf->index].data - cam->frame_buffer;
buf->length = cam->frame_size;
buf->input = 0;
buf->reserved = 0;
memset(&buf->timecode, 0, sizeof(buf->timecode));
DBG("DQBUF #%d status:%d seq:%d length:%d\n", buf->index,
cam->buffers[buf->index].status, buf->sequence, buf->bytesused);
return 0;
}
static int cpia2_g_priority(struct file *file, void *_fh, enum v4l2_priority *p)
{
struct cpia2_fh *fh = _fh;
*p = fh->prio;
return 0;
}
static int cpia2_s_priority(struct file *file, void *_fh, enum v4l2_priority prio)
{
struct camera_data *cam = video_drvdata(file);
struct cpia2_fh *fh = _fh;
if (cam->streaming && prio != fh->prio &&
fh->prio == V4L2_PRIORITY_RECORD)
return -EBUSY;
if (prio == V4L2_PRIORITY_RECORD && prio != fh->prio &&
v4l2_prio_max(&cam->prio) == V4L2_PRIORITY_RECORD)
return -EBUSY;
return v4l2_prio_change(&cam->prio, &fh->prio, prio);
}
static int cpia2_streamon(struct file *file, void *fh, enum v4l2_buf_type type)
{
struct camera_data *cam = video_drvdata(file);
DBG("VIDIOC_STREAMON, streaming=%d\n", cam->streaming);
if (!cam->mmapped || type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (!cam->streaming)
return cpia2_usb_stream_start(cam,
cam->params.camera_state.stream_mode);
return -EINVAL;
}
static int cpia2_streamoff(struct file *file, void *fh, enum v4l2_buf_type type)
{
struct camera_data *cam = video_drvdata(file);
DBG("VIDIOC_STREAMOFF, streaming=%d\n", cam->streaming);
if (!cam->mmapped || type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (cam->streaming)
return cpia2_usb_stream_stop(cam);
return -EINVAL;
}
static int cpia2_mmap(struct file *file, struct vm_area_struct *area)
{
struct camera_data *cam = video_drvdata(file);
int retval;
struct cpia2_fh *fh = file->private_data;
if(fh->prio != V4L2_PRIORITY_RECORD) {
return -EBUSY;
}
retval = cpia2_remap_buffer(cam, area);
if(!retval)
fh->mmapped = 1;
return retval;
}
static void reset_camera_struct_v4l(struct camera_data *cam)
{
cam->width = cam->params.roi.width;
cam->height = cam->params.roi.height;
cam->frame_size = buffer_size;
cam->num_frames = num_buffers;
cam->params.flicker_control.flicker_mode_req = flicker_mode;
cam->params.flicker_control.mains_frequency = flicker_freq;
cam->params.camera_state.stream_mode = alternate;
cam->pixelformat = V4L2_PIX_FMT_JPEG;
v4l2_prio_init(&cam->prio);
}
int cpia2_register_camera(struct camera_data *cam)
{
cam->vdev = video_device_alloc();
if(!cam->vdev)
return -ENOMEM;
memcpy(cam->vdev, &cpia2_template, sizeof(cpia2_template));
video_set_drvdata(cam->vdev, cam);
cam->vdev->lock = &cam->v4l2_lock;
reset_camera_struct_v4l(cam);
if (video_register_device(cam->vdev, VFL_TYPE_GRABBER, video_nr) < 0) {
ERR("video_register_device failed\n");
video_device_release(cam->vdev);
return -ENODEV;
}
return 0;
}
void cpia2_unregister_camera(struct camera_data *cam)
{
if (!cam->open_count) {
video_unregister_device(cam->vdev);
} else {
LOG("%s removed while open, deferring "
"video_unregister_device\n",
video_device_node_name(cam->vdev));
}
}
static void __init check_parameters(void)
{
if(buffer_size < PAGE_SIZE) {
buffer_size = PAGE_SIZE;
LOG("buffer_size too small, setting to %d\n", buffer_size);
} else if(buffer_size > 1024*1024) {
buffer_size = 1024*1024;
LOG("buffer_size ridiculously large, setting to %d\n",
buffer_size);
} else {
buffer_size += PAGE_SIZE-1;
buffer_size &= ~(PAGE_SIZE-1);
}
if(num_buffers < 1) {
num_buffers = 1;
LOG("num_buffers too small, setting to %d\n", num_buffers);
} else if(num_buffers > VIDEO_MAX_FRAME) {
num_buffers = VIDEO_MAX_FRAME;
LOG("num_buffers too large, setting to %d\n", num_buffers);
}
if(alternate < USBIF_ISO_1 || alternate > USBIF_ISO_6) {
alternate = DEFAULT_ALT;
LOG("alternate specified is invalid, using %d\n", alternate);
}
if (flicker_mode != NEVER_FLICKER && flicker_mode != ANTI_FLICKER_ON) {
flicker_mode = NEVER_FLICKER;
LOG("Flicker mode specified is invalid, using %d\n",
flicker_mode);
}
if (flicker_freq != FLICKER_50 && flicker_freq != FLICKER_60) {
flicker_freq = FLICKER_60;
LOG("Flicker mode specified is invalid, using %d\n",
flicker_freq);
}
if(video_nr < -1 || video_nr > 64) {
video_nr = -1;
LOG("invalid video_nr specified, must be -1 to 64\n");
}
DBG("Using %d buffers, each %d bytes, alternate=%d\n",
num_buffers, buffer_size, alternate);
}
static int __init cpia2_init(void)
{
LOG("%s v%s\n",
ABOUT, CPIA_VERSION);
check_parameters();
cpia2_usb_init();
return 0;
}
static void __exit cpia2_exit(void)
{
cpia2_usb_cleanup();
schedule_timeout(2 * HZ);
}
