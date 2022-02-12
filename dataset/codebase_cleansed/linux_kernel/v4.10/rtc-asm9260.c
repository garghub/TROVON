static irqreturn_t asm9260_rtc_irq(int irq, void *dev_id)
{
struct asm9260_rtc_priv *priv = dev_id;
u32 isr;
unsigned long events = 0;
mutex_lock(&priv->rtc->ops_lock);
isr = ioread32(priv->iobase + HW_CIIR);
if (!isr) {
mutex_unlock(&priv->rtc->ops_lock);
return IRQ_NONE;
}
iowrite32(0, priv->iobase + HW_CIIR);
mutex_unlock(&priv->rtc->ops_lock);
events |= RTC_AF | RTC_IRQF;
rtc_update_irq(priv->rtc, 1, events);
return IRQ_HANDLED;
}
static int asm9260_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct asm9260_rtc_priv *priv = dev_get_drvdata(dev);
u32 ctime0, ctime1, ctime2;
ctime0 = ioread32(priv->iobase + HW_CTIME0);
ctime1 = ioread32(priv->iobase + HW_CTIME1);
ctime2 = ioread32(priv->iobase + HW_CTIME2);
if (ctime1 != ioread32(priv->iobase + HW_CTIME1)) {
ctime0 = ioread32(priv->iobase + HW_CTIME0);
ctime1 = ioread32(priv->iobase + HW_CTIME1);
ctime2 = ioread32(priv->iobase + HW_CTIME2);
}
tm->tm_sec = (ctime0 >> BM_CTIME0_SEC_S) & BM_CTIME0_SEC_M;
tm->tm_min = (ctime0 >> BM_CTIME0_MIN_S) & BM_CTIME0_MIN_M;
tm->tm_hour = (ctime0 >> BM_CTIME0_HOUR_S) & BM_CTIME0_HOUR_M;
tm->tm_wday = (ctime0 >> BM_CTIME0_DOW_S) & BM_CTIME0_DOW_M;
tm->tm_mday = (ctime1 >> BM_CTIME1_DOM_S) & BM_CTIME1_DOM_M;
tm->tm_mon = (ctime1 >> BM_CTIME1_MON_S) & BM_CTIME1_MON_M;
tm->tm_year = (ctime1 >> BM_CTIME1_YEAR_S) & BM_CTIME1_YEAR_M;
tm->tm_yday = (ctime2 >> BM_CTIME2_DOY_S) & BM_CTIME2_DOY_M;
return 0;
}
static int asm9260_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct asm9260_rtc_priv *priv = dev_get_drvdata(dev);
iowrite32(0, priv->iobase + HW_SEC);
iowrite32(tm->tm_year, priv->iobase + HW_YEAR);
iowrite32(tm->tm_mon, priv->iobase + HW_MONTH);
iowrite32(tm->tm_mday, priv->iobase + HW_DOM);
iowrite32(tm->tm_wday, priv->iobase + HW_DOW);
iowrite32(tm->tm_yday, priv->iobase + HW_DOY);
iowrite32(tm->tm_hour, priv->iobase + HW_HOUR);
iowrite32(tm->tm_min, priv->iobase + HW_MIN);
iowrite32(tm->tm_sec, priv->iobase + HW_SEC);
return 0;
}
static int asm9260_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct asm9260_rtc_priv *priv = dev_get_drvdata(dev);
alrm->time.tm_year = ioread32(priv->iobase + HW_ALYEAR);
alrm->time.tm_mon = ioread32(priv->iobase + HW_ALMON);
alrm->time.tm_mday = ioread32(priv->iobase + HW_ALDOM);
alrm->time.tm_wday = ioread32(priv->iobase + HW_ALDOW);
alrm->time.tm_yday = ioread32(priv->iobase + HW_ALDOY);
alrm->time.tm_hour = ioread32(priv->iobase + HW_ALHOUR);
alrm->time.tm_min = ioread32(priv->iobase + HW_ALMIN);
alrm->time.tm_sec = ioread32(priv->iobase + HW_ALSEC);
alrm->enabled = ioread32(priv->iobase + HW_AMR) ? 1 : 0;
alrm->pending = ioread32(priv->iobase + HW_CIIR) ? 1 : 0;
return rtc_valid_tm(&alrm->time);
}
static int asm9260_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct asm9260_rtc_priv *priv = dev_get_drvdata(dev);
iowrite32(alrm->time.tm_year, priv->iobase + HW_ALYEAR);
iowrite32(alrm->time.tm_mon, priv->iobase + HW_ALMON);
iowrite32(alrm->time.tm_mday, priv->iobase + HW_ALDOM);
iowrite32(alrm->time.tm_wday, priv->iobase + HW_ALDOW);
iowrite32(alrm->time.tm_yday, priv->iobase + HW_ALDOY);
iowrite32(alrm->time.tm_hour, priv->iobase + HW_ALHOUR);
iowrite32(alrm->time.tm_min, priv->iobase + HW_ALMIN);
iowrite32(alrm->time.tm_sec, priv->iobase + HW_ALSEC);
iowrite32(alrm->enabled ? 0 : BM_AMR_OFF, priv->iobase + HW_AMR);
return 0;
}
static int asm9260_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct asm9260_rtc_priv *priv = dev_get_drvdata(dev);
iowrite32(enabled ? 0 : BM_AMR_OFF, priv->iobase + HW_AMR);
return 0;
}
static int asm9260_rtc_probe(struct platform_device *pdev)
{
struct asm9260_rtc_priv *priv;
struct device *dev = &pdev->dev;
struct resource *res;
int irq_alarm, ret;
u32 ccr;
priv = devm_kzalloc(dev, sizeof(struct asm9260_rtc_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = &pdev->dev;
platform_set_drvdata(pdev, priv);
irq_alarm = platform_get_irq(pdev, 0);
if (irq_alarm < 0) {
dev_err(dev, "No alarm IRQ resource defined\n");
return irq_alarm;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->iobase = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->iobase))
return PTR_ERR(priv->iobase);
priv->clk = devm_clk_get(dev, "ahb");
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "Failed to enable clk!\n");
return ret;
}
ccr = ioread32(priv->iobase + HW_CCR);
if ((ccr & (BM_CLKEN | BM_CTCRST)) != BM_CLKEN) {
iowrite32(BM_CTCRST, priv->iobase + HW_CCR);
ccr = 0;
}
iowrite32(BM_CLKEN | ccr, priv->iobase + HW_CCR);
iowrite32(0, priv->iobase + HW_CIIR);
iowrite32(BM_AMR_OFF, priv->iobase + HW_AMR);
priv->rtc = devm_rtc_device_register(dev, dev_name(dev),
&asm9260_rtc_ops, THIS_MODULE);
if (IS_ERR(priv->rtc)) {
ret = PTR_ERR(priv->rtc);
dev_err(dev, "Failed to register RTC device: %d\n", ret);
goto err_return;
}
ret = devm_request_threaded_irq(dev, irq_alarm, NULL,
asm9260_rtc_irq, IRQF_ONESHOT,
dev_name(dev), priv);
if (ret < 0) {
dev_err(dev, "can't get irq %i, err %d\n",
irq_alarm, ret);
goto err_return;
}
return 0;
err_return:
clk_disable_unprepare(priv->clk);
return ret;
}
static int asm9260_rtc_remove(struct platform_device *pdev)
{
struct asm9260_rtc_priv *priv = platform_get_drvdata(pdev);
iowrite32(BM_AMR_OFF, priv->iobase + HW_AMR);
clk_disable_unprepare(priv->clk);
return 0;
}
