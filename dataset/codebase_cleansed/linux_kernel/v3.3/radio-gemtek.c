static void gemtek_bu2614_transmit(struct gemtek *gt)
{
int i, bit, q, mute;
mutex_lock(&gt->lock);
mute = gt->muted ? GEMTEK_MT : 0x00;
outb_p(mute | GEMTEK_DA | GEMTEK_CK, gt->io);
udelay(SHORT_DELAY);
outb_p(mute | GEMTEK_CE | GEMTEK_DA | GEMTEK_CK, gt->io);
udelay(LONG_DELAY);
for (i = 0, q = gt->bu2614data; i < 32; i++, q >>= 1) {
bit = (q & 1) ? GEMTEK_DA : 0;
outb_p(mute | GEMTEK_CE | bit, gt->io);
udelay(SHORT_DELAY);
outb_p(mute | GEMTEK_CE | bit | GEMTEK_CK, gt->io);
udelay(SHORT_DELAY);
}
outb_p(mute | GEMTEK_DA | GEMTEK_CK, gt->io);
udelay(SHORT_DELAY);
outb_p(mute | GEMTEK_CE | GEMTEK_DA | GEMTEK_CK, gt->io);
udelay(LONG_DELAY);
mutex_unlock(&gt->lock);
}
static unsigned long gemtek_convfreq(unsigned long freq)
{
return ((freq<<FSCALE) + IF_OFFSET + REF_FREQ/2) / REF_FREQ;
}
static void gemtek_setfreq(struct gemtek *gt, unsigned long freq)
{
if (keepmuted && hardmute && gt->muted)
return;
freq = clamp_val(freq, GEMTEK_LOWFREQ, GEMTEK_HIGHFREQ);
gt->lastfreq = freq;
gt->muted = 0;
gemtek_bu2614_set(gt, BU2614_PORT, 0);
gemtek_bu2614_set(gt, BU2614_FMES, 0);
gemtek_bu2614_set(gt, BU2614_SWIN, 0);
gemtek_bu2614_set(gt, BU2614_SWAL, 0);
gemtek_bu2614_set(gt, BU2614_FMUN, 1);
gemtek_bu2614_set(gt, BU2614_TEST, 0);
gemtek_bu2614_set(gt, BU2614_STDF, GEMTEK_STDF_3_125_KHZ);
gemtek_bu2614_set(gt, BU2614_FREQ, gemtek_convfreq(freq));
gemtek_bu2614_transmit(gt);
}
static void gemtek_mute(struct gemtek *gt)
{
int i;
gt->muted = 1;
if (hardmute) {
gemtek_bu2614_set(gt, BU2614_PORT, 0);
gemtek_bu2614_set(gt, BU2614_FMES, 0);
gemtek_bu2614_set(gt, BU2614_SWIN, 0);
gemtek_bu2614_set(gt, BU2614_SWAL, 0);
gemtek_bu2614_set(gt, BU2614_FMUN, 0);
gemtek_bu2614_set(gt, BU2614_TEST, 0);
gemtek_bu2614_set(gt, BU2614_STDF, GEMTEK_PLL_OFF);
gemtek_bu2614_set(gt, BU2614_FREQ, 0);
gemtek_bu2614_transmit(gt);
return;
}
mutex_lock(&gt->lock);
i = inb_p(gt->io);
outb_p((i >> 5) | GEMTEK_MT, gt->io);
udelay(SHORT_DELAY);
mutex_unlock(&gt->lock);
}
static void gemtek_unmute(struct gemtek *gt)
{
int i;
gt->muted = 0;
if (hardmute) {
gemtek_setfreq(gt, gt->lastfreq);
return;
}
mutex_lock(&gt->lock);
i = inb_p(gt->io);
outb_p(i >> 5, gt->io);
udelay(SHORT_DELAY);
mutex_unlock(&gt->lock);
}
static inline int gemtek_getsigstr(struct gemtek *gt)
{
int sig;
mutex_lock(&gt->lock);
sig = inb_p(gt->io) & GEMTEK_NS ? 0 : 1;
mutex_unlock(&gt->lock);
return sig;
}
static int gemtek_verify(struct gemtek *gt, int port)
{
int i, q;
if (gt->verified == port)
return 1;
mutex_lock(&gt->lock);
q = inb_p(port);
for (i = 0; i < 3; ++i) {
outb_p(1 << i, port);
udelay(SHORT_DELAY);
if ((inb_p(port) & (~GEMTEK_NS)) != (0x17 | (1 << (i + 5)))) {
mutex_unlock(&gt->lock);
return 0;
}
}
outb_p(q >> 5, port);
udelay(SHORT_DELAY);
mutex_unlock(&gt->lock);
gt->verified = port;
return 1;
}
static int gemtek_probe(struct gemtek *gt)
{
struct v4l2_device *v4l2_dev = &gt->v4l2_dev;
int ioports[] = { 0x20c, 0x30c, 0x24c, 0x34c, 0x248, 0x28c };
int i;
if (!probe) {
v4l2_info(v4l2_dev, "Automatic device probing disabled.\n");
return -1;
}
v4l2_info(v4l2_dev, "Automatic device probing enabled.\n");
for (i = 0; i < ARRAY_SIZE(ioports); ++i) {
v4l2_info(v4l2_dev, "Trying I/O port 0x%x...\n", ioports[i]);
if (!request_region(ioports[i], 1, "gemtek-probe")) {
v4l2_warn(v4l2_dev, "I/O port 0x%x busy!\n",
ioports[i]);
continue;
}
if (gemtek_verify(gt, ioports[i])) {
v4l2_info(v4l2_dev, "Card found from I/O port "
"0x%x!\n", ioports[i]);
release_region(ioports[i], 1);
gt->io = ioports[i];
return gt->io;
}
release_region(ioports[i], 1);
}
v4l2_err(v4l2_dev, "Automatic probing failed!\n");
return -1;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-gemtek", sizeof(v->driver));
strlcpy(v->card, "GemTek", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv, struct v4l2_tuner *v)
{
struct gemtek *gt = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = GEMTEK_LOWFREQ;
v->rangehigh = GEMTEK_HIGHFREQ;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
v->signal = 0xffff * gemtek_getsigstr(gt);
if (v->signal) {
v->audmode = V4L2_TUNER_MODE_STEREO;
v->rxsubchans = V4L2_TUNER_SUB_STEREO;
} else {
v->audmode = V4L2_TUNER_MODE_MONO;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
}
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv, struct v4l2_tuner *v)
{
return (v->index != 0) ? -EINVAL : 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct gemtek *gt = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = gt->lastfreq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct gemtek *gt = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
gemtek_setfreq(gt, f->frequency);
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 0);
default:
return -EINVAL;
}
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct gemtek *gt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = gt->muted;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct gemtek *gt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
gemtek_mute(gt);
else
gemtek_unmute(gt);
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
return (i != 0) ? -EINVAL : 0;
}
static int vidioc_g_audio(struct file *file, void *priv, struct v4l2_audio *a)
{
a->index = 0;
strlcpy(a->name, "Radio", sizeof(a->name));
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_s_audio(struct file *file, void *priv, struct v4l2_audio *a)
{
return (a->index != 0) ? -EINVAL : 0;
}
static int __init gemtek_init(void)
{
struct gemtek *gt = &gemtek_card;
struct v4l2_device *v4l2_dev = &gt->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "gemtek", sizeof(v4l2_dev->name));
v4l2_info(v4l2_dev, "GemTek Radio card driver: v0.0.3\n");
mutex_init(&gt->lock);
gt->verified = -1;
gt->io = io;
gemtek_probe(gt);
if (gt->io) {
if (!request_region(gt->io, 1, "gemtek")) {
v4l2_err(v4l2_dev, "I/O port 0x%x already in use.\n", gt->io);
return -EBUSY;
}
if (!gemtek_verify(gt, gt->io))
v4l2_warn(v4l2_dev, "Card at I/O port 0x%x does not "
"respond properly, check your "
"configuration.\n", gt->io);
else
v4l2_info(v4l2_dev, "Using I/O port 0x%x.\n", gt->io);
} else if (probe) {
v4l2_err(v4l2_dev, "Automatic probing failed and no "
"fixed I/O port defined.\n");
return -ENODEV;
} else {
v4l2_err(v4l2_dev, "Automatic probing disabled but no fixed "
"I/O port defined.");
return -EINVAL;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
release_region(gt->io, 1);
return res;
}
strlcpy(gt->vdev.name, v4l2_dev->name, sizeof(gt->vdev.name));
gt->vdev.v4l2_dev = v4l2_dev;
gt->vdev.fops = &gemtek_fops;
gt->vdev.ioctl_ops = &gemtek_ioctl_ops;
gt->vdev.release = video_device_release_empty;
video_set_drvdata(&gt->vdev, gt);
gt->lastfreq = GEMTEK_LOWFREQ;
gt->bu2614data = 0;
if (initmute)
gemtek_mute(gt);
if (video_register_device(&gt->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(gt->io, 1);
return -EBUSY;
}
return 0;
}
static void __exit gemtek_exit(void)
{
struct gemtek *gt = &gemtek_card;
struct v4l2_device *v4l2_dev = &gt->v4l2_dev;
if (shutdown) {
hardmute = 1;
gemtek_mute(gt);
} else {
v4l2_info(v4l2_dev, "Module unloaded but card not muted!\n");
}
video_unregister_device(&gt->vdev);
v4l2_device_unregister(&gt->v4l2_dev);
release_region(gt->io, 1);
}
