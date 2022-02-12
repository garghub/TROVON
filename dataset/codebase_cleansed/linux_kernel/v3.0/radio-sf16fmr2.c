static inline void wait(int n, int io)
{
for (; n; --n)
inb(io);
}
static void outbits(int bits, unsigned int data, int nWait, int io)
{
int bit;
for (; --bits >= 0;) {
bit = (data >> bits) & 1;
outb(bit, io);
wait(nWait, io);
outb(bit | 2, io);
wait(nWait, io);
outb(bit, io);
wait(nWait, io);
}
}
static inline void fmr2_mute(int io)
{
outb(0x00, io);
wait(4, io);
}
static inline void fmr2_unmute(int io)
{
outb(0x04, io);
wait(4, io);
}
static inline int fmr2_stereo_mode(int io)
{
int n = inb(io);
outb(6, io);
inb(io);
n = ((n >> 3) & 1) ^ 1;
debug_print((KERN_DEBUG "stereo: %d\n", n));
return n;
}
static int fmr2_product_info(struct fmr2 *dev)
{
int n = inb(dev->io);
n &= 0xC1;
if (n == 0) {
dev->card_type = 12;
return 0;
}
dev->card_type = (n == 128) ? 11 : 0;
return n;
}
static inline int fmr2_getsigstr(struct fmr2 *dev)
{
int res = 0xffff;
outb(5, dev->io);
wait(4, dev->io);
if (!(inb(dev->io) & 1))
res = 0;
debug_print((KERN_DEBUG "signal: %d\n", res));
return res;
}
static int fmr2_setfreq(struct fmr2 *dev)
{
unsigned long freq = dev->curfreq;
fmr2_mute(dev->io);
outbits(9, 0x2, 3, dev->io);
outbits(16, RSF16_ENCODE(freq), 2, dev->io);
fmr2_unmute(dev->io);
msleep(110);
dev->stereo = fmr2_stereo_mode(dev->io);
return 0;
}
static int fmr2_setvolume(struct fmr2 *dev)
{
int vol[16] = { 0x021, 0x084, 0x090, 0x104,
0x110, 0x204, 0x210, 0x402,
0x404, 0x408, 0x410, 0x801,
0x802, 0x804, 0x808, 0x810 };
int i, a;
int n = vol[dev->curvol & 0x0f];
if (dev->card_type != 11)
return 1;
for (i = 12; --i >= 0; ) {
a = ((n >> i) & 1) << 6;
outb(a | 4, dev->io);
wait(4, dev->io);
outb(a | 0x24, dev->io);
wait(4, dev->io);
outb(a | 4, dev->io);
wait(4, dev->io);
}
for (i = 6; --i >= 0; ) {
a = ((0x18 >> i) & 1) << 6;
outb(a | 4, dev->io);
wait(4, dev->io);
outb(a | 0x24, dev->io);
wait(4, dev->io);
outb(a | 4, dev->io);
wait(4, dev->io);
}
wait(4, dev->io);
outb(0x14, dev->io);
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-sf16fmr2", sizeof(v->driver));
strlcpy(v->card, "SF16-FMR2 radio", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct fmr2 *fmr2 = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = RSF16_MINFREQ;
v->rangehigh = RSF16_MAXFREQ;
v->rxsubchans = fmr2->stereo ? V4L2_TUNER_SUB_STEREO :
V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_STEREO;
mutex_lock(&fmr2->lock);
v->signal = fmr2_getsigstr(fmr2);
mutex_unlock(&fmr2->lock);
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
struct fmr2 *fmr2 = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (f->frequency < RSF16_MINFREQ ||
f->frequency > RSF16_MAXFREQ)
return -EINVAL;
fmr2->curfreq = (f->frequency / 200) * 200;
if (fmr2->curvol && !fmr2->mute) {
mutex_lock(&fmr2->lock);
fmr2_setfreq(fmr2);
mutex_unlock(&fmr2->lock);
}
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct fmr2 *fmr2 = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = fmr2->curfreq;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
struct fmr2 *fmr2 = video_drvdata(file);
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
case V4L2_CID_AUDIO_VOLUME:
if (fmr2->card_type == 11)
return v4l2_ctrl_query_fill(qc, 0, 15, 1, 0);
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 0);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct fmr2 *fmr2 = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = fmr2->mute;
return 0;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = fmr2->curvol;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct fmr2 *fmr2 = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
fmr2->mute = ctrl->value;
break;
case V4L2_CID_AUDIO_VOLUME:
fmr2->curvol = ctrl->value;
break;
default:
return -EINVAL;
}
#ifdef DEBUG
if (fmr2->curvol && !fmr2->mute)
printk(KERN_DEBUG "unmute\n");
else
printk(KERN_DEBUG "mute\n");
#endif
mutex_lock(&fmr2->lock);
if (fmr2->curvol && !fmr2->mute) {
fmr2_setvolume(fmr2);
fmr2_setfreq(fmr2);
} else
fmr2_mute(fmr2->io);
mutex_unlock(&fmr2->lock);
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
static int __init fmr2_init(void)
{
struct fmr2 *fmr2 = &fmr2_card;
struct v4l2_device *v4l2_dev = &fmr2->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "sf16fmr2", sizeof(v4l2_dev->name));
fmr2->io = io;
fmr2->stereo = 1;
mutex_init(&fmr2->lock);
if (!request_region(fmr2->io, 2, "sf16fmr2")) {
v4l2_err(v4l2_dev, "request_region failed!\n");
return -EBUSY;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(fmr2->io, 2);
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return res;
}
strlcpy(fmr2->vdev.name, v4l2_dev->name, sizeof(fmr2->vdev.name));
fmr2->vdev.v4l2_dev = v4l2_dev;
fmr2->vdev.fops = &fmr2_fops;
fmr2->vdev.ioctl_ops = &fmr2_ioctl_ops;
fmr2->vdev.release = video_device_release_empty;
video_set_drvdata(&fmr2->vdev, fmr2);
fmr2_mute(fmr2->io);
fmr2_product_info(fmr2);
if (video_register_device(&fmr2->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(fmr2->io, 2);
return -EINVAL;
}
v4l2_info(v4l2_dev, "SF16FMR2 radio card driver at 0x%x.\n", fmr2->io);
debug_print((KERN_DEBUG "card_type %d\n", fmr2->card_type));
return 0;
}
static void __exit fmr2_exit(void)
{
struct fmr2 *fmr2 = &fmr2_card;
video_unregister_device(&fmr2->vdev);
v4l2_device_unregister(&fmr2->v4l2_dev);
release_region(fmr2->io, 2);
}
static int __init fmr2_setup_io(char *str)
{
get_option(&str, &io);
return 1;
}
