static const struct fimc_fmt *fimc_lite_find_format(const u32 *pixelformat,
const u32 *mbus_code, unsigned int mask, int index)
{
const struct fimc_fmt *fmt, *def_fmt = NULL;
unsigned int i;
int id = 0;
if (index >= (int)ARRAY_SIZE(fimc_lite_formats))
return NULL;
for (i = 0; i < ARRAY_SIZE(fimc_lite_formats); ++i) {
fmt = &fimc_lite_formats[i];
if (mask && !(fmt->flags & mask))
continue;
if (pixelformat && fmt->fourcc == *pixelformat)
return fmt;
if (mbus_code && fmt->mbus_code == *mbus_code)
return fmt;
if (index == id)
def_fmt = fmt;
id++;
}
return def_fmt;
}
static struct v4l2_subdev *__find_remote_sensor(struct media_entity *me)
{
struct media_pad *pad = &me->pads[0];
struct v4l2_subdev *sd;
while (pad->flags & MEDIA_PAD_FL_SINK) {
pad = media_entity_remote_source(pad);
if (pad == NULL ||
media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
break;
sd = media_entity_to_v4l2_subdev(pad->entity);
if (sd->grp_id == GRP_ID_FIMC_IS_SENSOR ||
sd->grp_id == GRP_ID_SENSOR)
return sd;
pad = &sd->entity.pads[0];
}
return NULL;
}
static int fimc_lite_hw_init(struct fimc_lite *fimc, bool isp_output)
{
struct fimc_source_info *si;
unsigned long flags;
if (fimc->sensor == NULL)
return -ENXIO;
if (fimc->inp_frame.fmt == NULL || fimc->out_frame.fmt == NULL)
return -EINVAL;
si = v4l2_get_subdev_hostdata(fimc->sensor);
if (!si)
return -EINVAL;
spin_lock_irqsave(&fimc->slock, flags);
flite_hw_set_camera_bus(fimc, si);
flite_hw_set_source_format(fimc, &fimc->inp_frame);
flite_hw_set_window_offset(fimc, &fimc->inp_frame);
flite_hw_set_output_dma(fimc, &fimc->out_frame, !isp_output);
flite_hw_set_interrupt_mask(fimc);
flite_hw_set_test_pattern(fimc, fimc->test_pattern->val);
if (debug > 0)
flite_hw_dump_regs(fimc, __func__);
spin_unlock_irqrestore(&fimc->slock, flags);
return 0;
}
static int fimc_lite_reinit(struct fimc_lite *fimc, bool suspend)
{
struct flite_buffer *buf;
unsigned long flags;
bool streaming;
spin_lock_irqsave(&fimc->slock, flags);
streaming = fimc->state & (1 << ST_SENSOR_STREAM);
fimc->state &= ~(1 << ST_FLITE_RUN | 1 << ST_FLITE_OFF |
1 << ST_FLITE_STREAM | 1 << ST_SENSOR_STREAM);
if (suspend)
fimc->state |= (1 << ST_FLITE_SUSPENDED);
else
fimc->state &= ~(1 << ST_FLITE_PENDING |
1 << ST_FLITE_SUSPENDED);
while (!suspend && !list_empty(&fimc->pending_buf_q)) {
buf = fimc_lite_pending_queue_pop(fimc);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
while (!list_empty(&fimc->active_buf_q)) {
buf = fimc_lite_active_queue_pop(fimc);
if (suspend)
fimc_lite_pending_queue_add(fimc, buf);
else
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&fimc->slock, flags);
flite_hw_reset(fimc);
if (!streaming)
return 0;
return fimc_pipeline_call(fimc, set_stream, &fimc->pipeline, 0);
}
static int fimc_lite_stop_capture(struct fimc_lite *fimc, bool suspend)
{
unsigned long flags;
if (!fimc_lite_active(fimc))
return 0;
spin_lock_irqsave(&fimc->slock, flags);
set_bit(ST_FLITE_OFF, &fimc->state);
flite_hw_capture_stop(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
wait_event_timeout(fimc->irq_queue,
!test_bit(ST_FLITE_OFF, &fimc->state),
(2*HZ/10));
return fimc_lite_reinit(fimc, suspend);
}
static void fimc_lite_config_update(struct fimc_lite *fimc)
{
flite_hw_set_window_offset(fimc, &fimc->inp_frame);
flite_hw_set_dma_window(fimc, &fimc->out_frame);
flite_hw_set_test_pattern(fimc, fimc->test_pattern->val);
clear_bit(ST_FLITE_CONFIG, &fimc->state);
}
static irqreturn_t flite_irq_handler(int irq, void *priv)
{
struct fimc_lite *fimc = priv;
struct flite_buffer *vbuf;
unsigned long flags;
struct timeval *tv;
struct timespec ts;
u32 intsrc;
spin_lock_irqsave(&fimc->slock, flags);
intsrc = flite_hw_get_interrupt_source(fimc);
flite_hw_clear_pending_irq(fimc);
if (test_and_clear_bit(ST_FLITE_OFF, &fimc->state)) {
wake_up(&fimc->irq_queue);
goto done;
}
if (intsrc & FLITE_REG_CISTATUS_IRQ_SRC_OVERFLOW) {
clear_bit(ST_FLITE_RUN, &fimc->state);
fimc->events.data_overflow++;
}
if (intsrc & FLITE_REG_CISTATUS_IRQ_SRC_LASTCAPEND) {
flite_hw_clear_last_capture_end(fimc);
clear_bit(ST_FLITE_STREAM, &fimc->state);
wake_up(&fimc->irq_queue);
}
if (atomic_read(&fimc->out_path) != FIMC_IO_DMA)
goto done;
if ((intsrc & FLITE_REG_CISTATUS_IRQ_SRC_FRMSTART) &&
test_bit(ST_FLITE_RUN, &fimc->state) &&
!list_empty(&fimc->active_buf_q) &&
!list_empty(&fimc->pending_buf_q)) {
vbuf = fimc_lite_active_queue_pop(fimc);
ktime_get_ts(&ts);
tv = &vbuf->vb.v4l2_buf.timestamp;
tv->tv_sec = ts.tv_sec;
tv->tv_usec = ts.tv_nsec / NSEC_PER_USEC;
vbuf->vb.v4l2_buf.sequence = fimc->frame_count++;
vb2_buffer_done(&vbuf->vb, VB2_BUF_STATE_DONE);
vbuf = fimc_lite_pending_queue_pop(fimc);
flite_hw_set_output_addr(fimc, vbuf->paddr);
fimc_lite_active_queue_add(fimc, vbuf);
}
if (test_bit(ST_FLITE_CONFIG, &fimc->state))
fimc_lite_config_update(fimc);
if (list_empty(&fimc->pending_buf_q)) {
flite_hw_capture_stop(fimc);
clear_bit(ST_FLITE_STREAM, &fimc->state);
}
done:
set_bit(ST_FLITE_RUN, &fimc->state);
spin_unlock_irqrestore(&fimc->slock, flags);
return IRQ_HANDLED;
}
static int start_streaming(struct vb2_queue *q, unsigned int count)
{
struct fimc_lite *fimc = q->drv_priv;
int ret;
fimc->frame_count = 0;
ret = fimc_lite_hw_init(fimc, false);
if (ret) {
fimc_lite_reinit(fimc, false);
return ret;
}
set_bit(ST_FLITE_PENDING, &fimc->state);
if (!list_empty(&fimc->active_buf_q) &&
!test_and_set_bit(ST_FLITE_STREAM, &fimc->state)) {
flite_hw_capture_start(fimc);
if (!test_and_set_bit(ST_SENSOR_STREAM, &fimc->state))
fimc_pipeline_call(fimc, set_stream,
&fimc->pipeline, 1);
}
if (debug > 0)
flite_hw_dump_regs(fimc, __func__);
return 0;
}
static int stop_streaming(struct vb2_queue *q)
{
struct fimc_lite *fimc = q->drv_priv;
if (!fimc_lite_active(fimc))
return -EINVAL;
return fimc_lite_stop_capture(fimc, false);
}
static int queue_setup(struct vb2_queue *vq, const struct v4l2_format *pfmt,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], void *allocators[])
{
const struct v4l2_pix_format_mplane *pixm = NULL;
struct fimc_lite *fimc = vq->drv_priv;
struct flite_frame *frame = &fimc->out_frame;
const struct fimc_fmt *fmt = frame->fmt;
unsigned long wh;
int i;
if (pfmt) {
pixm = &pfmt->fmt.pix_mp;
fmt = fimc_lite_find_format(&pixm->pixelformat, NULL, 0, -1);
wh = pixm->width * pixm->height;
} else {
wh = frame->f_width * frame->f_height;
}
if (fmt == NULL)
return -EINVAL;
*num_planes = fmt->memplanes;
for (i = 0; i < fmt->memplanes; i++) {
unsigned int size = (wh * fmt->depth[i]) / 8;
if (pixm)
sizes[i] = max(size, pixm->plane_fmt[i].sizeimage);
else
sizes[i] = size;
allocators[i] = fimc->alloc_ctx;
}
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_queue *vq = vb->vb2_queue;
struct fimc_lite *fimc = vq->drv_priv;
int i;
if (fimc->out_frame.fmt == NULL)
return -EINVAL;
for (i = 0; i < fimc->out_frame.fmt->memplanes; i++) {
unsigned long size = fimc->payload[i];
if (vb2_plane_size(vb, i) < size) {
v4l2_err(&fimc->vfd,
"User buffer too small (%ld < %ld)\n",
vb2_plane_size(vb, i), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, i, size);
}
return 0;
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct flite_buffer *buf
= container_of(vb, struct flite_buffer, vb);
struct fimc_lite *fimc = vb2_get_drv_priv(vb->vb2_queue);
unsigned long flags;
spin_lock_irqsave(&fimc->slock, flags);
buf->paddr = vb2_dma_contig_plane_dma_addr(vb, 0);
if (!test_bit(ST_FLITE_SUSPENDED, &fimc->state) &&
!test_bit(ST_FLITE_STREAM, &fimc->state) &&
list_empty(&fimc->active_buf_q)) {
flite_hw_set_output_addr(fimc, buf->paddr);
fimc_lite_active_queue_add(fimc, buf);
} else {
fimc_lite_pending_queue_add(fimc, buf);
}
if (vb2_is_streaming(&fimc->vb_queue) &&
!list_empty(&fimc->pending_buf_q) &&
!test_and_set_bit(ST_FLITE_STREAM, &fimc->state)) {
flite_hw_capture_start(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
if (!test_and_set_bit(ST_SENSOR_STREAM, &fimc->state))
fimc_pipeline_call(fimc, set_stream,
&fimc->pipeline, 1);
return;
}
spin_unlock_irqrestore(&fimc->slock, flags);
}
static void fimc_lite_clear_event_counters(struct fimc_lite *fimc)
{
unsigned long flags;
spin_lock_irqsave(&fimc->slock, flags);
memset(&fimc->events, 0, sizeof(fimc->events));
spin_unlock_irqrestore(&fimc->slock, flags);
}
static int fimc_lite_open(struct file *file)
{
struct fimc_lite *fimc = video_drvdata(file);
struct media_entity *me = &fimc->vfd.entity;
int ret;
mutex_lock(&me->parent->graph_mutex);
mutex_lock(&fimc->lock);
if (atomic_read(&fimc->out_path) != FIMC_IO_DMA) {
ret = -EBUSY;
goto unlock;
}
set_bit(ST_FLITE_IN_USE, &fimc->state);
ret = pm_runtime_get_sync(&fimc->pdev->dev);
if (ret < 0)
goto unlock;
ret = v4l2_fh_open(file);
if (ret < 0)
goto err_pm;
if (!v4l2_fh_is_singular_file(file) ||
atomic_read(&fimc->out_path) != FIMC_IO_DMA)
goto unlock;
ret = fimc_pipeline_call(fimc, open, &fimc->pipeline,
me, true);
if (!ret) {
fimc_lite_clear_event_counters(fimc);
fimc->ref_count++;
goto unlock;
}
v4l2_fh_release(file);
err_pm:
pm_runtime_put_sync(&fimc->pdev->dev);
clear_bit(ST_FLITE_IN_USE, &fimc->state);
unlock:
mutex_unlock(&fimc->lock);
mutex_unlock(&me->parent->graph_mutex);
return ret;
}
static int fimc_lite_release(struct file *file)
{
struct fimc_lite *fimc = video_drvdata(file);
mutex_lock(&fimc->lock);
if (v4l2_fh_is_singular_file(file) &&
atomic_read(&fimc->out_path) == FIMC_IO_DMA) {
if (fimc->streaming) {
media_entity_pipeline_stop(&fimc->vfd.entity);
fimc->streaming = false;
}
clear_bit(ST_FLITE_IN_USE, &fimc->state);
fimc_lite_stop_capture(fimc, false);
fimc_pipeline_call(fimc, close, &fimc->pipeline);
fimc->ref_count--;
}
vb2_fop_release(file);
pm_runtime_put(&fimc->pdev->dev);
clear_bit(ST_FLITE_SUSPENDED, &fimc->state);
mutex_unlock(&fimc->lock);
return 0;
}
static const struct fimc_fmt *fimc_lite_try_format(struct fimc_lite *fimc,
u32 *width, u32 *height,
u32 *code, u32 *fourcc, int pad)
{
struct flite_drvdata *dd = fimc->dd;
const struct fimc_fmt *fmt;
unsigned int flags = 0;
if (pad == FLITE_SD_PAD_SINK) {
v4l_bound_align_image(width, 8, dd->max_width,
ffs(dd->out_width_align) - 1,
height, 0, dd->max_height, 0, 0);
} else {
v4l_bound_align_image(width, 8, fimc->inp_frame.rect.width,
ffs(dd->out_width_align) - 1,
height, 0, fimc->inp_frame.rect.height,
0, 0);
flags = fimc->inp_frame.fmt->flags;
}
fmt = fimc_lite_find_format(fourcc, code, flags, 0);
if (WARN_ON(!fmt))
return NULL;
if (code)
*code = fmt->mbus_code;
if (fourcc)
*fourcc = fmt->fourcc;
v4l2_dbg(1, debug, &fimc->subdev, "code: 0x%x, %dx%d\n",
code ? *code : 0, *width, *height);
return fmt;
}
static void fimc_lite_try_crop(struct fimc_lite *fimc, struct v4l2_rect *r)
{
struct flite_frame *frame = &fimc->inp_frame;
v4l_bound_align_image(&r->width, 0, frame->f_width, 0,
&r->height, 0, frame->f_height, 0, 0);
r->left = clamp_t(u32, r->left, 0, frame->f_width - r->width);
r->left = round_down(r->left, fimc->dd->win_hor_offs_align);
r->top = clamp_t(u32, r->top, 0, frame->f_height - r->height);
v4l2_dbg(1, debug, &fimc->subdev, "(%d,%d)/%dx%d, sink fmt: %dx%d\n",
r->left, r->top, r->width, r->height,
frame->f_width, frame->f_height);
}
static void fimc_lite_try_compose(struct fimc_lite *fimc, struct v4l2_rect *r)
{
struct flite_frame *frame = &fimc->out_frame;
struct v4l2_rect *crop_rect = &fimc->inp_frame.rect;
r->width = crop_rect->width;
r->height = crop_rect->height;
r->left = clamp_t(u32, r->left, 0, frame->f_width - r->width);
r->left = round_down(r->left, fimc->dd->out_hor_offs_align);
r->top = clamp_t(u32, r->top, 0, fimc->out_frame.f_height - r->height);
v4l2_dbg(1, debug, &fimc->subdev, "(%d,%d)/%dx%d, source fmt: %dx%d\n",
r->left, r->top, r->width, r->height,
frame->f_width, frame->f_height);
}
static int fimc_vidioc_querycap_capture(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strlcpy(cap->driver, FIMC_LITE_DRV_NAME, sizeof(cap->driver));
cap->bus_info[0] = 0;
cap->card[0] = 0;
cap->capabilities = V4L2_CAP_STREAMING;
return 0;
}
static int fimc_lite_enum_fmt_mplane(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
const struct fimc_fmt *fmt;
if (f->index >= ARRAY_SIZE(fimc_lite_formats))
return -EINVAL;
fmt = &fimc_lite_formats[f->index];
strlcpy(f->description, fmt->name, sizeof(f->description));
f->pixelformat = fmt->fourcc;
return 0;
}
static int fimc_lite_g_fmt_mplane(struct file *file, void *fh,
struct v4l2_format *f)
{
struct fimc_lite *fimc = video_drvdata(file);
struct v4l2_pix_format_mplane *pixm = &f->fmt.pix_mp;
struct v4l2_plane_pix_format *plane_fmt = &pixm->plane_fmt[0];
struct flite_frame *frame = &fimc->out_frame;
const struct fimc_fmt *fmt = frame->fmt;
plane_fmt->bytesperline = (frame->f_width * fmt->depth[0]) / 8;
plane_fmt->sizeimage = plane_fmt->bytesperline * frame->f_height;
pixm->num_planes = fmt->memplanes;
pixm->pixelformat = fmt->fourcc;
pixm->width = frame->f_width;
pixm->height = frame->f_height;
pixm->field = V4L2_FIELD_NONE;
pixm->colorspace = V4L2_COLORSPACE_JPEG;
return 0;
}
static int fimc_lite_try_fmt(struct fimc_lite *fimc,
struct v4l2_pix_format_mplane *pixm,
const struct fimc_fmt **ffmt)
{
u32 bpl = pixm->plane_fmt[0].bytesperline;
struct flite_drvdata *dd = fimc->dd;
const struct fimc_fmt *inp_fmt = fimc->inp_frame.fmt;
const struct fimc_fmt *fmt;
if (WARN_ON(inp_fmt == NULL))
return -EINVAL;
if (inp_fmt->flags & FMT_FLAGS_YUV)
fmt = fimc_lite_find_format(&pixm->pixelformat, NULL,
inp_fmt->flags, 0);
else
fmt = inp_fmt;
if (WARN_ON(fmt == NULL))
return -EINVAL;
if (ffmt)
*ffmt = fmt;
v4l_bound_align_image(&pixm->width, 8, dd->max_width,
ffs(dd->out_width_align) - 1,
&pixm->height, 0, dd->max_height, 0, 0);
if ((bpl == 0 || ((bpl * 8) / fmt->depth[0]) < pixm->width))
pixm->plane_fmt[0].bytesperline = (pixm->width *
fmt->depth[0]) / 8;
if (pixm->plane_fmt[0].sizeimage == 0)
pixm->plane_fmt[0].sizeimage = (pixm->width * pixm->height *
fmt->depth[0]) / 8;
pixm->num_planes = fmt->memplanes;
pixm->pixelformat = fmt->fourcc;
pixm->colorspace = V4L2_COLORSPACE_JPEG;
pixm->field = V4L2_FIELD_NONE;
return 0;
}
static int fimc_lite_try_fmt_mplane(struct file *file, void *fh,
struct v4l2_format *f)
{
struct fimc_lite *fimc = video_drvdata(file);
return fimc_lite_try_fmt(fimc, &f->fmt.pix_mp, NULL);
}
static int fimc_lite_s_fmt_mplane(struct file *file, void *priv,
struct v4l2_format *f)
{
struct v4l2_pix_format_mplane *pixm = &f->fmt.pix_mp;
struct fimc_lite *fimc = video_drvdata(file);
struct flite_frame *frame = &fimc->out_frame;
const struct fimc_fmt *fmt = NULL;
int ret;
if (vb2_is_busy(&fimc->vb_queue))
return -EBUSY;
ret = fimc_lite_try_fmt(fimc, &f->fmt.pix_mp, &fmt);
if (ret < 0)
return ret;
frame->fmt = fmt;
fimc->payload[0] = max((pixm->width * pixm->height * fmt->depth[0]) / 8,
pixm->plane_fmt[0].sizeimage);
frame->f_width = pixm->width;
frame->f_height = pixm->height;
return 0;
}
static int fimc_pipeline_validate(struct fimc_lite *fimc)
{
struct v4l2_subdev *sd = &fimc->subdev;
struct v4l2_subdev_format sink_fmt, src_fmt;
struct media_pad *pad;
int ret;
while (1) {
pad = &sd->entity.pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
if (sd == &fimc->subdev) {
struct flite_frame *ff = &fimc->out_frame;
sink_fmt.format.width = ff->f_width;
sink_fmt.format.height = ff->f_height;
sink_fmt.format.code = fimc->inp_frame.fmt->mbus_code;
} else {
sink_fmt.pad = pad->index;
sink_fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL,
&sink_fmt);
if (ret < 0 && ret != -ENOIOCTLCMD)
return -EPIPE;
}
pad = media_entity_remote_source(pad);
if (pad == NULL ||
media_entity_type(pad->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
break;
sd = media_entity_to_v4l2_subdev(pad->entity);
src_fmt.pad = pad->index;
src_fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL, &src_fmt);
if (ret < 0 && ret != -ENOIOCTLCMD)
return -EPIPE;
if (src_fmt.format.width != sink_fmt.format.width ||
src_fmt.format.height != sink_fmt.format.height ||
src_fmt.format.code != sink_fmt.format.code)
return -EPIPE;
}
return 0;
}
static int fimc_lite_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct fimc_lite *fimc = video_drvdata(file);
struct media_entity *entity = &fimc->vfd.entity;
struct fimc_pipeline *p = &fimc->pipeline;
int ret;
if (fimc_lite_active(fimc))
return -EBUSY;
ret = media_entity_pipeline_start(entity, p->m_pipeline);
if (ret < 0)
return ret;
ret = fimc_pipeline_validate(fimc);
if (ret < 0)
goto err_p_stop;
fimc->sensor = __find_remote_sensor(&fimc->subdev.entity);
ret = vb2_ioctl_streamon(file, priv, type);
if (!ret) {
fimc->streaming = true;
return ret;
}
err_p_stop:
media_entity_pipeline_stop(entity);
return 0;
}
static int fimc_lite_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct fimc_lite *fimc = video_drvdata(file);
int ret;
ret = vb2_ioctl_streamoff(file, priv, type);
if (ret < 0)
return ret;
media_entity_pipeline_stop(&fimc->vfd.entity);
fimc->streaming = false;
return 0;
}
static int fimc_lite_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbufs)
{
struct fimc_lite *fimc = video_drvdata(file);
int ret;
reqbufs->count = max_t(u32, FLITE_REQ_BUFS_MIN, reqbufs->count);
ret = vb2_ioctl_reqbufs(file, priv, reqbufs);
if (!ret)
fimc->reqbufs_count = reqbufs->count;
return ret;
}
static int enclosed_rectangle(struct v4l2_rect *a, struct v4l2_rect *b)
{
if (a->left < b->left || a->top < b->top)
return 0;
if (a->left + a->width > b->left + b->width)
return 0;
if (a->top + a->height > b->top + b->height)
return 0;
return 1;
}
static int fimc_lite_g_selection(struct file *file, void *fh,
struct v4l2_selection *sel)
{
struct fimc_lite *fimc = video_drvdata(file);
struct flite_frame *f = &fimc->out_frame;
if (sel->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
case V4L2_SEL_TGT_COMPOSE_DEFAULT:
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = f->f_width;
sel->r.height = f->f_height;
return 0;
case V4L2_SEL_TGT_COMPOSE:
sel->r = f->rect;
return 0;
}
return -EINVAL;
}
static int fimc_lite_s_selection(struct file *file, void *fh,
struct v4l2_selection *sel)
{
struct fimc_lite *fimc = video_drvdata(file);
struct flite_frame *f = &fimc->out_frame;
struct v4l2_rect rect = sel->r;
unsigned long flags;
if (sel->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE ||
sel->target != V4L2_SEL_TGT_COMPOSE)
return -EINVAL;
fimc_lite_try_compose(fimc, &rect);
if ((sel->flags & V4L2_SEL_FLAG_LE) &&
!enclosed_rectangle(&rect, &sel->r))
return -ERANGE;
if ((sel->flags & V4L2_SEL_FLAG_GE) &&
!enclosed_rectangle(&sel->r, &rect))
return -ERANGE;
sel->r = rect;
spin_lock_irqsave(&fimc->slock, flags);
f->rect = rect;
set_bit(ST_FLITE_CONFIG, &fimc->state);
spin_unlock_irqrestore(&fimc->slock, flags);
return 0;
}
static int fimc_lite_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
unsigned int remote_ent_type = media_entity_type(remote->entity);
int ret = 0;
if (WARN_ON(fimc == NULL))
return 0;
v4l2_dbg(1, debug, sd, "%s: %s --> %s, flags: 0x%x. source_id: 0x%x\n",
__func__, remote->entity->name, local->entity->name,
flags, fimc->source_subdev_grp_id);
mutex_lock(&fimc->lock);
switch (local->index) {
case FLITE_SD_PAD_SINK:
if (remote_ent_type != MEDIA_ENT_T_V4L2_SUBDEV) {
ret = -EINVAL;
break;
}
if (flags & MEDIA_LNK_FL_ENABLED) {
if (fimc->source_subdev_grp_id == 0)
fimc->source_subdev_grp_id = sd->grp_id;
else
ret = -EBUSY;
} else {
fimc->source_subdev_grp_id = 0;
fimc->sensor = NULL;
}
break;
case FLITE_SD_PAD_SOURCE_DMA:
if (!(flags & MEDIA_LNK_FL_ENABLED))
atomic_set(&fimc->out_path, FIMC_IO_NONE);
else if (remote_ent_type == MEDIA_ENT_T_DEVNODE)
atomic_set(&fimc->out_path, FIMC_IO_DMA);
else
ret = -EINVAL;
break;
case FLITE_SD_PAD_SOURCE_ISP:
if (!(flags & MEDIA_LNK_FL_ENABLED))
atomic_set(&fimc->out_path, FIMC_IO_NONE);
else if (remote_ent_type == MEDIA_ENT_T_V4L2_SUBDEV)
atomic_set(&fimc->out_path, FIMC_IO_ISP);
else
ret = -EINVAL;
break;
default:
v4l2_err(sd, "Invalid pad index\n");
ret = -EINVAL;
}
mb();
mutex_unlock(&fimc->lock);
return ret;
}
static int fimc_lite_subdev_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
const struct fimc_fmt *fmt;
fmt = fimc_lite_find_format(NULL, NULL, 0, code->index);
if (!fmt)
return -EINVAL;
code->code = fmt->mbus_code;
return 0;
}
static int fimc_lite_subdev_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *mf = &fmt->format;
struct flite_frame *f = &fimc->inp_frame;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(fh, fmt->pad);
fmt->format = *mf;
return 0;
}
mf->colorspace = V4L2_COLORSPACE_JPEG;
mutex_lock(&fimc->lock);
mf->code = f->fmt->mbus_code;
if (fmt->pad == FLITE_SD_PAD_SINK) {
mf->width = f->f_width;
mf->height = f->f_height;
} else {
mf->width = f->rect.width;
mf->height = f->rect.height;
}
mutex_unlock(&fimc->lock);
return 0;
}
static int fimc_lite_subdev_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *mf = &fmt->format;
struct flite_frame *sink = &fimc->inp_frame;
struct flite_frame *source = &fimc->out_frame;
const struct fimc_fmt *ffmt;
v4l2_dbg(1, debug, sd, "pad%d: code: 0x%x, %dx%d\n",
fmt->pad, mf->code, mf->width, mf->height);
mf->colorspace = V4L2_COLORSPACE_JPEG;
mutex_lock(&fimc->lock);
if ((atomic_read(&fimc->out_path) == FIMC_IO_ISP &&
sd->entity.stream_count > 0) ||
(atomic_read(&fimc->out_path) == FIMC_IO_DMA &&
vb2_is_busy(&fimc->vb_queue))) {
mutex_unlock(&fimc->lock);
return -EBUSY;
}
ffmt = fimc_lite_try_format(fimc, &mf->width, &mf->height,
&mf->code, NULL, fmt->pad);
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(fh, fmt->pad);
*mf = fmt->format;
mutex_unlock(&fimc->lock);
return 0;
}
if (fmt->pad == FLITE_SD_PAD_SINK) {
sink->f_width = mf->width;
sink->f_height = mf->height;
sink->fmt = ffmt;
sink->rect.width = mf->width;
sink->rect.height = mf->height;
sink->rect.left = 0;
sink->rect.top = 0;
source->rect = sink->rect;
source->f_width = mf->width;
source->f_height = mf->height;
} else {
mf->code = sink->fmt->mbus_code;
mf->width = sink->rect.width;
mf->height = sink->rect.height;
}
mutex_unlock(&fimc->lock);
return 0;
}
static int fimc_lite_subdev_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_selection *sel)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
struct flite_frame *f = &fimc->inp_frame;
if ((sel->target != V4L2_SEL_TGT_CROP &&
sel->target != V4L2_SEL_TGT_CROP_BOUNDS) ||
sel->pad != FLITE_SD_PAD_SINK)
return -EINVAL;
if (sel->which == V4L2_SUBDEV_FORMAT_TRY) {
sel->r = *v4l2_subdev_get_try_crop(fh, sel->pad);
return 0;
}
mutex_lock(&fimc->lock);
if (sel->target == V4L2_SEL_TGT_CROP) {
sel->r = f->rect;
} else {
sel->r.left = 0;
sel->r.top = 0;
sel->r.width = f->f_width;
sel->r.height = f->f_height;
}
mutex_unlock(&fimc->lock);
v4l2_dbg(1, debug, sd, "%s: (%d,%d) %dx%d, f_w: %d, f_h: %d\n",
__func__, f->rect.left, f->rect.top, f->rect.width,
f->rect.height, f->f_width, f->f_height);
return 0;
}
static int fimc_lite_subdev_set_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_selection *sel)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
struct flite_frame *f = &fimc->inp_frame;
int ret = 0;
if (sel->target != V4L2_SEL_TGT_CROP || sel->pad != FLITE_SD_PAD_SINK)
return -EINVAL;
mutex_lock(&fimc->lock);
fimc_lite_try_crop(fimc, &sel->r);
if (sel->which == V4L2_SUBDEV_FORMAT_TRY) {
*v4l2_subdev_get_try_crop(fh, sel->pad) = sel->r;
} else {
unsigned long flags;
spin_lock_irqsave(&fimc->slock, flags);
f->rect = sel->r;
fimc->out_frame.rect = sel->r;
set_bit(ST_FLITE_CONFIG, &fimc->state);
spin_unlock_irqrestore(&fimc->slock, flags);
}
mutex_unlock(&fimc->lock);
v4l2_dbg(1, debug, sd, "%s: (%d,%d) %dx%d, f_w: %d, f_h: %d\n",
__func__, f->rect.left, f->rect.top, f->rect.width,
f->rect.height, f->f_width, f->f_height);
return ret;
}
static int fimc_lite_subdev_s_stream(struct v4l2_subdev *sd, int on)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
unsigned long flags;
int ret;
fimc->sensor = __find_remote_sensor(&sd->entity);
if (atomic_read(&fimc->out_path) != FIMC_IO_ISP)
return -ENOIOCTLCMD;
mutex_lock(&fimc->lock);
if (on) {
flite_hw_reset(fimc);
ret = fimc_lite_hw_init(fimc, true);
if (!ret) {
spin_lock_irqsave(&fimc->slock, flags);
flite_hw_capture_start(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
}
} else {
set_bit(ST_FLITE_OFF, &fimc->state);
spin_lock_irqsave(&fimc->slock, flags);
flite_hw_capture_stop(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
ret = wait_event_timeout(fimc->irq_queue,
!test_bit(ST_FLITE_OFF, &fimc->state),
msecs_to_jiffies(200));
if (ret == 0)
v4l2_err(sd, "s_stream(0) timeout\n");
clear_bit(ST_FLITE_RUN, &fimc->state);
}
mutex_unlock(&fimc->lock);
return ret;
}
static int fimc_lite_log_status(struct v4l2_subdev *sd)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
flite_hw_dump_regs(fimc, __func__);
return 0;
}
static int fimc_lite_subdev_registered(struct v4l2_subdev *sd)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
struct vb2_queue *q = &fimc->vb_queue;
struct video_device *vfd = &fimc->vfd;
int ret;
memset(vfd, 0, sizeof(*vfd));
fimc->inp_frame.fmt = &fimc_lite_formats[0];
fimc->out_frame.fmt = &fimc_lite_formats[0];
atomic_set(&fimc->out_path, FIMC_IO_DMA);
snprintf(vfd->name, sizeof(vfd->name), "fimc-lite.%d.capture",
fimc->index);
vfd->fops = &fimc_lite_fops;
vfd->ioctl_ops = &fimc_lite_ioctl_ops;
vfd->v4l2_dev = sd->v4l2_dev;
vfd->minor = -1;
vfd->release = video_device_release_empty;
vfd->queue = q;
fimc->reqbufs_count = 0;
INIT_LIST_HEAD(&fimc->pending_buf_q);
INIT_LIST_HEAD(&fimc->active_buf_q);
memset(q, 0, sizeof(*q));
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->ops = &fimc_lite_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct flite_buffer);
q->drv_priv = fimc;
q->timestamp_type = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &fimc->lock;
ret = vb2_queue_init(q);
if (ret < 0)
return ret;
fimc->vd_pad.flags = MEDIA_PAD_FL_SINK;
ret = media_entity_init(&vfd->entity, 1, &fimc->vd_pad, 0);
if (ret < 0)
return ret;
video_set_drvdata(vfd, fimc);
fimc->pipeline_ops = v4l2_get_subdev_hostdata(sd);
ret = video_register_device(vfd, VFL_TYPE_GRABBER, -1);
if (ret < 0) {
media_entity_cleanup(&vfd->entity);
fimc->pipeline_ops = NULL;
return ret;
}
v4l2_info(sd->v4l2_dev, "Registered %s as /dev/%s\n",
vfd->name, video_device_node_name(vfd));
return 0;
}
static void fimc_lite_subdev_unregistered(struct v4l2_subdev *sd)
{
struct fimc_lite *fimc = v4l2_get_subdevdata(sd);
if (fimc == NULL)
return;
if (video_is_registered(&fimc->vfd)) {
video_unregister_device(&fimc->vfd);
media_entity_cleanup(&fimc->vfd.entity);
fimc->pipeline_ops = NULL;
}
}
static int fimc_lite_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct fimc_lite *fimc = container_of(ctrl->handler, struct fimc_lite,
ctrl_handler);
set_bit(ST_FLITE_CONFIG, &fimc->state);
return 0;
}
static int fimc_lite_create_capture_subdev(struct fimc_lite *fimc)
{
struct v4l2_ctrl_handler *handler = &fimc->ctrl_handler;
struct v4l2_subdev *sd = &fimc->subdev;
int ret;
v4l2_subdev_init(sd, &fimc_lite_subdev_ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
snprintf(sd->name, sizeof(sd->name), "FIMC-LITE.%d", fimc->index);
fimc->subdev_pads[FLITE_SD_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
fimc->subdev_pads[FLITE_SD_PAD_SOURCE_DMA].flags = MEDIA_PAD_FL_SOURCE;
fimc->subdev_pads[FLITE_SD_PAD_SOURCE_ISP].flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&sd->entity, FLITE_SD_PADS_NUM,
fimc->subdev_pads, 0);
if (ret)
return ret;
v4l2_ctrl_handler_init(handler, 1);
fimc->test_pattern = v4l2_ctrl_new_custom(handler, &fimc_lite_ctrl,
NULL);
if (handler->error) {
media_entity_cleanup(&sd->entity);
return handler->error;
}
sd->ctrl_handler = handler;
sd->internal_ops = &fimc_lite_subdev_internal_ops;
sd->entity.ops = &fimc_lite_subdev_media_ops;
sd->owner = THIS_MODULE;
v4l2_set_subdevdata(sd, fimc);
return 0;
}
static void fimc_lite_unregister_capture_subdev(struct fimc_lite *fimc)
{
struct v4l2_subdev *sd = &fimc->subdev;
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
v4l2_ctrl_handler_free(&fimc->ctrl_handler);
v4l2_set_subdevdata(sd, NULL);
}
static void fimc_lite_clk_put(struct fimc_lite *fimc)
{
if (IS_ERR_OR_NULL(fimc->clock))
return;
clk_unprepare(fimc->clock);
clk_put(fimc->clock);
fimc->clock = NULL;
}
static int fimc_lite_clk_get(struct fimc_lite *fimc)
{
int ret;
fimc->clock = clk_get(&fimc->pdev->dev, FLITE_CLK_NAME);
if (IS_ERR(fimc->clock))
return PTR_ERR(fimc->clock);
ret = clk_prepare(fimc->clock);
if (ret < 0) {
clk_put(fimc->clock);
fimc->clock = NULL;
}
return ret;
}
static int fimc_lite_probe(struct platform_device *pdev)
{
struct flite_drvdata *drv_data = NULL;
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct fimc_lite *fimc;
struct resource *res;
int ret;
fimc = devm_kzalloc(dev, sizeof(*fimc), GFP_KERNEL);
if (!fimc)
return -ENOMEM;
if (dev->of_node) {
of_id = of_match_node(flite_of_match, dev->of_node);
if (of_id)
drv_data = (struct flite_drvdata *)of_id->data;
fimc->index = of_alias_get_id(dev->of_node, "fimc-lite");
} else {
drv_data = fimc_lite_get_drvdata(pdev);
fimc->index = pdev->id;
}
if (!drv_data || fimc->index < 0 || fimc->index >= FIMC_LITE_MAX_DEVS)
return -EINVAL;
fimc->dd = drv_data;
fimc->pdev = pdev;
init_waitqueue_head(&fimc->irq_queue);
spin_lock_init(&fimc->slock);
mutex_init(&fimc->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fimc->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(fimc->regs))
return PTR_ERR(fimc->regs);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(dev, "Failed to get IRQ resource\n");
return -ENXIO;
}
ret = fimc_lite_clk_get(fimc);
if (ret)
return ret;
ret = devm_request_irq(dev, res->start, flite_irq_handler,
0, dev_name(dev), fimc);
if (ret) {
dev_err(dev, "Failed to install irq (%d)\n", ret);
goto err_clk;
}
ret = fimc_lite_create_capture_subdev(fimc);
if (ret)
goto err_clk;
platform_set_drvdata(pdev, fimc);
pm_runtime_enable(dev);
ret = pm_runtime_get_sync(dev);
if (ret < 0)
goto err_sd;
fimc->alloc_ctx = vb2_dma_contig_init_ctx(dev);
if (IS_ERR(fimc->alloc_ctx)) {
ret = PTR_ERR(fimc->alloc_ctx);
goto err_pm;
}
pm_runtime_put(dev);
dev_dbg(dev, "FIMC-LITE.%d registered successfully\n",
fimc->index);
return 0;
err_pm:
pm_runtime_put(dev);
err_sd:
fimc_lite_unregister_capture_subdev(fimc);
err_clk:
fimc_lite_clk_put(fimc);
return ret;
}
static int fimc_lite_runtime_resume(struct device *dev)
{
struct fimc_lite *fimc = dev_get_drvdata(dev);
clk_enable(fimc->clock);
return 0;
}
static int fimc_lite_runtime_suspend(struct device *dev)
{
struct fimc_lite *fimc = dev_get_drvdata(dev);
clk_disable(fimc->clock);
return 0;
}
static int fimc_lite_resume(struct device *dev)
{
struct fimc_lite *fimc = dev_get_drvdata(dev);
struct flite_buffer *buf;
unsigned long flags;
int i;
spin_lock_irqsave(&fimc->slock, flags);
if (!test_and_clear_bit(ST_LPM, &fimc->state) ||
!test_bit(ST_FLITE_IN_USE, &fimc->state)) {
spin_unlock_irqrestore(&fimc->slock, flags);
return 0;
}
flite_hw_reset(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
if (!test_and_clear_bit(ST_FLITE_SUSPENDED, &fimc->state))
return 0;
INIT_LIST_HEAD(&fimc->active_buf_q);
fimc_pipeline_call(fimc, open, &fimc->pipeline,
&fimc->vfd.entity, false);
fimc_lite_hw_init(fimc, atomic_read(&fimc->out_path) == FIMC_IO_ISP);
clear_bit(ST_FLITE_SUSPENDED, &fimc->state);
for (i = 0; i < fimc->reqbufs_count; i++) {
if (list_empty(&fimc->pending_buf_q))
break;
buf = fimc_lite_pending_queue_pop(fimc);
buffer_queue(&buf->vb);
}
return 0;
}
static int fimc_lite_suspend(struct device *dev)
{
struct fimc_lite *fimc = dev_get_drvdata(dev);
bool suspend = test_bit(ST_FLITE_IN_USE, &fimc->state);
int ret;
if (test_and_set_bit(ST_LPM, &fimc->state))
return 0;
ret = fimc_lite_stop_capture(fimc, suspend);
if (ret < 0 || !fimc_lite_active(fimc))
return ret;
return fimc_pipeline_call(fimc, close, &fimc->pipeline);
}
static int fimc_lite_remove(struct platform_device *pdev)
{
struct fimc_lite *fimc = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
fimc_lite_unregister_capture_subdev(fimc);
vb2_dma_contig_cleanup_ctx(fimc->alloc_ctx);
fimc_lite_clk_put(fimc);
dev_info(dev, "Driver unloaded\n");
return 0;
}
