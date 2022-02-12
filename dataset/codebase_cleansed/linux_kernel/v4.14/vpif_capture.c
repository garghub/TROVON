static inline
struct vpif_cap_buffer *to_vpif_buffer(struct vb2_v4l2_buffer *vb)
{
return container_of(vb, struct vpif_cap_buffer, vb);
}
static int vpif_buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vb2_queue *q = vb->vb2_queue;
struct channel_obj *ch = vb2_get_drv_priv(q);
struct common_obj *common;
unsigned long addr;
vpif_dbg(2, debug, "vpif_buffer_prepare\n");
common = &ch->common[VPIF_VIDEO_INDEX];
vb2_set_plane_payload(vb, 0, common->fmt.fmt.pix.sizeimage);
if (vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0))
return -EINVAL;
vbuf->field = common->fmt.fmt.pix.field;
addr = vb2_dma_contig_plane_dma_addr(vb, 0);
if (!IS_ALIGNED((addr + common->ytop_off), 8) ||
!IS_ALIGNED((addr + common->ybtm_off), 8) ||
!IS_ALIGNED((addr + common->ctop_off), 8) ||
!IS_ALIGNED((addr + common->cbtm_off), 8)) {
vpif_dbg(1, debug, "offset is not aligned\n");
return -EINVAL;
}
return 0;
}
static int vpif_buffer_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct channel_obj *ch = vb2_get_drv_priv(vq);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
unsigned size = common->fmt.fmt.pix.sizeimage;
vpif_dbg(2, debug, "vpif_buffer_setup\n");
if (*nplanes) {
if (sizes[0] < size)
return -EINVAL;
size = sizes[0];
}
if (vq->num_buffers + *nbuffers < 3)
*nbuffers = 3 - vq->num_buffers;
*nplanes = 1;
sizes[0] = size;
vpif_calculate_offsets(ch);
return 0;
}
static void vpif_buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct channel_obj *ch = vb2_get_drv_priv(vb->vb2_queue);
struct vpif_cap_buffer *buf = to_vpif_buffer(vbuf);
struct common_obj *common;
unsigned long flags;
common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_buffer_queue\n");
spin_lock_irqsave(&common->irqlock, flags);
list_add_tail(&buf->list, &common->dma_queue);
spin_unlock_irqrestore(&common->irqlock, flags);
}
static int vpif_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vpif_capture_config *vpif_config_data =
vpif_dev->platform_data;
struct channel_obj *ch = vb2_get_drv_priv(vq);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_params *vpif = &ch->vpifparams;
struct vpif_cap_buffer *buf, *tmp;
unsigned long addr, flags;
int ret;
ch->field_id = 0;
if (vpif_config_data->setup_input_channel_mode) {
ret = vpif_config_data->
setup_input_channel_mode(vpif->std_info.ycmux_mode);
if (ret < 0) {
vpif_dbg(1, debug, "can't set vpif channel mode\n");
goto err;
}
}
ret = v4l2_subdev_call(ch->sd, video, s_stream, 1);
if (ret && ret != -ENOIOCTLCMD && ret != -ENODEV) {
vpif_dbg(1, debug, "stream on failed in subdev\n");
goto err;
}
ret = vpif_set_video_params(vpif, ch->channel_id);
if (ret < 0) {
vpif_dbg(1, debug, "can't set video params\n");
goto err;
}
ycmux_mode = ret;
vpif_config_addr(ch, ret);
spin_lock_irqsave(&common->irqlock, flags);
common->cur_frm = common->next_frm = list_entry(common->dma_queue.next,
struct vpif_cap_buffer, list);
list_del(&common->cur_frm->list);
spin_unlock_irqrestore(&common->irqlock, flags);
addr = vb2_dma_contig_plane_dma_addr(&common->cur_frm->vb.vb2_buf, 0);
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
channel_first_int[VPIF_VIDEO_INDEX][ch->channel_id] = 1;
if (VPIF_CHANNEL0_VIDEO == ch->channel_id) {
channel0_intr_assert();
channel0_intr_enable(1);
enable_channel0(1);
}
if (VPIF_CHANNEL1_VIDEO == ch->channel_id ||
ycmux_mode == 2) {
channel1_intr_assert();
channel1_intr_enable(1);
enable_channel1(1);
}
return 0;
err:
spin_lock_irqsave(&common->irqlock, flags);
list_for_each_entry_safe(buf, tmp, &common->dma_queue, list) {
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_QUEUED);
}
spin_unlock_irqrestore(&common->irqlock, flags);
return ret;
}
static void vpif_stop_streaming(struct vb2_queue *vq)
{
struct channel_obj *ch = vb2_get_drv_priv(vq);
struct common_obj *common;
unsigned long flags;
int ret;
common = &ch->common[VPIF_VIDEO_INDEX];
if (VPIF_CHANNEL0_VIDEO == ch->channel_id) {
enable_channel0(0);
channel0_intr_enable(0);
}
if (VPIF_CHANNEL1_VIDEO == ch->channel_id ||
ycmux_mode == 2) {
enable_channel1(0);
channel1_intr_enable(0);
}
ycmux_mode = 0;
ret = v4l2_subdev_call(ch->sd, video, s_stream, 0);
if (ret && ret != -ENOIOCTLCMD && ret != -ENODEV)
vpif_dbg(1, debug, "stream off failed in subdev\n");
if (common->cur_frm == common->next_frm) {
vb2_buffer_done(&common->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
} else {
if (common->cur_frm)
vb2_buffer_done(&common->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
if (common->next_frm)
vb2_buffer_done(&common->next_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
}
spin_lock_irqsave(&common->irqlock, flags);
while (!list_empty(&common->dma_queue)) {
common->next_frm = list_entry(common->dma_queue.next,
struct vpif_cap_buffer, list);
list_del(&common->next_frm->list);
vb2_buffer_done(&common->next_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&common->irqlock, flags);
}
static void vpif_process_buffer_complete(struct common_obj *common)
{
common->cur_frm->vb.vb2_buf.timestamp = ktime_get_ns();
vb2_buffer_done(&common->cur_frm->vb.vb2_buf, VB2_BUF_STATE_DONE);
common->cur_frm = common->next_frm;
}
static void vpif_schedule_next_buffer(struct common_obj *common)
{
unsigned long addr = 0;
spin_lock(&common->irqlock);
common->next_frm = list_entry(common->dma_queue.next,
struct vpif_cap_buffer, list);
list_del(&common->next_frm->list);
spin_unlock(&common->irqlock);
addr = vb2_dma_contig_plane_dma_addr(&common->next_frm->vb.vb2_buf, 0);
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
}
static irqreturn_t vpif_channel_isr(int irq, void *dev_id)
{
struct vpif_device *dev = &vpif_obj;
struct common_obj *common;
struct channel_obj *ch;
int channel_id;
int fid = -1, i;
channel_id = *(int *)(dev_id);
if (!vpif_intr_status(channel_id))
return IRQ_NONE;
ch = dev->dev[channel_id];
for (i = 0; i < VPIF_NUMBER_OF_OBJECTS; i++) {
common = &ch->common[i];
if (1 == ch->vpifparams.std_info.frm_fmt ||
common->fmt.fmt.pix.field == V4L2_FIELD_NONE) {
spin_lock(&common->irqlock);
if (list_empty(&common->dma_queue)) {
spin_unlock(&common->irqlock);
continue;
}
spin_unlock(&common->irqlock);
if (!channel_first_int[i][channel_id])
vpif_process_buffer_complete(common);
channel_first_int[i][channel_id] = 0;
vpif_schedule_next_buffer(common);
channel_first_int[i][channel_id] = 0;
} else {
if (channel_first_int[i][channel_id]) {
channel_first_int[i][channel_id] = 0;
continue;
}
if (0 == i) {
ch->field_id ^= 1;
fid = vpif_channel_getfid(ch->channel_id);
if (fid != ch->field_id) {
if (0 == fid)
ch->field_id = fid;
return IRQ_HANDLED;
}
}
if (0 == fid) {
if (common->cur_frm == common->next_frm)
continue;
vpif_process_buffer_complete(common);
} else if (1 == fid) {
spin_lock(&common->irqlock);
if (list_empty(&common->dma_queue) ||
(common->cur_frm != common->next_frm)) {
spin_unlock(&common->irqlock);
continue;
}
spin_unlock(&common->irqlock);
vpif_schedule_next_buffer(common);
}
}
}
return IRQ_HANDLED;
}
static int vpif_update_std_info(struct channel_obj *ch)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_params *vpifparams = &ch->vpifparams;
const struct vpif_channel_config_params *config;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
struct video_obj *vid_ch = &ch->video;
int index;
struct v4l2_pix_format *pixfmt = &common->fmt.fmt.pix;
vpif_dbg(2, debug, "vpif_update_std_info\n");
if (pixfmt->width && pixfmt->height) {
if (pixfmt->field == V4L2_FIELD_ANY ||
pixfmt->field == V4L2_FIELD_NONE)
pixfmt->field = V4L2_FIELD_NONE;
vpifparams->iface.if_type = VPIF_IF_BT656;
if (pixfmt->pixelformat == V4L2_PIX_FMT_SGRBG10 ||
pixfmt->pixelformat == V4L2_PIX_FMT_SBGGR8)
vpifparams->iface.if_type = VPIF_IF_RAW_BAYER;
if (pixfmt->pixelformat == V4L2_PIX_FMT_SGRBG10)
vpifparams->params.data_sz = 1;
if (vpifparams->iface.if_type == VPIF_IF_RAW_BAYER) {
memset(std_info, 0, sizeof(struct vpif_channel_config_params));
vpifparams->std_info.capture_format = 1;
return 0;
}
}
for (index = 0; index < vpif_ch_params_count; index++) {
config = &vpif_ch_params[index];
if (config->hd_sd == 0) {
vpif_dbg(2, debug, "SD format\n");
if (config->stdid & vid_ch->stdid) {
memcpy(std_info, config, sizeof(*config));
break;
}
} else {
vpif_dbg(2, debug, "HD format\n");
if (!memcmp(&config->dv_timings, &vid_ch->dv_timings,
sizeof(vid_ch->dv_timings))) {
memcpy(std_info, config, sizeof(*config));
break;
}
}
}
if (index == vpif_ch_params_count)
return -EINVAL;
common->fmt.fmt.pix.width = std_info->width;
common->width = std_info->width;
common->fmt.fmt.pix.height = std_info->height;
common->height = std_info->height;
common->fmt.fmt.pix.sizeimage = common->height * common->width * 2;
common->fmt.fmt.pix.bytesperline = std_info->width;
vpifparams->video_params.hpitch = std_info->width;
vpifparams->video_params.storage_mode = std_info->frm_fmt;
if (vid_ch->stdid)
common->fmt.fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
else
common->fmt.fmt.pix.colorspace = V4L2_COLORSPACE_REC709;
if (ch->vpifparams.std_info.frm_fmt)
common->fmt.fmt.pix.field = V4L2_FIELD_NONE;
else
common->fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
if (ch->vpifparams.iface.if_type == VPIF_IF_RAW_BAYER)
common->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_SBGGR8;
else
common->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_NV16;
common->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
return 0;
}
static void vpif_calculate_offsets(struct channel_obj *ch)
{
unsigned int hpitch, sizeimage;
struct video_obj *vid_ch = &(ch->video);
struct vpif_params *vpifparams = &ch->vpifparams;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
enum v4l2_field field = common->fmt.fmt.pix.field;
vpif_dbg(2, debug, "vpif_calculate_offsets\n");
if (V4L2_FIELD_ANY == field) {
if (vpifparams->std_info.frm_fmt)
vid_ch->buf_field = V4L2_FIELD_NONE;
else
vid_ch->buf_field = V4L2_FIELD_INTERLACED;
} else
vid_ch->buf_field = common->fmt.fmt.pix.field;
sizeimage = common->fmt.fmt.pix.sizeimage;
hpitch = common->fmt.fmt.pix.bytesperline;
if ((V4L2_FIELD_NONE == vid_ch->buf_field) ||
(V4L2_FIELD_INTERLACED == vid_ch->buf_field)) {
common->ytop_off = 0;
common->ybtm_off = hpitch;
common->ctop_off = sizeimage / 2;
common->cbtm_off = sizeimage / 2 + hpitch;
} else if (V4L2_FIELD_SEQ_TB == vid_ch->buf_field) {
common->ytop_off = 0;
common->ybtm_off = sizeimage / 4;
common->ctop_off = sizeimage / 2;
common->cbtm_off = common->ctop_off + sizeimage / 4;
} else if (V4L2_FIELD_SEQ_BT == vid_ch->buf_field) {
common->ybtm_off = 0;
common->ytop_off = sizeimage / 4;
common->cbtm_off = sizeimage / 2;
common->ctop_off = common->cbtm_off + sizeimage / 4;
}
if ((V4L2_FIELD_NONE == vid_ch->buf_field) ||
(V4L2_FIELD_INTERLACED == vid_ch->buf_field))
vpifparams->video_params.storage_mode = 1;
else
vpifparams->video_params.storage_mode = 0;
if (1 == vpifparams->std_info.frm_fmt)
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline;
else {
if ((field == V4L2_FIELD_ANY)
|| (field == V4L2_FIELD_INTERLACED))
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline * 2;
else
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline;
}
ch->vpifparams.video_params.stdid = vpifparams->std_info.stdid;
}
static inline enum v4l2_field vpif_get_default_field(
struct vpif_interface *iface)
{
return (iface->if_type == VPIF_IF_RAW_BAYER) ? V4L2_FIELD_NONE :
V4L2_FIELD_INTERLACED;
}
static void vpif_config_addr(struct channel_obj *ch, int muxmode)
{
struct common_obj *common;
vpif_dbg(2, debug, "vpif_config_addr\n");
common = &(ch->common[VPIF_VIDEO_INDEX]);
if (VPIF_CHANNEL1_VIDEO == ch->channel_id)
common->set_addr = ch1_set_videobuf_addr;
else if (2 == muxmode)
common->set_addr = ch0_set_videobuf_addr_yc_nmux;
else
common->set_addr = ch0_set_videobuf_addr;
}
static int vpif_input_to_subdev(
struct vpif_capture_config *vpif_cfg,
struct vpif_capture_chan_config *chan_cfg,
int input_index)
{
struct vpif_subdev_info *subdev_info;
const char *subdev_name;
int i;
vpif_dbg(2, debug, "vpif_input_to_subdev\n");
if (!chan_cfg)
return -1;
if (input_index >= chan_cfg->input_count)
return -1;
subdev_name = chan_cfg->inputs[input_index].subdev_name;
if (!subdev_name)
return -1;
for (i = 0; i < vpif_cfg->subdev_count; i++) {
subdev_info = &vpif_cfg->subdev_info[i];
if (subdev_info && !strcmp(subdev_info->name, subdev_name))
return i;
}
return -1;
}
static int vpif_set_input(
struct vpif_capture_config *vpif_cfg,
struct channel_obj *ch,
int index)
{
struct vpif_capture_chan_config *chan_cfg =
&vpif_cfg->chan_config[ch->channel_id];
struct vpif_subdev_info *subdev_info = NULL;
struct v4l2_subdev *sd = NULL;
u32 input = 0, output = 0;
int sd_index;
int ret;
sd_index = vpif_input_to_subdev(vpif_cfg, chan_cfg, index);
if (sd_index >= 0) {
sd = vpif_obj.sd[sd_index];
subdev_info = &vpif_cfg->subdev_info[sd_index];
} else {
return 0;
}
if (sd && vpif_cfg->setup_input_path) {
ret = vpif_cfg->setup_input_path(ch->channel_id,
subdev_info->name);
if (ret < 0) {
vpif_dbg(1, debug, "couldn't setup input path for the" \
" sub device %s, for input index %d\n",
subdev_info->name, index);
return ret;
}
}
if (sd) {
input = chan_cfg->inputs[index].input_route;
output = chan_cfg->inputs[index].output_route;
ret = v4l2_subdev_call(sd, video, s_routing,
input, output, 0);
if (ret < 0 && ret != -ENOIOCTLCMD) {
vpif_dbg(1, debug, "Failed to set input\n");
return ret;
}
}
ch->input_idx = index;
ch->sd = sd;
ch->vpifparams.iface = chan_cfg->vpif_if;
ch->video_dev.tvnorms = chan_cfg->inputs[index].input.std;
return 0;
}
static int vpif_querystd(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
int ret;
vpif_dbg(2, debug, "vpif_querystd\n");
ret = v4l2_subdev_call(ch->sd, video, querystd, std_id);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
return -ENODATA;
if (ret) {
vpif_dbg(1, debug, "Failed to query standard for sub devices\n");
return ret;
}
return 0;
}
static int vpif_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct vpif_capture_chan_config *chan_cfg;
struct v4l2_input input;
vpif_dbg(2, debug, "vpif_g_std\n");
if (!config->chan_config[ch->channel_id].inputs)
return -ENODATA;
chan_cfg = &config->chan_config[ch->channel_id];
input = chan_cfg->inputs[ch->input_idx].input;
if (input.capabilities != V4L2_IN_CAP_STD)
return -ENODATA;
*std = ch->video.stdid;
return 0;
}
static int vpif_s_std(struct file *file, void *priv, v4l2_std_id std_id)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_capture_chan_config *chan_cfg;
struct v4l2_input input;
int ret;
vpif_dbg(2, debug, "vpif_s_std\n");
if (!config->chan_config[ch->channel_id].inputs)
return -ENODATA;
chan_cfg = &config->chan_config[ch->channel_id];
input = chan_cfg->inputs[ch->input_idx].input;
if (input.capabilities != V4L2_IN_CAP_STD)
return -ENODATA;
if (vb2_is_busy(&common->buffer_queue))
return -EBUSY;
ch->video.stdid = std_id;
memset(&ch->video.dv_timings, 0, sizeof(ch->video.dv_timings));
if (vpif_update_std_info(ch)) {
vpif_err("Error getting the standard info\n");
return -EINVAL;
}
ret = v4l2_subdev_call(ch->sd, video, s_std, std_id);
if (ret && ret != -ENOIOCTLCMD && ret != -ENODEV) {
vpif_dbg(1, debug, "Failed to set standard for sub devices\n");
return ret;
}
return 0;
}
static int vpif_enum_input(struct file *file, void *priv,
struct v4l2_input *input)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct vpif_capture_chan_config *chan_cfg;
chan_cfg = &config->chan_config[ch->channel_id];
if (input->index >= chan_cfg->input_count)
return -EINVAL;
memcpy(input, &chan_cfg->inputs[input->index].input,
sizeof(*input));
return 0;
}
static int vpif_g_input(struct file *file, void *priv, unsigned int *index)
{
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
*index = ch->input_idx;
return 0;
}
static int vpif_s_input(struct file *file, void *priv, unsigned int index)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_capture_chan_config *chan_cfg;
chan_cfg = &config->chan_config[ch->channel_id];
if (index >= chan_cfg->input_count)
return -EINVAL;
if (vb2_is_busy(&common->buffer_queue))
return -EBUSY;
return vpif_set_input(config, ch, index);
}
static int vpif_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
if (fmt->index != 0) {
vpif_dbg(1, debug, "Invalid format index\n");
return -EINVAL;
}
if (ch->vpifparams.iface.if_type == VPIF_IF_RAW_BAYER) {
fmt->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
strcpy(fmt->description, "Raw Mode -Bayer Pattern GrRBGb");
fmt->pixelformat = V4L2_PIX_FMT_SBGGR8;
} else {
fmt->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
strcpy(fmt->description, "YCbCr4:2:2 Semi-Planar");
fmt->pixelformat = V4L2_PIX_FMT_NV16;
}
return 0;
}
static int vpif_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct v4l2_pix_format *pixfmt = &fmt->fmt.pix;
struct common_obj *common = &(ch->common[VPIF_VIDEO_INDEX]);
common->fmt = *fmt;
vpif_update_std_info(ch);
pixfmt->field = common->fmt.fmt.pix.field;
pixfmt->colorspace = common->fmt.fmt.pix.colorspace;
pixfmt->bytesperline = common->fmt.fmt.pix.width;
pixfmt->width = common->fmt.fmt.pix.width;
pixfmt->height = common->fmt.fmt.pix.height;
pixfmt->sizeimage = pixfmt->bytesperline * pixfmt->height * 2;
if (pixfmt->pixelformat == V4L2_PIX_FMT_SGRBG10) {
pixfmt->bytesperline = common->fmt.fmt.pix.width * 2;
pixfmt->sizeimage = pixfmt->bytesperline * pixfmt->height;
}
pixfmt->priv = 0;
dev_dbg(vpif_dev, "%s: %d x %d; pitch=%d pixelformat=0x%08x, field=%d, size=%d\n", __func__,
pixfmt->width, pixfmt->height,
pixfmt->bytesperline, pixfmt->pixelformat,
pixfmt->field, pixfmt->sizeimage);
return 0;
}
static int vpif_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct v4l2_pix_format *pix_fmt = &fmt->fmt.pix;
struct v4l2_subdev_format format = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
};
struct v4l2_mbus_framefmt *mbus_fmt = &format.format;
int ret;
if (common->fmt.type != fmt->type)
return -EINVAL;
*fmt = common->fmt;
ret = v4l2_subdev_call(ch->sd, pad, get_fmt, NULL, &format);
if (!ret && mbus_fmt->code) {
v4l2_fill_pix_format(pix_fmt, mbus_fmt);
pix_fmt->bytesperline = pix_fmt->width;
if (mbus_fmt->code == MEDIA_BUS_FMT_SGRBG10_1X10) {
pix_fmt->pixelformat = V4L2_PIX_FMT_SGRBG10;
pix_fmt->bytesperline = pix_fmt->width * 2;
} else if (mbus_fmt->code == MEDIA_BUS_FMT_UYVY8_2X8) {
pix_fmt->pixelformat = V4L2_PIX_FMT_NV16;
pix_fmt->bytesperline = pix_fmt->width * 2;
} else {
dev_warn(vpif_dev, "%s: Unhandled media-bus format 0x%x\n",
__func__, mbus_fmt->code);
}
pix_fmt->sizeimage = pix_fmt->bytesperline * pix_fmt->height;
dev_dbg(vpif_dev, "%s: %d x %d; pitch=%d, pixelformat=0x%08x, code=0x%x, field=%d, size=%d\n", __func__,
pix_fmt->width, pix_fmt->height,
pix_fmt->bytesperline, pix_fmt->pixelformat,
mbus_fmt->code, pix_fmt->field, pix_fmt->sizeimage);
common->fmt = *fmt;
vpif_update_std_info(ch);
}
return 0;
}
static int vpif_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret;
vpif_dbg(2, debug, "%s\n", __func__);
if (vb2_is_busy(&common->buffer_queue))
return -EBUSY;
ret = vpif_try_fmt_vid_cap(file, priv, fmt);
if (ret)
return ret;
common->fmt = *fmt;
return 0;
}
static int vpif_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
strlcpy(cap->driver, VPIF_DRIVER_NAME, sizeof(cap->driver));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(vpif_dev));
strlcpy(cap->card, config->card_name, sizeof(cap->card));
return 0;
}
static int
vpif_enum_dv_timings(struct file *file, void *priv,
struct v4l2_enum_dv_timings *timings)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct vpif_capture_chan_config *chan_cfg;
struct v4l2_input input;
int ret;
if (!config->chan_config[ch->channel_id].inputs)
return -ENODATA;
chan_cfg = &config->chan_config[ch->channel_id];
input = chan_cfg->inputs[ch->input_idx].input;
if (input.capabilities != V4L2_IN_CAP_DV_TIMINGS)
return -ENODATA;
timings->pad = 0;
ret = v4l2_subdev_call(ch->sd, pad, enum_dv_timings, timings);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
return -EINVAL;
return ret;
}
static int
vpif_query_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct vpif_capture_chan_config *chan_cfg;
struct v4l2_input input;
int ret;
if (!config->chan_config[ch->channel_id].inputs)
return -ENODATA;
chan_cfg = &config->chan_config[ch->channel_id];
input = chan_cfg->inputs[ch->input_idx].input;
if (input.capabilities != V4L2_IN_CAP_DV_TIMINGS)
return -ENODATA;
ret = v4l2_subdev_call(ch->sd, video, query_dv_timings, timings);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
return -ENODATA;
return ret;
}
static int vpif_s_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct vpif_params *vpifparams = &ch->vpifparams;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct video_obj *vid_ch = &ch->video;
struct v4l2_bt_timings *bt = &vid_ch->dv_timings.bt;
struct vpif_capture_chan_config *chan_cfg;
struct v4l2_input input;
int ret;
if (!config->chan_config[ch->channel_id].inputs)
return -ENODATA;
chan_cfg = &config->chan_config[ch->channel_id];
input = chan_cfg->inputs[ch->input_idx].input;
if (input.capabilities != V4L2_IN_CAP_DV_TIMINGS)
return -ENODATA;
if (timings->type != V4L2_DV_BT_656_1120) {
vpif_dbg(2, debug, "Timing type not defined\n");
return -EINVAL;
}
if (vb2_is_busy(&common->buffer_queue))
return -EBUSY;
ret = v4l2_subdev_call(ch->sd, video, s_dv_timings, timings);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
ret = 0;
if (ret < 0) {
vpif_dbg(2, debug, "Error setting custom DV timings\n");
return ret;
}
if (!(timings->bt.width && timings->bt.height &&
(timings->bt.hbackporch ||
timings->bt.hfrontporch ||
timings->bt.hsync) &&
timings->bt.vfrontporch &&
(timings->bt.vbackporch ||
timings->bt.vsync))) {
vpif_dbg(2, debug, "Timings for width, height, horizontal back porch, horizontal sync, horizontal front porch, vertical back porch, vertical sync and vertical back porch must be defined\n");
return -EINVAL;
}
vid_ch->dv_timings = *timings;
std_info->eav2sav = V4L2_DV_BT_BLANKING_WIDTH(bt) - 8;
std_info->sav2eav = bt->width;
std_info->l1 = 1;
std_info->l3 = bt->vsync + bt->vbackporch + 1;
std_info->vsize = V4L2_DV_BT_FRAME_HEIGHT(bt);
if (bt->interlaced) {
if (bt->il_vbackporch || bt->il_vfrontporch || bt->il_vsync) {
std_info->l5 = std_info->vsize/2 -
(bt->vfrontporch - 1);
std_info->l7 = std_info->vsize/2 + 1;
std_info->l9 = std_info->l7 + bt->il_vsync +
bt->il_vbackporch + 1;
std_info->l11 = std_info->vsize -
(bt->il_vfrontporch - 1);
} else {
vpif_dbg(2, debug, "Required timing values for interlaced BT format missing\n");
return -EINVAL;
}
} else {
std_info->l5 = std_info->vsize - (bt->vfrontporch - 1);
}
strncpy(std_info->name, "Custom timings BT656/1120", VPIF_MAX_NAME);
std_info->width = bt->width;
std_info->height = bt->height;
std_info->frm_fmt = bt->interlaced ? 0 : 1;
std_info->ycmux_mode = 0;
std_info->capture_format = 0;
std_info->vbi_supported = 0;
std_info->hd_sd = 1;
std_info->stdid = 0;
vid_ch->stdid = 0;
return 0;
}
static int vpif_g_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(file);
struct channel_obj *ch = video_get_drvdata(vdev);
struct video_obj *vid_ch = &ch->video;
struct vpif_capture_chan_config *chan_cfg;
struct v4l2_input input;
if (!config->chan_config[ch->channel_id].inputs)
return -ENODATA;
chan_cfg = &config->chan_config[ch->channel_id];
input = chan_cfg->inputs[ch->input_idx].input;
if (input.capabilities != V4L2_IN_CAP_DV_TIMINGS)
return -ENODATA;
*timings = vid_ch->dv_timings;
return 0;
}
static int vpif_log_status(struct file *filep, void *priv)
{
v4l2_device_call_all(&vpif_obj.v4l2_dev, 0, core, log_status);
return 0;
}
static int initialize_vpif(void)
{
int err, i, j;
int free_channel_objects_index;
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
vpif_obj.dev[i] =
kzalloc(sizeof(*vpif_obj.dev[i]), GFP_KERNEL);
if (!vpif_obj.dev[i]) {
free_channel_objects_index = i;
err = -ENOMEM;
goto vpif_init_free_channel_objects;
}
}
return 0;
vpif_init_free_channel_objects:
for (j = 0; j < free_channel_objects_index; j++)
kfree(vpif_obj.dev[j]);
return err;
}
static int vpif_async_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
int i;
for (i = 0; i < vpif_obj.config->asd_sizes[0]; i++) {
struct v4l2_async_subdev *_asd = vpif_obj.config->asd[i];
const struct fwnode_handle *fwnode = _asd->match.fwnode.fwnode;
if (fwnode == subdev->fwnode) {
vpif_obj.sd[i] = subdev;
vpif_obj.config->chan_config->inputs[i].subdev_name =
(char *)to_of_node(subdev->fwnode)->full_name;
vpif_dbg(2, debug,
"%s: setting input %d subdev_name = %pOF\n",
__func__, i,
to_of_node(subdev->fwnode));
return 0;
}
}
for (i = 0; i < vpif_obj.config->subdev_count; i++)
if (!strcmp(vpif_obj.config->subdev_info[i].name,
subdev->name)) {
vpif_obj.sd[i] = subdev;
return 0;
}
return -EINVAL;
}
static int vpif_probe_complete(void)
{
struct common_obj *common;
struct video_device *vdev;
struct channel_obj *ch;
struct vb2_queue *q;
int j, err, k;
for (j = 0; j < VPIF_CAPTURE_MAX_DEVICES; j++) {
ch = vpif_obj.dev[j];
ch->channel_id = j;
common = &(ch->common[VPIF_VIDEO_INDEX]);
spin_lock_init(&common->irqlock);
mutex_init(&common->lock);
err = vpif_set_input(vpif_obj.config, ch, 0);
if (err)
goto probe_out;
ch->video.stdid = V4L2_STD_525_60;
memset(&ch->video.dv_timings, 0, sizeof(ch->video.dv_timings));
common->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
vpif_update_std_info(ch);
q = &common->buffer_queue;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
q->drv_priv = ch;
q->ops = &video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct vpif_cap_buffer);
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 1;
q->lock = &common->lock;
q->dev = vpif_dev;
err = vb2_queue_init(q);
if (err) {
vpif_err("vpif_capture: vb2_queue_init() failed\n");
goto probe_out;
}
INIT_LIST_HEAD(&common->dma_queue);
vdev = &ch->video_dev;
strlcpy(vdev->name, VPIF_DRIVER_NAME, sizeof(vdev->name));
vdev->release = video_device_release_empty;
vdev->fops = &vpif_fops;
vdev->ioctl_ops = &vpif_ioctl_ops;
vdev->v4l2_dev = &vpif_obj.v4l2_dev;
vdev->vfl_dir = VFL_DIR_RX;
vdev->queue = q;
vdev->lock = &common->lock;
video_set_drvdata(&ch->video_dev, ch);
err = video_register_device(vdev,
VFL_TYPE_GRABBER, (j ? 1 : 0));
if (err)
goto probe_out;
}
v4l2_info(&vpif_obj.v4l2_dev, "VPIF capture driver initialized\n");
return 0;
probe_out:
for (k = 0; k < j; k++) {
ch = vpif_obj.dev[k];
common = &ch->common[k];
video_unregister_device(&ch->video_dev);
}
kfree(vpif_obj.sd);
v4l2_device_unregister(&vpif_obj.v4l2_dev);
return err;
}
static int vpif_async_complete(struct v4l2_async_notifier *notifier)
{
return vpif_probe_complete();
}
static struct vpif_capture_config *
vpif_capture_get_pdata(struct platform_device *pdev)
{
struct device_node *endpoint = NULL;
struct v4l2_fwnode_endpoint bus_cfg;
struct vpif_capture_config *pdata;
struct vpif_subdev_info *sdinfo;
struct vpif_capture_chan_config *chan;
unsigned int i;
if (pdev->dev.parent && pdev->dev.parent->of_node)
pdev->dev.of_node = pdev->dev.parent->of_node;
if (!IS_ENABLED(CONFIG_OF) || !pdev->dev.of_node)
return pdev->dev.platform_data;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
pdata->subdev_info =
devm_kzalloc(&pdev->dev, sizeof(*pdata->subdev_info) *
VPIF_CAPTURE_NUM_CHANNELS, GFP_KERNEL);
if (!pdata->subdev_info)
return NULL;
for (i = 0; i < VPIF_CAPTURE_NUM_CHANNELS; i++) {
struct device_node *rem;
unsigned int flags;
int err;
endpoint = of_graph_get_next_endpoint(pdev->dev.of_node,
endpoint);
if (!endpoint)
break;
sdinfo = &pdata->subdev_info[i];
chan = &pdata->chan_config[i];
chan->inputs = devm_kzalloc(&pdev->dev,
sizeof(*chan->inputs) *
VPIF_CAPTURE_NUM_CHANNELS,
GFP_KERNEL);
chan->input_count++;
chan->inputs[i].input.type = V4L2_INPUT_TYPE_CAMERA;
chan->inputs[i].input.std = V4L2_STD_ALL;
chan->inputs[i].input.capabilities = V4L2_IN_CAP_STD;
err = v4l2_fwnode_endpoint_parse(of_fwnode_handle(endpoint),
&bus_cfg);
if (err) {
dev_err(&pdev->dev, "Could not parse the endpoint\n");
goto done;
}
dev_dbg(&pdev->dev, "Endpoint %pOF, bus_width = %d\n",
endpoint, bus_cfg.bus.parallel.bus_width);
flags = bus_cfg.bus.parallel.flags;
if (flags & V4L2_MBUS_HSYNC_ACTIVE_HIGH)
chan->vpif_if.hd_pol = 1;
if (flags & V4L2_MBUS_VSYNC_ACTIVE_HIGH)
chan->vpif_if.vd_pol = 1;
rem = of_graph_get_remote_port_parent(endpoint);
if (!rem) {
dev_dbg(&pdev->dev, "Remote device at %pOF not found\n",
endpoint);
goto done;
}
dev_dbg(&pdev->dev, "Remote device %s, %pOF found\n",
rem->name, rem);
sdinfo->name = rem->full_name;
pdata->asd[i] = devm_kzalloc(&pdev->dev,
sizeof(struct v4l2_async_subdev),
GFP_KERNEL);
if (!pdata->asd[i]) {
of_node_put(rem);
pdata = NULL;
goto done;
}
pdata->asd[i]->match_type = V4L2_ASYNC_MATCH_FWNODE;
pdata->asd[i]->match.fwnode.fwnode = of_fwnode_handle(rem);
of_node_put(rem);
}
done:
if (pdata) {
pdata->asd_sizes[0] = i;
pdata->subdev_count = i;
pdata->card_name = "DA850/OMAP-L138 Video Capture";
}
return pdata;
}
static __init int vpif_probe(struct platform_device *pdev)
{
struct vpif_subdev_info *subdevdata;
struct i2c_adapter *i2c_adap;
struct resource *res;
int subdev_count;
int res_idx = 0;
int i, err;
pdev->dev.platform_data = vpif_capture_get_pdata(pdev);
if (!pdev->dev.platform_data) {
dev_warn(&pdev->dev, "Missing platform data. Giving up.\n");
return -EINVAL;
}
if (!pdev->dev.platform_data) {
dev_warn(&pdev->dev, "Missing platform data. Giving up.\n");
return -EINVAL;
}
vpif_dev = &pdev->dev;
err = initialize_vpif();
if (err) {
v4l2_err(vpif_dev->driver, "Error initializing vpif\n");
return err;
}
err = v4l2_device_register(vpif_dev, &vpif_obj.v4l2_dev);
if (err) {
v4l2_err(vpif_dev->driver, "Error registering v4l2 device\n");
return err;
}
while ((res = platform_get_resource(pdev, IORESOURCE_IRQ, res_idx))) {
err = devm_request_irq(&pdev->dev, res->start, vpif_channel_isr,
IRQF_SHARED, VPIF_DRIVER_NAME,
(void *)(&vpif_obj.dev[res_idx]->
channel_id));
if (err) {
err = -EINVAL;
goto vpif_unregister;
}
res_idx++;
}
vpif_obj.config = pdev->dev.platform_data;
subdev_count = vpif_obj.config->subdev_count;
vpif_obj.sd = kcalloc(subdev_count, sizeof(*vpif_obj.sd), GFP_KERNEL);
if (!vpif_obj.sd) {
err = -ENOMEM;
goto vpif_unregister;
}
if (!vpif_obj.config->asd_sizes[0]) {
int i2c_id = vpif_obj.config->i2c_adapter_id;
i2c_adap = i2c_get_adapter(i2c_id);
WARN_ON(!i2c_adap);
for (i = 0; i < subdev_count; i++) {
subdevdata = &vpif_obj.config->subdev_info[i];
vpif_obj.sd[i] =
v4l2_i2c_new_subdev_board(&vpif_obj.v4l2_dev,
i2c_adap,
&subdevdata->
board_info,
NULL);
if (!vpif_obj.sd[i]) {
vpif_err("Error registering v4l2 subdevice\n");
err = -ENODEV;
goto probe_subdev_out;
}
v4l2_info(&vpif_obj.v4l2_dev,
"registered sub device %s\n",
subdevdata->name);
}
vpif_probe_complete();
} else {
vpif_obj.notifier.subdevs = vpif_obj.config->asd;
vpif_obj.notifier.num_subdevs = vpif_obj.config->asd_sizes[0];
vpif_obj.notifier.bound = vpif_async_bound;
vpif_obj.notifier.complete = vpif_async_complete;
err = v4l2_async_notifier_register(&vpif_obj.v4l2_dev,
&vpif_obj.notifier);
if (err) {
vpif_err("Error registering async notifier\n");
err = -EINVAL;
goto probe_subdev_out;
}
}
return 0;
probe_subdev_out:
kfree(vpif_obj.sd);
vpif_unregister:
v4l2_device_unregister(&vpif_obj.v4l2_dev);
return err;
}
static int vpif_remove(struct platform_device *device)
{
struct channel_obj *ch;
int i;
v4l2_device_unregister(&vpif_obj.v4l2_dev);
kfree(vpif_obj.sd);
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
video_unregister_device(&ch->video_dev);
kfree(vpif_obj.dev[i]);
}
return 0;
}
static int vpif_suspend(struct device *dev)
{
struct common_obj *common;
struct channel_obj *ch;
int i;
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
common = &ch->common[VPIF_VIDEO_INDEX];
if (!vb2_start_streaming_called(&common->buffer_queue))
continue;
mutex_lock(&common->lock);
if (ch->channel_id == VPIF_CHANNEL0_VIDEO) {
enable_channel0(0);
channel0_intr_enable(0);
}
if (ch->channel_id == VPIF_CHANNEL1_VIDEO ||
ycmux_mode == 2) {
enable_channel1(0);
channel1_intr_enable(0);
}
mutex_unlock(&common->lock);
}
return 0;
}
static int vpif_resume(struct device *dev)
{
struct common_obj *common;
struct channel_obj *ch;
int i;
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
common = &ch->common[VPIF_VIDEO_INDEX];
if (!vb2_start_streaming_called(&common->buffer_queue))
continue;
mutex_lock(&common->lock);
if (ch->channel_id == VPIF_CHANNEL0_VIDEO) {
enable_channel0(1);
channel0_intr_enable(1);
}
if (ch->channel_id == VPIF_CHANNEL1_VIDEO ||
ycmux_mode == 2) {
enable_channel1(1);
channel1_intr_enable(1);
}
mutex_unlock(&common->lock);
}
return 0;
}
