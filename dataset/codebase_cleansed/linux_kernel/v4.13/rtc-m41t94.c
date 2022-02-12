static int m41t94_set_time(struct device *dev, struct rtc_time *tm)
{
struct spi_device *spi = to_spi_device(dev);
u8 buf[8];
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"write", tm->tm_sec, tm->tm_min,
tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
buf[0] = 0x80 | M41T94_REG_SECONDS;
buf[M41T94_REG_SECONDS] = bin2bcd(tm->tm_sec);
buf[M41T94_REG_MINUTES] = bin2bcd(tm->tm_min);
buf[M41T94_REG_HOURS] = bin2bcd(tm->tm_hour);
buf[M41T94_REG_WDAY] = bin2bcd(tm->tm_wday + 1);
buf[M41T94_REG_DAY] = bin2bcd(tm->tm_mday);
buf[M41T94_REG_MONTH] = bin2bcd(tm->tm_mon + 1);
buf[M41T94_REG_HOURS] |= M41T94_BIT_CEB;
if (tm->tm_year >= 100)
buf[M41T94_REG_HOURS] |= M41T94_BIT_CB;
buf[M41T94_REG_YEAR] = bin2bcd(tm->tm_year % 100);
return spi_write(spi, buf, 8);
}
static int m41t94_read_time(struct device *dev, struct rtc_time *tm)
{
struct spi_device *spi = to_spi_device(dev);
u8 buf[2];
int ret, hour;
ret = spi_w8r8(spi, M41T94_REG_HT);
if (ret < 0)
return ret;
if (ret & M41T94_BIT_HALT) {
buf[0] = 0x80 | M41T94_REG_HT;
buf[1] = ret & ~M41T94_BIT_HALT;
spi_write(spi, buf, 2);
}
ret = spi_w8r8(spi, M41T94_REG_SECONDS);
if (ret < 0)
return ret;
if (ret & M41T94_BIT_STOP) {
buf[0] = 0x80 | M41T94_REG_SECONDS;
buf[1] = ret & ~M41T94_BIT_STOP;
spi_write(spi, buf, 2);
}
tm->tm_sec = bcd2bin(spi_w8r8(spi, M41T94_REG_SECONDS));
tm->tm_min = bcd2bin(spi_w8r8(spi, M41T94_REG_MINUTES));
hour = spi_w8r8(spi, M41T94_REG_HOURS);
tm->tm_hour = bcd2bin(hour & 0x3f);
tm->tm_wday = bcd2bin(spi_w8r8(spi, M41T94_REG_WDAY)) - 1;
tm->tm_mday = bcd2bin(spi_w8r8(spi, M41T94_REG_DAY));
tm->tm_mon = bcd2bin(spi_w8r8(spi, M41T94_REG_MONTH)) - 1;
tm->tm_year = bcd2bin(spi_w8r8(spi, M41T94_REG_YEAR));
if ((hour & M41T94_BIT_CB) || !(hour & M41T94_BIT_CEB))
tm->tm_year += 100;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"read", tm->tm_sec, tm->tm_min,
tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
return rtc_valid_tm(tm);
}
static int m41t94_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
int res;
spi->bits_per_word = 8;
spi_setup(spi);
res = spi_w8r8(spi, M41T94_REG_SECONDS);
if (res < 0) {
dev_err(&spi->dev, "not found.\n");
return res;
}
rtc = devm_rtc_device_register(&spi->dev, m41t94_driver.driver.name,
&m41t94_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
spi_set_drvdata(spi, rtc);
return 0;
}
