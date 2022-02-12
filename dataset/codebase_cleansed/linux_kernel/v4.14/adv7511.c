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
static inline void adv7511_wr_and_or(struct v4l2_subdev *sd, u8 reg, u8 clr_mask, u8 val_mask)
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
static void adv7511_edid_rd(struct v4l2_subdev *sd, uint16_t len, uint8_t *buf)
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
static inline int adv7511_cec_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7511_state *state = get_adv7511_state(sd);
return i2c_smbus_read_byte_data(state->i2c_cec, reg);
}
static int adv7511_cec_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7511_state *state = get_adv7511_state(sd);
int ret;
int i;
for (i = 0; i < 3; i++) {
ret = i2c_smbus_write_byte_data(state->i2c_cec, reg, val);
if (ret == 0)
return 0;
}
v4l2_err(sd, "%s: I2C Write Problem\n", __func__);
return ret;
}
static inline int adv7511_cec_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask,
u8 val)
{
return adv7511_cec_write(sd, reg, (adv7511_cec_read(sd, reg) & mask) | val);
}
static int adv7511_pktmem_rd(struct v4l2_subdev *sd, u8 reg)
{
struct adv7511_state *state = get_adv7511_state(sd);
return adv_smbus_read_byte_data(state->i2c_pktmem, reg);
}
static int adv7511_pktmem_wr(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7511_state *state = get_adv7511_state(sd);
int ret;
int i;
for (i = 0; i < 3; i++) {
ret = i2c_smbus_write_byte_data(state->i2c_pktmem, reg, val);
if (ret == 0)
return 0;
}
v4l2_err(sd, "%s: i2c write error\n", __func__);
return ret;
}
static inline void adv7511_pktmem_wr_and_or(struct v4l2_subdev *sd, u8 reg, u8 clr_mask, u8 val_mask)
{
adv7511_pktmem_wr(sd, reg, (adv7511_pktmem_rd(sd, reg) & clr_mask) | val_mask);
}
static inline bool adv7511_have_hotplug(struct v4l2_subdev *sd)
{
return adv7511_rd(sd, 0x42) & MASK_ADV7511_HPD_DETECT;
}
static inline bool adv7511_have_rx_sense(struct v4l2_subdev *sd)
{
return adv7511_rd(sd, 0x42) & MASK_ADV7511_MSEN_DETECT;
}
static void adv7511_csc_conversion_mode(struct v4l2_subdev *sd, u8 mode)
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
u8 csc_mode = 0;
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
static void adv7511_set_rgb_quantization_mode(struct v4l2_subdev *sd, struct v4l2_ctrl *ctrl)
{
struct adv7511_state *state = get_adv7511_state(sd);
if (state->fmt_code != MEDIA_BUS_FMT_RGB888_1X24) {
adv7511_csc_rgb_full2limit(sd, false);
return;
}
switch (ctrl->val) {
case V4L2_DV_RGB_RANGE_AUTO:
if (state->dv_timings.bt.flags & V4L2_DV_FL_IS_CE_VIDEO) {
adv7511_csc_rgb_full2limit(sd, true);
} else {
adv7511_csc_rgb_full2limit(sd, false);
}
break;
case V4L2_DV_RGB_RANGE_LIMITED:
adv7511_csc_rgb_full2limit(sd, true);
break;
case V4L2_DV_RGB_RANGE_FULL:
adv7511_csc_rgb_full2limit(sd, false);
break;
}
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
if (state->rgb_quantization_range_ctrl == ctrl) {
adv7511_set_rgb_quantization_mode(sd, ctrl);
return 0;
}
if (state->content_type_ctrl == ctrl) {
u8 itc, cn;
state->content_type = ctrl->val;
itc = state->content_type != V4L2_DV_IT_CONTENT_TYPE_NO_ITC;
cn = itc ? state->content_type : V4L2_DV_IT_CONTENT_TYPE_GRAPHICS;
adv7511_wr_and_or(sd, 0x57, 0x7f, itc << 7);
adv7511_wr_and_or(sd, 0x59, 0xcf, cn << 4);
return 0;
}
return -EINVAL;
}
static void adv7511_inv_register(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
v4l2_info(sd, "0x000-0x0ff: Main Map\n");
if (state->i2c_cec)
v4l2_info(sd, "0x100-0x1ff: CEC Map\n");
}
static int adv7511_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct adv7511_state *state = get_adv7511_state(sd);
reg->size = 1;
switch (reg->reg >> 8) {
case 0:
reg->val = adv7511_rd(sd, reg->reg & 0xff);
break;
case 1:
if (state->i2c_cec) {
reg->val = adv7511_cec_read(sd, reg->reg & 0xff);
break;
}
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7511_inv_register(sd);
break;
}
return 0;
}
static int adv7511_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
struct adv7511_state *state = get_adv7511_state(sd);
switch (reg->reg >> 8) {
case 0:
adv7511_wr(sd, reg->reg & 0xff, reg->val & 0xff);
break;
case 1:
if (state->i2c_cec) {
adv7511_cec_write(sd, reg->reg & 0xff, reg->val & 0xff);
break;
}
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7511_inv_register(sd);
break;
}
return 0;
}
static u8 hdmi_infoframe_checksum(u8 *ptr, size_t size)
{
u8 csum = 0;
size_t i;
for (i = 0; i < size; i++)
csum += ptr[i];
return 256 - csum;
}
static void log_infoframe(struct v4l2_subdev *sd, const struct adv7511_cfg_read_infoframe *cri)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct device *dev = &client->dev;
union hdmi_infoframe frame;
u8 buffer[32];
u8 len;
int i;
if (!(adv7511_rd(sd, cri->present_reg) & cri->present_mask)) {
v4l2_info(sd, "%s infoframe not transmitted\n", cri->desc);
return;
}
memcpy(buffer, cri->header, sizeof(cri->header));
len = buffer[2];
if (len + 4 > sizeof(buffer)) {
v4l2_err(sd, "%s: invalid %s infoframe length %d\n", __func__, cri->desc, len);
return;
}
if (cri->payload_addr >= 0x100) {
for (i = 0; i < len; i++)
buffer[i + 4] = adv7511_pktmem_rd(sd, cri->payload_addr + i - 0x100);
} else {
for (i = 0; i < len; i++)
buffer[i + 4] = adv7511_rd(sd, cri->payload_addr + i);
}
buffer[3] = 0;
buffer[3] = hdmi_infoframe_checksum(buffer, len + 4);
if (hdmi_infoframe_unpack(&frame, buffer) < 0) {
v4l2_err(sd, "%s: unpack of %s infoframe failed\n", __func__, cri->desc);
return;
}
hdmi_infoframe_log(KERN_INFO, dev, &frame);
}
static void adv7511_log_infoframes(struct v4l2_subdev *sd)
{
static const struct adv7511_cfg_read_infoframe cri[] = {
{ "AVI", 0x44, 0x10, { 0x82, 2, 13 }, 0x55 },
{ "Audio", 0x44, 0x08, { 0x84, 1, 10 }, 0x73 },
{ "SDP", 0x40, 0x40, { 0x83, 1, 25 }, 0x103 },
};
int i;
for (i = 0; i < ARRAY_SIZE(cri); i++)
log_infoframe(sd, &cri[i]);
}
static int adv7511_log_status(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
struct adv7511_state_edid *edid = &state->edid;
int i;
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
adv7511_log_infoframes(sd);
}
if (state->dv_timings.type == V4L2_DV_BT_656_1120)
v4l2_print_dv_timings(sd->name, "timings: ",
&state->dv_timings, false);
else
v4l2_info(sd, "no timings set\n");
v4l2_info(sd, "i2c edid addr: 0x%x\n", state->i2c_edid_addr);
if (state->i2c_cec == NULL)
return 0;
v4l2_info(sd, "i2c cec addr: 0x%x\n", state->i2c_cec_addr);
v4l2_info(sd, "CEC: %s\n", state->cec_enabled_adap ?
"enabled" : "disabled");
if (state->cec_enabled_adap) {
for (i = 0; i < ADV7511_MAX_ADDRS; i++) {
bool is_valid = state->cec_valid_addrs & (1 << i);
if (is_valid)
v4l2_info(sd, "CEC Logical Address: 0x%x\n",
state->cec_addr[i]);
}
}
v4l2_info(sd, "i2c pktmem addr: 0x%x\n", state->i2c_pktmem_addr);
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
adv7511_wr(sd, 0x45, state->i2c_pktmem_addr);
adv7511_wr(sd, 0xc9, 0xf);
return true;
}
static int adv7511_cec_adap_enable(struct cec_adapter *adap, bool enable)
{
struct adv7511_state *state = cec_get_drvdata(adap);
struct v4l2_subdev *sd = &state->sd;
if (state->i2c_cec == NULL)
return -EIO;
if (!state->cec_enabled_adap && enable) {
adv7511_cec_write_and_or(sd, 0x4e, 0xfc, 0x01);
adv7511_cec_write(sd, 0x4a, 0x07);
adv7511_cec_write(sd, 0x4a, 0);
adv7511_cec_write_and_or(sd, 0x11, 0xfe, 0);
if (state->enabled_irq)
adv7511_wr_and_or(sd, 0x95, 0xc0, 0x39);
} else if (state->cec_enabled_adap && !enable) {
if (state->enabled_irq)
adv7511_wr_and_or(sd, 0x95, 0xc0, 0x00);
adv7511_cec_write_and_or(sd, 0x4b, 0x8f, 0x00);
adv7511_cec_write_and_or(sd, 0x4e, 0xfc, 0x00);
state->cec_valid_addrs = 0;
}
state->cec_enabled_adap = enable;
return 0;
}
static int adv7511_cec_adap_log_addr(struct cec_adapter *adap, u8 addr)
{
struct adv7511_state *state = cec_get_drvdata(adap);
struct v4l2_subdev *sd = &state->sd;
unsigned int i, free_idx = ADV7511_MAX_ADDRS;
if (!state->cec_enabled_adap)
return addr == CEC_LOG_ADDR_INVALID ? 0 : -EIO;
if (addr == CEC_LOG_ADDR_INVALID) {
adv7511_cec_write_and_or(sd, 0x4b, 0x8f, 0);
state->cec_valid_addrs = 0;
return 0;
}
for (i = 0; i < ADV7511_MAX_ADDRS; i++) {
bool is_valid = state->cec_valid_addrs & (1 << i);
if (free_idx == ADV7511_MAX_ADDRS && !is_valid)
free_idx = i;
if (is_valid && state->cec_addr[i] == addr)
return 0;
}
if (i == ADV7511_MAX_ADDRS) {
i = free_idx;
if (i == ADV7511_MAX_ADDRS)
return -ENXIO;
}
state->cec_addr[i] = addr;
state->cec_valid_addrs |= 1 << i;
switch (i) {
case 0:
adv7511_cec_write_and_or(sd, 0x4b, 0xef, 0x10);
adv7511_cec_write_and_or(sd, 0x4c, 0xf0, addr);
break;
case 1:
adv7511_cec_write_and_or(sd, 0x4b, 0xdf, 0x20);
adv7511_cec_write_and_or(sd, 0x4c, 0x0f, addr << 4);
break;
case 2:
adv7511_cec_write_and_or(sd, 0x4b, 0xbf, 0x40);
adv7511_cec_write_and_or(sd, 0x4d, 0xf0, addr);
break;
}
return 0;
}
static int adv7511_cec_adap_transmit(struct cec_adapter *adap, u8 attempts,
u32 signal_free_time, struct cec_msg *msg)
{
struct adv7511_state *state = cec_get_drvdata(adap);
struct v4l2_subdev *sd = &state->sd;
u8 len = msg->len;
unsigned int i;
v4l2_dbg(1, debug, sd, "%s: len %d\n", __func__, len);
if (len > 16) {
v4l2_err(sd, "%s: len exceeded 16 (%d)\n", __func__, len);
return -EINVAL;
}
adv7511_cec_write_and_or(sd, 0x12, ~0x70, max(1, attempts - 1) << 4);
adv7511_wr_and_or(sd, 0x97, 0xc7, 0x38);
for (i = 0; i < len; i++)
adv7511_cec_write(sd, i, msg->msg[i]);
adv7511_cec_write(sd, 0x10, len);
adv7511_cec_write(sd, 0x11, 0x01);
return 0;
}
static void adv_cec_tx_raw_status(struct v4l2_subdev *sd, u8 tx_raw_status)
{
struct adv7511_state *state = get_adv7511_state(sd);
if ((adv7511_cec_read(sd, 0x11) & 0x01) == 0) {
v4l2_dbg(1, debug, sd, "%s: tx raw: tx disabled\n", __func__);
return;
}
if (tx_raw_status & 0x10) {
v4l2_dbg(1, debug, sd,
"%s: tx raw: arbitration lost\n", __func__);
cec_transmit_done(state->cec_adap, CEC_TX_STATUS_ARB_LOST,
1, 0, 0, 0);
return;
}
if (tx_raw_status & 0x08) {
u8 status;
u8 nack_cnt;
u8 low_drive_cnt;
v4l2_dbg(1, debug, sd, "%s: tx raw: retry failed\n", __func__);
status = CEC_TX_STATUS_MAX_RETRIES;
nack_cnt = adv7511_cec_read(sd, 0x14) & 0xf;
if (nack_cnt)
status |= CEC_TX_STATUS_NACK;
low_drive_cnt = adv7511_cec_read(sd, 0x14) >> 4;
if (low_drive_cnt)
status |= CEC_TX_STATUS_LOW_DRIVE;
cec_transmit_done(state->cec_adap, status,
0, nack_cnt, low_drive_cnt, 0);
return;
}
if (tx_raw_status & 0x20) {
v4l2_dbg(1, debug, sd, "%s: tx raw: ready ok\n", __func__);
cec_transmit_done(state->cec_adap, CEC_TX_STATUS_OK, 0, 0, 0, 0);
return;
}
}
static void adv7511_set_isr(struct v4l2_subdev *sd, bool enable)
{
struct adv7511_state *state = get_adv7511_state(sd);
u8 irqs = MASK_ADV7511_HPD_INT | MASK_ADV7511_MSEN_INT;
u8 irqs_rd;
int retries = 100;
v4l2_dbg(2, debug, sd, "%s: %s\n", __func__, enable ? "enable" : "disable");
if (state->enabled_irq == enable)
return;
state->enabled_irq = enable;
if (!enable)
irqs = 0;
else if (adv7511_have_hotplug(sd))
irqs |= MASK_ADV7511_EDID_RDY_INT;
adv7511_wr_and_or(sd, 0x95, 0xc0,
(state->cec_enabled_adap && enable) ? 0x39 : 0x00);
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
u8 irq_status;
u8 cec_irq;
adv7511_set_isr(sd, false);
irq_status = adv7511_rd(sd, 0x96);
cec_irq = adv7511_rd(sd, 0x97);
adv7511_wr(sd, 0x96, irq_status);
adv7511_wr(sd, 0x97, cec_irq);
v4l2_dbg(1, debug, sd, "%s: irq 0x%x, cec-irq 0x%x\n", __func__,
irq_status, cec_irq);
if (irq_status & (MASK_ADV7511_HPD_INT | MASK_ADV7511_MSEN_INT))
adv7511_check_monitor_present_status(sd);
if (irq_status & MASK_ADV7511_EDID_RDY_INT)
adv7511_check_edid_status(sd);
#if IS_ENABLED(CONFIG_VIDEO_ADV7511_CEC)
if (cec_irq & 0x38)
adv_cec_tx_raw_status(sd, cec_irq);
if (cec_irq & 1) {
struct adv7511_state *state = get_adv7511_state(sd);
struct cec_msg msg;
msg.len = adv7511_cec_read(sd, 0x25) & 0x1f;
v4l2_dbg(1, debug, sd, "%s: cec msg len %d\n", __func__,
msg.len);
if (msg.len > 16)
msg.len = 16;
if (msg.len) {
u8 i;
for (i = 0; i < msg.len; i++)
msg.msg[i] = adv7511_cec_read(sd, i + 0x15);
adv7511_cec_write(sd, 0x4a, 1);
adv7511_cec_write(sd, 0x4a, 0);
cec_received_msg(state->cec_adap, &msg);
}
}
#endif
adv7511_set_isr(sd, true);
if (handled)
*handled = true;
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
struct v4l2_bt_timings *bt = &timings->bt;
u32 fps;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (!v4l2_valid_dv_timings(timings, &adv7511_timings_cap, NULL, NULL))
return -EINVAL;
v4l2_find_dv_timings_cap(timings, &adv7511_timings_cap, 0, NULL, NULL);
state->dv_timings = *timings;
adv7511_wr_and_or(sd, 0x17, 0x9f,
((bt->polarities & V4L2_DV_VSYNC_POS_POL) ? 0 : 0x40) |
((bt->polarities & V4L2_DV_HSYNC_POS_POL) ? 0 : 0x20));
fps = (u32)bt->pixelclock / (V4L2_DV_BT_FRAME_WIDTH(bt) * V4L2_DV_BT_FRAME_HEIGHT(bt));
switch (fps) {
case 24:
adv7511_wr_and_or(sd, 0xfb, 0xf9, 1 << 1);
break;
case 25:
adv7511_wr_and_or(sd, 0xfb, 0xf9, 2 << 1);
break;
case 30:
adv7511_wr_and_or(sd, 0xfb, 0xf9, 3 << 1);
break;
default:
adv7511_wr_and_or(sd, 0xfb, 0xf9, 0);
break;
}
adv7511_set_rgb_quantization_mode(sd, state->rgb_quantization_range_ctrl);
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
if (timings->pad != 0)
return -EINVAL;
return v4l2_enum_dv_timings_cap(timings, &adv7511_timings_cap, NULL, NULL);
}
static int adv7511_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
if (cap->pad != 0)
return -EINVAL;
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
static int adv7511_get_edid(struct v4l2_subdev *sd, struct v4l2_edid *edid)
{
struct adv7511_state *state = get_adv7511_state(sd);
memset(edid->reserved, 0, sizeof(edid->reserved));
if (edid->pad != 0)
return -EINVAL;
if (edid->start_block == 0 && edid->blocks == 0) {
edid->blocks = state->edid.segments * 2;
return 0;
}
if (state->edid.segments == 0)
return -ENODATA;
if (edid->start_block >= state->edid.segments * 2)
return -EINVAL;
if (edid->start_block + edid->blocks > state->edid.segments * 2)
edid->blocks = state->edid.segments * 2 - edid->start_block;
memcpy(edid->edid, &state->edid.data[edid->start_block * 128],
128 * edid->blocks);
return 0;
}
static int adv7511_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->pad != 0)
return -EINVAL;
switch (code->index) {
case 0:
code->code = MEDIA_BUS_FMT_RGB888_1X24;
break;
case 1:
code->code = MEDIA_BUS_FMT_YUYV8_1X16;
break;
case 2:
code->code = MEDIA_BUS_FMT_UYVY8_1X16;
break;
default:
return -EINVAL;
}
return 0;
}
static void adv7511_fill_format(struct adv7511_state *state,
struct v4l2_mbus_framefmt *format)
{
format->width = state->dv_timings.bt.width;
format->height = state->dv_timings.bt.height;
format->field = V4L2_FIELD_NONE;
}
static int adv7511_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct adv7511_state *state = get_adv7511_state(sd);
if (format->pad != 0)
return -EINVAL;
memset(&format->format, 0, sizeof(format->format));
adv7511_fill_format(state, &format->format);
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
struct v4l2_mbus_framefmt *fmt;
fmt = v4l2_subdev_get_try_format(sd, cfg, format->pad);
format->format.code = fmt->code;
format->format.colorspace = fmt->colorspace;
format->format.ycbcr_enc = fmt->ycbcr_enc;
format->format.quantization = fmt->quantization;
format->format.xfer_func = fmt->xfer_func;
} else {
format->format.code = state->fmt_code;
format->format.colorspace = state->colorspace;
format->format.ycbcr_enc = state->ycbcr_enc;
format->format.quantization = state->quantization;
format->format.xfer_func = state->xfer_func;
}
return 0;
}
static int adv7511_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct adv7511_state *state = get_adv7511_state(sd);
u8 c = HDMI_COLORIMETRY_NONE;
u8 ec = HDMI_EXTENDED_COLORIMETRY_XV_YCC_601;
u8 y = HDMI_COLORSPACE_RGB;
u8 q = HDMI_QUANTIZATION_RANGE_DEFAULT;
u8 yq = HDMI_YCC_QUANTIZATION_RANGE_LIMITED;
u8 itc = state->content_type != V4L2_DV_IT_CONTENT_TYPE_NO_ITC;
u8 cn = itc ? state->content_type : V4L2_DV_IT_CONTENT_TYPE_GRAPHICS;
if (format->pad != 0)
return -EINVAL;
switch (format->format.code) {
case MEDIA_BUS_FMT_UYVY8_1X16:
case MEDIA_BUS_FMT_YUYV8_1X16:
case MEDIA_BUS_FMT_RGB888_1X24:
break;
default:
return -EINVAL;
}
adv7511_fill_format(state, &format->format);
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
struct v4l2_mbus_framefmt *fmt;
fmt = v4l2_subdev_get_try_format(sd, cfg, format->pad);
fmt->code = format->format.code;
fmt->colorspace = format->format.colorspace;
fmt->ycbcr_enc = format->format.ycbcr_enc;
fmt->quantization = format->format.quantization;
fmt->xfer_func = format->format.xfer_func;
return 0;
}
switch (format->format.code) {
case MEDIA_BUS_FMT_UYVY8_1X16:
adv7511_wr_and_or(sd, 0x15, 0xf0, 0x01);
adv7511_wr_and_or(sd, 0x16, 0x03, 0xb8);
y = HDMI_COLORSPACE_YUV422;
break;
case MEDIA_BUS_FMT_YUYV8_1X16:
adv7511_wr_and_or(sd, 0x15, 0xf0, 0x01);
adv7511_wr_and_or(sd, 0x16, 0x03, 0xbc);
y = HDMI_COLORSPACE_YUV422;
break;
case MEDIA_BUS_FMT_RGB888_1X24:
default:
adv7511_wr_and_or(sd, 0x15, 0xf0, 0x00);
adv7511_wr_and_or(sd, 0x16, 0x03, 0x00);
break;
}
state->fmt_code = format->format.code;
state->colorspace = format->format.colorspace;
state->ycbcr_enc = format->format.ycbcr_enc;
state->quantization = format->format.quantization;
state->xfer_func = format->format.xfer_func;
switch (format->format.colorspace) {
case V4L2_COLORSPACE_ADOBERGB:
c = HDMI_COLORIMETRY_EXTENDED;
ec = y ? HDMI_EXTENDED_COLORIMETRY_ADOBE_YCC_601 :
HDMI_EXTENDED_COLORIMETRY_ADOBE_RGB;
break;
case V4L2_COLORSPACE_SMPTE170M:
c = y ? HDMI_COLORIMETRY_ITU_601 : HDMI_COLORIMETRY_NONE;
if (y && format->format.ycbcr_enc == V4L2_YCBCR_ENC_XV601) {
c = HDMI_COLORIMETRY_EXTENDED;
ec = HDMI_EXTENDED_COLORIMETRY_XV_YCC_601;
}
break;
case V4L2_COLORSPACE_REC709:
c = y ? HDMI_COLORIMETRY_ITU_709 : HDMI_COLORIMETRY_NONE;
if (y && format->format.ycbcr_enc == V4L2_YCBCR_ENC_XV709) {
c = HDMI_COLORIMETRY_EXTENDED;
ec = HDMI_EXTENDED_COLORIMETRY_XV_YCC_709;
}
break;
case V4L2_COLORSPACE_SRGB:
c = y ? HDMI_COLORIMETRY_EXTENDED : HDMI_COLORIMETRY_NONE;
ec = y ? HDMI_EXTENDED_COLORIMETRY_S_YCC_601 :
HDMI_EXTENDED_COLORIMETRY_XV_YCC_601;
break;
case V4L2_COLORSPACE_BT2020:
c = HDMI_COLORIMETRY_EXTENDED;
if (y && format->format.ycbcr_enc == V4L2_YCBCR_ENC_BT2020_CONST_LUM)
ec = 5;
else
ec = 6;
break;
default:
break;
}
switch (format->format.quantization) {
case V4L2_QUANTIZATION_FULL_RANGE:
q = y ? HDMI_QUANTIZATION_RANGE_DEFAULT :
HDMI_QUANTIZATION_RANGE_FULL;
yq = q ? q - 1 : HDMI_YCC_QUANTIZATION_RANGE_FULL;
break;
case V4L2_QUANTIZATION_LIM_RANGE:
q = y ? HDMI_QUANTIZATION_RANGE_DEFAULT :
HDMI_QUANTIZATION_RANGE_LIMITED;
yq = q ? q - 1 : HDMI_YCC_QUANTIZATION_RANGE_LIMITED;
break;
}
adv7511_wr_and_or(sd, 0x4a, 0xbf, 0);
adv7511_wr_and_or(sd, 0x55, 0x9f, y << 5);
adv7511_wr_and_or(sd, 0x56, 0x3f, c << 6);
adv7511_wr_and_or(sd, 0x57, 0x83, (ec << 4) | (q << 2) | (itc << 7));
adv7511_wr_and_or(sd, 0x59, 0x0f, (yq << 6) | (cn << 4));
adv7511_wr_and_or(sd, 0x4a, 0xff, 1);
adv7511_set_rgb_quantization_mode(sd, state->rgb_quantization_range_ctrl);
return 0;
}
static void adv7511_dbg_dump_edid(int lvl, int debug, struct v4l2_subdev *sd, int segment, u8 *buf)
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
static void adv7511_notify_no_edid(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
struct adv7511_edid_detect ed;
ed.present = false;
ed.segment = adv7511_rd(sd, 0xc4);
ed.phys_addr = CEC_PHYS_ADDR_INVALID;
cec_s_phys_addr(state->cec_adap, ed.phys_addr, false);
v4l2_subdev_notify(sd, ADV7511_EDID_DETECT, (void *)&ed);
v4l2_ctrl_s_ctrl(state->have_edid0_ctrl, 0x0);
}
static void adv7511_edid_handler(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct adv7511_state *state = container_of(dwork, struct adv7511_state, edid_handler);
struct v4l2_subdev *sd = &state->sd;
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
adv7511_notify_no_edid(sd);
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
u8 status = adv7511_rd(sd, 0x42);
v4l2_dbg(1, debug, sd, "%s: status: 0x%x%s%s\n",
__func__,
status,
status & MASK_ADV7511_HPD_DETECT ? ", hotplug" : "",
status & MASK_ADV7511_MSEN_DETECT ? ", rx-sense" : "");
v4l2_ctrl_s_ctrl(state->hotplug_ctrl, adv7511_have_hotplug(sd) ? 0x1 : 0x0);
v4l2_ctrl_s_ctrl(state->rx_sense_ctrl, adv7511_have_rx_sense(sd) ? 0x1 : 0x0);
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
adv7511_notify_no_edid(sd);
}
}
static bool edid_block_verify_crc(u8 *edid_block)
{
u8 sum = 0;
int i;
for (i = 0; i < 128; i++)
sum += edid_block[i];
return sum == 0;
}
static bool edid_verify_crc(struct v4l2_subdev *sd, u32 segment)
{
struct adv7511_state *state = get_adv7511_state(sd);
u32 blocks = state->edid.blocks;
u8 *data = state->edid.data;
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
u8 edidRdy = adv7511_rd(sd, 0xc5);
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
v4l2_ctrl_s_ctrl(state->have_edid0_ctrl, 0x1);
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
ed.phys_addr = cec_get_edid_phys_addr(state->edid.data,
state->edid.segments * 256,
NULL);
ed.present = true;
ed.segment = 0;
state->edid_detect_counter++;
cec_s_phys_addr(state->cec_adap, ed.phys_addr, false);
v4l2_subdev_notify(sd, ADV7511_EDID_DETECT, (void *)&ed);
return ed.present;
}
return false;
}
static int adv7511_registered(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int err;
err = cec_register_adapter(state->cec_adap, &client->dev);
if (err)
cec_delete_adapter(state->cec_adap);
return err;
}
static void adv7511_unregistered(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
cec_unregister_adapter(state->cec_adap);
}
static void adv7511_init_setup(struct v4l2_subdev *sd)
{
struct adv7511_state *state = get_adv7511_state(sd);
struct adv7511_state_edid *edid = &state->edid;
u32 cec_clk = state->pdata.cec_clk;
u8 ratio;
v4l2_dbg(1, debug, sd, "%s\n", __func__);
adv7511_wr(sd, 0x96, 0xff);
adv7511_wr(sd, 0x97, 0xff);
adv7511_wr_and_or(sd, 0xd6, 0x3f, 0xc0);
memset(edid, 0, sizeof(struct adv7511_state_edid));
state->have_monitor = false;
adv7511_set_isr(sd, false);
adv7511_s_stream(sd, false);
adv7511_s_audio_stream(sd, false);
if (state->i2c_cec == NULL)
return;
v4l2_dbg(1, debug, sd, "%s: cec_clk %d\n", __func__, cec_clk);
adv7511_cec_write(sd, 0x50, 0x01);
adv7511_cec_write(sd, 0x50, 0x00);
adv7511_cec_write(sd, 0x4a, 0x00);
if (cec_clk % 750000 != 0)
v4l2_err(sd, "%s: cec_clk %d, not multiple of 750 Khz\n",
__func__, cec_clk);
ratio = (cec_clk / 750000) - 1;
adv7511_cec_write(sd, 0x4e, ratio << 2);
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
state->fmt_code = MEDIA_BUS_FMT_RGB888_1X24;
state->colorspace = V4L2_COLORSPACE_SRGB;
sd = &state->sd;
v4l2_dbg(1, debug, sd, "detecting adv7511 client on address 0x%x\n",
client->addr << 1);
v4l2_i2c_subdev_init(sd, client, &adv7511_ops);
sd->internal_ops = &adv7511_int_ops;
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
state->content_type_ctrl =
v4l2_ctrl_new_std_menu(hdl, &adv7511_ctrl_ops,
V4L2_CID_DV_TX_IT_CONTENT_TYPE, V4L2_DV_IT_CONTENT_TYPE_NO_ITC,
0, V4L2_DV_IT_CONTENT_TYPE_NO_ITC);
sd->ctrl_handler = hdl;
if (hdl->error) {
err = hdl->error;
goto err_hdl;
}
state->pad.flags = MEDIA_PAD_FL_SINK;
err = media_entity_pads_init(&sd->entity, 1, &state->pad);
if (err)
goto err_hdl;
state->i2c_edid_addr = state->pdata.i2c_edid << 1;
state->i2c_cec_addr = state->pdata.i2c_cec << 1;
state->i2c_pktmem_addr = state->pdata.i2c_pktmem << 1;
state->chip_revision = adv7511_rd(sd, 0x0);
chip_id[0] = adv7511_rd(sd, 0xf5);
chip_id[1] = adv7511_rd(sd, 0xf6);
if (chip_id[0] != 0x75 || chip_id[1] != 0x11) {
v4l2_err(sd, "chip_id != 0x7511, read 0x%02x%02x\n", chip_id[0],
chip_id[1]);
err = -EIO;
goto err_entity;
}
state->i2c_edid = i2c_new_dummy(client->adapter,
state->i2c_edid_addr >> 1);
if (state->i2c_edid == NULL) {
v4l2_err(sd, "failed to register edid i2c client\n");
err = -ENOMEM;
goto err_entity;
}
adv7511_wr(sd, 0xe1, state->i2c_cec_addr);
if (state->pdata.cec_clk < 3000000 ||
state->pdata.cec_clk > 100000000) {
v4l2_err(sd, "%s: cec_clk %u outside range, disabling cec\n",
__func__, state->pdata.cec_clk);
state->pdata.cec_clk = 0;
}
if (state->pdata.cec_clk) {
state->i2c_cec = i2c_new_dummy(client->adapter,
state->i2c_cec_addr >> 1);
if (state->i2c_cec == NULL) {
v4l2_err(sd, "failed to register cec i2c client\n");
err = -ENOMEM;
goto err_unreg_edid;
}
adv7511_wr(sd, 0xe2, 0x00);
} else {
adv7511_wr(sd, 0xe2, 0x01);
}
state->i2c_pktmem = i2c_new_dummy(client->adapter, state->i2c_pktmem_addr >> 1);
if (state->i2c_pktmem == NULL) {
v4l2_err(sd, "failed to register pktmem i2c client\n");
err = -ENOMEM;
goto err_unreg_cec;
}
state->work_queue = create_singlethread_workqueue(sd->name);
if (state->work_queue == NULL) {
v4l2_err(sd, "could not create workqueue\n");
err = -ENOMEM;
goto err_unreg_pktmem;
}
INIT_DELAYED_WORK(&state->edid_handler, adv7511_edid_handler);
adv7511_init_setup(sd);
#if IS_ENABLED(CONFIG_VIDEO_ADV7511_CEC)
state->cec_adap = cec_allocate_adapter(&adv7511_cec_adap_ops,
state, dev_name(&client->dev), CEC_CAP_DEFAULTS,
ADV7511_MAX_ADDRS);
err = PTR_ERR_OR_ZERO(state->cec_adap);
if (err) {
destroy_workqueue(state->work_queue);
goto err_unreg_pktmem;
}
#endif
adv7511_set_isr(sd, true);
adv7511_check_monitor_present_status(sd);
v4l2_info(sd, "%s found @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
return 0;
err_unreg_pktmem:
i2c_unregister_device(state->i2c_pktmem);
err_unreg_cec:
if (state->i2c_cec)
i2c_unregister_device(state->i2c_cec);
err_unreg_edid:
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
adv7511_set_isr(sd, false);
adv7511_init_setup(sd);
cancel_delayed_work(&state->edid_handler);
i2c_unregister_device(state->i2c_edid);
if (state->i2c_cec)
i2c_unregister_device(state->i2c_cec);
i2c_unregister_device(state->i2c_pktmem);
destroy_workqueue(state->work_queue);
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
v4l2_ctrl_handler_free(sd->ctrl_handler);
return 0;
}
