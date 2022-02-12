static int cadet_getstereo(struct cadet *dev)
{
int ret = V4L2_TUNER_SUB_MONO;
if (!dev->is_fm_band)
return V4L2_TUNER_SUB_MONO;
outb(7, dev->io);
if ((inb(dev->io + 1) & 0x40) == 0)
ret = V4L2_TUNER_SUB_STEREO;
return ret;
}
static unsigned cadet_gettune(struct cadet *dev)
{
int curvol, i;
unsigned fifo = 0;
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
return fifo;
}
static unsigned cadet_getfreq(struct cadet *dev)
{
int i;
unsigned freq = 0, test, fifo = 0;
fifo = cadet_gettune(dev);
if (!dev->is_fm_band)
return ((fifo & 0x7fff) - 450) * 16;
test = 12500;
for (i = 0; i < 14; i++) {
if ((fifo & 0x01) != 0)
freq += test;
test = test << 1;
fifo = fifo >> 1;
}
freq -= 10700000;
freq = (freq * 16) / 1000;
return freq;
}
static void cadet_settune(struct cadet *dev, unsigned fifo)
{
int i;
unsigned test;
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
}
static void cadet_setfreq(struct cadet *dev, unsigned freq)
{
unsigned fifo;
int i, j, test;
int curvol;
freq = clamp(freq, bands[dev->is_fm_band].rangelow,
bands[dev->is_fm_band].rangehigh);
dev->curfreq = freq;
fifo = 0;
if (dev->is_fm_band) {
test = 102400;
freq = freq / 16;
freq += 10700;
for (i = 0; i < 14; i++) {
fifo = fifo << 1;
if (freq >= test) {
fifo |= 0x01;
freq -= test;
}
test = test >> 1;
}
} else {
fifo = (freq / 16) + 450;
fifo |= 0x100000;
}
outb(7, dev->io);
curvol = inb(dev->io + 1);
for (j = 3; j > -1; j--) {
cadet_settune(dev, fifo | (j << 16));
outb(7, dev->io);
outb(curvol, dev->io + 1);
msleep(100);
cadet_gettune(dev);
if ((dev->tunestat & 0x40) == 0) {
dev->sigstrength = sigtable[dev->is_fm_band][j];
goto reset_rds;
}
}
dev->sigstrength = 0;
reset_rds:
outb(3, dev->io);
outb(inb(dev->io + 1) & 0x7f, dev->io + 1);
}
static bool cadet_has_rds_data(struct cadet *dev)
{
bool result;
mutex_lock(&dev->lock);
result = dev->rdsin != dev->rdsout;
mutex_unlock(&dev->lock);
return result;
}
static void cadet_handler(unsigned long data)
{
struct cadet *dev = (void *)data;
if (mutex_trylock(&dev->lock)) {
outb(0x3, dev->io);
if ((inb(dev->io + 1) & 0x20) != 0)
pr_err("cadet: RDS fifo overflow\n");
outb(0x80, dev->io);
while ((inb(dev->io) & 0x80) != 0) {
dev->rdsbuf[dev->rdsin] = inb(dev->io + 1);
if (dev->rdsin + 1 != dev->rdsout)
dev->rdsin++;
}
mutex_unlock(&dev->lock);
}
if (cadet_has_rds_data(dev))
wake_up_interruptible(&dev->read_queue);
init_timer(&dev->readtimer);
dev->readtimer.function = cadet_handler;
dev->readtimer.data = data;
dev->readtimer.expires = jiffies + msecs_to_jiffies(50);
add_timer(&dev->readtimer);
}
static void cadet_start_rds(struct cadet *dev)
{
dev->rdsstat = 1;
outb(0x80, dev->io);
init_timer(&dev->readtimer);
dev->readtimer.function = cadet_handler;
dev->readtimer.data = (unsigned long)dev;
dev->readtimer.expires = jiffies + msecs_to_jiffies(50);
add_timer(&dev->readtimer);
}
static ssize_t cadet_read(struct file *file, char __user *data, size_t count, loff_t *ppos)
{
struct cadet *dev = video_drvdata(file);
unsigned char readbuf[RDS_BUFFER];
int i = 0;
mutex_lock(&dev->lock);
if (dev->rdsstat == 0)
cadet_start_rds(dev);
mutex_unlock(&dev->lock);
if (!cadet_has_rds_data(dev) && (file->f_flags & O_NONBLOCK))
return -EWOULDBLOCK;
i = wait_event_interruptible(dev->read_queue, cadet_has_rds_data(dev));
if (i)
return i;
mutex_lock(&dev->lock);
while (i < count && dev->rdsin != dev->rdsout)
readbuf[i++] = dev->rdsbuf[dev->rdsout++];
mutex_unlock(&dev->lock);
if (i && copy_to_user(data, readbuf, i))
return -EFAULT;
return i;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "ADS Cadet", sizeof(v->driver));
strlcpy(v->card, "ADS Cadet", sizeof(v->card));
strlcpy(v->bus_info, "ISA:radio-cadet", sizeof(v->bus_info));
v->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO |
V4L2_CAP_READWRITE | V4L2_CAP_RDS_CAPTURE;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct cadet *dev = video_drvdata(file);
if (v->index)
return -EINVAL;
v->type = V4L2_TUNER_RADIO;
strlcpy(v->name, "Radio", sizeof(v->name));
v->capability = bands[0].capability | bands[1].capability;
v->rangelow = bands[0].rangelow;
v->rangehigh = bands[1].rangehigh;
if (dev->is_fm_band) {
v->rxsubchans = cadet_getstereo(dev);
outb(3, dev->io);
outb(inb(dev->io + 1) & 0x7f, dev->io + 1);
mdelay(100);
outb(3, dev->io);
if (inb(dev->io + 1) & 0x80)
v->rxsubchans |= V4L2_TUNER_SUB_RDS;
} else {
v->rangelow = 8320;
v->rangehigh = 26400;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
}
v->audmode = V4L2_TUNER_MODE_STEREO;
v->signal = dev->sigstrength;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
}
static int vidioc_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
if (band->tuner)
return -EINVAL;
if (band->index >= ARRAY_SIZE(bands))
return -EINVAL;
*band = bands[band->index];
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct cadet *dev = video_drvdata(file);
if (f->tuner)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = dev->curfreq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct cadet *dev = video_drvdata(file);
if (f->tuner)
return -EINVAL;
dev->is_fm_band =
f->frequency >= (bands[0].rangehigh + bands[1].rangelow) / 2;
cadet_setfreq(dev, f->frequency);
return 0;
}
static int cadet_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct cadet *dev = container_of(ctrl->handler, struct cadet, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
outb(7, dev->io);
if (ctrl->val)
outb(0x00, dev->io + 1);
else
outb(0x20, dev->io + 1);
return 0;
}
return -EINVAL;
}
static int cadet_open(struct file *file)
{
struct cadet *dev = video_drvdata(file);
int err;
mutex_lock(&dev->lock);
err = v4l2_fh_open(file);
if (err)
goto fail;
if (v4l2_fh_is_singular_file(file))
init_waitqueue_head(&dev->read_queue);
fail:
mutex_unlock(&dev->lock);
return err;
}
static int cadet_release(struct file *file)
{
struct cadet *dev = video_drvdata(file);
mutex_lock(&dev->lock);
if (v4l2_fh_is_singular_file(file) && dev->rdsstat) {
del_timer_sync(&dev->readtimer);
dev->rdsstat = 0;
}
v4l2_fh_release(file);
mutex_unlock(&dev->lock);
return 0;
}
static unsigned int cadet_poll(struct file *file, struct poll_table_struct *wait)
{
struct cadet *dev = video_drvdata(file);
unsigned long req_events = poll_requested_events(wait);
unsigned int res = v4l2_ctrl_poll(file, wait);
poll_wait(file, &dev->read_queue, wait);
if (dev->rdsstat == 0 && (req_events & (POLLIN | POLLRDNORM))) {
mutex_lock(&dev->lock);
if (dev->rdsstat == 0)
cadet_start_rds(dev);
mutex_unlock(&dev->lock);
}
if (cadet_has_rds_data(dev))
res |= POLLIN | POLLRDNORM;
return res;
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
cadet_setfreq(dev, bands[1].rangelow);
if (cadet_getfreq(dev) == bands[1].rangelow) {
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
struct v4l2_ctrl_handler *hdl;
int res = -ENODEV;
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
hdl = &dev->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 2);
v4l2_ctrl_new_std(hdl, &cadet_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
v4l2_dev->ctrl_handler = hdl;
if (hdl->error) {
res = hdl->error;
v4l2_err(v4l2_dev, "Could not register controls\n");
goto err_hdl;
}
dev->is_fm_band = true;
dev->curfreq = bands[dev->is_fm_band].rangelow;
cadet_setfreq(dev, dev->curfreq);
strlcpy(dev->vdev.name, v4l2_dev->name, sizeof(dev->vdev.name));
dev->vdev.v4l2_dev = v4l2_dev;
dev->vdev.fops = &cadet_fops;
dev->vdev.ioctl_ops = &cadet_ioctl_ops;
dev->vdev.release = video_device_release_empty;
dev->vdev.lock = &dev->lock;
set_bit(V4L2_FL_USE_FH_PRIO, &dev->vdev.flags);
video_set_drvdata(&dev->vdev, dev);
res = video_register_device(&dev->vdev, VFL_TYPE_RADIO, radio_nr);
if (res < 0)
goto err_hdl;
v4l2_info(v4l2_dev, "ADS Cadet Radio Card at 0x%x\n", dev->io);
return 0;
err_hdl:
v4l2_ctrl_handler_free(hdl);
v4l2_device_unregister(v4l2_dev);
release_region(dev->io, 2);
fail:
pnp_unregister_driver(&cadet_pnp_driver);
return res;
}
static void __exit cadet_exit(void)
{
struct cadet *dev = &cadet_card;
video_unregister_device(&dev->vdev);
v4l2_ctrl_handler_free(&dev->ctrl_handler);
v4l2_device_unregister(&dev->v4l2_dev);
outb(7, dev->io);
outb(0x00, dev->io + 1);
release_region(dev->io, 2);
pnp_unregister_driver(&cadet_pnp_driver);
}
