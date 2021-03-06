void fmi_set_pins(void *handle, u8 pins)
{
struct fmi *fmi = handle;
u8 bits = FMI_BIT_TUN_STRQ;
if (!fmi->mute)
bits |= FMI_BIT_VOL_SW;
if (pins & LM7000_DATA)
bits |= FMI_BIT_TUN_DATA;
if (pins & LM7000_CLK)
bits |= FMI_BIT_TUN_CLK;
if (pins & LM7000_CE)
bits |= FMI_BIT_TUN_CE;
mutex_lock(&fmi->lock);
outb_p(bits, fmi->io);
mutex_unlock(&fmi->lock);
}
static inline void fmi_mute(struct fmi *fmi)
{
mutex_lock(&fmi->lock);
outb(0x00, fmi->io);
mutex_unlock(&fmi->lock);
}
static inline void fmi_unmute(struct fmi *fmi)
{
mutex_lock(&fmi->lock);
outb(0x08, fmi->io);
mutex_unlock(&fmi->lock);
}
static inline int fmi_getsigstr(struct fmi *fmi)
{
int val;
int res;
mutex_lock(&fmi->lock);
val = fmi->mute ? 0x00 : 0x08;
outb(val, fmi->io);
outb(val | 0x10, fmi->io);
msleep(143);
res = (int)inb(fmi->io + 1);
outb(val, fmi->io);
mutex_unlock(&fmi->lock);
return (res & 2) ? 0 : 0xFFFF;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "radio-sf16fmi", sizeof(v->driver));
strlcpy(v->card, "SF16-FMI/FMP/FMD radio", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct fmi *fmi = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = RSF16_MINFREQ;
v->rangehigh = RSF16_MAXFREQ;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_STEREO;
v->signal = fmi_getsigstr(fmi);
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
struct fmi *fmi = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (f->frequency < RSF16_MINFREQ ||
f->frequency > RSF16_MAXFREQ)
return -EINVAL;
lm7000_set_freq((f->frequency / 800) * 800, fmi, fmi_set_pins);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct fmi *fmi = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = fmi->curfreq;
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
struct fmi *fmi = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = fmi->mute;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct fmi *fmi = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
fmi_mute(fmi);
else
fmi_unmute(fmi);
fmi->mute = ctrl->value;
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
const struct v4l2_audio *a)
{
return a->index ? -EINVAL : 0;
}
static int __init isapnp_fmi_probe(void)
{
int i = 0;
while (id_table[i].card_vendor != 0 && dev == NULL) {
dev = pnp_find_dev(NULL, id_table[i].vendor,
id_table[i].function, NULL);
i++;
}
if (!dev)
return -ENODEV;
if (pnp_device_attach(dev) < 0)
return -EAGAIN;
if (pnp_activate_dev(dev) < 0) {
printk(KERN_ERR "radio-sf16fmi: PnP configure failed (out of resources?)\n");
pnp_device_detach(dev);
return -ENOMEM;
}
if (!pnp_port_valid(dev, 0)) {
pnp_device_detach(dev);
return -ENODEV;
}
i = pnp_port_start(dev, 0);
printk(KERN_INFO "radio-sf16fmi: PnP reports card at %#x\n", i);
return i;
}
static int __init fmi_init(void)
{
struct fmi *fmi = &fmi_card;
struct v4l2_device *v4l2_dev = &fmi->v4l2_dev;
int res, i;
int probe_ports[] = { 0, 0x284, 0x384 };
if (io < 0) {
for (i = 0; i < ARRAY_SIZE(probe_ports); i++) {
io = probe_ports[i];
if (io == 0) {
io = isapnp_fmi_probe();
if (io < 0)
continue;
pnp_attached = 1;
}
if (!request_region(io, 2, "radio-sf16fmi")) {
if (pnp_attached)
pnp_device_detach(dev);
io = -1;
continue;
}
if (pnp_attached ||
((inb(io) & 0xf9) == 0xf9 && (inb(io) & 0x4) == 0))
break;
release_region(io, 2);
io = -1;
}
} else {
if (!request_region(io, 2, "radio-sf16fmi")) {
printk(KERN_ERR "radio-sf16fmi: port %#x already in use\n", io);
return -EBUSY;
}
if (inb(io) == 0xff) {
printk(KERN_ERR "radio-sf16fmi: card not present at %#x\n", io);
release_region(io, 2);
return -ENODEV;
}
}
if (io < 0) {
printk(KERN_ERR "radio-sf16fmi: no cards found\n");
return -ENODEV;
}
strlcpy(v4l2_dev->name, "sf16fmi", sizeof(v4l2_dev->name));
fmi->io = io;
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(fmi->io, 2);
if (pnp_attached)
pnp_device_detach(dev);
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
return res;
}
strlcpy(fmi->vdev.name, v4l2_dev->name, sizeof(fmi->vdev.name));
fmi->vdev.v4l2_dev = v4l2_dev;
fmi->vdev.fops = &fmi_fops;
fmi->vdev.ioctl_ops = &fmi_ioctl_ops;
fmi->vdev.release = video_device_release_empty;
video_set_drvdata(&fmi->vdev, fmi);
mutex_init(&fmi->lock);
fmi_mute(fmi);
if (video_register_device(&fmi->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(fmi->io, 2);
if (pnp_attached)
pnp_device_detach(dev);
return -EINVAL;
}
v4l2_info(v4l2_dev, "card driver at 0x%x\n", fmi->io);
return 0;
}
static void __exit fmi_exit(void)
{
struct fmi *fmi = &fmi_card;
video_unregister_device(&fmi->vdev);
v4l2_device_unregister(&fmi->v4l2_dev);
release_region(fmi->io, 2);
if (dev && pnp_attached)
pnp_device_detach(dev);
}
