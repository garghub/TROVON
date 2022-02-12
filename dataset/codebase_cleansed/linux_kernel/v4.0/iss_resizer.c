static void resizer_print_status(struct iss_resizer_device *resizer)
{
struct iss_device *iss = to_iss_device(resizer);
dev_dbg(iss->dev, "-------------RESIZER Register dump-------------\n");
RSZ_PRINT_REGISTER(iss, SYSCONFIG);
RSZ_PRINT_REGISTER(iss, IN_FIFO_CTRL);
RSZ_PRINT_REGISTER(iss, FRACDIV);
RSZ_PRINT_REGISTER(iss, SRC_EN);
RSZ_PRINT_REGISTER(iss, SRC_MODE);
RSZ_PRINT_REGISTER(iss, SRC_FMT0);
RSZ_PRINT_REGISTER(iss, SRC_FMT1);
RSZ_PRINT_REGISTER(iss, SRC_VPS);
RSZ_PRINT_REGISTER(iss, SRC_VSZ);
RSZ_PRINT_REGISTER(iss, SRC_HPS);
RSZ_PRINT_REGISTER(iss, SRC_HSZ);
RSZ_PRINT_REGISTER(iss, DMA_RZA);
RSZ_PRINT_REGISTER(iss, DMA_RZB);
RSZ_PRINT_REGISTER(iss, DMA_STA);
RSZ_PRINT_REGISTER(iss, GCK_MMR);
RSZ_PRINT_REGISTER(iss, GCK_SDR);
RSZ_PRINT_REGISTER(iss, IRQ_RZA);
RSZ_PRINT_REGISTER(iss, IRQ_RZB);
RSZ_PRINT_REGISTER(iss, YUV_Y_MIN);
RSZ_PRINT_REGISTER(iss, YUV_Y_MAX);
RSZ_PRINT_REGISTER(iss, YUV_C_MIN);
RSZ_PRINT_REGISTER(iss, YUV_C_MAX);
RSZ_PRINT_REGISTER(iss, SEQ);
RZA_PRINT_REGISTER(iss, EN);
RZA_PRINT_REGISTER(iss, MODE);
RZA_PRINT_REGISTER(iss, 420);
RZA_PRINT_REGISTER(iss, I_VPS);
RZA_PRINT_REGISTER(iss, I_HPS);
RZA_PRINT_REGISTER(iss, O_VSZ);
RZA_PRINT_REGISTER(iss, O_HSZ);
RZA_PRINT_REGISTER(iss, V_PHS_Y);
RZA_PRINT_REGISTER(iss, V_PHS_C);
RZA_PRINT_REGISTER(iss, V_DIF);
RZA_PRINT_REGISTER(iss, V_TYP);
RZA_PRINT_REGISTER(iss, V_LPF);
RZA_PRINT_REGISTER(iss, H_PHS);
RZA_PRINT_REGISTER(iss, H_DIF);
RZA_PRINT_REGISTER(iss, H_TYP);
RZA_PRINT_REGISTER(iss, H_LPF);
RZA_PRINT_REGISTER(iss, DWN_EN);
RZA_PRINT_REGISTER(iss, SDR_Y_BAD_H);
RZA_PRINT_REGISTER(iss, SDR_Y_BAD_L);
RZA_PRINT_REGISTER(iss, SDR_Y_SAD_H);
RZA_PRINT_REGISTER(iss, SDR_Y_SAD_L);
RZA_PRINT_REGISTER(iss, SDR_Y_OFT);
RZA_PRINT_REGISTER(iss, SDR_Y_PTR_S);
RZA_PRINT_REGISTER(iss, SDR_Y_PTR_E);
RZA_PRINT_REGISTER(iss, SDR_C_BAD_H);
RZA_PRINT_REGISTER(iss, SDR_C_BAD_L);
RZA_PRINT_REGISTER(iss, SDR_C_SAD_H);
RZA_PRINT_REGISTER(iss, SDR_C_SAD_L);
RZA_PRINT_REGISTER(iss, SDR_C_OFT);
RZA_PRINT_REGISTER(iss, SDR_C_PTR_S);
RZA_PRINT_REGISTER(iss, SDR_C_PTR_E);
dev_dbg(iss->dev, "-----------------------------------------------\n");
}
static void resizer_enable(struct iss_resizer_device *resizer, u8 enable)
{
struct iss_device *iss = to_iss_device(resizer);
iss_reg_update(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_EN,
RSZ_SRC_EN_SRC_EN, enable ? RSZ_SRC_EN_SRC_EN : 0);
iss_reg_update(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_EN, RSZ_EN_EN,
enable ? RSZ_EN_EN : 0);
}
static void resizer_set_outaddr(struct iss_resizer_device *resizer, u32 addr)
{
struct iss_device *iss = to_iss_device(resizer);
struct v4l2_mbus_framefmt *informat, *outformat;
informat = &resizer->formats[RESIZER_PAD_SINK];
outformat = &resizer->formats[RESIZER_PAD_SOURCE_MEM];
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_BAD_H,
(addr >> 16) & 0xffff);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_BAD_L,
addr & 0xffff);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_SAD_H,
(addr >> 16) & 0xffff);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_SAD_L,
addr & 0xffff);
if ((informat->code == MEDIA_BUS_FMT_UYVY8_1X16) &&
(outformat->code == MEDIA_BUS_FMT_YUYV8_1_5X8)) {
u32 c_addr = addr + (resizer->video_out.bpl_value *
(outformat->height - 1));
if ((c_addr ^ addr) & 0x7f) {
c_addr &= ~0x7f;
c_addr += 0x80;
c_addr |= addr & 0x7f;
}
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_BAD_H,
(c_addr >> 16) & 0xffff);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_BAD_L,
c_addr & 0xffff);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_SAD_H,
(c_addr >> 16) & 0xffff);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_SAD_L,
c_addr & 0xffff);
}
}
static void resizer_configure(struct iss_resizer_device *resizer)
{
struct iss_device *iss = to_iss_device(resizer);
struct v4l2_mbus_framefmt *informat, *outformat;
informat = &resizer->formats[RESIZER_PAD_SINK];
outformat = &resizer->formats[RESIZER_PAD_SOURCE_MEM];
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_FMT0,
RSZ_SRC_FMT0_BYPASS);
iss_reg_update(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_FMT0,
RSZ_SRC_FMT0_SEL,
resizer->input == RESIZER_INPUT_IPIPEIF ?
RSZ_SRC_FMT0_SEL : 0);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_MODE,
RSZ_SRC_MODE_WRT);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_MODE,
RSZ_SRC_MODE_OST);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_MODE,
RZA_MODE_ONE_SHOT);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_VPS, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_HPS, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_VSZ,
informat->height - 2);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SRC_HSZ,
informat->width - 1);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_I_VPS, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_I_HPS, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_O_VSZ,
outformat->height - 2);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_O_HSZ,
outformat->width - 1);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_V_DIF, 0x100);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_H_DIF, 0x100);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_PTR_S, 0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_PTR_E,
outformat->height - 1);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_Y_OFT,
resizer->video_out.bpl_value);
if ((informat->code == MEDIA_BUS_FMT_UYVY8_1X16) &&
(outformat->code == MEDIA_BUS_FMT_YUYV8_1_5X8)) {
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_420,
RSZ_420_CEN | RSZ_420_YEN);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_PTR_S,
0);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_PTR_E,
outformat->height - 1);
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_SDR_C_OFT,
resizer->video_out.bpl_value);
} else {
iss_reg_write(iss, OMAP4_ISS_MEM_ISP_RESIZER, RZA_420, 0);
}
}
static void resizer_isr_buffer(struct iss_resizer_device *resizer)
{
struct iss_buffer *buffer;
resizer_enable(resizer, 0);
buffer = omap4iss_video_buffer_next(&resizer->video_out);
if (buffer == NULL)
return;
resizer_set_outaddr(resizer, buffer->iss_addr);
resizer_enable(resizer, 1);
}
void omap4iss_resizer_isr(struct iss_resizer_device *resizer, u32 events)
{
struct iss_device *iss = to_iss_device(resizer);
struct iss_pipeline *pipe =
to_iss_pipeline(&resizer->subdev.entity);
if (events & (ISP5_IRQ_RSZ_FIFO_IN_BLK_ERR |
ISP5_IRQ_RSZ_FIFO_OVF)) {
dev_dbg(iss->dev, "RSZ Err: FIFO_IN_BLK:%d, FIFO_OVF:%d\n",
events & ISP5_IRQ_RSZ_FIFO_IN_BLK_ERR ? 1 : 0,
events & ISP5_IRQ_RSZ_FIFO_OVF ? 1 : 0);
omap4iss_pipeline_cancel_stream(pipe);
}
if (omap4iss_module_sync_is_stopping(&resizer->wait,
&resizer->stopping))
return;
if (events & ISP5_IRQ_RSZ_INT_DMA)
resizer_isr_buffer(resizer);
}
static int resizer_video_queue(struct iss_video *video,
struct iss_buffer *buffer)
{
struct iss_resizer_device *resizer = container_of(video,
struct iss_resizer_device, video_out);
if (!(resizer->output & RESIZER_OUTPUT_MEMORY))
return -ENODEV;
resizer_set_outaddr(resizer, buffer->iss_addr);
if (video->dmaqueue_flags & ISS_VIDEO_DMAQUEUE_UNDERRUN) {
resizer_enable(resizer, 1);
iss_video_dmaqueue_flags_clr(video);
}
return 0;
}
static int resizer_set_stream(struct v4l2_subdev *sd, int enable)
{
struct iss_resizer_device *resizer = v4l2_get_subdevdata(sd);
struct iss_device *iss = to_iss_device(resizer);
struct iss_video *video_out = &resizer->video_out;
int ret = 0;
if (resizer->state == ISS_PIPELINE_STREAM_STOPPED) {
if (enable == ISS_PIPELINE_STREAM_STOPPED)
return 0;
omap4iss_isp_subclk_enable(iss, OMAP4_ISS_ISP_SUBCLK_RSZ);
iss_reg_set(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_GCK_MMR,
RSZ_GCK_MMR_MMR);
iss_reg_set(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_GCK_SDR,
RSZ_GCK_SDR_CORE);
iss_reg_set(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SYSCONFIG,
RSZ_SYSCONFIG_RSZA_CLK_EN);
}
switch (enable) {
case ISS_PIPELINE_STREAM_CONTINUOUS:
resizer_configure(resizer);
resizer_print_status(resizer);
if (resizer->output & RESIZER_OUTPUT_MEMORY &&
!(video_out->dmaqueue_flags & ISS_VIDEO_DMAQUEUE_QUEUED))
break;
atomic_set(&resizer->stopping, 0);
resizer_enable(resizer, 1);
iss_video_dmaqueue_flags_clr(video_out);
break;
case ISS_PIPELINE_STREAM_STOPPED:
if (resizer->state == ISS_PIPELINE_STREAM_STOPPED)
return 0;
if (omap4iss_module_sync_idle(&sd->entity, &resizer->wait,
&resizer->stopping))
ret = -ETIMEDOUT;
resizer_enable(resizer, 0);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_SYSCONFIG,
RSZ_SYSCONFIG_RSZA_CLK_EN);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_GCK_SDR,
RSZ_GCK_SDR_CORE);
iss_reg_clr(iss, OMAP4_ISS_MEM_ISP_RESIZER, RSZ_GCK_MMR,
RSZ_GCK_MMR_MMR);
omap4iss_isp_subclk_disable(iss, OMAP4_ISS_ISP_SUBCLK_RSZ);
iss_video_dmaqueue_flags_clr(video_out);
break;
}
resizer->state = enable;
return ret;
}
static struct v4l2_mbus_framefmt *
__resizer_get_format(struct iss_resizer_device *resizer,
struct v4l2_subdev_fh *fh, unsigned int pad,
enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(fh, pad);
return &resizer->formats[pad];
}
static void
resizer_try_format(struct iss_resizer_device *resizer,
struct v4l2_subdev_fh *fh, unsigned int pad,
struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
u32 pixelcode;
struct v4l2_mbus_framefmt *format;
unsigned int width = fmt->width;
unsigned int height = fmt->height;
unsigned int i;
switch (pad) {
case RESIZER_PAD_SINK:
for (i = 0; i < ARRAY_SIZE(resizer_fmts); i++) {
if (fmt->code == resizer_fmts[i])
break;
}
if (i >= ARRAY_SIZE(resizer_fmts))
fmt->code = MEDIA_BUS_FMT_UYVY8_1X16;
fmt->width = clamp_t(u32, width, 1, 8192);
fmt->height = clamp_t(u32, height, 1, 8192);
break;
case RESIZER_PAD_SOURCE_MEM:
pixelcode = fmt->code;
format = __resizer_get_format(resizer, fh, RESIZER_PAD_SINK,
which);
memcpy(fmt, format, sizeof(*fmt));
if ((pixelcode == MEDIA_BUS_FMT_YUYV8_1_5X8) &&
(fmt->code == MEDIA_BUS_FMT_UYVY8_1X16))
fmt->code = pixelcode;
fmt->width = clamp_t(u32, width, 32, (fmt->width + 15) & ~15);
fmt->width &= ~15;
fmt->height = clamp_t(u32, height, 32, fmt->height);
break;
}
fmt->colorspace = V4L2_COLORSPACE_JPEG;
fmt->field = V4L2_FIELD_NONE;
}
static int resizer_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
struct iss_resizer_device *resizer = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
switch (code->pad) {
case RESIZER_PAD_SINK:
if (code->index >= ARRAY_SIZE(resizer_fmts))
return -EINVAL;
code->code = resizer_fmts[code->index];
break;
case RESIZER_PAD_SOURCE_MEM:
format = __resizer_get_format(resizer, fh, RESIZER_PAD_SINK,
V4L2_SUBDEV_FORMAT_TRY);
if (code->index == 0) {
code->code = format->code;
break;
}
switch (format->code) {
case MEDIA_BUS_FMT_UYVY8_1X16:
if (code->index == 1)
code->code = MEDIA_BUS_FMT_YUYV8_1_5X8;
else
return -EINVAL;
break;
default:
if (code->index != 0)
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int resizer_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct iss_resizer_device *resizer = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
resizer_try_format(resizer, fh, fse->pad, &format,
V4L2_SUBDEV_FORMAT_TRY);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
resizer_try_format(resizer, fh, fse->pad, &format,
V4L2_SUBDEV_FORMAT_TRY);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int resizer_get_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct iss_resizer_device *resizer = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __resizer_get_format(resizer, fh, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int resizer_set_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct iss_resizer_device *resizer = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __resizer_get_format(resizer, fh, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
resizer_try_format(resizer, fh, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == RESIZER_PAD_SINK) {
format = __resizer_get_format(resizer, fh,
RESIZER_PAD_SOURCE_MEM,
fmt->which);
*format = fmt->format;
resizer_try_format(resizer, fh, RESIZER_PAD_SOURCE_MEM, format,
fmt->which);
}
return 0;
}
static int resizer_link_validate(struct v4l2_subdev *sd,
struct media_link *link,
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
static int resizer_init_formats(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format;
memset(&format, 0, sizeof(format));
format.pad = RESIZER_PAD_SINK;
format.which = fh ? V4L2_SUBDEV_FORMAT_TRY : V4L2_SUBDEV_FORMAT_ACTIVE;
format.format.code = MEDIA_BUS_FMT_UYVY8_1X16;
format.format.width = 4096;
format.format.height = 4096;
resizer_set_format(sd, fh, &format);
return 0;
}
static int resizer_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct iss_resizer_device *resizer = v4l2_get_subdevdata(sd);
struct iss_device *iss = to_iss_device(resizer);
switch (local->index | media_entity_type(remote->entity)) {
case RESIZER_PAD_SINK | MEDIA_ENT_T_V4L2_SUBDEV:
if (!(flags & MEDIA_LNK_FL_ENABLED)) {
resizer->input = RESIZER_INPUT_NONE;
break;
}
if (resizer->input != RESIZER_INPUT_NONE)
return -EBUSY;
if (remote->entity == &iss->ipipeif.subdev.entity)
resizer->input = RESIZER_INPUT_IPIPEIF;
else if (remote->entity == &iss->ipipe.subdev.entity)
resizer->input = RESIZER_INPUT_IPIPE;
break;
case RESIZER_PAD_SOURCE_MEM | MEDIA_ENT_T_DEVNODE:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (resizer->output & ~RESIZER_OUTPUT_MEMORY)
return -EBUSY;
resizer->output |= RESIZER_OUTPUT_MEMORY;
} else {
resizer->output &= ~RESIZER_OUTPUT_MEMORY;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int resizer_init_entities(struct iss_resizer_device *resizer)
{
struct v4l2_subdev *sd = &resizer->subdev;
struct media_pad *pads = resizer->pads;
struct media_entity *me = &sd->entity;
int ret;
resizer->input = RESIZER_INPUT_NONE;
v4l2_subdev_init(sd, &resizer_v4l2_ops);
sd->internal_ops = &resizer_v4l2_internal_ops;
strlcpy(sd->name, "OMAP4 ISS ISP resizer", sizeof(sd->name));
sd->grp_id = 1 << 16;
v4l2_set_subdevdata(sd, resizer);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
pads[RESIZER_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[RESIZER_PAD_SOURCE_MEM].flags = MEDIA_PAD_FL_SOURCE;
me->ops = &resizer_media_ops;
ret = media_entity_init(me, RESIZER_PADS_NUM, pads, 0);
if (ret < 0)
return ret;
resizer_init_formats(sd, NULL);
resizer->video_out.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
resizer->video_out.ops = &resizer_video_ops;
resizer->video_out.iss = to_iss_device(resizer);
resizer->video_out.capture_mem = PAGE_ALIGN(4096 * 4096) * 3;
resizer->video_out.bpl_alignment = 32;
resizer->video_out.bpl_zero_padding = 1;
resizer->video_out.bpl_max = 0x1ffe0;
ret = omap4iss_video_init(&resizer->video_out, "ISP resizer a");
if (ret < 0)
return ret;
ret = media_entity_create_link(&resizer->subdev.entity,
RESIZER_PAD_SOURCE_MEM,
&resizer->video_out.video.entity, 0, 0);
if (ret < 0)
return ret;
return 0;
}
void omap4iss_resizer_unregister_entities(struct iss_resizer_device *resizer)
{
media_entity_cleanup(&resizer->subdev.entity);
v4l2_device_unregister_subdev(&resizer->subdev);
omap4iss_video_unregister(&resizer->video_out);
}
int omap4iss_resizer_register_entities(struct iss_resizer_device *resizer,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &resizer->subdev);
if (ret < 0)
goto error;
ret = omap4iss_video_register(&resizer->video_out, vdev);
if (ret < 0)
goto error;
return 0;
error:
omap4iss_resizer_unregister_entities(resizer);
return ret;
}
int omap4iss_resizer_init(struct iss_device *iss)
{
struct iss_resizer_device *resizer = &iss->resizer;
resizer->state = ISS_PIPELINE_STREAM_STOPPED;
init_waitqueue_head(&resizer->wait);
return resizer_init_entities(resizer);
}
void omap4iss_resizer_cleanup(struct iss_device *iss)
{
}
