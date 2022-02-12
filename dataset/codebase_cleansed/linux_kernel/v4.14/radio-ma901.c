static inline struct ma901radio_device *to_ma901radio_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct ma901radio_device, v4l2_dev);
}
static int ma901radio_set_freq(struct ma901radio_device *radio, int freq)
{
unsigned int freq_send = 0x300 + (freq >> 5) / 25;
int retval;
radio->buffer[0] = 0x0a;
radio->buffer[1] = MA901_RADIO_SET_FREQ;
radio->buffer[2] = ((freq_send >> 8) & 0xff) + 0x80;
radio->buffer[3] = freq_send & 0xff;
radio->buffer[4] = 0x00;
radio->buffer[5] = 0x00;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
retval = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
9, 0x21, 0x0300, 0,
radio->buffer, BUFFER_LENGTH, USB_TIMEOUT);
if (retval < 0)
return retval;
radio->curfreq = freq;
return 0;
}
static int ma901radio_set_volume(struct ma901radio_device *radio, u16 vol_to_set)
{
int retval;
radio->buffer[0] = 0x0a;
radio->buffer[1] = MA901_RADIO_SET_VOLUME;
radio->buffer[2] = 0xc2;
radio->buffer[3] = vol_to_set + 0x20;
radio->buffer[4] = 0x00;
radio->buffer[5] = 0x00;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
retval = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
9, 0x21, 0x0300, 0,
radio->buffer, BUFFER_LENGTH, USB_TIMEOUT);
if (retval < 0)
return retval;
radio->volume = vol_to_set;
return retval;
}
static int ma901_set_stereo(struct ma901radio_device *radio, u8 stereo)
{
int retval;
radio->buffer[0] = 0x0a;
radio->buffer[1] = MA901_RADIO_SET_MONO_STEREO;
radio->buffer[2] = stereo;
radio->buffer[3] = 0x00;
radio->buffer[4] = 0x00;
radio->buffer[5] = 0x00;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
retval = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
9, 0x21, 0x0300, 0,
radio->buffer, BUFFER_LENGTH, USB_TIMEOUT);
if (retval < 0)
return retval;
if (stereo == MA901_WANT_STEREO)
radio->stereo = V4L2_TUNER_MODE_STEREO;
else
radio->stereo = V4L2_TUNER_MODE_MONO;
return retval;
}
static void usb_ma901radio_disconnect(struct usb_interface *intf)
{
struct ma901radio_device *radio = to_ma901radio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
video_unregister_device(&radio->vdev);
usb_set_intfdata(intf, NULL);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->lock);
v4l2_device_put(&radio->v4l2_dev);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct ma901radio_device *radio = video_drvdata(file);
strlcpy(v->driver, "radio-ma901", sizeof(v->driver));
strlcpy(v->card, "Masterkit MA901 USB FM Radio", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_RADIO | V4L2_CAP_TUNER;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct ma901radio_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
v->signal = 0;
strcpy(v->name, "FM");
v->type = V4L2_TUNER_RADIO;
v->rangelow = FREQ_MIN * FREQ_MUL;
v->rangehigh = FREQ_MAX * FREQ_MUL;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
v->audmode = radio->stereo ?
V4L2_TUNER_MODE_STEREO : V4L2_TUNER_MODE_MONO;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct ma901radio_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
switch (v->audmode) {
case V4L2_TUNER_MODE_MONO:
return ma901_set_stereo(radio, MA901_WANT_MONO);
default:
return ma901_set_stereo(radio, MA901_WANT_STEREO);
}
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct ma901radio_device *radio = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
return ma901radio_set_freq(radio, clamp_t(unsigned, f->frequency,
FREQ_MIN * FREQ_MUL, FREQ_MAX * FREQ_MUL));
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct ma901radio_device *radio = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->frequency = radio->curfreq;
return 0;
}
static int usb_ma901radio_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ma901radio_device *radio =
container_of(ctrl->handler, struct ma901radio_device, hdl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_VOLUME:
return ma901radio_set_volume(radio, (u16)ctrl->val);
}
return -EINVAL;
}
static int usb_ma901radio_suspend(struct usb_interface *intf, pm_message_t message)
{
return 0;
}
static int usb_ma901radio_resume(struct usb_interface *intf)
{
return 0;
}
static void usb_ma901radio_release(struct v4l2_device *v4l2_dev)
{
struct ma901radio_device *radio = to_ma901radio_dev(v4l2_dev);
v4l2_ctrl_handler_free(&radio->hdl);
v4l2_device_unregister(&radio->v4l2_dev);
kfree(radio->buffer);
kfree(radio);
}
static int usb_ma901radio_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct ma901radio_device *radio;
int retval = 0;
if (dev->product && dev->manufacturer &&
(strncmp(dev->product, "MA901", 5) != 0
|| strncmp(dev->manufacturer, "www.masterkit.ru", 16) != 0))
return -ENODEV;
radio = kzalloc(sizeof(struct ma901radio_device), GFP_KERNEL);
if (!radio) {
dev_err(&intf->dev, "kzalloc for ma901radio_device failed\n");
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
v4l2_ctrl_new_std(&radio->hdl, &usb_ma901radio_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, MA901_VOLUME_MIN,
MA901_VOLUME_MAX, 1, MA901_VOLUME_MAX);
if (radio->hdl.error) {
retval = radio->hdl.error;
dev_err(&intf->dev, "couldn't register control\n");
goto err_ctrl;
}
mutex_init(&radio->lock);
radio->v4l2_dev.ctrl_handler = &radio->hdl;
radio->v4l2_dev.release = usb_ma901radio_release;
strlcpy(radio->vdev.name, radio->v4l2_dev.name,
sizeof(radio->vdev.name));
radio->vdev.v4l2_dev = &radio->v4l2_dev;
radio->vdev.fops = &usb_ma901radio_fops;
radio->vdev.ioctl_ops = &usb_ma901radio_ioctl_ops;
radio->vdev.release = video_device_release_empty;
radio->vdev.lock = &radio->lock;
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
usb_set_intfdata(intf, &radio->v4l2_dev);
radio->curfreq = 95.21 * FREQ_MUL;
video_set_drvdata(&radio->vdev, radio);
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
