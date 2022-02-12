static int dsbr100_setfreq(struct dsbr100_device *radio, unsigned freq)
{
unsigned f = (freq / 16 * 80) / 1000 + 856;
int retval = 0;
if (!radio->muted) {
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_TUNE,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
(f >> 8) & 0x00ff, f & 0xff,
radio->transfer_buffer, 8, 300);
if (retval >= 0)
mdelay(1);
}
if (retval >= 0) {
radio->curfreq = freq;
return 0;
}
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, DSB100_TUNE);
return retval;
}
static int dsbr100_start(struct dsbr100_device *radio)
{
int retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_ONOFF,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x01, 0x00, radio->transfer_buffer, 8, 300);
if (retval >= 0)
return dsbr100_setfreq(radio, radio->curfreq);
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, DSB100_ONOFF);
return retval;
}
static int dsbr100_stop(struct dsbr100_device *radio)
{
int retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_ONOFF,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, 0x00, radio->transfer_buffer, 8, 300);
if (retval >= 0)
return 0;
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, DSB100_ONOFF);
return retval;
}
static void dsbr100_getstat(struct dsbr100_device *radio)
{
int retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
USB_REQ_GET_STATUS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, 0x24, radio->transfer_buffer, 8, 300);
if (retval < 0) {
radio->stereo = false;
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, USB_REQ_GET_STATUS);
} else {
radio->stereo = !(radio->transfer_buffer[0] & 0x01);
}
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct dsbr100_device *radio = video_drvdata(file);
strlcpy(v->driver, "dsbr100", sizeof(v->driver));
strlcpy(v->card, "D-Link R-100 USB FM Radio", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_RADIO | V4L2_CAP_TUNER;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct dsbr100_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
dsbr100_getstat(radio);
strcpy(v->name, "FM");
v->type = V4L2_TUNER_RADIO;
v->rangelow = FREQ_MIN * FREQ_MUL;
v->rangehigh = FREQ_MAX * FREQ_MUL;
v->rxsubchans = radio->stereo ? V4L2_TUNER_SUB_STEREO :
V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
v->audmode = V4L2_TUNER_MODE_STEREO;
v->signal = radio->stereo ? 0xffff : 0;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct dsbr100_device *radio = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
return dsbr100_setfreq(radio, clamp_t(unsigned, f->frequency,
FREQ_MIN * FREQ_MUL, FREQ_MAX * FREQ_MUL));
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct dsbr100_device *radio = video_drvdata(file);
if (f->tuner)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = radio->curfreq;
return 0;
}
static int usb_dsbr100_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct dsbr100_device *radio =
container_of(ctrl->handler, struct dsbr100_device, hdl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
radio->muted = ctrl->val;
return radio->muted ? dsbr100_stop(radio) : dsbr100_start(radio);
}
return -EINVAL;
}
static void usb_dsbr100_disconnect(struct usb_interface *intf)
{
struct dsbr100_device *radio = usb_get_intfdata(intf);
mutex_lock(&radio->v4l2_lock);
usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_ONOFF,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, 0x00, radio->transfer_buffer, 8, 300);
usb_set_intfdata(intf, NULL);
video_unregister_device(&radio->videodev);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->v4l2_lock);
v4l2_device_put(&radio->v4l2_dev);
}
static int usb_dsbr100_suspend(struct usb_interface *intf, pm_message_t message)
{
struct dsbr100_device *radio = usb_get_intfdata(intf);
mutex_lock(&radio->v4l2_lock);
if (!radio->muted && dsbr100_stop(radio) < 0)
dev_warn(&intf->dev, "dsbr100_stop failed\n");
mutex_unlock(&radio->v4l2_lock);
dev_info(&intf->dev, "going into suspend..\n");
return 0;
}
static int usb_dsbr100_resume(struct usb_interface *intf)
{
struct dsbr100_device *radio = usb_get_intfdata(intf);
mutex_lock(&radio->v4l2_lock);
if (!radio->muted && dsbr100_start(radio) < 0)
dev_warn(&intf->dev, "dsbr100_start failed\n");
mutex_unlock(&radio->v4l2_lock);
dev_info(&intf->dev, "coming out of suspend..\n");
return 0;
}
static void usb_dsbr100_release(struct v4l2_device *v4l2_dev)
{
struct dsbr100_device *radio = v4l2_dev_to_radio(v4l2_dev);
v4l2_ctrl_handler_free(&radio->hdl);
v4l2_device_unregister(&radio->v4l2_dev);
kfree(radio->transfer_buffer);
kfree(radio);
}
static int usb_dsbr100_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct dsbr100_device *radio;
struct v4l2_device *v4l2_dev;
int retval;
radio = kzalloc(sizeof(struct dsbr100_device), GFP_KERNEL);
if (!radio)
return -ENOMEM;
radio->transfer_buffer = kmalloc(TB_LEN, GFP_KERNEL);
if (!(radio->transfer_buffer)) {
kfree(radio);
return -ENOMEM;
}
v4l2_dev = &radio->v4l2_dev;
v4l2_dev->release = usb_dsbr100_release;
retval = v4l2_device_register(&intf->dev, v4l2_dev);
if (retval < 0) {
v4l2_err(v4l2_dev, "couldn't register v4l2_device\n");
goto err_reg_dev;
}
v4l2_ctrl_handler_init(&radio->hdl, 1);
v4l2_ctrl_new_std(&radio->hdl, &usb_dsbr100_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
if (radio->hdl.error) {
retval = radio->hdl.error;
v4l2_err(v4l2_dev, "couldn't register control\n");
goto err_reg_ctrl;
}
mutex_init(&radio->v4l2_lock);
strlcpy(radio->videodev.name, v4l2_dev->name, sizeof(radio->videodev.name));
radio->videodev.v4l2_dev = v4l2_dev;
radio->videodev.fops = &usb_dsbr100_fops;
radio->videodev.ioctl_ops = &usb_dsbr100_ioctl_ops;
radio->videodev.release = video_device_release_empty;
radio->videodev.lock = &radio->v4l2_lock;
radio->videodev.ctrl_handler = &radio->hdl;
set_bit(V4L2_FL_USE_FH_PRIO, &radio->videodev.flags);
radio->usbdev = interface_to_usbdev(intf);
radio->curfreq = FREQ_MIN * FREQ_MUL;
radio->muted = true;
video_set_drvdata(&radio->videodev, radio);
usb_set_intfdata(intf, radio);
retval = video_register_device(&radio->videodev, VFL_TYPE_RADIO, radio_nr);
if (retval == 0)
return 0;
v4l2_err(v4l2_dev, "couldn't register video device\n");
err_reg_ctrl:
v4l2_ctrl_handler_free(&radio->hdl);
v4l2_device_unregister(v4l2_dev);
err_reg_dev:
kfree(radio->transfer_buffer);
kfree(radio);
return retval;
}
