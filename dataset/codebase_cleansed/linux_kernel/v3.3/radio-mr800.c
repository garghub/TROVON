static inline struct amradio_device *to_amradio_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct amradio_device, v4l2_dev);
}
static int amradio_set_mute(struct amradio_device *radio, char argument)
{
int retval;
int size;
radio->buffer[0] = 0x00;
radio->buffer[1] = 0x55;
radio->buffer[2] = 0xaa;
radio->buffer[3] = 0x00;
radio->buffer[4] = AMRADIO_SET_MUTE;
radio->buffer[5] = argument;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
retval = usb_bulk_msg(radio->usbdev, usb_sndintpipe(radio->usbdev, 2),
(void *) (radio->buffer), BUFFER_LENGTH, &size, USB_TIMEOUT);
if (retval < 0 || size != BUFFER_LENGTH) {
amradio_dev_warn(&radio->videodev.dev, "set mute failed\n");
return retval;
}
radio->muted = argument;
return retval;
}
static int amradio_setfreq(struct amradio_device *radio, int freq)
{
int retval;
int size;
unsigned short freq_send = 0x10 + (freq >> 3) / 25;
radio->buffer[0] = 0x00;
radio->buffer[1] = 0x55;
radio->buffer[2] = 0xaa;
radio->buffer[3] = 0x03;
radio->buffer[4] = AMRADIO_SET_FREQ;
radio->buffer[5] = 0x00;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x08;
retval = usb_bulk_msg(radio->usbdev, usb_sndintpipe(radio->usbdev, 2),
(void *) (radio->buffer), BUFFER_LENGTH, &size, USB_TIMEOUT);
if (retval < 0 || size != BUFFER_LENGTH)
goto out_err;
radio->buffer[0] = (freq_send >> 8) & 0xff;
radio->buffer[1] = freq_send & 0xff;
radio->buffer[2] = 0x01;
radio->buffer[3] = 0x00;
radio->buffer[4] = 0x00;
radio->buffer[7] = 0x00;
retval = usb_bulk_msg(radio->usbdev, usb_sndintpipe(radio->usbdev, 2),
(void *) (radio->buffer), BUFFER_LENGTH, &size, USB_TIMEOUT);
if (retval < 0 || size != BUFFER_LENGTH)
goto out_err;
radio->curfreq = freq;
goto out;
out_err:
amradio_dev_warn(&radio->videodev.dev, "set frequency failed\n");
out:
return retval;
}
static int amradio_set_stereo(struct amradio_device *radio, char argument)
{
int retval;
int size;
radio->buffer[0] = 0x00;
radio->buffer[1] = 0x55;
radio->buffer[2] = 0xaa;
radio->buffer[3] = 0x00;
radio->buffer[4] = AMRADIO_SET_MONO;
radio->buffer[5] = argument;
radio->buffer[6] = 0x00;
radio->buffer[7] = 0x00;
retval = usb_bulk_msg(radio->usbdev, usb_sndintpipe(radio->usbdev, 2),
(void *) (radio->buffer), BUFFER_LENGTH, &size, USB_TIMEOUT);
if (retval < 0 || size != BUFFER_LENGTH) {
amradio_dev_warn(&radio->videodev.dev, "set stereo failed\n");
return retval;
}
if (argument == WANT_STEREO)
radio->stereo = 1;
else
radio->stereo = 0;
return retval;
}
static void usb_amradio_disconnect(struct usb_interface *intf)
{
struct amradio_device *radio = to_amradio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
get_device(&radio->videodev.dev);
v4l2_device_disconnect(&radio->v4l2_dev);
video_unregister_device(&radio->videodev);
mutex_unlock(&radio->lock);
put_device(&radio->videodev.dev);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct amradio_device *radio = file->private_data;
strlcpy(v->driver, "radio-mr800", sizeof(v->driver));
strlcpy(v->card, "AverMedia MR 800 USB FM Radio", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->capabilities = V4L2_CAP_TUNER;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct amradio_device *radio = file->private_data;
int retval;
if (v->index > 0)
return -EINVAL;
retval = amradio_set_stereo(radio, WANT_STEREO);
strcpy(v->name, "FM");
v->type = V4L2_TUNER_RADIO;
v->rangelow = FREQ_MIN * FREQ_MUL;
v->rangehigh = FREQ_MAX * FREQ_MUL;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW;
if (radio->stereo)
v->audmode = V4L2_TUNER_MODE_STEREO;
else
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xffff;
v->afc = 0;
return retval;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct amradio_device *radio = file->private_data;
int retval = -EINVAL;
if (v->index > 0)
return -EINVAL;
switch (v->audmode) {
case V4L2_TUNER_MODE_MONO:
retval = amradio_set_stereo(radio, WANT_MONO);
break;
case V4L2_TUNER_MODE_STEREO:
retval = amradio_set_stereo(radio, WANT_STEREO);
break;
}
return retval;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct amradio_device *radio = file->private_data;
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
return amradio_setfreq(radio, f->frequency);
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct amradio_device *radio = file->private_data;
if (f->tuner != 0)
return -EINVAL;
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
struct amradio_device *radio = file->private_data;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = radio->muted;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct amradio_device *radio = file->private_data;
int retval = -EINVAL;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
retval = amradio_set_mute(radio, AMRADIO_STOP);
else
retval = amradio_set_mute(radio, AMRADIO_START);
break;
}
return retval;
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
static int vidioc_s_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
if (a->index != 0)
return -EINVAL;
return 0;
}
static int vidioc_g_input(struct file *filp, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *filp, void *priv, unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int usb_amradio_init(struct amradio_device *radio)
{
int retval;
retval = amradio_set_mute(radio, AMRADIO_STOP);
if (retval)
goto out_err;
retval = amradio_set_stereo(radio, WANT_STEREO);
if (retval)
goto out_err;
radio->initialized = 1;
goto out;
out_err:
amradio_dev_err(&radio->videodev.dev, "initialization failed\n");
out:
return retval;
}
static int usb_amradio_open(struct file *file)
{
struct amradio_device *radio = video_drvdata(file);
int retval;
file->private_data = radio;
retval = usb_autopm_get_interface(radio->intf);
if (retval)
return retval;
if (unlikely(!radio->initialized)) {
retval = usb_amradio_init(radio);
if (retval)
usb_autopm_put_interface(radio->intf);
}
return retval;
}
static int usb_amradio_close(struct file *file)
{
struct amradio_device *radio = file->private_data;
if (video_is_registered(&radio->videodev))
usb_autopm_put_interface(radio->intf);
return 0;
}
static int usb_amradio_suspend(struct usb_interface *intf, pm_message_t message)
{
struct amradio_device *radio = to_amradio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
if (!radio->muted && radio->initialized) {
amradio_set_mute(radio, AMRADIO_STOP);
radio->muted = 0;
}
mutex_unlock(&radio->lock);
dev_info(&intf->dev, "going into suspend..\n");
return 0;
}
static int usb_amradio_resume(struct usb_interface *intf)
{
struct amradio_device *radio = to_amradio_dev(usb_get_intfdata(intf));
mutex_lock(&radio->lock);
if (unlikely(!radio->initialized))
goto unlock;
if (radio->stereo)
amradio_set_stereo(radio, WANT_STEREO);
else
amradio_set_stereo(radio, WANT_MONO);
amradio_setfreq(radio, radio->curfreq);
if (!radio->muted)
amradio_set_mute(radio, AMRADIO_START);
unlock:
mutex_unlock(&radio->lock);
dev_info(&intf->dev, "coming out of suspend..\n");
return 0;
}
static void usb_amradio_video_device_release(struct video_device *videodev)
{
struct amradio_device *radio = video_get_drvdata(videodev);
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
mutex_init(&radio->lock);
strlcpy(radio->videodev.name, radio->v4l2_dev.name,
sizeof(radio->videodev.name));
radio->videodev.v4l2_dev = &radio->v4l2_dev;
radio->videodev.fops = &usb_amradio_fops;
radio->videodev.ioctl_ops = &usb_amradio_ioctl_ops;
radio->videodev.release = usb_amradio_video_device_release;
radio->videodev.lock = &radio->lock;
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
radio->curfreq = 95.16 * FREQ_MUL;
video_set_drvdata(&radio->videodev, radio);
retval = video_register_device(&radio->videodev, VFL_TYPE_RADIO,
radio_nr);
if (retval < 0) {
dev_err(&intf->dev, "could not register video device\n");
goto err_vdev;
}
return 0;
err_vdev:
v4l2_device_unregister(&radio->v4l2_dev);
err_v4l2:
kfree(radio->buffer);
err_nobuf:
kfree(radio);
err:
return retval;
}
