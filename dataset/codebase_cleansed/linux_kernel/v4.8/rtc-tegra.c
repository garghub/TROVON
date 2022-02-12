static inline u32 tegra_rtc_check_busy(struct tegra_rtc_info *info)
{
return readl(info->rtc_base + TEGRA_RTC_REG_BUSY) & 1;
}
static int tegra_rtc_wait_while_busy(struct device *dev)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
int retries = 500;
while (tegra_rtc_check_busy(info)) {
if (!retries--)
goto retry_failed;
udelay(1);
}
return 0;
retry_failed:
dev_err(dev, "write failed:retry count exceeded.\n");
return -ETIMEDOUT;
}
static int tegra_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
unsigned long sec, msec;
unsigned long sl_irq_flags;
spin_lock_irqsave(&info->tegra_rtc_lock, sl_irq_flags);
msec = readl(info->rtc_base + TEGRA_RTC_REG_MILLI_SECONDS);
sec = readl(info->rtc_base + TEGRA_RTC_REG_SHADOW_SECONDS);
spin_unlock_irqrestore(&info->tegra_rtc_lock, sl_irq_flags);
rtc_time_to_tm(sec, tm);
dev_vdbg(dev, "time read as %lu. %d/%d/%d %d:%02u:%02u\n",
sec,
tm->tm_mon + 1,
tm->tm_mday,
tm->tm_year + 1900,
tm->tm_hour,
tm->tm_min,
tm->tm_sec
);
return 0;
}
static int tegra_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
unsigned long sec;
int ret;
ret = rtc_valid_tm(tm);
if (ret)
return ret;
rtc_tm_to_time(tm, &sec);
dev_vdbg(dev, "time set to %lu. %d/%d/%d %d:%02u:%02u\n",
sec,
tm->tm_mon+1,
tm->tm_mday,
tm->tm_year+1900,
tm->tm_hour,
tm->tm_min,
tm->tm_sec
);
ret = tegra_rtc_wait_while_busy(dev);
if (!ret)
writel(sec, info->rtc_base + TEGRA_RTC_REG_SECONDS);
dev_vdbg(dev, "time read back as %d\n",
readl(info->rtc_base + TEGRA_RTC_REG_SECONDS));
return ret;
}
static int tegra_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
unsigned long sec;
unsigned tmp;
sec = readl(info->rtc_base + TEGRA_RTC_REG_SECONDS_ALARM0);
if (sec == 0) {
alarm->enabled = 0;
} else {
alarm->enabled = 1;
rtc_time_to_tm(sec, &alarm->time);
}
tmp = readl(info->rtc_base + TEGRA_RTC_REG_INTR_STATUS);
alarm->pending = (tmp & TEGRA_RTC_INTR_STATUS_SEC_ALARM0) != 0;
return 0;
}
static int tegra_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
unsigned status;
unsigned long sl_irq_flags;
tegra_rtc_wait_while_busy(dev);
spin_lock_irqsave(&info->tegra_rtc_lock, sl_irq_flags);
status = readl(info->rtc_base + TEGRA_RTC_REG_INTR_MASK);
if (enabled)
status |= TEGRA_RTC_INTR_MASK_SEC_ALARM0;
else
status &= ~TEGRA_RTC_INTR_MASK_SEC_ALARM0;
writel(status, info->rtc_base + TEGRA_RTC_REG_INTR_MASK);
spin_unlock_irqrestore(&info->tegra_rtc_lock, sl_irq_flags);
return 0;
}
static int tegra_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
unsigned long sec;
if (alarm->enabled)
rtc_tm_to_time(&alarm->time, &sec);
else
sec = 0;
tegra_rtc_wait_while_busy(dev);
writel(sec, info->rtc_base + TEGRA_RTC_REG_SECONDS_ALARM0);
dev_vdbg(dev, "alarm read back as %d\n",
readl(info->rtc_base + TEGRA_RTC_REG_SECONDS_ALARM0));
if (sec) {
tegra_rtc_alarm_irq_enable(dev, 1);
dev_vdbg(dev, "alarm set as %lu. %d/%d/%d %d:%02u:%02u\n",
sec,
alarm->time.tm_mon+1,
alarm->time.tm_mday,
alarm->time.tm_year+1900,
alarm->time.tm_hour,
alarm->time.tm_min,
alarm->time.tm_sec);
} else {
dev_vdbg(dev, "alarm disabled\n");
tegra_rtc_alarm_irq_enable(dev, 0);
}
return 0;
}
static int tegra_rtc_proc(struct device *dev, struct seq_file *seq)
{
if (!dev || !dev->driver)
return 0;
seq_printf(seq, "name\t\t: %s\n", dev_name(dev));
return 0;
}
static irqreturn_t tegra_rtc_irq_handler(int irq, void *data)
{
struct device *dev = data;
struct tegra_rtc_info *info = dev_get_drvdata(dev);
unsigned long events = 0;
unsigned status;
unsigned long sl_irq_flags;
status = readl(info->rtc_base + TEGRA_RTC_REG_INTR_STATUS);
if (status) {
tegra_rtc_wait_while_busy(dev);
spin_lock_irqsave(&info->tegra_rtc_lock, sl_irq_flags);
writel(0, info->rtc_base + TEGRA_RTC_REG_INTR_MASK);
writel(status, info->rtc_base + TEGRA_RTC_REG_INTR_STATUS);
spin_unlock_irqrestore(&info->tegra_rtc_lock, sl_irq_flags);
}
if ((status & TEGRA_RTC_INTR_STATUS_SEC_ALARM0))
events |= RTC_IRQF | RTC_AF;
if ((status & TEGRA_RTC_INTR_STATUS_SEC_CDN_ALARM))
events |= RTC_IRQF | RTC_PF;
rtc_update_irq(info->rtc_dev, 1, events);
return IRQ_HANDLED;
}
static int __init tegra_rtc_probe(struct platform_device *pdev)
{
struct tegra_rtc_info *info;
struct resource *res;
int ret;
info = devm_kzalloc(&pdev->dev, sizeof(struct tegra_rtc_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->rtc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->rtc_base))
return PTR_ERR(info->rtc_base);
info->tegra_rtc_irq = platform_get_irq(pdev, 0);
if (info->tegra_rtc_irq <= 0)
return -EBUSY;
info->pdev = pdev;
spin_lock_init(&info->tegra_rtc_lock);
platform_set_drvdata(pdev, info);
writel(0, info->rtc_base + TEGRA_RTC_REG_SECONDS_ALARM0);
writel(0xffffffff, info->rtc_base + TEGRA_RTC_REG_INTR_STATUS);
writel(0, info->rtc_base + TEGRA_RTC_REG_INTR_MASK);
device_init_wakeup(&pdev->dev, 1);
info->rtc_dev = devm_rtc_device_register(&pdev->dev,
dev_name(&pdev->dev), &tegra_rtc_ops,
THIS_MODULE);
if (IS_ERR(info->rtc_dev)) {
ret = PTR_ERR(info->rtc_dev);
dev_err(&pdev->dev, "Unable to register device (err=%d).\n",
ret);
return ret;
}
ret = devm_request_irq(&pdev->dev, info->tegra_rtc_irq,
tegra_rtc_irq_handler, IRQF_TRIGGER_HIGH,
dev_name(&pdev->dev), &pdev->dev);
if (ret) {
dev_err(&pdev->dev,
"Unable to request interrupt for device (err=%d).\n",
ret);
return ret;
}
dev_notice(&pdev->dev, "Tegra internal Real Time Clock\n");
return 0;
}
static int tegra_rtc_suspend(struct device *dev)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
tegra_rtc_wait_while_busy(dev);
writel(0xffffffff, info->rtc_base + TEGRA_RTC_REG_INTR_STATUS);
writel(TEGRA_RTC_INTR_STATUS_SEC_ALARM0,
info->rtc_base + TEGRA_RTC_REG_INTR_MASK);
dev_vdbg(dev, "alarm sec = %d\n",
readl(info->rtc_base + TEGRA_RTC_REG_SECONDS_ALARM0));
dev_vdbg(dev, "Suspend (device_may_wakeup=%d) irq:%d\n",
device_may_wakeup(dev), info->tegra_rtc_irq);
if (device_may_wakeup(dev))
enable_irq_wake(info->tegra_rtc_irq);
return 0;
}
static int tegra_rtc_resume(struct device *dev)
{
struct tegra_rtc_info *info = dev_get_drvdata(dev);
dev_vdbg(dev, "Resume (device_may_wakeup=%d)\n",
device_may_wakeup(dev));
if (device_may_wakeup(dev))
disable_irq_wake(info->tegra_rtc_irq);
return 0;
}
static void tegra_rtc_shutdown(struct platform_device *pdev)
{
dev_vdbg(&pdev->dev, "disabling interrupts.\n");
tegra_rtc_alarm_irq_enable(&pdev->dev, 0);
}
