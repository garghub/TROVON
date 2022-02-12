static int mtk_rtc_write_trigger(struct mt6397_rtc *rtc)
{
unsigned long timeout = jiffies + HZ;
int ret;
u32 data;
ret = regmap_write(rtc->regmap, rtc->addr_base + RTC_WRTGR, 1);
if (ret < 0)
return ret;
while (1) {
ret = regmap_read(rtc->regmap, rtc->addr_base + RTC_BBPU,
&data);
if (ret < 0)
break;
if (!(data & RTC_BBPU_CBUSY))
break;
if (time_after(jiffies, timeout)) {
ret = -ETIMEDOUT;
break;
}
cpu_relax();
}
return ret;
}
static irqreturn_t mtk_rtc_irq_handler_thread(int irq, void *data)
{
struct mt6397_rtc *rtc = data;
u32 irqsta, irqen;
int ret;
ret = regmap_read(rtc->regmap, rtc->addr_base + RTC_IRQ_STA, &irqsta);
if ((ret >= 0) && (irqsta & RTC_IRQ_STA_AL)) {
rtc_update_irq(rtc->rtc_dev, 1, RTC_IRQF | RTC_AF);
irqen = irqsta & ~RTC_IRQ_EN_AL;
mutex_lock(&rtc->lock);
if (regmap_write(rtc->regmap, rtc->addr_base + RTC_IRQ_EN,
irqen) < 0)
mtk_rtc_write_trigger(rtc);
mutex_unlock(&rtc->lock);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int __mtk_rtc_read_time(struct mt6397_rtc *rtc,
struct rtc_time *tm, int *sec)
{
int ret;
u16 data[RTC_OFFSET_COUNT];
mutex_lock(&rtc->lock);
ret = regmap_bulk_read(rtc->regmap, rtc->addr_base + RTC_TC_SEC,
data, RTC_OFFSET_COUNT);
if (ret < 0)
goto exit;
tm->tm_sec = data[RTC_OFFSET_SEC];
tm->tm_min = data[RTC_OFFSET_MIN];
tm->tm_hour = data[RTC_OFFSET_HOUR];
tm->tm_mday = data[RTC_OFFSET_DOM];
tm->tm_mon = data[RTC_OFFSET_MTH];
tm->tm_year = data[RTC_OFFSET_YEAR];
ret = regmap_read(rtc->regmap, rtc->addr_base + RTC_TC_SEC, sec);
exit:
mutex_unlock(&rtc->lock);
return ret;
}
static int mtk_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
time64_t time;
struct mt6397_rtc *rtc = dev_get_drvdata(dev);
int days, sec, ret;
do {
ret = __mtk_rtc_read_time(rtc, tm, &sec);
if (ret < 0)
goto exit;
} while (sec < tm->tm_sec);
tm->tm_year += RTC_MIN_YEAR_OFFSET;
tm->tm_mon--;
time = rtc_tm_to_time64(tm);
days = div_s64(time, 86400);
tm->tm_wday = (days + 4) % 7;
exit:
return ret;
}
static int mtk_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct mt6397_rtc *rtc = dev_get_drvdata(dev);
int ret;
u16 data[RTC_OFFSET_COUNT];
tm->tm_year -= RTC_MIN_YEAR_OFFSET;
tm->tm_mon++;
data[RTC_OFFSET_SEC] = tm->tm_sec;
data[RTC_OFFSET_MIN] = tm->tm_min;
data[RTC_OFFSET_HOUR] = tm->tm_hour;
data[RTC_OFFSET_DOM] = tm->tm_mday;
data[RTC_OFFSET_MTH] = tm->tm_mon;
data[RTC_OFFSET_YEAR] = tm->tm_year;
mutex_lock(&rtc->lock);
ret = regmap_bulk_write(rtc->regmap, rtc->addr_base + RTC_TC_SEC,
data, RTC_OFFSET_COUNT);
if (ret < 0)
goto exit;
ret = mtk_rtc_write_trigger(rtc);
exit:
mutex_unlock(&rtc->lock);
return ret;
}
static int mtk_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct rtc_time *tm = &alm->time;
struct mt6397_rtc *rtc = dev_get_drvdata(dev);
u32 irqen, pdn2;
int ret;
u16 data[RTC_OFFSET_COUNT];
mutex_lock(&rtc->lock);
ret = regmap_read(rtc->regmap, rtc->addr_base + RTC_IRQ_EN, &irqen);
if (ret < 0)
goto err_exit;
ret = regmap_read(rtc->regmap, rtc->addr_base + RTC_PDN2, &pdn2);
if (ret < 0)
goto err_exit;
ret = regmap_bulk_read(rtc->regmap, rtc->addr_base + RTC_AL_SEC,
data, RTC_OFFSET_COUNT);
if (ret < 0)
goto err_exit;
alm->enabled = !!(irqen & RTC_IRQ_EN_AL);
alm->pending = !!(pdn2 & RTC_PDN2_PWRON_ALARM);
mutex_unlock(&rtc->lock);
tm->tm_sec = data[RTC_OFFSET_SEC];
tm->tm_min = data[RTC_OFFSET_MIN];
tm->tm_hour = data[RTC_OFFSET_HOUR];
tm->tm_mday = data[RTC_OFFSET_DOM];
tm->tm_mon = data[RTC_OFFSET_MTH];
tm->tm_year = data[RTC_OFFSET_YEAR];
tm->tm_year += RTC_MIN_YEAR_OFFSET;
tm->tm_mon--;
return 0;
err_exit:
mutex_unlock(&rtc->lock);
return ret;
}
static int mtk_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct rtc_time *tm = &alm->time;
struct mt6397_rtc *rtc = dev_get_drvdata(dev);
int ret;
u16 data[RTC_OFFSET_COUNT];
tm->tm_year -= RTC_MIN_YEAR_OFFSET;
tm->tm_mon++;
data[RTC_OFFSET_SEC] = tm->tm_sec;
data[RTC_OFFSET_MIN] = tm->tm_min;
data[RTC_OFFSET_HOUR] = tm->tm_hour;
data[RTC_OFFSET_DOM] = tm->tm_mday;
data[RTC_OFFSET_MTH] = tm->tm_mon;
data[RTC_OFFSET_YEAR] = tm->tm_year;
mutex_lock(&rtc->lock);
if (alm->enabled) {
ret = regmap_bulk_write(rtc->regmap,
rtc->addr_base + RTC_AL_SEC,
data, RTC_OFFSET_COUNT);
if (ret < 0)
goto exit;
ret = regmap_write(rtc->regmap, rtc->addr_base + RTC_AL_MASK,
RTC_AL_MASK_DOW);
if (ret < 0)
goto exit;
ret = regmap_update_bits(rtc->regmap,
rtc->addr_base + RTC_IRQ_EN,
RTC_IRQ_EN_ONESHOT_AL,
RTC_IRQ_EN_ONESHOT_AL);
if (ret < 0)
goto exit;
} else {
ret = regmap_update_bits(rtc->regmap,
rtc->addr_base + RTC_IRQ_EN,
RTC_IRQ_EN_ONESHOT_AL, 0);
if (ret < 0)
goto exit;
}
ret = mtk_rtc_write_trigger(rtc);
exit:
mutex_unlock(&rtc->lock);
return ret;
}
static int mtk_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct mt6397_chip *mt6397_chip = dev_get_drvdata(pdev->dev.parent);
struct mt6397_rtc *rtc;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(struct mt6397_rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc->addr_base = res->start;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
rtc->irq = irq_create_mapping(mt6397_chip->irq_domain, res->start);
if (rtc->irq <= 0)
return -EINVAL;
rtc->regmap = mt6397_chip->regmap;
rtc->dev = &pdev->dev;
mutex_init(&rtc->lock);
platform_set_drvdata(pdev, rtc);
ret = request_threaded_irq(rtc->irq, NULL,
mtk_rtc_irq_handler_thread,
IRQF_ONESHOT | IRQF_TRIGGER_HIGH,
"mt6397-rtc", rtc);
if (ret) {
dev_err(&pdev->dev, "Failed to request alarm IRQ: %d: %d\n",
rtc->irq, ret);
goto out_dispose_irq;
}
device_init_wakeup(&pdev->dev, 1);
rtc->rtc_dev = rtc_device_register("mt6397-rtc", &pdev->dev,
&mtk_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev)) {
dev_err(&pdev->dev, "register rtc device failed\n");
ret = PTR_ERR(rtc->rtc_dev);
goto out_free_irq;
}
return 0;
out_free_irq:
free_irq(rtc->irq, rtc->rtc_dev);
out_dispose_irq:
irq_dispose_mapping(rtc->irq);
return ret;
}
static int mtk_rtc_remove(struct platform_device *pdev)
{
struct mt6397_rtc *rtc = platform_get_drvdata(pdev);
rtc_device_unregister(rtc->rtc_dev);
free_irq(rtc->irq, rtc->rtc_dev);
irq_dispose_mapping(rtc->irq);
return 0;
}
