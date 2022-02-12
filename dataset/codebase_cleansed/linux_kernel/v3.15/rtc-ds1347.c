static int ds1347_read_reg(struct device *dev, unsigned char address,
unsigned char *data)
{
struct spi_device *spi = to_spi_device(dev);
*data = address | 0x80;
return spi_write_then_read(spi, data, 1, data, 1);
}
static int ds1347_write_reg(struct device *dev, unsigned char address,
unsigned char data)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[2];
buf[0] = address & 0x7F;
buf[1] = data;
return spi_write_then_read(spi, buf, 2, NULL, 0);
}
static int ds1347_read_time(struct device *dev, struct rtc_time *dt)
{
struct spi_device *spi = to_spi_device(dev);
int err;
unsigned char buf[8];
buf[0] = DS1347_CLOCK_BURST | 0x80;
err = spi_write_then_read(spi, buf, 1, buf, 8);
if (err)
return err;
dt->tm_sec = bcd2bin(buf[0]);
dt->tm_min = bcd2bin(buf[1]);
dt->tm_hour = bcd2bin(buf[2] & 0x3F);
dt->tm_mday = bcd2bin(buf[3]);
dt->tm_mon = bcd2bin(buf[4]) - 1;
dt->tm_wday = bcd2bin(buf[5]) - 1;
dt->tm_year = bcd2bin(buf[6]) + 100;
return rtc_valid_tm(dt);
}
static int ds1347_set_time(struct device *dev, struct rtc_time *dt)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[9];
buf[0] = DS1347_CLOCK_BURST & 0x7F;
buf[1] = bin2bcd(dt->tm_sec);
buf[2] = bin2bcd(dt->tm_min);
buf[3] = (bin2bcd(dt->tm_hour) & 0x3F);
buf[4] = bin2bcd(dt->tm_mday);
buf[5] = bin2bcd(dt->tm_mon + 1);
buf[6] = bin2bcd(dt->tm_wday + 1);
dt->tm_year = dt->tm_year % 100;
buf[7] = bin2bcd(dt->tm_year);
buf[8] = bin2bcd(0x00);
return spi_write_then_read(spi, buf, 9, NULL, 0);
}
static int ds1347_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
unsigned char data;
int res;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
res = ds1347_read_reg(&spi->dev, DS1347_SECONDS_REG, &data);
if (res)
return res;
ds1347_read_reg(&spi->dev, DS1347_CONTROL_REG, &data);
data = data & ~(1<<7);
ds1347_write_reg(&spi->dev, DS1347_CONTROL_REG, data);
ds1347_read_reg(&spi->dev, DS1347_STATUS_REG, &data);
data = data & 0x1B;
ds1347_write_reg(&spi->dev, DS1347_STATUS_REG, data);
ds1347_read_reg(&spi->dev, DS1347_CONTROL_REG, &data);
dev_info(&spi->dev, "DS1347 RTC CTRL Reg = 0x%02x\n", data);
ds1347_read_reg(&spi->dev, DS1347_STATUS_REG, &data);
dev_info(&spi->dev, "DS1347 RTC Status Reg = 0x%02x\n", data);
rtc = devm_rtc_device_register(&spi->dev, "ds1347",
&ds1347_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
spi_set_drvdata(spi, rtc);
return 0;
}
