static void fm3130_rtc_mode(struct device *dev, int mode)
{
struct fm3130 *fm3130 = dev_get_drvdata(dev);
fm3130->regs[FM3130_RTC_CONTROL] =
i2c_smbus_read_byte_data(fm3130->client, FM3130_RTC_CONTROL);
switch (mode) {
case FM3130_MODE_NORMAL:
fm3130->regs[FM3130_RTC_CONTROL] &=
~(FM3130_RTC_CONTROL_BIT_WRITE |
FM3130_RTC_CONTROL_BIT_READ);
break;
case FM3130_MODE_WRITE:
fm3130->regs[FM3130_RTC_CONTROL] |= FM3130_RTC_CONTROL_BIT_WRITE;
break;
case FM3130_MODE_READ:
fm3130->regs[FM3130_RTC_CONTROL] |= FM3130_RTC_CONTROL_BIT_READ;
break;
default:
dev_dbg(dev, "invalid mode %d\n", mode);
break;
}
i2c_smbus_write_byte_data(fm3130->client,
FM3130_RTC_CONTROL, fm3130->regs[FM3130_RTC_CONTROL]);
}
static int fm3130_get_time(struct device *dev, struct rtc_time *t)
{
struct fm3130 *fm3130 = dev_get_drvdata(dev);
int tmp;
if (!fm3130->data_valid) {
return -EIO;
}
fm3130_rtc_mode(dev, FM3130_MODE_READ);
tmp = i2c_transfer(to_i2c_adapter(fm3130->client->dev.parent),
fm3130->msg, 2);
if (tmp != 2) {
dev_err(dev, "%s error %d\n", "read", tmp);
return -EIO;
}
fm3130_rtc_mode(dev, FM3130_MODE_NORMAL);
dev_dbg(dev, "%s: %02x %02x %02x %02x %02x %02x %02x %02x"
"%02x %02x %02x %02x %02x %02x %02x\n",
"read",
fm3130->regs[0], fm3130->regs[1],
fm3130->regs[2], fm3130->regs[3],
fm3130->regs[4], fm3130->regs[5],
fm3130->regs[6], fm3130->regs[7],
fm3130->regs[8], fm3130->regs[9],
fm3130->regs[0xa], fm3130->regs[0xb],
fm3130->regs[0xc], fm3130->regs[0xd],
fm3130->regs[0xe]);
t->tm_sec = bcd2bin(fm3130->regs[FM3130_RTC_SECONDS] & 0x7f);
t->tm_min = bcd2bin(fm3130->regs[FM3130_RTC_MINUTES] & 0x7f);
tmp = fm3130->regs[FM3130_RTC_HOURS] & 0x3f;
t->tm_hour = bcd2bin(tmp);
t->tm_wday = bcd2bin(fm3130->regs[FM3130_RTC_DAY] & 0x07) - 1;
t->tm_mday = bcd2bin(fm3130->regs[FM3130_RTC_DATE] & 0x3f);
tmp = fm3130->regs[FM3130_RTC_MONTHS] & 0x1f;
t->tm_mon = bcd2bin(tmp) - 1;
t->tm_year = bcd2bin(fm3130->regs[FM3130_RTC_YEARS]) + 100;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"read", t->tm_sec, t->tm_min,
t->tm_hour, t->tm_mday,
t->tm_mon, t->tm_year, t->tm_wday);
return rtc_valid_tm(t);
}
static int fm3130_set_time(struct device *dev, struct rtc_time *t)
{
struct fm3130 *fm3130 = dev_get_drvdata(dev);
int tmp, i;
u8 *buf = fm3130->regs;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"write", t->tm_sec, t->tm_min,
t->tm_hour, t->tm_mday,
t->tm_mon, t->tm_year, t->tm_wday);
buf[FM3130_RTC_SECONDS] = bin2bcd(t->tm_sec);
buf[FM3130_RTC_MINUTES] = bin2bcd(t->tm_min);
buf[FM3130_RTC_HOURS] = bin2bcd(t->tm_hour);
buf[FM3130_RTC_DAY] = bin2bcd(t->tm_wday + 1);
buf[FM3130_RTC_DATE] = bin2bcd(t->tm_mday);
buf[FM3130_RTC_MONTHS] = bin2bcd(t->tm_mon + 1);
tmp = t->tm_year - 100;
buf[FM3130_RTC_YEARS] = bin2bcd(tmp);
dev_dbg(dev, "%s: %02x %02x %02x %02x %02x %02x %02x"
"%02x %02x %02x %02x %02x %02x %02x %02x\n",
"write", buf[0], buf[1], buf[2], buf[3],
buf[4], buf[5], buf[6], buf[7],
buf[8], buf[9], buf[0xa], buf[0xb],
buf[0xc], buf[0xd], buf[0xe]);
fm3130_rtc_mode(dev, FM3130_MODE_WRITE);
for (i = 0; i < FM3130_CLOCK_REGS; i++) {
i2c_smbus_write_byte_data(fm3130->client,
FM3130_RTC_SECONDS + i,
fm3130->regs[FM3130_RTC_SECONDS + i]);
}
fm3130_rtc_mode(dev, FM3130_MODE_NORMAL);
if (!fm3130->data_valid)
fm3130->data_valid = 1;
return 0;
}
static int fm3130_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct fm3130 *fm3130 = dev_get_drvdata(dev);
int tmp;
struct rtc_time *tm = &alrm->time;
if (!fm3130->alarm_valid) {
return -EIO;
}
tmp = i2c_transfer(to_i2c_adapter(fm3130->client->dev.parent),
&fm3130->msg[2], 2);
if (tmp != 2) {
dev_err(dev, "%s error %d\n", "read", tmp);
return -EIO;
}
dev_dbg(dev, "alarm read %02x %02x %02x %02x %02x\n",
fm3130->regs[FM3130_ALARM_SECONDS],
fm3130->regs[FM3130_ALARM_MINUTES],
fm3130->regs[FM3130_ALARM_HOURS],
fm3130->regs[FM3130_ALARM_DATE],
fm3130->regs[FM3130_ALARM_MONTHS]);
tm->tm_sec = bcd2bin(fm3130->regs[FM3130_ALARM_SECONDS] & 0x7F);
tm->tm_min = bcd2bin(fm3130->regs[FM3130_ALARM_MINUTES] & 0x7F);
tm->tm_hour = bcd2bin(fm3130->regs[FM3130_ALARM_HOURS] & 0x3F);
tm->tm_mday = bcd2bin(fm3130->regs[FM3130_ALARM_DATE] & 0x3F);
tm->tm_mon = bcd2bin(fm3130->regs[FM3130_ALARM_MONTHS] & 0x1F);
if (tm->tm_mon > 0)
tm->tm_mon -= 1;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"read alarm", tm->tm_sec, tm->tm_min,
tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
fm3130->regs[FM3130_RTC_CONTROL] =
i2c_smbus_read_byte_data(fm3130->client, FM3130_RTC_CONTROL);
if ((fm3130->regs[FM3130_RTC_CONTROL] & FM3130_RTC_CONTROL_BIT_AEN) &&
(~fm3130->regs[FM3130_RTC_CONTROL] &
FM3130_RTC_CONTROL_BIT_CAL)) {
alrm->enabled = 1;
}
return 0;
}
static int fm3130_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct fm3130 *fm3130 = dev_get_drvdata(dev);
struct rtc_time *tm = &alrm->time;
int i;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"write alarm", tm->tm_sec, tm->tm_min,
tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
fm3130->regs[FM3130_ALARM_SECONDS] =
(tm->tm_sec != -1) ? bin2bcd(tm->tm_sec) : 0x80;
fm3130->regs[FM3130_ALARM_MINUTES] =
(tm->tm_min != -1) ? bin2bcd(tm->tm_min) : 0x80;
fm3130->regs[FM3130_ALARM_HOURS] =
(tm->tm_hour != -1) ? bin2bcd(tm->tm_hour) : 0x80;
fm3130->regs[FM3130_ALARM_DATE] =
(tm->tm_mday != -1) ? bin2bcd(tm->tm_mday) : 0x80;
fm3130->regs[FM3130_ALARM_MONTHS] =
(tm->tm_mon != -1) ? bin2bcd(tm->tm_mon + 1) : 0x80;
dev_dbg(dev, "alarm write %02x %02x %02x %02x %02x\n",
fm3130->regs[FM3130_ALARM_SECONDS],
fm3130->regs[FM3130_ALARM_MINUTES],
fm3130->regs[FM3130_ALARM_HOURS],
fm3130->regs[FM3130_ALARM_DATE],
fm3130->regs[FM3130_ALARM_MONTHS]);
for (i = 0; i < FM3130_ALARM_REGS; i++) {
i2c_smbus_write_byte_data(fm3130->client,
FM3130_ALARM_SECONDS + i,
fm3130->regs[FM3130_ALARM_SECONDS + i]);
}
fm3130->regs[FM3130_RTC_CONTROL] =
i2c_smbus_read_byte_data(fm3130->client, FM3130_RTC_CONTROL);
if (alrm->enabled) {
i2c_smbus_write_byte_data(fm3130->client, FM3130_RTC_CONTROL,
(fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_CAL)) |
FM3130_RTC_CONTROL_BIT_AEN);
} else {
i2c_smbus_write_byte_data(fm3130->client, FM3130_RTC_CONTROL,
fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_CAL) &
~(FM3130_RTC_CONTROL_BIT_AEN));
}
if (!fm3130->alarm_valid)
fm3130->alarm_valid = 1;
return 0;
}
static int fm3130_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct fm3130 *fm3130 = dev_get_drvdata(dev);
int ret = 0;
fm3130->regs[FM3130_RTC_CONTROL] =
i2c_smbus_read_byte_data(fm3130->client, FM3130_RTC_CONTROL);
dev_dbg(dev, "alarm_irq_enable: enable=%d, FM3130_RTC_CONTROL=%02x\n",
enabled, fm3130->regs[FM3130_RTC_CONTROL]);
switch (enabled) {
case 0:
ret = i2c_smbus_write_byte_data(fm3130->client,
FM3130_RTC_CONTROL, fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_CAL) &
~(FM3130_RTC_CONTROL_BIT_AEN));
break;
case 1:
ret = i2c_smbus_write_byte_data(fm3130->client,
FM3130_RTC_CONTROL, (fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_CAL)) |
FM3130_RTC_CONTROL_BIT_AEN);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int __devinit fm3130_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct fm3130 *fm3130;
int err = -ENODEV;
int tmp;
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
if (!i2c_check_functionality(adapter,
I2C_FUNC_I2C | I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -EIO;
fm3130 = kzalloc(sizeof(struct fm3130), GFP_KERNEL);
if (!fm3130)
return -ENOMEM;
fm3130->client = client;
i2c_set_clientdata(client, fm3130);
fm3130->reg_addr_time = FM3130_RTC_SECONDS;
fm3130->reg_addr_alarm = FM3130_ALARM_SECONDS;
fm3130->msg[0].addr = client->addr;
fm3130->msg[0].flags = 0;
fm3130->msg[0].len = 1;
fm3130->msg[0].buf = &fm3130->reg_addr_time;
fm3130->msg[1].addr = client->addr;
fm3130->msg[1].flags = I2C_M_RD;
fm3130->msg[1].len = FM3130_CLOCK_REGS;
fm3130->msg[1].buf = &fm3130->regs[FM3130_RTC_SECONDS];
fm3130->msg[2].addr = client->addr;
fm3130->msg[2].flags = 0;
fm3130->msg[2].len = 1;
fm3130->msg[2].buf = &fm3130->reg_addr_alarm;
fm3130->msg[3].addr = client->addr;
fm3130->msg[3].flags = I2C_M_RD;
fm3130->msg[3].len = FM3130_ALARM_REGS;
fm3130->msg[3].buf = &fm3130->regs[FM3130_ALARM_SECONDS];
fm3130->alarm_valid = 0;
fm3130->data_valid = 0;
tmp = i2c_transfer(adapter, fm3130->msg, 4);
if (tmp != 4) {
pr_debug("read error %d\n", tmp);
err = -EIO;
goto exit_free;
}
fm3130->regs[FM3130_RTC_CONTROL] =
i2c_smbus_read_byte_data(client, FM3130_RTC_CONTROL);
fm3130->regs[FM3130_CAL_CONTROL] =
i2c_smbus_read_byte_data(client, FM3130_CAL_CONTROL);
if (fm3130->regs[FM3130_RTC_CONTROL] & FM3130_RTC_CONTROL_BIT_CAL) {
i2c_smbus_write_byte_data(client, FM3130_RTC_CONTROL,
fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_CAL));
dev_warn(&client->dev, "Disabling calibration mode!\n");
}
if (fm3130->regs[FM3130_RTC_CONTROL] & FM3130_RTC_CONTROL_BIT_WRITE ||
fm3130->regs[FM3130_RTC_CONTROL] & FM3130_RTC_CONTROL_BIT_READ) {
i2c_smbus_write_byte_data(client, FM3130_RTC_CONTROL,
fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_READ |
FM3130_RTC_CONTROL_BIT_WRITE));
dev_warn(&client->dev, "Disabling READ or WRITE mode!\n");
}
if (fm3130->regs[FM3130_CAL_CONTROL] & FM3130_CAL_CONTROL_BIT_nOSCEN)
i2c_smbus_write_byte_data(client, FM3130_CAL_CONTROL,
fm3130->regs[FM3130_CAL_CONTROL] &
~(FM3130_CAL_CONTROL_BIT_nOSCEN));
if (fm3130->regs[FM3130_RTC_CONTROL] & FM3130_RTC_CONTROL_BIT_LB) {
i2c_smbus_write_byte_data(client, FM3130_RTC_CONTROL,
fm3130->regs[FM3130_RTC_CONTROL] &
~(FM3130_RTC_CONTROL_BIT_LB));
dev_warn(&client->dev, "Low battery!\n");
}
if (fm3130->regs[FM3130_RTC_CONTROL] & FM3130_RTC_CONTROL_BIT_POR) {
i2c_smbus_write_byte_data(client, FM3130_RTC_CONTROL,
fm3130->regs[FM3130_RTC_CONTROL] &
~FM3130_RTC_CONTROL_BIT_POR);
dev_dbg(&client->dev, "POR bit is set\n");
}
i2c_smbus_write_byte_data(client, FM3130_ALARM_WP_CONTROL, 0x80);
tmp = bcd2bin(fm3130->regs[FM3130_RTC_SECONDS] & 0x7f);
if (tmp > 59)
goto bad_alarm;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_MINUTES] & 0x7f);
if (tmp > 59)
goto bad_alarm;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_HOURS] & 0x3f);
if (tmp > 23)
goto bad_alarm;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_DATE] & 0x3f);
if (tmp == 0 || tmp > 31)
goto bad_alarm;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_MONTHS] & 0x1f);
if (tmp == 0 || tmp > 12)
goto bad_alarm;
fm3130->alarm_valid = 1;
bad_alarm:
tmp = bcd2bin(fm3130->regs[FM3130_RTC_SECONDS] & 0x7f);
if (tmp > 59)
goto bad_clock;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_MINUTES] & 0x7f);
if (tmp > 59)
goto bad_clock;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_HOURS] & 0x3f);
if (tmp > 23)
goto bad_clock;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_DAY] & 0x7);
if (tmp == 0 || tmp > 7)
goto bad_clock;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_DATE] & 0x3f);
if (tmp == 0 || tmp > 31)
goto bad_clock;
tmp = bcd2bin(fm3130->regs[FM3130_RTC_MONTHS] & 0x1f);
if (tmp == 0 || tmp > 12)
goto bad_clock;
fm3130->data_valid = 1;
bad_clock:
if (!fm3130->data_valid || !fm3130->alarm_valid)
dev_dbg(&client->dev,
"%s: %02x %02x %02x %02x %02x %02x %02x %02x"
"%02x %02x %02x %02x %02x %02x %02x\n",
"bogus registers",
fm3130->regs[0], fm3130->regs[1],
fm3130->regs[2], fm3130->regs[3],
fm3130->regs[4], fm3130->regs[5],
fm3130->regs[6], fm3130->regs[7],
fm3130->regs[8], fm3130->regs[9],
fm3130->regs[0xa], fm3130->regs[0xb],
fm3130->regs[0xc], fm3130->regs[0xd],
fm3130->regs[0xe]);
fm3130->rtc = rtc_device_register(client->name, &client->dev,
&fm3130_rtc_ops, THIS_MODULE);
if (IS_ERR(fm3130->rtc)) {
err = PTR_ERR(fm3130->rtc);
dev_err(&client->dev,
"unable to register the class device\n");
goto exit_free;
}
return 0;
exit_free:
kfree(fm3130);
return err;
}
static int __devexit fm3130_remove(struct i2c_client *client)
{
struct fm3130 *fm3130 = i2c_get_clientdata(client);
rtc_device_unregister(fm3130->rtc);
kfree(fm3130);
return 0;
}
static int __init fm3130_init(void)
{
return i2c_add_driver(&fm3130_driver);
}
static void __exit fm3130_exit(void)
{
i2c_del_driver(&fm3130_driver);
}
