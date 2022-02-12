static inline struct ml86v7667_priv *to_ml86v7667(struct v4l2_subdev *subdev)
{
return container_of(subdev, struct ml86v7667_priv, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct ml86v7667_priv, hdl)->sd;
}
static int ml86v7667_mask_set(struct i2c_client *client, const u8 reg,
const u8 mask, const u8 data)
{
int val = i2c_smbus_read_byte_data(client, reg);
if (val < 0)
return val;
val = (val & ~mask) | (data & mask);
return i2c_smbus_write_byte_data(client, reg, val);
}
static int ml86v7667_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret = -EINVAL;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ret = ml86v7667_mask_set(client, SSEPL_REG,
SSEPL_LUMINANCE_MASK, ctrl->val);
break;
case V4L2_CID_CONTRAST:
ret = ml86v7667_mask_set(client, CLC_REG,
CLC_CONTRAST_MASK, ctrl->val);
break;
case V4L2_CID_CHROMA_GAIN:
ret = ml86v7667_mask_set(client, ACCRC_REG, ACCRC_CHROMA_MASK,
ctrl->val << ACCRC_CHROMA_SHIFT);
break;
case V4L2_CID_HUE:
ret = ml86v7667_mask_set(client, HUE_REG, ~0, ctrl->val);
break;
case V4L2_CID_RED_BALANCE:
ret = ml86v7667_mask_set(client, ACCC_REG,
ACCC_CHROMA_CR_MASK,
ctrl->val << ACCC_CHROMA_CR_SHIFT);
break;
case V4L2_CID_BLUE_BALANCE:
ret = ml86v7667_mask_set(client, ACCC_REG,
ACCC_CHROMA_CB_MASK,
ctrl->val << ACCC_CHROMA_CB_SHIFT);
break;
case V4L2_CID_SHARPNESS:
ret = ml86v7667_mask_set(client, LUMC_REG,
LUMC_ONOFF_MASK,
ctrl->val << LUMC_ONOFF_SHIFT);
break;
case V4L2_CID_COLOR_KILLER:
ret = ml86v7667_mask_set(client, CHRCA_REG,
CHRCA_MODE_MASK,
ctrl->val << CHRCA_MODE_SHIFT);
break;
}
return ret;
}
static int ml86v7667_querystd(struct v4l2_subdev *sd, v4l2_std_id *std)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int status;
status = i2c_smbus_read_byte_data(client, STATUS_REG);
if (status < 0)
return status;
if (status & STATUS_HLOCK_DETECT)
*std &= status & STATUS_NTSCPAL ? V4L2_STD_625_50 : V4L2_STD_525_60;
else
*std = V4L2_STD_UNKNOWN;
return 0;
}
static int ml86v7667_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int status_reg;
status_reg = i2c_smbus_read_byte_data(client, STATUS_REG);
if (status_reg < 0)
return status_reg;
*status = status_reg & STATUS_HLOCK_DETECT ? 0 : V4L2_IN_ST_NO_SIGNAL;
return 0;
}
static int ml86v7667_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned int index,
u32 *code)
{
if (index > 0)
return -EINVAL;
*code = MEDIA_BUS_FMT_YUYV8_2X8;
return 0;
}
static int ml86v7667_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct ml86v7667_priv *priv = to_ml86v7667(sd);
fmt->code = MEDIA_BUS_FMT_YUYV8_2X8;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
fmt->field = V4L2_FIELD_INTERLACED_TB;
fmt->width = 720;
fmt->height = priv->std & V4L2_STD_525_60 ? 480 : 576;
return 0;
}
static int ml86v7667_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
cfg->flags = V4L2_MBUS_MASTER | V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_BT656;
return 0;
}
static int ml86v7667_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct ml86v7667_priv *priv = to_ml86v7667(sd);
struct i2c_client *client = v4l2_get_subdevdata(&priv->sd);
int ret;
u8 mode;
mode = std & V4L2_STD_525_60 ? MRA_NTSC_BT601 : MRA_PAL_BT601;
ret = ml86v7667_mask_set(client, MRA_REG, MRA_INPUT_MODE_MASK, mode);
if (ret < 0)
return ret;
priv->std = std;
return 0;
}
static int ml86v7667_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
ret = i2c_smbus_read_byte_data(client, (u8)reg->reg);
if (ret < 0)
return ret;
reg->val = ret;
reg->size = sizeof(u8);
return 0;
}
static int ml86v7667_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return i2c_smbus_write_byte_data(client, (u8)reg->reg, (u8)reg->val);
}
static int ml86v7667_init(struct ml86v7667_priv *priv)
{
struct i2c_client *client = v4l2_get_subdevdata(&priv->sd);
int val;
int ret;
ret = ml86v7667_mask_set(client, MRA_REG,
MRA_OUTPUT_MODE_MASK | MRA_REGISTER_MODE,
MRA_ITUR_BT656 | MRA_REGISTER_MODE);
ret |= ml86v7667_mask_set(client, PLLR1_REG, PLLR1_FIXED_CLOCK,
PLLR1_FIXED_CLOCK);
ret |= ml86v7667_mask_set(client, ADC2_REG, ADC2_CLAMP_VOLTAGE_MASK,
ADC2_CLAMP_VOLTAGE(7));
ret |= ml86v7667_mask_set(client, SSEPL_REG, SSEPL_LUMINANCE_ONOFF,
SSEPL_LUMINANCE_ONOFF);
ret |= ml86v7667_mask_set(client, CLC_REG, CLC_CONTRAST_ONOFF, 0);
val = i2c_smbus_read_byte_data(client, STATUS_REG);
if (val < 0)
return val;
priv->std = val & STATUS_NTSCPAL ? V4L2_STD_625_50 : V4L2_STD_525_60;
ret |= ml86v7667_mask_set(client, MRC_REG, MRC_AUTOSELECT, 0);
val = priv->std & V4L2_STD_525_60 ? MRA_NTSC_BT601 : MRA_PAL_BT601;
ret |= ml86v7667_mask_set(client, MRA_REG, MRA_INPUT_MODE_MASK, val);
return ret;
}
static int ml86v7667_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct ml86v7667_priv *priv;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
priv = devm_kzalloc(&client->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
v4l2_i2c_subdev_init(&priv->sd, client, &ml86v7667_subdev_ops);
v4l2_ctrl_handler_init(&priv->hdl, 8);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_BRIGHTNESS, -64, 63, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_CONTRAST, -8, 7, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_CHROMA_GAIN, -32, 31, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_RED_BALANCE, -4, 3, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_BLUE_BALANCE, -4, 3, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 1, 1, 0);
v4l2_ctrl_new_std(&priv->hdl, &ml86v7667_ctrl_ops,
V4L2_CID_COLOR_KILLER, 0, 1, 1, 0);
priv->sd.ctrl_handler = &priv->hdl;
ret = priv->hdl.error;
if (ret)
goto cleanup;
v4l2_ctrl_handler_setup(&priv->hdl);
ret = ml86v7667_init(priv);
if (ret)
goto cleanup;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr, client->adapter->name);
return 0;
cleanup:
v4l2_ctrl_handler_free(&priv->hdl);
v4l2_device_unregister_subdev(&priv->sd);
v4l_err(client, "failed to probe @ 0x%02x (%s)\n",
client->addr, client->adapter->name);
return ret;
}
static int ml86v7667_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ml86v7667_priv *priv = to_ml86v7667(sd);
v4l2_ctrl_handler_free(&priv->hdl);
v4l2_device_unregister_subdev(&priv->sd);
return 0;
}
