static int cadet_getstereo(struct cadet *dev)
{
int ret = V4L2_TUNER_SUB_MONO;
if (dev->curtuner != 0)
return V4L2_TUNER_SUB_MONO;
mutex_lock(&dev->lock);
outb(7, dev->io);
if ((inb(dev->io + 1) & 0x40) == 0)
ret = V4L2_TUNER_SUB_STEREO;
mutex_unlock(&dev->lock);
return ret;
}
static unsigned cadet_gettune(struct cadet *dev)
{
int curvol, i;
unsigned fifo = 0;
mutex_lock(&dev->lock);
outb(7, dev->io);
curvol = inb(dev->io + 1);
outb(0x00, dev->io + 1);
dev->tunestat = 0xffff;
for (i = 0; i < 25; i++) {
fifo = (fifo << 1) | ((inb(dev->io + 1) >> 7) & 0x01);
if (i < 24) {
outb(0x01, dev->io + 1);
dev->tunestat &= inb(dev->io + 1);
outb(0x00, dev->io + 1);
}
}
outb(curvol, dev->io + 1);
mutex_unlock(&dev->lock);
return fifo;
}
static unsigned cadet_getfreq(struct cadet *dev)
{
int i;
unsigned freq = 0, test, fifo = 0;
fifo = cadet_gettune(dev);
if (dev->curtuner == 0) {
test = 12500;
for (i = 0; i < 14; i++) {
if ((fifo & 0x01) != 0)
freq += test;
test = test << 1;
fifo = fifo >> 1;
}
freq -= 10700000;
freq = (freq * 16) / 1000000;
}
if (dev->curtuner == 1)
freq = ((fifo & 0x7fff) - 2010) * 16;
return freq;
}
static void cadet_settune(struct cadet *dev, unsigned fifo)
{
int i;
unsigned test;
mutex_lock(&dev->lock);
outb(7, dev->io);
test = 0;
test = (fifo >> 23) & 0x02;
test |= 0x1c;
outb(7, dev->io);
outb(test, dev->io + 1);
for (i = 0; i < 25; i++) {
test |= 0x01;
outb(test, dev->io + 1);
test &= 0xfe;
outb(test, dev->io + 1);
fifo = fifo << 1;
test = 0x1c | ((fifo >> 23) & 0x02);
outb(test, dev->io + 1);
}
mutex_unlock(&dev->lock);
}
static void cadet_setfreq(struct cadet *dev, unsigned freq)
{
unsigned fifo;
int i, j, test;
int curvol;
fifo = 0;
if (dev->curtuner == 0) {
test = 102400;
freq = (freq * 1000) / 16;
freq += 10700;
for (i = 0; i < 14; i++) {
fifo = fifo << 1;
if (freq >= test) {
fifo |= 0x01;
freq -= test;
}
test = test >> 1;
}
}
if (dev->curtuner == 1) {
fifo = (freq / 16) + 2010;
fifo |= 0x100000;
}
mutex_lock(&dev->lock);
outb(7, dev->io);
curvol = inb(dev->io + 1);
mutex_unlock(&dev->lock);
for (j = 3; j > -1; j--) {
cadet_settune(dev, fifo | (j << 16));
mutex_lock(&dev->lock);
outb(7, dev->io);
outb(curvol, dev->io + 1);
mutex_unlock(&dev->lock);
msleep(100);
cadet_gettune(dev);
if ((dev->tunestat & 0x40) == 0) {
dev->sigstrength = sigtable[dev->curtuner][j];
return;
}
}
dev->sigstrength = 0;
}
static int cadet_getvol(struct cadet *dev)
{
int ret = 0;
mutex_lock(&dev->lock);
outb(7, dev->io);
if ((inb(dev->io + 1) & 0x20) != 0)
ret = 0xffff;
mutex_unlock(&dev->lock);
return ret;
}
static void cadet_setvol(struct cadet *dev, int vol)
{
mutex_lock(&dev->lock);
outb(7, dev->io);
if (vol > 0)
outb(0x20, dev->io + 1);
else
outb(0x00, dev->io + 1);
mutex_unlock(&dev->lock);
}
static void cadet_handler(unsigned long data)
{
struct cadet *dev = (void *)data;
if (mutex_trylock(&dev->lock)) {
outb(0x3, dev->io);
if ((inb(dev->io + 1) & 0x20) != 0)
printk(KERN_CRIT "cadet: RDS fifo overflow\n");
outb(0x80, dev->io);
while ((inb(dev->io) & 0x80) != 0) {
dev->rdsbuf[dev->rdsin] = inb(dev->io + 1);
if (dev->rdsin == dev->rdsout)
printk(KERN_WARNING "cadet: RDS buffer overflow\n");
else
dev->rdsin++;
}
mutex_unlock(&dev->lock);
}
if (dev->rdsin != dev->rdsout)
wake_up_interruptible(&dev->read_queue);
init_timer(&dev->readtimer);
dev->readtimer.function = cadet_handler;
dev->readtimer.data = (unsigned long)0;
dev->readtimer.expires = jiffies + msecs_to_jiffies(50);
add_timer(&dev->readtimer);
}
static ssize_t cadet_read(struct file *file, char __user *data, size_t count, loff_t *ppos)
{
struct cadet *dev = video_drvdata(file);
unsigned char readbuf[RDS_BUFFER];
int i = 0;
mutex_lock(&dev->lock);
if (dev->rdsstat == 0) {
dev->rdsstat = 1;
outb(0x80, dev->io);
init_timer(&dev->readtimer);
dev->readtimer.function = cadet_handler;
dev->readtimer.data = (unsigned long)dev;
dev->readtimer.expires = jiffies + msecs_to_jiffies(50);
add_timer(&dev->readtimer);
}
if (dev->rdsin == dev->rdsout) {
mutex_unlock(&dev->lock);
if (file->f_flags & O_NONBLOCK)
return -EWOULDBLOCK;
interruptible_sleep_on(&dev->read_queue);
mutex_lock(&dev->lock);
}
while (i < count && dev->rdsin != dev->rdsout)
readbuf[i++] = dev->rdsbuf[dev->rdsout++];
mutex_unlock(&dev->lock);
if (copy_to_user(data, readbuf, i))
return -EFAULT;
return i;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "ADS Cadet", sizeof(v->driver));
strlcpy(v->card, "ADS Cadet", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO |
V4L2_CAP_READWRITE | V4L2_CAP_RDS_CAPTURE;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct cadet *dev = video_drvdata(file);
v->type = V4L2_TUNER_RADIO;
switch (v->index) {
case 0:
strlcpy(v->name, "FM", sizeof(v->name));
v->capability = V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_RDS |
V4L2_TUNER_CAP_RDS_BLOCK_IO;
v->rangelow = 1400;
v->rangehigh = 1728;
v->rxsubchans = cadet_getstereo(dev);
switch (v->rxsubchans) {
case V4L2_TUNER_SUB_MONO:
v->audmode = V4L2_TUNER_MODE_MONO;
break;
case V4L2_TUNER_SUB_STEREO:
v->audmode = V4L2_TUNER_MODE_STEREO;
break;
default:
break;
}
v->rxsubchans |= V4L2_TUNER_SUB_RDS;
break;
case 1:
strlcpy(v->name, "AM", sizeof(v->name));
v->capability = V4L2_TUNER_CAP_LOW;
v->rangelow = 8320;
v->rangehigh = 26400;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
v->audmode = V4L2_TUNER_MODE_MONO;
break;
default:
return -EINVAL;
}
v->signal = dev->sigstrength;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct cadet *dev = video_drvdata(file);
if (v->index != 0 && v->index != 1)
return -EINVAL;
dev->curtuner = v->index;
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cadet *dev = video_drvdata(file);
f->tuner = dev->curtuner;
f->type = V4L2_TUNER_RADIO;
f->frequency = cadet_getfreq(dev);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cadet *dev = video_drvdata(file);
if (f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (dev->curtuner == 0 && (f->frequency < 1400 || f->frequency > 1728))
return -EINVAL;
if (dev->curtuner == 1 && (f->frequency < 8320 || f->frequency > 26400))
return -EINVAL;
cadet_setfreq(dev, f->frequency);
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
struct cadet *dev = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = (cadet_getvol(dev) == 0);
break;
case V4L2_CID_AUDIO_VOLUME:
ctrl->value = cadet_getvol(dev);
break;
default:
return -EINVAL;
}
return 0;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct cadet *dev = video_drvdata(file);
switch (ctrl->id){
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
cadet_setvol(dev, 0);
else
cadet_setvol(dev, 0xffff);
break;
case V4L2_CID_AUDIO_VOLUME:
cadet_setvol(dev, ctrl->value);
break;
default:
return -EINVAL;
}
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
static int cadet_open(struct file *file)
{
struct cadet *dev = video_drvdata(file);
mutex_lock(&dev->lock);
dev->users++;
if (1 == dev->users)
init_waitqueue_head(&dev->read_queue);
mutex_unlock(&dev->lock);
return 0;
}
static int cadet_release(struct file *file)
{
struct cadet *dev = video_drvdata(file);
mutex_lock(&dev->lock);
dev->users--;
if (0 == dev->users) {
del_timer_sync(&dev->readtimer);
dev->rdsstat = 0;
}
mutex_unlock(&dev->lock);
return 0;
}
static unsigned int cadet_poll(struct file *file, struct poll_table_struct *wait)
{
struct cadet *dev = video_drvdata(file);
poll_wait(file, &dev->read_queue, wait);
if (dev->rdsin != dev->rdsout)
return POLLIN | POLLRDNORM;
return 0;
}
static int cadet_pnp_probe(struct pnp_dev *dev, const struct pnp_device_id *dev_id)
{
if (!dev)
return -ENODEV;
if (io > 0)
return -EBUSY;
if (!pnp_port_valid(dev, 0))
return -ENODEV;
io = pnp_port_start(dev, 0);
printk(KERN_INFO "radio-cadet: PnP reports device at %#x\n", io);
return io;
}
static void cadet_probe(struct cadet *dev)
{
static int iovals[8] = { 0x330, 0x332, 0x334, 0x336, 0x338, 0x33a, 0x33c, 0x33e };
int i;
for (i = 0; i < 8; i++) {
dev->io = iovals[i];
if (request_region(dev->io, 2, "cadet-probe")) {
cadet_setfreq(dev, 1410);
if (cadet_getfreq(dev) == 1410) {
release_region(dev->io, 2);
return;
}
release_region(dev->io, 2);
}
}
dev->io = -1;
}
static int __init cadet_init(void)
{
struct cadet *dev = &cadet_card;
struct v4l2_device *v4l2_dev = &dev->v4l2_dev;
int res;
strlcpy(v4l2_dev->name, "cadet", sizeof(v4l2_dev->name));
mutex_init(&dev->lock);
if (io < 0)
pnp_register_driver(&cadet_pnp_driver);
dev->io = io;
if (dev->io < 0)
cadet_probe(dev);
if (dev->io < 0) {
#ifdef MODULE
v4l2_err(v4l2_dev, "you must set an I/O address with io=0x330, 0x332, 0x334,\n");
v4l2_err(v4l2_dev, "0x336, 0x338, 0x33a, 0x33c or 0x33e\n");
#endif
goto fail;
}
if (!request_region(dev->io, 2, "cadet"))
goto fail;
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
release_region(dev->io, 2);
v4l2_err(v4l2_dev, "could not register v4l2_device\n");
goto fail;
}
strlcpy(dev->vdev.name, v4l2_dev->name, sizeof(dev->vdev.name));
dev->vdev.v4l2_dev = v4l2_dev;
dev->vdev.fops = &cadet_fops;
dev->vdev.ioctl_ops = &cadet_ioctl_ops;
dev->vdev.release = video_device_release_empty;
video_set_drvdata(&dev->vdev, dev);
if (video_register_device(&dev->vdev, VFL_TYPE_RADIO, radio_nr) < 0) {
v4l2_device_unregister(v4l2_dev);
release_region(dev->io, 2);
goto fail;
}
v4l2_info(v4l2_dev, "ADS Cadet Radio Card at 0x%x\n", dev->io);
return 0;
fail:
pnp_unregister_driver(&cadet_pnp_driver);
return -ENODEV;
}
static void __exit cadet_exit(void)
{
struct cadet *dev = &cadet_card;
video_unregister_device(&dev->vdev);
v4l2_device_unregister(&dev->v4l2_dev);
release_region(dev->io, 2);
pnp_unregister_driver(&cadet_pnp_driver);
}
