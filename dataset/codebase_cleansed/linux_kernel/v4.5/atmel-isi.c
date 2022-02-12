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
static u32 setup_cfg2_yuv_swap(struct atmel_isi *isi,
const struct soc_camera_format_xlate *xlate)
{
if (xlate->host_fmt->fourcc == V4L2_PIX_FMT_YUYV) {
switch (xlate->code) {
case MEDIA_BUS_FMT_VYUY8_2X8:
return ISI_CFG2_YCC_SWAP_MODE_3;
case MEDIA_BUS_FMT_UYVY8_2X8:
return ISI_CFG2_YCC_SWAP_MODE_2;
case MEDIA_BUS_FMT_YVYU8_2X8:
return ISI_CFG2_YCC_SWAP_MODE_1;
}
} else if (xlate->host_fmt->fourcc == V4L2_PIX_FMT_RGB565) {
switch (xlate->code) {
case MEDIA_BUS_FMT_VYUY8_2X8:
return ISI_CFG2_YCC_SWAP_MODE_1;
case MEDIA_BUS_FMT_YUYV8_2X8:
return ISI_CFG2_YCC_SWAP_MODE_2;
case MEDIA_BUS_FMT_YVYU8_2X8:
return ISI_CFG2_YCC_SWAP_MODE_3;
}
}
return ISI_CFG2_YCC_SWAP_DEFAULT;
}
static void configure_geometry(struct atmel_isi *isi, u32 width,
u32 height, const struct soc_camera_format_xlate *xlate)
{
u32 cfg2, psize;
u32 fourcc = xlate->host_fmt->fourcc;
isi->enable_preview_path = fourcc == V4L2_PIX_FMT_RGB565 ||
fourcc == V4L2_PIX_FMT_RGB32;
switch (xlate->code) {
default:
case MEDIA_BUS_FMT_Y8_1X8:
cfg2 = ISI_CFG2_GRAYSCALE | ISI_CFG2_COL_SPACE_YCbCr;
break;
case MEDIA_BUS_FMT_VYUY8_2X8:
case MEDIA_BUS_FMT_UYVY8_2X8:
case MEDIA_BUS_FMT_YVYU8_2X8:
case MEDIA_BUS_FMT_YUYV8_2X8:
cfg2 = ISI_CFG2_COL_SPACE_YCbCr |
setup_cfg2_yuv_swap(isi, xlate);
break;
}
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
cfg2 |= ((width - 1) << ISI_CFG2_IM_HSIZE_OFFSET) &
ISI_CFG2_IM_HSIZE_MASK;
cfg2 |= ((height - 1) << ISI_CFG2_IM_VSIZE_OFFSET)
& ISI_CFG2_IM_VSIZE_MASK;
isi_writel(isi, ISI_CFG2, cfg2);
psize = ((width - 1) << ISI_PSIZE_PREV_HSIZE_OFFSET) &
ISI_PSIZE_PREV_HSIZE_MASK;
psize |= ((height - 1) << ISI_PSIZE_PREV_VSIZE_OFFSET) &
ISI_PSIZE_PREV_VSIZE_MASK;
isi_writel(isi, ISI_PSIZE, psize);
isi_writel(isi, ISI_PDECF, ISI_PDECF_NO_SAMPLING);
return;
}
static bool is_supported(struct soc_camera_device *icd,
const u32 pixformat)
{
switch (pixformat) {
case V4L2_PIX_FMT_GREY:
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_YVYU:
case V4L2_PIX_FMT_VYUY:
case V4L2_PIX_FMT_RGB565:
return true;
default:
return false;
}
}
static irqreturn_t atmel_isi_handle_streaming(struct atmel_isi *isi)
{
if (isi->active) {
struct vb2_v4l2_buffer *vbuf = &isi->active->vb;
struct frame_buffer *buf = isi->active;
list_del_init(&buf->list);
vbuf->vb2_buf.timestamp = ktime_get_ns();
vbuf->sequence = isi->sequence++;
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
if (likely(pending & ISI_SR_CXFR_DONE) ||
likely(pending & ISI_SR_PXFR_DONE))
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
msecs_to_jiffies(500));
if (timeout == 0)
return -ETIMEDOUT;
return 0;
}
static int queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
unsigned long size;
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
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
buf->p_dma_desc = NULL;
INIT_LIST_HEAD(&buf->list);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
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
vb2_set_plane_payload(vb, 0, size);
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
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
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
dev_err(isi->soc_host.icd->parent, "Already in frame handling.\n");
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
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct atmel_isi *isi = ici->priv;
struct frame_buffer *buf = container_of(vbuf, struct frame_buffer, vb);
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
int ret;
pm_runtime_get_sync(ici->v4l2_dev.dev);
ret = atmel_isi_wait_status(isi, WAIT_ISI_RESET);
if (ret < 0) {
dev_err(icd->parent, "Reset ISI timed out\n");
pm_runtime_put(ici->v4l2_dev.dev);
return ret;
}
isi_writel(isi, ISI_INTDIS, (u32)~0UL);
configure_geometry(isi, icd->user_width, icd->user_height,
icd->current_fmt);
spin_lock_irq(&isi->lock);
isi_readl(isi, ISI_STATUS);
if (count)
start_dma(isi, isi->active);
spin_unlock_irq(&isi->lock);
return 0;
}
static void stop_streaming(struct vb2_queue *vq)
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
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irq(&isi->lock);
if (!isi->enable_preview_path) {
timeout = jiffies + FRAME_INTERVAL_MILLI_SEC * HZ;
while ((isi_readl(isi, ISI_STATUS) & ISI_CTRL_CDC) &&
time_before(jiffies, timeout))
msleep(1);
if (time_after(jiffies, timeout))
dev_err(icd->parent,
"Timeout waiting for finishing codec request\n");
}
isi_writel(isi, ISI_INTDIS,
ISI_SR_CXFR_DONE | ISI_SR_PXFR_DONE);
ret = atmel_isi_wait_status(isi, WAIT_ISI_DISABLE);
if (ret < 0)
dev_err(icd->parent, "Disable ISI timed out\n");
pm_runtime_put(ici->v4l2_dev.dev);
}
static int isi_camera_init_videobuf(struct vb2_queue *q,
struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP;
q->drv_priv = icd;
q->buf_struct_size = sizeof(struct frame_buffer);
q->ops = &isi_video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &ici->host_lock;
return vb2_queue_init(q);
}
static int isi_camera_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
struct v4l2_mbus_framefmt *mf = &format.format;
int ret;
if (!is_supported(icd, pix->pixelformat))
pix->pixelformat = V4L2_PIX_FMT_YUYV;
xlate = soc_camera_xlate_by_fourcc(icd, pix->pixelformat);
if (!xlate) {
dev_warn(icd->parent, "Format %x not found\n",
pix->pixelformat);
return -EINVAL;
}
dev_dbg(icd->parent, "Plan to set format %dx%d\n",
pix->width, pix->height);
mf->width = pix->width;
mf->height = pix->height;
mf->field = pix->field;
mf->colorspace = pix->colorspace;
mf->code = xlate->code;
ret = v4l2_subdev_call(sd, pad, set_fmt, NULL, &format);
if (ret < 0)
return ret;
if (mf->code != xlate->code)
return -EINVAL;
pix->width = mf->width;
pix->height = mf->height;
pix->field = mf->field;
pix->colorspace = mf->colorspace;
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
struct v4l2_subdev_pad_config pad_cfg;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_TRY,
};
struct v4l2_mbus_framefmt *mf = &format.format;
u32 pixfmt = pix->pixelformat;
int ret;
if (!is_supported(icd, pix->pixelformat))
pix->pixelformat = V4L2_PIX_FMT_YUYV;
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (pixfmt && !xlate) {
dev_warn(icd->parent, "Format %x not found\n", pixfmt);
return -EINVAL;
}
if (pix->height > MAX_SUPPORT_HEIGHT)
pix->height = MAX_SUPPORT_HEIGHT;
if (pix->width > MAX_SUPPORT_WIDTH)
pix->width = MAX_SUPPORT_WIDTH;
mf->width = pix->width;
mf->height = pix->height;
mf->field = pix->field;
mf->colorspace = pix->colorspace;
mf->code = xlate->code;
ret = v4l2_subdev_call(sd, pad, set_fmt, &pad_cfg, &format);
if (ret < 0)
return ret;
pix->width = mf->width;
pix->height = mf->height;
pix->colorspace = mf->colorspace;
switch (mf->field) {
case V4L2_FIELD_ANY:
pix->field = V4L2_FIELD_NONE;
break;
case V4L2_FIELD_NONE:
break;
default:
dev_err(icd->parent, "Field type %d unsupported.\n",
mf->field);
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
int formats = 0, ret, i, n;
struct v4l2_subdev_mbus_code_enum code = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
.index = idx,
};
const struct soc_mbus_pixelfmt *fmt;
ret = v4l2_subdev_call(sd, pad, enum_mbus_code, NULL, &code);
if (ret < 0)
return 0;
fmt = soc_mbus_get_fmtdesc(code.code);
if (!fmt) {
dev_err(icd->parent,
"Invalid format code #%u: %d\n", idx, code.code);
return 0;
}
ret = isi_camera_try_bus_param(icd, fmt->bits_per_sample);
if (ret < 0) {
dev_err(icd->parent,
"Fail to try the bus parameters.\n");
return 0;
}
switch (code.code) {
case MEDIA_BUS_FMT_UYVY8_2X8:
case MEDIA_BUS_FMT_VYUY8_2X8:
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_YVYU8_2X8:
n = ARRAY_SIZE(isi_camera_formats);
formats += n;
for (i = 0; xlate && i < n; i++, xlate++) {
xlate->host_fmt = &isi_camera_formats[i];
xlate->code = code.code;
dev_dbg(icd->parent, "Providing format %s using code %d\n",
xlate->host_fmt->name, xlate->code);
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
xlate->code = code.code;
xlate++;
}
return formats;
}
static int isi_camera_add_device(struct soc_camera_device *icd)
{
dev_dbg(icd->parent, "Atmel ISI Camera driver attached to camera %d\n",
icd->devnum);
return 0;
}
static void isi_camera_remove_device(struct soc_camera_device *icd)
{
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
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
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
if (isi->pdata.hsync_act_low)
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)) {
if (isi->pdata.vsync_act_low)
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_PCLK_SAMPLE_RISING) &&
(common_flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)) {
if (isi->pdata.pclk_act_falling)
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
dev_dbg(icd->parent, "vsync active %s, hsync active %s, sampling on pix clock %s edge\n",
common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW ? "low" : "high",
common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW ? "low" : "high",
common_flags & V4L2_MBUS_PCLK_SAMPLE_FALLING ? "falling" : "rising");
if (isi->pdata.has_emb_sync)
cfg1 |= ISI_CFG1_EMB_SYNC;
if (isi->pdata.full_mode)
cfg1 |= ISI_CFG1_FULL_MODE;
cfg1 |= ISI_CFG1_THMASK_BEATS_16;
pm_runtime_get_sync(ici->v4l2_dev.dev);
isi_writel(isi, ISI_CTRL, ISI_CTRL_DIS);
isi_writel(isi, ISI_CFG1, cfg1);
pm_runtime_put(ici->v4l2_dev.dev);
return 0;
}
static int atmel_isi_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct atmel_isi *isi = container_of(soc_host,
struct atmel_isi, soc_host);
soc_camera_host_unregister(soc_host);
vb2_dma_contig_cleanup_ctx(isi->alloc_ctx);
dma_free_coherent(&pdev->dev,
sizeof(struct fbd) * MAX_BUFFER_NUM,
isi->p_fb_descriptors,
isi->fb_descriptors_phys);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int atmel_isi_parse_dt(struct atmel_isi *isi,
struct platform_device *pdev)
{
struct device_node *np= pdev->dev.of_node;
struct v4l2_of_endpoint ep;
int err;
isi->pdata.full_mode = 1;
isi->pdata.frate = ISI_CFG1_FRATE_CAPTURE_ALL;
np = of_graph_get_next_endpoint(np, NULL);
if (!np) {
dev_err(&pdev->dev, "Could not find the endpoint\n");
return -EINVAL;
}
err = v4l2_of_parse_endpoint(np, &ep);
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
static int atmel_isi_probe(struct platform_device *pdev)
{
unsigned int irq;
struct atmel_isi *isi;
struct resource *regs;
int ret, i;
struct soc_camera_host *soc_host;
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
spin_lock_init(&isi->lock);
INIT_LIST_HEAD(&isi->video_buffer_list);
INIT_LIST_HEAD(&isi->dma_desc_head);
isi->p_fb_descriptors = dma_alloc_coherent(&pdev->dev,
sizeof(struct fbd) * MAX_BUFFER_NUM,
&isi->fb_descriptors_phys,
GFP_KERNEL);
if (!isi->p_fb_descriptors) {
dev_err(&pdev->dev, "Can't allocate descriptors!\n");
return -ENOMEM;
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
if (IS_ERR_VALUE(irq)) {
ret = irq;
goto err_req_irq;
}
ret = devm_request_irq(&pdev->dev, irq, isi_interrupt, 0, "isi", isi);
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
pm_suspend_ignore_children(&pdev->dev, true);
pm_runtime_enable(&pdev->dev);
ret = soc_camera_host_register(soc_host);
if (ret) {
dev_err(&pdev->dev, "Unable to register soc camera host\n");
goto err_register_soc_camera_host;
}
return 0;
err_register_soc_camera_host:
pm_runtime_disable(&pdev->dev);
err_req_irq:
err_ioremap:
vb2_dma_contig_cleanup_ctx(isi->alloc_ctx);
err_alloc_ctx:
dma_free_coherent(&pdev->dev,
sizeof(struct fbd) * MAX_BUFFER_NUM,
isi->p_fb_descriptors,
isi->fb_descriptors_phys);
return ret;
}
static int atmel_isi_runtime_suspend(struct device *dev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(dev);
struct atmel_isi *isi = container_of(soc_host,
struct atmel_isi, soc_host);
clk_disable_unprepare(isi->pclk);
return 0;
}
static int atmel_isi_runtime_resume(struct device *dev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(dev);
struct atmel_isi *isi = container_of(soc_host,
struct atmel_isi, soc_host);
return clk_prepare_enable(isi->pclk);
}
