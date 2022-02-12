static int ep93xx_rtc_get_swcomp(struct device *dev, unsigned short *preload,
unsigned short *delete)
{
struct ep93xx_rtc *ep93xx_rtc = dev_get_platdata(dev);
unsigned long comp;
comp = __raw_readl(ep93xx_rtc->mmio_base + EP93XX_RTC_SWCOMP);
if (preload)
*preload = (comp & EP93XX_RTC_SWCOMP_INT_MASK)
>> EP93XX_RTC_SWCOMP_INT_SHIFT;
if (delete)
*delete = (comp & EP93XX_RTC_SWCOMP_DEL_MASK)
>> EP93XX_RTC_SWCOMP_DEL_SHIFT;
return 0;
}
static int ep93xx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct ep93xx_rtc *ep93xx_rtc = dev_get_platdata(dev);
unsigned long time;
time = __raw_readl(ep93xx_rtc->mmio_base + EP93XX_RTC_DATA);
rtc_time_to_tm(time, tm);
return 0;
}
static int ep93xx_rtc_set_mmss(struct device *dev, unsigned long secs)
{
struct ep93xx_rtc *ep93xx_rtc = dev_get_platdata(dev);
__raw_writel(secs + 1, ep93xx_rtc->mmio_base + EP93XX_RTC_LOAD);
return 0;
}
static int ep93xx_rtc_proc(struct device *dev, struct seq_file *seq)
{
unsigned short preload, delete;
ep93xx_rtc_get_swcomp(dev, &preload, &delete);
seq_printf(seq, "preload\t\t: %d\n", preload);
seq_printf(seq, "delete\t\t: %d\n", delete);
return 0;
}
static ssize_t ep93xx_rtc_show_comp_preload(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned short preload;
ep93xx_rtc_get_swcomp(dev, &preload, NULL);
return sprintf(buf, "%d\n", preload);
}
static ssize_t ep93xx_rtc_show_comp_delete(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned short delete;
ep93xx_rtc_get_swcomp(dev, NULL, &delete);
return sprintf(buf, "%d\n", delete);
}
static int ep93xx_rtc_probe(struct platform_device *pdev)
{
struct ep93xx_rtc *ep93xx_rtc;
struct resource *res;
int err;
ep93xx_rtc = devm_kzalloc(&pdev->dev, sizeof(*ep93xx_rtc), GFP_KERNEL);
if (!ep93xx_rtc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ep93xx_rtc->mmio_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ep93xx_rtc->mmio_base))
return PTR_ERR(ep93xx_rtc->mmio_base);
pdev->dev.platform_data = ep93xx_rtc;
platform_set_drvdata(pdev, ep93xx_rtc);
ep93xx_rtc->rtc = devm_rtc_device_register(&pdev->dev,
pdev->name, &ep93xx_rtc_ops, THIS_MODULE);
if (IS_ERR(ep93xx_rtc->rtc)) {
err = PTR_ERR(ep93xx_rtc->rtc);
goto exit;
}
err = sysfs_create_group(&pdev->dev.kobj, &ep93xx_rtc_sysfs_files);
if (err)
goto exit;
return 0;
exit:
pdev->dev.platform_data = NULL;
return err;
}
static int ep93xx_rtc_remove(struct platform_device *pdev)
{
sysfs_remove_group(&pdev->dev.kobj, &ep93xx_rtc_sysfs_files);
pdev->dev.platform_data = NULL;
return 0;
}
