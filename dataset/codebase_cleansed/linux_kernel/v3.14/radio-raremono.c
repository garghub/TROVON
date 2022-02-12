static inline struct raremono_device *to_raremono_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct raremono_device, v4l2_dev);
}
static int raremono_cmd_main(struct raremono_device *radio, unsigned band, unsigned freq)
{
unsigned band_offset;
int ret;
switch (band) {
case BAND_FM:
band_offset = 1;
freq /= 10;
break;
case BAND_AM:
band_offset = 0;
break;
default:
band_offset = 2;
break;
}
radio->buffer[0] = 0x04 + band_offset;
radio->buffer[1] = freq >> 8;
radio->buffer[2] = freq & 0xff;
ret = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
HID_REQ_SET_REPORT,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_OUT,
0x0300 + radio->buffer[0], 2,
radio->buffer, 3, USB_TIMEOUT);
if (ret < 0) {
dev_warn(radio->v4l2_dev.dev, "%s failed (%d)\n", __func__, ret);
return ret;
}
radio->curfreq = (band == BAND_FM) ? freq * 10 : freq;
return 0;
}
static void usb_raremono_disconnect(struct usb_interface *intf)
{
struct raremono_device *radio = to_raremono_dev(usb_get_intfdata(intf));
dev_info(&intf->dev, "Thanko's Raremono disconnected\n");
mutex_lock(&radio->lock);
usb_set_intfdata(intf, NULL);
video_unregister_device(&radio->vdev);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->lock);
v4l2_device_put(&radio->v4l2_dev);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct raremono_device *radio = video_drvdata(file);
strlcpy(v->driver, "radio-raremono", sizeof(v->driver));
strlcpy(v->card, "Thanko's Raremono", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
if (band->tuner != 0)
return -EINVAL;
if (band->index >= ARRAY_SIZE(bands))
return -EINVAL;
*band = bands[band->index];
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct raremono_device *radio = video_drvdata(file);
int ret;
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "AM/FM/SW", sizeof(v->name));
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = AM_FREQ_RANGE_LOW * 16;
v->rangehigh = FM_FREQ_RANGE_HIGH * 16;
v->rxsubchans = V4L2_TUNER_SUB_STEREO | V4L2_TUNER_SUB_MONO;
v->audmode = (radio->curfreq < FM_FREQ_RANGE_LOW) ?
V4L2_TUNER_MODE_MONO : V4L2_TUNER_MODE_STEREO;
memset(radio->buffer, 1, BUFFER_LENGTH);
ret = usb_control_msg(radio->usbdev, usb_rcvctrlpipe(radio->usbdev, 0),
1, 0xa1, 0x030d, 2, radio->buffer, BUFFER_LENGTH, USB_TIMEOUT);
if (ret < 0) {
dev_warn(radio->v4l2_dev.dev, "%s failed (%d)\n", __func__, ret);
return ret;
}
v->signal = ((radio->buffer[1] & 0xf) << 8 | radio->buffer[2]) << 4;
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
struct raremono_device *radio = video_drvdata(file);
u32 freq = f->frequency;
unsigned band;
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (f->frequency >= (FM_FREQ_RANGE_LOW + SW_FREQ_RANGE_HIGH) * 8)
band = BAND_FM;
else if (f->frequency <= (AM_FREQ_RANGE_HIGH + SW_FREQ_RANGE_LOW) * 8)
band = BAND_AM;
else
band = BAND_SW;
freq = clamp_t(u32, f->frequency, bands[band].rangelow, bands[band].rangehigh);
return raremono_cmd_main(radio, band, freq / 16);
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct raremono_device *radio = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = radio->curfreq * 16;
return 0;
}
static int usb_raremono_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct raremono_device *radio;
int retval = 0;
radio = devm_kzalloc(&intf->dev, sizeof(struct raremono_device), GFP_KERNEL);
if (radio)
radio->buffer = devm_kmalloc(&intf->dev, BUFFER_LENGTH, GFP_KERNEL);
if (!radio || !radio->buffer)
return -ENOMEM;
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
msleep(20);
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
HID_REQ_GET_REPORT,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_IN,
1, 2,
radio->buffer, 3, 500);
if (retval != 3 ||
(get_unaligned_be16(&radio->buffer[1]) & 0xfff) == 0x0242) {
dev_info(&intf->dev, "this is not Thanko's Raremono.\n");
return -ENODEV;
}
dev_info(&intf->dev, "Thanko's Raremono connected: (%04X:%04X)\n",
id->idVendor, id->idProduct);
retval = v4l2_device_register(&intf->dev, &radio->v4l2_dev);
if (retval < 0) {
dev_err(&intf->dev, "couldn't register v4l2_device\n");
return retval;
}
mutex_init(&radio->lock);
strlcpy(radio->vdev.name, radio->v4l2_dev.name,
sizeof(radio->vdev.name));
radio->vdev.v4l2_dev = &radio->v4l2_dev;
radio->vdev.fops = &usb_raremono_fops;
radio->vdev.ioctl_ops = &usb_raremono_ioctl_ops;
radio->vdev.lock = &radio->lock;
radio->vdev.release = video_device_release_empty;
usb_set_intfdata(intf, &radio->v4l2_dev);
video_set_drvdata(&radio->vdev, radio);
set_bit(V4L2_FL_USE_FH_PRIO, &radio->vdev.flags);
raremono_cmd_main(radio, BAND_FM, 95160);
retval = video_register_device(&radio->vdev, VFL_TYPE_RADIO, -1);
if (retval == 0) {
dev_info(&intf->dev, "V4L2 device registered as %s\n",
video_device_node_name(&radio->vdev));
return 0;
}
dev_err(&intf->dev, "could not register video device\n");
v4l2_device_unregister(&radio->v4l2_dev);
return retval;
}
