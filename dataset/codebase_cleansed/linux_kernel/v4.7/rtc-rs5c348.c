static int
rs5c348_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct spi_device *spi = to_spi_device(dev);
struct rs5c348_plat_data *pdata = dev_get_platdata(&spi->dev);
u8 txbuf[5+7], *txp;
int ret;
txp = txbuf;
txbuf[0] = RS5C348_CMD_R(RS5C348_REG_CTL2);
txbuf[1] = 0;
txbuf[2] = RS5C348_CMD_R(RS5C348_REG_CTL2);
txbuf[3] = 0;
txbuf[4] = RS5C348_CMD_MW(RS5C348_REG_SECS);
txp = &txbuf[5];
txp[RS5C348_REG_SECS] = bin2bcd(tm->tm_sec);
txp[RS5C348_REG_MINS] = bin2bcd(tm->tm_min);
if (pdata->rtc_24h) {
txp[RS5C348_REG_HOURS] = bin2bcd(tm->tm_hour);
} else {
txp[RS5C348_REG_HOURS] = bin2bcd((tm->tm_hour + 11) % 12 + 1) |
(tm->tm_hour >= 12 ? RS5C348_BIT_PM : 0);
}
txp[RS5C348_REG_WDAY] = bin2bcd(tm->tm_wday);
txp[RS5C348_REG_DAY] = bin2bcd(tm->tm_mday);
txp[RS5C348_REG_MONTH] = bin2bcd(tm->tm_mon + 1) |
(tm->tm_year >= 100 ? RS5C348_BIT_Y2K : 0);
txp[RS5C348_REG_YEAR] = bin2bcd(tm->tm_year % 100);
ret = spi_write_then_read(spi, txbuf, sizeof(txbuf), NULL, 0);
udelay(62);
return ret;
}
static int
rs5c348_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct spi_device *spi = to_spi_device(dev);
struct rs5c348_plat_data *pdata = dev_get_platdata(&spi->dev);
u8 txbuf[5], rxbuf[7];
int ret;
txbuf[0] = RS5C348_CMD_R(RS5C348_REG_CTL2);
txbuf[1] = 0;
txbuf[2] = RS5C348_CMD_R(RS5C348_REG_CTL2);
txbuf[3] = 0;
txbuf[4] = RS5C348_CMD_MR(RS5C348_REG_SECS);
ret = spi_write_then_read(spi, txbuf, sizeof(txbuf),
rxbuf, sizeof(rxbuf));
udelay(62);
if (ret < 0)
return ret;
tm->tm_sec = bcd2bin(rxbuf[RS5C348_REG_SECS] & RS5C348_SECS_MASK);
tm->tm_min = bcd2bin(rxbuf[RS5C348_REG_MINS] & RS5C348_MINS_MASK);
tm->tm_hour = bcd2bin(rxbuf[RS5C348_REG_HOURS] & RS5C348_HOURS_MASK);
if (!pdata->rtc_24h) {
if (rxbuf[RS5C348_REG_HOURS] & RS5C348_BIT_PM) {
tm->tm_hour -= 20;
tm->tm_hour %= 12;
tm->tm_hour += 12;
} else
tm->tm_hour %= 12;
}
tm->tm_wday = bcd2bin(rxbuf[RS5C348_REG_WDAY] & RS5C348_WDAY_MASK);
tm->tm_mday = bcd2bin(rxbuf[RS5C348_REG_DAY] & RS5C348_DAY_MASK);
tm->tm_mon =
bcd2bin(rxbuf[RS5C348_REG_MONTH] & RS5C348_MONTH_MASK) - 1;
tm->tm_year = bcd2bin(rxbuf[RS5C348_REG_YEAR]) +
((rxbuf[RS5C348_REG_MONTH] & RS5C348_BIT_Y2K) ? 100 : 0);
if (rtc_valid_tm(tm) < 0) {
dev_err(&spi->dev, "retrieved date/time is not valid.\n");
rtc_time_to_tm(0, tm);
}
return 0;
}
static int rs5c348_probe(struct spi_device *spi)
{
int ret;
struct rtc_device *rtc;
struct rs5c348_plat_data *pdata;
pdata = devm_kzalloc(&spi->dev, sizeof(struct rs5c348_plat_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
spi->dev.platform_data = pdata;
ret = spi_w8r8(spi, RS5C348_CMD_R(RS5C348_REG_SECS));
if (ret < 0 || (ret & 0x80)) {
dev_err(&spi->dev, "not found.\n");
goto kfree_exit;
}
dev_info(&spi->dev, "spiclk %u KHz.\n",
(spi->max_speed_hz + 500) / 1000);
ret = spi_w8r8(spi, RS5C348_CMD_R(RS5C348_REG_CTL2));
if (ret < 0)
goto kfree_exit;
if (ret & (RS5C348_BIT_XSTP | RS5C348_BIT_VDET)) {
u8 buf[2];
struct rtc_time tm;
if (ret & RS5C348_BIT_VDET)
dev_warn(&spi->dev, "voltage-low detected.\n");
if (ret & RS5C348_BIT_XSTP)
dev_warn(&spi->dev, "oscillator-stop detected.\n");
rtc_time_to_tm(0, &tm);
ret = rs5c348_rtc_set_time(&spi->dev, &tm);
if (ret < 0)
goto kfree_exit;
buf[0] = RS5C348_CMD_W(RS5C348_REG_CTL2);
buf[1] = 0;
ret = spi_write_then_read(spi, buf, sizeof(buf), NULL, 0);
if (ret < 0)
goto kfree_exit;
}
ret = spi_w8r8(spi, RS5C348_CMD_R(RS5C348_REG_CTL1));
if (ret < 0)
goto kfree_exit;
if (ret & RS5C348_BIT_24H)
pdata->rtc_24h = 1;
rtc = devm_rtc_device_register(&spi->dev, rs5c348_driver.driver.name,
&rs5c348_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
ret = PTR_ERR(rtc);
goto kfree_exit;
}
pdata->rtc = rtc;
return 0;
kfree_exit:
return ret;
}
