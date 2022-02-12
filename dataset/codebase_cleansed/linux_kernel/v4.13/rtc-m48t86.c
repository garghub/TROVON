static unsigned char m48t86_readb(struct device *dev, unsigned long addr)
{
struct m48t86_rtc_info *info = dev_get_drvdata(dev);
unsigned char value;
writeb(addr, info->index_reg);
value = readb(info->data_reg);
return value;
}
static void m48t86_writeb(struct device *dev,
unsigned char value, unsigned long addr)
{
struct m48t86_rtc_info *info = dev_get_drvdata(dev);
writeb(addr, info->index_reg);
writeb(value, info->data_reg);
}
static int m48t86_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
unsigned char reg;
reg = m48t86_readb(dev, M48T86_B);
if (reg & M48T86_B_DM) {
tm->tm_sec = m48t86_readb(dev, M48T86_SEC);
tm->tm_min = m48t86_readb(dev, M48T86_MIN);
tm->tm_hour = m48t86_readb(dev, M48T86_HOUR) & 0x3f;
tm->tm_mday = m48t86_readb(dev, M48T86_DOM);
tm->tm_mon = m48t86_readb(dev, M48T86_MONTH) - 1;
tm->tm_year = m48t86_readb(dev, M48T86_YEAR) + 100;
tm->tm_wday = m48t86_readb(dev, M48T86_DOW);
} else {
tm->tm_sec = bcd2bin(m48t86_readb(dev, M48T86_SEC));
tm->tm_min = bcd2bin(m48t86_readb(dev, M48T86_MIN));
tm->tm_hour = bcd2bin(m48t86_readb(dev, M48T86_HOUR) &
0x3f);
tm->tm_mday = bcd2bin(m48t86_readb(dev, M48T86_DOM));
tm->tm_mon = bcd2bin(m48t86_readb(dev, M48T86_MONTH)) - 1;
tm->tm_year = bcd2bin(m48t86_readb(dev, M48T86_YEAR)) + 100;
tm->tm_wday = bcd2bin(m48t86_readb(dev, M48T86_DOW));
}
if (!(reg & M48T86_B_H24))
if (m48t86_readb(dev, M48T86_HOUR) & 0x80)
tm->tm_hour += 12;
return rtc_valid_tm(tm);
}
static int m48t86_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
unsigned char reg;
reg = m48t86_readb(dev, M48T86_B);
reg |= M48T86_B_SET | M48T86_B_H24;
m48t86_writeb(dev, reg, M48T86_B);
if (reg & M48T86_B_DM) {
m48t86_writeb(dev, tm->tm_sec, M48T86_SEC);
m48t86_writeb(dev, tm->tm_min, M48T86_MIN);
m48t86_writeb(dev, tm->tm_hour, M48T86_HOUR);
m48t86_writeb(dev, tm->tm_mday, M48T86_DOM);
m48t86_writeb(dev, tm->tm_mon + 1, M48T86_MONTH);
m48t86_writeb(dev, tm->tm_year % 100, M48T86_YEAR);
m48t86_writeb(dev, tm->tm_wday, M48T86_DOW);
} else {
m48t86_writeb(dev, bin2bcd(tm->tm_sec), M48T86_SEC);
m48t86_writeb(dev, bin2bcd(tm->tm_min), M48T86_MIN);
m48t86_writeb(dev, bin2bcd(tm->tm_hour), M48T86_HOUR);
m48t86_writeb(dev, bin2bcd(tm->tm_mday), M48T86_DOM);
m48t86_writeb(dev, bin2bcd(tm->tm_mon + 1), M48T86_MONTH);
m48t86_writeb(dev, bin2bcd(tm->tm_year % 100), M48T86_YEAR);
m48t86_writeb(dev, bin2bcd(tm->tm_wday), M48T86_DOW);
}
reg &= ~M48T86_B_SET;
m48t86_writeb(dev, reg, M48T86_B);
return 0;
}
static int m48t86_rtc_proc(struct device *dev, struct seq_file *seq)
{
unsigned char reg;
reg = m48t86_readb(dev, M48T86_B);
seq_printf(seq, "mode\t\t: %s\n",
(reg & M48T86_B_DM) ? "binary" : "bcd");
reg = m48t86_readb(dev, M48T86_D);
seq_printf(seq, "battery\t\t: %s\n",
(reg & M48T86_D_VRT) ? "ok" : "exhausted");
return 0;
}
static ssize_t m48t86_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
unsigned int i;
for (i = 0; i < count; i++)
buf[i] = m48t86_readb(dev, M48T86_NVRAM(off + i));
return count;
}
static ssize_t m48t86_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
unsigned int i;
for (i = 0; i < count; i++)
m48t86_writeb(dev, buf[i], M48T86_NVRAM(off + i));
return count;
}
static bool m48t86_verify_chip(struct platform_device *pdev)
{
unsigned int offset0 = M48T86_NVRAM(M48T86_NVRAM_LEN - 2);
unsigned int offset1 = M48T86_NVRAM(M48T86_NVRAM_LEN - 1);
unsigned char tmp0, tmp1;
tmp0 = m48t86_readb(&pdev->dev, offset0);
tmp1 = m48t86_readb(&pdev->dev, offset1);
m48t86_writeb(&pdev->dev, 0x00, offset0);
m48t86_writeb(&pdev->dev, 0x55, offset1);
if (m48t86_readb(&pdev->dev, offset1) == 0x55) {
m48t86_writeb(&pdev->dev, 0xaa, offset1);
if (m48t86_readb(&pdev->dev, offset1) == 0xaa &&
m48t86_readb(&pdev->dev, offset0) == 0x00) {
m48t86_writeb(&pdev->dev, tmp0, offset0);
m48t86_writeb(&pdev->dev, tmp1, offset1);
return true;
}
}
return false;
}
static int m48t86_rtc_probe(struct platform_device *pdev)
{
struct m48t86_rtc_info *info;
struct resource *res;
unsigned char reg;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
info->index_reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->index_reg))
return PTR_ERR(info->index_reg);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res)
return -ENODEV;
info->data_reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->data_reg))
return PTR_ERR(info->data_reg);
dev_set_drvdata(&pdev->dev, info);
if (!m48t86_verify_chip(pdev)) {
dev_info(&pdev->dev, "RTC not present\n");
return -ENODEV;
}
info->rtc = devm_rtc_device_register(&pdev->dev, "m48t86",
&m48t86_rtc_ops, THIS_MODULE);
if (IS_ERR(info->rtc))
return PTR_ERR(info->rtc);
reg = m48t86_readb(&pdev->dev, M48T86_D);
dev_info(&pdev->dev, "battery %s\n",
(reg & M48T86_D_VRT) ? "ok" : "exhausted");
if (device_create_bin_file(&pdev->dev, &bin_attr_nvram))
dev_err(&pdev->dev, "failed to create nvram sysfs entry\n");
return 0;
}
static int m48t86_rtc_remove(struct platform_device *pdev)
{
device_remove_bin_file(&pdev->dev, &bin_attr_nvram);
return 0;
}
