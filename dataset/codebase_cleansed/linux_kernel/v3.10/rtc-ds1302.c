static inline int ds1302_hw_init(void)
{
return 0;
}
static inline void ds1302_reset(void)
{
set_dp(get_dp() & ~(RTC_RESET | RTC_IODATA | RTC_SCLK));
}
static inline void ds1302_clock(void)
{
set_dp(get_dp() | RTC_SCLK);
set_dp(get_dp() & ~RTC_SCLK);
}
static inline void ds1302_start(void)
{
set_dp(get_dp() | RTC_RESET);
}
static inline void ds1302_stop(void)
{
set_dp(get_dp() & ~RTC_RESET);
}
static inline void ds1302_txbit(int bit)
{
set_dp((get_dp() & ~RTC_IODATA) | (bit ? RTC_IODATA : 0));
}
static inline int ds1302_rxbit(void)
{
return !!(get_dp() & RTC_IODATA);
}
static void ds1302_sendbits(unsigned int val)
{
int i;
ds1302_set_tx();
for (i = 8; (i); i--, val >>= 1) {
ds1302_txbit(val & 0x1);
ds1302_clock();
}
}
static unsigned int ds1302_recvbits(void)
{
unsigned int val;
int i;
ds1302_set_rx();
for (i = 0, val = 0; (i < 8); i++) {
val |= (ds1302_rxbit() << i);
ds1302_clock();
}
return val;
}
static unsigned int ds1302_readbyte(unsigned int addr)
{
unsigned int val;
ds1302_reset();
ds1302_start();
ds1302_sendbits(((addr & 0x3f) << 1) | RTC_CMD_READ);
val = ds1302_recvbits();
ds1302_stop();
return val;
}
static void ds1302_writebyte(unsigned int addr, unsigned int val)
{
ds1302_reset();
ds1302_start();
ds1302_sendbits(((addr & 0x3f) << 1) | RTC_CMD_WRITE);
ds1302_sendbits(val);
ds1302_stop();
}
static int ds1302_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(ds1302_readbyte(RTC_ADDR_SEC));
tm->tm_min = bcd2bin(ds1302_readbyte(RTC_ADDR_MIN));
tm->tm_hour = bcd2bin(ds1302_readbyte(RTC_ADDR_HOUR));
tm->tm_wday = bcd2bin(ds1302_readbyte(RTC_ADDR_DAY));
tm->tm_mday = bcd2bin(ds1302_readbyte(RTC_ADDR_DATE));
tm->tm_mon = bcd2bin(ds1302_readbyte(RTC_ADDR_MON)) - 1;
tm->tm_year = bcd2bin(ds1302_readbyte(RTC_ADDR_YEAR));
if (tm->tm_year < 70)
tm->tm_year += 100;
dev_dbg(dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon + 1, tm->tm_year, tm->tm_wday);
return rtc_valid_tm(tm);
}
static int ds1302_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
ds1302_writebyte(RTC_ADDR_SEC, ds1302_readbyte(RTC_ADDR_SEC) | 0x80);
ds1302_writebyte(RTC_ADDR_SEC, bin2bcd(tm->tm_sec));
ds1302_writebyte(RTC_ADDR_MIN, bin2bcd(tm->tm_min));
ds1302_writebyte(RTC_ADDR_HOUR, bin2bcd(tm->tm_hour));
ds1302_writebyte(RTC_ADDR_DAY, bin2bcd(tm->tm_wday));
ds1302_writebyte(RTC_ADDR_DATE, bin2bcd(tm->tm_mday));
ds1302_writebyte(RTC_ADDR_MON, bin2bcd(tm->tm_mon + 1));
ds1302_writebyte(RTC_ADDR_YEAR, bin2bcd(tm->tm_year % 100));
ds1302_writebyte(RTC_ADDR_SEC, ds1302_readbyte(RTC_ADDR_SEC) & ~0x80);
return 0;
}
static int ds1302_rtc_ioctl(struct device *dev, unsigned int cmd,
unsigned long arg)
{
switch (cmd) {
#ifdef RTC_SET_CHARGE
case RTC_SET_CHARGE:
{
int tcs_val;
if (copy_from_user(&tcs_val, (int __user *)arg, sizeof(int)))
return -EFAULT;
ds1302_writebyte(RTC_ADDR_TCR, (0xa0 | tcs_val * 0xf));
return 0;
}
#endif
}
return -ENOIOCTLCMD;
}
static int __init ds1302_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
if (ds1302_hw_init()) {
dev_err(&pdev->dev, "Failed to init communication channel");
return -EINVAL;
}
ds1302_reset();
ds1302_writebyte(RTC_ADDR_RAM0, 0x42);
if (ds1302_readbyte(RTC_ADDR_RAM0) != 0x42) {
dev_err(&pdev->dev, "Failed to probe");
return -ENODEV;
}
rtc = devm_rtc_device_register(&pdev->dev, "ds1302",
&ds1302_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(pdev, rtc);
return 0;
}
static int __exit ds1302_rtc_remove(struct platform_device *pdev)
{
platform_set_drvdata(pdev, NULL);
return 0;
}
