static int smiapp_write_8(struct smiapp_sensor *sensor, u16 reg, u8 val)
{
return smiapp_write(sensor, SMIAPP_REG_MK_U8(reg), val);
}
static int smiapp_write_8s(struct smiapp_sensor *sensor,
const struct smiapp_reg_8 *regs, int len)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
int rval;
for (; len > 0; len--, regs++) {
rval = smiapp_write_8(sensor, regs->reg, regs->val);
if (rval < 0) {
dev_err(&client->dev,
"error %d writing reg 0x%4.4x, val 0x%2.2x",
rval, regs->reg, regs->val);
return rval;
}
}
return 0;
}
void smiapp_replace_limit(struct smiapp_sensor *sensor,
u32 limit, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
dev_dbg(&client->dev, "quirk: 0x%8.8x \"%s\" = %d, 0x%x\n",
smiapp_reg_limits[limit].addr,
smiapp_reg_limits[limit].what, val, val);
sensor->limits[limit] = val;
}
static int jt8ew9_limits(struct smiapp_sensor *sensor)
{
if (sensor->minfo.revision_number_major < 0x03)
sensor->frame_skip = 1;
smiapp_replace_limit(sensor, SMIAPP_LIMIT_ANALOGUE_GAIN_CODE_MIN, 59);
smiapp_replace_limit(
sensor, SMIAPP_LIMIT_ANALOGUE_GAIN_CODE_MAX, 6000);
return 0;
}
static int jt8ew9_post_poweron(struct smiapp_sensor *sensor)
{
static const struct smiapp_reg_8 regs[] = {
{ 0x30a3, 0xd8 },
{ 0x30ae, 0x00 },
{ 0x30af, 0xd0 },
{ 0x322d, 0x04 },
{ 0x3255, 0x0f },
{ 0x3256, 0x15 },
{ 0x3258, 0x70 },
{ 0x3259, 0x70 },
{ 0x325f, 0x7c },
{ 0x3302, 0x06 },
{ 0x3304, 0x00 },
{ 0x3307, 0x22 },
{ 0x3308, 0x8d },
{ 0x331e, 0x0f },
{ 0x3320, 0x30 },
{ 0x3321, 0x11 },
{ 0x3322, 0x98 },
{ 0x3323, 0x64 },
{ 0x3325, 0x83 },
{ 0x3330, 0x18 },
{ 0x333c, 0x01 },
{ 0x3345, 0x2f },
{ 0x33de, 0x38 },
{ 0x32e0, 0x05 },
{ 0x32e1, 0x05 },
{ 0x32e2, 0x04 },
{ 0x32e5, 0x04 },
{ 0x32e6, 0x04 },
};
return smiapp_write_8s(sensor, regs, ARRAY_SIZE(regs));
}
static int imx125es_post_poweron(struct smiapp_sensor *sensor)
{
static const struct smiapp_reg_8 regs[] = {
{ 0x3302, 0x01 },
{ 0x302d, 0x00 },
{ 0x3b08, 0x8c },
};
return smiapp_write_8s(sensor, regs, ARRAY_SIZE(regs));
}
static int jt8ev1_limits(struct smiapp_sensor *sensor)
{
smiapp_replace_limit(sensor, SMIAPP_LIMIT_X_ADDR_MAX, 4271);
smiapp_replace_limit(sensor,
SMIAPP_LIMIT_MIN_LINE_BLANKING_PCK_BIN, 184);
return 0;
}
static int jt8ev1_post_poweron(struct smiapp_sensor *sensor)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
int rval;
static const struct smiapp_reg_8 regs[] = {
{ 0x3031, 0xcd },
{ 0x30a3, 0xd0 },
{ 0x3237, 0x00 },
{ 0x3238, 0x43 },
{ 0x3301, 0x06 },
{ 0x3302, 0x06 },
{ 0x3304, 0x00 },
{ 0x3305, 0x88 },
{ 0x332a, 0x14 },
{ 0x332c, 0x6b },
{ 0x3336, 0x01 },
{ 0x333f, 0x1f },
{ 0x3355, 0x00 },
{ 0x3356, 0x20 },
{ 0x33bf, 0x20 },
{ 0x33c9, 0x20 },
{ 0x33ce, 0x30 },
{ 0x33cf, 0xec },
{ 0x3328, 0x80 },
};
static const struct smiapp_reg_8 regs_96[] = {
{ 0x30ae, 0x00 },
{ 0x30af, 0xd0 },
{ 0x30b0, 0x01 },
};
rval = smiapp_write_8s(sensor, regs, ARRAY_SIZE(regs));
if (rval < 0)
return rval;
switch (sensor->hwcfg->ext_clk) {
case 9600000:
return smiapp_write_8s(sensor, regs_96,
ARRAY_SIZE(regs_96));
default:
dev_warn(&client->dev, "no MSRs for %d Hz ext_clk\n",
sensor->hwcfg->ext_clk);
return 0;
}
}
static int jt8ev1_pre_streamon(struct smiapp_sensor *sensor)
{
return smiapp_write_8(sensor, 0x3328, 0x00);
}
static int jt8ev1_post_streamoff(struct smiapp_sensor *sensor)
{
int rval;
rval = smiapp_write_8(sensor, 0x3205, 0x04);
if (rval < 0)
return rval;
usleep_range(2000, 2000);
rval = smiapp_write_8(sensor, 0x3205, 0x00);
if (rval < 0)
return rval;
return smiapp_write_8(sensor, 0x3328, 0x80);
}
static int jt8ev1_init(struct smiapp_sensor *sensor)
{
sensor->pll.flags |= SMIAPP_PLL_FLAG_OP_PIX_CLOCK_PER_LANE;
return 0;
}
static int tcm8500md_limits(struct smiapp_sensor *sensor)
{
smiapp_replace_limit(sensor, SMIAPP_LIMIT_MIN_PLL_IP_FREQ_HZ, 2700000);
return 0;
}
