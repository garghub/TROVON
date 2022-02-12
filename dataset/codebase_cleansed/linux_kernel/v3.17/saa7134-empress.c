static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct saa7134_dmaqueue *dmaq = vq->drv_priv;
struct saa7134_dev *dev = dmaq->dev;
u32 leading_null_bytes = 0;
int err;
err = saa7134_ts_start_streaming(vq, count);
if (err)
return err;
switch (dev->board) {
case SAA7134_BOARD_BEHOLD_M6:
case SAA7134_BOARD_BEHOLD_M63:
case SAA7134_BOARD_BEHOLD_M6_EXTRA:
leading_null_bytes = 1;
break;
}
saa_call_all(dev, core, init, leading_null_bytes);
saa_writeb(SAA7134_AUDIO_MUTE_CTRL,
saa_readb(SAA7134_AUDIO_MUTE_CTRL) & ~(1 << 6));
dev->empress_started = 1;
return 0;
}
static void stop_streaming(struct vb2_queue *vq)
{
struct saa7134_dmaqueue *dmaq = vq->drv_priv;
struct saa7134_dev *dev = dmaq->dev;
saa7134_ts_stop_streaming(vq);
saa_writeb(SAA7134_SPECIAL_MODE, 0x00);
msleep(20);
saa_writeb(SAA7134_SPECIAL_MODE, 0x01);
msleep(100);
saa_writeb(SAA7134_AUDIO_MUTE_CTRL,
saa_readb(SAA7134_AUDIO_MUTE_CTRL) | (1 << 6));
dev->empress_started = 0;
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
struct vb2_queue *q;
int err;
dprintk("%s: %s\n",dev->name,__func__);
dev->empress_dev = video_device_alloc();
if (NULL == dev->empress_dev)
return -ENOMEM;
*(dev->empress_dev) = saa7134_empress_template;
dev->empress_dev->v4l2_dev = &dev->v4l2_dev;
dev->empress_dev->release = video_device_release;
dev->empress_dev->lock = &dev->lock;
snprintf(dev->empress_dev->name, sizeof(dev->empress_dev->name),
"%s empress (%s)", dev->name,
saa7134_boards[dev->board].name);
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
q = &dev->empress_vbq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_READ;
q->drv_priv = &dev->ts_q;
q->ops = &saa7134_empress_qops;
q->gfp_flags = GFP_DMA32;
q->mem_ops = &vb2_dma_sg_memops;
q->buf_struct_size = sizeof(struct saa7134_buf);
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &dev->lock;
err = vb2_queue_init(q);
if (err)
return err;
dev->empress_dev->queue = q;
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
vb2_queue_release(&dev->empress_vbq);
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
