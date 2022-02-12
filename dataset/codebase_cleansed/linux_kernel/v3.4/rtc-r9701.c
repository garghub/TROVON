static int write_reg(struct device *dev, int address, unsigned char data)
{
struct spi_device *spi = to_spi_device(dev);
unsigned char buf[2];
buf[0] = address & 0x7f;
buf[1] = data;
return spi_write(spi, buf, ARRAY_SIZE(buf));
}
static int read_regs(struct device *dev, unsigned char *regs, int no_regs)
{
struct spi_device *spi = to_spi_device(dev);
u8 txbuf[1], rxbuf[1];
int k, ret;
ret = 0;
for (k = 0; ret == 0 && k < no_regs; k++) {
txbuf[0] = 0x80 | regs[k];
ret = spi_write_then_read(spi, txbuf, 1, rxbuf, 1);
regs[k] = rxbuf[0];
}
return ret;
}
static int r9701_get_datetime(struct device *dev, struct rtc_time *dt)
{
int ret;
unsigned char buf[] = { RSECCNT, RMINCNT, RHRCNT,
RDAYCNT, RMONCNT, RYRCNT };
ret = read_regs(dev, buf, ARRAY_SIZE(buf));
if (ret)
return ret;
memset(dt, 0, sizeof(*dt));
dt->tm_sec = bcd2bin(buf[0]);
dt->tm_min = bcd2bin(buf[1]);
dt->tm_hour = bcd2bin(buf[2]);
dt->tm_mday = bcd2bin(buf[3]);
dt->tm_mon = bcd2bin(buf[4]) - 1;
dt->tm_year = bcd2bin(buf[5]) + 100;
return rtc_valid_tm(dt);
}
static int r9701_set_datetime(struct device *dev, struct rtc_time *dt)
{
int ret, year;
year = dt->tm_year + 1900;
if (year >= 2100 || year < 2000)
return -EINVAL;
ret = write_reg(dev, RHRCNT, bin2bcd(dt->tm_hour));
ret = ret ? ret : write_reg(dev, RMINCNT, bin2bcd(dt->tm_min));
ret = ret ? ret : write_reg(dev, RSECCNT, bin2bcd(dt->tm_sec));
ret = ret ? ret : write_reg(dev, RDAYCNT, bin2bcd(dt->tm_mday));
ret = ret ? ret : write_reg(dev, RMONCNT, bin2bcd(dt->tm_mon + 1));
ret = ret ? ret : write_reg(dev, RYRCNT, bin2bcd(dt->tm_year - 100));
ret = ret ? ret : write_reg(dev, RWKCNT, 1 << dt->tm_wday);
return ret;
}
static int __devinit r9701_probe(struct spi_device *spi)
{
struct rtc_device *rtc;
struct rtc_time dt;
unsigned char tmp;
int res;
tmp = R100CNT;
res = read_regs(&spi->dev, &tmp, 1);
if (res || tmp != 0x20) {
dev_err(&spi->dev, "cannot read RTC register\n");
return -ENODEV;
}
r9701_get_datetime(&spi->dev, &dt);
if (rtc_valid_tm(&dt)) {
dev_info(&spi->dev, "trying to repair invalid date/time\n");
dt.tm_sec = 0;
dt.tm_min = 0;
dt.tm_hour = 0;
dt.tm_mday = 1;
dt.tm_mon = 0;
dt.tm_year = 100;
if (r9701_set_datetime(&spi->dev, &dt)) {
dev_err(&spi->dev, "cannot repair RTC register\n");
return -ENODEV;
}
}
rtc = rtc_device_register("r9701",
&spi->dev, &r9701_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
dev_set_drvdata(&spi->dev, rtc);
return 0;
}
static int __devexit r9701_remove(struct spi_device *spi)
{
struct rtc_device *rtc = dev_get_drvdata(&spi->dev);
rtc_device_unregister(rtc);
return 0;
}
