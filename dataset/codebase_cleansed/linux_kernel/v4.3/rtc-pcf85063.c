static int pcf85063_get_datetime(struct i2c_client *client, struct rtc_time *tm)
{
struct pcf85063 *pcf85063 = i2c_get_clientdata(client);
unsigned char buf[13] = { PCF85063_REG_CTRL1 };
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.len = 1,
.buf = buf
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 13,
.buf = buf
},
};
if ((i2c_transfer(client->adapter, msgs, 2)) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
tm->tm_sec = bcd2bin(buf[PCF85063_REG_SC] & 0x7F);
tm->tm_min = bcd2bin(buf[PCF85063_REG_MN] & 0x7F);
tm->tm_hour = bcd2bin(buf[PCF85063_REG_HR] & 0x3F);
tm->tm_mday = bcd2bin(buf[PCF85063_REG_DM] & 0x3F);
tm->tm_wday = buf[PCF85063_REG_DW] & 0x07;
tm->tm_mon = bcd2bin(buf[PCF85063_REG_MO] & 0x1F) - 1;
tm->tm_year = bcd2bin(buf[PCF85063_REG_YR]);
if (tm->tm_year < 70)
tm->tm_year += 100;
pcf85063->c_polarity = (buf[PCF85063_REG_MO] & PCF85063_MO_C) ?
(tm->tm_year >= 100) : (tm->tm_year < 100);
if (rtc_valid_tm(tm) < 0)
dev_err(&client->dev, "retrieved date/time is not valid.\n");
return 0;
}
static int pcf85063_set_datetime(struct i2c_client *client, struct rtc_time *tm)
{
int i = 0, err = 0;
unsigned char buf[11];
buf[PCF85063_REG_CTRL1] = 0;
buf[PCF85063_REG_CTRL2] = 5;
buf[PCF85063_REG_SC] = bin2bcd(tm->tm_sec) & 0x7F;
buf[PCF85063_REG_MN] = bin2bcd(tm->tm_min);
buf[PCF85063_REG_HR] = bin2bcd(tm->tm_hour);
buf[PCF85063_REG_DM] = bin2bcd(tm->tm_mday);
buf[PCF85063_REG_DW] = tm->tm_wday & 0x07;
buf[PCF85063_REG_MO] = bin2bcd(tm->tm_mon + 1);
buf[PCF85063_REG_YR] = bin2bcd(tm->tm_year % 100);
for (i = 0; i < sizeof(buf); i++) {
unsigned char data[2] = { i, buf[i] };
err = i2c_master_send(client, data, sizeof(data));
if (err != sizeof(data)) {
dev_err(&client->dev, "%s: err=%d addr=%02x, data=%02x\n",
__func__, err, data[0], data[1]);
return -EIO;
}
}
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
struct pcf85063 *pcf85063;
dev_dbg(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
pcf85063 = devm_kzalloc(&client->dev, sizeof(struct pcf85063),
GFP_KERNEL);
if (!pcf85063)
return -ENOMEM;
dev_info(&client->dev, "chip found, driver version " DRV_VERSION "\n");
i2c_set_clientdata(client, pcf85063);
pcf85063->rtc = devm_rtc_device_register(&client->dev,
pcf85063_driver.driver.name,
&pcf85063_rtc_ops, THIS_MODULE);
return PTR_ERR_OR_ZERO(pcf85063->rtc);
}
