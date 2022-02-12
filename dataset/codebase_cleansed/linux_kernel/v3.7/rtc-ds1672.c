static int ds1672_get_datetime(struct i2c_client *client, struct rtc_time *tm)
{
unsigned long time;
unsigned char addr = DS1672_REG_CNT_BASE;
unsigned char buf[4];
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.len = 1,
.buf = &addr
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 4,
.buf = buf
},
};
if ((i2c_transfer(client->adapter, &msgs[0], 2)) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
dev_dbg(&client->dev,
"%s: raw read data - counters=%02x,%02x,%02x,%02x\n",
__func__, buf[0], buf[1], buf[2], buf[3]);
time = (buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
rtc_time_to_tm(time, tm);
dev_dbg(&client->dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__, tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
return 0;
}
static int ds1672_set_mmss(struct i2c_client *client, unsigned long secs)
{
int xfer;
unsigned char buf[6];
buf[0] = DS1672_REG_CNT_BASE;
buf[1] = secs & 0x000000FF;
buf[2] = (secs & 0x0000FF00) >> 8;
buf[3] = (secs & 0x00FF0000) >> 16;
buf[4] = (secs & 0xFF000000) >> 24;
buf[5] = 0;
xfer = i2c_master_send(client, buf, 6);
if (xfer != 6) {
dev_err(&client->dev, "%s: send: %d\n", __func__, xfer);
return -EIO;
}
return 0;
}
static int ds1672_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return ds1672_get_datetime(to_i2c_client(dev), tm);
}
static int ds1672_rtc_set_mmss(struct device *dev, unsigned long secs)
{
return ds1672_set_mmss(to_i2c_client(dev), secs);
}
static int ds1672_get_control(struct i2c_client *client, u8 *status)
{
unsigned char addr = DS1672_REG_CONTROL;
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.len = 1,
.buf = &addr
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 1,
.buf = status
},
};
if ((i2c_transfer(client->adapter, &msgs[0], 2)) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
return 0;
}
static ssize_t show_control(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
u8 control;
int err;
err = ds1672_get_control(client, &control);
if (err)
return err;
return sprintf(buf, "%s\n", (control & DS1672_REG_CONTROL_EOSC)
? "disabled" : "enabled");
}
static int ds1672_remove(struct i2c_client *client)
{
struct rtc_device *rtc = i2c_get_clientdata(client);
if (rtc)
rtc_device_unregister(rtc);
return 0;
}
static int ds1672_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err = 0;
u8 control;
struct rtc_device *rtc;
dev_dbg(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
dev_info(&client->dev, "chip found, driver version " DRV_VERSION "\n");
rtc = rtc_device_register(ds1672_driver.driver.name, &client->dev,
&ds1672_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
err = ds1672_get_control(client, &control);
if (err)
goto exit_devreg;
if (control & DS1672_REG_CONTROL_EOSC)
dev_warn(&client->dev, "Oscillator not enabled. "
"Set time to enable.\n");
err = device_create_file(&client->dev, &dev_attr_control);
if (err)
goto exit_devreg;
return 0;
exit_devreg:
rtc_device_unregister(rtc);
return err;
}
