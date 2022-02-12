static bool adv7842_check_dv_timings(const struct v4l2_dv_timings *t, void *hdl)
{
int i;
for (i = 0; adv7842_timings_exceptions[i].bt.width; i++)
if (v4l2_match_dv_timings(t, adv7842_timings_exceptions + i, 0))
return false;
return true;
}
static inline struct adv7842_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7842_state, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct adv7842_state, hdl)->sd;
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
return -EIO;
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
static void adv_smbus_write_byte_no_check(struct i2c_client *client,
u8 command, u8 value)
{
union i2c_smbus_data data;
data.byte = value;
i2c_smbus_xfer(client->adapter, client->addr,
client->flags,
I2C_SMBUS_WRITE, command,
I2C_SMBUS_BYTE_DATA, &data);
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
static inline int io_write_clr_set(struct v4l2_subdev *sd,
u8 reg, u8 mask, u8 val)
{
return io_write(sd, reg, (io_read(sd, reg) & ~mask) | val);
}
static inline int avlink_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_avlink, reg);
}
static inline int avlink_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_avlink, reg, val);
}
static inline int cec_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_cec, reg);
}
static inline int cec_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_cec, reg, val);
}
static inline int cec_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return cec_write(sd, reg, (cec_read(sd, reg) & mask) | val);
}
static inline int infoframe_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_infoframe, reg);
}
static inline int infoframe_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_infoframe, reg, val);
}
static inline int sdp_io_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_sdp_io, reg);
}
static inline int sdp_io_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_sdp_io, reg, val);
}
static inline int sdp_io_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return sdp_io_write(sd, reg, (sdp_io_read(sd, reg) & mask) | val);
}
static inline int sdp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_sdp, reg);
}
static inline int sdp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_sdp, reg, val);
}
static inline int sdp_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return sdp_write(sd, reg, (sdp_read(sd, reg) & mask) | val);
}
static inline int afe_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_afe, reg);
}
static inline int afe_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_afe, reg, val);
}
static inline int afe_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return afe_write(sd, reg, (afe_read(sd, reg) & mask) | val);
}
static inline int rep_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_repeater, reg);
}
static inline int rep_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_repeater, reg, val);
}
static inline int rep_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return rep_write(sd, reg, (rep_read(sd, reg) & mask) | val);
}
static inline int edid_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_edid, reg);
}
static inline int edid_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_edid, reg, val);
}
static inline int hdmi_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_hdmi, reg);
}
static inline int hdmi_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_hdmi, reg, val);
}
static inline int hdmi_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return hdmi_write(sd, reg, (hdmi_read(sd, reg) & mask) | val);
}
static inline int cp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_cp, reg);
}
static inline int cp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_cp, reg, val);
}
static inline int cp_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask, u8 val)
{
return cp_write(sd, reg, (cp_read(sd, reg) & mask) | val);
}
static inline int vdp_read(struct v4l2_subdev *sd, u8 reg)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_read_byte_data(state->i2c_vdp, reg);
}
static inline int vdp_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct adv7842_state *state = to_state(sd);
return adv_smbus_write_byte_data(state->i2c_vdp, reg, val);
}
static void main_reset(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
adv_smbus_write_byte_no_check(client, 0xff, 0x80);
mdelay(5);
}
static const struct adv7842_format_info *
adv7842_format_info(struct adv7842_state *state, u32 code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(adv7842_formats); ++i) {
if (adv7842_formats[i].code == code)
return &adv7842_formats[i];
}
return NULL;
}
static inline bool is_analog_input(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
return ((state->mode == ADV7842_MODE_RGB) ||
(state->mode == ADV7842_MODE_COMP));
}
static inline bool is_digital_input(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
return state->mode == ADV7842_MODE_HDMI;
}
static inline const struct v4l2_dv_timings_cap *
adv7842_get_dv_timings_cap(struct v4l2_subdev *sd)
{
return is_digital_input(sd) ? &adv7842_timings_cap_digital :
&adv7842_timings_cap_analog;
}
static void adv7842_delayed_work_enable_hotplug(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct adv7842_state *state = container_of(dwork,
struct adv7842_state, delayed_work_enable_hotplug);
struct v4l2_subdev *sd = &state->sd;
int present = state->hdmi_edid.present;
u8 mask = 0;
v4l2_dbg(2, debug, sd, "%s: enable hotplug on ports: 0x%x\n",
__func__, present);
if (present & (0x04 << ADV7842_EDID_PORT_A))
mask |= 0x20;
if (present & (0x04 << ADV7842_EDID_PORT_B))
mask |= 0x10;
io_write_and_or(sd, 0x20, 0xcf, mask);
}
static int edid_write_vga_segment(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct adv7842_state *state = to_state(sd);
const u8 *val = state->vga_edid.edid;
int err = 0;
int i;
v4l2_dbg(2, debug, sd, "%s: write EDID on VGA port\n", __func__);
io_write_and_or(sd, 0x20, 0xcf, 0x00);
rep_write_and_or(sd, 0x7f, 0x7f, 0x00);
rep_write_and_or(sd, 0x77, 0xef, 0x10);
for (i = 0; !err && i < 256; i += I2C_SMBUS_BLOCK_MAX)
err = adv_smbus_write_i2c_block_data(state->i2c_edid, i,
I2C_SMBUS_BLOCK_MAX, val + i);
if (err)
return err;
rep_write_and_or(sd, 0x7f, 0x7f, 0x80);
for (i = 0; i < 1000; i++) {
if (rep_read(sd, 0x79) & 0x20)
break;
mdelay(1);
}
if (i == 1000) {
v4l_err(client, "error enabling edid on VGA port\n");
return -EIO;
}
queue_delayed_work(state->work_queues,
&state->delayed_work_enable_hotplug, HZ / 5);
return 0;
}
static int edid_spa_location(const u8 *edid)
{
u8 d;
if ((edid[0x7e] != 1) ||
(edid[0x80] != 0x02) ||
(edid[0x81] != 0x03)) {
return -EINVAL;
}
d = edid[0x82] & 0x7f;
if (d > 4) {
int i = 0x84;
int end = 0x80 + d;
do {
u8 tag = edid[i]>>5;
u8 len = edid[i] & 0x1f;
if ((tag == 3) && (len >= 5))
return i + 4;
i += len + 1;
} while (i < end);
}
return -EINVAL;
}
static int edid_write_hdmi_segment(struct v4l2_subdev *sd, u8 port)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct adv7842_state *state = to_state(sd);
const u8 *val = state->hdmi_edid.edid;
int spa_loc = edid_spa_location(val);
int err = 0;
int i;
v4l2_dbg(2, debug, sd, "%s: write EDID on port %c (spa at 0x%x)\n",
__func__, (port == ADV7842_EDID_PORT_A) ? 'A' : 'B', spa_loc);
io_write_and_or(sd, 0x20, 0xcf, 0x00);
rep_write_and_or(sd, 0x77, 0xf3, 0x00);
if (!state->hdmi_edid.present)
return 0;
rep_write_and_or(sd, 0x77, 0xef, 0x00);
for (i = 0; !err && i < 256; i += I2C_SMBUS_BLOCK_MAX)
err = adv_smbus_write_i2c_block_data(state->i2c_edid, i,
I2C_SMBUS_BLOCK_MAX, val + i);
if (err)
return err;
if (spa_loc < 0)
spa_loc = 0xc0;
if (port == ADV7842_EDID_PORT_A) {
rep_write(sd, 0x72, val[spa_loc]);
rep_write(sd, 0x73, val[spa_loc + 1]);
} else {
rep_write(sd, 0x74, val[spa_loc]);
rep_write(sd, 0x75, val[spa_loc + 1]);
}
rep_write(sd, 0x76, spa_loc & 0xff);
rep_write_and_or(sd, 0x77, 0xbf, (spa_loc >> 2) & 0x40);
rep_write_and_or(sd, 0x77, 0xf3, state->hdmi_edid.present);
for (i = 0; i < 1000; i++) {
if (rep_read(sd, 0x7d) & state->hdmi_edid.present)
break;
mdelay(1);
}
if (i == 1000) {
v4l_err(client, "error enabling edid on port %c\n",
(port == ADV7842_EDID_PORT_A) ? 'A' : 'B');
return -EIO;
}
queue_delayed_work(state->work_queues,
&state->delayed_work_enable_hotplug, HZ / 5);
return 0;
}
static void adv7842_inv_register(struct v4l2_subdev *sd)
{
v4l2_info(sd, "0x000-0x0ff: IO Map\n");
v4l2_info(sd, "0x100-0x1ff: AVLink Map\n");
v4l2_info(sd, "0x200-0x2ff: CEC Map\n");
v4l2_info(sd, "0x300-0x3ff: InfoFrame Map\n");
v4l2_info(sd, "0x400-0x4ff: SDP_IO Map\n");
v4l2_info(sd, "0x500-0x5ff: SDP Map\n");
v4l2_info(sd, "0x600-0x6ff: AFE Map\n");
v4l2_info(sd, "0x700-0x7ff: Repeater Map\n");
v4l2_info(sd, "0x800-0x8ff: EDID Map\n");
v4l2_info(sd, "0x900-0x9ff: HDMI Map\n");
v4l2_info(sd, "0xa00-0xaff: CP Map\n");
v4l2_info(sd, "0xb00-0xbff: VDP Map\n");
}
static int adv7842_g_register(struct v4l2_subdev *sd,
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
reg->val = sdp_io_read(sd, reg->reg & 0xff);
break;
case 5:
reg->val = sdp_read(sd, reg->reg & 0xff);
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
reg->val = cp_read(sd, reg->reg & 0xff);
break;
case 0xb:
reg->val = vdp_read(sd, reg->reg & 0xff);
break;
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7842_inv_register(sd);
break;
}
return 0;
}
static int adv7842_s_register(struct v4l2_subdev *sd,
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
sdp_io_write(sd, reg->reg & 0xff, val);
break;
case 5:
sdp_write(sd, reg->reg & 0xff, val);
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
cp_write(sd, reg->reg & 0xff, val);
break;
case 0xb:
vdp_write(sd, reg->reg & 0xff, val);
break;
default:
v4l2_info(sd, "Register %03llx not supported\n", reg->reg);
adv7842_inv_register(sd);
break;
}
return 0;
}
static int adv7842_s_detect_tx_5v_ctrl(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
int prev = v4l2_ctrl_g_ctrl(state->detect_tx_5v_ctrl);
u8 reg_io_6f = io_read(sd, 0x6f);
int val = 0;
if (reg_io_6f & 0x02)
val |= 1;
if (reg_io_6f & 0x01)
val |= 2;
v4l2_dbg(1, debug, sd, "%s: 0x%x -> 0x%x\n", __func__, prev, val);
if (val != prev)
return v4l2_ctrl_s_ctrl(state->detect_tx_5v_ctrl, val);
return 0;
}
static int find_and_set_predefined_video_timings(struct v4l2_subdev *sd,
u8 prim_mode,
const struct adv7842_video_standards *predef_vid_timings,
const struct v4l2_dv_timings *timings)
{
int i;
for (i = 0; predef_vid_timings[i].timings.bt.width; i++) {
if (!v4l2_match_dv_timings(timings, &predef_vid_timings[i].timings,
is_digital_input(sd) ? 250000 : 1000000))
continue;
io_write(sd, 0x00, predef_vid_timings[i].vid_std);
io_write(sd, 0x01, (predef_vid_timings[i].v_freq << 4) + prim_mode);
return 0;
}
return -1;
}
static int configure_predefined_video_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7842_state *state = to_state(sd);
int err;
v4l2_dbg(1, debug, sd, "%s\n", __func__);
io_write(sd, 0x16, 0x43);
io_write(sd, 0x17, 0x5a);
cp_write_and_or(sd, 0x81, 0xef, 0x00);
cp_write(sd, 0x26, 0x00);
cp_write(sd, 0x27, 0x00);
cp_write(sd, 0x28, 0x00);
cp_write(sd, 0x29, 0x00);
cp_write(sd, 0x8f, 0x40);
cp_write(sd, 0x90, 0x00);
cp_write(sd, 0xa5, 0x00);
cp_write(sd, 0xa6, 0x00);
cp_write(sd, 0xa7, 0x00);
cp_write(sd, 0xab, 0x00);
cp_write(sd, 0xac, 0x00);
switch (state->mode) {
case ADV7842_MODE_COMP:
case ADV7842_MODE_RGB:
err = find_and_set_predefined_video_timings(sd,
0x01, adv7842_prim_mode_comp, timings);
if (err)
err = find_and_set_predefined_video_timings(sd,
0x02, adv7842_prim_mode_gr, timings);
break;
case ADV7842_MODE_HDMI:
err = find_and_set_predefined_video_timings(sd,
0x05, adv7842_prim_mode_hdmi_comp, timings);
if (err)
err = find_and_set_predefined_video_timings(sd,
0x06, adv7842_prim_mode_hdmi_gr, timings);
break;
default:
v4l2_dbg(2, debug, sd, "%s: Unknown mode %d\n",
__func__, state->mode);
err = -1;
break;
}
return err;
}
static void configure_custom_video_timings(struct v4l2_subdev *sd,
const struct v4l2_bt_timings *bt)
{
struct adv7842_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u32 width = htotal(bt);
u32 height = vtotal(bt);
u16 cp_start_sav = bt->hsync + bt->hbackporch - 4;
u16 cp_start_eav = width - bt->hfrontporch;
u16 cp_start_vbi = height - bt->vfrontporch + 1;
u16 cp_end_vbi = bt->vsync + bt->vbackporch + 1;
u16 ch1_fr_ll = (((u32)bt->pixelclock / 100) > 0) ?
((width * (ADV7842_fsc / 100)) / ((u32)bt->pixelclock / 100)) : 0;
const u8 pll[2] = {
0xc0 | ((width >> 8) & 0x1f),
width & 0xff
};
v4l2_dbg(2, debug, sd, "%s\n", __func__);
switch (state->mode) {
case ADV7842_MODE_COMP:
case ADV7842_MODE_RGB:
io_write(sd, 0x00, 0x07);
io_write(sd, 0x01, 0x02);
cp_write_and_or(sd, 0x81, 0xef, 0x10);
if (adv_smbus_write_i2c_block_data(client, 0x16, 2, pll)) {
v4l2_err(sd, "writing to reg 0x16 and 0x17 failed\n");
break;
}
cp_write(sd, 0x26, (cp_start_sav >> 8) & 0xf);
cp_write(sd, 0x27, (cp_start_sav & 0xff));
cp_write(sd, 0x28, (cp_start_eav >> 8) & 0xf);
cp_write(sd, 0x29, (cp_start_eav & 0xff));
cp_write(sd, 0xa5, (cp_start_vbi >> 4) & 0xff);
cp_write(sd, 0xa6, ((cp_start_vbi & 0xf) << 4) |
((cp_end_vbi >> 8) & 0xf));
cp_write(sd, 0xa7, cp_end_vbi & 0xff);
break;
case ADV7842_MODE_HDMI:
io_write(sd, 0x00, 0x02);
io_write(sd, 0x01, 0x06);
break;
default:
v4l2_dbg(2, debug, sd, "%s: Unknown mode %d\n",
__func__, state->mode);
break;
}
cp_write(sd, 0x8f, (ch1_fr_ll >> 8) & 0x7);
cp_write(sd, 0x90, ch1_fr_ll & 0xff);
cp_write(sd, 0xab, (height >> 4) & 0xff);
cp_write(sd, 0xac, (height & 0x0f) << 4);
}
static void adv7842_set_offset(struct v4l2_subdev *sd, bool auto_offset, u16 offset_a, u16 offset_b, u16 offset_c)
{
struct adv7842_state *state = to_state(sd);
u8 offset_buf[4];
if (auto_offset) {
offset_a = 0x3ff;
offset_b = 0x3ff;
offset_c = 0x3ff;
}
v4l2_dbg(2, debug, sd, "%s: %s offset: a = 0x%x, b = 0x%x, c = 0x%x\n",
__func__, auto_offset ? "Auto" : "Manual",
offset_a, offset_b, offset_c);
offset_buf[0]= (cp_read(sd, 0x77) & 0xc0) | ((offset_a & 0x3f0) >> 4);
offset_buf[1] = ((offset_a & 0x00f) << 4) | ((offset_b & 0x3c0) >> 6);
offset_buf[2] = ((offset_b & 0x03f) << 2) | ((offset_c & 0x300) >> 8);
offset_buf[3] = offset_c & 0x0ff;
if (adv_smbus_write_i2c_block_data(state->i2c_cp, 0x77, 4, offset_buf))
v4l2_err(sd, "%s: i2c error writing to CP reg 0x77, 0x78, 0x79, 0x7a\n", __func__);
}
static void adv7842_set_gain(struct v4l2_subdev *sd, bool auto_gain, u16 gain_a, u16 gain_b, u16 gain_c)
{
struct adv7842_state *state = to_state(sd);
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
struct adv7842_state *state = to_state(sd);
bool rgb_output = io_read(sd, 0x02) & 0x02;
bool hdmi_signal = hdmi_read(sd, 0x05) & 0x80;
v4l2_dbg(2, debug, sd, "%s: RGB quantization range: %d, RGB out: %d, HDMI: %d\n",
__func__, state->rgb_quantization_range,
rgb_output, hdmi_signal);
adv7842_set_gain(sd, true, 0x0, 0x0, 0x0);
adv7842_set_offset(sd, true, 0x0, 0x0, 0x0);
switch (state->rgb_quantization_range) {
case V4L2_DV_RGB_RANGE_AUTO:
if (state->mode == ADV7842_MODE_RGB) {
io_write_and_or(sd, 0x02, 0x0f, 0x10);
break;
}
if (state->mode == ADV7842_MODE_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0xf0);
break;
}
if (hdmi_signal) {
io_write_and_or(sd, 0x02, 0x0f, 0xf0);
break;
}
if (state->timings.bt.flags & V4L2_DV_FL_IS_CE_VIDEO) {
io_write_and_or(sd, 0x02, 0x0f, 0x00);
} else {
io_write_and_or(sd, 0x02, 0x0f, 0x10);
if (is_digital_input(sd) && rgb_output) {
adv7842_set_offset(sd, false, 0x40, 0x40, 0x40);
} else {
adv7842_set_gain(sd, false, 0xe0, 0xe0, 0xe0);
adv7842_set_offset(sd, false, 0x70, 0x70, 0x70);
}
}
break;
case V4L2_DV_RGB_RANGE_LIMITED:
if (state->mode == ADV7842_MODE_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0x20);
break;
}
io_write_and_or(sd, 0x02, 0x0f, 0x00);
break;
case V4L2_DV_RGB_RANGE_FULL:
if (state->mode == ADV7842_MODE_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0x60);
break;
}
io_write_and_or(sd, 0x02, 0x0f, 0x10);
if (is_analog_input(sd) || hdmi_signal)
break;
if (rgb_output) {
adv7842_set_offset(sd, false, 0x40, 0x40, 0x40);
} else {
adv7842_set_gain(sd, false, 0xe0, 0xe0, 0xe0);
adv7842_set_offset(sd, false, 0x70, 0x70, 0x70);
}
break;
}
}
static int adv7842_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct adv7842_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
cp_write(sd, 0x3c, ctrl->val);
sdp_write(sd, 0x14, ctrl->val);
return 0;
case V4L2_CID_CONTRAST:
cp_write(sd, 0x3a, ctrl->val);
sdp_write(sd, 0x13, ctrl->val);
return 0;
case V4L2_CID_SATURATION:
cp_write(sd, 0x3b, ctrl->val);
sdp_write(sd, 0x15, ctrl->val);
return 0;
case V4L2_CID_HUE:
cp_write(sd, 0x3d, ctrl->val);
sdp_write(sd, 0x16, ctrl->val);
return 0;
case V4L2_CID_ADV_RX_ANALOG_SAMPLING_PHASE:
afe_write(sd, 0xc8, ctrl->val);
return 0;
case V4L2_CID_ADV_RX_FREE_RUN_COLOR_MANUAL:
cp_write_and_or(sd, 0xbf, ~0x04, (ctrl->val << 2));
sdp_write_and_or(sd, 0xdd, ~0x04, (ctrl->val << 2));
return 0;
case V4L2_CID_ADV_RX_FREE_RUN_COLOR: {
u8 R = (ctrl->val & 0xff0000) >> 16;
u8 G = (ctrl->val & 0x00ff00) >> 8;
u8 B = (ctrl->val & 0x0000ff);
int Y = 66 * R + 129 * G + 25 * B;
int U = -38 * R - 74 * G + 112 * B;
int V = 112 * R - 94 * G - 18 * B;
Y = (Y + 128) >> 8;
U = (U + 128) >> 8;
V = (V + 128) >> 8;
Y += 16;
U += 128;
V += 128;
v4l2_dbg(1, debug, sd, "R %x, G %x, B %x\n", R, G, B);
v4l2_dbg(1, debug, sd, "Y %x, U %x, V %x\n", Y, U, V);
cp_write(sd, 0xc1, R);
cp_write(sd, 0xc0, G);
cp_write(sd, 0xc2, B);
sdp_write(sd, 0xde, Y);
sdp_write(sd, 0xdf, (V & 0xf0) | ((U >> 4) & 0x0f));
return 0;
}
case V4L2_CID_DV_RX_RGB_RANGE:
state->rgb_quantization_range = ctrl->val;
set_rgb_quantization_range(sd);
return 0;
}
return -EINVAL;
}
static inline bool no_power(struct v4l2_subdev *sd)
{
return io_read(sd, 0x0c) & 0x24;
}
static inline bool no_cp_signal(struct v4l2_subdev *sd)
{
return ((cp_read(sd, 0xb5) & 0xd0) != 0xd0) || !(cp_read(sd, 0xb1) & 0x80);
}
static inline bool is_hdmi(struct v4l2_subdev *sd)
{
return hdmi_read(sd, 0x05) & 0x80;
}
static int adv7842_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
struct adv7842_state *state = to_state(sd);
*status = 0;
if (io_read(sd, 0x0c) & 0x24)
*status |= V4L2_IN_ST_NO_POWER;
if (state->mode == ADV7842_MODE_SDP) {
if (!(sdp_read(sd, 0x5A) & 0x01))
*status |= V4L2_IN_ST_NO_SIGNAL;
v4l2_dbg(1, debug, sd, "%s: SDP status = 0x%x\n",
__func__, *status);
return 0;
}
if ((cp_read(sd, 0xb5) & 0xd0) != 0xd0 ||
!(cp_read(sd, 0xb1) & 0x80))
*status |= V4L2_IN_ST_NO_SIGNAL;
if (is_digital_input(sd) && ((io_read(sd, 0x74) & 0x03) != 0x03))
*status |= V4L2_IN_ST_NO_SIGNAL;
v4l2_dbg(1, debug, sd, "%s: CP status = 0x%x\n",
__func__, *status);
return 0;
}
static int stdi2dv_timings(struct v4l2_subdev *sd,
struct stdi_readback *stdi,
struct v4l2_dv_timings *timings)
{
struct adv7842_state *state = to_state(sd);
u32 hfreq = (ADV7842_fsc * 8) / stdi->bl;
u32 pix_clk;
int i;
for (i = 0; v4l2_dv_timings_presets[i].bt.width; i++) {
const struct v4l2_bt_timings *bt = &v4l2_dv_timings_presets[i].bt;
if (!v4l2_valid_dv_timings(&v4l2_dv_timings_presets[i],
adv7842_get_dv_timings_cap(sd),
adv7842_check_dv_timings, NULL))
continue;
if (vtotal(bt) != stdi->lcf + 1)
continue;
if (bt->vsync != stdi->lcvs)
continue;
pix_clk = hfreq * htotal(bt);
if ((pix_clk < bt->pixelclock + 1000000) &&
(pix_clk > bt->pixelclock - 1000000)) {
*timings = v4l2_dv_timings_presets[i];
return 0;
}
}
if (v4l2_detect_cvt(stdi->lcf + 1, hfreq, stdi->lcvs,
(stdi->hs_pol == '+' ? V4L2_DV_HSYNC_POS_POL : 0) |
(stdi->vs_pol == '+' ? V4L2_DV_VSYNC_POS_POL : 0),
false, timings))
return 0;
if (v4l2_detect_gtf(stdi->lcf + 1, hfreq, stdi->lcvs,
(stdi->hs_pol == '+' ? V4L2_DV_HSYNC_POS_POL : 0) |
(stdi->vs_pol == '+' ? V4L2_DV_VSYNC_POS_POL : 0),
false, state->aspect_ratio, timings))
return 0;
v4l2_dbg(2, debug, sd,
"%s: No format candidate found for lcvs = %d, lcf=%d, bl = %d, %chsync, %cvsync\n",
__func__, stdi->lcvs, stdi->lcf, stdi->bl,
stdi->hs_pol, stdi->vs_pol);
return -1;
}
static int read_stdi(struct v4l2_subdev *sd, struct stdi_readback *stdi)
{
u32 status;
adv7842_g_input_status(sd, &status);
if (status & V4L2_IN_ST_NO_SIGNAL) {
v4l2_dbg(2, debug, sd, "%s: no signal\n", __func__);
return -ENOLINK;
}
stdi->bl = ((cp_read(sd, 0xb1) & 0x3f) << 8) | cp_read(sd, 0xb2);
stdi->lcf = ((cp_read(sd, 0xb3) & 0x7) << 8) | cp_read(sd, 0xb4);
stdi->lcvs = cp_read(sd, 0xb3) >> 3;
if ((cp_read(sd, 0xb5) & 0x80) && ((cp_read(sd, 0xb5) & 0x03) == 0x01)) {
stdi->hs_pol = ((cp_read(sd, 0xb5) & 0x10) ?
((cp_read(sd, 0xb5) & 0x08) ? '+' : '-') : 'x');
stdi->vs_pol = ((cp_read(sd, 0xb5) & 0x40) ?
((cp_read(sd, 0xb5) & 0x20) ? '+' : '-') : 'x');
} else {
stdi->hs_pol = 'x';
stdi->vs_pol = 'x';
}
stdi->interlaced = (cp_read(sd, 0xb1) & 0x40) ? true : false;
if (stdi->lcf < 239 || stdi->bl < 8 || stdi->bl == 0x3fff) {
v4l2_dbg(2, debug, sd, "%s: invalid signal\n", __func__);
return -ENOLINK;
}
v4l2_dbg(2, debug, sd,
"%s: lcf (frame height - 1) = %d, bl = %d, lcvs (vsync) = %d, %chsync, %cvsync, %s\n",
__func__, stdi->lcf, stdi->bl, stdi->lcvs,
stdi->hs_pol, stdi->vs_pol,
stdi->interlaced ? "interlaced" : "progressive");
return 0;
}
static int adv7842_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
if (timings->pad != 0)
return -EINVAL;
return v4l2_enum_dv_timings_cap(timings,
adv7842_get_dv_timings_cap(sd), adv7842_check_dv_timings, NULL);
}
static int adv7842_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
if (cap->pad != 0)
return -EINVAL;
*cap = *adv7842_get_dv_timings_cap(sd);
return 0;
}
static void adv7842_fill_optional_dv_timings_fields(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
v4l2_find_dv_timings_cap(timings, adv7842_get_dv_timings_cap(sd),
is_digital_input(sd) ? 250000 : 1000000,
adv7842_check_dv_timings, NULL);
}
static int adv7842_query_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7842_state *state = to_state(sd);
struct v4l2_bt_timings *bt = &timings->bt;
struct stdi_readback stdi = { 0 };
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
memset(timings, 0, sizeof(struct v4l2_dv_timings));
if (state->mode == ADV7842_MODE_SDP)
return -ENODATA;
if (read_stdi(sd, &stdi)) {
state->restart_stdi_once = true;
v4l2_dbg(1, debug, sd, "%s: no valid signal\n", __func__);
return -ENOLINK;
}
bt->interlaced = stdi.interlaced ?
V4L2_DV_INTERLACED : V4L2_DV_PROGRESSIVE;
bt->standards = V4L2_DV_BT_STD_CEA861 | V4L2_DV_BT_STD_DMT |
V4L2_DV_BT_STD_GTF | V4L2_DV_BT_STD_CVT;
if (is_digital_input(sd)) {
u32 freq;
timings->type = V4L2_DV_BT_656_1120;
bt->width = (hdmi_read(sd, 0x07) & 0x0f) * 256 + hdmi_read(sd, 0x08);
bt->height = (hdmi_read(sd, 0x09) & 0x0f) * 256 + hdmi_read(sd, 0x0a);
freq = ((hdmi_read(sd, 0x51) << 1) + (hdmi_read(sd, 0x52) >> 7)) * 1000000;
freq += ((hdmi_read(sd, 0x52) & 0x7f) * 7813);
if (is_hdmi(sd)) {
freq = freq * 8 / (((hdmi_read(sd, 0x0b) & 0xc0) >> 6) * 2 + 8);
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
bt->il_vbackporch = ((hdmi_read(sd, 0x34) & 0x1f) * 256 +
hdmi_read(sd, 0x35)) / 2;
} else {
bt->il_vfrontporch = 0;
bt->il_vsync = 0;
bt->il_vbackporch = 0;
}
adv7842_fill_optional_dv_timings_fields(sd, timings);
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
if (debug > 1)
v4l2_print_dv_timings(sd->name, "adv7842_query_dv_timings:",
timings, true);
return 0;
}
static int adv7842_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7842_state *state = to_state(sd);
struct v4l2_bt_timings *bt;
int err;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (state->mode == ADV7842_MODE_SDP)
return -ENODATA;
if (v4l2_match_dv_timings(&state->timings, timings, 0)) {
v4l2_dbg(1, debug, sd, "%s: no change\n", __func__);
return 0;
}
bt = &timings->bt;
if (!v4l2_valid_dv_timings(timings, adv7842_get_dv_timings_cap(sd),
adv7842_check_dv_timings, NULL))
return -ERANGE;
adv7842_fill_optional_dv_timings_fields(sd, timings);
state->timings = *timings;
cp_write(sd, 0x91, bt->interlaced ? 0x40 : 0x00);
err = configure_predefined_video_timings(sd, timings);
if (err) {
configure_custom_video_timings(sd, bt);
}
set_rgb_quantization_range(sd);
if (debug > 1)
v4l2_print_dv_timings(sd->name, "adv7842_s_dv_timings: ",
timings, true);
return 0;
}
static int adv7842_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct adv7842_state *state = to_state(sd);
if (state->mode == ADV7842_MODE_SDP)
return -ENODATA;
*timings = state->timings;
return 0;
}
static void enable_input(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
set_rgb_quantization_range(sd);
switch (state->mode) {
case ADV7842_MODE_SDP:
case ADV7842_MODE_COMP:
case ADV7842_MODE_RGB:
io_write(sd, 0x15, 0xb0);
break;
case ADV7842_MODE_HDMI:
hdmi_write(sd, 0x01, 0x00);
io_write(sd, 0x15, 0xa0);
hdmi_write_and_or(sd, 0x1a, 0xef, 0x00);
break;
default:
v4l2_dbg(2, debug, sd, "%s: Unknown mode %d\n",
__func__, state->mode);
break;
}
}
static void disable_input(struct v4l2_subdev *sd)
{
hdmi_write_and_or(sd, 0x1a, 0xef, 0x10);
msleep(16);
io_write(sd, 0x15, 0xbe);
hdmi_write(sd, 0x01, 0x78);
}
static void sdp_csc_coeff(struct v4l2_subdev *sd,
const struct adv7842_sdp_csc_coeff *c)
{
sdp_io_write_and_or(sd, 0xe0, 0xbf, c->manual ? 0x00 : 0x40);
if (!c->manual)
return;
sdp_io_write_and_or(sd, 0xe0, 0x7f, c->scaling == 2 ? 0x80 : 0x00);
sdp_io_write_and_or(sd, 0xe0, 0xe0, c->A1 >> 8);
sdp_io_write(sd, 0xe1, c->A1);
sdp_io_write_and_or(sd, 0xe2, 0xe0, c->A2 >> 8);
sdp_io_write(sd, 0xe3, c->A2);
sdp_io_write_and_or(sd, 0xe4, 0xe0, c->A3 >> 8);
sdp_io_write(sd, 0xe5, c->A3);
sdp_io_write_and_or(sd, 0xe6, 0x80, c->A4 >> 8);
sdp_io_write(sd, 0xe7, c->A4);
sdp_io_write_and_or(sd, 0xe8, 0xe0, c->B1 >> 8);
sdp_io_write(sd, 0xe9, c->B1);
sdp_io_write_and_or(sd, 0xea, 0xe0, c->B2 >> 8);
sdp_io_write(sd, 0xeb, c->B2);
sdp_io_write_and_or(sd, 0xec, 0xe0, c->B3 >> 8);
sdp_io_write(sd, 0xed, c->B3);
sdp_io_write_and_or(sd, 0xee, 0x80, c->B4 >> 8);
sdp_io_write(sd, 0xef, c->B4);
sdp_io_write_and_or(sd, 0xf0, 0xe0, c->C1 >> 8);
sdp_io_write(sd, 0xf1, c->C1);
sdp_io_write_and_or(sd, 0xf2, 0xe0, c->C2 >> 8);
sdp_io_write(sd, 0xf3, c->C2);
sdp_io_write_and_or(sd, 0xf4, 0xe0, c->C3 >> 8);
sdp_io_write(sd, 0xf5, c->C3);
sdp_io_write_and_or(sd, 0xf6, 0x80, c->C4 >> 8);
sdp_io_write(sd, 0xf7, c->C4);
}
static void select_input(struct v4l2_subdev *sd,
enum adv7842_vid_std_select vid_std_select)
{
struct adv7842_state *state = to_state(sd);
switch (state->mode) {
case ADV7842_MODE_SDP:
io_write(sd, 0x00, vid_std_select);
io_write(sd, 0x01, 0);
cp_write_and_or(sd, 0x81, 0xef, 0x10);
afe_write(sd, 0x00, 0x00);
afe_write(sd, 0xc8, 0x00);
io_write(sd, 0xdd, 0x90);
afe_write_and_or(sd, 0x02, 0x7f, 0x80);
if (vid_std_select == ADV7842_SDP_VID_STD_CVBS_SD_4x1) {
afe_write(sd, 0x03, 0xa0);
afe_write(sd, 0x04, 0x00);
} else {
afe_write(sd, 0x03, 0xa0);
afe_write(sd, 0x04, 0xc0);
}
afe_write(sd, 0x0c, 0x1f);
afe_write(sd, 0x12, 0x63);
sdp_io_write(sd, 0xb2, 0x60);
sdp_io_write(sd, 0xc8, 0xe3);
sdp_write(sd, 0x00, 0x3F);
sdp_write(sd, 0x01, 0x00);
sdp_write(sd, 0x03, 0xE4);
sdp_write(sd, 0x04, 0x0B);
sdp_write(sd, 0x05, 0xC3);
sdp_write(sd, 0x06, 0xFE);
sdp_write(sd, 0x12, 0x0D);
sdp_write(sd, 0xA7, 0x00);
sdp_io_write(sd, 0xB0, 0x00);
sdp_write_and_or(sd, 0x12, 0xf6, 0x09);
break;
case ADV7842_MODE_COMP:
case ADV7842_MODE_RGB:
afe_write_and_or(sd, 0x02, 0x7f, 0x00);
io_write(sd, 0x00, vid_std_select);
io_write(sd, 0x01, 0x02);
cp_write_and_or(sd, 0x81, 0xef, 0x10);
afe_write(sd, 0x00, 0x00);
afe_write(sd, 0xc8, 0x00);
if (state->mode == ADV7842_MODE_COMP) {
io_write_and_or(sd, 0x02, 0x0f, 0x60);
} else {
io_write_and_or(sd, 0x02, 0x0f, 0x10);
}
afe_write(sd, 0x0c, 0x1f);
afe_write(sd, 0x12, 0x63);
cp_write(sd, 0x73, 0x10);
cp_write(sd, 0x74, 0x04);
cp_write(sd, 0x75, 0x01);
cp_write(sd, 0x76, 0x00);
cp_write(sd, 0x3e, 0x04);
cp_write(sd, 0xc3, 0x39);
cp_write(sd, 0x40, 0x5c);
break;
case ADV7842_MODE_HDMI:
afe_write_and_or(sd, 0x02, 0x7f, 0x00);
if (state->hdmi_port_a)
hdmi_write(sd, 0x00, 0x02);
else
hdmi_write(sd, 0x00, 0x03);
io_write(sd, 0x00, vid_std_select);
io_write(sd, 0x01, 5);
cp_write_and_or(sd, 0x81, 0xef, 0x00);
hdmi_write(sd, 0xc0, 0x00);
hdmi_write(sd, 0x0d, 0x34);
hdmi_write(sd, 0x3d, 0x10);
hdmi_write(sd, 0x44, 0x85);
hdmi_write(sd, 0x46, 0x1f);
hdmi_write(sd, 0x57, 0xb6);
hdmi_write(sd, 0x58, 0x03);
hdmi_write(sd, 0x60, 0x88);
hdmi_write(sd, 0x61, 0x88);
hdmi_write(sd, 0x6c, 0x18);
hdmi_write(sd, 0x75, 0x10);
hdmi_write(sd, 0x85, 0x1f);
hdmi_write(sd, 0x87, 0x70);
hdmi_write(sd, 0x89, 0x04);
hdmi_write(sd, 0x8a, 0x1e);
hdmi_write(sd, 0x93, 0x04);
hdmi_write(sd, 0x94, 0x1e);
hdmi_write(sd, 0x99, 0xa1);
hdmi_write(sd, 0x9b, 0x09);
hdmi_write(sd, 0x9d, 0x02);
afe_write(sd, 0x00, 0xff);
afe_write(sd, 0xc8, 0x40);
cp_write(sd, 0x73, 0x10);
cp_write(sd, 0x74, 0x04);
cp_write(sd, 0x75, 0x01);
cp_write(sd, 0x76, 0x00);
afe_write(sd, 0x12, 0xfb);
afe_write(sd, 0x0c, 0x0d);
cp_write(sd, 0x3e, 0x00);
cp_write(sd, 0xc3, 0x33);
io_write_and_or(sd, 0x02, 0x0f, 0xf0);
break;
default:
v4l2_dbg(2, debug, sd, "%s: Unknown mode %d\n",
__func__, state->mode);
break;
}
}
static int adv7842_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct adv7842_state *state = to_state(sd);
v4l2_dbg(2, debug, sd, "%s: input %d\n", __func__, input);
switch (input) {
case ADV7842_SELECT_HDMI_PORT_A:
state->mode = ADV7842_MODE_HDMI;
state->vid_std_select = ADV7842_HDMI_COMP_VID_STD_HD_1250P;
state->hdmi_port_a = true;
break;
case ADV7842_SELECT_HDMI_PORT_B:
state->mode = ADV7842_MODE_HDMI;
state->vid_std_select = ADV7842_HDMI_COMP_VID_STD_HD_1250P;
state->hdmi_port_a = false;
break;
case ADV7842_SELECT_VGA_COMP:
state->mode = ADV7842_MODE_COMP;
state->vid_std_select = ADV7842_RGB_VID_STD_AUTO_GRAPH_MODE;
break;
case ADV7842_SELECT_VGA_RGB:
state->mode = ADV7842_MODE_RGB;
state->vid_std_select = ADV7842_RGB_VID_STD_AUTO_GRAPH_MODE;
break;
case ADV7842_SELECT_SDP_CVBS:
state->mode = ADV7842_MODE_SDP;
state->vid_std_select = ADV7842_SDP_VID_STD_CVBS_SD_4x1;
break;
case ADV7842_SELECT_SDP_YC:
state->mode = ADV7842_MODE_SDP;
state->vid_std_select = ADV7842_SDP_VID_STD_YC_SD4_x1;
break;
default:
return -EINVAL;
}
disable_input(sd);
select_input(sd, state->vid_std_select);
enable_input(sd);
v4l2_subdev_notify(sd, V4L2_DEVICE_NOTIFY_EVENT,
(void *)&adv7842_ev_fmt);
return 0;
}
static int adv7842_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index >= ARRAY_SIZE(adv7842_formats))
return -EINVAL;
code->code = adv7842_formats[code->index].code;
return 0;
}
static void adv7842_fill_format(struct adv7842_state *state,
struct v4l2_mbus_framefmt *format)
{
memset(format, 0, sizeof(*format));
format->width = state->timings.bt.width;
format->height = state->timings.bt.height;
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
if (state->timings.bt.flags & V4L2_DV_FL_IS_CE_VIDEO)
format->colorspace = (state->timings.bt.height <= 576) ?
V4L2_COLORSPACE_SMPTE170M : V4L2_COLORSPACE_REC709;
}
static unsigned int adv7842_op_ch_sel(struct adv7842_state *state)
{
#define _SEL(a, b, c, d, e, f) { \
ADV7842_OP_CH_SEL_##a, ADV7842_OP_CH_SEL_##b, ADV7842_OP_CH_SEL_##c, \
ADV7842_OP_CH_SEL_##d, ADV7842_OP_CH_SEL_##e, ADV7842_OP_CH_SEL_##f }
#define _BUS(x) [ADV7842_BUS_ORDER_##x]
static const unsigned int op_ch_sel[6][6] = {
_BUS(RGB) = _SEL(GBR, GRB, BGR, RGB, BRG, RBG),
_BUS(GRB) = _SEL(BGR, RGB, GBR, GRB, RBG, BRG),
_BUS(RBG) = _SEL(GRB, GBR, BRG, RBG, BGR, RGB),
_BUS(BGR) = _SEL(RBG, BRG, RGB, BGR, GRB, GBR),
_BUS(BRG) = _SEL(BRG, RBG, GRB, GBR, RGB, BGR),
_BUS(GBR) = _SEL(RGB, BGR, RBG, BRG, GBR, GRB),
};
return op_ch_sel[state->pdata.bus_order][state->format->op_ch_sel >> 5];
}
static void adv7842_setup_format(struct adv7842_state *state)
{
struct v4l2_subdev *sd = &state->sd;
io_write_clr_set(sd, 0x02, 0x02,
state->format->rgb_out ? ADV7842_RGB_OUT : 0);
io_write(sd, 0x03, state->format->op_format_sel |
state->pdata.op_format_mode_sel);
io_write_clr_set(sd, 0x04, 0xe0, adv7842_op_ch_sel(state));
io_write_clr_set(sd, 0x05, 0x01,
state->format->swap_cb_cr ? ADV7842_OP_SWAP_CB_CR : 0);
}
static int adv7842_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct adv7842_state *state = to_state(sd);
if (format->pad != ADV7842_PAD_SOURCE)
return -EINVAL;
if (state->mode == ADV7842_MODE_SDP) {
if (!(sdp_read(sd, 0x5a) & 0x01))
return -EINVAL;
format->format.code = MEDIA_BUS_FMT_YUYV8_2X8;
format->format.width = 720;
if (state->norm & V4L2_STD_525_60)
format->format.height = 480;
else
format->format.height = 576;
format->format.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
adv7842_fill_format(state, &format->format);
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
struct v4l2_mbus_framefmt *fmt;
fmt = v4l2_subdev_get_try_format(sd, cfg, format->pad);
format->format.code = fmt->code;
} else {
format->format.code = state->format->code;
}
return 0;
}
static int adv7842_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct adv7842_state *state = to_state(sd);
const struct adv7842_format_info *info;
if (format->pad != ADV7842_PAD_SOURCE)
return -EINVAL;
if (state->mode == ADV7842_MODE_SDP)
return adv7842_get_format(sd, cfg, format);
info = adv7842_format_info(state, format->format.code);
if (info == NULL)
info = adv7842_format_info(state, MEDIA_BUS_FMT_YUYV8_2X8);
adv7842_fill_format(state, &format->format);
format->format.code = info->code;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
struct v4l2_mbus_framefmt *fmt;
fmt = v4l2_subdev_get_try_format(sd, cfg, format->pad);
fmt->code = format->format.code;
} else {
state->format = info;
adv7842_setup_format(state);
}
return 0;
}
static void adv7842_irq_enable(struct v4l2_subdev *sd, bool enable)
{
if (enable) {
io_write(sd, 0x46, 0x9c);
io_write(sd, 0x5a, 0x10);
io_write(sd, 0x73, 0x03);
io_write(sd, 0x78, 0x03);
io_write(sd, 0xa0, 0x09);
io_write(sd, 0x69, 0x08);
} else {
io_write(sd, 0x46, 0x0);
io_write(sd, 0x5a, 0x0);
io_write(sd, 0x73, 0x0);
io_write(sd, 0x78, 0x0);
io_write(sd, 0xa0, 0x0);
io_write(sd, 0x69, 0x0);
}
}
static int adv7842_isr(struct v4l2_subdev *sd, u32 status, bool *handled)
{
struct adv7842_state *state = to_state(sd);
u8 fmt_change_cp, fmt_change_digital, fmt_change_sdp;
u8 irq_status[6];
adv7842_irq_enable(sd, false);
irq_status[0] = io_read(sd, 0x43);
irq_status[1] = io_read(sd, 0x57);
irq_status[2] = io_read(sd, 0x70);
irq_status[3] = io_read(sd, 0x75);
irq_status[4] = io_read(sd, 0x9d);
irq_status[5] = io_read(sd, 0x66);
if (irq_status[0])
io_write(sd, 0x44, irq_status[0]);
if (irq_status[1])
io_write(sd, 0x58, irq_status[1]);
if (irq_status[2])
io_write(sd, 0x71, irq_status[2]);
if (irq_status[3])
io_write(sd, 0x76, irq_status[3]);
if (irq_status[4])
io_write(sd, 0x9e, irq_status[4]);
if (irq_status[5])
io_write(sd, 0x67, irq_status[5]);
adv7842_irq_enable(sd, true);
v4l2_dbg(1, debug, sd, "%s: irq %x, %x, %x, %x, %x, %x\n", __func__,
irq_status[0], irq_status[1], irq_status[2],
irq_status[3], irq_status[4], irq_status[5]);
fmt_change_cp = irq_status[0] & 0x9c;
if (state->mode == ADV7842_MODE_SDP)
fmt_change_sdp = (irq_status[1] & 0x30) | (irq_status[4] & 0x09);
else
fmt_change_sdp = 0;
if (is_digital_input(sd))
fmt_change_digital = irq_status[3] & 0x03;
else
fmt_change_digital = 0;
if (fmt_change_cp || fmt_change_digital || fmt_change_sdp) {
v4l2_dbg(1, debug, sd,
"%s: fmt_change_cp = 0x%x, fmt_change_digital = 0x%x, fmt_change_sdp = 0x%x\n",
__func__, fmt_change_cp, fmt_change_digital,
fmt_change_sdp);
v4l2_subdev_notify(sd, V4L2_DEVICE_NOTIFY_EVENT,
(void *)&adv7842_ev_fmt);
if (handled)
*handled = true;
}
if (irq_status[5] & 0x08) {
v4l2_dbg(1, debug, sd, "%s: irq %s mode\n", __func__,
(io_read(sd, 0x65) & 0x08) ? "HDMI" : "DVI");
set_rgb_quantization_range(sd);
if (handled)
*handled = true;
}
if (irq_status[2] & 0x3) {
v4l2_dbg(1, debug, sd, "%s: irq tx_5v\n", __func__);
adv7842_s_detect_tx_5v_ctrl(sd);
if (handled)
*handled = true;
}
return 0;
}
static int adv7842_get_edid(struct v4l2_subdev *sd, struct v4l2_edid *edid)
{
struct adv7842_state *state = to_state(sd);
u8 *data = NULL;
memset(edid->reserved, 0, sizeof(edid->reserved));
switch (edid->pad) {
case ADV7842_EDID_PORT_A:
case ADV7842_EDID_PORT_B:
if (state->hdmi_edid.present & (0x04 << edid->pad))
data = state->hdmi_edid.edid;
break;
case ADV7842_EDID_PORT_VGA:
if (state->vga_edid.present)
data = state->vga_edid.edid;
break;
default:
return -EINVAL;
}
if (edid->start_block == 0 && edid->blocks == 0) {
edid->blocks = data ? 2 : 0;
return 0;
}
if (!data)
return -ENODATA;
if (edid->start_block >= 2)
return -EINVAL;
if (edid->start_block + edid->blocks > 2)
edid->blocks = 2 - edid->start_block;
memcpy(edid->edid, data + edid->start_block * 128, edid->blocks * 128);
return 0;
}
static int adv7842_set_edid(struct v4l2_subdev *sd, struct v4l2_edid *e)
{
struct adv7842_state *state = to_state(sd);
int err = 0;
memset(e->reserved, 0, sizeof(e->reserved));
if (e->pad > ADV7842_EDID_PORT_VGA)
return -EINVAL;
if (e->start_block != 0)
return -EINVAL;
if (e->blocks > 2) {
e->blocks = 2;
return -E2BIG;
}
state->aspect_ratio = v4l2_calc_aspect_ratio(e->edid[0x15],
e->edid[0x16]);
switch (e->pad) {
case ADV7842_EDID_PORT_VGA:
memset(&state->vga_edid.edid, 0, 256);
state->vga_edid.present = e->blocks ? 0x1 : 0x0;
memcpy(&state->vga_edid.edid, e->edid, 128 * e->blocks);
err = edid_write_vga_segment(sd);
break;
case ADV7842_EDID_PORT_A:
case ADV7842_EDID_PORT_B:
memset(&state->hdmi_edid.edid, 0, 256);
if (e->blocks)
state->hdmi_edid.present |= 0x04 << e->pad;
else
state->hdmi_edid.present &= ~(0x04 << e->pad);
memcpy(&state->hdmi_edid.edid, e->edid, 128 * e->blocks);
err = edid_write_hdmi_segment(sd, e->pad);
break;
default:
return -EINVAL;
}
if (err < 0)
v4l2_err(sd, "error %d writing edid on port %d\n", err, e->pad);
return err;
}
static void log_infoframe(struct v4l2_subdev *sd, struct adv7842_cfg_read_infoframe *cri)
{
int i;
u8 buffer[32];
union hdmi_infoframe frame;
u8 len;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct device *dev = &client->dev;
if (!(io_read(sd, 0x60) & cri->present_mask)) {
v4l2_info(sd, "%s infoframe not received\n", cri->desc);
return;
}
for (i = 0; i < 3; i++)
buffer[i] = infoframe_read(sd, cri->head_addr + i);
len = buffer[2] + 1;
if (len + 3 > sizeof(buffer)) {
v4l2_err(sd, "%s: invalid %s infoframe length %d\n", __func__, cri->desc, len);
return;
}
for (i = 0; i < len; i++)
buffer[i + 3] = infoframe_read(sd, cri->payload_addr + i);
if (hdmi_infoframe_unpack(&frame, buffer) < 0) {
v4l2_err(sd, "%s: unpack of %s infoframe failed\n", __func__, cri->desc);
return;
}
hdmi_infoframe_log(KERN_INFO, dev, &frame);
}
static void adv7842_log_infoframes(struct v4l2_subdev *sd)
{
int i;
struct adv7842_cfg_read_infoframe cri[] = {
{ "AVI", 0x01, 0xe0, 0x00 },
{ "Audio", 0x02, 0xe3, 0x1c },
{ "SDP", 0x04, 0xe6, 0x2a },
{ "Vendor", 0x10, 0xec, 0x54 }
};
if (!(hdmi_read(sd, 0x05) & 0x80)) {
v4l2_info(sd, "receive DVI-D signal, no infoframes\n");
return;
}
for (i = 0; i < ARRAY_SIZE(cri); i++)
log_infoframe(sd, &cri[i]);
}
static int adv7842_sdp_log_status(struct v4l2_subdev *sd)
{
u8 sdp_signal_detected = sdp_read(sd, 0x5A) & 0x01;
v4l2_info(sd, "Chip powered %s\n", no_power(sd) ? "off" : "on");
v4l2_info(sd, "Prim-mode = 0x%x, video std = 0x%x\n",
io_read(sd, 0x01) & 0x0f, io_read(sd, 0x00) & 0x3f);
v4l2_info(sd, "SDP: free run: %s\n",
(sdp_read(sd, 0x56) & 0x01) ? "on" : "off");
v4l2_info(sd, "SDP: %s\n", sdp_signal_detected ?
"valid SD/PR signal detected" : "invalid/no signal");
if (sdp_signal_detected) {
static const char * const sdp_std_txt[] = {
"NTSC-M/J",
"1?",
"NTSC-443",
"60HzSECAM",
"PAL-M",
"5?",
"PAL-60",
"7?", "8?", "9?", "a?", "b?",
"PAL-CombN",
"d?",
"PAL-BGHID",
"SECAM"
};
v4l2_info(sd, "SDP: standard %s\n",
sdp_std_txt[sdp_read(sd, 0x52) & 0x0f]);
v4l2_info(sd, "SDP: %s\n",
(sdp_read(sd, 0x59) & 0x08) ? "50Hz" : "60Hz");
v4l2_info(sd, "SDP: %s\n",
(sdp_read(sd, 0x57) & 0x08) ? "Interlaced" : "Progressive");
v4l2_info(sd, "SDP: deinterlacer %s\n",
(sdp_read(sd, 0x12) & 0x08) ? "enabled" : "disabled");
v4l2_info(sd, "SDP: csc %s mode\n",
(sdp_io_read(sd, 0xe0) & 0x40) ? "auto" : "manual");
}
return 0;
}
static int adv7842_cp_log_status(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
struct v4l2_dv_timings timings;
u8 reg_io_0x02 = io_read(sd, 0x02);
u8 reg_io_0x21 = io_read(sd, 0x21);
u8 reg_rep_0x77 = rep_read(sd, 0x77);
u8 reg_rep_0x7d = rep_read(sd, 0x7d);
bool audio_pll_locked = hdmi_read(sd, 0x04) & 0x01;
bool audio_sample_packet_detect = hdmi_read(sd, 0x18) & 0x01;
bool audio_mute = io_read(sd, 0x65) & 0x40;
static const char * const csc_coeff_sel_rb[16] = {
"bypassed", "YPbPr601 -> RGB", "reserved", "YPbPr709 -> RGB",
"reserved", "RGB -> YPbPr601", "reserved", "RGB -> YPbPr709",
"reserved", "YPbPr709 -> YPbPr601", "YPbPr601 -> YPbPr709",
"reserved", "reserved", "reserved", "reserved", "manual"
};
static const char * const input_color_space_txt[16] = {
"RGB limited range (16-235)", "RGB full range (0-255)",
"YCbCr Bt.601 (16-235)", "YCbCr Bt.709 (16-235)",
"xvYCC Bt.601", "xvYCC Bt.709",
"YCbCr Bt.601 (0-255)", "YCbCr Bt.709 (0-255)",
"invalid", "invalid", "invalid", "invalid", "invalid",
"invalid", "invalid", "automatic"
};
static const char * const rgb_quantization_range_txt[] = {
"Automatic",
"RGB limited range (16-235)",
"RGB full range (0-255)",
};
static const char * const deep_color_mode_txt[4] = {
"8-bits per channel",
"10-bits per channel",
"12-bits per channel",
"16-bits per channel (not supported)"
};
v4l2_info(sd, "-----Chip status-----\n");
v4l2_info(sd, "Chip power: %s\n", no_power(sd) ? "off" : "on");
v4l2_info(sd, "HDMI/DVI-D port selected: %s\n",
state->hdmi_port_a ? "A" : "B");
v4l2_info(sd, "EDID A %s, B %s\n",
((reg_rep_0x7d & 0x04) && (reg_rep_0x77 & 0x04)) ?
"enabled" : "disabled",
((reg_rep_0x7d & 0x08) && (reg_rep_0x77 & 0x08)) ?
"enabled" : "disabled");
v4l2_info(sd, "HPD A %s, B %s\n",
reg_io_0x21 & 0x02 ? "enabled" : "disabled",
reg_io_0x21 & 0x01 ? "enabled" : "disabled");
v4l2_info(sd, "CEC %s\n", !!(cec_read(sd, 0x2a) & 0x01) ?
"enabled" : "disabled");
v4l2_info(sd, "-----Signal status-----\n");
if (state->hdmi_port_a) {
v4l2_info(sd, "Cable detected (+5V power): %s\n",
io_read(sd, 0x6f) & 0x02 ? "true" : "false");
v4l2_info(sd, "TMDS signal detected: %s\n",
(io_read(sd, 0x6a) & 0x02) ? "true" : "false");
v4l2_info(sd, "TMDS signal locked: %s\n",
(io_read(sd, 0x6a) & 0x20) ? "true" : "false");
} else {
v4l2_info(sd, "Cable detected (+5V power):%s\n",
io_read(sd, 0x6f) & 0x01 ? "true" : "false");
v4l2_info(sd, "TMDS signal detected: %s\n",
(io_read(sd, 0x6a) & 0x01) ? "true" : "false");
v4l2_info(sd, "TMDS signal locked: %s\n",
(io_read(sd, 0x6a) & 0x10) ? "true" : "false");
}
v4l2_info(sd, "CP free run: %s\n",
(!!(cp_read(sd, 0xff) & 0x10) ? "on" : "off"));
v4l2_info(sd, "Prim-mode = 0x%x, video std = 0x%x, v_freq = 0x%x\n",
io_read(sd, 0x01) & 0x0f, io_read(sd, 0x00) & 0x3f,
(io_read(sd, 0x01) & 0x70) >> 4);
v4l2_info(sd, "-----Video Timings-----\n");
if (no_cp_signal(sd)) {
v4l2_info(sd, "STDI: not locked\n");
} else {
u32 bl = ((cp_read(sd, 0xb1) & 0x3f) << 8) | cp_read(sd, 0xb2);
u32 lcf = ((cp_read(sd, 0xb3) & 0x7) << 8) | cp_read(sd, 0xb4);
u32 lcvs = cp_read(sd, 0xb3) >> 3;
u32 fcl = ((cp_read(sd, 0xb8) & 0x1f) << 8) | cp_read(sd, 0xb9);
char hs_pol = ((cp_read(sd, 0xb5) & 0x10) ?
((cp_read(sd, 0xb5) & 0x08) ? '+' : '-') : 'x');
char vs_pol = ((cp_read(sd, 0xb5) & 0x40) ?
((cp_read(sd, 0xb5) & 0x20) ? '+' : '-') : 'x');
v4l2_info(sd,
"STDI: lcf (frame height - 1) = %d, bl = %d, lcvs (vsync) = %d, fcl = %d, %s, %chsync, %cvsync\n",
lcf, bl, lcvs, fcl,
(cp_read(sd, 0xb1) & 0x40) ?
"interlaced" : "progressive",
hs_pol, vs_pol);
}
if (adv7842_query_dv_timings(sd, &timings))
v4l2_info(sd, "No video detected\n");
else
v4l2_print_dv_timings(sd->name, "Detected format: ",
&timings, true);
v4l2_print_dv_timings(sd->name, "Configured format: ",
&state->timings, true);
if (no_cp_signal(sd))
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
csc_coeff_sel_rb[cp_read(sd, 0xf4) >> 4]);
if (!is_digital_input(sd))
return 0;
v4l2_info(sd, "-----%s status-----\n", is_hdmi(sd) ? "HDMI" : "DVI-D");
v4l2_info(sd, "HDCP encrypted content: %s\n",
(hdmi_read(sd, 0x05) & 0x40) ? "true" : "false");
v4l2_info(sd, "HDCP keys read: %s%s\n",
(hdmi_read(sd, 0x04) & 0x20) ? "yes" : "no",
(hdmi_read(sd, 0x04) & 0x10) ? "ERROR" : "");
if (!is_hdmi(sd))
return 0;
v4l2_info(sd, "Audio: pll %s, samples %s, %s\n",
audio_pll_locked ? "locked" : "not locked",
audio_sample_packet_detect ? "detected" : "not detected",
audio_mute ? "muted" : "enabled");
if (audio_pll_locked && audio_sample_packet_detect) {
v4l2_info(sd, "Audio format: %s\n",
(hdmi_read(sd, 0x07) & 0x40) ? "multi-channel" : "stereo");
}
v4l2_info(sd, "Audio CTS: %u\n", (hdmi_read(sd, 0x5b) << 12) +
(hdmi_read(sd, 0x5c) << 8) +
(hdmi_read(sd, 0x5d) & 0xf0));
v4l2_info(sd, "Audio N: %u\n", ((hdmi_read(sd, 0x5d) & 0x0f) << 16) +
(hdmi_read(sd, 0x5e) << 8) +
hdmi_read(sd, 0x5f));
v4l2_info(sd, "AV Mute: %s\n",
(hdmi_read(sd, 0x04) & 0x40) ? "on" : "off");
v4l2_info(sd, "Deep color mode: %s\n",
deep_color_mode_txt[hdmi_read(sd, 0x0b) >> 6]);
adv7842_log_infoframes(sd);
return 0;
}
static int adv7842_log_status(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
if (state->mode == ADV7842_MODE_SDP)
return adv7842_sdp_log_status(sd);
return adv7842_cp_log_status(sd);
}
static int adv7842_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
struct adv7842_state *state = to_state(sd);
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (state->mode != ADV7842_MODE_SDP)
return -ENODATA;
if (!(sdp_read(sd, 0x5A) & 0x01)) {
*std = 0;
v4l2_dbg(1, debug, sd, "%s: no valid signal\n", __func__);
return 0;
}
switch (sdp_read(sd, 0x52) & 0x0f) {
case 0:
*std &= V4L2_STD_NTSC;
break;
case 2:
*std &= V4L2_STD_NTSC_443;
break;
case 3:
*std &= V4L2_STD_SECAM;
break;
case 4:
*std &= V4L2_STD_PAL_M;
break;
case 6:
*std &= V4L2_STD_PAL_60;
break;
case 0xc:
*std &= V4L2_STD_PAL_Nc;
break;
case 0xe:
*std &= V4L2_STD_PAL;
break;
case 0xf:
*std &= V4L2_STD_SECAM;
break;
default:
*std &= V4L2_STD_ALL;
break;
}
return 0;
}
static void adv7842_s_sdp_io(struct v4l2_subdev *sd, struct adv7842_sdp_io_sync_adjustment *s)
{
if (s && s->adjust) {
sdp_io_write(sd, 0x94, (s->hs_beg >> 8) & 0xf);
sdp_io_write(sd, 0x95, s->hs_beg & 0xff);
sdp_io_write(sd, 0x96, (s->hs_width >> 8) & 0xf);
sdp_io_write(sd, 0x97, s->hs_width & 0xff);
sdp_io_write(sd, 0x98, (s->de_beg >> 8) & 0xf);
sdp_io_write(sd, 0x99, s->de_beg & 0xff);
sdp_io_write(sd, 0x9a, (s->de_end >> 8) & 0xf);
sdp_io_write(sd, 0x9b, s->de_end & 0xff);
sdp_io_write(sd, 0xa8, s->vs_beg_o);
sdp_io_write(sd, 0xa9, s->vs_beg_e);
sdp_io_write(sd, 0xaa, s->vs_end_o);
sdp_io_write(sd, 0xab, s->vs_end_e);
sdp_io_write(sd, 0xac, s->de_v_beg_o);
sdp_io_write(sd, 0xad, s->de_v_beg_e);
sdp_io_write(sd, 0xae, s->de_v_end_o);
sdp_io_write(sd, 0xaf, s->de_v_end_e);
} else {
sdp_io_write(sd, 0x94, 0x00);
sdp_io_write(sd, 0x95, 0x00);
sdp_io_write(sd, 0x96, 0x00);
sdp_io_write(sd, 0x97, 0x20);
sdp_io_write(sd, 0x98, 0x00);
sdp_io_write(sd, 0x99, 0x00);
sdp_io_write(sd, 0x9a, 0x00);
sdp_io_write(sd, 0x9b, 0x00);
sdp_io_write(sd, 0xa8, 0x04);
sdp_io_write(sd, 0xa9, 0x04);
sdp_io_write(sd, 0xaa, 0x04);
sdp_io_write(sd, 0xab, 0x04);
sdp_io_write(sd, 0xac, 0x04);
sdp_io_write(sd, 0xad, 0x04);
sdp_io_write(sd, 0xae, 0x04);
sdp_io_write(sd, 0xaf, 0x04);
}
}
static int adv7842_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct adv7842_state *state = to_state(sd);
struct adv7842_platform_data *pdata = &state->pdata;
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (state->mode != ADV7842_MODE_SDP)
return -ENODATA;
if (norm & V4L2_STD_625_50)
adv7842_s_sdp_io(sd, &pdata->sdp_io_sync_625);
else if (norm & V4L2_STD_525_60)
adv7842_s_sdp_io(sd, &pdata->sdp_io_sync_525);
else
adv7842_s_sdp_io(sd, NULL);
if (norm & V4L2_STD_ALL) {
state->norm = norm;
return 0;
}
return -EINVAL;
}
static int adv7842_g_std(struct v4l2_subdev *sd, v4l2_std_id *norm)
{
struct adv7842_state *state = to_state(sd);
v4l2_dbg(1, debug, sd, "%s:\n", __func__);
if (state->mode != ADV7842_MODE_SDP)
return -ENODATA;
*norm = state->norm;
return 0;
}
static int adv7842_core_init(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
struct adv7842_platform_data *pdata = &state->pdata;
hdmi_write(sd, 0x48,
(pdata->disable_pwrdnb ? 0x80 : 0) |
(pdata->disable_cable_det_rst ? 0x40 : 0));
disable_input(sd);
rep_write_and_or(sd, 0x77, 0xd3, 0x20);
io_write(sd, 0x0c, 0x42);
io_write(sd, 0x15, 0x80);
io_write(sd, 0x02,
0xf0 |
pdata->alt_gamma << 3 |
pdata->op_656_range << 2 |
pdata->alt_data_sat << 0);
io_write_and_or(sd, 0x05, 0xf0, pdata->blank_data << 3 |
pdata->insert_av_codes << 2 |
pdata->replicate_av_codes << 1);
adv7842_setup_format(state);
hdmi_write_and_or(sd, 0x1a, 0xf1, 0x08);
io_write_and_or(sd, 0x14, 0xc0,
pdata->dr_str_data << 4 |
pdata->dr_str_clk << 2 |
pdata->dr_str_sync);
cp_write_and_or(sd, 0xba, 0xfc, pdata->hdmi_free_run_enable |
(pdata->hdmi_free_run_mode << 1));
sdp_write_and_or(sd, 0xdd, 0xf0, pdata->sdp_free_run_force |
(pdata->sdp_free_run_cbar_en << 1) |
(pdata->sdp_free_run_man_col_en << 2) |
(pdata->sdp_free_run_auto << 3));
cp_write(sd, 0x69, 0x14);
io_write(sd, 0x06, 0xa6);
cp_write(sd, 0xf3, 0xdc);
afe_write(sd, 0xb5, 0x01);
afe_write(sd, 0x02, pdata->ain_sel);
io_write_and_or(sd, 0x30, ~(1 << 4), pdata->output_bus_lsb_to_msb << 4);
sdp_csc_coeff(sd, &pdata->sdp_csc_coeff);
if (pdata->sd_ram_size >= 128) {
sdp_write(sd, 0x12, 0x0d);
if (pdata->sd_ram_ddr) {
sdp_io_write(sd, 0x6f, 0x00);
sdp_io_write(sd, 0x75, 0x0a);
sdp_io_write(sd, 0x7a, 0xa5);
sdp_io_write(sd, 0x7b, 0x8f);
sdp_io_write(sd, 0x60, 0x01);
} else {
sdp_io_write(sd, 0x75, 0x0a);
sdp_io_write(sd, 0x74, 0x00);
sdp_io_write(sd, 0x79, 0x33);
sdp_io_write(sd, 0x6f, 0x01);
sdp_io_write(sd, 0x7a, 0xa5);
sdp_io_write(sd, 0x7b, 0x8f);
sdp_io_write(sd, 0x60, 0x01);
}
} else {
sdp_io_write(sd, 0x29, 0x10);
}
select_input(sd, pdata->vid_std_select);
enable_input(sd);
if (pdata->hpa_auto) {
hdmi_write(sd, 0x69, 0x5c);
} else {
hdmi_write(sd, 0x69, 0xa3);
io_write_and_or(sd, 0x20, 0xcf, 0x00);
}
io_write(sd, 0x19, 0x80 | pdata->llc_dll_phase);
io_write(sd, 0x33, 0x40);
io_write(sd, 0x40, 0xf2);
adv7842_irq_enable(sd, true);
return v4l2_ctrl_handler_setup(sd->ctrl_handler);
}
static int adv7842_ddr_ram_test(struct v4l2_subdev *sd)
{
int i;
int pass = 0;
int fail = 0;
int complete = 0;
io_write(sd, 0x00, 0x01);
io_write(sd, 0x01, 0x00);
afe_write(sd, 0x80, 0x92);
afe_write(sd, 0x9B, 0x01);
afe_write(sd, 0x9C, 0x60);
afe_write(sd, 0x9E, 0x02);
afe_write(sd, 0xA0, 0x0B);
afe_write(sd, 0xC3, 0x02);
io_write(sd, 0x0C, 0x40);
io_write(sd, 0x15, 0xBA);
sdp_write(sd, 0x12, 0x00);
io_write(sd, 0xFF, 0x04);
mdelay(5);
sdp_write(sd, 0x12, 0x00);
sdp_io_write(sd, 0x2A, 0x01);
sdp_io_write(sd, 0x7c, 0x19);
sdp_io_write(sd, 0x80, 0x87);
sdp_io_write(sd, 0x81, 0x4a);
sdp_io_write(sd, 0x82, 0x2c);
sdp_io_write(sd, 0x83, 0x0e);
sdp_io_write(sd, 0x84, 0x94);
sdp_io_write(sd, 0x85, 0x62);
sdp_io_write(sd, 0x7d, 0x00);
sdp_io_write(sd, 0x7e, 0x1a);
mdelay(5);
sdp_io_write(sd, 0xd9, 0xd5);
sdp_write(sd, 0x12, 0x05);
mdelay(20);
for (i = 0; i < 10; i++) {
u8 result = sdp_io_read(sd, 0xdb);
if (result & 0x10) {
complete++;
if (result & 0x20)
fail++;
else
pass++;
}
mdelay(20);
}
v4l2_dbg(1, debug, sd,
"Ram Test: completed %d of %d: pass %d, fail %d\n",
complete, i, pass, fail);
if (!complete || fail)
return -EIO;
return 0;
}
static void adv7842_rewrite_i2c_addresses(struct v4l2_subdev *sd,
struct adv7842_platform_data *pdata)
{
io_write(sd, 0xf1, pdata->i2c_sdp << 1);
io_write(sd, 0xf2, pdata->i2c_sdp_io << 1);
io_write(sd, 0xf3, pdata->i2c_avlink << 1);
io_write(sd, 0xf4, pdata->i2c_cec << 1);
io_write(sd, 0xf5, pdata->i2c_infoframe << 1);
io_write(sd, 0xf8, pdata->i2c_afe << 1);
io_write(sd, 0xf9, pdata->i2c_repeater << 1);
io_write(sd, 0xfa, pdata->i2c_edid << 1);
io_write(sd, 0xfb, pdata->i2c_hdmi << 1);
io_write(sd, 0xfd, pdata->i2c_cp << 1);
io_write(sd, 0xfe, pdata->i2c_vdp << 1);
}
static int adv7842_command_ram_test(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct adv7842_state *state = to_state(sd);
struct adv7842_platform_data *pdata = client->dev.platform_data;
struct v4l2_dv_timings timings;
int ret = 0;
if (!pdata)
return -ENODEV;
if (!pdata->sd_ram_size || !pdata->sd_ram_ddr) {
v4l2_info(sd, "no sdram or no ddr sdram\n");
return -EINVAL;
}
main_reset(sd);
adv7842_rewrite_i2c_addresses(sd, pdata);
ret = adv7842_ddr_ram_test(sd);
main_reset(sd);
adv7842_rewrite_i2c_addresses(sd, pdata);
adv7842_core_init(sd);
disable_input(sd);
select_input(sd, state->vid_std_select);
enable_input(sd);
edid_write_vga_segment(sd);
edid_write_hdmi_segment(sd, ADV7842_EDID_PORT_A);
edid_write_hdmi_segment(sd, ADV7842_EDID_PORT_B);
timings = state->timings;
memset(&state->timings, 0, sizeof(struct v4l2_dv_timings));
adv7842_s_dv_timings(sd, &timings);
return ret;
}
static long adv7842_ioctl(struct v4l2_subdev *sd, unsigned int cmd, void *arg)
{
switch (cmd) {
case ADV7842_CMD_RAM_TEST:
return adv7842_command_ram_test(sd);
}
return -ENOTTY;
}
static void adv7842_unregister_clients(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
if (state->i2c_avlink)
i2c_unregister_device(state->i2c_avlink);
if (state->i2c_cec)
i2c_unregister_device(state->i2c_cec);
if (state->i2c_infoframe)
i2c_unregister_device(state->i2c_infoframe);
if (state->i2c_sdp_io)
i2c_unregister_device(state->i2c_sdp_io);
if (state->i2c_sdp)
i2c_unregister_device(state->i2c_sdp);
if (state->i2c_afe)
i2c_unregister_device(state->i2c_afe);
if (state->i2c_repeater)
i2c_unregister_device(state->i2c_repeater);
if (state->i2c_edid)
i2c_unregister_device(state->i2c_edid);
if (state->i2c_hdmi)
i2c_unregister_device(state->i2c_hdmi);
if (state->i2c_cp)
i2c_unregister_device(state->i2c_cp);
if (state->i2c_vdp)
i2c_unregister_device(state->i2c_vdp);
state->i2c_avlink = NULL;
state->i2c_cec = NULL;
state->i2c_infoframe = NULL;
state->i2c_sdp_io = NULL;
state->i2c_sdp = NULL;
state->i2c_afe = NULL;
state->i2c_repeater = NULL;
state->i2c_edid = NULL;
state->i2c_hdmi = NULL;
state->i2c_cp = NULL;
state->i2c_vdp = NULL;
}
static struct i2c_client *adv7842_dummy_client(struct v4l2_subdev *sd, const char *desc,
u8 addr, u8 io_reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct i2c_client *cp;
io_write(sd, io_reg, addr << 1);
if (addr == 0) {
v4l2_err(sd, "no %s i2c addr configured\n", desc);
return NULL;
}
cp = i2c_new_dummy(client->adapter, io_read(sd, io_reg) >> 1);
if (!cp)
v4l2_err(sd, "register %s on i2c addr 0x%x failed\n", desc, addr);
return cp;
}
static int adv7842_register_clients(struct v4l2_subdev *sd)
{
struct adv7842_state *state = to_state(sd);
struct adv7842_platform_data *pdata = &state->pdata;
state->i2c_avlink = adv7842_dummy_client(sd, "avlink", pdata->i2c_avlink, 0xf3);
state->i2c_cec = adv7842_dummy_client(sd, "cec", pdata->i2c_cec, 0xf4);
state->i2c_infoframe = adv7842_dummy_client(sd, "infoframe", pdata->i2c_infoframe, 0xf5);
state->i2c_sdp_io = adv7842_dummy_client(sd, "sdp_io", pdata->i2c_sdp_io, 0xf2);
state->i2c_sdp = adv7842_dummy_client(sd, "sdp", pdata->i2c_sdp, 0xf1);
state->i2c_afe = adv7842_dummy_client(sd, "afe", pdata->i2c_afe, 0xf8);
state->i2c_repeater = adv7842_dummy_client(sd, "repeater", pdata->i2c_repeater, 0xf9);
state->i2c_edid = adv7842_dummy_client(sd, "edid", pdata->i2c_edid, 0xfa);
state->i2c_hdmi = adv7842_dummy_client(sd, "hdmi", pdata->i2c_hdmi, 0xfb);
state->i2c_cp = adv7842_dummy_client(sd, "cp", pdata->i2c_cp, 0xfd);
state->i2c_vdp = adv7842_dummy_client(sd, "vdp", pdata->i2c_vdp, 0xfe);
if (!state->i2c_avlink ||
!state->i2c_cec ||
!state->i2c_infoframe ||
!state->i2c_sdp_io ||
!state->i2c_sdp ||
!state->i2c_afe ||
!state->i2c_repeater ||
!state->i2c_edid ||
!state->i2c_hdmi ||
!state->i2c_cp ||
!state->i2c_vdp)
return -1;
return 0;
}
static int adv7842_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv7842_state *state;
static const struct v4l2_dv_timings cea640x480 =
V4L2_DV_BT_CEA_640X480P59_94;
struct adv7842_platform_data *pdata = client->dev.platform_data;
struct v4l2_ctrl_handler *hdl;
struct v4l2_subdev *sd;
u16 rev;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_dbg(1, debug, client, "detecting adv7842 client on address 0x%x\n",
client->addr << 1);
if (!pdata) {
v4l_err(client, "No platform data!\n");
return -ENODEV;
}
state = devm_kzalloc(&client->dev, sizeof(struct adv7842_state), GFP_KERNEL);
if (!state) {
v4l_err(client, "Could not allocate adv7842_state memory!\n");
return -ENOMEM;
}
state->pdata = *pdata;
state->timings = cea640x480;
state->format = adv7842_format_info(state, MEDIA_BUS_FMT_YUYV8_2X8);
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &adv7842_ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
state->mode = pdata->mode;
state->hdmi_port_a = pdata->input == ADV7842_SELECT_HDMI_PORT_A;
state->restart_stdi_once = true;
rev = adv_smbus_read_byte_data_check(client, 0xea, false) << 8 |
adv_smbus_read_byte_data_check(client, 0xeb, false);
if (rev != 0x2012) {
v4l2_info(sd, "got rev=0x%04x on first read attempt\n", rev);
rev = adv_smbus_read_byte_data_check(client, 0xea, false) << 8 |
adv_smbus_read_byte_data_check(client, 0xeb, false);
}
if (rev != 0x2012) {
v4l2_info(sd, "not an adv7842 on address 0x%x (rev=0x%04x)\n",
client->addr << 1, rev);
return -ENODEV;
}
if (pdata->chip_reset)
main_reset(sd);
hdl = &state->hdl;
v4l2_ctrl_handler_init(hdl, 6);
v4l2_ctrl_new_std(hdl, &adv7842_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &adv7842_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &adv7842_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &adv7842_ctrl_ops,
V4L2_CID_HUE, 0, 128, 1, 0);
state->detect_tx_5v_ctrl = v4l2_ctrl_new_std(hdl, NULL,
V4L2_CID_DV_RX_POWER_PRESENT, 0, 3, 0, 0);
state->analog_sampling_phase_ctrl = v4l2_ctrl_new_custom(hdl,
&adv7842_ctrl_analog_sampling_phase, NULL);
state->free_run_color_ctrl_manual = v4l2_ctrl_new_custom(hdl,
&adv7842_ctrl_free_run_color_manual, NULL);
state->free_run_color_ctrl = v4l2_ctrl_new_custom(hdl,
&adv7842_ctrl_free_run_color, NULL);
state->rgb_quantization_range_ctrl =
v4l2_ctrl_new_std_menu(hdl, &adv7842_ctrl_ops,
V4L2_CID_DV_RX_RGB_RANGE, V4L2_DV_RGB_RANGE_FULL,
0, V4L2_DV_RGB_RANGE_AUTO);
sd->ctrl_handler = hdl;
if (hdl->error) {
err = hdl->error;
goto err_hdl;
}
state->detect_tx_5v_ctrl->is_private = true;
state->rgb_quantization_range_ctrl->is_private = true;
state->analog_sampling_phase_ctrl->is_private = true;
state->free_run_color_ctrl_manual->is_private = true;
state->free_run_color_ctrl->is_private = true;
if (adv7842_s_detect_tx_5v_ctrl(sd)) {
err = -ENODEV;
goto err_hdl;
}
if (adv7842_register_clients(sd) < 0) {
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
adv7842_delayed_work_enable_hotplug);
state->pad.flags = MEDIA_PAD_FL_SOURCE;
err = media_entity_init(&sd->entity, 1, &state->pad, 0);
if (err)
goto err_work_queues;
err = adv7842_core_init(sd);
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
adv7842_unregister_clients(sd);
err_hdl:
v4l2_ctrl_handler_free(hdl);
return err;
}
static int adv7842_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7842_state *state = to_state(sd);
adv7842_irq_enable(sd, false);
cancel_delayed_work(&state->delayed_work_enable_hotplug);
destroy_workqueue(state->work_queues);
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
adv7842_unregister_clients(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
return 0;
}
