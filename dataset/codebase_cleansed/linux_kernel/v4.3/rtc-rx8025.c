static s32 rx8025_read_reg(const struct i2c_client *client, u8 number)
{
return i2c_smbus_read_byte_data(client, number << 4);
}
static int rx8025_read_regs(const struct i2c_client *client,
u8 number, u8 length, u8 *values)
{
int ret = i2c_smbus_read_i2c_block_data(client, number << 4, length,
values);
if (ret != length)
return ret < 0 ? ret : -EIO;
return 0;
}
static s32 rx8025_write_reg(const struct i2c_client *client, u8 number,
u8 value)
{
return i2c_smbus_write_byte_data(client, number << 4, value);
}
static s32 rx8025_write_regs(const struct i2c_client *client,
u8 number, u8 length, const u8 *values)
{
return i2c_smbus_write_i2c_block_data(client, number << 4,
length, values);
}
static int rx8025_check_validity(struct device *dev)
{
struct rx8025_data *rx8025 = dev_get_drvdata(dev);
int ctrl2;
ctrl2 = rx8025_read_reg(rx8025->client, RX8025_REG_CTRL2);
if (ctrl2 < 0)
return ctrl2;
if (ctrl2 & RX8025_BIT_CTRL2_VDET)
dev_warn(dev, "power voltage drop detected\n");
if (ctrl2 & RX8025_BIT_CTRL2_PON) {
dev_warn(dev, "power-on reset detected, date is invalid\n");
return -EINVAL;
}
if (!(ctrl2 & RX8025_BIT_CTRL2_XST)) {
dev_warn(dev, "crystal stopped, date is invalid\n");
return -EINVAL;
}
return 0;
}
static int rx8025_reset_validity(struct i2c_client *client)
{
int ctrl2 = rx8025_read_reg(client, RX8025_REG_CTRL2);
if (ctrl2 < 0)
return ctrl2;
ctrl2 &= ~(RX8025_BIT_CTRL2_PON | RX8025_BIT_CTRL2_VDET);
return rx8025_write_reg(client, RX8025_REG_CTRL2,
ctrl2 | RX8025_BIT_CTRL2_XST);
}
static irqreturn_t rx8025_handle_irq(int irq, void *dev_id)
{
struct i2c_client *client = dev_id;
struct rx8025_data *rx8025 = i2c_get_clientdata(client);
int status;
status = rx8025_read_reg(client, RX8025_REG_CTRL2);
if (status < 0)
goto out;
if (!(status & RX8025_BIT_CTRL2_XST))
dev_warn(&client->dev, "Oscillation stop was detected,"
"you may have to readjust the clock\n");
if (status & RX8025_BIT_CTRL2_CTFG) {
status &= ~RX8025_BIT_CTRL2_CTFG;
rtc_update_irq(rx8025->rtc, 1, RTC_PF | RTC_IRQF);
}
if (status & RX8025_BIT_CTRL2_DAFG) {
status &= RX8025_BIT_CTRL2_DAFG;
if (rx8025_write_reg(client, RX8025_REG_CTRL1,
rx8025->ctrl1 & ~RX8025_BIT_CTRL1_DALE))
goto out;
rtc_update_irq(rx8025->rtc, 1, RTC_AF | RTC_IRQF);
}
out:
return IRQ_HANDLED;
}
static int rx8025_get_time(struct device *dev, struct rtc_time *dt)
{
struct rx8025_data *rx8025 = dev_get_drvdata(dev);
u8 date[7];
int err;
err = rx8025_check_validity(dev);
if (err)
return err;
err = rx8025_read_regs(rx8025->client, RX8025_REG_SEC, 7, date);
if (err)
return err;
dev_dbg(dev, "%s: read 0x%02x 0x%02x "
"0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n", __func__,
date[0], date[1], date[2], date[3], date[4],
date[5], date[6]);
dt->tm_sec = bcd2bin(date[RX8025_REG_SEC] & 0x7f);
dt->tm_min = bcd2bin(date[RX8025_REG_MIN] & 0x7f);
if (rx8025->ctrl1 & RX8025_BIT_CTRL1_1224)
dt->tm_hour = bcd2bin(date[RX8025_REG_HOUR] & 0x3f);
else
dt->tm_hour = bcd2bin(date[RX8025_REG_HOUR] & 0x1f) % 12
+ (date[RX8025_REG_HOUR] & 0x20 ? 12 : 0);
dt->tm_mday = bcd2bin(date[RX8025_REG_MDAY] & 0x3f);
dt->tm_mon = bcd2bin(date[RX8025_REG_MONTH] & 0x1f) - 1;
dt->tm_year = bcd2bin(date[RX8025_REG_YEAR]) + 100;
dev_dbg(dev, "%s: date %ds %dm %dh %dmd %dm %dy\n", __func__,
dt->tm_sec, dt->tm_min, dt->tm_hour,
dt->tm_mday, dt->tm_mon, dt->tm_year);
return rtc_valid_tm(dt);
}
static int rx8025_set_time(struct device *dev, struct rtc_time *dt)
{
struct rx8025_data *rx8025 = dev_get_drvdata(dev);
u8 date[7];
int ret;
if ((dt->tm_year < 100) || (dt->tm_year > 199))
return -EINVAL;
date[RX8025_REG_SEC] = bin2bcd(dt->tm_sec);
date[RX8025_REG_MIN] = bin2bcd(dt->tm_min);
if (rx8025->ctrl1 & RX8025_BIT_CTRL1_1224)
date[RX8025_REG_HOUR] = bin2bcd(dt->tm_hour);
else
date[RX8025_REG_HOUR] = (dt->tm_hour >= 12 ? 0x20 : 0)
| bin2bcd((dt->tm_hour + 11) % 12 + 1);
date[RX8025_REG_WDAY] = bin2bcd(dt->tm_wday);
date[RX8025_REG_MDAY] = bin2bcd(dt->tm_mday);
date[RX8025_REG_MONTH] = bin2bcd(dt->tm_mon + 1);
date[RX8025_REG_YEAR] = bin2bcd(dt->tm_year - 100);
dev_dbg(dev,
"%s: write 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n",
__func__,
date[0], date[1], date[2], date[3], date[4], date[5], date[6]);
ret = rx8025_write_regs(rx8025->client, RX8025_REG_SEC, 7, date);
if (ret < 0)
return ret;
return rx8025_reset_validity(rx8025->client);
}
static int rx8025_init_client(struct i2c_client *client)
{
struct rx8025_data *rx8025 = i2c_get_clientdata(client);
u8 ctrl[2], ctrl2;
int need_clear = 0;
int err;
err = rx8025_read_regs(rx8025->client, RX8025_REG_CTRL1, 2, ctrl);
if (err)
goto out;
rx8025->ctrl1 = ctrl[0] & ~RX8025_BIT_CTRL1_TEST;
if (ctrl[1] & (RX8025_BIT_CTRL2_DAFG | RX8025_BIT_CTRL2_WAFG)) {
dev_warn(&client->dev, "Alarm was detected\n");
need_clear = 1;
}
if (ctrl[1] & RX8025_BIT_CTRL2_CTFG)
need_clear = 1;
if (need_clear) {
ctrl2 = ctrl[1];
ctrl2 &= ~(RX8025_BIT_CTRL2_CTFG | RX8025_BIT_CTRL2_WAFG |
RX8025_BIT_CTRL2_DAFG);
err = rx8025_write_reg(client, RX8025_REG_CTRL2, ctrl2);
}
out:
return err;
}
static int rx8025_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct rx8025_data *rx8025 = dev_get_drvdata(dev);
struct i2c_client *client = rx8025->client;
u8 ald[2];
int ctrl2, err;
if (client->irq <= 0)
return -EINVAL;
err = rx8025_read_regs(client, RX8025_REG_ALDMIN, 2, ald);
if (err)
return err;
ctrl2 = rx8025_read_reg(client, RX8025_REG_CTRL2);
if (ctrl2 < 0)
return ctrl2;
dev_dbg(dev, "%s: read alarm 0x%02x 0x%02x ctrl2 %02x\n",
__func__, ald[0], ald[1], ctrl2);
t->time.tm_sec = 0;
t->time.tm_min = bcd2bin(ald[0] & 0x7f);
if (rx8025->ctrl1 & RX8025_BIT_CTRL1_1224)
t->time.tm_hour = bcd2bin(ald[1] & 0x3f);
else
t->time.tm_hour = bcd2bin(ald[1] & 0x1f) % 12
+ (ald[1] & 0x20 ? 12 : 0);
t->time.tm_wday = -1;
t->time.tm_mday = -1;
t->time.tm_mon = -1;
t->time.tm_year = -1;
dev_dbg(dev, "%s: date: %ds %dm %dh %dmd %dm %dy\n",
__func__,
t->time.tm_sec, t->time.tm_min, t->time.tm_hour,
t->time.tm_mday, t->time.tm_mon, t->time.tm_year);
t->enabled = !!(rx8025->ctrl1 & RX8025_BIT_CTRL1_DALE);
t->pending = (ctrl2 & RX8025_BIT_CTRL2_DAFG) && t->enabled;
return err;
}
static int rx8025_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
struct rx8025_data *rx8025 = dev_get_drvdata(dev);
u8 ald[2];
int err;
if (client->irq <= 0)
return -EINVAL;
ald[0] = bin2bcd(t->time.tm_min);
if (rx8025->ctrl1 & RX8025_BIT_CTRL1_1224)
ald[1] = bin2bcd(t->time.tm_hour);
else
ald[1] = (t->time.tm_hour >= 12 ? 0x20 : 0)
| bin2bcd((t->time.tm_hour + 11) % 12 + 1);
dev_dbg(dev, "%s: write 0x%02x 0x%02x\n", __func__, ald[0], ald[1]);
if (rx8025->ctrl1 & RX8025_BIT_CTRL1_DALE) {
rx8025->ctrl1 &= ~RX8025_BIT_CTRL1_DALE;
err = rx8025_write_reg(rx8025->client, RX8025_REG_CTRL1,
rx8025->ctrl1);
if (err)
return err;
}
err = rx8025_write_regs(rx8025->client, RX8025_REG_ALDMIN, 2, ald);
if (err)
return err;
if (t->enabled) {
rx8025->ctrl1 |= RX8025_BIT_CTRL1_DALE;
err = rx8025_write_reg(rx8025->client, RX8025_REG_CTRL1,
rx8025->ctrl1);
if (err)
return err;
}
return 0;
}
static int rx8025_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct rx8025_data *rx8025 = dev_get_drvdata(dev);
u8 ctrl1;
int err;
ctrl1 = rx8025->ctrl1;
if (enabled)
ctrl1 |= RX8025_BIT_CTRL1_DALE;
else
ctrl1 &= ~RX8025_BIT_CTRL1_DALE;
if (ctrl1 != rx8025->ctrl1) {
rx8025->ctrl1 = ctrl1;
err = rx8025_write_reg(rx8025->client, RX8025_REG_CTRL1,
rx8025->ctrl1);
if (err)
return err;
}
return 0;
}
static int rx8025_get_clock_adjust(struct device *dev, int *adj)
{
struct i2c_client *client = to_i2c_client(dev);
int digoff;
digoff = rx8025_read_reg(client, RX8025_REG_DIGOFF);
if (digoff < 0)
return digoff;
*adj = digoff >= 64 ? digoff - 128 : digoff;
if (*adj > 0)
(*adj)--;
*adj *= -RX8025_ADJ_RESOLUTION;
return 0;
}
static int rx8025_set_clock_adjust(struct device *dev, int adj)
{
struct i2c_client *client = to_i2c_client(dev);
u8 digoff;
int err;
adj /= -RX8025_ADJ_RESOLUTION;
if (adj > RX8025_ADJ_DATA_MAX)
adj = RX8025_ADJ_DATA_MAX;
else if (adj < RX8025_ADJ_DATA_MIN)
adj = RX8025_ADJ_DATA_MIN;
else if (adj > 0)
adj++;
else if (adj < 0)
adj += 128;
digoff = adj;
err = rx8025_write_reg(client, RX8025_REG_DIGOFF, digoff);
if (err)
return err;
dev_dbg(dev, "%s: write 0x%02x\n", __func__, digoff);
return 0;
}
static ssize_t rx8025_sysfs_show_clock_adjust(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int err, adj;
err = rx8025_get_clock_adjust(dev, &adj);
if (err)
return err;
return sprintf(buf, "%d\n", adj);
}
static ssize_t rx8025_sysfs_store_clock_adjust(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int adj, err;
if (sscanf(buf, "%i", &adj) != 1)
return -EINVAL;
err = rx8025_set_clock_adjust(dev, adj);
return err ? err : count;
}
static int rx8025_sysfs_register(struct device *dev)
{
return device_create_file(dev, &dev_attr_clock_adjust_ppb);
}
static void rx8025_sysfs_unregister(struct device *dev)
{
device_remove_file(dev, &dev_attr_clock_adjust_ppb);
}
static int rx8025_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct rx8025_data *rx8025;
int err = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_I2C_BLOCK)) {
dev_err(&adapter->dev,
"doesn't support required functionality\n");
return -EIO;
}
rx8025 = devm_kzalloc(&client->dev, sizeof(*rx8025), GFP_KERNEL);
if (!rx8025) {
return -ENOMEM;
}
rx8025->client = client;
i2c_set_clientdata(client, rx8025);
err = rx8025_init_client(client);
if (err)
return err;
rx8025->rtc = devm_rtc_device_register(&client->dev, client->name,
&rx8025_rtc_ops, THIS_MODULE);
if (IS_ERR(rx8025->rtc)) {
dev_err(&client->dev, "unable to register the class device\n");
return PTR_ERR(rx8025->rtc);
}
if (client->irq > 0) {
dev_info(&client->dev, "IRQ %d supplied\n", client->irq);
err = devm_request_threaded_irq(&client->dev, client->irq, NULL,
rx8025_handle_irq, 0, "rx8025",
client);
if (err) {
dev_err(&client->dev, "unable to request IRQ, alarms disabled\n");
client->irq = 0;
}
}
rx8025->rtc->max_user_freq = 1;
err = rx8025_sysfs_register(&client->dev);
return err;
}
static int rx8025_remove(struct i2c_client *client)
{
rx8025_sysfs_unregister(&client->dev);
return 0;
}
