static inline struct saa7706h_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa7706h_state, sd);
}
static int saa7706h_i2c_send(struct i2c_client *client, const u8 *data, int len)
{
int err = i2c_master_send(client, data, len);
if (err == len)
return 0;
return err > 0 ? -EIO : err;
}
static int saa7706h_i2c_transfer(struct i2c_client *client,
struct i2c_msg *msgs, int num)
{
int err = i2c_transfer(client->adapter, msgs, num);
if (err == num)
return 0;
return err > 0 ? -EIO : err;
}
static int saa7706h_set_reg24(struct v4l2_subdev *sd, u16 reg, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[5];
int pos = 0;
buf[pos++] = reg >> 8;
buf[pos++] = reg;
buf[pos++] = val >> 16;
buf[pos++] = val >> 8;
buf[pos++] = val;
return saa7706h_i2c_send(client, buf, pos);
}
static int saa7706h_set_reg24_err(struct v4l2_subdev *sd, u16 reg, u32 val,
int *err)
{
return *err ? *err : saa7706h_set_reg24(sd, reg, val);
}
static int saa7706h_set_reg16(struct v4l2_subdev *sd, u16 reg, u16 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[4];
int pos = 0;
buf[pos++] = reg >> 8;
buf[pos++] = reg;
buf[pos++] = val >> 8;
buf[pos++] = val;
return saa7706h_i2c_send(client, buf, pos);
}
static int saa7706h_set_reg16_err(struct v4l2_subdev *sd, u16 reg, u16 val,
int *err)
{
return *err ? *err : saa7706h_set_reg16(sd, reg, val);
}
static int saa7706h_get_reg16(struct v4l2_subdev *sd, u16 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[2];
int err;
u8 regaddr[] = {reg >> 8, reg};
struct i2c_msg msg[] = {
{
.addr = client->addr,
.len = sizeof(regaddr),
.buf = regaddr
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = sizeof(buf),
.buf = buf
}
};
err = saa7706h_i2c_transfer(client, msg, ARRAY_SIZE(msg));
if (err)
return err;
return buf[0] << 8 | buf[1];
}
static int saa7706h_unmute(struct v4l2_subdev *sd)
{
struct saa7706h_state *state = to_state(sd);
int err = 0;
err = saa7706h_set_reg16_err(sd, SAA7706H_REG_CTRL,
SAA7706H_CTRL_PLL3_62975MHZ | SAA7706H_CTRL_PC_RESET_DSP1 |
SAA7706H_CTRL_PC_RESET_DSP2, &err);
msleep(1);
err = saa7706h_set_reg16_err(sd, SAA7706H_REG_CTRL,
SAA7706H_CTRL_PLL3_62975MHZ, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_EVALUATION, 0, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_CL_GEN1, 0x040022, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_CL_GEN2,
SAA7706H_CL_GEN2_WSEDGE_FALLING, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_CL_GEN4, 0x024080, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_SEL, 0x200080, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_IAC, 0xf4caed, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_CLK_SET, 0x124334, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_CLK_COEFF, 0x004a1a,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_INPUT_SENS, 0x0071c7,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_PHONE_NAV_AUDIO,
0x0e22ff, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_IO_CONF_DSP2, 0x001ff8,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_STATUS_DSP2, 0x080003,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_REG_PC_DSP2, 0x000004, &err);
err = saa7706h_set_reg16_err(sd, SAA7706H_DSP1_MOD0, 0x0c6c, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_MPTR0, 0x000b4b, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP1_MODPNTR, 0x000600, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP1_MODPNTR, 0x0000c0, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_XMEM_CONTLLCW, 0x000819,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_XMEM_CONTLLCW, 0x00085a,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_XMEM_BUSAMP, 0x7fffff,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_XMEM_FDACPNTR, 0x2000cb,
&err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_XMEM_IIS1PNTR, 0x2000cb,
&err);
err = saa7706h_set_reg16_err(sd, SAA7706H_DSP2_YMEM_PVGA, 0x0f80, &err);
err = saa7706h_set_reg16_err(sd, SAA7706H_DSP2_YMEM_PVAT1, 0x0800,
&err);
err = saa7706h_set_reg16_err(sd, SAA7706H_DSP2_YMEM_PVAT, 0x0800, &err);
err = saa7706h_set_reg24_err(sd, SAA7706H_DSP2_XMEM_CONTLLCW, 0x000905,
&err);
if (!err)
state->muted = 0;
return err;
}
static int saa7706h_mute(struct v4l2_subdev *sd)
{
struct saa7706h_state *state = to_state(sd);
int err;
err = saa7706h_set_reg16(sd, SAA7706H_REG_CTRL,
SAA7706H_CTRL_PLL3_62975MHZ | SAA7706H_CTRL_PC_RESET_DSP1 |
SAA7706H_CTRL_PC_RESET_DSP2);
if (!err)
state->muted = 1;
return err;
}
static int saa7706h_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
}
return -EINVAL;
}
static int saa7706h_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct saa7706h_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = state->muted;
return 0;
}
return -EINVAL;
}
static int saa7706h_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (ctrl->value)
return saa7706h_mute(sd);
return saa7706h_unmute(sd);
}
return -EINVAL;
}
static int saa7706h_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_SAA7706H, 0);
}
static int __devinit saa7706h_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct saa7706h_state *state;
struct v4l2_subdev *sd;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct saa7706h_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &saa7706h_ops);
err = saa7706h_get_reg16(sd, SAA7706H_DSP1_ROM_VER);
if (err < 0)
goto err;
if (err != SUPPORTED_DSP1_ROM_VER)
v4l2_warn(sd, "Unknown DSP1 ROM code version: 0x%x\n", err);
state->muted = 1;
err = saa7706h_mute(sd);
if (err)
goto err;
return 0;
err:
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
printk(KERN_ERR DRIVER_NAME ": Failed to probe: %d\n", err);
return err;
}
static int __devexit saa7706h_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
saa7706h_mute(sd);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
