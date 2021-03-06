static int fimc_capture_hw_init(struct fimc_dev *fimc)
{
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct fimc_pipeline *p = &fimc->pipeline;
struct fimc_sensor_info *sensor;
unsigned long flags;
int ret = 0;
if (p->subdevs[IDX_SENSOR] == NULL || ctx == NULL)
return -ENXIO;
if (ctx->s_frame.fmt == NULL)
return -EINVAL;
sensor = v4l2_get_subdev_hostdata(p->subdevs[IDX_SENSOR]);
spin_lock_irqsave(&fimc->slock, flags);
fimc_prepare_dma_offset(ctx, &ctx->d_frame);
fimc_set_yuv_order(ctx);
fimc_hw_set_camera_polarity(fimc, &sensor->pdata);
fimc_hw_set_camera_type(fimc, &sensor->pdata);
fimc_hw_set_camera_source(fimc, &sensor->pdata);
fimc_hw_set_camera_offset(fimc, &ctx->s_frame);
ret = fimc_set_scaler_info(ctx);
if (!ret) {
fimc_hw_set_input_path(ctx);
fimc_hw_set_prescaler(ctx);
fimc_hw_set_mainscaler(ctx);
fimc_hw_set_target_format(ctx);
fimc_hw_set_rotation(ctx);
fimc_hw_set_effect(ctx);
fimc_hw_set_output_path(ctx);
fimc_hw_set_out_dma(ctx);
if (fimc->variant->has_alpha)
fimc_hw_set_rgb_alpha(ctx);
clear_bit(ST_CAPT_APPLY_CFG, &fimc->state);
}
spin_unlock_irqrestore(&fimc->slock, flags);
return ret;
}
static int fimc_capture_state_cleanup(struct fimc_dev *fimc, bool suspend)
{
struct fimc_vid_cap *cap = &fimc->vid_cap;
struct fimc_vid_buffer *buf;
unsigned long flags;
bool streaming;
spin_lock_irqsave(&fimc->slock, flags);
streaming = fimc->state & (1 << ST_CAPT_ISP_STREAM);
fimc->state &= ~(1 << ST_CAPT_RUN | 1 << ST_CAPT_SHUT |
1 << ST_CAPT_STREAM | 1 << ST_CAPT_ISP_STREAM);
if (suspend)
fimc->state |= (1 << ST_CAPT_SUSPENDED);
else
fimc->state &= ~(1 << ST_CAPT_PEND | 1 << ST_CAPT_SUSPENDED);
while (!suspend && !list_empty(&cap->pending_buf_q)) {
buf = fimc_pending_queue_pop(cap);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
while (!list_empty(&cap->active_buf_q)) {
buf = fimc_active_queue_pop(cap);
if (suspend)
fimc_pending_queue_add(cap, buf);
else
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
fimc_hw_reset(fimc);
cap->buf_index = 0;
spin_unlock_irqrestore(&fimc->slock, flags);
if (streaming)
return fimc_pipeline_call(fimc, set_stream,
&fimc->pipeline, 0);
else
return 0;
}
static int fimc_stop_capture(struct fimc_dev *fimc, bool suspend)
{
unsigned long flags;
if (!fimc_capture_active(fimc))
return 0;
spin_lock_irqsave(&fimc->slock, flags);
set_bit(ST_CAPT_SHUT, &fimc->state);
fimc_deactivate_capture(fimc);
spin_unlock_irqrestore(&fimc->slock, flags);
wait_event_timeout(fimc->irq_queue,
!test_bit(ST_CAPT_SHUT, &fimc->state),
(2*HZ/10));
return fimc_capture_state_cleanup(fimc, suspend);
}
static int fimc_capture_config_update(struct fimc_ctx *ctx)
{
struct fimc_dev *fimc = ctx->fimc_dev;
int ret;
fimc_hw_set_camera_offset(fimc, &ctx->s_frame);
ret = fimc_set_scaler_info(ctx);
if (ret)
return ret;
fimc_hw_set_prescaler(ctx);
fimc_hw_set_mainscaler(ctx);
fimc_hw_set_target_format(ctx);
fimc_hw_set_rotation(ctx);
fimc_hw_set_effect(ctx);
fimc_prepare_dma_offset(ctx, &ctx->d_frame);
fimc_hw_set_out_dma(ctx);
if (fimc->variant->has_alpha)
fimc_hw_set_rgb_alpha(ctx);
clear_bit(ST_CAPT_APPLY_CFG, &fimc->state);
return ret;
}
void fimc_capture_irq_handler(struct fimc_dev *fimc, int deq_buf)
{
struct v4l2_subdev *csis = fimc->pipeline.subdevs[IDX_CSIS];
struct fimc_vid_cap *cap = &fimc->vid_cap;
struct fimc_frame *f = &cap->ctx->d_frame;
struct fimc_vid_buffer *v_buf;
struct timeval *tv;
struct timespec ts;
if (test_and_clear_bit(ST_CAPT_SHUT, &fimc->state)) {
wake_up(&fimc->irq_queue);
goto done;
}
if (!list_empty(&cap->active_buf_q) &&
test_bit(ST_CAPT_RUN, &fimc->state) && deq_buf) {
ktime_get_real_ts(&ts);
v_buf = fimc_active_queue_pop(cap);
tv = &v_buf->vb.v4l2_buf.timestamp;
tv->tv_sec = ts.tv_sec;
tv->tv_usec = ts.tv_nsec / NSEC_PER_USEC;
v_buf->vb.v4l2_buf.sequence = cap->frame_count++;
vb2_buffer_done(&v_buf->vb, VB2_BUF_STATE_DONE);
}
if (!list_empty(&cap->pending_buf_q)) {
v_buf = fimc_pending_queue_pop(cap);
fimc_hw_set_output_addr(fimc, &v_buf->paddr, cap->buf_index);
v_buf->index = cap->buf_index;
fimc_active_queue_add(cap, v_buf);
dbg("next frame: %d, done frame: %d",
fimc_hw_get_frame_index(fimc), v_buf->index);
if (++cap->buf_index >= FIMC_MAX_OUT_BUFS)
cap->buf_index = 0;
}
if (f->fmt->mdataplanes && !list_empty(&cap->active_buf_q)) {
unsigned int plane = ffs(f->fmt->mdataplanes) - 1;
unsigned int size = f->payload[plane];
s32 index = fimc_hw_get_frame_index(fimc);
void *vaddr;
list_for_each_entry(v_buf, &cap->active_buf_q, list) {
if (v_buf->index != index)
continue;
vaddr = vb2_plane_vaddr(&v_buf->vb, plane);
v4l2_subdev_call(csis, video, s_rx_buffer,
vaddr, &size);
break;
}
}
if (cap->active_buf_cnt == 0) {
if (deq_buf)
clear_bit(ST_CAPT_RUN, &fimc->state);
if (++cap->buf_index >= FIMC_MAX_OUT_BUFS)
cap->buf_index = 0;
} else {
set_bit(ST_CAPT_RUN, &fimc->state);
}
if (test_bit(ST_CAPT_APPLY_CFG, &fimc->state))
fimc_capture_config_update(cap->ctx);
done:
if (cap->active_buf_cnt == 1) {
fimc_deactivate_capture(fimc);
clear_bit(ST_CAPT_STREAM, &fimc->state);
}
dbg("frame: %d, active_buf_cnt: %d",
fimc_hw_get_frame_index(fimc), cap->active_buf_cnt);
}
static int start_streaming(struct vb2_queue *q, unsigned int count)
{
struct fimc_ctx *ctx = q->drv_priv;
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_vid_cap *vid_cap = &fimc->vid_cap;
int min_bufs;
int ret;
vid_cap->frame_count = 0;
ret = fimc_capture_hw_init(fimc);
if (ret) {
fimc_capture_state_cleanup(fimc, false);
return ret;
}
set_bit(ST_CAPT_PEND, &fimc->state);
min_bufs = fimc->vid_cap.reqbufs_count > 1 ? 2 : 1;
if (vid_cap->active_buf_cnt >= min_bufs &&
!test_and_set_bit(ST_CAPT_STREAM, &fimc->state)) {
fimc_activate_capture(ctx);
if (!test_and_set_bit(ST_CAPT_ISP_STREAM, &fimc->state))
fimc_pipeline_call(fimc, set_stream,
&fimc->pipeline, 1);
}
return 0;
}
static int stop_streaming(struct vb2_queue *q)
{
struct fimc_ctx *ctx = q->drv_priv;
struct fimc_dev *fimc = ctx->fimc_dev;
if (!fimc_capture_active(fimc))
return -EINVAL;
return fimc_stop_capture(fimc, false);
}
int fimc_capture_suspend(struct fimc_dev *fimc)
{
bool suspend = fimc_capture_busy(fimc);
int ret = fimc_stop_capture(fimc, suspend);
if (ret)
return ret;
return fimc_pipeline_call(fimc, close, &fimc->pipeline);
}
int fimc_capture_resume(struct fimc_dev *fimc)
{
struct fimc_vid_cap *vid_cap = &fimc->vid_cap;
struct fimc_vid_buffer *buf;
int i;
if (!test_and_clear_bit(ST_CAPT_SUSPENDED, &fimc->state))
return 0;
INIT_LIST_HEAD(&fimc->vid_cap.active_buf_q);
vid_cap->buf_index = 0;
fimc_pipeline_call(fimc, open, &fimc->pipeline,
&vid_cap->vfd.entity, false);
fimc_capture_hw_init(fimc);
clear_bit(ST_CAPT_SUSPENDED, &fimc->state);
for (i = 0; i < vid_cap->reqbufs_count; i++) {
if (list_empty(&vid_cap->pending_buf_q))
break;
buf = fimc_pending_queue_pop(vid_cap);
buffer_queue(&buf->vb);
}
return 0;
}
static int queue_setup(struct vb2_queue *vq, const struct v4l2_format *pfmt,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], void *allocators[])
{
const struct v4l2_pix_format_mplane *pixm = NULL;
struct fimc_ctx *ctx = vq->drv_priv;
struct fimc_frame *frame = &ctx->d_frame;
struct fimc_fmt *fmt = frame->fmt;
unsigned long wh;
int i;
if (pfmt) {
pixm = &pfmt->fmt.pix_mp;
fmt = fimc_find_format(&pixm->pixelformat, NULL,
FMT_FLAGS_CAM | FMT_FLAGS_M2M, -1);
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
else if (fimc_fmt_is_user_defined(fmt->color))
sizes[i] = frame->payload[i];
else
sizes[i] = max_t(u32, size, frame->payload[i]);
allocators[i] = ctx->fimc_dev->alloc_ctx;
}
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_queue *vq = vb->vb2_queue;
struct fimc_ctx *ctx = vq->drv_priv;
int i;
if (ctx->d_frame.fmt == NULL)
return -EINVAL;
for (i = 0; i < ctx->d_frame.fmt->memplanes; i++) {
unsigned long size = ctx->d_frame.payload[i];
if (vb2_plane_size(vb, i) < size) {
v4l2_err(&ctx->fimc_dev->vid_cap.vfd,
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
struct fimc_vid_buffer *buf
= container_of(vb, struct fimc_vid_buffer, vb);
struct fimc_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_vid_cap *vid_cap = &fimc->vid_cap;
unsigned long flags;
int min_bufs;
spin_lock_irqsave(&fimc->slock, flags);
fimc_prepare_addr(ctx, &buf->vb, &ctx->d_frame, &buf->paddr);
if (!test_bit(ST_CAPT_SUSPENDED, &fimc->state) &&
!test_bit(ST_CAPT_STREAM, &fimc->state) &&
vid_cap->active_buf_cnt < FIMC_MAX_OUT_BUFS) {
int buf_id = (vid_cap->reqbufs_count == 1) ? -1 :
vid_cap->buf_index;
fimc_hw_set_output_addr(fimc, &buf->paddr, buf_id);
buf->index = vid_cap->buf_index;
fimc_active_queue_add(vid_cap, buf);
if (++vid_cap->buf_index >= FIMC_MAX_OUT_BUFS)
vid_cap->buf_index = 0;
} else {
fimc_pending_queue_add(vid_cap, buf);
}
min_bufs = vid_cap->reqbufs_count > 1 ? 2 : 1;
if (vb2_is_streaming(&vid_cap->vbq) &&
vid_cap->active_buf_cnt >= min_bufs &&
!test_and_set_bit(ST_CAPT_STREAM, &fimc->state)) {
fimc_activate_capture(ctx);
spin_unlock_irqrestore(&fimc->slock, flags);
if (!test_and_set_bit(ST_CAPT_ISP_STREAM, &fimc->state))
fimc_pipeline_call(fimc, set_stream,
&fimc->pipeline, 1);
return;
}
spin_unlock_irqrestore(&fimc->slock, flags);
}
static void fimc_lock(struct vb2_queue *vq)
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vq);
mutex_lock(&ctx->fimc_dev->lock);
}
static void fimc_unlock(struct vb2_queue *vq)
{
struct fimc_ctx *ctx = vb2_get_drv_priv(vq);
mutex_unlock(&ctx->fimc_dev->lock);
}
int fimc_capture_ctrls_create(struct fimc_dev *fimc)
{
struct fimc_vid_cap *vid_cap = &fimc->vid_cap;
int ret;
if (WARN_ON(vid_cap->ctx == NULL))
return -ENXIO;
if (vid_cap->ctx->ctrls.ready)
return 0;
ret = fimc_ctrls_create(vid_cap->ctx);
if (ret || vid_cap->user_subdev_api || !vid_cap->ctx->ctrls.ready)
return ret;
return v4l2_ctrl_add_handler(&vid_cap->ctx->ctrls.handler,
fimc->pipeline.subdevs[IDX_SENSOR]->ctrl_handler, NULL);
}
static int fimc_capture_open(struct file *file)
{
struct fimc_dev *fimc = video_drvdata(file);
int ret = -EBUSY;
dbg("pid: %d, state: 0x%lx", task_pid_nr(current), fimc->state);
if (mutex_lock_interruptible(&fimc->lock))
return -ERESTARTSYS;
if (fimc_m2m_active(fimc))
goto unlock;
set_bit(ST_CAPT_BUSY, &fimc->state);
ret = pm_runtime_get_sync(&fimc->pdev->dev);
if (ret < 0)
goto unlock;
ret = v4l2_fh_open(file);
if (ret) {
pm_runtime_put(&fimc->pdev->dev);
goto unlock;
}
if (++fimc->vid_cap.refcnt == 1) {
ret = fimc_pipeline_call(fimc, open, &fimc->pipeline,
&fimc->vid_cap.vfd.entity, true);
if (!ret && !fimc->vid_cap.user_subdev_api)
ret = fimc_capture_set_default_format(fimc);
if (!ret)
ret = fimc_capture_ctrls_create(fimc);
if (ret < 0) {
clear_bit(ST_CAPT_BUSY, &fimc->state);
pm_runtime_put_sync(&fimc->pdev->dev);
fimc->vid_cap.refcnt--;
v4l2_fh_release(file);
}
}
unlock:
mutex_unlock(&fimc->lock);
return ret;
}
static int fimc_capture_close(struct file *file)
{
struct fimc_dev *fimc = video_drvdata(file);
int ret;
dbg("pid: %d, state: 0x%lx", task_pid_nr(current), fimc->state);
mutex_lock(&fimc->lock);
if (--fimc->vid_cap.refcnt == 0) {
clear_bit(ST_CAPT_BUSY, &fimc->state);
fimc_stop_capture(fimc, false);
fimc_pipeline_call(fimc, close, &fimc->pipeline);
clear_bit(ST_CAPT_SUSPENDED, &fimc->state);
}
pm_runtime_put(&fimc->pdev->dev);
if (fimc->vid_cap.refcnt == 0) {
vb2_queue_release(&fimc->vid_cap.vbq);
fimc_ctrls_delete(fimc->vid_cap.ctx);
}
ret = v4l2_fh_release(file);
mutex_unlock(&fimc->lock);
return ret;
}
static unsigned int fimc_capture_poll(struct file *file,
struct poll_table_struct *wait)
{
struct fimc_dev *fimc = video_drvdata(file);
int ret;
if (mutex_lock_interruptible(&fimc->lock))
return POLL_ERR;
ret = vb2_poll(&fimc->vid_cap.vbq, file, wait);
mutex_unlock(&fimc->lock);
return ret;
}
static int fimc_capture_mmap(struct file *file, struct vm_area_struct *vma)
{
struct fimc_dev *fimc = video_drvdata(file);
int ret;
if (mutex_lock_interruptible(&fimc->lock))
return -ERESTARTSYS;
ret = vb2_mmap(&fimc->vid_cap.vbq, vma);
mutex_unlock(&fimc->lock);
return ret;
}
static struct fimc_fmt *fimc_capture_try_format(struct fimc_ctx *ctx,
u32 *width, u32 *height,
u32 *code, u32 *fourcc, int pad)
{
bool rotation = ctx->rotation == 90 || ctx->rotation == 270;
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_variant *var = fimc->variant;
struct fimc_pix_limit *pl = var->pix_limit;
struct fimc_frame *dst = &ctx->d_frame;
u32 depth, min_w, max_w, min_h, align_h = 3;
u32 mask = FMT_FLAGS_CAM;
struct fimc_fmt *ffmt;
if (code && ctx->s_frame.fmt && pad == FIMC_SD_PAD_SOURCE &&
fimc_fmt_is_user_defined(ctx->s_frame.fmt->color))
*code = ctx->s_frame.fmt->mbus_code;
if (fourcc && *fourcc != V4L2_PIX_FMT_JPEG && pad != FIMC_SD_PAD_SINK)
mask |= FMT_FLAGS_M2M;
ffmt = fimc_find_format(fourcc, code, mask, 0);
if (WARN_ON(!ffmt))
return NULL;
if (code)
*code = ffmt->mbus_code;
if (fourcc)
*fourcc = ffmt->fourcc;
if (pad == FIMC_SD_PAD_SINK) {
max_w = fimc_fmt_is_user_defined(ffmt->color) ?
pl->scaler_dis_w : pl->scaler_en_w;
v4l_bound_align_image(width, max_t(u32, *width, 32), max_w, 4,
height, max_t(u32, *height, 32),
FIMC_CAMIF_MAX_HEIGHT,
fimc_fmt_is_user_defined(ffmt->color) ?
3 : 1,
0);
return ffmt;
}
if (fimc_fmt_is_user_defined(ffmt->color)) {
*width = ctx->s_frame.f_width;
*height = ctx->s_frame.f_height;
return ffmt;
}
max_w = rotation ? pl->out_rot_en_w : pl->out_rot_dis_w;
if (ctx->state & FIMC_COMPOSE) {
min_w = dst->offs_h + dst->width;
min_h = dst->offs_v + dst->height;
} else {
min_w = var->min_out_pixsize;
min_h = var->min_out_pixsize;
}
if (var->min_vsize_align == 1 && !rotation)
align_h = fimc_fmt_is_rgb(ffmt->color) ? 0 : 1;
depth = fimc_get_format_depth(ffmt);
v4l_bound_align_image(width, min_w, max_w,
ffs(var->min_out_pixsize) - 1,
height, min_h, FIMC_CAMIF_MAX_HEIGHT,
align_h,
64/(ALIGN(depth, 8)));
dbg("pad%d: code: 0x%x, %dx%d. dst fmt: %dx%d",
pad, code ? *code : 0, *width, *height,
dst->f_width, dst->f_height);
return ffmt;
}
static void fimc_capture_try_selection(struct fimc_ctx *ctx,
struct v4l2_rect *r,
int target)
{
bool rotate = ctx->rotation == 90 || ctx->rotation == 270;
struct fimc_dev *fimc = ctx->fimc_dev;
struct fimc_variant *var = fimc->variant;
struct fimc_pix_limit *pl = var->pix_limit;
struct fimc_frame *sink = &ctx->s_frame;
u32 max_w, max_h, min_w = 0, min_h = 0, min_sz;
u32 align_sz = 0, align_h = 4;
u32 max_sc_h, max_sc_v;
if (fimc_fmt_is_user_defined(ctx->d_frame.fmt->color)) {
r->width = sink->f_width;
r->height = sink->f_height;
r->left = r->top = 0;
return;
}
if (target == V4L2_SEL_TGT_COMPOSE) {
if (ctx->rotation != 90 && ctx->rotation != 270)
align_h = 1;
max_sc_h = min(SCALER_MAX_HRATIO, 1 << (ffs(sink->width) - 3));
max_sc_v = min(SCALER_MAX_VRATIO, 1 << (ffs(sink->height) - 1));
min_sz = var->min_out_pixsize;
} else {
u32 depth = fimc_get_format_depth(sink->fmt);
align_sz = 64/ALIGN(depth, 8);
min_sz = var->min_inp_pixsize;
min_w = min_h = min_sz;
max_sc_h = max_sc_v = 1;
}
max_w = min_t(u32,
rotate ? pl->out_rot_en_w : pl->out_rot_dis_w,
rotate ? sink->f_height : sink->f_width);
max_h = min_t(u32, FIMC_CAMIF_MAX_HEIGHT, sink->f_height);
if (target == V4L2_SEL_TGT_COMPOSE) {
min_w = min_t(u32, max_w, sink->f_width / max_sc_h);
min_h = min_t(u32, max_h, sink->f_height / max_sc_v);
if (rotate) {
swap(max_sc_h, max_sc_v);
swap(min_w, min_h);
}
}
v4l_bound_align_image(&r->width, min_w, max_w, ffs(min_sz) - 1,
&r->height, min_h, max_h, align_h,
align_sz);
r->left = clamp_t(u32, r->left, 0, sink->f_width - r->width);
r->top = clamp_t(u32, r->top, 0, sink->f_height - r->height);
r->left = round_down(r->left, var->hor_offs_align);
dbg("target %#x: (%d,%d)/%dx%d, sink fmt: %dx%d",
target, r->left, r->top, r->width, r->height,
sink->f_width, sink->f_height);
}
static int fimc_vidioc_querycap_capture(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct fimc_dev *fimc = video_drvdata(file);
strncpy(cap->driver, fimc->pdev->name, sizeof(cap->driver) - 1);
strncpy(cap->card, fimc->pdev->name, sizeof(cap->card) - 1);
cap->bus_info[0] = 0;
cap->capabilities = V4L2_CAP_STREAMING | V4L2_CAP_VIDEO_CAPTURE_MPLANE;
return 0;
}
static int fimc_cap_enum_fmt_mplane(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct fimc_fmt *fmt;
fmt = fimc_find_format(NULL, NULL, FMT_FLAGS_CAM | FMT_FLAGS_M2M,
f->index);
if (!fmt)
return -EINVAL;
strncpy(f->description, fmt->name, sizeof(f->description) - 1);
f->pixelformat = fmt->fourcc;
if (fmt->fourcc == V4L2_MBUS_FMT_JPEG_1X8)
f->flags |= V4L2_FMT_FLAG_COMPRESSED;
return 0;
}
static int fimc_pipeline_try_format(struct fimc_ctx *ctx,
struct v4l2_mbus_framefmt *tfmt,
struct fimc_fmt **fmt_id,
bool set)
{
struct fimc_dev *fimc = ctx->fimc_dev;
struct v4l2_subdev *sd = fimc->pipeline.subdevs[IDX_SENSOR];
struct v4l2_subdev *csis = fimc->pipeline.subdevs[IDX_CSIS];
struct v4l2_subdev_format sfmt;
struct v4l2_mbus_framefmt *mf = &sfmt.format;
struct fimc_fmt *ffmt = NULL;
int ret, i = 0;
if (WARN_ON(!sd || !tfmt))
return -EINVAL;
memset(&sfmt, 0, sizeof(sfmt));
sfmt.format = *tfmt;
sfmt.which = set ? V4L2_SUBDEV_FORMAT_ACTIVE : V4L2_SUBDEV_FORMAT_TRY;
while (1) {
ffmt = fimc_find_format(NULL, mf->code != 0 ? &mf->code : NULL,
FMT_FLAGS_CAM, i++);
if (ffmt == NULL) {
return -EINVAL;
}
mf->code = tfmt->code = ffmt->mbus_code;
ret = v4l2_subdev_call(sd, pad, set_fmt, NULL, &sfmt);
if (ret)
return ret;
if (mf->code != tfmt->code) {
mf->code = 0;
continue;
}
if (mf->width != tfmt->width || mf->height != tfmt->height) {
u32 fcc = ffmt->fourcc;
tfmt->width = mf->width;
tfmt->height = mf->height;
ffmt = fimc_capture_try_format(ctx,
&tfmt->width, &tfmt->height,
NULL, &fcc, FIMC_SD_PAD_SOURCE);
if (ffmt && ffmt->mbus_code)
mf->code = ffmt->mbus_code;
if (mf->width != tfmt->width ||
mf->height != tfmt->height)
continue;
tfmt->code = mf->code;
}
if (csis)
ret = v4l2_subdev_call(csis, pad, set_fmt, NULL, &sfmt);
if (mf->code == tfmt->code &&
mf->width == tfmt->width && mf->height == tfmt->height)
break;
}
if (fmt_id && ffmt)
*fmt_id = ffmt;
*tfmt = *mf;
dbg("code: 0x%x, %dx%d, %p", mf->code, mf->width, mf->height, ffmt);
return 0;
}
static int fimc_get_sensor_frame_desc(struct v4l2_subdev *sensor,
struct v4l2_plane_pix_format *plane_fmt,
unsigned int num_planes, bool try)
{
struct v4l2_mbus_frame_desc fd;
int i, ret;
for (i = 0; i < num_planes; i++)
fd.entry[i].length = plane_fmt[i].sizeimage;
if (try)
ret = v4l2_subdev_call(sensor, pad, set_frame_desc, 0, &fd);
else
ret = v4l2_subdev_call(sensor, pad, get_frame_desc, 0, &fd);
if (ret < 0)
return ret;
if (num_planes != fd.num_entries)
return -EINVAL;
for (i = 0; i < num_planes; i++)
plane_fmt[i].sizeimage = fd.entry[i].length;
if (fd.entry[0].length > FIMC_MAX_JPEG_BUF_SIZE) {
v4l2_err(sensor->v4l2_dev, "Unsupported buffer size: %u\n",
fd.entry[0].length);
return -EINVAL;
}
return 0;
}
static int fimc_cap_g_fmt_mplane(struct file *file, void *fh,
struct v4l2_format *f)
{
struct fimc_dev *fimc = video_drvdata(file);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
return fimc_fill_format(&ctx->d_frame, f);
}
static int fimc_cap_try_fmt_mplane(struct file *file, void *fh,
struct v4l2_format *f)
{
struct v4l2_pix_format_mplane *pix = &f->fmt.pix_mp;
struct fimc_dev *fimc = video_drvdata(file);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct v4l2_mbus_framefmt mf;
struct fimc_fmt *ffmt = NULL;
if (fimc_jpeg_fourcc(pix->pixelformat)) {
fimc_capture_try_format(ctx, &pix->width, &pix->height,
NULL, &pix->pixelformat,
FIMC_SD_PAD_SINK);
ctx->s_frame.f_width = pix->width;
ctx->s_frame.f_height = pix->height;
}
ffmt = fimc_capture_try_format(ctx, &pix->width, &pix->height,
NULL, &pix->pixelformat,
FIMC_SD_PAD_SOURCE);
if (!ffmt)
return -EINVAL;
if (!fimc->vid_cap.user_subdev_api) {
mf.width = pix->width;
mf.height = pix->height;
mf.code = ffmt->mbus_code;
fimc_md_graph_lock(fimc);
fimc_pipeline_try_format(ctx, &mf, &ffmt, false);
fimc_md_graph_unlock(fimc);
pix->width = mf.width;
pix->height = mf.height;
if (ffmt)
pix->pixelformat = ffmt->fourcc;
}
fimc_adjust_mplane_format(ffmt, pix->width, pix->height, pix);
if (ffmt->flags & FMT_FLAGS_COMPRESSED)
fimc_get_sensor_frame_desc(fimc->pipeline.subdevs[IDX_SENSOR],
pix->plane_fmt, ffmt->memplanes, true);
return 0;
}
static void fimc_capture_mark_jpeg_xfer(struct fimc_ctx *ctx,
enum fimc_color_fmt color)
{
bool jpeg = fimc_fmt_is_user_defined(color);
ctx->scaler.enabled = !jpeg;
fimc_ctrls_activate(ctx, !jpeg);
if (jpeg)
set_bit(ST_CAPT_JPEG, &ctx->fimc_dev->state);
else
clear_bit(ST_CAPT_JPEG, &ctx->fimc_dev->state);
}
static int fimc_capture_set_format(struct fimc_dev *fimc, struct v4l2_format *f)
{
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct v4l2_pix_format_mplane *pix = &f->fmt.pix_mp;
struct v4l2_mbus_framefmt *mf = &fimc->vid_cap.mf;
struct fimc_frame *ff = &ctx->d_frame;
struct fimc_fmt *s_fmt = NULL;
int ret, i;
if (vb2_is_busy(&fimc->vid_cap.vbq))
return -EBUSY;
if (fimc_jpeg_fourcc(pix->pixelformat)) {
fimc_capture_try_format(ctx, &pix->width, &pix->height,
NULL, &pix->pixelformat,
FIMC_SD_PAD_SINK);
ctx->s_frame.f_width = pix->width;
ctx->s_frame.f_height = pix->height;
}
ff->fmt = fimc_capture_try_format(ctx, &pix->width, &pix->height,
NULL, &pix->pixelformat,
FIMC_SD_PAD_SOURCE);
if (!ff->fmt)
return -EINVAL;
fimc_alpha_ctrl_update(ctx);
if (!fimc->vid_cap.user_subdev_api) {
mf->code = ff->fmt->mbus_code;
mf->width = pix->width;
mf->height = pix->height;
fimc_md_graph_lock(fimc);
ret = fimc_pipeline_try_format(ctx, mf, &s_fmt, true);
fimc_md_graph_unlock(fimc);
if (ret)
return ret;
pix->width = mf->width;
pix->height = mf->height;
}
fimc_adjust_mplane_format(ff->fmt, pix->width, pix->height, pix);
if (ff->fmt->flags & FMT_FLAGS_COMPRESSED) {
ret = fimc_get_sensor_frame_desc(fimc->pipeline.subdevs[IDX_SENSOR],
pix->plane_fmt, ff->fmt->memplanes,
true);
if (ret < 0)
return ret;
}
for (i = 0; i < ff->fmt->memplanes; i++)
ff->payload[i] = pix->plane_fmt[i].sizeimage;
set_frame_bounds(ff, pix->width, pix->height);
if (!(ctx->state & FIMC_COMPOSE))
set_frame_crop(ff, 0, 0, pix->width, pix->height);
fimc_capture_mark_jpeg_xfer(ctx, ff->fmt->color);
if (!fimc->vid_cap.user_subdev_api) {
ctx->s_frame.fmt = s_fmt;
set_frame_bounds(&ctx->s_frame, pix->width, pix->height);
set_frame_crop(&ctx->s_frame, 0, 0, pix->width, pix->height);
}
return ret;
}
static int fimc_cap_s_fmt_mplane(struct file *file, void *priv,
struct v4l2_format *f)
{
struct fimc_dev *fimc = video_drvdata(file);
return fimc_capture_set_format(fimc, f);
}
static int fimc_cap_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct fimc_dev *fimc = video_drvdata(file);
struct v4l2_subdev *sd = fimc->pipeline.subdevs[IDX_SENSOR];
if (i->index != 0)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
if (sd)
strlcpy(i->name, sd->name, sizeof(i->name));
return 0;
}
static int fimc_cap_s_input(struct file *file, void *priv, unsigned int i)
{
return i == 0 ? i : -EINVAL;
}
static int fimc_cap_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int fimc_pipeline_validate(struct fimc_dev *fimc)
{
struct v4l2_subdev_format sink_fmt, src_fmt;
struct fimc_vid_cap *vid_cap = &fimc->vid_cap;
struct v4l2_subdev *sd;
struct media_pad *pad;
int ret;
pad = media_entity_remote_source(&vid_cap->vd_pad);
if (pad == NULL)
return -EPIPE;
sd = media_entity_to_v4l2_subdev(pad->entity);
while (1) {
pad = &sd->entity.pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
if (sd == &fimc->vid_cap.subdev) {
struct fimc_frame *ff = &vid_cap->ctx->s_frame;
sink_fmt.format.width = ff->f_width;
sink_fmt.format.height = ff->f_height;
sink_fmt.format.code = ff->fmt ? ff->fmt->mbus_code : 0;
} else {
sink_fmt.pad = pad->index;
sink_fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(sd, pad, get_fmt, NULL, &sink_fmt);
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
if (sd == fimc->pipeline.subdevs[IDX_SENSOR] &&
fimc_user_defined_mbus_fmt(src_fmt.format.code)) {
struct v4l2_plane_pix_format plane_fmt[FIMC_MAX_PLANES];
struct fimc_frame *frame = &vid_cap->ctx->d_frame;
unsigned int i;
ret = fimc_get_sensor_frame_desc(sd, plane_fmt,
frame->fmt->memplanes,
false);
if (ret < 0)
return -EPIPE;
for (i = 0; i < frame->fmt->memplanes; i++)
if (frame->payload[i] < plane_fmt[i].sizeimage)
return -EPIPE;
}
}
return 0;
}
static int fimc_cap_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct fimc_dev *fimc = video_drvdata(file);
struct fimc_pipeline *p = &fimc->pipeline;
struct v4l2_subdev *sd = p->subdevs[IDX_SENSOR];
int ret;
if (fimc_capture_active(fimc))
return -EBUSY;
ret = media_entity_pipeline_start(&sd->entity, p->m_pipeline);
if (ret < 0)
return ret;
if (fimc->vid_cap.user_subdev_api) {
ret = fimc_pipeline_validate(fimc);
if (ret < 0) {
media_entity_pipeline_stop(&sd->entity);
return ret;
}
}
return vb2_streamon(&fimc->vid_cap.vbq, type);
}
static int fimc_cap_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct fimc_dev *fimc = video_drvdata(file);
struct v4l2_subdev *sd = fimc->pipeline.subdevs[IDX_SENSOR];
int ret;
ret = vb2_streamoff(&fimc->vid_cap.vbq, type);
if (ret == 0)
media_entity_pipeline_stop(&sd->entity);
return ret;
}
static int fimc_cap_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbufs)
{
struct fimc_dev *fimc = video_drvdata(file);
int ret = vb2_reqbufs(&fimc->vid_cap.vbq, reqbufs);
if (!ret)
fimc->vid_cap.reqbufs_count = reqbufs->count;
return ret;
}
static int fimc_cap_querybuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct fimc_dev *fimc = video_drvdata(file);
return vb2_querybuf(&fimc->vid_cap.vbq, buf);
}
static int fimc_cap_qbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct fimc_dev *fimc = video_drvdata(file);
return vb2_qbuf(&fimc->vid_cap.vbq, buf);
}
static int fimc_cap_expbuf(struct file *file, void *priv,
struct v4l2_exportbuffer *eb)
{
struct fimc_dev *fimc = video_drvdata(file);
return vb2_expbuf(&fimc->vid_cap.vbq, eb);
}
static int fimc_cap_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct fimc_dev *fimc = video_drvdata(file);
return vb2_dqbuf(&fimc->vid_cap.vbq, buf, file->f_flags & O_NONBLOCK);
}
static int fimc_cap_create_bufs(struct file *file, void *priv,
struct v4l2_create_buffers *create)
{
struct fimc_dev *fimc = video_drvdata(file);
return vb2_create_bufs(&fimc->vid_cap.vbq, create);
}
static int fimc_cap_prepare_buf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct fimc_dev *fimc = video_drvdata(file);
return vb2_prepare_buf(&fimc->vid_cap.vbq, b);
}
static int fimc_cap_g_selection(struct file *file, void *fh,
struct v4l2_selection *s)
{
struct fimc_dev *fimc = video_drvdata(file);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct fimc_frame *f = &ctx->s_frame;
if (s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
return -EINVAL;
switch (s->target) {
case V4L2_SEL_TGT_COMPOSE_DEFAULT:
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
f = &ctx->d_frame;
case V4L2_SEL_TGT_CROP_BOUNDS:
case V4L2_SEL_TGT_CROP_DEFAULT:
s->r.left = 0;
s->r.top = 0;
s->r.width = f->o_width;
s->r.height = f->o_height;
return 0;
case V4L2_SEL_TGT_COMPOSE:
f = &ctx->d_frame;
case V4L2_SEL_TGT_CROP:
s->r.left = f->offs_h;
s->r.top = f->offs_v;
s->r.width = f->width;
s->r.height = f->height;
return 0;
}
return -EINVAL;
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
static int fimc_cap_s_selection(struct file *file, void *fh,
struct v4l2_selection *s)
{
struct fimc_dev *fimc = video_drvdata(file);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct v4l2_rect rect = s->r;
struct fimc_frame *f;
unsigned long flags;
if (s->type != V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE)
return -EINVAL;
if (s->target == V4L2_SEL_TGT_COMPOSE)
f = &ctx->d_frame;
else if (s->target == V4L2_SEL_TGT_CROP)
f = &ctx->s_frame;
else
return -EINVAL;
fimc_capture_try_selection(ctx, &rect, s->target);
if (s->flags & V4L2_SEL_FLAG_LE &&
!enclosed_rectangle(&rect, &s->r))
return -ERANGE;
if (s->flags & V4L2_SEL_FLAG_GE &&
!enclosed_rectangle(&s->r, &rect))
return -ERANGE;
s->r = rect;
spin_lock_irqsave(&fimc->slock, flags);
set_frame_crop(f, s->r.left, s->r.top, s->r.width,
s->r.height);
spin_unlock_irqrestore(&fimc->slock, flags);
set_bit(ST_CAPT_APPLY_CFG, &fimc->state);
return 0;
}
static int fimc_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
if (media_entity_type(remote->entity) != MEDIA_ENT_T_V4L2_SUBDEV)
return -EINVAL;
if (WARN_ON(fimc == NULL))
return 0;
dbg("%s --> %s, flags: 0x%x. input: 0x%x",
local->entity->name, remote->entity->name, flags,
fimc->vid_cap.input);
if (flags & MEDIA_LNK_FL_ENABLED) {
if (fimc->vid_cap.input != 0)
return -EBUSY;
fimc->vid_cap.input = sd->grp_id;
return 0;
}
fimc->vid_cap.input = 0;
return 0;
}
void fimc_sensor_notify(struct v4l2_subdev *sd, unsigned int notification,
void *arg)
{
struct fimc_sensor_info *sensor;
struct fimc_vid_buffer *buf;
struct fimc_md *fmd;
struct fimc_dev *fimc;
unsigned long flags;
if (sd == NULL)
return;
sensor = v4l2_get_subdev_hostdata(sd);
fmd = entity_to_fimc_mdev(&sd->entity);
spin_lock_irqsave(&fmd->slock, flags);
fimc = sensor ? sensor->host : NULL;
if (fimc && arg && notification == S5P_FIMC_TX_END_NOTIFY &&
test_bit(ST_CAPT_PEND, &fimc->state)) {
unsigned long irq_flags;
spin_lock_irqsave(&fimc->slock, irq_flags);
if (!list_empty(&fimc->vid_cap.active_buf_q)) {
buf = list_entry(fimc->vid_cap.active_buf_q.next,
struct fimc_vid_buffer, list);
vb2_set_plane_payload(&buf->vb, 0, *((u32 *)arg));
}
fimc_capture_irq_handler(fimc, 1);
fimc_deactivate_capture(fimc);
spin_unlock_irqrestore(&fimc->slock, irq_flags);
}
spin_unlock_irqrestore(&fmd->slock, flags);
}
static int fimc_subdev_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
struct fimc_fmt *fmt;
fmt = fimc_find_format(NULL, NULL, FMT_FLAGS_CAM, code->index);
if (!fmt)
return -EINVAL;
code->code = fmt->mbus_code;
return 0;
}
static int fimc_subdev_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct v4l2_mbus_framefmt *mf;
struct fimc_frame *ff;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(fh, fmt->pad);
fmt->format = *mf;
return 0;
}
mf = &fmt->format;
mf->colorspace = V4L2_COLORSPACE_JPEG;
ff = fmt->pad == FIMC_SD_PAD_SINK ? &ctx->s_frame : &ctx->d_frame;
mutex_lock(&fimc->lock);
if (!WARN_ON(ctx->s_frame.fmt == NULL))
mf->code = ctx->s_frame.fmt->mbus_code;
mf->width = ff->f_width;
mf->height = ff->f_height;
mutex_unlock(&fimc->lock);
return 0;
}
static int fimc_subdev_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *mf = &fmt->format;
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct fimc_frame *ff;
struct fimc_fmt *ffmt;
dbg("pad%d: code: 0x%x, %dx%d",
fmt->pad, mf->code, mf->width, mf->height);
if (fmt->pad == FIMC_SD_PAD_SOURCE &&
vb2_is_busy(&fimc->vid_cap.vbq))
return -EBUSY;
mutex_lock(&fimc->lock);
ffmt = fimc_capture_try_format(ctx, &mf->width, &mf->height,
&mf->code, NULL, fmt->pad);
mutex_unlock(&fimc->lock);
mf->colorspace = V4L2_COLORSPACE_JPEG;
if (fmt->which == V4L2_SUBDEV_FORMAT_TRY) {
mf = v4l2_subdev_get_try_format(fh, fmt->pad);
*mf = fmt->format;
return 0;
}
fimc_alpha_ctrl_update(ctx);
fimc_capture_mark_jpeg_xfer(ctx, ffmt->color);
ff = fmt->pad == FIMC_SD_PAD_SINK ?
&ctx->s_frame : &ctx->d_frame;
mutex_lock(&fimc->lock);
set_frame_bounds(ff, mf->width, mf->height);
fimc->vid_cap.mf = *mf;
ff->fmt = ffmt;
if (!(fmt->pad == FIMC_SD_PAD_SOURCE && (ctx->state & FIMC_COMPOSE)))
set_frame_crop(ff, 0, 0, mf->width, mf->height);
if (fmt->pad == FIMC_SD_PAD_SINK)
ctx->state &= ~FIMC_COMPOSE;
mutex_unlock(&fimc->lock);
return 0;
}
static int fimc_subdev_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_selection *sel)
{
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct fimc_frame *f = &ctx->s_frame;
struct v4l2_rect *r = &sel->r;
struct v4l2_rect *try_sel;
if (sel->pad != FIMC_SD_PAD_SINK)
return -EINVAL;
mutex_lock(&fimc->lock);
switch (sel->target) {
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
f = &ctx->d_frame;
case V4L2_SEL_TGT_CROP_BOUNDS:
r->width = f->o_width;
r->height = f->o_height;
r->left = 0;
r->top = 0;
mutex_unlock(&fimc->lock);
return 0;
case V4L2_SEL_TGT_CROP:
try_sel = v4l2_subdev_get_try_crop(fh, sel->pad);
break;
case V4L2_SEL_TGT_COMPOSE:
try_sel = v4l2_subdev_get_try_compose(fh, sel->pad);
f = &ctx->d_frame;
break;
default:
mutex_unlock(&fimc->lock);
return -EINVAL;
}
if (sel->which == V4L2_SUBDEV_FORMAT_TRY) {
sel->r = *try_sel;
} else {
r->left = f->offs_h;
r->top = f->offs_v;
r->width = f->width;
r->height = f->height;
}
dbg("target %#x: l:%d, t:%d, %dx%d, f_w: %d, f_h: %d",
sel->pad, r->left, r->top, r->width, r->height,
f->f_width, f->f_height);
mutex_unlock(&fimc->lock);
return 0;
}
static int fimc_subdev_set_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_selection *sel)
{
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
struct fimc_ctx *ctx = fimc->vid_cap.ctx;
struct fimc_frame *f = &ctx->s_frame;
struct v4l2_rect *r = &sel->r;
struct v4l2_rect *try_sel;
unsigned long flags;
if (sel->pad != FIMC_SD_PAD_SINK)
return -EINVAL;
mutex_lock(&fimc->lock);
fimc_capture_try_selection(ctx, r, V4L2_SEL_TGT_CROP);
switch (sel->target) {
case V4L2_SEL_TGT_COMPOSE_BOUNDS:
f = &ctx->d_frame;
case V4L2_SEL_TGT_CROP_BOUNDS:
r->width = f->o_width;
r->height = f->o_height;
r->left = 0;
r->top = 0;
mutex_unlock(&fimc->lock);
return 0;
case V4L2_SEL_TGT_CROP:
try_sel = v4l2_subdev_get_try_crop(fh, sel->pad);
break;
case V4L2_SEL_TGT_COMPOSE:
try_sel = v4l2_subdev_get_try_compose(fh, sel->pad);
f = &ctx->d_frame;
break;
default:
mutex_unlock(&fimc->lock);
return -EINVAL;
}
if (sel->which == V4L2_SUBDEV_FORMAT_TRY) {
*try_sel = sel->r;
} else {
spin_lock_irqsave(&fimc->slock, flags);
set_frame_crop(f, r->left, r->top, r->width, r->height);
set_bit(ST_CAPT_APPLY_CFG, &fimc->state);
spin_unlock_irqrestore(&fimc->slock, flags);
if (sel->target == V4L2_SEL_TGT_COMPOSE)
ctx->state |= FIMC_COMPOSE;
}
dbg("target %#x: (%d,%d)/%dx%d", sel->target, r->left, r->top,
r->width, r->height);
mutex_unlock(&fimc->lock);
return 0;
}
static int fimc_capture_set_default_format(struct fimc_dev *fimc)
{
struct v4l2_format fmt = {
.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE,
.fmt.pix_mp = {
.width = 640,
.height = 480,
.pixelformat = V4L2_PIX_FMT_YUYV,
.field = V4L2_FIELD_NONE,
.colorspace = V4L2_COLORSPACE_JPEG,
},
};
return fimc_capture_set_format(fimc, &fmt);
}
static int fimc_register_capture_device(struct fimc_dev *fimc,
struct v4l2_device *v4l2_dev)
{
struct video_device *vfd = &fimc->vid_cap.vfd;
struct fimc_vid_cap *vid_cap;
struct fimc_ctx *ctx;
struct vb2_queue *q;
int ret = -ENOMEM;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->fimc_dev = fimc;
ctx->in_path = FIMC_IO_CAMERA;
ctx->out_path = FIMC_IO_DMA;
ctx->state = FIMC_CTX_CAP;
ctx->s_frame.fmt = fimc_find_format(NULL, NULL, FMT_FLAGS_CAM, 0);
ctx->d_frame.fmt = ctx->s_frame.fmt;
memset(vfd, 0, sizeof(*vfd));
snprintf(vfd->name, sizeof(vfd->name), "fimc.%d.capture", fimc->id);
vfd->fops = &fimc_capture_fops;
vfd->ioctl_ops = &fimc_capture_ioctl_ops;
vfd->v4l2_dev = v4l2_dev;
vfd->minor = -1;
vfd->release = video_device_release_empty;
vfd->lock = &fimc->lock;
video_set_drvdata(vfd, fimc);
vid_cap = &fimc->vid_cap;
vid_cap->active_buf_cnt = 0;
vid_cap->reqbufs_count = 0;
vid_cap->refcnt = 0;
INIT_LIST_HEAD(&vid_cap->pending_buf_q);
INIT_LIST_HEAD(&vid_cap->active_buf_q);
vid_cap->ctx = ctx;
q = &fimc->vid_cap.vbq;
memset(q, 0, sizeof(*q));
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
q->drv_priv = fimc->vid_cap.ctx;
q->ops = &fimc_capture_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct fimc_vid_buffer);
ret = vb2_queue_init(q);
if (ret)
goto err_ent;
vid_cap->vd_pad.flags = MEDIA_PAD_FL_SINK;
ret = media_entity_init(&vfd->entity, 1, &vid_cap->vd_pad, 0);
if (ret)
goto err_ent;
ret = video_register_device(vfd, VFL_TYPE_GRABBER, -1);
if (ret)
goto err_vd;
v4l2_info(v4l2_dev, "Registered %s as /dev/%s\n",
vfd->name, video_device_node_name(vfd));
vfd->ctrl_handler = &ctx->ctrls.handler;
return 0;
err_vd:
media_entity_cleanup(&vfd->entity);
err_ent:
kfree(ctx);
return ret;
}
static int fimc_capture_subdev_registered(struct v4l2_subdev *sd)
{
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
int ret;
if (fimc == NULL)
return -ENXIO;
ret = fimc_register_m2m_device(fimc, sd->v4l2_dev);
if (ret)
return ret;
fimc->pipeline_ops = v4l2_get_subdev_hostdata(sd);
ret = fimc_register_capture_device(fimc, sd->v4l2_dev);
if (ret) {
fimc_unregister_m2m_device(fimc);
fimc->pipeline_ops = NULL;
}
return ret;
}
static void fimc_capture_subdev_unregistered(struct v4l2_subdev *sd)
{
struct fimc_dev *fimc = v4l2_get_subdevdata(sd);
if (fimc == NULL)
return;
fimc_unregister_m2m_device(fimc);
if (video_is_registered(&fimc->vid_cap.vfd)) {
video_unregister_device(&fimc->vid_cap.vfd);
media_entity_cleanup(&fimc->vid_cap.vfd.entity);
fimc->pipeline_ops = NULL;
}
kfree(fimc->vid_cap.ctx);
fimc->vid_cap.ctx = NULL;
}
int fimc_initialize_capture_subdev(struct fimc_dev *fimc)
{
struct v4l2_subdev *sd = &fimc->vid_cap.subdev;
int ret;
v4l2_subdev_init(sd, &fimc_subdev_ops);
sd->flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
snprintf(sd->name, sizeof(sd->name), "FIMC.%d", fimc->pdev->id);
fimc->vid_cap.sd_pads[FIMC_SD_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
fimc->vid_cap.sd_pads[FIMC_SD_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&sd->entity, FIMC_SD_PADS_NUM,
fimc->vid_cap.sd_pads, 0);
if (ret)
return ret;
sd->entity.ops = &fimc_sd_media_ops;
sd->internal_ops = &fimc_capture_sd_internal_ops;
v4l2_set_subdevdata(sd, fimc);
return 0;
}
void fimc_unregister_capture_subdev(struct fimc_dev *fimc)
{
struct v4l2_subdev *sd = &fimc->vid_cap.subdev;
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
v4l2_set_subdevdata(sd, NULL);
}
