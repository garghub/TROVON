static u32 ryxr_calc(struct rtc_time *tm)
{
return ((tm->tm_year + 1900) << RYxR_YEAR_S)
| ((tm->tm_mon + 1) << RYxR_MONTH_S)
| tm->tm_mday;
}
static u32 rdxr_calc(struct rtc_time *tm)
{
return ((((tm->tm_mday + 6) / 7) << RDxR_WOM_S) & RDxR_WOM_MASK)
| (((tm->tm_wday + 1) << RDxR_DOW_S) & RDxR_DOW_MASK)
| (tm->tm_hour << RDxR_HOUR_S)
| (tm->tm_min << RDxR_MIN_S)
| tm->tm_sec;
}
static void tm_calc(u32 rycr, u32 rdcr, struct rtc_time *tm)
{
tm->tm_year = ((rycr & RYxR_YEAR_MASK) >> RYxR_YEAR_S) - 1900;
tm->tm_mon = (((rycr & RYxR_MONTH_MASK) >> RYxR_MONTH_S)) - 1;
tm->tm_mday = (rycr & RYxR_DAY_MASK);
tm->tm_wday = ((rycr & RDxR_DOW_MASK) >> RDxR_DOW_S) - 1;
tm->tm_hour = (rdcr & RDxR_HOUR_MASK) >> RDxR_HOUR_S;
tm->tm_min = (rdcr & RDxR_MIN_MASK) >> RDxR_MIN_S;
tm->tm_sec = rdcr & RDxR_SEC_MASK;
}
static void rtsr_clear_bits(struct pxa_rtc *pxa_rtc, u32 mask)
{
u32 rtsr;
rtsr = rtc_readl(pxa_rtc, RTSR);
rtsr &= ~RTSR_TRIG_MASK;
rtsr &= ~mask;
rtc_writel(pxa_rtc, RTSR, rtsr);
}
static void rtsr_set_bits(struct pxa_rtc *pxa_rtc, u32 mask)
{
u32 rtsr;
rtsr = rtc_readl(pxa_rtc, RTSR);
rtsr &= ~RTSR_TRIG_MASK;
rtsr |= mask;
rtc_writel(pxa_rtc, RTSR, rtsr);
}
static irqreturn_t pxa_rtc_irq(int irq, void *dev_id)
{
struct platform_device *pdev = to_platform_device(dev_id);
struct pxa_rtc *pxa_rtc = platform_get_drvdata(pdev);
u32 rtsr;
unsigned long events = 0;
spin_lock(&pxa_rtc->lock);
rtsr = rtc_readl(pxa_rtc, RTSR);
rtc_writel(pxa_rtc, RTSR, rtsr);
rtsr_clear_bits(pxa_rtc, RTSR_RDALE1 | RTSR_PIALE | RTSR_HZE);
if (rtsr & RTSR_RDAL1)
rtsr &= ~RTSR_RDALE1;
if (rtsr & RTSR_RDAL1)
events |= RTC_AF | RTC_IRQF;
if (rtsr & RTSR_HZ)
events |= RTC_UF | RTC_IRQF;
if (rtsr & RTSR_PIAL)
events |= RTC_PF | RTC_IRQF;
rtc_update_irq(pxa_rtc->rtc, 1, events);
rtc_writel(pxa_rtc, RTSR, rtsr & ~RTSR_TRIG_MASK);
spin_unlock(&pxa_rtc->lock);
return IRQ_HANDLED;
}
static int pxa_rtc_open(struct device *dev)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
int ret;
ret = request_irq(pxa_rtc->irq_1Hz, pxa_rtc_irq, 0,
"rtc 1Hz", dev);
if (ret < 0) {
dev_err(dev, "can't get irq %i, err %d\n", pxa_rtc->irq_1Hz,
ret);
goto err_irq_1Hz;
}
ret = request_irq(pxa_rtc->irq_Alrm, pxa_rtc_irq, 0,
"rtc Alrm", dev);
if (ret < 0) {
dev_err(dev, "can't get irq %i, err %d\n", pxa_rtc->irq_Alrm,
ret);
goto err_irq_Alrm;
}
return 0;
err_irq_Alrm:
free_irq(pxa_rtc->irq_1Hz, dev);
err_irq_1Hz:
return ret;
}
static void pxa_rtc_release(struct device *dev)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
spin_lock_irq(&pxa_rtc->lock);
rtsr_clear_bits(pxa_rtc, RTSR_PIALE | RTSR_RDALE1 | RTSR_HZE);
spin_unlock_irq(&pxa_rtc->lock);
free_irq(pxa_rtc->irq_Alrm, dev);
free_irq(pxa_rtc->irq_1Hz, dev);
}
static int pxa_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
spin_lock_irq(&pxa_rtc->lock);
if (enabled)
rtsr_set_bits(pxa_rtc, RTSR_RDALE1);
else
rtsr_clear_bits(pxa_rtc, RTSR_RDALE1);
spin_unlock_irq(&pxa_rtc->lock);
return 0;
}
static int pxa_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
u32 rycr, rdcr;
rycr = rtc_readl(pxa_rtc, RYCR);
rdcr = rtc_readl(pxa_rtc, RDCR);
tm_calc(rycr, rdcr, tm);
return 0;
}
static int pxa_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
rtc_writel(pxa_rtc, RYCR, ryxr_calc(tm));
rtc_writel(pxa_rtc, RDCR, rdxr_calc(tm));
return 0;
}
static int pxa_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
u32 rtsr, ryar, rdar;
ryar = rtc_readl(pxa_rtc, RYAR1);
rdar = rtc_readl(pxa_rtc, RDAR1);
tm_calc(ryar, rdar, &alrm->time);
rtsr = rtc_readl(pxa_rtc, RTSR);
alrm->enabled = (rtsr & RTSR_RDALE1) ? 1 : 0;
alrm->pending = (rtsr & RTSR_RDAL1) ? 1 : 0;
return 0;
}
static int pxa_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
u32 rtsr;
spin_lock_irq(&pxa_rtc->lock);
rtc_writel(pxa_rtc, RYAR1, ryxr_calc(&alrm->time));
rtc_writel(pxa_rtc, RDAR1, rdxr_calc(&alrm->time));
rtsr = rtc_readl(pxa_rtc, RTSR);
if (alrm->enabled)
rtsr |= RTSR_RDALE1;
else
rtsr &= ~RTSR_RDALE1;
rtc_writel(pxa_rtc, RTSR, rtsr);
spin_unlock_irq(&pxa_rtc->lock);
return 0;
}
static int pxa_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
seq_printf(seq, "trim/divider\t: 0x%08x\n", rtc_readl(pxa_rtc, RTTR));
seq_printf(seq, "update_IRQ\t: %s\n",
(rtc_readl(pxa_rtc, RTSR) & RTSR_HZE) ? "yes" : "no");
seq_printf(seq, "periodic_IRQ\t: %s\n",
(rtc_readl(pxa_rtc, RTSR) & RTSR_PIALE) ? "yes" : "no");
seq_printf(seq, "periodic_freq\t: %u\n", rtc_readl(pxa_rtc, PIAR));
return 0;
}
static int __init pxa_rtc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct pxa_rtc *pxa_rtc;
int ret;
u32 rttr;
pxa_rtc = kzalloc(sizeof(struct pxa_rtc), GFP_KERNEL);
if (!pxa_rtc)
return -ENOMEM;
spin_lock_init(&pxa_rtc->lock);
platform_set_drvdata(pdev, pxa_rtc);
ret = -ENXIO;
pxa_rtc->ress = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!pxa_rtc->ress) {
dev_err(dev, "No I/O memory resource defined\n");
goto err_ress;
}
pxa_rtc->irq_1Hz = platform_get_irq(pdev, 0);
if (pxa_rtc->irq_1Hz < 0) {
dev_err(dev, "No 1Hz IRQ resource defined\n");
goto err_ress;
}
pxa_rtc->irq_Alrm = platform_get_irq(pdev, 1);
if (pxa_rtc->irq_Alrm < 0) {
dev_err(dev, "No alarm IRQ resource defined\n");
goto err_ress;
}
pxa_rtc_open(dev);
ret = -ENOMEM;
pxa_rtc->base = ioremap(pxa_rtc->ress->start,
resource_size(pxa_rtc->ress));
if (!pxa_rtc->base) {
dev_err(&pdev->dev, "Unable to map pxa RTC I/O memory\n");
goto err_map;
}
if (rtc_readl(pxa_rtc, RTTR) == 0) {
rttr = RTC_DEF_DIVIDER + (RTC_DEF_TRIM << 16);
rtc_writel(pxa_rtc, RTTR, rttr);
dev_warn(dev, "warning: initializing default clock"
" divider/trim value\n");
}
rtsr_clear_bits(pxa_rtc, RTSR_PIALE | RTSR_RDALE1 | RTSR_HZE);
pxa_rtc->rtc = rtc_device_register("pxa-rtc", &pdev->dev, &pxa_rtc_ops,
THIS_MODULE);
ret = PTR_ERR(pxa_rtc->rtc);
if (IS_ERR(pxa_rtc->rtc)) {
dev_err(dev, "Failed to register RTC device -> %d\n", ret);
goto err_rtc_reg;
}
device_init_wakeup(dev, 1);
return 0;
err_rtc_reg:
iounmap(pxa_rtc->base);
err_ress:
err_map:
kfree(pxa_rtc);
return ret;
}
static int __exit pxa_rtc_remove(struct platform_device *pdev)
{
struct pxa_rtc *pxa_rtc = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
pxa_rtc_release(dev);
rtc_device_unregister(pxa_rtc->rtc);
spin_lock_irq(&pxa_rtc->lock);
iounmap(pxa_rtc->base);
spin_unlock_irq(&pxa_rtc->lock);
kfree(pxa_rtc);
return 0;
}
static int pxa_rtc_suspend(struct device *dev)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(pxa_rtc->irq_Alrm);
return 0;
}
static int pxa_rtc_resume(struct device *dev)
{
struct pxa_rtc *pxa_rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(pxa_rtc->irq_Alrm);
return 0;
}
