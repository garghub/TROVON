static int rx6110_rtc_tm_to_data(struct rtc_time *tm, u8 *data)
{
pr_debug("%s: date %ds %dm %dh %dmd %dm %dy\n", __func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year);
if (tm->tm_year < 100 || tm->tm_year >= 200)
return -EINVAL;
data[RTC_SEC] = bin2bcd(tm->tm_sec);
data[RTC_MIN] = bin2bcd(tm->tm_min);
data[RTC_HOUR] = bin2bcd(tm->tm_hour);
data[RTC_WDAY] = BIT(bin2bcd(tm->tm_wday));
data[RTC_MDAY] = bin2bcd(tm->tm_mday);
data[RTC_MONTH] = bin2bcd(tm->tm_mon + 1);
data[RTC_YEAR] = bin2bcd(tm->tm_year % 100);
return 0;
}
static int rx6110_data_to_rtc_tm(u8 *data, struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(data[RTC_SEC] & 0x7f);
tm->tm_min = bcd2bin(data[RTC_MIN] & 0x7f);
tm->tm_hour = bcd2bin(data[RTC_HOUR] & 0x3f);
tm->tm_wday = ffs(data[RTC_WDAY] & 0x7f);
tm->tm_mday = bcd2bin(data[RTC_MDAY] & 0x3f);
tm->tm_mon = bcd2bin(data[RTC_MONTH] & 0x1f) - 1;
tm->tm_year = bcd2bin(data[RTC_YEAR]) + 100;
pr_debug("%s: date %ds %dm %dh %dmd %dm %dy\n", __func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year);
if (tm->tm_year < 100 || tm->tm_year >= 200)
return -EINVAL;
return 0;
}
static int rx6110_set_time(struct device *dev, struct rtc_time *tm)
{
struct rx6110_data *rx6110 = dev_get_drvdata(dev);
u8 data[RTC_NR_TIME];
int ret;
ret = rx6110_rtc_tm_to_data(tm, data);
if (ret < 0)
return ret;
ret = regmap_update_bits(rx6110->regmap, RX6110_REG_CTRL,
RX6110_BIT_CTRL_STOP, RX6110_BIT_CTRL_STOP);
if (ret)
return ret;
ret = regmap_bulk_write(rx6110->regmap, RX6110_REG_SEC, data,
RTC_NR_TIME);
if (ret)
return ret;
ret = regmap_update_bits(rx6110->regmap, RX6110_REG_FLAG,
RX6110_BIT_FLAG_VLF, 0);
if (ret)
return ret;
ret = regmap_update_bits(rx6110->regmap, RX6110_REG_CTRL,
RX6110_BIT_CTRL_STOP, 0);
return ret;
}
static int rx6110_get_time(struct device *dev, struct rtc_time *tm)
{
struct rx6110_data *rx6110 = dev_get_drvdata(dev);
u8 data[RTC_NR_TIME];
int flags;
int ret;
ret = regmap_read(rx6110->regmap, RX6110_REG_FLAG, &flags);
if (ret)
return -EINVAL;
if ((flags & RX6110_BIT_FLAG_VLF)) {
dev_warn(dev, "Voltage low, data is invalid.\n");
return -EINVAL;
}
ret = regmap_bulk_read(rx6110->regmap, RX6110_REG_SEC, data,
RTC_NR_TIME);
if (ret)
return ret;
ret = rx6110_data_to_rtc_tm(data, tm);
if (ret)
return ret;
dev_dbg(dev, "%s: date %ds %dm %dh %dmd %dm %dy\n", __func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon, tm->tm_year);
return rtc_valid_tm(tm);
}
static int rx6110_init(struct rx6110_data *rx6110)
{
struct rtc_device *rtc = rx6110->rtc;
int flags;
int ret;
ret = regmap_update_bits(rx6110->regmap, RX6110_REG_EXT,
RX6110_BIT_EXT_TE, 0);
if (ret)
return ret;
ret = regmap_register_patch(rx6110->regmap, rx6110_default_regs,
ARRAY_SIZE(rx6110_default_regs));
if (ret)
return ret;
ret = regmap_read(rx6110->regmap, RX6110_REG_FLAG, &flags);
if (ret)
return ret;
if ((flags & RX6110_BIT_FLAG_VLF))
dev_warn(&rtc->dev, "Voltage low, data loss detected.\n");
if (flags & RX6110_BIT_FLAG_AF)
dev_warn(&rtc->dev, "An alarm may have been missed.\n");
if (flags & RX6110_BIT_FLAG_TF)
dev_warn(&rtc->dev, "Periodic timer was detected\n");
if (flags & RX6110_BIT_FLAG_UF)
dev_warn(&rtc->dev, "Update timer was detected\n");
ret = regmap_update_bits(rx6110->regmap, RX6110_REG_FLAG,
RX6110_BIT_FLAG_AF |
RX6110_BIT_FLAG_UF |
RX6110_BIT_FLAG_TF,
0);
return ret;
}
static int rx6110_probe(struct spi_device *spi)
{
struct rx6110_data *rx6110;
int err;
if ((spi->bits_per_word && spi->bits_per_word != 8) ||
(spi->max_speed_hz > 2000000) ||
(spi->mode != (SPI_CS_HIGH | SPI_CPOL | SPI_CPHA))) {
dev_warn(&spi->dev, "SPI settings: bits_per_word: %d, max_speed_hz: %d, mode: %xh\n",
spi->bits_per_word, spi->max_speed_hz, spi->mode);
dev_warn(&spi->dev, "driving device in an unsupported mode");
}
rx6110 = devm_kzalloc(&spi->dev, sizeof(*rx6110), GFP_KERNEL);
if (!rx6110)
return -ENOMEM;
rx6110->regmap = devm_regmap_init_spi(spi, &regmap_spi_config);
if (IS_ERR(rx6110->regmap)) {
dev_err(&spi->dev, "regmap init failed for rtc rx6110\n");
return PTR_ERR(rx6110->regmap);
}
spi_set_drvdata(spi, rx6110);
rx6110->rtc = devm_rtc_device_register(&spi->dev,
RX6110_DRIVER_NAME,
&rx6110_rtc_ops, THIS_MODULE);
if (IS_ERR(rx6110->rtc))
return PTR_ERR(rx6110->rtc);
err = rx6110_init(rx6110);
if (err)
return err;
rx6110->rtc->max_user_freq = 1;
return 0;
}
static int rx6110_remove(struct spi_device *spi)
{
return 0;
}
