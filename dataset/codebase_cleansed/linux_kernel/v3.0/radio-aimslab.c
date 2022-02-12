static void rt_decvol(struct rtrack *rt)
{
outb(0x58, rt->io);
msleep(100);
outb(0xd8, rt->io);
}
static void rt_incvol(struct rtrack *rt)
{
outb(0x98, rt->io);
msleep(100);
outb(0xd8, rt->io);
}
static void rt_mute(struct rtrack *rt)
{
rt->muted = 1;
mutex_lock(&rt->lock);
outb(0xd0, rt->io);
mutex_unlock(&rt->lock);
}
static int rt_setvol(struct rtrack *rt, int vol)
{
int i;
mutex_lock(&rt->lock);
if (vol == rt->curvol) {
if (rt->muted) {
rt->muted = 0;
outb(0xd8, rt->io);
}
mutex_unlock(&rt->lock);
return 0;
}
if (vol == 0) {
outb(0x48, rt->io);
msleep(2000);
outb(0xd0, rt->io);
rt->curvol = 0;
mutex_unlock(&rt->lock);
return 0;
}
rt->muted = 0;
if (vol > rt->curvol)
for (i = rt->curvol; i < vol; i++)
rt_incvol(rt);
else
for (i = rt->curvol; i > vol; i--)
rt_decvol(rt);
rt->curvol = vol;
mutex_unlock(&rt->lock);
return 0;
}
static void send_0_byte(struct rtrack *rt)
{
if (rt->curvol == 0 || rt->muted) {
outb_p(128+64+16+ 1, rt->io);
outb_p(128+64+16+2+1, rt->io);
}
else {
outb_p(128+64+16+8+ 1, rt->io);
outb_p(128+64+16+8+2+1, rt->io);
}
msleep(1);
}
static void send_1_byte(struct rtrack *rt)
{
if (rt->curvol == 0 || rt->muted) {
outb_p(128+64+16+4 +1, rt->io);
outb_p(128+64+16+4+2+1, rt->io);
}
else {
outb_p(128+64+16+8+4 +1, rt->io);
outb_p(128+64+16+8+4+2+1, rt->io);
}
msleep(1);
}
static int rt_setfreq(struct rtrack *rt, unsigned long freq)
{
int i;
mutex_lock(&rt->lock);
rt->curfreq = freq;
freq += 171200;
freq /= 800;
send_0_byte(rt);
for (i = 0; i < 13; i++)
if (freq & (1 << i))
send_1_byte(rt);
else
send_0_byte(rt);
send_0_byte(rt);
send_0_byte(rt);
send_0_byte(rt);
send_0_byte(rt);
send_0_byte(rt);
send_0_byte(rt);
send_0_byte(rt);
send_1_byte(rt);
send_0_byte(rt);
send_1_byte(rt);
if (rt->curvol == 0 || rt->muted)
outb(0xd0, rt->io);
else
outb(0xd8, rt->io);
mutex_unlock(&rt->lock);
return 0;
}
static int rt_getsigstr(struct rtrack *rt)
{
int sig = 1;
mutex_lock(&rt->lock);
if (inb(rt->io) & 2)
sig = 0;
mutex_unlock(&rt->lock);
return sig;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-aimslab", sizeof(v->driver));
strlcpy(v->card, "RadioTrack", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct rtrack *rt = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 87 * 16000;
v->rangehigh = 108 * 16000;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xffff * rt_getsigstr(rt);
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
struct rtrack *rt = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
rt_setfreq(rt, f->frequency);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct rtrack *rt = video_drvdata(file);
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
return v4l2_ctrl_query_fill(qc, 0, 0xff, 1, 0xff);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct rtrack *rt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = rt->muted;
return 0;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = rt->curvol;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct rtrack *rt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
rt_mute(rt);
else
rt_setvol(rt, rt->curvol);
return 0;
case V4L2_CID_AUDIO_VOLUME:
rt_setvol(rt, ctrl->value);
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
static int __init rtrack_init(void)
{
struct rtrack *rt = &rtrack_card;
struct v4l2_device *v4l2_dev = &rt->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "rtrack", sizeof(v4l2_dev->name));
rt->io = io;
if (rt->io == -1) {
v4l2_err(v4l2_dev, "you must set an I/O address with io=0x20f or 0x30f\n");
return -EINVAL;
}
if (!request_region(rt->io, 2, "rtrack")) {
v4l2_err(v4l2_dev, "port 0x%x already in use\n", rt->io);
return -EBUSY;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(rt->io, 2);
v4l2_err(v4l2_dev, "could not register v4l2_device\n");
return res;
}
strlcpy(rt->vdev.name, v4l2_dev->name, sizeof(rt->vdev.name));
rt->vdev.v4l2_dev = v4l2_dev;
rt->vdev.fops = &rtrack_fops;
rt->vdev.ioctl_ops = &rtrack_ioctl_ops;
rt->vdev.release = video_device_release_empty;
video_set_drvdata(&rt->vdev, rt);
mutex_init(&rt->lock);
outb(0x48, rt->io);
msleep(2000);
outb(0xc0, rt->io);
if (video_register_device(&rt->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(&rt->v4l2_dev);
release_region(rt->io, 2);
return -EINVAL;
}
v4l2_info(v4l2_dev, "AIMSlab RadioTrack/RadioReveal card driver.\n");
return 0;
}
static void __exit rtrack_exit(void)
{
struct rtrack *rt = &rtrack_card;
video_unregister_device(&rt->vdev);
v4l2_device_unregister(&rt->v4l2_dev);
release_region(rt->io, 2);
}
