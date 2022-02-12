static int rk808_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
struct rk808_rtc *rk808_rtc = dev_get_drvdata(dev);
struct rk808 *rk808 = rk808_rtc->rk808;
u8 rtc_data[NUM_TIME_REGS];
int ret;
ret = regmap_update_bits(rk808->regmap, RK808_RTC_CTRL_REG,
BIT_RTC_CTRL_REG_RTC_GET_TIME,
BIT_RTC_CTRL_REG_RTC_GET_TIME);
if (ret) {
dev_err(dev, "Failed to update bits rtc_ctrl: %d\n", ret);
return ret;
}
ret = regmap_update_bits(rk808->regmap, RK808_RTC_CTRL_REG,
BIT_RTC_CTRL_REG_RTC_GET_TIME,
0);
if (ret) {
dev_err(dev, "Failed to update bits rtc_ctrl: %d\n", ret);
return ret;
}
ret = regmap_bulk_read(rk808->regmap, RK808_SECONDS_REG,
rtc_data, NUM_TIME_REGS);
if (ret) {
dev_err(dev, "Failed to bulk read rtc_data: %d\n", ret);
return ret;
}
tm->tm_sec = bcd2bin(rtc_data[0] & SECONDS_REG_MSK);
tm->tm_min = bcd2bin(rtc_data[1] & MINUTES_REG_MAK);
tm->tm_hour = bcd2bin(rtc_data[2] & HOURS_REG_MSK);
tm->tm_mday = bcd2bin(rtc_data[3] & DAYS_REG_MSK);
tm->tm_mon = (bcd2bin(rtc_data[4] & MONTHS_REG_MSK)) - 1;
tm->tm_year = (bcd2bin(rtc_data[5] & YEARS_REG_MSK)) + 100;
tm->tm_wday = bcd2bin(rtc_data[6] & WEEKS_REG_MSK);
dev_dbg(dev, "RTC date/time %4d-%02d-%02d(%d) %02d:%02d:%02d\n",
1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday,
tm->tm_wday, tm->tm_hour , tm->tm_min, tm->tm_sec);
return ret;
}
static int rk808_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct rk808_rtc *rk808_rtc = dev_get_drvdata(dev);
struct rk808 *rk808 = rk808_rtc->rk808;
u8 rtc_data[NUM_TIME_REGS];
int ret;
rtc_data[0] = bin2bcd(tm->tm_sec);
rtc_data[1] = bin2bcd(tm->tm_min);
rtc_data[2] = bin2bcd(tm->tm_hour);
rtc_data[3] = bin2bcd(tm->tm_mday);
rtc_data[4] = bin2bcd(tm->tm_mon + 1);
rtc_data[5] = bin2bcd(tm->tm_year - 100);
rtc_data[6] = bin2bcd(tm->tm_wday);
dev_dbg(dev, "set RTC date/time %4d-%02d-%02d(%d) %02d:%02d:%02d\n",
1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday,
tm->tm_wday, tm->tm_hour , tm->tm_min, tm->tm_sec);
ret = regmap_update_bits(rk808->regmap, RK808_RTC_CTRL_REG,
BIT_RTC_CTRL_REG_STOP_RTC_M,
BIT_RTC_CTRL_REG_STOP_RTC_M);
if (ret) {
dev_err(dev, "Failed to update RTC control: %d\n", ret);
return ret;
}
ret = regmap_bulk_write(rk808->regmap, RK808_SECONDS_REG,
rtc_data, NUM_TIME_REGS);
if (ret) {
dev_err(dev, "Failed to bull write rtc_data: %d\n", ret);
return ret;
}
ret = regmap_update_bits(rk808->regmap, RK808_RTC_CTRL_REG,
BIT_RTC_CTRL_REG_STOP_RTC_M, 0);
if (ret) {
dev_err(dev, "Failed to update RTC control: %d\n", ret);
return ret;
}
return 0;
}
static int rk808_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct rk808_rtc *rk808_rtc = dev_get_drvdata(dev);
struct rk808 *rk808 = rk808_rtc->rk808;
u8 alrm_data[NUM_ALARM_REGS];
uint32_t int_reg;
int ret;
ret = regmap_bulk_read(rk808->regmap, RK808_ALARM_SECONDS_REG,
alrm_data, NUM_ALARM_REGS);
alrm->time.tm_sec = bcd2bin(alrm_data[0] & SECONDS_REG_MSK);
alrm->time.tm_min = bcd2bin(alrm_data[1] & MINUTES_REG_MAK);
alrm->time.tm_hour = bcd2bin(alrm_data[2] & HOURS_REG_MSK);
alrm->time.tm_mday = bcd2bin(alrm_data[3] & DAYS_REG_MSK);
alrm->time.tm_mon = (bcd2bin(alrm_data[4] & MONTHS_REG_MSK)) - 1;
alrm->time.tm_year = (bcd2bin(alrm_data[5] & YEARS_REG_MSK)) + 100;
ret = regmap_read(rk808->regmap, RK808_RTC_INT_REG, &int_reg);
if (ret) {
dev_err(dev, "Failed to read RTC INT REG: %d\n", ret);
return ret;
}
dev_dbg(dev, "alrm read RTC date/time %4d-%02d-%02d(%d) %02d:%02d:%02d\n",
1900 + alrm->time.tm_year, alrm->time.tm_mon + 1,
alrm->time.tm_mday, alrm->time.tm_wday, alrm->time.tm_hour,
alrm->time.tm_min, alrm->time.tm_sec);
alrm->enabled = (int_reg & BIT_RTC_INTERRUPTS_REG_IT_ALARM_M) ? 1 : 0;
return 0;
}
static int rk808_rtc_stop_alarm(struct rk808_rtc *rk808_rtc)
{
struct rk808 *rk808 = rk808_rtc->rk808;
int ret;
ret = regmap_update_bits(rk808->regmap, RK808_RTC_INT_REG,
BIT_RTC_INTERRUPTS_REG_IT_ALARM_M, 0);
return ret;
}
static int rk808_rtc_start_alarm(struct rk808_rtc *rk808_rtc)
{
struct rk808 *rk808 = rk808_rtc->rk808;
int ret;
ret = regmap_update_bits(rk808->regmap, RK808_RTC_INT_REG,
BIT_RTC_INTERRUPTS_REG_IT_ALARM_M,
BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
return ret;
}
static int rk808_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct rk808_rtc *rk808_rtc = dev_get_drvdata(dev);
struct rk808 *rk808 = rk808_rtc->rk808;
u8 alrm_data[NUM_ALARM_REGS];
int ret;
ret = rk808_rtc_stop_alarm(rk808_rtc);
if (ret) {
dev_err(dev, "Failed to stop alarm: %d\n", ret);
return ret;
}
dev_dbg(dev, "alrm set RTC date/time %4d-%02d-%02d(%d) %02d:%02d:%02d\n",
1900 + alrm->time.tm_year, alrm->time.tm_mon + 1,
alrm->time.tm_mday, alrm->time.tm_wday, alrm->time.tm_hour,
alrm->time.tm_min, alrm->time.tm_sec);
alrm_data[0] = bin2bcd(alrm->time.tm_sec);
alrm_data[1] = bin2bcd(alrm->time.tm_min);
alrm_data[2] = bin2bcd(alrm->time.tm_hour);
alrm_data[3] = bin2bcd(alrm->time.tm_mday);
alrm_data[4] = bin2bcd(alrm->time.tm_mon + 1);
alrm_data[5] = bin2bcd(alrm->time.tm_year - 100);
ret = regmap_bulk_write(rk808->regmap, RK808_ALARM_SECONDS_REG,
alrm_data, NUM_ALARM_REGS);
if (ret) {
dev_err(dev, "Failed to bulk write: %d\n", ret);
return ret;
}
if (alrm->enabled) {
ret = rk808_rtc_start_alarm(rk808_rtc);
if (ret) {
dev_err(dev, "Failed to start alarm: %d\n", ret);
return ret;
}
}
return 0;
}
static int rk808_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct rk808_rtc *rk808_rtc = dev_get_drvdata(dev);
if (enabled)
return rk808_rtc_start_alarm(rk808_rtc);
return rk808_rtc_stop_alarm(rk808_rtc);
}
static irqreturn_t rk808_alarm_irq(int irq, void *data)
{
struct rk808_rtc *rk808_rtc = data;
struct rk808 *rk808 = rk808_rtc->rk808;
struct i2c_client *client = rk808->i2c;
int ret;
ret = regmap_write(rk808->regmap, RK808_RTC_STATUS_REG,
RTC_STATUS_MASK);
if (ret) {
dev_err(&client->dev,
"%s:Failed to update RTC status: %d\n", __func__, ret);
return ret;
}
rtc_update_irq(rk808_rtc->rtc, 1, RTC_IRQF | RTC_AF);
dev_dbg(&client->dev,
"%s:irq=%d\n", __func__, irq);
return IRQ_HANDLED;
}
static int rk808_rtc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct rk808_rtc *rk808_rtc = dev_get_drvdata(&pdev->dev);
if (device_may_wakeup(dev))
enable_irq_wake(rk808_rtc->irq);
return 0;
}
static int rk808_rtc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct rk808_rtc *rk808_rtc = dev_get_drvdata(&pdev->dev);
if (device_may_wakeup(dev))
disable_irq_wake(rk808_rtc->irq);
return 0;
}
static int rk808_rtc_probe(struct platform_device *pdev)
{
struct rk808 *rk808 = dev_get_drvdata(pdev->dev.parent);
struct rk808_rtc *rk808_rtc;
struct rtc_time tm;
int ret;
rk808_rtc = devm_kzalloc(&pdev->dev, sizeof(*rk808_rtc), GFP_KERNEL);
if (rk808_rtc == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, rk808_rtc);
rk808_rtc->rk808 = rk808;
ret = regmap_update_bits(rk808->regmap, RK808_RTC_CTRL_REG,
BIT_RTC_CTRL_REG_STOP_RTC_M |
BIT_RTC_CTRL_REG_RTC_READSEL_M,
BIT_RTC_CTRL_REG_RTC_READSEL_M);
if (ret) {
dev_err(&pdev->dev,
"Failed to update RTC control: %d\n", ret);
return ret;
}
ret = regmap_write(rk808->regmap, RK808_RTC_STATUS_REG,
RTC_STATUS_MASK);
if (ret) {
dev_err(&pdev->dev,
"Failed to write RTC status: %d\n", ret);
return ret;
}
ret = rk808_rtc_readtime(&pdev->dev, &tm);
if (ret) {
dev_err(&pdev->dev, "Failed to read RTC time\n");
return ret;
}
ret = rtc_valid_tm(&tm);
if (ret)
dev_warn(&pdev->dev, "invalid date/time\n");
device_init_wakeup(&pdev->dev, 1);
rk808_rtc->rtc = devm_rtc_device_register(&pdev->dev, "rk808-rtc",
&rk808_rtc_ops, THIS_MODULE);
if (IS_ERR(rk808_rtc->rtc)) {
ret = PTR_ERR(rk808_rtc->rtc);
return ret;
}
rk808_rtc->irq = platform_get_irq(pdev, 0);
if (rk808_rtc->irq < 0) {
if (rk808_rtc->irq != -EPROBE_DEFER)
dev_err(&pdev->dev, "Wake up is not possible as irq = %d\n",
rk808_rtc->irq);
return rk808_rtc->irq;
}
ret = devm_request_threaded_irq(&pdev->dev, rk808_rtc->irq, NULL,
rk808_alarm_irq, 0,
"RTC alarm", rk808_rtc);
if (ret) {
dev_err(&pdev->dev, "Failed to request alarm IRQ %d: %d\n",
rk808_rtc->irq, ret);
}
return ret;
}
