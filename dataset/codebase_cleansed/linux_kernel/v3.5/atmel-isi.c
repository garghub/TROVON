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
static int configure_geometry(struct atmel_isi *isi, u32 width,
u32 height, enum v4l2_mbus_pixelcode code)
{
u32 cfg2, cr;
switch (code) {
case V4L2_MBUS_FMT_Y8_1X8:
cr = ISI_CFG2_GRAYSCALE;
break;
case V4L2_MBUS_FMT_UYVY8_2X8:
cr = ISI_CFG2_YCC_SWAP_MODE_3;
break;
case V4L2_MBUS_FMT_VYUY8_2X8:
cr = ISI_CFG2_YCC_SWAP_MODE_2;
break;
case V4L2_MBUS_FMT_YUYV8_2X8:
cr = ISI_CFG2_YCC_SWAP_MODE_1;
break;
case V4L2_MBUS_FMT_YVYU8_2X8:
cr = ISI_CFG2_YCC_SWAP_DEFAULT;
break;
default:
return -EINVAL;
}
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
cfg2 = isi_readl(isi, ISI_CFG2);
cfg2 |= cr;
cfg2 &= ~(ISI_CFG2_IM_HSIZE_MASK);
cfg2 |= ((width - 1) << ISI_CFG2_IM_HSIZE_OFFSET) &
ISI_CFG2_IM_HSIZE_MASK;
cfg2 &= ~(ISI_CFG2_IM_VSIZE_MASK);
cfg2 |= ((height - 1) << ISI_CFG2_IM_VSIZE_OFFSET)
& ISI_CFG2_IM_VSIZE_MASK;
isi_writel(isi, ISI_CFG2, cfg2);
return 0;
}
static irqreturn_t atmel_isi_handle_streaming(struct atmel_isi *isi)
{
if (isi->active) {
struct vb2_buffer *vb = &isi->active->vb;
struct frame_buffer *buf = isi->active;
list_del_init(&buf->list);
do_gettimeofday(&vb->v4l2_buf.timestamp);
vb->v4l2_buf.sequence = isi->sequence++;
vb2_buffer_done(vb, VB2_BUF_STATE_DONE);
}
if (list_empty(&isi->video_buffer_list)) {
isi->active = NULL;
} else {
isi->active = list_entry(isi->video_buffer_list.next,
struct frame_buffer, list);
isi_writel(isi, ISI_DMA_C_DSCR,
isi->active->p_dma_desc->fbd_phys);
isi_writel(isi, ISI_DMA_C_CTRL,
ISI_DMA_CTRL_FETCH | ISI_DMA_CTRL_DONE);
isi_writel(isi, ISI_DMA_CHER, ISI_DMA_CHSR_C_CH);
}
return IRQ_HANDLED;
}
static irqreturn_t isi_interrupt(int irq, void *dev_id)
{
struct atmel_isi *isi = dev_id;
u32 status, mask, pending;
irqreturn_t ret = IRQ_NONE;
spin_lock(&isi->lock);
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
if ((pending & ISI_SR_VSYNC) &&
(isi->state == ISI_STATE_IDLE)) {
isi->state = ISI_STATE_READY;
wake_up_interruptible(&isi->vsync_wq);
ret = IRQ_HANDLED;
}
if (likely(pending & ISI_SR_CXFR_DONE))
ret = atmel_isi_handle_streaming(isi);
}
spin_unlock(&isi->lock);
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
msecs_to_jiffies(100));
if (timeout == 0)
return -ETIMEDOUT;
return 0;
}
static int queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
unsigned long size;
int ret;
ret = atmel_isi_wait_status(isi, WAIT_ISI_RESET);
if (ret < 0) {
dev_err(icd->parent, "Reset ISI timed out\n");
return ret;
}
isi_writel(isi, ISI_INTDIS, ~0UL);
size = icd->sizeimage;
if (!*nbuffers || *nbuffers > MAX_BUFFER_NUM)
*nbuffers = MAX_BUFFER_NUM;
if (size * *nbuffers > VID_LIMIT_BYTES)
*nbuffers = VID_LIMIT_BYTES / size;
*nplanes = 1;
sizes[0] = size;
alloc_ctxs[0] = isi->alloc_ctx;
isi->sequence = 0;
isi->active = NULL;
dev_dbg(icd->parent, "%s, count=%d, size=%ld\n", __func__,
*nbuffers, size);
return 0;
}
static int buffer_init(struct vb2_buffer *vb)
{
struct frame_buffer *buf = container_of(vb, struct frame_buffer, vb);
buf->p_dma_desc = NULL;
INIT_LIST_HEAD(&buf->list);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct frame_buffer *buf = container_of(vb, struct frame_buffer, vb);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
unsigned long size;
struct isi_dma_desc *desc;
size = icd->sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(icd->parent, "%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(&buf->vb, 0, size);
if (!buf->p_dma_desc) {
if (list_empty(&isi->dma_desc_head)) {
dev_err(icd->parent, "Not enough dma descriptors.\n");
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
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct frame_buffer *buf = container_of(vb, struct frame_buffer, vb);
if (buf->p_dma_desc)
list_add(&buf->p_dma_desc->list, &isi->dma_desc_head);
}
static void start_dma(struct atmel_isi *isi, struct frame_buffer *buffer)
{
u32 ctrl, cfg1;
cfg1 = isi_readl(isi, ISI_CFG1);
isi_writel(isi, ISI_INTEN,
ISI_SR_CXFR_DONE | ISI_SR_PXFR_DONE);
if (isi_readl(isi, ISI_STATUS) & ISI_CTRL_CDC) {
dev_err(isi->icd->parent, "Already in frame handling.\n");
return;
}
isi_writel(isi, ISI_DMA_C_DSCR, buffer->p_dma_desc->fbd_phys);
isi_writel(isi, ISI_DMA_C_CTRL, ISI_DMA_CTRL_FETCH | ISI_DMA_CTRL_DONE);
isi_writel(isi, ISI_DMA_CHER, ISI_DMA_CHSR_C_CH);
cfg1 |= isi->pdata->frate | ISI_CFG1_DISCR;
ctrl = ISI_CTRL_CDC | ISI_CTRL_EN;
isi_writel(isi, ISI_CTRL, ctrl);
isi_writel(isi, ISI_CFG1, cfg1);
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct frame_buffer *buf = container_of(vb, struct frame_buffer, vb);
unsigned long flags = 0;
spin_lock_irqsave(&isi->lock, flags);
list_add_tail(&buf->list, &isi->video_buffer_list);
if (isi->active == NULL) {
isi->active = buf;
if (vb2_is_streaming(vb->vb2_queue))
start_dma(isi, buf);
}
spin_unlock_irqrestore(&isi->lock, flags);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
u32 sr = 0;
int ret;
spin_lock_irq(&isi->lock);
isi->state = ISI_STATE_IDLE;
sr = isi_readl(isi, ISI_STATUS);
isi_writel(isi, ISI_INTEN, ISI_SR_VSYNC);
isi_writel(isi, ISI_CTRL, ISI_CTRL_EN);
spin_unlock_irq(&isi->lock);
dev_dbg(icd->parent, "Waiting for SOF\n");
ret = wait_event_interruptible(isi->vsync_wq,
isi->state != ISI_STATE_IDLE);
if (ret)
goto err;
if (isi->state != ISI_STATE_READY) {
ret = -EIO;
goto err;
}
spin_lock_irq(&isi->lock);
isi->state = ISI_STATE_WAIT_SOF;
isi_writel(isi, ISI_INTDIS, ISI_SR_VSYNC);
if (count)
start_dma(isi, isi->active);
spin_unlock_irq(&isi->lock);
return 0;
err:
isi->active = NULL;
isi->sequence = 0;
INIT_LIST_HEAD(&isi->video_buffer_list);
return ret;
}
static int stop_streaming(struct vb2_queue *vq)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct frame_buffer *buf, *node;
int ret = 0;
unsigned long timeout;
spin_lock_irq(&isi->lock);
isi->active = NULL;
list_for_each_entry_safe(buf, node, &isi->video_buffer_list, list) {
list_del_init(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irq(&isi->lock);
timeout = jiffies + FRAME_INTERVAL_MILLI_SEC * HZ;
while ((isi_readl(isi, ISI_STATUS) & ISI_CTRL_CDC) &&
time_before(jiffies, timeout))
msleep(1);
if (time_after(jiffies, timeout)) {
dev_err(icd->parent,
"Timeout waiting for finishing codec request\n");
return -ETIMEDOUT;
}
isi_writel(isi, ISI_INTDIS,
ISI_SR_CXFR_DONE | ISI_SR_PXFR_DONE);
ret = atmel_isi_wait_status(isi, WAIT_ISI_DISABLE);
if (ret < 0)
dev_err(icd->parent, "Disable ISI timed out\n");
return ret;
}
static int isi_camera_init_videobuf(struct vb2_queue *q,
struct soc_camera_device *icd)
{
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP;
q->drv_priv = icd;
q->buf_struct_size = sizeof(struct frame_buffer);
q->ops = &isi_video_qops;
q->mem_ops = &vb2_dma_contig_memops;
return vb2_queue_init(q);
}
static int isi_camera_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd, pix->pixelformat);
if (!xlate) {
dev_warn(icd->parent, "Format %x not found\n",
pix->pixelformat);
return -EINVAL;
}
dev_dbg(icd->parent, "Plan to set format %dx%d\n",
pix->width, pix->height);
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
ret = v4l2_subdev_call(sd, video, s_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (mf.code != xlate->code)
return -EINVAL;
ret = configure_geometry(isi, pix->width, pix->height, xlate->code);
if (ret < 0)
return ret;
pix->width = mf.width;
pix->height = mf.height;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
icd->current_fmt = xlate;
dev_dbg(icd->parent, "Finally set format %dx%d\n",
pix->width, pix->height);
return ret;
}
static int isi_camera_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
u32 pixfmt = pix->pixelformat;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (pixfmt && !xlate) {
dev_warn(icd->parent, "Format %x not found\n", pixfmt);
return -EINVAL;
}
if (pix->height > MAX_SUPPORT_HEIGHT)
pix->height = MAX_SUPPORT_HEIGHT;
if (pix->width > MAX_SUPPORT_WIDTH)
pix->width = MAX_SUPPORT_WIDTH;
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
ret = v4l2_subdev_call(sd, video, try_mbus_fmt, &mf);
if (ret < 0)
return ret;
pix->width = mf.width;
pix->height = mf.height;
pix->colorspace = mf.colorspace;
switch (mf.field) {
case V4L2_FIELD_ANY:
pix->field = V4L2_FIELD_NONE;
break;
case V4L2_FIELD_NONE:
break;
default:
dev_err(icd->parent, "Field type %d unsupported.\n",
mf.field);
ret = -EINVAL;
}
return ret;
}
static bool isi_camera_packing_supported(const struct soc_mbus_pixelfmt *fmt)
{
return fmt->packing == SOC_MBUS_PACKING_NONE ||
(fmt->bits_per_sample == 8 &&
fmt->packing == SOC_MBUS_PACKING_2X8_PADHI) ||
(fmt->bits_per_sample > 8 &&
fmt->packing == SOC_MBUS_PACKING_EXTEND16);
}
static int isi_camera_try_bus_param(struct soc_camera_device *icd,
unsigned char buswidth)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
unsigned long common_flags;
int ret;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg,
ISI_BUS_PARAM);
if (!common_flags) {
dev_warn(icd->parent,
"Flags incompatible: camera 0x%x, host 0x%x\n",
cfg.flags, ISI_BUS_PARAM);
return -EINVAL;
}
} else if (ret != -ENOIOCTLCMD) {
return ret;
}
if ((1 << (buswidth - 1)) & isi->width_flags)
return 0;
return -EINVAL;
}
static int isi_camera_get_formats(struct soc_camera_device *icd,
unsigned int idx,
struct soc_camera_format_xlate *xlate)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
int formats = 0, ret;
enum v4l2_mbus_pixelcode code;
const struct soc_mbus_pixelfmt *fmt;
ret = v4l2_subdev_call(sd, video, enum_mbus_fmt, idx, &code);
if (ret < 0)
return 0;
fmt = soc_mbus_get_fmtdesc(code);
if (!fmt) {
dev_err(icd->parent,
"Invalid format code #%u: %d\n", idx, code);
return 0;
}
ret = isi_camera_try_bus_param(icd, fmt->bits_per_sample);
if (ret < 0) {
dev_err(icd->parent,
"Fail to try the bus parameters.\n");
return 0;
}
switch (code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
case V4L2_MBUS_FMT_VYUY8_2X8:
case V4L2_MBUS_FMT_YUYV8_2X8:
case V4L2_MBUS_FMT_YVYU8_2X8:
formats++;
if (xlate) {
xlate->host_fmt = &isi_camera_formats[0];
xlate->code = code;
xlate++;
dev_dbg(icd->parent, "Providing format %s using code %d\n",
isi_camera_formats[0].name, code);
}
break;
default:
if (!isi_camera_packing_supported(fmt))
return 0;
if (xlate)
dev_dbg(icd->parent,
"Providing format %s in pass-through mode\n",
fmt->name);
}
formats++;
if (xlate) {
xlate->host_fmt = fmt;
xlate->code = code;
xlate++;
}
return formats;
}
static int isi_camera_add_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
int ret;
if (isi->icd)
return -EBUSY;
ret = clk_enable(isi->pclk);
if (ret)
return ret;
ret = clk_enable(isi->mck);
if (ret) {
clk_disable(isi->pclk);
return ret;
}
isi->icd = icd;
dev_dbg(icd->parent, "Atmel ISI Camera driver attached to camera %d\n",
icd->devnum);
return 0;
}
static void isi_camera_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
BUG_ON(icd != isi->icd);
clk_disable(isi->mck);
clk_disable(isi->pclk);
isi->icd = NULL;
dev_dbg(icd->parent, "Atmel ISI Camera driver detached from camera %d\n",
icd->devnum);
}
static unsigned int isi_camera_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
return vb2_poll(&icd->vb2_vidq, file, pt);
}
static int isi_camera_querycap(struct soc_camera_host *ici,
struct v4l2_capability *cap)
{
strcpy(cap->driver, "atmel-isi");
strcpy(cap->card, "Atmel Image Sensor Interface");
cap->capabilities = (V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING);
return 0;
}
static int isi_camera_set_bus_param(struct soc_camera_device *icd)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
unsigned long common_flags;
int ret;
u32 cfg1 = 0;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg,
ISI_BUS_PARAM);
if (!common_flags) {
dev_warn(icd->parent,
"Flags incompatible: camera 0x%x, host 0x%x\n",
cfg.flags, ISI_BUS_PARAM);
return -EINVAL;
}
} else if (ret != -ENOIOCTLCMD) {
return ret;
} else {
common_flags = ISI_BUS_PARAM;
}
dev_dbg(icd->parent, "Flags cam: 0x%x host: 0x%x common: 0x%lx\n",
cfg.flags, ISI_BUS_PARAM, common_flags);
if ((common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)) {
if (isi->pdata->hsync_act_low)
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)) {
if (isi->pdata->vsync_act_low)
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_PCLK_SAMPLE_RISING) &&
(common_flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)) {
if (isi->pdata->pclk_act_falling)
common_flags &= ~V4L2_MBUS_PCLK_SAMPLE_RISING;
else
common_flags &= ~V4L2_MBUS_PCLK_SAMPLE_FALLING;
}
cfg.flags = common_flags;
ret = v4l2_subdev_call(sd, video, s_mbus_config, &cfg);
if (ret < 0 && ret != -ENOIOCTLCMD) {
dev_dbg(icd->parent, "camera s_mbus_config(0x%lx) returned %d\n",
common_flags, ret);
return ret;
}
if (common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)
cfg1 |= ISI_CFG1_HSYNC_POL_ACTIVE_LOW;
if (common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)
cfg1 |= ISI_CFG1_VSYNC_POL_ACTIVE_LOW;
if (common_flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)
cfg1 |= ISI_CFG1_PIXCLK_POL_ACTIVE_FALLING;
if (isi->pdata->has_emb_sync)
cfg1 |= ISI_CFG1_EMB_SYNC;
if (isi->pdata->full_mode)
cfg1 |= ISI_CFG1_FULL_MODE;
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
isi_writel(isi, ISI_CFG1, cfg1);
return 0;
}
static int __devexit atmel_isi_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct atmel_isi *isi = container_of(soc_host,
struct atmel_isi, soc_host);
free_irq(isi->irq, isi);
soc_camera_host_unregister(soc_host);
vb2_dma_contig_cleanup_ctx(isi->alloc_ctx);
dma_free_coherent(&pdev->dev,
sizeof(struct fbd) * MAX_BUFFER_NUM,
isi->p_fb_descriptors,
isi->fb_descriptors_phys);
iounmap(isi->regs);
clk_unprepare(isi->mck);
clk_put(isi->mck);
clk_unprepare(isi->pclk);
clk_put(isi->pclk);
kfree(isi);
return 0;
}
static int __devinit atmel_isi_probe(struct platform_device *pdev)
{
unsigned int irq;
struct atmel_isi *isi;
struct clk *pclk;
struct resource *regs;
int ret, i;
struct device *dev = &pdev->dev;
struct soc_camera_host *soc_host;
struct isi_platform_data *pdata;
pdata = dev->platform_data;
if (!pdata || !pdata->data_width_flags || !pdata->mck_hz) {
dev_err(&pdev->dev,
"No config available for Atmel ISI\n");
return -EINVAL;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs)
return -ENXIO;
pclk = clk_get(&pdev->dev, "isi_clk");
if (IS_ERR(pclk))
return PTR_ERR(pclk);
ret = clk_prepare(pclk);
if (ret)
goto err_clk_prepare_pclk;
isi = kzalloc(sizeof(struct atmel_isi), GFP_KERNEL);
if (!isi) {
ret = -ENOMEM;
dev_err(&pdev->dev, "Can't allocate interface!\n");
goto err_alloc_isi;
}
isi->pclk = pclk;
isi->pdata = pdata;
isi->active = NULL;
spin_lock_init(&isi->lock);
init_waitqueue_head(&isi->vsync_wq);
INIT_LIST_HEAD(&isi->video_buffer_list);
INIT_LIST_HEAD(&isi->dma_desc_head);
isi->mck = clk_get(dev, "isi_mck");
if (IS_ERR(isi->mck)) {
dev_err(dev, "Failed to get isi_mck\n");
ret = PTR_ERR(isi->mck);
goto err_clk_get;
}
ret = clk_prepare(isi->mck);
if (ret)
goto err_clk_prepare_mck;
ret = clk_set_rate(isi->mck, pdata->mck_hz);
if (ret < 0)
goto err_set_mck_rate;
isi->p_fb_descriptors = dma_alloc_coherent(&pdev->dev,
sizeof(struct fbd) * MAX_BUFFER_NUM,
&isi->fb_descriptors_phys,
GFP_KERNEL);
if (!isi->p_fb_descriptors) {
ret = -ENOMEM;
dev_err(&pdev->dev, "Can't allocate descriptors!\n");
goto err_alloc_descriptors;
}
for (i = 0; i < MAX_BUFFER_NUM; i++) {
isi->dma_desc[i].p_fbd = isi->p_fb_descriptors + i;
isi->dma_desc[i].fbd_phys = isi->fb_descriptors_phys +
i * sizeof(struct fbd);
list_add(&isi->dma_desc[i].list, &isi->dma_desc_head);
}
isi->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(isi->alloc_ctx)) {
ret = PTR_ERR(isi->alloc_ctx);
goto err_alloc_ctx;
}
isi->regs = ioremap(regs->start, resource_size(regs));
if (!isi->regs) {
ret = -ENOMEM;
goto err_ioremap;
}
if (pdata->data_width_flags & ISI_DATAWIDTH_8)
isi->width_flags = 1 << 7;
if (pdata->data_width_flags & ISI_DATAWIDTH_10)
isi->width_flags |= 1 << 9;
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto err_req_irq;
}
ret = request_irq(irq, isi_interrupt, 0, "isi", isi);
if (ret) {
dev_err(&pdev->dev, "Unable to request irq %d\n", irq);
goto err_req_irq;
}
isi->irq = irq;
soc_host = &isi->soc_host;
soc_host->drv_name = "isi-camera";
soc_host->ops = &isi_soc_camera_host_ops;
soc_host->priv = isi;
soc_host->v4l2_dev.dev = &pdev->dev;
soc_host->nr = pdev->id;
ret = soc_camera_host_register(soc_host);
if (ret) {
dev_err(&pdev->dev, "Unable to register soc camera host\n");
goto err_register_soc_camera_host;
}
return 0;
err_register_soc_camera_host:
free_irq(isi->irq, isi);
err_req_irq:
iounmap(isi->regs);
err_ioremap:
vb2_dma_contig_cleanup_ctx(isi->alloc_ctx);
err_alloc_ctx:
dma_free_coherent(&pdev->dev,
sizeof(struct fbd) * MAX_BUFFER_NUM,
isi->p_fb_descriptors,
isi->fb_descriptors_phys);
err_alloc_descriptors:
err_set_mck_rate:
clk_unprepare(isi->mck);
err_clk_prepare_mck:
clk_put(isi->mck);
err_clk_get:
kfree(isi);
err_alloc_isi:
clk_unprepare(pclk);
err_clk_prepare_pclk:
clk_put(pclk);
return ret;
}
static int __init atmel_isi_init_module(void)
{
return platform_driver_probe(&atmel_isi_driver, &atmel_isi_probe);
}
static void __exit atmel_isi_exit(void)
{
platform_driver_unregister(&atmel_isi_driver);
}
