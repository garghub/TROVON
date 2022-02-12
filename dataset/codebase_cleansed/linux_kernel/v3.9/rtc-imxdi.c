static void di_int_enable(struct imxdi_dev *imxdi, u32 intr)
{
unsigned long flags;
spin_lock_irqsave(&imxdi->irq_lock, flags);
__raw_writel(__raw_readl(imxdi->ioaddr + DIER) | intr,
imxdi->ioaddr + DIER);
spin_unlock_irqrestore(&imxdi->irq_lock, flags);
}
static void di_int_disable(struct imxdi_dev *imxdi, u32 intr)
{
unsigned long flags;
spin_lock_irqsave(&imxdi->irq_lock, flags);
__raw_writel(__raw_readl(imxdi->ioaddr + DIER) & ~intr,
imxdi->ioaddr + DIER);
spin_unlock_irqrestore(&imxdi->irq_lock, flags);
}
static void clear_write_error(struct imxdi_dev *imxdi)
{
int cnt;
dev_warn(&imxdi->pdev->dev, "WARNING: Register write error!\n");
__raw_writel(DSR_WEF, imxdi->ioaddr + DSR);
for (cnt = 0; cnt < 1000; cnt++) {
if ((__raw_readl(imxdi->ioaddr + DSR) & DSR_WEF) == 0)
return;
udelay(10);
}
dev_err(&imxdi->pdev->dev,
"ERROR: Cannot clear write-error flag!\n");
}
static int di_write_wait(struct imxdi_dev *imxdi, u32 val, int reg)
{
int ret;
int rc = 0;
mutex_lock(&imxdi->write_mutex);
di_int_enable(imxdi, DIER_WCIE);
imxdi->dsr = 0;
__raw_writel(val, imxdi->ioaddr + reg);
ret = wait_event_interruptible_timeout(imxdi->write_wait,
imxdi->dsr & (DSR_WCF | DSR_WEF), msecs_to_jiffies(1));
if (ret < 0) {
rc = ret;
goto out;
} else if (ret == 0) {
dev_warn(&imxdi->pdev->dev,
"Write-wait timeout "
"val = 0x%08x reg = 0x%08x\n", val, reg);
}
if (imxdi->dsr & DSR_WEF) {
clear_write_error(imxdi);
rc = -EIO;
}
out:
mutex_unlock(&imxdi->write_mutex);
return rc;
}
static int dryice_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
unsigned long now;
now = __raw_readl(imxdi->ioaddr + DTCMR);
rtc_time_to_tm(now, tm);
return 0;
}
static int dryice_rtc_set_mmss(struct device *dev, unsigned long secs)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
int rc;
rc = di_write_wait(imxdi, 0, DTCLR);
if (rc == 0)
rc = di_write_wait(imxdi, secs, DTCMR);
return rc;
}
static int dryice_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
if (enabled)
di_int_enable(imxdi, DIER_CAIE);
else
di_int_disable(imxdi, DIER_CAIE);
return 0;
}
static int dryice_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
u32 dcamr;
dcamr = __raw_readl(imxdi->ioaddr + DCAMR);
rtc_time_to_tm(dcamr, &alarm->time);
alarm->enabled = (__raw_readl(imxdi->ioaddr + DIER) & DIER_CAIE) != 0;
mutex_lock(&imxdi->write_mutex);
alarm->pending = (__raw_readl(imxdi->ioaddr + DSR) & DSR_CAF) != 0;
mutex_unlock(&imxdi->write_mutex);
return 0;
}
static int dryice_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
unsigned long now;
unsigned long alarm_time;
int rc;
rc = rtc_tm_to_time(&alarm->time, &alarm_time);
if (rc)
return rc;
now = __raw_readl(imxdi->ioaddr + DTCMR);
if (alarm_time < now)
return -EINVAL;
rc = di_write_wait(imxdi, (u32)alarm_time, DCAMR);
if (rc)
return rc;
if (alarm->enabled)
di_int_enable(imxdi, DIER_CAIE);
else
di_int_disable(imxdi, DIER_CAIE);
return 0;
}
static irqreturn_t dryice_norm_irq(int irq, void *dev_id)
{
struct imxdi_dev *imxdi = dev_id;
u32 dsr, dier;
irqreturn_t rc = IRQ_NONE;
dier = __raw_readl(imxdi->ioaddr + DIER);
if ((dier & DIER_WCIE)) {
if (list_empty_careful(&imxdi->write_wait.task_list))
return rc;
dsr = __raw_readl(imxdi->ioaddr + DSR);
if ((dsr & (DSR_WCF | DSR_WEF))) {
di_int_disable(imxdi, DIER_WCIE);
imxdi->dsr |= dsr;
wake_up_interruptible(&imxdi->write_wait);
rc = IRQ_HANDLED;
}
}
if ((dier & DIER_CAIE)) {
dsr = __raw_readl(imxdi->ioaddr + DSR);
if (dsr & DSR_CAF) {
di_int_disable(imxdi, DIER_CAIE);
schedule_work(&imxdi->work);
rc = IRQ_HANDLED;
}
}
return rc;
}
static void dryice_work(struct work_struct *work)
{
struct imxdi_dev *imxdi = container_of(work,
struct imxdi_dev, work);
di_write_wait(imxdi, DSR_CAF, DSR);
rtc_update_irq(imxdi->rtc, 1, RTC_AF | RTC_IRQF);
}
static int dryice_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct imxdi_dev *imxdi;
int rc;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
imxdi = devm_kzalloc(&pdev->dev, sizeof(*imxdi), GFP_KERNEL);
if (!imxdi)
return -ENOMEM;
imxdi->pdev = pdev;
if (!devm_request_mem_region(&pdev->dev, res->start, resource_size(res),
pdev->name))
return -EBUSY;
imxdi->ioaddr = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (imxdi->ioaddr == NULL)
return -ENOMEM;
spin_lock_init(&imxdi->irq_lock);
imxdi->irq = platform_get_irq(pdev, 0);
if (imxdi->irq < 0)
return imxdi->irq;
init_waitqueue_head(&imxdi->write_wait);
INIT_WORK(&imxdi->work, dryice_work);
mutex_init(&imxdi->write_mutex);
imxdi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(imxdi->clk))
return PTR_ERR(imxdi->clk);
clk_prepare_enable(imxdi->clk);
__raw_writel(0, imxdi->ioaddr + DIER);
rc = devm_request_irq(&pdev->dev, imxdi->irq, dryice_norm_irq,
IRQF_SHARED, pdev->name, imxdi);
if (rc) {
dev_warn(&pdev->dev, "interrupt not available.\n");
goto err;
}
if (__raw_readl(imxdi->ioaddr + DSR) & DSR_NVF) {
rc = di_write_wait(imxdi, DSR_NVF | DSR_SVF, DSR);
if (rc)
goto err;
}
rc = di_write_wait(imxdi, DCAMR_UNSET, DCAMR);
if (rc)
goto err;
rc = di_write_wait(imxdi, 0, DCALR);
if (rc)
goto err;
if (__raw_readl(imxdi->ioaddr + DSR) & DSR_CAF) {
rc = di_write_wait(imxdi, DSR_CAF, DSR);
if (rc)
goto err;
}
if (__raw_readl(imxdi->ioaddr + DTCMR) == 0) {
rc = di_write_wait(imxdi, 0, DTCMR);
if (rc)
goto err;
}
if (!(__raw_readl(imxdi->ioaddr + DCR) & DCR_TCE)) {
rc = di_write_wait(imxdi,
__raw_readl(imxdi->ioaddr + DCR) | DCR_TCE,
DCR);
if (rc)
goto err;
}
platform_set_drvdata(pdev, imxdi);
imxdi->rtc = rtc_device_register(pdev->name, &pdev->dev,
&dryice_rtc_ops, THIS_MODULE);
if (IS_ERR(imxdi->rtc)) {
rc = PTR_ERR(imxdi->rtc);
goto err;
}
return 0;
err:
clk_disable_unprepare(imxdi->clk);
return rc;
}
static int dryice_rtc_remove(struct platform_device *pdev)
{
struct imxdi_dev *imxdi = platform_get_drvdata(pdev);
flush_work(&imxdi->work);
__raw_writel(0, imxdi->ioaddr + DIER);
rtc_device_unregister(imxdi->rtc);
clk_disable_unprepare(imxdi->clk);
return 0;
}
static int __init dryice_rtc_init(void)
{
return platform_driver_probe(&dryice_rtc_driver, dryice_rtc_probe);
}
static void __exit dryice_rtc_exit(void)
{
platform_driver_unregister(&dryice_rtc_driver);
}
