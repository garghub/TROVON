static inline struct amradio_device *to_amradio_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct amradio_device, v4l2_dev);
}
static int amradio_send_cmd(struct amradio_device *radio, u8 cmd, u8 arg,
u8 *extra, u8 extralen, bool reply)
{
int retval;
int size;
radio->buffer[0] = 0x00;
radio->buffer[1] = 0x55;
radio->buffer[2] = 0xaa;
radio->buffer[3] = extralen;
radio->buffer[4] = cmd;
radio->buffer[5] = arg;
radio->buffer[6] = 0x00;
radio->buffer[7] = extra || reply ? 8 : 0;
retval = usb_bulk_msg(radio->usbdev, usb_sndintpipe(radio->usbdev, 2),
radio->buffer, BUFFER_LENGTH, &size, USB_TIMEOUT);
if (retval < 0 || size != BUFFER_LENGTH) {
if (video_is_registered(&radio->vdev))
amradio_dev_warn(&radio->vdev.dev,
"cmd %02x failed\n", cmd);
return retval ? retval : -EIO;
}
if (!extra && !reply)
return 0;
if (extra) {
memcpy(radio->buffer, extra, extralen);
memset(radio->buffer + extralen, 0, 8 - extralen);
retval = usb_bulk_msg(radio->usbdev, usb_sndintpipe(radio->usbdev, 2),
radio->buffer, BUFFER_LENGTH, &size, USB_TIMEOUT);
} else {
memset(radio->buffer, 0, 8);
retval = usb_bulk_msg(radio->usbdev, usb_rcvbulkpipe(radio->usbdev, 0x81),
radio->buffer, BUFFER_LENGTH, &size, USB_TIMEOUT);
}
if (retval == 0 && size == BUFFER_LENGTH)
return 0;
if (video_is_registered(&radio->vdev) && cmd != AMRADIO_GET_READY_FLAG)
amradio_dev_warn(&radio->vdev.dev, "follow-up to cmd %02x failed\n", cmd);
return retval ? retval : -EIO;
}
static int amradio_set_mute(struct amradio_device *radio, bool mute)
{
int ret = amradio_send_cmd(radio,
AMRADIO_SET_MUTE, mute, NULL, 0, false);
if (!ret)
radio->muted = mute;
return ret;
}
static int amradio_set_freq(struct amradio_device *radio, int freq)
{
unsigned short freq_send = 0x10 + (freq >> 3) / 25;
u8 buf[3];
int retval;
buf[0] = (freq_send >> 8) & 0xff;
buf[1] = freq_send & 0xff;
buf[2] = 0x01;
retval = amradio_send_cmd(radio, AMRADIO_SET_FREQ, 0, buf, 3, false);
if (retval)
return retval;
radio->curfreq = freq;
msleep(40);
return 0;
}
static int amradio_set_stereo(struct amradio_device *radio, bool stereo)
{
int ret = amradio_send_cmd(radio,
AMRADIO_SET_MONO, !stereo, NULL, 0, false);
if (!ret)
radio->stereo = stereo;
return ret;
}
static int amradio_get_stat(struct amradio_device *radio, bool *is_stereo, u32 *signal)
{
int ret = amradio_send_cmd(radio,
AMRADIO_GET_SIGNAL, 0, NULL, 0, true);
if (ret)
return ret;
*is_stereo = radio->buffer[2] >> 7;
*signal = (radio->buffer[3] & 0xf0) << 8;
return 0;
}
static void usb_amradio_disconnect(struct usb_interface *intf)
{
struct amradio_device *radio = to_amradio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
video_unregister_device(&radio->vdev);
amradio_set_mute(radio, true);
usb_set_intfdata(intf, NULL);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->lock);
v4l2_device_put(&radio->v4l2_dev);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct amradio_device *radio = video_drvdata(file);
strlcpy(v->driver, "radio-mr800", sizeof(v->driver));
strlcpy(v->card, "AverMedia MR 800 USB FM Radio", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_RADIO | V4L2_CAP_TUNER |
V4L2_CAP_HW_FREQ_SEEK;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct amradio_device *radio = video_drvdata(file);
bool is_stereo = false;
int retval;
if (v->index > 0)
return -EINVAL;
v->signal = 0;
retval = amradio_get_stat(radio, &is_stereo, &v->signal);
if (retval)
return retval;
strcpy(v->name, "FM");
v->type = V4L2_TUNER_RADIO;
v->rangelow = FREQ_MIN * FREQ_MUL;
v->rangehigh = FREQ_MAX * FREQ_MUL;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
v->rxsubchans = is_stereo ? V4L2_TUNER_SUB_STEREO : V4L2_TUNER_SUB_MONO;
v->audmode = radio->stereo ?
V4L2_TUNER_MODE_STEREO : V4L2_TUNER_MODE_MONO;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct amradio_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
switch (v->audmode) {
case V4L2_TUNER_MODE_MONO:
return amradio_set_stereo(radio, WANT_MONO);
default:
return amradio_set_stereo(radio, WANT_STEREO);
}
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct amradio_device *radio = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
return amradio_set_freq(radio, clamp_t(unsigned, f->frequency,
FREQ_MIN * FREQ_MUL, FREQ_MAX * FREQ_MUL));
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct amradio_device *radio = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = radio->curfreq;
return 0;
}
static int vidioc_s_hw_freq_seek(struct file *file, void *priv,
struct v4l2_hw_freq_seek *seek)
{
static u8 buf[8] = {
0x3d, 0x32, 0x0f, 0x08, 0x3d, 0x32, 0x0f, 0x08
};
struct amradio_device *radio = video_drvdata(file);
unsigned long timeout;
int retval;
if (seek->tuner != 0 || !seek->wrap_around)
return -EINVAL;
retval = amradio_send_cmd(radio,
AMRADIO_SET_SEARCH_LVL, 0, buf, 8, false);
if (retval)
return retval;
amradio_set_freq(radio, radio->curfreq);
retval = amradio_send_cmd(radio,
seek->seek_upward ? AMRADIO_SET_SEARCH_UP : AMRADIO_SET_SEARCH_DOWN,
0, NULL, 0, false);
if (retval)
return retval;
timeout = jiffies + msecs_to_jiffies(30000);
for (;;) {
if (time_after(jiffies, timeout)) {
retval = -EAGAIN;
break;
}
if (schedule_timeout_interruptible(msecs_to_jiffies(10))) {
retval = -ERESTARTSYS;
break;
}
retval = amradio_send_cmd(radio, AMRADIO_GET_READY_FLAG,
0, NULL, 0, true);
if (retval)
continue;
amradio_send_cmd(radio, AMRADIO_GET_FREQ, 0, NULL, 0, true);
if (radio->buffer[1] || radio->buffer[2]) {
radio->curfreq = (radio->buffer[1] << 8) | radio->buffer[2];
radio->curfreq = (radio->curfreq - 0x10) * 200;
amradio_send_cmd(radio, AMRADIO_STOP_SEARCH,
0, NULL, 0, false);
amradio_set_freq(radio, radio->curfreq);
retval = 0;
break;
}
}
amradio_send_cmd(radio, AMRADIO_STOP_SEARCH, 0, NULL, 0, false);
amradio_set_freq(radio, radio->curfreq);
return retval;
}
static int usb_amradio_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct amradio_device *radio =
container_of(ctrl->handler, struct amradio_device, hdl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
return amradio_set_mute(radio, ctrl->val);
}
return -EINVAL;
}
static int usb_amradio_init(struct amradio_device *radio)
{
int retval;
retval = amradio_set_mute(radio, true);
if (retval)
goto out_err;
retval = amradio_set_stereo(radio, true);
if (retval)
goto out_err;
retval = amradio_set_freq(radio, radio->curfreq);
if (retval)
goto out_err;
return 0;
out_err:
amradio_dev_err(&radio->vdev.dev, "initialization failed\n");
return retval;
}
static int usb_amradio_suspend(struct usb_interface *intf, pm_message_t message)
{
struct amradio_device *radio = to_amradio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
if (!radio->muted) {
amradio_set_mute(radio, true);
radio->muted = false;
}
mutex_unlock(&radio->lock);
dev_info(&intf->dev, "going into suspend..\n");
return 0;
}
static int usb_amradio_resume(struct usb_interface *intf)
{
struct amradio_device *radio = to_amradio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
amradio_set_stereo(radio, radio->stereo);
amradio_set_freq(radio, radio->curfreq);
if (!radio->muted)
amradio_set_mute(radio, false);
mutex_unlock(&radio->lock);
dev_info(&intf->dev, "coming out of suspend..\n");
return 0;
}
static void usb_amradio_release(struct v4l2_device *v4l2_dev)
{
struct amradio_device *radio = to_amradio_dev(v4l2_dev);
v4l2_ctrl_handler_free(&radio->hdl);
v4l2_device_unregister(&radio->v4l2_dev);
kfree(radio->buffer);
kfree(radio);
}
static int usb_amradio_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct amradio_device *radio;
int retval = 0;
radio = kzalloc(sizeof(struct amradio_device), GFP_KERNEL);
if (!radio) {
dev_err(&intf->dev, "kmalloc for amradio_device failed\n");
retval = -ENOMEM;
goto err;
}
radio->buffer = kmalloc(BUFFER_LENGTH, GFP_KERNEL);
if (!radio->buffer) {
dev_err(&intf->dev, "kmalloc for radio->buffer failed\n");
retval = -ENOMEM;
goto err_nobuf;
}
retval = v4l2_device_register(&intf->dev, &radio->v4l2_dev);
if (retval < 0) {
dev_err(&intf->dev, "couldn't register v4l2_device\n");
goto err_v4l2;
}
v4l2_ctrl_handler_init(&radio->hdl, 1);
v4l2_ctrl_new_std(&radio->hdl, &usb_amradio_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
if (radio->hdl.error) {
retval = radio->hdl.error;
dev_err(&intf->dev, "couldn't register control\n");
goto err_ctrl;
}
mutex_init(&radio->lock);
radio->v4l2_dev.ctrl_handler = &radio->hdl;
radio->v4l2_dev.release = usb_amradio_release;
strlcpy(radio->vdev.name, radio->v4l2_dev.name,
sizeof(radio->vdev.name));
radio->vdev.v4l2_dev = &radio->v4l2_dev;
radio->vdev.fops = &usb_amradio_fops;
radio->vdev.ioctl_ops = &usb_amradio_ioctl_ops;
radio->vdev.release = video_device_release_empty;
radio->vdev.lock = &radio->lock;
set_bit(V4L2_FL_USE_FH_PRIO, &radio->vdev.flags);
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
usb_set_intfdata(intf, &radio->v4l2_dev);
radio->curfreq = 95.16 * FREQ_MUL;
video_set_drvdata(&radio->vdev, radio);
retval = usb_amradio_init(radio);
if (retval)
goto err_vdev;
retval = video_register_device(&radio->vdev, VFL_TYPE_RADIO,
radio_nr);
if (retval < 0) {
dev_err(&intf->dev, "could not register video device\n");
goto err_vdev;
}
return 0;
err_vdev:
v4l2_ctrl_handler_free(&radio->hdl);
err_ctrl:
v4l2_device_unregister(&radio->v4l2_dev);
err_v4l2:
kfree(radio->buffer);
err_nobuf:
kfree(radio);
err:
return retval;
}
