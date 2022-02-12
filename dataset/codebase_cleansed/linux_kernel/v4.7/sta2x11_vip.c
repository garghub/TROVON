static inline struct vip_buffer *to_vip_buffer(struct vb2_v4l2_buffer *vb2)
{
return container_of(vb2, struct vip_buffer, vb);
}
static inline void reg_write(struct sta2x11_vip *vip, unsigned int reg, u32 val)
{
iowrite32((val), (vip->iomem)+(reg));
}
static inline u32 reg_read(struct sta2x11_vip *vip, unsigned int reg)
{
return ioread32((vip->iomem)+(reg));
}
static void start_dma(struct sta2x11_vip *vip, struct vip_buffer *vip_buf)
{
unsigned long offset = 0;
if (vip->format.field == V4L2_FIELD_INTERLACED)
offset = vip->format.width * 2;
spin_lock_irq(&vip->slock);
reg_write(vip, DVP_CTL, reg_read(vip, DVP_CTL) | DVP_CTL_ENA);
reg_write(vip, DVP_VTP, (u32)vip_buf->dma);
reg_write(vip, DVP_VBP, (u32)vip_buf->dma + offset);
spin_unlock_irq(&vip->slock);
}
static void vip_active_buf_next(struct sta2x11_vip *vip)
{
spin_lock(&vip->lock);
if (list_empty(&vip->buffer_list)) {
spin_unlock(&vip->lock);
return;
}
vip->active = list_first_entry(&vip->buffer_list,
struct vip_buffer,
list);
vip->tcount = 0;
vip->bcount = 0;
spin_unlock(&vip->lock);
if (vb2_is_streaming(&vip->vb_vidq)) {
start_dma(vip, vip->active);
}
}
static int queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct sta2x11_vip *vip = vb2_get_drv_priv(vq);
if (!(*nbuffers) || *nbuffers < MAX_FRAMES)
*nbuffers = MAX_FRAMES;
*nplanes = 1;
sizes[0] = vip->format.sizeimage;
alloc_ctxs[0] = vip->alloc_ctx;
vip->sequence = 0;
vip->active = NULL;
vip->tcount = 0;
vip->bcount = 0;
return 0;
}
static int buffer_init(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vip_buffer *vip_buf = to_vip_buffer(vbuf);
vip_buf->dma = vb2_dma_contig_plane_dma_addr(vb, 0);
INIT_LIST_HEAD(&vip_buf->list);
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct sta2x11_vip *vip = vb2_get_drv_priv(vb->vb2_queue);
struct vip_buffer *vip_buf = to_vip_buffer(vbuf);
unsigned long size;
size = vip->format.sizeimage;
if (vb2_plane_size(vb, 0) < size) {
v4l2_err(&vip->v4l2_dev, "buffer too small (%lu < %lu)\n",
vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(&vip_buf->vb.vb2_buf, 0, size);
return 0;
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct sta2x11_vip *vip = vb2_get_drv_priv(vb->vb2_queue);
struct vip_buffer *vip_buf = to_vip_buffer(vbuf);
spin_lock(&vip->lock);
list_add_tail(&vip_buf->list, &vip->buffer_list);
if (!vip->active) {
vip->active = list_first_entry(&vip->buffer_list,
struct vip_buffer,
list);
if (vb2_is_streaming(&vip->vb_vidq))
start_dma(vip, vip_buf);
}
spin_unlock(&vip->lock);
}
static void buffer_finish(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct sta2x11_vip *vip = vb2_get_drv_priv(vb->vb2_queue);
struct vip_buffer *vip_buf = to_vip_buffer(vbuf);
spin_lock(&vip->lock);
list_del_init(&vip_buf->list);
spin_unlock(&vip->lock);
if (vb2_is_streaming(vb->vb2_queue))
vip_active_buf_next(vip);
}
static int start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct sta2x11_vip *vip = vb2_get_drv_priv(vq);
spin_lock_irq(&vip->slock);
reg_write(vip, DVP_ITM, DVP_IT_VSB | DVP_IT_VST);
spin_unlock_irq(&vip->slock);
if (count)
start_dma(vip, vip->active);
return 0;
}
static void stop_streaming(struct vb2_queue *vq)
{
struct sta2x11_vip *vip = vb2_get_drv_priv(vq);
struct vip_buffer *vip_buf, *node;
reg_write(vip, DVP_CTL, reg_read(vip, DVP_CTL) & ~DVP_CTL_ENA);
reg_write(vip, DVP_ITM, 0);
spin_lock(&vip->lock);
list_for_each_entry_safe(vip_buf, node, &vip->buffer_list, list) {
vb2_buffer_done(&vip_buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
list_del(&vip_buf->list);
}
spin_unlock(&vip->lock);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct sta2x11_vip *vip = video_drvdata(file);
strcpy(cap->driver, KBUILD_MODNAME);
strcpy(cap->card, KBUILD_MODNAME);
snprintf(cap->bus_info, sizeof(cap->bus_info), "PCI:%s",
pci_name(vip->pdev));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_s_std(struct file *file, void *priv, v4l2_std_id std)
{
struct sta2x11_vip *vip = video_drvdata(file);
if (std == V4L2_STD_ALL) {
v4l2_subdev_call(vip->decoder, video, querystd, &std);
if (std == V4L2_STD_UNKNOWN)
return -EIO;
}
if (vip->std != std) {
vip->std = std;
if (V4L2_STD_525_60 & std)
vip->format = formats_60[0];
else
vip->format = formats_50[0];
}
return v4l2_subdev_call(vip->decoder, video, s_std, std);
}
static int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct sta2x11_vip *vip = video_drvdata(file);
*std = vip->std;
return 0;
}
static int vidioc_querystd(struct file *file, void *priv, v4l2_std_id *std)
{
struct sta2x11_vip *vip = video_drvdata(file);
return v4l2_subdev_call(vip->decoder, video, querystd, std);
}
static int vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
if (inp->index > 1)
return -EINVAL;
inp->type = V4L2_INPUT_TYPE_CAMERA;
inp->std = V4L2_STD_ALL;
sprintf(inp->name, "Camera %u", inp->index);
return 0;
}
static int vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
struct sta2x11_vip *vip = video_drvdata(file);
int ret;
if (i > 1)
return -EINVAL;
ret = v4l2_subdev_call(vip->decoder, video, s_routing, i, 0, 0);
if (!ret)
vip->input = i;
return 0;
}
static int vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
struct sta2x11_vip *vip = video_drvdata(file);
*i = vip->input;
return 0;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
strcpy(f->description, "4:2:2, packed, UYVY");
f->pixelformat = V4L2_PIX_FMT_UYVY;
f->flags = 0;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct sta2x11_vip *vip = video_drvdata(file);
int interlace_lim;
if (V4L2_PIX_FMT_UYVY != f->fmt.pix.pixelformat) {
v4l2_warn(&vip->v4l2_dev, "Invalid format, only UYVY supported\n");
return -EINVAL;
}
if (V4L2_STD_525_60 & vip->std)
interlace_lim = 240;
else
interlace_lim = 288;
switch (f->fmt.pix.field) {
default:
case V4L2_FIELD_ANY:
if (interlace_lim < f->fmt.pix.height)
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
else
f->fmt.pix.field = V4L2_FIELD_BOTTOM;
break;
case V4L2_FIELD_TOP:
case V4L2_FIELD_BOTTOM:
if (interlace_lim < f->fmt.pix.height)
f->fmt.pix.height = interlace_lim;
break;
case V4L2_FIELD_INTERLACED:
break;
}
f->fmt.pix.pixelformat = V4L2_PIX_FMT_UYVY;
f->fmt.pix.height &= ~1;
if (2 * interlace_lim < f->fmt.pix.height)
f->fmt.pix.height = 2 * interlace_lim;
if (200 > f->fmt.pix.height)
f->fmt.pix.height = 200;
f->fmt.pix.width = 720;
f->fmt.pix.bytesperline = f->fmt.pix.width * 2;
f->fmt.pix.sizeimage = f->fmt.pix.width * 2 * f->fmt.pix.height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct sta2x11_vip *vip = video_drvdata(file);
unsigned int t_stop, b_stop, pitch;
int ret;
ret = vidioc_try_fmt_vid_cap(file, priv, f);
if (ret)
return ret;
if (vb2_is_busy(&vip->vb_vidq)) {
v4l2_err(&vip->v4l2_dev, "device busy\n");
return -EBUSY;
}
vip->format = f->fmt.pix;
switch (vip->format.field) {
case V4L2_FIELD_INTERLACED:
t_stop = ((vip->format.height / 2 - 1) << 16) |
(2 * vip->format.width - 1);
b_stop = t_stop;
pitch = 4 * vip->format.width;
break;
case V4L2_FIELD_TOP:
t_stop = ((vip->format.height - 1) << 16) |
(2 * vip->format.width - 1);
b_stop = (0 << 16) | (2 * vip->format.width - 1);
pitch = 2 * vip->format.width;
break;
case V4L2_FIELD_BOTTOM:
t_stop = (0 << 16) | (2 * vip->format.width - 1);
b_stop = (vip->format.height << 16) |
(2 * vip->format.width - 1);
pitch = 2 * vip->format.width;
break;
default:
v4l2_err(&vip->v4l2_dev, "unknown field format\n");
return -EINVAL;
}
spin_lock_irq(&vip->slock);
reg_write(vip, DVP_TFO, 0);
reg_write(vip, DVP_BFO, 0);
reg_write(vip, DVP_TFS, t_stop);
reg_write(vip, DVP_BFS, b_stop);
reg_write(vip, DVP_VMP, pitch);
spin_unlock_irq(&vip->slock);
return 0;
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct sta2x11_vip *vip = video_drvdata(file);
f->fmt.pix = vip->format;
return 0;
}
static irqreturn_t vip_irq(int irq, struct sta2x11_vip *vip)
{
unsigned int status;
status = reg_read(vip, DVP_ITS);
if (!status)
return IRQ_NONE;
if (status & DVP_IT_FIFO)
if (vip->overflow++ > 5)
pr_info("VIP: fifo overflow\n");
if ((status & DVP_IT_VST) && (status & DVP_IT_VSB)) {
return IRQ_HANDLED;
}
if (status & DVP_IT_VST)
if ((++vip->tcount) < 2)
return IRQ_HANDLED;
if (status & DVP_IT_VSB) {
vip->bcount++;
return IRQ_HANDLED;
}
if (vip->active) {
reg_write(vip, DVP_CTL, reg_read(vip, DVP_CTL) & ~DVP_CTL_ENA);
vip->active->vb.vb2_buf.timestamp = ktime_get_ns();
vip->active->vb.sequence = vip->sequence++;
vb2_buffer_done(&vip->active->vb.vb2_buf, VB2_BUF_STATE_DONE);
}
return IRQ_HANDLED;
}
static void sta2x11_vip_init_register(struct sta2x11_vip *vip)
{
spin_lock_irq(&vip->slock);
reg_read(vip, DVP_ITS);
reg_write(vip, DVP_HLFLN, DVP_HLFLN_SD);
reg_write(vip, DVP_CTL, DVP_CTL_RST);
reg_write(vip, DVP_CTL, 0);
spin_unlock_irq(&vip->slock);
}
static void sta2x11_vip_clear_register(struct sta2x11_vip *vip)
{
spin_lock_irq(&vip->slock);
reg_write(vip, DVP_ITM, 0);
reg_write(vip, DVP_CTL, DVP_CTL_RST);
reg_write(vip, DVP_CTL, 0);
reg_read(vip, DVP_ITS);
spin_unlock_irq(&vip->slock);
}
static int sta2x11_vip_init_buffer(struct sta2x11_vip *vip)
{
int err;
err = dma_set_coherent_mask(&vip->pdev->dev, DMA_BIT_MASK(29));
if (err) {
v4l2_err(&vip->v4l2_dev, "Cannot configure coherent mask");
return err;
}
memset(&vip->vb_vidq, 0, sizeof(struct vb2_queue));
vip->vb_vidq.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
vip->vb_vidq.io_modes = VB2_MMAP | VB2_READ;
vip->vb_vidq.drv_priv = vip;
vip->vb_vidq.buf_struct_size = sizeof(struct vip_buffer);
vip->vb_vidq.ops = &vip_video_qops;
vip->vb_vidq.mem_ops = &vb2_dma_contig_memops;
vip->vb_vidq.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
err = vb2_queue_init(&vip->vb_vidq);
if (err)
return err;
INIT_LIST_HEAD(&vip->buffer_list);
spin_lock_init(&vip->lock);
vip->alloc_ctx = vb2_dma_contig_init_ctx(&vip->pdev->dev);
if (IS_ERR(vip->alloc_ctx)) {
v4l2_err(&vip->v4l2_dev, "Can't allocate buffer context");
return PTR_ERR(vip->alloc_ctx);
}
return 0;
}
static void sta2x11_vip_release_buffer(struct sta2x11_vip *vip)
{
vb2_dma_contig_cleanup_ctx(vip->alloc_ctx);
}
static int sta2x11_vip_init_controls(struct sta2x11_vip *vip)
{
v4l2_ctrl_handler_init(&vip->ctrl_hdl, 0);
vip->v4l2_dev.ctrl_handler = &vip->ctrl_hdl;
if (vip->ctrl_hdl.error) {
int err = vip->ctrl_hdl.error;
v4l2_ctrl_handler_free(&vip->ctrl_hdl);
return err;
}
return 0;
}
static int vip_gpio_reserve(struct device *dev, int pin, int dir,
const char *name)
{
int ret;
if (pin == -1)
return 0;
ret = gpio_request(pin, name);
if (ret) {
dev_err(dev, "Failed to allocate pin %d (%s)\n", pin, name);
return ret;
}
ret = gpio_direction_output(pin, dir);
if (ret) {
dev_err(dev, "Failed to set direction for pin %d (%s)\n",
pin, name);
gpio_free(pin);
return ret;
}
ret = gpio_export(pin, false);
if (ret) {
dev_err(dev, "Failed to export pin %d (%s)\n", pin, name);
gpio_free(pin);
return ret;
}
return 0;
}
static void vip_gpio_release(struct device *dev, int pin, const char *name)
{
if (pin != -1) {
dev_dbg(dev, "releasing pin %d (%s)\n", pin, name);
gpio_unexport(pin);
gpio_free(pin);
}
}
static int sta2x11_vip_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int ret;
struct sta2x11_vip *vip;
struct vip_config *config;
if (dma_set_mask(&pdev->dev, DMA_BIT_MASK(26))) {
dev_err(&pdev->dev, "26-bit DMA addressing not available\n");
return -EINVAL;
}
ret = pci_enable_device(pdev);
if (ret)
return ret;
config = dev_get_platdata(&pdev->dev);
if (!config) {
dev_info(&pdev->dev, "VIP slot disabled\n");
ret = -EINVAL;
goto disable;
}
ret = vip_gpio_reserve(&pdev->dev, config->pwr_pin, 0,
config->pwr_name);
if (ret)
goto disable;
if (config->reset_pin >= 0) {
ret = vip_gpio_reserve(&pdev->dev, config->reset_pin, 0,
config->reset_name);
if (ret) {
vip_gpio_release(&pdev->dev, config->pwr_pin,
config->pwr_name);
goto disable;
}
}
if (config->pwr_pin != -1) {
usleep_range(5000, 25000);
ret = gpio_direction_output(config->pwr_pin, 1);
}
if (config->reset_pin != -1) {
usleep_range(5000, 25000);
ret = gpio_direction_output(config->reset_pin, 1);
}
usleep_range(5000, 25000);
vip = kzalloc(sizeof(struct sta2x11_vip), GFP_KERNEL);
if (!vip) {
ret = -ENOMEM;
goto release_gpios;
}
vip->pdev = pdev;
vip->std = V4L2_STD_PAL;
vip->format = formats_50[0];
vip->config = config;
ret = sta2x11_vip_init_controls(vip);
if (ret)
goto free_mem;
ret = v4l2_device_register(&pdev->dev, &vip->v4l2_dev);
if (ret)
goto free_mem;
dev_dbg(&pdev->dev, "BAR #0 at 0x%lx 0x%lx irq %d\n",
(unsigned long)pci_resource_start(pdev, 0),
(unsigned long)pci_resource_len(pdev, 0), pdev->irq);
pci_set_master(pdev);
ret = pci_request_regions(pdev, KBUILD_MODNAME);
if (ret)
goto unreg;
vip->iomem = pci_iomap(pdev, 0, 0x100);
if (!vip->iomem) {
ret = -ENOMEM;
goto release;
}
pci_enable_msi(pdev);
ret = sta2x11_vip_init_buffer(vip);
if (ret)
goto unmap;
spin_lock_init(&vip->slock);
ret = request_irq(pdev->irq,
(irq_handler_t) vip_irq,
IRQF_SHARED, KBUILD_MODNAME, vip);
if (ret) {
dev_err(&pdev->dev, "request_irq failed\n");
ret = -ENODEV;
goto release_buf;
}
vip->video_dev = video_dev_template;
vip->video_dev.v4l2_dev = &vip->v4l2_dev;
vip->video_dev.queue = &vip->vb_vidq;
video_set_drvdata(&vip->video_dev, vip);
ret = video_register_device(&vip->video_dev, VFL_TYPE_GRABBER, -1);
if (ret)
goto vrelease;
vip->adapter = i2c_get_adapter(vip->config->i2c_id);
if (!vip->adapter) {
ret = -ENODEV;
dev_err(&pdev->dev, "no I2C adapter found\n");
goto vunreg;
}
vip->decoder = v4l2_i2c_new_subdev(&vip->v4l2_dev, vip->adapter,
"adv7180", vip->config->i2c_addr,
NULL);
if (!vip->decoder) {
ret = -ENODEV;
dev_err(&pdev->dev, "no decoder found\n");
goto vunreg;
}
i2c_put_adapter(vip->adapter);
v4l2_subdev_call(vip->decoder, core, init, 0);
sta2x11_vip_init_register(vip);
dev_info(&pdev->dev, "STA2X11 Video Input Port (VIP) loaded\n");
return 0;
vunreg:
video_set_drvdata(&vip->video_dev, NULL);
vrelease:
video_unregister_device(&vip->video_dev);
free_irq(pdev->irq, vip);
release_buf:
sta2x11_vip_release_buffer(vip);
pci_disable_msi(pdev);
unmap:
vb2_queue_release(&vip->vb_vidq);
pci_iounmap(pdev, vip->iomem);
release:
pci_release_regions(pdev);
unreg:
v4l2_device_unregister(&vip->v4l2_dev);
free_mem:
kfree(vip);
release_gpios:
vip_gpio_release(&pdev->dev, config->reset_pin, config->reset_name);
vip_gpio_release(&pdev->dev, config->pwr_pin, config->pwr_name);
disable:
return ret;
}
static void sta2x11_vip_remove_one(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pdev);
struct sta2x11_vip *vip =
container_of(v4l2_dev, struct sta2x11_vip, v4l2_dev);
sta2x11_vip_clear_register(vip);
video_set_drvdata(&vip->video_dev, NULL);
video_unregister_device(&vip->video_dev);
free_irq(pdev->irq, vip);
pci_disable_msi(pdev);
vb2_queue_release(&vip->vb_vidq);
pci_iounmap(pdev, vip->iomem);
pci_release_regions(pdev);
v4l2_device_unregister(&vip->v4l2_dev);
vip_gpio_release(&pdev->dev, vip->config->pwr_pin,
vip->config->pwr_name);
vip_gpio_release(&pdev->dev, vip->config->reset_pin,
vip->config->reset_name);
kfree(vip);
}
static int sta2x11_vip_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pdev);
struct sta2x11_vip *vip =
container_of(v4l2_dev, struct sta2x11_vip, v4l2_dev);
unsigned long flags;
int i;
spin_lock_irqsave(&vip->slock, flags);
vip->register_save_area[0] = reg_read(vip, DVP_CTL);
reg_write(vip, DVP_CTL, vip->register_save_area[0] & DVP_CTL_DIS);
vip->register_save_area[SAVE_COUNT] = reg_read(vip, DVP_ITM);
reg_write(vip, DVP_ITM, 0);
for (i = 1; i < SAVE_COUNT; i++)
vip->register_save_area[i] = reg_read(vip, 4 * i);
for (i = 0; i < AUX_COUNT; i++)
vip->register_save_area[SAVE_COUNT + IRQ_COUNT + i] =
reg_read(vip, registers_to_save[i]);
spin_unlock_irqrestore(&vip->slock, flags);
pci_save_state(pdev);
if (pci_set_power_state(pdev, pci_choose_state(pdev, state))) {
vip->disabled = 1;
}
pr_info("VIP: suspend\n");
return 0;
}
static int sta2x11_vip_resume(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pdev);
struct sta2x11_vip *vip =
container_of(v4l2_dev, struct sta2x11_vip, v4l2_dev);
unsigned long flags;
int ret, i;
pr_info("VIP: resume\n");
if (vip->disabled) {
ret = pci_enable_device(pdev);
if (ret) {
pr_warn("VIP: Can't enable device.\n");
return ret;
}
vip->disabled = 0;
}
ret = pci_set_power_state(pdev, PCI_D0);
if (ret) {
pr_warn("VIP: Can't enable device.\n");
vip->disabled = 1;
return ret;
}
pci_restore_state(pdev);
spin_lock_irqsave(&vip->slock, flags);
for (i = 1; i < SAVE_COUNT; i++)
reg_write(vip, 4 * i, vip->register_save_area[i]);
for (i = 0; i < AUX_COUNT; i++)
reg_write(vip, registers_to_save[i],
vip->register_save_area[SAVE_COUNT + IRQ_COUNT + i]);
reg_write(vip, DVP_CTL, vip->register_save_area[0]);
reg_write(vip, DVP_ITM, vip->register_save_area[SAVE_COUNT]);
spin_unlock_irqrestore(&vip->slock, flags);
return 0;
}
static int __init sta2x11_vip_init_module(void)
{
return pci_register_driver(&sta2x11_vip_driver);
}
static void __exit sta2x11_vip_exit_module(void)
{
pci_unregister_driver(&sta2x11_vip_driver);
}
