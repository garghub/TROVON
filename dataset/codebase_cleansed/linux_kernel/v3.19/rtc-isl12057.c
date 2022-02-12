static void isl12057_rtc_regs_to_tm(struct rtc_time *tm, u8 *regs)
{
tm->tm_sec = bcd2bin(regs[ISL12057_REG_RTC_SC]);
tm->tm_min = bcd2bin(regs[ISL12057_REG_RTC_MN]);
if (regs[ISL12057_REG_RTC_HR] & ISL12057_REG_RTC_HR_MIL) {
tm->tm_hour = bcd2bin(regs[ISL12057_REG_RTC_HR] & 0x1f);
if (regs[ISL12057_REG_RTC_HR] & ISL12057_REG_RTC_HR_PM)
tm->tm_hour += 12;
} else {
tm->tm_hour = bcd2bin(regs[ISL12057_REG_RTC_HR] & 0x3f);
}
tm->tm_mday = bcd2bin(regs[ISL12057_REG_RTC_DT]);
tm->tm_wday = bcd2bin(regs[ISL12057_REG_RTC_DW]) - 1;
tm->tm_mon = bcd2bin(regs[ISL12057_REG_RTC_MO] & 0x1f) - 1;
tm->tm_year = bcd2bin(regs[ISL12057_REG_RTC_YR]) + 100;
if (regs[ISL12057_REG_RTC_MO] & ISL12057_REG_RTC_MO_CEN)
tm->tm_year += 100;
}
static int isl12057_rtc_tm_to_regs(u8 *regs, struct rtc_time *tm)
{
u8 century_bit;
if (tm->tm_year < 100 || tm->tm_year > 299)
return -EINVAL;
century_bit = (tm->tm_year > 199) ? ISL12057_REG_RTC_MO_CEN : 0;
regs[ISL12057_REG_RTC_SC] = bin2bcd(tm->tm_sec);
regs[ISL12057_REG_RTC_MN] = bin2bcd(tm->tm_min);
regs[ISL12057_REG_RTC_HR] = bin2bcd(tm->tm_hour);
regs[ISL12057_REG_RTC_DT] = bin2bcd(tm->tm_mday);
regs[ISL12057_REG_RTC_MO] = bin2bcd(tm->tm_mon + 1) | century_bit;
regs[ISL12057_REG_RTC_YR] = bin2bcd(tm->tm_year % 100);
regs[ISL12057_REG_RTC_DW] = bin2bcd(tm->tm_wday + 1);
return 0;
}
static int isl12057_i2c_validate_chip(struct regmap *regmap)
{
u8 regs[ISL12057_MEM_MAP_LEN];
static const u8 mask[ISL12057_MEM_MAP_LEN] = { 0x80, 0x80, 0x80, 0xf8,
0xc0, 0x60, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x60, 0x7c };
int ret, i;
ret = regmap_bulk_read(regmap, 0, regs, ISL12057_MEM_MAP_LEN);
if (ret)
return ret;
for (i = 0; i < ISL12057_MEM_MAP_LEN; ++i) {
if (regs[i] & mask[i])
return -ENODEV;
}
return 0;
}
static int isl12057_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
u8 regs[ISL12057_RTC_SEC_LEN];
unsigned int sr;
int ret;
mutex_lock(&data->lock);
ret = regmap_read(data->regmap, ISL12057_REG_SR, &sr);
if (ret) {
dev_err(dev, "%s: unable to read oscillator status flag (%d)\n",
__func__, ret);
goto out;
} else {
if (sr & ISL12057_REG_SR_OSF) {
ret = -ENODATA;
goto out;
}
}
ret = regmap_bulk_read(data->regmap, ISL12057_REG_RTC_SC, regs,
ISL12057_RTC_SEC_LEN);
if (ret)
dev_err(dev, "%s: unable to read RTC time section (%d)\n",
__func__, ret);
out:
mutex_unlock(&data->lock);
if (ret)
return ret;
isl12057_rtc_regs_to_tm(tm, regs);
return rtc_valid_tm(tm);
}
static int isl12057_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct isl12057_rtc_data *data = dev_get_drvdata(dev);
u8 regs[ISL12057_RTC_SEC_LEN];
int ret;
ret = isl12057_rtc_tm_to_regs(regs, tm);
if (ret)
return ret;
mutex_lock(&data->lock);
ret = regmap_bulk_write(data->regmap, ISL12057_REG_RTC_SC, regs,
ISL12057_RTC_SEC_LEN);
if (ret) {
dev_err(dev, "%s: unable to write RTC time section (%d)\n",
__func__, ret);
goto out;
}
ret = regmap_update_bits(data->regmap, ISL12057_REG_SR,
ISL12057_REG_SR_OSF, 0);
if (ret < 0)
dev_err(dev, "%s: unable to clear osc. failure bit (%d)\n",
__func__, ret);
out:
mutex_unlock(&data->lock);
return ret;
}
static int isl12057_check_rtc_status(struct device *dev, struct regmap *regmap)
{
int ret;
ret = regmap_update_bits(regmap, ISL12057_REG_INT,
ISL12057_REG_INT_EOSC, 0);
if (ret < 0) {
dev_err(dev, "%s: unable to enable oscillator (%d)\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(regmap, ISL12057_REG_SR,
ISL12057_REG_SR_A1F, 0);
if (ret < 0) {
dev_err(dev, "%s: unable to clear alarm bit (%d)\n",
__func__, ret);
return ret;
}
return 0;
}
static int isl12057_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct isl12057_rtc_data *data;
struct rtc_device *rtc;
struct regmap *regmap;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK))
return -ENODEV;
regmap = devm_regmap_init_i2c(client, &isl12057_rtc_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(dev, "%s: regmap allocation failed (%d)\n",
__func__, ret);
return ret;
}
ret = isl12057_i2c_validate_chip(regmap);
if (ret)
return ret;
ret = isl12057_check_rtc_status(dev, regmap);
if (ret)
return ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->lock);
data->regmap = regmap;
dev_set_drvdata(dev, data);
rtc = devm_rtc_device_register(dev, DRV_NAME, &rtc_ops, THIS_MODULE);
return PTR_ERR_OR_ZERO(rtc);
}
