static int venc_is_second_field(struct vpbe_display *disp_dev)
{
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
int ret;
int val;
ret = v4l2_subdev_call(vpbe_dev->venc,
core,
ioctl,
VENC_GET_FLD,
&val);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Error in getting Field ID 0\n");
}
return val;
}
static void vpbe_isr_even_field(struct vpbe_display *disp_obj,
struct vpbe_layer *layer)
{
if (layer->cur_frm == layer->next_frm)
return;
layer->cur_frm->vb.vb2_buf.timestamp = ktime_get_ns();
vb2_buffer_done(&layer->cur_frm->vb.vb2_buf, VB2_BUF_STATE_DONE);
layer->cur_frm = layer->next_frm;
}
static void vpbe_isr_odd_field(struct vpbe_display *disp_obj,
struct vpbe_layer *layer)
{
struct osd_state *osd_device = disp_obj->osd_device;
unsigned long addr;
spin_lock(&disp_obj->dma_queue_lock);
if (list_empty(&layer->dma_queue) ||
(layer->cur_frm != layer->next_frm)) {
spin_unlock(&disp_obj->dma_queue_lock);
return;
}
layer->next_frm = list_entry(layer->dma_queue.next,
struct vpbe_disp_buffer, list);
list_del(&layer->next_frm->list);
spin_unlock(&disp_obj->dma_queue_lock);
layer->next_frm->vb.vb2_buf.state = VB2_BUF_STATE_ACTIVE;
addr = vb2_dma_contig_plane_dma_addr(&layer->next_frm->vb.vb2_buf, 0);
osd_device->ops.start_layer(osd_device,
layer->layer_info.id,
addr,
disp_obj->cbcr_ofst);
}
static irqreturn_t venc_isr(int irq, void *arg)
{
struct vpbe_display *disp_dev = (struct vpbe_display *)arg;
struct vpbe_layer *layer;
static unsigned last_event;
unsigned event = 0;
int fid;
int i;
if ((NULL == arg) || (NULL == disp_dev->dev[0]))
return IRQ_HANDLED;
if (venc_is_second_field(disp_dev))
event |= VENC_SECOND_FIELD;
else
event |= VENC_FIRST_FIELD;
if (event == (last_event & ~VENC_END_OF_FRAME)) {
event |= VENC_END_OF_FRAME;
} else if (event == VENC_SECOND_FIELD) {
event |= VENC_END_OF_FRAME;
}
last_event = event;
for (i = 0; i < VPBE_DISPLAY_MAX_DEVICES; i++) {
layer = disp_dev->dev[i];
if (!vb2_start_streaming_called(&layer->buffer_queue))
continue;
if (layer->layer_first_int) {
layer->layer_first_int = 0;
continue;
}
if ((V4L2_FIELD_NONE == layer->pix_fmt.field) &&
(event & VENC_END_OF_FRAME)) {
vpbe_isr_even_field(disp_dev, layer);
vpbe_isr_odd_field(disp_dev, layer);
} else {
layer->field_id ^= 1;
if (event & VENC_FIRST_FIELD)
fid = 0;
else
fid = 1;
if (fid != layer->field_id) {
layer->field_id = fid;
continue;
}
if (0 == fid)
vpbe_isr_even_field(disp_dev, layer);
else
vpbe_isr_odd_field(disp_dev, layer);
}
}
return IRQ_HANDLED;
}
static int vpbe_buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_queue *q = vb->vb2_queue;
struct vpbe_layer *layer = vb2_get_drv_priv(q);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
unsigned long addr;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"vpbe_buffer_prepare\n");
vb2_set_plane_payload(vb, 0, layer->pix_fmt.sizeimage);
if (vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0))
return -EINVAL;
addr = vb2_dma_contig_plane_dma_addr(vb, 0);
if (!IS_ALIGNED(addr, 8)) {
v4l2_err(&vpbe_dev->v4l2_dev,
"buffer_prepare:offset is not aligned to 32 bytes\n");
return -EINVAL;
}
return 0;
}
static int
vpbe_buffer_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct vpbe_layer *layer = vb2_get_drv_priv(vq);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "vpbe_buffer_setup\n");
if (vq->num_buffers + *nbuffers < VPBE_DEFAULT_NUM_BUFS)
*nbuffers = VPBE_DEFAULT_NUM_BUFS - vq->num_buffers;
if (*nplanes)
return sizes[0] < layer->pix_fmt.sizeimage ? -EINVAL : 0;
*nplanes = 1;
sizes[0] = layer->pix_fmt.sizeimage;
return 0;
}
static void vpbe_buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vpbe_disp_buffer *buf = container_of(vbuf,
struct vpbe_disp_buffer, vb);
struct vpbe_layer *layer = vb2_get_drv_priv(vb->vb2_queue);
struct vpbe_display *disp = layer->disp_dev;
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
unsigned long flags;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"vpbe_buffer_queue\n");
spin_lock_irqsave(&disp->dma_queue_lock, flags);
list_add_tail(&buf->list, &layer->dma_queue);
spin_unlock_irqrestore(&disp->dma_queue_lock, flags);
}
static int vpbe_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vpbe_layer *layer = vb2_get_drv_priv(vq);
struct osd_state *osd_device = layer->disp_dev->osd_device;
int ret;
osd_device->ops.disable_layer(osd_device, layer->layer_info.id);
layer->next_frm = layer->cur_frm = list_entry(layer->dma_queue.next,
struct vpbe_disp_buffer, list);
list_del(&layer->cur_frm->list);
layer->cur_frm->vb.vb2_buf.state = VB2_BUF_STATE_ACTIVE;
layer->field_id = 0;
ret = vpbe_set_osd_display_params(layer->disp_dev, layer);
if (ret < 0) {
struct vpbe_disp_buffer *buf, *tmp;
vb2_buffer_done(&layer->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_QUEUED);
list_for_each_entry_safe(buf, tmp, &layer->dma_queue, list) {
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf,
VB2_BUF_STATE_QUEUED);
}
return ret;
}
layer->layer_first_int = 1;
return ret;
}
static void vpbe_stop_streaming(struct vb2_queue *vq)
{
struct vpbe_layer *layer = vb2_get_drv_priv(vq);
struct osd_state *osd_device = layer->disp_dev->osd_device;
struct vpbe_display *disp = layer->disp_dev;
unsigned long flags;
if (!vb2_is_streaming(vq))
return;
osd_device->ops.disable_layer(osd_device, layer->layer_info.id);
spin_lock_irqsave(&disp->dma_queue_lock, flags);
if (layer->cur_frm == layer->next_frm) {
vb2_buffer_done(&layer->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
} else {
if (layer->cur_frm != NULL)
vb2_buffer_done(&layer->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
if (layer->next_frm != NULL)
vb2_buffer_done(&layer->next_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
}
while (!list_empty(&layer->dma_queue)) {
layer->next_frm = list_entry(layer->dma_queue.next,
struct vpbe_disp_buffer, list);
list_del(&layer->next_frm->list);
vb2_buffer_done(&layer->next_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&disp->dma_queue_lock, flags);
}
static
struct vpbe_layer*
_vpbe_display_get_other_win_layer(struct vpbe_display *disp_dev,
struct vpbe_layer *layer)
{
enum vpbe_display_device_id thiswin, otherwin;
thiswin = layer->device_id;
otherwin = (thiswin == VPBE_DISPLAY_DEVICE_0) ?
VPBE_DISPLAY_DEVICE_1 : VPBE_DISPLAY_DEVICE_0;
return disp_dev->dev[otherwin];
}
static int vpbe_set_osd_display_params(struct vpbe_display *disp_dev,
struct vpbe_layer *layer)
{
struct osd_layer_config *cfg = &layer->layer_info.config;
struct osd_state *osd_device = disp_dev->osd_device;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
unsigned long addr;
int ret;
addr = vb2_dma_contig_plane_dma_addr(&layer->cur_frm->vb.vb2_buf, 0);
osd_device->ops.start_layer(osd_device,
layer->layer_info.id,
addr,
disp_dev->cbcr_ofst);
ret = osd_device->ops.enable_layer(osd_device,
layer->layer_info.id, 0);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Error in enabling osd window layer 0\n");
return -1;
}
layer->layer_info.enable = 1;
if (cfg->pixfmt == PIXFMT_NV12) {
struct vpbe_layer *otherlayer =
_vpbe_display_get_other_win_layer(disp_dev, layer);
ret = osd_device->ops.enable_layer(osd_device,
otherlayer->layer_info.id, 1);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Error in enabling osd window layer 1\n");
return -1;
}
otherlayer->layer_info.enable = 1;
}
return 0;
}
static void
vpbe_disp_calculate_scale_factor(struct vpbe_display *disp_dev,
struct vpbe_layer *layer,
int expected_xsize, int expected_ysize)
{
struct display_layer_info *layer_info = &layer->layer_info;
struct v4l2_pix_format *pixfmt = &layer->pix_fmt;
struct osd_layer_config *cfg = &layer->layer_info.config;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
int calculated_xsize;
int h_exp = 0;
int v_exp = 0;
int h_scale;
int v_scale;
v4l2_std_id standard_id = vpbe_dev->current_timings.std_id;
cfg->xsize = pixfmt->width;
cfg->ysize = pixfmt->height;
layer_info->h_zoom = ZOOM_X1;
layer_info->v_zoom = ZOOM_X1;
layer_info->h_exp = H_EXP_OFF;
layer_info->v_exp = V_EXP_OFF;
if (pixfmt->width < expected_xsize) {
h_scale = vpbe_dev->current_timings.xres / pixfmt->width;
if (h_scale < 2)
h_scale = 1;
else if (h_scale >= 4)
h_scale = 4;
else
h_scale = 2;
cfg->xsize *= h_scale;
if (cfg->xsize < expected_xsize) {
if ((standard_id & V4L2_STD_525_60) ||
(standard_id & V4L2_STD_625_50)) {
calculated_xsize = (cfg->xsize *
VPBE_DISPLAY_H_EXP_RATIO_N) /
VPBE_DISPLAY_H_EXP_RATIO_D;
if (calculated_xsize <= expected_xsize) {
h_exp = 1;
cfg->xsize = calculated_xsize;
}
}
}
if (h_scale == 2)
layer_info->h_zoom = ZOOM_X2;
else if (h_scale == 4)
layer_info->h_zoom = ZOOM_X4;
if (h_exp)
layer_info->h_exp = H_EXP_9_OVER_8;
} else {
cfg->xsize = expected_xsize;
}
if (pixfmt->height < expected_ysize) {
v_scale = expected_ysize / pixfmt->height;
if (v_scale < 2)
v_scale = 1;
else if (v_scale >= 4)
v_scale = 4;
else
v_scale = 2;
cfg->ysize *= v_scale;
if (cfg->ysize < expected_ysize) {
if ((standard_id & V4L2_STD_625_50)) {
calculated_xsize = (cfg->ysize *
VPBE_DISPLAY_V_EXP_RATIO_N) /
VPBE_DISPLAY_V_EXP_RATIO_D;
if (calculated_xsize <= expected_ysize) {
v_exp = 1;
cfg->ysize = calculated_xsize;
}
}
}
if (v_scale == 2)
layer_info->v_zoom = ZOOM_X2;
else if (v_scale == 4)
layer_info->v_zoom = ZOOM_X4;
if (v_exp)
layer_info->h_exp = V_EXP_6_OVER_5;
} else {
cfg->ysize = expected_ysize;
}
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"crop display xsize = %d, ysize = %d\n",
cfg->xsize, cfg->ysize);
}
static void vpbe_disp_adj_position(struct vpbe_display *disp_dev,
struct vpbe_layer *layer,
int top, int left)
{
struct osd_layer_config *cfg = &layer->layer_info.config;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
cfg->xpos = min((unsigned int)left,
vpbe_dev->current_timings.xres - cfg->xsize);
cfg->ypos = min((unsigned int)top,
vpbe_dev->current_timings.yres - cfg->ysize);
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"new xpos = %d, ypos = %d\n",
cfg->xpos, cfg->ypos);
}
static void vpbe_disp_check_window_params(struct vpbe_display *disp_dev,
struct v4l2_rect *c)
{
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
if ((c->width == 0) ||
((c->width + c->left) > vpbe_dev->current_timings.xres))
c->width = vpbe_dev->current_timings.xres - c->left;
if ((c->height == 0) || ((c->height + c->top) >
vpbe_dev->current_timings.yres))
c->height = vpbe_dev->current_timings.yres - c->top;
if (vpbe_dev->current_timings.interlaced)
c->height &= (~0x01);
}
static int vpbe_try_format(struct vpbe_display *disp_dev,
struct v4l2_pix_format *pixfmt, int check)
{
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
int min_height = 1;
int min_width = 32;
int max_height;
int max_width;
int bpp;
if ((pixfmt->pixelformat != V4L2_PIX_FMT_UYVY) &&
(pixfmt->pixelformat != V4L2_PIX_FMT_NV12))
pixfmt->pixelformat = V4L2_PIX_FMT_UYVY;
if ((pixfmt->field != V4L2_FIELD_INTERLACED) &&
(pixfmt->field != V4L2_FIELD_NONE)) {
if (vpbe_dev->current_timings.interlaced)
pixfmt->field = V4L2_FIELD_INTERLACED;
else
pixfmt->field = V4L2_FIELD_NONE;
}
if (pixfmt->field == V4L2_FIELD_INTERLACED)
min_height = 2;
if (pixfmt->pixelformat == V4L2_PIX_FMT_NV12)
bpp = 1;
else
bpp = 2;
max_width = vpbe_dev->current_timings.xres;
max_height = vpbe_dev->current_timings.yres;
min_width /= bpp;
if (!pixfmt->width || (pixfmt->width < min_width) ||
(pixfmt->width > max_width)) {
pixfmt->width = vpbe_dev->current_timings.xres;
}
if (!pixfmt->height || (pixfmt->height < min_height) ||
(pixfmt->height > max_height)) {
pixfmt->height = vpbe_dev->current_timings.yres;
}
if (pixfmt->bytesperline < (pixfmt->width * bpp))
pixfmt->bytesperline = pixfmt->width * bpp;
pixfmt->bytesperline = ((pixfmt->width * bpp + 31) & ~31);
if (pixfmt->pixelformat == V4L2_PIX_FMT_NV12)
pixfmt->sizeimage = pixfmt->bytesperline * pixfmt->height +
(pixfmt->bytesperline * pixfmt->height >> 1);
else
pixfmt->sizeimage = pixfmt->bytesperline * pixfmt->height;
return 0;
}
static int vpbe_display_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
cap->device_caps = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
snprintf(cap->driver, sizeof(cap->driver), "%s",
dev_name(vpbe_dev->pdev));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(vpbe_dev->pdev));
strlcpy(cap->card, vpbe_dev->cfg->module_name, sizeof(cap->card));
return 0;
}
static int vpbe_display_s_selection(struct file *file, void *priv,
struct v4l2_selection *sel)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_display *disp_dev = layer->disp_dev;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
struct osd_layer_config *cfg = &layer->layer_info.config;
struct osd_state *osd_device = disp_dev->osd_device;
struct v4l2_rect rect = sel->r;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"VIDIOC_S_SELECTION, layer id = %d\n", layer->device_id);
if (sel->type != V4L2_BUF_TYPE_VIDEO_OUTPUT ||
sel->target != V4L2_SEL_TGT_CROP)
return -EINVAL;
if (rect.top < 0)
rect.top = 0;
if (rect.left < 0)
rect.left = 0;
vpbe_disp_check_window_params(disp_dev, &rect);
osd_device->ops.get_layer_config(osd_device,
layer->layer_info.id, cfg);
vpbe_disp_calculate_scale_factor(disp_dev, layer,
rect.width,
rect.height);
vpbe_disp_adj_position(disp_dev, layer, rect.top,
rect.left);
ret = osd_device->ops.set_layer_config(osd_device,
layer->layer_info.id, cfg);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Error in set layer config:\n");
return -EINVAL;
}
osd_device->ops.set_zoom(osd_device,
layer->layer_info.id,
layer->layer_info.h_zoom,
layer->layer_info.v_zoom);
ret = osd_device->ops.set_vid_expansion(osd_device,
layer->layer_info.h_exp,
layer->layer_info.v_exp);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Error in set vid expansion:\n");
return -EINVAL;
}
if ((layer->layer_info.h_zoom != ZOOM_X1) ||
(layer->layer_info.v_zoom != ZOOM_X1) ||
(layer->layer_info.h_exp != H_EXP_OFF) ||
(layer->layer_info.v_exp != V_EXP_OFF))
osd_device->ops.set_interpolation_filter(osd_device, 1);
else
osd_device->ops.set_interpolation_filter(osd_device, 0);
sel->r = rect;
return 0;
}
static int vpbe_display_g_selection(struct file *file, void *priv,
struct v4l2_selection *sel)
{
struct vpbe_layer *layer = video_drvdata(file);
struct osd_layer_config *cfg = &layer->layer_info.config;
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
struct osd_state *osd_device = layer->disp_dev->osd_device;
struct v4l2_rect *rect = &sel->r;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"VIDIOC_G_SELECTION, layer id = %d\n",
layer->device_id);
if (sel->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
switch (sel->target) {
case V4L2_SEL_TGT_CROP:
osd_device->ops.get_layer_config(osd_device,
layer->layer_info.id, cfg);
rect->top = cfg->ypos;
rect->left = cfg->xpos;
rect->width = cfg->xsize;
rect->height = cfg->ysize;
break;
case V4L2_SEL_TGT_CROP_DEFAULT:
case V4L2_SEL_TGT_CROP_BOUNDS:
rect->left = 0;
rect->top = 0;
rect->width = vpbe_dev->current_timings.xres;
rect->height = vpbe_dev->current_timings.yres;
break;
default:
return -EINVAL;
}
return 0;
}
static int vpbe_display_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *cropcap)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_CROPCAP ioctl\n");
if (cropcap->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
cropcap->pixelaspect = vpbe_dev->current_timings.aspect;
return 0;
}
static int vpbe_display_g_fmt(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"VIDIOC_G_FMT, layer id = %d\n",
layer->device_id);
if (V4L2_BUF_TYPE_VIDEO_OUTPUT != fmt->type) {
v4l2_err(&vpbe_dev->v4l2_dev, "invalid type\n");
return -EINVAL;
}
fmt->fmt.pix = layer->pix_fmt;
return 0;
}
static int vpbe_display_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
unsigned int index = 0;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"VIDIOC_ENUM_FMT, layer id = %d\n",
layer->device_id);
if (fmt->index > 1) {
v4l2_err(&vpbe_dev->v4l2_dev, "Invalid format index\n");
return -EINVAL;
}
index = fmt->index;
memset(fmt, 0, sizeof(*fmt));
fmt->index = index;
fmt->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
if (index == 0) {
strcpy(fmt->description, "YUV 4:2:2 - UYVY");
fmt->pixelformat = V4L2_PIX_FMT_UYVY;
} else {
strcpy(fmt->description, "Y/CbCr 4:2:0");
fmt->pixelformat = V4L2_PIX_FMT_NV12;
}
return 0;
}
static int vpbe_display_s_fmt(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_display *disp_dev = layer->disp_dev;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
struct osd_layer_config *cfg = &layer->layer_info.config;
struct v4l2_pix_format *pixfmt = &fmt->fmt.pix;
struct osd_state *osd_device = disp_dev->osd_device;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"VIDIOC_S_FMT, layer id = %d\n",
layer->device_id);
if (vb2_is_busy(&layer->buffer_queue))
return -EBUSY;
if (V4L2_BUF_TYPE_VIDEO_OUTPUT != fmt->type) {
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "invalid type\n");
return -EINVAL;
}
ret = vpbe_try_format(disp_dev, pixfmt, 1);
if (ret)
return ret;
layer->pix_fmt = *pixfmt;
if (pixfmt->pixelformat == V4L2_PIX_FMT_NV12) {
struct vpbe_layer *otherlayer;
otherlayer = _vpbe_display_get_other_win_layer(disp_dev, layer);
ret = osd_device->ops.request_layer(osd_device,
otherlayer->layer_info.id);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Display Manager failed to allocate layer\n");
return -EBUSY;
}
}
osd_device->ops.get_layer_config(osd_device,
layer->layer_info.id, cfg);
cfg->xsize = pixfmt->width;
cfg->ysize = pixfmt->height;
cfg->line_length = pixfmt->bytesperline;
cfg->ypos = 0;
cfg->xpos = 0;
cfg->interlaced = vpbe_dev->current_timings.interlaced;
if (V4L2_PIX_FMT_UYVY == pixfmt->pixelformat)
cfg->pixfmt = PIXFMT_YCBCRI;
if (V4L2_PIX_FMT_NV12 == pixfmt->pixelformat) {
struct vpbe_layer *otherlayer;
cfg->pixfmt = PIXFMT_NV12;
otherlayer = _vpbe_display_get_other_win_layer(disp_dev,
layer);
otherlayer->layer_info.config.pixfmt = PIXFMT_NV12;
}
ret = osd_device->ops.set_layer_config(osd_device,
layer->layer_info.id, cfg);
if (ret < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Error in S_FMT params:\n");
return -EINVAL;
}
osd_device->ops.get_layer_config(osd_device,
layer->layer_info.id, cfg);
return 0;
}
static int vpbe_display_try_fmt(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_display *disp_dev = layer->disp_dev;
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
struct v4l2_pix_format *pixfmt = &fmt->fmt.pix;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_TRY_FMT\n");
if (V4L2_BUF_TYPE_VIDEO_OUTPUT != fmt->type) {
v4l2_err(&vpbe_dev->v4l2_dev, "invalid type\n");
return -EINVAL;
}
return vpbe_try_format(disp_dev, pixfmt, 0);
}
static int vpbe_display_s_std(struct file *file, void *priv,
v4l2_std_id std_id)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_S_STD\n");
if (vb2_is_busy(&layer->buffer_queue))
return -EBUSY;
if (NULL != vpbe_dev->ops.s_std) {
ret = vpbe_dev->ops.s_std(vpbe_dev, std_id);
if (ret) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Failed to set standard for sub devices\n");
return -EINVAL;
}
} else {
return -EINVAL;
}
return 0;
}
static int vpbe_display_g_std(struct file *file, void *priv,
v4l2_std_id *std_id)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_G_STD\n");
if (vpbe_dev->current_timings.timings_type & VPBE_ENC_STD) {
*std_id = vpbe_dev->current_timings.std_id;
return 0;
}
return -EINVAL;
}
static int vpbe_display_enum_output(struct file *file, void *priv,
struct v4l2_output *output)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_ENUM_OUTPUT\n");
if (NULL == vpbe_dev->ops.enum_outputs)
return -EINVAL;
ret = vpbe_dev->ops.enum_outputs(vpbe_dev, output);
if (ret) {
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"Failed to enumerate outputs\n");
return -EINVAL;
}
return 0;
}
static int vpbe_display_s_output(struct file *file, void *priv,
unsigned int i)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_S_OUTPUT\n");
if (vb2_is_busy(&layer->buffer_queue))
return -EBUSY;
if (NULL == vpbe_dev->ops.set_output)
return -EINVAL;
ret = vpbe_dev->ops.set_output(vpbe_dev, i);
if (ret) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Failed to set output for sub devices\n");
return -EINVAL;
}
return 0;
}
static int vpbe_display_g_output(struct file *file, void *priv,
unsigned int *i)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_G_OUTPUT\n");
*i = vpbe_dev->current_out_index;
return 0;
}
static int
vpbe_display_enum_dv_timings(struct file *file, void *priv,
struct v4l2_enum_dv_timings *timings)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_ENUM_DV_TIMINGS\n");
if (NULL == vpbe_dev->ops.enum_dv_timings)
return -EINVAL;
ret = vpbe_dev->ops.enum_dv_timings(vpbe_dev, timings);
if (ret) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Failed to enumerate dv timings info\n");
return -EINVAL;
}
return 0;
}
static int
vpbe_display_s_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
int ret;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_S_DV_TIMINGS\n");
if (vb2_is_busy(&layer->buffer_queue))
return -EBUSY;
if (!vpbe_dev->ops.s_dv_timings)
return -EINVAL;
ret = vpbe_dev->ops.s_dv_timings(vpbe_dev, timings);
if (ret) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Failed to set the dv timings info\n");
return -EINVAL;
}
return 0;
}
static int
vpbe_display_g_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *dv_timings)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_device *vpbe_dev = layer->disp_dev->vpbe_dev;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "VIDIOC_G_DV_TIMINGS\n");
if (vpbe_dev->current_timings.timings_type &
VPBE_ENC_DV_TIMINGS) {
*dv_timings = vpbe_dev->current_timings.dv_timings;
} else {
return -EINVAL;
}
return 0;
}
static int vpbe_display_open(struct file *file)
{
struct vpbe_layer *layer = video_drvdata(file);
struct vpbe_display *disp_dev = layer->disp_dev;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
struct osd_state *osd_device = disp_dev->osd_device;
int err;
err = v4l2_fh_open(file);
if (err) {
v4l2_err(&vpbe_dev->v4l2_dev, "v4l2_fh_open failed\n");
return err;
}
if (!v4l2_fh_is_singular_file(file))
return err;
if (!layer->usrs) {
if (mutex_lock_interruptible(&layer->opslock))
return -ERESTARTSYS;
err = osd_device->ops.request_layer(osd_device,
layer->layer_info.id);
mutex_unlock(&layer->opslock);
if (err < 0) {
v4l2_err(&vpbe_dev->v4l2_dev,
"Display Manager failed to allocate layer\n");
v4l2_fh_release(file);
return -EINVAL;
}
}
layer->usrs++;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev,
"vpbe display device opened successfully\n");
return 0;
}
static int vpbe_display_release(struct file *file)
{
struct vpbe_layer *layer = video_drvdata(file);
struct osd_layer_config *cfg = &layer->layer_info.config;
struct vpbe_display *disp_dev = layer->disp_dev;
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
struct osd_state *osd_device = disp_dev->osd_device;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "vpbe_display_release\n");
mutex_lock(&layer->opslock);
osd_device->ops.disable_layer(osd_device,
layer->layer_info.id);
layer->usrs--;
if (!layer->usrs) {
if (cfg->pixfmt == PIXFMT_NV12) {
struct vpbe_layer *otherlayer;
otherlayer =
_vpbe_display_get_other_win_layer(disp_dev, layer);
osd_device->ops.disable_layer(osd_device,
otherlayer->layer_info.id);
osd_device->ops.release_layer(osd_device,
otherlayer->layer_info.id);
}
osd_device->ops.disable_layer(osd_device,
layer->layer_info.id);
osd_device->ops.release_layer(osd_device,
layer->layer_info.id);
}
_vb2_fop_release(file, NULL);
mutex_unlock(&layer->opslock);
disp_dev->cbcr_ofst = 0;
return 0;
}
static int vpbe_device_get(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct vpbe_display *vpbe_disp = data;
if (strcmp("vpbe_controller", pdev->name) == 0)
vpbe_disp->vpbe_dev = platform_get_drvdata(pdev);
if (strstr(pdev->name, "vpbe-osd") != NULL)
vpbe_disp->osd_device = platform_get_drvdata(pdev);
return 0;
}
static int init_vpbe_layer(int i, struct vpbe_display *disp_dev,
struct platform_device *pdev)
{
struct vpbe_layer *vpbe_display_layer = NULL;
struct video_device *vbd = NULL;
disp_dev->dev[i] =
kzalloc(sizeof(struct vpbe_layer), GFP_KERNEL);
if (!disp_dev->dev[i]) {
printk(KERN_ERR "ran out of memory\n");
return -ENOMEM;
}
spin_lock_init(&disp_dev->dev[i]->irqlock);
mutex_init(&disp_dev->dev[i]->opslock);
vpbe_display_layer = disp_dev->dev[i];
vbd = &vpbe_display_layer->video_dev;
vbd->release = video_device_release_empty;
vbd->fops = &vpbe_fops;
vbd->ioctl_ops = &vpbe_ioctl_ops;
vbd->minor = -1;
vbd->v4l2_dev = &disp_dev->vpbe_dev->v4l2_dev;
vbd->lock = &vpbe_display_layer->opslock;
vbd->vfl_dir = VFL_DIR_TX;
if (disp_dev->vpbe_dev->current_timings.timings_type &
VPBE_ENC_STD)
vbd->tvnorms = (V4L2_STD_525_60 | V4L2_STD_625_50);
snprintf(vbd->name, sizeof(vbd->name),
"DaVinci_VPBE Display_DRIVER_V%d.%d.%d",
(VPBE_DISPLAY_VERSION_CODE >> 16) & 0xff,
(VPBE_DISPLAY_VERSION_CODE >> 8) & 0xff,
(VPBE_DISPLAY_VERSION_CODE) & 0xff);
vpbe_display_layer->device_id = i;
vpbe_display_layer->layer_info.id =
((i == VPBE_DISPLAY_DEVICE_0) ? WIN_VID0 : WIN_VID1);
return 0;
}
static int register_device(struct vpbe_layer *vpbe_display_layer,
struct vpbe_display *disp_dev,
struct platform_device *pdev)
{
int err;
v4l2_info(&disp_dev->vpbe_dev->v4l2_dev,
"Trying to register VPBE display device.\n");
v4l2_info(&disp_dev->vpbe_dev->v4l2_dev,
"layer=%x,layer->video_dev=%x\n",
(int)vpbe_display_layer,
(int)&vpbe_display_layer->video_dev);
vpbe_display_layer->video_dev.queue = &vpbe_display_layer->buffer_queue;
err = video_register_device(&vpbe_display_layer->video_dev,
VFL_TYPE_GRABBER,
-1);
if (err)
return -ENODEV;
vpbe_display_layer->disp_dev = disp_dev;
platform_set_drvdata(pdev, disp_dev);
video_set_drvdata(&vpbe_display_layer->video_dev,
vpbe_display_layer);
return 0;
}
static int vpbe_display_probe(struct platform_device *pdev)
{
struct vpbe_display *disp_dev;
struct v4l2_device *v4l2_dev;
struct resource *res = NULL;
struct vb2_queue *q;
int k;
int i;
int err;
int irq;
printk(KERN_DEBUG "vpbe_display_probe\n");
disp_dev = devm_kzalloc(&pdev->dev, sizeof(struct vpbe_display),
GFP_KERNEL);
if (!disp_dev)
return -ENOMEM;
spin_lock_init(&disp_dev->dma_queue_lock);
err = bus_for_each_dev(&platform_bus_type, NULL, disp_dev,
vpbe_device_get);
if (err < 0)
return err;
v4l2_dev = &disp_dev->vpbe_dev->v4l2_dev;
if (NULL != disp_dev->vpbe_dev->ops.initialize) {
err = disp_dev->vpbe_dev->ops.initialize(&pdev->dev,
disp_dev->vpbe_dev);
if (err) {
v4l2_err(v4l2_dev, "Error initing vpbe\n");
err = -ENOMEM;
goto probe_out;
}
}
for (i = 0; i < VPBE_DISPLAY_MAX_DEVICES; i++) {
if (init_vpbe_layer(i, disp_dev, pdev)) {
err = -ENODEV;
goto probe_out;
}
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
v4l2_err(v4l2_dev, "Unable to get VENC interrupt resource\n");
err = -ENODEV;
goto probe_out;
}
irq = res->start;
err = devm_request_irq(&pdev->dev, irq, venc_isr, 0,
VPBE_DISPLAY_DRIVER, disp_dev);
if (err) {
v4l2_err(v4l2_dev, "VPBE IRQ request failed\n");
goto probe_out;
}
for (i = 0; i < VPBE_DISPLAY_MAX_DEVICES; i++) {
q = &disp_dev->dev[i]->buffer_queue;
memset(q, 0, sizeof(*q));
q->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
q->drv_priv = disp_dev->dev[i];
q->ops = &video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct vpbe_disp_buffer);
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 1;
q->lock = &disp_dev->dev[i]->opslock;
q->dev = disp_dev->vpbe_dev->pdev;
err = vb2_queue_init(q);
if (err) {
v4l2_err(v4l2_dev, "vb2_queue_init() failed\n");
goto probe_out;
}
INIT_LIST_HEAD(&disp_dev->dev[i]->dma_queue);
if (register_device(disp_dev->dev[i], disp_dev, pdev)) {
err = -ENODEV;
goto probe_out;
}
}
v4l2_dbg(1, debug, v4l2_dev,
"Successfully completed the probing of vpbe v4l2 device\n");
return 0;
probe_out:
for (k = 0; k < VPBE_DISPLAY_MAX_DEVICES; k++) {
if (disp_dev->dev[k] != NULL) {
video_unregister_device(&disp_dev->dev[k]->video_dev);
kfree(disp_dev->dev[k]);
}
}
return err;
}
static int vpbe_display_remove(struct platform_device *pdev)
{
struct vpbe_layer *vpbe_display_layer;
struct vpbe_display *disp_dev = platform_get_drvdata(pdev);
struct vpbe_device *vpbe_dev = disp_dev->vpbe_dev;
int i;
v4l2_dbg(1, debug, &vpbe_dev->v4l2_dev, "vpbe_display_remove\n");
if (NULL != vpbe_dev->ops.deinitialize)
vpbe_dev->ops.deinitialize(&pdev->dev, vpbe_dev);
for (i = 0; i < VPBE_DISPLAY_MAX_DEVICES; i++) {
vpbe_display_layer = disp_dev->dev[i];
video_unregister_device(&vpbe_display_layer->video_dev);
}
for (i = 0; i < VPBE_DISPLAY_MAX_DEVICES; i++) {
kfree(disp_dev->dev[i]);
disp_dev->dev[i] = NULL;
}
return 0;
}
