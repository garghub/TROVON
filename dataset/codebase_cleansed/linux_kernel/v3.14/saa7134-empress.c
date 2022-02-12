static void ts_reset_encoder(struct saa7134_dev* dev)
{
if (!dev->empress_started)
return;
saa_writeb(SAA7134_SPECIAL_MODE, 0x00);
msleep(10);
saa_writeb(SAA7134_SPECIAL_MODE, 0x01);
msleep(100);
dev->empress_started = 0;
}
static int ts_init_encoder(struct saa7134_dev* dev)
{
u32 leading_null_bytes = 0;
switch (dev->board) {
case SAA7134_BOARD_BEHOLD_M6:
case SAA7134_BOARD_BEHOLD_M63:
case SAA7134_BOARD_BEHOLD_M6_EXTRA:
leading_null_bytes = 1;
break;
}
ts_reset_encoder(dev);
saa_call_all(dev, core, init, leading_null_bytes);
dev->empress_started = 1;
return 0;
}
static int ts_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct saa7134_dev *dev = video_drvdata(file);
struct saa7134_fh *fh;
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (NULL == fh)
return -ENOMEM;
v4l2_fh_init(&fh->fh, vdev);
file->private_data = fh;
fh->is_empress = true;
v4l2_fh_add(&fh->fh);
saa_writeb(SAA7134_AUDIO_MUTE_CTRL,
saa_readb(SAA7134_AUDIO_MUTE_CTRL) & ~(1 << 6));
return 0;
}
static int ts_release(struct file *file)
{
struct saa7134_dev *dev = video_drvdata(file);
struct saa7134_fh *fh = file->private_data;
if (res_check(fh, RESOURCE_EMPRESS)) {
videobuf_stop(&dev->empress_tsq);
videobuf_mmap_free(&dev->empress_tsq);
ts_reset_encoder(dev);
saa_writeb(SAA7134_AUDIO_MUTE_CTRL,
saa_readb(SAA7134_AUDIO_MUTE_CTRL) | (1 << 6));
}
v4l2_fh_del(&fh->fh);
v4l2_fh_exit(&fh->fh);
return 0;
}
static ssize_t
ts_read(struct file *file, char __user *data, size_t count, loff_t *ppos)
{
struct saa7134_dev *dev = video_drvdata(file);
if (res_locked(dev, RESOURCE_EMPRESS))
return -EBUSY;
if (!dev->empress_started)
ts_init_encoder(dev);
return videobuf_read_stream(&dev->empress_tsq,
data, count, ppos, 0,
file->f_flags & O_NONBLOCK);
}
static unsigned int
ts_poll(struct file *file, struct poll_table_struct *wait)
{
unsigned long req_events = poll_requested_events(wait);
struct saa7134_dev *dev = video_drvdata(file);
struct saa7134_fh *fh = file->private_data;
unsigned int rc = 0;
if (v4l2_event_pending(&fh->fh))
rc = POLLPRI;
else if (req_events & POLLPRI)
poll_wait(file, &fh->fh.wait, wait);
return rc | videobuf_poll_stream(file, &dev->empress_tsq, wait);
}
static int
ts_mmap(struct file *file, struct vm_area_struct * vma)
{
struct saa7134_dev *dev = video_drvdata(file);
return videobuf_mmap_mapper(&dev->empress_tsq, vma);
}
static int empress_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
strlcpy(f->description, "MPEG TS", sizeof(f->description));
f->pixelformat = V4L2_PIX_FMT_MPEG;
f->flags = V4L2_FMT_FLAG_COMPRESSED;
return 0;
}
static int empress_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct saa7134_dev *dev = video_drvdata(file);
struct v4l2_mbus_framefmt mbus_fmt;
saa_call_all(dev, video, g_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.sizeimage = TS_PACKET_SIZE * dev->ts.nr_packets;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.priv = 0;
return 0;
}
static int empress_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct saa7134_dev *dev = video_drvdata(file);
struct v4l2_mbus_framefmt mbus_fmt;
v4l2_fill_mbus_format(&mbus_fmt, &f->fmt.pix, V4L2_MBUS_FMT_FIXED);
saa_call_all(dev, video, s_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.sizeimage = TS_PACKET_SIZE * dev->ts.nr_packets;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.priv = 0;
return 0;
}
static int empress_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct saa7134_dev *dev = video_drvdata(file);
struct v4l2_mbus_framefmt mbus_fmt;
v4l2_fill_mbus_format(&mbus_fmt, &f->fmt.pix, V4L2_MBUS_FMT_FIXED);
saa_call_all(dev, video, try_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.sizeimage = TS_PACKET_SIZE * dev->ts.nr_packets;
f->fmt.pix.bytesperline = 0;
f->fmt.pix.priv = 0;
return 0;
}
static void empress_signal_update(struct work_struct *work)
{
struct saa7134_dev* dev =
container_of(work, struct saa7134_dev, empress_workqueue);
if (dev->nosignal) {
dprintk("no video signal\n");
} else {
dprintk("video signal acquired\n");
}
}
static void empress_signal_change(struct saa7134_dev *dev)
{
schedule_work(&dev->empress_workqueue);
}
static bool empress_ctrl_filter(const struct v4l2_ctrl *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
case V4L2_CID_HUE:
case V4L2_CID_CONTRAST:
case V4L2_CID_SATURATION:
case V4L2_CID_AUDIO_MUTE:
case V4L2_CID_AUDIO_VOLUME:
case V4L2_CID_PRIVATE_INVERT:
case V4L2_CID_PRIVATE_AUTOMUTE:
return true;
default:
return false;
}
}
static int empress_init(struct saa7134_dev *dev)
{
struct v4l2_ctrl_handler *hdl = &dev->empress_ctrl_handler;
int err;
dprintk("%s: %s\n",dev->name,__func__);
dev->empress_dev = video_device_alloc();
if (NULL == dev->empress_dev)
return -ENOMEM;
*(dev->empress_dev) = saa7134_empress_template;
dev->empress_dev->v4l2_dev = &dev->v4l2_dev;
dev->empress_dev->release = video_device_release;
snprintf(dev->empress_dev->name, sizeof(dev->empress_dev->name),
"%s empress (%s)", dev->name,
saa7134_boards[dev->board].name);
set_bit(V4L2_FL_USE_FH_PRIO, &dev->empress_dev->flags);
v4l2_ctrl_handler_init(hdl, 21);
v4l2_ctrl_add_handler(hdl, &dev->ctrl_handler, empress_ctrl_filter);
if (dev->empress_sd)
v4l2_ctrl_add_handler(hdl, dev->empress_sd->ctrl_handler, NULL);
if (hdl->error) {
video_device_release(dev->empress_dev);
return hdl->error;
}
dev->empress_dev->ctrl_handler = hdl;
INIT_WORK(&dev->empress_workqueue, empress_signal_update);
video_set_drvdata(dev->empress_dev, dev);
err = video_register_device(dev->empress_dev,VFL_TYPE_GRABBER,
empress_nr[dev->nr]);
if (err < 0) {
printk(KERN_INFO "%s: can't register video device\n",
dev->name);
video_device_release(dev->empress_dev);
dev->empress_dev = NULL;
return err;
}
printk(KERN_INFO "%s: registered device %s [mpeg]\n",
dev->name, video_device_node_name(dev->empress_dev));
videobuf_queue_sg_init(&dev->empress_tsq, &saa7134_ts_qops,
&dev->pci->dev, &dev->slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_ALTERNATE,
sizeof(struct saa7134_buf),
dev, NULL);
empress_signal_update(&dev->empress_workqueue);
return 0;
}
static int empress_fini(struct saa7134_dev *dev)
{
dprintk("%s: %s\n",dev->name,__func__);
if (NULL == dev->empress_dev)
return 0;
flush_work(&dev->empress_workqueue);
video_unregister_device(dev->empress_dev);
v4l2_ctrl_handler_free(&dev->empress_ctrl_handler);
dev->empress_dev = NULL;
return 0;
}
static int __init empress_register(void)
{
return saa7134_ts_register(&empress_ops);
}
static void __exit empress_unregister(void)
{
saa7134_ts_unregister(&empress_ops);
}
