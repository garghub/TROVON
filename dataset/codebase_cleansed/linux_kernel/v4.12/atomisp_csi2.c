static struct v4l2_mbus_framefmt *__csi2_get_format(struct
atomisp_mipi_csi2_device
*csi2,
struct
v4l2_subdev_pad_config *cfg,
enum
v4l2_subdev_format_whence
which, unsigned int pad)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&csi2->subdev, cfg, pad);
else
return &csi2->formats[pad];
}
static int csi2_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
const struct atomisp_in_fmt_conv *ic = atomisp_in_fmt_conv;
unsigned int i = 0;
while (ic->code) {
if (i == code->index) {
code->code = ic->code;
return 0;
}
i++, ic++;
}
return -EINVAL;
}
static int csi2_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct atomisp_mipi_csi2_device *csi2 = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __csi2_get_format(csi2, cfg, fmt->which, fmt->pad);
fmt->format = *format;
return 0;
}
int atomisp_csi2_set_ffmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
unsigned int which, uint16_t pad,
struct v4l2_mbus_framefmt *ffmt)
{
struct atomisp_mipi_csi2_device *csi2 = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *actual_ffmt =
#ifndef ISP2401
__csi2_get_format(csi2, cfg, which, pad);
#else
__csi2_get_format(csi2, cfg, which, pad);
#endif
if (pad == CSI2_PAD_SINK) {
const struct atomisp_in_fmt_conv *ic;
struct v4l2_mbus_framefmt tmp_ffmt;
ic = atomisp_find_in_fmt_conv(ffmt->code);
if (ic)
actual_ffmt->code = ic->code;
else
actual_ffmt->code = atomisp_in_fmt_conv[0].code;
actual_ffmt->width = clamp_t(
u32, ffmt->width, ATOM_ISP_MIN_WIDTH,
ATOM_ISP_MAX_WIDTH);
actual_ffmt->height = clamp_t(
u32, ffmt->height, ATOM_ISP_MIN_HEIGHT,
ATOM_ISP_MAX_HEIGHT);
tmp_ffmt = *ffmt = *actual_ffmt;
return atomisp_csi2_set_ffmt(sd, cfg, which, CSI2_PAD_SOURCE,
&tmp_ffmt);
}
*actual_ffmt = *ffmt =
#ifndef ISP2401
*__csi2_get_format(csi2, cfg, which, CSI2_PAD_SINK);
#else
*__csi2_get_format(csi2, cfg, which, CSI2_PAD_SINK);
#endif
return 0;
}
static int csi2_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
return atomisp_csi2_set_ffmt(sd, cfg, fmt->which, fmt->pad,
&fmt->format);
}
static int csi2_set_stream(struct v4l2_subdev *sd, int enable)
{
return 0;
}
static int csi2_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct atomisp_mipi_csi2_device *csi2 = v4l2_get_subdevdata(sd);
u32 result = local->index | is_media_entity_v4l2_subdev(remote->entity);
switch (result) {
case CSI2_PAD_SOURCE | MEDIA_ENT_F_OLD_BASE:
return -EINVAL;
case CSI2_PAD_SOURCE | MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN:
if (flags & MEDIA_LNK_FL_ENABLED) {
if (csi2->output & ~CSI2_OUTPUT_ISP_SUBDEV)
return -EBUSY;
csi2->output |= CSI2_OUTPUT_ISP_SUBDEV;
} else {
csi2->output &= ~CSI2_OUTPUT_ISP_SUBDEV;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int mipi_csi2_init_entities(struct atomisp_mipi_csi2_device *csi2,
int port)
{
struct v4l2_subdev *sd = &csi2->subdev;
struct media_pad *pads = csi2->pads;
struct media_entity *me = &sd->entity;
int ret;
v4l2_subdev_init(sd, &csi2_ops);
snprintf(sd->name, sizeof(sd->name), "ATOM ISP CSI2-port%d", port);
v4l2_set_subdevdata(sd, csi2);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
pads[CSI2_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
pads[CSI2_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
me->ops = &csi2_media_ops;
me->function = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
ret = media_entity_pads_init(me, CSI2_PADS_NUM, pads);
if (ret < 0)
return ret;
csi2->formats[CSI2_PAD_SINK].code =
csi2->formats[CSI2_PAD_SOURCE].code =
atomisp_in_fmt_conv[0].code;
return 0;
}
void
atomisp_mipi_csi2_unregister_entities(struct atomisp_mipi_csi2_device *csi2)
{
media_entity_cleanup(&csi2->subdev.entity);
v4l2_device_unregister_subdev(&csi2->subdev);
}
int atomisp_mipi_csi2_register_entities(struct atomisp_mipi_csi2_device *csi2,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &csi2->subdev);
if (ret < 0)
goto error;
return 0;
error:
atomisp_mipi_csi2_unregister_entities(csi2);
return ret;
}
static int
atomisp_csi2_configure_calc(const short int coeffs[2], int mipi_freq, int def)
{
static const int accinv = 16;
int r;
if (mipi_freq >> LIMIT_SHIFT <= 0)
return def;
r = accinv * coeffs[1] * (500000000 >> LIMIT_SHIFT);
r /= mipi_freq >> LIMIT_SHIFT;
r += accinv * coeffs[0];
return r;
}
static void atomisp_csi2_configure_isp2401(struct atomisp_sub_device *asd)
{
static const short int coeff_clk_termen[] = { 0, 0 };
static const short int coeff_clk_settle[] = { 95, -8 };
static const short int coeff_dat_termen[] = { 0, 0 };
static const short int coeff_dat_settle[] = { 85, -2 };
static const int TERMEN_DEFAULT = 0 * 0;
static const int SETTLE_DEFAULT = 0x480;
static const hrt_address csi2_port_base[] = {
[ATOMISP_CAMERA_PORT_PRIMARY] = CSI2_PORT_A_BASE,
[ATOMISP_CAMERA_PORT_SECONDARY] = CSI2_PORT_B_BASE,
[ATOMISP_CAMERA_PORT_TERTIARY] = CSI2_PORT_C_BASE,
};
static const unsigned char csi2_port_lanes[] = {
[ATOMISP_CAMERA_PORT_PRIMARY] = 4,
[ATOMISP_CAMERA_PORT_SECONDARY] = 2,
[ATOMISP_CAMERA_PORT_TERTIARY] = 2,
};
static const hrt_address csi2_lane_base[] = {
CSI2_LANE_CL_BASE,
CSI2_LANE_D0_BASE,
CSI2_LANE_D1_BASE,
CSI2_LANE_D2_BASE,
CSI2_LANE_D3_BASE,
};
int clk_termen;
int clk_settle;
int dat_termen;
int dat_settle;
struct v4l2_control ctrl;
struct atomisp_device *isp = asd->isp;
struct camera_mipi_info *mipi_info;
int mipi_freq = 0;
enum atomisp_camera_port port;
int n;
mipi_info = atomisp_to_sensor_mipi_info(
isp->inputs[asd->input_curr].camera);
port = mipi_info->port;
ctrl.id = V4L2_CID_LINK_FREQ;
if (v4l2_g_ctrl
(isp->inputs[asd->input_curr].camera->ctrl_handler, &ctrl) == 0)
mipi_freq = ctrl.value;
clk_termen = atomisp_csi2_configure_calc(coeff_clk_termen,
mipi_freq, TERMEN_DEFAULT);
clk_settle = atomisp_csi2_configure_calc(coeff_clk_settle,
mipi_freq, SETTLE_DEFAULT);
dat_termen = atomisp_csi2_configure_calc(coeff_dat_termen,
mipi_freq, TERMEN_DEFAULT);
dat_settle = atomisp_csi2_configure_calc(coeff_dat_settle,
mipi_freq, SETTLE_DEFAULT);
for (n = 0; n < csi2_port_lanes[port] + 1; n++) {
hrt_address base = csi2_port_base[port] + csi2_lane_base[n];
atomisp_store_uint32(base + CSI2_REG_RX_CSI_DLY_CNT_TERMEN,
n == 0 ? clk_termen : dat_termen);
atomisp_store_uint32(base + CSI2_REG_RX_CSI_DLY_CNT_SETTLE,
n == 0 ? clk_settle : dat_settle);
}
}
void atomisp_csi2_configure(struct atomisp_sub_device *asd)
{
if (IS_HWREVISION(asd->isp, ATOMISP_HW_REVISION_ISP2401))
atomisp_csi2_configure_isp2401(asd);
}
void atomisp_mipi_csi2_cleanup(struct atomisp_device *isp)
{
}
int atomisp_mipi_csi2_init(struct atomisp_device *isp)
{
struct atomisp_mipi_csi2_device *csi2_port;
unsigned int i;
int ret;
for (i = 0; i < ATOMISP_CAMERA_NR_PORTS; i++) {
csi2_port = &isp->csi2_port[i];
csi2_port->isp = isp;
ret = mipi_csi2_init_entities(csi2_port, i);
if (ret < 0)
goto fail;
}
return 0;
fail:
atomisp_mipi_csi2_cleanup(isp);
return ret;
}
