static inline struct adv7604_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7604_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct adv7604_state, hdl)->sd;
}
static inline unsigned hblanking(const struct v4l2_bt_timings *t)
{
return V4L2_DV_BT_BLANKING_WIDTH(t);
}
static inline unsigned htotal(const struct v4l2_bt_timings *t)
{
return V4L2_DV_BT_FRAME_WIDTH(t);
}
static inline unsigned vblanking(const struct v4l2_bt_timings *t)
{
return V4L2_DV_BT_BLANKING_HEIGHT(t);
}
static inline unsigned vtotal(const struct v4l2_bt_timings *t)
{
return V4L2_DV_BT_FRAME_HEIGHT(t);
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
return -EIO;
}
static s32 adv_smbus_read_byte_data(struct i2c_client *client, u8 command)
{
return adv_smbus_read_byte_data_check(client, command, true);
}
static s32 adv_smbus_write_byte_data(struct i2c_client *client,
u8 command, u8 value)
{
union i2c_smbus_data data;
int err;
int i;
data.byte = value;
for (i = 0; i < 3; i++) {
err = i2c_smbus_xfer(client->adapter, client->addr,
client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_BYTE_DATA, &data);
if (!err)
break;
}
if (err < 0)
v4l_err(client, "error writing %02x, %02x, %02x\n",
client->addr, command, value);
return err;
}
static s32 adv_smbus_write_i2c_block_data(struct i2c_client *client,
u8 command, unsigned length, const u8 *values)
{
union i2c_smbus_data data;
if (length > I2C_SMBUS_BLOCK_MAX)
length = I2C_SMBUS_BLOCK_MAX;
data.block[0] = length;
memcpy(data.block + 1, values, length);
return i2c_smbus_xfer(client->adapter, client->addr, client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_I2C_BLOCK_DATA, &data);
}
static inline int io_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return adv_smbus_read_byte_data(client, reg);
}
static inline int io_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return adv_smbus_write_byte_data(client, reg, val);
}
static inline int io_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return io_write(sd, reg, (io_read(sd, reg) & mask) | val);
}
static inline int avlink_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_avlink, reg);
}
static inline int avlink_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_avlink, reg, val);
}
static inline int cec_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_cec, reg);
}
static inline int cec_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_cec, reg, val);
}
static inline int cec_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return cec_write(sd, reg, (cec_read(sd, reg) & mask) | val);
}
static inline int infoframe_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_infoframe, reg);
}
static inline int infoframe_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_infoframe, reg, val);
}
static inline int esdp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_esdp, reg);
}
static inline int esdp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_esdp, reg, val);
}
static inline int dpp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_dpp, reg);
}
static inline int dpp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_dpp, reg, val);
}
static inline int afe_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_afe, reg);
}
static inline int afe_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_afe, reg, val);
}
static inline int rep_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_repeater, reg);
}
static inline int rep_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_repeater, reg, val);
}
static inline int rep_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return rep_write(sd, reg, (rep_read(sd, reg) & mask) | val);
}
static inline int edid_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_edid, reg);
}
static inline int edid_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_edid, reg, val);
}
static inline int edid_read_block(struct v4l2_subdev *sd, unsigned len, u8 *val)
{
struct adv7604_state *state = to_state(sd);
struct i2c_client *client = state->i2c_edid;
u8 msgbuf0[1] = { 0 };
u8 msgbuf1[256];
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.len = 1,
.buf = msgbuf0
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = len,
.buf = msgbuf1
},
};
if (i2c_transfer(client->adapter, msg, 2) < 0)
return -EIO;
memcpy(val, msgbuf1, len);
return 0;
}
static inline int edid_write_block(struct v4l2_subdev *sd,
unsigned len, const u8 *val)
{
struct adv7604_state *state = to_state(sd);
int err = 0;
int i;
v4l2_dbg(2, debug, sd, "%s: write EDID block (%d byte)\n", __func__, len);
for (i = 0; !err && i < len; i += I2C_SMBUS_BLOCK_MAX)
err = adv_smbus_write_i2c_block_data(state->i2c_edid, i,
I2C_SMBUS_BLOCK_MAX, val + i);
return err;
}
static void adv7604_delayed_work_enable_hotplug(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct adv7604_state *state = container_of(dwork, struct adv7604_state,
delayed_work_enable_hotplug);
struct v4l2_subdev *sd = &state->sd;
v4l2_dbg(2, debug, sd, "%s: enable hotplug\n", __func__);
v4l2_subdev_notify(sd, ADV7604_HOTPLUG, (void *)&state->edid.present);
}
static inline int hdmi_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_hdmi, reg);
}
static inline int hdmi_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_hdmi, reg, val);
}
static inline int hdmi_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return hdmi_write(sd, reg, (hdmi_read(sd, reg) & mask) | val);
}
static inline int test_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_test, reg);
}
static inline int test_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_test, reg, val);
}
static inline int cp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_cp, reg);
}
static inline int cp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_cp, reg, val);
}
static inline int cp_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return cp_write(sd, reg, (cp_read(sd, reg) & mask) | val);
}
static inline int vdp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_vdp, reg);
}
static inline int vdp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7604_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_vdp, reg, val);
}
static inline bool is_analog_input(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
return state->selected_input == ADV7604_INPUT_VGA_RGB ||
state->selected_input == ADV7604_INPUT_VGA_COMP;
}
static inline bool is_digital_input(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
return state->selected_input == ADV7604_INPUT_HDMI_PORT_A ||
state->selected_input == ADV7604_INPUT_HDMI_PORT_B ||
state->selected_input == ADV7604_INPUT_HDMI_PORT_C ||
state->selected_input == ADV7604_INPUT_HDMI_PORT_D;
}
static void adv7604_inv_register(struct v4l2_subdev *sd)
{
v4l2_info(sd, "0x000-0x0ff: IO Map\n");
v4l2_info(sd, "0x100-0x1ff: AVLink Map\n");
v4l2_info(sd, "0x200-0x2ff: CEC Map\n");
v4l2_info(sd, "0x300-0x3ff: InfoFrame Map\n");
v4l2_info(sd, "0x400-0x4ff: ESDP Map\n");
v4l2_info(sd, "0x500-0x5ff: DPP Map\n");
v4l2_info(sd, "0x600-0x6ff: AFE Map\n");
v4l2_info(sd, "0x700-0x7ff: Repeater Map\n");
v4l2_info(sd, "0x800-0x8ff: EDID Map\n");
v4l2_info(sd, "0x900-0x9ff: HDMI Map\n");
v4l2_info(sd, "0xa00-0xaff: Test Map\n");
v4l2_info(sd, "0xb00-0xbff: CP Map\n");
v4l2_info(sd, "0xc00-0xcff: VDP Map\n");
}
static int adv7604_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
reg->size = 1;
switch (reg->reg >> 8) {
case 0:
reg->val = io_read(sd, reg->reg & 0xff);
break;
case 1:
reg->val = avlink_read(sd, reg->reg & 0xff);
break;
case 2:
reg->val = cec_read(sd, reg->reg & 0xff);
break;
case 3:
reg->val = infoframe_read(sd, reg->reg & 0xff);
break;
case 4:
reg->val = esdp_read(sd, reg->reg & 0xff);
break;
case 5:
reg->val = dpp_read(sd, reg->reg & 0xff);
break;
case 6:
reg->val = afe_read(sd, reg->reg & 0xff);
break;
case 7:
reg->val = rep_read(sd, reg->reg & 0xff);
break;
case 8:
reg->val = edid_read(sd, reg->reg & 0xff);
break;
case 9:
reg->val = hdmi_read(sd, reg->reg & 0xff);
break;
case 0xa:
reg->val = test_read(sd, reg->reg & 0xff);
break;
case 0xb:
reg->val = cp_read(sd, reg->reg & 0xff);
break;
case 0xc:
reg->val = vdp_read(sd, reg->reg & 0xff);
break;
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7604_inv_register(sd);
break;
}
return 0;
}
static int adv7604_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
u8 val = reg->val & 0xff;
switch (reg->reg >> 8) {
case 0:
io_write(sd, reg->reg & 0xff, val);
break;
case 1:
avlink_write(sd, reg->reg & 0xff, val);
break;
case 2:
cec_write(sd, reg->reg & 0xff, val);
break;
case 3:
infoframe_write(sd, reg->reg & 0xff, val);
break;
case 4:
esdp_write(sd, reg->reg & 0xff, val);
break;
case 5:
dpp_write(sd, reg->reg & 0xff, val);
break;
case 6:
afe_write(sd, reg->reg & 0xff, val);
break;
case 7:
rep_write(sd, reg->reg & 0xff, val);
break;
case 8:
edid_write(sd, reg->reg & 0xff, val);
break;
case 9:
hdmi_write(sd, reg->reg & 0xff, val);
break;
case 0xa:
test_write(sd, reg->reg & 0xff, val);
break;
case 0xb:
cp_write(sd, reg->reg & 0xff, val);
break;
case 0xc:
vdp_write(sd, reg->reg & 0xff, val);
break;
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7604_inv_register(sd);
break;
}
return 0;
}
static int adv7604_s_detect_tx_5v_ctrl(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
u8 reg_io_6f = io_read(sd, 0x6f);
return v4l2_ctrl_s_ctrl(state->detect_tx_5v_ctrl,
((reg_io_6f & 0x10) >> 4) |
((reg_io_6f & 0x08) >> 2) |
(reg_io_6f & 0x04) |
((reg_io_6f & 0x02) << 2));
}
static int find_and_set_predefined_video_timings(struct v4l2_subdev *sd,
u8 prim_mode,
const struct adv7604_video_standards *predef_vid_timings,
const struct v4l2_dv_timings *timings)
{
int i;
for (i = 0; predef_vid_timings[i].timings.bt.width; i++) {
if (!v4l2_match_dv_timings(timings, &predef_vid_timings[i].timings,
is_digital_input(sd) ? 250000 : 1000000))
continue;
io_write(sd, 0x00, predef_vid_timings[i].vid_std);
io_write(sd, 0x01, (predef_vid_timings[i].v_freq << 4) +
prim_mode);
return 0;
}
return -1;
}
static int configure_predefined_video_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7604_state *state = to_state(sd);
int err;
v4l2_dbg(1, debug, sd, "%s", __func__);
io_write(sd, 0x16, 0x43);
io_write(sd, 0x17, 0x5a);
cp_write_and_or(sd, 0x81, 0xef, 0x00);
cp_write(sd, 0x8f, 0x00);
cp_write(sd, 0x90, 0x00);
cp_write(sd, 0xa2, 0x00);
cp_write(sd, 0xa3, 0x00);
cp_write(sd, 0xa4, 0x00);
cp_write(sd, 0xa5, 0x00);
cp_write(sd, 0xa6, 0x00);
cp_write(sd, 0xa7, 0x00);
cp_write(sd, 0xab, 0x00);
cp_write(sd, 0xac, 0x00);
if (is_analog_input(sd)) {
err = find_and_set_predefined_video_timings(sd,
0x01, adv7604_prim_mode_comp, timings);
if (err)
err = find_and_set_predefined_video_timings(sd,
0x02, adv7604_prim_mode_gr, timings);
} else if (is_digital_input(sd)) {
err = find_and_set_predefined_video_timings(sd,
0x05, adv7604_prim_mode_hdmi_comp, timings);
if (err)
err = find_and_set_predefined_video_timings(sd,
0x06, adv7604_prim_mode_hdmi_gr, timings);
} else {
v4l2_dbg(2, debug, sd, "%s: Unknown port %d selected\n",
__func__, state->selected_input);
err = -1;
}
return err;
}
static void configure_custom_video_timings(struct v4l2_subdev *sd,
const struct v4l2_bt_timings *bt)
{
struct adv7604_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u32 width = htotal(bt);
u32 height = vtotal(bt);
u16 cp_start_sav = bt->hsync + bt->hbackporch - 4;
u16 cp_start_eav = width - bt->hfrontporch;
u16 cp_start_vbi = height - bt->vfrontporch;
u16 cp_end_vbi = bt->vsync + bt->vbackporch;
u16 ch1_fr_ll = (((u32)bt->pixelclock / 100) > 0) ?
((width * (ADV7604_fsc / 100)) / ((u32)bt->pixelclock / 100)) : 0;
const u8 pll[2] = {
0xc0 | ((width >> 8) & 0x1f),
width & 0xff
};
v4l2_dbg(2, debug, sd, "%s\n", __func__);
if (is_analog_input(sd)) {
io_write(sd, 0x00, 0x07);
io_write(sd, 0x01, 0x02);
cp_write_and_or(sd, 0x81, 0xef, 0x10);
if (adv_smbus_write_i2c_block_data(client, 0x16, 2, pll))
v4l2_err(sd, "writing to reg 0x16 and 0x17 failed\n");
cp_write(sd, 0xa2, (cp_start_sav >> 4) & 0xff);
cp_write(sd, 0xa3, ((cp_start_sav & 0x0f) << 4) |
((cp_start_eav >> 8) & 0x0f));
cp_write(sd, 0xa4, cp_start_eav & 0xff);
cp_write(sd, 0xa5, (cp_start_vbi >> 4) & 0xff);
cp_write(sd, 0xa6, ((cp_start_vbi & 0xf) << 4) |
((cp_end_vbi >> 8) & 0xf));
cp_write(sd, 0xa7, cp_end_vbi & 0xff);
} else if (is_digital_input(sd)) {
io_write(sd, 0x00, 0x02);
io_write(sd, 0x01, 0x06);
} else {
v4l2_dbg(2, debug, sd, "%s: Unknown port %d selected\n",
__func__, state->selected_input);
}
cp_write(sd, 0x8f, (ch1_fr_ll >> 8) & 0x7);
cp_write(sd, 0x90, ch1_fr_ll & 0xff);
cp_write(sd, 0xab, (height >> 4) & 0xff);
cp_write(sd, 0xac, (height & 0x0f) << 4);
}
static void adv7604_set_offset(struct v4l2_subdev *sd, bool auto_offset, u16 offset_a, u16 offset_b, u16 offset_c)
{
struct adv7604_state *state = to_state(sd);
u8 offset_buf[4];
if (auto_offset) {
offset_a = 0x3ff;
offset_b = 0x3ff;
offset_c = 0x3ff;
}
v4l2_dbg(2, debug, sd, "%s: %s offset: a = 0x%x, b = 0x%x, c = 0x%x\n",
__func__, auto_offset ? "Auto" : "Manual",
offset_a, offset_b, offset_c);
offset_buf[0] = (cp_read(sd, 0x77) & 0xc0) | ((offset_a & 0x3f0) >> 4);
offset_buf[1] = ((offset_a & 0x00f) << 4) | ((offset_b & 0x3c0) >> 6);
offset_buf[2] = ((offset_b & 0x03f) << 2) | ((offset_c & 0x300) >> 8);
offset_buf[3] = offset_c & 0x0ff;
if (adv_smbus_write_i2c_block_data(state->i2c_cp, 0x77, 4, offset_buf))
v4l2_err(sd, "%s: i2c error writing to CP reg 0x77, 0x78, 0x79, 0x7a\n", __func__);
}
static void adv7604_set_gain(struct v4l2_subdev *sd, bool auto_gain, u16 gain_a, u16 gain_b, u16 gain_c)
{
struct adv7604_state *state = to_state(sd);
u8 gain_buf[4];
u8 gain_man = 1;
u8 agc_mode_man = 1;
if (auto_gain) {
gain_man = 0;
agc_mode_man = 0;
gain_a = 0x100;
gain_b = 0x100;
gain_c = 0x100;
}
v4l2_dbg(2, debug, sd, "%s: %s gain: a = 0x%x, b = 0x%x, c = 0x%x\n",
__func__, auto_gain ? "Auto" : "Manual",
gain_a, gain_b, gain_c);
gain_buf[0] = ((gain_man << 7) | (agc_mode_man << 6) | ((gain_a & 0x3f0) >> 4));
gain_buf[1] = (((gain_a & 0x00f) << 4) | ((gain_b & 0x3c0) >> 6));
gain_buf[2] = (((gain_b & 0x03f) << 2) | ((gain_c & 0x300) >> 8));
gain_buf[3] = ((gain_c & 0x0ff));
if (adv_smbus_write_i2c_block_data(state->i2c_cp, 0x73, 4, gain_buf))
v4l2_err(sd, "%s: i2c error writing to CP reg 0x73, 0x74, 0x75, 0x76\n", __func__);
}
static void set_rgb_quantization_range(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
bool rgb_output = io_read(sd, 0x02) & 0x02;
bool hdmi_signal = hdmi_read(sd, 0x05) & 0x80;
v4l2_dbg(2, debug, sd, "%s: RGB quantization range: %d, RGB out: %d, HDMI: %d\n",
__func__, state->rgb_quantization_range,
rgb_output, hdmi_signal);
adv7604_set_gain(sd, true, 0x0, 0x0, 0x0);
adv7604_set_offset(sd, true, 0x0, 0x0, 0x0);
switch (state->rgb_quantization_range) {
case V4L2_DV_RGB_RANGE_AUTO:
if (state->selected_input == ADV7604_INPUT_VGA_RGB) {
io_write_and_or(sd, 0x02, 0x0f, 0x10);
break;
}
if (state->selected_input == ADV7604_INPUT_VGA_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0xf0);
break;
}
if (hdmi_signal) {
io_write_and_or(sd, 0x02, 0x0f, 0xf0);
break;
}
if (state->timings.bt.standards & V4L2_DV_BT_STD_CEA861) {
io_write_and_or(sd, 0x02, 0x0f, 0x00);
} else {
io_write_and_or(sd, 0x02, 0x0f, 0x10);
if (is_digital_input(sd) && rgb_output) {
adv7604_set_offset(sd, false, 0x40, 0x40, 0x40);
} else {
adv7604_set_gain(sd, false, 0xe0, 0xe0, 0xe0);
adv7604_set_offset(sd, false, 0x70, 0x70, 0x70);
}
}
break;
case V4L2_DV_RGB_RANGE_LIMITED:
if (state->selected_input == ADV7604_INPUT_VGA_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0x20);
break;
}
io_write_and_or(sd, 0x02, 0x0f, 0x00);
break;
case V4L2_DV_RGB_RANGE_FULL:
if (state->selected_input == ADV7604_INPUT_VGA_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0x60);
break;
}
io_write_and_or(sd, 0x02, 0x0f, 0x10);
if (is_analog_input(sd) || hdmi_signal)
break;
if (rgb_output) {
adv7604_set_offset(sd, false, 0x40, 0x40, 0x40);
} else {
adv7604_set_gain(sd, false, 0xe0, 0xe0, 0xe0);
adv7604_set_offset(sd, false, 0x70, 0x70, 0x70);
}
break;
}
}
static int adv7604_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct adv7604_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
cp_write(sd, 0x3c, ctrl->val);
return 0;
case V4L2_CID_CONTRAST:
cp_write(sd, 0x3a, ctrl->val);
return 0;
case V4L2_CID_SATURATION:
cp_write(sd, 0x3b, ctrl->val);
return 0;
case V4L2_CID_HUE:
cp_write(sd, 0x3d, ctrl->val);
return 0;
case V4L2_CID_DV_RX_RGB_RANGE:
state->rgb_quantization_range = ctrl->val;
set_rgb_quantization_range(sd);
return 0;
case V4L2_CID_ADV_RX_ANALOG_SAMPLING_PHASE:
afe_write(sd, 0xc8, ctrl->val);
return 0;
case V4L2_CID_ADV_RX_FREE_RUN_COLOR_MANUAL:
cp_write_and_or(sd, 0xbf, ~0x04, (ctrl->val << 2));
return 0;
case V4L2_CID_ADV_RX_FREE_RUN_COLOR:
cp_write(sd, 0xc0, (ctrl->val & 0xff0000) >> 16);
cp_write(sd, 0xc1, (ctrl->val & 0x00ff00) >> 8);
cp_write(sd, 0xc2, (u8)(ctrl->val & 0x0000ff));
return 0;
}
return -EINVAL;
}
static inline bool no_power(struct v4l2_subdev *sd)
{
return io_read(sd, 0x0c) & 0x24;
}
static inline bool no_signal_tmds(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
return !(io_read(sd, 0x6a) & (0x10 >> state->selected_input));
}
static inline bool no_lock_tmds(struct v4l2_subdev *sd)
{
return (io_read(sd, 0x6a) & 0xe0) != 0xe0;
}
static inline bool is_hdmi(struct v4l2_subdev *sd)
{
return hdmi_read(sd, 0x05) & 0x80;
}
static inline bool no_lock_sspd(struct v4l2_subdev *sd)
{
return ((cp_read(sd, 0xb5) & 0xd0) != 0xd0);
}
static inline bool no_lock_stdi(struct v4l2_subdev *sd)
{
return !(cp_read(sd, 0xb1) & 0x80);
}
static inline bool no_signal(struct v4l2_subdev *sd)
{
bool ret;
ret = no_power(sd);
ret |= no_lock_stdi(sd);
ret |= no_lock_sspd(sd);
if (is_digital_input(sd)) {
ret |= no_lock_tmds(sd);
ret |= no_signal_tmds(sd);
}
return ret;
}
static inline bool no_lock_cp(struct v4l2_subdev *sd)
{
return io_read(sd, 0x12) & 0x01;
}
static int adv7604_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
*status = 0;
*status |= no_power(sd) ? V4L2_IN_ST_NO_POWER : 0;
*status |= no_signal(sd) ? V4L2_IN_ST_NO_SIGNAL : 0;
if (no_lock_cp(sd))
*status |= is_digital_input(sd) ? V4L2_IN_ST_NO_SYNC : V4L2_IN_ST_NO_H_LOCK;
v4l2_dbg(1, debug, sd, "%s: status = 0x%x\n", __func__, *status);
return 0;
}
static int stdi2dv_timings(struct v4l2_subdev *sd,
struct stdi_readback *stdi,
struct v4l2_dv_timings *timings)
{
struct adv7604_state *state = to_state(sd);
u32 hfreq = (ADV7604_fsc * 8) / stdi->bl;
u32 pix_clk;
int i;
for (i = 0; adv7604_timings[i].bt.height; i++) {
if (vtotal(&adv7604_timings[i].bt) != stdi->lcf + 1)
continue;
if (adv7604_timings[i].bt.vsync != stdi->lcvs)
continue;
pix_clk = hfreq * htotal(&adv7604_timings[i].bt);
if ((pix_clk < adv7604_timings[i].bt.pixelclock + 1000000) &&
(pix_clk > adv7604_timings[i].bt.pixelclock - 1000000)) {
*timings = adv7604_timings[i];
return 0;
}
}
if (v4l2_detect_cvt(stdi->lcf + 1, hfreq, stdi->lcvs,
(stdi->hs_pol == '+' ? V4L2_DV_HSYNC_POS_POL : 0) |
(stdi->vs_pol == '+' ? V4L2_DV_VSYNC_POS_POL : 0),
timings))
return 0;
if (v4l2_detect_gtf(stdi->lcf + 1, hfreq, stdi->lcvs,
(stdi->hs_pol == '+' ? V4L2_DV_HSYNC_POS_POL : 0) |
(stdi->vs_pol == '+' ? V4L2_DV_VSYNC_POS_POL : 0),
state->aspect_ratio, timings))
return 0;
v4l2_dbg(2, debug, sd,
"%s: No format candidate found for lcvs = %d, lcf=%d, bl = %d, %chsync, %cvsync\n",
__func__, stdi->lcvs, stdi->lcf, stdi->bl,
stdi->hs_pol, stdi->vs_pol);
return -1;
}
static int read_stdi(struct v4l2_subdev *sd, struct stdi_readback *stdi)
{
if (no_lock_stdi(sd) || no_lock_sspd(sd)) {
v4l2_dbg(2, debug, sd, "%s: STDI and/or SSPD not locked\n", __func__);
return -1;
}
stdi->bl = ((cp_read(sd, 0xb1) & 0x3f) << 8) | cp_read(sd, 0xb2);
stdi->lcf = ((cp_read(sd, 0xb3) & 0x7) << 8) | cp_read(sd, 0xb4);
stdi->lcvs = cp_read(sd, 0xb3) >> 3;
stdi->interlaced = io_read(sd, 0x12) & 0x10;
if ((cp_read(sd, 0xb5) & 0x03) == 0x01) {
stdi->hs_pol = ((cp_read(sd, 0xb5) & 0x10) ?
((cp_read(sd, 0xb5) & 0x08) ? '+' : '-') : 'x');
stdi->vs_pol = ((cp_read(sd, 0xb5) & 0x40) ?
((cp_read(sd, 0xb5) & 0x20) ? '+' : '-') : 'x');
} else {
stdi->hs_pol = 'x';
stdi->vs_pol = 'x';
}
if (no_lock_stdi(sd) || no_lock_sspd(sd)) {
v4l2_dbg(2, debug, sd,
"%s: signal lost during readout of STDI/SSPD\n", __func__);
return -1;
}
if (stdi->lcf < 239 || stdi->bl < 8 || stdi->bl == 0x3fff) {
v4l2_dbg(2, debug, sd, "%s: invalid signal\n", __func__);
memset(stdi, 0, sizeof(struct stdi_readback));
return -1;
}
v4l2_dbg(2, debug, sd,
"%s: lcf (frame height - 1) = %d, bl = %d, lcvs (vsync) = %d, %chsync, %cvsync, %s\n",
__func__, stdi->lcf, stdi->bl, stdi->lcvs,
stdi->hs_pol, stdi->vs_pol,
stdi->interlaced ? "interlaced" : "progressive");
return 0;
}
static int adv7604_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
if (timings->index >= ARRAY_SIZE(adv7604_timings) - 1)
return -EINVAL;
memset(timings->reserved, 0, sizeof(timings->reserved));
timings->timings = adv7604_timings[timings->index];
return 0;
}
static int adv7604_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
cap->type = V4L2_DV_BT_656_1120;
cap->bt.max_width = 1920;
cap->bt.max_height = 1200;
cap->bt.min_pixelclock = 25000000;
if (is_digital_input(sd))
cap->bt.max_pixelclock = 225000000;
else
cap->bt.max_pixelclock = 170000000;
cap->bt.standards = V4L2_DV_BT_STD_CEA861 | V4L2_DV_BT_STD_DMT |
V4L2_DV_BT_STD_GTF | V4L2_DV_BT_STD_CVT;
cap->bt.capabilities = V4L2_DV_BT_CAP_PROGRESSIVE |
V4L2_DV_BT_CAP_REDUCED_BLANKING | V4L2_DV_BT_CAP_CUSTOM;
return 0;
}
static void adv7604_fill_optional_dv_timings_fields(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
int i;
for (i = 0; adv7604_timings[i].bt.width; i++) {
if (v4l2_match_dv_timings(timings, &adv7604_timings[i],
is_digital_input(sd) ? 250000 : 1000000)) {
*timings = adv7604_timings[i];
break;
}
}
}
static int adv7604_query_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7604_state *state = to_state(sd);
struct v4l2_bt_timings *bt = &timings->bt;
struct stdi_readback stdi;
if (!timings)
return -EINVAL;
memset(timings, 0, sizeof(struct v4l2_dv_timings));
if (no_signal(sd)) {
state->restart_stdi_once = true;
v4l2_dbg(1, debug, sd, "%s: no valid signal\n", __func__);
return -ENOLINK;
}
if (read_stdi(sd, &stdi)) {
v4l2_dbg(1, debug, sd, "%s: STDI/SSPD not locked\n", __func__);
return -ENOLINK;
}
bt->interlaced = stdi.interlaced ?
V4L2_DV_INTERLACED : V4L2_DV_PROGRESSIVE;
if (is_digital_input(sd)) {
uint32_t freq;
timings->type = V4L2_DV_BT_656_1120;
bt->width = (hdmi_read(sd, 0x07) & 0x0f) * 256 + hdmi_read(sd, 0x08);
bt->height = (hdmi_read(sd, 0x09) & 0x0f) * 256 + hdmi_read(sd, 0x0a);
freq = (hdmi_read(sd, 0x06) * 1000000) +
((hdmi_read(sd, 0x3b) & 0x30) >> 4) * 250000;
if (is_hdmi(sd)) {
unsigned bits_per_channel = ((hdmi_read(sd, 0x0b) & 0x60) >> 4) + 8;
freq = freq * 8 / bits_per_channel;
}
bt->pixelclock = freq;
bt->hfrontporch = (hdmi_read(sd, 0x20) & 0x03) * 256 +
hdmi_read(sd, 0x21);
bt->hsync = (hdmi_read(sd, 0x22) & 0x03) * 256 +
hdmi_read(sd, 0x23);
bt->hbackporch = (hdmi_read(sd, 0x24) & 0x03) * 256 +
hdmi_read(sd, 0x25);
bt->vfrontporch = ((hdmi_read(sd, 0x2a) & 0x1f) * 256 +
hdmi_read(sd, 0x2b)) / 2;
bt->vsync = ((hdmi_read(sd, 0x2e) & 0x1f) * 256 +
hdmi_read(sd, 0x2f)) / 2;
bt->vbackporch = ((hdmi_read(sd, 0x32) & 0x1f) * 256 +
hdmi_read(sd, 0x33)) / 2;
bt->polarities = ((hdmi_read(sd, 0x05) & 0x10) ? V4L2_DV_VSYNC_POS_POL : 0) |
((hdmi_read(sd, 0x05) & 0x20) ? V4L2_DV_HSYNC_POS_POL : 0);
if (bt->interlaced == V4L2_DV_INTERLACED) {
bt->height += (hdmi_read(sd, 0x0b) & 0x0f) * 256 +
hdmi_read(sd, 0x0c);
bt->il_vfrontporch = ((hdmi_read(sd, 0x2c) & 0x1f) * 256 +
hdmi_read(sd, 0x2d)) / 2;
bt->il_vsync = ((hdmi_read(sd, 0x30) & 0x1f) * 256 +
hdmi_read(sd, 0x31)) / 2;
bt->vbackporch = ((hdmi_read(sd, 0x34) & 0x1f) * 256 +
hdmi_read(sd, 0x35)) / 2;
}
adv7604_fill_optional_dv_timings_fields(sd, timings);
} else {
if (!stdi2dv_timings(sd, &stdi, timings))
goto found;
stdi.lcvs += 1;
v4l2_dbg(1, debug, sd, "%s: lcvs + 1 = %d\n", __func__, stdi.lcvs);
if (!stdi2dv_timings(sd, &stdi, timings))
goto found;
stdi.lcvs -= 2;
v4l2_dbg(1, debug, sd, "%s: lcvs - 1 = %d\n", __func__, stdi.lcvs);
if (stdi2dv_timings(sd, &stdi, timings)) {
if (state->restart_stdi_once) {
v4l2_dbg(1, debug, sd, "%s: restart STDI\n", __func__);
cp_write_and_or(sd, 0x86, 0xf9, 0x00);
cp_write_and_or(sd, 0x86, 0xf9, 0x04);
cp_write_and_or(sd, 0x86, 0xf9, 0x02);
state->restart_stdi_once = false;
return -ENOLINK;
}
v4l2_dbg(1, debug, sd, "%s: format not supported\n", __func__);
return -ERANGE;
}
state->restart_stdi_once = true;
}
found:
if (no_signal(sd)) {
v4l2_dbg(1, debug, sd, "%s: signal lost during readout\n", __func__);
memset(timings, 0, sizeof(struct v4l2_dv_timings));
return -ENOLINK;
}
if ((is_analog_input(sd) && bt->pixelclock > 170000000) ||
(is_digital_input(sd) && bt->pixelclock > 225000000)) {
v4l2_dbg(1, debug, sd, "%s: pixelclock out of range %d\n",
__func__, (u32)bt->pixelclock);
return -ERANGE;
}
if (debug > 1)
v4l2_print_dv_timings(sd->name, "adv7604_query_dv_timings: ",
timings, true);
return 0;
}
static int adv7604_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7604_state *state = to_state(sd);
struct v4l2_bt_timings *bt;
int err;
if (!timings)
return -EINVAL;
if (v4l2_match_dv_timings(&state->timings, timings, 0)) {
v4l2_dbg(1, debug, sd, "%s: no change\n", __func__);
return 0;
}
bt = &timings->bt;
if ((is_analog_input(sd) && bt->pixelclock > 170000000) ||
(is_digital_input(sd) && bt->pixelclock > 225000000)) {
v4l2_dbg(1, debug, sd, "%s: pixelclock out of range %d\n",
__func__, (u32)bt->pixelclock);
return -ERANGE;
}
adv7604_fill_optional_dv_timings_fields(sd, timings);
state->timings = *timings;
cp_write(sd, 0x91, bt->interlaced ? 0x50 : 0x10);
err = configure_predefined_video_timings(sd, timings);
if (err) {
configure_custom_video_timings(sd, bt);
}
set_rgb_quantization_range(sd);
if (debug > 1)
v4l2_print_dv_timings(sd->name, "adv7604_s_dv_timings: ",
timings, true);
return 0;
}
static int adv7604_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7604_state *state = to_state(sd);
*timings = state->timings;
return 0;
}
static void enable_input(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
if (is_analog_input(sd)) {
io_write(sd, 0x15, 0xb0);
} else if (is_digital_input(sd)) {
hdmi_write_and_or(sd, 0x00, 0xfc, state->selected_input);
hdmi_write(sd, 0x01, 0x00);
io_write(sd, 0x15, 0xa0);
hdmi_write_and_or(sd, 0x1a, 0xef, 0x00);
} else {
v4l2_dbg(2, debug, sd, "%s: Unknown port %d selected\n",
__func__, state->selected_input);
}
}
static void disable_input(struct v4l2_subdev *sd)
{
hdmi_write_and_or(sd, 0x1a, 0xef, 0x10);
msleep(16);
io_write(sd, 0x15, 0xbe);
hdmi_write(sd, 0x01, 0x78);
}
static void select_input(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
if (is_analog_input(sd)) {
hdmi_write(sd, 0x0d, 0x04);
hdmi_write(sd, 0x3d, 0x00);
hdmi_write(sd, 0x3e, 0x74);
hdmi_write(sd, 0x4e, 0x3b);
hdmi_write(sd, 0x57, 0x74);
hdmi_write(sd, 0x58, 0x63);
hdmi_write(sd, 0x8d, 0x18);
hdmi_write(sd, 0x8e, 0x34);
hdmi_write(sd, 0x93, 0x88);
hdmi_write(sd, 0x94, 0x2e);
hdmi_write(sd, 0x96, 0x00);
afe_write(sd, 0x00, 0x08);
afe_write(sd, 0x01, 0x06);
afe_write(sd, 0xc8, 0x00);
afe_write(sd, 0x12, 0x7b);
afe_write(sd, 0x0c, 0x1f);
cp_write(sd, 0x3e, 0x04);
cp_write(sd, 0xc3, 0x39);
cp_write(sd, 0x40, 0x5c);
} else if (is_digital_input(sd)) {
hdmi_write(sd, 0x00, state->selected_input & 0x03);
hdmi_write(sd, 0x0d, 0x84);
hdmi_write(sd, 0x3d, 0x10);
hdmi_write(sd, 0x3e, 0x39);
hdmi_write(sd, 0x4e, 0x3b);
hdmi_write(sd, 0x57, 0xb6);
hdmi_write(sd, 0x58, 0x03);
hdmi_write(sd, 0x8d, 0x18);
hdmi_write(sd, 0x8e, 0x34);
hdmi_write(sd, 0x93, 0x8b);
hdmi_write(sd, 0x94, 0x2d);
hdmi_write(sd, 0x96, 0x01);
afe_write(sd, 0x00, 0xff);
afe_write(sd, 0x01, 0xfe);
afe_write(sd, 0xc8, 0x40);
afe_write(sd, 0x12, 0xfb);
afe_write(sd, 0x0c, 0x0d);
cp_write(sd, 0x3e, 0x00);
cp_write(sd, 0xc3, 0x39);
cp_write(sd, 0x40, 0x80);
} else {
v4l2_dbg(2, debug, sd, "%s: Unknown port %d selected\n",
__func__, state->selected_input);
}
}
static int adv7604_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct adv7604_state *state = to_state(sd);
v4l2_dbg(2, debug, sd, "%s: input %d, selected input %d",
__func__, input, state->selected_input);
if (input == state->selected_input)
return 0;
state->selected_input = input;
disable_input(sd);
select_input(sd);
enable_input(sd);
return 0;
}
static int adv7604_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned int index,
enum v4l2_mbus_pixelcode *code)
{
if (index)
return -EINVAL;
*code = V4L2_MBUS_FMT_FIXED;
return 0;
}
static int adv7604_g_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct adv7604_state *state = to_state(sd);
fmt->width = state->timings.bt.width;
fmt->height = state->timings.bt.height;
fmt->code = V4L2_MBUS_FMT_FIXED;
fmt->field = V4L2_FIELD_NONE;
if (state->timings.bt.standards & V4L2_DV_BT_STD_CEA861) {
fmt->colorspace = (state->timings.bt.height <= 576) ?
V4L2_COLORSPACE_SMPTE170M : V4L2_COLORSPACE_REC709;
}
return 0;
}
static int adv7604_isr(struct v4l2_subdev *sd, u32 status, bool *handled)
{
const u8 irq_reg_0x43 = io_read(sd, 0x43);
const u8 irq_reg_0x6b = io_read(sd, 0x6b);
const u8 irq_reg_0x70 = io_read(sd, 0x70);
u8 fmt_change_digital;
u8 fmt_change;
u8 tx_5v;
if (irq_reg_0x43)
io_write(sd, 0x44, irq_reg_0x43);
if (irq_reg_0x70)
io_write(sd, 0x71, irq_reg_0x70);
if (irq_reg_0x6b)
io_write(sd, 0x6c, irq_reg_0x6b);
v4l2_dbg(2, debug, sd, "%s: ", __func__);
fmt_change = irq_reg_0x43 & 0x98;
fmt_change_digital = is_digital_input(sd) ? (irq_reg_0x6b & 0xc0) : 0;
if (fmt_change || fmt_change_digital) {
v4l2_dbg(1, debug, sd,
"%s: fmt_change = 0x%x, fmt_change_digital = 0x%x\n",
__func__, fmt_change, fmt_change_digital);
v4l2_subdev_notify(sd, ADV7604_FMT_CHANGE, NULL);
if (handled)
*handled = true;
}
if (irq_reg_0x6b & 0x01) {
v4l2_dbg(1, debug, sd, "%s: irq %s mode\n", __func__,
(io_read(sd, 0x6a) & 0x01) ? "HDMI" : "DVI");
set_rgb_quantization_range(sd);
if (handled)
*handled = true;
}
tx_5v = io_read(sd, 0x70) & 0x1e;
if (tx_5v) {
v4l2_dbg(1, debug, sd, "%s: tx_5v: 0x%x\n", __func__, tx_5v);
io_write(sd, 0x71, tx_5v);
adv7604_s_detect_tx_5v_ctrl(sd);
if (handled)
*handled = true;
}
return 0;
}
static int adv7604_get_edid(struct v4l2_subdev *sd, struct v4l2_subdev_edid *edid)
{
struct adv7604_state *state = to_state(sd);
u8 *data = NULL;
if (edid->pad > ADV7604_EDID_PORT_D)
return -EINVAL;
if (edid->blocks == 0)
return -EINVAL;
if (edid->blocks > 2)
return -EINVAL;
if (edid->start_block > 1)
return -EINVAL;
if (edid->start_block == 1)
edid->blocks = 1;
if (!edid->edid)
return -EINVAL;
if (edid->blocks > state->edid.blocks)
edid->blocks = state->edid.blocks;
switch (edid->pad) {
case ADV7604_EDID_PORT_A:
case ADV7604_EDID_PORT_B:
case ADV7604_EDID_PORT_C:
case ADV7604_EDID_PORT_D:
if (state->edid.present & (1 << edid->pad))
data = state->edid.edid;
break;
default:
return -EINVAL;
break;
}
if (!data)
return -ENODATA;
memcpy(edid->edid,
data + edid->start_block * 128,
edid->blocks * 128);
return 0;
}
static int get_edid_spa_location(const u8 *edid)
{
u8 d;
if ((edid[0x7e] != 1) ||
(edid[0x80] != 0x02) ||
(edid[0x81] != 0x03)) {
return -1;
}
d = edid[0x82] & 0x7f;
if (d > 4) {
int i = 0x84;
int end = 0x80 + d;
do {
u8 tag = edid[i] >> 5;
u8 len = edid[i] & 0x1f;
if ((tag == 3) && (len >= 5))
return i + 4;
i += len + 1;
} while (i < end);
}
return -1;
}
static int adv7604_set_edid(struct v4l2_subdev *sd, struct v4l2_subdev_edid *edid)
{
struct adv7604_state *state = to_state(sd);
int spa_loc;
int tmp = 0;
int err;
int i;
if (edid->pad > ADV7604_EDID_PORT_D)
return -EINVAL;
if (edid->start_block != 0)
return -EINVAL;
if (edid->blocks == 0) {
state->edid.present &= ~(1 << edid->pad);
v4l2_subdev_notify(sd, ADV7604_HOTPLUG, (void *)&state->edid.present);
rep_write_and_or(sd, 0x77, 0xf0, state->edid.present);
state->aspect_ratio.numerator = 16;
state->aspect_ratio.denominator = 9;
if (!state->edid.present)
state->edid.blocks = 0;
v4l2_dbg(2, debug, sd, "%s: clear EDID pad %d, edid.present = 0x%x\n",
__func__, edid->pad, state->edid.present);
return 0;
}
if (edid->blocks > 2) {
edid->blocks = 2;
return -E2BIG;
}
if (!edid->edid)
return -EINVAL;
v4l2_dbg(2, debug, sd, "%s: write EDID pad %d, edid.present = 0x%x\n",
__func__, edid->pad, state->edid.present);
cancel_delayed_work_sync(&state->delayed_work_enable_hotplug);
v4l2_subdev_notify(sd, ADV7604_HOTPLUG, (void *)&tmp);
rep_write_and_or(sd, 0x77, 0xf0, 0x00);
spa_loc = get_edid_spa_location(edid->edid);
if (spa_loc < 0)
spa_loc = 0xc0;
switch (edid->pad) {
case ADV7604_EDID_PORT_A:
state->spa_port_a[0] = edid->edid[spa_loc];
state->spa_port_a[1] = edid->edid[spa_loc + 1];
break;
case ADV7604_EDID_PORT_B:
rep_write(sd, 0x70, edid->edid[spa_loc]);
rep_write(sd, 0x71, edid->edid[spa_loc + 1]);
break;
case ADV7604_EDID_PORT_C:
rep_write(sd, 0x72, edid->edid[spa_loc]);
rep_write(sd, 0x73, edid->edid[spa_loc + 1]);
break;
case ADV7604_EDID_PORT_D:
rep_write(sd, 0x74, edid->edid[spa_loc]);
rep_write(sd, 0x75, edid->edid[spa_loc + 1]);
break;
default:
return -EINVAL;
}
rep_write(sd, 0x76, spa_loc & 0xff);
rep_write_and_or(sd, 0x77, 0xbf, (spa_loc >> 2) & 0x40);
edid->edid[spa_loc] = state->spa_port_a[0];
edid->edid[spa_loc + 1] = state->spa_port_a[1];
memcpy(state->edid.edid, edid->edid, 128 * edid->blocks);
state->edid.blocks = edid->blocks;
state->aspect_ratio = v4l2_calc_aspect_ratio(edid->edid[0x15],
edid->edid[0x16]);
state->edid.present |= 1 << edid->pad;
err = edid_write_block(sd, 128 * edid->blocks, state->edid.edid);
if (err < 0) {
v4l2_err(sd, "error %d writing edid pad %d\n", err, edid->pad);
return err;
}
rep_write_and_or(sd, 0x77, 0xf0, state->edid.present);
for (i = 0; i < 1000; i++) {
if (rep_read(sd, 0x7d) & state->edid.present)
break;
mdelay(1);
}
if (i == 1000) {
v4l2_err(sd, "error enabling edid (0x%x)\n", state->edid.present);
return -EIO;
}
queue_delayed_work(state->work_queues,
&state->delayed_work_enable_hotplug, HZ / 10);
return 0;
}
static void print_avi_infoframe(struct v4l2_subdev *sd)
{
int i;
u8 buf[14];
u8 avi_len;
u8 avi_ver;
if (!is_hdmi(sd)) {
v4l2_info(sd, "receive DVI-D signal (AVI infoframe not supported)\n");
return;
}
if (!(io_read(sd, 0x60) & 0x01)) {
v4l2_info(sd, "AVI infoframe not received\n");
return;
}
if (io_read(sd, 0x83) & 0x01) {
v4l2_info(sd, "AVI infoframe checksum error has occurred earlier\n");
io_write(sd, 0x85, 0x01);
if (io_read(sd, 0x83) & 0x01) {
v4l2_info(sd, "AVI infoframe checksum error still present\n");
io_write(sd, 0x85, 0x01);
}
}
avi_len = infoframe_read(sd, 0xe2);
avi_ver = infoframe_read(sd, 0xe1);
v4l2_info(sd, "AVI infoframe version %d (%d byte)\n",
avi_ver, avi_len);
if (avi_ver != 0x02)
return;
for (i = 0; i < 14; i++)
buf[i] = infoframe_read(sd, i);
v4l2_info(sd,
"\t%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7],
buf[8], buf[9], buf[10], buf[11], buf[12], buf[13]);
}
static int adv7604_log_status(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
struct v4l2_dv_timings timings;
struct stdi_readback stdi;
u8 reg_io_0x02 = io_read(sd, 0x02);
char *csc_coeff_sel_rb[16] = {
"bypassed", "YPbPr601 -> RGB", "reserved", "YPbPr709 -> RGB",
"reserved", "RGB -> YPbPr601", "reserved", "RGB -> YPbPr709",
"reserved", "YPbPr709 -> YPbPr601", "YPbPr601 -> YPbPr709",
"reserved", "reserved", "reserved", "reserved", "manual"
};
char *input_color_space_txt[16] = {
"RGB limited range (16-235)", "RGB full range (0-255)",
"YCbCr Bt.601 (16-235)", "YCbCr Bt.709 (16-235)",
"xvYCC Bt.601", "xvYCC Bt.709",
"YCbCr Bt.601 (0-255)", "YCbCr Bt.709 (0-255)",
"invalid", "invalid", "invalid", "invalid", "invalid",
"invalid", "invalid", "automatic"
};
char *rgb_quantization_range_txt[] = {
"Automatic",
"RGB limited range (16-235)",
"RGB full range (0-255)",
};
char *deep_color_mode_txt[4] = {
"8-bits per channel",
"10-bits per channel",
"12-bits per channel",
"16-bits per channel (not supported)"
};
v4l2_info(sd, "-----Chip status-----\n");
v4l2_info(sd, "Chip power: %s\n", no_power(sd) ? "off" : "on");
v4l2_info(sd, "EDID enabled port A: %s, B: %s, C: %s, D: %s\n",
((rep_read(sd, 0x7d) & 0x01) ? "Yes" : "No"),
((rep_read(sd, 0x7d) & 0x02) ? "Yes" : "No"),
((rep_read(sd, 0x7d) & 0x04) ? "Yes" : "No"),
((rep_read(sd, 0x7d) & 0x08) ? "Yes" : "No"));
v4l2_info(sd, "CEC: %s\n", !!(cec_read(sd, 0x2a) & 0x01) ?
"enabled" : "disabled");
v4l2_info(sd, "-----Signal status-----\n");
v4l2_info(sd, "Cable detected (+5V power) port A: %s, B: %s, C: %s, D: %s\n",
((io_read(sd, 0x6f) & 0x10) ? "Yes" : "No"),
((io_read(sd, 0x6f) & 0x08) ? "Yes" : "No"),
((io_read(sd, 0x6f) & 0x04) ? "Yes" : "No"),
((io_read(sd, 0x6f) & 0x02) ? "Yes" : "No"));
v4l2_info(sd, "TMDS signal detected: %s\n",
no_signal_tmds(sd) ? "false" : "true");
v4l2_info(sd, "TMDS signal locked: %s\n",
no_lock_tmds(sd) ? "false" : "true");
v4l2_info(sd, "SSPD locked: %s\n", no_lock_sspd(sd) ? "false" : "true");
v4l2_info(sd, "STDI locked: %s\n", no_lock_stdi(sd) ? "false" : "true");
v4l2_info(sd, "CP locked: %s\n", no_lock_cp(sd) ? "false" : "true");
v4l2_info(sd, "CP free run: %s\n",
(!!(cp_read(sd, 0xff) & 0x10) ? "on" : "off"));
v4l2_info(sd, "Prim-mode = 0x%x, video std = 0x%x, v_freq = 0x%x\n",
io_read(sd, 0x01) & 0x0f, io_read(sd, 0x00) & 0x3f,
(io_read(sd, 0x01) & 0x70) >> 4);
v4l2_info(sd, "-----Video Timings-----\n");
if (read_stdi(sd, &stdi))
v4l2_info(sd, "STDI: not locked\n");
else
v4l2_info(sd, "STDI: lcf (frame height - 1) = %d, bl = %d, lcvs (vsync) = %d, %s, %chsync, %cvsync\n",
stdi.lcf, stdi.bl, stdi.lcvs,
stdi.interlaced ? "interlaced" : "progressive",
stdi.hs_pol, stdi.vs_pol);
if (adv7604_query_dv_timings(sd, &timings))
v4l2_info(sd, "No video detected\n");
else
v4l2_print_dv_timings(sd->name, "Detected format: ",
&timings, true);
v4l2_print_dv_timings(sd->name, "Configured format: ",
&state->timings, true);
if (no_signal(sd))
return 0;
v4l2_info(sd, "-----Color space-----\n");
v4l2_info(sd, "RGB quantization range ctrl: %s\n",
rgb_quantization_range_txt[state->rgb_quantization_range]);
v4l2_info(sd, "Input color space: %s\n",
input_color_space_txt[reg_io_0x02 >> 4]);
v4l2_info(sd, "Output color space: %s %s, saturator %s\n",
(reg_io_0x02 & 0x02) ? "RGB" : "YCbCr",
(reg_io_0x02 & 0x04) ? "(16-235)" : "(0-255)",
((reg_io_0x02 & 0x04) ^ (reg_io_0x02 & 0x01)) ?
"enabled" : "disabled");
v4l2_info(sd, "Color space conversion: %s\n",
csc_coeff_sel_rb[cp_read(sd, 0xfc) >> 4]);
if (!is_digital_input(sd))
return 0;
v4l2_info(sd, "-----%s status-----\n", is_hdmi(sd) ? "HDMI" : "DVI-D");
v4l2_info(sd, "Digital video port selected: %c\n",
(hdmi_read(sd, 0x00) & 0x03) + 'A');
v4l2_info(sd, "HDCP encrypted content: %s\n",
(hdmi_read(sd, 0x05) & 0x40) ? "true" : "false");
v4l2_info(sd, "HDCP keys read: %s%s\n",
(hdmi_read(sd, 0x04) & 0x20) ? "yes" : "no",
(hdmi_read(sd, 0x04) & 0x10) ? "ERROR" : "");
if (!is_hdmi(sd)) {
bool audio_pll_locked = hdmi_read(sd, 0x04) & 0x01;
bool audio_sample_packet_detect = hdmi_read(sd, 0x18) & 0x01;
bool audio_mute = io_read(sd, 0x65) & 0x40;
v4l2_info(sd, "Audio: pll %s, samples %s, %s\n",
audio_pll_locked ? "locked" : "not locked",
audio_sample_packet_detect ? "detected" : "not detected",
audio_mute ? "muted" : "enabled");
if (audio_pll_locked && audio_sample_packet_detect) {
v4l2_info(sd, "Audio format: %s\n",
(hdmi_read(sd, 0x07) & 0x20) ? "multi-channel" : "stereo");
}
v4l2_info(sd, "Audio CTS: %u\n", (hdmi_read(sd, 0x5b) << 12) +
(hdmi_read(sd, 0x5c) << 8) +
(hdmi_read(sd, 0x5d) & 0xf0));
v4l2_info(sd, "Audio N: %u\n", ((hdmi_read(sd, 0x5d) & 0x0f) << 16) +
(hdmi_read(sd, 0x5e) << 8) +
hdmi_read(sd, 0x5f));
v4l2_info(sd, "AV Mute: %s\n", (hdmi_read(sd, 0x04) & 0x40) ? "on" : "off");
v4l2_info(sd, "Deep color mode: %s\n", deep_color_mode_txt[(hdmi_read(sd, 0x0b) & 0x60) >> 5]);
print_avi_infoframe(sd);
}
return 0;
}
static int adv7604_core_init(struct v4l2_subdev *sd)
{
struct adv7604_state *state = to_state(sd);
struct adv7604_platform_data *pdata = &state->pdata;
hdmi_write(sd, 0x48,
(pdata->disable_pwrdnb ? 0x80 : 0) |
(pdata->disable_cable_det_rst ? 0x40 : 0));
disable_input(sd);
io_write(sd, 0x0c, 0x42);
io_write(sd, 0x0b, 0x44);
cp_write(sd, 0xcf, 0x01);
io_write_and_or(sd, 0x02, 0xf0,
pdata->alt_gamma << 3 |
pdata->op_656_range << 2 |
pdata->rgb_out << 1 |
pdata->alt_data_sat << 0);
io_write(sd, 0x03, pdata->op_format_sel);
io_write_and_or(sd, 0x04, 0x1f, pdata->op_ch_sel << 5);
io_write_and_or(sd, 0x05, 0xf0, pdata->blank_data << 3 |
pdata->insert_av_codes << 2 |
pdata->replicate_av_codes << 1 |
pdata->invert_cbcr << 0);
cp_write(sd, 0x69, 0x30);
io_write(sd, 0x06, 0xa0 | pdata->inv_vs_pol << 2 | pdata->inv_hs_pol << 1);
io_write(sd, 0x14, 0x40 | pdata->dr_str_data << 4 |
pdata->dr_str_clk << 2 |
pdata->dr_str_sync);
cp_write(sd, 0xba, (pdata->hdmi_free_run_mode << 1) | 0x01);
cp_write(sd, 0xf3, 0xdc);
cp_write(sd, 0xf9, 0x23);
cp_write(sd, 0x45, 0x23);
cp_write(sd, 0xc9, 0x2d);
hdmi_write_and_or(sd, 0x15, 0xfc, 0x03);
hdmi_write_and_or(sd, 0x1a, 0xf1, 0x08);
hdmi_write_and_or(sd, 0x68, 0xf9, 0x06);
afe_write(sd, 0xb5, 0x01);
afe_write(sd, 0x02, pdata->ain_sel);
io_write_and_or(sd, 0x30, ~(1 << 4), pdata->output_bus_lsb_to_msb << 4);
io_write(sd, 0x40, 0xc2);
io_write(sd, 0x41, 0xd7);
io_write(sd, 0x46, 0x98);
io_write(sd, 0x6e, 0xc1);
io_write(sd, 0x73, 0x1e);
return v4l2_ctrl_handler_setup(sd->ctrl_handler);
}
static void adv7604_unregister_clients(struct adv7604_state *state)
{
if (state->i2c_avlink)
i2c_unregister_device(state->i2c_avlink);
if (state->i2c_cec)
i2c_unregister_device(state->i2c_cec);
if (state->i2c_infoframe)
i2c_unregister_device(state->i2c_infoframe);
if (state->i2c_esdp)
i2c_unregister_device(state->i2c_esdp);
if (state->i2c_dpp)
i2c_unregister_device(state->i2c_dpp);
if (state->i2c_afe)
i2c_unregister_device(state->i2c_afe);
if (state->i2c_repeater)
i2c_unregister_device(state->i2c_repeater);
if (state->i2c_edid)
i2c_unregister_device(state->i2c_edid);
if (state->i2c_hdmi)
i2c_unregister_device(state->i2c_hdmi);
if (state->i2c_test)
i2c_unregister_device(state->i2c_test);
if (state->i2c_cp)
i2c_unregister_device(state->i2c_cp);
if (state->i2c_vdp)
i2c_unregister_device(state->i2c_vdp);
}
static struct i2c_client *adv7604_dummy_client(struct v4l2_subdev *sd,
u8 addr, u8 io_reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (addr)
io_write(sd, io_reg, addr << 1);
return i2c_new_dummy(client->adapter, io_read(sd, io_reg) >> 1);
}
static int adv7604_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static const struct v4l2_dv_timings cea640x480 =
V4L2_DV_BT_CEA_640X480P59_94;
struct adv7604_state *state;
struct adv7604_platform_data *pdata = client->dev.platform_data;
struct v4l2_ctrl_handler *hdl;
struct v4l2_subdev *sd;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_dbg(1, debug, client, "detecting adv7604 client on address 0x%x\n",
client->addr << 1);
state = devm_kzalloc(&client->dev, sizeof(*state), GFP_KERNEL);
if (!state) {
v4l_err(client, "Could not allocate adv7604_state memory!\n");
return -ENOMEM;
}
state->restart_stdi_once = true;
state->selected_input = ~0;
if (!pdata) {
v4l_err(client, "No platform data!\n");
return -ENODEV;
}
state->pdata = *pdata;
state->timings = cea640x480;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &adv7604_ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
if (adv_smbus_read_byte_data_check(client, 0xfb, false) != 0x68) {
v4l2_info(sd, "not an adv7604 on address 0x%x\n",
client->addr << 1);
return -ENODEV;
}
hdl = &state->hdl;
v4l2_ctrl_handler_init(hdl, 9);
v4l2_ctrl_new_std(hdl, &adv7604_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &adv7604_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &adv7604_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &adv7604_ctrl_ops,
V4L2_CID_HUE, 0, 128, 1, 0);
state->detect_tx_5v_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_RX_POWER_PRESENT, 0, 0x0f, 0, 0);
state->rgb_quantization_range_ctrl =
v4l2_ctrl_new_std_menu(hdl, &adv7604_ctrl_ops,
V4L2_CID_DV_RX_RGB_RANGE, V4L2_DV_RGB_RANGE_FULL,
0, V4L2_DV_RGB_RANGE_AUTO);
state->analog_sampling_phase_ctrl =
v4l2_ctrl_new_custom(hdl, &adv7604_ctrl_analog_sampling_phase, NULL);
state->free_run_color_manual_ctrl =
v4l2_ctrl_new_custom(hdl, &adv7604_ctrl_free_run_color_manual, NULL);
state->free_run_color_ctrl =
v4l2_ctrl_new_custom(hdl, &adv7604_ctrl_free_run_color, NULL);
sd->ctrl_handler = hdl;
if (hdl->error) {
err = hdl->error;
goto err_hdl;
}
state->detect_tx_5v_ctrl->is_private = true;
state->rgb_quantization_range_ctrl->is_private = true;
state->analog_sampling_phase_ctrl->is_private = true;
state->free_run_color_manual_ctrl->is_private = true;
state->free_run_color_ctrl->is_private = true;
if (adv7604_s_detect_tx_5v_ctrl(sd)) {
err = -ENODEV;
goto err_hdl;
}
state->i2c_avlink = adv7604_dummy_client(sd, pdata->i2c_avlink, 0xf3);
state->i2c_cec = adv7604_dummy_client(sd, pdata->i2c_cec, 0xf4);
state->i2c_infoframe = adv7604_dummy_client(sd, pdata->i2c_infoframe, 0xf5);
state->i2c_esdp = adv7604_dummy_client(sd, pdata->i2c_esdp, 0xf6);
state->i2c_dpp = adv7604_dummy_client(sd, pdata->i2c_dpp, 0xf7);
state->i2c_afe = adv7604_dummy_client(sd, pdata->i2c_afe, 0xf8);
state->i2c_repeater = adv7604_dummy_client(sd, pdata->i2c_repeater, 0xf9);
state->i2c_edid = adv7604_dummy_client(sd, pdata->i2c_edid, 0xfa);
state->i2c_hdmi = adv7604_dummy_client(sd, pdata->i2c_hdmi, 0xfb);
state->i2c_test = adv7604_dummy_client(sd, pdata->i2c_test, 0xfc);
state->i2c_cp = adv7604_dummy_client(sd, pdata->i2c_cp, 0xfd);
state->i2c_vdp = adv7604_dummy_client(sd, pdata->i2c_vdp, 0xfe);
if (!state->i2c_avlink || !state->i2c_cec || !state->i2c_infoframe ||
!state->i2c_esdp || !state->i2c_dpp || !state->i2c_afe ||
!state->i2c_repeater || !state->i2c_edid || !state->i2c_hdmi ||
!state->i2c_test || !state->i2c_cp || !state->i2c_vdp) {
err = -ENOMEM;
v4l2_err(sd, "failed to create all i2c clients\n");
goto err_i2c;
}
state->work_queues = create_singlethread_workqueue(client->name);
if (!state->work_queues) {
v4l2_err(sd, "Could not create work queue\n");
err = -ENOMEM;
goto err_i2c;
}
INIT_DELAYED_WORK(&state->delayed_work_enable_hotplug,
adv7604_delayed_work_enable_hotplug);
state->pad.flags = MEDIA_PAD_FL_SOURCE;
err = media_entity_init(&sd->entity, 1, &state->pad, 0);
if (err)
goto err_work_queues;
err = adv7604_core_init(sd);
if (err)
goto err_entity;
v4l2_info(sd, "%s found @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
return 0;
err_entity:
media_entity_cleanup(&sd->entity);
err_work_queues:
cancel_delayed_work(&state->delayed_work_enable_hotplug);
destroy_workqueue(state->work_queues);
err_i2c:
adv7604_unregister_clients(state);
err_hdl:
v4l2_ctrl_handler_free(hdl);
return err;
}
static int adv7604_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7604_state *state = to_state(sd);
cancel_delayed_work(&state->delayed_work_enable_hotplug);
destroy_workqueue(state->work_queues);
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
adv7604_unregister_clients(to_state(sd));
v4l2_ctrl_handler_free(sd->ctrl_handler);
return 0;
}
