static int
rv3029c2_i2c_read_regs(struct i2c_client *client, u8 reg, u8 *buf,
unsigned len)
{
int ret;
if ((reg > RV3029C2_USR1_RAM_PAGE + 7) ||
(reg + len > RV3029C2_USR1_RAM_PAGE + 8))
return -EINVAL;
ret = i2c_smbus_read_i2c_block_data(client, reg, len, buf);
if (ret < 0)
return ret;
if (ret < len)
return -EIO;
return 0;
}
static int
rv3029c2_i2c_write_regs(struct i2c_client *client, u8 reg, u8 const buf[],
unsigned len)
{
if ((reg > RV3029C2_USR1_RAM_PAGE + 7) ||
(reg + len > RV3029C2_USR1_RAM_PAGE + 8))
return -EINVAL;
return i2c_smbus_write_i2c_block_data(client, reg, len, buf);
}
static int
rv3029c2_i2c_get_sr(struct i2c_client *client, u8 *buf)
{
int ret = rv3029c2_i2c_read_regs(client, RV3029C2_STATUS, buf, 1);
if (ret < 0)
return -EIO;
dev_dbg(&client->dev, "status = 0x%.2x (%d)\n", buf[0], buf[0]);
return 0;
}
static int
rv3029c2_i2c_set_sr(struct i2c_client *client, u8 val)
{
u8 buf[1];
int sr;
buf[0] = val;
sr = rv3029c2_i2c_write_regs(client, RV3029C2_STATUS, buf, 1);
dev_dbg(&client->dev, "status = 0x%.2x (%d)\n", buf[0], buf[0]);
if (sr < 0)
return -EIO;
return 0;
}
static int
rv3029c2_i2c_read_time(struct i2c_client *client, struct rtc_time *tm)
{
u8 buf[1];
int ret;
u8 regs[RV3029C2_WATCH_SECTION_LEN] = { 0, };
ret = rv3029c2_i2c_get_sr(client, buf);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return -EIO;
}
ret = rv3029c2_i2c_read_regs(client, RV3029C2_W_SEC , regs,
RV3029C2_WATCH_SECTION_LEN);
if (ret < 0) {
dev_err(&client->dev, "%s: reading RTC section failed\n",
__func__);
return ret;
}
tm->tm_sec = bcd2bin(regs[RV3029C2_W_SEC-RV3029C2_W_SEC]);
tm->tm_min = bcd2bin(regs[RV3029C2_W_MINUTES-RV3029C2_W_SEC]);
{
const u8 _hr = regs[RV3029C2_W_HOURS-RV3029C2_W_SEC];
if (_hr & RV3029C2_REG_HR_12_24) {
tm->tm_hour = bcd2bin(_hr & 0x1f);
if (_hr & RV3029C2_REG_HR_PM)
tm->tm_hour += 12;
} else
tm->tm_hour = bcd2bin(_hr & 0x3f);
}
tm->tm_mday = bcd2bin(regs[RV3029C2_W_DATE-RV3029C2_W_SEC]);
tm->tm_mon = bcd2bin(regs[RV3029C2_W_MONTHS-RV3029C2_W_SEC]) - 1;
tm->tm_year = bcd2bin(regs[RV3029C2_W_YEARS-RV3029C2_W_SEC]) + 100;
tm->tm_wday = bcd2bin(regs[RV3029C2_W_DAYS-RV3029C2_W_SEC]) - 1;
return 0;
}
static int rv3029c2_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
return rv3029c2_i2c_read_time(to_i2c_client(dev), tm);
}
static int
rv3029c2_i2c_read_alarm(struct i2c_client *client, struct rtc_wkalrm *alarm)
{
struct rtc_time *const tm = &alarm->time;
int ret;
u8 regs[8];
ret = rv3029c2_i2c_get_sr(client, regs);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return -EIO;
}
ret = rv3029c2_i2c_read_regs(client, RV3029C2_A_SC, regs,
RV3029C2_ALARM_SECTION_LEN);
if (ret < 0) {
dev_err(&client->dev, "%s: reading alarm section failed\n",
__func__);
return ret;
}
tm->tm_sec = bcd2bin(regs[RV3029C2_A_SC-RV3029C2_A_SC] & 0x7f);
tm->tm_min = bcd2bin(regs[RV3029C2_A_MN-RV3029C2_A_SC] & 0x7f);
tm->tm_hour = bcd2bin(regs[RV3029C2_A_HR-RV3029C2_A_SC] & 0x3f);
tm->tm_mday = bcd2bin(regs[RV3029C2_A_DT-RV3029C2_A_SC] & 0x3f);
tm->tm_mon = bcd2bin(regs[RV3029C2_A_MO-RV3029C2_A_SC] & 0x1f) - 1;
tm->tm_year = bcd2bin(regs[RV3029C2_A_YR-RV3029C2_A_SC] & 0x7f) + 100;
tm->tm_wday = bcd2bin(regs[RV3029C2_A_DW-RV3029C2_A_SC] & 0x07) - 1;
return 0;
}
static int
rv3029c2_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
return rv3029c2_i2c_read_alarm(to_i2c_client(dev), alarm);
}
static int rv3029c2_rtc_i2c_alarm_set_irq(struct i2c_client *client,
int enable)
{
int ret;
u8 buf[1];
ret = rv3029c2_i2c_read_regs(client, RV3029C2_IRQ_CTRL, buf, 1);
if (ret < 0) {
dev_err(&client->dev, "can't read INT reg\n");
return ret;
}
if (enable)
buf[0] |= RV3029C2_IRQ_CTRL_AIE;
else
buf[0] &= ~RV3029C2_IRQ_CTRL_AIE;
ret = rv3029c2_i2c_write_regs(client, RV3029C2_IRQ_CTRL, buf, 1);
if (ret < 0) {
dev_err(&client->dev, "can't set INT reg\n");
return ret;
}
return 0;
}
static int rv3029c2_rtc_i2c_set_alarm(struct i2c_client *client,
struct rtc_wkalrm *alarm)
{
struct rtc_time *const tm = &alarm->time;
int ret;
u8 regs[8];
if (tm->tm_year < 100)
return -EINVAL;
ret = rv3029c2_i2c_get_sr(client, regs);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return -EIO;
}
regs[RV3029C2_A_SC-RV3029C2_A_SC] = bin2bcd(tm->tm_sec & 0x7f);
regs[RV3029C2_A_MN-RV3029C2_A_SC] = bin2bcd(tm->tm_min & 0x7f);
regs[RV3029C2_A_HR-RV3029C2_A_SC] = bin2bcd(tm->tm_hour & 0x3f);
regs[RV3029C2_A_DT-RV3029C2_A_SC] = bin2bcd(tm->tm_mday & 0x3f);
regs[RV3029C2_A_MO-RV3029C2_A_SC] = bin2bcd((tm->tm_mon & 0x1f) - 1);
regs[RV3029C2_A_DW-RV3029C2_A_SC] = bin2bcd((tm->tm_wday & 7) - 1);
regs[RV3029C2_A_YR-RV3029C2_A_SC] = bin2bcd((tm->tm_year & 0x7f) - 100);
ret = rv3029c2_i2c_write_regs(client, RV3029C2_A_SC, regs,
RV3029C2_ALARM_SECTION_LEN);
if (ret < 0)
return ret;
if (alarm->enabled) {
u8 buf[1];
ret = rv3029c2_i2c_read_regs(client, RV3029C2_IRQ_FLAGS,
buf, 1);
if (ret < 0) {
dev_err(&client->dev, "can't read alarm flag\n");
return ret;
}
buf[0] &= ~RV3029C2_IRQ_FLAGS_AF;
ret = rv3029c2_i2c_write_regs(client, RV3029C2_IRQ_FLAGS,
buf, 1);
if (ret < 0) {
dev_err(&client->dev, "can't set alarm flag\n");
return ret;
}
ret = rv3029c2_rtc_i2c_alarm_set_irq(client, 1);
if (ret)
return ret;
dev_dbg(&client->dev, "alarm IRQ armed\n");
} else {
ret = rv3029c2_rtc_i2c_alarm_set_irq(client, 1);
if (ret)
return ret;
dev_dbg(&client->dev, "alarm IRQ disabled\n");
}
return 0;
}
static int rv3029c2_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
return rv3029c2_rtc_i2c_set_alarm(to_i2c_client(dev), alarm);
}
static int
rv3029c2_i2c_set_time(struct i2c_client *client, struct rtc_time const *tm)
{
u8 regs[8];
int ret;
if (tm->tm_year < 100)
return -EINVAL;
regs[RV3029C2_W_SEC-RV3029C2_W_SEC] = bin2bcd(tm->tm_sec);
regs[RV3029C2_W_MINUTES-RV3029C2_W_SEC] = bin2bcd(tm->tm_min);
regs[RV3029C2_W_HOURS-RV3029C2_W_SEC] = bin2bcd(tm->tm_hour);
regs[RV3029C2_W_DATE-RV3029C2_W_SEC] = bin2bcd(tm->tm_mday);
regs[RV3029C2_W_MONTHS-RV3029C2_W_SEC] = bin2bcd(tm->tm_mon+1);
regs[RV3029C2_W_DAYS-RV3029C2_W_SEC] = bin2bcd((tm->tm_wday & 7)+1);
regs[RV3029C2_W_YEARS-RV3029C2_W_SEC] = bin2bcd(tm->tm_year - 100);
ret = rv3029c2_i2c_write_regs(client, RV3029C2_W_SEC, regs,
RV3029C2_WATCH_SECTION_LEN);
if (ret < 0)
return ret;
ret = rv3029c2_i2c_get_sr(client, regs);
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return ret;
}
ret = rv3029c2_i2c_set_sr(client, (regs[0] & ~RV3029C2_STATUS_PON));
if (ret < 0) {
dev_err(&client->dev, "%s: reading SR failed\n", __func__);
return ret;
}
return 0;
}
static int rv3029c2_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
return rv3029c2_i2c_set_time(to_i2c_client(dev), tm);
}
static int rv3029c2_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rtc_device *rtc;
int rc = 0;
u8 buf[1];
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_EMUL))
return -ENODEV;
rtc = devm_rtc_device_register(&client->dev, client->name,
&rv3029c2_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
rc = rv3029c2_i2c_get_sr(client, buf);
if (rc < 0) {
dev_err(&client->dev, "reading status failed\n");
return rc;
}
return 0;
}
static int rv3029c2_remove(struct i2c_client *client)
{
return 0;
}
