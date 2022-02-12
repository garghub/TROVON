static int xlnx_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
unsigned long new_time;
new_time = rtc_tm_to_time64(tm);
if (new_time > RTC_SEC_MAX_VAL)
return -EINVAL;
writel(new_time, xrtcdev->reg_base + RTC_SET_TM_WR);
return 0;
}
static int xlnx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
rtc_time64_to_tm(readl(xrtcdev->reg_base + RTC_CUR_TM), tm);
return rtc_valid_tm(tm);
}
static int xlnx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
rtc_time64_to_tm(readl(xrtcdev->reg_base + RTC_ALRM), &alrm->time);
alrm->enabled = readl(xrtcdev->reg_base + RTC_INT_MASK) & RTC_INT_ALRM;
return 0;
}
static int xlnx_rtc_alarm_irq_enable(struct device *dev, u32 enabled)
{
struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
if (enabled)
writel(RTC_INT_ALRM, xrtcdev->reg_base + RTC_INT_EN);
else
writel(RTC_INT_ALRM, xrtcdev->reg_base + RTC_INT_DIS);
return 0;
}
static int xlnx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct xlnx_rtc_dev *xrtcdev = dev_get_drvdata(dev);
unsigned long alarm_time;
alarm_time = rtc_tm_to_time64(&alrm->time);
if (alarm_time > RTC_SEC_MAX_VAL)
return -EINVAL;
writel((u32)alarm_time, (xrtcdev->reg_base + RTC_ALRM));
xlnx_rtc_alarm_irq_enable(dev, alrm->enabled);
return 0;
}
static void xlnx_init_rtc(struct xlnx_rtc_dev *xrtcdev, u32 calibval)
{
calibval &= RTC_CALIB_MASK;
writel(calibval, (xrtcdev->reg_base + RTC_CALIB_WR));
}
static irqreturn_t xlnx_rtc_interrupt(int irq, void *id)
{
struct xlnx_rtc_dev *xrtcdev = (struct xlnx_rtc_dev *)id;
unsigned int status;
status = readl(xrtcdev->reg_base + RTC_INT_STS);
if (!(status & (RTC_INT_SEC | RTC_INT_ALRM)))
return IRQ_NONE;
writel(status, xrtcdev->reg_base + RTC_INT_STS);
if (status & RTC_INT_SEC)
rtc_update_irq(xrtcdev->rtc, 1, RTC_IRQF | RTC_UF);
if (status & RTC_INT_ALRM)
rtc_update_irq(xrtcdev->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int xlnx_rtc_probe(struct platform_device *pdev)
{
struct xlnx_rtc_dev *xrtcdev;
struct resource *res;
int ret;
unsigned int calibvalue;
xrtcdev = devm_kzalloc(&pdev->dev, sizeof(*xrtcdev), GFP_KERNEL);
if (!xrtcdev)
return -ENOMEM;
platform_set_drvdata(pdev, xrtcdev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xrtcdev->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xrtcdev->reg_base))
return PTR_ERR(xrtcdev->reg_base);
xrtcdev->alarm_irq = platform_get_irq_byname(pdev, "alarm");
if (xrtcdev->alarm_irq < 0) {
dev_err(&pdev->dev, "no irq resource\n");
return xrtcdev->alarm_irq;
}
ret = devm_request_irq(&pdev->dev, xrtcdev->alarm_irq,
xlnx_rtc_interrupt, 0,
dev_name(&pdev->dev), xrtcdev);
if (ret) {
dev_err(&pdev->dev, "request irq failed\n");
return ret;
}
xrtcdev->sec_irq = platform_get_irq_byname(pdev, "sec");
if (xrtcdev->sec_irq < 0) {
dev_err(&pdev->dev, "no irq resource\n");
return xrtcdev->sec_irq;
}
ret = devm_request_irq(&pdev->dev, xrtcdev->sec_irq,
xlnx_rtc_interrupt, 0,
dev_name(&pdev->dev), xrtcdev);
if (ret) {
dev_err(&pdev->dev, "request irq failed\n");
return ret;
}
ret = of_property_read_u32(pdev->dev.of_node, "calibration",
&calibvalue);
if (ret)
calibvalue = RTC_CALIB_DEF;
xlnx_init_rtc(xrtcdev, calibvalue);
device_init_wakeup(&pdev->dev, 1);
xrtcdev->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&xlnx_rtc_ops, THIS_MODULE);
return PTR_ERR_OR_ZERO(xrtcdev->rtc);
}
static int xlnx_rtc_remove(struct platform_device *pdev)
{
xlnx_rtc_alarm_irq_enable(&pdev->dev, 0);
device_init_wakeup(&pdev->dev, 0);
return 0;
}
static int __maybe_unused xlnx_rtc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct xlnx_rtc_dev *xrtcdev = platform_get_drvdata(pdev);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(xrtcdev->alarm_irq);
else
xlnx_rtc_alarm_irq_enable(dev, 0);
return 0;
}
static int __maybe_unused xlnx_rtc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct xlnx_rtc_dev *xrtcdev = platform_get_drvdata(pdev);
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(xrtcdev->alarm_irq);
else
xlnx_rtc_alarm_irq_enable(dev, 1);
return 0;
}
