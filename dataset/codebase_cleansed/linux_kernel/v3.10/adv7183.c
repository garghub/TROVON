static inline struct adv7183 *to_adv7183(struct v4l2_subdev *sd)
{
return container_of(sd, struct adv7183, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct adv7183, hdl)->sd;
}
static inline int adv7183_read(struct v4l2_subdev *sd, unsigned char reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_read_byte_data(client, reg);
}
static inline int adv7183_write(struct v4l2_subdev *sd, unsigned char reg,
unsigned char value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, reg, value);
}
static int adv7183_writeregs(struct v4l2_subdev *sd,
const unsigned char *regs, unsigned int num)
{
unsigned char reg, data;
unsigned int cnt = 0;
if (num & 0x1) {
v4l2_err(sd, "invalid regs array\n");
return -1;
}
while (cnt < num) {
reg = *regs++;
data = *regs++;
cnt += 2;
adv7183_write(sd, reg, data);
}
return 0;
}
static int adv7183_log_status(struct v4l2_subdev *sd)
{
struct adv7183 *decoder = to_adv7183(sd);
v4l2_info(sd, "adv7183: Input control = 0x%02x\n",
adv7183_read(sd, ADV7183_IN_CTRL));
v4l2_info(sd, "adv7183: Video selection = 0x%02x\n",
adv7183_read(sd, ADV7183_VD_SEL));
v4l2_info(sd, "adv7183: Output control = 0x%02x\n",
adv7183_read(sd, ADV7183_OUT_CTRL));
v4l2_info(sd, "adv7183: Extended output control = 0x%02x\n",
adv7183_read(sd, ADV7183_EXT_OUT_CTRL));
v4l2_info(sd, "adv7183: Autodetect enable = 0x%02x\n",
adv7183_read(sd, ADV7183_AUTO_DET_EN));
v4l2_info(sd, "adv7183: Contrast = 0x%02x\n",
adv7183_read(sd, ADV7183_CONTRAST));
v4l2_info(sd, "adv7183: Brightness = 0x%02x\n",
adv7183_read(sd, ADV7183_BRIGHTNESS));
v4l2_info(sd, "adv7183: Hue = 0x%02x\n",
adv7183_read(sd, ADV7183_HUE));
v4l2_info(sd, "adv7183: Default value Y = 0x%02x\n",
adv7183_read(sd, ADV7183_DEF_Y));
v4l2_info(sd, "adv7183: Default value C = 0x%02x\n",
adv7183_read(sd, ADV7183_DEF_C));
v4l2_info(sd, "adv7183: ADI control = 0x%02x\n",
adv7183_read(sd, ADV7183_ADI_CTRL));
v4l2_info(sd, "adv7183: Power Management = 0x%02x\n",
adv7183_read(sd, ADV7183_POW_MANAGE));
v4l2_info(sd, "adv7183: Status 1 2 and 3 = 0x%02x 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_STATUS_1),
adv7183_read(sd, ADV7183_STATUS_2),
adv7183_read(sd, ADV7183_STATUS_3));
v4l2_info(sd, "adv7183: Ident = 0x%02x\n",
adv7183_read(sd, ADV7183_IDENT));
v4l2_info(sd, "adv7183: Analog clamp control = 0x%02x\n",
adv7183_read(sd, ADV7183_ANAL_CLAMP_CTRL));
v4l2_info(sd, "adv7183: Digital clamp control 1 = 0x%02x\n",
adv7183_read(sd, ADV7183_DIGI_CLAMP_CTRL_1));
v4l2_info(sd, "adv7183: Shaping filter control 1 and 2 = 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_SHAP_FILT_CTRL),
adv7183_read(sd, ADV7183_SHAP_FILT_CTRL_2));
v4l2_info(sd, "adv7183: Comb filter control = 0x%02x\n",
adv7183_read(sd, ADV7183_COMB_FILT_CTRL));
v4l2_info(sd, "adv7183: ADI control 2 = 0x%02x\n",
adv7183_read(sd, ADV7183_ADI_CTRL_2));
v4l2_info(sd, "adv7183: Pixel delay control = 0x%02x\n",
adv7183_read(sd, ADV7183_PIX_DELAY_CTRL));
v4l2_info(sd, "adv7183: Misc gain control = 0x%02x\n",
adv7183_read(sd, ADV7183_MISC_GAIN_CTRL));
v4l2_info(sd, "adv7183: AGC mode control = 0x%02x\n",
adv7183_read(sd, ADV7183_AGC_MODE_CTRL));
v4l2_info(sd, "adv7183: Chroma gain control 1 and 2 = 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_CHRO_GAIN_CTRL_1),
adv7183_read(sd, ADV7183_CHRO_GAIN_CTRL_2));
v4l2_info(sd, "adv7183: Luma gain control 1 and 2 = 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_LUMA_GAIN_CTRL_1),
adv7183_read(sd, ADV7183_LUMA_GAIN_CTRL_2));
v4l2_info(sd, "adv7183: Vsync field control 1 2 and 3 = 0x%02x 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_VS_FIELD_CTRL_1),
adv7183_read(sd, ADV7183_VS_FIELD_CTRL_2),
adv7183_read(sd, ADV7183_VS_FIELD_CTRL_3));
v4l2_info(sd, "adv7183: Hsync positon control 1 2 and 3 = 0x%02x 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_HS_POS_CTRL_1),
adv7183_read(sd, ADV7183_HS_POS_CTRL_2),
adv7183_read(sd, ADV7183_HS_POS_CTRL_3));
v4l2_info(sd, "adv7183: Polarity = 0x%02x\n",
adv7183_read(sd, ADV7183_POLARITY));
v4l2_info(sd, "adv7183: ADC control = 0x%02x\n",
adv7183_read(sd, ADV7183_ADC_CTRL));
v4l2_info(sd, "adv7183: SD offset Cb and Cr = 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_SD_OFFSET_CB),
adv7183_read(sd, ADV7183_SD_OFFSET_CR));
v4l2_info(sd, "adv7183: SD saturation Cb and Cr = 0x%02x 0x%02x\n",
adv7183_read(sd, ADV7183_SD_SATURATION_CB),
adv7183_read(sd, ADV7183_SD_SATURATION_CR));
v4l2_info(sd, "adv7183: Drive strength = 0x%02x\n",
adv7183_read(sd, ADV7183_DRIVE_STR));
v4l2_ctrl_handler_log_status(&decoder->hdl, sd->name);
return 0;
}
static int adv7183_g_std(struct v4l2_subdev *sd, v4l2_std_id *std)
{
struct adv7183 *decoder = to_adv7183(sd);
*std = decoder->std;
return 0;
}
static int adv7183_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct adv7183 *decoder = to_adv7183(sd);
int reg;
reg = adv7183_read(sd, ADV7183_IN_CTRL) & 0xF;
if (std == V4L2_STD_PAL_60)
reg |= 0x60;
else if (std == V4L2_STD_NTSC_443)
reg |= 0x70;
else if (std == V4L2_STD_PAL_N)
reg |= 0x90;
else if (std == V4L2_STD_PAL_M)
reg |= 0xA0;
else if (std == V4L2_STD_PAL_Nc)
reg |= 0xC0;
else if (std & V4L2_STD_PAL)
reg |= 0x80;
else if (std & V4L2_STD_NTSC)
reg |= 0x50;
else if (std & V4L2_STD_SECAM)
reg |= 0xE0;
else
return -EINVAL;
adv7183_write(sd, ADV7183_IN_CTRL, reg);
decoder->std = std;
return 0;
}
static int adv7183_reset(struct v4l2_subdev *sd, u32 val)
{
int reg;
reg = adv7183_read(sd, ADV7183_POW_MANAGE) | 0x80;
adv7183_write(sd, ADV7183_POW_MANAGE, reg);
usleep_range(5000, 10000);
return 0;
}
static int adv7183_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct adv7183 *decoder = to_adv7183(sd);
int reg;
if ((input > ADV7183_COMPONENT1) || (output > ADV7183_16BIT_OUT))
return -EINVAL;
if (input != decoder->input) {
decoder->input = input;
reg = adv7183_read(sd, ADV7183_IN_CTRL) & 0xF0;
switch (input) {
case ADV7183_COMPOSITE1:
reg |= 0x1;
break;
case ADV7183_COMPOSITE2:
reg |= 0x2;
break;
case ADV7183_COMPOSITE3:
reg |= 0x3;
break;
case ADV7183_COMPOSITE4:
reg |= 0x4;
break;
case ADV7183_COMPOSITE5:
reg |= 0x5;
break;
case ADV7183_COMPOSITE6:
reg |= 0xB;
break;
case ADV7183_COMPOSITE7:
reg |= 0xC;
break;
case ADV7183_COMPOSITE8:
reg |= 0xD;
break;
case ADV7183_COMPOSITE9:
reg |= 0xE;
break;
case ADV7183_COMPOSITE10:
reg |= 0xF;
break;
case ADV7183_SVIDEO0:
reg |= 0x6;
break;
case ADV7183_SVIDEO1:
reg |= 0x7;
break;
case ADV7183_SVIDEO2:
reg |= 0x8;
break;
case ADV7183_COMPONENT0:
reg |= 0x9;
break;
case ADV7183_COMPONENT1:
reg |= 0xA;
break;
default:
break;
}
adv7183_write(sd, ADV7183_IN_CTRL, reg);
}
if (output != decoder->output) {
decoder->output = output;
reg = adv7183_read(sd, ADV7183_OUT_CTRL) & 0xC0;
switch (output) {
case ADV7183_16BIT_OUT:
reg |= 0x9;
break;
default:
reg |= 0xC;
break;
}
adv7183_write(sd, ADV7183_OUT_CTRL, reg);
}
return 0;
}
static int adv7183_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
int val = ctrl->val;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
if (val < 0)
val = 127 - val;
adv7183_write(sd, ADV7183_BRIGHTNESS, val);
break;
case V4L2_CID_CONTRAST:
adv7183_write(sd, ADV7183_CONTRAST, val);
break;
case V4L2_CID_SATURATION:
adv7183_write(sd, ADV7183_SD_SATURATION_CB, val >> 8);
adv7183_write(sd, ADV7183_SD_SATURATION_CR, (val & 0xFF));
break;
case V4L2_CID_HUE:
adv7183_write(sd, ADV7183_SD_OFFSET_CB, val >> 8);
adv7183_write(sd, ADV7183_SD_OFFSET_CR, (val & 0xFF));
break;
default:
return -EINVAL;
}
return 0;
}
static int adv7183_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
struct adv7183 *decoder = to_adv7183(sd);
int reg;
reg = adv7183_read(sd, ADV7183_IN_CTRL) & 0xF;
adv7183_write(sd, ADV7183_IN_CTRL, reg);
mdelay(10);
reg = adv7183_read(sd, ADV7183_STATUS_1);
switch ((reg >> 0x4) & 0x7) {
case 0:
*std = V4L2_STD_NTSC;
break;
case 1:
*std = V4L2_STD_NTSC_443;
break;
case 2:
*std = V4L2_STD_PAL_M;
break;
case 3:
*std = V4L2_STD_PAL_60;
break;
case 4:
*std = V4L2_STD_PAL;
break;
case 5:
*std = V4L2_STD_SECAM;
break;
case 6:
*std = V4L2_STD_PAL_Nc;
break;
case 7:
*std = V4L2_STD_SECAM;
break;
default:
*std = V4L2_STD_UNKNOWN;
break;
}
adv7183_s_std(sd, decoder->std);
return 0;
}
static int adv7183_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
int reg;
*status = V4L2_IN_ST_NO_SIGNAL;
reg = adv7183_read(sd, ADV7183_STATUS_1);
if (reg < 0)
return reg;
if (reg & 0x1)
*status = 0;
return 0;
}
static int adv7183_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned index,
enum v4l2_mbus_pixelcode *code)
{
if (index > 0)
return -EINVAL;
*code = V4L2_MBUS_FMT_UYVY8_2X8;
return 0;
}
static int adv7183_try_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct adv7183 *decoder = to_adv7183(sd);
fmt->code = V4L2_MBUS_FMT_UYVY8_2X8;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
if (decoder->std & V4L2_STD_525_60) {
fmt->field = V4L2_FIELD_SEQ_TB;
fmt->width = 720;
fmt->height = 480;
} else {
fmt->field = V4L2_FIELD_SEQ_BT;
fmt->width = 720;
fmt->height = 576;
}
return 0;
}
static int adv7183_s_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct adv7183 *decoder = to_adv7183(sd);
adv7183_try_mbus_fmt(sd, fmt);
decoder->fmt = *fmt;
return 0;
}
static int adv7183_g_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct adv7183 *decoder = to_adv7183(sd);
*fmt = decoder->fmt;
return 0;
}
static int adv7183_s_stream(struct v4l2_subdev *sd, int enable)
{
struct adv7183 *decoder = to_adv7183(sd);
if (enable)
gpio_direction_output(decoder->oe_pin, 0);
else
gpio_direction_output(decoder->oe_pin, 1);
udelay(1);
return 0;
}
static int adv7183_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
int rev;
struct i2c_client *client = v4l2_get_subdevdata(sd);
rev = adv7183_read(sd, ADV7183_IDENT);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_ADV7183, rev);
}
static int adv7183_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = adv7183_read(sd, reg->reg & 0xff);
reg->size = 1;
return 0;
}
static int adv7183_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
adv7183_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int adv7183_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv7183 *decoder;
struct v4l2_subdev *sd;
struct v4l2_ctrl_handler *hdl;
int ret;
struct v4l2_mbus_framefmt fmt;
const unsigned *pin_array;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
pin_array = client->dev.platform_data;
if (pin_array == NULL)
return -EINVAL;
decoder = kzalloc(sizeof(struct adv7183), GFP_KERNEL);
if (decoder == NULL)
return -ENOMEM;
decoder->reset_pin = pin_array[0];
decoder->oe_pin = pin_array[1];
if (gpio_request(decoder->reset_pin, "ADV7183 Reset")) {
v4l_err(client, "failed to request GPIO %d\n", decoder->reset_pin);
ret = -EBUSY;
goto err_free_decoder;
}
if (gpio_request(decoder->oe_pin, "ADV7183 Output Enable")) {
v4l_err(client, "failed to request GPIO %d\n", decoder->oe_pin);
ret = -EBUSY;
goto err_free_reset;
}
sd = &decoder->sd;
v4l2_i2c_subdev_init(sd, client, &adv7183_ops);
hdl = &decoder->hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &adv7183_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &adv7183_ctrl_ops,
V4L2_CID_CONTRAST, 0, 0xFF, 1, 0x80);
v4l2_ctrl_new_std(hdl, &adv7183_ctrl_ops,
V4L2_CID_SATURATION, 0, 0xFFFF, 1, 0x8080);
v4l2_ctrl_new_std(hdl, &adv7183_ctrl_ops,
V4L2_CID_HUE, 0, 0xFFFF, 1, 0x8080);
sd->ctrl_handler = hdl;
if (hdl->error) {
ret = hdl->error;
v4l2_ctrl_handler_free(hdl);
goto err_free_oe;
}
decoder->std = V4L2_STD_PAL;
decoder->input = ADV7183_COMPOSITE4;
decoder->output = ADV7183_8BIT_OUT;
gpio_direction_output(decoder->oe_pin, 1);
gpio_direction_output(decoder->reset_pin, 0);
mdelay(10);
gpio_direction_output(decoder->reset_pin, 1);
mdelay(5);
adv7183_writeregs(sd, adv7183_init_regs, ARRAY_SIZE(adv7183_init_regs));
adv7183_s_std(sd, decoder->std);
fmt.width = 720;
fmt.height = 576;
adv7183_s_mbus_fmt(sd, &fmt);
ret = v4l2_ctrl_handler_setup(hdl);
if (ret) {
v4l2_ctrl_handler_free(hdl);
goto err_free_oe;
}
return 0;
err_free_oe:
gpio_free(decoder->oe_pin);
err_free_reset:
gpio_free(decoder->reset_pin);
err_free_decoder:
kfree(decoder);
return ret;
}
static int adv7183_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct adv7183 *decoder = to_adv7183(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
gpio_free(decoder->oe_pin);
gpio_free(decoder->reset_pin);
kfree(decoder);
return 0;
}
