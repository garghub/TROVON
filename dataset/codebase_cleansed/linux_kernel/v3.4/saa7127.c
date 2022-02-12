static inline struct saa7127_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa7127_state, sd);
}
static int saa7127_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static int saa7127_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int i;
for (i = 0; i < 3; i++) {
if (i2c_smbus_write_byte_data(client, reg, val) == 0)
return 0;
}
v4l2_err(sd, "I2C Write Problem\n");
return -1;
}
static int saa7127_write_inittab(struct v4l2_subdev *sd,
const struct i2c_reg_value *regs)
{
while (regs->reg != 0) {
saa7127_write(sd, regs->reg, regs->value);
regs++;
}
return 0;
}
static int saa7127_set_vps(struct v4l2_subdev *sd, const struct v4l2_sliced_vbi_data *data)
{
struct saa7127_state *state = to_state(sd);
int enable = (data->line != 0);
if (enable && (data->field != 0 || data->line != 16))
return -EINVAL;
if (state->vps_enable != enable) {
v4l2_dbg(1, debug, sd, "Turn VPS Signal %s\n", enable ? "on" : "off");
saa7127_write(sd, 0x54, enable << 7);
state->vps_enable = enable;
}
if (!enable)
return 0;
state->vps_data[0] = data->data[2];
state->vps_data[1] = data->data[8];
state->vps_data[2] = data->data[9];
state->vps_data[3] = data->data[10];
state->vps_data[4] = data->data[11];
v4l2_dbg(1, debug, sd, "Set VPS data %02x %02x %02x %02x %02x\n",
state->vps_data[0], state->vps_data[1],
state->vps_data[2], state->vps_data[3],
state->vps_data[4]);
saa7127_write(sd, 0x55, state->vps_data[0]);
saa7127_write(sd, 0x56, state->vps_data[1]);
saa7127_write(sd, 0x57, state->vps_data[2]);
saa7127_write(sd, 0x58, state->vps_data[3]);
saa7127_write(sd, 0x59, state->vps_data[4]);
return 0;
}
static int saa7127_set_cc(struct v4l2_subdev *sd, const struct v4l2_sliced_vbi_data *data)
{
struct saa7127_state *state = to_state(sd);
u16 cc = data->data[1] << 8 | data->data[0];
int enable = (data->line != 0);
if (enable && (data->field != 0 || data->line != 21))
return -EINVAL;
if (state->cc_enable != enable) {
v4l2_dbg(1, debug, sd,
"Turn CC %s\n", enable ? "on" : "off");
saa7127_write(sd, SAA7127_REG_CLOSED_CAPTION,
(state->xds_enable << 7) | (enable << 6) | 0x11);
state->cc_enable = enable;
}
if (!enable)
return 0;
v4l2_dbg(2, debug, sd, "CC data: %04x\n", cc);
saa7127_write(sd, SAA7127_REG_LINE_21_ODD_0, cc & 0xff);
saa7127_write(sd, SAA7127_REG_LINE_21_ODD_1, cc >> 8);
state->cc_data = cc;
return 0;
}
static int saa7127_set_xds(struct v4l2_subdev *sd, const struct v4l2_sliced_vbi_data *data)
{
struct saa7127_state *state = to_state(sd);
u16 xds = data->data[1] << 8 | data->data[0];
int enable = (data->line != 0);
if (enable && (data->field != 1 || data->line != 21))
return -EINVAL;
if (state->xds_enable != enable) {
v4l2_dbg(1, debug, sd, "Turn XDS %s\n", enable ? "on" : "off");
saa7127_write(sd, SAA7127_REG_CLOSED_CAPTION,
(enable << 7) | (state->cc_enable << 6) | 0x11);
state->xds_enable = enable;
}
if (!enable)
return 0;
v4l2_dbg(2, debug, sd, "XDS data: %04x\n", xds);
saa7127_write(sd, SAA7127_REG_LINE_21_EVEN_0, xds & 0xff);
saa7127_write(sd, SAA7127_REG_LINE_21_EVEN_1, xds >> 8);
state->xds_data = xds;
return 0;
}
static int saa7127_set_wss(struct v4l2_subdev *sd, const struct v4l2_sliced_vbi_data *data)
{
struct saa7127_state *state = to_state(sd);
int enable = (data->line != 0);
if (enable && (data->field != 0 || data->line != 23))
return -EINVAL;
if (state->wss_enable != enable) {
v4l2_dbg(1, debug, sd, "Turn WSS %s\n", enable ? "on" : "off");
saa7127_write(sd, 0x27, enable << 7);
state->wss_enable = enable;
}
if (!enable)
return 0;
saa7127_write(sd, 0x26, data->data[0]);
saa7127_write(sd, 0x27, 0x80 | (data->data[1] & 0x3f));
v4l2_dbg(1, debug, sd,
"WSS mode: %s\n", wss_strs[data->data[0] & 0xf]);
state->wss_mode = (data->data[1] & 0x3f) << 8 | data->data[0];
return 0;
}
static int saa7127_set_video_enable(struct v4l2_subdev *sd, int enable)
{
struct saa7127_state *state = to_state(sd);
if (enable) {
v4l2_dbg(1, debug, sd, "Enable Video Output\n");
saa7127_write(sd, 0x2d, state->reg_2d);
saa7127_write(sd, 0x61, state->reg_61);
} else {
v4l2_dbg(1, debug, sd, "Disable Video Output\n");
saa7127_write(sd, 0x2d, (state->reg_2d & 0xf0));
saa7127_write(sd, 0x61, (state->reg_61 | 0xc0));
}
state->video_enable = enable;
return 0;
}
static int saa7127_set_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa7127_state *state = to_state(sd);
const struct i2c_reg_value *inittab;
if (std & V4L2_STD_525_60) {
v4l2_dbg(1, debug, sd, "Selecting 60 Hz video Standard\n");
inittab = saa7127_init_config_60hz;
state->reg_61 = SAA7127_60HZ_DAC_CONTROL;
} else if (state->ident == V4L2_IDENT_SAA7129 &&
(std & V4L2_STD_SECAM) &&
!(std & (V4L2_STD_625_50 & ~V4L2_STD_SECAM))) {
v4l2_dbg(1, debug, sd,
"Selecting 50 Hz SECAM video Standard\n");
inittab = saa7127_init_config_50hz_secam;
state->reg_61 = SAA7127_50HZ_SECAM_DAC_CONTROL;
} else {
v4l2_dbg(1, debug, sd, "Selecting 50 Hz PAL video Standard\n");
inittab = saa7127_init_config_50hz_pal;
state->reg_61 = SAA7127_50HZ_PAL_DAC_CONTROL;
}
saa7127_write_inittab(sd, inittab);
state->std = std;
return 0;
}
static int saa7127_set_output_type(struct v4l2_subdev *sd, int output)
{
struct saa7127_state *state = to_state(sd);
switch (output) {
case SAA7127_OUTPUT_TYPE_RGB:
state->reg_2d = 0x0f;
state->reg_3a = 0x13;
break;
case SAA7127_OUTPUT_TYPE_COMPOSITE:
if (state->ident == V4L2_IDENT_SAA7129)
state->reg_2d = 0x20;
else
state->reg_2d = 0x08;
state->reg_3a = 0x13;
break;
case SAA7127_OUTPUT_TYPE_SVIDEO:
if (state->ident == V4L2_IDENT_SAA7129)
state->reg_2d = 0x18;
else
state->reg_2d = 0xff;
state->reg_3a = 0x13;
break;
case SAA7127_OUTPUT_TYPE_YUV_V:
state->reg_2d = 0x4f;
state->reg_3a = 0x0b;
break;
case SAA7127_OUTPUT_TYPE_YUV_C:
state->reg_2d = 0x0f;
state->reg_3a = 0x0b;
break;
case SAA7127_OUTPUT_TYPE_BOTH:
if (state->ident == V4L2_IDENT_SAA7129)
state->reg_2d = 0x38;
else
state->reg_2d = 0xbf;
state->reg_3a = 0x13;
break;
default:
return -EINVAL;
}
v4l2_dbg(1, debug, sd,
"Selecting %s output type\n", output_strs[output]);
saa7127_write(sd, 0x2d, state->reg_2d);
saa7127_write(sd, 0x3a, state->reg_3a | state->reg_3a_cb);
state->output_type = output;
return 0;
}
static int saa7127_set_input_type(struct v4l2_subdev *sd, int input)
{
struct saa7127_state *state = to_state(sd);
switch (input) {
case SAA7127_INPUT_TYPE_NORMAL:
v4l2_dbg(1, debug, sd, "Selecting Normal Encoder Input\n");
state->reg_3a_cb = 0;
break;
case SAA7127_INPUT_TYPE_TEST_IMAGE:
v4l2_dbg(1, debug, sd, "Selecting Color Bar generator\n");
state->reg_3a_cb = 0x80;
break;
default:
return -EINVAL;
}
saa7127_write(sd, 0x3a, state->reg_3a | state->reg_3a_cb);
state->input_type = input;
return 0;
}
static int saa7127_s_std_output(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct saa7127_state *state = to_state(sd);
if (state->std == std)
return 0;
return saa7127_set_std(sd, std);
}
static int saa7127_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct saa7127_state *state = to_state(sd);
int rc = 0;
if (state->input_type != input)
rc = saa7127_set_input_type(sd, input);
if (rc == 0 && state->output_type != output)
rc = saa7127_set_output_type(sd, output);
return rc;
}
static int saa7127_s_stream(struct v4l2_subdev *sd, int enable)
{
struct saa7127_state *state = to_state(sd);
if (state->video_enable == enable)
return 0;
return saa7127_set_video_enable(sd, enable);
}
static int saa7127_g_sliced_fmt(struct v4l2_subdev *sd, struct v4l2_sliced_vbi_format *fmt)
{
struct saa7127_state *state = to_state(sd);
memset(fmt, 0, sizeof(*fmt));
if (state->vps_enable)
fmt->service_lines[0][16] = V4L2_SLICED_VPS;
if (state->wss_enable)
fmt->service_lines[0][23] = V4L2_SLICED_WSS_625;
if (state->cc_enable) {
fmt->service_lines[0][21] = V4L2_SLICED_CAPTION_525;
fmt->service_lines[1][21] = V4L2_SLICED_CAPTION_525;
}
fmt->service_set =
(state->vps_enable ? V4L2_SLICED_VPS : 0) |
(state->wss_enable ? V4L2_SLICED_WSS_625 : 0) |
(state->cc_enable ? V4L2_SLICED_CAPTION_525 : 0);
return 0;
}
static int saa7127_s_vbi_data(struct v4l2_subdev *sd, const struct v4l2_sliced_vbi_data *data)
{
switch (data->id) {
case V4L2_SLICED_WSS_625:
return saa7127_set_wss(sd, data);
case V4L2_SLICED_VPS:
return saa7127_set_vps(sd, data);
case V4L2_SLICED_CAPTION_525:
if (data->field == 0)
return saa7127_set_cc(sd, data);
return saa7127_set_xds(sd, data);
default:
return -EINVAL;
}
return 0;
}
static int saa7127_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = saa7127_read(sd, reg->reg & 0xff);
reg->size = 1;
return 0;
}
static int saa7127_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
saa7127_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int saa7127_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct saa7127_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, state->ident, 0);
}
static int saa7127_log_status(struct v4l2_subdev *sd)
{
struct saa7127_state *state = to_state(sd);
v4l2_info(sd, "Standard: %s\n", (state->std & V4L2_STD_525_60) ? "60 Hz" : "50 Hz");
v4l2_info(sd, "Input: %s\n", state->input_type ? "color bars" : "normal");
v4l2_info(sd, "Output: %s\n", state->video_enable ?
output_strs[state->output_type] : "disabled");
v4l2_info(sd, "WSS: %s\n", state->wss_enable ?
wss_strs[state->wss_mode] : "disabled");
v4l2_info(sd, "VPS: %s\n", state->vps_enable ? "enabled" : "disabled");
v4l2_info(sd, "CC: %s\n", state->cc_enable ? "enabled" : "disabled");
return 0;
}
static int saa7127_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct saa7127_state *state;
struct v4l2_subdev *sd;
struct v4l2_sliced_vbi_data vbi = { 0, 0, 0, 0 };
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_dbg(1, debug, client, "detecting saa7127 client on address 0x%x\n",
client->addr << 1);
state = kzalloc(sizeof(struct saa7127_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &saa7127_ops);
if ((saa7127_read(sd, 0) & 0xe4) != 0 ||
(saa7127_read(sd, 0x29) & 0x3f) != 0x1d) {
v4l2_dbg(1, debug, sd, "saa7127 not found\n");
kfree(state);
return -ENODEV;
}
if (id->driver_data) {
state->ident = id->driver_data;
} else {
int read_result;
read_result = saa7127_read(sd, SAA7129_REG_FADE_KEY_COL2);
saa7127_write(sd, SAA7129_REG_FADE_KEY_COL2, 0xaa);
if (saa7127_read(sd, SAA7129_REG_FADE_KEY_COL2) == 0xaa) {
saa7127_write(sd, SAA7129_REG_FADE_KEY_COL2,
read_result);
state->ident = V4L2_IDENT_SAA7129;
strlcpy(client->name, "saa7129", I2C_NAME_SIZE);
} else {
state->ident = V4L2_IDENT_SAA7127;
strlcpy(client->name, "saa7127", I2C_NAME_SIZE);
}
}
v4l2_info(sd, "%s found @ 0x%x (%s)\n", client->name,
client->addr << 1, client->adapter->name);
v4l2_dbg(1, debug, sd, "Configuring encoder\n");
saa7127_write_inittab(sd, saa7127_init_config_common);
saa7127_set_std(sd, V4L2_STD_NTSC);
saa7127_set_output_type(sd, SAA7127_OUTPUT_TYPE_BOTH);
saa7127_set_vps(sd, &vbi);
saa7127_set_wss(sd, &vbi);
saa7127_set_cc(sd, &vbi);
saa7127_set_xds(sd, &vbi);
if (test_image == 1)
saa7127_set_input_type(sd, SAA7127_INPUT_TYPE_TEST_IMAGE);
else
saa7127_set_input_type(sd, SAA7127_INPUT_TYPE_NORMAL);
saa7127_set_video_enable(sd, 1);
if (state->ident == V4L2_IDENT_SAA7129)
saa7127_write_inittab(sd, saa7129_init_config_extra);
return 0;
}
static int saa7127_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
saa7127_set_video_enable(sd, 0);
kfree(to_state(sd));
return 0;
}
