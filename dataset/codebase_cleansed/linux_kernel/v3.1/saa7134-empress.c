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
int err;
dprintk("open dev=%s\n", video_device_node_name(vdev));
err = -EBUSY;
if (!mutex_trylock(&dev->empress_tsq.vb_lock))
return err;
if (atomic_read(&dev->empress_users))
goto done;
saa_writeb(SAA7134_AUDIO_MUTE_CTRL,
saa_readb(SAA7134_AUDIO_MUTE_CTRL) & ~(1 << 6));
atomic_inc(&dev->empress_users);
file->private_data = dev;
err = 0;
done:
mutex_unlock(&dev->empress_tsq.vb_lock);
return err;
}
static int ts_release(struct file *file)
{
struct saa7134_dev *dev = file->private_data;
videobuf_stop(&dev->empress_tsq);
videobuf_mmap_free(&dev->empress_tsq);
ts_reset_encoder(dev);
saa_writeb(SAA7134_AUDIO_MUTE_CTRL,
saa_readb(SAA7134_AUDIO_MUTE_CTRL) | (1 << 6));
atomic_dec(&dev->empress_users);
return 0;
}
static ssize_t
ts_read(struct file *file, char __user *data, size_t count, loff_t *ppos)
{
struct saa7134_dev *dev = file->private_data;
if (!dev->empress_started)
ts_init_encoder(dev);
return videobuf_read_stream(&dev->empress_tsq,
data, count, ppos, 0,
file->f_flags & O_NONBLOCK);
}
static unsigned int
ts_poll(struct file *file, struct poll_table_struct *wait)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_poll_stream(file, &dev->empress_tsq, wait);
}
static int
ts_mmap(struct file *file, struct vm_area_struct * vma)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_mmap_mapper(&dev->empress_tsq, vma);
}
static int empress_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct saa7134_dev *dev = file->private_data;
strcpy(cap->driver, "saa7134");
strlcpy(cap->card, saa7134_boards[dev->board].name,
sizeof(cap->card));
sprintf(cap->bus_info, "PCI:%s", pci_name(dev->pci));
cap->capabilities =
V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
return 0;
}
static int empress_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
strcpy(i->name, "CCIR656");
return 0;
}
static int empress_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int empress_s_input(struct file *file, void *priv, unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int empress_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
strlcpy(f->description, "MPEG TS", sizeof(f->description));
f->pixelformat = V4L2_PIX_FMT_MPEG;
return 0;
}
static int empress_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct saa7134_dev *dev = file->private_data;
struct v4l2_mbus_framefmt mbus_fmt;
saa_call_all(dev, video, g_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.sizeimage = TS_PACKET_SIZE * dev->ts.nr_packets;
return 0;
}
static int empress_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct saa7134_dev *dev = file->private_data;
struct v4l2_mbus_framefmt mbus_fmt;
v4l2_fill_mbus_format(&mbus_fmt, &f->fmt.pix, V4L2_MBUS_FMT_FIXED);
saa_call_all(dev, video, s_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(&f->fmt.pix, &mbus_fmt);
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.sizeimage = TS_PACKET_SIZE * dev->ts.nr_packets;
return 0;
}
static int empress_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct saa7134_dev *dev = file->private_data;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_MPEG;
f->fmt.pix.sizeimage = TS_PACKET_SIZE * dev->ts.nr_packets;
return 0;
}
static int empress_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_reqbufs(&dev->empress_tsq, p);
}
static int empress_querybuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_querybuf(&dev->empress_tsq, b);
}
static int empress_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_qbuf(&dev->empress_tsq, b);
}
static int empress_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_dqbuf(&dev->empress_tsq, b,
file->f_flags & O_NONBLOCK);
}
static int empress_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_streamon(&dev->empress_tsq);
}
static int empress_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct saa7134_dev *dev = file->private_data;
return videobuf_streamoff(&dev->empress_tsq);
}
static int empress_s_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *ctrls)
{
struct saa7134_dev *dev = file->private_data;
int err;
if (ctrls->count == 0)
return 0;
if (ctrls->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
err = saa_call_empress(dev, core, s_ext_ctrls, ctrls);
ts_init_encoder(dev);
return err;
}
static int empress_g_ext_ctrls(struct file *file, void *priv,
struct v4l2_ext_controls *ctrls)
{
struct saa7134_dev *dev = file->private_data;
if (ctrls->ctrl_class != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
return saa_call_empress(dev, core, g_ext_ctrls, ctrls);
}
static int empress_g_ctrl(struct file *file, void *priv,
struct v4l2_control *c)
{
struct saa7134_dev *dev = file->private_data;
return saa7134_g_ctrl_internal(dev, NULL, c);
}
static int empress_s_ctrl(struct file *file, void *priv,
struct v4l2_control *c)
{
struct saa7134_dev *dev = file->private_data;
return saa7134_s_ctrl_internal(dev, NULL, c);
}
static int empress_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *c)
{
static const u32 user_ctrls[] = {
V4L2_CID_USER_CLASS,
V4L2_CID_BRIGHTNESS,
V4L2_CID_CONTRAST,
V4L2_CID_SATURATION,
V4L2_CID_HUE,
V4L2_CID_AUDIO_VOLUME,
V4L2_CID_AUDIO_MUTE,
V4L2_CID_HFLIP,
0
};
static const u32 mpeg_ctrls[] = {
V4L2_CID_MPEG_CLASS,
V4L2_CID_MPEG_STREAM_TYPE,
V4L2_CID_MPEG_STREAM_PID_PMT,
V4L2_CID_MPEG_STREAM_PID_AUDIO,
V4L2_CID_MPEG_STREAM_PID_VIDEO,
V4L2_CID_MPEG_STREAM_PID_PCR,
V4L2_CID_MPEG_AUDIO_SAMPLING_FREQ,
V4L2_CID_MPEG_AUDIO_ENCODING,
V4L2_CID_MPEG_AUDIO_L2_BITRATE,
V4L2_CID_MPEG_VIDEO_ENCODING,
V4L2_CID_MPEG_VIDEO_ASPECT,
V4L2_CID_MPEG_VIDEO_BITRATE_MODE,
V4L2_CID_MPEG_VIDEO_BITRATE,
V4L2_CID_MPEG_VIDEO_BITRATE_PEAK,
0
};
static const u32 *ctrl_classes[] = {
user_ctrls,
mpeg_ctrls,
NULL
};
struct saa7134_dev *dev = file->private_data;
c->id = v4l2_ctrl_next(ctrl_classes, c->id);
if (c->id == 0)
return -EINVAL;
if (c->id == V4L2_CID_USER_CLASS || c->id == V4L2_CID_MPEG_CLASS)
return v4l2_ctrl_query_fill(c, 0, 0, 0, 0);
if (V4L2_CTRL_ID2CLASS(c->id) != V4L2_CTRL_CLASS_MPEG)
return saa7134_queryctrl(file, priv, c);
return saa_call_empress(dev, core, queryctrl, c);
}
static int empress_querymenu(struct file *file, void *priv,
struct v4l2_querymenu *c)
{
struct saa7134_dev *dev = file->private_data;
if (V4L2_CTRL_ID2CLASS(c->id) != V4L2_CTRL_CLASS_MPEG)
return -EINVAL;
return saa_call_empress(dev, core, querymenu, c);
}
static int empress_g_chip_ident(struct file *file, void *fh,
struct v4l2_dbg_chip_ident *chip)
{
struct saa7134_dev *dev = file->private_data;
chip->ident = V4L2_IDENT_NONE;
chip->revision = 0;
if (chip->match.type == V4L2_CHIP_MATCH_I2C_DRIVER &&
!strcmp(chip->match.name, "saa6752hs"))
return saa_call_empress(dev, core, g_chip_ident, chip);
if (chip->match.type == V4L2_CHIP_MATCH_I2C_ADDR)
return saa_call_empress(dev, core, g_chip_ident, chip);
return -EINVAL;
}
static int empress_s_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct saa7134_dev *dev = file->private_data;
return saa7134_s_std_internal(dev, NULL, id);
}
static int empress_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct saa7134_dev *dev = file->private_data;
*id = dev->tvnorm->id;
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
static int empress_init(struct saa7134_dev *dev)
{
int err;
dprintk("%s: %s\n",dev->name,__func__);
dev->empress_dev = video_device_alloc();
if (NULL == dev->empress_dev)
return -ENOMEM;
*(dev->empress_dev) = saa7134_empress_template;
dev->empress_dev->parent = &dev->pci->dev;
dev->empress_dev->release = video_device_release;
snprintf(dev->empress_dev->name, sizeof(dev->empress_dev->name),
"%s empress (%s)", dev->name,
saa7134_boards[dev->board].name);
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
flush_work_sync(&dev->empress_workqueue);
video_unregister_device(dev->empress_dev);
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
