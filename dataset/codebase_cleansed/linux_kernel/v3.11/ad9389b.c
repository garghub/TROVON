static inline struct ad9389b_state *get_ad9389b_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct ad9389b_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct ad9389b_state, hdl)->sd;
}
static int ad9389b_rd(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int ad9389b_wr(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
int i;
for (i = 0; i < 3; i++) {
ret = i2c_smbus_write_byte_data(client, reg, val);
if (ret == 0)
return 0;
}
v4l2_err(sd, "I2C Write Problem\n");
return ret;
}
static inline void ad9389b_wr_and_or(struct v4l2_subdev *sd, u8 reg,
u8 clr_mask, u8 val_mask)
{
ad9389b_wr(sd, reg, (ad9389b_rd(sd, reg) & clr_mask) | val_mask);
}
static void ad9389b_edid_rd(struct v4l2_subdev *sd, u16 len, u8 *buf)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
int i;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
for (i = 0; i < len; i++)
buf[i] = i2c_smbus_read_byte_data(state->edid_i2c_client, i);
}
static inline bool ad9389b_have_hotplug(struct v4l2_subdev *sd)
{
return ad9389b_rd(sd, 0x42) & MASK_AD9389B_HPD_DETECT;
}
static inline bool ad9389b_have_rx_sense(struct v4l2_subdev *sd)
{
return ad9389b_rd(sd, 0x42) & MASK_AD9389B_MSEN_DETECT;
}
static void ad9389b_csc_conversion_mode(struct v4l2_subdev *sd, u8 mode)
{
ad9389b_wr_and_or(sd, 0x17, 0xe7, (mode & 0x3)<<3);
ad9389b_wr_and_or(sd, 0x18, 0x9f, (mode & 0x3)<<5);
}
static void ad9389b_csc_coeff(struct v4l2_subdev *sd,
u16 A1, u16 A2, u16 A3, u16 A4,
u16 B1, u16 B2, u16 B3, u16 B4,
u16 C1, u16 C2, u16 C3, u16 C4)
{
ad9389b_wr_and_or(sd, 0x18, 0xe0, A1>>8);
ad9389b_wr(sd, 0x19, A1);
ad9389b_wr_and_or(sd, 0x1A, 0xe0, A2>>8);
ad9389b_wr(sd, 0x1B, A2);
ad9389b_wr_and_or(sd, 0x1c, 0xe0, A3>>8);
ad9389b_wr(sd, 0x1d, A3);
ad9389b_wr_and_or(sd, 0x1e, 0xe0, A4>>8);
ad9389b_wr(sd, 0x1f, A4);
ad9389b_wr_and_or(sd, 0x20, 0xe0, B1>>8);
ad9389b_wr(sd, 0x21, B1);
ad9389b_wr_and_or(sd, 0x22, 0xe0, B2>>8);
ad9389b_wr(sd, 0x23, B2);
ad9389b_wr_and_or(sd, 0x24, 0xe0, B3>>8);
ad9389b_wr(sd, 0x25, B3);
ad9389b_wr_and_or(sd, 0x26, 0xe0, B4>>8);
ad9389b_wr(sd, 0x27, B4);
ad9389b_wr_and_or(sd, 0x28, 0xe0, C1>>8);
ad9389b_wr(sd, 0x29, C1);
ad9389b_wr_and_or(sd, 0x2A, 0xe0, C2>>8);
ad9389b_wr(sd, 0x2B, C2);
ad9389b_wr_and_or(sd, 0x2C, 0xe0, C3>>8);
ad9389b_wr(sd, 0x2D, C3);
ad9389b_wr_and_or(sd, 0x2E, 0xe0, C4>>8);
ad9389b_wr(sd, 0x2F, C4);
}
static void ad9389b_csc_rgb_full2limit(struct v4l2_subdev *sd, bool enable)
{
if (enable) {
u8 csc_mode = 0;
ad9389b_csc_conversion_mode(sd, csc_mode);
ad9389b_csc_coeff(sd,
4096-564, 0, 0, 256,
0, 4096-564, 0, 256,
0, 0, 4096-564, 256);
ad9389b_wr_and_or(sd, 0x3b, 0xfe, 0x1);
ad9389b_wr_and_or(sd, 0xcd, 0xf9, 0x02);
} else {
ad9389b_wr_and_or(sd, 0x3b, 0xfe, 0x0);
ad9389b_wr_and_or(sd, 0xcd, 0xf9, 0x04);
}
}
static void ad9389b_set_IT_content_AVI_InfoFrame(struct v4l2_subdev *sd)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
if (state->dv_timings.bt.standards & V4L2_DV_BT_STD_CEA861) {
ad9389b_wr_and_or(sd, 0xcd, 0xbf, 0x00);
} else {
ad9389b_wr_and_or(sd, 0xcd, 0xbf, 0x40);
}
}
static int ad9389b_set_rgb_quantization_mode(struct v4l2_subdev *sd, struct v4l2_ctrl *ctrl)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
switch (ctrl->val) {
case V4L2_DV_RGB_RANGE_AUTO:
if (state->dv_timings.bt.standards & V4L2_DV_BT_STD_CEA861) {
ad9389b_csc_rgb_full2limit(sd, true);
} else {
ad9389b_csc_rgb_full2limit(sd, false);
}
break;
case V4L2_DV_RGB_RANGE_LIMITED:
ad9389b_csc_rgb_full2limit(sd, true);
break;
case V4L2_DV_RGB_RANGE_FULL:
ad9389b_csc_rgb_full2limit(sd, false);
break;
default:
return -EINVAL;
}
return 0;
}
static void ad9389b_set_manual_pll_gear(struct v4l2_subdev *sd, u32 pixelclock)
{
u8 gear;
if (pixelclock > 140000000)
gear = 0xc0;
else if (pixelclock > 117000000)
gear = 0xb0;
else if (pixelclock > 87000000)
gear = 0xa0;
else if (pixelclock > 60000000)
gear = 0x90;
else
gear = 0x80;
ad9389b_wr_and_or(sd, 0x98, 0x0f, gear);
}
static int ad9389b_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct ad9389b_state *state = get_ad9389b_state(sd);
v4l2_dbg(1, debug, sd,
"%s: ctrl id: %d, ctrl->val %d\n", __func__, ctrl->id, ctrl->val);
if (state->hdmi_mode_ctrl == ctrl) {
ad9389b_wr_and_or(sd, 0xaf, 0xfd,
ctrl->val == V4L2_DV_TX_MODE_HDMI ? 0x02 : 0x00);
return 0;
}
if (state->rgb_quantization_range_ctrl == ctrl)
return ad9389b_set_rgb_quantization_mode(sd, ctrl);
return -EINVAL;
}
static int ad9389b_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
reg->val = ad9389b_rd(sd, reg->reg & 0xff);
reg->size = 1;
return 0;
}
static int ad9389b_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
ad9389b_wr(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int ad9389b_log_status(struct v4l2_subdev *sd)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
struct ad9389b_state_edid *edid = &state->edid;
static const char * const states[] = {
"in reset",
"reading EDID",
"idle",
"initializing HDCP",
"HDCP enabled",
"initializing HDCP repeater",
"6", "7", "8", "9", "A", "B", "C", "D", "E", "F"
};
static const char * const errors[] = {
"no error",
"bad receiver BKSV",
"Ri mismatch",
"Pj mismatch",
"i2c error",
"timed out",
"max repeater cascade exceeded",
"hash check failed",
"too many devices",
"9", "A", "B", "C", "D", "E", "F"
};
u8 manual_gear;
v4l2_info(sd, "chip revision %d\n", state->chip_revision);
v4l2_info(sd, "power %s\n", state->power_on ? "on" : "off");
v4l2_info(sd, "%s hotplug, %s Rx Sense, %s EDID (%d block(s))\n",
(ad9389b_rd(sd, 0x42) & MASK_AD9389B_HPD_DETECT) ?
"detected" : "no",
(ad9389b_rd(sd, 0x42) & MASK_AD9389B_MSEN_DETECT) ?
"detected" : "no",
edid->segments ? "found" : "no", edid->blocks);
if (state->have_monitor) {
v4l2_info(sd, "%s output %s\n",
(ad9389b_rd(sd, 0xaf) & 0x02) ?
"HDMI" : "DVI-D",
(ad9389b_rd(sd, 0xa1) & 0x3c) ?
"disabled" : "enabled");
}
v4l2_info(sd, "ad9389b: %s\n", (ad9389b_rd(sd, 0xb8) & 0x40) ?
"encrypted" : "no encryption");
v4l2_info(sd, "state: %s, error: %s, detect count: %u, msk/irq: %02x/%02x\n",
states[ad9389b_rd(sd, 0xc8) & 0xf],
errors[ad9389b_rd(sd, 0xc8) >> 4],
state->edid_detect_counter,
ad9389b_rd(sd, 0x94), ad9389b_rd(sd, 0x96));
manual_gear = ad9389b_rd(sd, 0x98) & 0x80;
v4l2_info(sd, "ad9389b: RGB quantization: %s range\n",
ad9389b_rd(sd, 0x3b) & 0x01 ? "limited" : "full");
v4l2_info(sd, "ad9389b: %s gear %d\n",
manual_gear ? "manual" : "automatic",
manual_gear ? ((ad9389b_rd(sd, 0x98) & 0x70) >> 4) :
((ad9389b_rd(sd, 0x9e) & 0x0e) >> 1));
if (state->have_monitor) {
if (ad9389b_rd(sd, 0xaf) & 0x02) {
u8 manual_cts = ad9389b_rd(sd, 0x0a) & 0x80;
u32 N = (ad9389b_rd(sd, 0x01) & 0xf) << 16 |
ad9389b_rd(sd, 0x02) << 8 |
ad9389b_rd(sd, 0x03);
u8 vic_detect = ad9389b_rd(sd, 0x3e) >> 2;
u8 vic_sent = ad9389b_rd(sd, 0x3d) & 0x3f;
u32 CTS;
if (manual_cts)
CTS = (ad9389b_rd(sd, 0x07) & 0xf) << 16 |
ad9389b_rd(sd, 0x08) << 8 |
ad9389b_rd(sd, 0x09);
else
CTS = (ad9389b_rd(sd, 0x04) & 0xf) << 16 |
ad9389b_rd(sd, 0x05) << 8 |
ad9389b_rd(sd, 0x06);
N = (ad9389b_rd(sd, 0x01) & 0xf) << 16 |
ad9389b_rd(sd, 0x02) << 8 |
ad9389b_rd(sd, 0x03);
v4l2_info(sd, "ad9389b: CTS %s mode: N %d, CTS %d\n",
manual_cts ? "manual" : "automatic", N, CTS);
v4l2_info(sd, "ad9389b: VIC: detected %d, sent %d\n",
vic_detect, vic_sent);
}
}
if (state->dv_timings.type == V4L2_DV_BT_656_1120) {
struct v4l2_bt_timings *bt = bt = &state->dv_timings.bt;
u32 frame_width = bt->width + bt->hfrontporch +
bt->hsync + bt->hbackporch;
u32 frame_height = bt->height + bt->vfrontporch +
bt->vsync + bt->vbackporch;
u32 frame_size = frame_width * frame_height;
v4l2_info(sd, "timings: %ux%u%s%u (%ux%u). Pix freq. = %u Hz. Polarities = 0x%x\n",
bt->width, bt->height, bt->interlaced ? "i" : "p",
frame_size > 0 ? (unsigned)bt->pixelclock / frame_size : 0,
frame_width, frame_height,
(unsigned)bt->pixelclock, bt->polarities);
} else {
v4l2_info(sd, "no timings set\n");
}
return 0;
}
static int ad9389b_s_power(struct v4l2_subdev *sd, int on)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
struct ad9389b_platform_data *pdata = &state->pdata;
const int retries = 20;
int i;
v4l2_dbg(1, debug, sd, "%s: power %s\n", __func__, on ? "on" : "off");
state->power_on = on;
if (!on) {
ad9389b_wr_and_or(sd, 0x41, 0xbf, 0x40);
return true;
}
for (i = 0; i < retries; i++) {
ad9389b_wr_and_or(sd, 0x41, 0xbf, 0x0);
if ((ad9389b_rd(sd, 0x41) & 0x40) == 0)
break;
ad9389b_wr_and_or(sd, 0x41, 0xbf, 0x40);
msleep(10);
}
if (i == retries) {
v4l2_dbg(1, debug, sd, "failed to powerup the ad9389b\n");
ad9389b_s_power(sd, 0);
return false;
}
if (i > 1)
v4l2_dbg(1, debug, sd,
"needed %d retries to powerup the ad9389b\n", i);
ad9389b_wr_and_or(sd, 0xba, 0xef, 0x10);
ad9389b_wr_and_or(sd, 0x98, 0xf0, 0x07);
ad9389b_wr(sd, 0x9c, 0x38);
ad9389b_wr_and_or(sd, 0x9d, 0xfc, 0x01);
if (pdata->diff_data_drive_strength > 0)
ad9389b_wr(sd, 0xa2, pdata->diff_data_drive_strength);
else
ad9389b_wr(sd, 0xa2, 0x87);
if (pdata->diff_clk_drive_strength > 0)
ad9389b_wr(sd, 0xa3, pdata->diff_clk_drive_strength);
else
ad9389b_wr(sd, 0xa3, 0x87);
ad9389b_wr(sd, 0x0a, 0x01);
ad9389b_wr(sd, 0xbb, 0xff);
ad9389b_wr(sd, 0xc9, 0xf);
return true;
}
static void ad9389b_set_isr(struct v4l2_subdev *sd, bool enable)
{
u8 irqs = MASK_AD9389B_HPD_INT | MASK_AD9389B_MSEN_INT;
u8 irqs_rd;
int retries = 100;
if (!enable)
irqs = 0;
else if (ad9389b_have_hotplug(sd))
irqs |= MASK_AD9389B_EDID_RDY_INT;
do {
ad9389b_wr(sd, 0x94, irqs);
irqs_rd = ad9389b_rd(sd, 0x94);
} while (retries-- && irqs_rd != irqs);
if (irqs_rd != irqs)
v4l2_err(sd, "Could not set interrupts: hw failure?\n");
}
static int ad9389b_isr(struct v4l2_subdev *sd, u32 status, bool *handled)
{
u8 irq_status;
ad9389b_set_isr(sd, false);
irq_status = ad9389b_rd(sd, 0x96);
ad9389b_wr(sd, 0x96, irq_status);
if (irq_status & (MASK_AD9389B_HPD_INT | MASK_AD9389B_MSEN_INT))
ad9389b_check_monitor_present_status(sd);
if (irq_status & MASK_AD9389B_EDID_RDY_INT)
ad9389b_check_edid_status(sd);
ad9389b_set_isr(sd, true);
*handled = true;
return 0;
}
static int ad9389b_get_edid(struct v4l2_subdev *sd, struct v4l2_subdev_edid *edid)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
if (edid->pad != 0)
return -EINVAL;
if (edid->blocks == 0 || edid->blocks > 256)
return -EINVAL;
if (!edid->edid)
return -EINVAL;
if (!state->edid.segments) {
v4l2_dbg(1, debug, sd, "EDID segment 0 not found\n");
return -ENODATA;
}
if (edid->start_block >= state->edid.segments * 2)
return -E2BIG;
if (edid->blocks + edid->start_block >= state->edid.segments * 2)
edid->blocks = state->edid.segments * 2 - edid->start_block;
memcpy(edid->edid, &state->edid.data[edid->start_block * 128],
128 * edid->blocks);
return 0;
}
static int ad9389b_s_stream(struct v4l2_subdev *sd, int enable)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
v4l2_dbg(1, debug, sd, "%s: %sable\n", __func__, (enable ? "en" : "dis"));
ad9389b_wr_and_or(sd, 0xa1, ~0x3c, (enable ? 0 : 0x3c));
if (enable) {
ad9389b_check_monitor_present_status(sd);
} else {
ad9389b_s_power(sd, 0);
state->have_monitor = false;
}
return 0;
}
static int ad9389b_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
int i;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (timings->type != V4L2_DV_BT_656_1120)
return -EINVAL;
if (timings->bt.interlaced)
return -EINVAL;
if (timings->bt.pixelclock < 27000000 ||
timings->bt.pixelclock > 170000000)
return -EINVAL;
for (i = 0; ad9389b_timings[i].bt.width; i++) {
if (v4l_match_dv_timings(timings, &ad9389b_timings[i], 0)) {
*timings = ad9389b_timings[i];
break;
}
}
timings->bt.flags &= ~V4L2_DV_FL_REDUCED_FPS;
state->dv_timings = *timings;
ad9389b_set_rgb_quantization_mode(sd, state->rgb_quantization_range_ctrl);
if (state->pdata.tmds_pll_gear == AD9389B_TMDS_PLL_GEAR_SEMI_AUTOMATIC)
ad9389b_set_manual_pll_gear(sd, (u32)timings->bt.pixelclock);
ad9389b_set_IT_content_AVI_InfoFrame(sd);
return 0;
}
static int ad9389b_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (!timings)
return -EINVAL;
*timings = state->dv_timings;
return 0;
}
static int ad9389b_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
if (timings->index >= ARRAY_SIZE(ad9389b_timings))
return -EINVAL;
memset(timings->reserved, 0, sizeof(timings->reserved));
timings->timings = ad9389b_timings[timings->index];
return 0;
}
static int ad9389b_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
cap->type = V4L2_DV_BT_656_1120;
cap->bt.max_width = 1920;
cap->bt.max_height = 1200;
cap->bt.min_pixelclock = 27000000;
cap->bt.max_pixelclock = 170000000;
cap->bt.standards = V4L2_DV_BT_STD_CEA861 | V4L2_DV_BT_STD_DMT |
V4L2_DV_BT_STD_GTF | V4L2_DV_BT_STD_CVT;
cap->bt.capabilities = V4L2_DV_BT_CAP_PROGRESSIVE |
V4L2_DV_BT_CAP_REDUCED_BLANKING | V4L2_DV_BT_CAP_CUSTOM;
return 0;
}
static int ad9389b_s_audio_stream(struct v4l2_subdev *sd, int enable)
{
v4l2_dbg(1, debug, sd, "%s: %sable\n", __func__, (enable ? "en" : "dis"));
if (enable)
ad9389b_wr_and_or(sd, 0x45, 0x3f, 0x80);
else
ad9389b_wr_and_or(sd, 0x45, 0x3f, 0x40);
return 0;
}
static int ad9389b_s_clock_freq(struct v4l2_subdev *sd, u32 freq)
{
u32 N;
switch (freq) {
case 32000: N = 4096; break;
case 44100: N = 6272; break;
case 48000: N = 6144; break;
case 88200: N = 12544; break;
case 96000: N = 12288; break;
case 176400: N = 25088; break;
case 192000: N = 24576; break;
default:
return -EINVAL;
}
ad9389b_wr(sd, 0x01, (N >> 16) & 0xf);
ad9389b_wr(sd, 0x02, (N >> 8) & 0xff);
ad9389b_wr(sd, 0x03, N & 0xff);
return 0;
}
static int ad9389b_s_i2s_clock_freq(struct v4l2_subdev *sd, u32 freq)
{
u32 i2s_sf;
switch (freq) {
case 32000: i2s_sf = 0x30; break;
case 44100: i2s_sf = 0x00; break;
case 48000: i2s_sf = 0x20; break;
case 88200: i2s_sf = 0x80; break;
case 96000: i2s_sf = 0xa0; break;
case 176400: i2s_sf = 0xc0; break;
case 192000: i2s_sf = 0xe0; break;
default:
return -EINVAL;
}
ad9389b_wr_and_or(sd, 0x15, 0xf, i2s_sf);
return 0;
}
static int ad9389b_s_routing(struct v4l2_subdev *sd, u32 input, u32 output, u32 config)
{
ad9389b_wr_and_or(sd, 0x50, 0x1f, 0x20);
ad9389b_wr(sd, 0x51, 0x00);
ad9389b_wr_and_or(sd, 0x14, 0xf0, 0x02);
return 0;
}
static void ad9389b_dbg_dump_edid(int lvl, int debug, struct v4l2_subdev *sd,
int segment, u8 *buf)
{
int i, j;
if (debug < lvl)
return;
v4l2_dbg(lvl, debug, sd, "edid segment %d\n", segment);
for (i = 0; i < 256; i += 16) {
u8 b[128];
u8 *bp = b;
if (i == 128)
v4l2_dbg(lvl, debug, sd, "\n");
for (j = i; j < i + 16; j++) {
sprintf(bp, "0x%02x, ", buf[j]);
bp += 6;
}
bp[0] = '\0';
v4l2_dbg(lvl, debug, sd, "%s\n", b);
}
}
static void ad9389b_edid_handler(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct ad9389b_state *state = container_of(dwork,
struct ad9389b_state, edid_handler);
struct v4l2_subdev *sd = &state->sd;
struct ad9389b_edid_detect ed;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (ad9389b_check_edid_status(sd)) {
return;
}
if (ad9389b_have_hotplug(sd)) {
if (state->edid.read_retries) {
state->edid.read_retries--;
ad9389b_wr(sd, 0xc9, 0xf);
queue_delayed_work(state->work_queue,
&state->edid_handler, EDID_DELAY);
return;
}
}
ed.present = false;
ed.segment = ad9389b_rd(sd, 0xc4);
v4l2_subdev_notify(sd, AD9389B_EDID_DETECT, (void *)&ed);
v4l2_dbg(1, debug, sd, "%s: no edid found\n", __func__);
}
static void ad9389b_audio_setup(struct v4l2_subdev *sd)
{
v4l2_dbg(1, debug, sd, "%s\n", __func__);
ad9389b_s_i2s_clock_freq(sd, 48000);
ad9389b_s_clock_freq(sd, 48000);
ad9389b_s_routing(sd, 0, 0, 0);
}
static void ad9389b_setup(struct v4l2_subdev *sd)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
v4l2_dbg(1, debug, sd, "%s\n", __func__);
ad9389b_wr_and_or(sd, 0x15, 0xf1, 0x0);
ad9389b_wr_and_or(sd, 0x16, 0x3f, 0x0);
ad9389b_wr_and_or(sd, 0x17, 0xe1, 0x0e);
ad9389b_wr_and_or(sd, 0x3b, 0x9e, 0x0);
ad9389b_wr_and_or(sd, 0x45, 0xc7, 0x08);
ad9389b_wr_and_or(sd, 0x46, 0x3f, 0x80);
ad9389b_wr(sd, 0x3c, 0x0);
ad9389b_wr(sd, 0x47, 0x80);
ad9389b_wr_and_or(sd, 0xaf, 0xef, 0x0);
ad9389b_wr_and_or(sd, 0xba, 0x1f, 0x60);
ad9389b_audio_setup(sd);
v4l2_ctrl_handler_setup(&state->hdl);
ad9389b_set_IT_content_AVI_InfoFrame(sd);
}
static void ad9389b_notify_monitor_detect(struct v4l2_subdev *sd)
{
struct ad9389b_monitor_detect mdt;
struct ad9389b_state *state = get_ad9389b_state(sd);
mdt.present = state->have_monitor;
v4l2_subdev_notify(sd, AD9389B_MONITOR_DETECT, (void *)&mdt);
}
static void ad9389b_check_monitor_present_status(struct v4l2_subdev *sd)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
u8 status = ad9389b_rd(sd, 0x42);
v4l2_dbg(1, debug, sd, "%s: status: 0x%x%s%s\n",
__func__,
status,
status & MASK_AD9389B_HPD_DETECT ? ", hotplug" : "",
status & MASK_AD9389B_MSEN_DETECT ? ", rx-sense" : "");
if ((status & MASK_AD9389B_HPD_DETECT) &&
((status & MASK_AD9389B_MSEN_DETECT) || state->edid.segments)) {
v4l2_dbg(1, debug, sd,
"%s: hotplug and (rx-sense or edid)\n", __func__);
if (!state->have_monitor) {
v4l2_dbg(1, debug, sd, "%s: monitor detected\n", __func__);
state->have_monitor = true;
ad9389b_set_isr(sd, true);
if (!ad9389b_s_power(sd, true)) {
v4l2_dbg(1, debug, sd,
"%s: monitor detected, powerup failed\n", __func__);
return;
}
ad9389b_setup(sd);
ad9389b_notify_monitor_detect(sd);
state->edid.read_retries = EDID_MAX_RETRIES;
queue_delayed_work(state->work_queue,
&state->edid_handler, EDID_DELAY);
}
} else if (status & MASK_AD9389B_HPD_DETECT) {
v4l2_dbg(1, debug, sd, "%s: hotplug detected\n", __func__);
state->edid.read_retries = EDID_MAX_RETRIES;
queue_delayed_work(state->work_queue,
&state->edid_handler, EDID_DELAY);
} else if (!(status & MASK_AD9389B_HPD_DETECT)) {
v4l2_dbg(1, debug, sd, "%s: hotplug not detected\n", __func__);
if (state->have_monitor) {
v4l2_dbg(1, debug, sd, "%s: monitor not detected\n", __func__);
state->have_monitor = false;
ad9389b_notify_monitor_detect(sd);
}
ad9389b_s_power(sd, false);
memset(&state->edid, 0, sizeof(struct ad9389b_state_edid));
}
v4l2_ctrl_s_ctrl(state->hotplug_ctrl, ad9389b_have_hotplug(sd) ? 0x1 : 0x0);
v4l2_ctrl_s_ctrl(state->rx_sense_ctrl, ad9389b_have_rx_sense(sd) ? 0x1 : 0x0);
v4l2_ctrl_s_ctrl(state->have_edid0_ctrl, state->edid.segments ? 0x1 : 0x0);
}
static bool edid_block_verify_crc(u8 *edid_block)
{
int i;
u8 sum = 0;
for (i = 0; i < 127; i++)
sum += *(edid_block + i);
return ((255 - sum + 1) == edid_block[127]);
}
static bool edid_segment_verify_crc(struct v4l2_subdev *sd, u32 segment)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
u32 blocks = state->edid.blocks;
u8 *data = state->edid.data;
if (edid_block_verify_crc(&data[segment * 256])) {
if ((segment + 1) * 2 <= blocks)
return edid_block_verify_crc(&data[segment * 256 + 128]);
return true;
}
return false;
}
static bool ad9389b_check_edid_status(struct v4l2_subdev *sd)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
struct ad9389b_edid_detect ed;
int segment;
u8 edidRdy = ad9389b_rd(sd, 0xc5);
v4l2_dbg(1, debug, sd, "%s: edid ready (retries: %d)\n",
__func__, EDID_MAX_RETRIES - state->edid.read_retries);
if (!(edidRdy & MASK_AD9389B_EDID_RDY))
return false;
segment = ad9389b_rd(sd, 0xc4);
if (segment >= EDID_MAX_SEGM) {
v4l2_err(sd, "edid segment number too big\n");
return false;
}
v4l2_dbg(1, debug, sd, "%s: got segment %d\n", __func__, segment);
ad9389b_edid_rd(sd, 256, &state->edid.data[segment * 256]);
ad9389b_dbg_dump_edid(2, debug, sd, segment,
&state->edid.data[segment * 256]);
if (segment == 0) {
state->edid.blocks = state->edid.data[0x7e] + 1;
v4l2_dbg(1, debug, sd, "%s: %d blocks in total\n",
__func__, state->edid.blocks);
}
if (!edid_segment_verify_crc(sd, segment)) {
ad9389b_s_power(sd, false);
ad9389b_s_power(sd, true);
return false;
}
state->edid.segments = segment + 1;
if (((state->edid.data[0x7e] >> 1) + 1) > state->edid.segments) {
v4l2_dbg(1, debug, sd, "%s: request segment %d\n",
__func__, state->edid.segments);
ad9389b_wr(sd, 0xc9, 0xf);
ad9389b_wr(sd, 0xc4, state->edid.segments);
state->edid.read_retries = EDID_MAX_RETRIES;
queue_delayed_work(state->work_queue,
&state->edid_handler, EDID_DELAY);
return false;
}
ed.present = true;
ed.segment = 0;
v4l2_subdev_notify(sd, AD9389B_EDID_DETECT, (void *)&ed);
state->edid_detect_counter++;
v4l2_ctrl_s_ctrl(state->have_edid0_ctrl, state->edid.segments ? 0x1 : 0x0);
return ed.present;
}
static void ad9389b_init_setup(struct v4l2_subdev *sd)
{
struct ad9389b_state *state = get_ad9389b_state(sd);
struct ad9389b_state_edid *edid = &state->edid;
v4l2_dbg(1, debug, sd, "%s\n", __func__);
ad9389b_wr(sd, 0x96, 0xff);
memset(edid, 0, sizeof(struct ad9389b_state_edid));
state->have_monitor = false;
ad9389b_set_isr(sd, false);
}
static int ad9389b_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
const struct v4l2_dv_timings dv1080p60 = V4L2_DV_BT_CEA_1920X1080P60;
struct ad9389b_state *state;
struct ad9389b_platform_data *pdata = client->dev.platform_data;
struct v4l2_ctrl_handler *hdl;
struct v4l2_subdev *sd;
int err = -EIO;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_dbg(1, debug, client, "detecting ad9389b client on address 0x%x\n",
client->addr << 1);
state = devm_kzalloc(&client->dev, sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
if (pdata == NULL) {
v4l_err(client, "No platform data!\n");
return -ENODEV;
}
memcpy(&state->pdata, pdata, sizeof(state->pdata));
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &ad9389b_ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
hdl = &state->hdl;
v4l2_ctrl_handler_init(hdl, 5);
state->hdmi_mode_ctrl = v4l2_ctrl_new_std_menu(hdl, &ad9389b_ctrl_ops,
V4L2_CID_DV_TX_MODE, V4L2_DV_TX_MODE_HDMI,
0, V4L2_DV_TX_MODE_DVI_D);
state->hdmi_mode_ctrl->is_private = true;
state->hotplug_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_TX_HOTPLUG, 0, 1, 0, 0);
state->hotplug_ctrl->is_private = true;
state->rx_sense_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_TX_RXSENSE, 0, 1, 0, 0);
state->rx_sense_ctrl->is_private = true;
state->have_edid0_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_TX_EDID_PRESENT, 0, 1, 0, 0);
state->have_edid0_ctrl->is_private = true;
state->rgb_quantization_range_ctrl =
v4l2_ctrl_new_std_menu(hdl, &ad9389b_ctrl_ops,
V4L2_CID_DV_TX_RGB_RANGE, V4L2_DV_RGB_RANGE_FULL,
0, V4L2_DV_RGB_RANGE_AUTO);
state->rgb_quantization_range_ctrl->is_private = true;
sd->ctrl_handler = hdl;
if (hdl->error) {
err = hdl->error;
goto err_hdl;
}
state->pad.flags = MEDIA_PAD_FL_SINK;
err = media_entity_init(&sd->entity, 1, &state->pad, 0);
if (err)
goto err_hdl;
state->chip_revision = ad9389b_rd(sd, 0x0);
if (state->chip_revision != 2) {
v4l2_err(sd, "chip_revision %d != 2\n", state->chip_revision);
err = -EIO;
goto err_entity;
}
v4l2_dbg(1, debug, sd, "reg 0x41 0x%x, chip version (reg 0x00) 0x%x\n",
ad9389b_rd(sd, 0x41), state->chip_revision);
state->edid_i2c_client = i2c_new_dummy(client->adapter, (0x7e>>1));
if (state->edid_i2c_client == NULL) {
v4l2_err(sd, "failed to register edid i2c client\n");
err = -ENOMEM;
goto err_entity;
}
state->work_queue = create_singlethread_workqueue(sd->name);
if (state->work_queue == NULL) {
v4l2_err(sd, "could not create workqueue\n");
err = -ENOMEM;
goto err_unreg;
}
INIT_DELAYED_WORK(&state->edid_handler, ad9389b_edid_handler);
state->dv_timings = dv1080p60;
ad9389b_init_setup(sd);
ad9389b_set_isr(sd, true);
v4l2_info(sd, "%s found @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
return 0;
err_unreg:
i2c_unregister_device(state->edid_i2c_client);
err_entity:
media_entity_cleanup(&sd->entity);
err_hdl:
v4l2_ctrl_handler_free(&state->hdl);
return err;
}
static int ad9389b_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ad9389b_state *state = get_ad9389b_state(sd);
state->chip_revision = -1;
v4l2_dbg(1, debug, sd, "%s removed @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
ad9389b_s_stream(sd, false);
ad9389b_s_audio_stream(sd, false);
ad9389b_init_setup(sd);
cancel_delayed_work(&state->edid_handler);
i2c_unregister_device(state->edid_i2c_client);
destroy_workqueue(state->work_queue);
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
v4l2_ctrl_handler_free(sd->ctrl_handler);
return 0;
}
