static int pcf8563_read_block_data(struct i2c_client *client, unsigned char reg,
unsigned char length, unsigned char *buf)
{
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.len = 1,
.buf = &reg,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = length,
.buf = buf
},
};
if ((i2c_transfer(client->adapter, msgs, 2)) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
return 0;
}
static int pcf8563_write_block_data(struct i2c_client *client,
unsigned char reg, unsigned char length,
unsigned char *buf)
{
int i, err;
for (i = 0; i < length; i++) {
unsigned char data[2] = { reg + i, buf[i] };
err = i2c_master_send(client, data, sizeof(data));
if (err != sizeof(data)) {
dev_err(&client->dev,
"%s: err=%d addr=%02x, data=%02x\n",
__func__, err, data[0], data[1]);
return -EIO;
}
}
return 0;
}
static int pcf8563_set_alarm_mode(struct i2c_client *client, bool on)
{
unsigned char buf;
int err;
err = pcf8563_read_block_data(client, PCF8563_REG_ST2, 1, &buf);
if (err < 0)
return err;
if (on)
buf |= PCF8563_BIT_AIE;
else
buf &= ~PCF8563_BIT_AIE;
buf &= ~(PCF8563_BIT_AF | PCF8563_BITS_ST2_N);
err = pcf8563_write_block_data(client, PCF8563_REG_ST2, 1, &buf);
if (err < 0) {
dev_err(&client->dev, "%s: write error\n", __func__);
return -EIO;
}
return 0;
}
static int pcf8563_get_alarm_mode(struct i2c_client *client, unsigned char *en,
unsigned char *pen)
{
unsigned char buf;
int err;
err = pcf8563_read_block_data(client, PCF8563_REG_ST2, 1, &buf);
if (err)
return err;
if (en)
*en = !!(buf & PCF8563_BIT_AIE);
if (pen)
*pen = !!(buf & PCF8563_BIT_AF);
return 0;
}
static irqreturn_t pcf8563_irq(int irq, void *dev_id)
{
struct pcf8563 *pcf8563 = i2c_get_clientdata(dev_id);
int err;
char pending;
err = pcf8563_get_alarm_mode(pcf8563->client, NULL, &pending);
if (err)
return IRQ_NONE;
if (pending) {
rtc_update_irq(pcf8563->rtc, 1, RTC_IRQF | RTC_AF);
pcf8563_set_alarm_mode(pcf8563->client, 1);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int pcf8563_get_datetime(struct i2c_client *client, struct rtc_time *tm)
{
struct pcf8563 *pcf8563 = i2c_get_clientdata(client);
unsigned char buf[9];
int err;
err = pcf8563_read_block_data(client, PCF8563_REG_ST1, 9, buf);
if (err)
return err;
if (buf[PCF8563_REG_SC] & PCF8563_SC_LV) {
pcf8563->voltage_low = 1;
dev_err(&client->dev,
"low voltage detected, date/time is not reliable.\n");
return -EINVAL;
}
dev_dbg(&client->dev,
"%s: raw data is st1=%02x, st2=%02x, sec=%02x, min=%02x, hr=%02x, "
"mday=%02x, wday=%02x, mon=%02x, year=%02x\n",
__func__,
buf[0], buf[1], buf[2], buf[3],
buf[4], buf[5], buf[6], buf[7],
buf[8]);
tm->tm_sec = bcd2bin(buf[PCF8563_REG_SC] & 0x7F);
tm->tm_min = bcd2bin(buf[PCF8563_REG_MN] & 0x7F);
tm->tm_hour = bcd2bin(buf[PCF8563_REG_HR] & 0x3F);
tm->tm_mday = bcd2bin(buf[PCF8563_REG_DM] & 0x3F);
tm->tm_wday = buf[PCF8563_REG_DW] & 0x07;
tm->tm_mon = bcd2bin(buf[PCF8563_REG_MO] & 0x1F) - 1;
tm->tm_year = bcd2bin(buf[PCF8563_REG_YR]);
if (tm->tm_year < 70)
tm->tm_year += 100;
pcf8563->c_polarity = (buf[PCF8563_REG_MO] & PCF8563_MO_C) ?
(tm->tm_year >= 100) : (tm->tm_year < 100);
dev_dbg(&client->dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
return 0;
}
static int pcf8563_set_datetime(struct i2c_client *client, struct rtc_time *tm)
{
struct pcf8563 *pcf8563 = i2c_get_clientdata(client);
unsigned char buf[9];
dev_dbg(&client->dev, "%s: secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
buf[PCF8563_REG_SC] = bin2bcd(tm->tm_sec);
buf[PCF8563_REG_MN] = bin2bcd(tm->tm_min);
buf[PCF8563_REG_HR] = bin2bcd(tm->tm_hour);
buf[PCF8563_REG_DM] = bin2bcd(tm->tm_mday);
buf[PCF8563_REG_MO] = bin2bcd(tm->tm_mon + 1);
buf[PCF8563_REG_YR] = bin2bcd(tm->tm_year % 100);
if (pcf8563->c_polarity ? (tm->tm_year >= 100) : (tm->tm_year < 100))
buf[PCF8563_REG_MO] |= PCF8563_MO_C;
buf[PCF8563_REG_DW] = tm->tm_wday & 0x07;
return pcf8563_write_block_data(client, PCF8563_REG_SC,
9 - PCF8563_REG_SC, buf + PCF8563_REG_SC);
}
static int pcf8563_rtc_ioctl(struct device *dev, unsigned int cmd, unsigned long arg)
{
struct pcf8563 *pcf8563 = i2c_get_clientdata(to_i2c_client(dev));
struct rtc_time tm;
switch (cmd) {
case RTC_VL_READ:
if (pcf8563->voltage_low)
dev_info(dev, "low voltage detected, date/time is not reliable.\n");
if (copy_to_user((void __user *)arg, &pcf8563->voltage_low,
sizeof(int)))
return -EFAULT;
return 0;
case RTC_VL_CLR:
if (pcf8563_get_datetime(to_i2c_client(dev), &tm))
pcf8563_set_datetime(to_i2c_client(dev), &tm);
pcf8563->voltage_low = 0;
return 0;
default:
return -ENOIOCTLCMD;
}
}
static int pcf8563_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return pcf8563_get_datetime(to_i2c_client(dev), tm);
}
static int pcf8563_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return pcf8563_set_datetime(to_i2c_client(dev), tm);
}
static int pcf8563_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[4];
int err;
err = pcf8563_read_block_data(client, PCF8563_REG_AMN, 4, buf);
if (err)
return err;
dev_dbg(&client->dev,
"%s: raw data is min=%02x, hr=%02x, mday=%02x, wday=%02x\n",
__func__, buf[0], buf[1], buf[2], buf[3]);
tm->time.tm_min = bcd2bin(buf[0] & 0x7F);
tm->time.tm_hour = bcd2bin(buf[1] & 0x3F);
tm->time.tm_mday = bcd2bin(buf[2] & 0x3F);
tm->time.tm_wday = bcd2bin(buf[3] & 0x7);
tm->time.tm_mon = -1;
tm->time.tm_year = -1;
tm->time.tm_yday = -1;
tm->time.tm_isdst = -1;
err = pcf8563_get_alarm_mode(client, &tm->enabled, &tm->pending);
if (err < 0)
return err;
dev_dbg(&client->dev, "%s: tm is mins=%d, hours=%d, mday=%d, wday=%d,"
" enabled=%d, pending=%d\n", __func__, tm->time.tm_min,
tm->time.tm_hour, tm->time.tm_mday, tm->time.tm_wday,
tm->enabled, tm->pending);
return 0;
}
static int pcf8563_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[4];
int err;
if (tm->time.tm_sec) {
time64_t alarm_time = rtc_tm_to_time64(&tm->time);
alarm_time += 60 - tm->time.tm_sec;
rtc_time64_to_tm(alarm_time, &tm->time);
}
dev_dbg(dev, "%s, min=%d hour=%d wday=%d mday=%d "
"enabled=%d pending=%d\n", __func__,
tm->time.tm_min, tm->time.tm_hour, tm->time.tm_wday,
tm->time.tm_mday, tm->enabled, tm->pending);
buf[0] = bin2bcd(tm->time.tm_min);
buf[1] = bin2bcd(tm->time.tm_hour);
buf[2] = bin2bcd(tm->time.tm_mday);
buf[3] = tm->time.tm_wday & 0x07;
err = pcf8563_write_block_data(client, PCF8563_REG_AMN, 4, buf);
if (err)
return err;
return pcf8563_set_alarm_mode(client, 1);
}
static int pcf8563_irq_enable(struct device *dev, unsigned int enabled)
{
dev_dbg(dev, "%s: en=%d\n", __func__, enabled);
return pcf8563_set_alarm_mode(to_i2c_client(dev), !!enabled);
}
static int pcf8563_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pcf8563 *pcf8563;
int err;
unsigned char buf;
unsigned char alm_pending;
dev_dbg(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
pcf8563 = devm_kzalloc(&client->dev, sizeof(struct pcf8563),
GFP_KERNEL);
if (!pcf8563)
return -ENOMEM;
dev_info(&client->dev, "chip found, driver version " DRV_VERSION "\n");
i2c_set_clientdata(client, pcf8563);
pcf8563->client = client;
device_set_wakeup_capable(&client->dev, 1);
buf = PCF8563_TMRC_1_60;
err = pcf8563_write_block_data(client, PCF8563_REG_TMRC, 1, &buf);
if (err < 0) {
dev_err(&client->dev, "%s: write error\n", __func__);
return err;
}
err = pcf8563_get_alarm_mode(client, NULL, &alm_pending);
if (err) {
dev_err(&client->dev, "%s: read error\n", __func__);
return err;
}
if (alm_pending)
pcf8563_set_alarm_mode(client, 0);
pcf8563->rtc = devm_rtc_device_register(&client->dev,
pcf8563_driver.driver.name,
&pcf8563_rtc_ops, THIS_MODULE);
if (IS_ERR(pcf8563->rtc))
return PTR_ERR(pcf8563->rtc);
if (client->irq > 0) {
err = devm_request_threaded_irq(&client->dev, client->irq,
NULL, pcf8563_irq,
IRQF_SHARED|IRQF_ONESHOT|IRQF_TRIGGER_FALLING,
pcf8563->rtc->name, client);
if (err) {
dev_err(&client->dev, "unable to request IRQ %d\n",
client->irq);
return err;
}
}
pcf8563->rtc->uie_unsupported = 1;
return 0;
}
