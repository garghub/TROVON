static int zol_setvol(struct zoltrix *zol, int vol)
{
zol->curvol = vol;
if (zol->muted)
return 0;
mutex_lock(&zol->lock);
if (vol == 0) {
outb(0, zol->io);
outb(0, zol->io);
inb(zol->io + 3);
mutex_unlock(&zol->lock);
return 0;
}
outb(zol->curvol-1, zol->io);
msleep(10);
inb(zol->io + 2);
mutex_unlock(&zol->lock);
return 0;
}
static void zol_mute(struct zoltrix *zol)
{
zol->muted = 1;
mutex_lock(&zol->lock);
outb(0, zol->io);
outb(0, zol->io);
inb(zol->io + 3);
mutex_unlock(&zol->lock);
}
static void zol_unmute(struct zoltrix *zol)
{
zol->muted = 0;
zol_setvol(zol, zol->curvol);
}
static int zol_setfreq(struct zoltrix *zol, unsigned long freq)
{
struct v4l2_device *v4l2_dev = &zol->v4l2_dev;
unsigned long long bitmask, f, m;
unsigned int stereo = zol->stereo;
int i;
if (freq == 0) {
v4l2_warn(v4l2_dev, "cannot set a frequency of 0.\n");
return -EINVAL;
}
m = (freq / 160 - 8800) * 2;
f = (unsigned long long)m + 0x4d1c;
bitmask = 0xc480402c10080000ull;
i = 45;
mutex_lock(&zol->lock);
zol->curfreq = freq;
outb(0, zol->io);
outb(0, zol->io);
inb(zol->io + 3);
outb(0x40, zol->io);
outb(0xc0, zol->io);
bitmask = (bitmask ^ ((f & 0xff) << 47) ^ ((f & 0xff00) << 30) ^ (stereo << 31));
while (i--) {
if ((bitmask & 0x8000000000000000ull) != 0) {
outb(0x80, zol->io);
udelay(50);
outb(0x00, zol->io);
udelay(50);
outb(0x80, zol->io);
udelay(50);
} else {
outb(0xc0, zol->io);
udelay(50);
outb(0x40, zol->io);
udelay(50);
outb(0xc0, zol->io);
udelay(50);
}
bitmask *= 2;
}
outb(0x80, zol->io);
outb(0xc0, zol->io);
outb(0x40, zol->io);
udelay(1000);
inb(zol->io + 2);
udelay(1000);
if (zol->muted) {
outb(0, zol->io);
outb(0, zol->io);
inb(zol->io + 3);
udelay(1000);
}
mutex_unlock(&zol->lock);
if (!zol->muted)
zol_setvol(zol, zol->curvol);
return 0;
}
static int zol_getsigstr(struct zoltrix *zol)
{
int a, b;
mutex_lock(&zol->lock);
outb(0x00, zol->io);
outb(zol->curvol, zol->io);
msleep(20);
a = inb(zol->io);
msleep(10);
b = inb(zol->io);
mutex_unlock(&zol->lock);
if (a != b)
return 0;
return a == 0xcf || a == 0xdf || a == 0xef;
}
static int zol_is_stereo(struct zoltrix *zol)
{
int x1, x2;
mutex_lock(&zol->lock);
outb(0x00, zol->io);
outb(zol->curvol, zol->io);
msleep(20);
x1 = inb(zol->io);
msleep(10);
x2 = inb(zol->io);
mutex_unlock(&zol->lock);
return x1 == x2 && x1 == 0xcf;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-zoltrix", sizeof(v->driver));
strlcpy(v->card, "Zoltrix Radio", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct zoltrix *zol = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 88 * 16000;
v->rangehigh = 108 * 16000;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW;
if (zol_is_stereo(zol))
v->audmode = V4L2_TUNER_MODE_STEREO;
else
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xFFFF * zol_getsigstr(zol);
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
struct zoltrix *zol = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (zol_setfreq(zol, f->frequency) != 0)
return -EINVAL;
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct zoltrix *zol = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = zol->curfreq;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
case V4L2_CID_AUDIO_VOLUME:
return v4l2_ctrl_query_fill(qc, 0, 65535, 4096, 65535);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct zoltrix *zol = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = zol->muted;
return 0;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = zol->curvol * 4096;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct zoltrix *zol = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
zol_mute(zol);
else {
zol_unmute(zol);
zol_setvol(zol, zol->curvol);
}
return 0;
case V4L2_CID_AUDIO_VOLUME:
zol_setvol(zol, ctrl->value / 4096);
return 0;
}
zol->stereo = 1;
if (zol_setfreq(zol, zol->curfreq) != 0)
return -EINVAL;
#if 0
if (v->mode & VIDEO_SOUND_STEREO) {
zol->stereo = 1;
zol_setfreq(zol, zol->curfreq);
}
if (v->mode & VIDEO_SOUND_MONO) {
zol->stereo = 0;
zol_setfreq(zol, zol->curfreq);
}
#endif
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
static int __init zoltrix_init(void)
{
struct zoltrix *zol = &zoltrix_card;
struct v4l2_device *v4l2_dev = &zol->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "zoltrix", sizeof(v4l2_dev->name));
zol->io = io;
if (zol->io == -1) {
v4l2_err(v4l2_dev, "You must set an I/O address with io=0x20c or 0x30c\n");
return -EINVAL;
}
if (zol->io != 0x20c && zol->io != 0x30c) {
v4l2_err(v4l2_dev, "invalid port, try 0x20c or 0x30c\n");
return -ENXIO;
}
if (!request_region(zol->io, 2, "zoltrix")) {
v4l2_err(v4l2_dev, "port 0x%x already in use\n", zol->io);
return -EBUSY;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(zol->io, 2);
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return res;
}
mutex_init(&zol->lock);
outb(0, zol->io);
outb(0, zol->io);
msleep(20);
inb(zol->io + 3);
zol->curvol = 0;
zol->stereo = 1;
strlcpy(zol->vdev.name, v4l2_dev->name, sizeof(zol->vdev.name));
zol->vdev.v4l2_dev = v4l2_dev;
zol->vdev.fops = &zoltrix_fops;
zol->vdev.ioctl_ops = &zoltrix_ioctl_ops;
zol->vdev.release = video_device_release_empty;
video_set_drvdata(&zol->vdev, zol);
if (video_register_device(&zol->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(zol->io, 2);
return -EINVAL;
}
v4l2_info(v4l2_dev, "Zoltrix Radio Plus card driver.\n");
return 0;
}
static void __exit zoltrix_exit(void)
{
struct zoltrix *zol = &zoltrix_card;
video_unregister_device(&zol->vdev);
v4l2_device_unregister(&zol->v4l2_dev);
release_region(zol->io, 2);
}
