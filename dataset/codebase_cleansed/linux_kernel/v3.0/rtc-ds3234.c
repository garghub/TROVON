static int ds3234_set_reg(struct device *dev, unsigned char address,
unsigned char data)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[2];
buf[0] = address | 0x80;
buf[1] = data;
return spi_write_then_read(spi, buf, 2, NULL, 0);
}
static int ds3234_get_reg(struct device *dev, unsigned char address,
unsigned char *data)
{
struct spi_device *spi = to_spi_device(dev);
*data = address & 0x7f;
return spi_write_then_read(spi, data, 1, data, 1);
}
static int ds3234_read_time(struct device *dev, struct rtc_time *dt)
{
int err;
unsigned char buf[8];
struct spi_device *spi = to_spi_device(dev);
buf[0] = 0x00;
err = spi_write_then_read(spi, buf, 1, buf, 8);
if (err != 0)
return err;
dt->tm_sec = bcd2bin(buf[0]);
dt->tm_min = bcd2bin(buf[1]);
dt->tm_hour = bcd2bin(buf[2] & 0x3f);
dt->tm_wday = bcd2bin(buf[3]) - 1;
dt->tm_mday = bcd2bin(buf[4]);
dt->tm_mon = bcd2bin(buf[5] & 0x1f) - 1;
dt->tm_year = bcd2bin(buf[6] & 0xff) + 100;
return rtc_valid_tm(dt);
}
static int ds3234_set_time(struct device *dev, struct rtc_time *dt)
{
ds3234_set_reg(dev, DS3234_REG_SECONDS, bin2bcd(dt->tm_sec));
ds3234_set_reg(dev, DS3234_REG_MINUTES, bin2bcd(dt->tm_min));
ds3234_set_reg(dev, DS3234_REG_HOURS, bin2bcd(dt->tm_hour) & 0x3f);
ds3234_set_reg(dev, DS3234_REG_DAY, bin2bcd(dt->tm_wday + 1));
ds3234_set_reg(dev, DS3234_REG_DATE, bin2bcd(dt->tm_mday));
ds3234_set_reg(dev, DS3234_REG_MONTH, bin2bcd(dt->tm_mon + 1));
if (dt->tm_year > 100)
dt->tm_year -= 100;
ds3234_set_reg(dev, DS3234_REG_YEAR, bin2bcd(dt->tm_year));
return 0;
}
static int __devinit ds3234_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
unsigned char tmp;
int res;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
res = ds3234_get_reg(&spi->dev, DS3234_REG_SECONDS, &tmp);
if (res != 0)
return res;
ds3234_get_reg(&spi->dev, DS3234_REG_CONTROL, &tmp);
ds3234_set_reg(&spi->dev, DS3234_REG_CONTROL, tmp & 0x1c);
ds3234_get_reg(&spi->dev, DS3234_REG_CONT_STAT, &tmp);
ds3234_set_reg(&spi->dev, DS3234_REG_CONT_STAT, tmp & 0x88);
ds3234_get_reg(&spi->dev, DS3234_REG_CONTROL, &tmp);
dev_info(&spi->dev, "Control Reg: 0x%02x\n", tmp);
ds3234_get_reg(&spi->dev, DS3234_REG_CONT_STAT, &tmp);
dev_info(&spi->dev, "Ctrl/Stat Reg: 0x%02x\n", tmp);
rtc = rtc_device_register("ds3234",
&spi->dev, &ds3234_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
dev_set_drvdata(&spi->dev, rtc);
return 0;
}
static int __devexit ds3234_remove(struct spi_device *spi)
{
struct rtc_device *rtc = spi_get_drvdata(spi);
rtc_device_unregister(rtc);
return 0;
}
static __init int ds3234_init(void)
{
return spi_register_driver(&ds3234_driver);
}
static __exit void ds3234_exit(void)
{
spi_unregister_driver(&ds3234_driver);
}
