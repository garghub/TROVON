static inline struct keene_device *to_keene_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct keene_device, v4l2_dev);
}
static int keene_cmd_main(struct keene_device *radio, unsigned freq, bool play)
{
unsigned short freq_send = freq ? (freq - 76 * 16000) / 800 : 0;
int ret;
radio->buffer[0] = 0x00;
radio->buffer[1] = 0x50;
radio->buffer[2] = (freq_send >> 8) & 0xff;
radio->buffer[3] = freq_send & 0xff;
radio->buffer[4] = radio->pa;
radio->buffer[5] = (radio->muted ? 4 : 8) | (play ? 1 : 2) |
(freq ? 0x10 : 0);
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
ret = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
9, 0x21, 0x200, 2, radio->buffer, BUFFER_LENGTH, USB_TIMEOUT);
if (ret < 0) {
dev_warn(&radio->vdev.dev, "%s failed (%d)\n", __func__, ret);
return ret;
}
if (freq)
radio->curfreq = freq;
return 0;
}
static int keene_cmd_set(struct keene_device *radio)
{
int ret;
radio->buffer[0] = 0x00;
radio->buffer[1] = 0x51;
radio->buffer[2] = radio->tx;
radio->buffer[3] = (!radio->stereo) | (radio->preemph_75_us ? 4 : 0);
radio->buffer[4] = 0x00;
radio->buffer[5] = 0x00;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
ret = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
9, 0x21, 0x200, 2, radio->buffer, BUFFER_LENGTH, USB_TIMEOUT);
if (ret < 0) {
dev_warn(&radio->vdev.dev, "%s failed (%d)\n", __func__, ret);
return ret;
}
return 0;
}
static void usb_keene_disconnect(struct usb_interface *intf)
{
struct keene_device *radio = to_keene_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
usb_set_intfdata(intf, NULL);
video_unregister_device(&radio->vdev);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->lock);
v4l2_device_put(&radio->v4l2_dev);
}
static int usb_keene_suspend(struct usb_interface *intf, pm_message_t message)
{
struct keene_device *radio = to_keene_dev(usb_get_intfdata(intf));
return keene_cmd_main(radio, 0, false);
}
static int usb_keene_resume(struct usb_interface *intf)
{
struct keene_device *radio = to_keene_dev(usb_get_intfdata(intf));
mdelay(50);
keene_cmd_set(radio);
keene_cmd_main(radio, radio->curfreq, true);
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct keene_device *radio = video_drvdata(file);
strlcpy(v->driver, "radio-keene", sizeof(v->driver));
strlcpy(v->card, "Keene FM Transmitter", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_RADIO | V4L2_CAP_MODULATOR;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_modulator(struct file *file, void *priv,
struct v4l2_modulator *v)
{
struct keene_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->rangelow = FREQ_MIN * FREQ_MUL;
v->rangehigh = FREQ_MAX * FREQ_MUL;
v->txsubchans = radio->stereo ? V4L2_TUNER_SUB_STEREO : V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
return 0;
}
static int vidioc_s_modulator(struct file *file, void *priv,
const struct v4l2_modulator *v)
{
struct keene_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
radio->stereo = (v->txsubchans == V4L2_TUNER_SUB_STEREO);
return keene_cmd_set(radio);
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct keene_device *radio = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
f->frequency = clamp(f->frequency,
FREQ_MIN * FREQ_MUL, FREQ_MAX * FREQ_MUL);
return keene_cmd_main(radio, f->frequency, true);
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct keene_device *radio = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = radio->curfreq;
return 0;
}
static int keene_s_ctrl(struct v4l2_ctrl *ctrl)
{
static const u8 db2tx[] = {
0x03, 0x13, 0x02, 0x12, 0x22, 0x32,
0x21, 0x31, 0x20, 0x30, 0x40, 0x50
};
struct keene_device *radio =
container_of(ctrl->handler, struct keene_device, hdl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
radio->muted = ctrl->val;
return keene_cmd_main(radio, 0, true);
case V4L2_CID_TUNE_POWER_LEVEL:
radio->pa = (ctrl->val - 71) * 100 / 62;
return keene_cmd_main(radio, 0, true);
case V4L2_CID_TUNE_PREEMPHASIS:
radio->preemph_75_us = ctrl->val == V4L2_PREEMPHASIS_75_uS;
return keene_cmd_set(radio);
case V4L2_CID_AUDIO_COMPRESSION_GAIN:
radio->tx = db2tx[(ctrl->val - ctrl->minimum) / ctrl->step];
return keene_cmd_set(radio);
}
return -EINVAL;
}
static void usb_keene_video_device_release(struct v4l2_device *v4l2_dev)
{
struct keene_device *radio = to_keene_dev(v4l2_dev);
v4l2_ctrl_handler_free(&radio->hdl);
kfree(radio->buffer);
kfree(radio);
}
static int usb_keene_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct keene_device *radio;
struct v4l2_ctrl_handler *hdl;
int retval = 0;
if (dev->product && strcmp(dev->product, "B-LINK USB Audio "))
return -ENODEV;
radio = kzalloc(sizeof(struct keene_device), GFP_KERNEL);
if (radio)
radio->buffer = kmalloc(BUFFER_LENGTH, GFP_KERNEL);
if (!radio || !radio->buffer) {
dev_err(&intf->dev, "kmalloc for keene_device failed\n");
kfree(radio);
retval = -ENOMEM;
goto err;
}
hdl = &radio->hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &keene_ctrl_ops, V4L2_CID_AUDIO_MUTE,
0, 1, 1, 0);
v4l2_ctrl_new_std_menu(hdl, &keene_ctrl_ops, V4L2_CID_TUNE_PREEMPHASIS,
V4L2_PREEMPHASIS_75_uS, 1, V4L2_PREEMPHASIS_50_uS);
v4l2_ctrl_new_std(hdl, &keene_ctrl_ops, V4L2_CID_TUNE_POWER_LEVEL,
84, 118, 1, 118);
v4l2_ctrl_new_std(hdl, &keene_ctrl_ops, V4L2_CID_AUDIO_COMPRESSION_GAIN,
-15, 18, 3, 0);
radio->pa = 118;
radio->tx = 0x32;
radio->stereo = true;
radio->curfreq = 95.16 * FREQ_MUL;
if (hdl->error) {
retval = hdl->error;
v4l2_ctrl_handler_free(hdl);
goto err_v4l2;
}
retval = v4l2_device_register(&intf->dev, &radio->v4l2_dev);
if (retval < 0) {
dev_err(&intf->dev, "couldn't register v4l2_device\n");
goto err_v4l2;
}
mutex_init(&radio->lock);
radio->v4l2_dev.ctrl_handler = hdl;
radio->v4l2_dev.release = usb_keene_video_device_release;
strlcpy(radio->vdev.name, radio->v4l2_dev.name,
sizeof(radio->vdev.name));
radio->vdev.v4l2_dev = &radio->v4l2_dev;
radio->vdev.fops = &usb_keene_fops;
radio->vdev.ioctl_ops = &usb_keene_ioctl_ops;
radio->vdev.lock = &radio->lock;
radio->vdev.release = video_device_release_empty;
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
usb_set_intfdata(intf, &radio->v4l2_dev);
video_set_drvdata(&radio->vdev, radio);
set_bit(V4L2_FL_USE_FH_PRIO, &radio->vdev.flags);
retval = video_register_device(&radio->vdev, VFL_TYPE_RADIO, -1);
if (retval < 0) {
dev_err(&intf->dev, "could not register video device\n");
goto err_vdev;
}
v4l2_ctrl_handler_setup(hdl);
dev_info(&intf->dev, "V4L2 device registered as %s\n",
video_device_node_name(&radio->vdev));
return 0;
err_vdev:
v4l2_device_unregister(&radio->v4l2_dev);
err_v4l2:
kfree(radio->buffer);
kfree(radio);
err:
return retval;
}
static int __init keene_init(void)
{
int retval = usb_register(&usb_keene_driver);
if (retval)
pr_err(KBUILD_MODNAME
": usb_register failed. Error number %d\n", retval);
return retval;
}
static void __exit keene_exit(void)
{
usb_deregister(&usb_keene_driver);
}
