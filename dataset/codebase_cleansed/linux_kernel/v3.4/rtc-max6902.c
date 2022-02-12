static int max6902_set_reg(struct device *dev, unsigned char address,
unsigned char data)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[2];
buf[0] = address & 0x7f;
buf[1] = data;
return spi_write_then_read(spi, buf, 2, NULL, 0);
}
static int max6902_get_reg(struct device *dev, unsigned char address,
unsigned char *data)
{
struct spi_device *spi = to_spi_device(dev);
*data = address | 0x80;
return spi_write_then_read(spi, data, 1, data, 1);
}
static int max6902_read_time(struct device *dev, struct rtc_time *dt)
{
int err, century;
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[8];
buf[0] = 0xbf;
err = spi_write_then_read(spi, buf, 1, buf, 8);
if (err != 0)
return err;
dt->tm_sec = bcd2bin(buf[0]);
dt->tm_min = bcd2bin(buf[1]);
dt->tm_hour = bcd2bin(buf[2]);
dt->tm_mday = bcd2bin(buf[3]);
dt->tm_mon = bcd2bin(buf[4]) - 1;
dt->tm_wday = bcd2bin(buf[5]);
dt->tm_year = bcd2bin(buf[6]);
err = max6902_get_reg(dev, MAX6902_REG_CENTURY, &buf[0]);
if (err != 0)
return err;
century = bcd2bin(buf[0]) * 100;
dt->tm_year += century;
dt->tm_year -= 1900;
return rtc_valid_tm(dt);
}
static int max6902_set_time(struct device *dev, struct rtc_time *dt)
{
dt->tm_year = dt->tm_year + 1900;
max6902_set_reg(dev, 0xF, 0);
max6902_set_reg(dev, 0x01, bin2bcd(dt->tm_sec));
max6902_set_reg(dev, 0x03, bin2bcd(dt->tm_min));
max6902_set_reg(dev, 0x05, bin2bcd(dt->tm_hour));
max6902_set_reg(dev, 0x07, bin2bcd(dt->tm_mday));
max6902_set_reg(dev, 0x09, bin2bcd(dt->tm_mon + 1));
max6902_set_reg(dev, 0x0B, bin2bcd(dt->tm_wday));
max6902_set_reg(dev, 0x0D, bin2bcd(dt->tm_year % 100));
max6902_set_reg(dev, 0x13, bin2bcd(dt->tm_year / 100));
max6902_set_reg(dev, 0xF, 0x80);
return 0;
}
static int __devinit max6902_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
unsigned char tmp;
int res;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
res = max6902_get_reg(&spi->dev, MAX6902_REG_SECONDS, &tmp);
if (res != 0)
return res;
rtc = rtc_device_register("max6902",
&spi->dev, &max6902_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
dev_set_drvdata(&spi->dev, rtc);
return 0;
}
static int __devexit max6902_remove(struct spi_device *spi)
{
struct rtc_device *rtc = dev_get_drvdata(&spi->dev);
rtc_device_unregister(rtc);
return 0;
}
