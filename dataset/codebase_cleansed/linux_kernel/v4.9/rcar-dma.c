static void rvin_write(struct rvin_dev *vin, u32 value, u32 offset)
{
iowrite32(value, vin->base + offset);
}
static u32 rvin_read(struct rvin_dev *vin, u32 offset)
{
return ioread32(vin->base + offset);
}
static int rvin_setup(struct rvin_dev *vin)
{
u32 vnmc, dmr, dmr2, interrupts;
v4l2_std_id std;
bool progressive = false, output_is_yuv = false, input_is_yuv = false;
switch (vin->format.field) {
case V4L2_FIELD_TOP:
vnmc = VNMC_IM_ODD;
break;
case V4L2_FIELD_BOTTOM:
vnmc = VNMC_IM_EVEN;
break;
case V4L2_FIELD_INTERLACED:
vnmc = VNMC_IM_FULL;
if (!v4l2_subdev_call(vin_to_source(vin), video, g_std, &std)) {
if (std & V4L2_STD_525_60)
vnmc = VNMC_IM_FULL | VNMC_FOC;
}
break;
case V4L2_FIELD_INTERLACED_TB:
vnmc = VNMC_IM_FULL;
break;
case V4L2_FIELD_INTERLACED_BT:
vnmc = VNMC_IM_FULL | VNMC_FOC;
break;
case V4L2_FIELD_ALTERNATE:
case V4L2_FIELD_NONE:
if (vin->continuous) {
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
switch (vin->digital.code) {
case MEDIA_BUS_FMT_YUYV8_1X16:
vnmc |= VNMC_INF_YUV16;
input_is_yuv = true;
break;
case MEDIA_BUS_FMT_UYVY8_2X8:
vnmc |= vin->digital.mbus_cfg.type == V4L2_MBUS_BT656 ?
VNMC_INF_YUV8_BT656 : VNMC_INF_YUV8_BT601;
input_is_yuv = true;
break;
case MEDIA_BUS_FMT_RGB888_1X24:
vnmc |= VNMC_INF_RGB888;
break;
case MEDIA_BUS_FMT_UYVY10_2X10:
vnmc |= vin->digital.mbus_cfg.type == V4L2_MBUS_BT656 ?
VNMC_INF_YUV10_BT656 : VNMC_INF_YUV10_BT601;
input_is_yuv = true;
break;
default:
break;
}
dmr2 = VNDMR2_FTEV | VNDMR2_VLV(1);
if (!(vin->digital.mbus_cfg.flags & V4L2_MBUS_HSYNC_ACTIVE_LOW))
dmr2 |= VNDMR2_HPS;
if (!(vin->digital.mbus_cfg.flags & V4L2_MBUS_VSYNC_ACTIVE_LOW))
dmr2 |= VNDMR2_VPS;
switch (vin->format.pixelformat) {
case V4L2_PIX_FMT_NV16:
rvin_write(vin,
ALIGN(vin->format.width * vin->format.height, 0x80),
VNUVAOF_REG);
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
case V4L2_PIX_FMT_XRGB555:
dmr = VNDMR_DTMD_ARGB1555;
break;
case V4L2_PIX_FMT_RGB565:
dmr = 0;
break;
case V4L2_PIX_FMT_XBGR32:
dmr = VNDMR_EXRGB;
break;
default:
vin_err(vin, "Invalid pixelformat (0x%x)\n",
vin->format.pixelformat);
return -EINVAL;
}
vnmc |= VNMC_VUP;
if (input_is_yuv == output_is_yuv)
vnmc |= VNMC_BPS;
interrupts = progressive ? VNIE_FIE : VNIE_EFE;
rvin_write(vin, interrupts, VNINTS_REG);
rvin_write(vin, interrupts, VNIE_REG);
rvin_write(vin, dmr, VNDMR_REG);
rvin_write(vin, dmr2, VNDMR2_REG);
rvin_write(vin, vnmc | VNMC_ME, VNMC_REG);
return 0;
}
static void rvin_capture_on(struct rvin_dev *vin)
{
vin_dbg(vin, "Capture on in %s mode\n",
vin->continuous ? "continuous" : "single");
if (vin->continuous)
rvin_write(vin, VNFC_C_FRAME, VNFC_REG);
else
rvin_write(vin, VNFC_S_FRAME, VNFC_REG);
}
static void rvin_capture_off(struct rvin_dev *vin)
{
rvin_write(vin, 0, VNFC_REG);
}
static int rvin_capture_start(struct rvin_dev *vin)
{
int ret;
rvin_crop_scale_comp(vin);
ret = rvin_setup(vin);
if (ret)
return ret;
rvin_capture_on(vin);
return 0;
}
static void rvin_capture_stop(struct rvin_dev *vin)
{
rvin_capture_off(vin);
rvin_write(vin, rvin_read(vin, VNMC_REG) & ~VNMC_ME, VNMC_REG);
}
static void rvin_disable_interrupts(struct rvin_dev *vin)
{
rvin_write(vin, 0, VNIE_REG);
}
static u32 rvin_get_interrupt_status(struct rvin_dev *vin)
{
return rvin_read(vin, VNINTS_REG);
}
static void rvin_ack_interrupt(struct rvin_dev *vin)
{
rvin_write(vin, rvin_read(vin, VNINTS_REG), VNINTS_REG);
}
static bool rvin_capture_active(struct rvin_dev *vin)
{
return rvin_read(vin, VNMS_REG) & VNMS_CA;
}
static int rvin_get_active_slot(struct rvin_dev *vin, u32 vnms)
{
if (vin->continuous)
return (vnms & VNMS_FBS_MASK) >> VNMS_FBS_SHIFT;
return 0;
}
static enum v4l2_field rvin_get_active_field(struct rvin_dev *vin, u32 vnms)
{
if (vin->format.field == V4L2_FIELD_ALTERNATE) {
if (vnms & VNMS_FS)
return V4L2_FIELD_BOTTOM;
return V4L2_FIELD_TOP;
}
return vin->format.field;
}
static void rvin_set_slot_addr(struct rvin_dev *vin, int slot, dma_addr_t addr)
{
const struct rvin_video_format *fmt;
int offsetx, offsety;
dma_addr_t offset;
fmt = rvin_format_from_pixel(vin->format.pixelformat);
offsetx = vin->compose.left * fmt->bpp;
offsety = vin->compose.top * vin->format.bytesperline;
offset = addr + offsetx + offsety;
if (WARN_ON((offsetx | offsety | offset) & HW_BUFFER_MASK))
return;
rvin_write(vin, offset, VNMB_REG(slot));
}
static void rvin_set_coeff(struct rvin_dev *vin, unsigned short xs)
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
rvin_write(vin, p_set->coeff_set[0], VNC1A_REG);
rvin_write(vin, p_set->coeff_set[1], VNC1B_REG);
rvin_write(vin, p_set->coeff_set[2], VNC1C_REG);
rvin_write(vin, p_set->coeff_set[3], VNC2A_REG);
rvin_write(vin, p_set->coeff_set[4], VNC2B_REG);
rvin_write(vin, p_set->coeff_set[5], VNC2C_REG);
rvin_write(vin, p_set->coeff_set[6], VNC3A_REG);
rvin_write(vin, p_set->coeff_set[7], VNC3B_REG);
rvin_write(vin, p_set->coeff_set[8], VNC3C_REG);
rvin_write(vin, p_set->coeff_set[9], VNC4A_REG);
rvin_write(vin, p_set->coeff_set[10], VNC4B_REG);
rvin_write(vin, p_set->coeff_set[11], VNC4C_REG);
rvin_write(vin, p_set->coeff_set[12], VNC5A_REG);
rvin_write(vin, p_set->coeff_set[13], VNC5B_REG);
rvin_write(vin, p_set->coeff_set[14], VNC5C_REG);
rvin_write(vin, p_set->coeff_set[15], VNC6A_REG);
rvin_write(vin, p_set->coeff_set[16], VNC6B_REG);
rvin_write(vin, p_set->coeff_set[17], VNC6C_REG);
rvin_write(vin, p_set->coeff_set[18], VNC7A_REG);
rvin_write(vin, p_set->coeff_set[19], VNC7B_REG);
rvin_write(vin, p_set->coeff_set[20], VNC7C_REG);
rvin_write(vin, p_set->coeff_set[21], VNC8A_REG);
rvin_write(vin, p_set->coeff_set[22], VNC8B_REG);
rvin_write(vin, p_set->coeff_set[23], VNC8C_REG);
}
void rvin_crop_scale_comp(struct rvin_dev *vin)
{
u32 xs, ys;
rvin_write(vin, vin->crop.left, VNSPPRC_REG);
rvin_write(vin, vin->crop.left + vin->crop.width - 1, VNEPPRC_REG);
switch (vin->format.field) {
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
rvin_write(vin, vin->crop.top / 2, VNSLPRC_REG);
rvin_write(vin, (vin->crop.top + vin->crop.height) / 2 - 1,
VNELPRC_REG);
break;
default:
rvin_write(vin, vin->crop.top, VNSLPRC_REG);
rvin_write(vin, vin->crop.top + vin->crop.height - 1,
VNELPRC_REG);
break;
}
ys = 0;
if (vin->crop.height != vin->compose.height)
ys = (4096 * vin->crop.height) / vin->compose.height;
rvin_write(vin, ys, VNYS_REG);
xs = 0;
if (vin->crop.width != vin->compose.width)
xs = (4096 * vin->crop.width) / vin->compose.width;
if (xs > 0 && xs < 2048)
xs = 2048;
rvin_write(vin, xs, VNXS_REG);
if (xs < 4096)
xs *= 2;
rvin_set_coeff(vin, xs);
rvin_write(vin, 0, VNSPPOC_REG);
rvin_write(vin, 0, VNSLPOC_REG);
rvin_write(vin, vin->format.width - 1, VNEPPOC_REG);
switch (vin->format.field) {
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
rvin_write(vin, vin->format.height / 2 - 1, VNELPOC_REG);
break;
default:
rvin_write(vin, vin->format.height - 1, VNELPOC_REG);
break;
}
if (vin->format.pixelformat == V4L2_PIX_FMT_NV16)
rvin_write(vin, ALIGN(vin->format.width, 0x20), VNIS_REG);
else
rvin_write(vin, ALIGN(vin->format.width, 0x10), VNIS_REG);
vin_dbg(vin,
"Pre-Clip: %ux%u@%u:%u YS: %d XS: %d Post-Clip: %ux%u@%u:%u\n",
vin->crop.width, vin->crop.height, vin->crop.left,
vin->crop.top, ys, xs, vin->format.width, vin->format.height,
0, 0);
}
void rvin_scale_try(struct rvin_dev *vin, struct v4l2_pix_format *pix,
u32 width, u32 height)
{
pix->width = width;
pix->height = height;
}
static bool rvin_fill_hw_slot(struct rvin_dev *vin, int slot)
{
struct rvin_buffer *buf;
struct vb2_v4l2_buffer *vbuf;
dma_addr_t phys_addr_top;
if (vin->queue_buf[slot] != NULL)
return true;
if (list_empty(&vin->buf_list))
return false;
vin_dbg(vin, "Filling HW slot: %d\n", slot);
buf = list_entry(vin->buf_list.next, struct rvin_buffer, list);
vbuf = &buf->vb;
list_del_init(to_buf_list(vbuf));
vin->queue_buf[slot] = vbuf;
phys_addr_top = vb2_dma_contig_plane_dma_addr(&vbuf->vb2_buf, 0);
rvin_set_slot_addr(vin, slot, phys_addr_top);
return true;
}
static bool rvin_fill_hw(struct rvin_dev *vin)
{
int slot, limit;
limit = vin->continuous ? HW_BUFFER_NUM : 1;
for (slot = 0; slot < limit; slot++)
if (!rvin_fill_hw_slot(vin, slot))
return false;
return true;
}
static irqreturn_t rvin_irq(int irq, void *data)
{
struct rvin_dev *vin = data;
u32 int_status, vnms;
int slot;
unsigned int sequence, handled = 0;
unsigned long flags;
spin_lock_irqsave(&vin->qlock, flags);
int_status = rvin_get_interrupt_status(vin);
if (!int_status)
goto done;
rvin_ack_interrupt(vin);
handled = 1;
if (vin->state == STOPPED) {
vin_dbg(vin, "IRQ while state stopped\n");
goto done;
}
if (vin->state == STOPPING) {
vin_dbg(vin, "IRQ while state stopping\n");
goto done;
}
vnms = rvin_read(vin, VNMS_REG);
slot = rvin_get_active_slot(vin, vnms);
sequence = vin->sequence++;
vin_dbg(vin, "IRQ %02d: %d\tbuf0: %c buf1: %c buf2: %c\tmore: %d\n",
sequence, slot,
slot == 0 ? 'x' : vin->queue_buf[0] != NULL ? '1' : '0',
slot == 1 ? 'x' : vin->queue_buf[1] != NULL ? '1' : '0',
slot == 2 ? 'x' : vin->queue_buf[2] != NULL ? '1' : '0',
!list_empty(&vin->buf_list));
if (WARN_ON((vin->queue_buf[slot] == NULL)))
goto done;
vin->queue_buf[slot]->field = rvin_get_active_field(vin, vnms);
vin->queue_buf[slot]->sequence = sequence;
vin->queue_buf[slot]->vb2_buf.timestamp = ktime_get_ns();
vb2_buffer_done(&vin->queue_buf[slot]->vb2_buf, VB2_BUF_STATE_DONE);
vin->queue_buf[slot] = NULL;
if (!rvin_fill_hw(vin)) {
vin->state = STALLED;
if (vin->continuous) {
rvin_capture_off(vin);
vin_dbg(vin, "IRQ %02d: hw not ready stop\n", sequence);
}
} else {
if (!vin->continuous)
rvin_capture_on(vin);
}
done:
spin_unlock_irqrestore(&vin->qlock, flags);
return IRQ_RETVAL(handled);
}
static void return_all_buffers(struct rvin_dev *vin,
enum vb2_buffer_state state)
{
struct rvin_buffer *buf, *node;
int i;
for (i = 0; i < HW_BUFFER_NUM; i++) {
if (vin->queue_buf[i]) {
vb2_buffer_done(&vin->queue_buf[i]->vb2_buf,
state);
vin->queue_buf[i] = NULL;
}
}
list_for_each_entry_safe(buf, node, &vin->buf_list, list) {
vb2_buffer_done(&buf->vb.vb2_buf, state);
list_del(&buf->list);
}
}
static int rvin_queue_setup(struct vb2_queue *vq, unsigned int *nbuffers,
unsigned int *nplanes, unsigned int sizes[],
struct device *alloc_devs[])
{
struct rvin_dev *vin = vb2_get_drv_priv(vq);
if (*nplanes)
return sizes[0] < vin->format.sizeimage ? -EINVAL : 0;
*nplanes = 1;
sizes[0] = vin->format.sizeimage;
return 0;
}
static int rvin_buffer_prepare(struct vb2_buffer *vb)
{
struct rvin_dev *vin = vb2_get_drv_priv(vb->vb2_queue);
unsigned long size = vin->format.sizeimage;
if (vb2_plane_size(vb, 0) < size) {
vin_err(vin, "buffer too small (%lu < %lu)\n",
vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, size);
return 0;
}
static void rvin_buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct rvin_dev *vin = vb2_get_drv_priv(vb->vb2_queue);
unsigned long flags;
spin_lock_irqsave(&vin->qlock, flags);
list_add_tail(to_buf_list(vbuf), &vin->buf_list);
if (vin->state == STALLED)
if (rvin_fill_hw(vin))
rvin_capture_on(vin);
spin_unlock_irqrestore(&vin->qlock, flags);
}
static int rvin_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct rvin_dev *vin = vb2_get_drv_priv(vq);
struct v4l2_subdev *sd;
unsigned long flags;
int ret;
sd = vin_to_source(vin);
v4l2_subdev_call(sd, video, s_stream, 1);
spin_lock_irqsave(&vin->qlock, flags);
vin->state = RUNNING;
vin->sequence = 0;
vin->continuous = count > HW_BUFFER_NUM;
if (!rvin_fill_hw(vin)) {
vin_err(vin, "HW not ready to start, not enough buffers available\n");
ret = -EINVAL;
goto out;
}
ret = rvin_capture_start(vin);
out:
if (ret) {
return_all_buffers(vin, VB2_BUF_STATE_QUEUED);
v4l2_subdev_call(sd, video, s_stream, 0);
}
spin_unlock_irqrestore(&vin->qlock, flags);
return ret;
}
static void rvin_stop_streaming(struct vb2_queue *vq)
{
struct rvin_dev *vin = vb2_get_drv_priv(vq);
struct v4l2_subdev *sd;
unsigned long flags;
int retries = 0;
spin_lock_irqsave(&vin->qlock, flags);
vin->state = STOPPING;
while (retries++ < RVIN_RETRIES) {
rvin_capture_stop(vin);
if (!rvin_capture_active(vin)) {
vin->state = STOPPED;
break;
}
spin_unlock_irqrestore(&vin->qlock, flags);
msleep(RVIN_TIMEOUT_MS);
spin_lock_irqsave(&vin->qlock, flags);
}
if (vin->state != STOPPED) {
vin_err(vin, "Failed stop HW, something is seriously broken\n");
vin->state = STOPPED;
}
return_all_buffers(vin, VB2_BUF_STATE_ERROR);
spin_unlock_irqrestore(&vin->qlock, flags);
sd = vin_to_source(vin);
v4l2_subdev_call(sd, video, s_stream, 0);
rvin_disable_interrupts(vin);
}
void rvin_dma_remove(struct rvin_dev *vin)
{
mutex_destroy(&vin->lock);
v4l2_device_unregister(&vin->v4l2_dev);
}
int rvin_dma_probe(struct rvin_dev *vin, int irq)
{
struct vb2_queue *q = &vin->queue;
int i, ret;
ret = v4l2_device_register(vin->dev, &vin->v4l2_dev);
if (ret)
return ret;
mutex_init(&vin->lock);
INIT_LIST_HEAD(&vin->buf_list);
spin_lock_init(&vin->qlock);
vin->state = STOPPED;
for (i = 0; i < HW_BUFFER_NUM; i++)
vin->queue_buf[i] = NULL;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_READ | VB2_DMABUF;
q->lock = &vin->lock;
q->drv_priv = vin;
q->buf_struct_size = sizeof(struct rvin_buffer);
q->ops = &rvin_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
q->dev = vin->dev;
ret = vb2_queue_init(q);
if (ret < 0) {
vin_err(vin, "failed to initialize VB2 queue\n");
goto error;
}
ret = devm_request_irq(vin->dev, irq, rvin_irq, IRQF_SHARED,
KBUILD_MODNAME, vin);
if (ret) {
vin_err(vin, "failed to request irq\n");
goto error;
}
return 0;
error:
rvin_dma_remove(vin);
return ret;
}
