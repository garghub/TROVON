static int abx80x_is_rc_mode(struct i2c_client *client)
{
int flags = 0;
flags = i2c_smbus_read_byte_data(client, ABX8XX_REG_OSS);
if (flags < 0) {
dev_err(&client->dev,
"Failed to read autocalibration attribute\n");
return flags;
}
return (flags & ABX8XX_OSS_OMODE) ? 1 : 0;
}
static int abx80x_enable_trickle_charger(struct i2c_client *client,
u8 trickle_cfg)
{
int err;
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_CFG_KEY,
ABX8XX_CFG_KEY_MISC);
if (err < 0) {
dev_err(&client->dev, "Unable to write configuration key\n");
return -EIO;
}
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_TRICKLE,
ABX8XX_TRICKLE_CHARGE_ENABLE |
trickle_cfg);
if (err < 0) {
dev_err(&client->dev, "Unable to write trickle register\n");
return -EIO;
}
return 0;
}
static int abx80x_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[8];
int err, flags, rc_mode = 0;
rc_mode = abx80x_is_rc_mode(client);
if (rc_mode < 0)
return rc_mode;
if (!rc_mode) {
flags = i2c_smbus_read_byte_data(client, ABX8XX_REG_OSS);
if (flags < 0)
return flags;
if (flags & ABX8XX_OSS_OF) {
dev_err(dev, "Oscillator failure, data is invalid.\n");
return -EINVAL;
}
}
err = i2c_smbus_read_i2c_block_data(client, ABX8XX_REG_HTH,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to read date\n");
return -EIO;
}
tm->tm_sec = bcd2bin(buf[ABX8XX_REG_SC] & 0x7F);
tm->tm_min = bcd2bin(buf[ABX8XX_REG_MN] & 0x7F);
tm->tm_hour = bcd2bin(buf[ABX8XX_REG_HR] & 0x3F);
tm->tm_wday = buf[ABX8XX_REG_WD] & 0x7;
tm->tm_mday = bcd2bin(buf[ABX8XX_REG_DA] & 0x3F);
tm->tm_mon = bcd2bin(buf[ABX8XX_REG_MO] & 0x1F) - 1;
tm->tm_year = bcd2bin(buf[ABX8XX_REG_YR]) + 100;
err = rtc_valid_tm(tm);
if (err < 0)
dev_err(&client->dev, "retrieved date/time is not valid.\n");
return err;
}
static int abx80x_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[8];
int err, flags;
if (tm->tm_year < 100)
return -EINVAL;
buf[ABX8XX_REG_HTH] = 0;
buf[ABX8XX_REG_SC] = bin2bcd(tm->tm_sec);
buf[ABX8XX_REG_MN] = bin2bcd(tm->tm_min);
buf[ABX8XX_REG_HR] = bin2bcd(tm->tm_hour);
buf[ABX8XX_REG_DA] = bin2bcd(tm->tm_mday);
buf[ABX8XX_REG_MO] = bin2bcd(tm->tm_mon + 1);
buf[ABX8XX_REG_YR] = bin2bcd(tm->tm_year - 100);
buf[ABX8XX_REG_WD] = tm->tm_wday;
err = i2c_smbus_write_i2c_block_data(client, ABX8XX_REG_HTH,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to write to date registers\n");
return -EIO;
}
flags = i2c_smbus_read_byte_data(client, ABX8XX_REG_OSS);
if (flags < 0)
return flags;
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_OSS,
flags & ~ABX8XX_OSS_OF);
if (err < 0) {
dev_err(&client->dev, "Unable to write oscillator status register\n");
return err;
}
return 0;
}
static irqreturn_t abx80x_handle_irq(int irq, void *dev_id)
{
struct i2c_client *client = dev_id;
struct rtc_device *rtc = i2c_get_clientdata(client);
int status;
status = i2c_smbus_read_byte_data(client, ABX8XX_REG_STATUS);
if (status < 0)
return IRQ_NONE;
if (status & ABX8XX_STATUS_AF)
rtc_update_irq(rtc, 1, RTC_AF | RTC_IRQF);
i2c_smbus_write_byte_data(client, ABX8XX_REG_STATUS, 0);
return IRQ_HANDLED;
}
static int abx80x_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned char buf[7];
int irq_mask, err;
if (client->irq <= 0)
return -EINVAL;
err = i2c_smbus_read_i2c_block_data(client, ABX8XX_REG_ASC,
sizeof(buf), buf);
if (err)
return err;
irq_mask = i2c_smbus_read_byte_data(client, ABX8XX_REG_IRQ);
if (irq_mask < 0)
return irq_mask;
t->time.tm_sec = bcd2bin(buf[0] & 0x7F);
t->time.tm_min = bcd2bin(buf[1] & 0x7F);
t->time.tm_hour = bcd2bin(buf[2] & 0x3F);
t->time.tm_mday = bcd2bin(buf[3] & 0x3F);
t->time.tm_mon = bcd2bin(buf[4] & 0x1F) - 1;
t->time.tm_wday = buf[5] & 0x7;
t->enabled = !!(irq_mask & ABX8XX_IRQ_AIE);
t->pending = (buf[6] & ABX8XX_STATUS_AF) && t->enabled;
return err;
}
static int abx80x_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct i2c_client *client = to_i2c_client(dev);
u8 alarm[6];
int err;
if (client->irq <= 0)
return -EINVAL;
alarm[0] = 0x0;
alarm[1] = bin2bcd(t->time.tm_sec);
alarm[2] = bin2bcd(t->time.tm_min);
alarm[3] = bin2bcd(t->time.tm_hour);
alarm[4] = bin2bcd(t->time.tm_mday);
alarm[5] = bin2bcd(t->time.tm_mon + 1);
err = i2c_smbus_write_i2c_block_data(client, ABX8XX_REG_AHTH,
sizeof(alarm), alarm);
if (err < 0) {
dev_err(&client->dev, "Unable to write alarm registers\n");
return -EIO;
}
if (t->enabled) {
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_IRQ,
(ABX8XX_IRQ_IM_1_4 |
ABX8XX_IRQ_AIE));
if (err)
return err;
}
return 0;
}
static int abx80x_rtc_set_autocalibration(struct device *dev,
int autocalibration)
{
struct i2c_client *client = to_i2c_client(dev);
int retval, flags = 0;
if ((autocalibration != 0) && (autocalibration != 1024) &&
(autocalibration != 512)) {
dev_err(dev, "autocalibration value outside permitted range\n");
return -EINVAL;
}
flags = i2c_smbus_read_byte_data(client, ABX8XX_REG_OSC);
if (flags < 0)
return flags;
if (autocalibration == 0) {
flags &= ~(ABX8XX_OSC_ACAL_512 | ABX8XX_OSC_ACAL_1024);
} else if (autocalibration == 1024) {
flags |= ABX8XX_OSC_ACAL_1024;
flags &= ~(ABX8XX_OSC_ACAL_512);
} else {
flags |= (ABX8XX_OSC_ACAL_1024 | ABX8XX_OSC_ACAL_512);
}
retval = i2c_smbus_write_byte_data(client, ABX8XX_REG_CFG_KEY,
ABX8XX_CFG_KEY_OSC);
if (retval < 0) {
dev_err(dev, "Failed to write CONFIG_KEY register\n");
return retval;
}
retval = i2c_smbus_write_byte_data(client, ABX8XX_REG_OSC, flags);
return retval;
}
static int abx80x_rtc_get_autocalibration(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int flags = 0, autocalibration;
flags = i2c_smbus_read_byte_data(client, ABX8XX_REG_OSC);
if (flags < 0)
return flags;
if (flags & ABX8XX_OSC_ACAL_512)
autocalibration = 512;
else if (flags & ABX8XX_OSC_ACAL_1024)
autocalibration = 1024;
else
autocalibration = 0;
return autocalibration;
}
static ssize_t autocalibration_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int retval;
unsigned long autocalibration = 0;
retval = kstrtoul(buf, 10, &autocalibration);
if (retval < 0) {
dev_err(dev, "Failed to store RTC autocalibration attribute\n");
return -EINVAL;
}
retval = abx80x_rtc_set_autocalibration(dev, autocalibration);
return retval ? retval : count;
}
static ssize_t autocalibration_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int autocalibration = 0;
autocalibration = abx80x_rtc_get_autocalibration(dev);
if (autocalibration < 0) {
dev_err(dev, "Failed to read RTC autocalibration\n");
sprintf(buf, "0\n");
return autocalibration;
}
return sprintf(buf, "%d\n", autocalibration);
}
static ssize_t oscillator_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
int retval, flags, rc_mode = 0;
if (strncmp(buf, "rc", 2) == 0) {
rc_mode = 1;
} else if (strncmp(buf, "xtal", 4) == 0) {
rc_mode = 0;
} else {
dev_err(dev, "Oscillator selection value outside permitted ones\n");
return -EINVAL;
}
flags = i2c_smbus_read_byte_data(client, ABX8XX_REG_OSC);
if (flags < 0)
return flags;
if (rc_mode == 0)
flags &= ~(ABX8XX_OSC_OSEL);
else
flags |= (ABX8XX_OSC_OSEL);
retval = i2c_smbus_write_byte_data(client, ABX8XX_REG_CFG_KEY,
ABX8XX_CFG_KEY_OSC);
if (retval < 0) {
dev_err(dev, "Failed to write CONFIG_KEY register\n");
return retval;
}
retval = i2c_smbus_write_byte_data(client, ABX8XX_REG_OSC, flags);
if (retval < 0) {
dev_err(dev, "Failed to write Oscillator Control register\n");
return retval;
}
return retval ? retval : count;
}
static ssize_t oscillator_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int rc_mode = 0;
struct i2c_client *client = to_i2c_client(dev);
rc_mode = abx80x_is_rc_mode(client);
if (rc_mode < 0) {
dev_err(dev, "Failed to read RTC oscillator selection\n");
sprintf(buf, "\n");
return rc_mode;
}
if (rc_mode)
return sprintf(buf, "rc\n");
else
return sprintf(buf, "xtal\n");
}
static int abx80x_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct i2c_client *client = to_i2c_client(dev);
int err;
if (enabled)
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_IRQ,
(ABX8XX_IRQ_IM_1_4 |
ABX8XX_IRQ_AIE));
else
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_IRQ,
ABX8XX_IRQ_IM_1_4);
return err;
}
static int abx80x_dt_trickle_cfg(struct device_node *np)
{
const char *diode;
int trickle_cfg = 0;
int i, ret;
u32 tmp;
ret = of_property_read_string(np, "abracon,tc-diode", &diode);
if (ret)
return ret;
if (!strcmp(diode, "standard"))
trickle_cfg |= ABX8XX_TRICKLE_STANDARD_DIODE;
else if (!strcmp(diode, "schottky"))
trickle_cfg |= ABX8XX_TRICKLE_SCHOTTKY_DIODE;
else
return -EINVAL;
ret = of_property_read_u32(np, "abracon,tc-resistor", &tmp);
if (ret)
return ret;
for (i = 0; i < sizeof(trickle_resistors); i++)
if (trickle_resistors[i] == tmp)
break;
if (i == sizeof(trickle_resistors))
return -EINVAL;
return (trickle_cfg | i);
}
static void rtc_calib_remove_sysfs_group(void *_dev)
{
struct device *dev = _dev;
sysfs_remove_group(&dev->kobj, &rtc_calib_attr_group);
}
static int abx80x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node;
struct rtc_device *rtc;
int i, data, err, trickle_cfg = -EINVAL;
char buf[7];
unsigned int part = id->driver_data;
unsigned int partnumber;
unsigned int majrev, minrev;
unsigned int lot;
unsigned int wafer;
unsigned int uid;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
err = i2c_smbus_read_i2c_block_data(client, ABX8XX_REG_ID0,
sizeof(buf), buf);
if (err < 0) {
dev_err(&client->dev, "Unable to read partnumber\n");
return -EIO;
}
partnumber = (buf[0] << 8) | buf[1];
majrev = buf[2] >> 3;
minrev = buf[2] & 0x7;
lot = ((buf[4] & 0x80) << 2) | ((buf[6] & 0x80) << 1) | buf[3];
uid = ((buf[4] & 0x7f) << 8) | buf[5];
wafer = (buf[6] & 0x7c) >> 2;
dev_info(&client->dev, "model %04x, revision %u.%u, lot %x, wafer %x, uid %x\n",
partnumber, majrev, minrev, lot, wafer, uid);
data = i2c_smbus_read_byte_data(client, ABX8XX_REG_CTRL1);
if (data < 0) {
dev_err(&client->dev, "Unable to read control register\n");
return -EIO;
}
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_CTRL1,
((data & ~(ABX8XX_CTRL_12_24 |
ABX8XX_CTRL_ARST)) |
ABX8XX_CTRL_WRITE));
if (err < 0) {
dev_err(&client->dev, "Unable to write control register\n");
return -EIO;
}
if (part == ABX80X) {
for (i = 0; abx80x_caps[i].pn; i++)
if (partnumber == abx80x_caps[i].pn)
break;
if (abx80x_caps[i].pn == 0) {
dev_err(&client->dev, "Unknown part: %04x\n",
partnumber);
return -EINVAL;
}
part = i;
}
if (partnumber != abx80x_caps[part].pn) {
dev_err(&client->dev, "partnumber mismatch %04x != %04x\n",
partnumber, abx80x_caps[part].pn);
return -EINVAL;
}
if (np && abx80x_caps[part].has_tc)
trickle_cfg = abx80x_dt_trickle_cfg(np);
if (trickle_cfg > 0) {
dev_info(&client->dev, "Enabling trickle charger: %02x\n",
trickle_cfg);
abx80x_enable_trickle_charger(client, trickle_cfg);
}
err = i2c_smbus_write_byte_data(client, ABX8XX_REG_CD_TIMER_CTL,
BIT(2));
if (err)
return err;
rtc = devm_rtc_device_register(&client->dev, "abx8xx",
&abx80x_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
i2c_set_clientdata(client, rtc);
if (client->irq > 0) {
dev_info(&client->dev, "IRQ %d supplied\n", client->irq);
err = devm_request_threaded_irq(&client->dev, client->irq, NULL,
abx80x_handle_irq,
IRQF_SHARED | IRQF_ONESHOT,
"abx8xx",
client);
if (err) {
dev_err(&client->dev, "unable to request IRQ, alarms disabled\n");
client->irq = 0;
}
}
err = sysfs_create_group(&(&client->dev)->kobj, &rtc_calib_attr_group);
if (err) {
dev_err(&client->dev, "Failed to create sysfs group: %d\n",
err);
return err;
}
err = devm_add_action(&client->dev, rtc_calib_remove_sysfs_group,
&client->dev);
if (err) {
rtc_calib_remove_sysfs_group(&client->dev);
dev_err(&client->dev,
"Failed to add sysfs cleanup action: %d\n",
err);
return err;
}
return 0;
}
static int abx80x_remove(struct i2c_client *client)
{
return 0;
}
