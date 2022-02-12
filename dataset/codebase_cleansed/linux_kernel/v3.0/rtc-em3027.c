static int em3027_get_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char addr = EM3027_REG_WATCH_SEC;
unsigned char buf[7];
struct i2c_msg msgs[] = {
{client->addr, 0, 1, &addr},
{client->addr, I2C_M_RD, 7, buf},
};
if ((i2c_transfer(client->adapter, &msgs[0], 2)) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
tm->tm_sec = bcd2bin(buf[0]);
tm->tm_min = bcd2bin(buf[1]);
tm->tm_hour = bcd2bin(buf[2]);
tm->tm_mday = bcd2bin(buf[3]);
tm->tm_wday = bcd2bin(buf[4]);
tm->tm_mon = bcd2bin(buf[5]);
tm->tm_year = bcd2bin(buf[6]) + 100;
return 0;
}
static int em3027_set_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[8];
struct i2c_msg msg = {
client->addr, 0, 8, buf,
};
buf[0] = EM3027_REG_WATCH_SEC;
buf[1] = bin2bcd(tm->tm_sec);
buf[2] = bin2bcd(tm->tm_min);
buf[3] = bin2bcd(tm->tm_hour);
buf[4] = bin2bcd(tm->tm_mday);
buf[5] = bin2bcd(tm->tm_wday);
buf[6] = bin2bcd(tm->tm_mon);
buf[7] = bin2bcd(tm->tm_year % 100);
if ((i2c_transfer(client->adapter, &msg, 1)) != 1) {
dev_err(&client->dev, "%s: write error\n", __func__);
return -EIO;
}
return 0;
}
static int em3027_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rtc_device *rtc;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
rtc = rtc_device_register(em3027_driver.driver.name, &client->dev,
&em3027_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
return 0;
}
static int em3027_remove(struct i2c_client *client)
{
struct rtc_device *rtc = i2c_get_clientdata(client);
if (rtc)
rtc_device_unregister(rtc);
return 0;
}
static int __init em3027_init(void)
{
return i2c_add_driver(&em3027_driver);
}
static void __exit em3027_exit(void)
{
i2c_del_driver(&em3027_driver);
}
