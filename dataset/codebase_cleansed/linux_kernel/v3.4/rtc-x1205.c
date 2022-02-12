static int x1205_get_datetime(struct i2c_client *client, struct rtc_time *tm,
unsigned char reg_base)
{
unsigned char dt_addr[2] = { 0, reg_base };
unsigned char buf[8];
int i;
struct i2c_msg msgs[] = {
{ client->addr, 0, 2, dt_addr },
{ client->addr, I2C_M_RD, 8, buf },
};
if (i2c_transfer(client->adapter, &msgs[0], 2) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
dev_dbg(&client->dev,
"%s: raw read data - sec=%02x, min=%02x, hr=%02x, "
"mday=%02x, mon=%02x, year=%02x, wday=%02x, y2k=%02x\n",
__func__,
buf[0], buf[1], buf[2], buf[3],
buf[4], buf[5], buf[6], buf[7]);
if (reg_base < X1205_CCR_BASE)
for (i = 0; i <= 4; i++)
buf[i] &= 0x7F;
tm->tm_sec = bcd2bin(buf[CCR_SEC]);
tm->tm_min = bcd2bin(buf[CCR_MIN]);
tm->tm_hour = bcd2bin(buf[CCR_HOUR] & 0x3F);
tm->tm_mday = bcd2bin(buf[CCR_MDAY]);
tm->tm_mon = bcd2bin(buf[CCR_MONTH]) - 1;
tm->tm_year = bcd2bin(buf[CCR_YEAR])
+ (bcd2bin(buf[CCR_Y2K]) * 100) - 1900;
tm->tm_wday = buf[CCR_WDAY];
dev_dbg(&client->dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
return 0;
}
static int x1205_get_status(struct i2c_client *client, unsigned char *sr)
{
static unsigned char sr_addr[2] = { 0, X1205_REG_SR };
struct i2c_msg msgs[] = {
{ client->addr, 0, 2, sr_addr },
{ client->addr, I2C_M_RD, 1, sr },
};
if (i2c_transfer(client->adapter, &msgs[0], 2) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
return 0;
}
static int x1205_set_datetime(struct i2c_client *client, struct rtc_time *tm,
u8 reg_base, unsigned char alm_enable)
{
int i, xfer;
unsigned char rdata[10] = { 0, reg_base };
unsigned char *buf = rdata + 2;
static const unsigned char wel[3] = { 0, X1205_REG_SR,
X1205_SR_WEL };
static const unsigned char rwel[3] = { 0, X1205_REG_SR,
X1205_SR_WEL | X1205_SR_RWEL };
static const unsigned char diswe[3] = { 0, X1205_REG_SR, 0 };
dev_dbg(&client->dev,
"%s: sec=%d min=%d hour=%d mday=%d mon=%d year=%d wday=%d\n",
__func__, tm->tm_sec, tm->tm_min, tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
buf[CCR_SEC] = bin2bcd(tm->tm_sec);
buf[CCR_MIN] = bin2bcd(tm->tm_min);
buf[CCR_HOUR] = bin2bcd(tm->tm_hour) | X1205_HR_MIL;
buf[CCR_MDAY] = bin2bcd(tm->tm_mday);
buf[CCR_MONTH] = bin2bcd(tm->tm_mon + 1);
buf[CCR_YEAR] = bin2bcd(tm->tm_year % 100);
buf[CCR_WDAY] = tm->tm_wday & 0x07;
buf[CCR_Y2K] = bin2bcd((tm->tm_year + 1900) / 100);
if (reg_base < X1205_CCR_BASE)
for (i = 0; i <= 4; i++)
buf[i] |= 0x80;
if ((xfer = i2c_master_send(client, wel, 3)) != 3) {
dev_err(&client->dev, "%s: wel - %d\n", __func__, xfer);
return -EIO;
}
if ((xfer = i2c_master_send(client, rwel, 3)) != 3) {
dev_err(&client->dev, "%s: rwel - %d\n", __func__, xfer);
return -EIO;
}
xfer = i2c_master_send(client, rdata, sizeof(rdata));
if (xfer != sizeof(rdata)) {
dev_err(&client->dev,
"%s: result=%d addr=%02x, data=%02x\n",
__func__,
xfer, rdata[1], rdata[2]);
return -EIO;
}
if (reg_base < X1205_CCR_BASE) {
unsigned char al0e[3] = { 0, X1205_REG_INT, 0 };
msleep(10);
xfer = i2c_master_send(client, rwel, 3);
if (xfer != 3) {
dev_err(&client->dev,
"%s: aloe rwel - %d\n",
__func__,
xfer);
return -EIO;
}
if (alm_enable)
al0e[2] = X1205_INT_AL0E;
xfer = i2c_master_send(client, al0e, 3);
if (xfer != 3) {
dev_err(&client->dev,
"%s: al0e - %d\n",
__func__,
xfer);
return -EIO;
}
msleep(10);
}
if ((xfer = i2c_master_send(client, diswe, 3)) != 3) {
dev_err(&client->dev, "%s: diswe - %d\n", __func__, xfer);
return -EIO;
}
return 0;
}
static int x1205_fix_osc(struct i2c_client *client)
{
int err;
struct rtc_time tm;
memset(&tm, 0, sizeof(tm));
err = x1205_set_datetime(client, &tm, X1205_CCR_BASE, 0);
if (err < 0)
dev_err(&client->dev, "unable to restart the oscillator\n");
return err;
}
static int x1205_get_dtrim(struct i2c_client *client, int *trim)
{
unsigned char dtr;
static unsigned char dtr_addr[2] = { 0, X1205_REG_DTR };
struct i2c_msg msgs[] = {
{ client->addr, 0, 2, dtr_addr },
{ client->addr, I2C_M_RD, 1, &dtr },
};
if (i2c_transfer(client->adapter, &msgs[0], 2) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
dev_dbg(&client->dev, "%s: raw dtr=%x\n", __func__, dtr);
*trim = 0;
if (dtr & X1205_DTR_DTR0)
*trim += 20;
if (dtr & X1205_DTR_DTR1)
*trim += 10;
if (dtr & X1205_DTR_DTR2)
*trim = -*trim;
return 0;
}
static int x1205_get_atrim(struct i2c_client *client, int *trim)
{
s8 atr;
static unsigned char atr_addr[2] = { 0, X1205_REG_ATR };
struct i2c_msg msgs[] = {
{ client->addr, 0, 2, atr_addr },
{ client->addr, I2C_M_RD, 1, &atr },
};
if (i2c_transfer(client->adapter, &msgs[0], 2) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
dev_dbg(&client->dev, "%s: raw atr=%x\n", __func__, atr);
if (atr & 0x20)
atr |= 0xC0;
dev_dbg(&client->dev, "%s: raw atr=%x (%d)\n", __func__, atr, atr);
*trim = (atr * 250) + 11000;
dev_dbg(&client->dev, "%s: real=%d\n", __func__, *trim);
return 0;
}
static int x1205_validate_client(struct i2c_client *client)
{
int i, xfer;
static const unsigned char probe_zero_pattern[] = {
X1205_REG_SR, 0x18,
X1205_REG_DTR, 0xF8,
X1205_REG_ATR, 0xC0,
X1205_REG_INT, 0x18,
X1205_REG_0, 0xFF,
};
static const struct x1205_limit probe_limits_pattern[] = {
{ X1205_REG_Y2K, 0xFF, 19, 20 },
{ X1205_REG_DW, 0xFF, 0, 6 },
{ X1205_REG_YR, 0xFF, 0, 99 },
{ X1205_REG_MO, 0xFF, 0, 12 },
{ X1205_REG_DT, 0xFF, 0, 31 },
{ X1205_REG_HR, 0x7F, 0, 23 },
{ X1205_REG_MN, 0xFF, 0, 59 },
{ X1205_REG_SC, 0xFF, 0, 59 },
{ X1205_REG_Y2K1, 0xFF, 19, 20 },
{ X1205_REG_Y2K0, 0xFF, 19, 20 },
};
for (i = 0; i < ARRAY_SIZE(probe_zero_pattern); i += 2) {
unsigned char buf;
unsigned char addr[2] = { 0, probe_zero_pattern[i] };
struct i2c_msg msgs[2] = {
{ client->addr, 0, 2, addr },
{ client->addr, I2C_M_RD, 1, &buf },
};
if ((xfer = i2c_transfer(client->adapter, msgs, 2)) != 2) {
dev_err(&client->dev,
"%s: could not read register %x\n",
__func__, probe_zero_pattern[i]);
return -EIO;
}
if ((buf & probe_zero_pattern[i+1]) != 0) {
dev_err(&client->dev,
"%s: register=%02x, zero pattern=%d, value=%x\n",
__func__, probe_zero_pattern[i], i, buf);
return -ENODEV;
}
}
for (i = 0; i < ARRAY_SIZE(probe_limits_pattern); i++) {
unsigned char reg, value;
unsigned char addr[2] = { 0, probe_limits_pattern[i].reg };
struct i2c_msg msgs[2] = {
{ client->addr, 0, 2, addr },
{ client->addr, I2C_M_RD, 1, &reg },
};
if ((xfer = i2c_transfer(client->adapter, msgs, 2)) != 2) {
dev_err(&client->dev,
"%s: could not read register %x\n",
__func__, probe_limits_pattern[i].reg);
return -EIO;
}
value = bcd2bin(reg & probe_limits_pattern[i].mask);
if (value > probe_limits_pattern[i].max ||
value < probe_limits_pattern[i].min) {
dev_dbg(&client->dev,
"%s: register=%x, lim pattern=%d, value=%d\n",
__func__, probe_limits_pattern[i].reg,
i, value);
return -ENODEV;
}
}
return 0;
}
static int x1205_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
int err;
unsigned char intreg, status;
static unsigned char int_addr[2] = { 0, X1205_REG_INT };
struct i2c_client *client = to_i2c_client(dev);
struct i2c_msg msgs[] = {
{ client->addr, 0, 2, int_addr },
{ client->addr, I2C_M_RD, 1, &intreg },
};
if (i2c_transfer(client->adapter, &msgs[0], 2) != 2) {
dev_err(&client->dev, "%s: read error\n", __func__);
return -EIO;
}
err = x1205_get_status(client, &status);
if (err == 0) {
alrm->pending = (status & X1205_SR_AL0) ? 1 : 0;
alrm->enabled = (intreg & X1205_INT_AL0E) ? 1 : 0;
err = x1205_get_datetime(client, &alrm->time, X1205_ALM0_BASE);
}
return err;
}
static int x1205_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
return x1205_set_datetime(to_i2c_client(dev),
&alrm->time, X1205_ALM0_BASE, alrm->enabled);
}
static int x1205_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return x1205_get_datetime(to_i2c_client(dev),
tm, X1205_CCR_BASE);
}
static int x1205_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return x1205_set_datetime(to_i2c_client(dev),
tm, X1205_CCR_BASE, 0);
}
static int x1205_rtc_proc(struct device *dev, struct seq_file *seq)
{
int err, dtrim, atrim;
if ((err = x1205_get_dtrim(to_i2c_client(dev), &dtrim)) == 0)
seq_printf(seq, "digital_trim\t: %d ppm\n", dtrim);
if ((err = x1205_get_atrim(to_i2c_client(dev), &atrim)) == 0)
seq_printf(seq, "analog_trim\t: %d.%02d pF\n",
atrim / 1000, atrim % 1000);
return 0;
}
static ssize_t x1205_sysfs_show_atrim(struct device *dev,
struct device_attribute *attr, char *buf)
{
int err, atrim;
err = x1205_get_atrim(to_i2c_client(dev), &atrim);
if (err)
return err;
return sprintf(buf, "%d.%02d pF\n", atrim / 1000, atrim % 1000);
}
static ssize_t x1205_sysfs_show_dtrim(struct device *dev,
struct device_attribute *attr, char *buf)
{
int err, dtrim;
err = x1205_get_dtrim(to_i2c_client(dev), &dtrim);
if (err)
return err;
return sprintf(buf, "%d ppm\n", dtrim);
}
static int x1205_sysfs_register(struct device *dev)
{
int err;
err = device_create_file(dev, &dev_attr_atrim);
if (err)
return err;
err = device_create_file(dev, &dev_attr_dtrim);
if (err)
device_remove_file(dev, &dev_attr_atrim);
return err;
}
static void x1205_sysfs_unregister(struct device *dev)
{
device_remove_file(dev, &dev_attr_atrim);
device_remove_file(dev, &dev_attr_dtrim);
}
static int x1205_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err = 0;
unsigned char sr;
struct rtc_device *rtc;
dev_dbg(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
if (x1205_validate_client(client) < 0)
return -ENODEV;
dev_info(&client->dev, "chip found, driver version " DRV_VERSION "\n");
rtc = rtc_device_register(x1205_driver.driver.name, &client->dev,
&x1205_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
if ((err = x1205_get_status(client, &sr)) == 0) {
if (sr & X1205_SR_RTCF) {
dev_err(&client->dev,
"power failure detected, "
"please set the clock\n");
udelay(50);
x1205_fix_osc(client);
}
}
else
dev_err(&client->dev, "couldn't read status\n");
err = x1205_sysfs_register(&client->dev);
if (err)
goto exit_devreg;
return 0;
exit_devreg:
rtc_device_unregister(rtc);
return err;
}
static int x1205_remove(struct i2c_client *client)
{
struct rtc_device *rtc = i2c_get_clientdata(client);
rtc_device_unregister(rtc);
x1205_sysfs_unregister(&client->dev);
return 0;
}
