static void i2c_av_write(struct i2c_adapter *i2c, u16 reg, u8 val)
{
int ret;
u8 buf[3];
struct i2c_msg msg = {
.addr = 0x88 >> 1,
.flags = 0,
.buf = buf,
.len = 3
};
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
buf[2] = val;
ret = i2c_transfer(i2c, &msg, 1);
if (ret != 1)
pr_err("%s: i2c write error!\n", __func__);
}
static void i2c_av_write4(struct i2c_adapter *i2c, u16 reg, u32 val)
{
int ret;
u8 buf[6];
struct i2c_msg msg = {
.addr = 0x88 >> 1,
.flags = 0,
.buf = buf,
.len = 6
};
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
buf[2] = val & 0xff;
buf[3] = (val >> 8) & 0xff;
buf[4] = (val >> 16) & 0xff;
buf[5] = val >> 24;
ret = i2c_transfer(i2c, &msg, 1);
if (ret != 1)
pr_err("%s: i2c write error!\n", __func__);
}
static u8 i2c_av_read(struct i2c_adapter *i2c, u16 reg)
{
int ret;
u8 buf[2];
struct i2c_msg msg = {
.addr = 0x88 >> 1,
.flags = 0,
.buf = buf,
.len = 2
};
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
ret = i2c_transfer(i2c, &msg, 1);
if (ret != 1)
pr_err("%s: i2c write error!\n", __func__);
msg.flags = I2C_M_RD;
msg.len = 1;
ret = i2c_transfer(i2c, &msg, 1);
if (ret != 1)
pr_err("%s: i2c read error!\n", __func__);
return buf[0];
}
static void i2c_av_and_or(struct i2c_adapter *i2c, u16 reg, unsigned and_mask,
u8 or_value)
{
i2c_av_write(i2c, reg, (i2c_av_read(i2c, reg) & and_mask) | or_value);
}
void netup_initialize(struct cx23885_dev *dev)
{
struct cx23885_i2c *i2c_bus = &dev->i2c_bus[2];
struct i2c_adapter *i2c = &i2c_bus->i2c_adap;
i2c_av_and_or(i2c, 0x803, ~0x10, 0x00);
i2c_av_write4(i2c, 0x114, 0xea0eb3);
i2c_av_write4(i2c, 0x110, 0x090319);
i2c_av_and_or(i2c, 0x803, ~0x10, 0x10);
}
