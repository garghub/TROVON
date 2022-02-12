static inline struct prp_priv *sd_to_priv(struct v4l2_subdev *sd)
{
struct imx_ic_priv *ic_priv = v4l2_get_subdevdata(sd);
return ic_priv->prp_priv;
}
static int prp_start(struct prp_priv *priv)
{
struct imx_ic_priv *ic_priv = priv->ic_priv;
bool src_is_vdic;
priv->ipu = priv->md->ipu[ic_priv->ipu_id];
src_is_vdic = !!(priv->src_sd->grp_id & IMX_MEDIA_GRP_ID_VDIC);
ipu_set_ic_src_mux(priv->ipu, priv->csi_id, src_is_vdic);
return 0;
}
static void prp_stop(struct prp_priv *priv)
{
}
static struct v4l2_mbus_framefmt *
__prp_get_fmt(struct prp_priv *priv, struct v4l2_subdev_pad_config *cfg,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
struct imx_ic_priv *ic_priv = priv->ic_priv;
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&ic_priv->sd, cfg, pad);
else
return &priv->format_mbus;
}
static int prp_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct prp_priv *priv = sd_to_priv(sd);
struct v4l2_mbus_framefmt *infmt;
int ret = 0;
mutex_lock(&priv->lock);
switch (code->pad) {
case PRP_SINK_PAD:
ret = imx_media_enum_ipu_format(&code->code, code->index,
CS_SEL_ANY);
break;
case PRP_SRC_PAD_PRPENC:
case PRP_SRC_PAD_PRPVF:
if (code->index != 0) {
ret = -EINVAL;
goto out;
}
infmt = __prp_get_fmt(priv, cfg, PRP_SINK_PAD, code->which);
code->code = infmt->code;
break;
default:
ret = -EINVAL;
}
out:
mutex_unlock(&priv->lock);
return ret;
}
static int prp_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct prp_priv *priv = sd_to_priv(sd);
struct v4l2_mbus_framefmt *fmt;
int ret = 0;
if (sdformat->pad >= PRP_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
fmt = __prp_get_fmt(priv, cfg, sdformat->pad, sdformat->which);
if (!fmt) {
ret = -EINVAL;
goto out;
}
sdformat->format = *fmt;
out:
mutex_unlock(&priv->lock);
return ret;
}
static int prp_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct prp_priv *priv = sd_to_priv(sd);
struct v4l2_mbus_framefmt *fmt, *infmt;
const struct imx_media_pixfmt *cc;
int ret = 0;
u32 code;
if (sdformat->pad >= PRP_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
if (priv->stream_count > 0) {
ret = -EBUSY;
goto out;
}
infmt = __prp_get_fmt(priv, cfg, PRP_SINK_PAD, sdformat->which);
switch (sdformat->pad) {
case PRP_SINK_PAD:
v4l_bound_align_image(&sdformat->format.width, MIN_W, MAX_W,
W_ALIGN, &sdformat->format.height,
MIN_H, MAX_H, H_ALIGN, S_ALIGN);
cc = imx_media_find_ipu_format(sdformat->format.code,
CS_SEL_ANY);
if (!cc) {
imx_media_enum_ipu_format(&code, 0, CS_SEL_ANY);
cc = imx_media_find_ipu_format(code, CS_SEL_ANY);
sdformat->format.code = cc->codes[0];
}
imx_media_fill_default_mbus_fields(&sdformat->format, infmt,
true);
break;
case PRP_SRC_PAD_PRPENC:
case PRP_SRC_PAD_PRPVF:
sdformat->format = *infmt;
break;
}
fmt = __prp_get_fmt(priv, cfg, sdformat->pad, sdformat->which);
*fmt = sdformat->format;
out:
mutex_unlock(&priv->lock);
return ret;
}
static int prp_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct imx_ic_priv *ic_priv = v4l2_get_subdevdata(sd);
struct prp_priv *priv = ic_priv->prp_priv;
struct v4l2_subdev *remote_sd;
int ret = 0;
dev_dbg(ic_priv->dev, "link setup %s -> %s", remote->entity->name,
local->entity->name);
remote_sd = media_entity_to_v4l2_subdev(remote->entity);
mutex_lock(&priv->lock);
if (local->flags & MEDIA_PAD_FL_SINK) {
if (flags & MEDIA_LNK_FL_ENABLED) {
if (priv->src_sd) {
ret = -EBUSY;
goto out;
}
if (priv->sink_sd_prpenc && (remote_sd->grp_id &
IMX_MEDIA_GRP_ID_VDIC)) {
ret = -EINVAL;
goto out;
}
priv->src_sd = remote_sd;
} else {
priv->src_sd = NULL;
}
goto out;
}
if (flags & MEDIA_LNK_FL_ENABLED) {
switch (local->index) {
case PRP_SRC_PAD_PRPENC:
if (priv->sink_sd_prpenc) {
ret = -EBUSY;
goto out;
}
if (priv->src_sd && (priv->src_sd->grp_id &
IMX_MEDIA_GRP_ID_VDIC)) {
ret = -EINVAL;
goto out;
}
priv->sink_sd_prpenc = remote_sd;
break;
case PRP_SRC_PAD_PRPVF:
if (priv->sink_sd_prpvf) {
ret = -EBUSY;
goto out;
}
priv->sink_sd_prpvf = remote_sd;
break;
default:
ret = -EINVAL;
}
} else {
switch (local->index) {
case PRP_SRC_PAD_PRPENC:
priv->sink_sd_prpenc = NULL;
break;
case PRP_SRC_PAD_PRPVF:
priv->sink_sd_prpvf = NULL;
break;
default:
ret = -EINVAL;
}
}
out:
mutex_unlock(&priv->lock);
return ret;
}
static int prp_link_validate(struct v4l2_subdev *sd,
struct media_link *link,
struct v4l2_subdev_format *source_fmt,
struct v4l2_subdev_format *sink_fmt)
{
struct imx_ic_priv *ic_priv = v4l2_get_subdevdata(sd);
struct prp_priv *priv = ic_priv->prp_priv;
struct imx_media_subdev *csi;
int ret;
ret = v4l2_subdev_link_validate_default(sd, link,
source_fmt, sink_fmt);
if (ret)
return ret;
csi = imx_media_find_upstream_subdev(priv->md, &ic_priv->sd.entity,
IMX_MEDIA_GRP_ID_CSI);
if (IS_ERR(csi))
csi = NULL;
mutex_lock(&priv->lock);
if (priv->src_sd->grp_id & IMX_MEDIA_GRP_ID_VDIC) {
if (priv->sink_sd_prpenc)
ret = -EINVAL;
goto out;
} else {
if (!csi) {
ret = -EINVAL;
goto out;
}
}
if (csi) {
switch (csi->sd->grp_id) {
case IMX_MEDIA_GRP_ID_CSI0:
priv->csi_id = 0;
break;
case IMX_MEDIA_GRP_ID_CSI1:
priv->csi_id = 1;
break;
default:
ret = -EINVAL;
}
} else {
priv->csi_id = 0;
}
out:
mutex_unlock(&priv->lock);
return ret;
}
static int prp_s_stream(struct v4l2_subdev *sd, int enable)
{
struct imx_ic_priv *ic_priv = v4l2_get_subdevdata(sd);
struct prp_priv *priv = ic_priv->prp_priv;
int ret = 0;
mutex_lock(&priv->lock);
if (!priv->src_sd || (!priv->sink_sd_prpenc && !priv->sink_sd_prpvf)) {
ret = -EPIPE;
goto out;
}
if (priv->stream_count != !enable)
goto update_count;
dev_dbg(ic_priv->dev, "stream %s\n", enable ? "ON" : "OFF");
if (enable)
ret = prp_start(priv);
else
prp_stop(priv);
if (ret)
goto out;
ret = v4l2_subdev_call(priv->src_sd, video, s_stream, enable);
ret = (ret && ret != -ENOIOCTLCMD) ? ret : 0;
if (ret) {
if (enable)
prp_stop(priv);
goto out;
}
update_count:
priv->stream_count += enable ? 1 : -1;
if (priv->stream_count < 0)
priv->stream_count = 0;
out:
mutex_unlock(&priv->lock);
return ret;
}
static int prp_g_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct prp_priv *priv = sd_to_priv(sd);
if (fi->pad >= PRP_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
fi->interval = priv->frame_interval;
mutex_unlock(&priv->lock);
return 0;
}
static int prp_s_frame_interval(struct v4l2_subdev *sd,
struct v4l2_subdev_frame_interval *fi)
{
struct prp_priv *priv = sd_to_priv(sd);
if (fi->pad >= PRP_NUM_PADS)
return -EINVAL;
mutex_lock(&priv->lock);
priv->frame_interval = fi->interval;
mutex_unlock(&priv->lock);
return 0;
}
static int prp_registered(struct v4l2_subdev *sd)
{
struct prp_priv *priv = sd_to_priv(sd);
int i, ret;
u32 code;
priv->md = dev_get_drvdata(sd->v4l2_dev->dev);
for (i = 0; i < PRP_NUM_PADS; i++) {
priv->pad[i].flags = (i == PRP_SINK_PAD) ?
MEDIA_PAD_FL_SINK : MEDIA_PAD_FL_SOURCE;
}
priv->frame_interval.numerator = 1;
priv->frame_interval.denominator = 30;
imx_media_enum_ipu_format(&code, 0, CS_SEL_YUV);
ret = imx_media_init_mbus_fmt(&priv->format_mbus, 640, 480, code,
V4L2_FIELD_NONE, NULL);
if (ret)
return ret;
return media_entity_pads_init(&sd->entity, PRP_NUM_PADS, priv->pad);
}
static int prp_init(struct imx_ic_priv *ic_priv)
{
struct prp_priv *priv;
priv = devm_kzalloc(ic_priv->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mutex_init(&priv->lock);
ic_priv->prp_priv = priv;
priv->ic_priv = ic_priv;
return 0;
}
static void prp_remove(struct imx_ic_priv *ic_priv)
{
struct prp_priv *priv = ic_priv->prp_priv;
mutex_destroy(&priv->lock);
}
