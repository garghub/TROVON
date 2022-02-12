static struct sh_mobile_ceu_buffer *to_ceu_vb(struct vb2_buffer *vb)
{
return container_of(vb, struct sh_mobile_ceu_buffer, vb);
}
static unsigned long make_bus_param(struct sh_mobile_ceu_dev *pcdev)
{
unsigned long flags;
flags = SOCAM_MASTER |
SOCAM_PCLK_SAMPLE_RISING |
SOCAM_HSYNC_ACTIVE_HIGH |
SOCAM_HSYNC_ACTIVE_LOW |
SOCAM_VSYNC_ACTIVE_HIGH |
SOCAM_VSYNC_ACTIVE_LOW |
SOCAM_DATA_ACTIVE_HIGH;
if (pcdev->pdata->flags & SH_CEU_FLAG_USE_8BIT_BUS)
flags |= SOCAM_DATAWIDTH_8;
if (pcdev->pdata->flags & SH_CEU_FLAG_USE_16BIT_BUS)
flags |= SOCAM_DATAWIDTH_16;
if (flags & SOCAM_DATAWIDTH_MASK)
return flags;
return 0;
}
static void ceu_write(struct sh_mobile_ceu_dev *priv,
unsigned long reg_offs, u32 data)
{
iowrite32(data, priv->base + reg_offs);
}
static u32 ceu_read(struct sh_mobile_ceu_dev *priv, unsigned long reg_offs)
{
return ioread32(priv->base + reg_offs);
}
static int sh_mobile_ceu_soft_reset(struct sh_mobile_ceu_dev *pcdev)
{
int i, success = 0;
struct soc_camera_device *icd = pcdev->icd;
ceu_write(pcdev, CAPSR, 1 << 16);
for (i = 0; i < 1000; i++) {
if (!(ceu_read(pcdev, CSTSR) & 1)) {
success++;
break;
}
udelay(1);
}
for (i = 0; i < 1000; i++) {
if (!(ceu_read(pcdev, CAPSR) & (1 << 16))) {
success++;
break;
}
udelay(1);
}
if (2 != success) {
dev_warn(&icd->dev, "soft reset time out\n");
return -EIO;
}
return 0;
}
static int sh_mobile_ceu_videobuf_setup(struct vb2_queue *vq,
unsigned int *count, unsigned int *num_planes,
unsigned long sizes[], void *alloc_ctxs[])
{
struct soc_camera_device *icd = container_of(vq, struct soc_camera_device, vb2_vidq);
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
int bytes_per_line = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
if (bytes_per_line < 0)
return bytes_per_line;
*num_planes = 1;
pcdev->sequence = 0;
sizes[0] = bytes_per_line * icd->user_height;
alloc_ctxs[0] = pcdev->alloc_ctx;
if (!*count)
*count = 2;
if (pcdev->video_limit) {
if (PAGE_ALIGN(sizes[0]) * *count > pcdev->video_limit)
*count = pcdev->video_limit / PAGE_ALIGN(sizes[0]);
}
dev_dbg(icd->dev.parent, "count=%d, size=%lu\n", *count, sizes[0]);
return 0;
}
static int sh_mobile_ceu_capture(struct sh_mobile_ceu_dev *pcdev)
{
struct soc_camera_device *icd = pcdev->icd;
dma_addr_t phys_addr_top, phys_addr_bottom;
unsigned long top1, top2;
unsigned long bottom1, bottom2;
u32 status;
int ret = 0;
ceu_write(pcdev, CEIER, ceu_read(pcdev, CEIER) & ~CEU_CEIER_MASK);
status = ceu_read(pcdev, CETCR);
ceu_write(pcdev, CETCR, ~status & CEU_CETCR_MAGIC);
if (!pcdev->frozen)
ceu_write(pcdev, CEIER, ceu_read(pcdev, CEIER) | CEU_CEIER_MASK);
ceu_write(pcdev, CAPCR, ceu_read(pcdev, CAPCR) & ~CEU_CAPCR_CTNCP);
ceu_write(pcdev, CETCR, CEU_CETCR_MAGIC ^ CEU_CETCR_IGRW);
if (status & CEU_CEIER_VBP) {
sh_mobile_ceu_soft_reset(pcdev);
ret = -EIO;
}
if (pcdev->frozen) {
complete(&pcdev->complete);
return ret;
}
if (!pcdev->active)
return ret;
if (V4L2_FIELD_INTERLACED_BT == pcdev->field) {
top1 = CDBYR;
top2 = CDBCR;
bottom1 = CDAYR;
bottom2 = CDACR;
} else {
top1 = CDAYR;
top2 = CDACR;
bottom1 = CDBYR;
bottom2 = CDBCR;
}
phys_addr_top = vb2_dma_contig_plane_paddr(pcdev->active, 0);
ceu_write(pcdev, top1, phys_addr_top);
if (V4L2_FIELD_NONE != pcdev->field) {
phys_addr_bottom = phys_addr_top + icd->user_width;
ceu_write(pcdev, bottom1, phys_addr_bottom);
}
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
phys_addr_top += icd->user_width *
icd->user_height;
ceu_write(pcdev, top2, phys_addr_top);
if (V4L2_FIELD_NONE != pcdev->field) {
phys_addr_bottom = phys_addr_top + icd->user_width;
ceu_write(pcdev, bottom2, phys_addr_bottom);
}
}
ceu_write(pcdev, CAPSR, 0x1);
return ret;
}
static int sh_mobile_ceu_videobuf_prepare(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = container_of(vb->vb2_queue, struct soc_camera_device, vb2_vidq);
struct sh_mobile_ceu_buffer *buf;
int bytes_per_line = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
unsigned long size;
if (bytes_per_line < 0)
return bytes_per_line;
buf = to_ceu_vb(vb);
dev_dbg(icd->dev.parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
WARN(!list_empty(&buf->queue), "Buffer %p on queue!\n", vb);
#ifdef DEBUG
if (vb2_plane_vaddr(vb, 0))
memset(vb2_plane_vaddr(vb, 0), 0xaa, vb2_get_plane_payload(vb, 0));
#endif
BUG_ON(NULL == icd->current_fmt);
size = icd->user_height * bytes_per_line;
if (vb2_plane_size(vb, 0) < size) {
dev_err(icd->dev.parent, "Buffer too small (%lu < %lu)\n",
vb2_plane_size(vb, 0), size);
return -ENOBUFS;
}
vb2_set_plane_payload(vb, 0, size);
return 0;
}
static void sh_mobile_ceu_videobuf_queue(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = container_of(vb->vb2_queue, struct soc_camera_device, vb2_vidq);
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct sh_mobile_ceu_buffer *buf = to_ceu_vb(vb);
dev_dbg(icd->dev.parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
spin_lock_irq(&pcdev->lock);
list_add_tail(&buf->queue, &pcdev->capture);
if (!pcdev->active) {
pcdev->active = vb;
sh_mobile_ceu_capture(pcdev);
}
spin_unlock_irq(&pcdev->lock);
}
static void sh_mobile_ceu_videobuf_release(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = container_of(vb->vb2_queue, struct soc_camera_device, vb2_vidq);
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_buffer *buf = to_ceu_vb(vb);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
spin_lock_irq(&pcdev->lock);
if (pcdev->active == vb) {
ceu_write(pcdev, CAPSR, 1 << 16);
pcdev->active = NULL;
}
list_del_init(&buf->queue);
spin_unlock_irq(&pcdev->lock);
}
static int sh_mobile_ceu_videobuf_init(struct vb2_buffer *vb)
{
INIT_LIST_HEAD(&to_ceu_vb(vb)->queue);
return 0;
}
static int sh_mobile_ceu_stop_streaming(struct vb2_queue *q)
{
struct soc_camera_device *icd = container_of(q, struct soc_camera_device, vb2_vidq);
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct list_head *buf_head, *tmp;
spin_lock_irq(&pcdev->lock);
pcdev->active = NULL;
list_for_each_safe(buf_head, tmp, &pcdev->capture)
list_del_init(buf_head);
spin_unlock_irq(&pcdev->lock);
return sh_mobile_ceu_soft_reset(pcdev);
}
static irqreturn_t sh_mobile_ceu_irq(int irq, void *data)
{
struct sh_mobile_ceu_dev *pcdev = data;
struct vb2_buffer *vb;
int ret;
spin_lock(&pcdev->lock);
vb = pcdev->active;
if (!vb)
goto out;
list_del_init(&to_ceu_vb(vb)->queue);
if (!list_empty(&pcdev->capture))
pcdev->active = &list_entry(pcdev->capture.next,
struct sh_mobile_ceu_buffer, queue)->vb;
else
pcdev->active = NULL;
ret = sh_mobile_ceu_capture(pcdev);
do_gettimeofday(&vb->v4l2_buf.timestamp);
if (!ret) {
vb->v4l2_buf.field = pcdev->field;
vb->v4l2_buf.sequence = pcdev->sequence++;
}
vb2_buffer_done(vb, ret < 0 ? VB2_BUF_STATE_ERROR : VB2_BUF_STATE_DONE);
out:
spin_unlock(&pcdev->lock);
return IRQ_HANDLED;
}
static int sh_mobile_ceu_add_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
int ret;
if (pcdev->icd)
return -EBUSY;
dev_info(icd->dev.parent,
"SuperH Mobile CEU driver attached to camera %d\n",
icd->devnum);
pm_runtime_get_sync(ici->v4l2_dev.dev);
ret = sh_mobile_ceu_soft_reset(pcdev);
if (!ret)
pcdev->icd = icd;
return ret;
}
static void sh_mobile_ceu_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
BUG_ON(icd != pcdev->icd);
ceu_write(pcdev, CEIER, 0);
sh_mobile_ceu_soft_reset(pcdev);
spin_lock_irq(&pcdev->lock);
if (pcdev->active) {
list_del_init(&to_ceu_vb(pcdev->active)->queue);
vb2_buffer_done(pcdev->active, VB2_BUF_STATE_ERROR);
pcdev->active = NULL;
}
spin_unlock_irq(&pcdev->lock);
pm_runtime_put_sync(ici->v4l2_dev.dev);
dev_info(icd->dev.parent,
"SuperH Mobile CEU driver detached from camera %d\n",
icd->devnum);
pcdev->icd = NULL;
}
static unsigned int size_dst(unsigned int src, unsigned int scale)
{
unsigned int mant_pre = scale >> 12;
if (!src || !scale)
return src;
return ((mant_pre + 2 * (src - 1)) / (2 * mant_pre) - 1) *
mant_pre * 4096 / scale + 1;
}
static u16 calc_scale(unsigned int src, unsigned int *dst)
{
u16 scale;
if (src == *dst)
return 0;
scale = (src * 4096 / *dst) & ~7;
while (scale > 4096 && size_dst(src, scale) < *dst)
scale -= 8;
*dst = size_dst(src, scale);
return scale;
}
static void sh_mobile_ceu_set_rect(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct sh_mobile_ceu_dev *pcdev = ici->priv;
unsigned int height, width, cdwdr_width, in_width, in_height;
unsigned int left_offset, top_offset;
u32 camor;
dev_geo(icd->dev.parent, "Crop %ux%u@%u:%u\n",
icd->user_width, icd->user_height, cam->ceu_left, cam->ceu_top);
left_offset = cam->ceu_left;
top_offset = cam->ceu_top;
if (pcdev->image_mode) {
in_width = cam->width;
if (!pcdev->is_16bit) {
in_width *= 2;
left_offset *= 2;
}
width = icd->user_width;
cdwdr_width = icd->user_width;
} else {
int bytes_per_line = soc_mbus_bytes_per_line(icd->user_width,
icd->current_fmt->host_fmt);
unsigned int w_factor;
width = icd->user_width;
switch (icd->current_fmt->host_fmt->packing) {
case SOC_MBUS_PACKING_2X8_PADHI:
w_factor = 2;
break;
default:
w_factor = 1;
}
in_width = cam->width * w_factor;
left_offset = left_offset * w_factor;
if (bytes_per_line < 0)
cdwdr_width = icd->user_width;
else
cdwdr_width = bytes_per_line;
}
height = icd->user_height;
in_height = cam->height;
if (V4L2_FIELD_NONE != pcdev->field) {
height /= 2;
in_height /= 2;
top_offset /= 2;
cdwdr_width *= 2;
}
if (pcdev->pdata->csi2_dev) {
in_width = ((in_width - 2) * 2);
left_offset *= 2;
}
camor = left_offset | (top_offset << 16);
dev_geo(icd->dev.parent,
"CAMOR 0x%x, CAPWR 0x%x, CFSZR 0x%x, CDWDR 0x%x\n", camor,
(in_height << 16) | in_width, (height << 16) | width,
cdwdr_width);
ceu_write(pcdev, CAMOR, camor);
ceu_write(pcdev, CAPWR, (in_height << 16) | in_width);
ceu_write(pcdev, CFSZR, (height << 16) | width);
ceu_write(pcdev, CDWDR, cdwdr_width);
}
static u32 capture_save_reset(struct sh_mobile_ceu_dev *pcdev)
{
u32 capsr = ceu_read(pcdev, CAPSR);
ceu_write(pcdev, CAPSR, 1 << 16);
return capsr;
}
static void capture_restore(struct sh_mobile_ceu_dev *pcdev, u32 capsr)
{
unsigned long timeout = jiffies + 10 * HZ;
while ((ceu_read(pcdev, CSTSR) & 1) && time_before(jiffies, timeout))
msleep(1);
if (time_after(jiffies, timeout)) {
dev_err(pcdev->ici.v4l2_dev.dev,
"Timeout waiting for frame end! Interface problem?\n");
return;
}
while (ceu_read(pcdev, CAPSR) & (1 << 16))
udelay(10);
if (capsr & ~(1 << 16))
ceu_write(pcdev, CAPSR, capsr);
}
static int sh_mobile_ceu_set_bus_param(struct soc_camera_device *icd,
__u32 pixfmt)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
int ret;
unsigned long camera_flags, common_flags, value;
int yuv_lineskip;
struct sh_mobile_ceu_cam *cam = icd->host_priv;
u32 capsr = capture_save_reset(pcdev);
camera_flags = icd->ops->query_bus_param(icd);
common_flags = soc_camera_bus_param_compatible(camera_flags,
make_bus_param(pcdev));
if (!common_flags)
return -EINVAL;
if ((common_flags & SOCAM_HSYNC_ACTIVE_HIGH) &&
(common_flags & SOCAM_HSYNC_ACTIVE_LOW)) {
if (pcdev->pdata->flags & SH_CEU_FLAG_HSYNC_LOW)
common_flags &= ~SOCAM_HSYNC_ACTIVE_HIGH;
else
common_flags &= ~SOCAM_HSYNC_ACTIVE_LOW;
}
if ((common_flags & SOCAM_VSYNC_ACTIVE_HIGH) &&
(common_flags & SOCAM_VSYNC_ACTIVE_LOW)) {
if (pcdev->pdata->flags & SH_CEU_FLAG_VSYNC_LOW)
common_flags &= ~SOCAM_VSYNC_ACTIVE_HIGH;
else
common_flags &= ~SOCAM_VSYNC_ACTIVE_LOW;
}
ret = icd->ops->set_bus_param(icd, common_flags);
if (ret < 0)
return ret;
switch (common_flags & SOCAM_DATAWIDTH_MASK) {
case SOCAM_DATAWIDTH_8:
pcdev->is_16bit = 0;
break;
case SOCAM_DATAWIDTH_16:
pcdev->is_16bit = 1;
break;
default:
return -EINVAL;
}
ceu_write(pcdev, CRCNTR, 0);
ceu_write(pcdev, CRCMPR, 0);
value = 0x00000010;
yuv_lineskip = 0;
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
yuv_lineskip = 1;
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
switch (cam->code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
value = 0x00000000;
break;
case V4L2_MBUS_FMT_VYUY8_2X8:
value = 0x00000100;
break;
case V4L2_MBUS_FMT_YUYV8_2X8:
value = 0x00000200;
break;
case V4L2_MBUS_FMT_YVYU8_2X8:
value = 0x00000300;
break;
default:
BUG();
}
}
if (icd->current_fmt->host_fmt->fourcc == V4L2_PIX_FMT_NV21 ||
icd->current_fmt->host_fmt->fourcc == V4L2_PIX_FMT_NV61)
value ^= 0x00000100;
value |= common_flags & SOCAM_VSYNC_ACTIVE_LOW ? 1 << 1 : 0;
value |= common_flags & SOCAM_HSYNC_ACTIVE_LOW ? 1 << 0 : 0;
value |= pcdev->is_16bit ? 1 << 12 : 0;
if (pcdev->pdata->csi2_dev)
value |= 3 << 12;
ceu_write(pcdev, CAMCR, value);
ceu_write(pcdev, CAPCR, 0x00300000);
switch (pcdev->field) {
case V4L2_FIELD_INTERLACED_TB:
value = 0x101;
break;
case V4L2_FIELD_INTERLACED_BT:
value = 0x102;
break;
default:
value = 0;
break;
}
ceu_write(pcdev, CAIFR, value);
sh_mobile_ceu_set_rect(icd);
mdelay(1);
dev_geo(icd->dev.parent, "CFLCR 0x%x\n", pcdev->cflcr);
ceu_write(pcdev, CFLCR, pcdev->cflcr);
value = 0x00000017;
if (yuv_lineskip)
value &= ~0x00000010;
ceu_write(pcdev, CDOCR, value);
ceu_write(pcdev, CFWCR, 0);
dev_dbg(icd->dev.parent, "S_FMT successful for %c%c%c%c %ux%u\n",
pixfmt & 0xff, (pixfmt >> 8) & 0xff,
(pixfmt >> 16) & 0xff, (pixfmt >> 24) & 0xff,
icd->user_width, icd->user_height);
capture_restore(pcdev, capsr);
return 0;
}
static int sh_mobile_ceu_try_bus_param(struct soc_camera_device *icd,
unsigned char buswidth)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
unsigned long camera_flags, common_flags;
camera_flags = icd->ops->query_bus_param(icd);
common_flags = soc_camera_bus_param_compatible(camera_flags,
make_bus_param(pcdev));
if (!common_flags || buswidth > 16 ||
(buswidth > 8 && !(common_flags & SOCAM_DATAWIDTH_16)))
return -EINVAL;
return 0;
}
static bool sh_mobile_ceu_packing_supported(const struct soc_mbus_pixelfmt *fmt)
{
return fmt->packing == SOC_MBUS_PACKING_NONE ||
(fmt->bits_per_sample == 8 &&
fmt->packing == SOC_MBUS_PACKING_2X8_PADHI) ||
(fmt->bits_per_sample > 8 &&
fmt->packing == SOC_MBUS_PACKING_EXTEND16);
}
static int sh_mobile_ceu_get_formats(struct soc_camera_device *icd, unsigned int idx,
struct soc_camera_format_xlate *xlate)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->dev.parent;
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
int ret, k, n;
int formats = 0;
struct sh_mobile_ceu_cam *cam;
enum v4l2_mbus_pixelcode code;
const struct soc_mbus_pixelfmt *fmt;
ret = v4l2_subdev_call(sd, video, enum_mbus_fmt, idx, &code);
if (ret < 0)
return 0;
fmt = soc_mbus_get_fmtdesc(code);
if (!fmt) {
dev_warn(dev, "unsupported format code #%u: %d\n", idx, code);
return 0;
}
if (!pcdev->pdata->csi2_dev) {
ret = sh_mobile_ceu_try_bus_param(icd, fmt->bits_per_sample);
if (ret < 0)
return 0;
}
if (!icd->host_priv) {
struct v4l2_mbus_framefmt mf;
struct v4l2_rect rect;
int shift = 0;
ret = client_g_rect(sd, &rect);
if (ret < 0)
return ret;
ret = v4l2_subdev_call(sd, video, g_mbus_fmt, &mf);
if (ret < 0)
return ret;
while ((mf.width > 2560 || mf.height > 1920) && shift < 4) {
mf.width = 2560 >> shift;
mf.height = 1920 >> shift;
ret = v4l2_device_call_until_err(sd->v4l2_dev, (long)icd, video,
s_mbus_fmt, &mf);
if (ret < 0)
return ret;
shift++;
}
if (shift == 4) {
dev_err(dev, "Failed to configure the client below %ux%x\n",
mf.width, mf.height);
return -EIO;
}
dev_geo(dev, "camera fmt %ux%u\n", mf.width, mf.height);
cam = kzalloc(sizeof(*cam), GFP_KERNEL);
if (!cam)
return -ENOMEM;
cam->rect = rect;
cam->subrect = rect;
cam->width = mf.width;
cam->height = mf.height;
cam->width = mf.width;
cam->height = mf.height;
icd->host_priv = cam;
} else {
cam = icd->host_priv;
}
if (!idx)
cam->extra_fmt = NULL;
switch (code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
case V4L2_MBUS_FMT_VYUY8_2X8:
case V4L2_MBUS_FMT_YUYV8_2X8:
case V4L2_MBUS_FMT_YVYU8_2X8:
if (cam->extra_fmt)
break;
cam->extra_fmt = sh_mobile_ceu_formats;
n = ARRAY_SIZE(sh_mobile_ceu_formats);
formats += n;
for (k = 0; xlate && k < n; k++) {
xlate->host_fmt = &sh_mobile_ceu_formats[k];
xlate->code = code;
xlate++;
dev_dbg(dev, "Providing format %s using code %d\n",
sh_mobile_ceu_formats[k].name, code);
}
break;
default:
if (!sh_mobile_ceu_packing_supported(fmt))
return 0;
}
formats++;
if (xlate) {
xlate->host_fmt = fmt;
xlate->code = code;
xlate++;
dev_dbg(dev, "Providing format %s in pass-through mode\n",
fmt->name);
}
return formats;
}
static void sh_mobile_ceu_put_formats(struct soc_camera_device *icd)
{
kfree(icd->host_priv);
icd->host_priv = NULL;
}
static bool is_smaller(struct v4l2_rect *r1, struct v4l2_rect *r2)
{
return r1->width < r2->width || r1->height < r2->height;
}
static bool is_inside(struct v4l2_rect *r1, struct v4l2_rect *r2)
{
return r1->left > r2->left || r1->top > r2->top ||
r1->left + r1->width < r2->left + r2->width ||
r1->top + r1->height < r2->top + r2->height;
}
static unsigned int scale_down(unsigned int size, unsigned int scale)
{
return (size * 4096 + scale / 2) / scale;
}
static unsigned int calc_generic_scale(unsigned int input, unsigned int output)
{
return (input * 4096 + output / 2) / output;
}
static int client_g_rect(struct v4l2_subdev *sd, struct v4l2_rect *rect)
{
struct v4l2_crop crop;
struct v4l2_cropcap cap;
int ret;
crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
ret = v4l2_subdev_call(sd, video, g_crop, &crop);
if (!ret) {
*rect = crop.c;
return ret;
}
cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
ret = v4l2_subdev_call(sd, video, cropcap, &cap);
if (!ret)
*rect = cap.defrect;
return ret;
}
static void update_subrect(struct sh_mobile_ceu_cam *cam)
{
struct v4l2_rect *rect = &cam->rect, *subrect = &cam->subrect;
if (rect->width < subrect->width)
subrect->width = rect->width;
if (rect->height < subrect->height)
subrect->height = rect->height;
if (rect->left > subrect->left)
subrect->left = rect->left;
else if (rect->left + rect->width >
subrect->left + subrect->width)
subrect->left = rect->left + rect->width -
subrect->width;
if (rect->top > subrect->top)
subrect->top = rect->top;
else if (rect->top + rect->height >
subrect->top + subrect->height)
subrect->top = rect->top + rect->height -
subrect->height;
}
static int client_s_crop(struct soc_camera_device *icd, struct v4l2_crop *crop,
struct v4l2_crop *cam_crop)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_rect *rect = &crop->c, *cam_rect = &cam_crop->c;
struct device *dev = sd->v4l2_dev->dev;
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_cropcap cap;
int ret;
unsigned int width, height;
v4l2_subdev_call(sd, video, s_crop, crop);
ret = client_g_rect(sd, cam_rect);
if (ret < 0)
return ret;
if (!memcmp(rect, cam_rect, sizeof(*rect))) {
dev_dbg(dev, "Camera S_CROP successful for %dx%d@%d:%d\n",
rect->width, rect->height, rect->left, rect->top);
cam->rect = *cam_rect;
return 0;
}
dev_geo(dev, "Fix camera S_CROP for %dx%d@%d:%d to %dx%d@%d:%d\n",
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top,
rect->width, rect->height, rect->left, rect->top);
ret = v4l2_subdev_call(sd, video, cropcap, &cap);
if (ret < 0)
return ret;
soc_camera_limit_side(&rect->left, &rect->width, cap.bounds.left, 2,
cap.bounds.width);
soc_camera_limit_side(&rect->top, &rect->height, cap.bounds.top, 4,
cap.bounds.height);
width = max(cam_rect->width, 2);
height = max(cam_rect->height, 2);
while (!ret && (is_smaller(cam_rect, rect) ||
is_inside(cam_rect, rect)) &&
(cap.bounds.width > width || cap.bounds.height > height)) {
width *= 2;
height *= 2;
cam_rect->width = width;
cam_rect->height = height;
if (cam_rect->left > rect->left)
cam_rect->left = cap.bounds.left;
if (cam_rect->left + cam_rect->width < rect->left + rect->width)
cam_rect->width = rect->left + rect->width -
cam_rect->left;
if (cam_rect->top > rect->top)
cam_rect->top = cap.bounds.top;
if (cam_rect->top + cam_rect->height < rect->top + rect->height)
cam_rect->height = rect->top + rect->height -
cam_rect->top;
v4l2_subdev_call(sd, video, s_crop, cam_crop);
ret = client_g_rect(sd, cam_rect);
dev_geo(dev, "Camera S_CROP %d for %dx%d@%d:%d\n", ret,
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
}
if (is_smaller(cam_rect, rect) || is_inside(cam_rect, rect)) {
*cam_rect = cap.bounds;
v4l2_subdev_call(sd, video, s_crop, cam_crop);
ret = client_g_rect(sd, cam_rect);
dev_geo(dev, "Camera S_CROP %d for max %dx%d@%d:%d\n", ret,
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
}
if (!ret) {
cam->rect = *cam_rect;
update_subrect(cam);
}
return ret;
}
static int client_s_fmt(struct soc_camera_device *icd,
struct v4l2_mbus_framefmt *mf, bool ceu_can_scale)
{
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->dev.parent;
unsigned int width = mf->width, height = mf->height, tmp_w, tmp_h;
unsigned int max_width, max_height;
struct v4l2_cropcap cap;
int ret;
ret = v4l2_device_call_until_err(sd->v4l2_dev, (long)icd, video,
s_mbus_fmt, mf);
if (ret < 0)
return ret;
dev_geo(dev, "camera scaled to %ux%u\n", mf->width, mf->height);
if ((width == mf->width && height == mf->height) || !ceu_can_scale)
goto update_cache;
cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
ret = v4l2_subdev_call(sd, video, cropcap, &cap);
if (ret < 0)
return ret;
max_width = min(cap.bounds.width, 2560);
max_height = min(cap.bounds.height, 1920);
tmp_w = mf->width;
tmp_h = mf->height;
while ((width > tmp_w || height > tmp_h) &&
tmp_w < max_width && tmp_h < max_height) {
tmp_w = min(2 * tmp_w, max_width);
tmp_h = min(2 * tmp_h, max_height);
mf->width = tmp_w;
mf->height = tmp_h;
ret = v4l2_device_call_until_err(sd->v4l2_dev, (long)icd, video,
s_mbus_fmt, mf);
dev_geo(dev, "Camera scaled to %ux%u\n",
mf->width, mf->height);
if (ret < 0) {
dev_err(dev, "Client failed to set format: %d\n", ret);
return ret;
}
}
update_cache:
ret = client_g_rect(sd, &cam->rect);
if (ret < 0)
return ret;
update_subrect(cam);
return 0;
}
static int client_scale(struct soc_camera_device *icd,
struct v4l2_mbus_framefmt *mf,
unsigned int *width, unsigned int *height,
bool ceu_can_scale)
{
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct device *dev = icd->dev.parent;
struct v4l2_mbus_framefmt mf_tmp = *mf;
unsigned int scale_h, scale_v;
int ret;
ret = client_s_fmt(icd, &mf_tmp, ceu_can_scale);
if (ret < 0)
return ret;
dev_geo(dev, "5: camera scaled to %ux%u\n",
mf_tmp.width, mf_tmp.height);
scale_h = calc_generic_scale(cam->rect.width, mf_tmp.width);
scale_v = calc_generic_scale(cam->rect.height, mf_tmp.height);
mf->width = mf_tmp.width;
mf->height = mf_tmp.height;
mf->colorspace = mf_tmp.colorspace;
*width = scale_down(cam->subrect.width, scale_h);
*height = scale_down(cam->subrect.height, scale_v);
dev_geo(dev, "8: new client sub-window %ux%u\n", *width, *height);
return 0;
}
static int sh_mobile_ceu_set_crop(struct soc_camera_device *icd,
struct v4l2_crop *a)
{
struct v4l2_rect *rect = &a->c;
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct v4l2_crop cam_crop;
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_rect *cam_rect = &cam_crop.c;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->dev.parent;
struct v4l2_mbus_framefmt mf;
unsigned int scale_cam_h, scale_cam_v, scale_ceu_h, scale_ceu_v,
out_width, out_height;
int interm_width, interm_height;
u32 capsr, cflcr;
int ret;
dev_geo(dev, "S_CROP(%ux%u@%u:%u)\n", rect->width, rect->height,
rect->left, rect->top);
capsr = capture_save_reset(pcdev);
dev_dbg(dev, "CAPSR 0x%x, CFLCR 0x%x\n", capsr, pcdev->cflcr);
ret = client_s_crop(icd, a, &cam_crop);
if (ret < 0)
return ret;
dev_geo(dev, "1-2: camera cropped to %ux%u@%u:%u\n",
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
ret = v4l2_subdev_call(sd, video, g_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (mf.width > 2560 || mf.height > 1920)
return -EINVAL;
scale_cam_h = calc_generic_scale(cam_rect->width, mf.width);
scale_cam_v = calc_generic_scale(cam_rect->height, mf.height);
interm_width = scale_down(rect->width, scale_cam_h);
interm_height = scale_down(rect->height, scale_cam_v);
if (interm_width < icd->user_width) {
u32 new_scale_h;
new_scale_h = calc_generic_scale(rect->width, icd->user_width);
mf.width = scale_down(cam_rect->width, new_scale_h);
}
if (interm_height < icd->user_height) {
u32 new_scale_v;
new_scale_v = calc_generic_scale(rect->height, icd->user_height);
mf.height = scale_down(cam_rect->height, new_scale_v);
}
if (interm_width < icd->user_width || interm_height < icd->user_height) {
ret = v4l2_device_call_until_err(sd->v4l2_dev, (int)icd, video,
s_mbus_fmt, &mf);
if (ret < 0)
return ret;
dev_geo(dev, "New camera output %ux%u\n", mf.width, mf.height);
scale_cam_h = calc_generic_scale(cam_rect->width, mf.width);
scale_cam_v = calc_generic_scale(cam_rect->height, mf.height);
interm_width = scale_down(rect->width, scale_cam_h);
interm_height = scale_down(rect->height, scale_cam_v);
}
cam->width = mf.width;
cam->height = mf.height;
if (pcdev->image_mode) {
out_width = min(interm_width, icd->user_width);
out_height = min(interm_height, icd->user_height);
} else {
out_width = interm_width;
out_height = interm_height;
}
scale_ceu_h = calc_scale(interm_width, &out_width);
scale_ceu_v = calc_scale(interm_height, &out_height);
dev_geo(dev, "5: CEU scales %u:%u\n", scale_ceu_h, scale_ceu_v);
cflcr = scale_ceu_h | (scale_ceu_v << 16);
if (cflcr != pcdev->cflcr) {
pcdev->cflcr = cflcr;
ceu_write(pcdev, CFLCR, cflcr);
}
icd->user_width = out_width;
icd->user_height = out_height;
cam->ceu_left = scale_down(rect->left - cam_rect->left, scale_cam_h) & ~1;
cam->ceu_top = scale_down(rect->top - cam_rect->top, scale_cam_v) & ~1;
sh_mobile_ceu_set_rect(icd);
cam->subrect = *rect;
dev_geo(dev, "6: CEU cropped to %ux%u@%u:%u\n",
icd->user_width, icd->user_height,
cam->ceu_left, cam->ceu_top);
if (pcdev->active)
capsr |= 1;
capture_restore(pcdev, capsr);
return ret;
}
static int sh_mobile_ceu_get_crop(struct soc_camera_device *icd,
struct v4l2_crop *a)
{
struct sh_mobile_ceu_cam *cam = icd->host_priv;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->c = cam->subrect;
return 0;
}
static void calculate_client_output(struct soc_camera_device *icd,
struct v4l2_pix_format *pix, struct v4l2_mbus_framefmt *mf)
{
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct device *dev = icd->dev.parent;
struct v4l2_rect *cam_subrect = &cam->subrect;
unsigned int scale_v, scale_h;
if (cam_subrect->width == cam->rect.width &&
cam_subrect->height == cam->rect.height) {
mf->width = pix->width;
mf->height = pix->height;
return;
}
dev_geo(dev, "2: subwin %ux%u@%u:%u\n",
cam_subrect->width, cam_subrect->height,
cam_subrect->left, cam_subrect->top);
scale_h = calc_generic_scale(cam_subrect->width, pix->width);
scale_v = calc_generic_scale(cam_subrect->height, pix->height);
dev_geo(dev, "3: scales %u:%u\n", scale_h, scale_v);
mf->width = scale_down(cam->rect.width, scale_h);
mf->height = scale_down(cam->rect.height, scale_v);
}
static int sh_mobile_ceu_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
struct device *dev = icd->dev.parent;
__u32 pixfmt = pix->pixelformat;
const struct soc_camera_format_xlate *xlate;
unsigned int ceu_sub_width = 0, ceu_sub_height = 0;
u16 scale_v, scale_h;
int ret;
bool image_mode;
enum v4l2_field field;
dev_geo(dev, "S_FMT(pix=0x%x, %ux%u)\n", pixfmt, pix->width, pix->height);
switch (pix->field) {
default:
pix->field = V4L2_FIELD_NONE;
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
case V4L2_FIELD_NONE:
field = pix->field;
break;
case V4L2_FIELD_INTERLACED:
field = V4L2_FIELD_INTERLACED_TB;
break;
}
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate) {
dev_warn(dev, "Format %x not found\n", pixfmt);
return -EINVAL;
}
calculate_client_output(icd, &f->fmt.pix, &mf);
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
switch (pixfmt) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
image_mode = true;
break;
default:
image_mode = false;
}
dev_geo(dev, "4: request camera output %ux%u\n", mf.width, mf.height);
ret = client_scale(icd, &mf, &ceu_sub_width, &ceu_sub_height,
image_mode && V4L2_FIELD_NONE == field);
dev_geo(dev, "5-9: client scale return %d\n", ret);
dev_geo(dev, "fmt %ux%u, requested %ux%u\n",
mf.width, mf.height, pix->width, pix->height);
if (ret < 0)
return ret;
if (mf.code != xlate->code)
return -EINVAL;
cam->width = mf.width;
cam->height = mf.height;
if (pix->width > ceu_sub_width)
ceu_sub_width = pix->width;
if (pix->height > ceu_sub_height)
ceu_sub_height = pix->height;
pix->colorspace = mf.colorspace;
if (image_mode) {
scale_h = calc_scale(ceu_sub_width, &pix->width);
scale_v = calc_scale(ceu_sub_height, &pix->height);
} else {
pix->width = ceu_sub_width;
pix->height = ceu_sub_height;
scale_h = 0;
scale_v = 0;
}
pcdev->cflcr = scale_h | (scale_v << 16);
dev_geo(dev, "10: W: %u : 0x%x = %u, H: %u : 0x%x = %u\n",
ceu_sub_width, scale_h, pix->width,
ceu_sub_height, scale_v, pix->height);
cam->code = xlate->code;
icd->current_fmt = xlate;
pcdev->field = field;
pcdev->image_mode = image_mode;
return 0;
}
static int sh_mobile_ceu_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_framefmt mf;
__u32 pixfmt = pix->pixelformat;
int width, height;
int ret;
dev_geo(icd->dev.parent, "TRY_FMT(pix=0x%x, %ux%u)\n",
pixfmt, pix->width, pix->height);
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate) {
dev_warn(icd->dev.parent, "Format %x not found\n", pixfmt);
return -EINVAL;
}
v4l_bound_align_image(&pix->width, 2, 2560, 1,
&pix->height, 4, 1920, 2, 0);
width = pix->width;
height = pix->height;
pix->bytesperline = soc_mbus_bytes_per_line(width, xlate->host_fmt);
if ((int)pix->bytesperline < 0)
return pix->bytesperline;
pix->sizeimage = height * pix->bytesperline;
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.code = xlate->code;
mf.colorspace = pix->colorspace;
ret = v4l2_device_call_until_err(sd->v4l2_dev, (long)icd, video, try_mbus_fmt, &mf);
if (ret < 0)
return ret;
pix->width = mf.width;
pix->height = mf.height;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
switch (pixfmt) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
if (pix->width < width || pix->height < height) {
mf.width = 2560;
mf.height = 1920;
ret = v4l2_device_call_until_err(sd->v4l2_dev, (long)icd, video,
try_mbus_fmt, &mf);
if (ret < 0) {
dev_err(icd->dev.parent,
"FIXME: client try_fmt() = %d\n", ret);
return ret;
}
}
if (mf.width > width)
pix->width = width;
if (mf.height > height)
pix->height = height;
}
dev_geo(icd->dev.parent, "%s(): return %d, fmt 0x%x, %ux%u\n",
__func__, ret, pix->pixelformat, pix->width, pix->height);
return ret;
}
static int sh_mobile_ceu_set_livecrop(struct soc_camera_device *icd,
struct v4l2_crop *a)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
u32 out_width = icd->user_width, out_height = icd->user_height;
int ret;
pcdev->frozen = 1;
ret = wait_for_completion_interruptible(&pcdev->complete);
ret = v4l2_subdev_call(sd, video, s_stream, 0);
if (ret < 0)
dev_warn(icd->dev.parent,
"Client failed to stop the stream: %d\n", ret);
else
sh_mobile_ceu_set_crop(icd, a);
dev_geo(icd->dev.parent, "Output after crop: %ux%u\n", icd->user_width, icd->user_height);
if (icd->user_width != out_width || icd->user_height != out_height) {
struct v4l2_format f = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
.fmt.pix = {
.width = out_width,
.height = out_height,
.pixelformat = icd->current_fmt->host_fmt->fourcc,
.field = pcdev->field,
.colorspace = icd->colorspace,
},
};
ret = sh_mobile_ceu_set_fmt(icd, &f);
if (!ret && (out_width != f.fmt.pix.width ||
out_height != f.fmt.pix.height))
ret = -EINVAL;
if (!ret) {
icd->user_width = out_width;
icd->user_height = out_height;
ret = sh_mobile_ceu_set_bus_param(icd,
icd->current_fmt->host_fmt->fourcc);
}
}
pcdev->frozen = 0;
spin_lock_irq(&pcdev->lock);
sh_mobile_ceu_capture(pcdev);
spin_unlock_irq(&pcdev->lock);
ret = v4l2_subdev_call(sd, video, s_stream, 1);
return ret;
}
static unsigned int sh_mobile_ceu_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
return vb2_poll(&icd->vb2_vidq, file, pt);
}
static int sh_mobile_ceu_querycap(struct soc_camera_host *ici,
struct v4l2_capability *cap)
{
strlcpy(cap->card, "SuperH_Mobile_CEU", sizeof(cap->card));
cap->version = KERNEL_VERSION(0, 0, 5);
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
return 0;
}
static int sh_mobile_ceu_init_videobuf(struct vb2_queue *q,
struct soc_camera_device *icd)
{
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->drv_priv = icd;
q->ops = &sh_mobile_ceu_videobuf_ops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct sh_mobile_ceu_buffer);
return vb2_queue_init(q);
}
static int sh_mobile_ceu_get_ctrl(struct soc_camera_device *icd,
struct v4l2_control *ctrl)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
u32 val;
switch (ctrl->id) {
case V4L2_CID_SHARPNESS:
val = ceu_read(pcdev, CLFCR);
ctrl->value = val ^ 1;
return 0;
}
return -ENOIOCTLCMD;
}
static int sh_mobile_ceu_set_ctrl(struct soc_camera_device *icd,
struct v4l2_control *ctrl)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->dev.parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
switch (ctrl->id) {
case V4L2_CID_SHARPNESS:
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
ceu_write(pcdev, CLFCR, !ctrl->value);
return 0;
}
return -EINVAL;
}
return -ENOIOCTLCMD;
}
static int bus_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct device *dev = data;
struct bus_wait *wait = container_of(nb, struct bus_wait, notifier);
if (wait->dev != dev)
return NOTIFY_DONE;
switch (action) {
case BUS_NOTIFY_UNBOUND_DRIVER:
wait_for_completion(&wait->completion);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static int __devinit sh_mobile_ceu_probe(struct platform_device *pdev)
{
struct sh_mobile_ceu_dev *pcdev;
struct resource *res;
void __iomem *base;
unsigned int irq;
int err = 0;
struct bus_wait wait = {
.completion = COMPLETION_INITIALIZER_ONSTACK(wait.completion),
.notifier.notifier_call = bus_notify,
};
struct device *csi2;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || (int)irq <= 0) {
dev_err(&pdev->dev, "Not enough CEU platform resources.\n");
err = -ENODEV;
goto exit;
}
pcdev = kzalloc(sizeof(*pcdev), GFP_KERNEL);
if (!pcdev) {
dev_err(&pdev->dev, "Could not allocate pcdev\n");
err = -ENOMEM;
goto exit;
}
INIT_LIST_HEAD(&pcdev->capture);
spin_lock_init(&pcdev->lock);
init_completion(&pcdev->complete);
pcdev->pdata = pdev->dev.platform_data;
if (!pcdev->pdata) {
err = -EINVAL;
dev_err(&pdev->dev, "CEU platform data not set.\n");
goto exit_kfree;
}
base = ioremap_nocache(res->start, resource_size(res));
if (!base) {
err = -ENXIO;
dev_err(&pdev->dev, "Unable to ioremap CEU registers.\n");
goto exit_kfree;
}
pcdev->irq = irq;
pcdev->base = base;
pcdev->video_limit = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res) {
err = dma_declare_coherent_memory(&pdev->dev, res->start,
res->start,
resource_size(res),
DMA_MEMORY_MAP |
DMA_MEMORY_EXCLUSIVE);
if (!err) {
dev_err(&pdev->dev, "Unable to declare CEU memory.\n");
err = -ENXIO;
goto exit_iounmap;
}
pcdev->video_limit = resource_size(res);
}
err = request_irq(pcdev->irq, sh_mobile_ceu_irq, IRQF_DISABLED,
dev_name(&pdev->dev), pcdev);
if (err) {
dev_err(&pdev->dev, "Unable to register CEU interrupt.\n");
goto exit_release_mem;
}
pm_suspend_ignore_children(&pdev->dev, true);
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
pcdev->ici.priv = pcdev;
pcdev->ici.v4l2_dev.dev = &pdev->dev;
pcdev->ici.nr = pdev->id;
pcdev->ici.drv_name = dev_name(&pdev->dev);
pcdev->ici.ops = &sh_mobile_ceu_host_ops;
csi2 = pcdev->pdata->csi2_dev;
if (csi2) {
wait.dev = csi2;
err = bus_register_notifier(&platform_bus_type, &wait.notifier);
if (err < 0)
goto exit_free_clk;
if (!csi2->driver) {
complete(&wait.completion);
bus_unregister_notifier(&platform_bus_type, &wait.notifier);
err = -ENXIO;
goto exit_free_clk;
}
err = try_module_get(csi2->driver->owner);
complete(&wait.completion);
bus_unregister_notifier(&platform_bus_type, &wait.notifier);
if (!err) {
err = -ENODEV;
goto exit_free_clk;
}
}
pcdev->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(pcdev->alloc_ctx)) {
err = PTR_ERR(pcdev->alloc_ctx);
goto exit_module_put;
}
err = soc_camera_host_register(&pcdev->ici);
if (err)
goto exit_free_ctx;
return 0;
exit_free_ctx:
vb2_dma_contig_cleanup_ctx(pcdev->alloc_ctx);
exit_module_put:
if (csi2 && csi2->driver)
module_put(csi2->driver->owner);
exit_free_clk:
pm_runtime_disable(&pdev->dev);
free_irq(pcdev->irq, pcdev);
exit_release_mem:
if (platform_get_resource(pdev, IORESOURCE_MEM, 1))
dma_release_declared_memory(&pdev->dev);
exit_iounmap:
iounmap(base);
exit_kfree:
kfree(pcdev);
exit:
return err;
}
static int __devexit sh_mobile_ceu_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct sh_mobile_ceu_dev *pcdev = container_of(soc_host,
struct sh_mobile_ceu_dev, ici);
struct device *csi2 = pcdev->pdata->csi2_dev;
soc_camera_host_unregister(soc_host);
pm_runtime_disable(&pdev->dev);
free_irq(pcdev->irq, pcdev);
if (platform_get_resource(pdev, IORESOURCE_MEM, 1))
dma_release_declared_memory(&pdev->dev);
iounmap(pcdev->base);
vb2_dma_contig_cleanup_ctx(pcdev->alloc_ctx);
if (csi2 && csi2->driver)
module_put(csi2->driver->owner);
kfree(pcdev);
return 0;
}
static int sh_mobile_ceu_runtime_nop(struct device *dev)
{
return 0;
}
static int __init sh_mobile_ceu_init(void)
{
request_module("sh_mobile_csi2");
return platform_driver_register(&sh_mobile_ceu_driver);
}
static void __exit sh_mobile_ceu_exit(void)
{
platform_driver_unregister(&sh_mobile_ceu_driver);
}
