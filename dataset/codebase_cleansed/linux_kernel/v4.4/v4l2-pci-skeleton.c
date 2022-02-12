static inline struct skel_buffer *to_skel_buffer(struct vb2_buffer *vb2)
{
return container_of(vb2, struct skel_buffer, vb);
}
static irqreturn_t skeleton_irq(int irq, void *dev_id)
{
#ifdef TODO
struct skeleton *skel = dev_id;
if (captured_new_frame) {
...
spin_lock(&skel->qlock);
list_del(&new_buf->list);
spin_unlock(&skel->qlock);
v4l2_get_timestamp(&new_buf->vb.v4l2_buf.timestamp);
new_buf->vb.v4l2_buf.sequence = skel->sequence++;
new_buf->vb.v4l2_buf.field = skel->field;
if (skel->format.field == V4L2_FIELD_ALTERNATE) {
if (skel->field == V4L2_FIELD_BOTTOM)
skel->field = V4L2_FIELD_TOP;
else if (skel->field == V4L2_FIELD_TOP)
skel->field = V4L2_FIELD_BOTTOM;
}
vb2_buffer_done(&new_buf->vb, VB2_BUF_STATE_DONE);
}
#endif
return IRQ_HANDLED;
}
static int queue_setup(struct vb2_queue *vq, const void *parg,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
const struct v4l2_format *fmt = parg;
struct skeleton *skel = vb2_get_drv_priv(vq);
skel->field = skel->format.field;
if (skel->field == V4L2_FIELD_ALTERNATE) {
if (vb2_fileio_is_active(vq))
return -EINVAL;
skel->field = V4L2_FIELD_TOP;
}
if (vq->num_buffers + *nbuffers < 3)
*nbuffers = 3 - vq->num_buffers;
if (fmt && fmt->fmt.pix.sizeimage < skel->format.sizeimage)
return -EINVAL;
*nplanes = 1;
sizes[0] = fmt ? fmt->fmt.pix.sizeimage : skel->format.sizeimage;
alloc_ctxs[0] = skel->alloc_ctx;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct skeleton *skel = vb2_get_drv_priv(vb->vb2_queue);
unsigned long size = skel->format.sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(&skel->pdev->dev, "buffer too small (%lu < %lu)\n",
vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, size);
return 0;
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct skeleton *skel = vb2_get_drv_priv(vb->vb2_queue);
struct skel_buffer *buf = to_skel_buffer(vb);
unsigned long flags;
spin_lock_irqsave(&skel->qlock, flags);
list_add_tail(&buf->list, &skel->buf_list);
spin_unlock_irqrestore(&skel->qlock, flags);
}
static void return_all_buffers(struct skeleton *skel,
enum vb2_buffer_state state)
{
struct skel_buffer *buf, *node;
unsigned long flags;
spin_lock_irqsave(&skel->qlock, flags);
list_for_each_entry_safe(buf, node, &skel->buf_list, list) {
vb2_buffer_done(&buf->vb, state);
list_del(&buf->list);
}
spin_unlock_irqrestore(&skel->qlock, flags);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct skeleton *skel = vb2_get_drv_priv(vq);
int ret = 0;
skel->sequence = 0;
if (ret) {
return_all_buffers(skel, VB2_BUF_STATE_QUEUED);
}
return ret;
}
static void stop_streaming(struct vb2_queue *vq)
{
struct skeleton *skel = vb2_get_drv_priv(vq);
return_all_buffers(skel, VB2_BUF_STATE_ERROR);
}
static int skeleton_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct skeleton *skel = video_drvdata(file);
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, "V4L2 PCI Skeleton", sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info), "PCI:%s",
pci_name(skel->pdev));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static void skeleton_fill_pix_format(struct skeleton *skel,
struct v4l2_pix_format *pix)
{
pix->pixelformat = V4L2_PIX_FMT_YUYV;
if (skel->input == 0) {
pix->width = 720;
pix->height = (skel->std & V4L2_STD_525_60) ? 480 : 576;
pix->field = V4L2_FIELD_INTERLACED;
pix->colorspace = V4L2_COLORSPACE_SMPTE170M;
} else {
pix->width = skel->timings.bt.width;
pix->height = skel->timings.bt.height;
if (skel->timings.bt.interlaced) {
pix->field = V4L2_FIELD_ALTERNATE;
pix->height /= 2;
} else {
pix->field = V4L2_FIELD_NONE;
}
pix->colorspace = V4L2_COLORSPACE_REC709;
}
pix->bytesperline = pix->width * 2;
pix->sizeimage = pix->bytesperline * pix->height;
pix->priv = 0;
}
static int skeleton_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct skeleton *skel = video_drvdata(file);
struct v4l2_pix_format *pix = &f->fmt.pix;
if (pix->pixelformat != V4L2_PIX_FMT_YUYV)
return -EINVAL;
skeleton_fill_pix_format(skel, pix);
return 0;
}
static int skeleton_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct skeleton *skel = video_drvdata(file);
int ret;
ret = skeleton_try_fmt_vid_cap(file, priv, f);
if (ret)
return ret;
if (vb2_is_busy(&skel->queue))
return -EBUSY;
skel->format = f->fmt.pix;
return 0;
}
static int skeleton_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct skeleton *skel = video_drvdata(file);
f->fmt.pix = skel->format;
return 0;
}
static int skeleton_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
f->pixelformat = V4L2_PIX_FMT_YUYV;
return 0;
}
static int skeleton_s_std(struct file *file, void *priv, v4l2_std_id std)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input)
return -ENODATA;
if (std == skel->std)
return 0;
if (vb2_is_busy(&skel->queue))
return -EBUSY;
skel->std = std;
skeleton_fill_pix_format(skel, &skel->format);
return 0;
}
static int skeleton_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input)
return -ENODATA;
*std = skel->std;
return 0;
}
static int skeleton_querystd(struct file *file, void *priv, v4l2_std_id *std)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input)
return -ENODATA;
#ifdef TODO
get_signal_info();
if (no_signal) {
*std = 0;
return 0;
}
if (signal_has_525_lines)
*std &= V4L2_STD_525_60;
else
*std &= V4L2_STD_625_50;
#endif
return 0;
}
static int skeleton_s_dv_timings(struct file *file, void *_fh,
struct v4l2_dv_timings *timings)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input == 0)
return -ENODATA;
if (!v4l2_valid_dv_timings(timings, &skel_timings_cap, NULL, NULL))
return -EINVAL;
if (!v4l2_find_dv_timings_cap(timings, &skel_timings_cap,
0, NULL, NULL))
return -EINVAL;
if (v4l2_match_dv_timings(timings, &skel->timings, 0))
return 0;
if (vb2_is_busy(&skel->queue))
return -EBUSY;
skel->timings = *timings;
skeleton_fill_pix_format(skel, &skel->format);
return 0;
}
static int skeleton_g_dv_timings(struct file *file, void *_fh,
struct v4l2_dv_timings *timings)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input == 0)
return -ENODATA;
*timings = skel->timings;
return 0;
}
static int skeleton_enum_dv_timings(struct file *file, void *_fh,
struct v4l2_enum_dv_timings *timings)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input == 0)
return -ENODATA;
return v4l2_enum_dv_timings_cap(timings, &skel_timings_cap,
NULL, NULL);
}
static int skeleton_query_dv_timings(struct file *file, void *_fh,
struct v4l2_dv_timings *timings)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input == 0)
return -ENODATA;
#ifdef TODO
detect_timings();
if (no_signal)
return -ENOLINK;
if (cannot_lock_to_signal)
return -ENOLCK;
if (signal_out_of_range_of_capabilities)
return -ERANGE;
v4l2_print_dv_timings(skel->v4l2_dev.name, "query_dv_timings:",
timings, true);
#endif
return 0;
}
static int skeleton_dv_timings_cap(struct file *file, void *fh,
struct v4l2_dv_timings_cap *cap)
{
struct skeleton *skel = video_drvdata(file);
if (skel->input == 0)
return -ENODATA;
*cap = skel_timings_cap;
return 0;
}
static int skeleton_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index > 1)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
if (i->index == 0) {
i->std = SKEL_TVNORMS;
strlcpy(i->name, "S-Video", sizeof(i->name));
i->capabilities = V4L2_IN_CAP_STD;
} else {
i->std = 0;
strlcpy(i->name, "HDMI", sizeof(i->name));
i->capabilities = V4L2_IN_CAP_DV_TIMINGS;
}
return 0;
}
static int skeleton_s_input(struct file *file, void *priv, unsigned int i)
{
struct skeleton *skel = video_drvdata(file);
if (i > 1)
return -EINVAL;
if (vb2_is_busy(&skel->queue))
return -EBUSY;
skel->input = i;
skel->vdev.tvnorms = i ? 0 : SKEL_TVNORMS;
skeleton_fill_pix_format(skel, &skel->format);
return 0;
}
static int skeleton_g_input(struct file *file, void *priv, unsigned int *i)
{
struct skeleton *skel = video_drvdata(file);
*i = skel->input;
return 0;
}
static int skeleton_s_ctrl(struct v4l2_ctrl *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
break;
case V4L2_CID_CONTRAST:
break;
case V4L2_CID_SATURATION:
break;
case V4L2_CID_HUE:
break;
default:
return -EINVAL;
}
return 0;
}
static int skeleton_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
static const struct v4l2_dv_timings timings_def =
V4L2_DV_BT_CEA_1280X720P60;
struct skeleton *skel;
struct video_device *vdev;
struct v4l2_ctrl_handler *hdl;
struct vb2_queue *q;
int ret;
ret = pci_enable_device(pdev);
if (ret)
return ret;
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (ret) {
dev_err(&pdev->dev, "no suitable DMA available.\n");
goto disable_pci;
}
skel = devm_kzalloc(&pdev->dev, sizeof(struct skeleton), GFP_KERNEL);
if (!skel)
return -ENOMEM;
ret = devm_request_irq(&pdev->dev, pdev->irq,
skeleton_irq, 0, KBUILD_MODNAME, skel);
if (ret) {
dev_err(&pdev->dev, "request_irq failed\n");
goto disable_pci;
}
skel->pdev = pdev;
skel->timings = timings_def;
skel->std = V4L2_STD_625_50;
skeleton_fill_pix_format(skel, &skel->format);
ret = v4l2_device_register(&pdev->dev, &skel->v4l2_dev);
if (ret)
goto disable_pci;
mutex_init(&skel->lock);
hdl = &skel->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &skel_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 127);
v4l2_ctrl_new_std(hdl, &skel_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 16);
v4l2_ctrl_new_std(hdl, &skel_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 127);
v4l2_ctrl_new_std(hdl, &skel_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
if (hdl->error) {
ret = hdl->error;
goto free_hdl;
}
skel->v4l2_dev.ctrl_handler = hdl;
q = &skel->queue;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_DMABUF | VB2_READ;
q->drv_priv = skel;
q->buf_struct_size = sizeof(struct skel_buffer);
q->ops = &skel_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
q->lock = &skel->lock;
q->gfp_flags = GFP_DMA32;
ret = vb2_queue_init(q);
if (ret)
goto free_hdl;
skel->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(skel->alloc_ctx)) {
dev_err(&pdev->dev, "Can't allocate buffer context");
ret = PTR_ERR(skel->alloc_ctx);
goto free_hdl;
}
INIT_LIST_HEAD(&skel->buf_list);
spin_lock_init(&skel->qlock);
vdev = &skel->vdev;
strlcpy(vdev->name, KBUILD_MODNAME, sizeof(vdev->name));
vdev->release = video_device_release_empty;
vdev->fops = &skel_fops,
vdev->ioctl_ops = &skel_ioctl_ops,
vdev->lock = &skel->lock;
vdev->queue = q;
vdev->v4l2_dev = &skel->v4l2_dev;
vdev->tvnorms = SKEL_TVNORMS;
video_set_drvdata(vdev, skel);
ret = video_register_device(vdev, VFL_TYPE_GRABBER, -1);
if (ret)
goto free_ctx;
dev_info(&pdev->dev, "V4L2 PCI Skeleton Driver loaded\n");
return 0;
free_ctx:
vb2_dma_contig_cleanup_ctx(skel->alloc_ctx);
free_hdl:
v4l2_ctrl_handler_free(&skel->ctrl_handler);
v4l2_device_unregister(&skel->v4l2_dev);
disable_pci:
pci_disable_device(pdev);
return ret;
}
static void skeleton_remove(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pdev);
struct skeleton *skel = container_of(v4l2_dev, struct skeleton, v4l2_dev);
video_unregister_device(&skel->vdev);
v4l2_ctrl_handler_free(&skel->ctrl_handler);
vb2_dma_contig_cleanup_ctx(skel->alloc_ctx);
v4l2_device_unregister(&skel->v4l2_dev);
pci_disable_device(skel->pdev);
}
