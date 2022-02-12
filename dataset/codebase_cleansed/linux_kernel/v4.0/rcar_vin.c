static int rcar_vin_videobuf_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *count,
unsigned int *num_planes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
if (fmt) {
const struct soc_camera_format_xlate *xlate;
unsigned int bytes_per_line;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd,
fmt->fmt.pix.pixelformat);
if (!xlate)
return -EINVAL;
ret = soc_mbus_bytes_per_line(fmt->fmt.pix.width,
xlate->host_fmt);
if (ret < 0)
return ret;
bytes_per_line = max_t(u32, fmt->fmt.pix.bytesperline, ret);
ret = soc_mbus_image_size(xlate->host_fmt, bytes_per_line,
fmt->fmt.pix.height);
if (ret < 0)
return ret;
sizes[0] = max_t(u32, fmt->fmt.pix.sizeimage, ret);
} else {
sizes[0] = icd->sizeimage;
}
alloc_ctxs[0] = priv->alloc_ctx;
if (!vq->num_buffers)
priv->sequence = 0;
if (!*count)
*count = 2;
priv->vb_count = *count;
*num_planes = 1;
if (is_continuous_transfer(priv))
priv->nr_hw_slots = MAX_BUFFER_NUM;
else
priv->nr_hw_slots = 1;
dev_dbg(icd->parent, "count=%d, size=%u\n", *count, sizes[0]);
return 0;
}
static int rcar_vin_setup(struct rcar_vin_priv *priv)
{
struct soc_camera_device *icd = priv->ici.icd;
struct rcar_vin_cam *cam = icd->host_priv;
u32 vnmc, dmr, interrupts;
bool progressive = false, output_is_yuv = false;
switch (priv->field) {
case V4L2_FIELD_TOP:
vnmc = VNMC_IM_ODD;
break;
case V4L2_FIELD_BOTTOM:
vnmc = VNMC_IM_EVEN;
break;
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_INTERLACED_TB:
vnmc = VNMC_IM_FULL;
break;
case V4L2_FIELD_INTERLACED_BT:
vnmc = VNMC_IM_FULL | VNMC_FOC;
break;
case V4L2_FIELD_NONE:
if (is_continuous_transfer(priv)) {
vnmc = VNMC_IM_ODD_EVEN;
progressive = true;
} else {
vnmc = VNMC_IM_ODD;
}
break;
default:
vnmc = VNMC_IM_ODD;
break;
}
switch (icd->current_fmt->code) {
case MEDIA_BUS_FMT_YUYV8_1X16:
vnmc |= VNMC_INF_YUV16;
break;
case MEDIA_BUS_FMT_YUYV8_2X8:
vnmc |= priv->pdata_flags & RCAR_VIN_BT656 ?
VNMC_INF_YUV8_BT656 : VNMC_INF_YUV8_BT601;
break;
case MEDIA_BUS_FMT_YUYV10_2X10:
vnmc |= priv->pdata_flags & RCAR_VIN_BT656 ?
VNMC_INF_YUV10_BT656 : VNMC_INF_YUV10_BT601;
break;
default:
break;
}
switch (icd->current_fmt->host_fmt->fourcc) {
case V4L2_PIX_FMT_NV16:
iowrite32(ALIGN(cam->width * cam->height, 0x80),
priv->base + VNUVAOF_REG);
dmr = VNDMR_DTMD_YCSEP;
output_is_yuv = true;
break;
case V4L2_PIX_FMT_YUYV:
dmr = VNDMR_BPSM;
output_is_yuv = true;
break;
case V4L2_PIX_FMT_UYVY:
dmr = 0;
output_is_yuv = true;
break;
case V4L2_PIX_FMT_RGB555X:
dmr = VNDMR_DTMD_ARGB1555;
break;
case V4L2_PIX_FMT_RGB565:
dmr = 0;
break;
case V4L2_PIX_FMT_RGB32:
if (priv->chip == RCAR_GEN2 || priv->chip == RCAR_H1 ||
priv->chip == RCAR_E1) {
dmr = VNDMR_EXRGB;
break;
}
default:
dev_warn(icd->parent, "Invalid fourcc format (0x%x)\n",
icd->current_fmt->host_fmt->fourcc);
return -EINVAL;
}
vnmc |= VNMC_VUP;
if (output_is_yuv)
vnmc |= VNMC_BPS;
interrupts = progressive ? VNIE_FIE : VNIE_EFE;
iowrite32(interrupts, priv->base + VNINTS_REG);
iowrite32(interrupts, priv->base + VNIE_REG);
iowrite32(dmr, priv->base + VNDMR_REG);
iowrite32(vnmc | VNMC_ME, priv->base + VNMC_REG);
return 0;
}
static void rcar_vin_capture(struct rcar_vin_priv *priv)
{
if (is_continuous_transfer(priv))
iowrite32(VNFC_C_FRAME, priv->base + VNFC_REG);
else
iowrite32(VNFC_S_FRAME, priv->base + VNFC_REG);
}
static void rcar_vin_request_capture_stop(struct rcar_vin_priv *priv)
{
priv->state = STOPPING;
iowrite32(0, priv->base + VNFC_REG);
iowrite32(ioread32(priv->base + VNMC_REG) & ~VNMC_ME,
priv->base + VNMC_REG);
if (!(ioread32(priv->base + VNMS_REG) & VNMS_CA))
priv->state = STOPPED;
}
static int rcar_vin_get_free_hw_slot(struct rcar_vin_priv *priv)
{
int slot;
for (slot = 0; slot < priv->nr_hw_slots; slot++)
if (priv->queue_buf[slot] == NULL)
return slot;
return -1;
}
static int rcar_vin_hw_ready(struct rcar_vin_priv *priv)
{
return rcar_vin_get_free_hw_slot(priv) < 0 ? 1 : 0;
}
static int rcar_vin_fill_hw_slot(struct rcar_vin_priv *priv)
{
struct vb2_buffer *vb;
dma_addr_t phys_addr_top;
int slot;
if (list_empty(&priv->capture))
return 0;
slot = rcar_vin_get_free_hw_slot(priv);
if (slot < 0)
return 0;
vb = &list_entry(priv->capture.next, struct rcar_vin_buffer, list)->vb;
list_del_init(to_buf_list(vb));
priv->queue_buf[slot] = vb;
phys_addr_top = vb2_dma_contig_plane_dma_addr(vb, 0);
iowrite32(phys_addr_top, priv->base + VNMB_REG(slot));
return 1;
}
static void rcar_vin_videobuf_queue(struct vb2_buffer *vb)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vb->vb2_queue);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
unsigned long size;
size = icd->sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(icd->parent, "Buffer #%d too small (%lu < %lu)\n",
vb->v4l2_buf.index, vb2_plane_size(vb, 0), size);
goto error;
}
vb2_set_plane_payload(vb, 0, size);
dev_dbg(icd->parent, "%s (vb=0x%p) 0x%p %lu\n", __func__,
vb, vb2_plane_vaddr(vb, 0), vb2_get_plane_payload(vb, 0));
spin_lock_irq(&priv->lock);
list_add_tail(to_buf_list(vb), &priv->capture);
rcar_vin_fill_hw_slot(priv);
if (priv->state != RUNNING && rcar_vin_hw_ready(priv)) {
if (rcar_vin_setup(priv)) {
list_del_init(to_buf_list(vb));
spin_unlock_irq(&priv->lock);
goto error;
}
priv->request_to_stop = false;
init_completion(&priv->capture_stop);
priv->state = RUNNING;
rcar_vin_capture(priv);
}
spin_unlock_irq(&priv->lock);
return;
error:
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
static void rcar_vin_wait_stop_streaming(struct rcar_vin_priv *priv)
{
while (priv->state != STOPPED) {
if (priv->state == RUNNING)
rcar_vin_request_capture_stop(priv);
if (priv->state == STOPPING) {
priv->request_to_stop = true;
spin_unlock_irq(&priv->lock);
wait_for_completion(&priv->capture_stop);
spin_lock_irq(&priv->lock);
}
}
}
static void rcar_vin_stop_streaming(struct vb2_queue *vq)
{
struct soc_camera_device *icd = soc_camera_from_vb2q(vq);
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
struct list_head *buf_head, *tmp;
int i;
spin_lock_irq(&priv->lock);
rcar_vin_wait_stop_streaming(priv);
for (i = 0; i < MAX_BUFFER_NUM; i++) {
if (priv->queue_buf[i]) {
vb2_buffer_done(priv->queue_buf[i],
VB2_BUF_STATE_ERROR);
priv->queue_buf[i] = NULL;
}
}
list_for_each_safe(buf_head, tmp, &priv->capture) {
vb2_buffer_done(&list_entry(buf_head,
struct rcar_vin_buffer, list)->vb,
VB2_BUF_STATE_ERROR);
list_del_init(buf_head);
}
spin_unlock_irq(&priv->lock);
}
static irqreturn_t rcar_vin_irq(int irq, void *data)
{
struct rcar_vin_priv *priv = data;
u32 int_status;
bool can_run = false, hw_stopped;
int slot;
unsigned int handled = 0;
spin_lock(&priv->lock);
int_status = ioread32(priv->base + VNINTS_REG);
if (!int_status)
goto done;
iowrite32(int_status, priv->base + VNINTS_REG);
handled = 1;
if (priv->state == STOPPED)
goto done;
hw_stopped = !(ioread32(priv->base + VNMS_REG) & VNMS_CA);
if (!priv->request_to_stop) {
if (is_continuous_transfer(priv))
slot = (ioread32(priv->base + VNMS_REG) &
VNMS_FBS_MASK) >> VNMS_FBS_SHIFT;
else
slot = 0;
priv->queue_buf[slot]->v4l2_buf.field = priv->field;
priv->queue_buf[slot]->v4l2_buf.sequence = priv->sequence++;
do_gettimeofday(&priv->queue_buf[slot]->v4l2_buf.timestamp);
vb2_buffer_done(priv->queue_buf[slot], VB2_BUF_STATE_DONE);
priv->queue_buf[slot] = NULL;
if (priv->state != STOPPING)
can_run = rcar_vin_fill_hw_slot(priv);
if (hw_stopped || !can_run) {
priv->state = STOPPED;
} else if (is_continuous_transfer(priv) &&
list_empty(&priv->capture) &&
priv->state == RUNNING) {
rcar_vin_request_capture_stop(priv);
} else {
rcar_vin_capture(priv);
}
} else if (hw_stopped) {
priv->state = STOPPED;
priv->request_to_stop = false;
complete(&priv->capture_stop);
}
done:
spin_unlock(&priv->lock);
return IRQ_RETVAL(handled);
}
static int rcar_vin_add_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
int i;
for (i = 0; i < MAX_BUFFER_NUM; i++)
priv->queue_buf[i] = NULL;
pm_runtime_get_sync(ici->v4l2_dev.dev);
dev_dbg(icd->parent, "R-Car VIN driver attached to camera %d\n",
icd->devnum);
return 0;
}
static void rcar_vin_remove_device(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
struct vb2_buffer *vb;
int i;
iowrite32(ioread32(priv->base + VNMC_REG) & ~VNMC_ME,
priv->base + VNMC_REG);
iowrite32(0, priv->base + VNIE_REG);
priv->state = STOPPED;
priv->request_to_stop = false;
spin_lock_irq(&priv->lock);
for (i = 0; i < MAX_BUFFER_NUM; i++) {
vb = priv->queue_buf[i];
if (vb) {
list_del_init(to_buf_list(vb));
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
}
spin_unlock_irq(&priv->lock);
pm_runtime_put(ici->v4l2_dev.dev);
dev_dbg(icd->parent, "R-Car VIN driver detached from camera %d\n",
icd->devnum);
}
static int rcar_vin_clock_start(struct soc_camera_host *ici)
{
return 0;
}
static void rcar_vin_clock_stop(struct soc_camera_host *ici)
{
}
static void set_coeff(struct rcar_vin_priv *priv, unsigned short xs)
{
int i;
const struct vin_coeff *p_prev_set = NULL;
const struct vin_coeff *p_set = NULL;
for (i = 0; i < ARRAY_SIZE(vin_coeff_set); i++) {
p_prev_set = p_set;
p_set = &vin_coeff_set[i];
if (xs < p_set->xs_value)
break;
}
if (p_prev_set && p_set &&
xs - p_prev_set->xs_value < p_set->xs_value - xs)
p_set = p_prev_set;
iowrite32(p_set->coeff_set[0], priv->base + VNC1A_REG);
iowrite32(p_set->coeff_set[1], priv->base + VNC1B_REG);
iowrite32(p_set->coeff_set[2], priv->base + VNC1C_REG);
iowrite32(p_set->coeff_set[3], priv->base + VNC2A_REG);
iowrite32(p_set->coeff_set[4], priv->base + VNC2B_REG);
iowrite32(p_set->coeff_set[5], priv->base + VNC2C_REG);
iowrite32(p_set->coeff_set[6], priv->base + VNC3A_REG);
iowrite32(p_set->coeff_set[7], priv->base + VNC3B_REG);
iowrite32(p_set->coeff_set[8], priv->base + VNC3C_REG);
iowrite32(p_set->coeff_set[9], priv->base + VNC4A_REG);
iowrite32(p_set->coeff_set[10], priv->base + VNC4B_REG);
iowrite32(p_set->coeff_set[11], priv->base + VNC4C_REG);
iowrite32(p_set->coeff_set[12], priv->base + VNC5A_REG);
iowrite32(p_set->coeff_set[13], priv->base + VNC5B_REG);
iowrite32(p_set->coeff_set[14], priv->base + VNC5C_REG);
iowrite32(p_set->coeff_set[15], priv->base + VNC6A_REG);
iowrite32(p_set->coeff_set[16], priv->base + VNC6B_REG);
iowrite32(p_set->coeff_set[17], priv->base + VNC6C_REG);
iowrite32(p_set->coeff_set[18], priv->base + VNC7A_REG);
iowrite32(p_set->coeff_set[19], priv->base + VNC7B_REG);
iowrite32(p_set->coeff_set[20], priv->base + VNC7C_REG);
iowrite32(p_set->coeff_set[21], priv->base + VNC8A_REG);
iowrite32(p_set->coeff_set[22], priv->base + VNC8B_REG);
iowrite32(p_set->coeff_set[23], priv->base + VNC8C_REG);
}
static int rcar_vin_set_rect(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_cam *cam = icd->host_priv;
struct rcar_vin_priv *priv = ici->priv;
unsigned int left_offset, top_offset;
unsigned char dsize = 0;
struct v4l2_rect *cam_subrect = &cam->subrect;
u32 value;
dev_dbg(icd->parent, "Crop %ux%u@%u:%u\n",
icd->user_width, icd->user_height, cam->vin_left, cam->vin_top);
left_offset = cam->vin_left;
top_offset = cam->vin_top;
if (icd->current_fmt->host_fmt->fourcc == V4L2_PIX_FMT_RGB32 &&
priv->chip == RCAR_E1)
dsize = 1;
dev_dbg(icd->parent, "Cam %ux%u@%u:%u\n",
cam->width, cam->height, cam->vin_left, cam->vin_top);
dev_dbg(icd->parent, "Cam subrect %ux%u@%u:%u\n",
cam_subrect->width, cam_subrect->height,
cam_subrect->left, cam_subrect->top);
iowrite32(left_offset << dsize, priv->base + VNSPPRC_REG);
iowrite32((left_offset + cam_subrect->width - 1) << dsize,
priv->base + VNEPPRC_REG);
switch (priv->field) {
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
iowrite32(top_offset / 2, priv->base + VNSLPRC_REG);
iowrite32((top_offset + cam_subrect->height) / 2 - 1,
priv->base + VNELPRC_REG);
break;
default:
iowrite32(top_offset, priv->base + VNSLPRC_REG);
iowrite32(top_offset + cam_subrect->height - 1,
priv->base + VNELPRC_REG);
break;
}
value = 0;
if (cam_subrect->height != cam->out_height)
value = (4096 * cam_subrect->height) / cam->out_height;
dev_dbg(icd->parent, "YS Value: %x\n", value);
iowrite32(value, priv->base + VNYS_REG);
value = 0;
if (cam_subrect->width != cam->out_width)
value = (4096 * cam_subrect->width) / cam->out_width;
if (0 < value && value < 2048)
value = 2048;
dev_dbg(icd->parent, "XS Value: %x\n", value);
iowrite32(value, priv->base + VNXS_REG);
if (value < 4096)
value *= 2;
set_coeff(priv, value);
iowrite32(0, priv->base + VNSPPOC_REG);
iowrite32(0, priv->base + VNSLPOC_REG);
iowrite32((cam->out_width - 1) << dsize, priv->base + VNEPPOC_REG);
switch (priv->field) {
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
iowrite32(cam->out_height / 2 - 1,
priv->base + VNELPOC_REG);
break;
default:
iowrite32(cam->out_height - 1, priv->base + VNELPOC_REG);
break;
}
iowrite32(ALIGN(cam->out_width, 0x10), priv->base + VNIS_REG);
return 0;
}
static void capture_stop_preserve(struct rcar_vin_priv *priv, u32 *vnmc)
{
*vnmc = ioread32(priv->base + VNMC_REG);
iowrite32(*vnmc & ~VNMC_ME, priv->base + VNMC_REG);
}
static void capture_restore(struct rcar_vin_priv *priv, u32 vnmc)
{
unsigned long timeout = jiffies + 10 * HZ;
while ((ioread32(priv->base + VNMS_REG) & VNMS_AV) &&
time_before(jiffies, timeout))
msleep(1);
if (time_after(jiffies, timeout)) {
dev_err(priv->ici.v4l2_dev.dev,
"Timeout waiting for frame end! Interface problem?\n");
return;
}
iowrite32(vnmc, priv->base + VNMC_REG);
}
static int rcar_vin_set_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_config cfg;
unsigned long common_flags;
u32 vnmc;
u32 val;
int ret;
capture_stop_preserve(priv, &vnmc);
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (!ret) {
common_flags = soc_mbus_config_compatible(&cfg, VIN_MBUS_FLAGS);
if (!common_flags) {
dev_warn(icd->parent,
"MBUS flags incompatible: camera 0x%x, host 0x%x\n",
cfg.flags, VIN_MBUS_FLAGS);
return -EINVAL;
}
} else if (ret != -ENOIOCTLCMD) {
return ret;
} else {
common_flags = VIN_MBUS_FLAGS;
}
if ((common_flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)) {
if (priv->pdata_flags & RCAR_VIN_HSYNC_ACTIVE_LOW)
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_HSYNC_ACTIVE_LOW;
}
if ((common_flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH) &&
(common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)) {
if (priv->pdata_flags & RCAR_VIN_VSYNC_ACTIVE_LOW)
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_HIGH;
else
common_flags &= ~V4L2_MBUS_VSYNC_ACTIVE_LOW;
}
cfg.flags = common_flags;
ret = v4l2_subdev_call(sd, video, s_mbus_config, &cfg);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
val = VNDMR2_FTEV | VNDMR2_VLV(1);
if (!(common_flags & V4L2_MBUS_VSYNC_ACTIVE_LOW))
val |= VNDMR2_VPS;
if (!(common_flags & V4L2_MBUS_HSYNC_ACTIVE_LOW))
val |= VNDMR2_HPS;
iowrite32(val, priv->base + VNDMR2_REG);
ret = rcar_vin_set_rect(icd);
if (ret < 0)
return ret;
capture_restore(priv, vnmc);
return 0;
}
static int rcar_vin_try_bus_param(struct soc_camera_device *icd,
unsigned char buswidth)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_config cfg;
int ret;
ret = v4l2_subdev_call(sd, video, g_mbus_config, &cfg);
if (ret == -ENOIOCTLCMD)
return 0;
else if (ret)
return ret;
if (buswidth > 24)
return -EINVAL;
ret = soc_mbus_config_compatible(&cfg, VIN_MBUS_FLAGS);
if (ret)
return 0;
dev_warn(icd->parent,
"MBUS flags incompatible: camera 0x%x, host 0x%x\n",
cfg.flags, VIN_MBUS_FLAGS);
return -EINVAL;
}
static bool rcar_vin_packing_supported(const struct soc_mbus_pixelfmt *fmt)
{
return fmt->packing == SOC_MBUS_PACKING_NONE ||
(fmt->bits_per_sample > 8 &&
fmt->packing == SOC_MBUS_PACKING_EXTEND16);
}
static int rcar_vin_get_formats(struct soc_camera_device *icd, unsigned int idx,
struct soc_camera_format_xlate *xlate)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->parent;
int ret, k, n;
int formats = 0;
struct rcar_vin_cam *cam;
u32 code;
const struct soc_mbus_pixelfmt *fmt;
ret = v4l2_subdev_call(sd, video, enum_mbus_fmt, idx, &code);
if (ret < 0)
return 0;
fmt = soc_mbus_get_fmtdesc(code);
if (!fmt) {
dev_warn(dev, "unsupported format code #%u: %d\n", idx, code);
return 0;
}
ret = rcar_vin_try_bus_param(icd, fmt->bits_per_sample);
if (ret < 0)
return 0;
if (!icd->host_priv) {
struct v4l2_mbus_framefmt mf;
struct v4l2_rect rect;
struct device *dev = icd->parent;
int shift;
ret = v4l2_subdev_call(sd, video, g_mbus_fmt, &mf);
if (ret < 0)
return ret;
ret = soc_camera_client_g_rect(sd, &rect);
if (ret == -ENOIOCTLCMD) {
rect.left = 0;
rect.top = 0;
rect.width = mf.width;
rect.height = mf.height;
} else if (ret < 0) {
return ret;
}
for (shift = 0; shift < 3; shift++) {
if (mf.width <= VIN_MAX_WIDTH &&
mf.height <= VIN_MAX_HEIGHT)
break;
mf.width = 1280 >> shift;
mf.height = 960 >> shift;
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd),
video, s_mbus_fmt,
&mf);
if (ret < 0)
return ret;
}
if (shift == 3) {
dev_err(dev,
"Failed to configure the client below %ux%u\n",
mf.width, mf.height);
return -EIO;
}
dev_dbg(dev, "camera fmt %ux%u\n", mf.width, mf.height);
cam = kzalloc(sizeof(*cam), GFP_KERNEL);
if (!cam)
return -ENOMEM;
cam->rect = rect;
cam->subrect = rect;
cam->width = mf.width;
cam->height = mf.height;
cam->out_width = mf.width;
cam->out_height = mf.height;
icd->host_priv = cam;
} else {
cam = icd->host_priv;
}
if (!idx)
cam->extra_fmt = NULL;
switch (code) {
case MEDIA_BUS_FMT_YUYV8_1X16:
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_YUYV10_2X10:
if (cam->extra_fmt)
break;
cam->extra_fmt = rcar_vin_formats;
n = ARRAY_SIZE(rcar_vin_formats);
formats += n;
for (k = 0; xlate && k < n; k++, xlate++) {
xlate->host_fmt = &rcar_vin_formats[k];
xlate->code = code;
dev_dbg(dev, "Providing format %s using code %d\n",
rcar_vin_formats[k].name, code);
}
break;
default:
if (!rcar_vin_packing_supported(fmt))
return 0;
dev_dbg(dev, "Providing format %s in pass-through mode\n",
fmt->name);
break;
}
formats++;
if (xlate) {
xlate->host_fmt = fmt;
xlate->code = code;
xlate++;
}
return formats;
}
static void rcar_vin_put_formats(struct soc_camera_device *icd)
{
kfree(icd->host_priv);
icd->host_priv = NULL;
}
static int rcar_vin_set_crop(struct soc_camera_device *icd,
const struct v4l2_crop *a)
{
struct v4l2_crop a_writable = *a;
const struct v4l2_rect *rect = &a_writable.c;
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
struct v4l2_crop cam_crop;
struct rcar_vin_cam *cam = icd->host_priv;
struct v4l2_rect *cam_rect = &cam_crop.c;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->parent;
struct v4l2_mbus_framefmt mf;
u32 vnmc;
int ret, i;
dev_dbg(dev, "S_CROP(%ux%u@%u:%u)\n", rect->width, rect->height,
rect->left, rect->top);
capture_stop_preserve(priv, &vnmc);
dev_dbg(dev, "VNMC_REG 0x%x\n", vnmc);
ret = soc_camera_client_s_crop(sd, &a_writable, &cam_crop,
&cam->rect, &cam->subrect);
if (ret < 0)
return ret;
dev_dbg(dev, "camera cropped to %ux%u@%u:%u\n",
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
ret = v4l2_subdev_call(sd, video, g_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (mf.width > VIN_MAX_WIDTH || mf.height > VIN_MAX_HEIGHT)
return -EINVAL;
cam->width = mf.width;
cam->height = mf.height;
icd->user_width = cam->width;
icd->user_height = cam->height;
cam->vin_left = rect->left & ~1;
cam->vin_top = rect->top & ~1;
ret = rcar_vin_set_rect(icd);
if (ret < 0)
return ret;
cam->subrect = *rect;
dev_dbg(dev, "VIN cropped to %ux%u@%u:%u\n",
icd->user_width, icd->user_height,
cam->vin_left, cam->vin_top);
for (i = 0; i < MAX_BUFFER_NUM; i++) {
if (priv->queue_buf[i] && priv->state == STOPPED) {
vnmc |= VNMC_ME;
break;
}
}
capture_restore(priv, vnmc);
return ret;
}
static int rcar_vin_get_crop(struct soc_camera_device *icd,
struct v4l2_crop *a)
{
struct rcar_vin_cam *cam = icd->host_priv;
a->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
a->c = cam->subrect;
return 0;
}
static int rcar_vin_set_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
struct rcar_vin_priv *priv = ici->priv;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct rcar_vin_cam *cam = icd->host_priv;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_mbus_framefmt mf;
struct device *dev = icd->parent;
__u32 pixfmt = pix->pixelformat;
const struct soc_camera_format_xlate *xlate;
unsigned int vin_sub_width = 0, vin_sub_height = 0;
int ret;
bool can_scale;
enum v4l2_field field;
v4l2_std_id std;
dev_dbg(dev, "S_FMT(pix=0x%x, %ux%u)\n",
pixfmt, pix->width, pix->height);
switch (pix->field) {
default:
pix->field = V4L2_FIELD_NONE;
case V4L2_FIELD_NONE:
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
field = pix->field;
break;
case V4L2_FIELD_INTERLACED:
ret = v4l2_subdev_call(sd, video, querystd, &std);
if (ret < 0)
std = V4L2_STD_625_50;
field = std & V4L2_STD_625_50 ? V4L2_FIELD_INTERLACED_TB :
V4L2_FIELD_INTERLACED_BT;
break;
}
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate) {
dev_warn(dev, "Format %x not found\n", pixfmt);
return -EINVAL;
}
soc_camera_calc_client_output(icd, &cam->rect, &cam->subrect, pix, &mf,
12);
mf.field = pix->field;
mf.colorspace = pix->colorspace;
mf.code = xlate->code;
switch (pixfmt) {
case V4L2_PIX_FMT_RGB32:
can_scale = priv->chip != RCAR_E1;
break;
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_RGB565:
case V4L2_PIX_FMT_RGB555X:
can_scale = true;
break;
default:
can_scale = false;
break;
}
dev_dbg(dev, "request camera output %ux%u\n", mf.width, mf.height);
ret = soc_camera_client_scale(icd, &cam->rect, &cam->subrect,
&mf, &vin_sub_width, &vin_sub_height,
can_scale, 12);
dev_dbg(dev, "Camera %d fmt %ux%u, requested %ux%u\n",
ret, mf.width, mf.height, pix->width, pix->height);
if (ret == -ENOIOCTLCMD)
dev_dbg(dev, "Sensor doesn't support scaling\n");
else if (ret < 0)
return ret;
if (mf.code != xlate->code)
return -EINVAL;
cam->width = mf.width;
cam->height = mf.height;
if (pix->width > vin_sub_width)
vin_sub_width = pix->width;
if (pix->height > vin_sub_height)
vin_sub_height = pix->height;
pix->colorspace = mf.colorspace;
if (!can_scale) {
pix->width = vin_sub_width;
pix->height = vin_sub_height;
}
dev_dbg(dev, "W: %u : %u, H: %u : %u\n",
vin_sub_width, pix->width, vin_sub_height, pix->height);
cam->out_width = pix->width;
cam->out_height = pix->height;
icd->current_fmt = xlate;
priv->field = field;
return 0;
}
static int rcar_vin_try_fmt(struct soc_camera_device *icd,
struct v4l2_format *f)
{
const struct soc_camera_format_xlate *xlate;
struct v4l2_pix_format *pix = &f->fmt.pix;
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_framefmt mf;
__u32 pixfmt = pix->pixelformat;
int width, height;
int ret;
xlate = soc_camera_xlate_by_fourcc(icd, pixfmt);
if (!xlate) {
xlate = icd->current_fmt;
dev_dbg(icd->parent, "Format %x not found, keeping %x\n",
pixfmt, xlate->host_fmt->fourcc);
pixfmt = xlate->host_fmt->fourcc;
pix->pixelformat = pixfmt;
pix->colorspace = icd->colorspace;
}
v4l_bound_align_image(&pix->width, 2, VIN_MAX_WIDTH, 1,
&pix->height, 4, VIN_MAX_HEIGHT, 2, 0);
width = pix->width;
height = pix->height;
pix->bytesperline = 0;
pix->sizeimage = 0;
mf.width = pix->width;
mf.height = pix->height;
mf.field = pix->field;
mf.code = xlate->code;
mf.colorspace = pix->colorspace;
ret = v4l2_device_call_until_err(sd->v4l2_dev, soc_camera_grp_id(icd),
video, try_mbus_fmt, &mf);
if (ret < 0)
return ret;
if (pix->width > mf.width * 2)
pix->width = mf.width * 2;
if (pix->height > mf.height * 3)
pix->height = mf.height * 3;
pix->field = mf.field;
pix->colorspace = mf.colorspace;
if (pixfmt == V4L2_PIX_FMT_NV16) {
if (pix->width < width || pix->height < height) {
mf.width = VIN_MAX_WIDTH;
mf.height = VIN_MAX_HEIGHT;
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd),
video, try_mbus_fmt,
&mf);
if (ret < 0) {
dev_err(icd->parent,
"client try_fmt() = %d\n", ret);
return ret;
}
}
if (mf.width > width)
pix->width = width;
if (mf.height > height)
pix->height = height;
}
return ret;
}
static unsigned int rcar_vin_poll(struct file *file, poll_table *pt)
{
struct soc_camera_device *icd = file->private_data;
return vb2_poll(&icd->vb2_vidq, file, pt);
}
static int rcar_vin_querycap(struct soc_camera_host *ici,
struct v4l2_capability *cap)
{
strlcpy(cap->card, "R_Car_VIN", sizeof(cap->card));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int rcar_vin_init_videobuf2(struct vb2_queue *vq,
struct soc_camera_device *icd)
{
struct soc_camera_host *ici = to_soc_camera_host(icd->parent);
vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
vq->io_modes = VB2_MMAP | VB2_USERPTR;
vq->drv_priv = icd;
vq->ops = &rcar_vin_vb2_ops;
vq->mem_ops = &vb2_dma_contig_memops;
vq->buf_struct_size = sizeof(struct rcar_vin_buffer);
vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
vq->lock = &ici->host_lock;
return vb2_queue_init(vq);
}
static int rcar_vin_probe(struct platform_device *pdev)
{
const struct of_device_id *match = NULL;
struct rcar_vin_priv *priv;
struct resource *mem;
struct rcar_vin_platform_data *pdata;
unsigned int pdata_flags;
int irq, ret;
if (pdev->dev.of_node) {
struct v4l2_of_endpoint ep;
struct device_node *np;
match = of_match_device(of_match_ptr(rcar_vin_of_table),
&pdev->dev);
np = of_graph_get_next_endpoint(pdev->dev.of_node, NULL);
if (!np) {
dev_err(&pdev->dev, "could not find endpoint\n");
return -EINVAL;
}
ret = v4l2_of_parse_endpoint(np, &ep);
if (ret) {
dev_err(&pdev->dev, "could not parse endpoint\n");
return ret;
}
if (ep.bus_type == V4L2_MBUS_BT656)
pdata_flags = RCAR_VIN_BT656;
else {
pdata_flags = 0;
if (ep.bus.parallel.flags & V4L2_MBUS_HSYNC_ACTIVE_LOW)
pdata_flags |= RCAR_VIN_HSYNC_ACTIVE_LOW;
if (ep.bus.parallel.flags & V4L2_MBUS_VSYNC_ACTIVE_LOW)
pdata_flags |= RCAR_VIN_VSYNC_ACTIVE_LOW;
}
of_node_put(np);
dev_dbg(&pdev->dev, "pdata_flags = %08x\n", pdata_flags);
} else {
pdata = pdev->dev.platform_data;
if (!pdata || !pdata->flags) {
dev_err(&pdev->dev, "platform data not set\n");
return -EINVAL;
}
pdata_flags = pdata->flags;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (mem == NULL)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(struct rcar_vin_priv),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
ret = devm_request_irq(&pdev->dev, irq, rcar_vin_irq, IRQF_SHARED,
dev_name(&pdev->dev), priv);
if (ret)
return ret;
priv->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(priv->alloc_ctx))
return PTR_ERR(priv->alloc_ctx);
priv->ici.priv = priv;
priv->ici.v4l2_dev.dev = &pdev->dev;
priv->ici.drv_name = dev_name(&pdev->dev);
priv->ici.ops = &rcar_vin_host_ops;
priv->pdata_flags = pdata_flags;
if (!match) {
priv->ici.nr = pdev->id;
priv->chip = pdev->id_entry->driver_data;
} else {
priv->ici.nr = of_alias_get_id(pdev->dev.of_node, "vin");
priv->chip = (enum chip_id)match->data;
}
spin_lock_init(&priv->lock);
INIT_LIST_HEAD(&priv->capture);
priv->state = STOPPED;
pm_suspend_ignore_children(&pdev->dev, true);
pm_runtime_enable(&pdev->dev);
ret = soc_camera_host_register(&priv->ici);
if (ret)
goto cleanup;
return 0;
cleanup:
pm_runtime_disable(&pdev->dev);
vb2_dma_contig_cleanup_ctx(priv->alloc_ctx);
return ret;
}
static int rcar_vin_remove(struct platform_device *pdev)
{
struct soc_camera_host *soc_host = to_soc_camera_host(&pdev->dev);
struct rcar_vin_priv *priv = container_of(soc_host,
struct rcar_vin_priv, ici);
soc_camera_host_unregister(soc_host);
pm_runtime_disable(&pdev->dev);
vb2_dma_contig_cleanup_ctx(priv->alloc_ctx);
return 0;
}
