static int _to_tm_wday(u8 lp8788_wday)
{
int i;
if (lp8788_wday == 0)
return 0;
for (i = 0; i < MAX_WDAY_BITS; i++) {
if ((lp8788_wday >> i) == LP8788_WDAY_SET)
break;
}
return i + 1;
}
static inline int _to_lp8788_wday(int tm_wday)
{
return LP8788_WDAY_SET << (tm_wday - 1);
}
static void lp8788_rtc_unlock(struct lp8788 *lp)
{
lp8788_write_byte(lp, LP8788_RTC_UNLOCK, RTC_UNLOCK);
lp8788_write_byte(lp, LP8788_RTC_UNLOCK, RTC_LATCH);
}
static int lp8788_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct lp8788_rtc *rtc = dev_get_drvdata(dev);
struct lp8788 *lp = rtc->lp;
u8 data[LPTIME_MAX];
int ret;
lp8788_rtc_unlock(lp);
ret = lp8788_read_multi_bytes(lp, LP8788_RTC_SEC, data, LPTIME_MAX);
if (ret)
return ret;
tm->tm_sec = data[LPTIME_SEC];
tm->tm_min = data[LPTIME_MIN];
tm->tm_hour = data[LPTIME_HOUR];
tm->tm_mday = data[LPTIME_MDAY];
tm->tm_mon = data[LPTIME_MON] - LP8788_MONTH_OFFSET;
tm->tm_year = data[LPTIME_YEAR] + LP8788_BASE_YEAR - 1900;
tm->tm_wday = _to_tm_wday(data[LPTIME_WDAY]);
return 0;
}
static int lp8788_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct lp8788_rtc *rtc = dev_get_drvdata(dev);
struct lp8788 *lp = rtc->lp;
u8 data[LPTIME_MAX - 1];
int ret, i, year;
year = tm->tm_year + 1900 - LP8788_BASE_YEAR;
if (year < 0) {
dev_err(lp->dev, "invalid year: %d\n", year);
return -EINVAL;
}
data[LPTIME_SEC] = tm->tm_sec;
data[LPTIME_MIN] = tm->tm_min;
data[LPTIME_HOUR] = tm->tm_hour;
data[LPTIME_MDAY] = tm->tm_mday;
data[LPTIME_MON] = tm->tm_mon + LP8788_MONTH_OFFSET;
data[LPTIME_YEAR] = year;
for (i = 0; i < ARRAY_SIZE(data); i++) {
ret = lp8788_write_byte(lp, LP8788_RTC_SEC + i, data[i]);
if (ret)
return ret;
}
return 0;
}
static int lp8788_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct lp8788_rtc *rtc = dev_get_drvdata(dev);
struct lp8788 *lp = rtc->lp;
struct rtc_time *tm = &alarm->time;
u8 addr, data[LPTIME_MAX];
int ret;
addr = addr_alarm_sec[rtc->alarm];
ret = lp8788_read_multi_bytes(lp, addr, data, LPTIME_MAX);
if (ret)
return ret;
tm->tm_sec = data[LPTIME_SEC];
tm->tm_min = data[LPTIME_MIN];
tm->tm_hour = data[LPTIME_HOUR];
tm->tm_mday = data[LPTIME_MDAY];
tm->tm_mon = data[LPTIME_MON] - LP8788_MONTH_OFFSET;
tm->tm_year = data[LPTIME_YEAR] + LP8788_BASE_YEAR - 1900;
tm->tm_wday = _to_tm_wday(data[LPTIME_WDAY]);
alarm->enabled = data[LPTIME_WDAY] & LP8788_ALM_EN_M;
return 0;
}
static int lp8788_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct lp8788_rtc *rtc = dev_get_drvdata(dev);
struct lp8788 *lp = rtc->lp;
struct rtc_time *tm = &alarm->time;
u8 addr, data[LPTIME_MAX];
int ret, i, year;
year = tm->tm_year + 1900 - LP8788_BASE_YEAR;
if (year < 0) {
dev_err(lp->dev, "invalid year: %d\n", year);
return -EINVAL;
}
data[LPTIME_SEC] = tm->tm_sec;
data[LPTIME_MIN] = tm->tm_min;
data[LPTIME_HOUR] = tm->tm_hour;
data[LPTIME_MDAY] = tm->tm_mday;
data[LPTIME_MON] = tm->tm_mon + LP8788_MONTH_OFFSET;
data[LPTIME_YEAR] = year;
data[LPTIME_WDAY] = _to_lp8788_wday(tm->tm_wday);
for (i = 0; i < ARRAY_SIZE(data); i++) {
addr = addr_alarm_sec[rtc->alarm] + i;
ret = lp8788_write_byte(lp, addr, data[i]);
if (ret)
return ret;
}
alarm->enabled = 1;
addr = addr_alarm_en[rtc->alarm];
return lp8788_update_bits(lp, addr, LP8788_ALM_EN_M,
alarm->enabled << LP8788_ALM_EN_S);
}
static int lp8788_alarm_irq_enable(struct device *dev, unsigned int enable)
{
struct lp8788_rtc *rtc = dev_get_drvdata(dev);
struct lp8788 *lp = rtc->lp;
u8 mask, shift;
if (!rtc->irq)
return -EIO;
mask = mask_alarm_en[rtc->alarm];
shift = shift_alarm_en[rtc->alarm];
return lp8788_update_bits(lp, LP8788_INTEN_3, mask, enable << shift);
}
static irqreturn_t lp8788_alarm_irq_handler(int irq, void *ptr)
{
struct lp8788_rtc *rtc = ptr;
rtc_update_irq(rtc->rdev, 1, ALARM_IRQ_FLAG);
return IRQ_HANDLED;
}
static int lp8788_alarm_irq_register(struct platform_device *pdev,
struct lp8788_rtc *rtc)
{
struct resource *r;
struct lp8788 *lp = rtc->lp;
struct irq_domain *irqdm = lp->irqdm;
int irq;
rtc->irq = 0;
r = platform_get_resource_byname(pdev, IORESOURCE_IRQ, LP8788_ALM_IRQ);
if (!r)
return 0;
if (rtc->alarm == LP8788_ALARM_1)
irq = r->start;
else
irq = r->end;
rtc->irq = irq_create_mapping(irqdm, irq);
return devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
lp8788_alarm_irq_handler,
0, LP8788_ALM_IRQ, rtc);
}
static int lp8788_rtc_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
struct lp8788_rtc *rtc;
struct device *dev = &pdev->dev;
rtc = devm_kzalloc(dev, sizeof(struct lp8788_rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->lp = lp;
rtc->alarm = lp->pdata ? lp->pdata->alarm_sel : DEFAULT_ALARM_SEL;
platform_set_drvdata(pdev, rtc);
device_init_wakeup(dev, 1);
rtc->rdev = devm_rtc_device_register(dev, "lp8788_rtc",
&lp8788_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rdev)) {
dev_err(dev, "can not register rtc device\n");
return PTR_ERR(rtc->rdev);
}
if (lp8788_alarm_irq_register(pdev, rtc))
dev_warn(lp->dev, "no rtc irq handler\n");
return 0;
}
