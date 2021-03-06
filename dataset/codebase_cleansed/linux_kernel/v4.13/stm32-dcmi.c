static inline struct stm32_dcmi *notifier_to_dcmi(struct v4l2_async_notifier *n)
{
return container_of(n, struct stm32_dcmi, notifier);
}
static inline u32 reg_read(void __iomem *base, u32 reg)
{
return readl_relaxed(base + reg);
}
static inline void reg_write(void __iomem *base, u32 reg, u32 val)
{
writel_relaxed(val, base + reg);
}
static inline void reg_set(void __iomem *base, u32 reg, u32 mask)
{
reg_write(base, reg, reg_read(base, reg) | mask);
}
static inline void reg_clear(void __iomem *base, u32 reg, u32 mask)
{
reg_write(base, reg, reg_read(base, reg) & ~mask);
}
static void dcmi_dma_callback(void *param)
{
struct stm32_dcmi *dcmi = (struct stm32_dcmi *)param;
struct dma_chan *chan = dcmi->dma_chan;
struct dma_tx_state state;
enum dma_status status;
spin_lock(&dcmi->irqlock);
status = dmaengine_tx_status(chan, dcmi->dma_cookie, &state);
switch (status) {
case DMA_IN_PROGRESS:
dev_dbg(dcmi->dev, "%s: Received DMA_IN_PROGRESS\n", __func__);
break;
case DMA_PAUSED:
dev_err(dcmi->dev, "%s: Received DMA_PAUSED\n", __func__);
break;
case DMA_ERROR:
dev_err(dcmi->dev, "%s: Received DMA_ERROR\n", __func__);
break;
case DMA_COMPLETE:
dev_dbg(dcmi->dev, "%s: Received DMA_COMPLETE\n", __func__);
if (dcmi->active) {
struct dcmi_buf *buf = dcmi->active;
struct vb2_v4l2_buffer *vbuf = &dcmi->active->vb;
vbuf->sequence = dcmi->sequence++;
vbuf->field = V4L2_FIELD_NONE;
vbuf->vb2_buf.timestamp = ktime_get_ns();
vb2_set_plane_payload(&vbuf->vb2_buf, 0, buf->size);
vb2_buffer_done(&vbuf->vb2_buf, VB2_BUF_STATE_DONE);
dev_dbg(dcmi->dev, "buffer[%d] done seq=%d\n",
vbuf->vb2_buf.index, vbuf->sequence);
dcmi->buffers_count++;
dcmi->active = NULL;
}
if (dcmi->state == RUNNING) {
if (list_empty(&dcmi->buffers)) {
dev_err(dcmi->dev, "%s: No more buffer queued, cannot capture buffer",
__func__);
dcmi->errors_count++;
dcmi->active = NULL;
spin_unlock(&dcmi->irqlock);
return;
}
dcmi->active = list_entry(dcmi->buffers.next,
struct dcmi_buf, list);
list_del_init(&dcmi->active->list);
if (dcmi_start_capture(dcmi)) {
dev_err(dcmi->dev, "%s: Cannot restart capture on DMA complete",
__func__);
spin_unlock(&dcmi->irqlock);
return;
}
reg_set(dcmi->regs, DCMI_CR, CR_CAPTURE);
}
break;
default:
dev_err(dcmi->dev, "%s: Received unknown status\n", __func__);
break;
}
spin_unlock(&dcmi->irqlock);
}
static int dcmi_start_dma(struct stm32_dcmi *dcmi,
struct dcmi_buf *buf)
{
struct dma_async_tx_descriptor *desc = NULL;
struct dma_slave_config config;
int ret;
memset(&config, 0, sizeof(config));
config.src_addr = (dma_addr_t)dcmi->res->start + DCMI_DR;
config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
config.dst_maxburst = 4;
ret = dmaengine_slave_config(dcmi->dma_chan, &config);
if (ret < 0) {
dev_err(dcmi->dev, "%s: DMA channel config failed (%d)\n",
__func__, ret);
return ret;
}
desc = dmaengine_prep_slave_single(dcmi->dma_chan, buf->paddr,
buf->size,
DMA_DEV_TO_MEM, DMA_PREP_INTERRUPT);
if (!desc) {
dev_err(dcmi->dev, "%s: DMA dmaengine_prep_slave_single failed for buffer size %zu\n",
__func__, buf->size);
return -EINVAL;
}
desc->callback = dcmi_dma_callback;
desc->callback_param = dcmi;
dcmi->dma_cookie = dmaengine_submit(desc);
dma_async_issue_pending(dcmi->dma_chan);
return 0;
}
static int dcmi_start_capture(struct stm32_dcmi *dcmi)
{
int ret;
struct dcmi_buf *buf = dcmi->active;
if (!buf)
return -EINVAL;
ret = dcmi_start_dma(dcmi, buf);
if (ret) {
dcmi->errors_count++;
return ret;
}
reg_set(dcmi->regs, DCMI_CR, CR_CAPTURE);
return 0;
}
static irqreturn_t dcmi_irq_thread(int irq, void *arg)
{
struct stm32_dcmi *dcmi = arg;
spin_lock(&dcmi->irqlock);
if (dcmi->state == STOPPING) {
reg_clear(dcmi->regs, DCMI_IER, IT_FRAME | IT_OVR | IT_ERR);
dcmi->state = STOPPED;
complete(&dcmi->complete);
spin_unlock(&dcmi->irqlock);
return IRQ_HANDLED;
}
if ((dcmi->misr & IT_OVR) || (dcmi->misr & IT_ERR)) {
dev_warn(dcmi->dev, "%s: Overflow or error detected\n",
__func__);
dcmi->errors_count++;
dmaengine_terminate_all(dcmi->dma_chan);
reg_set(dcmi->regs, DCMI_ICR, IT_FRAME | IT_OVR | IT_ERR);
dev_dbg(dcmi->dev, "Restarting capture after DCMI error\n");
if (dcmi_start_capture(dcmi)) {
dev_err(dcmi->dev, "%s: Cannot restart capture on overflow or error\n",
__func__);
spin_unlock(&dcmi->irqlock);
return IRQ_HANDLED;
}
}
spin_unlock(&dcmi->irqlock);
return IRQ_HANDLED;
}
static irqreturn_t dcmi_irq_callback(int irq, void *arg)
{
struct stm32_dcmi *dcmi = arg;
spin_lock(&dcmi->irqlock);
dcmi->misr = reg_read(dcmi->regs, DCMI_MIS);
reg_set(dcmi->regs, DCMI_ICR, IT_FRAME | IT_OVR | IT_ERR);
spin_unlock(&dcmi->irqlock);
return IRQ_WAKE_THREAD;
}
static int dcmi_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers,
unsigned int *nplanes,
unsigned int sizes[],
struct device *alloc_devs[])
{
struct stm32_dcmi *dcmi = vb2_get_drv_priv(vq);
unsigned int size;
size = dcmi->fmt.fmt.pix.sizeimage;
if (*nplanes)
return sizes[0] < size ? -EINVAL : 0;
*nplanes = 1;
sizes[0] = size;
dcmi->active = NULL;
dev_dbg(dcmi->dev, "Setup queue, count=%d, size=%d\n",
*nbuffers, size);
return 0;
}
static int dcmi_buf_init(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct dcmi_buf *buf = container_of(vbuf, struct dcmi_buf, vb);
INIT_LIST_HEAD(&buf->list);
return 0;
}
static int dcmi_buf_prepare(struct vb2_buffer *vb)
{
struct stm32_dcmi *dcmi = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct dcmi_buf *buf = container_of(vbuf, struct dcmi_buf, vb);
unsigned long size;
size = dcmi->fmt.fmt.pix.sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(dcmi->dev, "%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, size);
if (!buf->prepared) {
buf->paddr =
vb2_dma_contig_plane_dma_addr(&buf->vb.vb2_buf, 0);
buf->size = vb2_plane_size(&buf->vb.vb2_buf, 0);
buf->prepared = true;
vb2_set_plane_payload(&buf->vb.vb2_buf, 0, buf->size);
dev_dbg(dcmi->dev, "buffer[%d] phy=0x%pad size=%zu\n",
vb->index, &buf->paddr, buf->size);
}
return 0;
}
static void dcmi_buf_queue(struct vb2_buffer *vb)
{
struct stm32_dcmi *dcmi = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct dcmi_buf *buf = container_of(vbuf, struct dcmi_buf, vb);
unsigned long flags = 0;
spin_lock_irqsave(&dcmi->irqlock, flags);
if ((dcmi->state == RUNNING) && (!dcmi->active)) {
dcmi->active = buf;
dev_dbg(dcmi->dev, "Starting capture on buffer[%d] queued\n",
buf->vb.vb2_buf.index);
if (dcmi_start_capture(dcmi)) {
dev_err(dcmi->dev, "%s: Cannot restart capture on overflow or error\n",
__func__);
spin_unlock_irqrestore(&dcmi->irqlock, flags);
return;
}
} else {
list_add_tail(&buf->list, &dcmi->buffers);
}
spin_unlock_irqrestore(&dcmi->irqlock, flags);
}
static int dcmi_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct stm32_dcmi *dcmi = vb2_get_drv_priv(vq);
struct dcmi_buf *buf, *node;
u32 val;
int ret;
ret = clk_enable(dcmi->mclk);
if (ret) {
dev_err(dcmi->dev, "%s: Failed to start streaming, cannot enable clock",
__func__);
goto err_release_buffers;
}
ret = v4l2_subdev_call(dcmi->entity.subdev, video, s_stream, 1);
if (ret && ret != -ENOIOCTLCMD) {
dev_err(dcmi->dev, "%s: Failed to start streaming, subdev streamon error",
__func__);
goto err_disable_clock;
}
spin_lock_irq(&dcmi->irqlock);
val = reg_read(dcmi->regs, DCMI_CR);
val &= ~(CR_PCKPOL | CR_HSPOL | CR_VSPOL |
CR_EDM_0 | CR_EDM_1 | CR_FCRC_0 |
CR_FCRC_1 | CR_JPEG | CR_ESS);
switch (dcmi->bus.bus_width) {
case 14:
val &= CR_EDM_0 + CR_EDM_1;
break;
case 12:
val &= CR_EDM_1;
break;
case 10:
val &= CR_EDM_0;
break;
default:
break;
}
if (dcmi->bus.flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH)
val |= CR_VSPOL;
if (dcmi->bus.flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH)
val |= CR_HSPOL;
if (dcmi->bus.flags & V4L2_MBUS_PCLK_SAMPLE_RISING)
val |= CR_PCKPOL;
reg_write(dcmi->regs, DCMI_CR, val);
reg_set(dcmi->regs, DCMI_CR, CR_ENABLE);
dcmi->state = RUNNING;
dcmi->sequence = 0;
dcmi->errors_count = 0;
dcmi->buffers_count = 0;
dcmi->active = NULL;
if (list_empty(&dcmi->buffers)) {
dev_dbg(dcmi->dev, "Start streaming is deferred to next buffer queueing\n");
spin_unlock_irq(&dcmi->irqlock);
return 0;
}
dcmi->active = list_entry(dcmi->buffers.next, struct dcmi_buf, list);
list_del_init(&dcmi->active->list);
dev_dbg(dcmi->dev, "Start streaming, starting capture\n");
ret = dcmi_start_capture(dcmi);
if (ret) {
dev_err(dcmi->dev, "%s: Start streaming failed, cannot start capture",
__func__);
spin_unlock_irq(&dcmi->irqlock);
goto err_subdev_streamoff;
}
reg_set(dcmi->regs, DCMI_IER, IT_FRAME | IT_OVR | IT_ERR);
spin_unlock_irq(&dcmi->irqlock);
return 0;
err_subdev_streamoff:
v4l2_subdev_call(dcmi->entity.subdev, video, s_stream, 0);
err_disable_clock:
clk_disable(dcmi->mclk);
err_release_buffers:
spin_lock_irq(&dcmi->irqlock);
if (dcmi->active) {
buf = dcmi->active;
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_QUEUED);
dcmi->active = NULL;
}
list_for_each_entry_safe(buf, node, &dcmi->buffers, list) {
list_del_init(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_QUEUED);
}
spin_unlock_irq(&dcmi->irqlock);
return ret;
}
static void dcmi_stop_streaming(struct vb2_queue *vq)
{
struct stm32_dcmi *dcmi = vb2_get_drv_priv(vq);
struct dcmi_buf *buf, *node;
unsigned long time_ms = msecs_to_jiffies(TIMEOUT_MS);
long timeout;
int ret;
ret = v4l2_subdev_call(dcmi->entity.subdev, video, s_stream, 0);
if (ret && ret != -ENOIOCTLCMD)
dev_err(dcmi->dev, "stream off failed in subdev\n");
dcmi->state = STOPPING;
timeout = wait_for_completion_interruptible_timeout(&dcmi->complete,
time_ms);
spin_lock_irq(&dcmi->irqlock);
reg_clear(dcmi->regs, DCMI_IER, IT_FRAME | IT_OVR | IT_ERR);
reg_clear(dcmi->regs, DCMI_CR, CR_ENABLE);
if (!timeout) {
dev_err(dcmi->dev, "Timeout during stop streaming\n");
dcmi->state = STOPPED;
}
if (dcmi->active) {
buf = dcmi->active;
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
dcmi->active = NULL;
}
list_for_each_entry_safe(buf, node, &dcmi->buffers, list) {
list_del_init(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irq(&dcmi->irqlock);
dmaengine_terminate_all(dcmi->dma_chan);
clk_disable(dcmi->mclk);
dev_dbg(dcmi->dev, "Stop streaming, errors=%d buffers=%d\n",
dcmi->errors_count, dcmi->buffers_count);
}
static int dcmi_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
*fmt = dcmi->fmt;
return 0;
}
static const struct dcmi_format *find_format_by_fourcc(struct stm32_dcmi *dcmi,
unsigned int fourcc)
{
unsigned int num_formats = dcmi->num_user_formats;
const struct dcmi_format *fmt;
unsigned int i;
for (i = 0; i < num_formats; i++) {
fmt = dcmi->user_formats[i];
if (fmt->fourcc == fourcc)
return fmt;
}
return NULL;
}
static int dcmi_try_fmt(struct stm32_dcmi *dcmi, struct v4l2_format *f,
const struct dcmi_format **current_fmt)
{
const struct dcmi_format *dcmi_fmt;
struct v4l2_pix_format *pixfmt = &f->fmt.pix;
struct v4l2_subdev_pad_config pad_cfg;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_TRY,
};
int ret;
dcmi_fmt = find_format_by_fourcc(dcmi, pixfmt->pixelformat);
if (!dcmi_fmt) {
dcmi_fmt = dcmi->user_formats[dcmi->num_user_formats - 1];
pixfmt->pixelformat = dcmi_fmt->fourcc;
}
pixfmt->width = clamp(pixfmt->width, MIN_WIDTH, MAX_WIDTH);
pixfmt->height = clamp(pixfmt->height, MIN_HEIGHT, MAX_HEIGHT);
v4l2_fill_mbus_format(&format.format, pixfmt, dcmi_fmt->mbus_code);
ret = v4l2_subdev_call(dcmi->entity.subdev, pad, set_fmt,
&pad_cfg, &format);
if (ret < 0)
return ret;
v4l2_fill_pix_format(pixfmt, &format.format);
pixfmt->field = V4L2_FIELD_NONE;
pixfmt->bytesperline = pixfmt->width * dcmi_fmt->bpp;
pixfmt->sizeimage = pixfmt->bytesperline * pixfmt->height;
if (current_fmt)
*current_fmt = dcmi_fmt;
return 0;
}
static int dcmi_set_fmt(struct stm32_dcmi *dcmi, struct v4l2_format *f)
{
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
const struct dcmi_format *current_fmt;
int ret;
ret = dcmi_try_fmt(dcmi, f, &current_fmt);
if (ret)
return ret;
v4l2_fill_mbus_format(&format.format, &f->fmt.pix,
current_fmt->mbus_code);
ret = v4l2_subdev_call(dcmi->entity.subdev, pad,
set_fmt, NULL, &format);
if (ret < 0)
return ret;
dcmi->fmt = *f;
dcmi->current_fmt = current_fmt;
return 0;
}
static int dcmi_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
if (vb2_is_streaming(&dcmi->queue))
return -EBUSY;
return dcmi_set_fmt(dcmi, f);
}
static int dcmi_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
return dcmi_try_fmt(dcmi, f, NULL);
}
static int dcmi_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
if (f->index >= dcmi->num_user_formats)
return -EINVAL;
f->pixelformat = dcmi->user_formats[f->index]->fourcc;
return 0;
}
static int dcmi_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strlcpy(cap->driver, DRV_NAME, sizeof(cap->driver));
strlcpy(cap->card, "STM32 Camera Memory Interface",
sizeof(cap->card));
strlcpy(cap->bus_info, "platform:dcmi", sizeof(cap->bus_info));
return 0;
}
static int dcmi_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
strlcpy(i->name, "Camera", sizeof(i->name));
return 0;
}
static int dcmi_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int dcmi_s_input(struct file *file, void *priv, unsigned int i)
{
if (i > 0)
return -EINVAL;
return 0;
}
static int dcmi_enum_framesizes(struct file *file, void *fh,
struct v4l2_frmsizeenum *fsize)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
const struct dcmi_format *dcmi_fmt;
struct v4l2_subdev_frame_size_enum fse = {
.index = fsize->index,
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
int ret;
dcmi_fmt = find_format_by_fourcc(dcmi, fsize->pixel_format);
if (!dcmi_fmt)
return -EINVAL;
fse.code = dcmi_fmt->mbus_code;
ret = v4l2_subdev_call(dcmi->entity.subdev, pad, enum_frame_size,
NULL, &fse);
if (ret)
return ret;
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = fse.max_width;
fsize->discrete.height = fse.max_height;
return 0;
}
static int dcmi_enum_frameintervals(struct file *file, void *fh,
struct v4l2_frmivalenum *fival)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
const struct dcmi_format *dcmi_fmt;
struct v4l2_subdev_frame_interval_enum fie = {
.index = fival->index,
.width = fival->width,
.height = fival->height,
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
int ret;
dcmi_fmt = find_format_by_fourcc(dcmi, fival->pixel_format);
if (!dcmi_fmt)
return -EINVAL;
fie.code = dcmi_fmt->mbus_code;
ret = v4l2_subdev_call(dcmi->entity.subdev, pad,
enum_frame_interval, NULL, &fie);
if (ret)
return ret;
fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;
fival->discrete = fie.interval;
return 0;
}
static int dcmi_open(struct file *file)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
struct v4l2_subdev *sd = dcmi->entity.subdev;
int ret;
if (mutex_lock_interruptible(&dcmi->lock))
return -ERESTARTSYS;
ret = v4l2_fh_open(file);
if (ret < 0)
goto unlock;
if (!v4l2_fh_is_singular_file(file))
goto fh_rel;
ret = v4l2_subdev_call(sd, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
goto fh_rel;
ret = dcmi_set_fmt(dcmi, &dcmi->fmt);
if (ret)
v4l2_subdev_call(sd, core, s_power, 0);
fh_rel:
if (ret)
v4l2_fh_release(file);
unlock:
mutex_unlock(&dcmi->lock);
return ret;
}
static int dcmi_release(struct file *file)
{
struct stm32_dcmi *dcmi = video_drvdata(file);
struct v4l2_subdev *sd = dcmi->entity.subdev;
bool fh_singular;
int ret;
mutex_lock(&dcmi->lock);
fh_singular = v4l2_fh_is_singular_file(file);
ret = _vb2_fop_release(file, NULL);
if (fh_singular)
v4l2_subdev_call(sd, core, s_power, 0);
mutex_unlock(&dcmi->lock);
return ret;
}
static int dcmi_set_default_fmt(struct stm32_dcmi *dcmi)
{
struct v4l2_format f = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
.fmt.pix = {
.width = CIF_WIDTH,
.height = CIF_HEIGHT,
.field = V4L2_FIELD_NONE,
.pixelformat = dcmi->user_formats[0]->fourcc,
},
};
int ret;
ret = dcmi_try_fmt(dcmi, &f, NULL);
if (ret)
return ret;
dcmi->current_fmt = dcmi->user_formats[0];
dcmi->fmt = f;
return 0;
}
static int dcmi_formats_init(struct stm32_dcmi *dcmi)
{
const struct dcmi_format *dcmi_fmts[ARRAY_SIZE(dcmi_formats)];
unsigned int num_fmts = 0, i, j;
struct v4l2_subdev *subdev = dcmi->entity.subdev;
struct v4l2_subdev_mbus_code_enum mbus_code = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
while (!v4l2_subdev_call(subdev, pad, enum_mbus_code,
NULL, &mbus_code)) {
for (i = 0; i < ARRAY_SIZE(dcmi_formats); i++) {
if (dcmi_formats[i].mbus_code != mbus_code.code)
continue;
for (j = 0; j < num_fmts; j++)
if (dcmi_fmts[j]->fourcc ==
dcmi_formats[i].fourcc)
break;
if (j == num_fmts)
dcmi_fmts[num_fmts++] = dcmi_formats + i;
}
mbus_code.index++;
}
if (!num_fmts)
return -ENXIO;
dcmi->num_user_formats = num_fmts;
dcmi->user_formats = devm_kcalloc(dcmi->dev,
num_fmts, sizeof(struct dcmi_format *),
GFP_KERNEL);
if (!dcmi->user_formats) {
dev_err(dcmi->dev, "could not allocate memory\n");
return -ENOMEM;
}
memcpy(dcmi->user_formats, dcmi_fmts,
num_fmts * sizeof(struct dcmi_format *));
dcmi->current_fmt = dcmi->user_formats[0];
return 0;
}
static int dcmi_graph_notify_complete(struct v4l2_async_notifier *notifier)
{
struct stm32_dcmi *dcmi = notifier_to_dcmi(notifier);
int ret;
dcmi->vdev->ctrl_handler = dcmi->entity.subdev->ctrl_handler;
ret = dcmi_formats_init(dcmi);
if (ret) {
dev_err(dcmi->dev, "No supported mediabus format found\n");
return ret;
}
ret = dcmi_set_default_fmt(dcmi);
if (ret) {
dev_err(dcmi->dev, "Could not set default format\n");
return ret;
}
ret = video_register_device(dcmi->vdev, VFL_TYPE_GRABBER, -1);
if (ret) {
dev_err(dcmi->dev, "Failed to register video device\n");
return ret;
}
dev_dbg(dcmi->dev, "Device registered as %s\n",
video_device_node_name(dcmi->vdev));
return 0;
}
static void dcmi_graph_notify_unbind(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *sd,
struct v4l2_async_subdev *asd)
{
struct stm32_dcmi *dcmi = notifier_to_dcmi(notifier);
dev_dbg(dcmi->dev, "Removing %s\n", video_device_node_name(dcmi->vdev));
video_unregister_device(dcmi->vdev);
}
static int dcmi_graph_notify_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct stm32_dcmi *dcmi = notifier_to_dcmi(notifier);
dev_dbg(dcmi->dev, "Subdev %s bound\n", subdev->name);
dcmi->entity.subdev = subdev;
return 0;
}
static int dcmi_graph_parse(struct stm32_dcmi *dcmi, struct device_node *node)
{
struct device_node *ep = NULL;
struct device_node *remote;
while (1) {
ep = of_graph_get_next_endpoint(node, ep);
if (!ep)
return -EINVAL;
remote = of_graph_get_remote_port_parent(ep);
if (!remote) {
of_node_put(ep);
return -EINVAL;
}
dcmi->entity.node = remote;
dcmi->entity.asd.match_type = V4L2_ASYNC_MATCH_FWNODE;
dcmi->entity.asd.match.fwnode.fwnode = of_fwnode_handle(remote);
return 0;
}
}
static int dcmi_graph_init(struct stm32_dcmi *dcmi)
{
struct v4l2_async_subdev **subdevs = NULL;
int ret;
ret = dcmi_graph_parse(dcmi, dcmi->dev->of_node);
if (ret < 0) {
dev_err(dcmi->dev, "Graph parsing failed\n");
return ret;
}
subdevs = devm_kzalloc(dcmi->dev, sizeof(*subdevs), GFP_KERNEL);
if (!subdevs) {
of_node_put(dcmi->entity.node);
return -ENOMEM;
}
subdevs[0] = &dcmi->entity.asd;
dcmi->notifier.subdevs = subdevs;
dcmi->notifier.num_subdevs = 1;
dcmi->notifier.bound = dcmi_graph_notify_bound;
dcmi->notifier.unbind = dcmi_graph_notify_unbind;
dcmi->notifier.complete = dcmi_graph_notify_complete;
ret = v4l2_async_notifier_register(&dcmi->v4l2_dev, &dcmi->notifier);
if (ret < 0) {
dev_err(dcmi->dev, "Notifier registration failed\n");
of_node_put(dcmi->entity.node);
return ret;
}
return 0;
}
static int dcmi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match = NULL;
struct v4l2_fwnode_endpoint ep;
struct stm32_dcmi *dcmi;
struct vb2_queue *q;
struct dma_chan *chan;
struct clk *mclk;
int irq;
int ret = 0;
match = of_match_device(of_match_ptr(stm32_dcmi_of_match), &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Could not find a match in devicetree\n");
return -ENODEV;
}
dcmi = devm_kzalloc(&pdev->dev, sizeof(struct stm32_dcmi), GFP_KERNEL);
if (!dcmi)
return -ENOMEM;
dcmi->rstc = devm_reset_control_get(&pdev->dev, NULL);
if (IS_ERR(dcmi->rstc)) {
dev_err(&pdev->dev, "Could not get reset control\n");
return -ENODEV;
}
np = of_graph_get_next_endpoint(np, NULL);
if (!np) {
dev_err(&pdev->dev, "Could not find the endpoint\n");
of_node_put(np);
return -ENODEV;
}
ret = v4l2_fwnode_endpoint_parse(of_fwnode_handle(np), &ep);
if (ret) {
dev_err(&pdev->dev, "Could not parse the endpoint\n");
of_node_put(np);
return -ENODEV;
}
if (ep.bus_type == V4L2_MBUS_CSI2) {
dev_err(&pdev->dev, "CSI bus not supported\n");
of_node_put(np);
return -ENODEV;
}
dcmi->bus.flags = ep.bus.parallel.flags;
dcmi->bus.bus_width = ep.bus.parallel.bus_width;
dcmi->bus.data_shift = ep.bus.parallel.data_shift;
of_node_put(np);
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "Could not get irq\n");
return -ENODEV;
}
dcmi->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!dcmi->res) {
dev_err(&pdev->dev, "Could not get resource\n");
return -ENODEV;
}
dcmi->regs = devm_ioremap_resource(&pdev->dev, dcmi->res);
if (IS_ERR(dcmi->regs)) {
dev_err(&pdev->dev, "Could not map registers\n");
return PTR_ERR(dcmi->regs);
}
ret = devm_request_threaded_irq(&pdev->dev, irq, dcmi_irq_callback,
dcmi_irq_thread, IRQF_ONESHOT,
dev_name(&pdev->dev), dcmi);
if (ret) {
dev_err(&pdev->dev, "Unable to request irq %d\n", irq);
return -ENODEV;
}
mclk = devm_clk_get(&pdev->dev, "mclk");
if (IS_ERR(mclk)) {
dev_err(&pdev->dev, "Unable to get mclk\n");
return PTR_ERR(mclk);
}
chan = dma_request_slave_channel(&pdev->dev, "tx");
if (!chan) {
dev_info(&pdev->dev, "Unable to request DMA channel, defer probing\n");
return -EPROBE_DEFER;
}
ret = clk_prepare(mclk);
if (ret) {
dev_err(&pdev->dev, "Unable to prepare mclk %p\n", mclk);
goto err_dma_release;
}
spin_lock_init(&dcmi->irqlock);
mutex_init(&dcmi->lock);
init_completion(&dcmi->complete);
INIT_LIST_HEAD(&dcmi->buffers);
dcmi->dev = &pdev->dev;
dcmi->mclk = mclk;
dcmi->state = STOPPED;
dcmi->dma_chan = chan;
q = &dcmi->queue;
ret = v4l2_device_register(&pdev->dev, &dcmi->v4l2_dev);
if (ret)
goto err_clk_unprepare;
dcmi->vdev = video_device_alloc();
if (!dcmi->vdev) {
ret = -ENOMEM;
goto err_device_unregister;
}
dcmi->vdev->fops = &dcmi_fops;
dcmi->vdev->v4l2_dev = &dcmi->v4l2_dev;
dcmi->vdev->queue = &dcmi->queue;
strlcpy(dcmi->vdev->name, KBUILD_MODNAME, sizeof(dcmi->vdev->name));
dcmi->vdev->release = video_device_release;
dcmi->vdev->ioctl_ops = &dcmi_ioctl_ops;
dcmi->vdev->lock = &dcmi->lock;
dcmi->vdev->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
video_set_drvdata(dcmi->vdev, dcmi);
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_READ | VB2_DMABUF;
q->lock = &dcmi->lock;
q->drv_priv = dcmi;
q->buf_struct_size = sizeof(struct dcmi_buf);
q->ops = &dcmi_video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
q->dev = &pdev->dev;
ret = vb2_queue_init(q);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to initialize vb2 queue\n");
goto err_device_release;
}
ret = dcmi_graph_init(dcmi);
if (ret < 0)
goto err_device_release;
ret = reset_control_assert(dcmi->rstc);
if (ret) {
dev_err(&pdev->dev, "Failed to assert the reset line\n");
goto err_device_release;
}
usleep_range(3000, 5000);
ret = reset_control_deassert(dcmi->rstc);
if (ret) {
dev_err(&pdev->dev, "Failed to deassert the reset line\n");
goto err_device_release;
}
dev_info(&pdev->dev, "Probe done\n");
platform_set_drvdata(pdev, dcmi);
return 0;
err_device_release:
video_device_release(dcmi->vdev);
err_device_unregister:
v4l2_device_unregister(&dcmi->v4l2_dev);
err_clk_unprepare:
clk_unprepare(dcmi->mclk);
err_dma_release:
dma_release_channel(dcmi->dma_chan);
return ret;
}
static int dcmi_remove(struct platform_device *pdev)
{
struct stm32_dcmi *dcmi = platform_get_drvdata(pdev);
v4l2_async_notifier_unregister(&dcmi->notifier);
v4l2_device_unregister(&dcmi->v4l2_dev);
clk_unprepare(dcmi->mclk);
dma_release_channel(dcmi->dma_chan);
return 0;
}
