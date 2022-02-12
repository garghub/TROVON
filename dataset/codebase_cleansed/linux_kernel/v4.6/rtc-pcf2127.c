static int pcf2127_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct pcf2127 *pcf2127 = dev_get_drvdata(dev);
unsigned char buf[10];
int ret;
ret = regmap_bulk_read(pcf2127->regmap, PCF2127_REG_CTRL1, buf,
sizeof(buf));
if (ret) {
dev_err(dev, "%s: read error\n", __func__);
return ret;
}
if (buf[PCF2127_REG_CTRL3] & PCF2127_REG_CTRL3_BLF)
dev_info(dev,
"low voltage detected, check/replace RTC battery.\n");
if (buf[PCF2127_REG_SC] & PCF2127_OSF) {
dev_warn(dev,
"oscillator stop detected, date/time is not reliable\n");
return -EINVAL;
}
dev_dbg(dev,
"%s: raw data is cr1=%02x, cr2=%02x, cr3=%02x, "
"sec=%02x, min=%02x, hr=%02x, "
"mday=%02x, wday=%02x, mon=%02x, year=%02x\n",
__func__,
buf[0], buf[1], buf[2],
buf[3], buf[4], buf[5],
buf[6], buf[7], buf[8], buf[9]);
tm->tm_sec = bcd2bin(buf[PCF2127_REG_SC] & 0x7F);
tm->tm_min = bcd2bin(buf[PCF2127_REG_MN] & 0x7F);
tm->tm_hour = bcd2bin(buf[PCF2127_REG_HR] & 0x3F);
tm->tm_mday = bcd2bin(buf[PCF2127_REG_DM] & 0x3F);
tm->tm_wday = buf[PCF2127_REG_DW] & 0x07;
tm->tm_mon = bcd2bin(buf[PCF2127_REG_MO] & 0x1F) - 1;
tm->tm_year = bcd2bin(buf[PCF2127_REG_YR]);
if (tm->tm_year < 70)
tm->tm_year += 100;
dev_dbg(dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
return rtc_valid_tm(tm);
}
static int pcf2127_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct pcf2127 *pcf2127 = dev_get_drvdata(dev);
unsigned char buf[7];
int i = 0, err;
dev_dbg(dev, "%s: secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_wday);
buf[i++] = bin2bcd(tm->tm_sec);
buf[i++] = bin2bcd(tm->tm_min);
buf[i++] = bin2bcd(tm->tm_hour);
buf[i++] = bin2bcd(tm->tm_mday);
buf[i++] = tm->tm_wday & 0x07;
buf[i++] = bin2bcd(tm->tm_mon + 1);
buf[i++] = bin2bcd(tm->tm_year % 100);
err = regmap_bulk_write(pcf2127->regmap, PCF2127_REG_SC, buf, i);
if (err) {
dev_err(dev,
"%s: err=%d", __func__, err);
return err;
}
return 0;
}
static int pcf2127_rtc_ioctl(struct device *dev,
unsigned int cmd, unsigned long arg)
{
struct pcf2127 *pcf2127 = dev_get_drvdata(dev);
int touser;
int ret;
switch (cmd) {
case RTC_VL_READ:
ret = regmap_read(pcf2127->regmap, PCF2127_REG_CTRL3, &touser);
if (ret)
return ret;
touser = touser & PCF2127_REG_CTRL3_BLF ? 1 : 0;
if (copy_to_user((void __user *)arg, &touser, sizeof(int)))
return -EFAULT;
return 0;
default:
return -ENOIOCTLCMD;
}
}
static int pcf2127_probe(struct device *dev, struct regmap *regmap,
const char *name)
{
struct pcf2127 *pcf2127;
dev_dbg(dev, "%s\n", __func__);
pcf2127 = devm_kzalloc(dev, sizeof(*pcf2127), GFP_KERNEL);
if (!pcf2127)
return -ENOMEM;
pcf2127->regmap = regmap;
dev_set_drvdata(dev, pcf2127);
pcf2127->rtc = devm_rtc_device_register(dev, name, &pcf2127_rtc_ops,
THIS_MODULE);
return PTR_ERR_OR_ZERO(pcf2127->rtc);
}
static int pcf2127_i2c_write(void *context, const void *data, size_t count)
{
struct device *dev = context;
struct i2c_client *client = to_i2c_client(dev);
int ret;
ret = i2c_master_send(client, data, count);
if (ret != count)
return ret < 0 ? ret : -EIO;
return 0;
}
static int pcf2127_i2c_gather_write(void *context,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
struct device *dev = context;
struct i2c_client *client = to_i2c_client(dev);
int ret;
void *buf;
if (WARN_ON(reg_size != 1))
return -EINVAL;
buf = kmalloc(val_size + 1, GFP_KERNEL);
if (!buf)
return -ENOMEM;
memcpy(buf, reg, 1);
memcpy(buf + 1, val, val_size);
ret = i2c_master_send(client, buf, val_size + 1);
if (ret != val_size + 1)
return ret < 0 ? ret : -EIO;
return 0;
}
static int pcf2127_i2c_read(void *context, const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct device *dev = context;
struct i2c_client *client = to_i2c_client(dev);
int ret;
if (WARN_ON(reg_size != 1))
return -EINVAL;
ret = i2c_master_send(client, reg, 1);
if (ret != 1)
return ret < 0 ? ret : -EIO;
ret = i2c_master_recv(client, val, val_size);
if (ret != val_size)
return ret < 0 ? ret : -EIO;
return 0;
}
static int pcf2127_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
static const struct regmap_config config = {
.reg_bits = 8,
.val_bits = 8,
};
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
regmap = devm_regmap_init(&client->dev, &pcf2127_i2c_regmap,
&client->dev, &config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "%s: regmap allocation failed: %ld\n",
__func__, PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return pcf2127_probe(&client->dev, regmap,
pcf2127_i2c_driver.driver.name);
}
static int pcf2127_i2c_register_driver(void)
{
return i2c_add_driver(&pcf2127_i2c_driver);
}
static void pcf2127_i2c_unregister_driver(void)
{
i2c_del_driver(&pcf2127_i2c_driver);
}
static int pcf2127_i2c_register_driver(void)
{
return 0;
}
static void pcf2127_i2c_unregister_driver(void)
{
}
static int pcf2127_spi_probe(struct spi_device *spi)
{
static const struct regmap_config config = {
.reg_bits = 8,
.val_bits = 8,
.read_flag_mask = 0xa0,
.write_flag_mask = 0x20,
};
struct regmap *regmap;
regmap = devm_regmap_init_spi(spi, &config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "%s: regmap allocation failed: %ld\n",
__func__, PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return pcf2127_probe(&spi->dev, regmap, pcf2127_spi_driver.driver.name);
}
static int pcf2127_spi_register_driver(void)
{
return spi_register_driver(&pcf2127_spi_driver);
}
static void pcf2127_spi_unregister_driver(void)
{
spi_unregister_driver(&pcf2127_spi_driver);
}
static int pcf2127_spi_register_driver(void)
{
return 0;
}
static void pcf2127_spi_unregister_driver(void)
{
}
static int __init pcf2127_init(void)
{
int ret;
ret = pcf2127_i2c_register_driver();
if (ret) {
pr_err("Failed to register pcf2127 i2c driver: %d\n", ret);
return ret;
}
ret = pcf2127_spi_register_driver();
if (ret) {
pr_err("Failed to register pcf2127 spi driver: %d\n", ret);
pcf2127_i2c_unregister_driver();
}
return ret;
}
static void __exit pcf2127_exit(void)
{
pcf2127_spi_unregister_driver();
pcf2127_i2c_unregister_driver();
}
