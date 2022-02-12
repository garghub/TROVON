static int mcp795_rtcc_read(struct device *dev, u8 addr, u8 *buf, u8 count)
{
struct spi_device *spi = to_spi_device(dev);
int ret;
u8 tx[2];
tx[0] = MCP795_READ;
tx[1] = addr;
ret = spi_write_then_read(spi, tx, sizeof(tx), buf, count);
if (ret)
dev_err(dev, "Failed reading %d bytes from address %x.\n",
count, addr);
return ret;
}
static int mcp795_rtcc_write(struct device *dev, u8 addr, u8 *data, u8 count)
{
struct spi_device *spi = to_spi_device(dev);
int ret;
u8 tx[2 + count];
tx[0] = MCP795_WRITE;
tx[1] = addr;
memcpy(&tx[2], data, count);
ret = spi_write(spi, tx, 2 + count);
if (ret)
dev_err(dev, "Failed to write %d bytes to address %x.\n",
count, addr);
return ret;
}
static int mcp795_rtcc_set_bits(struct device *dev, u8 addr, u8 mask, u8 state)
{
int ret;
u8 tmp;
ret = mcp795_rtcc_read(dev, addr, &tmp, 1);
if (ret)
return ret;
if ((tmp & mask) != state) {
tmp = (tmp & ~mask) | state;
ret = mcp795_rtcc_write(dev, addr, &tmp, 1);
}
return ret;
}
static int mcp795_stop_oscillator(struct device *dev, bool *extosc)
{
int retries = 5;
int ret;
u8 data;
ret = mcp795_rtcc_set_bits(dev, MCP795_REG_SECONDS, MCP795_ST_BIT, 0);
if (ret)
return ret;
ret = mcp795_rtcc_read(dev, MCP795_REG_CONTROL, &data, 1);
if (ret)
return ret;
*extosc = !!(data & MCP795_EXTOSC_BIT);
ret = mcp795_rtcc_set_bits(
dev, MCP795_REG_CONTROL, MCP795_EXTOSC_BIT, 0);
if (ret)
return ret;
do {
usleep_range(700, 800);
ret = mcp795_rtcc_read(dev, MCP795_REG_DAY, &data, 1);
if (ret)
break;
if (!(data & MCP795_OSCON_BIT))
break;
} while (--retries);
return !retries ? -EIO : ret;
}
static int mcp795_start_oscillator(struct device *dev, bool *extosc)
{
if (extosc) {
u8 data = *extosc ? MCP795_EXTOSC_BIT : 0;
int ret;
ret = mcp795_rtcc_set_bits(
dev, MCP795_REG_CONTROL, MCP795_EXTOSC_BIT, data);
if (ret)
return ret;
}
return mcp795_rtcc_set_bits(
dev, MCP795_REG_SECONDS, MCP795_ST_BIT, MCP795_ST_BIT);
}
static int mcp795_update_alarm(struct device *dev, bool enable)
{
int ret;
dev_dbg(dev, "%s alarm\n", enable ? "Enable" : "Disable");
if (enable) {
ret = mcp795_rtcc_set_bits(dev, MCP795_REG_ALM0_DAY,
MCP795_ALM0IF_BIT, 0);
if (ret)
return ret;
ret = mcp795_rtcc_set_bits(dev, MCP795_REG_CONTROL,
MCP795_ALM0_BIT, MCP795_ALM0_BIT);
} else {
ret = mcp795_rtcc_set_bits(dev, MCP795_REG_CONTROL,
MCP795_ALM0_BIT | MCP795_ALM1_BIT, 0);
}
return ret;
}
static int mcp795_set_time(struct device *dev, struct rtc_time *tim)
{
int ret;
u8 data[7];
bool extosc;
ret = mcp795_stop_oscillator(dev, &extosc);
if (ret)
return ret;
ret = mcp795_rtcc_read(dev, MCP795_REG_SECONDS, data, sizeof(data));
if (ret)
return ret;
data[0] = (data[0] & 0x80) | bin2bcd(tim->tm_sec);
data[1] = (data[1] & 0x80) | bin2bcd(tim->tm_min);
data[2] = bin2bcd(tim->tm_hour);
data[3] = (data[3] & 0xF8) | bin2bcd(tim->tm_wday + 1);
data[4] = bin2bcd(tim->tm_mday);
data[5] = (data[5] & MCP795_LP_BIT) | bin2bcd(tim->tm_mon + 1);
if (tim->tm_year > 100)
tim->tm_year -= 100;
data[6] = bin2bcd(tim->tm_year);
ret = mcp795_rtcc_write(dev, MCP795_REG_SECONDS, data, 5);
if (ret)
return ret;
ret = mcp795_rtcc_write(dev, MCP795_REG_MONTH, &data[5], 2);
if (ret)
return ret;
ret = mcp795_start_oscillator(dev, extosc ? &extosc : NULL);
if (ret)
return ret;
dev_dbg(dev, "Set mcp795: %04d-%02d-%02d(%d) %02d:%02d:%02d\n",
tim->tm_year + 1900, tim->tm_mon, tim->tm_mday,
tim->tm_wday, tim->tm_hour, tim->tm_min, tim->tm_sec);
return 0;
}
static int mcp795_read_time(struct device *dev, struct rtc_time *tim)
{
int ret;
u8 data[7];
ret = mcp795_rtcc_read(dev, MCP795_REG_SECONDS, data, sizeof(data));
if (ret)
return ret;
tim->tm_sec = bcd2bin(data[0] & 0x7F);
tim->tm_min = bcd2bin(data[1] & 0x7F);
tim->tm_hour = bcd2bin(data[2] & 0x3F);
tim->tm_wday = bcd2bin(data[3] & 0x07) - 1;
tim->tm_mday = bcd2bin(data[4] & 0x3F);
tim->tm_mon = bcd2bin(data[5] & 0x1F) - 1;
tim->tm_year = bcd2bin(data[6]) + 100;
dev_dbg(dev, "Read from mcp795: %04d-%02d-%02d(%d) %02d:%02d:%02d\n",
tim->tm_year + 1900, tim->tm_mon, tim->tm_mday,
tim->tm_wday, tim->tm_hour, tim->tm_min, tim->tm_sec);
return rtc_valid_tm(tim);
}
static int mcp795_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct rtc_time now_tm;
time64_t now;
time64_t later;
u8 tmp[6];
int ret;
ret = mcp795_read_time(dev, &now_tm);
if (ret)
return ret;
now = rtc_tm_to_time64(&now_tm);
later = rtc_tm_to_time64(&alm->time);
if (later <= now)
return -EINVAL;
if ((later - now) >=
(SEC_PER_DAY * (365 + is_leap_year(alm->time.tm_year))))
return -EDOM;
ret = mcp795_update_alarm(dev, false);
if (ret)
return ret;
ret = mcp795_rtcc_read(dev, MCP795_REG_ALM0_SECONDS, tmp, sizeof(tmp));
if (ret)
return ret;
alm->time.tm_year = -1;
alm->time.tm_isdst = -1;
alm->time.tm_yday = -1;
tmp[0] = (tmp[0] & 0x80) | bin2bcd(alm->time.tm_sec);
tmp[1] = (tmp[1] & 0x80) | bin2bcd(alm->time.tm_min);
tmp[2] = (tmp[2] & 0xE0) | bin2bcd(alm->time.tm_hour);
tmp[3] = (tmp[3] & 0x80) | bin2bcd(alm->time.tm_wday + 1);
tmp[3] |= (MCP795_ALM0C2_BIT | MCP795_ALM0C1_BIT | MCP795_ALM0C0_BIT);
tmp[4] = (tmp[4] & 0xC0) | bin2bcd(alm->time.tm_mday);
tmp[5] = (tmp[5] & 0xE0) | bin2bcd(alm->time.tm_mon + 1);
ret = mcp795_rtcc_write(dev, MCP795_REG_ALM0_SECONDS, tmp, sizeof(tmp));
if (ret)
return ret;
if (alm->enabled) {
ret = mcp795_update_alarm(dev, true);
if (ret)
return ret;
dev_dbg(dev, "Alarm IRQ armed\n");
}
dev_dbg(dev, "Set alarm: %02d-%02d(%d) %02d:%02d:%02d\n",
alm->time.tm_mon, alm->time.tm_mday, alm->time.tm_wday,
alm->time.tm_hour, alm->time.tm_min, alm->time.tm_sec);
return 0;
}
static int mcp795_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
u8 data[6];
int ret;
ret = mcp795_rtcc_read(
dev, MCP795_REG_ALM0_SECONDS, data, sizeof(data));
if (ret)
return ret;
alm->time.tm_sec = bcd2bin(data[0] & 0x7F);
alm->time.tm_min = bcd2bin(data[1] & 0x7F);
alm->time.tm_hour = bcd2bin(data[2] & 0x1F);
alm->time.tm_wday = bcd2bin(data[3] & 0x07) - 1;
alm->time.tm_mday = bcd2bin(data[4] & 0x3F);
alm->time.tm_mon = bcd2bin(data[5] & 0x1F) - 1;
alm->time.tm_year = -1;
alm->time.tm_isdst = -1;
alm->time.tm_yday = -1;
dev_dbg(dev, "Read alarm: %02d-%02d(%d) %02d:%02d:%02d\n",
alm->time.tm_mon, alm->time.tm_mday, alm->time.tm_wday,
alm->time.tm_hour, alm->time.tm_min, alm->time.tm_sec);
return 0;
}
static int mcp795_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
return mcp795_update_alarm(dev, !!enabled);
}
static irqreturn_t mcp795_irq(int irq, void *data)
{
struct spi_device *spi = data;
struct rtc_device *rtc = spi_get_drvdata(spi);
struct mutex *lock = &rtc->ops_lock;
int ret;
mutex_lock(lock);
ret = mcp795_update_alarm(&spi->dev, false);
if (ret)
dev_err(&spi->dev,
"Failed to disable alarm in IRQ (ret=%d)\n", ret);
rtc_update_irq(rtc, 1, RTC_AF | RTC_IRQF);
mutex_unlock(lock);
return IRQ_HANDLED;
}
static int mcp795_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
int ret;
spi->mode = SPI_MODE_0;
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret) {
dev_err(&spi->dev, "Unable to setup SPI\n");
return ret;
}
mcp795_start_oscillator(&spi->dev, NULL);
mcp795_rtcc_set_bits(&spi->dev, 0x03, MCP795_24_BIT, 0);
rtc = devm_rtc_device_register(&spi->dev, "rtc-mcp795",
&mcp795_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
spi_set_drvdata(spi, rtc);
if (spi->irq > 0) {
dev_dbg(&spi->dev, "Alarm support enabled\n");
mcp795_rtcc_set_bits(&spi->dev, MCP795_REG_ALM0_DAY,
MCP795_ALM0IF_BIT, 0);
ret = devm_request_threaded_irq(&spi->dev, spi->irq, NULL,
mcp795_irq, IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev_name(&rtc->dev), spi);
if (ret)
dev_err(&spi->dev, "Failed to request IRQ: %d: %d\n",
spi->irq, ret);
else
device_init_wakeup(&spi->dev, true);
}
return 0;
}
