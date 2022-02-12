static inline struct adv7511_state *get_adv7511_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7511_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct adv7511_state, hdl)->sd;
}
static s32 adv_smbus_read_byte_data_check(struct i2c_client *client,
u8 command, bool check)
{
union i2c_smbus_data data;
if (!i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, command,
I2C_SMBUS_BYTE_DATA, &data))
return data.byte;
if (check)
v4l_err(client, "error reading %02x, %02x\n",
client->addr, command);
return -1;
}
static s32 adv_smbus_read_byte_data(struct i2c_client *client, u8 command)
{
int i;
for (i = 0; i < 3; i++) {
int ret = adv_smbus_read_byte_data_check(client, command, true);
if (ret >= 0) {
if (i)
v4l_err(client, "read ok after %d retries\n", i);
return ret;
}
}
v4l_err(client, "read failed\n");
return -1;
}
static int adv7511_rd(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return adv_smbus_read_byte_data(client, reg);
}
static int adv7511_wr(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
int i;
for (i = 0; i < 3; i++) {
ret = i2c_smbus_write_byte_data(client, reg, val);
if (ret == 0)
return 0;
}
v4l2_err(sd, "%s: i2c write error\n", __func__);
return ret;
}
static inline void adv7511_wr_and_or(struct v4l2_subdev *sd, u8 reg, uint8_t clr_mask, uint8_t val_mask)
{
adv7511_wr(sd, reg, (adv7511_rd(sd, reg) & clr_mask) | val_mask);
}
static int adv_smbus_read_i2c_block_data(struct i2c_client *client,
u8 command, unsigned length, u8 *values)
{
union i2c_smbus_data data;
int ret;
if (length > I2C_SMBUS_BLOCK_MAX)
length = I2C_SMBUS_BLOCK_MAX;
data.block[0] = length;
ret = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_READ, command,
I2C_SMBUS_I2C_BLOCK_DATA, &data);
memcpy(values, data.block + 1, length);
return ret;
}
static inline void adv7511_edid_rd(struct v4l2_subdev *sd, uint16_t len, uint8_t *buf)
{
struct adv7511_state *state = get_adv7511_state(sd);
int i;
int err = 0;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
for (i = 0; !err && i < len; i += I2C_SMBUS_BLOCK_MAX)
err = adv_smbus_read_i2c_block_data(state->i2c_edid, i,
I2C_SMBUS_BLOCK_MAX, buf + i);
if (err)
v4l2_err(sd, "%s: i2c read error\n", __func__);
}
static inline bool adv7511_have_hotplug(struct v4l2_subdev *sd)
{
return adv7511_rd(sd, 0x42) & MASK_ADV7511_HPD_DETECT;
}
static inline bool adv7511_have_rx_sense(struct v4l2_subdev *sd)
{
return adv7511_rd(sd, 0x42) & MASK_ADV7511_MSEN_DETECT;
}
static void adv7511_csc_conversion_mode(struct v4l2_subdev *sd, uint8_t mode)
{
adv7511_wr_and_or(sd, 0x18, 0x9f, (mode & 0x3)<<5);
}
static void adv7511_csc_coeff(struct v4l2_subdev *sd,
u16 A1, u16 A2, u16 A3, u16 A4,
u16 B1, u16 B2, u16 B3, u16 B4,
u16 C1, u16 C2, u16 C3, u16 C4)
{
adv7511_wr_and_or(sd, 0x18, 0xe0, A1>>8);
adv7511_wr(sd, 0x19, A1);
adv7511_wr_and_or(sd, 0x1A, 0xe0, A2>>8);
adv7511_wr(sd, 0x1B, A2);
adv7511_wr_and_or(sd, 0x1c, 0xe0, A3>>8);
adv7511_wr(sd, 0x1d, A3);
adv7511_wr_and_or(sd, 0x1e, 0xe0, A4>>8);
adv7511_wr(sd, 0x1f, A4);
adv7511_wr_and_or(sd, 0x20, 0xe0, B1>>8);
adv7511_wr(sd, 0x21, B1);
adv7511_wr_and_or(sd, 0x22, 0xe0, B2>>8);
adv7511_wr(sd, 0x23, B2);
adv7511_wr_and_or(sd, 0x24, 0xe0, B3>>8);
adv7511_wr(sd, 0x25, B3);
adv7511_wr_and_or(sd, 0x26, 0xe0, B4>>8);
adv7511_wr(sd, 0x27, B4);
adv7511_wr_and_or(sd, 0x28, 0xe0, C1>>8);
adv7511_wr(sd, 0x29, C1);
adv7511_wr_and_or(sd, 0x2A, 0xe0, C2>>8);
adv7511_wr(sd, 0x2B, C2);
adv7511_wr_and_or(sd, 0x2C, 0xe0, C3>>8);
adv7511_wr(sd, 0x2D, C3);
adv7511_wr_and_or(sd, 0x2E, 0xe0, C4>>8);
adv7511_wr(sd, 0x2F, C4);
}
static void adv7511_csc_rgb_full2limit(struct v4l2_subdev *sd, bool enable)
{
if (enable) {
uint8_t csc_mode = 0;
adv7511_csc_conversion_mode(sd, csc_mode);
adv7511_csc_coeff(sd,
4096-564, 0, 0, 256,
0, 4096-564, 0, 256,
0, 0, 4096-564, 256);
adv7511_wr_and_or(sd, 0x18, 0x7f, 0x80);
adv7511_wr_and_or(sd, 0x57, 0xf3, 0x04);
} else {
adv7511_wr_and_or(sd, 0x18, 0x7f, 0x0);
adv7511_wr_and_or(sd, 0x57, 0xf3, 0x08);
}
}
static void adv7511_set_IT_content_AVI_InfoFrame(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
if (state->dv_timings.bt.standards & V4L2_DV_BT_STD_CEA861) {
adv7511_wr_and_or(sd, 0x57, 0x7f, 0x00);
} else {
adv7511_wr_and_or(sd, 0x57, 0x7f, 0x80);
}
}
static int adv7511_set_rgb_quantization_mode(struct v4l2_subdev *sd, struct v4l2_ctrl *ctrl)
{
switch (ctrl->val) {
default:
return -EINVAL;
break;
case V4L2_DV_RGB_RANGE_AUTO: {
struct adv7511_state *state = get_adv7511_state(sd);
if (state->dv_timings.bt.standards & V4L2_DV_BT_STD_CEA861) {
adv7511_csc_rgb_full2limit(sd, true);
} else {
adv7511_csc_rgb_full2limit(sd, false);
}
}
break;
case V4L2_DV_RGB_RANGE_LIMITED:
adv7511_csc_rgb_full2limit(sd, true);
break;
case V4L2_DV_RGB_RANGE_FULL:
adv7511_csc_rgb_full2limit(sd, false);
break;
}
return 0;
}
static int adv7511_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct adv7511_state *state = get_adv7511_state(sd);
v4l2_dbg(1, debug, sd, "%s: ctrl id: %d, ctrl->val %d\n", __func__, ctrl->id, ctrl->val);
if (state->hdmi_mode_ctrl == ctrl) {
adv7511_wr_and_or(sd, 0xaf, 0xfd, ctrl->val == V4L2_DV_TX_MODE_HDMI ? 0x02 : 0x00);
return 0;
}
if (state->rgb_quantization_range_ctrl == ctrl)
return adv7511_set_rgb_quantization_mode(sd, ctrl);
return -EINVAL;
}
static void adv7511_inv_register(struct v4l2_subdev *sd)
{
v4l2_info(sd, "0x000-0x0ff: Main Map\n");
}
static int adv7511_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
reg->size = 1;
switch (reg->reg >> 8) {
case 0:
reg->val = adv7511_rd(sd, reg->reg & 0xff);
break;
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7511_inv_register(sd);
break;
}
return 0;
}
static int adv7511_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
switch (reg->reg >> 8) {
case 0:
adv7511_wr(sd, reg->reg & 0xff, reg->val & 0xff);
break;
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7511_inv_register(sd);
break;
}
return 0;
}
static int adv7511_log_status(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
struct adv7511_state_edid *edid = &state->edid;
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
v4l2_info(sd, "power %s\n", state->power_on ? "on" : "off");
v4l2_info(sd, "%s hotplug, %s Rx Sense, %s EDID (%d block(s))\n",
(adv7511_rd(sd, 0x42) & MASK_ADV7511_HPD_DETECT) ? "detected" : "no",
(adv7511_rd(sd, 0x42) & MASK_ADV7511_MSEN_DETECT) ? "detected" : "no",
edid->segments ? "found" : "no",
edid->blocks);
v4l2_info(sd, "%s output %s\n",
(adv7511_rd(sd, 0xaf) & 0x02) ?
"HDMI" : "DVI-D",
(adv7511_rd(sd, 0xa1) & 0x3c) ?
"disabled" : "enabled");
v4l2_info(sd, "state: %s, error: %s, detect count: %u, msk/irq: %02x/%02x\n",
states[adv7511_rd(sd, 0xc8) & 0xf],
errors[adv7511_rd(sd, 0xc8) >> 4], state->edid_detect_counter,
adv7511_rd(sd, 0x94), adv7511_rd(sd, 0x96));
v4l2_info(sd, "RGB quantization: %s range\n", adv7511_rd(sd, 0x18) & 0x80 ? "limited" : "full");
if (adv7511_rd(sd, 0xaf) & 0x02) {
u8 manual_cts = adv7511_rd(sd, 0x0a) & 0x80;
u32 N = (adv7511_rd(sd, 0x01) & 0xf) << 16 |
adv7511_rd(sd, 0x02) << 8 |
adv7511_rd(sd, 0x03);
u8 vic_detect = adv7511_rd(sd, 0x3e) >> 2;
u8 vic_sent = adv7511_rd(sd, 0x3d) & 0x3f;
u32 CTS;
if (manual_cts)
CTS = (adv7511_rd(sd, 0x07) & 0xf) << 16 |
adv7511_rd(sd, 0x08) << 8 |
adv7511_rd(sd, 0x09);
else
CTS = (adv7511_rd(sd, 0x04) & 0xf) << 16 |
adv7511_rd(sd, 0x05) << 8 |
adv7511_rd(sd, 0x06);
v4l2_info(sd, "CTS %s mode: N %d, CTS %d\n",
manual_cts ? "manual" : "automatic", N, CTS);
v4l2_info(sd, "VIC: detected %d, sent %d\n",
vic_detect, vic_sent);
}
if (state->dv_timings.type == V4L2_DV_BT_656_1120)
v4l2_print_dv_timings(sd->name, "timings: ",
&state->dv_timings, false);
else
v4l2_info(sd, "no timings set\n");
v4l2_info(sd, "i2c edid addr: 0x%x\n", state->i2c_edid_addr);
v4l2_info(sd, "i2c cec addr: 0x%x\n", state->i2c_cec_addr);
return 0;
}
static int adv7511_s_power(struct v4l2_subdev *sd, int on)
{
struct adv7511_state *state = get_adv7511_state(sd);
const int retries = 20;
int i;
v4l2_dbg(1, debug, sd, "%s: power %s\n", __func__, on ? "on" : "off");
state->power_on = on;
if (!on) {
adv7511_wr_and_or(sd, 0x41, 0xbf, 0x40);
return true;
}
for (i = 0; i < retries; i++) {
adv7511_wr_and_or(sd, 0x41, 0xbf, 0x0);
if ((adv7511_rd(sd, 0x41) & 0x40) == 0)
break;
adv7511_wr_and_or(sd, 0x41, 0xbf, 0x40);
msleep(10);
}
if (i == retries) {
v4l2_dbg(1, debug, sd, "%s: failed to powerup the adv7511!\n", __func__);
adv7511_s_power(sd, 0);
return false;
}
if (i > 1)
v4l2_dbg(1, debug, sd, "%s: needed %d retries to powerup the adv7511\n", __func__, i);
adv7511_wr(sd, 0x98, 0x03);
adv7511_wr_and_or(sd, 0x9a, 0xfe, 0x70);
adv7511_wr(sd, 0x9c, 0x30);
adv7511_wr_and_or(sd, 0x9d, 0xfc, 0x01);
adv7511_wr(sd, 0xa2, 0xa4);
adv7511_wr(sd, 0xa3, 0xa4);
adv7511_wr(sd, 0xe0, 0xd0);
adv7511_wr(sd, 0xf9, 0x00);
adv7511_wr(sd, 0x43, state->i2c_edid_addr);
adv7511_wr(sd, 0xc9, 0xf);
return true;
}
static void adv7511_set_isr(struct v4l2_subdev *sd, bool enable)
{
uint8_t irqs = MASK_ADV7511_HPD_INT | MASK_ADV7511_MSEN_INT;
uint8_t irqs_rd;
int retries = 100;
v4l2_dbg(2, debug, sd, "%s: %s\n", __func__, enable ? "enable" : "disable");
if (!enable)
irqs = 0;
else if (adv7511_have_hotplug(sd))
irqs |= MASK_ADV7511_EDID_RDY_INT;
do {
adv7511_wr(sd, 0x94, irqs);
irqs_rd = adv7511_rd(sd, 0x94);
} while (retries-- && irqs_rd != irqs);
if (irqs_rd == irqs)
return;
v4l2_err(sd, "Could not set interrupts: hw failure?\n");
}
static int adv7511_isr(struct v4l2_subdev *sd, u32 status, bool *handled)
{
uint8_t irq_status;
adv7511_set_isr(sd, false);
irq_status = adv7511_rd(sd, 0x96);
adv7511_wr(sd, 0x96, irq_status);
v4l2_dbg(1, debug, sd, "%s: irq 0x%x\n", __func__, irq_status);
if (irq_status & (MASK_ADV7511_HPD_INT | MASK_ADV7511_MSEN_INT))
adv7511_check_monitor_present_status(sd);
if (irq_status & MASK_ADV7511_EDID_RDY_INT)
adv7511_check_edid_status(sd);
adv7511_set_isr(sd, true);
if (handled)
*handled = true;
return 0;
}
static int adv7511_get_edid(struct v4l2_subdev *sd, struct v4l2_subdev_edid *edid)
{
struct adv7511_state *state = get_adv7511_state(sd);
if (edid->pad != 0)
return -EINVAL;
if ((edid->blocks == 0) || (edid->blocks > 256))
return -EINVAL;
if (!edid->edid)
return -EINVAL;
if (!state->edid.segments) {
v4l2_dbg(1, debug, sd, "EDID segment 0 not found\n");
return -ENODATA;
}
if (edid->start_block >= state->edid.segments * 2)
return -E2BIG;
if ((edid->blocks + edid->start_block) >= state->edid.segments * 2)
edid->blocks = state->edid.segments * 2 - edid->start_block;
memcpy(edid->edid, &state->edid.data[edid->start_block * 128],
128 * edid->blocks);
return 0;
}
static int adv7511_s_stream(struct v4l2_subdev *sd, int enable)
{
struct adv7511_state *state = get_adv7511_state(sd);
v4l2_dbg(1, debug, sd, "%s: %sable\n", __func__, (enable ? "en" : "dis"));
adv7511_wr_and_or(sd, 0xa1, ~0x3c, (enable ? 0 : 0x3c));
if (enable) {
adv7511_check_monitor_present_status(sd);
} else {
adv7511_s_power(sd, 0);
state->have_monitor = false;
}
return 0;
}
static int adv7511_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7511_state *state = get_adv7511_state(sd);
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (!v4l2_valid_dv_timings(timings, &adv7511_timings_cap, NULL, NULL))
return -EINVAL;
v4l2_find_dv_timings_cap(timings, &adv7511_timings_cap, 0, NULL, NULL);
timings->bt.flags &= ~V4L2_DV_FL_REDUCED_FPS;
state->dv_timings = *timings;
adv7511_set_rgb_quantization_mode(sd, state->rgb_quantization_range_ctrl);
adv7511_set_IT_content_AVI_InfoFrame(sd);
return 0;
}
static int adv7511_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7511_state *state = get_adv7511_state(sd);
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (!timings)
return -EINVAL;
*timings = state->dv_timings;
return 0;
}
static int adv7511_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
return v4l2_enum_dv_timings_cap(timings, &adv7511_timings_cap, NULL, NULL);
}
static int adv7511_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
*cap = adv7511_timings_cap;
return 0;
}
static int adv7511_s_audio_stream(struct v4l2_subdev *sd, int enable)
{
v4l2_dbg(1, debug, sd, "%s: %sable\n", __func__, (enable ? "en" : "dis"));
if (enable)
adv7511_wr_and_or(sd, 0x4b, 0x3f, 0x80);
else
adv7511_wr_and_or(sd, 0x4b, 0x3f, 0x40);
return 0;
}
static int adv7511_s_clock_freq(struct v4l2_subdev *sd, u32 freq)
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
adv7511_wr(sd, 0x01, (N >> 16) & 0xf);
adv7511_wr(sd, 0x02, (N >> 8) & 0xff);
adv7511_wr(sd, 0x03, N & 0xff);
return 0;
}
static int adv7511_s_i2s_clock_freq(struct v4l2_subdev *sd, u32 freq)
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
adv7511_wr_and_or(sd, 0x15, 0xf, i2s_sf);
return 0;
}
static int adv7511_s_routing(struct v4l2_subdev *sd, u32 input, u32 output, u32 config)
{
adv7511_wr_and_or(sd, 0x73, 0xf8, 0x1);
adv7511_wr(sd, 0x76, 0x00);
adv7511_wr_and_or(sd, 0x14, 0xf0, 0x02);
return 0;
}
static void adv7511_dbg_dump_edid(int lvl, int debug, struct v4l2_subdev *sd, int segment, uint8_t *buf)
{
if (debug >= lvl) {
int i, j;
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
}
static void adv7511_edid_handler(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct adv7511_state *state = container_of(dwork, struct adv7511_state, edid_handler);
struct v4l2_subdev *sd = &state->sd;
struct adv7511_edid_detect ed;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (adv7511_check_edid_status(sd)) {
return;
}
if (adv7511_have_hotplug(sd)) {
if (state->edid.read_retries) {
state->edid.read_retries--;
v4l2_dbg(1, debug, sd, "%s: edid read failed\n", __func__);
state->have_monitor = false;
adv7511_s_power(sd, false);
adv7511_s_power(sd, true);
queue_delayed_work(state->work_queue, &state->edid_handler, EDID_DELAY);
return;
}
}
ed.present = false;
ed.segment = adv7511_rd(sd, 0xc4);
v4l2_subdev_notify(sd, ADV7511_EDID_DETECT, (void *)&ed);
v4l2_dbg(1, debug, sd, "%s: no edid found\n", __func__);
}
static void adv7511_audio_setup(struct v4l2_subdev *sd)
{
v4l2_dbg(1, debug, sd, "%s\n", __func__);
adv7511_s_i2s_clock_freq(sd, 48000);
adv7511_s_clock_freq(sd, 48000);
adv7511_s_routing(sd, 0, 0, 0);
}
static void adv7511_setup(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
v4l2_dbg(1, debug, sd, "%s\n", __func__);
adv7511_wr_and_or(sd, 0x15, 0xf0, 0x0);
adv7511_wr_and_or(sd, 0x16, 0x7f, 0x0);
adv7511_wr_and_or(sd, 0x17, 0xf9, 0x06);
adv7511_wr_and_or(sd, 0x3b, 0x9f, 0x0);
adv7511_wr_and_or(sd, 0x18, 0x7f, 0x0);
adv7511_wr_and_or(sd, 0x55, 0x9c, 0x12);
adv7511_wr_and_or(sd, 0x44, 0xe7, 0x10);
adv7511_wr(sd, 0x56, 0xa8);
adv7511_wr_and_or(sd, 0xaf, 0xed, 0x0);
adv7511_wr_and_or(sd, 0xba, 0x1f, 0x60);
adv7511_audio_setup(sd);
v4l2_ctrl_handler_setup(&state->hdl);
}
static void adv7511_notify_monitor_detect(struct v4l2_subdev *sd)
{
struct adv7511_monitor_detect mdt;
struct adv7511_state *state = get_adv7511_state(sd);
mdt.present = state->have_monitor;
v4l2_subdev_notify(sd, ADV7511_MONITOR_DETECT, (void *)&mdt);
}
static void adv7511_check_monitor_present_status(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
uint8_t status = adv7511_rd(sd, 0x42);
v4l2_dbg(1, debug, sd, "%s: status: 0x%x%s%s\n",
__func__,
status,
status & MASK_ADV7511_HPD_DETECT ? ", hotplug" : "",
status & MASK_ADV7511_MSEN_DETECT ? ", rx-sense" : "");
v4l2_ctrl_s_ctrl(state->hotplug_ctrl, adv7511_have_hotplug(sd) ? 0x1 : 0x0);
v4l2_ctrl_s_ctrl(state->rx_sense_ctrl, adv7511_have_rx_sense(sd) ? 0x1 : 0x0);
v4l2_ctrl_s_ctrl(state->have_edid0_ctrl, state->edid.segments ? 0x1 : 0x0);
if ((status & MASK_ADV7511_HPD_DETECT) && ((status & MASK_ADV7511_MSEN_DETECT) || state->edid.segments)) {
v4l2_dbg(1, debug, sd, "%s: hotplug and (rx-sense or edid)\n", __func__);
if (!state->have_monitor) {
v4l2_dbg(1, debug, sd, "%s: monitor detected\n", __func__);
state->have_monitor = true;
adv7511_set_isr(sd, true);
if (!adv7511_s_power(sd, true)) {
v4l2_dbg(1, debug, sd, "%s: monitor detected, powerup failed\n", __func__);
return;
}
adv7511_setup(sd);
adv7511_notify_monitor_detect(sd);
state->edid.read_retries = EDID_MAX_RETRIES;
queue_delayed_work(state->work_queue, &state->edid_handler, EDID_DELAY);
}
} else if (status & MASK_ADV7511_HPD_DETECT) {
v4l2_dbg(1, debug, sd, "%s: hotplug detected\n", __func__);
state->edid.read_retries = EDID_MAX_RETRIES;
queue_delayed_work(state->work_queue, &state->edid_handler, EDID_DELAY);
} else if (!(status & MASK_ADV7511_HPD_DETECT)) {
v4l2_dbg(1, debug, sd, "%s: hotplug not detected\n", __func__);
if (state->have_monitor) {
v4l2_dbg(1, debug, sd, "%s: monitor not detected\n", __func__);
state->have_monitor = false;
adv7511_notify_monitor_detect(sd);
}
adv7511_s_power(sd, false);
memset(&state->edid, 0, sizeof(struct adv7511_state_edid));
}
}
static bool edid_block_verify_crc(uint8_t *edid_block)
{
uint8_t sum = 0;
int i;
for (i = 0; i < 128; i++)
sum += edid_block[i];
return sum == 0;
}
static bool edid_verify_crc(struct v4l2_subdev *sd, u32 segment)
{
struct adv7511_state *state = get_adv7511_state(sd);
u32 blocks = state->edid.blocks;
uint8_t *data = state->edid.data;
if (!edid_block_verify_crc(&data[segment * 256]))
return false;
if ((segment + 1) * 2 <= blocks)
return edid_block_verify_crc(&data[segment * 256 + 128]);
return true;
}
static bool edid_verify_header(struct v4l2_subdev *sd, u32 segment)
{
static const u8 hdmi_header[] = {
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00
};
struct adv7511_state *state = get_adv7511_state(sd);
u8 *data = state->edid.data;
if (segment != 0)
return true;
return !memcmp(data, hdmi_header, sizeof(hdmi_header));
}
static bool adv7511_check_edid_status(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
uint8_t edidRdy = adv7511_rd(sd, 0xc5);
v4l2_dbg(1, debug, sd, "%s: edid ready (retries: %d)\n",
__func__, EDID_MAX_RETRIES - state->edid.read_retries);
if (state->edid.complete)
return true;
if (edidRdy & MASK_ADV7511_EDID_RDY) {
int segment = adv7511_rd(sd, 0xc4);
struct adv7511_edid_detect ed;
if (segment >= EDID_MAX_SEGM) {
v4l2_err(sd, "edid segment number too big\n");
return false;
}
v4l2_dbg(1, debug, sd, "%s: got segment %d\n", __func__, segment);
adv7511_edid_rd(sd, 256, &state->edid.data[segment * 256]);
adv7511_dbg_dump_edid(2, debug, sd, segment, &state->edid.data[segment * 256]);
if (segment == 0) {
state->edid.blocks = state->edid.data[0x7e] + 1;
v4l2_dbg(1, debug, sd, "%s: %d blocks in total\n", __func__, state->edid.blocks);
}
if (!edid_verify_crc(sd, segment) ||
!edid_verify_header(sd, segment)) {
v4l2_err(sd, "%s: edid crc or header error\n", __func__);
state->have_monitor = false;
adv7511_s_power(sd, false);
adv7511_s_power(sd, true);
return false;
}
state->edid.segments = segment + 1;
if (((state->edid.data[0x7e] >> 1) + 1) > state->edid.segments) {
v4l2_dbg(1, debug, sd, "%s: request segment %d\n", __func__, state->edid.segments);
adv7511_wr(sd, 0xc9, 0xf);
adv7511_wr(sd, 0xc4, state->edid.segments);
state->edid.read_retries = EDID_MAX_RETRIES;
queue_delayed_work(state->work_queue, &state->edid_handler, EDID_DELAY);
return false;
}
v4l2_dbg(1, debug, sd, "%s: edid complete with %d segment(s)\n", __func__, state->edid.segments);
state->edid.complete = true;
ed.present = true;
ed.segment = 0;
state->edid_detect_counter++;
v4l2_ctrl_s_ctrl(state->have_edid0_ctrl, state->edid.segments ? 0x1 : 0x0);
v4l2_subdev_notify(sd, ADV7511_EDID_DETECT, (void *)&ed);
return ed.present;
}
return false;
}
static void adv7511_init_setup(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
struct adv7511_state_edid *edid = &state->edid;
v4l2_dbg(1, debug, sd, "%s\n", __func__);
adv7511_wr(sd, 0x96, 0xff);
adv7511_wr_and_or(sd, 0xd6, 0x3f, 0xc0);
memset(edid, 0, sizeof(struct adv7511_state_edid));
state->have_monitor = false;
adv7511_set_isr(sd, false);
adv7511_s_stream(sd, false);
adv7511_s_audio_stream(sd, false);
}
static int adv7511_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct adv7511_state *state;
struct adv7511_platform_data *pdata = client->dev.platform_data;
struct v4l2_ctrl_handler *hdl;
struct v4l2_subdev *sd;
u8 chip_id[2];
int err = -EIO;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
state = devm_kzalloc(&client->dev, sizeof(struct adv7511_state), GFP_KERNEL);
if (!state)
return -ENOMEM;
if (!pdata) {
v4l_err(client, "No platform data!\n");
return -ENODEV;
}
memcpy(&state->pdata, pdata, sizeof(state->pdata));
sd = &state->sd;
v4l2_dbg(1, debug, sd, "detecting adv7511 client on address 0x%x\n",
client->addr << 1);
v4l2_i2c_subdev_init(sd, client, &adv7511_ops);
hdl = &state->hdl;
v4l2_ctrl_handler_init(hdl, 10);
state->hdmi_mode_ctrl = v4l2_ctrl_new_std_menu(hdl, &adv7511_ctrl_ops,
V4L2_CID_DV_TX_MODE, V4L2_DV_TX_MODE_HDMI,
0, V4L2_DV_TX_MODE_DVI_D);
state->hotplug_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_TX_HOTPLUG, 0, 1, 0, 0);
state->rx_sense_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_TX_RXSENSE, 0, 1, 0, 0);
state->have_edid0_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_TX_EDID_PRESENT, 0, 1, 0, 0);
state->rgb_quantization_range_ctrl =
v4l2_ctrl_new_std_menu(hdl, &adv7511_ctrl_ops,
V4L2_CID_DV_TX_RGB_RANGE, V4L2_DV_RGB_RANGE_FULL,
0, V4L2_DV_RGB_RANGE_AUTO);
sd->ctrl_handler = hdl;
if (hdl->error) {
err = hdl->error;
goto err_hdl;
}
state->hdmi_mode_ctrl->is_private = true;
state->hotplug_ctrl->is_private = true;
state->rx_sense_ctrl->is_private = true;
state->have_edid0_ctrl->is_private = true;
state->rgb_quantization_range_ctrl->is_private = true;
state->pad.flags = MEDIA_PAD_FL_SINK;
err = media_entity_init(&sd->entity, 1, &state->pad, 0);
if (err)
goto err_hdl;
state->i2c_edid_addr = state->pdata.i2c_edid << 1;
state->i2c_cec_addr = state->pdata.i2c_cec << 1;
state->chip_revision = adv7511_rd(sd, 0x0);
chip_id[0] = adv7511_rd(sd, 0xf5);
chip_id[1] = adv7511_rd(sd, 0xf6);
if (chip_id[0] != 0x75 || chip_id[1] != 0x11) {
v4l2_err(sd, "chip_id != 0x7511, read 0x%02x%02x\n", chip_id[0], chip_id[1]);
err = -EIO;
goto err_entity;
}
state->i2c_edid = i2c_new_dummy(client->adapter, state->i2c_edid_addr >> 1);
if (state->i2c_edid == NULL) {
v4l2_err(sd, "failed to register edid i2c client\n");
err = -ENOMEM;
goto err_entity;
}
adv7511_wr(sd, 0xe2, 0x01);
state->work_queue = create_singlethread_workqueue(sd->name);
if (state->work_queue == NULL) {
v4l2_err(sd, "could not create workqueue\n");
err = -ENOMEM;
goto err_unreg_cec;
}
INIT_DELAYED_WORK(&state->edid_handler, adv7511_edid_handler);
adv7511_init_setup(sd);
adv7511_set_isr(sd, true);
adv7511_check_monitor_present_status(sd);
v4l2_info(sd, "%s found @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
return 0;
err_unreg_cec:
i2c_unregister_device(state->i2c_edid);
err_entity:
media_entity_cleanup(&sd->entity);
err_hdl:
v4l2_ctrl_handler_free(&state->hdl);
return err;
}
static int adv7511_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7511_state *state = get_adv7511_state(sd);
state->chip_revision = -1;
v4l2_dbg(1, debug, sd, "%s removed @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
adv7511_init_setup(sd);
cancel_delayed_work(&state->edid_handler);
i2c_unregister_device(state->i2c_edid);
destroy_workqueue(state->work_queue);
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
v4l2_ctrl_handler_free(sd->ctrl_handler);
return 0;
}
