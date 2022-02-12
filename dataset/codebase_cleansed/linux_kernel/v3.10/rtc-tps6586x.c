static inline struct device *to_tps6586x_dev(struct device *dev)
{
return dev->parent;
}
static int tps6586x_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
struct device *tps_dev = to_tps6586x_dev(dev);
unsigned long long ticks = 0;
unsigned long seconds;
u8 buff[6];
int ret;
int i;
ret = tps6586x_reads(tps_dev, RTC_COUNT4_DUMMYREAD, sizeof(buff), buff);
if (ret < 0) {
dev_err(dev, "read counter failed with err %d\n", ret);
return ret;
}
for (i = 1; i < sizeof(buff); i++) {
ticks <<= 8;
ticks |= buff[i];
}
seconds = ticks >> 10;
seconds += rtc->epoch_start;
rtc_time_to_tm(seconds, tm);
return rtc_valid_tm(tm);
}
static int tps6586x_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
struct device *tps_dev = to_tps6586x_dev(dev);
unsigned long long ticks;
unsigned long seconds;
u8 buff[5];
int ret;
rtc_tm_to_time(tm, &seconds);
if (seconds < rtc->epoch_start) {
dev_err(dev, "requested time unsupported\n");
return -EINVAL;
}
seconds -= rtc->epoch_start;
ticks = (unsigned long long)seconds << 10;
buff[0] = (ticks >> 32) & 0xff;
buff[1] = (ticks >> 24) & 0xff;
buff[2] = (ticks >> 16) & 0xff;
buff[3] = (ticks >> 8) & 0xff;
buff[4] = ticks & 0xff;
ret = tps6586x_clr_bits(tps_dev, RTC_CTRL, RTC_ENABLE);
if (ret < 0) {
dev_err(dev, "failed to clear RTC_ENABLE\n");
return ret;
}
ret = tps6586x_writes(tps_dev, RTC_COUNT4, sizeof(buff), buff);
if (ret < 0) {
dev_err(dev, "failed to program new time\n");
return ret;
}
ret = tps6586x_set_bits(tps_dev, RTC_CTRL, RTC_ENABLE);
if (ret < 0) {
dev_err(dev, "failed to set RTC_ENABLE\n");
return ret;
}
return 0;
}
static int tps6586x_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
if (enabled && !rtc->irq_en) {
enable_irq(rtc->irq);
rtc->irq_en = true;
} else if (!enabled && rtc->irq_en) {
disable_irq(rtc->irq);
rtc->irq_en = false;
}
return 0;
}
static int tps6586x_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
struct device *tps_dev = to_tps6586x_dev(dev);
unsigned long seconds;
unsigned long ticks;
unsigned long rtc_current_time;
unsigned long long rticks = 0;
u8 buff[3];
u8 rbuff[6];
int ret;
int i;
rtc_tm_to_time(&alrm->time, &seconds);
if (alrm->enabled && (seconds < rtc->epoch_start)) {
dev_err(dev, "can't set alarm to requested time\n");
return -EINVAL;
}
ret = tps6586x_rtc_alarm_irq_enable(dev, alrm->enabled);
if (ret < 0) {
dev_err(dev, "can't set alarm irq, err %d\n", ret);
return ret;
}
seconds -= rtc->epoch_start;
ret = tps6586x_reads(tps_dev, RTC_COUNT4_DUMMYREAD,
sizeof(rbuff), rbuff);
if (ret < 0) {
dev_err(dev, "read counter failed with err %d\n", ret);
return ret;
}
for (i = 1; i < sizeof(rbuff); i++) {
rticks <<= 8;
rticks |= rbuff[i];
}
rtc_current_time = rticks >> 10;
if ((seconds - rtc_current_time) > ALM1_VALID_RANGE_IN_SEC)
seconds = rtc_current_time - 1;
ticks = (unsigned long long)seconds << 10;
buff[0] = (ticks >> 16) & 0xff;
buff[1] = (ticks >> 8) & 0xff;
buff[2] = ticks & 0xff;
ret = tps6586x_writes(tps_dev, RTC_ALARM1_HI, sizeof(buff), buff);
if (ret)
dev_err(dev, "programming alarm failed with err %d\n", ret);
return ret;
}
static int tps6586x_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
struct device *tps_dev = to_tps6586x_dev(dev);
unsigned long ticks;
unsigned long seconds;
u8 buff[3];
int ret;
ret = tps6586x_reads(tps_dev, RTC_ALARM1_HI, sizeof(buff), buff);
if (ret) {
dev_err(dev, "read RTC_ALARM1_HI failed with err %d\n", ret);
return ret;
}
ticks = (buff[0] << 16) | (buff[1] << 8) | buff[2];
seconds = ticks >> 10;
seconds += rtc->epoch_start;
rtc_time_to_tm(seconds, &alrm->time);
return 0;
}
static irqreturn_t tps6586x_rtc_irq(int irq, void *data)
{
struct tps6586x_rtc *rtc = data;
rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int tps6586x_rtc_probe(struct platform_device *pdev)
{
struct device *tps_dev = to_tps6586x_dev(&pdev->dev);
struct tps6586x_rtc *rtc;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->dev = &pdev->dev;
rtc->irq = platform_get_irq(pdev, 0);
rtc->epoch_start = mktime(2009, 1, 1, 0, 0, 0);
ret = tps6586x_update(tps_dev, RTC_CTRL,
RTC_ENABLE | OSC_SRC_SEL |
((TPS6586X_RTC_CL_SEL_1_5PF << CL_SEL_POS) & CL_SEL_MASK),
RTC_ENABLE | OSC_SRC_SEL | PRE_BYPASS | CL_SEL_MASK);
if (ret < 0) {
dev_err(&pdev->dev, "unable to start counter\n");
return ret;
}
device_init_wakeup(&pdev->dev, 1);
platform_set_drvdata(pdev, rtc);
rtc->rtc = devm_rtc_device_register(&pdev->dev, dev_name(&pdev->dev),
&tps6586x_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
ret = PTR_ERR(rtc->rtc);
dev_err(&pdev->dev, "RTC device register: ret %d\n", ret);
goto fail_rtc_register;
}
ret = devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
tps6586x_rtc_irq,
IRQF_ONESHOT | IRQF_EARLY_RESUME,
dev_name(&pdev->dev), rtc);
if (ret < 0) {
dev_err(&pdev->dev, "request IRQ(%d) failed with ret %d\n",
rtc->irq, ret);
goto fail_rtc_register;
}
disable_irq(rtc->irq);
return 0;
fail_rtc_register:
tps6586x_update(tps_dev, RTC_CTRL, 0,
RTC_ENABLE | OSC_SRC_SEL | PRE_BYPASS | CL_SEL_MASK);
return ret;
}
static int tps6586x_rtc_remove(struct platform_device *pdev)
{
struct device *tps_dev = to_tps6586x_dev(&pdev->dev);
tps6586x_update(tps_dev, RTC_CTRL, 0,
RTC_ENABLE | OSC_SRC_SEL | PRE_BYPASS | CL_SEL_MASK);
return 0;
}
static int tps6586x_rtc_suspend(struct device *dev)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(rtc->irq);
return 0;
}
static int tps6586x_rtc_resume(struct device *dev)
{
struct tps6586x_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(rtc->irq);
return 0;
}
