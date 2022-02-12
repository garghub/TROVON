static inline int is_imx25_camera(struct mx2_camera_dev *pcdev)
{
return pcdev->devtype == IMX25_CAMERA;
}
static inline int is_imx27_camera(struct mx2_camera_dev *pcdev)
{
return pcdev->devtype == IMX27_CAMERA;
}
static struct mx2_buffer *mx2_ibuf_to_buf(struct mx2_buf_internal *int_buf)
{
return container_of(int_buf, struct mx2_buffer, internal);
}
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
static void mx27_update_emma_buf(struct mx2_camera_dev *pcdev,
unsigned long phys, int bufnum)
{
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
if (prp->cfg.channel == 1) {
writel(phys, pcdev->base_emma +
PRP_DEST_RGB1_PTR + 4 * bufnum);
} else {
writel(phys, pcdev->base_emma +
PRP_DEST_Y_PTR - 0x14 * bufnum);
if (prp->out_fmt == V4L2_PIX_FMT_YUV420) {
u32 imgsize = pcdev->icd->user_height *
pcdev->icd->user_width;
writel(phys + imgsize, pcdev->base_emma +
PRP_DEST_CB_PTR - 0x14 * bufnum);
writel(phys + ((5 * imgsize) / 4), pcdev->base_emma +
PRP_DEST_CR_PTR - 0x14 * bufnum);
}
}
}
static void mx2_camera_deactivate(struct mx2_camera_dev *pcdev)
{
unsigned long flags;
clk_disable_unprepare(pcdev->clk_csi_ahb);
clk_disable_unprepare(pcdev->clk_csi_per);
writel(0, pcdev->base_csi + CSICR1);
if (is_imx27_camera(pcdev)) {
writel(0, pcdev->base_emma + PRP_CNTL);
} else if (is_imx25_camera(pcdev)) {
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
ret = clk_prepare_enable(pcdev->clk_csi_ahb);
if (ret < 0)
return ret;
ret = clk_prepare_enable(pcdev->clk_csi_per);
if (ret < 0)
goto exit_csi_ahb;
csicr1 = CSICR1_MCLKEN;
if (is_imx27_camera(pcdev))
csicr1 |= CSICR1_PRP_IF_EN | CSICR1_FCC |
CSICR1_RXFF_LEVEL(0);
pcdev->csicr1 = csicr1;
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
pcdev->icd = icd;
pcdev->frame_count = 0;
dev_info(icd->parent, "Camera driver attached to camera %d\n",
icd->devnum);
return 0;
exit_csi_ahb:
clk_disable_unprepare(pcdev->clk_csi_ahb);
return ret;
}
static void mx2_camera_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
BUG_ON(icd != pcdev->icd);
dev_info(icd->parent, "Camera driver detached from camera %d\n",
icd->devnum);
mx2_camera_deactivate(pcdev);
pcdev->icd = NULL;
}
static void mx25_camera_frame_done(struct mx2_camera_dev *pcdev, int fb,
int state)
{
struct vb2_buffer *vb;
struct mx2_buffer *buf;
struct mx2_buffer **fb_active = fb == 1 ? &pcdev->fb1_active :
&pcdev->fb2_active;
u32 fb_reg = fb == 1 ? CSIDMASA_FB1 : CSIDMASA_FB2;
unsigned long flags;
spin_lock_irqsave(&pcdev->lock, flags);
if (*fb_active == NULL)
goto out;
vb = &(*fb_active)->vb;
dev_dbg(pcdev->dev, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
do_gettimeofday(&vb->v4l2_buf.timestamp);
vb->v4l2_buf.sequence++;
vb2_buffer_done(vb, VB2_BUF_STATE_DONE);
if (list_empty(&pcdev->capture)) {
buf = NULL;
writel(0, pcdev->base_csi + fb_reg);
} else {
buf = list_first_entry(&pcdev->capture, struct mx2_buffer,
internal.queue);
vb = &buf->vb;
list_del(&buf->internal.queue);
buf->state = MX2_STATE_ACTIVE;
writel(vb2_dma_contig_plane_dma_addr(vb, 0),
pcdev->base_csi + fb_reg);
}
*fb_active = buf;
out:
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static irqreturn_t mx25_camera_irq(int irq_csi, void *data)
{
struct mx2_camera_dev *pcdev = data;
u32 status = readl(pcdev->base_csi + pcdev->reg_csisr);
if (status & CSISR_DMA_TSF_FB1_INT)
mx25_camera_frame_done(pcdev, 1, MX2_STATE_DONE);
else if (status & CSISR_DMA_TSF_FB2_INT)
mx25_camera_frame_done(pcdev, 2, MX2_STATE_DONE);
writel(status, pcdev->base_csi + pcdev->reg_csisr);
return IRQ_HANDLED;
}
static int mx2_videobuf_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *count, unsigned int *num_planes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
dev_dbg(icd->parent, "count=%d, size=%d\n", *count, sizes[0]);
if (fmt != NULL)
return -ENOTTY;
alloc_ctxs[0] = pcdev->alloc_ctx;
sizes[0] = icd->sizeimage;
if (0 == *count)
*count = 32;
if (!*num_planes &&
sizes[0] * *count > MAX_VIDEO_MEM * 1024 * 1024)
*count = (MAX_VIDEO_MEM * 1024 * 1024) / sizes[0];
*num_planes = 1;
return 0;
}
static int mx2_videobuf_prepare(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
int ret = 0;
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
#ifdef DEBUG
memset((void *)vb2_plane_vaddr(vb, 0),
0xaa, vb2_get_plane_payload(vb, 0));
#endif
vb2_set_plane_payload(vb, 0, icd->sizeimage);
if (vb2_plane_vaddr(vb, 0) &&
vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0)) {
ret = -EINVAL;
goto out;
}
return 0;
out:
return ret;
}
static void mx2_videobuf_queue(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici =
to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_buffer *buf = container_of(vb, struct mx2_buffer, vb);
unsigned long flags;
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
spin_lock_irqsave(&pcdev->lock, flags);
buf->state = MX2_STATE_QUEUED;
list_add_tail(&buf->internal.queue, &pcdev->capture);
if (is_imx25_camera(pcdev)) {
u32 csicr3, dma_inten = 0;
if (pcdev->fb1_active == NULL) {
writel(vb2_dma_contig_plane_dma_addr(vb, 0),
pcdev->base_csi + CSIDMASA_FB1);
pcdev->fb1_active = buf;
dma_inten = CSICR1_FB1_DMA_INTEN;
} else if (pcdev->fb2_active == NULL) {
writel(vb2_dma_contig_plane_dma_addr(vb, 0),
pcdev->base_csi + CSIDMASA_FB2);
pcdev->fb2_active = buf;
dma_inten = CSICR1_FB2_DMA_INTEN;
}
if (dma_inten) {
list_del(&buf->internal.queue);
buf->state = MX2_STATE_ACTIVE;
csicr3 = readl(pcdev->base_csi + pcdev->reg_csicr3);
writel(csicr3 | CSICR3_DMA_REFLASH_RFF,
pcdev->base_csi + pcdev->reg_csicr3);
writel(dma_inten, pcdev->base_csi + pcdev->reg_csisr);
pcdev->csicr1 |= dma_inten;
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
csicr3 |= CSICR3_DMA_REQ_EN_RFF | CSICR3_RXFF_LEVEL(1);
writel(csicr3, pcdev->base_csi + pcdev->reg_csicr3);
}
}
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static void mx2_videobuf_release(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_buffer *buf = container_of(vb, struct mx2_buffer, vb);
unsigned long flags;
#ifdef DEBUG
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
switch (buf->state) {
case MX2_STATE_ACTIVE:
dev_info(icd->parent, "%s (active)\n", __func__);
break;
case MX2_STATE_QUEUED:
dev_info(icd->parent, "%s (queued)\n", __func__);
break;
default:
dev_info(icd->parent, "%s (unknown) %d\n", __func__,
buf->state);
break;
}
#endif
spin_lock_irqsave(&pcdev->lock, flags);
if (is_imx25_camera(pcdev) && buf->state == MX2_STATE_ACTIVE) {
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
}
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static void mx27_camera_emma_buf_init(struct soc_camera_device *icd,
int bytesperline)
{
struct soc_camera_host *ici =
to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
writel((pcdev->s_width << 16) | pcdev->s_height,
pcdev->base_emma + PRP_SRC_FRAME_SIZE);
writel(prp->cfg.src_pixel,
pcdev->base_emma + PRP_SRC_PIXEL_FORMAT_CNTL);
if (prp->cfg.channel == 1) {
writel((icd->user_width << 16) | icd->user_height,
pcdev->base_emma + PRP_CH1_OUT_IMAGE_SIZE);
writel(bytesperline,
pcdev->base_emma + PRP_DEST_CH1_LINE_STRIDE);
writel(prp->cfg.ch1_pixel,
pcdev->base_emma + PRP_CH1_PIXEL_FORMAT_CNTL);
} else {
writel((icd->user_width << 16) | icd->user_height,
pcdev->base_emma + PRP_CH2_OUT_IMAGE_SIZE);
}
writel(prp->cfg.irq_flags, pcdev->base_emma + PRP_INTR_CNTL);
}
static void mx2_prp_resize_commit(struct mx2_camera_dev *pcdev)
{
int dir;
for (dir = RESIZE_DIR_H; dir <= RESIZE_DIR_V; dir++) {
unsigned char *s = pcdev->resizing[dir].s;
int len = pcdev->resizing[dir].len;
unsigned int coeff[2] = {0, 0};
unsigned int valid = 0;
int i;
if (len == 0)
continue;
for (i = RESIZE_NUM_MAX - 1; i >= 0; i--) {
int j;
j = i > 9 ? 1 : 0;
coeff[j] = (coeff[j] << BC_COEF) |
(s[i] & (SZ_COEF - 1));
if (i == 5 || i == 15)
coeff[j] <<= 1;
valid = (valid << 1) | (s[i] >> BC_COEF);
}
valid |= PRP_RZ_VALID_TBL_LEN(len);
if (pcdev->resizing[dir].algo == RESIZE_ALGO_BILINEAR)
valid |= PRP_RZ_VALID_BILINEAR;
if (pcdev->emma_prp->cfg.channel == 1) {
if (dir == RESIZE_DIR_H) {
writel(coeff[0], pcdev->base_emma +
PRP_CH1_RZ_HORI_COEF1);
writel(coeff[1], pcdev->base_emma +
PRP_CH1_RZ_HORI_COEF2);
writel(valid, pcdev->base_emma +
PRP_CH1_RZ_HORI_VALID);
} else {
writel(coeff[0], pcdev->base_emma +
PRP_CH1_RZ_VERT_COEF1);
writel(coeff[1], pcdev->base_emma +
PRP_CH1_RZ_VERT_COEF2);
writel(valid, pcdev->base_emma +
PRP_CH1_RZ_VERT_VALID);
}
} else {
if (dir == RESIZE_DIR_H) {
writel(coeff[0], pcdev->base_emma +
PRP_CH2_RZ_HORI_COEF1);
writel(coeff[1], pcdev->base_emma +
PRP_CH2_RZ_HORI_COEF2);
writel(valid, pcdev->base_emma +
PRP_CH2_RZ_HORI_VALID);
} else {
writel(coeff[0], pcdev->base_emma +
PRP_CH2_RZ_VERT_COEF1);
writel(coeff[1], pcdev->base_emma +
PRP_CH2_RZ_VERT_COEF2);
writel(valid, pcdev->base_emma +
PRP_CH2_RZ_VERT_VALID);
}
}
}
}
static int mx2_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(q);
struct soc_camera_host *ici =
to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
struct vb2_buffer *vb;
struct mx2_buffer *buf;
unsigned long phys;
int bytesperline;
if (is_imx27_camera(pcdev)) {
unsigned long flags;
if (count < 2)
return -EINVAL;
spin_lock_irqsave(&pcdev->lock, flags);
buf = list_first_entry(&pcdev->capture, struct mx2_buffer,
internal.queue);
buf->internal.bufnum = 0;
vb = &buf->vb;
buf->state = MX2_STATE_ACTIVE;
phys = vb2_dma_contig_plane_dma_addr(vb, 0);
mx27_update_emma_buf(pcdev, phys, buf->internal.bufnum);
list_move_tail(pcdev->capture.next, &pcdev->active_bufs);
buf = list_first_entry(&pcdev->capture, struct mx2_buffer,
internal.queue);
buf->internal.bufnum = 1;
vb = &buf->vb;
buf->state = MX2_STATE_ACTIVE;
phys = vb2_dma_contig_plane_dma_addr(vb, 0);
mx27_update_emma_buf(pcdev, phys, buf->internal.bufnum);
list_move_tail(pcdev->capture.next, &pcdev->active_bufs);
bytesperline = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
if (bytesperline < 0) {
spin_unlock_irqrestore(&pcdev->lock, flags);
return bytesperline;
}
pcdev->discard_size = icd->user_height * bytesperline;
pcdev->discard_buffer = dma_alloc_coherent(ici->v4l2_dev.dev,
pcdev->discard_size, &pcdev->discard_buffer_dma,
GFP_KERNEL);
if (!pcdev->discard_buffer) {
spin_unlock_irqrestore(&pcdev->lock, flags);
return -ENOMEM;
}
pcdev->buf_discard[0].discard = true;
list_add_tail(&pcdev->buf_discard[0].queue,
&pcdev->discard);
pcdev->buf_discard[1].discard = true;
list_add_tail(&pcdev->buf_discard[1].queue,
&pcdev->discard);
mx2_prp_resize_commit(pcdev);
mx27_camera_emma_buf_init(icd, bytesperline);
if (prp->cfg.channel == 1) {
writel(PRP_CNTL_CH1EN |
PRP_CNTL_CSIEN |
prp->cfg.in_fmt |
prp->cfg.out_fmt |
PRP_CNTL_CH1_LEN |
PRP_CNTL_CH1BYP |
PRP_CNTL_CH1_TSKIP(0) |
PRP_CNTL_IN_TSKIP(0),
pcdev->base_emma + PRP_CNTL);
} else {
writel(PRP_CNTL_CH2EN |
PRP_CNTL_CSIEN |
prp->cfg.in_fmt |
prp->cfg.out_fmt |
PRP_CNTL_CH2_LEN |
PRP_CNTL_CH2_TSKIP(0) |
PRP_CNTL_IN_TSKIP(0),
pcdev->base_emma + PRP_CNTL);
}
spin_unlock_irqrestore(&pcdev->lock, flags);
}
return 0;
}
static int mx2_stop_streaming(struct vb2_queue *q)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(q);
struct soc_camera_host *ici =
to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
unsigned long flags;
void *b;
u32 cntl;
if (is_imx27_camera(pcdev)) {
spin_lock_irqsave(&pcdev->lock, flags);
cntl = readl(pcdev->base_emma + PRP_CNTL);
if (prp->cfg.channel == 1) {
writel(cntl & ~PRP_CNTL_CH1EN,
pcdev->base_emma + PRP_CNTL);
} else {
writel(cntl & ~PRP_CNTL_CH2EN,
pcdev->base_emma + PRP_CNTL);
}
INIT_LIST_HEAD(&pcdev->capture);
INIT_LIST_HEAD(&pcdev->active_bufs);
INIT_LIST_HEAD(&pcdev->discard);
b = pcdev->discard_buffer;
pcdev->discard_buffer = NULL;
spin_unlock_irqrestore(&pcdev->lock, flags);
dma_free_coherent(ici->v4l2_dev.dev,
pcdev->discard_size, b, pcdev->discard_buffer_dma);
}
return 0;
}
static int mx2_camera_init_videobuf(struct vb2_queue *q,
struct soc_camera_device *icd)
{
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->drv_priv = icd;
q->ops = &mx2_videobuf_ops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct mx2_buffer);
return vb2_queue_init(q);
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
csicr1 = (csicr1 & ~CSICR1_FMT_MASK) | pcdev->emma_prp->cfg.csicr1;
if (common_flags & V4L2_MBUS_PCLK_SAMPLE_RISING)
csicr1 |= CSICR1_REDGE;
if (common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH)
csicr1 |= CSICR1_SOF_POL;
if (common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH)
csicr1 |= CSICR1_HSYNC_POL;
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
pcdev->csicr1 = csicr1;
bytesperline = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
if (bytesperline < 0)
return bytesperline;
if (is_imx27_camera(pcdev)) {
ret = mx27_camera_emma_prp_reset(pcdev);
if (ret)
return ret;
} else if (is_imx25_camera(pcdev)) {
writel((bytesperline * icd->user_height) >> 2,
pcdev->base_csi + CSIRXCNT);
writel((bytesperline << 16) | icd->user_height,
pcdev->base_csi + CSIIMAG_PARA);
}
writel(pcdev->csicr1, pcdev->base_csi + CSICR1);
return 0;
}
static int mx2_camera_set_crop(struct soc_camera_device *icd,
const struct v4l2_crop *a)
{
struct v4l2_crop a_writable = *a;
struct v4l2_rect *rect = &a_writable.c;
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
if (code == V4L2_MBUS_FMT_YUYV8_2X8 ||
code == V4L2_MBUS_FMT_UYVY8_2X8) {
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
if (code == V4L2_MBUS_FMT_UYVY8_2X8) {
formats++;
if (xlate) {
xlate->host_fmt =
soc_mbus_get_fmtdesc(V4L2_MBUS_FMT_YUYV8_2X8);
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
static int mx2_emmaprp_resize(struct mx2_camera_dev *pcdev,
struct v4l2_mbus_framefmt *mf_in,
struct v4l2_pix_format *pix_out, bool apply)
{
int num, den;
unsigned long m;
int i, dir;
for (dir = RESIZE_DIR_H; dir <= RESIZE_DIR_V; dir++) {
struct emma_prp_resize tmprsz;
unsigned char *s = tmprsz.s;
int len = 0;
int in, out;
if (dir == RESIZE_DIR_H) {
in = mf_in->width;
out = pix_out->width;
} else {
in = mf_in->height;
out = pix_out->height;
}
if (in < out)
return -EINVAL;
else if (in == out)
continue;
m = gcd(in, out);
num = in / m;
den = out / m;
if (num > RESIZE_NUM_MAX)
return -EINVAL;
if ((num >= 2 * den) && (den == 1) &&
(num < 9) && (!(num & 0x01))) {
int sum = 0;
int j;
tmprsz.algo = RESIZE_ALGO_AVERAGING;
len = num;
for (i = 0; i < (len / 2); i++)
s[i] = 8;
do {
for (i = 0; i < (len / 2); i++) {
s[i] = s[i] >> 1;
sum = 0;
for (j = 0; j < (len / 2); j++)
sum += s[j];
if (sum == 4)
break;
}
} while (sum != 4);
for (i = (len / 2); i < len; i++)
s[i] = s[len - i - 1];
s[len - 1] |= SZ_COEF;
} else {
int v;
int coeff, nxt;
int in_pos_inc = 2 * den;
int out_pos = num;
int out_pos_inc = 2 * num;
int init_carry = num - den;
int carry = init_carry;
tmprsz.algo = RESIZE_ALGO_BILINEAR;
v = den + in_pos_inc;
do {
coeff = v - out_pos;
out_pos += out_pos_inc;
carry += out_pos_inc;
for (nxt = 0; v < out_pos; nxt++) {
v += in_pos_inc;
carry -= in_pos_inc;
}
if (len > RESIZE_NUM_MAX)
return -EINVAL;
coeff = ((coeff << BC_COEF) +
(in_pos_inc >> 1)) / in_pos_inc;
if (coeff >= (SZ_COEF - 1))
coeff--;
coeff |= SZ_COEF;
s[len] = (unsigned char)coeff;
len++;
for (i = 1; i < nxt; i++) {
if (len >= RESIZE_NUM_MAX)
return -EINVAL;
s[len] = 0;
len++;
}
} while (carry != init_carry);
}
tmprsz.len = len;
if (dir == RESIZE_DIR_H)
mf_in->width = pix_out->width;
else
mf_in->height = pix_out->height;
if (apply)
memcpy(&pcdev->resizing[dir], &tmprsz, sizeof(tmprsz));
}
return 0;
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
dev_dbg(icd->parent, "%s: requested params: width = %d, height = %d\n",
__func__, pix->width, pix->height);
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
pcdev->s_width = mf.width;
pcdev->s_height = mf.height;
dev_dbg(icd->parent, "%s: sensor params: width = %d, height = %d\n",
__func__, pcdev->s_width, pcdev->s_height);
pcdev->emma_prp = mx27_emma_prp_get_format(xlate->code,
xlate->host_fmt->fourcc);
memset(pcdev->resizing, 0, sizeof(pcdev->resizing));
if ((mf.width != pix->width || mf.height != pix->height) &&
pcdev->emma_prp->cfg.in_fmt == PRP_CNTL_DATA_IN_YUV422) {
if (mx2_emmaprp_resize(pcdev, &mf, pix, true) < 0)
dev_dbg(icd->parent, "%s: can't resize\n", __func__);
}
if (mf.code != xlate->code)
return -EINVAL;
pix->width = mf.width;
pix->height = mf.height;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
icd->current_fmt = xlate;
dev_dbg(icd->parent, "%s: returned params: width = %d, height = %d\n",
__func__, pix->width, pix->height);
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
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct mx2_camera_dev *pcdev = ici->priv;
struct mx2_fmt_cfg *emma_prp;
unsigned int width_limit;
int ret;
dev_dbg(icd->parent, "%s: requested params: width = %d, height = %d\n",
__func__, pix->width, pix->height);
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (pixfmt && !xlate) {
dev_warn(icd->parent, "Format %x not found\n", pixfmt);
return -EINVAL;
}
if (is_imx25_camera(pcdev)) {
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
pix->sizeimage = soc_mbus_image_size(xlate->host_fmt,
pix->bytesperline, pix->height);
if (pix->sizeimage > 4 * 0x3ffff) {
unsigned int new_height = int_sqrt(div_u64(0x3ffffULL *
4 * pix->height, pix->bytesperline));
pix->width = new_height * pix->width / pix->height;
pix->height = new_height;
pix->bytesperline = soc_mbus_bytes_per_line(pix->width,
xlate->host_fmt);
BUG_ON(pix->bytesperline < 0);
pix->sizeimage = soc_mbus_image_size(xlate->host_fmt,
pix->bytesperline, pix->height);
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
dev_dbg(icd->parent, "%s: sensor params: width = %d, height = %d\n",
__func__, pcdev->s_width, pcdev->s_height);
emma_prp = mx27_emma_prp_get_format(xlate->code,
xlate->host_fmt->fourcc);
if ((mf.width != pix->width || mf.height != pix->height) &&
emma_prp->cfg.in_fmt == PRP_CNTL_DATA_IN_YUV422) {
if (mx2_emmaprp_resize(pcdev, &mf, pix, false) < 0)
dev_dbg(icd->parent, "%s: can't resize\n", __func__);
}
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
dev_dbg(icd->parent, "%s: returned params: width = %d, height = %d\n",
__func__, pix->width, pix->height);
return 0;
}
static int mx2_camera_querycap(struct soc_camera_host *ici,
struct v4l2_capability *cap)
{
strlcpy(cap->card, MX2_CAM_DRIVER_DESCRIPTION, sizeof(cap->card));
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
return 0;
}
static unsigned int mx2_camera_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
return vb2_poll(&icd->vb2_vidq, file, pt);
}
static void mx27_camera_frame_done_emma(struct mx2_camera_dev *pcdev,
int bufnum, bool err)
{
#ifdef DEBUG
struct mx2_fmt_cfg *prp = pcdev->emma_prp;
#endif
struct mx2_buf_internal *ibuf;
struct mx2_buffer *buf;
struct vb2_buffer *vb;
unsigned long phys;
ibuf = list_first_entry(&pcdev->active_bufs, struct mx2_buf_internal,
queue);
BUG_ON(ibuf->bufnum != bufnum);
if (ibuf->discard) {
list_move_tail(pcdev->active_bufs.next, &pcdev->discard);
} else {
buf = mx2_ibuf_to_buf(ibuf);
vb = &buf->vb;
#ifdef DEBUG
phys = vb2_dma_contig_plane_dma_addr(vb, 0);
if (prp->cfg.channel == 1) {
if (readl(pcdev->base_emma + PRP_DEST_RGB1_PTR +
4 * bufnum) != phys) {
dev_err(pcdev->dev, "%lx != %x\n", phys,
readl(pcdev->base_emma +
PRP_DEST_RGB1_PTR + 4 * bufnum));
}
} else {
if (readl(pcdev->base_emma + PRP_DEST_Y_PTR -
0x14 * bufnum) != phys) {
dev_err(pcdev->dev, "%lx != %x\n", phys,
readl(pcdev->base_emma +
PRP_DEST_Y_PTR - 0x14 * bufnum));
}
}
#endif
dev_dbg(pcdev->dev, "%s (vb=0x%p) 0x%p %lu\n", __func__, vb,
vb2_plane_vaddr(vb, 0),
vb2_get_plane_payload(vb, 0));
list_del_init(&buf->internal.queue);
do_gettimeofday(&vb->v4l2_buf.timestamp);
vb->v4l2_buf.sequence = pcdev->frame_count;
if (err)
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
else
vb2_buffer_done(vb, VB2_BUF_STATE_DONE);
}
pcdev->frame_count++;
if (list_empty(&pcdev->capture)) {
if (list_empty(&pcdev->discard)) {
dev_warn(pcdev->dev, "%s: trying to access empty discard list\n",
__func__);
return;
}
ibuf = list_first_entry(&pcdev->discard,
struct mx2_buf_internal, queue);
ibuf->bufnum = bufnum;
list_move_tail(pcdev->discard.next, &pcdev->active_bufs);
mx27_update_emma_buf(pcdev, pcdev->discard_buffer_dma, bufnum);
return;
}
buf = list_first_entry(&pcdev->capture, struct mx2_buffer,
internal.queue);
buf->internal.bufnum = bufnum;
list_move_tail(pcdev->capture.next, &pcdev->active_bufs);
vb = &buf->vb;
buf->state = MX2_STATE_ACTIVE;
phys = vb2_dma_contig_plane_dma_addr(vb, 0);
mx27_update_emma_buf(pcdev, phys, bufnum);
}
static irqreturn_t mx27_camera_emma_irq(int irq_emma, void *data)
{
struct mx2_camera_dev *pcdev = data;
unsigned int status = readl(pcdev->base_emma + PRP_INTRSTATUS);
struct mx2_buf_internal *ibuf;
spin_lock(&pcdev->lock);
if (list_empty(&pcdev->active_bufs)) {
dev_warn(pcdev->dev, "%s: called while active list is empty\n",
__func__);
if (!status) {
spin_unlock(&pcdev->lock);
return IRQ_NONE;
}
}
if (status & (1 << 7)) {
u32 cntl = readl(pcdev->base_emma + PRP_CNTL);
writel(cntl & ~(PRP_CNTL_CH1EN | PRP_CNTL_CH2EN),
pcdev->base_emma + PRP_CNTL);
writel(cntl, pcdev->base_emma + PRP_CNTL);
ibuf = list_first_entry(&pcdev->active_bufs,
struct mx2_buf_internal, queue);
mx27_camera_frame_done_emma(pcdev,
ibuf->bufnum, true);
status &= ~(1 << 7);
} else if (((status & (3 << 5)) == (3 << 5)) ||
((status & (3 << 3)) == (3 << 3))) {
ibuf = list_first_entry(&pcdev->active_bufs,
struct mx2_buf_internal, queue);
mx27_camera_frame_done_emma(pcdev, ibuf->bufnum, false);
status &= ~(1 << (6 - ibuf->bufnum));
} else if ((status & (1 << 6)) || (status & (1 << 4))) {
mx27_camera_frame_done_emma(pcdev, 0, false);
} else if ((status & (1 << 5)) || (status & (1 << 3))) {
mx27_camera_frame_done_emma(pcdev, 1, false);
}
spin_unlock(&pcdev->lock);
writel(status, pcdev->base_emma + PRP_INTRSTATUS);
return IRQ_HANDLED;
}
static int mx27_camera_emma_init(struct platform_device *pdev)
{
struct mx2_camera_dev *pcdev = platform_get_drvdata(pdev);
struct resource *res_emma;
int irq_emma;
int err = 0;
res_emma = platform_get_resource(pdev, IORESOURCE_MEM, 1);
irq_emma = platform_get_irq(pdev, 1);
if (!res_emma || !irq_emma) {
dev_err(pcdev->dev, "no EMMA resources\n");
err = -ENODEV;
goto out;
}
pcdev->base_emma = devm_request_and_ioremap(pcdev->dev, res_emma);
if (!pcdev->base_emma) {
err = -EADDRNOTAVAIL;
goto out;
}
err = devm_request_irq(pcdev->dev, irq_emma, mx27_camera_emma_irq, 0,
MX2_CAM_DRV_NAME, pcdev);
if (err) {
dev_err(pcdev->dev, "Camera EMMA interrupt register failed \n");
goto out;
}
pcdev->clk_emma_ipg = devm_clk_get(pcdev->dev, "emma-ipg");
if (IS_ERR(pcdev->clk_emma_ipg)) {
err = PTR_ERR(pcdev->clk_emma_ipg);
goto out;
}
clk_prepare_enable(pcdev->clk_emma_ipg);
pcdev->clk_emma_ahb = devm_clk_get(pcdev->dev, "emma-ahb");
if (IS_ERR(pcdev->clk_emma_ahb)) {
err = PTR_ERR(pcdev->clk_emma_ahb);
goto exit_clk_emma_ipg;
}
clk_prepare_enable(pcdev->clk_emma_ahb);
err = mx27_camera_emma_prp_reset(pcdev);
if (err)
goto exit_clk_emma_ahb;
return err;
exit_clk_emma_ahb:
clk_disable_unprepare(pcdev->clk_emma_ahb);
exit_clk_emma_ipg:
clk_disable_unprepare(pcdev->clk_emma_ipg);
out:
return err;
}
static int mx2_camera_probe(struct platform_device *pdev)
{
struct mx2_camera_dev *pcdev;
struct resource *res_csi;
int irq_csi;
int err = 0;
dev_dbg(&pdev->dev, "initialising\n");
res_csi = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq_csi = platform_get_irq(pdev, 0);
if (res_csi == NULL || irq_csi < 0) {
dev_err(&pdev->dev, "Missing platform resources data\n");
err = -ENODEV;
goto exit;
}
pcdev = devm_kzalloc(&pdev->dev, sizeof(*pcdev), GFP_KERNEL);
if (!pcdev) {
dev_err(&pdev->dev, "Could not allocate pcdev\n");
err = -ENOMEM;
goto exit;
}
pcdev->devtype = pdev->id_entry->driver_data;
switch (pcdev->devtype) {
case IMX25_CAMERA:
pcdev->reg_csisr = CSISR_IMX25;
pcdev->reg_csicr3 = CSICR3_IMX25;
break;
case IMX27_CAMERA:
pcdev->reg_csisr = CSISR_IMX27;
pcdev->reg_csicr3 = CSICR3_IMX27;
break;
default:
break;
}
pcdev->clk_csi_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(pcdev->clk_csi_ahb)) {
dev_err(&pdev->dev, "Could not get csi ahb clock\n");
err = PTR_ERR(pcdev->clk_csi_ahb);
goto exit;
}
pcdev->clk_csi_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(pcdev->clk_csi_per)) {
dev_err(&pdev->dev, "Could not get csi per clock\n");
err = PTR_ERR(pcdev->clk_csi_per);
goto exit;
}
pcdev->pdata = pdev->dev.platform_data;
if (pcdev->pdata) {
long rate;
pcdev->platform_flags = pcdev->pdata->flags;
rate = clk_round_rate(pcdev->clk_csi_per,
pcdev->pdata->clk * 2);
if (rate <= 0) {
err = -ENODEV;
goto exit;
}
err = clk_set_rate(pcdev->clk_csi_per, rate);
if (err < 0)
goto exit;
}
INIT_LIST_HEAD(&pcdev->capture);
INIT_LIST_HEAD(&pcdev->active_bufs);
INIT_LIST_HEAD(&pcdev->discard);
spin_lock_init(&pcdev->lock);
pcdev->base_csi = devm_request_and_ioremap(&pdev->dev, res_csi);
if (!pcdev->base_csi) {
err = -EADDRNOTAVAIL;
goto exit;
}
pcdev->dev = &pdev->dev;
platform_set_drvdata(pdev, pcdev);
if (is_imx25_camera(pcdev)) {
err = devm_request_irq(&pdev->dev, irq_csi, mx25_camera_irq, 0,
MX2_CAM_DRV_NAME, pcdev);
if (err) {
dev_err(pcdev->dev, "Camera interrupt register failed \n");
goto exit;
}
}
if (is_imx27_camera(pcdev)) {
err = mx27_camera_emma_init(pdev);
if (err)
goto exit;
}
platform_set_drvdata(pdev, NULL);
pcdev->soc_host.drv_name = MX2_CAM_DRV_NAME,
pcdev->soc_host.ops = &mx2_soc_camera_host_ops,
pcdev->soc_host.priv = pcdev;
pcdev->soc_host.v4l2_dev.dev = &pdev->dev;
pcdev->soc_host.nr = pdev->id;
if (is_imx25_camera(pcdev))
pcdev->soc_host.capabilities = SOCAM_HOST_CAP_STRIDE;
pcdev->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(pcdev->alloc_ctx)) {
err = PTR_ERR(pcdev->alloc_ctx);
goto eallocctx;
}
err = soc_camera_host_register(&pcdev->soc_host);
if (err)
goto exit_free_emma;
dev_info(&pdev->dev, "MX2 Camera (CSI) driver probed, clock frequency: %ld\n",
clk_get_rate(pcdev->clk_csi_per));
return 0;
exit_free_emma:
vb2_dma_contig_cleanup_ctx(pcdev->alloc_ctx);
eallocctx:
if (is_imx27_camera(pcdev)) {
clk_disable_unprepare(pcdev->clk_emma_ipg);
clk_disable_unprepare(pcdev->clk_emma_ahb);
}
exit:
return err;
}
static int mx2_camera_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct mx2_camera_dev *pcdev = container_of(soc_host,
struct mx2_camera_dev, soc_host);
soc_camera_host_unregister(&pcdev->soc_host);
vb2_dma_contig_cleanup_ctx(pcdev->alloc_ctx);
if (is_imx27_camera(pcdev)) {
clk_disable_unprepare(pcdev->clk_emma_ipg);
clk_disable_unprepare(pcdev->clk_emma_ahb);
}
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
