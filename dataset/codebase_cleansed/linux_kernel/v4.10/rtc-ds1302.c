static int ds1302_rtc_set_time(struct device *dev, struct rtc_time *time)
{
struct spi_device *spi = dev_get_drvdata(dev);
u8 buf[1 + RTC_CLCK_LEN];
u8 *bp = buf;
int status;
bp = buf;
*bp++ = RTC_ADDR_CTRL << 1 | RTC_CMD_WRITE;
*bp++ = RTC_CMD_WRITE_ENABLE;
status = spi_write_then_read(spi, buf, 2,
NULL, 0);
if (status)
return status;
bp = buf;
*bp++ = RTC_CLCK_BURST << 1 | RTC_CMD_WRITE;
*bp++ = bin2bcd(time->tm_sec);
*bp++ = bin2bcd(time->tm_min);
*bp++ = bin2bcd(time->tm_hour);
*bp++ = bin2bcd(time->tm_mday);
*bp++ = bin2bcd(time->tm_mon + 1);
*bp++ = time->tm_wday + 1;
*bp++ = bin2bcd(time->tm_year % 100);
*bp++ = RTC_CMD_WRITE_DISABLE;
return spi_write_then_read(spi, buf, sizeof(buf),
NULL, 0);
}
static int ds1302_rtc_get_time(struct device *dev, struct rtc_time *time)
{
struct spi_device *spi = dev_get_drvdata(dev);
u8 addr = RTC_CLCK_BURST << 1 | RTC_CMD_READ;
u8 buf[RTC_CLCK_LEN - 1];
int status;
status = spi_write_then_read(spi, &addr, sizeof(addr),
buf, sizeof(buf));
if (status < 0)
return status;
time->tm_sec = bcd2bin(buf[RTC_ADDR_SEC]);
time->tm_min = bcd2bin(buf[RTC_ADDR_MIN]);
time->tm_hour = bcd2bin(buf[RTC_ADDR_HOUR]);
time->tm_wday = buf[RTC_ADDR_DAY] - 1;
time->tm_mday = bcd2bin(buf[RTC_ADDR_DATE]);
time->tm_mon = bcd2bin(buf[RTC_ADDR_MON]) - 1;
time->tm_year = bcd2bin(buf[RTC_ADDR_YEAR]) + 100;
return rtc_valid_tm(time);
}
static int ds1302_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
u8 addr;
u8 buf[4];
u8 *bp = buf;
int status;
if (spi->bits_per_word && (spi->bits_per_word != 8)) {
dev_err(&spi->dev, "bad word length\n");
return -EINVAL;
} else if (spi->max_speed_hz > 2000000) {
dev_err(&spi->dev, "speed is too high\n");
return -EINVAL;
} else if (spi->mode & SPI_CPHA) {
dev_err(&spi->dev, "bad mode\n");
return -EINVAL;
}
addr = RTC_ADDR_CTRL << 1 | RTC_CMD_READ;
status = spi_write_then_read(spi, &addr, sizeof(addr), buf, 1);
if (status < 0) {
dev_err(&spi->dev, "control register read error %d\n",
status);
return status;
}
if ((buf[0] & ~RTC_CMD_WRITE_DISABLE) != 0) {
status = spi_write_then_read(spi, &addr, sizeof(addr), buf, 1);
if (status < 0) {
dev_err(&spi->dev, "control register read error %d\n",
status);
return status;
}
if ((buf[0] & ~RTC_CMD_WRITE_DISABLE) != 0) {
dev_err(&spi->dev, "junk in control register\n");
return -ENODEV;
}
}
if (buf[0] == 0) {
bp = buf;
*bp++ = RTC_ADDR_CTRL << 1 | RTC_CMD_WRITE;
*bp++ = RTC_CMD_WRITE_DISABLE;
status = spi_write_then_read(spi, buf, 2, NULL, 0);
if (status < 0) {
dev_err(&spi->dev, "control register write error %d\n",
status);
return status;
}
addr = RTC_ADDR_CTRL << 1 | RTC_CMD_READ;
status = spi_write_then_read(spi, &addr, sizeof(addr), buf, 1);
if (status < 0) {
dev_err(&spi->dev,
"error %d reading control register\n",
status);
return status;
}
if (buf[0] != RTC_CMD_WRITE_DISABLE) {
dev_err(&spi->dev, "failed to detect chip\n");
return -ENODEV;
}
}
spi_set_drvdata(spi, spi);
rtc = devm_rtc_device_register(&spi->dev, "ds1302",
&ds1302_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
status = PTR_ERR(rtc);
dev_err(&spi->dev, "error %d registering rtc\n", status);
return status;
}
return 0;
}
static int ds1302_remove(struct spi_device *spi)
{
spi_set_drvdata(spi, NULL);
return 0;
}
