static void set_dma_ctrl(struct fbd *fb_desc, u32 ctrl)
{
fb_desc->dma_ctrl = ctrl;
}
static void isi_writel(struct atmel_isi *isi, u32 reg, u32 val)
{
writel(val, isi->regs + reg);
}
static u32 isi_readl(struct atmel_isi *isi, u32 reg)
{
return readl(isi->regs + reg);
}
static void configure_geometry(struct atmel_isi *isi)
{
u32 cfg2, psize;
u32 fourcc = isi->current_fmt->fourcc;
isi->enable_preview_path = fourcc == V4L2_PIX_FMT_RGB565 ||
fourcc == V4L2_PIX_FMT_RGB32;
cfg2 = isi->current_fmt->swap;
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
cfg2 |= ((isi->fmt.fmt.pix.width - 1) << ISI_CFG2_IM_HSIZE_OFFSET) &
ISI_CFG2_IM_HSIZE_MASK;
cfg2 |= ((isi->fmt.fmt.pix.height - 1) << ISI_CFG2_IM_VSIZE_OFFSET)
& ISI_CFG2_IM_VSIZE_MASK;
isi_writel(isi, ISI_CFG2, cfg2);
psize = ((isi->fmt.fmt.pix.width - 1) << ISI_PSIZE_PREV_HSIZE_OFFSET) &
ISI_PSIZE_PREV_HSIZE_MASK;
psize |= ((isi->fmt.fmt.pix.height - 1) << ISI_PSIZE_PREV_VSIZE_OFFSET) &
ISI_PSIZE_PREV_VSIZE_MASK;
isi_writel(isi, ISI_PSIZE, psize);
isi_writel(isi, ISI_PDECF, ISI_PDECF_NO_SAMPLING);
}
static irqreturn_t atmel_isi_handle_streaming(struct atmel_isi *isi)
{
if (isi->active) {
struct vb2_v4l2_buffer *vbuf = &isi->active->vb;
struct frame_buffer *buf = isi->active;
list_del_init(&buf->list);
vbuf->vb2_buf.timestamp = ktime_get_ns();
vbuf->sequence = isi->sequence++;
vbuf->field = V4L2_FIELD_NONE;
vb2_buffer_done(&vbuf->vb2_buf, VB2_BUF_STATE_DONE);
}
if (list_empty(&isi->video_buffer_list)) {
isi->active = NULL;
} else {
isi->active = list_entry(isi->video_buffer_list.next,
struct frame_buffer, list);
if (!isi->enable_preview_path) {
isi_writel(isi, ISI_DMA_C_DSCR,
(u32)isi->active->p_dma_desc->fbd_phys);
isi_writel(isi, ISI_DMA_C_CTRL,
ISI_DMA_CTRL_FETCH | ISI_DMA_CTRL_DONE);
isi_writel(isi, ISI_DMA_CHER, ISI_DMA_CHSR_C_CH);
} else {
isi_writel(isi, ISI_DMA_P_DSCR,
(u32)isi->active->p_dma_desc->fbd_phys);
isi_writel(isi, ISI_DMA_P_CTRL,
ISI_DMA_CTRL_FETCH | ISI_DMA_CTRL_DONE);
isi_writel(isi, ISI_DMA_CHER, ISI_DMA_CHSR_P_CH);
}
}
return IRQ_HANDLED;
}
static irqreturn_t isi_interrupt(int irq, void *dev_id)
{
struct atmel_isi *isi = dev_id;
u32 status, mask, pending;
irqreturn_t ret = IRQ_NONE;
spin_lock(&isi->irqlock);
status = isi_readl(isi, ISI_STATUS);
mask = isi_readl(isi, ISI_INTMASK);
pending = status & mask;
if (pending & ISI_CTRL_SRST) {
complete(&isi->complete);
isi_writel(isi, ISI_INTDIS, ISI_CTRL_SRST);
ret = IRQ_HANDLED;
} else if (pending & ISI_CTRL_DIS) {
complete(&isi->complete);
isi_writel(isi, ISI_INTDIS, ISI_CTRL_DIS);
ret = IRQ_HANDLED;
} else {
if (likely(pending & ISI_SR_CXFR_DONE) ||
likely(pending & ISI_SR_PXFR_DONE))
ret = atmel_isi_handle_streaming(isi);
}
spin_unlock(&isi->irqlock);
return ret;
}
static int atmel_isi_wait_status(struct atmel_isi *isi, int wait_reset)
{
unsigned long timeout;
init_completion(&isi->complete);
if (wait_reset) {
isi_writel(isi, ISI_INTEN, ISI_CTRL_SRST);
isi_writel(isi, ISI_CTRL, ISI_CTRL_SRST);
} else {
isi_writel(isi, ISI_INTEN, ISI_CTRL_DIS);
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
}
timeout = wait_for_completion_timeout(&isi->complete,
msecs_to_jiffies(500));
if (timeout == 0)
return -ETIMEDOUT;
return 0;
}
static int queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct atmel_isi *isi = vb2_get_drv_priv(vq);
unsigned long size;
size = isi->fmt.fmt.pix.sizeimage;
if (*nplanes)
return sizes[0] < size ? -EINVAL : 0;
*nplanes = 1;
sizes[0] = size;
isi->active = NULL;
dev_dbg(isi->dev, "%s, count=%d, size=%ld\n", __func__,
*nbuffers, size);
return 0;
}
static int buffer_init(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
buf->p_dma_desc = NULL;
INIT_LIST_HEAD(&buf->list);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
struct atmel_isi *isi = vb2_get_drv_priv(vb->vb2_queue);
unsigned long size;
struct isi_dma_desc *desc;
size = isi->fmt.fmt.pix.sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(isi->dev, "%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, size);
if (!buf->p_dma_desc) {
if (list_empty(&isi->dma_desc_head)) {
dev_err(isi->dev, "Not enough dma descriptors.\n");
return -EINVAL;
} else {
desc = list_entry(isi->dma_desc_head.next,
struct isi_dma_desc, list);
list_del_init(&desc->list);
desc->p_fbd->fb_address =
vb2_dma_contig_plane_dma_addr(vb, 0);
desc->p_fbd->next_fbd_address = 0;
set_dma_ctrl(desc->p_fbd, ISI_DMA_CTRL_WB);
buf->p_dma_desc = desc;
}
}
return 0;
}
static void buffer_cleanup(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct atmel_isi *isi = vb2_get_drv_priv(vb->vb2_queue);
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
if (buf->p_dma_desc)
list_add(&buf->p_dma_desc->list, &isi->dma_desc_head);
}
static void start_dma(struct atmel_isi *isi, struct frame_buffer *buffer)
{
u32 ctrl, cfg1;
cfg1 = isi_readl(isi, ISI_CFG1);
isi_writel(isi, ISI_INTEN,
ISI_SR_CXFR_DONE | ISI_SR_PXFR_DONE);
if (!isi->enable_preview_path) {
if (isi_readl(isi, ISI_STATUS) & ISI_CTRL_CDC) {
dev_err(isi->dev, "Already in frame handling.\n");
return;
}
isi_writel(isi, ISI_DMA_C_DSCR,
(u32)buffer->p_dma_desc->fbd_phys);
isi_writel(isi, ISI_DMA_C_CTRL,
ISI_DMA_CTRL_FETCH | ISI_DMA_CTRL_DONE);
isi_writel(isi, ISI_DMA_CHER, ISI_DMA_CHSR_C_CH);
} else {
isi_writel(isi, ISI_DMA_P_DSCR,
(u32)buffer->p_dma_desc->fbd_phys);
isi_writel(isi, ISI_DMA_P_CTRL,
ISI_DMA_CTRL_FETCH | ISI_DMA_CTRL_DONE);
isi_writel(isi, ISI_DMA_CHER, ISI_DMA_CHSR_P_CH);
}
cfg1 &= ~ISI_CFG1_FRATE_DIV_MASK;
cfg1 |= isi->pdata.frate | ISI_CFG1_DISCR;
ctrl = ISI_CTRL_EN;
if (!isi->enable_preview_path)
ctrl |= ISI_CTRL_CDC;
isi_writel(isi, ISI_CTRL, ctrl);
isi_writel(isi, ISI_CFG1, cfg1);
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct atmel_isi *isi = vb2_get_drv_priv(vb->vb2_queue);
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
unsigned long flags = 0;
spin_lock_irqsave(&isi->irqlock, flags);
list_add_tail(&buf->list, &isi->video_buffer_list);
if (isi->active == NULL) {
isi->active = buf;
if (vb2_is_streaming(vb->vb2_queue))
start_dma(isi, buf);
}
spin_unlock_irqrestore(&isi->irqlock, flags);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct atmel_isi *isi = vb2_get_drv_priv(vq);
struct frame_buffer *buf, *node;
int ret;
pm_runtime_get_sync(isi->dev);
ret = v4l2_subdev_call(isi->entity.subdev, video, s_stream, 1);
if (ret && ret != -ENOIOCTLCMD) {
dev_err(isi->dev, "stream on failed in subdev\n");
goto err_start_stream;
}
ret = atmel_isi_wait_status(isi, WAIT_ISI_RESET);
if (ret < 0) {
dev_err(isi->dev, "Reset ISI timed out\n");
goto err_reset;
}
isi_writel(isi, ISI_INTDIS, (u32)~0UL);
isi->sequence = 0;
configure_geometry(isi);
spin_lock_irq(&isi->irqlock);
isi_readl(isi, ISI_STATUS);
start_dma(isi, isi->active);
spin_unlock_irq(&isi->irqlock);
return 0;
err_reset:
v4l2_subdev_call(isi->entity.subdev, video, s_stream, 0);
err_start_stream:
pm_runtime_put(isi->dev);
spin_lock_irq(&isi->irqlock);
isi->active = NULL;
list_for_each_entry_safe(buf, node, &isi->video_buffer_list, list) {
list_del_init(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_QUEUED);
}
spin_unlock_irq(&isi->irqlock);
return ret;
}
static void stop_streaming(struct vb2_queue *vq)
{
struct atmel_isi *isi = vb2_get_drv_priv(vq);
struct frame_buffer *buf, *node;
int ret = 0;
unsigned long timeout;
ret = v4l2_subdev_call(isi->entity.subdev, video, s_stream, 0);
if (ret && ret != -ENOIOCTLCMD)
dev_err(isi->dev, "stream off failed in subdev\n");
spin_lock_irq(&isi->irqlock);
isi->active = NULL;
list_for_each_entry_safe(buf, node, &isi->video_buffer_list, list) {
list_del_init(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irq(&isi->irqlock);
if (!isi->enable_preview_path) {
timeout = jiffies + FRAME_INTERVAL_MILLI_SEC * HZ;
while ((isi_readl(isi, ISI_STATUS) & ISI_CTRL_CDC) &&
time_before(jiffies, timeout))
msleep(1);
if (time_after(jiffies, timeout))
dev_err(isi->dev,
"Timeout waiting for finishing codec request\n");
}
isi_writel(isi, ISI_INTDIS,
ISI_SR_CXFR_DONE | ISI_SR_PXFR_DONE);
ret = atmel_isi_wait_status(isi, WAIT_ISI_DISABLE);
if (ret < 0)
dev_err(isi->dev, "Disable ISI timed out\n");
pm_runtime_put(isi->dev);
}
static int isi_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct atmel_isi *isi = video_drvdata(file);
*fmt = isi->fmt;
return 0;
}
static const struct isi_format *find_format_by_fourcc(struct atmel_isi *isi,
unsigned int fourcc)
{
unsigned int num_formats = isi->num_user_formats;
const struct isi_format *fmt;
unsigned int i;
for (i = 0; i < num_formats; i++) {
fmt = isi->user_formats[i];
if (fmt->fourcc == fourcc)
return fmt;
}
return NULL;
}
static int isi_try_fmt(struct atmel_isi *isi, struct v4l2_format *f,
const struct isi_format **current_fmt)
{
const struct isi_format *isi_fmt;
struct v4l2_pix_format *pixfmt = &f->fmt.pix;
struct v4l2_subdev_pad_config pad_cfg;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_TRY,
};
int ret;
isi_fmt = find_format_by_fourcc(isi, pixfmt->pixelformat);
if (!isi_fmt) {
isi_fmt = isi->user_formats[isi->num_user_formats - 1];
pixfmt->pixelformat = isi_fmt->fourcc;
}
pixfmt->width = clamp(pixfmt->width, 0U, MAX_SUPPORT_WIDTH);
pixfmt->height = clamp(pixfmt->height, 0U, MAX_SUPPORT_HEIGHT);
v4l2_fill_mbus_format(&format.format, pixfmt, isi_fmt->mbus_code);
ret = v4l2_subdev_call(isi->entity.subdev, pad, set_fmt,
&pad_cfg, &format);
if (ret < 0)
return ret;
v4l2_fill_pix_format(pixfmt, &format.format);
pixfmt->field = V4L2_FIELD_NONE;
pixfmt->bytesperline = pixfmt->width * isi_fmt->bpp;
pixfmt->sizeimage = pixfmt->bytesperline * pixfmt->height;
if (current_fmt)
*current_fmt = isi_fmt;
return 0;
}
static int isi_set_fmt(struct atmel_isi *isi, struct v4l2_format *f)
{
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
const struct isi_format *current_fmt;
int ret;
ret = isi_try_fmt(isi, f, &current_fmt);
if (ret)
return ret;
v4l2_fill_mbus_format(&format.format, &f->fmt.pix,
current_fmt->mbus_code);
ret = v4l2_subdev_call(isi->entity.subdev, pad,
set_fmt, NULL, &format);
if (ret < 0)
return ret;
isi->fmt = *f;
isi->current_fmt = current_fmt;
return 0;
}
static int isi_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct atmel_isi *isi = video_drvdata(file);
if (vb2_is_streaming(&isi->queue))
return -EBUSY;
return isi_set_fmt(isi, f);
}
static int isi_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct atmel_isi *isi = video_drvdata(file);
return isi_try_fmt(isi, f, NULL);
}
static int isi_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct atmel_isi *isi = video_drvdata(file);
if (f->index >= isi->num_user_formats)
return -EINVAL;
f->pixelformat = isi->user_formats[f->index]->fourcc;
return 0;
}
static int isi_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strlcpy(cap->driver, "atmel-isi", sizeof(cap->driver));
strlcpy(cap->card, "Atmel Image Sensor Interface", sizeof(cap->card));
strlcpy(cap->bus_info, "platform:isi", sizeof(cap->bus_info));
return 0;
}
static int isi_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
strlcpy(i->name, "Camera", sizeof(i->name));
return 0;
}
static int isi_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int isi_s_input(struct file *file, void *priv, unsigned int i)
{
if (i > 0)
return -EINVAL;
return 0;
}
static int isi_g_parm(struct file *file, void *fh, struct v4l2_streamparm *a)
{
struct atmel_isi *isi = video_drvdata(file);
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
a->parm.capture.readbuffers = 2;
return v4l2_subdev_call(isi->entity.subdev, video, g_parm, a);
}
static int isi_s_parm(struct file *file, void *fh, struct v4l2_streamparm *a)
{
struct atmel_isi *isi = video_drvdata(file);
if (a->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
a->parm.capture.readbuffers = 2;
return v4l2_subdev_call(isi->entity.subdev, video, s_parm, a);
}
static int isi_enum_framesizes(struct file *file, void *fh,
struct v4l2_frmsizeenum *fsize)
{
struct atmel_isi *isi = video_drvdata(file);
const struct isi_format *isi_fmt;
struct v4l2_subdev_frame_size_enum fse = {
.index = fsize->index,
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
int ret;
isi_fmt = find_format_by_fourcc(isi, fsize->pixel_format);
if (!isi_fmt)
return -EINVAL;
fse.code = isi_fmt->mbus_code;
ret = v4l2_subdev_call(isi->entity.subdev, pad, enum_frame_size,
NULL, &fse);
if (ret)
return ret;
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = fse.max_width;
fsize->discrete.height = fse.max_height;
return 0;
}
static int isi_enum_frameintervals(struct file *file, void *fh,
struct v4l2_frmivalenum *fival)
{
struct atmel_isi *isi = video_drvdata(file);
const struct isi_format *isi_fmt;
struct v4l2_subdev_frame_interval_enum fie = {
.index = fival->index,
.width = fival->width,
.height = fival->height,
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
int ret;
isi_fmt = find_format_by_fourcc(isi, fival->pixel_format);
if (!isi_fmt)
return -EINVAL;
fie.code = isi_fmt->mbus_code;
ret = v4l2_subdev_call(isi->entity.subdev, pad,
enum_frame_interval, NULL, &fie);
if (ret)
return ret;
fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
fival->discrete = fie.interval;
return 0;
}
static void isi_camera_set_bus_param(struct atmel_isi *isi)
{
u32 cfg1 = 0;
if (isi->pdata.hsync_act_low)
cfg1 |= ISI_CFG1_HSYNC_POL_ACTIVE_LOW;
if (isi->pdata.vsync_act_low)
cfg1 |= ISI_CFG1_VSYNC_POL_ACTIVE_LOW;
if (isi->pdata.pclk_act_falling)
cfg1 |= ISI_CFG1_PIXCLK_POL_ACTIVE_FALLING;
if (isi->pdata.has_emb_sync)
cfg1 |= ISI_CFG1_EMB_SYNC;
if (isi->pdata.full_mode)
cfg1 |= ISI_CFG1_FULL_MODE;
cfg1 |= ISI_CFG1_THMASK_BEATS_16;
pm_runtime_get_sync(isi->dev);
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
isi_writel(isi, ISI_CFG1, cfg1);
pm_runtime_put(isi->dev);
}
static int atmel_isi_parse_dt(struct atmel_isi *isi,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct v4l2_fwnode_endpoint ep;
int err;
isi->pdata.full_mode = 1;
isi->pdata.frate = ISI_CFG1_FRATE_CAPTURE_ALL;
np = of_graph_get_next_endpoint(np, NULL);
if (!np) {
dev_err(&pdev->dev, "Could not find the endpoint\n");
return -EINVAL;
}
err = v4l2_fwnode_endpoint_parse(of_fwnode_handle(np), &ep);
of_node_put(np);
if (err) {
dev_err(&pdev->dev, "Could not parse the endpoint\n");
return err;
}
switch (ep.bus.parallel.bus_width) {
case 8:
isi->pdata.data_width_flags = ISI_DATAWIDTH_8;
break;
case 10:
isi->pdata.data_width_flags =
ISI_DATAWIDTH_8 | ISI_DATAWIDTH_10;
break;
default:
dev_err(&pdev->dev, "Unsupported bus width: %d\n",
ep.bus.parallel.bus_width);
return -EINVAL;
}
if (ep.bus.parallel.flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)
isi->pdata.hsync_act_low = true;
if (ep.bus.parallel.flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)
isi->pdata.vsync_act_low = true;
if (ep.bus.parallel.flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)
isi->pdata.pclk_act_falling = true;
if (ep.bus_type == V4L2_MBUS_BT656)
isi->pdata.has_emb_sync = true;
return 0;
}
static int isi_open(struct file *file)
{
struct atmel_isi *isi = video_drvdata(file);
struct v4l2_subdev *sd = isi->entity.subdev;
int ret;
if (mutex_lock_interruptible(&isi->lock))
return -ERESTARTSYS;
ret = v4l2_fh_open(file);
if (ret < 0)
goto unlock;
if (!v4l2_fh_is_singular_file(file))
goto fh_rel;
ret = v4l2_subdev_call(sd, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
goto fh_rel;
ret = isi_set_fmt(isi, &isi->fmt);
if (ret)
v4l2_subdev_call(sd, core, s_power, 0);
fh_rel:
if (ret)
v4l2_fh_release(file);
unlock:
mutex_unlock(&isi->lock);
return ret;
}
static int isi_release(struct file *file)
{
struct atmel_isi *isi = video_drvdata(file);
struct v4l2_subdev *sd = isi->entity.subdev;
bool fh_singular;
int ret;
mutex_lock(&isi->lock);
fh_singular = v4l2_fh_is_singular_file(file);
ret = _vb2_fop_release(file, NULL);
if (fh_singular)
v4l2_subdev_call(sd, core, s_power, 0);
mutex_unlock(&isi->lock);
return ret;
}
static int isi_set_default_fmt(struct atmel_isi *isi)
{
struct v4l2_format f = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
.fmt.pix = {
.width = VGA_WIDTH,
.height = VGA_HEIGHT,
.field = V4L2_FIELD_NONE,
.pixelformat = isi->user_formats[0]->fourcc,
},
};
int ret;
ret = isi_try_fmt(isi, &f, NULL);
if (ret)
return ret;
isi->current_fmt = isi->user_formats[0];
isi->fmt = f;
return 0;
}
static int isi_formats_init(struct atmel_isi *isi)
{
const struct isi_format *isi_fmts[ARRAY_SIZE(isi_formats)];
unsigned int num_fmts = 0, i, j;
struct v4l2_subdev *subdev = isi->entity.subdev;
struct v4l2_subdev_mbus_code_enum mbus_code = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
while (!v4l2_subdev_call(subdev, pad, enum_mbus_code,
NULL, &mbus_code)) {
for (i = 0; i < ARRAY_SIZE(isi_formats); i++) {
if (isi_formats[i].mbus_code != mbus_code.code)
continue;
for (j = 0; j < num_fmts; j++)
if (isi_fmts[j]->fourcc == isi_formats[i].fourcc)
break;
if (j == num_fmts)
isi_fmts[num_fmts++] = isi_formats + i;
}
mbus_code.index++;
}
if (!num_fmts)
return -ENXIO;
isi->num_user_formats = num_fmts;
isi->user_formats = devm_kcalloc(isi->dev,
num_fmts, sizeof(struct isi_format *),
GFP_KERNEL);
if (!isi->user_formats) {
dev_err(isi->dev, "could not allocate memory\n");
return -ENOMEM;
}
memcpy(isi->user_formats, isi_fmts,
num_fmts * sizeof(struct isi_format *));
isi->current_fmt = isi->user_formats[0];
return 0;
}
static int isi_graph_notify_complete(struct v4l2_async_notifier *notifier)
{
struct atmel_isi *isi = notifier_to_isi(notifier);
int ret;
isi->vdev->ctrl_handler = isi->entity.subdev->ctrl_handler;
ret = isi_formats_init(isi);
if (ret) {
dev_err(isi->dev, "No supported mediabus format found\n");
return ret;
}
isi_camera_set_bus_param(isi);
ret = isi_set_default_fmt(isi);
if (ret) {
dev_err(isi->dev, "Could not set default format\n");
return ret;
}
ret = video_register_device(isi->vdev, VFL_TYPE_GRABBER, -1);
if (ret) {
dev_err(isi->dev, "Failed to register video device\n");
return ret;
}
dev_dbg(isi->dev, "Device registered as %s\n",
video_device_node_name(isi->vdev));
return 0;
}
static void isi_graph_notify_unbind(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *sd,
struct v4l2_async_subdev *asd)
{
struct atmel_isi *isi = notifier_to_isi(notifier);
dev_dbg(isi->dev, "Removing %s\n", video_device_node_name(isi->vdev));
video_unregister_device(isi->vdev);
}
static int isi_graph_notify_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct atmel_isi *isi = notifier_to_isi(notifier);
dev_dbg(isi->dev, "subdev %s bound\n", subdev->name);
isi->entity.subdev = subdev;
return 0;
}
static int isi_graph_parse(struct atmel_isi *isi, struct device_node *node)
{
struct device_node *ep = NULL;
struct device_node *remote;
while (1) {
ep = of_graph_get_next_endpoint(node, ep);
if (!ep)
return -EINVAL;
remote = of_graph_get_remote_port_parent(ep);
if (!remote) {
of_node_put(ep);
return -EINVAL;
}
isi->entity.node = remote;
isi->entity.asd.match_type = V4L2_ASYNC_MATCH_FWNODE;
isi->entity.asd.match.fwnode.fwnode = of_fwnode_handle(remote);
return 0;
}
}
static int isi_graph_init(struct atmel_isi *isi)
{
struct v4l2_async_subdev **subdevs = NULL;
int ret;
ret = isi_graph_parse(isi, isi->dev->of_node);
if (ret < 0) {
dev_err(isi->dev, "Graph parsing failed\n");
return ret;
}
subdevs = devm_kzalloc(isi->dev, sizeof(*subdevs), GFP_KERNEL);
if (subdevs == NULL) {
of_node_put(isi->entity.node);
return -ENOMEM;
}
subdevs[0] = &isi->entity.asd;
isi->notifier.subdevs = subdevs;
isi->notifier.num_subdevs = 1;
isi->notifier.bound = isi_graph_notify_bound;
isi->notifier.unbind = isi_graph_notify_unbind;
isi->notifier.complete = isi_graph_notify_complete;
ret = v4l2_async_notifier_register(&isi->v4l2_dev, &isi->notifier);
if (ret < 0) {
dev_err(isi->dev, "Notifier registration failed\n");
of_node_put(isi->entity.node);
return ret;
}
return 0;
}
static int atmel_isi_probe(struct platform_device *pdev)
{
int irq;
struct atmel_isi *isi;
struct vb2_queue *q;
struct resource *regs;
int ret, i;
isi = devm_kzalloc(&pdev->dev, sizeof(struct atmel_isi), GFP_KERNEL);
if (!isi) {
dev_err(&pdev->dev, "Can't allocate interface!\n");
return -ENOMEM;
}
isi->pclk = devm_clk_get(&pdev->dev, "isi_clk");
if (IS_ERR(isi->pclk))
return PTR_ERR(isi->pclk);
ret = atmel_isi_parse_dt(isi, pdev);
if (ret)
return ret;
isi->active = NULL;
isi->dev = &pdev->dev;
mutex_init(&isi->lock);
spin_lock_init(&isi->irqlock);
INIT_LIST_HEAD(&isi->video_buffer_list);
INIT_LIST_HEAD(&isi->dma_desc_head);
q = &isi->queue;
ret = v4l2_device_register(&pdev->dev, &isi->v4l2_dev);
if (ret)
return ret;
isi->vdev = video_device_alloc();
if (isi->vdev == NULL) {
ret = -ENOMEM;
goto err_vdev_alloc;
}
isi->vdev->fops = &isi_fops;
isi->vdev->v4l2_dev = &isi->v4l2_dev;
isi->vdev->queue = &isi->queue;
strlcpy(isi->vdev->name, KBUILD_MODNAME, sizeof(isi->vdev->name));
isi->vdev->release = video_device_release;
isi->vdev->ioctl_ops = &isi_ioctl_ops;
isi->vdev->lock = &isi->lock;
isi->vdev->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
video_set_drvdata(isi->vdev, isi);
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_READ | VB2_DMABUF;
q->lock = &isi->lock;
q->drv_priv = isi;
q->buf_struct_size = sizeof(struct frame_buffer);
q->ops = &isi_video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
q->dev = &pdev->dev;
ret = vb2_queue_init(q);
if (ret < 0) {
dev_err(&pdev->dev, "failed to initialize VB2 queue\n");
goto err_vb2_queue;
}
isi->p_fb_descriptors = dma_alloc_coherent(&pdev->dev,
sizeof(struct fbd) * VIDEO_MAX_FRAME,
&isi->fb_descriptors_phys,
GFP_KERNEL);
if (!isi->p_fb_descriptors) {
dev_err(&pdev->dev, "Can't allocate descriptors!\n");
ret = -ENOMEM;
goto err_dma_alloc;
}
for (i = 0; i < VIDEO_MAX_FRAME; i++) {
isi->dma_desc[i].p_fbd = isi->p_fb_descriptors + i;
isi->dma_desc[i].fbd_phys = isi->fb_descriptors_phys +
i * sizeof(struct fbd);
list_add(&isi->dma_desc[i].list, &isi->dma_desc_head);
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
isi->regs = devm_ioremap_resource(&pdev->dev, regs);
if (IS_ERR(isi->regs)) {
ret = PTR_ERR(isi->regs);
goto err_ioremap;
}
if (isi->pdata.data_width_flags & ISI_DATAWIDTH_8)
isi->width_flags = 1 << 7;
if (isi->pdata.data_width_flags & ISI_DATAWIDTH_10)
isi->width_flags |= 1 << 9;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto err_req_irq;
}
ret = devm_request_irq(&pdev->dev, irq, isi_interrupt, 0, "isi", isi);
if (ret) {
dev_err(&pdev->dev, "Unable to request irq %d\n", irq);
goto err_req_irq;
}
isi->irq = irq;
ret = isi_graph_init(isi);
if (ret < 0)
goto err_req_irq;
pm_suspend_ignore_children(&pdev->dev, true);
pm_runtime_enable(&pdev->dev);
platform_set_drvdata(pdev, isi);
return 0;
err_req_irq:
err_ioremap:
dma_free_coherent(&pdev->dev,
sizeof(struct fbd) * VIDEO_MAX_FRAME,
isi->p_fb_descriptors,
isi->fb_descriptors_phys);
err_dma_alloc:
err_vb2_queue:
video_device_release(isi->vdev);
err_vdev_alloc:
v4l2_device_unregister(&isi->v4l2_dev);
return ret;
}
static int atmel_isi_remove(struct platform_device *pdev)
{
struct atmel_isi *isi = platform_get_drvdata(pdev);
dma_free_coherent(&pdev->dev,
sizeof(struct fbd) * VIDEO_MAX_FRAME,
isi->p_fb_descriptors,
isi->fb_descriptors_phys);
pm_runtime_disable(&pdev->dev);
v4l2_async_notifier_unregister(&isi->notifier);
v4l2_device_unregister(&isi->v4l2_dev);
return 0;
}
static int atmel_isi_runtime_suspend(struct device *dev)
{
struct atmel_isi *isi = dev_get_drvdata(dev);
clk_disable_unprepare(isi->pclk);
return 0;
}
static int atmel_isi_runtime_resume(struct device *dev)
{
struct atmel_isi *isi = dev_get_drvdata(dev);
return clk_prepare_enable(isi->pclk);
}
