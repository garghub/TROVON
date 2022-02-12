u32 atomisp_subdev_uncompressed_code(u32 code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(compressed_codes); i++)
if (code == compressed_codes[i].compressed)
return compressed_codes[i].code;
return code;
}
bool atomisp_subdev_is_compressed(u32 code)
{
int i;
for (i = 0; i < ARRAY_SIZE(atomisp_in_fmt_conv) - 1; i++)
if (code == atomisp_in_fmt_conv[i].code)
return atomisp_in_fmt_conv[i].bpp !=
atomisp_in_fmt_conv[i].depth;
return false;
}
const struct atomisp_in_fmt_conv *atomisp_find_in_fmt_conv(u32 code)
{
int i;
for (i = 0; i < ARRAY_SIZE(atomisp_in_fmt_conv) - 1; i++)
if (code == atomisp_in_fmt_conv[i].code)
return atomisp_in_fmt_conv + i;
return NULL;
}
const struct atomisp_in_fmt_conv *atomisp_find_in_fmt_conv_by_atomisp_in_fmt(
enum atomisp_css_stream_format atomisp_in_fmt)
{
int i;
for (i = 0; i < ARRAY_SIZE(atomisp_in_fmt_conv) - 1; i++)
if (atomisp_in_fmt_conv[i].atomisp_in_fmt == atomisp_in_fmt)
return atomisp_in_fmt_conv + i;
return NULL;
}
bool atomisp_subdev_format_conversion(struct atomisp_sub_device *asd,
unsigned int source_pad)
{
struct v4l2_mbus_framefmt *sink, *src;
sink = atomisp_subdev_get_ffmt(&asd->subdev, NULL,
V4L2_SUBDEV_FORMAT_ACTIVE,
ATOMISP_SUBDEV_PAD_SINK);
src = atomisp_subdev_get_ffmt(&asd->subdev, NULL,
V4L2_SUBDEV_FORMAT_ACTIVE, source_pad);
return atomisp_is_mbuscode_raw(sink->code)
&& !atomisp_is_mbuscode_raw(src->code);
}
uint16_t atomisp_subdev_source_pad(struct video_device * vdev)
{
struct media_link *link;
uint16_t ret = 0;
list_for_each_entry(link, &vdev->entity.links, list) {
if (link->source) {
ret = link->source->index;
break;
}
}
return ret;
}
static long isp_subdev_ioctl(struct v4l2_subdev *sd,
unsigned int cmd, void *arg)
{
return 0;
}
static int isp_subdev_set_power(struct v4l2_subdev *sd, int on)
{
return 0;
}
static int isp_subdev_subscribe_event(struct v4l2_subdev *sd,
struct v4l2_fh *fh,
struct v4l2_event_subscription *sub)
{
struct atomisp_sub_device *isp_sd = v4l2_get_subdevdata(sd);
struct atomisp_device *isp = isp_sd->isp;
if (sub->type != V4L2_EVENT_FRAME_SYNC &&
sub->type != V4L2_EVENT_FRAME_END &&
sub->type != V4L2_EVENT_ATOMISP_3A_STATS_READY &&
sub->type != V4L2_EVENT_ATOMISP_METADATA_READY &&
sub->type != V4L2_EVENT_ATOMISP_PAUSE_BUFFER &&
sub->type != V4L2_EVENT_ATOMISP_CSS_RESET &&
sub->type != V4L2_EVENT_ATOMISP_RAW_BUFFERS_ALLOC_DONE &&
sub->type != V4L2_EVENT_ATOMISP_ACC_COMPLETE)
return -EINVAL;
if (sub->type == V4L2_EVENT_FRAME_SYNC &&
!atomisp_css_valid_sof(isp))
return -EINVAL;
return v4l2_event_subscribe(fh, sub, 16, NULL);
}
static int isp_subdev_unsubscribe_event(struct v4l2_subdev *sd,
struct v4l2_fh *fh,
struct v4l2_event_subscription *sub)
{
return v4l2_event_unsubscribe(fh, sub);
}
static int isp_subdev_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index >= ARRAY_SIZE(atomisp_in_fmt_conv) - 1)
return -EINVAL;
code->code = atomisp_in_fmt_conv[code->index].code;
return 0;
}
static int isp_subdev_validate_rect(struct v4l2_subdev *sd, uint32_t pad,
uint32_t target)
{
switch (pad) {
case ATOMISP_SUBDEV_PAD_SINK:
switch (target) {
case V4L2_SEL_TGT_CROP:
return 0;
}
break;
default:
switch (target) {
case V4L2_SEL_TGT_COMPOSE:
return 0;
}
break;
}
return -EINVAL;
}
struct v4l2_rect *atomisp_subdev_get_rect(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
uint32_t which, uint32_t pad,
uint32_t target)
{
struct atomisp_sub_device *isp_sd = v4l2_get_subdevdata(sd);
if (which == V4L2_SUBDEV_FORMAT_TRY) {
switch (target) {
case V4L2_SEL_TGT_CROP:
return v4l2_subdev_get_try_crop(sd, cfg, pad);
case V4L2_SEL_TGT_COMPOSE:
return v4l2_subdev_get_try_compose(sd, cfg, pad);
}
}
switch (target) {
case V4L2_SEL_TGT_CROP:
return &isp_sd->fmt[pad].crop;
case V4L2_SEL_TGT_COMPOSE:
return &isp_sd->fmt[pad].compose;
}
return NULL;
}
struct v4l2_mbus_framefmt
*atomisp_subdev_get_ffmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg, uint32_t which,
uint32_t pad)
{
struct atomisp_sub_device *isp_sd = v4l2_get_subdevdata(sd);
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(sd, cfg, pad);
return &isp_sd->fmt[pad].fmt;
}
static void isp_get_fmt_rect(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg, uint32_t which,
struct v4l2_mbus_framefmt **ffmt,
struct v4l2_rect *crop[ATOMISP_SUBDEV_PADS_NUM],
struct v4l2_rect *comp[ATOMISP_SUBDEV_PADS_NUM])
{
unsigned int i;
for (i = 0; i < ATOMISP_SUBDEV_PADS_NUM; i++) {
ffmt[i] = atomisp_subdev_get_ffmt(sd, cfg, which, i);
crop[i] = atomisp_subdev_get_rect(sd, cfg, which, i,
V4L2_SEL_TGT_CROP);
comp[i] = atomisp_subdev_get_rect(sd, cfg, which, i,
V4L2_SEL_TGT_COMPOSE);
}
}
static void isp_subdev_propagate(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
uint32_t which, uint32_t pad, uint32_t target,
uint32_t flags)
{
struct v4l2_mbus_framefmt *ffmt[ATOMISP_SUBDEV_PADS_NUM];
struct v4l2_rect *crop[ATOMISP_SUBDEV_PADS_NUM],
*comp[ATOMISP_SUBDEV_PADS_NUM];
if (flags & V4L2_SEL_FLAG_KEEP_CONFIG)
return;
isp_get_fmt_rect(sd, cfg, which, ffmt, crop, comp);
switch (pad) {
case ATOMISP_SUBDEV_PAD_SINK: {
struct v4l2_rect r = {0};
r.width = ffmt[pad]->width;
r.height = ffmt[pad]->height;
atomisp_subdev_set_selection(sd, cfg, which, pad,
target, flags, &r);
break;
}
}
}
static int isp_subdev_get_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
struct v4l2_rect *rec;
int rval = isp_subdev_validate_rect(sd, sel->pad, sel->target);
if (rval)
return rval;
rec = atomisp_subdev_get_rect(sd, cfg, sel->which, sel->pad,
sel->target);
if (!rec)
return -EINVAL;
sel->r = *rec;
return 0;
}
int atomisp_subdev_set_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
uint32_t which, uint32_t pad, uint32_t target,
uint32_t flags, struct v4l2_rect *r)
{
struct atomisp_sub_device *isp_sd = v4l2_get_subdevdata(sd);
struct atomisp_device *isp = isp_sd->isp;
struct v4l2_mbus_framefmt *ffmt[ATOMISP_SUBDEV_PADS_NUM];
uint16_t vdev_pad = atomisp_subdev_source_pad(sd->devnode);
struct v4l2_rect *crop[ATOMISP_SUBDEV_PADS_NUM],
*comp[ATOMISP_SUBDEV_PADS_NUM];
enum atomisp_input_stream_id stream_id;
unsigned int i;
unsigned int padding_w = pad_w;
unsigned int padding_h = pad_h;
stream_id = atomisp_source_pad_to_stream_id(isp_sd, vdev_pad);
isp_get_fmt_rect(sd, cfg, which, ffmt, crop, comp);
dev_dbg(isp->dev,
"sel: pad %s tgt %s l %d t %d w %d h %d which %s f 0x%8.8x\n",
atomisp_pad_str[pad], target == V4L2_SEL_TGT_CROP
? "V4L2_SEL_TGT_CROP" : "V4L2_SEL_TGT_COMPOSE",
r->left, r->top, r->width, r->height,
which == V4L2_SUBDEV_FORMAT_TRY ? "V4L2_SUBDEV_FORMAT_TRY"
: "V4L2_SUBDEV_FORMAT_ACTIVE", flags);
r->width = rounddown(r->width, ATOM_ISP_STEP_WIDTH);
r->height = rounddown(r->height, ATOM_ISP_STEP_HEIGHT);
switch (pad) {
case ATOMISP_SUBDEV_PAD_SINK: {
unsigned int dvs_w, dvs_h;
crop[pad]->width = ffmt[pad]->width;
crop[pad]->height = ffmt[pad]->height;
if (!strncmp(isp->inputs[isp_sd->input_curr].camera->name,
"ov2722", 6) && crop[pad]->height == 1092) {
padding_w = 12;
padding_h = 12;
}
if (isp->inputs[isp_sd->input_curr].type == SOC_CAMERA) {
padding_w = 0;
padding_h = 0;
}
if (atomisp_subdev_format_conversion(isp_sd,
isp_sd->capture_pad)
&& crop[pad]->width && crop[pad]->height)
crop[pad]->width -= padding_w, crop[pad]->height -= padding_h;
if (isp->inputs[isp_sd->input_curr].type == SOC_CAMERA)
isp_sd->params.video_dis_en = 0;
if (isp_sd->params.video_dis_en &&
isp_sd->run_mode->val == ATOMISP_RUN_MODE_VIDEO &&
!isp_sd->continuous_mode->val) {
crop[pad]->width = roundup(crop[pad]->width * 5 / 6,
ATOM_ISP_STEP_WIDTH);
crop[pad]->height = roundup(crop[pad]->height * 5 / 6,
ATOM_ISP_STEP_HEIGHT);
}
crop[pad]->width = min(crop[pad]->width, r->width);
crop[pad]->height = min(crop[pad]->height, r->height);
if (!(flags & V4L2_SEL_FLAG_KEEP_CONFIG)) {
for (i = ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE;
i < ATOMISP_SUBDEV_PADS_NUM; i++) {
struct v4l2_rect tmp = *crop[pad];
atomisp_subdev_set_selection(
sd, cfg, which, i, V4L2_SEL_TGT_COMPOSE,
flags, &tmp);
}
}
if (which == V4L2_SUBDEV_FORMAT_TRY)
break;
if (isp_sd->params.video_dis_en &&
isp_sd->run_mode->val == ATOMISP_RUN_MODE_VIDEO &&
!isp_sd->continuous_mode->val) {
dvs_w = rounddown(crop[pad]->width / 5,
ATOM_ISP_STEP_WIDTH);
dvs_h = rounddown(crop[pad]->height / 5,
ATOM_ISP_STEP_HEIGHT);
} else if (!isp_sd->params.video_dis_en &&
isp_sd->run_mode->val == ATOMISP_RUN_MODE_VIDEO) {
dvs_w = dvs_h = 12;
} else
dvs_w = dvs_h = 0;
atomisp_css_video_set_dis_envelope(isp_sd, dvs_w, dvs_h);
atomisp_css_input_set_effective_resolution(isp_sd, stream_id,
crop[pad]->width, crop[pad]->height);
break;
}
case ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE:
case ATOMISP_SUBDEV_PAD_SOURCE_VIDEO: {
if (isp_sd->vfpp->val == ATOMISP_VFPP_DISABLE_LOWLAT) {
r->width = crop[ATOMISP_SUBDEV_PAD_SINK]->width;
r->height = crop[ATOMISP_SUBDEV_PAD_SINK]->height;
}
if (crop[ATOMISP_SUBDEV_PAD_SINK]->width == r->width
&& crop[ATOMISP_SUBDEV_PAD_SINK]->height == r->height)
isp_sd->params.yuv_ds_en = false;
else
isp_sd->params.yuv_ds_en = true;
comp[pad]->width = r->width;
comp[pad]->height = r->height;
if (r->width == 0 || r->height == 0 ||
crop[ATOMISP_SUBDEV_PAD_SINK]->width == 0 ||
crop[ATOMISP_SUBDEV_PAD_SINK]->height == 0)
break;
if (r->width * crop[ATOMISP_SUBDEV_PAD_SINK]->height <
crop[ATOMISP_SUBDEV_PAD_SINK]->width * r->height)
atomisp_css_input_set_effective_resolution(isp_sd,
stream_id,
rounddown(crop[ATOMISP_SUBDEV_PAD_SINK]->
height * r->width / r->height,
ATOM_ISP_STEP_WIDTH),
crop[ATOMISP_SUBDEV_PAD_SINK]->height);
else
atomisp_css_input_set_effective_resolution(isp_sd,
stream_id,
crop[ATOMISP_SUBDEV_PAD_SINK]->width,
rounddown(crop[ATOMISP_SUBDEV_PAD_SINK]->
width * r->height / r->width,
ATOM_ISP_STEP_WIDTH));
break;
}
case ATOMISP_SUBDEV_PAD_SOURCE_VF:
case ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW:
comp[pad]->width = r->width;
comp[pad]->height = r->height;
break;
default:
return -EINVAL;
}
if (pad != ATOMISP_SUBDEV_PAD_SINK) {
ffmt[pad]->width = comp[pad]->width;
ffmt[pad]->height = comp[pad]->height;
}
if (!atomisp_subdev_get_rect(sd, cfg, which, pad, target))
return -EINVAL;
*r = *atomisp_subdev_get_rect(sd, cfg, which, pad, target);
dev_dbg(isp->dev, "sel actual: l %d t %d w %d h %d\n",
r->left, r->top, r->width, r->height);
return 0;
}
static int isp_subdev_set_selection(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_selection *sel)
{
int rval = isp_subdev_validate_rect(sd, sel->pad, sel->target);
if (rval)
return rval;
return atomisp_subdev_set_selection(sd, cfg, sel->which, sel->pad,
sel->target, sel->flags, &sel->r);
}
static int atomisp_get_sensor_bin_factor(struct atomisp_sub_device *asd)
{
struct v4l2_control ctrl = {0};
struct atomisp_device *isp = asd->isp;
int hbin, vbin;
int ret;
if (isp->inputs[asd->input_curr].type == FILE_INPUT ||
isp->inputs[asd->input_curr].type == TEST_PATTERN)
return 0;
ctrl.id = V4L2_CID_BIN_FACTOR_HORZ;
ret =
v4l2_g_ctrl(isp->inputs[asd->input_curr].camera->ctrl_handler,
&ctrl);
hbin = ctrl.value;
ctrl.id = V4L2_CID_BIN_FACTOR_VERT;
ret |=
v4l2_g_ctrl(isp->inputs[asd->input_curr].camera->ctrl_handler,
&ctrl);
vbin = ctrl.value;
if (ret || hbin != vbin)
hbin = 0;
return hbin;
}
void atomisp_subdev_set_ffmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg, uint32_t which,
uint32_t pad, struct v4l2_mbus_framefmt *ffmt)
{
struct atomisp_sub_device *isp_sd = v4l2_get_subdevdata(sd);
struct atomisp_device *isp = isp_sd->isp;
struct v4l2_mbus_framefmt *__ffmt =
atomisp_subdev_get_ffmt(sd, cfg, which, pad);
uint16_t vdev_pad = atomisp_subdev_source_pad(sd->devnode);
enum atomisp_input_stream_id stream_id;
dev_dbg(isp->dev, "ffmt: pad %s w %d h %d code 0x%8.8x which %s\n",
atomisp_pad_str[pad], ffmt->width, ffmt->height, ffmt->code,
which == V4L2_SUBDEV_FORMAT_TRY ? "V4L2_SUBDEV_FORMAT_TRY"
: "V4L2_SUBDEV_FORMAT_ACTIVE");
stream_id = atomisp_source_pad_to_stream_id(isp_sd, vdev_pad);
switch (pad) {
case ATOMISP_SUBDEV_PAD_SINK: {
const struct atomisp_in_fmt_conv *fc =
atomisp_find_in_fmt_conv(ffmt->code);
if (!fc) {
fc = atomisp_in_fmt_conv;
ffmt->code = fc->code;
dev_dbg(isp->dev, "using 0x%8.8x instead\n",
ffmt->code);
}
*__ffmt = *ffmt;
isp_subdev_propagate(sd, cfg, which, pad,
V4L2_SEL_TGT_CROP, 0);
if (which == V4L2_SUBDEV_FORMAT_ACTIVE) {
atomisp_css_input_set_resolution(isp_sd,
stream_id, ffmt);
atomisp_css_input_set_binning_factor(isp_sd,
stream_id,
atomisp_get_sensor_bin_factor(isp_sd));
atomisp_css_input_set_bayer_order(isp_sd, stream_id,
fc->bayer_order);
atomisp_css_input_set_format(isp_sd, stream_id,
fc->css_stream_fmt);
atomisp_css_set_default_isys_config(isp_sd, stream_id,
ffmt);
}
break;
}
case ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE:
case ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW:
case ATOMISP_SUBDEV_PAD_SOURCE_VF:
case ATOMISP_SUBDEV_PAD_SOURCE_VIDEO:
__ffmt->code = ffmt->code;
break;
}
}
static int isp_subdev_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
fmt->format = *atomisp_subdev_get_ffmt(sd, cfg, fmt->which, fmt->pad);
return 0;
}
static int isp_subdev_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
atomisp_subdev_set_ffmt(sd, cfg, fmt->which, fmt->pad, &fmt->format);
return 0;
}
static void isp_subdev_init_params(struct atomisp_sub_device *asd)
{
unsigned int i;
INIT_LIST_HEAD(&asd->s3a_stats);
INIT_LIST_HEAD(&asd->s3a_stats_in_css);
INIT_LIST_HEAD(&asd->s3a_stats_ready);
INIT_LIST_HEAD(&asd->dis_stats);
INIT_LIST_HEAD(&asd->dis_stats_in_css);
spin_lock_init(&asd->dis_stats_lock);
for (i = 0; i < ATOMISP_METADATA_TYPE_NUM; i++) {
INIT_LIST_HEAD(&asd->metadata[i]);
INIT_LIST_HEAD(&asd->metadata_in_css[i]);
INIT_LIST_HEAD(&asd->metadata_ready[i]);
}
}
static int isp_subdev_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct atomisp_sub_device *isp_sd = v4l2_get_subdevdata(sd);
struct atomisp_device *isp = isp_sd->isp;
unsigned int i;
switch (local->index | is_media_entity_v4l2_subdev(remote->entity)) {
case ATOMISP_SUBDEV_PAD_SINK | MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN:
if (!(flags & MEDIA_LNK_FL_ENABLED)) {
isp_sd->input = ATOMISP_SUBDEV_INPUT_NONE;
break;
}
if (isp_sd->input != ATOMISP_SUBDEV_INPUT_NONE)
return -EBUSY;
for (i = 0; i < ATOMISP_CAMERA_NR_PORTS; i++) {
if (remote->entity != &isp->csi2_port[i].subdev.entity)
continue;
isp_sd->input = ATOMISP_SUBDEV_INPUT_CSI2_PORT1 + i;
return 0;
}
return -EINVAL;
case ATOMISP_SUBDEV_PAD_SINK | MEDIA_ENT_F_OLD_BASE:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (isp_sd->input >= ATOMISP_SUBDEV_INPUT_CSI2_PORT1 &&
isp_sd->input < (ATOMISP_SUBDEV_INPUT_CSI2_PORT1
+ ATOMISP_CAMERA_NR_PORTS))
return -EBUSY;
isp_sd->input = ATOMISP_SUBDEV_INPUT_MEMORY;
} else {
if (isp_sd->input == ATOMISP_SUBDEV_INPUT_MEMORY)
isp_sd->input = ATOMISP_SUBDEV_INPUT_NONE;
}
break;
case ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW | MEDIA_ENT_F_OLD_BASE:
break;
case ATOMISP_SUBDEV_PAD_SOURCE_VF | MEDIA_ENT_F_OLD_BASE:
break;
case ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE | MEDIA_ENT_F_OLD_BASE:
break;
case ATOMISP_SUBDEV_PAD_SOURCE_VIDEO | MEDIA_ENT_F_OLD_BASE:
break;
default:
return -EINVAL;
}
return 0;
}
static int __atomisp_update_run_mode(struct atomisp_sub_device *asd)
{
struct atomisp_device *isp = asd->isp;
struct v4l2_ctrl *ctrl = asd->run_mode;
struct v4l2_ctrl *c;
struct v4l2_streamparm p = {0};
int modes[] = { CI_MODE_NONE,
CI_MODE_VIDEO,
CI_MODE_STILL_CAPTURE,
CI_MODE_CONTINUOUS,
CI_MODE_PREVIEW };
s32 mode;
if (ctrl->val != ATOMISP_RUN_MODE_VIDEO &&
asd->continuous_mode->val)
mode = ATOMISP_RUN_MODE_PREVIEW;
else
mode = ctrl->val;
c = v4l2_ctrl_find(
isp->inputs[asd->input_curr].camera->ctrl_handler,
V4L2_CID_RUN_MODE);
if (c)
return v4l2_ctrl_s_ctrl(c, mode);
p.parm.capture.capturemode = modes[mode];
return v4l2_subdev_call(
isp->inputs[asd->input_curr].camera, video, s_parm, &p);
}
int atomisp_update_run_mode(struct atomisp_sub_device *asd)
{
int rval;
mutex_lock(asd->ctrl_handler.lock);
rval = __atomisp_update_run_mode(asd);
mutex_unlock(asd->ctrl_handler.lock);
return rval;
}
static int s_ctrl(struct v4l2_ctrl *ctrl)
{
struct atomisp_sub_device *asd = container_of(
ctrl->handler, struct atomisp_sub_device, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_RUN_MODE:
return __atomisp_update_run_mode(asd);
case V4L2_CID_DEPTH_MODE:
if (asd->streaming != ATOMISP_DEVICE_STREAMING_DISABLED) {
dev_err(asd->isp->dev, "ISP is streaming, it is not supported to change the depth mode\n");
return -EINVAL;
}
break;
}
return 0;
}
static void atomisp_init_subdev_pipe(struct atomisp_sub_device *asd,
struct atomisp_video_pipe *pipe, enum v4l2_buf_type buf_type)
{
pipe->type = buf_type;
pipe->asd = asd;
pipe->isp = asd->isp;
spin_lock_init(&pipe->irq_lock);
INIT_LIST_HEAD(&pipe->activeq);
INIT_LIST_HEAD(&pipe->activeq_out);
INIT_LIST_HEAD(&pipe->buffers_waiting_for_param);
INIT_LIST_HEAD(&pipe->per_frame_params);
memset(pipe->frame_request_config_id,
0, VIDEO_MAX_FRAME * sizeof(unsigned int));
memset(pipe->frame_params,
0, VIDEO_MAX_FRAME *
sizeof(struct atomisp_css_params_with_list *));
}
static void atomisp_init_acc_pipe(struct atomisp_sub_device *asd,
struct atomisp_acc_pipe *pipe)
{
pipe->asd = asd;
pipe->isp = asd->isp;
INIT_LIST_HEAD(&asd->acc.fw);
INIT_LIST_HEAD(&asd->acc.memory_maps);
ida_init(&asd->acc.ida);
}
static int isp_subdev_init_entities(struct atomisp_sub_device *asd)
{
struct v4l2_subdev *sd = &asd->subdev;
struct media_pad *pads = asd->pads;
struct media_entity *me = &sd->entity;
int ret;
asd->input = ATOMISP_SUBDEV_INPUT_NONE;
v4l2_subdev_init(sd, &isp_subdev_v4l2_ops);
sprintf(sd->name, "ATOMISP_SUBDEV_%d", asd->index);
v4l2_set_subdevdata(sd, asd);
sd->flags |= V4L2_SUBDEV_FL_HAS_EVENTS | V4L2_SUBDEV_FL_HAS_DEVNODE;
pads[ATOMISP_SUBDEV_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW].flags = MEDIA_PAD_FL_SOURCE;
pads[ATOMISP_SUBDEV_PAD_SOURCE_VF].flags = MEDIA_PAD_FL_SOURCE;
pads[ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE].flags = MEDIA_PAD_FL_SOURCE;
pads[ATOMISP_SUBDEV_PAD_SOURCE_VIDEO].flags = MEDIA_PAD_FL_SOURCE;
asd->fmt[ATOMISP_SUBDEV_PAD_SINK].fmt.code =
MEDIA_BUS_FMT_SBGGR10_1X10;
asd->fmt[ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW].fmt.code =
MEDIA_BUS_FMT_SBGGR10_1X10;
asd->fmt[ATOMISP_SUBDEV_PAD_SOURCE_VF].fmt.code =
MEDIA_BUS_FMT_SBGGR10_1X10;
asd->fmt[ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE].fmt.code =
MEDIA_BUS_FMT_SBGGR10_1X10;
asd->fmt[ATOMISP_SUBDEV_PAD_SOURCE_VIDEO].fmt.code =
MEDIA_BUS_FMT_SBGGR10_1X10;
me->ops = &isp_subdev_media_ops;
me->function = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
ret = media_entity_pads_init(me, ATOMISP_SUBDEV_PADS_NUM, pads);
if (ret < 0)
return ret;
atomisp_init_subdev_pipe(asd, &asd->video_in,
V4L2_BUF_TYPE_VIDEO_OUTPUT);
atomisp_init_subdev_pipe(asd, &asd->video_out_preview,
V4L2_BUF_TYPE_VIDEO_CAPTURE);
atomisp_init_subdev_pipe(asd, &asd->video_out_vf,
V4L2_BUF_TYPE_VIDEO_CAPTURE);
atomisp_init_subdev_pipe(asd, &asd->video_out_capture,
V4L2_BUF_TYPE_VIDEO_CAPTURE);
atomisp_init_subdev_pipe(asd, &asd->video_out_video_capture,
V4L2_BUF_TYPE_VIDEO_CAPTURE);
atomisp_init_acc_pipe(asd, &asd->video_acc);
ret = atomisp_video_init(&asd->video_in, "MEMORY");
if (ret < 0)
return ret;
ret = atomisp_video_init(&asd->video_out_capture, "CAPTURE");
if (ret < 0)
return ret;
ret = atomisp_video_init(&asd->video_out_vf, "VIEWFINDER");
if (ret < 0)
return ret;
ret = atomisp_video_init(&asd->video_out_preview, "PREVIEW");
if (ret < 0)
return ret;
ret = atomisp_video_init(&asd->video_out_video_capture, "VIDEO");
if (ret < 0)
return ret;
atomisp_acc_init(&asd->video_acc, "ACC");
ret = v4l2_ctrl_handler_init(&asd->ctrl_handler, 1);
if (ret)
return ret;
asd->fmt_auto = v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_fmt_auto, NULL);
asd->run_mode = v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_run_mode, NULL);
asd->vfpp = v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_vfpp, NULL);
asd->continuous_mode = v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_continuous_mode, NULL);
asd->continuous_viewfinder = v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_continuous_viewfinder,
NULL);
asd->continuous_raw_buffer_size =
v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_continuous_raw_buffer_size,
NULL);
asd->enable_raw_buffer_lock =
v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_enable_raw_buffer_lock,
NULL);
asd->depth_mode =
v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_depth_mode,
NULL);
asd->disable_dz =
v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_disable_dz,
NULL);
#ifdef ISP2401
asd->select_isp_version =
v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_select_isp_version,
NULL);
#ifdef CONFIG_ION
asd->ion_dev_fd =
v4l2_ctrl_new_custom(&asd->ctrl_handler,
&ctrl_ion_dev_fd,
NULL);
#endif
#endif
asd->subdev.ctrl_handler = &asd->ctrl_handler;
spin_lock_init(&asd->raw_buffer_bitmap_lock);
return asd->ctrl_handler.error;
}
int atomisp_create_pads_links(struct atomisp_device *isp)
{
struct atomisp_sub_device *asd;
int i, j, ret = 0;
isp->num_of_streams = 2;
for (i = 0; i < ATOMISP_CAMERA_NR_PORTS; i++) {
for (j = 0; j < isp->num_of_streams; j++) {
ret =
media_create_pad_link(&isp->csi2_port[i].subdev.
entity, CSI2_PAD_SOURCE,
&isp->asd[j].subdev.entity,
ATOMISP_SUBDEV_PAD_SINK, 0);
if (ret < 0)
return ret;
}
}
for (i = 0; i < isp->input_cnt - 2; i++) {
ret = media_create_pad_link(&isp->inputs[i].camera->entity, 0,
&isp->csi2_port[isp->inputs[i].
port].subdev.entity,
CSI2_PAD_SINK,
MEDIA_LNK_FL_ENABLED |
MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
return ret;
}
for (i = 0; i < isp->num_of_streams; i++) {
asd = &isp->asd[i];
ret = media_create_pad_link(&asd->subdev.entity,
ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW,
&asd->video_out_preview.vdev.entity,
0, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(&asd->subdev.entity,
ATOMISP_SUBDEV_PAD_SOURCE_VF,
&asd->video_out_vf.vdev.entity, 0,
0);
if (ret < 0)
return ret;
ret = media_create_pad_link(&asd->subdev.entity,
ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE,
&asd->video_out_capture.vdev.entity,
0, 0);
if (ret < 0)
return ret;
ret = media_create_pad_link(&asd->subdev.entity,
ATOMISP_SUBDEV_PAD_SOURCE_VIDEO,
&asd->video_out_video_capture.vdev.
entity, 0, 0);
if (ret < 0)
return ret;
if (asd->index)
return 0;
ret = media_create_pad_link(&asd->video_in.vdev.entity,
0, &asd->subdev.entity,
ATOMISP_SUBDEV_PAD_SINK, 0);
if (ret < 0)
return ret;
}
return 0;
}
static void atomisp_subdev_cleanup_entities(struct atomisp_sub_device *asd)
{
v4l2_ctrl_handler_free(&asd->ctrl_handler);
media_entity_cleanup(&asd->subdev.entity);
}
void atomisp_subdev_cleanup_pending_events(struct atomisp_sub_device *asd)
{
struct v4l2_fh *fh, *fh_tmp;
struct v4l2_event event;
unsigned int i, pending_event;
list_for_each_entry_safe(fh, fh_tmp,
&asd->subdev.devnode->fh_list, list) {
pending_event = v4l2_event_pending(fh);
for (i = 0; i < pending_event; i++)
v4l2_event_dequeue(fh, &event, 1);
}
}
void atomisp_subdev_unregister_entities(struct atomisp_sub_device *asd)
{
atomisp_subdev_cleanup_entities(asd);
v4l2_device_unregister_subdev(&asd->subdev);
atomisp_video_unregister(&asd->video_in);
atomisp_video_unregister(&asd->video_out_preview);
atomisp_video_unregister(&asd->video_out_vf);
atomisp_video_unregister(&asd->video_out_capture);
atomisp_video_unregister(&asd->video_out_video_capture);
atomisp_acc_unregister(&asd->video_acc);
}
int atomisp_subdev_register_entities(struct atomisp_sub_device *asd,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &asd->subdev);
if (ret < 0)
goto error;
ret = atomisp_video_register(&asd->video_out_capture, vdev);
if (ret < 0)
goto error;
ret = atomisp_video_register(&asd->video_out_vf, vdev);
if (ret < 0)
goto error;
ret = atomisp_video_register(&asd->video_out_preview, vdev);
if (ret < 0)
goto error;
ret = atomisp_video_register(&asd->video_out_video_capture, vdev);
if (ret < 0)
goto error;
ret = atomisp_acc_register(&asd->video_acc, vdev);
if (ret < 0)
goto error;
if (asd->index)
return 0;
ret = atomisp_video_register(&asd->video_in, vdev);
if (ret < 0)
goto error;
return 0;
error:
atomisp_subdev_unregister_entities(asd);
return ret;
}
int atomisp_subdev_init(struct atomisp_device *isp)
{
struct atomisp_sub_device *asd;
int i, ret = 0;
isp->num_of_streams = 2;
isp->asd = devm_kzalloc(isp->dev, sizeof(struct atomisp_sub_device) *
isp->num_of_streams, GFP_KERNEL);
if (!isp->asd)
return -ENOMEM;
for (i = 0; i < isp->num_of_streams; i++) {
asd = &isp->asd[i];
spin_lock_init(&asd->lock);
asd->isp = isp;
isp_subdev_init_params(asd);
asd->index = i;
ret = isp_subdev_init_entities(asd);
if (ret < 0) {
atomisp_subdev_cleanup_entities(asd);
break;
}
}
return ret;
}
