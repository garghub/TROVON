static inline int m41t93_set_reg(struct spi_device *spi, u8 addr, u8 data)
{
u8 buf[2];
buf[0] = addr | 0x80;
buf[1] = data;
return spi_write(spi, buf, sizeof(buf));
}
static int m41t93_set_time(struct device *dev, struct rtc_time *tm)
{
struct spi_device *spi = to_spi_device(dev);
u8 buf[9] = {0x80};
u8 * const data = &buf[1];
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"write", tm->tm_sec, tm->tm_min,
tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
if (tm->tm_year < 100) {
dev_warn(&spi->dev, "unsupported date (before 2000-01-01).\n");
return -EINVAL;
}
data[M41T93_REG_SSEC] = 0;
data[M41T93_REG_ST_SEC] = bin2bcd(tm->tm_sec);
data[M41T93_REG_MIN] = bin2bcd(tm->tm_min);
data[M41T93_REG_CENT_HOUR] = bin2bcd(tm->tm_hour) |
((tm->tm_year/100-1) << 6);
data[M41T93_REG_DAY] = bin2bcd(tm->tm_mday);
data[M41T93_REG_WDAY] = bin2bcd(tm->tm_wday + 1);
data[M41T93_REG_MON] = bin2bcd(tm->tm_mon + 1);
data[M41T93_REG_YEAR] = bin2bcd(tm->tm_year % 100);
return spi_write(spi, buf, sizeof(buf));
}
static int m41t93_get_time(struct device *dev, struct rtc_time *tm)
{
struct spi_device *spi = to_spi_device(dev);
const u8 start_addr = 0;
u8 buf[8];
int century_after_1900;
int tmp;
int ret = 0;
tmp = spi_w8r8(spi, M41T93_REG_ALM_HOUR_HT);
if (tmp < 0)
return tmp;
if (tmp & M41T93_FLAG_HT) {
dev_dbg(&spi->dev, "HT bit is set, reenable clock update.\n");
m41t93_set_reg(spi, M41T93_REG_ALM_HOUR_HT,
tmp & ~M41T93_FLAG_HT);
}
tmp = spi_w8r8(spi, M41T93_REG_FLAGS);
if (tmp < 0)
return tmp;
if (tmp & M41T93_FLAG_OF) {
ret = -EINVAL;
dev_warn(&spi->dev, "OF bit is set, resetting.\n");
m41t93_set_reg(spi, M41T93_REG_FLAGS, tmp & ~M41T93_FLAG_OF);
tmp = spi_w8r8(spi, M41T93_REG_FLAGS);
if (tmp < 0)
return tmp;
else if (tmp & M41T93_FLAG_OF) {
u8 reset_osc = buf[M41T93_REG_ST_SEC] | M41T93_FLAG_ST;
dev_warn(&spi->dev,
"OF bit is still set, kickstarting clock.\n");
m41t93_set_reg(spi, M41T93_REG_ST_SEC, reset_osc);
reset_osc &= ~M41T93_FLAG_ST;
m41t93_set_reg(spi, M41T93_REG_ST_SEC, reset_osc);
}
}
if (tmp & M41T93_FLAG_BL)
dev_warn(&spi->dev, "BL bit is set, replace battery.\n");
tmp = spi_write_then_read(spi, &start_addr, 1, buf, sizeof(buf));
if (tmp < 0)
return tmp;
tm->tm_sec = bcd2bin(buf[M41T93_REG_ST_SEC]);
tm->tm_min = bcd2bin(buf[M41T93_REG_MIN]);
tm->tm_hour = bcd2bin(buf[M41T93_REG_CENT_HOUR] & 0x3f);
tm->tm_mday = bcd2bin(buf[M41T93_REG_DAY]);
tm->tm_mon = bcd2bin(buf[M41T93_REG_MON]) - 1;
tm->tm_wday = bcd2bin(buf[M41T93_REG_WDAY] & 0x0f) - 1;
century_after_1900 = (buf[M41T93_REG_CENT_HOUR] >> 6) + 1;
tm->tm_year = bcd2bin(buf[M41T93_REG_YEAR]) + century_after_1900 * 100;
dev_dbg(dev, "%s secs=%d, mins=%d, "
"hours=%d, mday=%d, mon=%d, year=%d, wday=%d\n",
"read", tm->tm_sec, tm->tm_min,
tm->tm_hour, tm->tm_mday,
tm->tm_mon, tm->tm_year, tm->tm_wday);
return ret < 0 ? ret : rtc_valid_tm(tm);
}
static int __devinit m41t93_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
int res;
spi->bits_per_word = 8;
spi_setup(spi);
res = spi_w8r8(spi, M41T93_REG_WDAY);
if (res < 0 || (res & 0xf8) != 0) {
dev_err(&spi->dev, "not found 0x%x.\n", res);
return -ENODEV;
}
rtc = rtc_device_register(m41t93_driver.driver.name,
&spi->dev, &m41t93_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
dev_set_drvdata(&spi->dev, rtc);
return 0;
}
static int __devexit m41t93_remove(struct spi_device *spi)
{
struct rtc_device *rtc = spi_get_drvdata(spi);
if (rtc)
rtc_device_unregister(rtc);
return 0;
}
static __init int m41t93_init(void)
{
return spi_register_driver(&m41t93_driver);
}
static __exit void m41t93_exit(void)
{
spi_unregister_driver(&m41t93_driver);
}
