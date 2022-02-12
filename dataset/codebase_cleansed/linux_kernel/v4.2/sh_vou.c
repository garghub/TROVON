static void sh_vou_reg_a_write(struct sh_vou_device *vou_dev, unsigned int reg,
u32 value)
{
__raw_writel(value, vou_dev->base + reg);
}
static void sh_vou_reg_ab_write(struct sh_vou_device *vou_dev, unsigned int reg,
u32 value)
{
__raw_writel(value, vou_dev->base + reg);
__raw_writel(value, vou_dev->base + reg + 0x1000);
}
static void sh_vou_reg_m_write(struct sh_vou_device *vou_dev, unsigned int reg,
u32 value)
{
__raw_writel(value, vou_dev->base + reg + 0x2000);
}
static u32 sh_vou_reg_a_read(struct sh_vou_device *vou_dev, unsigned int reg)
{
return __raw_readl(vou_dev->base + reg);
}
static void sh_vou_reg_a_set(struct sh_vou_device *vou_dev, unsigned int reg,
u32 value, u32 mask)
{
u32 old = __raw_readl(vou_dev->base + reg);
value = (value & mask) | (old & ~mask);
__raw_writel(value, vou_dev->base + reg);
}
static void sh_vou_reg_b_set(struct sh_vou_device *vou_dev, unsigned int reg,
u32 value, u32 mask)
{
sh_vou_reg_a_set(vou_dev, reg + 0x1000, value, mask);
}
static void sh_vou_reg_ab_set(struct sh_vou_device *vou_dev, unsigned int reg,
u32 value, u32 mask)
{
sh_vou_reg_a_set(vou_dev, reg, value, mask);
sh_vou_reg_b_set(vou_dev, reg, value, mask);
}
static void sh_vou_schedule_next(struct sh_vou_device *vou_dev,
struct videobuf_buffer *vb)
{
dma_addr_t addr1, addr2;
addr1 = videobuf_to_dma_contig(vb);
switch (vou_dev->pix.pixelformat) {
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV16:
addr2 = addr1 + vou_dev->pix.width * vou_dev->pix.height;
break;
default:
addr2 = 0;
}
sh_vou_reg_m_write(vou_dev, VOUAD1R, addr1);
sh_vou_reg_m_write(vou_dev, VOUAD2R, addr2);
}
static void sh_vou_stream_start(struct sh_vou_device *vou_dev,
struct videobuf_buffer *vb)
{
unsigned int row_coeff;
#ifdef __LITTLE_ENDIAN
u32 dataswap = 7;
#else
u32 dataswap = 0;
#endif
switch (vou_dev->pix.pixelformat) {
default:
case V4L2_PIX_FMT_NV12:
case V4L2_PIX_FMT_NV16:
row_coeff = 1;
break;
case V4L2_PIX_FMT_RGB565:
dataswap ^= 1;
case V4L2_PIX_FMT_RGB565X:
row_coeff = 2;
break;
case V4L2_PIX_FMT_RGB24:
row_coeff = 3;
break;
}
sh_vou_reg_a_write(vou_dev, VOUSWR, dataswap);
sh_vou_reg_ab_write(vou_dev, VOUAIR, vou_dev->pix.width * row_coeff);
sh_vou_schedule_next(vou_dev, vb);
}
static void free_buffer(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
BUG_ON(in_interrupt());
videobuf_waiton(vq, vb, 0, 0);
videobuf_dma_contig_free(vq, vb);
vb->state = VIDEOBUF_NEEDS_INIT;
}
static int sh_vou_buf_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct video_device *vdev = vq->priv_data;
struct sh_vou_device *vou_dev = video_get_drvdata(vdev);
*size = vou_fmt[vou_dev->pix_idx].bpp * vou_dev->pix.width *
vou_dev->pix.height / 8;
if (*count < 2)
*count = 2;
if (PAGE_ALIGN(*size) * *count > 4 * 1024 * 1024)
*count = 4 * 1024 * 1024 / PAGE_ALIGN(*size);
dev_dbg(vou_dev->v4l2_dev.dev, "%s(): count=%d, size=%d\n", __func__,
*count, *size);
return 0;
}
static int sh_vou_buf_prepare(struct videobuf_queue *vq,
struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct video_device *vdev = vq->priv_data;
struct sh_vou_device *vou_dev = video_get_drvdata(vdev);
struct v4l2_pix_format *pix = &vou_dev->pix;
int bytes_per_line = vou_fmt[vou_dev->pix_idx].bpp * pix->width / 8;
int ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
if (vb->width != pix->width ||
vb->height != pix->height ||
vb->field != pix->field) {
vb->width = pix->width;
vb->height = pix->height;
vb->field = field;
if (vb->state != VIDEOBUF_NEEDS_INIT)
free_buffer(vq, vb);
}
vb->size = vb->height * bytes_per_line;
if (vb->baddr && vb->bsize < vb->size) {
dev_warn(vq->dev, "User buffer too small: [%zu] @ %lx\n",
vb->bsize, vb->baddr);
return -EINVAL;
}
if (vb->state == VIDEOBUF_NEEDS_INIT) {
ret = videobuf_iolock(vq, vb, NULL);
if (ret < 0) {
dev_warn(vq->dev, "IOLOCK buf-type %d: %d\n",
vb->memory, ret);
return ret;
}
vb->state = VIDEOBUF_PREPARED;
}
dev_dbg(vou_dev->v4l2_dev.dev,
"%s(): fmt #%d, %u bytes per line, phys %pad, type %d, state %d\n",
__func__, vou_dev->pix_idx, bytes_per_line,
({ dma_addr_t addr = videobuf_to_dma_contig(vb); &addr; }),
vb->memory, vb->state);
return 0;
}
static void sh_vou_buf_queue(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct video_device *vdev = vq->priv_data;
struct sh_vou_device *vou_dev = video_get_drvdata(vdev);
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
vb->state = VIDEOBUF_QUEUED;
list_add_tail(&vb->queue, &vou_dev->queue);
if (vou_dev->status == SH_VOU_RUNNING) {
return;
} else if (!vou_dev->active) {
vou_dev->active = vb;
sh_vou_reg_a_write(vou_dev, VOURPR, 1);
dev_dbg(vou_dev->v4l2_dev.dev, "%s: first buffer status 0x%x\n",
__func__, sh_vou_reg_a_read(vou_dev, VOUSTR));
sh_vou_schedule_next(vou_dev, vb);
} else if (vou_dev->active->queue.next == &vb->queue) {
sh_vou_reg_a_write(vou_dev, VOURPR, 0);
sh_vou_stream_start(vou_dev, vb);
sh_vou_reg_a_write(vou_dev, VOURCR, 5);
dev_dbg(vou_dev->v4l2_dev.dev, "%s: second buffer status 0x%x\n",
__func__, sh_vou_reg_a_read(vou_dev, VOUSTR));
sh_vou_reg_a_write(vou_dev, VOUIR, 0x10004);
vou_dev->status = SH_VOU_RUNNING;
sh_vou_reg_a_write(vou_dev, VOUER, 0x107);
}
}
static void sh_vou_buf_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct video_device *vdev = vq->priv_data;
struct sh_vou_device *vou_dev = video_get_drvdata(vdev);
unsigned long flags;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
spin_lock_irqsave(&vou_dev->lock, flags);
if (vou_dev->active == vb) {
sh_vou_reg_a_set(vou_dev, VOUER, 0, 1);
sh_vou_reg_a_set(vou_dev, VOUIR, 0, 0x30000);
vou_dev->active = NULL;
}
if ((vb->state == VIDEOBUF_ACTIVE || vb->state == VIDEOBUF_QUEUED)) {
vb->state = VIDEOBUF_ERROR;
list_del(&vb->queue);
}
spin_unlock_irqrestore(&vou_dev->lock, flags);
free_buffer(vq, vb);
}
static int sh_vou_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
strlcpy(cap->card, "SuperH VOU", sizeof(cap->card));
cap->device_caps = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int sh_vou_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
if (fmt->index >= ARRAY_SIZE(vou_fmt))
return -EINVAL;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
fmt->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
strlcpy(fmt->description, vou_fmt[fmt->index].desc,
sizeof(fmt->description));
fmt->pixelformat = vou_fmt[fmt->index].pfmt;
return 0;
}
static int sh_vou_g_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
fmt->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
fmt->fmt.pix = vou_dev->pix;
return 0;
}
static void sh_vou_configure_geometry(struct sh_vou_device *vou_dev,
int pix_idx, int w_idx, int h_idx)
{
struct sh_vou_fmt *fmt = vou_fmt + pix_idx;
unsigned int black_left, black_top, width_max,
frame_in_height, frame_out_height, frame_out_top;
struct v4l2_rect *rect = &vou_dev->rect;
struct v4l2_pix_format *pix = &vou_dev->pix;
u32 vouvcr = 0, dsr_h, dsr_v;
if (vou_dev->std & V4L2_STD_525_60) {
width_max = 858;
} else {
width_max = 864;
}
frame_in_height = pix->height / 2;
frame_out_height = rect->height / 2;
frame_out_top = rect->top / 2;
black_left = width_max - VOU_MAX_IMAGE_WIDTH;
black_top = 20;
dsr_h = rect->width + rect->left;
dsr_v = frame_out_height + frame_out_top;
dev_dbg(vou_dev->v4l2_dev.dev,
"image %ux%u, black %u:%u, offset %u:%u, display %ux%u\n",
pix->width, frame_in_height, black_left, black_top,
rect->left, frame_out_top, dsr_h, dsr_v);
sh_vou_reg_ab_write(vou_dev, VOUISR, (pix->width << 16) | frame_in_height);
sh_vou_reg_ab_write(vou_dev, VOUVPR, (black_left << 16) | black_top);
sh_vou_reg_ab_write(vou_dev, VOUDPR, (rect->left << 16) | frame_out_top);
sh_vou_reg_ab_write(vou_dev, VOUDSR, (dsr_h << 16) | dsr_v);
if (w_idx)
vouvcr |= (1 << 15) | (vou_scale_h_fld[w_idx - 1] << 4);
if (h_idx)
vouvcr |= (1 << 14) | vou_scale_v_fld[h_idx - 1];
dev_dbg(vou_dev->v4l2_dev.dev, "%s: scaling 0x%x\n", fmt->desc, vouvcr);
sh_vou_reg_ab_write(vou_dev, VOUVCR, vouvcr);
sh_vou_reg_ab_write(vou_dev, VOUDFR,
fmt->pkf | (fmt->yf << 8) | (fmt->rgb << 16));
}
static void vou_adjust_input(struct sh_vou_geometry *geo, v4l2_std_id std)
{
unsigned int best_err = UINT_MAX, best = 0, img_height_max;
int i, idx = 0;
if (std & V4L2_STD_525_60)
img_height_max = 480;
else
img_height_max = 576;
v4l_bound_align_image(&geo->in_width, 0, VOU_MAX_IMAGE_WIDTH, 2,
&geo->in_height, 0, img_height_max, 1, 0);
for (i = ARRAY_SIZE(vou_scale_h_num) - 1; i >= 0; i--) {
unsigned int err;
unsigned int found = geo->output.width * vou_scale_h_den[i] /
vou_scale_h_num[i];
if (found > VOU_MAX_IMAGE_WIDTH)
break;
err = abs(found - geo->in_width);
if (err < best_err) {
best_err = err;
idx = i;
best = found;
}
if (!err)
break;
}
geo->in_width = best;
geo->scale_idx_h = idx;
best_err = UINT_MAX;
for (i = ARRAY_SIZE(vou_scale_v_num) - 1; i >= 0; i--) {
unsigned int err;
unsigned int found = geo->output.height * vou_scale_v_den[i] /
vou_scale_v_num[i];
if (found > img_height_max)
break;
err = abs(found - geo->in_height);
if (err < best_err) {
best_err = err;
idx = i;
best = found;
}
if (!err)
break;
}
geo->in_height = best;
geo->scale_idx_v = idx;
}
static void vou_adjust_output(struct sh_vou_geometry *geo, v4l2_std_id std)
{
unsigned int best_err = UINT_MAX, best = geo->in_width,
width_max, height_max, img_height_max;
int i, idx_h = 0, idx_v = 0;
if (std & V4L2_STD_525_60) {
width_max = 858;
height_max = 262 * 2;
img_height_max = 480;
} else {
width_max = 864;
height_max = 312 * 2;
img_height_max = 576;
}
for (i = 0; i < ARRAY_SIZE(vou_scale_h_num); i++) {
unsigned int err;
unsigned int found = geo->in_width * vou_scale_h_num[i] /
vou_scale_h_den[i];
if (found > VOU_MAX_IMAGE_WIDTH)
break;
err = abs(found - geo->output.width);
if (err < best_err) {
best_err = err;
idx_h = i;
best = found;
}
if (!err)
break;
}
geo->output.width = best;
geo->scale_idx_h = idx_h;
if (geo->output.left + best > width_max)
geo->output.left = width_max - best;
pr_debug("%s(): W %u * %u/%u = %u\n", __func__, geo->in_width,
vou_scale_h_num[idx_h], vou_scale_h_den[idx_h], best);
best_err = UINT_MAX;
for (i = 0; i < ARRAY_SIZE(vou_scale_v_num); i++) {
unsigned int err;
unsigned int found = geo->in_height * vou_scale_v_num[i] /
vou_scale_v_den[i];
if (found > img_height_max)
break;
err = abs(found - geo->output.height);
if (err < best_err) {
best_err = err;
idx_v = i;
best = found;
}
if (!err)
break;
}
geo->output.height = best;
geo->scale_idx_v = idx_v;
if (geo->output.top + best > height_max)
geo->output.top = height_max - best;
pr_debug("%s(): H %u * %u/%u = %u\n", __func__, geo->in_height,
vou_scale_v_num[idx_v], vou_scale_v_den[idx_v], best);
}
static int sh_vou_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct v4l2_pix_format *pix = &fmt->fmt.pix;
unsigned int img_height_max;
int pix_idx;
struct sh_vou_geometry geo;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
.format.code = MEDIA_BUS_FMT_YUYV8_2X8,
.format.field = V4L2_FIELD_INTERLACED,
.format.colorspace = V4L2_COLORSPACE_SMPTE170M,
};
struct v4l2_mbus_framefmt *mbfmt = &format.format;
int ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s(): %ux%u -> %ux%u\n", __func__,
vou_dev->rect.width, vou_dev->rect.height,
pix->width, pix->height);
if (pix->field == V4L2_FIELD_ANY)
pix->field = V4L2_FIELD_NONE;
if (fmt->type != V4L2_BUF_TYPE_VIDEO_OUTPUT ||
pix->field != V4L2_FIELD_NONE)
return -EINVAL;
for (pix_idx = 0; pix_idx < ARRAY_SIZE(vou_fmt); pix_idx++)
if (vou_fmt[pix_idx].pfmt == pix->pixelformat)
break;
if (pix_idx == ARRAY_SIZE(vou_fmt))
return -EINVAL;
if (vou_dev->std & V4L2_STD_525_60)
img_height_max = 480;
else
img_height_max = 576;
v4l_bound_align_image(&pix->width, 0, VOU_MAX_IMAGE_WIDTH, 2,
&pix->height, 0, img_height_max, 1, 0);
geo.in_width = pix->width;
geo.in_height = pix->height;
geo.output = vou_dev->rect;
vou_adjust_output(&geo, vou_dev->std);
mbfmt->width = geo.output.width;
mbfmt->height = geo.output.height;
ret = v4l2_device_call_until_err(&vou_dev->v4l2_dev, 0, pad,
set_fmt, NULL, &format);
if (ret < 0)
return ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s(): %ux%u -> %ux%u\n", __func__,
geo.output.width, geo.output.height, mbfmt->width, mbfmt->height);
if ((unsigned)mbfmt->width > VOU_MAX_IMAGE_WIDTH ||
(unsigned)mbfmt->height > img_height_max ||
mbfmt->code != MEDIA_BUS_FMT_YUYV8_2X8)
return -EIO;
if (mbfmt->width != geo.output.width ||
mbfmt->height != geo.output.height) {
geo.output.width = mbfmt->width;
geo.output.height = mbfmt->height;
vou_adjust_input(&geo, vou_dev->std);
}
vou_dev->rect = geo.output;
pix->width = geo.in_width;
pix->height = geo.in_height;
dev_dbg(vou_dev->v4l2_dev.dev, "%s(): %ux%u\n", __func__,
pix->width, pix->height);
vou_dev->pix_idx = pix_idx;
vou_dev->pix = *pix;
sh_vou_configure_geometry(vou_dev, pix_idx,
geo.scale_idx_h, geo.scale_idx_v);
return 0;
}
static int sh_vou_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct v4l2_pix_format *pix = &fmt->fmt.pix;
int i;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
fmt->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
pix->field = V4L2_FIELD_NONE;
v4l_bound_align_image(&pix->width, 0, VOU_MAX_IMAGE_WIDTH, 1,
&pix->height, 0, VOU_MAX_IMAGE_HEIGHT, 1, 0);
for (i = 0; i < ARRAY_SIZE(vou_fmt); i++)
if (vou_fmt[i].pfmt == pix->pixelformat)
return 0;
pix->pixelformat = vou_fmt[0].pfmt;
return 0;
}
static int sh_vou_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *req)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = priv;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
if (req->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
return videobuf_reqbufs(&vou_file->vbq, req);
}
static int sh_vou_querybuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = priv;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
return videobuf_querybuf(&vou_file->vbq, b);
}
static int sh_vou_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = priv;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
return videobuf_qbuf(&vou_file->vbq, b);
}
static int sh_vou_dqbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = priv;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
return videobuf_dqbuf(&vou_file->vbq, b, file->f_flags & O_NONBLOCK);
}
static int sh_vou_streamon(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = priv;
int ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
ret = v4l2_device_call_until_err(&vou_dev->v4l2_dev, 0,
video, s_stream, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
return videobuf_streamon(&vou_file->vbq);
}
static int sh_vou_streamoff(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = priv;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
videobuf_streamoff(&vou_file->vbq);
v4l2_device_call_until_err(&vou_dev->v4l2_dev, 0, video, s_stream, 0);
return 0;
}
static u32 sh_vou_ntsc_mode(enum sh_vou_bus_fmt bus_fmt)
{
switch (bus_fmt) {
default:
pr_warning("%s(): Invalid bus-format code %d, using default 8-bit\n",
__func__, bus_fmt);
case SH_VOU_BUS_8BIT:
return 1;
case SH_VOU_BUS_16BIT:
return 0;
case SH_VOU_BUS_BT656:
return 3;
}
}
static int sh_vou_s_std(struct file *file, void *priv, v4l2_std_id std_id)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
int ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s(): 0x%llx\n", __func__, std_id);
if (std_id & ~vou_dev->vdev.tvnorms)
return -EINVAL;
ret = v4l2_device_call_until_err(&vou_dev->v4l2_dev, 0, video,
s_std_output, std_id);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
if (std_id & V4L2_STD_525_60)
sh_vou_reg_ab_set(vou_dev, VOUCR,
sh_vou_ntsc_mode(vou_dev->pdata->bus_fmt) << 29, 7 << 29);
else
sh_vou_reg_ab_set(vou_dev, VOUCR, 5 << 29, 7 << 29);
vou_dev->std = std_id;
return 0;
}
static int sh_vou_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
*std = vou_dev->std;
return 0;
}
static int sh_vou_g_crop(struct file *file, void *fh, struct v4l2_crop *a)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
a->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
a->c = vou_dev->rect;
return 0;
}
static int sh_vou_s_crop(struct file *file, void *fh, const struct v4l2_crop *a)
{
struct v4l2_crop a_writable = *a;
struct sh_vou_device *vou_dev = video_drvdata(file);
struct v4l2_rect *rect = &a_writable.c;
struct v4l2_crop sd_crop = {.type = V4L2_BUF_TYPE_VIDEO_OUTPUT};
struct v4l2_pix_format *pix = &vou_dev->pix;
struct sh_vou_geometry geo;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
.format.code = MEDIA_BUS_FMT_YUYV8_2X8,
.format.field = V4L2_FIELD_INTERLACED,
.format.colorspace = V4L2_COLORSPACE_SMPTE170M,
};
unsigned int img_height_max;
int ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s(): %ux%u@%u:%u\n", __func__,
rect->width, rect->height, rect->left, rect->top);
if (a->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
if (vou_dev->std & V4L2_STD_525_60)
img_height_max = 480;
else
img_height_max = 576;
v4l_bound_align_image(&rect->width, 0, VOU_MAX_IMAGE_WIDTH, 1,
&rect->height, 0, img_height_max, 1, 0);
if (rect->width + rect->left > VOU_MAX_IMAGE_WIDTH)
rect->left = VOU_MAX_IMAGE_WIDTH - rect->width;
if (rect->height + rect->top > img_height_max)
rect->top = img_height_max - rect->height;
geo.output = *rect;
geo.in_width = pix->width;
geo.in_height = pix->height;
sd_crop.c.width = geo.output.width;
sd_crop.c.height = geo.output.height;
v4l2_device_call_until_err(&vou_dev->v4l2_dev, 0, video,
s_crop, &sd_crop);
format.format.width = geo.output.width;
format.format.height = geo.output.height;
ret = v4l2_device_call_until_err(&vou_dev->v4l2_dev, 0, pad,
set_fmt, NULL, &format);
if (ret < 0)
return ret;
if ((unsigned)format.format.width > VOU_MAX_IMAGE_WIDTH ||
(unsigned)format.format.height > img_height_max ||
format.format.code != MEDIA_BUS_FMT_YUYV8_2X8)
return -EIO;
geo.output.width = format.format.width;
geo.output.height = format.format.height;
vou_adjust_input(&geo, vou_dev->std);
vou_dev->rect = geo.output;
pix->width = geo.in_width;
pix->height = geo.in_height;
sh_vou_configure_geometry(vou_dev, vou_dev->pix_idx,
geo.scale_idx_h, geo.scale_idx_v);
return 0;
}
static int sh_vou_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *a)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
a->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
a->bounds.left = 0;
a->bounds.top = 0;
a->bounds.width = VOU_MAX_IMAGE_WIDTH;
a->bounds.height = VOU_MAX_IMAGE_HEIGHT;
a->defrect.left = 0;
a->defrect.top = 0;
a->defrect.width = VOU_MAX_IMAGE_WIDTH;
a->defrect.height = VOU_MAX_IMAGE_HEIGHT;
a->pixelaspect.numerator = 1;
a->pixelaspect.denominator = 1;
return 0;
}
static irqreturn_t sh_vou_isr(int irq, void *dev_id)
{
struct sh_vou_device *vou_dev = dev_id;
static unsigned long j;
struct videobuf_buffer *vb;
static int cnt;
u32 irq_status = sh_vou_reg_a_read(vou_dev, VOUIR), masked;
u32 vou_status = sh_vou_reg_a_read(vou_dev, VOUSTR);
if (!(irq_status & 0x300)) {
if (printk_timed_ratelimit(&j, 500))
dev_warn(vou_dev->v4l2_dev.dev, "IRQ status 0x%x!\n",
irq_status);
return IRQ_NONE;
}
spin_lock(&vou_dev->lock);
if (!vou_dev->active || list_empty(&vou_dev->queue)) {
if (printk_timed_ratelimit(&j, 500))
dev_warn(vou_dev->v4l2_dev.dev,
"IRQ without active buffer: %x!\n", irq_status);
sh_vou_reg_a_set(vou_dev, VOUIR, 0, 0x300);
spin_unlock(&vou_dev->lock);
return IRQ_HANDLED;
}
masked = ~(0x300 & irq_status) & irq_status & 0x30304;
dev_dbg(vou_dev->v4l2_dev.dev,
"IRQ status 0x%x -> 0x%x, VOU status 0x%x, cnt %d\n",
irq_status, masked, vou_status, cnt);
cnt++;
sh_vou_reg_a_write(vou_dev, VOUIR, masked);
vb = vou_dev->active;
list_del(&vb->queue);
vb->state = VIDEOBUF_DONE;
v4l2_get_timestamp(&vb->ts);
vb->field_count++;
wake_up(&vb->done);
if (list_empty(&vou_dev->queue)) {
dev_dbg(vou_dev->v4l2_dev.dev, "%s: queue empty after %d\n",
__func__, cnt);
sh_vou_reg_a_set(vou_dev, VOUER, 0, 1);
vou_dev->active = NULL;
vou_dev->status = SH_VOU_INITIALISING;
sh_vou_reg_a_set(vou_dev, VOUIR, 0, 0x30000);
spin_unlock(&vou_dev->lock);
return IRQ_HANDLED;
}
vou_dev->active = list_entry(vou_dev->queue.next,
struct videobuf_buffer, queue);
if (vou_dev->active->queue.next != &vou_dev->queue) {
struct videobuf_buffer *new = list_entry(vou_dev->active->queue.next,
struct videobuf_buffer, queue);
sh_vou_schedule_next(vou_dev, new);
}
spin_unlock(&vou_dev->lock);
return IRQ_HANDLED;
}
static int sh_vou_hw_init(struct sh_vou_device *vou_dev)
{
struct sh_vou_pdata *pdata = vou_dev->pdata;
u32 voucr = sh_vou_ntsc_mode(pdata->bus_fmt) << 29;
int i = 100;
sh_vou_reg_a_write(vou_dev, VOUIR, 0);
sh_vou_reg_a_write(vou_dev, VOUSRR, 0x101);
while (--i && (sh_vou_reg_a_read(vou_dev, VOUSRR) & 0x101))
udelay(1);
if (!i)
return -ETIMEDOUT;
dev_dbg(vou_dev->v4l2_dev.dev, "Reset took %dus\n", 100 - i);
if (pdata->flags & SH_VOU_PCLK_FALLING)
voucr |= 1 << 28;
if (pdata->flags & SH_VOU_HSYNC_LOW)
voucr |= 1 << 27;
if (pdata->flags & SH_VOU_VSYNC_LOW)
voucr |= 1 << 26;
sh_vou_reg_ab_set(vou_dev, VOUCR, voucr, 0xfc000000);
sh_vou_reg_a_write(vou_dev, VOURCR, 4);
sh_vou_reg_ab_write(vou_dev, VOUMSR, 0x800000);
return 0;
}
static int sh_vou_open(struct file *file)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = kzalloc(sizeof(struct sh_vou_file),
GFP_KERNEL);
if (!vou_file)
return -ENOMEM;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
if (mutex_lock_interruptible(&vou_dev->fop_lock)) {
kfree(vou_file);
return -ERESTARTSYS;
}
if (atomic_inc_return(&vou_dev->use_count) == 1) {
int ret;
vou_dev->status = SH_VOU_INITIALISING;
pm_runtime_get_sync(vou_dev->v4l2_dev.dev);
ret = sh_vou_hw_init(vou_dev);
if (ret < 0) {
atomic_dec(&vou_dev->use_count);
pm_runtime_put(vou_dev->v4l2_dev.dev);
vou_dev->status = SH_VOU_IDLE;
mutex_unlock(&vou_dev->fop_lock);
kfree(vou_file);
return ret;
}
}
videobuf_queue_dma_contig_init(&vou_file->vbq, &sh_vou_video_qops,
vou_dev->v4l2_dev.dev, &vou_dev->lock,
V4L2_BUF_TYPE_VIDEO_OUTPUT,
V4L2_FIELD_NONE,
sizeof(struct videobuf_buffer),
&vou_dev->vdev, &vou_dev->fop_lock);
mutex_unlock(&vou_dev->fop_lock);
file->private_data = vou_file;
return 0;
}
static int sh_vou_release(struct file *file)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = file->private_data;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
if (!atomic_dec_return(&vou_dev->use_count)) {
mutex_lock(&vou_dev->fop_lock);
vou_dev->status = SH_VOU_IDLE;
sh_vou_reg_a_set(vou_dev, VOUER, 0, 0x101);
pm_runtime_put(vou_dev->v4l2_dev.dev);
mutex_unlock(&vou_dev->fop_lock);
}
file->private_data = NULL;
kfree(vou_file);
return 0;
}
static int sh_vou_mmap(struct file *file, struct vm_area_struct *vma)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = file->private_data;
int ret;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
if (mutex_lock_interruptible(&vou_dev->fop_lock))
return -ERESTARTSYS;
ret = videobuf_mmap_mapper(&vou_file->vbq, vma);
mutex_unlock(&vou_dev->fop_lock);
return ret;
}
static unsigned int sh_vou_poll(struct file *file, poll_table *wait)
{
struct sh_vou_device *vou_dev = video_drvdata(file);
struct sh_vou_file *vou_file = file->private_data;
unsigned int res;
dev_dbg(vou_dev->v4l2_dev.dev, "%s()\n", __func__);
mutex_lock(&vou_dev->fop_lock);
res = videobuf_poll_stream(file, &vou_file->vbq, wait);
mutex_unlock(&vou_dev->fop_lock);
return res;
}
static int sh_vou_probe(struct platform_device *pdev)
{
struct sh_vou_pdata *vou_pdata = pdev->dev.platform_data;
struct v4l2_rect *rect;
struct v4l2_pix_format *pix;
struct i2c_adapter *i2c_adap;
struct video_device *vdev;
struct sh_vou_device *vou_dev;
struct resource *reg_res, *region;
struct v4l2_subdev *subdev;
int irq, ret;
reg_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!vou_pdata || !reg_res || irq <= 0) {
dev_err(&pdev->dev, "Insufficient VOU platform information.\n");
return -ENODEV;
}
vou_dev = kzalloc(sizeof(*vou_dev), GFP_KERNEL);
if (!vou_dev)
return -ENOMEM;
INIT_LIST_HEAD(&vou_dev->queue);
spin_lock_init(&vou_dev->lock);
mutex_init(&vou_dev->fop_lock);
atomic_set(&vou_dev->use_count, 0);
vou_dev->pdata = vou_pdata;
vou_dev->status = SH_VOU_IDLE;
rect = &vou_dev->rect;
pix = &vou_dev->pix;
vou_dev->std = V4L2_STD_NTSC_M;
rect->left = 0;
rect->top = 0;
rect->width = VOU_MAX_IMAGE_WIDTH;
rect->height = 480;
pix->width = VOU_MAX_IMAGE_WIDTH;
pix->height = 480;
pix->pixelformat = V4L2_PIX_FMT_YVYU;
pix->field = V4L2_FIELD_NONE;
pix->bytesperline = VOU_MAX_IMAGE_WIDTH * 2;
pix->sizeimage = VOU_MAX_IMAGE_WIDTH * 2 * 480;
pix->colorspace = V4L2_COLORSPACE_SMPTE170M;
region = request_mem_region(reg_res->start, resource_size(reg_res),
pdev->name);
if (!region) {
dev_err(&pdev->dev, "VOU region already claimed\n");
ret = -EBUSY;
goto ereqmemreg;
}
vou_dev->base = ioremap(reg_res->start, resource_size(reg_res));
if (!vou_dev->base) {
ret = -ENOMEM;
goto emap;
}
ret = request_irq(irq, sh_vou_isr, 0, "vou", vou_dev);
if (ret < 0)
goto ereqirq;
ret = v4l2_device_register(&pdev->dev, &vou_dev->v4l2_dev);
if (ret < 0) {
dev_err(&pdev->dev, "Error registering v4l2 device\n");
goto ev4l2devreg;
}
vdev = &vou_dev->vdev;
*vdev = sh_vou_video_template;
if (vou_pdata->bus_fmt == SH_VOU_BUS_8BIT)
vdev->tvnorms |= V4L2_STD_PAL;
vdev->v4l2_dev = &vou_dev->v4l2_dev;
vdev->release = video_device_release_empty;
vdev->lock = &vou_dev->fop_lock;
video_set_drvdata(vdev, vou_dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_resume(&pdev->dev);
i2c_adap = i2c_get_adapter(vou_pdata->i2c_adap);
if (!i2c_adap) {
ret = -ENODEV;
goto ei2cgadap;
}
ret = sh_vou_hw_init(vou_dev);
if (ret < 0)
goto ereset;
subdev = v4l2_i2c_new_subdev_board(&vou_dev->v4l2_dev, i2c_adap,
vou_pdata->board_info, NULL);
if (!subdev) {
ret = -ENOMEM;
goto ei2cnd;
}
ret = video_register_device(vdev, VFL_TYPE_GRABBER, -1);
if (ret < 0)
goto evregdev;
return 0;
evregdev:
ei2cnd:
ereset:
i2c_put_adapter(i2c_adap);
ei2cgadap:
pm_runtime_disable(&pdev->dev);
v4l2_device_unregister(&vou_dev->v4l2_dev);
ev4l2devreg:
free_irq(irq, vou_dev);
ereqirq:
iounmap(vou_dev->base);
emap:
release_mem_region(reg_res->start, resource_size(reg_res));
ereqmemreg:
kfree(vou_dev);
return ret;
}
static int sh_vou_remove(struct platform_device *pdev)
{
int irq = platform_get_irq(pdev, 0);
struct v4l2_device *v4l2_dev = platform_get_drvdata(pdev);
struct sh_vou_device *vou_dev = container_of(v4l2_dev,
struct sh_vou_device, v4l2_dev);
struct v4l2_subdev *sd = list_entry(v4l2_dev->subdevs.next,
struct v4l2_subdev, list);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct resource *reg_res;
if (irq > 0)
free_irq(irq, vou_dev);
pm_runtime_disable(&pdev->dev);
video_unregister_device(&vou_dev->vdev);
i2c_put_adapter(client->adapter);
v4l2_device_unregister(&vou_dev->v4l2_dev);
iounmap(vou_dev->base);
reg_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (reg_res)
release_mem_region(reg_res->start, resource_size(reg_res));
kfree(vou_dev);
return 0;
}
