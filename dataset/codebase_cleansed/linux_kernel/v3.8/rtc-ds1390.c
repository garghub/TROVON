static int ds1390_get_reg(struct device *dev, unsigned char address,
unsigned char *data)
{
struct spi_device *spi = to_spi_device(dev);
struct ds1390 *chip = dev_get_drvdata(dev);
int status;
if (!data)
return -EINVAL;
chip->txrx_buf[0] = address & 0x7f;
status = spi_write_then_read(spi, chip->txrx_buf, 1, chip->txrx_buf, 1);
if (status != 0)
return status;
*data = chip->txrx_buf[1];
return 0;
}
static int ds1390_read_time(struct device *dev, struct rtc_time *dt)
{
struct spi_device *spi = to_spi_device(dev);
struct ds1390 *chip = dev_get_drvdata(dev);
int status;
chip->txrx_buf[0] = DS1390_REG_SECONDS;
status = spi_write_then_read(spi, chip->txrx_buf, 1, chip->txrx_buf, 8);
if (status != 0)
return status;
dt->tm_sec = bcd2bin(chip->txrx_buf[0]);
dt->tm_min = bcd2bin(chip->txrx_buf[1]);
dt->tm_hour = bcd2bin(chip->txrx_buf[2]);
dt->tm_wday = bcd2bin(chip->txrx_buf[3]);
dt->tm_mday = bcd2bin(chip->txrx_buf[4]);
dt->tm_mon = bcd2bin(chip->txrx_buf[5] & 0x7f) - 1;
dt->tm_year = bcd2bin(chip->txrx_buf[6]) + ((chip->txrx_buf[5] & 0x80) ? 100 : 0);
return rtc_valid_tm(dt);
}
static int ds1390_set_time(struct device *dev, struct rtc_time *dt)
{
struct spi_device *spi = to_spi_device(dev);
struct ds1390 *chip = dev_get_drvdata(dev);
chip->txrx_buf[0] = DS1390_REG_SECONDS | 0x80;
chip->txrx_buf[1] = bin2bcd(dt->tm_sec);
chip->txrx_buf[2] = bin2bcd(dt->tm_min);
chip->txrx_buf[3] = bin2bcd(dt->tm_hour);
chip->txrx_buf[4] = bin2bcd(dt->tm_wday);
chip->txrx_buf[5] = bin2bcd(dt->tm_mday);
chip->txrx_buf[6] = bin2bcd(dt->tm_mon + 1) |
((dt->tm_year > 99) ? 0x80 : 0x00);
chip->txrx_buf[7] = bin2bcd(dt->tm_year % 100);
return spi_write_then_read(spi, chip->txrx_buf, 8, NULL, 0);
}
static int ds1390_probe(struct spi_device *spi)
{
unsigned char tmp;
struct ds1390 *chip;
int res;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
chip = kzalloc(sizeof *chip, GFP_KERNEL);
if (!chip) {
dev_err(&spi->dev, "unable to allocate device memory\n");
return -ENOMEM;
}
dev_set_drvdata(&spi->dev, chip);
res = ds1390_get_reg(&spi->dev, DS1390_REG_SECONDS, &tmp);
if (res != 0) {
dev_err(&spi->dev, "unable to read device\n");
kfree(chip);
return res;
}
chip->rtc = rtc_device_register("ds1390",
&spi->dev, &ds1390_rtc_ops, THIS_MODULE);
if (IS_ERR(chip->rtc)) {
dev_err(&spi->dev, "unable to register device\n");
res = PTR_ERR(chip->rtc);
kfree(chip);
}
return res;
}
static int ds1390_remove(struct spi_device *spi)
{
struct ds1390 *chip = spi_get_drvdata(spi);
rtc_device_unregister(chip->rtc);
kfree(chip);
return 0;
}
