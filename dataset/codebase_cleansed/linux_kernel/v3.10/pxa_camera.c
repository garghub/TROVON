static int pxa_videobuf_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct soc_camera_device *icd = vq->priv_data;
dev_dbg(icd->parent, "count=%d, size=%d\n", *count, *size);
*size = icd->sizeimage;
if (0 == *count)
*count = 32;
if (*size * *count > vid_limit * 1024 * 1024)
*count = (vid_limit * 1024 * 1024) / *size;
return 0;
}
static void free_buffer(struct videobuf_queue *vq, struct pxa_buffer *buf)
{
struct soc_camera_device *icd = vq->priv_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct videobuf_dmabuf *dma = videobuf_to_dma(&buf->vb);
int i;
BUG_ON(in_interrupt());
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
&buf->vb, buf->vb.baddr, buf->vb.bsize);
videobuf_waiton(vq, &buf->vb, 0, 0);
videobuf_dma_unmap(vq->dev, dma);
videobuf_dma_free(dma);
for (i = 0; i < ARRAY_SIZE(buf->dmas); i++) {
if (buf->dmas[i].sg_cpu)
dma_free_coherent(ici->v4l2_dev.dev,
buf->dmas[i].sg_size,
buf->dmas[i].sg_cpu,
buf->dmas[i].sg_dma);
buf->dmas[i].sg_cpu = NULL;
}
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int calculate_dma_sglen(struct scatterlist *sglist, int sglen,
int sg_first_ofs, int size)
{
int i, offset, dma_len, xfer_len;
struct scatterlist *sg;
offset = sg_first_ofs;
for_each_sg(sglist, sg, sglen, i) {
dma_len = sg_dma_len(sg);
xfer_len = roundup(min(dma_len - offset, size), 8);
size = max(0, size - xfer_len);
offset = 0;
if (size == 0)
break;
}
BUG_ON(size != 0);
return i + 1;
}
static int pxa_init_dma_channel(struct pxa_camera_dev *pcdev,
struct pxa_buffer *buf,
struct videobuf_dmabuf *dma, int channel,
int cibr, int size,
struct scatterlist **sg_first, int *sg_first_ofs)
{
struct pxa_cam_dma *pxa_dma = &buf->dmas[channel];
struct device *dev = pcdev->soc_host.v4l2_dev.dev;
struct scatterlist *sg;
int i, offset, sglen;
int dma_len = 0, xfer_len = 0;
if (pxa_dma->sg_cpu)
dma_free_coherent(dev, pxa_dma->sg_size,
pxa_dma->sg_cpu, pxa_dma->sg_dma);
sglen = calculate_dma_sglen(*sg_first, dma->sglen,
*sg_first_ofs, size);
pxa_dma->sg_size = (sglen + 1) * sizeof(struct pxa_dma_desc);
pxa_dma->sg_cpu = dma_alloc_coherent(dev, pxa_dma->sg_size,
&pxa_dma->sg_dma, GFP_KERNEL);
if (!pxa_dma->sg_cpu)
return -ENOMEM;
pxa_dma->sglen = sglen;
offset = *sg_first_ofs;
dev_dbg(dev, "DMA: sg_first=%p, sglen=%d, ofs=%d, dma.desc=%x\n",
*sg_first, sglen, *sg_first_ofs, pxa_dma->sg_dma);
for_each_sg(*sg_first, sg, sglen, i) {
dma_len = sg_dma_len(sg);
xfer_len = roundup(min(dma_len - offset, size), 8);
size = max(0, size - xfer_len);
pxa_dma->sg_cpu[i].dsadr = pcdev->res->start + cibr;
pxa_dma->sg_cpu[i].dtadr = sg_dma_address(sg) + offset;
pxa_dma->sg_cpu[i].dcmd =
DCMD_FLOWSRC | DCMD_BURST8 | DCMD_INCTRGADDR | xfer_len;
#ifdef DEBUG
if (!i)
pxa_dma->sg_cpu[i].dcmd |= DCMD_STARTIRQEN;
#endif
pxa_dma->sg_cpu[i].ddadr =
pxa_dma->sg_dma + (i + 1) * sizeof(struct pxa_dma_desc);
dev_vdbg(dev, "DMA: desc.%08x->@phys=0x%08x, len=%d\n",
pxa_dma->sg_dma + i * sizeof(struct pxa_dma_desc),
sg_dma_address(sg) + offset, xfer_len);
offset = 0;
if (size == 0)
break;
}
pxa_dma->sg_cpu[sglen].ddadr = DDADR_STOP;
pxa_dma->sg_cpu[sglen].dcmd = DCMD_FLOWSRC | DCMD_BURST8 | DCMD_ENDIRQEN;
if (xfer_len >= dma_len) {
*sg_first_ofs = xfer_len - dma_len;
*sg_first = sg_next(sg);
} else {
*sg_first_ofs = xfer_len;
*sg_first = sg;
}
return 0;
}
static void pxa_videobuf_set_actdma(struct pxa_camera_dev *pcdev,
struct pxa_buffer *buf)
{
buf->active_dma = DMA_Y;
if (pcdev->channels == 3)
buf->active_dma |= DMA_U | DMA_V;
}
static int pxa_videobuf_prepare(struct videobuf_queue *vq,
struct videobuf_buffer *vb, enum v4l2_field field)
{
struct soc_camera_device *icd = vq->priv_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
struct device *dev = pcdev->soc_host.v4l2_dev.dev;
struct pxa_buffer *buf = container_of(vb, struct pxa_buffer, vb);
int ret;
int size_y, size_u = 0, size_v = 0;
dev_dbg(dev, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
WARN_ON(!list_empty(&vb->queue));
#ifdef DEBUG
memset((void *)vb->baddr, 0xaa, vb->bsize);
#endif
BUG_ON(NULL == icd->current_fmt);
buf->inwork = 1;
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
vb->size = icd->sizeimage;
if (0 != vb->baddr && vb->bsize < vb->size) {
ret = -EINVAL;
goto out;
}
if (vb->state == VIDEOBUF_NEEDS_INIT) {
int size = vb->size;
int next_ofs = 0;
struct videobuf_dmabuf *dma = videobuf_to_dma(vb);
struct scatterlist *sg;
ret = videobuf_iolock(vq, vb, NULL);
if (ret)
goto fail;
if (pcdev->channels == 3) {
size_y = size / 2;
size_u = size_v = size / 4;
} else {
size_y = size;
}
sg = dma->sglist;
ret = pxa_init_dma_channel(pcdev, buf, dma, 0, CIBR0, size_y,
&sg, &next_ofs);
if (ret) {
dev_err(dev, "DMA initialization for Y/RGB failed\n");
goto fail;
}
if (size_u)
ret = pxa_init_dma_channel(pcdev, buf, dma, 1, CIBR1,
size_u, &sg, &next_ofs);
if (ret) {
dev_err(dev, "DMA initialization for U failed\n");
goto fail_u;
}
if (size_v)
ret = pxa_init_dma_channel(pcdev, buf, dma, 2, CIBR2,
size_v, &sg, &next_ofs);
if (ret) {
dev_err(dev, "DMA initialization for V failed\n");
goto fail_v;
}
vb->state = VIDEOBUF_PREPARED;
}
buf->inwork = 0;
pxa_videobuf_set_actdma(pcdev, buf);
return 0;
fail_v:
dma_free_coherent(dev, buf->dmas[1].sg_size,
buf->dmas[1].sg_cpu, buf->dmas[1].sg_dma);
fail_u:
dma_free_coherent(dev, buf->dmas[0].sg_size,
buf->dmas[0].sg_cpu, buf->dmas[0].sg_dma);
fail:
free_buffer(vq, buf);
out:
buf->inwork = 0;
return ret;
}
static void pxa_dma_start_channels(struct pxa_camera_dev *pcdev)
{
int i;
struct pxa_buffer *active;
active = pcdev->active;
for (i = 0; i < pcdev->channels; i++) {
dev_dbg(pcdev->soc_host.v4l2_dev.dev,
"%s (channel=%d) ddadr=%08x\n", __func__,
i, active->dmas[i].sg_dma);
DDADR(pcdev->dma_chans[i]) = active->dmas[i].sg_dma;
DCSR(pcdev->dma_chans[i]) = DCSR_RUN;
}
}
static void pxa_dma_stop_channels(struct pxa_camera_dev *pcdev)
{
int i;
for (i = 0; i < pcdev->channels; i++) {
dev_dbg(pcdev->soc_host.v4l2_dev.dev,
"%s (channel=%d)\n", __func__, i);
DCSR(pcdev->dma_chans[i]) = 0;
}
}
static void pxa_dma_add_tail_buf(struct pxa_camera_dev *pcdev,
struct pxa_buffer *buf)
{
int i;
struct pxa_dma_desc *buf_last_desc;
for (i = 0; i < pcdev->channels; i++) {
buf_last_desc = buf->dmas[i].sg_cpu + buf->dmas[i].sglen;
buf_last_desc->ddadr = DDADR_STOP;
if (pcdev->sg_tail[i])
pcdev->sg_tail[i]->ddadr = buf->dmas[i].sg_dma;
pcdev->sg_tail[i] = buf_last_desc;
}
}
static void pxa_camera_start_capture(struct pxa_camera_dev *pcdev)
{
unsigned long cicr0;
dev_dbg(pcdev->soc_host.v4l2_dev.dev, "%s\n", __func__);
cicr0 = __raw_readl(pcdev->base + CICR0) | CICR0_ENB;
cicr0 &= ~CICR0_EOFM;
__raw_writel(cicr0, pcdev->base + CICR0);
}
static void pxa_camera_stop_capture(struct pxa_camera_dev *pcdev)
{
unsigned long cicr0;
pxa_dma_stop_channels(pcdev);
cicr0 = __raw_readl(pcdev->base + CICR0) & ~CICR0_ENB;
__raw_writel(cicr0, pcdev->base + CICR0);
pcdev->active = NULL;
dev_dbg(pcdev->soc_host.v4l2_dev.dev, "%s\n", __func__);
}
static void pxa_videobuf_queue(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct soc_camera_device *icd = vq->priv_data;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
struct pxa_buffer *buf = container_of(vb, struct pxa_buffer, vb);
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%08lx %d active=%p\n",
__func__, vb, vb->baddr, vb->bsize, pcdev->active);
list_add_tail(&vb->queue, &pcdev->capture);
vb->state = VIDEOBUF_ACTIVE;
pxa_dma_add_tail_buf(pcdev, buf);
if (!pcdev->active)
pxa_camera_start_capture(pcdev);
}
static void pxa_videobuf_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct pxa_buffer *buf = container_of(vb, struct pxa_buffer, vb);
#ifdef DEBUG
struct soc_camera_device *icd = vq->priv_data;
struct device *dev = icd->parent;
dev_dbg(dev, "%s (vb=0x%p) 0x%08lx %d\n", __func__,
vb, vb->baddr, vb->bsize);
switch (vb->state) {
case VIDEOBUF_ACTIVE:
dev_dbg(dev, "%s (active)\n", __func__);
break;
case VIDEOBUF_QUEUED:
dev_dbg(dev, "%s (queued)\n", __func__);
break;
case VIDEOBUF_PREPARED:
dev_dbg(dev, "%s (prepared)\n", __func__);
break;
default:
dev_dbg(dev, "%s (unknown)\n", __func__);
break;
}
#endif
free_buffer(vq, buf);
}
static void pxa_camera_wakeup(struct pxa_camera_dev *pcdev,
struct videobuf_buffer *vb,
struct pxa_buffer *buf)
{
int i;
list_del_init(&vb->queue);
vb->state = VIDEOBUF_DONE;
v4l2_get_timestamp(&vb->ts);
vb->field_count++;
wake_up(&vb->done);
dev_dbg(pcdev->soc_host.v4l2_dev.dev, "%s dequeud buffer (vb=0x%p)\n",
__func__, vb);
if (list_empty(&pcdev->capture)) {
pxa_camera_stop_capture(pcdev);
for (i = 0; i < pcdev->channels; i++)
pcdev->sg_tail[i] = NULL;
return;
}
pcdev->active = list_entry(pcdev->capture.next,
struct pxa_buffer, vb.queue);
}
static void pxa_camera_check_link_miss(struct pxa_camera_dev *pcdev)
{
int i, is_dma_stopped = 1;
for (i = 0; i < pcdev->channels; i++)
if (DDADR(pcdev->dma_chans[i]) != DDADR_STOP)
is_dma_stopped = 0;
dev_dbg(pcdev->soc_host.v4l2_dev.dev,
"%s : top queued buffer=%p, dma_stopped=%d\n",
__func__, pcdev->active, is_dma_stopped);
if (pcdev->active && is_dma_stopped)
pxa_camera_start_capture(pcdev);
}
static void pxa_camera_dma_irq(int channel, struct pxa_camera_dev *pcdev,
enum pxa_camera_active_dma act_dma)
{
struct device *dev = pcdev->soc_host.v4l2_dev.dev;
struct pxa_buffer *buf;
unsigned long flags;
u32 status, camera_status, overrun;
struct videobuf_buffer *vb;
spin_lock_irqsave(&pcdev->lock, flags);
status = DCSR(channel);
DCSR(channel) = status;
camera_status = __raw_readl(pcdev->base + CISR);
overrun = CISR_IFO_0;
if (pcdev->channels == 3)
overrun |= CISR_IFO_1 | CISR_IFO_2;
if (status & DCSR_BUSERR) {
dev_err(dev, "DMA Bus Error IRQ!\n");
goto out;
}
if (!(status & (DCSR_ENDINTR | DCSR_STARTINTR))) {
dev_err(dev, "Unknown DMA IRQ source, status: 0x%08x\n",
status);
goto out;
}
if (!pcdev->active)
goto out;
vb = &pcdev->active->vb;
buf = container_of(vb, struct pxa_buffer, vb);
WARN_ON(buf->inwork || list_empty(&vb->queue));
dev_dbg(dev, "%s channel=%d %s%s(vb=0x%p) dma.desc=%x\n",
__func__, channel, status & DCSR_STARTINTR ? "SOF " : "",
status & DCSR_ENDINTR ? "EOF " : "", vb, DDADR(channel));
if (status & DCSR_ENDINTR) {
if (camera_status & overrun &&
!list_is_last(pcdev->capture.next, &pcdev->capture)) {
dev_dbg(dev, "FIFO overrun! CISR: %x\n",
camera_status);
pxa_camera_stop_capture(pcdev);
pxa_camera_start_capture(pcdev);
goto out;
}
buf->active_dma &= ~act_dma;
if (!buf->active_dma) {
pxa_camera_wakeup(pcdev, vb, buf);
pxa_camera_check_link_miss(pcdev);
}
}
out:
spin_unlock_irqrestore(&pcdev->lock, flags);
}
static void pxa_camera_dma_irq_y(int channel, void *data)
{
struct pxa_camera_dev *pcdev = data;
pxa_camera_dma_irq(channel, pcdev, DMA_Y);
}
static void pxa_camera_dma_irq_u(int channel, void *data)
{
struct pxa_camera_dev *pcdev = data;
pxa_camera_dma_irq(channel, pcdev, DMA_U);
}
static void pxa_camera_dma_irq_v(int channel, void *data)
{
struct pxa_camera_dev *pcdev = data;
pxa_camera_dma_irq(channel, pcdev, DMA_V);
}
static void pxa_camera_init_videobuf(struct videobuf_queue *q,
struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
videobuf_queue_sg_init(q, &pxa_videobuf_ops, NULL, &pcdev->lock,
V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_NONE,
sizeof(struct pxa_buffer), icd, &ici->host_lock);
}
static u32 mclk_get_divisor(struct platform_device *pdev,
struct pxa_camera_dev *pcdev)
{
unsigned long mclk = pcdev->mclk;
struct device *dev = &pdev->dev;
u32 div;
unsigned long lcdclk;
lcdclk = clk_get_rate(pcdev->clk);
pcdev->ciclk = lcdclk;
if (mclk > lcdclk / 4) {
mclk = lcdclk / 4;
dev_warn(dev, "Limiting master clock to %lu\n", mclk);
}
div = (lcdclk + 2 * mclk - 1) / (2 * mclk) - 1;
if (pcdev->platform_flags & PXA_CAMERA_MCLK_EN)
pcdev->mclk = lcdclk / (2 * (div + 1));
dev_dbg(dev, "LCD clock %luHz, target freq %luHz, divisor %u\n",
lcdclk, mclk, div);
return div;
}
static void recalculate_fifo_timeout(struct pxa_camera_dev *pcdev,
unsigned long pclk)
{
u32 ciclk_per_pixel = pcdev->ciclk / pclk + 1;
__raw_writel(ciclk_per_pixel, pcdev->base + CITOR);
}
static void pxa_camera_activate(struct pxa_camera_dev *pcdev)
{
u32 cicr4 = 0;
__raw_writel(0x3ff, pcdev->base + CICR0);
if (pcdev->platform_flags & PXA_CAMERA_PCLK_EN)
cicr4 |= CICR4_PCLK_EN;
if (pcdev->platform_flags & PXA_CAMERA_MCLK_EN)
cicr4 |= CICR4_MCLK_EN;
if (pcdev->platform_flags & PXA_CAMERA_PCP)
cicr4 |= CICR4_PCP;
if (pcdev->platform_flags & PXA_CAMERA_HSP)
cicr4 |= CICR4_HSP;
if (pcdev->platform_flags & PXA_CAMERA_VSP)
cicr4 |= CICR4_VSP;
__raw_writel(pcdev->mclk_divisor | cicr4, pcdev->base + CICR4);
if (pcdev->platform_flags & PXA_CAMERA_MCLK_EN)
recalculate_fifo_timeout(pcdev, pcdev->mclk);
else
recalculate_fifo_timeout(pcdev, 13000000);
clk_prepare_enable(pcdev->clk);
}
static void pxa_camera_deactivate(struct pxa_camera_dev *pcdev)
{
clk_disable_unprepare(pcdev->clk);
}
static irqreturn_t pxa_camera_irq(int irq, void *data)
{
struct pxa_camera_dev *pcdev = data;
unsigned long status, cifr, cicr0;
struct pxa_buffer *buf;
struct videobuf_buffer *vb;
status = __raw_readl(pcdev->base + CISR);
dev_dbg(pcdev->soc_host.v4l2_dev.dev,
"Camera interrupt status 0x%lx\n", status);
if (!status)
return IRQ_NONE;
__raw_writel(status, pcdev->base + CISR);
if (status & CISR_EOF) {
cifr = __raw_readl(pcdev->base + CIFR) | CIFR_RESET_F;
__raw_writel(cifr, pcdev->base + CIFR);
pcdev->active = list_first_entry(&pcdev->capture,
struct pxa_buffer, vb.queue);
vb = &pcdev->active->vb;
buf = container_of(vb, struct pxa_buffer, vb);
pxa_videobuf_set_actdma(pcdev, buf);
pxa_dma_start_channels(pcdev);
cicr0 = __raw_readl(pcdev->base + CICR0) | CICR0_EOFM;
__raw_writel(cicr0, pcdev->base + CICR0);
}
return IRQ_HANDLED;
}
static int pxa_camera_add_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
if (pcdev->icd)
return -EBUSY;
pxa_camera_activate(pcdev);
pcdev->icd = icd;
dev_info(icd->parent, "PXA Camera driver attached to camera %d\n",
icd->devnum);
return 0;
}
static void pxa_camera_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
BUG_ON(icd != pcdev->icd);
dev_info(icd->parent, "PXA Camera driver detached from camera %d\n",
icd->devnum);
__raw_writel(0x3ff, pcdev->base + CICR0);
DCSR(pcdev->dma_chans[0]) = 0;
DCSR(pcdev->dma_chans[1]) = 0;
DCSR(pcdev->dma_chans[2]) = 0;
pxa_camera_deactivate(pcdev);
pcdev->icd = NULL;
}
static int test_platform_param(struct pxa_camera_dev *pcdev,
unsigned char buswidth, unsigned long *flags)
{
*flags = (pcdev->platform_flags & PXA_CAMERA_MASTER ?
V4L2_MBUS_MASTER : V4L2_MBUS_SLAVE) |
V4L2_MBUS_HSYNC_ACTIVE_HIGH |
V4L2_MBUS_HSYNC_ACTIVE_LOW |
V4L2_MBUS_VSYNC_ACTIVE_HIGH |
V4L2_MBUS_VSYNC_ACTIVE_LOW |
V4L2_MBUS_DATA_ACTIVE_HIGH |
V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_PCLK_SAMPLE_FALLING;
if ((1 << (buswidth - 1)) & pcdev->width_flags)
return 0;
return -EINVAL;
}
static void pxa_camera_setup_cicr(struct soc_camera_device *icd,
unsigned long flags, __u32 pixfmt)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
unsigned long dw, bpp;
u32 cicr0, cicr1, cicr2, cicr3, cicr4 = 0, y_skip_top;
int ret = v4l2_subdev_call(sd, sensor, g_skip_top_lines, &y_skip_top);
if (ret < 0)
y_skip_top = 0;
switch (icd->current_fmt->host_fmt->bits_per_sample) {
case 10:
dw = 4;
bpp = 0x40;
break;
case 9:
dw = 3;
bpp = 0x20;
break;
default:
case 8:
dw = 2;
bpp = 0;
}
if (pcdev->platform_flags & PXA_CAMERA_PCLK_EN)
cicr4 |= CICR4_PCLK_EN;
if (pcdev->platform_flags & PXA_CAMERA_MCLK_EN)
cicr4 |= CICR4_MCLK_EN;
if (flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)
cicr4 |= CICR4_PCP;
if (flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)
cicr4 |= CICR4_HSP;
if (flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)
cicr4 |= CICR4_VSP;
cicr0 = __raw_readl(pcdev->base + CICR0);
if (cicr0 & CICR0_ENB)
__raw_writel(cicr0 & ~CICR0_ENB, pcdev->base + CICR0);
cicr1 = CICR1_PPL_VAL(icd->user_width - 1) | bpp | dw;
switch (pixfmt) {
case V4L2_PIX_FMT_YUV422P:
pcdev->channels = 3;
cicr1 |= CICR1_YCBCR_F;
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_VYUY:
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_YVYU:
cicr1 |= CICR1_COLOR_SP_VAL(2);
break;
case V4L2_PIX_FMT_RGB555:
cicr1 |= CICR1_RGB_BPP_VAL(1) | CICR1_RGBT_CONV_VAL(2) |
CICR1_TBIT | CICR1_COLOR_SP_VAL(1);
break;
case V4L2_PIX_FMT_RGB565:
cicr1 |= CICR1_COLOR_SP_VAL(1) | CICR1_RGB_BPP_VAL(2);
break;
}
cicr2 = 0;
cicr3 = CICR3_LPF_VAL(icd->user_height - 1) |
CICR3_BFW_VAL(min((u32)255, y_skip_top));
cicr4 |= pcdev->mclk_divisor;
__raw_writel(cicr1, pcdev->base + CICR1);
__raw_writel(cicr2, pcdev->base + CICR2);
__raw_writel(cicr3, pcdev->base + CICR3);
__raw_writel(cicr4, pcdev->base + CICR4);
cicr0 = (cicr0 & CICR0_ENB) | (pcdev->platform_flags & PXA_CAMERA_MASTER ?
CICR0_SIM_MP : (CICR0_SL_CAP_EN | CICR0_SIM_SP));
cicr0 |= CICR0_DMAEN | CICR0_IRQ_MASK;
__raw_writel(cicr0, pcdev->base + CICR0);
}
static int pxa_camera_set_bus_param(struct soc_camera_device *icd)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
u32 pixfmt = icd->current_fmt->host_fmt->fourcc;
unsigned long bus_flags, common_flags;
int ret;
struct pxa_cam *cam = icd->host_priv;
ret = test_platform_param(pcdev, icd->current_fmt->host_fmt->bits_per_sample,
&bus_flags);
if (ret < 0)
return ret;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg,
bus_flags);
if (!common_flags) {
dev_warn(icd->parent,
"Flags incompatible: camera 0x%x, host 0x%lx\n",
cfg.flags, bus_flags);
return -EINVAL;
}
} else if (ret != -ENOIOCTLCMD) {
return ret;
} else {
common_flags = bus_flags;
}
pcdev->channels = 1;
if ((common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)) {
if (pcdev->platform_flags & PXA_CAMERA_HSP)
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)) {
if (pcdev->platform_flags & PXA_CAMERA_VSP)
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_PCLK_SAMPLE_RISING) &&
(common_flags & V4L2_MBUS_PCLK_SAMPLE_FALLING)) {
if (pcdev->platform_flags & PXA_CAMERA_PCP)
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
cam->flags = common_flags;
pxa_camera_setup_cicr(icd, common_flags, pixfmt);
return 0;
}
static int pxa_camera_try_bus_param(struct soc_camera_device *icd,
unsigned char buswidth)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct pxa_camera_dev *pcdev = ici->priv;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
unsigned long bus_flags, common_flags;
int ret = test_platform_param(pcdev, buswidth, &bus_flags);
if (ret < 0)
return ret;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg,
bus_flags);
if (!common_flags) {
dev_warn(icd->parent,
"Flags incompatible: camera 0x%x, host 0x%lx\n",
cfg.flags, bus_flags);
return -EINVAL;
}
} else if (ret == -ENOIOCTLCMD) {
ret = 0;
}
return ret;
}
static bool pxa_camera_packing_supported(const struct soc_mbus_pixelfmt *fmt)
{
return fmt->packing == SOC_MBUS_PACKING_NONE ||
(fmt->bits_per_sample == 8 &&
fmt->packing == SOC_MBUS_PACKING_2X8_PADHI) ||
(fmt->bits_per_sample > 8 &&
fmt->packing == SOC_MBUS_PACKING_EXTEND16);
}
static int pxa_camera_get_formats(struct soc_camera_device *icd, unsigned int idx,
struct soc_camera_format_xlate *xlate)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->parent;
int formats = 0, ret;
struct pxa_cam *cam;
enum v4l2_mbus_pixelcode code;
const struct soc_mbus_pixelfmt *fmt;
ret = v4l2_subdev_call(sd, video, enum_mbus_fmt, idx, &code);
if (ret < 0)
return 0;
fmt = soc_mbus_get_fmtdesc(code);
if (!fmt) {
dev_err(dev, "Invalid format code #%u: %d\n", idx, code);
return 0;
}
ret = pxa_camera_try_bus_param(icd, fmt->bits_per_sample);
if (ret < 0)
return 0;
if (!icd->host_priv) {
cam = kzalloc(sizeof(*cam), GFP_KERNEL);
if (!cam)
return -ENOMEM;
icd->host_priv = cam;
} else {
cam = icd->host_priv;
}
switch (code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
formats++;
if (xlate) {
xlate->host_fmt = &pxa_camera_formats[0];
xlate->code = code;
xlate++;
dev_dbg(dev, "Providing format %s using code %d\n",
pxa_camera_formats[0].name, code);
}
case V4L2_MBUS_FMT_VYUY8_2X8:
case V4L2_MBUS_FMT_YUYV8_2X8:
case V4L2_MBUS_FMT_YVYU8_2X8:
case V4L2_MBUS_FMT_RGB565_2X8_LE:
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE:
if (xlate)
dev_dbg(dev, "Providing format %s packed\n",
fmt->name);
break;
default:
if (!pxa_camera_packing_supported(fmt))
return 0;
if (xlate)
dev_dbg(dev,
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
static void pxa_camera_put_formats(struct soc_camera_device *icd)
{
kfree(icd->host_priv);
icd->host_priv = NULL;
}
static int pxa_camera_check_frame(u32 width, u32 height)
{
return height < 32 || height > 2048 || width < 48 || width > 2048 ||
(width & 0x01);
}
static int pxa_camera_set_crop(struct soc_camera_device *icd,
const struct v4l2_crop *a)
{
const struct v4l2_rect *rect = &a->c;
struct device *dev = icd->parent;
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct pxa_camera_dev *pcdev = ici->priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_sense sense = {
.master_clock = pcdev->mclk,
.pixel_clock_max = pcdev->ciclk / 4,
};
struct v4l2_mbus_framefmt mf;
struct pxa_cam *cam = icd->host_priv;
u32 fourcc = icd->current_fmt->host_fmt->fourcc;
int ret;
if (pcdev->platform_flags & PXA_CAMERA_PCLK_EN)
icd->sense = &sense;
ret = v4l2_subdev_call(sd, video, s_crop, a);
icd->sense = NULL;
if (ret < 0) {
dev_warn(dev, "Failed to crop to %ux%u@%u:%u\n",
rect->width, rect->height, rect->left, rect->top);
return ret;
}
ret = v4l2_subdev_call(sd, video, g_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (pxa_camera_check_frame(mf.width, mf.height)) {
v4l_bound_align_image(&mf.width, 48, 2048, 1,
&mf.height, 32, 2048, 0,
fourcc == V4L2_PIX_FMT_YUV422P ? 4 : 0);
ret = v4l2_subdev_call(sd, video, s_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (pxa_camera_check_frame(mf.width, mf.height)) {
dev_warn(icd->parent,
"Inconsistent state. Use S_FMT to repair\n");
return -EINVAL;
}
}
if (sense.flags & SOCAM_SENSE_PCLK_CHANGED) {
if (sense.pixel_clock > sense.pixel_clock_max) {
dev_err(dev,
"pixel clock %lu set by the camera too high!",
sense.pixel_clock);
return -EIO;
}
recalculate_fifo_timeout(pcdev, sense.pixel_clock);
}
icd->user_width = mf.width;
icd->user_height = mf.height;
pxa_camera_setup_cicr(icd, cam->flags, fourcc);
return ret;
}
static int pxa_camera_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct device *dev = icd->parent;
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct pxa_camera_dev *pcdev = ici->priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate = NULL;
struct soc_camera_sense sense = {
.master_clock = pcdev->mclk,
.pixel_clock_max = pcdev->ciclk / 4,
};
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd, pix->pixelformat);
if (!xlate) {
dev_warn(dev, "Format %x not found\n", pix->pixelformat);
return -EINVAL;
}
if (pcdev->platform_flags & PXA_CAMERA_PCLK_EN)
icd->sense = &sense;
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
ret = v4l2_subdev_call(sd, video, s_mbus_fmt, &mf);
if (mf.code != xlate->code)
return -EINVAL;
icd->sense = NULL;
if (ret < 0) {
dev_warn(dev, "Failed to configure for format %x\n",
pix->pixelformat);
} else if (pxa_camera_check_frame(mf.width, mf.height)) {
dev_warn(dev,
"Camera driver produced an unsupported frame %dx%d\n",
mf.width, mf.height);
ret = -EINVAL;
} else if (sense.flags & SOCAM_SENSE_PCLK_CHANGED) {
if (sense.pixel_clock > sense.pixel_clock_max) {
dev_err(dev,
"pixel clock %lu set by the camera too high!",
sense.pixel_clock);
return -EIO;
}
recalculate_fifo_timeout(pcdev, sense.pixel_clock);
}
if (ret < 0)
return ret;
pix->width = mf.width;
pix->height = mf.height;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
icd->current_fmt = xlate;
return ret;
}
static int pxa_camera_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
__u32 pixfmt = pix->pixelformat;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate) {
dev_warn(icd->parent, "Format %x not found\n", pixfmt);
return -EINVAL;
}
v4l_bound_align_image(&pix->width, 48, 2048, 1,
&pix->height, 32, 2048, 0,
pixfmt == V4L2_PIX_FMT_YUV422P ? 4 : 0);
mf.width = pix->width;
mf.height = pix->height;
mf.field = V4L2_FIELD_NONE;
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
case V4L2_FIELD_NONE:
pix->field = V4L2_FIELD_NONE;
break;
default:
dev_err(icd->parent, "Field type %d unsupported.\n",
mf.field);
return -EINVAL;
}
return ret;
}
static int pxa_camera_reqbufs(struct soc_camera_device *icd,
struct v4l2_requestbuffers *p)
{
int i;
for (i = 0; i < p->count; i++) {
struct pxa_buffer *buf = container_of(icd->vb_vidq.bufs[i],
struct pxa_buffer, vb);
buf->inwork = 0;
INIT_LIST_HEAD(&buf->vb.queue);
}
return 0;
}
static unsigned int pxa_camera_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
struct pxa_buffer *buf;
buf = list_entry(icd->vb_vidq.stream.next, struct pxa_buffer,
vb.stream);
poll_wait(file, &buf->vb.done, pt);
if (buf->vb.state == VIDEOBUF_DONE ||
buf->vb.state == VIDEOBUF_ERROR)
return POLLIN|POLLRDNORM;
return 0;
}
static int pxa_camera_querycap(struct soc_camera_host *ici,
struct v4l2_capability *cap)
{
strlcpy(cap->card, pxa_cam_driver_description, sizeof(cap->card));
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
return 0;
}
static int pxa_camera_suspend(struct device *dev)
{
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct pxa_camera_dev *pcdev = ici->priv;
int i = 0, ret = 0;
pcdev->save_cicr[i++] = __raw_readl(pcdev->base + CICR0);
pcdev->save_cicr[i++] = __raw_readl(pcdev->base + CICR1);
pcdev->save_cicr[i++] = __raw_readl(pcdev->base + CICR2);
pcdev->save_cicr[i++] = __raw_readl(pcdev->base + CICR3);
pcdev->save_cicr[i++] = __raw_readl(pcdev->base + CICR4);
if (pcdev->icd) {
struct v4l2_subdev *sd = soc_camera_to_subdev(pcdev->icd);
ret = v4l2_subdev_call(sd, core, s_power, 0);
if (ret == -ENOIOCTLCMD)
ret = 0;
}
return ret;
}
static int pxa_camera_resume(struct device *dev)
{
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct pxa_camera_dev *pcdev = ici->priv;
int i = 0, ret = 0;
DRCMR(68) = pcdev->dma_chans[0] | DRCMR_MAPVLD;
DRCMR(69) = pcdev->dma_chans[1] | DRCMR_MAPVLD;
DRCMR(70) = pcdev->dma_chans[2] | DRCMR_MAPVLD;
__raw_writel(pcdev->save_cicr[i++] & ~CICR0_ENB, pcdev->base + CICR0);
__raw_writel(pcdev->save_cicr[i++], pcdev->base + CICR1);
__raw_writel(pcdev->save_cicr[i++], pcdev->base + CICR2);
__raw_writel(pcdev->save_cicr[i++], pcdev->base + CICR3);
__raw_writel(pcdev->save_cicr[i++], pcdev->base + CICR4);
if (pcdev->icd) {
struct v4l2_subdev *sd = soc_camera_to_subdev(pcdev->icd);
ret = v4l2_subdev_call(sd, core, s_power, 1);
if (ret == -ENOIOCTLCMD)
ret = 0;
}
if (!ret && pcdev->active)
pxa_camera_start_capture(pcdev);
return ret;
}
static int pxa_camera_probe(struct platform_device *pdev)
{
struct pxa_camera_dev *pcdev;
struct resource *res;
void __iomem *base;
int irq;
int err = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || irq < 0)
return -ENODEV;
pcdev = devm_kzalloc(&pdev->dev, sizeof(*pcdev), GFP_KERNEL);
if (!pcdev) {
dev_err(&pdev->dev, "Could not allocate pcdev\n");
return -ENOMEM;
}
pcdev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pcdev->clk))
return PTR_ERR(pcdev->clk);
pcdev->res = res;
pcdev->pdata = pdev->dev.platform_data;
pcdev->platform_flags = pcdev->pdata->flags;
if (!(pcdev->platform_flags & (PXA_CAMERA_DATAWIDTH_8 |
PXA_CAMERA_DATAWIDTH_9 | PXA_CAMERA_DATAWIDTH_10))) {
dev_warn(&pdev->dev, "WARNING! Platform hasn't set available "
"data widths, using default 10 bit\n");
pcdev->platform_flags |= PXA_CAMERA_DATAWIDTH_10;
}
if (pcdev->platform_flags & PXA_CAMERA_DATAWIDTH_8)
pcdev->width_flags = 1 << 7;
if (pcdev->platform_flags & PXA_CAMERA_DATAWIDTH_9)
pcdev->width_flags |= 1 << 8;
if (pcdev->platform_flags & PXA_CAMERA_DATAWIDTH_10)
pcdev->width_flags |= 1 << 9;
pcdev->mclk = pcdev->pdata->mclk_10khz * 10000;
if (!pcdev->mclk) {
dev_warn(&pdev->dev,
"mclk == 0! Please, fix your platform data. "
"Using default 20MHz\n");
pcdev->mclk = 20000000;
}
pcdev->mclk_divisor = mclk_get_divisor(pdev, pcdev);
INIT_LIST_HEAD(&pcdev->capture);
spin_lock_init(&pcdev->lock);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
pcdev->irq = irq;
pcdev->base = base;
err = pxa_request_dma("CI_Y", DMA_PRIO_HIGH,
pxa_camera_dma_irq_y, pcdev);
if (err < 0) {
dev_err(&pdev->dev, "Can't request DMA for Y\n");
return err;
}
pcdev->dma_chans[0] = err;
dev_dbg(&pdev->dev, "got DMA channel %d\n", pcdev->dma_chans[0]);
err = pxa_request_dma("CI_U", DMA_PRIO_HIGH,
pxa_camera_dma_irq_u, pcdev);
if (err < 0) {
dev_err(&pdev->dev, "Can't request DMA for U\n");
goto exit_free_dma_y;
}
pcdev->dma_chans[1] = err;
dev_dbg(&pdev->dev, "got DMA channel (U) %d\n", pcdev->dma_chans[1]);
err = pxa_request_dma("CI_V", DMA_PRIO_HIGH,
pxa_camera_dma_irq_v, pcdev);
if (err < 0) {
dev_err(&pdev->dev, "Can't request DMA for V\n");
goto exit_free_dma_u;
}
pcdev->dma_chans[2] = err;
dev_dbg(&pdev->dev, "got DMA channel (V) %d\n", pcdev->dma_chans[2]);
DRCMR(68) = pcdev->dma_chans[0] | DRCMR_MAPVLD;
DRCMR(69) = pcdev->dma_chans[1] | DRCMR_MAPVLD;
DRCMR(70) = pcdev->dma_chans[2] | DRCMR_MAPVLD;
err = devm_request_irq(&pdev->dev, pcdev->irq, pxa_camera_irq, 0,
PXA_CAM_DRV_NAME, pcdev);
if (err) {
dev_err(&pdev->dev, "Camera interrupt register failed\n");
goto exit_free_dma;
}
pcdev->soc_host.drv_name = PXA_CAM_DRV_NAME;
pcdev->soc_host.ops = &pxa_soc_camera_host_ops;
pcdev->soc_host.priv = pcdev;
pcdev->soc_host.v4l2_dev.dev = &pdev->dev;
pcdev->soc_host.nr = pdev->id;
err = soc_camera_host_register(&pcdev->soc_host);
if (err)
goto exit_free_dma;
return 0;
exit_free_dma:
pxa_free_dma(pcdev->dma_chans[2]);
exit_free_dma_u:
pxa_free_dma(pcdev->dma_chans[1]);
exit_free_dma_y:
pxa_free_dma(pcdev->dma_chans[0]);
return err;
}
static int pxa_camera_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct pxa_camera_dev *pcdev = container_of(soc_host,
struct pxa_camera_dev, soc_host);
pxa_free_dma(pcdev->dma_chans[0]);
pxa_free_dma(pcdev->dma_chans[1]);
pxa_free_dma(pcdev->dma_chans[2]);
soc_camera_host_unregister(soc_host);
dev_info(&pdev->dev, "PXA Camera driver unloaded\n");
return 0;
}
