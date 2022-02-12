static int dsbr100_start(struct dsbr100_device *radio)
{
int retval;
int request;
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
USB_REQ_GET_STATUS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, 0xC7, radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = USB_REQ_GET_STATUS;
goto usb_control_msg_failed;
}
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_ONOFF,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x01, 0x00, radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = DSB100_ONOFF;
goto usb_control_msg_failed;
}
radio->status = STARTED;
return (radio->transfer_buffer)[0];
usb_control_msg_failed:
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, request);
return retval;
}
static int dsbr100_stop(struct dsbr100_device *radio)
{
int retval;
int request;
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
USB_REQ_GET_STATUS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x16, 0x1C, radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = USB_REQ_GET_STATUS;
goto usb_control_msg_failed;
}
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_ONOFF,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, 0x00, radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = DSB100_ONOFF;
goto usb_control_msg_failed;
}
radio->status = STOPPED;
return (radio->transfer_buffer)[0];
usb_control_msg_failed:
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, request);
return retval;
}
static int dsbr100_setfreq(struct dsbr100_device *radio)
{
int retval;
int request;
int freq = (radio->curfreq / 16 * 80) / 1000 + 856;
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
DSB100_TUNE,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
(freq >> 8) & 0x00ff, freq & 0xff,
radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = DSB100_TUNE;
goto usb_control_msg_failed;
}
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
USB_REQ_GET_STATUS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x96, 0xB7, radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = USB_REQ_GET_STATUS;
goto usb_control_msg_failed;
}
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
USB_REQ_GET_STATUS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, 0x24, radio->transfer_buffer, 8, 300);
if (retval < 0) {
request = USB_REQ_GET_STATUS;
goto usb_control_msg_failed;
}
radio->stereo = !((radio->transfer_buffer)[0] & 0x01);
return (radio->transfer_buffer)[0];
usb_control_msg_failed:
radio->stereo = -1;
dev_err(&radio->usbdev->dev,
"%s - usb_control_msg returned %i, request %i\n",
__func__, retval, request);
return retval;
}
static void dsbr100_getstat(struct dsbr100_device *radio)
{
int retval;
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
USB_REQ_GET_STATUS,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00 , 0x24, radio->transfer_buffer, 8, 300);
if (retval < 0) {
radio->stereo = -1;
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
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER;
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
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW;
if(radio->stereo)
v->audmode = V4L2_TUNER_MODE_STEREO;
else
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xffff;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct dsbr100_device *radio = video_drvdata(file);
int retval;
radio->curfreq = f->frequency;
retval = dsbr100_setfreq(radio);
if (retval < 0)
dev_warn(&radio->usbdev->dev, "Set frequency failed\n");
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct dsbr100_device *radio = video_drvdata(file);
f->type = V4L2_TUNER_RADIO;
f->frequency = radio->curfreq;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct dsbr100_device *radio = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = radio->status;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct dsbr100_device *radio = video_drvdata(file);
int retval;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value) {
retval = dsbr100_stop(radio);
if (retval < 0) {
dev_warn(&radio->usbdev->dev,
"Radio did not respond properly\n");
return -EBUSY;
}
} else {
retval = dsbr100_start(radio);
if (retval < 0) {
dev_warn(&radio->usbdev->dev,
"Radio did not respond properly\n");
return -EBUSY;
}
}
return 0;
}
return -EINVAL;
}
static int vidioc_g_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
if (a->index > 1)
return -EINVAL;
strcpy(a->name, "Radio");
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_g_input(struct file *filp, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *filp, void *priv, unsigned int i)
{
return i ? -EINVAL : 0;
}
static int vidioc_s_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
return a->index ? -EINVAL : 0;
}
static void usb_dsbr100_disconnect(struct usb_interface *intf)
{
struct dsbr100_device *radio = usb_get_intfdata(intf);
v4l2_device_get(&radio->v4l2_dev);
mutex_lock(&radio->v4l2_lock);
usb_set_intfdata(intf, NULL);
video_unregister_device(&radio->videodev);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->v4l2_lock);
v4l2_device_put(&radio->v4l2_dev);
}
static int usb_dsbr100_suspend(struct usb_interface *intf, pm_message_t message)
{
struct dsbr100_device *radio = usb_get_intfdata(intf);
int retval;
mutex_lock(&radio->v4l2_lock);
if (radio->status == STARTED) {
retval = dsbr100_stop(radio);
if (retval < 0)
dev_warn(&intf->dev, "dsbr100_stop failed\n");
radio->status = STARTED;
}
mutex_unlock(&radio->v4l2_lock);
dev_info(&intf->dev, "going into suspend..\n");
return 0;
}
static int usb_dsbr100_resume(struct usb_interface *intf)
{
struct dsbr100_device *radio = usb_get_intfdata(intf);
int retval;
mutex_lock(&radio->v4l2_lock);
if (radio->status == STARTED) {
retval = dsbr100_start(radio);
if (retval < 0)
dev_warn(&intf->dev, "dsbr100_start failed\n");
}
mutex_unlock(&radio->v4l2_lock);
dev_info(&intf->dev, "coming out of suspend..\n");
return 0;
}
static void usb_dsbr100_release(struct v4l2_device *v4l2_dev)
{
struct dsbr100_device *radio = v4l2_dev_to_radio(v4l2_dev);
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
kfree(radio->transfer_buffer);
kfree(radio);
return retval;
}
mutex_init(&radio->v4l2_lock);
strlcpy(radio->videodev.name, v4l2_dev->name, sizeof(radio->videodev.name));
radio->videodev.v4l2_dev = v4l2_dev;
radio->videodev.fops = &usb_dsbr100_fops;
radio->videodev.ioctl_ops = &usb_dsbr100_ioctl_ops;
radio->videodev.release = video_device_release_empty;
radio->videodev.lock = &radio->v4l2_lock;
radio->usbdev = interface_to_usbdev(intf);
radio->curfreq = FREQ_MIN * FREQ_MUL;
radio->status = STOPPED;
video_set_drvdata(&radio->videodev, radio);
retval = video_register_device(&radio->videodev, VFL_TYPE_RADIO, radio_nr);
if (retval < 0) {
v4l2_err(v4l2_dev, "couldn't register video device\n");
v4l2_device_unregister(v4l2_dev);
kfree(radio->transfer_buffer);
kfree(radio);
return -EIO;
}
usb_set_intfdata(intf, radio);
return 0;
}
static int __init dsbr100_init(void)
{
int retval = usb_register(&usb_dsbr100_driver);
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return retval;
}
static void __exit dsbr100_exit(void)
{
usb_deregister(&usb_dsbr100_driver);
}
