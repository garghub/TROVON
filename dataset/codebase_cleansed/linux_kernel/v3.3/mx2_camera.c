static struct mx2_fmt_cfg *mx27_emma_prp_get_format(
enum v4l2_mbus_pixelcode in_fmt,
u32 out_fmt)
{
int i;
for (i = 1; i < ARRAY_SIZE(mx27_emma_prp_table); i++)
if ((mx27_emma_prp_table[i].in_fmt == in_fmt) &&
(mx27_emma_prp_table[i].out_fmt == out_fmt)) {
return &mx27_emma_prp_table[i];
}
return &mx27_emma_prp_table[0];
}
static void mx2_camera_deactivate(struct mx2_camera_dev *pcdev)
{
unsigned long flags;
clk_disable(pcdev->clk_csi);
writel(0, pcdev->base_csi + CSICR1);
if (mx27_camera_emma(pcdev)) {
writel(0, pcdev->base_emma + PRP_CNTL);
} else if (cpu_is_mx25()) {
spin_lock_irqsave(&pcdev->lock, flags);
pcdev->fb1_active = NULL;
pcdev->fb2_active = NULL;
writel(0, pcdev->base_csi + CSIDMASA_FB1);
writel(0, pcdev->base_csi + CSIDMASA_FB2);
spin_unlock_irqrestore(&pcdev->lock, flags);
}
}
static int mx2_camera_add_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
int ret;
u32 csicr1;
if (pcdev->icd)
return -EBUSY;
ret = clk_enable(pcdev->clk_csi);
if (ret < 0)
return ret;
csicr1 = CSICR1_MCLKEN;
if (mx27_camera_emma(pcdev)) {
csicr1 |= CSICR1_PRP_IF_EN | CSICR1_FCC |
CSICR1_RXFF_LEVEL(0);
} else if (cpu_is_mx27())
csicr1 |= CSICR1_SOF_INTEN | CSICR1_RXFF_LEVEL(2);
pcdev->csicr1 = csicr1;
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
pcdev->icd = icd;
pcdev->frame_count = 0;
dev_info(icd->parent, "Camera driver attached to camera %d\n",
icd->devnum);
return 0;
}
static void mx2_camera_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
BUG_ON(icd != pcdev->icd);
dev_info(icd->parent, "Camera driver detached from camera %d\n",
icd->devnum);
mx2_camera_deactivate(pcdev);
if (pcdev->discard_buffer) {
dma_free_coherent(ici->v4l2_dev.dev, pcdev->discard_size,
pcdev->discard_buffer,
pcdev->discard_buffer_dma);
pcdev->discard_buffer = NULL;
}
pcdev->icd = NULL;
}
static void mx27_camera_dma_enable(struct mx2_camera_dev *pcdev)
{
u32 tmp;
imx_dma_enable(pcdev->dma);
tmp = readl(pcdev->base_csi + CSICR1);
tmp |= CSICR1_RF_OR_INTEN;
writel(tmp, pcdev->base_csi + CSICR1);
}
static irqreturn_t mx27_camera_irq(int irq_csi, void *data)
{
struct mx2_camera_dev *pcdev = data;
u32 status = readl(pcdev->base_csi + CSISR);
if (status & CSISR_SOF_INT && pcdev->active) {
u32 tmp;
tmp = readl(pcdev->base_csi + CSICR1);
writel(tmp | CSICR1_CLR_RXFIFO, pcdev->base_csi + CSICR1);
mx27_camera_dma_enable(pcdev);
}
writel(CSISR_SOF_INT | CSISR_RFF_OR_INT, pcdev->base_csi + CSISR);
return IRQ_HANDLED;
}
static irqreturn_t mx27_camera_irq(int irq_csi, void *data)
{
return IRQ_NONE;
}
static void mx25_camera_frame_done(struct mx2_camera_dev *pcdev, int fb,
int state)
{
struct videobuf_buffer *vb;
struct mx2_buffer *buf;
struct mx2_buffer **fb_active = fb == 1 ? &pcdev->fb1_active :
&pcdev->fb2_active;
u32 fb_reg = fb == 1 ? CSIDMASA_FB1 : CSIDMASA_FB2;
unsigned long flags;
spin_lock_irqsave(&pcdev->lock, flags);
if (*fb_active == NULL)
goto out;
vb = &(*fb_active)->vb;
dev_dbg(pcdev->dev, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
vb->state = state;
do_gettimeofday(&vb->ts);
vb->field_count++;
wake_up(&vb->done);
if (list_empty(&pcdev->capture)) {
buf = NULL;
writel(0, pcdev->base_csi + fb_reg);
} else {
buf = list_entry(pcdev->capture.next, struct mx2_buffer,
vb.queue);
vb = &buf->vb;
list_del(&vb->queue);
vb->state = VIDEOBUF_ACTIVE;
writel(videobuf_to_dma_contig(vb), pcdev->base_csi + fb_reg);
}
*fb_active = buf;
out:
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static irqreturn_t mx25_camera_irq(int irq_csi, void *data)
{
struct mx2_camera_dev *pcdev = data;
u32 status = readl(pcdev->base_csi + CSISR);
if (status & CSISR_DMA_TSF_FB1_INT)
mx25_camera_frame_done(pcdev, 1, VIDEOBUF_DONE);
else if (status & CSISR_DMA_TSF_FB2_INT)
mx25_camera_frame_done(pcdev, 2, VIDEOBUF_DONE);
writel(status, pcdev->base_csi + CSISR);
return IRQ_HANDLED;
}
static int mx2_videobuf_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct soc_camera_device *icd = vq->priv_data;
int bytes_per_line = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
dev_dbg(icd->parent, "count=%d, size=%d\n", *count, *size);
if (bytes_per_line < 0)
return bytes_per_line;
*size = bytes_per_line * icd->user_height;
if (0 == *count)
*count = 32;
if (*size * *count > MAX_VIDEO_MEM * 1024 * 1024)
*count = (MAX_VIDEO_MEM * 1024 * 1024) / *size;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct mx2_buffer *buf)
{
struct soc_camera_device *icd = vq->priv_data;
struct videobuf_buffer *vb = &buf->vb;
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
videobuf_waiton(vq, vb, 0, 0);
videobuf_dma_contig_free(vq, vb);
dev_dbg(icd->parent, "%s freed\n", __func__);
vb->state = VIDEOBUF_NEEDS_INIT;
}
static int mx2_videobuf_prepare(struct videobuf_queue *vq,
struct videobuf_buffer *vb, enum v4l2_field field)
{
struct soc_camera_device *icd = vq->priv_data;
struct mx2_buffer *buf = container_of(vb, struct mx2_buffer, vb);
int bytes_per_line = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
int ret = 0;
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
if (bytes_per_line < 0)
return bytes_per_line;
#ifdef DEBUG
memset((void *)vb->baddr, 0xaa, vb->bsize);
#endif
if (buf->code != icd->current_fmt->code ||
vb->width != icd->user_width ||
vb->height != icd->user_height ||
vb->field != field) {
buf->code = icd->current_fmt->code;
vb->width = icd->user_width;
vb->height = icd->user_height;
vb->field = field;
vb->state = VIDEOBUF_NEEDS_INIT;
}
vb->size = bytes_per_line * vb->height;
if (vb->baddr && vb->bsize < vb->size) {
ret = -EINVAL;
goto out;
}
if (vb->state == VIDEOBUF_NEEDS_INIT) {
ret = videobuf_iolock(vq, vb, NULL);
if (ret)
goto fail;
vb->state = VIDEOBUF_PREPARED;
}
return 0;
fail:
free_buffer(vq, buf);
out:
return ret;
}
static void mx2_videobuf_queue(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct soc_camera_device *icd = vq->priv_data;
struct soc_camera_host *ici =
to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_buffer *buf = container_of(vb, struct mx2_buffer, vb);
unsigned long flags;
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
spin_lock_irqsave(&pcdev->lock, flags);
vb->state = VIDEOBUF_QUEUED;
list_add_tail(&vb->queue, &pcdev->capture);
if (mx27_camera_emma(pcdev)) {
goto out;
#ifdef CONFIG_MACH_MX27
} else if (cpu_is_mx27()) {
int ret;
if (pcdev->active == NULL) {
ret = imx_dma_setup_single(pcdev->dma,
videobuf_to_dma_contig(vb), vb->size,
(u32)pcdev->base_dma + 0x10,
DMA_MODE_READ);
if (ret) {
vb->state = VIDEOBUF_ERROR;
wake_up(&vb->done);
goto out;
}
vb->state = VIDEOBUF_ACTIVE;
pcdev->active = buf;
}
#endif
} else {
u32 csicr3, dma_inten = 0;
if (pcdev->fb1_active == NULL) {
writel(videobuf_to_dma_contig(vb),
pcdev->base_csi + CSIDMASA_FB1);
pcdev->fb1_active = buf;
dma_inten = CSICR1_FB1_DMA_INTEN;
} else if (pcdev->fb2_active == NULL) {
writel(videobuf_to_dma_contig(vb),
pcdev->base_csi + CSIDMASA_FB2);
pcdev->fb2_active = buf;
dma_inten = CSICR1_FB2_DMA_INTEN;
}
if (dma_inten) {
list_del(&vb->queue);
vb->state = VIDEOBUF_ACTIVE;
csicr3 = readl(pcdev->base_csi + CSICR3);
writel(csicr3 | CSICR3_DMA_REFLASH_RFF,
pcdev->base_csi + CSICR3);
writel(dma_inten, pcdev->base_csi + CSISR);
pcdev->csicr1 |= dma_inten;
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
csicr3 |= CSICR3_DMA_REQ_EN_RFF | CSICR3_RXFF_LEVEL(1);
writel(csicr3, pcdev->base_csi + CSICR3);
}
}
out:
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static void mx2_videobuf_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct soc_camera_device *icd = vq->priv_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_buffer *buf = container_of(vb, struct mx2_buffer, vb);
unsigned long flags;
#ifdef DEBUG
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
switch (vb->state) {
case VIDEOBUF_ACTIVE:
dev_info(icd->parent, "%s (active)\n", __func__);
break;
case VIDEOBUF_QUEUED:
dev_info(icd->parent, "%s (queued)\n", __func__);
break;
case VIDEOBUF_PREPARED:
dev_info(icd->parent, "%s (prepared)\n", __func__);
break;
default:
dev_info(icd->parent, "%s (unknown) %d\n", __func__,
vb->state);
break;
}
#endif
spin_lock_irqsave(&pcdev->lock, flags);
if (vb->state == VIDEOBUF_QUEUED) {
list_del(&vb->queue);
vb->state = VIDEOBUF_ERROR;
} else if (cpu_is_mx25() && vb->state == VIDEOBUF_ACTIVE) {
if (pcdev->fb1_active == buf) {
pcdev->csicr1 &= ~CSICR1_FB1_DMA_INTEN;
writel(0, pcdev->base_csi + CSIDMASA_FB1);
pcdev->fb1_active = NULL;
} else if (pcdev->fb2_active == buf) {
pcdev->csicr1 &= ~CSICR1_FB2_DMA_INTEN;
writel(0, pcdev->base_csi + CSIDMASA_FB2);
pcdev->fb2_active = NULL;
}
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
vb->state = VIDEOBUF_ERROR;
}
spin_unlock_irqrestore(&pcdev->lock, flags);
free_buffer(vq, buf);
}
static void mx2_camera_init_videobuf(struct videobuf_queue *q,
struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
videobuf_queue_dma_contig_init(q, &mx2_videobuf_ops, pcdev->dev,
&pcdev->lock, V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_NONE, sizeof(struct mx2_buffer),
icd, &icd->video_lock);
}
static int mx27_camera_emma_prp_reset(struct mx2_camera_dev *pcdev)
{
u32 cntl;
int count = 0;
cntl = readl(pcdev->base_emma + PRP_CNTL);
writel(PRP_CNTL_SWRST, pcdev->base_emma + PRP_CNTL);
while (count++ < 100) {
if (!(readl(pcdev->base_emma + PRP_CNTL) & PRP_CNTL_SWRST))
return 0;
barrier();
udelay(1);
}
return -ETIMEDOUT;
}
static void mx27_camera_emma_buf_init(struct soc_camera_device *icd,
int bytesperline)
{
struct soc_camera_host *ici =
to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
u32 imgsize = pcdev->icd->user_height * pcdev->icd->user_width;
if (prp->cfg.channel == 1) {
writel(pcdev->discard_buffer_dma,
pcdev->base_emma + PRP_DEST_RGB1_PTR);
writel(pcdev->discard_buffer_dma,
pcdev->base_emma + PRP_DEST_RGB2_PTR);
writel(PRP_CNTL_CH1EN |
PRP_CNTL_CSIEN |
prp->cfg.in_fmt |
prp->cfg.out_fmt |
PRP_CNTL_CH1_LEN |
PRP_CNTL_CH1BYP |
PRP_CNTL_CH1_TSKIP(0) |
PRP_CNTL_IN_TSKIP(0),
pcdev->base_emma + PRP_CNTL);
writel((icd->user_width << 16) | icd->user_height,
pcdev->base_emma + PRP_SRC_FRAME_SIZE);
writel((icd->user_width << 16) | icd->user_height,
pcdev->base_emma + PRP_CH1_OUT_IMAGE_SIZE);
writel(bytesperline,
pcdev->base_emma + PRP_DEST_CH1_LINE_STRIDE);
writel(prp->cfg.src_pixel,
pcdev->base_emma + PRP_SRC_PIXEL_FORMAT_CNTL);
writel(prp->cfg.ch1_pixel,
pcdev->base_emma + PRP_CH1_PIXEL_FORMAT_CNTL);
} else {
writel(pcdev->discard_buffer_dma,
pcdev->base_emma + PRP_DEST_Y_PTR);
writel(pcdev->discard_buffer_dma,
pcdev->base_emma + PRP_SOURCE_Y_PTR);
if (prp->cfg.out_fmt == PRP_CNTL_CH2_OUT_YUV420) {
writel(pcdev->discard_buffer_dma + imgsize,
pcdev->base_emma + PRP_DEST_CB_PTR);
writel(pcdev->discard_buffer_dma + ((5 * imgsize) / 4),
pcdev->base_emma + PRP_DEST_CR_PTR);
writel(pcdev->discard_buffer_dma + imgsize,
pcdev->base_emma + PRP_SOURCE_CB_PTR);
writel(pcdev->discard_buffer_dma + ((5 * imgsize) / 4),
pcdev->base_emma + PRP_SOURCE_CR_PTR);
}
writel(PRP_CNTL_CH2EN |
PRP_CNTL_CSIEN |
prp->cfg.in_fmt |
prp->cfg.out_fmt |
PRP_CNTL_CH2_LEN |
PRP_CNTL_CH2_TSKIP(0) |
PRP_CNTL_IN_TSKIP(0),
pcdev->base_emma + PRP_CNTL);
writel((icd->user_width << 16) | icd->user_height,
pcdev->base_emma + PRP_SRC_FRAME_SIZE);
writel((icd->user_width << 16) | icd->user_height,
pcdev->base_emma + PRP_CH2_OUT_IMAGE_SIZE);
writel(prp->cfg.src_pixel,
pcdev->base_emma + PRP_SRC_PIXEL_FORMAT_CNTL);
}
writel(prp->cfg.irq_flags, pcdev->base_emma + PRP_INTR_CNTL);
}
static int mx2_camera_set_bus_param(struct soc_camera_device *icd)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
unsigned long common_flags;
int ret;
int bytesperline;
u32 csicr1 = pcdev->csicr1;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg, MX2_BUS_FLAGS);
if (!common_flags) {
dev_warn(icd->parent,
"Flags incompatible: camera 0x%x, host 0x%x\n",
cfg.flags, MX2_BUS_FLAGS);
return -EINVAL;
}
} else if (ret != -ENOIOCTLCMD) {
return ret;
} else {
common_flags = MX2_BUS_FLAGS;
}
if ((common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)) {
if (pcdev->platform_flags & MX2_CAMERA_HSYNC_HIGH)
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_LOW;
else
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_HIGH;
}
if ((common_flags & V4L2_MBUS_PCLK_SAMPLE_RISING) &&
(common_flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)) {
if (pcdev->platform_flags & MX2_CAMERA_PCLK_SAMPLE_RISING)
common_flags &= ~V4L2_MBUS_PCLK_SAMPLE_FALLING;
else
common_flags &= ~V4L2_MBUS_PCLK_SAMPLE_RISING;
}
cfg.flags = common_flags;
ret = v4l2_subdev_call(sd, video, s_mbus_config, &cfg);
if (ret < 0 && ret != -ENOIOCTLCMD) {
dev_dbg(icd->parent, "camera s_mbus_config(0x%lx) returned %d\n",
common_flags, ret);
return ret;
}
if (common_flags & V4L2_MBUS_PCLK_SAMPLE_RISING)
csicr1 |= CSICR1_REDGE;
if (common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH)
csicr1 |= CSICR1_SOF_POL;
if (common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH)
csicr1 |= CSICR1_HSYNC_POL;
if (pcdev->platform_flags & MX2_CAMERA_SWAP16)
csicr1 |= CSICR1_SWAP16_EN;
if (pcdev->platform_flags & MX2_CAMERA_EXT_VSYNC)
csicr1 |= CSICR1_EXT_VSYNC;
if (pcdev->platform_flags & MX2_CAMERA_CCIR)
csicr1 |= CSICR1_CCIR_EN;
if (pcdev->platform_flags & MX2_CAMERA_CCIR_INTERLACE)
csicr1 |= CSICR1_CCIR_MODE;
if (pcdev->platform_flags & MX2_CAMERA_GATED_CLOCK)
csicr1 |= CSICR1_GCLK_MODE;
if (pcdev->platform_flags & MX2_CAMERA_INV_DATA)
csicr1 |= CSICR1_INV_DATA;
if (pcdev->platform_flags & MX2_CAMERA_PACK_DIR_MSB)
csicr1 |= CSICR1_PACK_DIR;
pcdev->csicr1 = csicr1;
bytesperline = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
if (bytesperline < 0)
return bytesperline;
if (mx27_camera_emma(pcdev)) {
ret = mx27_camera_emma_prp_reset(pcdev);
if (ret)
return ret;
if (pcdev->discard_buffer)
dma_free_coherent(ici->v4l2_dev.dev,
pcdev->discard_size, pcdev->discard_buffer,
pcdev->discard_buffer_dma);
pcdev->discard_size = icd->user_height * bytesperline;
pcdev->discard_buffer = dma_alloc_coherent(ici->v4l2_dev.dev,
pcdev->discard_size, &pcdev->discard_buffer_dma,
GFP_KERNEL);
if (!pcdev->discard_buffer)
return -ENOMEM;
mx27_camera_emma_buf_init(icd, bytesperline);
} else if (cpu_is_mx25()) {
writel((bytesperline * icd->user_height) >> 2,
pcdev->base_csi + CSIRXCNT);
writel((bytesperline << 16) | icd->user_height,
pcdev->base_csi + CSIIMAG_PARA);
}
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
return 0;
}
static int mx2_camera_set_crop(struct soc_camera_device *icd,
struct v4l2_crop *a)
{
struct v4l2_rect *rect = &a->c;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_framefmt mf;
int ret;
soc_camera_limit_side(&rect->left, &rect->width, 0, 2, 4096);
soc_camera_limit_side(&rect->top, &rect->height, 0, 2, 4096);
ret = v4l2_subdev_call(sd, video, s_crop, a);
if (ret < 0)
return ret;
ret = v4l2_subdev_call(sd, video, g_mbus_fmt, &mf);
if (ret < 0)
return ret;
dev_dbg(icd->parent, "Sensor cropped %dx%d\n",
mf.width, mf.height);
icd->user_width = mf.width;
icd->user_height = mf.height;
return ret;
}
static int mx2_camera_get_formats(struct soc_camera_device *icd,
unsigned int idx,
struct soc_camera_format_xlate *xlate)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_mbus_pixelfmt *fmt;
struct device *dev = icd->parent;
enum v4l2_mbus_pixelcode code;
int ret, formats = 0;
ret = v4l2_subdev_call(sd, video, enum_mbus_fmt, idx, &code);
if (ret < 0)
return 0;
fmt = soc_mbus_get_fmtdesc(code);
if (!fmt) {
dev_err(dev, "Invalid format code #%u: %d\n", idx, code);
return 0;
}
if (code == V4L2_MBUS_FMT_YUYV8_2X8) {
formats++;
if (xlate) {
xlate->host_fmt =
soc_mbus_get_fmtdesc(V4L2_MBUS_FMT_YUYV8_1_5X8);
xlate->code = code;
dev_dbg(dev, "Providing host format %s for sensor code %d\n",
xlate->host_fmt->name, code);
xlate++;
}
}
formats++;
if (xlate) {
xlate->host_fmt = fmt;
xlate->code = code;
xlate++;
}
return formats;
}
static int mx2_camera_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
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
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
ret = v4l2_subdev_call(sd, video, s_mbus_fmt, &mf);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
if (mf.code != xlate->code)
return -EINVAL;
pix->width = mf.width;
pix->height = mf.height;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
icd->current_fmt = xlate;
if (mx27_camera_emma(pcdev))
pcdev->emma_prp = mx27_emma_prp_get_format(xlate->code,
xlate->host_fmt->fourcc);
return 0;
}
static int mx2_camera_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
__u32 pixfmt = pix->pixelformat;
unsigned int width_limit;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (pixfmt && !xlate) {
dev_warn(icd->parent, "Format %x not found\n", pixfmt);
return -EINVAL;
}
if (cpu_is_mx25()) {
if (xlate->host_fmt->bits_per_sample <= 8)
width_limit = 0xffff * 4;
else
width_limit = 0xffff * 2;
if (pix->width > width_limit)
pix->width = width_limit;
if (pix->height > 0xffff)
pix->height = 0xffff;
pix->bytesperline = soc_mbus_bytes_per_line(pix->width,
xlate->host_fmt);
if (pix->bytesperline < 0)
return pix->bytesperline;
pix->sizeimage = pix->height * pix->bytesperline;
if (pix->sizeimage > 4 * 0x3ffff) {
unsigned int new_height = int_sqrt(4 * 0x3ffff *
pix->height / pix->bytesperline);
pix->width = new_height * pix->width / pix->height;
pix->height = new_height;
pix->bytesperline = soc_mbus_bytes_per_line(pix->width,
xlate->host_fmt);
BUG_ON(pix->bytesperline < 0);
}
}
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
ret = v4l2_subdev_call(sd, video, try_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (mf.field == V4L2_FIELD_ANY)
mf.field = V4L2_FIELD_NONE;
if (mf.field != V4L2_FIELD_NONE && !V4L2_FIELD_HAS_BOTH(mf.field)) {
dev_err(icd->parent, "Field type %d unsupported.\n",
mf.field);
return -EINVAL;
}
pix->width = mf.width;
pix->height = mf.height;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
return 0;
}
static int mx2_camera_querycap(struct soc_camera_host *ici,
struct v4l2_capability *cap)
{
strlcpy(cap->card, MX2_CAM_DRIVER_DESCRIPTION, sizeof(cap->card));
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
return 0;
}
static int mx2_camera_reqbufs(struct soc_camera_device *icd,
struct v4l2_requestbuffers *p)
{
int i;
for (i = 0; i < p->count; i++) {
struct mx2_buffer *buf = container_of(icd->vb_vidq.bufs[i],
struct mx2_buffer, vb);
INIT_LIST_HEAD(&buf->vb.queue);
}
return 0;
}
static void mx27_camera_frame_done(struct mx2_camera_dev *pcdev, int state)
{
struct videobuf_buffer *vb;
struct mx2_buffer *buf;
unsigned long flags;
int ret;
spin_lock_irqsave(&pcdev->lock, flags);
if (!pcdev->active) {
dev_err(pcdev->dev, "%s called with no active buffer!\n",
__func__);
goto out;
}
vb = &pcdev->active->vb;
buf = container_of(vb, struct mx2_buffer, vb);
WARN_ON(list_empty(&vb->queue));
dev_dbg(pcdev->dev, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
list_del_init(&vb->queue);
vb->state = state;
do_gettimeofday(&vb->ts);
vb->field_count++;
wake_up(&vb->done);
if (list_empty(&pcdev->capture)) {
pcdev->active = NULL;
goto out;
}
pcdev->active = list_entry(pcdev->capture.next,
struct mx2_buffer, vb.queue);
vb = &pcdev->active->vb;
vb->state = VIDEOBUF_ACTIVE;
ret = imx_dma_setup_single(pcdev->dma, videobuf_to_dma_contig(vb),
vb->size, (u32)pcdev->base_dma + 0x10, DMA_MODE_READ);
if (ret) {
vb->state = VIDEOBUF_ERROR;
pcdev->active = NULL;
wake_up(&vb->done);
}
out:
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static void mx27_camera_dma_err_callback(int channel, void *data, int err)
{
struct mx2_camera_dev *pcdev = data;
mx27_camera_frame_done(pcdev, VIDEOBUF_ERROR);
}
static void mx27_camera_dma_callback(int channel, void *data)
{
struct mx2_camera_dev *pcdev = data;
mx27_camera_frame_done(pcdev, VIDEOBUF_DONE);
}
static int __devinit mx27_camera_dma_init(struct platform_device *pdev,
struct mx2_camera_dev *pcdev)
{
int err;
pcdev->dma = imx_dma_request_by_prio("CSI RX DMA", DMA_PRIO_HIGH);
if (pcdev->dma < 0) {
dev_err(&pdev->dev, "%s failed to request DMA channel\n",
__func__);
return pcdev->dma;
}
err = imx_dma_setup_handlers(pcdev->dma, mx27_camera_dma_callback,
mx27_camera_dma_err_callback, pcdev);
if (err) {
dev_err(&pdev->dev, "%s failed to set DMA callback\n",
__func__);
goto err_out;
}
err = imx_dma_config_channel(pcdev->dma,
IMX_DMA_MEMSIZE_32 | IMX_DMA_TYPE_FIFO,
IMX_DMA_MEMSIZE_32 | IMX_DMA_TYPE_LINEAR,
DMA_REQ_CSI_RX, 1);
if (err) {
dev_err(&pdev->dev, "%s failed to config DMA channel\n",
__func__);
goto err_out;
}
imx_dma_config_burstlen(pcdev->dma, 64);
return 0;
err_out:
imx_dma_free(pcdev->dma);
return err;
}
static unsigned int mx2_camera_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
return videobuf_poll_stream(file, &icd->vb_vidq, pt);
}
static void mx27_camera_frame_done_emma(struct mx2_camera_dev *pcdev,
int bufnum, int state)
{
u32 imgsize = pcdev->icd->user_height * pcdev->icd->user_width;
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
struct mx2_buffer *buf;
struct videobuf_buffer *vb;
unsigned long phys;
if (!list_empty(&pcdev->active_bufs)) {
buf = list_entry(pcdev->active_bufs.next,
struct mx2_buffer, vb.queue);
BUG_ON(buf->bufnum != bufnum);
vb = &buf->vb;
#ifdef DEBUG
phys = videobuf_to_dma_contig(vb);
if (prp->cfg.channel == 1) {
if (readl(pcdev->base_emma + PRP_DEST_RGB1_PTR +
4 * bufnum) != phys) {
dev_err(pcdev->dev, "%p != %p\n", phys,
readl(pcdev->base_emma +
PRP_DEST_RGB1_PTR +
4 * bufnum));
}
} else {
if (readl(pcdev->base_emma + PRP_DEST_Y_PTR -
0x14 * bufnum) != phys) {
dev_err(pcdev->dev, "%p != %p\n", phys,
readl(pcdev->base_emma +
PRP_DEST_Y_PTR -
0x14 * bufnum));
}
}
#endif
dev_dbg(pcdev->dev, "%s (vb=0x%p) 0x%08lx %d\n", __func__, vb,
vb->baddr, vb->bsize);
list_del(&vb->queue);
vb->state = state;
do_gettimeofday(&vb->ts);
vb->field_count = pcdev->frame_count * 2;
pcdev->frame_count++;
wake_up(&vb->done);
}
if (list_empty(&pcdev->capture)) {
if (prp->cfg.channel == 1) {
writel(pcdev->discard_buffer_dma, pcdev->base_emma +
PRP_DEST_RGB1_PTR + 4 * bufnum);
} else {
writel(pcdev->discard_buffer_dma, pcdev->base_emma +
PRP_DEST_Y_PTR -
0x14 * bufnum);
if (prp->out_fmt == V4L2_PIX_FMT_YUV420) {
writel(pcdev->discard_buffer_dma + imgsize,
pcdev->base_emma + PRP_DEST_CB_PTR -
0x14 * bufnum);
writel(pcdev->discard_buffer_dma +
((5 * imgsize) / 4), pcdev->base_emma +
PRP_DEST_CR_PTR - 0x14 * bufnum);
}
}
return;
}
buf = list_entry(pcdev->capture.next,
struct mx2_buffer, vb.queue);
buf->bufnum = !bufnum;
list_move_tail(pcdev->capture.next, &pcdev->active_bufs);
vb = &buf->vb;
vb->state = VIDEOBUF_ACTIVE;
phys = videobuf_to_dma_contig(vb);
if (prp->cfg.channel == 1) {
writel(phys, pcdev->base_emma + PRP_DEST_RGB1_PTR + 4 * bufnum);
} else {
writel(phys, pcdev->base_emma +
PRP_DEST_Y_PTR - 0x14 * bufnum);
if (prp->cfg.out_fmt == PRP_CNTL_CH2_OUT_YUV420) {
writel(phys + imgsize, pcdev->base_emma +
PRP_DEST_CB_PTR - 0x14 * bufnum);
writel(phys + ((5 * imgsize) / 4), pcdev->base_emma +
PRP_DEST_CR_PTR - 0x14 * bufnum);
}
}
}
static irqreturn_t mx27_camera_emma_irq(int irq_emma, void *data)
{
struct mx2_camera_dev *pcdev = data;
unsigned int status = readl(pcdev->base_emma + PRP_INTRSTATUS);
struct mx2_buffer *buf;
if (status & (1 << 7)) {
u32 cntl;
cntl = readl(pcdev->base_emma + PRP_CNTL);
writel(cntl & ~(PRP_CNTL_CH1EN | PRP_CNTL_CH2EN),
pcdev->base_emma + PRP_CNTL);
writel(cntl, pcdev->base_emma + PRP_CNTL);
}
if ((((status & (3 << 5)) == (3 << 5)) ||
((status & (3 << 3)) == (3 << 3)))
&& !list_empty(&pcdev->active_bufs)) {
buf = list_entry(pcdev->active_bufs.next,
struct mx2_buffer, vb.queue);
mx27_camera_frame_done_emma(pcdev, buf->bufnum, VIDEOBUF_DONE);
status &= ~(1 << (6 - buf->bufnum));
}
if ((status & (1 << 6)) || (status & (1 << 4)))
mx27_camera_frame_done_emma(pcdev, 0, VIDEOBUF_DONE);
if ((status & (1 << 5)) || (status & (1 << 3)))
mx27_camera_frame_done_emma(pcdev, 1, VIDEOBUF_DONE);
writel(status, pcdev->base_emma + PRP_INTRSTATUS);
return IRQ_HANDLED;
}
static int __devinit mx27_camera_emma_init(struct mx2_camera_dev *pcdev)
{
struct resource *res_emma = pcdev->res_emma;
int err = 0;
if (!request_mem_region(res_emma->start, resource_size(res_emma),
MX2_CAM_DRV_NAME)) {
err = -EBUSY;
goto out;
}
pcdev->base_emma = ioremap(res_emma->start, resource_size(res_emma));
if (!pcdev->base_emma) {
err = -ENOMEM;
goto exit_release;
}
err = request_irq(pcdev->irq_emma, mx27_camera_emma_irq, 0,
MX2_CAM_DRV_NAME, pcdev);
if (err) {
dev_err(pcdev->dev, "Camera EMMA interrupt register failed \n");
goto exit_iounmap;
}
pcdev->clk_emma = clk_get(NULL, "emma");
if (IS_ERR(pcdev->clk_emma)) {
err = PTR_ERR(pcdev->clk_emma);
goto exit_free_irq;
}
clk_enable(pcdev->clk_emma);
err = mx27_camera_emma_prp_reset(pcdev);
if (err)
goto exit_clk_emma_put;
return err;
exit_clk_emma_put:
clk_disable(pcdev->clk_emma);
clk_put(pcdev->clk_emma);
exit_free_irq:
free_irq(pcdev->irq_emma, pcdev);
exit_iounmap:
iounmap(pcdev->base_emma);
exit_release:
release_mem_region(res_emma->start, resource_size(res_emma));
out:
return err;
}
static int __devinit mx2_camera_probe(struct platform_device *pdev)
{
struct mx2_camera_dev *pcdev;
struct resource *res_csi, *res_emma;
void __iomem *base_csi;
int irq_csi, irq_emma;
irq_handler_t mx2_cam_irq_handler = cpu_is_mx25() ? mx25_camera_irq
: mx27_camera_irq;
int err = 0;
dev_dbg(&pdev->dev, "initialising\n");
res_csi = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq_csi = platform_get_irq(pdev, 0);
if (res_csi == NULL || irq_csi < 0) {
dev_err(&pdev->dev, "Missing platform resources data\n");
err = -ENODEV;
goto exit;
}
pcdev = kzalloc(sizeof(*pcdev), GFP_KERNEL);
if (!pcdev) {
dev_err(&pdev->dev, "Could not allocate pcdev\n");
err = -ENOMEM;
goto exit;
}
pcdev->clk_csi = clk_get(&pdev->dev, NULL);
if (IS_ERR(pcdev->clk_csi)) {
err = PTR_ERR(pcdev->clk_csi);
goto exit_kfree;
}
dev_dbg(&pdev->dev, "Camera clock frequency: %ld\n",
clk_get_rate(pcdev->clk_csi));
#ifdef CONFIG_MACH_MX27
if (cpu_is_mx27()) {
err = mx27_camera_dma_init(pdev, pcdev);
if (err)
goto exit_clk_put;
}
#endif
pcdev->res_csi = res_csi;
pcdev->pdata = pdev->dev.platform_data;
if (pcdev->pdata) {
long rate;
pcdev->platform_flags = pcdev->pdata->flags;
rate = clk_round_rate(pcdev->clk_csi, pcdev->pdata->clk * 2);
if (rate <= 0) {
err = -ENODEV;
goto exit_dma_free;
}
err = clk_set_rate(pcdev->clk_csi, rate);
if (err < 0)
goto exit_dma_free;
}
INIT_LIST_HEAD(&pcdev->capture);
INIT_LIST_HEAD(&pcdev->active_bufs);
spin_lock_init(&pcdev->lock);
if (!request_mem_region(res_csi->start, resource_size(res_csi),
MX2_CAM_DRV_NAME)) {
err = -EBUSY;
goto exit_dma_free;
}
base_csi = ioremap(res_csi->start, resource_size(res_csi));
if (!base_csi) {
err = -ENOMEM;
goto exit_release;
}
pcdev->irq_csi = irq_csi;
pcdev->base_csi = base_csi;
pcdev->base_dma = res_csi->start;
pcdev->dev = &pdev->dev;
err = request_irq(pcdev->irq_csi, mx2_cam_irq_handler, 0,
MX2_CAM_DRV_NAME, pcdev);
if (err) {
dev_err(pcdev->dev, "Camera interrupt register failed \n");
goto exit_iounmap;
}
if (cpu_is_mx27()) {
res_emma = platform_get_resource(pdev, IORESOURCE_MEM, 1);
irq_emma = platform_get_irq(pdev, 1);
if (res_emma && irq_emma >= 0) {
dev_info(&pdev->dev, "Using EMMA\n");
pcdev->use_emma = 1;
pcdev->res_emma = res_emma;
pcdev->irq_emma = irq_emma;
if (mx27_camera_emma_init(pcdev))
goto exit_free_irq;
}
}
pcdev->soc_host.drv_name = MX2_CAM_DRV_NAME,
pcdev->soc_host.ops = &mx2_soc_camera_host_ops,
pcdev->soc_host.priv = pcdev;
pcdev->soc_host.v4l2_dev.dev = &pdev->dev;
pcdev->soc_host.nr = pdev->id;
err = soc_camera_host_register(&pcdev->soc_host);
if (err)
goto exit_free_emma;
dev_info(&pdev->dev, "MX2 Camera (CSI) driver probed, clock frequency: %ld\n",
clk_get_rate(pcdev->clk_csi));
return 0;
exit_free_emma:
if (mx27_camera_emma(pcdev)) {
free_irq(pcdev->irq_emma, pcdev);
clk_disable(pcdev->clk_emma);
clk_put(pcdev->clk_emma);
iounmap(pcdev->base_emma);
release_mem_region(res_emma->start, resource_size(res_emma));
}
exit_free_irq:
free_irq(pcdev->irq_csi, pcdev);
exit_iounmap:
iounmap(base_csi);
exit_release:
release_mem_region(res_csi->start, resource_size(res_csi));
exit_dma_free:
#ifdef CONFIG_MACH_MX27
if (cpu_is_mx27())
imx_dma_free(pcdev->dma);
exit_clk_put:
clk_put(pcdev->clk_csi);
#endif
exit_kfree:
kfree(pcdev);
exit:
return err;
}
static int __devexit mx2_camera_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct mx2_camera_dev *pcdev = container_of(soc_host,
struct mx2_camera_dev, soc_host);
struct resource *res;
clk_put(pcdev->clk_csi);
#ifdef CONFIG_MACH_MX27
if (cpu_is_mx27())
imx_dma_free(pcdev->dma);
#endif
free_irq(pcdev->irq_csi, pcdev);
if (mx27_camera_emma(pcdev))
free_irq(pcdev->irq_emma, pcdev);
soc_camera_host_unregister(&pcdev->soc_host);
iounmap(pcdev->base_csi);
if (mx27_camera_emma(pcdev)) {
clk_disable(pcdev->clk_emma);
clk_put(pcdev->clk_emma);
iounmap(pcdev->base_emma);
res = pcdev->res_emma;
release_mem_region(res->start, resource_size(res));
}
res = pcdev->res_csi;
release_mem_region(res->start, resource_size(res));
kfree(pcdev);
dev_info(&pdev->dev, "MX2 Camera driver unloaded\n");
return 0;
}
static int __init mx2_camera_init(void)
{
return platform_driver_probe(&mx2_camera_driver, &mx2_camera_probe);
}
static void __exit mx2_camera_exit(void)
{
return platform_driver_unregister(&mx2_camera_driver);
}
