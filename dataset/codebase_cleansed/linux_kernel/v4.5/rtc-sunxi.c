static irqreturn_t sunxi_rtc_alarmirq(int irq, void *id)
{
struct sunxi_rtc_dev *chip = (struct sunxi_rtc_dev *) id;
u32 val;
val = readl(chip->base + SUNXI_ALRM_IRQ_STA);
if (val & SUNXI_ALRM_IRQ_STA_CNT_IRQ_PEND) {
val |= SUNXI_ALRM_IRQ_STA_CNT_IRQ_PEND;
writel(val, chip->base + SUNXI_ALRM_IRQ_STA);
rtc_update_irq(chip->rtc, 1, RTC_AF | RTC_IRQF);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void sunxi_rtc_setaie(unsigned int to, struct sunxi_rtc_dev *chip)
{
u32 alrm_val = 0;
u32 alrm_irq_val = 0;
if (to) {
alrm_val = readl(chip->base + SUNXI_ALRM_EN);
alrm_val |= SUNXI_ALRM_EN_CNT_EN;
alrm_irq_val = readl(chip->base + SUNXI_ALRM_IRQ_EN);
alrm_irq_val |= SUNXI_ALRM_IRQ_EN_CNT_IRQ_EN;
} else {
writel(SUNXI_ALRM_IRQ_STA_CNT_IRQ_PEND,
chip->base + SUNXI_ALRM_IRQ_STA);
}
writel(alrm_val, chip->base + SUNXI_ALRM_EN);
writel(alrm_irq_val, chip->base + SUNXI_ALRM_IRQ_EN);
}
static int sunxi_rtc_getalarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct sunxi_rtc_dev *chip = dev_get_drvdata(dev);
struct rtc_time *alrm_tm = &wkalrm->time;
u32 alrm;
u32 alrm_en;
u32 date;
alrm = readl(chip->base + SUNXI_ALRM_DHMS);
date = readl(chip->base + SUNXI_RTC_YMD);
alrm_tm->tm_sec = SUNXI_ALRM_GET_SEC_VALUE(alrm);
alrm_tm->tm_min = SUNXI_ALRM_GET_MIN_VALUE(alrm);
alrm_tm->tm_hour = SUNXI_ALRM_GET_HOUR_VALUE(alrm);
alrm_tm->tm_mday = SUNXI_DATE_GET_DAY_VALUE(date);
alrm_tm->tm_mon = SUNXI_DATE_GET_MON_VALUE(date);
alrm_tm->tm_year = SUNXI_DATE_GET_YEAR_VALUE(date,
chip->data_year->mask);
alrm_tm->tm_mon -= 1;
alrm_tm->tm_year += SUNXI_YEAR_OFF(chip->data_year);
alrm_en = readl(chip->base + SUNXI_ALRM_IRQ_EN);
if (alrm_en & SUNXI_ALRM_EN_CNT_EN)
wkalrm->enabled = 1;
return 0;
}
static int sunxi_rtc_gettime(struct device *dev, struct rtc_time *rtc_tm)
{
struct sunxi_rtc_dev *chip = dev_get_drvdata(dev);
u32 date, time;
do {
date = readl(chip->base + SUNXI_RTC_YMD);
time = readl(chip->base + SUNXI_RTC_HMS);
} while ((date != readl(chip->base + SUNXI_RTC_YMD)) ||
(time != readl(chip->base + SUNXI_RTC_HMS)));
rtc_tm->tm_sec = SUNXI_TIME_GET_SEC_VALUE(time);
rtc_tm->tm_min = SUNXI_TIME_GET_MIN_VALUE(time);
rtc_tm->tm_hour = SUNXI_TIME_GET_HOUR_VALUE(time);
rtc_tm->tm_mday = SUNXI_DATE_GET_DAY_VALUE(date);
rtc_tm->tm_mon = SUNXI_DATE_GET_MON_VALUE(date);
rtc_tm->tm_year = SUNXI_DATE_GET_YEAR_VALUE(date,
chip->data_year->mask);
rtc_tm->tm_mon -= 1;
rtc_tm->tm_year += SUNXI_YEAR_OFF(chip->data_year);
return rtc_valid_tm(rtc_tm);
}
static int sunxi_rtc_setalarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct sunxi_rtc_dev *chip = dev_get_drvdata(dev);
struct rtc_time *alrm_tm = &wkalrm->time;
struct rtc_time tm_now;
u32 alrm;
time64_t diff;
unsigned long time_gap;
unsigned long time_gap_day;
unsigned long time_gap_hour;
unsigned long time_gap_min;
int ret;
ret = sunxi_rtc_gettime(dev, &tm_now);
if (ret < 0) {
dev_err(dev, "Error in getting time\n");
return -EINVAL;
}
diff = rtc_tm_sub(alrm_tm, &tm_now);
if (diff <= 0) {
dev_err(dev, "Date to set in the past\n");
return -EINVAL;
}
if (diff > 255 * SEC_IN_DAY) {
dev_err(dev, "Day must be in the range 0 - 255\n");
return -EINVAL;
}
time_gap = diff;
time_gap_day = time_gap / SEC_IN_DAY;
time_gap -= time_gap_day * SEC_IN_DAY;
time_gap_hour = time_gap / SEC_IN_HOUR;
time_gap -= time_gap_hour * SEC_IN_HOUR;
time_gap_min = time_gap / SEC_IN_MIN;
time_gap -= time_gap_min * SEC_IN_MIN;
sunxi_rtc_setaie(0, chip);
writel(0, chip->base + SUNXI_ALRM_DHMS);
usleep_range(100, 300);
alrm = SUNXI_ALRM_SET_SEC_VALUE(time_gap) |
SUNXI_ALRM_SET_MIN_VALUE(time_gap_min) |
SUNXI_ALRM_SET_HOUR_VALUE(time_gap_hour) |
SUNXI_ALRM_SET_DAY_VALUE(time_gap_day);
writel(alrm, chip->base + SUNXI_ALRM_DHMS);
writel(0, chip->base + SUNXI_ALRM_IRQ_EN);
writel(SUNXI_ALRM_IRQ_EN_CNT_IRQ_EN, chip->base + SUNXI_ALRM_IRQ_EN);
sunxi_rtc_setaie(wkalrm->enabled, chip);
return 0;
}
static int sunxi_rtc_wait(struct sunxi_rtc_dev *chip, int offset,
unsigned int mask, unsigned int ms_timeout)
{
const unsigned long timeout = jiffies + msecs_to_jiffies(ms_timeout);
u32 reg;
do {
reg = readl(chip->base + offset);
reg &= mask;
if (reg == mask)
return 0;
} while (time_before(jiffies, timeout));
return -ETIMEDOUT;
}
static int sunxi_rtc_settime(struct device *dev, struct rtc_time *rtc_tm)
{
struct sunxi_rtc_dev *chip = dev_get_drvdata(dev);
u32 date = 0;
u32 time = 0;
unsigned int year;
year = rtc_tm->tm_year + 1900;
if (year < chip->data_year->min || year > chip->data_year->max) {
dev_err(dev, "rtc only supports year in range %u - %u\n",
chip->data_year->min, chip->data_year->max);
return -EINVAL;
}
rtc_tm->tm_year -= SUNXI_YEAR_OFF(chip->data_year);
rtc_tm->tm_mon += 1;
date = SUNXI_DATE_SET_DAY_VALUE(rtc_tm->tm_mday) |
SUNXI_DATE_SET_MON_VALUE(rtc_tm->tm_mon) |
SUNXI_DATE_SET_YEAR_VALUE(rtc_tm->tm_year,
chip->data_year->mask);
if (is_leap_year(year))
date |= SUNXI_LEAP_SET_VALUE(1, chip->data_year->leap_shift);
time = SUNXI_TIME_SET_SEC_VALUE(rtc_tm->tm_sec) |
SUNXI_TIME_SET_MIN_VALUE(rtc_tm->tm_min) |
SUNXI_TIME_SET_HOUR_VALUE(rtc_tm->tm_hour);
writel(0, chip->base + SUNXI_RTC_HMS);
writel(0, chip->base + SUNXI_RTC_YMD);
writel(time, chip->base + SUNXI_RTC_HMS);
if (sunxi_rtc_wait(chip, SUNXI_LOSC_CTRL,
SUNXI_LOSC_CTRL_RTC_HMS_ACC, 50)) {
dev_err(dev, "Failed to set rtc time.\n");
return -1;
}
writel(date, chip->base + SUNXI_RTC_YMD);
if (sunxi_rtc_wait(chip, SUNXI_LOSC_CTRL,
SUNXI_LOSC_CTRL_RTC_YMD_ACC, 50)) {
dev_err(dev, "Failed to set rtc time.\n");
return -1;
}
return 0;
}
static int sunxi_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct sunxi_rtc_dev *chip = dev_get_drvdata(dev);
if (!enabled)
sunxi_rtc_setaie(enabled, chip);
return 0;
}
static int sunxi_rtc_probe(struct platform_device *pdev)
{
struct sunxi_rtc_dev *chip;
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
ret = devm_request_irq(&pdev->dev, chip->irq, sunxi_rtc_alarmirq,
0, dev_name(&pdev->dev), chip);
if (ret) {
dev_err(&pdev->dev, "Could not request IRQ\n");
return ret;
}
chip->data_year = of_device_get_match_data(&pdev->dev);
if (!chip->data_year) {
dev_err(&pdev->dev, "Unable to setup RTC data\n");
return -ENODEV;
}
writel(0, chip->base + SUNXI_ALRM_DHMS);
writel(0, chip->base + SUNXI_ALRM_EN);
writel(0, chip->base + SUNXI_ALRM_IRQ_EN);
writel(SUNXI_ALRM_IRQ_STA_CNT_IRQ_PEND, chip->base +
SUNXI_ALRM_IRQ_STA);
chip->rtc = rtc_device_register("rtc-sunxi", &pdev->dev,
&sunxi_rtc_ops, THIS_MODULE);
if (IS_ERR(chip->rtc)) {
dev_err(&pdev->dev, "unable to register device\n");
return PTR_ERR(chip->rtc);
}
dev_info(&pdev->dev, "RTC enabled\n");
return 0;
}
static int sunxi_rtc_remove(struct platform_device *pdev)
{
struct sunxi_rtc_dev *chip = platform_get_drvdata(pdev);
rtc_device_unregister(chip->rtc);
return 0;
}
