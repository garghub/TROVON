static int max6900_i2c_read_regs(struct i2c_client *client, u8 *buf)
{
u8 reg_burst_read[1] = { MAX6900_REG_BURST_READ };
u8 reg_century_read[1] = { MAX6900_REG_CENTURY_READ };
struct i2c_msg msgs[4] = {
{
.addr = client->addr,
.flags = 0,
.len = sizeof(reg_burst_read),
.buf = reg_burst_read}
,
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = MAX6900_BURST_LEN,
.buf = buf}
,
{
.addr = client->addr,
.flags = 0,
.len = sizeof(reg_century_read),
.buf = reg_century_read}
,
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = sizeof(buf[MAX6900_REG_CENTURY]),
.buf = &buf[MAX6900_REG_CENTURY]
}
};
int rc;
rc = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (rc != ARRAY_SIZE(msgs)) {
dev_err(&client->dev, "%s: register read failed\n", __func__);
return -EIO;
}
return 0;
}
static int max6900_i2c_write_regs(struct i2c_client *client, u8 const *buf)
{
u8 i2c_century_buf[1 + 1] = { MAX6900_REG_CENTURY_WRITE };
struct i2c_msg century_msgs[1] = {
{
.addr = client->addr,
.flags = 0,
.len = sizeof(i2c_century_buf),
.buf = i2c_century_buf}
};
u8 i2c_burst_buf[MAX6900_BURST_LEN + 1] = { MAX6900_REG_BURST_WRITE };
struct i2c_msg burst_msgs[1] = {
{
.addr = client->addr,
.flags = 0,
.len = sizeof(i2c_burst_buf),
.buf = i2c_burst_buf}
};
int rc;
i2c_century_buf[1] = buf[MAX6900_REG_CENTURY];
rc = i2c_transfer(client->adapter, century_msgs,
ARRAY_SIZE(century_msgs));
if (rc != ARRAY_SIZE(century_msgs))
goto write_failed;
msleep(MAX6900_IDLE_TIME_AFTER_WRITE);
memcpy(&i2c_burst_buf[1], buf, MAX6900_BURST_LEN);
rc = i2c_transfer(client->adapter, burst_msgs, ARRAY_SIZE(burst_msgs));
if (rc != ARRAY_SIZE(burst_msgs))
goto write_failed;
msleep(MAX6900_IDLE_TIME_AFTER_WRITE);
return 0;
write_failed:
dev_err(&client->dev, "%s: register write failed\n", __func__);
return -EIO;
}
static int max6900_i2c_read_time(struct i2c_client *client, struct rtc_time *tm)
{
int rc;
u8 regs[MAX6900_REG_LEN];
rc = max6900_i2c_read_regs(client, regs);
if (rc < 0)
return rc;
tm->tm_sec = bcd2bin(regs[MAX6900_REG_SC]);
tm->tm_min = bcd2bin(regs[MAX6900_REG_MN]);
tm->tm_hour = bcd2bin(regs[MAX6900_REG_HR] & 0x3f);
tm->tm_mday = bcd2bin(regs[MAX6900_REG_DT]);
tm->tm_mon = bcd2bin(regs[MAX6900_REG_MO]) - 1;
tm->tm_year = bcd2bin(regs[MAX6900_REG_YR]) +
bcd2bin(regs[MAX6900_REG_CENTURY]) * 100 - 1900;
tm->tm_wday = bcd2bin(regs[MAX6900_REG_DW]);
return rtc_valid_tm(tm);
}
static int max6900_i2c_clear_write_protect(struct i2c_client *client)
{
int rc;
rc = i2c_smbus_write_byte_data(client, MAX6900_REG_CONTROL_WRITE, 0);
if (rc < 0) {
dev_err(&client->dev, "%s: control register write failed\n",
__func__);
return -EIO;
}
return 0;
}
static int
max6900_i2c_set_time(struct i2c_client *client, struct rtc_time const *tm)
{
u8 regs[MAX6900_REG_LEN];
int rc;
rc = max6900_i2c_clear_write_protect(client);
if (rc < 0)
return rc;
regs[MAX6900_REG_SC] = bin2bcd(tm->tm_sec);
regs[MAX6900_REG_MN] = bin2bcd(tm->tm_min);
regs[MAX6900_REG_HR] = bin2bcd(tm->tm_hour);
regs[MAX6900_REG_DT] = bin2bcd(tm->tm_mday);
regs[MAX6900_REG_MO] = bin2bcd(tm->tm_mon + 1);
regs[MAX6900_REG_DW] = bin2bcd(tm->tm_wday);
regs[MAX6900_REG_YR] = bin2bcd(tm->tm_year % 100);
regs[MAX6900_REG_CENTURY] = bin2bcd((tm->tm_year + 1900) / 100);
regs[MAX6900_REG_CT] = MAX6900_REG_CT_WP;
rc = max6900_i2c_write_regs(client, regs);
if (rc < 0)
return rc;
return 0;
}
static int max6900_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return max6900_i2c_read_time(to_i2c_client(dev), tm);
}
static int max6900_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return max6900_i2c_set_time(to_i2c_client(dev), tm);
}
static int
max6900_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct rtc_device *rtc;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
dev_info(&client->dev, "chip found, driver version " DRV_VERSION "\n");
rtc = devm_rtc_device_register(&client->dev, max6900_driver.driver.name,
&max6900_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
return 0;
}
