static void tt_write_vol(struct terratec *tt, int volume)
{
int i;
volume = volume + (volume * 32);
mutex_lock(&tt->lock);
for (i = 0; i < 8; i++) {
if (volume & (0x80 >> i))
outb(0x80, tt->io + 1);
else
outb(0x00, tt->io + 1);
}
mutex_unlock(&tt->lock);
}
static void tt_mute(struct terratec *tt)
{
tt->muted = 1;
tt_write_vol(tt, 0);
}
static int tt_setvol(struct terratec *tt, int vol)
{
if (vol == tt->curvol) {
if (tt->muted) {
tt->muted = 0;
tt_write_vol(tt, vol);
}
return 0;
}
if (vol == 0) {
tt_write_vol(tt, 0);
tt->curvol = vol;
return 0;
}
tt->muted = 0;
tt_write_vol(tt, vol);
tt->curvol = vol;
return 0;
}
static int tt_setfreq(struct terratec *tt, unsigned long freq1)
{
int freq;
int i;
int p;
int temp;
long rest;
unsigned char buffer[25];
mutex_lock(&tt->lock);
tt->curfreq = freq1;
freq = freq1 / 160;
memset(buffer, 0, sizeof(buffer));
rest = freq * 10 + 10700;
i = 13;
p = 10;
temp = 102400;
while (rest != 0) {
if (rest % temp == rest)
buffer[i] = 0;
else {
buffer[i] = 1;
rest = rest - temp;
}
i--;
p--;
temp = temp / 2;
}
for (i = 24; i > -1; i--) {
if (buffer[i] == 1) {
outb(WRT_EN | DATA, tt->io);
outb(WRT_EN | DATA | CLK_ON, tt->io);
outb(WRT_EN | DATA, tt->io);
} else {
outb(WRT_EN | 0x00, tt->io);
outb(WRT_EN | 0x00 | CLK_ON, tt->io);
}
}
outb(0x00, tt->io);
mutex_unlock(&tt->lock);
return 0;
}
static int tt_getsigstr(struct terratec *tt)
{
if (inb(tt->io) & 2)
return 0;
return 1;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-terratec", sizeof(v->driver));
strlcpy(v->card, "ActiveRadio", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct terratec *tt = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 87 * 16000;
v->rangehigh = 108 * 16000;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xFFFF * tt_getsigstr(tt);
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
struct terratec *tt = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
tt_setfreq(tt, f->frequency);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct terratec *tt = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = tt->curfreq;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
int i;
for (i = 0; i < ARRAY_SIZE(radio_qctrl); i++) {
if (qc->id && qc->id == radio_qctrl[i].id) {
memcpy(qc, &(radio_qctrl[i]), sizeof(*qc));
return 0;
}
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct terratec *tt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (tt->muted)
ctrl->value = 1;
else
ctrl->value = 0;
return 0;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = tt->curvol * 6554;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct terratec *tt = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
tt_mute(tt);
else
tt_setvol(tt,tt->curvol);
return 0;
case V4L2_CID_AUDIO_VOLUME:
tt_setvol(tt,ctrl->value);
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
static int __init terratec_init(void)
{
struct terratec *tt = &terratec_card;
struct v4l2_device *v4l2_dev = &tt->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "terratec", sizeof(v4l2_dev->name));
tt->io = io;
if (tt->io == -1) {
v4l2_err(v4l2_dev, "you must set an I/O address with io=0x590 or 0x591\n");
return -EINVAL;
}
if (!request_region(tt->io, 2, "terratec")) {
v4l2_err(v4l2_dev, "port 0x%x already in use\n", io);
return -EBUSY;
}
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(tt->io, 2);
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return res;
}
strlcpy(tt->vdev.name, v4l2_dev->name, sizeof(tt->vdev.name));
tt->vdev.v4l2_dev = v4l2_dev;
tt->vdev.fops = &terratec_fops;
tt->vdev.ioctl_ops = &terratec_ioctl_ops;
tt->vdev.release = video_device_release_empty;
video_set_drvdata(&tt->vdev, tt);
mutex_init(&tt->lock);
tt_write_vol(tt, 0);
if (video_register_device(&tt->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(&tt->v4l2_dev);
release_region(tt->io, 2);
return -EINVAL;
}
v4l2_info(v4l2_dev, "TERRATEC ActivRadio Standalone card driver.\n");
return 0;
}
static void __exit terratec_exit(void)
{
struct terratec *tt = &terratec_card;
struct v4l2_device *v4l2_dev = &tt->v4l2_dev;
video_unregister_device(&tt->vdev);
v4l2_device_unregister(&tt->v4l2_dev);
release_region(tt->io, 2);
v4l2_info(v4l2_dev, "TERRATEC ActivRadio Standalone card driver unloaded.\n");
}
