static struct v4l2_mbus_framefmt *
__resizer_get_format(struct isp_res_device *res, struct v4l2_subdev_fh *fh,
unsigned int pad, enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(fh, pad);
else
return &res->formats[pad];
}
static struct v4l2_rect *
__resizer_get_crop(struct isp_res_device *res, struct v4l2_subdev_fh *fh,
enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_crop(fh, RESZ_PAD_SINK);
else
return &res->crop.request;
}
static void resizer_set_filters(struct isp_res_device *res, const u16 *h_coeff,
const u16 *v_coeff)
{
struct isp_device *isp = to_isp_device(res);
u32 startaddr_h, startaddr_v, tmp_h, tmp_v;
int i;
startaddr_h = ISPRSZ_HFILT10;
startaddr_v = ISPRSZ_VFILT10;
for (i = 0; i < COEFF_CNT; i += 2) {
tmp_h = h_coeff[i] |
(h_coeff[i + 1] << ISPRSZ_HFILT_COEF1_SHIFT);
tmp_v = v_coeff[i] |
(v_coeff[i + 1] << ISPRSZ_VFILT_COEF1_SHIFT);
isp_reg_writel(isp, tmp_h, OMAP3_ISP_IOMEM_RESZ, startaddr_h);
isp_reg_writel(isp, tmp_v, OMAP3_ISP_IOMEM_RESZ, startaddr_v);
startaddr_h += 4;
startaddr_v += 4;
}
}
static void resizer_set_bilinear(struct isp_res_device *res,
enum resizer_chroma_algo type)
{
struct isp_device *isp = to_isp_device(res);
if (type == RSZ_BILINEAR)
isp_reg_set(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_CBILIN);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_CBILIN);
}
static void resizer_set_ycpos(struct isp_res_device *res,
enum v4l2_mbus_pixelcode pixelcode)
{
struct isp_device *isp = to_isp_device(res);
switch (pixelcode) {
case V4L2_MBUS_FMT_YUYV8_1X16:
isp_reg_set(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_YCPOS);
break;
case V4L2_MBUS_FMT_UYVY8_1X16:
isp_reg_clr(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_YCPOS);
break;
default:
return;
}
}
static void resizer_set_phase(struct isp_res_device *res, u32 h_phase,
u32 v_phase)
{
struct isp_device *isp = to_isp_device(res);
u32 rgval = 0;
rgval = isp_reg_readl(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT) &
~(ISPRSZ_CNT_HSTPH_MASK | ISPRSZ_CNT_VSTPH_MASK);
rgval |= (h_phase << ISPRSZ_CNT_HSTPH_SHIFT) & ISPRSZ_CNT_HSTPH_MASK;
rgval |= (v_phase << ISPRSZ_CNT_VSTPH_SHIFT) & ISPRSZ_CNT_VSTPH_MASK;
isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT);
}
static void resizer_set_luma(struct isp_res_device *res,
struct resizer_luma_yenh *luma)
{
struct isp_device *isp = to_isp_device(res);
u32 rgval = 0;
rgval = (luma->algo << ISPRSZ_YENH_ALGO_SHIFT)
& ISPRSZ_YENH_ALGO_MASK;
rgval |= (luma->gain << ISPRSZ_YENH_GAIN_SHIFT)
& ISPRSZ_YENH_GAIN_MASK;
rgval |= (luma->slope << ISPRSZ_YENH_SLOP_SHIFT)
& ISPRSZ_YENH_SLOP_MASK;
rgval |= (luma->core << ISPRSZ_YENH_CORE_SHIFT)
& ISPRSZ_YENH_CORE_MASK;
isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_YENH);
}
static void resizer_set_source(struct isp_res_device *res,
enum resizer_input_entity source)
{
struct isp_device *isp = to_isp_device(res);
if (source == RESIZER_INPUT_MEMORY)
isp_reg_set(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_INPSRC);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_INPSRC);
}
static void resizer_set_ratio(struct isp_res_device *res,
const struct resizer_ratio *ratio)
{
struct isp_device *isp = to_isp_device(res);
const u16 *h_filter, *v_filter;
u32 rgval = 0;
rgval = isp_reg_readl(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT) &
~(ISPRSZ_CNT_HRSZ_MASK | ISPRSZ_CNT_VRSZ_MASK);
rgval |= ((ratio->horz - 1) << ISPRSZ_CNT_HRSZ_SHIFT)
& ISPRSZ_CNT_HRSZ_MASK;
rgval |= ((ratio->vert - 1) << ISPRSZ_CNT_VRSZ_SHIFT)
& ISPRSZ_CNT_VRSZ_MASK;
isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT);
if (ratio->horz > MID_RESIZE_VALUE)
h_filter = &filter_coefs.h_filter_coef_7tap[0];
else
h_filter = &filter_coefs.h_filter_coef_4tap[0];
if (ratio->vert > MID_RESIZE_VALUE)
v_filter = &filter_coefs.v_filter_coef_7tap[0];
else
v_filter = &filter_coefs.v_filter_coef_4tap[0];
resizer_set_filters(res, h_filter, v_filter);
}
static void resizer_set_output_size(struct isp_res_device *res,
u32 width, u32 height)
{
struct isp_device *isp = to_isp_device(res);
u32 rgval = 0;
dev_dbg(isp->dev, "Output size[w/h]: %dx%d\n", width, height);
rgval = (width << ISPRSZ_OUT_SIZE_HORZ_SHIFT)
& ISPRSZ_OUT_SIZE_HORZ_MASK;
rgval |= (height << ISPRSZ_OUT_SIZE_VERT_SHIFT)
& ISPRSZ_OUT_SIZE_VERT_MASK;
isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_OUT_SIZE);
}
static void resizer_set_output_offset(struct isp_res_device *res, u32 offset)
{
struct isp_device *isp = to_isp_device(res);
isp_reg_writel(isp, offset, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_SDR_OUTOFF);
}
static void resizer_set_start(struct isp_res_device *res, u32 left, u32 top)
{
struct isp_device *isp = to_isp_device(res);
u32 rgval = 0;
rgval = (left << ISPRSZ_IN_START_HORZ_ST_SHIFT)
& ISPRSZ_IN_START_HORZ_ST_MASK;
rgval |= (top << ISPRSZ_IN_START_VERT_ST_SHIFT)
& ISPRSZ_IN_START_VERT_ST_MASK;
isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_IN_START);
}
static void resizer_set_input_size(struct isp_res_device *res,
u32 width, u32 height)
{
struct isp_device *isp = to_isp_device(res);
u32 rgval = 0;
dev_dbg(isp->dev, "Input size[w/h]: %dx%d\n", width, height);
rgval = (width << ISPRSZ_IN_SIZE_HORZ_SHIFT)
& ISPRSZ_IN_SIZE_HORZ_MASK;
rgval |= (height << ISPRSZ_IN_SIZE_VERT_SHIFT)
& ISPRSZ_IN_SIZE_VERT_MASK;
isp_reg_writel(isp, rgval, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_IN_SIZE);
}
static void resizer_set_input_offset(struct isp_res_device *res, u32 offset)
{
struct isp_device *isp = to_isp_device(res);
isp_reg_writel(isp, offset, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_SDR_INOFF);
}
static void resizer_set_intype(struct isp_res_device *res,
enum resizer_colors_type type)
{
struct isp_device *isp = to_isp_device(res);
if (type == RSZ_COLOR8)
isp_reg_set(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_INPTYP);
else
isp_reg_clr(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_CNT,
ISPRSZ_CNT_INPTYP);
}
static void __resizer_set_inaddr(struct isp_res_device *res, u32 addr)
{
struct isp_device *isp = to_isp_device(res);
isp_reg_writel(isp, addr, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_SDR_INADD);
}
void omap3isp_resizer_max_rate(struct isp_res_device *res,
unsigned int *max_rate)
{
struct isp_pipeline *pipe = to_isp_pipeline(&res->subdev.entity);
const struct v4l2_mbus_framefmt *ofmt = &res->formats[RESZ_PAD_SOURCE];
unsigned long limit = min(pipe->l3_ick, 200000000UL);
unsigned long clock;
clock = div_u64((u64)limit * res->crop.active.height, ofmt->height);
clock = min(clock, limit / 2);
*max_rate = div_u64((u64)clock * res->crop.active.width, ofmt->width);
}
static void resizer_adjust_bandwidth(struct isp_res_device *res)
{
struct isp_pipeline *pipe = to_isp_pipeline(&res->subdev.entity);
struct isp_device *isp = to_isp_device(res);
unsigned long l3_ick = pipe->l3_ick;
struct v4l2_fract *timeperframe;
unsigned int cycles_per_frame;
unsigned int requests_per_frame;
unsigned int cycles_per_request;
unsigned int granularity;
unsigned int minimum;
unsigned int maximum;
unsigned int value;
if (res->input != RESIZER_INPUT_MEMORY) {
isp_reg_clr(isp, OMAP3_ISP_IOMEM_SBL, ISPSBL_SDR_REQ_EXP,
ISPSBL_SDR_REQ_RSZ_EXP_MASK);
return;
}
switch (isp->revision) {
case ISP_REVISION_1_0:
case ISP_REVISION_2_0:
default:
granularity = 1024;
break;
case ISP_REVISION_15_0:
granularity = 32;
break;
}
cycles_per_request = div_u64((u64)l3_ick / 2 * 256 + pipe->max_rate - 1,
pipe->max_rate);
minimum = DIV_ROUND_UP(cycles_per_request, granularity);
timeperframe = &pipe->max_timeperframe;
requests_per_frame = DIV_ROUND_UP(res->crop.active.width * 2, 256)
* res->crop.active.height;
cycles_per_frame = div_u64((u64)l3_ick * timeperframe->numerator,
timeperframe->denominator);
cycles_per_request = cycles_per_frame / requests_per_frame;
maximum = cycles_per_request / granularity;
value = max(minimum, maximum);
dev_dbg(isp->dev, "%s: cycles per request = %u\n", __func__, value);
isp_reg_clr_set(isp, OMAP3_ISP_IOMEM_SBL, ISPSBL_SDR_REQ_EXP,
ISPSBL_SDR_REQ_RSZ_EXP_MASK,
value << ISPSBL_SDR_REQ_RSZ_EXP_SHIFT);
}
int omap3isp_resizer_busy(struct isp_res_device *res)
{
struct isp_device *isp = to_isp_device(res);
return isp_reg_readl(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_PCR) &
ISPRSZ_PCR_BUSY;
}
static void resizer_set_inaddr(struct isp_res_device *res, u32 addr)
{
res->addr_base = addr;
if (res->crop_offset)
addr += res->crop_offset & ~0x1f;
__resizer_set_inaddr(res, addr);
}
static void resizer_set_outaddr(struct isp_res_device *res, u32 addr)
{
struct isp_device *isp = to_isp_device(res);
isp_reg_writel(isp, addr << ISPRSZ_SDR_OUTADD_ADDR_SHIFT,
OMAP3_ISP_IOMEM_RESZ, ISPRSZ_SDR_OUTADD);
}
static void resizer_print_status(struct isp_res_device *res)
{
struct isp_device *isp = to_isp_device(res);
dev_dbg(isp->dev, "-------------Resizer Register dump----------\n");
RSZ_PRINT_REGISTER(isp, PCR);
RSZ_PRINT_REGISTER(isp, CNT);
RSZ_PRINT_REGISTER(isp, OUT_SIZE);
RSZ_PRINT_REGISTER(isp, IN_START);
RSZ_PRINT_REGISTER(isp, IN_SIZE);
RSZ_PRINT_REGISTER(isp, SDR_INADD);
RSZ_PRINT_REGISTER(isp, SDR_INOFF);
RSZ_PRINT_REGISTER(isp, SDR_OUTADD);
RSZ_PRINT_REGISTER(isp, SDR_OUTOFF);
RSZ_PRINT_REGISTER(isp, YENH);
dev_dbg(isp->dev, "--------------------------------------------\n");
}
static void resizer_calc_ratios(struct isp_res_device *res,
struct v4l2_rect *input,
struct v4l2_mbus_framefmt *output,
struct resizer_ratio *ratio)
{
struct isp_device *isp = to_isp_device(res);
const unsigned int spv = DEFAULT_PHASE;
const unsigned int sph = DEFAULT_PHASE;
unsigned int upscaled_width;
unsigned int upscaled_height;
unsigned int min_width;
unsigned int min_height;
unsigned int max_width;
unsigned int max_height;
unsigned int width_alignment;
unsigned int width;
unsigned int height;
min_height = ((input->height - 7) * 256 - 32 - 64 * spv) / 1024 + 1;
min_height = max_t(unsigned int, min_height, MIN_OUT_HEIGHT);
max_height = ((input->height - 4) * 256 + 255 - 16 - 32 * spv) / 64 + 1;
max_height = min_t(unsigned int, max_height, MAX_OUT_HEIGHT);
output->height = clamp(output->height, min_height, max_height);
ratio->vert = ((input->height - 4) * 256 + 255 - 16 - 32 * spv)
/ (output->height - 1);
if (ratio->vert > MID_RESIZE_VALUE)
ratio->vert = ((input->height - 7) * 256 + 255 - 32 - 64 * spv)
/ (output->height - 1);
ratio->vert = clamp_t(unsigned int, ratio->vert,
MIN_RESIZE_VALUE, MAX_RESIZE_VALUE);
if (ratio->vert <= MID_RESIZE_VALUE) {
upscaled_height = (output->height - 1) * ratio->vert
+ 32 * spv + 16;
height = (upscaled_height >> 8) + 4;
} else {
upscaled_height = (output->height - 1) * ratio->vert
+ 64 * spv + 32;
height = (upscaled_height >> 8) + 7;
}
min_width = ((input->width - 7) * 256 - 32 - 64 * sph) / 1024 + 1;
min_width = max_t(unsigned int, min_width, MIN_OUT_WIDTH);
if (ratio->vert <= MID_RESIZE_VALUE) {
switch (isp->revision) {
case ISP_REVISION_1_0:
max_width = MAX_4TAP_OUT_WIDTH_ES1;
break;
case ISP_REVISION_2_0:
default:
max_width = MAX_4TAP_OUT_WIDTH_ES2;
break;
case ISP_REVISION_15_0:
max_width = MAX_4TAP_OUT_WIDTH_3630;
break;
}
} else {
switch (isp->revision) {
case ISP_REVISION_1_0:
max_width = MAX_7TAP_OUT_WIDTH_ES1;
break;
case ISP_REVISION_2_0:
default:
max_width = MAX_7TAP_OUT_WIDTH_ES2;
break;
case ISP_REVISION_15_0:
max_width = MAX_7TAP_OUT_WIDTH_3630;
break;
}
}
max_width = min(((input->width - 7) * 256 + 255 - 16 - 32 * sph) / 64
+ 1, max_width);
width_alignment = ratio->vert < 256 ? 8 : 2;
output->width = clamp(output->width, min_width,
max_width & ~(width_alignment - 1));
output->width = ALIGN(output->width, width_alignment);
ratio->horz = ((input->width - 7) * 256 + 255 - 16 - 32 * sph)
/ (output->width - 1);
if (ratio->horz > MID_RESIZE_VALUE)
ratio->horz = ((input->width - 7) * 256 + 255 - 32 - 64 * sph)
/ (output->width - 1);
ratio->horz = clamp_t(unsigned int, ratio->horz,
MIN_RESIZE_VALUE, MAX_RESIZE_VALUE);
if (ratio->horz <= MID_RESIZE_VALUE) {
upscaled_width = (output->width - 1) * ratio->horz
+ 32 * sph + 16;
width = (upscaled_width >> 8) + 7;
} else {
upscaled_width = (output->width - 1) * ratio->horz
+ 64 * sph + 32;
width = (upscaled_width >> 8) + 7;
}
input->left += (input->width - width) / 2;
input->top += (input->height - height) / 2;
input->width = width;
input->height = height;
}
static void resizer_set_crop_params(struct isp_res_device *res,
const struct v4l2_mbus_framefmt *input,
const struct v4l2_mbus_framefmt *output)
{
resizer_set_ratio(res, &res->ratio);
if (res->ratio.horz >= RESIZE_DIVISOR)
resizer_set_bilinear(res, RSZ_THE_SAME);
else
resizer_set_bilinear(res, RSZ_BILINEAR);
resizer_adjust_bandwidth(res);
if (res->input == RESIZER_INPUT_MEMORY) {
res->crop_offset = (res->crop.active.top * input->width +
res->crop.active.left) * 2;
resizer_set_start(res, (res->crop_offset / 2) & 0xf, 0);
__resizer_set_inaddr(res,
res->addr_base + (res->crop_offset & ~0x1f));
} else {
resizer_set_start(res, res->crop.active.left * 2,
res->crop.active.top);
__resizer_set_inaddr(res, 0);
resizer_set_input_offset(res, 0);
}
resizer_set_input_size(res, res->crop.active.width,
res->crop.active.height);
}
static void resizer_configure(struct isp_res_device *res)
{
struct v4l2_mbus_framefmt *informat, *outformat;
struct resizer_luma_yenh luma = {0, 0, 0, 0};
resizer_set_source(res, res->input);
informat = &res->formats[RESZ_PAD_SINK];
outformat = &res->formats[RESZ_PAD_SOURCE];
if (res->input == RESIZER_INPUT_VP)
resizer_set_input_offset(res, 0);
else
resizer_set_input_offset(res, ALIGN(informat->width, 0x10) * 2);
resizer_set_intype(res, RSZ_YUV422);
resizer_set_ycpos(res, informat->code);
resizer_set_phase(res, DEFAULT_PHASE, DEFAULT_PHASE);
resizer_set_luma(res, &luma);
resizer_set_output_offset(res, ALIGN(outformat->width * 2, 32));
resizer_set_output_size(res, outformat->width, outformat->height);
resizer_set_crop_params(res, informat, outformat);
}
static void resizer_enable_oneshot(struct isp_res_device *res)
{
struct isp_device *isp = to_isp_device(res);
isp_reg_set(isp, OMAP3_ISP_IOMEM_RESZ, ISPRSZ_PCR,
ISPRSZ_PCR_ENABLE | ISPRSZ_PCR_ONESHOT);
}
void omap3isp_resizer_isr_frame_sync(struct isp_res_device *res)
{
if (res->state == ISP_PIPELINE_STREAM_CONTINUOUS &&
res->video_out.dmaqueue_flags & ISP_VIDEO_DMAQUEUE_QUEUED) {
resizer_enable_oneshot(res);
isp_video_dmaqueue_flags_clr(&res->video_out);
}
}
static void resizer_isr_buffer(struct isp_res_device *res)
{
struct isp_pipeline *pipe = to_isp_pipeline(&res->subdev.entity);
struct isp_buffer *buffer;
int restart = 0;
if (res->state == ISP_PIPELINE_STREAM_STOPPED)
return;
buffer = omap3isp_video_buffer_next(&res->video_out);
if (buffer != NULL) {
resizer_set_outaddr(res, buffer->isp_addr);
restart = 1;
}
pipe->state |= ISP_PIPELINE_IDLE_OUTPUT;
if (res->input == RESIZER_INPUT_MEMORY) {
buffer = omap3isp_video_buffer_next(&res->video_in);
if (buffer != NULL)
resizer_set_inaddr(res, buffer->isp_addr);
pipe->state |= ISP_PIPELINE_IDLE_INPUT;
}
if (res->state == ISP_PIPELINE_STREAM_SINGLESHOT) {
if (isp_pipeline_ready(pipe))
omap3isp_pipeline_set_stream(pipe,
ISP_PIPELINE_STREAM_SINGLESHOT);
} else {
if (restart)
resizer_enable_oneshot(res);
}
}
void omap3isp_resizer_isr(struct isp_res_device *res)
{
struct v4l2_mbus_framefmt *informat, *outformat;
if (omap3isp_module_sync_is_stopping(&res->wait, &res->stopping))
return;
if (res->applycrop) {
outformat = __resizer_get_format(res, NULL, RESZ_PAD_SOURCE,
V4L2_SUBDEV_FORMAT_ACTIVE);
informat = __resizer_get_format(res, NULL, RESZ_PAD_SINK,
V4L2_SUBDEV_FORMAT_ACTIVE);
resizer_set_crop_params(res, informat, outformat);
res->applycrop = 0;
}
resizer_isr_buffer(res);
}
static int resizer_video_queue(struct isp_video *video,
struct isp_buffer *buffer)
{
struct isp_res_device *res = &video->isp->isp_res;
if (video->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
resizer_set_inaddr(res, buffer->isp_addr);
if (video->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
resizer_set_outaddr(res, buffer->isp_addr);
return 0;
}
static int resizer_set_stream(struct v4l2_subdev *sd, int enable)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct isp_video *video_out = &res->video_out;
struct isp_device *isp = to_isp_device(res);
struct device *dev = to_device(res);
if (res->state == ISP_PIPELINE_STREAM_STOPPED) {
if (enable == ISP_PIPELINE_STREAM_STOPPED)
return 0;
omap3isp_subclk_enable(isp, OMAP3_ISP_SUBCLK_RESIZER);
resizer_configure(res);
resizer_print_status(res);
}
switch (enable) {
case ISP_PIPELINE_STREAM_CONTINUOUS:
omap3isp_sbl_enable(isp, OMAP3_ISP_SBL_RESIZER_WRITE);
if (video_out->dmaqueue_flags & ISP_VIDEO_DMAQUEUE_QUEUED) {
resizer_enable_oneshot(res);
isp_video_dmaqueue_flags_clr(video_out);
}
break;
case ISP_PIPELINE_STREAM_SINGLESHOT:
if (res->input == RESIZER_INPUT_MEMORY)
omap3isp_sbl_enable(isp, OMAP3_ISP_SBL_RESIZER_READ);
omap3isp_sbl_enable(isp, OMAP3_ISP_SBL_RESIZER_WRITE);
resizer_enable_oneshot(res);
break;
case ISP_PIPELINE_STREAM_STOPPED:
if (omap3isp_module_sync_idle(&sd->entity, &res->wait,
&res->stopping))
dev_dbg(dev, "%s: module stop timeout.\n", sd->name);
omap3isp_sbl_disable(isp, OMAP3_ISP_SBL_RESIZER_READ |
OMAP3_ISP_SBL_RESIZER_WRITE);
omap3isp_subclk_disable(isp, OMAP3_ISP_SUBCLK_RESIZER);
isp_video_dmaqueue_flags_clr(video_out);
break;
}
res->state = enable;
return 0;
}
static int resizer_g_crop(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
struct resizer_ratio ratio;
if (crop->pad != RESZ_PAD_SINK)
return -EINVAL;
format = __resizer_get_format(res, fh, RESZ_PAD_SOURCE, crop->which);
crop->rect = *__resizer_get_crop(res, fh, crop->which);
resizer_calc_ratios(res, &crop->rect, format, &ratio);
return 0;
}
static void resizer_try_crop(const struct v4l2_mbus_framefmt *sink,
const struct v4l2_mbus_framefmt *source,
struct v4l2_rect *crop)
{
const unsigned int spv = DEFAULT_PHASE;
const unsigned int sph = DEFAULT_PHASE;
unsigned int min_width =
((32 * sph + (source->width - 1) * 64 + 16) >> 8) + 7;
unsigned int min_height =
((32 * spv + (source->height - 1) * 64 + 16) >> 8) + 4;
unsigned int max_width =
((64 * sph + (source->width - 1) * 1024 + 32) >> 8) + 7;
unsigned int max_height =
((64 * spv + (source->height - 1) * 1024 + 32) >> 8) + 7;
crop->width = clamp_t(u32, crop->width, min_width, max_width);
crop->height = clamp_t(u32, crop->height, min_height, max_height);
crop->left = clamp_t(u32, crop->left, 0, sink->width - MIN_IN_WIDTH);
crop->width = clamp_t(u32, crop->width, MIN_IN_WIDTH,
sink->width - crop->left);
crop->top = clamp_t(u32, crop->top, 0, sink->height - MIN_IN_HEIGHT);
crop->height = clamp_t(u32, crop->height, MIN_IN_HEIGHT,
sink->height - crop->top);
}
static int resizer_s_crop(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_crop *crop)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct isp_device *isp = to_isp_device(res);
struct v4l2_mbus_framefmt *format_sink, *format_source;
struct resizer_ratio ratio;
if (crop->pad != RESZ_PAD_SINK)
return -EINVAL;
format_sink = __resizer_get_format(res, fh, RESZ_PAD_SINK,
crop->which);
format_source = __resizer_get_format(res, fh, RESZ_PAD_SOURCE,
crop->which);
dev_dbg(isp->dev, "%s: L=%d,T=%d,W=%d,H=%d,which=%d\n", __func__,
crop->rect.left, crop->rect.top, crop->rect.width,
crop->rect.height, crop->which);
dev_dbg(isp->dev, "%s: input=%dx%d, output=%dx%d\n", __func__,
format_sink->width, format_sink->height,
format_source->width, format_source->height);
resizer_try_crop(format_sink, format_source, &crop->rect);
*__resizer_get_crop(res, fh, crop->which) = crop->rect;
resizer_calc_ratios(res, &crop->rect, format_source, &ratio);
if (crop->which == V4L2_SUBDEV_FORMAT_TRY)
return 0;
res->ratio = ratio;
res->crop.active = crop->rect;
if (res->state != ISP_PIPELINE_STREAM_STOPPED)
res->applycrop = 1;
return 0;
}
static unsigned int resizer_max_in_width(struct isp_res_device *res)
{
struct isp_device *isp = to_isp_device(res);
if (res->input == RESIZER_INPUT_MEMORY) {
return MAX_IN_WIDTH_MEMORY_MODE;
} else {
if (isp->revision == ISP_REVISION_1_0)
return MAX_IN_WIDTH_ONTHEFLY_MODE_ES1;
else
return MAX_IN_WIDTH_ONTHEFLY_MODE_ES2;
}
}
static void resizer_try_format(struct isp_res_device *res,
struct v4l2_subdev_fh *fh, unsigned int pad,
struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
struct v4l2_mbus_framefmt *format;
struct resizer_ratio ratio;
struct v4l2_rect crop;
switch (pad) {
case RESZ_PAD_SINK:
if (fmt->code != V4L2_MBUS_FMT_YUYV8_1X16 &&
fmt->code != V4L2_MBUS_FMT_UYVY8_1X16)
fmt->code = V4L2_MBUS_FMT_YUYV8_1X16;
fmt->width = clamp_t(u32, fmt->width, MIN_IN_WIDTH,
resizer_max_in_width(res));
fmt->height = clamp_t(u32, fmt->height, MIN_IN_HEIGHT,
MAX_IN_HEIGHT);
break;
case RESZ_PAD_SOURCE:
format = __resizer_get_format(res, fh, RESZ_PAD_SINK, which);
fmt->code = format->code;
crop = *__resizer_get_crop(res, fh, which);
resizer_calc_ratios(res, &crop, fmt, &ratio);
break;
}
fmt->colorspace = V4L2_COLORSPACE_JPEG;
fmt->field = V4L2_FIELD_NONE;
}
static int resizer_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
if (code->pad == RESZ_PAD_SINK) {
if (code->index >= ARRAY_SIZE(resizer_formats))
return -EINVAL;
code->code = resizer_formats[code->index];
} else {
if (code->index != 0)
return -EINVAL;
format = __resizer_get_format(res, fh, RESZ_PAD_SINK,
V4L2_SUBDEV_FORMAT_TRY);
code->code = format->code;
}
return 0;
}
static int resizer_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_frame_size_enum *fse)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
resizer_try_format(res, fh, fse->pad, &format, V4L2_SUBDEV_FORMAT_TRY);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
resizer_try_format(res, fh, fse->pad, &format, V4L2_SUBDEV_FORMAT_TRY);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int resizer_get_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __resizer_get_format(res, fh, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int resizer_set_format(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct isp_res_device *res = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
struct v4l2_rect *crop;
format = __resizer_get_format(res, fh, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
resizer_try_format(res, fh, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == RESZ_PAD_SINK) {
crop = __resizer_get_crop(res, fh, fmt->which);
crop->left = 0;
crop->top = 0;
crop->width = fmt->format.width;
crop->height = fmt->format.height;
format = __resizer_get_format(res, fh, RESZ_PAD_SOURCE,
fmt->which);
*format = fmt->format;
resizer_try_format(res, fh, RESZ_PAD_SOURCE, format,
fmt->which);
}
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
res->crop.active = res->crop.request;
resizer_calc_ratios(res, &res->crop.active, format,
&res->ratio);
}
return 0;
}
static int resizer_init_formats(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format;
memset(&format, 0, sizeof(format));
format.pad = RESZ_PAD_SINK;
format.which = fh ? V4L2_SUBDEV_FORMAT_TRY : V4L2_SUBDEV_FORMAT_ACTIVE;
format.format.code = V4L2_MBUS_FMT_YUYV8_1X16;
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
struct isp_res_device *res = v4l2_get_subdevdata(sd);
switch (local->index | media_entity_type(remote->entity)) {
case RESZ_PAD_SINK | MEDIA_ENT_T_DEVNODE:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (res->input == RESIZER_INPUT_VP)
return -EBUSY;
res->input = RESIZER_INPUT_MEMORY;
} else {
if (res->input == RESIZER_INPUT_MEMORY)
res->input = RESIZER_INPUT_NONE;
}
break;
case RESZ_PAD_SINK | MEDIA_ENT_T_V4L2_SUBDEV:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (res->input == RESIZER_INPUT_MEMORY)
return -EBUSY;
res->input = RESIZER_INPUT_VP;
} else {
if (res->input == RESIZER_INPUT_VP)
res->input = RESIZER_INPUT_NONE;
}
break;
case RESZ_PAD_SOURCE | MEDIA_ENT_T_DEVNODE:
break;
default:
return -EINVAL;
}
return 0;
}
void omap3isp_resizer_unregister_entities(struct isp_res_device *res)
{
v4l2_device_unregister_subdev(&res->subdev);
omap3isp_video_unregister(&res->video_in);
omap3isp_video_unregister(&res->video_out);
}
int omap3isp_resizer_register_entities(struct isp_res_device *res,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &res->subdev);
if (ret < 0)
goto error;
ret = omap3isp_video_register(&res->video_in, vdev);
if (ret < 0)
goto error;
ret = omap3isp_video_register(&res->video_out, vdev);
if (ret < 0)
goto error;
return 0;
error:
omap3isp_resizer_unregister_entities(res);
return ret;
}
static int resizer_init_entities(struct isp_res_device *res)
{
struct v4l2_subdev *sd = &res->subdev;
struct media_pad *pads = res->pads;
struct media_entity *me = &sd->entity;
int ret;
res->input = RESIZER_INPUT_NONE;
v4l2_subdev_init(sd, &resizer_v4l2_ops);
sd->internal_ops = &resizer_v4l2_internal_ops;
strlcpy(sd->name, "OMAP3 ISP resizer", sizeof(sd->name));
sd->grp_id = 1 << 16;
v4l2_set_subdevdata(sd, res);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
pads[RESZ_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[RESZ_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
me->ops = &resizer_media_ops;
ret = media_entity_init(me, RESZ_PADS_NUM, pads, 0);
if (ret < 0)
return ret;
resizer_init_formats(sd, NULL);
res->video_in.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
res->video_in.ops = &resizer_video_ops;
res->video_in.isp = to_isp_device(res);
res->video_in.capture_mem = PAGE_ALIGN(4096 * 4096) * 2 * 3;
res->video_in.bpl_alignment = 32;
res->video_out.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
res->video_out.ops = &resizer_video_ops;
res->video_out.isp = to_isp_device(res);
res->video_out.capture_mem = PAGE_ALIGN(4096 * 4096) * 2 * 3;
res->video_out.bpl_alignment = 32;
ret = omap3isp_video_init(&res->video_in, "resizer");
if (ret < 0)
goto error_video_in;
ret = omap3isp_video_init(&res->video_out, "resizer");
if (ret < 0)
goto error_video_out;
ret = media_entity_create_link(&res->video_in.video.entity, 0,
&res->subdev.entity, RESZ_PAD_SINK, 0);
if (ret < 0)
goto error_link;
ret = media_entity_create_link(&res->subdev.entity, RESZ_PAD_SOURCE,
&res->video_out.video.entity, 0, 0);
if (ret < 0)
goto error_link;
return 0;
error_link:
omap3isp_video_cleanup(&res->video_out);
error_video_out:
omap3isp_video_cleanup(&res->video_in);
error_video_in:
media_entity_cleanup(&res->subdev.entity);
return ret;
}
int omap3isp_resizer_init(struct isp_device *isp)
{
struct isp_res_device *res = &isp->isp_res;
init_waitqueue_head(&res->wait);
atomic_set(&res->stopping, 0);
return resizer_init_entities(res);
}
void omap3isp_resizer_cleanup(struct isp_device *isp)
{
struct isp_res_device *res = &isp->isp_res;
omap3isp_video_cleanup(&res->video_in);
omap3isp_video_cleanup(&res->video_out);
media_entity_cleanup(&res->subdev.entity);
}
