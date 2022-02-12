static int m48t86_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
unsigned char reg;
struct platform_device *pdev = to_platform_device(dev);
struct m48t86_ops *ops = pdev->dev.platform_data;
reg = ops->readbyte(M48T86_REG_B);
if (reg & M48T86_REG_B_DM) {
tm->tm_sec = ops->readbyte(M48T86_REG_SEC);
tm->tm_min = ops->readbyte(M48T86_REG_MIN);
tm->tm_hour = ops->readbyte(M48T86_REG_HOUR) & 0x3F;
tm->tm_mday = ops->readbyte(M48T86_REG_DOM);
tm->tm_mon = ops->readbyte(M48T86_REG_MONTH) - 1;
tm->tm_year = ops->readbyte(M48T86_REG_YEAR) + 100;
tm->tm_wday = ops->readbyte(M48T86_REG_DOW);
} else {
tm->tm_sec = bcd2bin(ops->readbyte(M48T86_REG_SEC));
tm->tm_min = bcd2bin(ops->readbyte(M48T86_REG_MIN));
tm->tm_hour = bcd2bin(ops->readbyte(M48T86_REG_HOUR) & 0x3F);
tm->tm_mday = bcd2bin(ops->readbyte(M48T86_REG_DOM));
tm->tm_mon = bcd2bin(ops->readbyte(M48T86_REG_MONTH)) - 1;
tm->tm_year = bcd2bin(ops->readbyte(M48T86_REG_YEAR)) + 100;
tm->tm_wday = bcd2bin(ops->readbyte(M48T86_REG_DOW));
}
if (!(reg & M48T86_REG_B_H24))
if (ops->readbyte(M48T86_REG_HOUR) & 0x80)
tm->tm_hour += 12;
return rtc_valid_tm(tm);
}
static int m48t86_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned char reg;
struct platform_device *pdev = to_platform_device(dev);
struct m48t86_ops *ops = pdev->dev.platform_data;
reg = ops->readbyte(M48T86_REG_B);
reg |= M48T86_REG_B_SET | M48T86_REG_B_H24;
ops->writebyte(reg, M48T86_REG_B);
if (reg & M48T86_REG_B_DM) {
ops->writebyte(tm->tm_sec, M48T86_REG_SEC);
ops->writebyte(tm->tm_min, M48T86_REG_MIN);
ops->writebyte(tm->tm_hour, M48T86_REG_HOUR);
ops->writebyte(tm->tm_mday, M48T86_REG_DOM);
ops->writebyte(tm->tm_mon + 1, M48T86_REG_MONTH);
ops->writebyte(tm->tm_year % 100, M48T86_REG_YEAR);
ops->writebyte(tm->tm_wday, M48T86_REG_DOW);
} else {
ops->writebyte(bin2bcd(tm->tm_sec), M48T86_REG_SEC);
ops->writebyte(bin2bcd(tm->tm_min), M48T86_REG_MIN);
ops->writebyte(bin2bcd(tm->tm_hour), M48T86_REG_HOUR);
ops->writebyte(bin2bcd(tm->tm_mday), M48T86_REG_DOM);
ops->writebyte(bin2bcd(tm->tm_mon + 1), M48T86_REG_MONTH);
ops->writebyte(bin2bcd(tm->tm_year % 100), M48T86_REG_YEAR);
ops->writebyte(bin2bcd(tm->tm_wday), M48T86_REG_DOW);
}
reg &= ~M48T86_REG_B_SET;
ops->writebyte(reg, M48T86_REG_B);
return 0;
}
static int m48t86_rtc_proc(struct device *dev, struct seq_file *seq)
{
unsigned char reg;
struct platform_device *pdev = to_platform_device(dev);
struct m48t86_ops *ops = pdev->dev.platform_data;
reg = ops->readbyte(M48T86_REG_B);
seq_printf(seq, "mode\t\t: %s\n",
(reg & M48T86_REG_B_DM) ? "binary" : "bcd");
reg = ops->readbyte(M48T86_REG_D);
seq_printf(seq, "battery\t\t: %s\n",
(reg & M48T86_REG_D_VRT) ? "ok" : "exhausted");
return 0;
}
static int __devinit m48t86_rtc_probe(struct platform_device *dev)
{
unsigned char reg;
struct m48t86_ops *ops = dev->dev.platform_data;
struct rtc_device *rtc = rtc_device_register("m48t86",
&dev->dev, &m48t86_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc))
return PTR_ERR(rtc);
platform_set_drvdata(dev, rtc);
reg = ops->readbyte(M48T86_REG_D);
dev_info(&dev->dev, "battery %s\n",
(reg & M48T86_REG_D_VRT) ? "ok" : "exhausted");
return 0;
}
static int __devexit m48t86_rtc_remove(struct platform_device *dev)
{
struct rtc_device *rtc = platform_get_drvdata(dev);
if (rtc)
rtc_device_unregister(rtc);
platform_set_drvdata(dev, NULL);
return 0;
}
