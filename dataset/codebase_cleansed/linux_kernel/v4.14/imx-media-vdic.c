static void vdic_put_ipu_resources(struct vdic_priv *priv)
{
if (priv->vdi_in_ch_p)
ipu_idmac_put(priv->vdi_in_ch_p);
priv->vdi_in_ch_p = NULL;
if (priv->vdi_in_ch)
ipu_idmac_put(priv->vdi_in_ch);
priv->vdi_in_ch = NULL;
if (priv->vdi_in_ch_n)
ipu_idmac_put(priv->vdi_in_ch_n);
priv->vdi_in_ch_n = NULL;
if (!IS_ERR_OR_NULL(priv->vdi))
ipu_vdi_put(priv->vdi);
priv->vdi = NULL;
}
static int vdic_get_ipu_resources(struct vdic_priv *priv)
{
int ret, err_chan;
struct ipuv3_channel *ch;
struct ipu_vdi *vdi;
priv->ipu = priv->md->ipu[priv->ipu_id];
vdi = ipu_vdi_get(priv->ipu);
if (IS_ERR(vdi)) {
v4l2_err(&priv->sd, "failed to get VDIC\n");
ret = PTR_ERR(vdi);
goto out;
}
priv->vdi = vdi;
if (!priv->csi_direct) {
ch = ipu_idmac_get(priv->ipu, IPUV3_CHANNEL_MEM_VDI_PREV);
if (IS_ERR(ch)) {
err_chan = IPUV3_CHANNEL_MEM_VDI_PREV;
ret = PTR_ERR(ch);
goto out_err_chan;
}
priv->vdi_in_ch_p = ch;
ch = ipu_idmac_get(priv->ipu, IPUV3_CHANNEL_MEM_VDI_CUR);
if (IS_ERR(ch)) {
err_chan = IPUV3_CHANNEL_MEM_VDI_CUR;
ret = PTR_ERR(ch);
goto out_err_chan;
}
priv->vdi_in_ch = ch;
ch = ipu_idmac_get(priv->ipu, IPUV3_CHANNEL_MEM_VDI_NEXT);
if (IS_ERR(priv->vdi_in_ch_n)) {
err_chan = IPUV3_CHANNEL_MEM_VDI_NEXT;
ret = PTR_ERR(ch);
goto out_err_chan;
}
priv->vdi_in_ch_n = ch;
}
return 0;
out_err_chan:
v4l2_err(&priv->sd, "could not get IDMAC channel %u\n", err_chan);
out:
vdic_put_ipu_resources(priv);
return ret;
}
static void __maybe_unused prepare_vdi_in_buffers(struct vdic_priv *priv,
struct imx_media_buffer *curr)
{
dma_addr_t prev_phys, curr_phys, next_phys;
struct imx_media_buffer *prev;
struct vb2_buffer *curr_vb, *prev_vb;
u32 fs = priv->field_size;
u32 is = priv->in_stride;
priv->prev_in_buf = priv->curr_in_buf;
priv->curr_in_buf = curr;
prev = priv->prev_in_buf ? priv->prev_in_buf : curr;
prev_vb = &prev->vbuf.vb2_buf;
curr_vb = &curr->vbuf.vb2_buf;
switch (priv->fieldtype) {
case V4L2_FIELD_SEQ_TB:
prev_phys = vb2_dma_contig_plane_dma_addr(prev_vb, 0);
curr_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0) + fs;
next_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0);
break;
case V4L2_FIELD_SEQ_BT:
prev_phys = vb2_dma_contig_plane_dma_addr(prev_vb, 0) + fs;
curr_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0);
next_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0) + fs;
break;
case V4L2_FIELD_INTERLACED_BT:
prev_phys = vb2_dma_contig_plane_dma_addr(prev_vb, 0) + is;
curr_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0);
next_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0) + is;
break;
default:
prev_phys = vb2_dma_contig_plane_dma_addr(prev_vb, 0);
curr_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0) + is;
next_phys = vb2_dma_contig_plane_dma_addr(curr_vb, 0);
break;
}
ipu_cpmem_set_buffer(priv->vdi_in_ch_p, 0, prev_phys);
ipu_cpmem_set_buffer(priv->vdi_in_ch, 0, curr_phys);
ipu_cpmem_set_buffer(priv->vdi_in_ch_n, 0, next_phys);
ipu_idmac_select_buffer(priv->vdi_in_ch_p, 0);
ipu_idmac_select_buffer(priv->vdi_in_ch, 0);
ipu_idmac_select_buffer(priv->vdi_in_ch_n, 0);
}
static int setup_vdi_channel(struct vdic_priv *priv,
struct ipuv3_channel *channel,
dma_addr_t phys0, dma_addr_t phys1)
{
struct imx_media_video_dev *vdev = priv->vdev;
unsigned int burst_size;
struct ipu_image image;
int ret;
ipu_cpmem_zero(channel);
memset(&image, 0, sizeof(image));
image.pix = vdev->fmt.fmt.pix;
image.pix.height /= 2;
image.rect.width = image.pix.width;
image.rect.height = image.pix.height;
image.phys0 = phys0;
image.phys1 = phys1;
ret = ipu_cpmem_set_image(channel, &image);
if (ret)
return ret;
burst_size = (image.pix.width & 0xf) ? 8 : 16;
ipu_cpmem_set_burstsize(channel, burst_size);
ipu_cpmem_set_axi_id(channel, 1);
ipu_idmac_set_double_buffer(channel, false);
return 0;
}
static int vdic_setup_direct(struct vdic_priv *priv)
{
ipu_fsu_link(priv->ipu, IPUV3_CHANNEL_CSI_DIRECT,
IPUV3_CHANNEL_CSI_VDI_PREV);
return 0;
}
static void vdic_start_direct(struct vdic_priv *priv)
{
}
static void vdic_stop_direct(struct vdic_priv *priv)
{
}
static void vdic_disable_direct(struct vdic_priv *priv)
{
ipu_fsu_unlink(priv->ipu, IPUV3_CHANNEL_CSI_DIRECT,
IPUV3_CHANNEL_CSI_VDI_PREV);
}
static int vdic_setup_indirect(struct vdic_priv *priv)
{
struct v4l2_mbus_framefmt *infmt;
const struct imx_media_pixfmt *incc;
int in_size, ret;
infmt = &priv->format_mbus[VDIC_SINK_PAD_IDMAC];
incc = priv->cc[VDIC_SINK_PAD_IDMAC];
in_size = (infmt->width * incc->bpp * infmt->height) >> 3;
priv->field_size = in_size / 2;
priv->in_stride = incc->planar ?
infmt->width : (infmt->width * incc->bpp) >> 3;
priv->prev_in_buf = NULL;
priv->curr_in_buf = NULL;
priv->fieldtype = infmt->field;
ret = setup_vdi_channel(priv, priv->vdi_in_ch_p, 0, 0);
if (ret)
return ret;
ret = setup_vdi_channel(priv, priv->vdi_in_ch, 0, 0);
if (ret)
return ret;
return setup_vdi_channel(priv, priv->vdi_in_ch_n, 0, 0);
}
static void vdic_start_indirect(struct vdic_priv *priv)
{
ipu_idmac_enable_channel(priv->vdi_in_ch_p);
ipu_idmac_enable_channel(priv->vdi_in_ch);
ipu_idmac_enable_channel(priv->vdi_in_ch_n);
}
static void vdic_stop_indirect(struct vdic_priv *priv)
{
ipu_idmac_disable_channel(priv->vdi_in_ch_p);
ipu_idmac_disable_channel(priv->vdi_in_ch);
ipu_idmac_disable_channel(priv->vdi_in_ch_n);
}
static void vdic_disable_indirect(struct vdic_priv *priv)
{
}
static int vdic_start(struct vdic_priv *priv)
{
struct v4l2_mbus_framefmt *infmt;
int ret;
infmt = &priv->format_mbus[priv->active_input_pad];
priv->ops = priv->csi_direct ? &direct_ops : &indirect_ops;
ret = vdic_get_ipu_resources(priv);
if (ret)
return ret;
ipu_vdi_setup(priv->vdi, MEDIA_BUS_FMT_UYVY8_2X8,
infmt->width, infmt->height);
ipu_vdi_set_field_order(priv->vdi, V4L2_STD_UNKNOWN, infmt->field);
ipu_vdi_set_motion(priv->vdi, priv->motion);
ret = priv->ops->setup(priv);
if (ret)
goto out_put_ipu;
ipu_vdi_enable(priv->vdi);
priv->ops->start(priv);
return 0;
out_put_ipu:
vdic_put_ipu_resources(priv);
return ret;
}
static void vdic_stop(struct vdic_priv *priv)
{
priv->ops->stop(priv);
ipu_vdi_disable(priv->vdi);
priv->ops->disable(priv);
vdic_put_ipu_resources(priv);
}
static int vdic_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vdic_priv *priv = container_of(ctrl->handler,
struct vdic_priv, ctrl_hdlr);
enum ipu_motion_sel motion;
int ret = 0;
mutex_lock(&priv->lock);
switch (ctrl->id) {
case V4L2_CID_DEINTERLACING_MODE:
motion = ctrl->val;
if (motion != priv->motion) {
if (priv->stream_count > 0) {
ret = -EBUSY;
goto out;
}
priv->motion = motion;
}
break;
default:
v4l2_err(&priv->sd, "Invalid control\n");
ret = -EINVAL;
}
out:
mutex_unlock(&priv->lock);
return ret;
}
static int vdic_init_controls(struct vdic_priv *priv)
{
struct v4l2_ctrl_handler *hdlr = &priv->ctrl_hdlr;
int ret;
v4l2_ctrl_handler_init(hdlr, 1);
v4l2_ctrl_new_std_menu_items(hdlr, &vdic_ctrl_ops,
V4L2_CID_DEINTERLACING_MODE,
HIGH_MOTION, 0, HIGH_MOTION,
vdic_ctrl_motion_menu);
priv->sd.ctrl_handler = hdlr;
if (hdlr->error) {
ret = hdlr->error;
goto out_free;
}
v4l2_ctrl_handler_setup(hdlr);
return 0;
out_free:
v4l2_ctrl_handler_free(hdlr);
return ret;
}
static int vdic_s_stream(struct v4l2_subdev *sd, int enable)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
struct v4l2_subdev *src_sd = NULL;
int ret = 0;
mutex_lock(&priv->lock);
if (!priv->src || !priv->sink_sd) {
ret = -EPIPE;
goto out;
}
if (priv->csi_direct)
src_sd = media_entity_to_v4l2_subdev(priv->src);
if (priv->stream_count != !enable)
goto update_count;
dev_dbg(priv->dev, "stream %s\n", enable ? "ON" : "OFF");
if (enable)
ret = vdic_start(priv);
else
vdic_stop(priv);
if (ret)
goto out;
if (src_sd) {
ret = v4l2_subdev_call(src_sd, video, s_stream, enable);
ret = (ret && ret != -ENOIOCTLCMD) ? ret : 0;
if (ret) {
if (enable)
vdic_stop(priv);
goto out;
}
}
update_count:
priv->stream_count += enable ? 1 : -1;
if (priv->stream_count < 0)
priv->stream_count = 0;
out:
mutex_unlock(&priv->lock);
return ret;
}
static struct v4l2_mbus_framefmt *
__vdic_get_fmt(struct vdic_priv *priv, struct v4l2_subdev_pad_config *cfg,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&priv->sd, cfg, pad);
else
return &priv->format_mbus[pad];
}
static int vdic_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad >= VDIC_NUM_PADS)
return -EINVAL;
return imx_media_enum_ipu_format(&code->code, code->index, CS_SEL_YUV);
}
static int vdic_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *fmt;
int ret = 0;
if (sdformat->pad >= VDIC_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
fmt = __vdic_get_fmt(priv, cfg, sdformat->pad, sdformat->which);
if (!fmt) {
ret = -EINVAL;
goto out;
}
sdformat->format = *fmt;
out:
mutex_unlock(&priv->lock);
return ret;
}
static void vdic_try_fmt(struct vdic_priv *priv,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat,
const struct imx_media_pixfmt **cc)
{
struct v4l2_mbus_framefmt *infmt;
*cc = imx_media_find_ipu_format(sdformat->format.code, CS_SEL_YUV);
if (!*cc) {
u32 code;
imx_media_enum_ipu_format(&code, 0, CS_SEL_YUV);
*cc = imx_media_find_ipu_format(code, CS_SEL_YUV);
sdformat->format.code = (*cc)->codes[0];
}
infmt = __vdic_get_fmt(priv, cfg, priv->active_input_pad,
sdformat->which);
switch (sdformat->pad) {
case VDIC_SRC_PAD_DIRECT:
sdformat->format = *infmt;
sdformat->format.field = V4L2_FIELD_NONE;
break;
case VDIC_SINK_PAD_DIRECT:
case VDIC_SINK_PAD_IDMAC:
v4l_bound_align_image(&sdformat->format.width,
MIN_W, MAX_W_VDIC, W_ALIGN,
&sdformat->format.height,
MIN_H, MAX_H_VDIC, H_ALIGN, S_ALIGN);
imx_media_fill_default_mbus_fields(&sdformat->format, infmt,
true);
if (!V4L2_FIELD_HAS_BOTH(sdformat->format.field))
sdformat->format.field = V4L2_FIELD_SEQ_TB;
break;
}
}
static int vdic_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
const struct imx_media_pixfmt *cc;
struct v4l2_mbus_framefmt *fmt;
int ret = 0;
if (sdformat->pad >= VDIC_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
if (priv->stream_count > 0) {
ret = -EBUSY;
goto out;
}
vdic_try_fmt(priv, cfg, sdformat, &cc);
fmt = __vdic_get_fmt(priv, cfg, sdformat->pad, sdformat->which);
*fmt = sdformat->format;
if (sdformat->pad == VDIC_SINK_PAD_DIRECT ||
sdformat->pad == VDIC_SINK_PAD_IDMAC) {
const struct imx_media_pixfmt *outcc;
struct v4l2_mbus_framefmt *outfmt;
struct v4l2_subdev_format format;
format.pad = VDIC_SRC_PAD_DIRECT;
format.which = sdformat->which;
format.format = sdformat->format;
vdic_try_fmt(priv, cfg, &format, &outcc);
outfmt = __vdic_get_fmt(priv, cfg, VDIC_SRC_PAD_DIRECT,
sdformat->which);
*outfmt = format.format;
if (sdformat->which == V4L2_SUBDEV_FORMAT_ACTIVE)
priv->cc[VDIC_SRC_PAD_DIRECT] = outcc;
}
if (sdformat->which == V4L2_SUBDEV_FORMAT_ACTIVE)
priv->cc[sdformat->pad] = cc;
out:
mutex_unlock(&priv->lock);
return ret;
}
static int vdic_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
struct v4l2_subdev *remote_sd;
int ret = 0;
dev_dbg(priv->dev, "link setup %s -> %s", remote->entity->name,
local->entity->name);
mutex_lock(&priv->lock);
if (local->flags & MEDIA_PAD_FL_SOURCE) {
if (!is_media_entity_v4l2_subdev(remote->entity)) {
ret = -EINVAL;
goto out;
}
remote_sd = media_entity_to_v4l2_subdev(remote->entity);
if (flags & MEDIA_LNK_FL_ENABLED) {
if (priv->sink_sd) {
ret = -EBUSY;
goto out;
}
priv->sink_sd = remote_sd;
} else {
priv->sink_sd = NULL;
}
goto out;
}
if (flags & MEDIA_LNK_FL_ENABLED) {
if (priv->src) {
ret = -EBUSY;
goto out;
}
} else {
priv->src = NULL;
goto out;
}
if (local->index == VDIC_SINK_PAD_IDMAC) {
struct imx_media_video_dev *vdev = priv->vdev;
if (!is_media_entity_v4l2_video_device(remote->entity)) {
ret = -EINVAL;
goto out;
}
if (!vdev) {
ret = -ENODEV;
goto out;
}
priv->csi_direct = false;
} else {
if (!is_media_entity_v4l2_subdev(remote->entity)) {
ret = -EINVAL;
goto out;
}
remote_sd = media_entity_to_v4l2_subdev(remote->entity);
if (!(remote_sd->grp_id & IMX_MEDIA_GRP_ID_CSI) ||
remote->index != CSI_SRC_PAD_DIRECT) {
ret = -EINVAL;
goto out;
}
priv->csi_direct = true;
}
priv->src = remote->entity;
priv->active_input_pad = local->index;
out:
mutex_unlock(&priv->lock);
return ret;
}
static int vdic_link_validate(struct v4l2_subdev *sd,
struct media_link *link,
struct v4l2_subdev_format *source_fmt,
struct v4l2_subdev_format *sink_fmt)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
int ret;
ret = v4l2_subdev_link_validate_default(sd, link,
source_fmt, sink_fmt);
if (ret)
return ret;
mutex_lock(&priv->lock);
if (priv->csi_direct && priv->motion != HIGH_MOTION) {
v4l2_err(&priv->sd,
"direct CSI pipeline requires high motion\n");
ret = -EINVAL;
}
mutex_unlock(&priv->lock);
return ret;
}
static int vdic_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
if (fi->pad >= VDIC_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
fi->interval = priv->frame_interval[fi->pad];
mutex_unlock(&priv->lock);
return 0;
}
static int vdic_s_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
struct v4l2_fract *input_fi, *output_fi;
int ret = 0;
mutex_lock(&priv->lock);
input_fi = &priv->frame_interval[priv->active_input_pad];
output_fi = &priv->frame_interval[VDIC_SRC_PAD_DIRECT];
switch (fi->pad) {
case VDIC_SINK_PAD_DIRECT:
case VDIC_SINK_PAD_IDMAC:
*output_fi = fi->interval;
if (priv->csi_direct)
output_fi->denominator *= 2;
break;
case VDIC_SRC_PAD_DIRECT:
fi->interval = *input_fi;
if (priv->csi_direct)
fi->interval.denominator *= 2;
break;
default:
ret = -EINVAL;
goto out;
}
priv->frame_interval[fi->pad] = fi->interval;
out:
mutex_unlock(&priv->lock);
return ret;
}
static int vdic_registered(struct v4l2_subdev *sd)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
int i, ret;
u32 code;
priv->md = dev_get_drvdata(sd->v4l2_dev->dev);
for (i = 0; i < VDIC_NUM_PADS; i++) {
priv->pad[i].flags = (i == VDIC_SRC_PAD_DIRECT) ?
MEDIA_PAD_FL_SOURCE : MEDIA_PAD_FL_SINK;
code = 0;
if (i != VDIC_SINK_PAD_IDMAC)
imx_media_enum_ipu_format(&code, 0, CS_SEL_YUV);
ret = imx_media_init_mbus_fmt(&priv->format_mbus[i],
640, 480, code, V4L2_FIELD_NONE,
&priv->cc[i]);
if (ret)
return ret;
priv->frame_interval[i].numerator = 1;
priv->frame_interval[i].denominator = 30;
if (i == VDIC_SRC_PAD_DIRECT)
priv->frame_interval[i].denominator *= 2;
}
priv->active_input_pad = VDIC_SINK_PAD_DIRECT;
ret = vdic_init_controls(priv);
if (ret)
return ret;
ret = media_entity_pads_init(&sd->entity, VDIC_NUM_PADS, priv->pad);
if (ret)
v4l2_ctrl_handler_free(&priv->ctrl_hdlr);
return ret;
}
static void vdic_unregistered(struct v4l2_subdev *sd)
{
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
v4l2_ctrl_handler_free(&priv->ctrl_hdlr);
}
static int imx_vdic_probe(struct platform_device *pdev)
{
struct imx_media_internal_sd_platformdata *pdata;
struct vdic_priv *priv;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, &priv->sd);
priv->dev = &pdev->dev;
pdata = priv->dev->platform_data;
priv->ipu_id = pdata->ipu_id;
v4l2_subdev_init(&priv->sd, &vdic_subdev_ops);
v4l2_set_subdevdata(&priv->sd, priv);
priv->sd.internal_ops = &vdic_internal_ops;
priv->sd.entity.ops = &vdic_entity_ops;
priv->sd.entity.function = MEDIA_ENT_F_PROC_VIDEO_PIXEL_FORMATTER;
priv->sd.dev = &pdev->dev;
priv->sd.owner = THIS_MODULE;
priv->sd.flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
priv->sd.grp_id = pdata->grp_id;
strncpy(priv->sd.name, pdata->sd_name, sizeof(priv->sd.name));
mutex_init(&priv->lock);
ret = v4l2_async_register_subdev(&priv->sd);
if (ret)
goto free;
return 0;
free:
mutex_destroy(&priv->lock);
return ret;
}
static int imx_vdic_remove(struct platform_device *pdev)
{
struct v4l2_subdev *sd = platform_get_drvdata(pdev);
struct vdic_priv *priv = v4l2_get_subdevdata(sd);
v4l2_info(sd, "Removing\n");
v4l2_async_unregister_subdev(sd);
mutex_destroy(&priv->lock);
media_entity_cleanup(&sd->entity);
return 0;
}
