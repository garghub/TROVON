static int pcf85063_stop_clock(struct i2c_client *client, u8 *ctrl1)
{
s32 ret;
ret = i2c_smbus_read_byte_data(client, PCF85063_REG_CTRL1);
if (ret < 0) {
dev_err(&client->dev, "Failing to stop the clock\n");
return -EIO;
}
ret |= PCF85063_REG_CTRL1_STOP;
ret = i2c_smbus_write_byte_data(client, PCF85063_REG_CTRL1, ret);
if (ret < 0) {
dev_err(&client->dev, "Failing to stop the clock\n");
return -EIO;
}
*ctrl1 = ret;
return 0;
}
static int pcf85063_start_clock(struct i2c_client *client, u8 ctrl1)
{
s32 ret;
ctrl1 &= PCF85063_REG_CTRL1_STOP;
ret = i2c_smbus_write_byte_data(client, PCF85063_REG_CTRL1, ctrl1);
if (ret < 0) {
dev_err(&client->dev, "Failing to start the clock\n");
return -EIO;
}
return 0;
}
static int pcf85063_get_datetime(struct i2c_client *client, struct rtc_time *tm)
{
int rc;
u8 regs[7];
rc = i2c_smbus_read_i2c_block_data(client, PCF85063_REG_SC,
sizeof(regs), regs);
if (rc != sizeof(regs)) {
dev_err(&client->dev, "date/time register read error\n");
return -EIO;
}
if (regs[0] & PCF85063_REG_SC_OS) {
dev_warn(&client->dev, "Power loss detected, invalid time\n");
return -EINVAL;
}
tm->tm_sec = bcd2bin(regs[0] & 0x7F);
tm->tm_min = bcd2bin(regs[1] & 0x7F);
tm->tm_hour = bcd2bin(regs[2] & 0x3F);
tm->tm_mday = bcd2bin(regs[3] & 0x3F);
tm->tm_wday = regs[4] & 0x07;
tm->tm_mon = bcd2bin(regs[5] & 0x1F) - 1;
tm->tm_year = bcd2bin(regs[6]);
tm->tm_year += 100;
return rtc_valid_tm(tm);
}
static int pcf85063_set_datetime(struct i2c_client *client, struct rtc_time *tm)
{
int rc;
u8 regs[7];
u8 ctrl1;
if ((tm->tm_year < 100) || (tm->tm_year > 199))
return -EINVAL;
rc = pcf85063_stop_clock(client, &ctrl1);
if (rc != 0)
return rc;
regs[0] = bin2bcd(tm->tm_sec) & 0x7F;
regs[1] = bin2bcd(tm->tm_min);
regs[2] = bin2bcd(tm->tm_hour);
regs[3] = bin2bcd(tm->tm_mday);
regs[4] = tm->tm_wday & 0x07;
regs[5] = bin2bcd(tm->tm_mon + 1);
regs[6] = bin2bcd(tm->tm_year - 100);
rc = i2c_smbus_write_i2c_block_data(client, PCF85063_REG_SC,
sizeof(regs), regs);
if (rc < 0) {
dev_err(&client->dev, "date/time register write error\n");
return rc;
}
rc = pcf85063_start_clock(client, ctrl1);
if (rc != 0)
return rc;
return 0;
}
static int pcf85063_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return pcf85063_get_datetime(to_i2c_client(dev), tm);
}
static int pcf85063_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return pcf85063_set_datetime(to_i2c_client(dev), tm);
}
static int pcf85063_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rtc_device *rtc;
dev_dbg(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
rtc = devm_rtc_device_register(&client->dev,
pcf85063_driver.driver.name,
&pcf85063_rtc_ops, THIS_MODULE);
return PTR_ERR_OR_ZERO(rtc);
}
