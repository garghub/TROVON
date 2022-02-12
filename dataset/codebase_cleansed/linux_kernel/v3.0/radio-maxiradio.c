static inline struct maxiradio *to_maxiradio(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct maxiradio, v4l2_dev);
}
static void outbit(unsigned long bit, u16 io)
{
int val = power | wren | (bit ? data : 0);
outb(val, io);
udelay(4);
outb(val | clk, io);
udelay(4);
outb(val, io);
udelay(4);
}
static void turn_power(struct maxiradio *dev, int p)
{
if (p != 0) {
dprintk(dev, 1, "Radio powered on\n");
outb(power, dev->io);
} else {
dprintk(dev, 1, "Radio powered off\n");
outb(0, dev->io);
}
}
static void set_freq(struct maxiradio *dev, u32 freq)
{
unsigned long int si;
int bl;
int io = dev->io;
int val = FREQ2BITS(freq);
outbit(0, io);
outbit(1, io);
outbit(0, io);
outbit(0, io);
outbit(0, io);
outbit(0, io);
outbit(0, io);
outbit(0, io);
outbit(0, io);
si = 0x8000;
for (bl = 1; bl <= 16; bl++) {
outbit(val & si, io);
si >>= 1;
}
dprintk(dev, 1, "Radio freq set to %d.%02d MHz\n",
freq / 16000,
freq % 16000 * 100 / 16000);
turn_power(dev, 1);
}
static int get_stereo(u16 io)
{
outb(power,io);
udelay(4);
return !(inb(io) & mo_st);
}
static int get_tune(u16 io)
{
outb(power+clk,io);
udelay(4);
return !(inb(io) & mo_st);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct maxiradio *dev = video_drvdata(file);
strlcpy(v->driver, "radio-maxiradio", sizeof(v->driver));
strlcpy(v->card, "Maxi Radio FM2000 radio", sizeof(v->card));
snprintf(v->bus_info, sizeof(v->bus_info), "PCI:%s", pci_name(dev->pdev));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct maxiradio *dev = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
mutex_lock(&dev->lock);
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = FREQ_LO;
v->rangehigh = FREQ_HI;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW;
if (get_stereo(dev->io))
v->audmode = V4L2_TUNER_MODE_STEREO;
else
v->audmode = V4L2_TUNER_MODE_MONO;
v->signal = 0xffff * get_tune(dev->io);
mutex_unlock(&dev->lock);
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
struct maxiradio *dev = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (f->frequency < FREQ_LO || f->frequency > FREQ_HI) {
dprintk(dev, 1, "radio freq (%d.%02d MHz) out of range (%d-%d)\n",
f->frequency / 16000,
f->frequency % 16000 * 100 / 16000,
FREQ_LO / 16000, FREQ_HI / 16000);
return -EINVAL;
}
mutex_lock(&dev->lock);
dev->freq = f->frequency;
set_freq(dev, dev->freq);
msleep(125);
mutex_unlock(&dev->lock);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct maxiradio *dev = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = dev->freq;
dprintk(dev, 4, "radio freq is %d.%02d MHz",
f->frequency / 16000,
f->frequency % 16000 * 100 / 16000);
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
struct maxiradio *dev = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = dev->muted;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct maxiradio *dev = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
mutex_lock(&dev->lock);
dev->muted = ctrl->value;
if (dev->muted)
turn_power(dev, 0);
else
set_freq(dev, dev->freq);
mutex_unlock(&dev->lock);
return 0;
}
return -EINVAL;
}
static int __devinit maxiradio_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct maxiradio *dev;
struct v4l2_device *v4l2_dev;
int retval = -ENOMEM;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&pdev->dev, "not enough memory\n");
return -ENOMEM;
}
v4l2_dev = &dev->v4l2_dev;
mutex_init(&dev->lock);
dev->pdev = pdev;
dev->muted = 1;
dev->freq = FREQ_LO;
strlcpy(v4l2_dev->name, "maxiradio", sizeof(v4l2_dev->name));
retval = v4l2_device_register(&pdev->dev, v4l2_dev);
if (retval < 0) {
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
goto errfr;
}
if (!request_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0), "Maxi Radio FM 2000")) {
v4l2_err(v4l2_dev, "can't reserve I/O ports\n");
goto err_out;
}
if (pci_enable_device(pdev))
goto err_out_free_region;
dev->io = pci_resource_start(pdev, 0);
strlcpy(dev->vdev.name, v4l2_dev->name, sizeof(dev->vdev.name));
dev->vdev.v4l2_dev = v4l2_dev;
dev->vdev.fops = &maxiradio_fops;
dev->vdev.ioctl_ops = &maxiradio_ioctl_ops;
dev->vdev.release = video_device_release_empty;
video_set_drvdata(&dev->vdev, dev);
if (video_register_device(&dev->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_err(v4l2_dev, "can't register device!");
goto err_out_free_region;
}
v4l2_info(v4l2_dev, "version " DRIVER_VERSION "\n");
v4l2_info(v4l2_dev, "found Guillemot MAXI Radio device (io = 0x%x)\n",
dev->io);
return 0;
err_out_free_region:
release_region(pci_resource_start(pdev, 0), pci_resource_len(pdev, 0));
err_out:
v4l2_device_unregister(v4l2_dev);
errfr:
kfree(dev);
return -ENODEV;
}
static void __devexit maxiradio_remove_one(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct maxiradio *dev = to_maxiradio(v4l2_dev);
video_unregister_device(&dev->vdev);
v4l2_device_unregister(&dev->v4l2_dev);
release_region(pci_resource_start(pdev, 0), pci_resource_len(pdev, 0));
}
static int __init maxiradio_radio_init(void)
{
return pci_register_driver(&maxiradio_driver);
}
static void __exit maxiradio_radio_exit(void)
{
pci_unregister_driver(&maxiradio_driver);
}
