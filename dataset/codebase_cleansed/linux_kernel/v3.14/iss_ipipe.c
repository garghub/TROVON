static void ipipe_print_status(struct iss_ipipe_device *ipipe)
{
struct iss_device *iss = to_iss_device(ipipe);
dev_dbg(iss->dev, "-------------IPIPE Register dump-------------\n");
IPIPE_PRINT_REGISTER(iss, SRC_EN);
IPIPE_PRINT_REGISTER(iss, SRC_MODE);
IPIPE_PRINT_REGISTER(iss, SRC_FMT);
IPIPE_PRINT_REGISTER(iss, SRC_COL);
IPIPE_PRINT_REGISTER(iss, SRC_VPS);
IPIPE_PRINT_REGISTER(iss, SRC_VSZ);
IPIPE_PRINT_REGISTER(iss, SRC_HPS);
IPIPE_PRINT_REGISTER(iss, SRC_HSZ);
IPIPE_PRINT_REGISTER(iss, GCK_MMR);
IPIPE_PRINT_REGISTER(iss, YUV_PHS);
dev_dbg(iss->dev, "-----------------------------------------------\n");
}
static void ipipe_enable(struct iss_ipipe_device *ipipe, u8 enable)
{
struct iss_device *iss = to_iss_device(ipipe);
iss_reg_update(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_EN,
IPIPE_SRC_EN_EN, enable ? IPIPE_SRC_EN_EN : 0);
}
static void ipipe_configure(struct iss_ipipe_device *ipipe)
{
struct iss_device *iss = to_iss_device(ipipe);
struct v4l2_mbus_framefmt *format;
format = &ipipe->formats[IPIPE_PAD_SINK];
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_FMT,
IPIPE_SRC_FMT_RAW2YUV);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_YUV_PHS,
IPIPE_YUV_PHS_LPF);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_VPS, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_HPS, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_VSZ,
(format->height - 2) & IPIPE_SRC_VSZ_MASK);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_HSZ,
(format->width - 1) & IPIPE_SRC_HSZ_MASK);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_MODE,
IPIPE_SRC_MODE_WRT | IPIPE_SRC_MODE_OST);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_SRC_COL,
IPIPE_SRC_COL_EE_B | IPIPE_SRC_COL_EO_GB |
IPIPE_SRC_COL_OE_GR | IPIPE_SRC_COL_OO_R);
format = &ipipe->formats[IPIPE_PAD_SOURCE_VP];
}
static int ipipe_set_stream(struct v4l2_subdev *sd, int enable)
{
struct iss_ipipe_device *ipipe = v4l2_get_subdevdata(sd);
struct iss_device *iss = to_iss_device(ipipe);
int ret = 0;
if (ipipe->state == ISS_PIPELINE_STREAM_STOPPED) {
if (enable == ISS_PIPELINE_STREAM_STOPPED)
return 0;
omap4iss_isp_subclk_enable(iss, OMAP4_ISS_ISP_SUBCLK_IPIPE);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_GCK_MMR,
IPIPE_GCK_MMR_REG);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_IPIPE, IPIPE_GCK_PIX,
IPIPE_GCK_PIX_G3 | IPIPE_GCK_PIX_G2 |
IPIPE_GCK_PIX_G1 | IPIPE_GCK_PIX_G0);
}
switch (enable) {
case ISS_PIPELINE_STREAM_CONTINUOUS:
ipipe_configure(ipipe);
ipipe_print_status(ipipe);
atomic_set(&ipipe->stopping, 0);
ipipe_enable(ipipe, 1);
break;
case ISS_PIPELINE_STREAM_STOPPED:
if (ipipe->state == ISS_PIPELINE_STREAM_STOPPED)
return 0;
if (omap4iss_module_sync_idle(&sd->entity, &ipipe->wait,
&ipipe->stopping))
ret = -ETIMEDOUT;
ipipe_enable(ipipe, 0);
omap4iss_isp_subclk_disable(iss, OMAP4_ISS_ISP_SUBCLK_IPIPE);
break;
}
ipipe->state = enable;
return ret;
}
static struct v4l2_mbus_framefmt *
__ipipe_get_format(struct iss_ipipe_device *ipipe, struct v4l2_subdev_fh *fh,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(fh, pad);
else
return &ipipe->formats[pad];
}
static void
ipipe_try_format(struct iss_ipipe_device *ipipe, struct v4l2_subdev_fh *fh,
unsigned int pad, struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
struct v4l2_mbus_framefmt *format;
unsigned int width = fmt->width;
unsigned int height = fmt->height;
unsigned int i;
switch (pad) {
case IPIPE_PAD_SINK:
for (i = 0; i < ARRAY_SIZE(ipipe_fmts); i++) {
if (fmt->code == ipipe_fmts[i])
break;
}
if (i >= ARRAY_SIZE(ipipe_fmts))
fmt->code = V4L2_MBUS_FMT_SGRBG10_1X10;
fmt->width = clamp_t(u32, width, 1, 8192);
fmt->height = clamp_t(u32, height, 1, 8192);
fmt->colorspace = V4L2_COLORSPACE_SRGB;
break;
case IPIPE_PAD_SOURCE_VP:
format = __ipipe_get_format(ipipe, fh, IPIPE_PAD_SINK, which);
memcpy(fmt, format, sizeof(*fmt));
fmt->code = V4L2_MBUS_FMT_UYVY8_1X16;
fmt->width = clamp_t(u32, width, 32, fmt->width);
fmt->height = clamp_t(u32, height, 32, fmt->height);
fmt->colorspace = V4L2_COLORSPACE_JPEG;
break;
}
fmt->field = V4L2_FIELD_NONE;
}
static int ipipe_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
switch (code->pad) {
case IPIPE_PAD_SINK:
if (code->index >= ARRAY_SIZE(ipipe_fmts))
return -EINVAL;
code->code = ipipe_fmts[code->index];
break;
case IPIPE_PAD_SOURCE_VP:
if (code->index != 0)
return -EINVAL;
code->code = V4L2_MBUS_FMT_UYVY8_1X16;
break;
default:
return -EINVAL;
}
return 0;
}
static int ipipe_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct iss_ipipe_device *ipipe = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
ipipe_try_format(ipipe, fh, fse->pad, &format, V4L2_SUBDEV_FORMAT_TRY);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
ipipe_try_format(ipipe, fh, fse->pad, &format, V4L2_SUBDEV_FORMAT_TRY);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int ipipe_get_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct iss_ipipe_device *ipipe = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __ipipe_get_format(ipipe, fh, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int ipipe_set_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct iss_ipipe_device *ipipe = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __ipipe_get_format(ipipe, fh, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
ipipe_try_format(ipipe, fh, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == IPIPE_PAD_SINK) {
format = __ipipe_get_format(ipipe, fh, IPIPE_PAD_SOURCE_VP,
fmt->which);
*format = fmt->format;
ipipe_try_format(ipipe, fh, IPIPE_PAD_SOURCE_VP, format,
fmt->which);
}
return 0;
}
static int ipipe_link_validate(struct v4l2_subdev *sd, struct media_link *link,
struct v4l2_subdev_format *source_fmt,
struct v4l2_subdev_format *sink_fmt)
{
if (source_fmt->format.width != sink_fmt->format.width ||
source_fmt->format.height != sink_fmt->format.height)
return -EPIPE;
if (source_fmt->format.code != sink_fmt->format.code)
return -EPIPE;
return 0;
}
static int ipipe_init_formats(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format;
memset(&format, 0, sizeof(format));
format.pad = IPIPE_PAD_SINK;
format.which = fh ? V4L2_SUBDEV_FORMAT_TRY : V4L2_SUBDEV_FORMAT_ACTIVE;
format.format.code = V4L2_MBUS_FMT_SGRBG10_1X10;
format.format.width = 4096;
format.format.height = 4096;
ipipe_set_format(sd, fh, &format);
return 0;
}
static int ipipe_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct iss_ipipe_device *ipipe = v4l2_get_subdevdata(sd);
struct iss_device *iss = to_iss_device(ipipe);
switch (local->index | media_entity_type(remote->entity)) {
case IPIPE_PAD_SINK | MEDIA_ENT_T_V4L2_SUBDEV:
if (!(flags & MEDIA_LNK_FL_ENABLED)) {
ipipe->input = IPIPE_INPUT_NONE;
break;
}
if (ipipe->input != IPIPE_INPUT_NONE)
return -EBUSY;
if (remote->entity == &iss->ipipeif.subdev.entity)
ipipe->input = IPIPE_INPUT_IPIPEIF;
break;
case IPIPE_PAD_SOURCE_VP | MEDIA_ENT_T_V4L2_SUBDEV:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (ipipe->output & ~IPIPE_OUTPUT_VP)
return -EBUSY;
ipipe->output |= IPIPE_OUTPUT_VP;
} else {
ipipe->output &= ~IPIPE_OUTPUT_VP;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int ipipe_init_entities(struct iss_ipipe_device *ipipe)
{
struct v4l2_subdev *sd = &ipipe->subdev;
struct media_pad *pads = ipipe->pads;
struct media_entity *me = &sd->entity;
int ret;
ipipe->input = IPIPE_INPUT_NONE;
v4l2_subdev_init(sd, &ipipe_v4l2_ops);
sd->internal_ops = &ipipe_v4l2_internal_ops;
strlcpy(sd->name, "OMAP4 ISS ISP IPIPE", sizeof(sd->name));
sd->grp_id = 1 << 16;
v4l2_set_subdevdata(sd, ipipe);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
pads[IPIPE_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[IPIPE_PAD_SOURCE_VP].flags = MEDIA_PAD_FL_SOURCE;
me->ops = &ipipe_media_ops;
ret = media_entity_init(me, IPIPE_PADS_NUM, pads, 0);
if (ret < 0)
return ret;
ipipe_init_formats(sd, NULL);
return 0;
}
void omap4iss_ipipe_unregister_entities(struct iss_ipipe_device *ipipe)
{
media_entity_cleanup(&ipipe->subdev.entity);
v4l2_device_unregister_subdev(&ipipe->subdev);
}
int omap4iss_ipipe_register_entities(struct iss_ipipe_device *ipipe,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &ipipe->subdev);
if (ret < 0)
goto error;
return 0;
error:
omap4iss_ipipe_unregister_entities(ipipe);
return ret;
}
int omap4iss_ipipe_init(struct iss_device *iss)
{
struct iss_ipipe_device *ipipe = &iss->ipipe;
ipipe->state = ISS_PIPELINE_STREAM_STOPPED;
init_waitqueue_head(&ipipe->wait);
return ipipe_init_entities(ipipe);
}
void omap4iss_ipipe_cleanup(struct iss_device *iss)
{
}
