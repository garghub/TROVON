static int tps80031_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
u8 buff[TPS80031_RTC_TIME_NUM_REGS];
int ret;
ret = tps80031_reads(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_SECONDS_REG, TPS80031_RTC_TIME_NUM_REGS, buff);
if (ret < 0) {
dev_err(dev, "reading RTC_SECONDS_REG failed, err = %d\n", ret);
return ret;
}
tm->tm_sec = bcd2bin(buff[0]);
tm->tm_min = bcd2bin(buff[1]);
tm->tm_hour = bcd2bin(buff[2]);
tm->tm_mday = bcd2bin(buff[3]);
tm->tm_mon = bcd2bin(buff[4]) - 1;
tm->tm_year = bcd2bin(buff[5]) + RTC_YEAR_OFFSET;
tm->tm_wday = bcd2bin(buff[6]);
return 0;
}
static int tps80031_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
u8 buff[7];
int ret;
buff[0] = bin2bcd(tm->tm_sec);
buff[1] = bin2bcd(tm->tm_min);
buff[2] = bin2bcd(tm->tm_hour);
buff[3] = bin2bcd(tm->tm_mday);
buff[4] = bin2bcd(tm->tm_mon + 1);
buff[5] = bin2bcd(tm->tm_year % RTC_YEAR_OFFSET);
buff[6] = bin2bcd(tm->tm_wday);
ret = tps80031_clr_bits(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_CTRL_REG, STOP_RTC);
if (ret < 0) {
dev_err(dev->parent, "Stop RTC failed, err = %d\n", ret);
return ret;
}
ret = tps80031_writes(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_SECONDS_REG,
TPS80031_RTC_TIME_NUM_REGS, buff);
if (ret < 0) {
dev_err(dev, "writing RTC_SECONDS_REG failed, err %d\n", ret);
return ret;
}
ret = tps80031_set_bits(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_CTRL_REG, STOP_RTC);
if (ret < 0)
dev_err(dev->parent, "Start RTC failed, err = %d\n", ret);
return ret;
}
static int tps80031_rtc_alarm_irq_enable(struct device *dev,
unsigned int enable)
{
int ret;
if (enable)
ret = tps80031_set_bits(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_INTERRUPTS_REG, ENABLE_ALARM_INT);
else
ret = tps80031_clr_bits(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_INTERRUPTS_REG, ENABLE_ALARM_INT);
if (ret < 0) {
dev_err(dev, "Update on RTC_INT failed, err = %d\n", ret);
return ret;
}
return 0;
}
static int tps80031_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
u8 buff[TPS80031_RTC_ALARM_NUM_REGS];
int ret;
buff[0] = bin2bcd(alrm->time.tm_sec);
buff[1] = bin2bcd(alrm->time.tm_min);
buff[2] = bin2bcd(alrm->time.tm_hour);
buff[3] = bin2bcd(alrm->time.tm_mday);
buff[4] = bin2bcd(alrm->time.tm_mon + 1);
buff[5] = bin2bcd(alrm->time.tm_year % RTC_YEAR_OFFSET);
ret = tps80031_writes(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_ALARM_SECONDS_REG,
TPS80031_RTC_ALARM_NUM_REGS, buff);
if (ret < 0) {
dev_err(dev, "Writing RTC_ALARM failed, err %d\n", ret);
return ret;
}
return tps80031_rtc_alarm_irq_enable(dev, alrm->enabled);
}
static int tps80031_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
u8 buff[6];
int ret;
ret = tps80031_reads(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_ALARM_SECONDS_REG,
TPS80031_RTC_ALARM_NUM_REGS, buff);
if (ret < 0) {
dev_err(dev->parent,
"reading RTC_ALARM failed, err = %d\n", ret);
return ret;
}
alrm->time.tm_sec = bcd2bin(buff[0]);
alrm->time.tm_min = bcd2bin(buff[1]);
alrm->time.tm_hour = bcd2bin(buff[2]);
alrm->time.tm_mday = bcd2bin(buff[3]);
alrm->time.tm_mon = bcd2bin(buff[4]) - 1;
alrm->time.tm_year = bcd2bin(buff[5]) + RTC_YEAR_OFFSET;
return 0;
}
static int clear_alarm_int_status(struct device *dev, struct tps80031_rtc *rtc)
{
int ret;
u8 buf;
ret = tps80031_read(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_STATUS_REG, &buf);
if (ret < 0) {
dev_err(dev, "reading RTC_STATUS failed. err = %d\n", ret);
return ret;
}
ret = tps80031_set_bits(dev->parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_STATUS_REG, ALARM_INT_STATUS);
if (ret < 0) {
dev_err(dev, "clear Alarm INT failed, err = %d\n", ret);
return ret;
}
return 0;
}
static irqreturn_t tps80031_rtc_irq(int irq, void *data)
{
struct device *dev = data;
struct tps80031_rtc *rtc = dev_get_drvdata(dev);
int ret;
ret = clear_alarm_int_status(dev, rtc);
if (ret < 0)
return ret;
rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int tps80031_rtc_probe(struct platform_device *pdev)
{
struct tps80031_rtc *rtc;
struct rtc_time tm;
int ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->irq = platform_get_irq(pdev, 0);
platform_set_drvdata(pdev, rtc);
ret = tps80031_set_bits(pdev->dev.parent, TPS80031_SLAVE_ID1,
TPS80031_RTC_CTRL_REG, STOP_RTC);
if (ret < 0) {
dev_err(&pdev->dev, "failed to start RTC. err = %d\n", ret);
return ret;
}
tps80031_rtc_read_time(&pdev->dev, &tm);
if ((tm.tm_year == RTC_YEAR_OFFSET + TPS80031_RTC_POR_YEAR) &&
(tm.tm_mon == (TPS80031_RTC_POR_MONTH - 1)) &&
(tm.tm_mday == TPS80031_RTC_POR_DAY)) {
tm.tm_year = 2000;
tm.tm_mday = 1;
tm.tm_mon = 1;
ret = tps80031_rtc_set_time(&pdev->dev, &tm);
if (ret < 0) {
dev_err(&pdev->dev,
"RTC set time failed, err = %d\n", ret);
return ret;
}
}
ret = clear_alarm_int_status(&pdev->dev, rtc);
if (ret < 0) {
dev_err(&pdev->dev, "Clear alarm int failed, err = %d\n", ret);
return ret;
}
rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&tps80031_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
ret = PTR_ERR(rtc->rtc);
dev_err(&pdev->dev, "RTC registration failed, err %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(&pdev->dev, rtc->irq, NULL,
tps80031_rtc_irq,
IRQF_ONESHOT | IRQF_EARLY_RESUME,
dev_name(&pdev->dev), rtc);
if (ret < 0) {
dev_err(&pdev->dev, "request IRQ:%d failed, err = %d\n",
rtc->irq, ret);
return ret;
}
device_set_wakeup_capable(&pdev->dev, 1);
return 0;
}
static int tps80031_rtc_suspend(struct device *dev)
{
struct tps80031_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(rtc->irq);
return 0;
}
static int tps80031_rtc_resume(struct device *dev)
{
struct tps80031_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(rtc->irq);
return 0;
}
