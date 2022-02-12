static int volconvert(int level)
{
level >>= 14;
level &= 3;
switch (level) {
case 0:
return 0;
case 1:
return 1;
case 2:
return 4;
case 3:
return 5;
}
return 0;
}
static void send_0_byte(struct aztech *az)
{
udelay(radio_wait_time);
outb_p(2 + volconvert(az->curvol), az->io);
outb_p(64 + 2 + volconvert(az->curvol), az->io);
}
static void send_1_byte(struct aztech *az)
{
udelay (radio_wait_time);
outb_p(128 + 2 + volconvert(az->curvol), az->io);
outb_p(128 + 64 + 2 + volconvert(az->curvol), az->io);
}
static int az_setvol(struct aztech *az, int vol)
{
mutex_lock(&az->lock);
outb(volconvert(vol), az->io);
mutex_unlock(&az->lock);
return 0;
}
static int az_getsigstr(struct aztech *az)
{
int sig = 1;
mutex_lock(&az->lock);
if (inb(az->io) & 2)
sig = 0;
mutex_unlock(&az->lock);
return sig;
}
static int az_getstereo(struct aztech *az)
{
int stereo = 1;
mutex_lock(&az->lock);
if (inb(az->io) & 1)
stereo = 0;
mutex_unlock(&az->lock);
return stereo;
}
static int az_setfreq(struct aztech *az, unsigned long frequency)
{
int i;
mutex_lock(&az->lock);
az->curfreq = frequency;
frequency += 171200;
frequency /= 800;
send_0_byte(az);
for (i = 0; i < 13; i++)
if (frequency & (1 << i))
send_1_byte(az);
else
send_0_byte(az);
send_0_byte(az);
send_0_byte(az);
send_0_byte(az);
if (az->stereo)
send_1_byte(az);
else
send_0_byte(az);
send_1_byte(az);
send_0_byte(az);
send_0_byte(az);
send_1_byte(az);
send_0_byte(az);
send_1_byte(az);
udelay(radio_wait_time);
outb_p(128 + 64 + volconvert(az->curvol), az->io);
mutex_unlock(&az->lock);
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-aztech", sizeof(v->driver));
strlcpy(v->card, "Aztech Radio", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct aztech *az = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 87 * 16000;
v->rangehigh = 108 * 16000;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW;
if (az_getstereo(az))
v->audmode = V4L2_TUNER_MODE_STEREO;
else
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xFFFF * az_getsigstr(az);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
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
static int vidioc_g_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
a->index = 0;
strlcpy(a->name, "Radio", sizeof(a->name));
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_s_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
return a->index ? -EINVAL : 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct aztech *az = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
az_setfreq(az, f->frequency);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct aztech *az = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = az->curfreq;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
case V4L2_CID_AUDIO_VOLUME:
return v4l2_ctrl_query_fill(qc, 0, 0xff, 1, 0xff);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct aztech *az = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (az->curvol == 0)
ctrl->value = 1;
else
ctrl->value = 0;
return 0;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = az->curvol * 6554;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct aztech *az = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
az_setvol(az, 0);
else
az_setvol(az, az->curvol);
return 0;
case V4L2_CID_AUDIO_VOLUME:
az_setvol(az, ctrl->value);
return 0;
}
return -EINVAL;
}
static int __init aztech_init(void)
{
struct aztech *az = &aztech_card;
struct v4l2_device *v4l2_dev = &az->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "aztech", sizeof(v4l2_dev->name));
az->io = io;
if (az->io == -1) {
v4l2_err(v4l2_dev, "you must set an I/O address with io=0x350 or 0x358\n");
return -EINVAL;
}
if (!request_region(az->io, 2, "aztech")) {
v4l2_err(v4l2_dev, "port 0x%x already in use\n", az->io);
return -EBUSY;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(az->io, 2);
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return res;
}
mutex_init(&az->lock);
strlcpy(az->vdev.name, v4l2_dev->name, sizeof(az->vdev.name));
az->vdev.v4l2_dev = v4l2_dev;
az->vdev.fops = &aztech_fops;
az->vdev.ioctl_ops = &aztech_ioctl_ops;
az->vdev.release = video_device_release_empty;
video_set_drvdata(&az->vdev, az);
outb(0, az->io);
if (video_register_device(&az->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(az->io, 2);
return -EINVAL;
}
v4l2_info(v4l2_dev, "Aztech radio card driver v1.00/19990224 rkroll@exploits.org\n");
return 0;
}
static void __exit aztech_exit(void)
{
struct aztech *az = &aztech_card;
video_unregister_device(&az->vdev);
v4l2_device_unregister(&az->v4l2_dev);
release_region(az->io, 2);
}
