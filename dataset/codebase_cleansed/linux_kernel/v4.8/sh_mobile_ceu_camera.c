static struct sh_mobile_ceu_buffer *to_ceu_vb(struct vb2_v4l2_buffer *vbuf)
{
return container_of(vbuf, struct sh_mobile_ceu_buffer, vb);
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
dev_warn(pcdev->ici.v4l2_dev.dev, "soft reset time out\n");
return -EIO;
}
return 0;
}
static int sh_mobile_ceu_videobuf_setup(struct vb2_queue *vq,
unsigned int *count, unsigned int *num_planes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
if (!vq->num_buffers)
pcdev->sequence = 0;
if (!*count)
*count = 2;
if (!*num_planes)
sizes[0] = icd->sizeimage;
else if (sizes[0] < icd->sizeimage)
return -EINVAL;
if (pcdev->video_limit) {
size_t size = PAGE_ALIGN(sizes[0]) * *count;
if (size + pcdev->buf_total > pcdev->video_limit)
*count = (pcdev->video_limit - pcdev->buf_total) /
PAGE_ALIGN(sizes[0]);
}
*num_planes = 1;
dev_dbg(icd->parent, "count=%d, size=%u\n", *count, sizes[0]);
return 0;
}
static int sh_mobile_ceu_capture(struct sh_mobile_ceu_dev *pcdev)
{
struct soc_camera_device *icd = pcdev->ici.icd;
dma_addr_t phys_addr_top, phys_addr_bottom;
unsigned long top1, top2;
unsigned long bottom1, bottom2;
u32 status;
bool planar;
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
phys_addr_top =
vb2_dma_contig_plane_dma_addr(&pcdev->active->vb2_buf, 0);
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
planar = true;
break;
default:
planar = false;
}
ceu_write(pcdev, top1, phys_addr_top);
if (V4L2_FIELD_NONE != pcdev->field) {
phys_addr_bottom = phys_addr_top + icd->bytesperline;
ceu_write(pcdev, bottom1, phys_addr_bottom);
}
if (planar) {
phys_addr_top += icd->bytesperline * icd->user_height;
ceu_write(pcdev, top2, phys_addr_top);
if (V4L2_FIELD_NONE != pcdev->field) {
phys_addr_bottom = phys_addr_top + icd->bytesperline;
ceu_write(pcdev, bottom2, phys_addr_bottom);
}
}
ceu_write(pcdev, CAPSR, 0x1);
return ret;
}
static int sh_mobile_ceu_videobuf_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct sh_mobile_ceu_buffer *buf = to_ceu_vb(vbuf);
WARN(!list_empty(&buf->queue), "Buffer %p on queue!\n", vb);
return 0;
}
static void sh_mobile_ceu_videobuf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct sh_mobile_ceu_buffer *buf = to_ceu_vb(vbuf);
unsigned long size;
size = icd->sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(icd->parent, "Buffer #%d too small (%lu < %lu)\n",
vb->index, vb2_plane_size(vb, 0), size);
goto error;
}
vb2_set_plane_payload(vb, 0, size);
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
#ifdef DEBUG
if (vb2_plane_vaddr(vb, 0))
memset(vb2_plane_vaddr(vb, 0), 0xaa, vb2_get_plane_payload(vb, 0));
#endif
spin_lock_irq(&pcdev->lock);
list_add_tail(&buf->queue, &pcdev->capture);
if (!pcdev->active) {
pcdev->active = vbuf;
sh_mobile_ceu_capture(pcdev);
}
spin_unlock_irq(&pcdev->lock);
return;
error:
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
static void sh_mobile_ceu_videobuf_release(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_buffer *buf = to_ceu_vb(vbuf);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
spin_lock_irq(&pcdev->lock);
if (pcdev->active == vbuf) {
ceu_write(pcdev, CAPSR, 1 << 16);
pcdev->active = NULL;
}
if (buf->queue.next)
list_del_init(&buf->queue);
pcdev->buf_total -= PAGE_ALIGN(vb2_plane_size(vb, 0));
dev_dbg(icd->parent, "%s() %zu bytes buffers\n", __func__,
pcdev->buf_total);
spin_unlock_irq(&pcdev->lock);
}
static int sh_mobile_ceu_videobuf_init(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
pcdev->buf_total += PAGE_ALIGN(vb2_plane_size(vb, 0));
dev_dbg(icd->parent, "%s() %zu bytes buffers\n", __func__,
pcdev->buf_total);
INIT_LIST_HEAD(&to_ceu_vb(vbuf)->queue);
return 0;
}
static void sh_mobile_ceu_stop_streaming(struct vb2_queue *q)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(q);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct list_head *buf_head, *tmp;
spin_lock_irq(&pcdev->lock);
pcdev->active = NULL;
list_for_each_safe(buf_head, tmp, &pcdev->capture)
list_del_init(buf_head);
spin_unlock_irq(&pcdev->lock);
sh_mobile_ceu_soft_reset(pcdev);
}
static irqreturn_t sh_mobile_ceu_irq(int irq, void *data)
{
struct sh_mobile_ceu_dev *pcdev = data;
struct vb2_v4l2_buffer *vbuf;
int ret;
spin_lock(&pcdev->lock);
vbuf = pcdev->active;
if (!vbuf)
goto out;
list_del_init(&to_ceu_vb(vbuf)->queue);
if (!list_empty(&pcdev->capture))
pcdev->active = &list_entry(pcdev->capture.next,
struct sh_mobile_ceu_buffer, queue)->vb;
else
pcdev->active = NULL;
ret = sh_mobile_ceu_capture(pcdev);
vbuf->vb2_buf.timestamp = ktime_get_ns();
if (!ret) {
vbuf->field = pcdev->field;
vbuf->sequence = pcdev->sequence++;
}
vb2_buffer_done(&vbuf->vb2_buf,
ret < 0 ? VB2_BUF_STATE_ERROR : VB2_BUF_STATE_DONE);
out:
spin_unlock(&pcdev->lock);
return IRQ_HANDLED;
}
static struct v4l2_subdev *find_csi2(struct sh_mobile_ceu_dev *pcdev)
{
struct v4l2_subdev *sd;
if (pcdev->csi2_sd)
return pcdev->csi2_sd;
if (pcdev->csi2_asd) {
char name[] = "sh-mobile-csi2";
v4l2_device_for_each_subdev(sd, &pcdev->ici.v4l2_dev)
if (!strncmp(name, sd->name, sizeof(name) - 1)) {
pcdev->csi2_sd = sd;
return sd;
}
}
return NULL;
}
static struct v4l2_subdev *csi2_subdev(struct sh_mobile_ceu_dev *pcdev,
struct soc_camera_device *icd)
{
struct v4l2_subdev *sd = pcdev->csi2_sd;
return sd && sd->grp_id == soc_camera_grp_id(icd) ? sd : NULL;
}
static int sh_mobile_ceu_add_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct v4l2_subdev *csi2_sd = find_csi2(pcdev);
int ret;
if (csi2_sd) {
csi2_sd->grp_id = soc_camera_grp_id(icd);
v4l2_set_subdev_hostdata(csi2_sd, icd);
}
ret = v4l2_subdev_call(csi2_sd, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD && ret != -ENODEV)
return ret;
if (csi2_sd && ret == -ENODEV)
csi2_sd->grp_id = 0;
dev_info(icd->parent,
"SuperH Mobile CEU%s driver attached to camera %d\n",
csi2_sd && csi2_sd->grp_id ? "/CSI-2" : "", icd->devnum);
return 0;
}
static void sh_mobile_ceu_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct v4l2_subdev *csi2_sd = find_csi2(pcdev);
dev_info(icd->parent,
"SuperH Mobile CEU driver detached from camera %d\n",
icd->devnum);
v4l2_subdev_call(csi2_sd, core, s_power, 0);
}
static int sh_mobile_ceu_clock_start(struct soc_camera_host *ici)
{
struct sh_mobile_ceu_dev *pcdev = ici->priv;
pm_runtime_get_sync(ici->v4l2_dev.dev);
pcdev->buf_total = 0;
sh_mobile_ceu_soft_reset(pcdev);
return 0;
}
static void sh_mobile_ceu_clock_stop(struct soc_camera_host *ici)
{
struct sh_mobile_ceu_dev *pcdev = ici->priv;
ceu_write(pcdev, CEIER, 0);
sh_mobile_ceu_soft_reset(pcdev);
spin_lock_irq(&pcdev->lock);
if (pcdev->active) {
list_del_init(&to_ceu_vb(pcdev->active)->queue);
vb2_buffer_done(&pcdev->active->vb2_buf, VB2_BUF_STATE_ERROR);
pcdev->active = NULL;
}
spin_unlock_irq(&pcdev->lock);
pm_runtime_put(ici->v4l2_dev.dev);
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
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct sh_mobile_ceu_dev *pcdev = ici->priv;
unsigned int height, width, cdwdr_width, in_width, in_height;
unsigned int left_offset, top_offset;
u32 camor;
dev_geo(icd->parent, "Crop %ux%u@%u:%u\n",
icd->user_width, icd->user_height, cam->ceu_left, cam->ceu_top);
left_offset = cam->ceu_left;
top_offset = cam->ceu_top;
WARN_ON(icd->user_width & 3 || icd->user_height & 3);
width = icd->user_width;
if (pcdev->image_mode) {
in_width = cam->width;
if (!pcdev->is_16bit) {
in_width *= 2;
left_offset *= 2;
}
} else {
unsigned int w_factor;
switch (icd->current_fmt->host_fmt->packing) {
case SOC_MBUS_PACKING_2X8_PADHI:
w_factor = 2;
break;
default:
w_factor = 1;
}
in_width = cam->width * w_factor;
left_offset *= w_factor;
}
cdwdr_width = icd->bytesperline;
height = icd->user_height;
in_height = cam->height;
if (V4L2_FIELD_NONE != pcdev->field) {
height = (height / 2) & ~3;
in_height /= 2;
top_offset /= 2;
cdwdr_width *= 2;
}
if (csi2_subdev(pcdev, icd)) {
in_width = ((in_width - 2) * 2);
left_offset *= 2;
}
camor = left_offset | (top_offset << 16);
dev_geo(icd->parent,
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
static struct v4l2_subdev *find_bus_subdev(struct sh_mobile_ceu_dev *pcdev,
struct soc_camera_device *icd)
{
return csi2_subdev(pcdev, icd) ? : soc_camera_to_subdev(icd);
}
static int sh_mobile_ceu_set_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct v4l2_subdev *sd = find_bus_subdev(pcdev, icd);
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
unsigned long value, common_flags = CEU_BUS_FLAGS;
u32 capsr = capture_save_reset(pcdev);
unsigned int yuv_lineskip;
int ret;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg,
common_flags);
if (!common_flags)
return -EINVAL;
} else if (ret != -ENOIOCTLCMD) {
return ret;
}
if ((common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)) {
if (pcdev->flags & SH_CEU_FLAG_HSYNC_LOW)
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)) {
if (pcdev->flags & SH_CEU_FLAG_VSYNC_LOW)
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_LOW;
}
cfg.flags = common_flags;
ret = v4l2_subdev_call(sd, video, s_mbus_config, &cfg);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
if (icd->current_fmt->host_fmt->bits_per_sample > 8)
pcdev->is_16bit = 1;
else
pcdev->is_16bit = 0;
ceu_write(pcdev, CRCNTR, 0);
ceu_write(pcdev, CRCMPR, 0);
value = 0x00000010;
yuv_lineskip = 0x10;
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
yuv_lineskip = 0;
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
switch (cam->code) {
case MEDIA_BUS_FMT_UYVY8_2X8:
value = 0x00000000;
break;
case MEDIA_BUS_FMT_VYUY8_2X8:
value = 0x00000100;
break;
case MEDIA_BUS_FMT_YUYV8_2X8:
value = 0x00000200;
break;
case MEDIA_BUS_FMT_YVYU8_2X8:
value = 0x00000300;
break;
default:
BUG();
}
}
if (icd->current_fmt->host_fmt->fourcc == V4L2_PIX_FMT_NV21 ||
icd->current_fmt->host_fmt->fourcc == V4L2_PIX_FMT_NV61)
value ^= 0x00000100;
value |= common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW ? 1 << 1 : 0;
value |= common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW ? 1 << 0 : 0;
if (csi2_subdev(pcdev, icd))
value |= 3 << 12;
else if (pcdev->is_16bit)
value |= 1 << 12;
else if (pcdev->flags & SH_CEU_FLAG_LOWER_8BIT)
value |= 2 << 12;
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
dev_geo(icd->parent, "CFLCR 0x%x\n", pcdev->cflcr);
ceu_write(pcdev, CFLCR, pcdev->cflcr);
value = 0x00000007 | yuv_lineskip;
ceu_write(pcdev, CDOCR, value);
ceu_write(pcdev, CFWCR, 0);
capture_restore(pcdev, capsr);
return 0;
}
static int sh_mobile_ceu_try_bus_param(struct soc_camera_device *icd,
unsigned char buswidth)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct v4l2_subdev *sd = find_bus_subdev(pcdev, icd);
unsigned long common_flags = CEU_BUS_FLAGS;
struct v4l2_mbus_config cfg = {.type = V4L2_MBUS_PARALLEL,};
int ret;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret)
common_flags = soc_mbus_config_compatible(&cfg,
common_flags);
else if (ret != -ENOIOCTLCMD)
return ret;
if (!common_flags || buswidth > 16)
return -EINVAL;
return 0;
}
static bool sh_mobile_ceu_packing_supported(const struct soc_mbus_pixelfmt *fmt)
{
return fmt->packing == SOC_MBUS_PACKING_NONE ||
(fmt->bits_per_sample == 8 &&
fmt->packing == SOC_MBUS_PACKING_1_5X8) ||
(fmt->bits_per_sample == 8 &&
fmt->packing == SOC_MBUS_PACKING_2X8_PADHI) ||
(fmt->bits_per_sample > 8 &&
fmt->packing == SOC_MBUS_PACKING_EXTEND16);
}
static struct soc_camera_device *ctrl_to_icd(struct v4l2_ctrl *ctrl)
{
return container_of(ctrl->handler, struct soc_camera_device,
ctrl_handler);
}
static int sh_mobile_ceu_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct soc_camera_device *icd = ctrl_to_icd(ctrl);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
switch (ctrl->id) {
case V4L2_CID_SHARPNESS:
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
ceu_write(pcdev, CLFCR, !ctrl->val);
return 0;
}
break;
}
return -EINVAL;
}
static int sh_mobile_ceu_get_formats(struct soc_camera_device *icd, unsigned int idx,
struct soc_camera_format_xlate *xlate)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->parent;
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
int ret, k, n;
int formats = 0;
struct sh_mobile_ceu_cam *cam;
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
dev_warn(dev, "unsupported format code #%u: %d\n", idx, code.code);
return 0;
}
if (!csi2_subdev(pcdev, icd)) {
ret = sh_mobile_ceu_try_bus_param(icd, fmt->bits_per_sample);
if (ret < 0)
return 0;
}
if (!icd->host_priv) {
struct v4l2_subdev_format fmt = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
struct v4l2_mbus_framefmt *mf = &fmt.format;
struct v4l2_rect rect;
int shift = 0;
v4l2_ctrl_new_std(&icd->ctrl_handler, &sh_mobile_ceu_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 1, 1, 1);
if (icd->ctrl_handler.error)
return icd->ctrl_handler.error;
ret = soc_camera_client_g_rect(sd, &rect);
if (ret < 0)
return ret;
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL, &fmt);
if (ret < 0)
return ret;
while ((mf->width > pcdev->max_width ||
mf->height > pcdev->max_height) && shift < 4) {
mf->width = 2560 >> shift;
mf->height = 1920 >> shift;
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd), pad,
set_fmt, NULL, &fmt);
if (ret < 0)
return ret;
shift++;
}
if (shift == 4) {
dev_err(dev, "Failed to configure the client below %ux%x\n",
mf->width, mf->height);
return -EIO;
}
dev_geo(dev, "camera fmt %ux%u\n", mf->width, mf->height);
cam = kzalloc(sizeof(*cam), GFP_KERNEL);
if (!cam)
return -ENOMEM;
cam->rect = rect;
cam->subrect = rect;
cam->width = mf->width;
cam->height = mf->height;
icd->host_priv = cam;
} else {
cam = icd->host_priv;
}
if (!idx)
cam->extra_fmt = NULL;
switch (code.code) {
case MEDIA_BUS_FMT_UYVY8_2X8:
case MEDIA_BUS_FMT_VYUY8_2X8:
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_YVYU8_2X8:
if (cam->extra_fmt)
break;
cam->extra_fmt = sh_mobile_ceu_formats;
n = ARRAY_SIZE(sh_mobile_ceu_formats);
formats += n;
for (k = 0; xlate && k < n; k++) {
xlate->host_fmt = &sh_mobile_ceu_formats[k];
xlate->code = code.code;
xlate++;
dev_dbg(dev, "Providing format %s using code %d\n",
sh_mobile_ceu_formats[k].name, code.code);
}
break;
default:
if (!sh_mobile_ceu_packing_supported(fmt))
return 0;
}
formats++;
if (xlate) {
xlate->host_fmt = fmt;
xlate->code = code.code;
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
static int sh_mobile_ceu_set_crop(struct soc_camera_device *icd,
const struct v4l2_crop *a)
{
struct v4l2_crop a_writable = *a;
const struct v4l2_rect *rect = &a_writable.c;
struct device *dev = icd->parent;
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct v4l2_crop cam_crop;
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_rect *cam_rect = &cam_crop.c;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_subdev_format fmt = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
struct v4l2_mbus_framefmt *mf = &fmt.format;
unsigned int scale_cam_h, scale_cam_v, scale_ceu_h, scale_ceu_v,
out_width, out_height;
int interm_width, interm_height;
u32 capsr, cflcr;
int ret;
dev_geo(dev, "S_CROP(%ux%u@%u:%u)\n", rect->width, rect->height,
rect->left, rect->top);
capsr = capture_save_reset(pcdev);
dev_dbg(dev, "CAPSR 0x%x, CFLCR 0x%x\n", capsr, pcdev->cflcr);
ret = soc_camera_client_s_crop(sd, &a_writable, &cam_crop,
&cam->rect, &cam->subrect);
if (ret < 0)
return ret;
dev_geo(dev, "1-2: camera cropped to %ux%u@%u:%u\n",
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL, &fmt);
if (ret < 0)
return ret;
if (mf->width > pcdev->max_width || mf->height > pcdev->max_height)
return -EINVAL;
scale_cam_h = calc_generic_scale(cam_rect->width, mf->width);
scale_cam_v = calc_generic_scale(cam_rect->height, mf->height);
interm_width = scale_down(rect->width, scale_cam_h);
interm_height = scale_down(rect->height, scale_cam_v);
if (interm_width < icd->user_width) {
u32 new_scale_h;
new_scale_h = calc_generic_scale(rect->width, icd->user_width);
mf->width = scale_down(cam_rect->width, new_scale_h);
}
if (interm_height < icd->user_height) {
u32 new_scale_v;
new_scale_v = calc_generic_scale(rect->height, icd->user_height);
mf->height = scale_down(cam_rect->height, new_scale_v);
}
if (interm_width < icd->user_width || interm_height < icd->user_height) {
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd), pad,
set_fmt, NULL, &fmt);
if (ret < 0)
return ret;
dev_geo(dev, "New camera output %ux%u\n", mf->width, mf->height);
scale_cam_h = calc_generic_scale(cam_rect->width, mf->width);
scale_cam_v = calc_generic_scale(cam_rect->height, mf->height);
interm_width = scale_down(rect->width, scale_cam_h);
interm_height = scale_down(rect->height, scale_cam_v);
}
cam->width = mf->width;
cam->height = mf->height;
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
icd->user_width = out_width & ~3;
icd->user_height = out_height & ~3;
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
static int sh_mobile_ceu_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct device *dev = icd->parent;
struct soc_camera_host *ici = to_soc_camera_host(dev);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
struct sh_mobile_ceu_cam *cam = icd->host_priv;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
__u32 pixfmt = pix->pixelformat;
const struct soc_camera_format_xlate *xlate;
unsigned int ceu_sub_width = pcdev->max_width,
ceu_sub_height = pcdev->max_height;
u16 scale_v, scale_h;
int ret;
bool image_mode;
enum v4l2_field field;
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
soc_camera_calc_client_output(icd, &cam->rect, &cam->subrect, pix, &mf, 12);
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
dev_geo(dev, "S_FMT(pix=0x%x, fld 0x%x, code 0x%x, %ux%u)\n", pixfmt, mf.field, mf.code,
pix->width, pix->height);
dev_geo(dev, "4: request camera output %ux%u\n", mf.width, mf.height);
ret = soc_camera_client_scale(icd, &cam->rect, &cam->subrect,
&mf, &ceu_sub_width, &ceu_sub_height,
image_mode && V4L2_FIELD_NONE == field, 12);
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
pix->width &= ~3;
pix->height &= ~3;
return 0;
}
static int sh_mobile_ceu_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_subdev_pad_config pad_cfg;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_TRY,
};
struct v4l2_mbus_framefmt *mf = &format.format;
__u32 pixfmt = pix->pixelformat;
int width, height;
int ret;
dev_geo(icd->parent, "TRY_FMT(pix=0x%x, %ux%u)\n",
pixfmt, pix->width, pix->height);
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate) {
xlate = icd->current_fmt;
dev_dbg(icd->parent, "Format %x not found, keeping %x\n",
pixfmt, xlate->host_fmt->fourcc);
pixfmt = xlate->host_fmt->fourcc;
pix->pixelformat = pixfmt;
pix->colorspace = icd->colorspace;
}
v4l_bound_align_image(&pix->width, 2, pcdev->max_width, 2,
&pix->height, 4, pcdev->max_height, 2, 0);
width = pix->width;
height = pix->height;
mf->width = pix->width;
mf->height = pix->height;
mf->field = pix->field;
mf->code = xlate->code;
mf->colorspace = pix->colorspace;
ret = v4l2_device_call_until_err(sd->v4l2_dev, soc_camera_grp_id(icd),
pad, set_fmt, &pad_cfg, &format);
if (ret < 0)
return ret;
pix->width = mf->width;
pix->height = mf->height;
pix->field = mf->field;
pix->colorspace = mf->colorspace;
switch (pixfmt) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV21:
case V4L2_PIX_FMT_NV16:
case V4L2_PIX_FMT_NV61:
if (pix->width < width || pix->height < height) {
mf->width = pcdev->max_width;
mf->height = pcdev->max_height;
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd), pad,
set_fmt, &pad_cfg, &format);
if (ret < 0) {
dev_err(icd->parent,
"FIXME: client try_fmt() = %d\n", ret);
return ret;
}
}
if (mf->width > width)
pix->width = width;
if (mf->height > height)
pix->height = height;
pix->bytesperline = max(pix->bytesperline, pix->width);
pix->bytesperline = min(pix->bytesperline, CEU_CHDW_MAX);
pix->bytesperline &= ~3;
break;
default:
pix->bytesperline = 0;
}
pix->width &= ~3;
pix->height &= ~3;
pix->sizeimage = 0;
dev_geo(icd->parent, "%s(): return %d, fmt 0x%x, %ux%u\n",
__func__, ret, pix->pixelformat, pix->width, pix->height);
return ret;
}
static int sh_mobile_ceu_set_livecrop(struct soc_camera_device *icd,
const struct v4l2_crop *a)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct sh_mobile_ceu_dev *pcdev = ici->priv;
u32 out_width = icd->user_width, out_height = icd->user_height;
int ret;
pcdev->frozen = 1;
ret = wait_for_completion_interruptible(&pcdev->complete);
ret = v4l2_subdev_call(sd, video, s_stream, 0);
if (ret < 0)
dev_warn(icd->parent,
"Client failed to stop the stream: %d\n", ret);
else
sh_mobile_ceu_set_crop(icd, a);
dev_geo(icd->parent, "Output after crop: %ux%u\n", icd->user_width, icd->user_height);
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
icd->user_width = out_width & ~3;
icd->user_height = out_height & ~3;
ret = sh_mobile_ceu_set_bus_param(icd);
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
strlcpy(cap->driver, "sh_mobile_ceu", sizeof(cap->driver));
strlcpy(cap->bus_info, "platform:sh_mobile_ceu", sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int sh_mobile_ceu_init_videobuf(struct vb2_queue *q,
struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->drv_priv = icd;
q->ops = &sh_mobile_ceu_videobuf_ops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct sh_mobile_ceu_buffer);
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &ici->host_lock;
q->dev = ici->v4l2_dev.dev;
return vb2_queue_init(q);
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
static int sh_mobile_ceu_probe(struct platform_device *pdev)
{
struct sh_mobile_ceu_dev *pcdev;
struct resource *res;
void __iomem *base;
unsigned int irq;
int err, i;
struct bus_wait wait = {
.completion = COMPLETION_INITIALIZER_ONSTACK(wait.completion),
.notifier.notifier_call = bus_notify,
};
struct sh_mobile_ceu_companion *csi2;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || (int)irq <= 0) {
dev_err(&pdev->dev, "Not enough CEU platform resources.\n");
return -ENODEV;
}
pcdev = devm_kzalloc(&pdev->dev, sizeof(*pcdev), GFP_KERNEL);
if (!pcdev) {
dev_err(&pdev->dev, "Could not allocate pcdev\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&pcdev->capture);
spin_lock_init(&pcdev->lock);
init_completion(&pcdev->complete);
pcdev->pdata = pdev->dev.platform_data;
if (!pcdev->pdata && !pdev->dev.of_node) {
dev_err(&pdev->dev, "CEU platform data not set.\n");
return -EINVAL;
}
if (pcdev->pdata) {
pcdev->max_width = pcdev->pdata->max_width;
pcdev->max_height = pcdev->pdata->max_height;
pcdev->flags = pcdev->pdata->flags;
}
pcdev->field = V4L2_FIELD_NONE;
if (!pcdev->max_width) {
unsigned int v;
err = of_property_read_u32(pdev->dev.of_node, "renesas,max-width", &v);
if (!err)
pcdev->max_width = v;
if (!pcdev->max_width)
pcdev->max_width = 2560;
}
if (!pcdev->max_height) {
unsigned int v;
err = of_property_read_u32(pdev->dev.of_node, "renesas,max-height", &v);
if (!err)
pcdev->max_height = v;
if (!pcdev->max_height)
pcdev->max_height = 1920;
}
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
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
return -ENXIO;
}
pcdev->video_limit = resource_size(res);
}
err = devm_request_irq(&pdev->dev, pcdev->irq, sh_mobile_ceu_irq,
0, dev_name(&pdev->dev), pcdev);
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
pcdev->ici.capabilities = SOCAM_HOST_CAP_STRIDE;
if (pcdev->pdata && pcdev->pdata->asd_sizes) {
struct v4l2_async_subdev **asd;
char name[] = "sh-mobile-csi2";
int j;
asd = pcdev->pdata->asd;
for (j = 0; pcdev->pdata->asd_sizes[j]; j++) {
for (i = 0; i < pcdev->pdata->asd_sizes[j]; i++, asd++) {
dev_dbg(&pdev->dev, "%s(): subdev #%d, type %u\n",
__func__, i, (*asd)->match_type);
if ((*asd)->match_type == V4L2_ASYNC_MATCH_DEVNAME &&
!strncmp(name, (*asd)->match.device_name.name,
sizeof(name) - 1)) {
pcdev->csi2_asd = *asd;
break;
}
}
if (pcdev->csi2_asd)
break;
}
pcdev->ici.asd = pcdev->pdata->asd;
pcdev->ici.asd_sizes = pcdev->pdata->asd_sizes;
}
csi2 = pcdev->pdata ? pcdev->pdata->csi2 : NULL;
if (csi2) {
struct platform_device *csi2_pdev =
platform_device_alloc("sh-mobile-csi2", csi2->id);
struct sh_csi2_pdata *csi2_pdata = csi2->platform_data;
if (!csi2_pdev) {
err = -ENOMEM;
goto exit_free_clk;
}
pcdev->csi2_pdev = csi2_pdev;
err = platform_device_add_data(csi2_pdev, csi2_pdata,
sizeof(*csi2_pdata));
if (err < 0)
goto exit_pdev_put;
csi2_pdev->resource = csi2->resource;
csi2_pdev->num_resources = csi2->num_resources;
err = platform_device_add(csi2_pdev);
if (err < 0)
goto exit_pdev_put;
wait.dev = &csi2_pdev->dev;
err = bus_register_notifier(&platform_bus_type, &wait.notifier);
if (err < 0)
goto exit_pdev_unregister;
if (!csi2_pdev->dev.driver) {
complete(&wait.completion);
bus_unregister_notifier(&platform_bus_type, &wait.notifier);
err = -ENXIO;
goto exit_pdev_unregister;
}
err = try_module_get(csi2_pdev->dev.driver->owner);
complete(&wait.completion);
bus_unregister_notifier(&platform_bus_type, &wait.notifier);
if (!err) {
err = -ENODEV;
goto exit_pdev_unregister;
}
pcdev->csi2_sd = platform_get_drvdata(csi2_pdev);
}
err = soc_camera_host_register(&pcdev->ici);
if (err)
goto exit_csi2_unregister;
if (csi2) {
err = v4l2_device_register_subdev(&pcdev->ici.v4l2_dev,
pcdev->csi2_sd);
dev_dbg(&pdev->dev, "%s(): ret(register_subdev) = %d\n",
__func__, err);
if (err < 0)
goto exit_host_unregister;
module_put(pcdev->csi2_sd->owner);
}
return 0;
exit_host_unregister:
soc_camera_host_unregister(&pcdev->ici);
exit_csi2_unregister:
if (csi2) {
module_put(pcdev->csi2_pdev->dev.driver->owner);
exit_pdev_unregister:
platform_device_del(pcdev->csi2_pdev);
exit_pdev_put:
pcdev->csi2_pdev->resource = NULL;
platform_device_put(pcdev->csi2_pdev);
}
exit_free_clk:
pm_runtime_disable(&pdev->dev);
exit_release_mem:
if (platform_get_resource(pdev, IORESOURCE_MEM, 1))
dma_release_declared_memory(&pdev->dev);
return err;
}
static int sh_mobile_ceu_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct sh_mobile_ceu_dev *pcdev = container_of(soc_host,
struct sh_mobile_ceu_dev, ici);
struct platform_device *csi2_pdev = pcdev->csi2_pdev;
soc_camera_host_unregister(soc_host);
pm_runtime_disable(&pdev->dev);
if (platform_get_resource(pdev, IORESOURCE_MEM, 1))
dma_release_declared_memory(&pdev->dev);
if (csi2_pdev && csi2_pdev->dev.driver) {
struct module *csi2_drv = csi2_pdev->dev.driver->owner;
platform_device_del(csi2_pdev);
csi2_pdev->resource = NULL;
platform_device_put(csi2_pdev);
module_put(csi2_drv);
}
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
