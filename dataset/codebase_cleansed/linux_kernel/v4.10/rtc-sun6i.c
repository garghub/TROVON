static irqreturn_t sun6i_rtc_alarmirq(int irq, void *id)
{
struct sun6i_rtc_dev *chip = (struct sun6i_rtc_dev *) id;
u32 val;
val = readl(chip->base + SUN6I_ALRM_IRQ_STA);
if (val & SUN6I_ALRM_IRQ_STA_CNT_IRQ_PEND) {
val |= SUN6I_ALRM_IRQ_STA_CNT_IRQ_PEND;
writel(val, chip->base + SUN6I_ALRM_IRQ_STA);
rtc_update_irq(chip->rtc, 1, RTC_AF | RTC_IRQF);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void sun6i_rtc_setaie(int to, struct sun6i_rtc_dev *chip)
{
u32 alrm_val = 0;
u32 alrm_irq_val = 0;
u32 alrm_wake_val = 0;
if (to) {
alrm_val = SUN6I_ALRM_EN_CNT_EN;
alrm_irq_val = SUN6I_ALRM_IRQ_EN_CNT_IRQ_EN;
alrm_wake_val = SUN6I_ALARM_CONFIG_WAKEUP;
} else {
writel(SUN6I_ALRM_IRQ_STA_CNT_IRQ_PEND,
chip->base + SUN6I_ALRM_IRQ_STA);
}
writel(alrm_val, chip->base + SUN6I_ALRM_EN);
writel(alrm_irq_val, chip->base + SUN6I_ALRM_IRQ_EN);
writel(alrm_wake_val, chip->base + SUN6I_ALARM_CONFIG);
}
static int sun6i_rtc_gettime(struct device *dev, struct rtc_time *rtc_tm)
{
struct sun6i_rtc_dev *chip = dev_get_drvdata(dev);
u32 date, time;
do {
date = readl(chip->base + SUN6I_RTC_YMD);
time = readl(chip->base + SUN6I_RTC_HMS);
} while ((date != readl(chip->base + SUN6I_RTC_YMD)) ||
(time != readl(chip->base + SUN6I_RTC_HMS)));
rtc_tm->tm_sec = SUN6I_TIME_GET_SEC_VALUE(time);
rtc_tm->tm_min = SUN6I_TIME_GET_MIN_VALUE(time);
rtc_tm->tm_hour = SUN6I_TIME_GET_HOUR_VALUE(time);
rtc_tm->tm_mday = SUN6I_DATE_GET_DAY_VALUE(date);
rtc_tm->tm_mon = SUN6I_DATE_GET_MON_VALUE(date);
rtc_tm->tm_year = SUN6I_DATE_GET_YEAR_VALUE(date);
rtc_tm->tm_mon -= 1;
rtc_tm->tm_year += SUN6I_YEAR_OFF;
return rtc_valid_tm(rtc_tm);
}
static int sun6i_rtc_getalarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct sun6i_rtc_dev *chip = dev_get_drvdata(dev);
u32 alrm_st;
u32 alrm_en;
alrm_en = readl(chip->base + SUN6I_ALRM_IRQ_EN);
alrm_st = readl(chip->base + SUN6I_ALRM_IRQ_STA);
wkalrm->enabled = !!(alrm_en & SUN6I_ALRM_EN_CNT_EN);
wkalrm->pending = !!(alrm_st & SUN6I_ALRM_EN_CNT_EN);
rtc_time_to_tm(chip->alarm, &wkalrm->time);
return 0;
}
static int sun6i_rtc_setalarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct sun6i_rtc_dev *chip = dev_get_drvdata(dev);
struct rtc_time *alrm_tm = &wkalrm->time;
struct rtc_time tm_now;
unsigned long time_now = 0;
unsigned long time_set = 0;
unsigned long time_gap = 0;
int ret = 0;
ret = sun6i_rtc_gettime(dev, &tm_now);
if (ret < 0) {
dev_err(dev, "Error in getting time\n");
return -EINVAL;
}
rtc_tm_to_time(alrm_tm, &time_set);
rtc_tm_to_time(&tm_now, &time_now);
if (time_set <= time_now) {
dev_err(dev, "Date to set in the past\n");
return -EINVAL;
}
time_gap = time_set - time_now;
if (time_gap > U32_MAX) {
dev_err(dev, "Date too far in the future\n");
return -EINVAL;
}
sun6i_rtc_setaie(0, chip);
writel(0, chip->base + SUN6I_ALRM_COUNTER);
usleep_range(100, 300);
writel(time_gap, chip->base + SUN6I_ALRM_COUNTER);
chip->alarm = time_set;
sun6i_rtc_setaie(wkalrm->enabled, chip);
return 0;
}
static int sun6i_rtc_wait(struct sun6i_rtc_dev *chip, int offset,
unsigned int mask, unsigned int ms_timeout)
{
const unsigned long timeout = jiffies + msecs_to_jiffies(ms_timeout);
u32 reg;
do {
reg = readl(chip->base + offset);
reg &= mask;
if (!reg)
return 0;
} while (time_before(jiffies, timeout));
return -ETIMEDOUT;
}
static int sun6i_rtc_settime(struct device *dev, struct rtc_time *rtc_tm)
{
struct sun6i_rtc_dev *chip = dev_get_drvdata(dev);
u32 date = 0;
u32 time = 0;
int year;
year = rtc_tm->tm_year + 1900;
if (year < SUN6I_YEAR_MIN || year > SUN6I_YEAR_MAX) {
dev_err(dev, "rtc only supports year in range %d - %d\n",
SUN6I_YEAR_MIN, SUN6I_YEAR_MAX);
return -EINVAL;
}
rtc_tm->tm_year -= SUN6I_YEAR_OFF;
rtc_tm->tm_mon += 1;
date = SUN6I_DATE_SET_DAY_VALUE(rtc_tm->tm_mday) |
SUN6I_DATE_SET_MON_VALUE(rtc_tm->tm_mon) |
SUN6I_DATE_SET_YEAR_VALUE(rtc_tm->tm_year);
if (is_leap_year(year))
date |= SUN6I_LEAP_SET_VALUE(1);
time = SUN6I_TIME_SET_SEC_VALUE(rtc_tm->tm_sec) |
SUN6I_TIME_SET_MIN_VALUE(rtc_tm->tm_min) |
SUN6I_TIME_SET_HOUR_VALUE(rtc_tm->tm_hour);
if (sun6i_rtc_wait(chip, SUN6I_LOSC_CTRL,
SUN6I_LOSC_CTRL_ACC_MASK, 50)) {
dev_err(dev, "rtc is still busy.\n");
return -EBUSY;
}
writel(time, chip->base + SUN6I_RTC_HMS);
if (sun6i_rtc_wait(chip, SUN6I_LOSC_CTRL,
SUN6I_LOSC_CTRL_RTC_HMS_ACC, 50)) {
dev_err(dev, "Failed to set rtc time.\n");
return -ETIMEDOUT;
}
writel(date, chip->base + SUN6I_RTC_YMD);
if (sun6i_rtc_wait(chip, SUN6I_LOSC_CTRL,
SUN6I_LOSC_CTRL_RTC_YMD_ACC, 50)) {
dev_err(dev, "Failed to set rtc time.\n");
return -ETIMEDOUT;
}
return 0;
}
static int sun6i_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct sun6i_rtc_dev *chip = dev_get_drvdata(dev);
if (!enabled)
sun6i_rtc_setaie(enabled, chip);
return 0;
}
static int sun6i_rtc_probe(struct platform_device *pdev)
{
struct sun6i_rtc_dev *chip;
struct resource *res;
int ret;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
platform_set_drvdata(pdev, chip);
chip->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
chip->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(chip->base))
return PTR_ERR(chip->base);
chip->irq = platform_get_irq(pdev, 0);
if (chip->irq < 0) {
dev_err(&pdev->dev, "No IRQ resource\n");
return chip->irq;
}
ret = devm_request_irq(&pdev->dev, chip->irq, sun6i_rtc_alarmirq,
0, dev_name(&pdev->dev), chip);
if (ret) {
dev_err(&pdev->dev, "Could not request IRQ\n");
return ret;
}
writel(0, chip->base + SUN6I_ALRM_COUNTER);
writel(0, chip->base + SUN6I_ALRM_EN);
writel(0, chip->base + SUN6I_ALRM_IRQ_EN);
writel(0, chip->base + SUN6I_ALRM1_EN);
writel(0, chip->base + SUN6I_ALRM1_IRQ_EN);
writel(SUN6I_ALRM_IRQ_STA_CNT_IRQ_PEND,
chip->base + SUN6I_ALRM_IRQ_STA);
writel(SUN6I_ALRM1_IRQ_STA_WEEK_IRQ_PEND,
chip->base + SUN6I_ALRM1_IRQ_STA);
writel(0, chip->base + SUN6I_ALARM_CONFIG);
chip->rtc = rtc_device_register("rtc-sun6i", &pdev->dev,
&sun6i_rtc_ops, THIS_MODULE);
if (IS_ERR(chip->rtc)) {
dev_err(&pdev->dev, "unable to register device\n");
return PTR_ERR(chip->rtc);
}
dev_info(&pdev->dev, "RTC enabled\n");
return 0;
}
static int sun6i_rtc_remove(struct platform_device *pdev)
{
struct sun6i_rtc_dev *chip = platform_get_drvdata(pdev);
rtc_device_unregister(chip->rtc);
return 0;
}
