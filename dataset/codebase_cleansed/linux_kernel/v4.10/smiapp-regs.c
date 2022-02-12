static uint32_t float_to_u32_mul_1000000(struct i2c_client *client,
uint32_t phloat)
{
int32_t exp;
uint64_t man;
if (phloat >= 0x80000000) {
dev_err(&client->dev, "this is a negative number\n");
return 0;
}
if (phloat == 0x7f800000)
return ~0;
if ((phloat & 0x7f800000) == 0x7f800000) {
dev_err(&client->dev, "NaN or other special number\n");
return 0;
}
if (phloat == 0)
return 0;
if (phloat > 0x4f800000)
return ~0;
exp = ((int32_t)phloat >> 23) - 127;
man = ((phloat & 0x7fffff) | 0x800000) * 1000000ULL;
if (exp < 0)
man >>= -exp;
else
man <<= exp;
man >>= 23;
return man & 0xffffffff;
}
static int ____smiapp_read(struct smiapp_sensor *sensor, u16 reg,
u16 len, u32 *val)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
struct i2c_msg msg;
unsigned char data[4];
u16 offset = reg;
int r;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2;
msg.buf = data;
data[0] = (u8) (offset >> 8);
data[1] = (u8) offset;
r = i2c_transfer(client->adapter, &msg, 1);
if (r != 1) {
if (r >= 0)
r = -EBUSY;
goto err;
}
msg.len = len;
msg.flags = I2C_M_RD;
r = i2c_transfer(client->adapter, &msg, 1);
if (r != 1) {
if (r >= 0)
r = -EBUSY;
goto err;
}
*val = 0;
switch (len) {
case SMIAPP_REG_32BIT:
*val = (data[0] << 24) + (data[1] << 16) + (data[2] << 8) +
data[3];
break;
case SMIAPP_REG_16BIT:
*val = (data[0] << 8) + data[1];
break;
case SMIAPP_REG_8BIT:
*val = data[0];
break;
default:
BUG();
}
return 0;
err:
dev_err(&client->dev, "read from offset 0x%x error %d\n", offset, r);
return r;
}
static int ____smiapp_read_8only(struct smiapp_sensor *sensor, u16 reg,
u16 len, u32 *val)
{
unsigned int i;
int rval;
*val = 0;
for (i = 0; i < len; i++) {
u32 val8;
rval = ____smiapp_read(sensor, reg + i, 1, &val8);
if (rval < 0)
return rval;
*val |= val8 << ((len - i - 1) << 3);
}
return 0;
}
static int __smiapp_read(struct smiapp_sensor *sensor, u32 reg, u32 *val,
bool only8)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
u8 len = SMIAPP_REG_WIDTH(reg);
int rval;
if (len != SMIAPP_REG_8BIT && len != SMIAPP_REG_16BIT
&& len != SMIAPP_REG_32BIT)
return -EINVAL;
if (len == SMIAPP_REG_8BIT || !only8)
rval = ____smiapp_read(sensor, SMIAPP_REG_ADDR(reg), len, val);
else
rval = ____smiapp_read_8only(sensor, SMIAPP_REG_ADDR(reg), len,
val);
if (rval < 0)
return rval;
if (reg & SMIAPP_REG_FLAG_FLOAT)
*val = float_to_u32_mul_1000000(client, *val);
return 0;
}
int smiapp_read_no_quirk(struct smiapp_sensor *sensor, u32 reg, u32 *val)
{
return __smiapp_read(
sensor, reg, val,
smiapp_needs_quirk(sensor,
SMIAPP_QUIRK_FLAG_8BIT_READ_ONLY));
}
static int smiapp_read_quirk(struct smiapp_sensor *sensor, u32 reg, u32 *val,
bool force8)
{
int rval;
*val = 0;
rval = smiapp_call_quirk(sensor, reg_access, false, &reg, val);
if (rval == -ENOIOCTLCMD)
return 0;
if (rval < 0)
return rval;
if (force8)
return __smiapp_read(sensor, reg, val, true);
return smiapp_read_no_quirk(sensor, reg, val);
}
int smiapp_read(struct smiapp_sensor *sensor, u32 reg, u32 *val)
{
return smiapp_read_quirk(sensor, reg, val, false);
}
int smiapp_read_8only(struct smiapp_sensor *sensor, u32 reg, u32 *val)
{
return smiapp_read_quirk(sensor, reg, val, true);
}
int smiapp_write_no_quirk(struct smiapp_sensor *sensor, u32 reg, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(&sensor->src->sd);
struct i2c_msg msg;
unsigned char data[6];
unsigned int retries;
u8 flags = SMIAPP_REG_FLAGS(reg);
u8 len = SMIAPP_REG_WIDTH(reg);
u16 offset = SMIAPP_REG_ADDR(reg);
int r;
if ((len != SMIAPP_REG_8BIT && len != SMIAPP_REG_16BIT &&
len != SMIAPP_REG_32BIT) || flags)
return -EINVAL;
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2 + len;
msg.buf = data;
data[0] = (u8) (reg >> 8);
data[1] = (u8) (reg & 0xff);
switch (len) {
case SMIAPP_REG_8BIT:
data[2] = val;
break;
case SMIAPP_REG_16BIT:
data[2] = val >> 8;
data[3] = val;
break;
case SMIAPP_REG_32BIT:
data[2] = val >> 24;
data[3] = val >> 16;
data[4] = val >> 8;
data[5] = val;
break;
default:
BUG();
}
for (retries = 0; retries < 5; retries++) {
r = i2c_transfer(client->adapter, &msg, 1);
if (r == 1) {
if (retries)
dev_err(&client->dev,
"sensor i2c stall encountered. retries: %d\n",
retries);
return 0;
}
usleep_range(2000, 2000);
}
dev_err(&client->dev,
"wrote 0x%x to offset 0x%x error %d\n", val, offset, r);
return r;
}
int smiapp_write(struct smiapp_sensor *sensor, u32 reg, u32 val)
{
int rval;
rval = smiapp_call_quirk(sensor, reg_access, true, &reg, &val);
if (rval == -ENOIOCTLCMD)
return 0;
if (rval < 0)
return rval;
return smiapp_write_no_quirk(sensor, reg, val);
}
