static void rt_mute(struct rtrack2 *dev)
{
if (dev->muted)
return;
mutex_lock(&dev->lock);
outb(1, dev->io);
mutex_unlock(&dev->lock);
dev->muted = 1;
}
static void rt_unmute(struct rtrack2 *dev)
{
if(dev->muted == 0)
return;
mutex_lock(&dev->lock);
outb(0, dev->io);
mutex_unlock(&dev->lock);
dev->muted = 0;
}
static void zero(struct rtrack2 *dev)
{
outb_p(1, dev->io);
outb_p(3, dev->io);
outb_p(1, dev->io);
}
static void one(struct rtrack2 *dev)
{
outb_p(5, dev->io);
outb_p(7, dev->io);
outb_p(5, dev->io);
}
static int rt_setfreq(struct rtrack2 *dev, unsigned long freq)
{
int i;
mutex_lock(&dev->lock);
dev->curfreq = freq;
freq = freq / 200 + 856;
outb_p(0xc8, dev->io);
outb_p(0xc9, dev->io);
outb_p(0xc9, dev->io);
for (i = 0; i < 10; i++)
zero(dev);
for (i = 14; i >= 0; i--)
if (freq & (1 << i))
one(dev);
else
zero(dev);
outb_p(0xc8, dev->io);
if (!dev->muted)
outb_p(0, dev->io);
mutex_unlock(&dev->lock);
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-rtrack2", sizeof(v->driver));
strlcpy(v->card, "RadioTrack II", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
}
static int rt_getsigstr(struct rtrack2 *dev)
{
int sig = 1;
mutex_lock(&dev->lock);
if (inb(dev->io) & 2)
sig = 0;
mutex_unlock(&dev->lock);
return sig;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct rtrack2 *rt = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 88 * 16000;
v->rangehigh = 108 * 16000;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xFFFF * rt_getsigstr(rt);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct rtrack2 *rt = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
rt_setfreq(rt, f->frequency);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct rtrack2 *rt = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = rt->curfreq;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
case V4L2_CID_AUDIO_VOLUME:
return v4l2_ctrl_query_fill(qc, 0, 65535, 65535, 65535);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct rtrack2 *rt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = rt->muted;
return 0;
case V4L2_CID_AUDIO_VOLUME:
if (rt->muted)
ctrl->value = 0;
else
ctrl->value = 65535;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct rtrack2 *rt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
rt_mute(rt);
else
rt_unmute(rt);
return 0;
case V4L2_CID_AUDIO_VOLUME:
if (ctrl->value)
rt_unmute(rt);
else
rt_mute(rt);
return 0;
}
return -EINVAL;
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
static int __init rtrack2_init(void)
{
struct rtrack2 *dev = &rtrack2_card;
struct v4l2_device *v4l2_dev = &dev->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "rtrack2", sizeof(v4l2_dev->name));
dev->io = io;
if (dev->io == -1) {
v4l2_err(v4l2_dev, "You must set an I/O address with io=0x20c or io=0x30c\n");
return -EINVAL;
}
if (!request_region(dev->io, 4, "rtrack2")) {
v4l2_err(v4l2_dev, "port 0x%x already in use\n", dev->io);
return -EBUSY;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(dev->io, 4);
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return res;
}
strlcpy(dev->vdev.name, v4l2_dev->name, sizeof(dev->vdev.name));
dev->vdev.v4l2_dev = v4l2_dev;
dev->vdev.fops = &rtrack2_fops;
dev->vdev.ioctl_ops = &rtrack2_ioctl_ops;
dev->vdev.release = video_device_release_empty;
video_set_drvdata(&dev->vdev, dev);
outb(1, dev->io);
dev->muted = 1;
mutex_init(&dev->lock);
if (video_register_device(&dev->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(dev->io, 4);
return -EINVAL;
}
v4l2_info(v4l2_dev, "AIMSlab Radiotrack II card driver.\n");
return 0;
}
static void __exit rtrack2_exit(void)
{
struct rtrack2 *dev = &rtrack2_card;
video_unregister_device(&dev->vdev);
v4l2_device_unregister(&dev->v4l2_dev);
release_region(dev->io, 4);
}
