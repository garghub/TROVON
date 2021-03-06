static struct via_format *via_find_format(u32 pixelformat)
{
unsigned i;
for (i = 0; i < N_VIA_FMTS; i++)
if (via_formats[i].pixelformat == pixelformat)
return via_formats + i;
return via_formats;
}
static int via_sensor_power_setup(struct via_camera *cam)
{
int ret;
cam->power_gpio = viafb_gpio_lookup("VGPIO3");
cam->reset_gpio = viafb_gpio_lookup("VGPIO2");
if (cam->power_gpio < 0 || cam->reset_gpio < 0) {
dev_err(&cam->platdev->dev, "Unable to find GPIO lines\n");
return -EINVAL;
}
ret = gpio_request(cam->power_gpio, "viafb-camera");
if (ret) {
dev_err(&cam->platdev->dev, "Unable to request power GPIO\n");
return ret;
}
ret = gpio_request(cam->reset_gpio, "viafb-camera");
if (ret) {
dev_err(&cam->platdev->dev, "Unable to request reset GPIO\n");
gpio_free(cam->power_gpio);
return ret;
}
gpio_direction_output(cam->power_gpio, 0);
gpio_direction_output(cam->reset_gpio, 0);
return 0;
}
static void via_sensor_power_up(struct via_camera *cam)
{
gpio_set_value(cam->power_gpio, 1);
gpio_set_value(cam->reset_gpio, 0);
msleep(20);
gpio_set_value(cam->reset_gpio, 1);
msleep(20);
}
static void via_sensor_power_down(struct via_camera *cam)
{
gpio_set_value(cam->power_gpio, 0);
gpio_set_value(cam->reset_gpio, 0);
}
static void via_sensor_power_release(struct via_camera *cam)
{
via_sensor_power_down(cam);
gpio_free(cam->power_gpio);
gpio_free(cam->reset_gpio);
}
static int viacam_set_flip(struct via_camera *cam)
{
struct v4l2_control ctrl;
memset(&ctrl, 0, sizeof(ctrl));
ctrl.id = V4L2_CID_VFLIP;
ctrl.value = flip_image;
return sensor_call(cam, core, s_ctrl, &ctrl);
}
static int viacam_configure_sensor(struct via_camera *cam)
{
struct v4l2_mbus_framefmt mbus_fmt;
int ret;
v4l2_fill_mbus_format(&mbus_fmt, &cam->sensor_format, cam->mbus_code);
ret = sensor_call(cam, core, init, 0);
if (ret == 0)
ret = sensor_call(cam, video, s_mbus_fmt, &mbus_fmt);
if (ret == 0)
ret = viacam_set_flip(cam);
return ret;
}
static inline void viacam_write_reg(struct via_camera *cam,
int reg, int value)
{
iowrite32(value, cam->mmio + reg);
}
static inline int viacam_read_reg(struct via_camera *cam, int reg)
{
return ioread32(cam->mmio + reg);
}
static inline void viacam_write_reg_mask(struct via_camera *cam,
int reg, int value, int mask)
{
int tmp = viacam_read_reg(cam, reg);
tmp = (tmp & ~mask) | (value & mask);
viacam_write_reg(cam, reg, tmp);
}
static irqreturn_t viacam_quick_irq(int irq, void *data)
{
struct via_camera *cam = data;
irqreturn_t ret = IRQ_NONE;
int icv;
spin_lock(&cam->viadev->reg_lock);
icv = viacam_read_reg(cam, VCR_INTCTRL);
if (icv & VCR_IC_EAV) {
icv |= VCR_IC_EAV|VCR_IC_EVBI|VCR_IC_FFULL;
viacam_write_reg(cam, VCR_INTCTRL, icv);
ret = IRQ_WAKE_THREAD;
}
spin_unlock(&cam->viadev->reg_lock);
return ret;
}
static struct videobuf_buffer *viacam_next_buffer(struct via_camera *cam)
{
unsigned long flags;
struct videobuf_buffer *buf = NULL;
spin_lock_irqsave(&cam->viadev->reg_lock, flags);
if (cam->opstate != S_RUNNING)
goto out;
if (list_empty(&cam->buffer_queue))
goto out;
buf = list_entry(cam->buffer_queue.next, struct videobuf_buffer, queue);
if (!waitqueue_active(&buf->done)) {
buf = NULL;
goto out;
}
list_del(&buf->queue);
buf->state = VIDEOBUF_ACTIVE;
out:
spin_unlock_irqrestore(&cam->viadev->reg_lock, flags);
return buf;
}
static irqreturn_t viacam_irq(int irq, void *data)
{
int bufn;
struct videobuf_buffer *vb;
struct via_camera *cam = data;
struct videobuf_dmabuf *vdma;
vb = viacam_next_buffer(cam);
if (vb == NULL)
goto done;
bufn = (viacam_read_reg(cam, VCR_INTCTRL) & VCR_IC_ACTBUF) >> 3;
bufn -= 1;
if (bufn < 0)
bufn = cam->n_cap_bufs - 1;
vdma = videobuf_to_dma(vb);
viafb_dma_copy_out_sg(cam->cb_offsets[bufn], vdma->sglist, vdma->sglen);
vb->state = VIDEOBUF_DONE;
vb->size = cam->user_format.sizeimage;
wake_up(&vb->done);
done:
return IRQ_HANDLED;
}
static void viacam_int_enable(struct via_camera *cam)
{
viacam_write_reg(cam, VCR_INTCTRL,
VCR_IC_INTEN|VCR_IC_EAV|VCR_IC_EVBI|VCR_IC_FFULL);
viafb_irq_enable(VDE_I_C0AVEN);
}
static void viacam_int_disable(struct via_camera *cam)
{
viafb_irq_disable(VDE_I_C0AVEN);
viacam_write_reg(cam, VCR_INTCTRL, 0);
}
static int viacam_ctlr_cbufs(struct via_camera *cam)
{
int nbuf = cam->viadev->camera_fbmem_size/cam->sensor_format.sizeimage;
int i;
unsigned int offset;
if (nbuf >= 3) {
cam->n_cap_bufs = 3;
viacam_write_reg_mask(cam, VCR_CAPINTC, VCR_CI_3BUFS,
VCR_CI_3BUFS);
} else if (nbuf == 2) {
cam->n_cap_bufs = 2;
viacam_write_reg_mask(cam, VCR_CAPINTC, 0, VCR_CI_3BUFS);
} else {
cam_warn(cam, "Insufficient frame buffer memory\n");
return -ENOMEM;
}
offset = cam->fb_offset;
for (i = 0; i < cam->n_cap_bufs; i++) {
cam->cb_offsets[i] = offset;
cam->cb_addrs[i] = cam->fbmem + offset;
viacam_write_reg(cam, VCR_VBUF1 + i*4, offset & VCR_VBUF_MASK);
offset += cam->sensor_format.sizeimage;
}
return 0;
}
static void viacam_set_scale(struct via_camera *cam)
{
unsigned int avscale;
int sf;
if (cam->user_format.width == VGA_WIDTH)
avscale = 0;
else {
sf = (cam->user_format.width*2048)/VGA_WIDTH;
avscale = VCR_AVS_HEN | sf;
}
if (cam->user_format.height < VGA_HEIGHT) {
sf = (1024*cam->user_format.height)/VGA_HEIGHT;
avscale |= VCR_AVS_VEN | (sf << 16);
}
viacam_write_reg(cam, VCR_AVSCALE, avscale);
}
static void viacam_ctlr_image(struct via_camera *cam)
{
int cicreg;
viacam_write_reg(cam, VCR_CAPINTC, ~(VCR_CI_ENABLE|VCR_CI_CLKEN));
viacam_write_reg(cam, VCR_HORRANGE, 0x06200120);
viacam_write_reg(cam, VCR_VERTRANGE, 0x01de0000);
viacam_set_scale(cam);
viacam_write_reg(cam, VCR_MAXDATA,
(cam->sensor_format.height << 16) |
(cam->sensor_format.bytesperline >> 3));
viacam_write_reg(cam, VCR_MAXVBI, 0);
viacam_write_reg(cam, VCR_VSTRIDE,
cam->user_format.bytesperline & VCR_VS_STRIDE);
cicreg = VCR_CI_CLKEN |
0x08000000 |
VCR_CI_FLDINV |
VCR_CI_VREFINV |
VCR_CI_DIBOTH |
VCR_CI_CCIR601_8;
if (cam->n_cap_bufs == 3)
cicreg |= VCR_CI_3BUFS;
if (cam->user_format.pixelformat == V4L2_PIX_FMT_YUYV)
cicreg |= VCR_CI_YUYV;
else
cicreg |= VCR_CI_UYVY;
viacam_write_reg(cam, VCR_CAPINTC, cicreg);
}
static int viacam_config_controller(struct via_camera *cam)
{
int ret;
unsigned long flags;
spin_lock_irqsave(&cam->viadev->reg_lock, flags);
ret = viacam_ctlr_cbufs(cam);
if (!ret)
viacam_ctlr_image(cam);
spin_unlock_irqrestore(&cam->viadev->reg_lock, flags);
clear_bit(CF_CONFIG_NEEDED, &cam->flags);
return ret;
}
static void viacam_start_engine(struct via_camera *cam)
{
spin_lock_irq(&cam->viadev->reg_lock);
cam->next_buf = 0;
viacam_write_reg_mask(cam, VCR_CAPINTC, VCR_CI_ENABLE, VCR_CI_ENABLE);
viacam_int_enable(cam);
(void) viacam_read_reg(cam, VCR_CAPINTC);
cam->opstate = S_RUNNING;
spin_unlock_irq(&cam->viadev->reg_lock);
}
static void viacam_stop_engine(struct via_camera *cam)
{
spin_lock_irq(&cam->viadev->reg_lock);
viacam_int_disable(cam);
viacam_write_reg_mask(cam, VCR_CAPINTC, 0, VCR_CI_ENABLE);
(void) viacam_read_reg(cam, VCR_CAPINTC);
cam->opstate = S_IDLE;
spin_unlock_irq(&cam->viadev->reg_lock);
}
static int viacam_vb_buf_setup(struct videobuf_queue *q,
unsigned int *count, unsigned int *size)
{
struct via_camera *cam = q->priv_data;
*size = cam->user_format.sizeimage;
if (*count == 0 || *count > 6)
*count = 6;
return 0;
}
static int viacam_vb_buf_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb, enum v4l2_field field)
{
struct via_camera *cam = q->priv_data;
vb->size = cam->user_format.sizeimage;
vb->width = cam->user_format.width;
vb->height = cam->user_format.height;
vb->field = field;
if (vb->state == VIDEOBUF_NEEDS_INIT) {
int ret = videobuf_iolock(q, vb, NULL);
if (ret)
return ret;
}
vb->state = VIDEOBUF_PREPARED;
return 0;
}
static void viacam_vb_buf_queue(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct via_camera *cam = q->priv_data;
vb->state = VIDEOBUF_QUEUED;
list_add_tail(&vb->queue, &cam->buffer_queue);
}
static void viacam_vb_buf_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct via_camera *cam = q->priv_data;
videobuf_dma_unmap(&cam->platdev->dev, videobuf_to_dma(vb));
videobuf_dma_free(videobuf_to_dma(vb));
vb->state = VIDEOBUF_NEEDS_INIT;
}
static int viacam_open(struct file *filp)
{
struct via_camera *cam = video_drvdata(filp);
filp->private_data = cam;
mutex_lock(&cam->lock);
if (cam->users == 0) {
int ret = viafb_request_dma();
if (ret) {
mutex_unlock(&cam->lock);
return ret;
}
via_sensor_power_up(cam);
set_bit(CF_CONFIG_NEEDED, &cam->flags);
videobuf_queue_sg_init(&cam->vb_queue, &viacam_vb_ops,
&cam->platdev->dev, &cam->viadev->reg_lock,
V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_NONE,
sizeof(struct videobuf_buffer), cam, NULL);
}
(cam->users)++;
mutex_unlock(&cam->lock);
return 0;
}
static int viacam_release(struct file *filp)
{
struct via_camera *cam = video_drvdata(filp);
mutex_lock(&cam->lock);
(cam->users)--;
if (filp == cam->owner) {
videobuf_stop(&cam->vb_queue);
if (cam->opstate != S_IDLE)
viacam_stop_engine(cam);
cam->owner = NULL;
}
if (cam->users == 0) {
videobuf_mmap_free(&cam->vb_queue);
via_sensor_power_down(cam);
viafb_release_dma();
}
mutex_unlock(&cam->lock);
return 0;
}
static ssize_t viacam_read(struct file *filp, char __user *buffer,
size_t len, loff_t *pos)
{
struct via_camera *cam = video_drvdata(filp);
int ret;
mutex_lock(&cam->lock);
if (cam->owner && cam->owner != filp) {
ret = -EBUSY;
goto out_unlock;
}
cam->owner = filp;
if (test_bit(CF_CONFIG_NEEDED, &cam->flags)) {
ret = viacam_configure_sensor(cam);
if (!ret)
ret = viacam_config_controller(cam);
if (ret)
goto out_unlock;
}
INIT_LIST_HEAD(&cam->buffer_queue);
viacam_start_engine(cam);
ret = videobuf_read_stream(&cam->vb_queue, buffer, len, pos, 0,
filp->f_flags & O_NONBLOCK);
viacam_stop_engine(cam);
out_unlock:
mutex_unlock(&cam->lock);
return ret;
}
static unsigned int viacam_poll(struct file *filp, struct poll_table_struct *pt)
{
struct via_camera *cam = video_drvdata(filp);
return videobuf_poll_stream(filp, &cam->vb_queue, pt);
}
static int viacam_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct via_camera *cam = video_drvdata(filp);
return videobuf_mmap_mapper(&cam->vb_queue, vma);
}
static int viacam_g_chip_ident(struct file *file, void *priv,
struct v4l2_dbg_chip_ident *ident)
{
struct via_camera *cam = priv;
ident->ident = V4L2_IDENT_NONE;
ident->revision = 0;
if (v4l2_chip_match_host(&ident->match)) {
ident->ident = V4L2_IDENT_VIA_VX855;
return 0;
}
return sensor_call(cam, core, g_chip_ident, ident);
}
static int viacam_queryctrl(struct file *filp, void *priv,
struct v4l2_queryctrl *qc)
{
struct via_camera *cam = priv;
int ret;
mutex_lock(&cam->lock);
ret = sensor_call(cam, core, queryctrl, qc);
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_g_ctrl(struct file *filp, void *priv,
struct v4l2_control *ctrl)
{
struct via_camera *cam = priv;
int ret;
mutex_lock(&cam->lock);
ret = sensor_call(cam, core, g_ctrl, ctrl);
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_s_ctrl(struct file *filp, void *priv,
struct v4l2_control *ctrl)
{
struct via_camera *cam = priv;
int ret;
mutex_lock(&cam->lock);
ret = sensor_call(cam, core, s_ctrl, ctrl);
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_enum_input(struct file *filp, void *priv,
struct v4l2_input *input)
{
if (input->index != 0)
return -EINVAL;
input->type = V4L2_INPUT_TYPE_CAMERA;
input->std = V4L2_STD_ALL;
strcpy(input->name, "Camera");
return 0;
}
static int viacam_g_input(struct file *filp, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int viacam_s_input(struct file *filp, void *priv, unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int viacam_s_std(struct file *filp, void *priv, v4l2_std_id *std)
{
return 0;
}
static int viacam_enum_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_fmtdesc *fmt)
{
if (fmt->index >= N_VIA_FMTS)
return -EINVAL;
strlcpy(fmt->description, via_formats[fmt->index].desc,
sizeof(fmt->description));
fmt->pixelformat = via_formats[fmt->index].pixelformat;
return 0;
}
static void viacam_fmt_pre(struct v4l2_pix_format *userfmt,
struct v4l2_pix_format *sensorfmt)
{
*sensorfmt = *userfmt;
if (userfmt->width < QCIF_WIDTH || userfmt->height < QCIF_HEIGHT) {
userfmt->width = QCIF_WIDTH;
userfmt->height = QCIF_HEIGHT;
}
if (userfmt->width > VGA_WIDTH || userfmt->height > VGA_HEIGHT) {
userfmt->width = VGA_WIDTH;
userfmt->height = VGA_HEIGHT;
}
sensorfmt->width = VGA_WIDTH;
sensorfmt->height = VGA_HEIGHT;
}
static void viacam_fmt_post(struct v4l2_pix_format *userfmt,
struct v4l2_pix_format *sensorfmt)
{
struct via_format *f = via_find_format(userfmt->pixelformat);
sensorfmt->bytesperline = sensorfmt->width * f->bpp;
sensorfmt->sizeimage = sensorfmt->height * sensorfmt->bytesperline;
userfmt->pixelformat = sensorfmt->pixelformat;
userfmt->field = sensorfmt->field;
userfmt->bytesperline = 2 * userfmt->width;
userfmt->sizeimage = userfmt->bytesperline * userfmt->height;
}
static int viacam_do_try_fmt(struct via_camera *cam,
struct v4l2_pix_format *upix, struct v4l2_pix_format *spix)
{
int ret;
struct v4l2_mbus_framefmt mbus_fmt;
struct via_format *f = via_find_format(upix->pixelformat);
upix->pixelformat = f->pixelformat;
viacam_fmt_pre(upix, spix);
v4l2_fill_mbus_format(&mbus_fmt, upix, f->mbus_code);
ret = sensor_call(cam, video, try_mbus_fmt, &mbus_fmt);
v4l2_fill_pix_format(spix, &mbus_fmt);
viacam_fmt_post(upix, spix);
return ret;
}
static int viacam_try_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_format *fmt)
{
struct via_camera *cam = priv;
struct v4l2_format sfmt;
int ret;
mutex_lock(&cam->lock);
ret = viacam_do_try_fmt(cam, &fmt->fmt.pix, &sfmt.fmt.pix);
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_g_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_format *fmt)
{
struct via_camera *cam = priv;
mutex_lock(&cam->lock);
fmt->fmt.pix = cam->user_format;
mutex_unlock(&cam->lock);
return 0;
}
static int viacam_s_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_format *fmt)
{
struct via_camera *cam = priv;
int ret;
struct v4l2_format sfmt;
struct via_format *f = via_find_format(fmt->fmt.pix.pixelformat);
mutex_lock(&cam->lock);
if (cam->opstate != S_IDLE) {
ret = -EBUSY;
goto out;
}
ret = viacam_do_try_fmt(cam, &fmt->fmt.pix, &sfmt.fmt.pix);
if (ret)
goto out;
cam->user_format = fmt->fmt.pix;
cam->sensor_format = sfmt.fmt.pix;
cam->mbus_code = f->mbus_code;
ret = viacam_configure_sensor(cam);
if (!ret)
ret = viacam_config_controller(cam);
out:
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_querycap(struct file *filp, void *priv,
struct v4l2_capability *cap)
{
strcpy(cap->driver, "via-camera");
strcpy(cap->card, "via-camera");
cap->version = 1;
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
return 0;
}
static int viacam_reqbufs(struct file *filp, void *priv,
struct v4l2_requestbuffers *rb)
{
struct via_camera *cam = priv;
return videobuf_reqbufs(&cam->vb_queue, rb);
}
static int viacam_querybuf(struct file *filp, void *priv,
struct v4l2_buffer *buf)
{
struct via_camera *cam = priv;
return videobuf_querybuf(&cam->vb_queue, buf);
}
static int viacam_qbuf(struct file *filp, void *priv, struct v4l2_buffer *buf)
{
struct via_camera *cam = priv;
return videobuf_qbuf(&cam->vb_queue, buf);
}
static int viacam_dqbuf(struct file *filp, void *priv, struct v4l2_buffer *buf)
{
struct via_camera *cam = priv;
return videobuf_dqbuf(&cam->vb_queue, buf, filp->f_flags & O_NONBLOCK);
}
static int viacam_streamon(struct file *filp, void *priv, enum v4l2_buf_type t)
{
struct via_camera *cam = priv;
int ret = 0;
if (t != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
mutex_lock(&cam->lock);
if (cam->opstate != S_IDLE) {
ret = -EBUSY;
goto out;
}
if (cam->owner && cam->owner != filp) {
ret = -EBUSY;
goto out;
}
cam->owner = filp;
if (test_bit(CF_CONFIG_NEEDED, &cam->flags)) {
ret = viacam_configure_sensor(cam);
if (ret)
goto out;
ret = viacam_config_controller(cam);
if (ret)
goto out;
}
pm_qos_add_request(&cam->qos_request, PM_QOS_CPU_DMA_LATENCY, 50);
INIT_LIST_HEAD(&cam->buffer_queue);
ret = videobuf_streamon(&cam->vb_queue);
if (!ret)
viacam_start_engine(cam);
out:
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_streamoff(struct file *filp, void *priv, enum v4l2_buf_type t)
{
struct via_camera *cam = priv;
int ret;
if (t != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
mutex_lock(&cam->lock);
if (cam->opstate != S_RUNNING) {
ret = -EINVAL;
goto out;
}
pm_qos_remove_request(&cam->qos_request);
viacam_stop_engine(cam);
ret = videobuf_streamoff(&cam->vb_queue);
INIT_LIST_HEAD(&cam->buffer_queue);
out:
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_g_parm(struct file *filp, void *priv,
struct v4l2_streamparm *parm)
{
struct via_camera *cam = priv;
int ret;
mutex_lock(&cam->lock);
ret = sensor_call(cam, video, g_parm, parm);
mutex_unlock(&cam->lock);
parm->parm.capture.readbuffers = cam->n_cap_bufs;
return ret;
}
static int viacam_s_parm(struct file *filp, void *priv,
struct v4l2_streamparm *parm)
{
struct via_camera *cam = priv;
int ret;
mutex_lock(&cam->lock);
ret = sensor_call(cam, video, s_parm, parm);
mutex_unlock(&cam->lock);
parm->parm.capture.readbuffers = cam->n_cap_bufs;
return ret;
}
static int viacam_enum_framesizes(struct file *filp, void *priv,
struct v4l2_frmsizeenum *sizes)
{
if (sizes->index != 0)
return -EINVAL;
sizes->type = V4L2_FRMSIZE_TYPE_CONTINUOUS;
sizes->stepwise.min_width = QCIF_WIDTH;
sizes->stepwise.min_height = QCIF_HEIGHT;
sizes->stepwise.max_width = VGA_WIDTH;
sizes->stepwise.max_height = VGA_HEIGHT;
sizes->stepwise.step_width = sizes->stepwise.step_height = 1;
return 0;
}
static int viacam_enum_frameintervals(struct file *filp, void *priv,
struct v4l2_frmivalenum *interval)
{
struct via_camera *cam = priv;
int ret;
mutex_lock(&cam->lock);
ret = sensor_call(cam, video, enum_frameintervals, interval);
mutex_unlock(&cam->lock);
return ret;
}
static int viacam_suspend(void *priv)
{
struct via_camera *cam = priv;
enum viacam_opstate state = cam->opstate;
if (cam->opstate != S_IDLE) {
viacam_stop_engine(cam);
cam->opstate = state;
}
return 0;
}
static int viacam_resume(void *priv)
{
struct via_camera *cam = priv;
int ret = 0;
via_write_reg_mask(VIASR, 0x78, 0, 0x80);
via_write_reg_mask(VIASR, 0x1e, 0xc0, 0xc0);
viacam_int_disable(cam);
set_bit(CF_CONFIG_NEEDED, &cam->flags);
if (cam->users > 0)
via_sensor_power_up(cam);
else
via_sensor_power_down(cam);
if (cam->opstate != S_IDLE) {
mutex_lock(&cam->lock);
ret = viacam_configure_sensor(cam);
if (!ret)
ret = viacam_config_controller(cam);
mutex_unlock(&cam->lock);
if (!ret)
viacam_start_engine(cam);
}
return ret;
}
static __devinit bool viacam_serial_is_enabled(void)
{
struct pci_bus *pbus = pci_find_bus(0, 0);
u8 cbyte;
if (!pbus)
return false;
pci_bus_read_config_byte(pbus, VIACAM_SERIAL_DEVFN,
VIACAM_SERIAL_CREG, &cbyte);
if ((cbyte & VIACAM_SERIAL_BIT) == 0)
return false;
if (override_serial == 0) {
printk(KERN_NOTICE "Via camera: serial port is enabled, " \
"refusing to load.\n");
printk(KERN_NOTICE "Specify override_serial=1 to force " \
"module loading.\n");
return true;
}
printk(KERN_NOTICE "Via camera: overriding serial port\n");
pci_bus_write_config_byte(pbus, VIACAM_SERIAL_DEVFN,
VIACAM_SERIAL_CREG, cbyte & ~VIACAM_SERIAL_BIT);
return false;
}
static __devinit int viacam_probe(struct platform_device *pdev)
{
int ret;
struct i2c_adapter *sensor_adapter;
struct viafb_dev *viadev = pdev->dev.platform_data;
struct via_camera *cam;
if (viadev->camera_fbmem_size < (VGA_HEIGHT*VGA_WIDTH*4)) {
printk(KERN_ERR "viacam: insufficient FB memory reserved\n");
return -ENOMEM;
}
if (viadev->engine_mmio == NULL) {
printk(KERN_ERR "viacam: No I/O memory, so no pictures\n");
return -ENOMEM;
}
if (machine_is_olpc() && viacam_serial_is_enabled())
return -EBUSY;
cam = kzalloc (sizeof(struct via_camera), GFP_KERNEL);
if (cam == NULL)
return -ENOMEM;
via_cam_info = cam;
cam->platdev = pdev;
cam->viadev = viadev;
cam->users = 0;
cam->owner = NULL;
cam->opstate = S_IDLE;
cam->user_format = cam->sensor_format = viacam_def_pix_format;
mutex_init(&cam->lock);
INIT_LIST_HEAD(&cam->buffer_queue);
cam->mmio = viadev->engine_mmio;
cam->fbmem = viadev->fbmem;
cam->fb_offset = viadev->camera_fbmem_offset;
cam->flags = 1 << CF_CONFIG_NEEDED;
cam->mbus_code = via_def_mbus_code;
ret = v4l2_device_register(&pdev->dev, &cam->v4l2_dev);
if (ret) {
dev_err(&pdev->dev, "Unable to register v4l2 device\n");
return ret;
}
pdev->dev.dma_mask = &viadev->pdev->dma_mask;
dma_set_mask(&pdev->dev, 0xffffffff);
via_write_reg_mask(VIASR, 0x78, 0, 0x80);
via_write_reg_mask(VIASR, 0x1e, 0xc0, 0xc0);
ret = via_sensor_power_setup(cam);
if (ret)
goto out_unregister;
via_sensor_power_up(cam);
sensor_adapter = viafb_find_i2c_adapter(VIA_PORT_31);
cam->sensor = v4l2_i2c_new_subdev(&cam->v4l2_dev, sensor_adapter,
"ov7670", 0x42 >> 1, NULL);
if (cam->sensor == NULL) {
dev_err(&pdev->dev, "Unable to find the sensor!\n");
ret = -ENODEV;
goto out_power_down;
}
viacam_int_disable(cam);
ret = request_threaded_irq(viadev->pdev->irq, viacam_quick_irq,
viacam_irq, IRQF_SHARED, "via-camera", cam);
if (ret)
goto out_power_down;
cam->vdev = viacam_v4l_template;
cam->vdev.v4l2_dev = &cam->v4l2_dev;
ret = video_register_device(&cam->vdev, VFL_TYPE_GRABBER, -1);
if (ret)
goto out_irq;
video_set_drvdata(&cam->vdev, cam);
#ifdef CONFIG_PM
viacam_pm_hooks.private = cam;
viafb_pm_register(&viacam_pm_hooks);
#endif
via_sensor_power_down(cam);
return 0;
out_irq:
free_irq(viadev->pdev->irq, cam);
out_power_down:
via_sensor_power_release(cam);
out_unregister:
v4l2_device_unregister(&cam->v4l2_dev);
return ret;
}
static __devexit int viacam_remove(struct platform_device *pdev)
{
struct via_camera *cam = via_cam_info;
struct viafb_dev *viadev = pdev->dev.platform_data;
video_unregister_device(&cam->vdev);
v4l2_device_unregister(&cam->v4l2_dev);
free_irq(viadev->pdev->irq, cam);
via_sensor_power_release(cam);
via_cam_info = NULL;
return 0;
}
static int viacam_init(void)
{
return platform_driver_register(&viacam_driver);
}
static void viacam_exit(void)
{
platform_driver_unregister(&viacam_driver);
}
