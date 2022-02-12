static void mpc5121_rtc_update_smh(struct mpc5121_rtc_regs __iomem *regs,
struct rtc_time *tm)
{
out_8(&regs->second_set, tm->tm_sec);
out_8(&regs->minute_set, tm->tm_min);
out_8(&regs->hour_set, tm->tm_hour);
out_8(&regs->set_time, 0x1);
out_8(&regs->set_time, 0x3);
out_8(&regs->set_time, 0x1);
out_8(&regs->set_time, 0x0);
}
static int mpc5121_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
unsigned long now;
now = in_be32(&regs->actual_time) + in_be32(&regs->target_time);
rtc_time_to_tm(now, tm);
mpc5121_rtc_update_smh(regs, tm);
return rtc_valid_tm(tm);
}
static int mpc5121_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
int ret;
unsigned long now;
ret = rtc_tm_to_time(tm, &now);
if (ret == 0)
out_be32(&regs->target_time, now - in_be32(&regs->actual_time));
mpc5121_rtc_update_smh(regs, tm);
return 0;
}
static int mpc5200_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
int tmp;
tm->tm_sec = in_8(&regs->second);
tm->tm_min = in_8(&regs->minute);
if (in_8(&regs->hour) & 0x20)
tm->tm_hour = (in_8(&regs->hour) >> 1) +
(in_8(&regs->hour) & 1 ? 12 : 0);
else
tm->tm_hour = in_8(&regs->hour);
tmp = in_8(&regs->wday_mday);
tm->tm_mday = tmp & 0x1f;
tm->tm_mon = in_8(&regs->month) - 1;
tm->tm_year = in_be16(&regs->year) - 1900;
tm->tm_wday = (tmp >> 5) % 7;
tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon, tm->tm_year);
tm->tm_isdst = 0;
return 0;
}
static int mpc5200_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
mpc5121_rtc_update_smh(regs, tm);
out_8(&regs->month_set, tm->tm_mon + 1);
out_8(&regs->weekday_set, tm->tm_wday ? tm->tm_wday : 7);
out_8(&regs->date_set, tm->tm_mday);
out_be16(&regs->year_set, tm->tm_year + 1900);
out_8(&regs->set_date, 0x1);
out_8(&regs->set_date, 0x3);
out_8(&regs->set_date, 0x1);
out_8(&regs->set_date, 0x0);
return 0;
}
static int mpc5121_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
*alarm = rtc->wkalarm;
alarm->pending = in_8(&regs->alm_status);
return 0;
}
static int mpc5121_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
if (alarm->time.tm_sec) {
alarm->time.tm_sec = 0;
alarm->time.tm_min++;
if (alarm->time.tm_min >= 60) {
alarm->time.tm_min = 0;
alarm->time.tm_hour++;
if (alarm->time.tm_hour >= 24)
alarm->time.tm_hour = 0;
}
}
alarm->time.tm_mday = -1;
alarm->time.tm_mon = -1;
alarm->time.tm_year = -1;
out_8(&regs->alm_min_set, alarm->time.tm_min);
out_8(&regs->alm_hour_set, alarm->time.tm_hour);
out_8(&regs->alm_enable, alarm->enabled);
rtc->wkalarm = *alarm;
return 0;
}
static irqreturn_t mpc5121_rtc_handler(int irq, void *dev)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata((struct device *)dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
if (in_8(&regs->int_alm)) {
out_8(&regs->int_alm, 1);
out_8(&regs->alm_status, 1);
rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static irqreturn_t mpc5121_rtc_handler_upd(int irq, void *dev)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata((struct device *)dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
if (in_8(&regs->int_sec) && (in_8(&regs->int_enable) & 0x1)) {
out_8(&regs->int_sec, 1);
rtc_update_irq(rtc->rtc, 1, RTC_IRQF | RTC_UF);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int mpc5121_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
int val;
if (enabled)
val = 1;
else
val = 0;
out_8(&regs->alm_enable, val);
rtc->wkalarm.enabled = val;
return 0;
}
static int __devinit mpc5121_rtc_probe(struct platform_device *op)
{
struct mpc5121_rtc_data *rtc;
int err = 0;
rtc = kzalloc(sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->regs = of_iomap(op->dev.of_node, 0);
if (!rtc->regs) {
dev_err(&op->dev, "%s: couldn't map io space\n", __func__);
err = -ENOSYS;
goto out_free;
}
device_init_wakeup(&op->dev, 1);
dev_set_drvdata(&op->dev, rtc);
rtc->irq = irq_of_parse_and_map(op->dev.of_node, 1);
err = request_irq(rtc->irq, mpc5121_rtc_handler, IRQF_DISABLED,
"mpc5121-rtc", &op->dev);
if (err) {
dev_err(&op->dev, "%s: could not request irq: %i\n",
__func__, rtc->irq);
goto out_dispose;
}
rtc->irq_periodic = irq_of_parse_and_map(op->dev.of_node, 0);
err = request_irq(rtc->irq_periodic, mpc5121_rtc_handler_upd,
IRQF_DISABLED, "mpc5121-rtc_upd", &op->dev);
if (err) {
dev_err(&op->dev, "%s: could not request irq: %i\n",
__func__, rtc->irq_periodic);
goto out_dispose2;
}
if (of_device_is_compatible(op->dev.of_node, "fsl,mpc5121-rtc")) {
u32 ka;
ka = in_be32(&rtc->regs->keep_alive);
if (ka & 0x02) {
dev_warn(&op->dev,
"mpc5121-rtc: Battery or oscillator failure!\n");
out_be32(&rtc->regs->keep_alive, ka);
}
rtc->rtc = rtc_device_register("mpc5121-rtc", &op->dev,
&mpc5121_rtc_ops, THIS_MODULE);
} else {
rtc->rtc = rtc_device_register("mpc5200-rtc", &op->dev,
&mpc5200_rtc_ops, THIS_MODULE);
}
if (IS_ERR(rtc->rtc)) {
err = PTR_ERR(rtc->rtc);
goto out_free_irq;
}
return 0;
out_free_irq:
free_irq(rtc->irq_periodic, &op->dev);
out_dispose2:
irq_dispose_mapping(rtc->irq_periodic);
free_irq(rtc->irq, &op->dev);
out_dispose:
irq_dispose_mapping(rtc->irq);
iounmap(rtc->regs);
out_free:
kfree(rtc);
return err;
}
static int __devexit mpc5121_rtc_remove(struct platform_device *op)
{
struct mpc5121_rtc_data *rtc = dev_get_drvdata(&op->dev);
struct mpc5121_rtc_regs __iomem *regs = rtc->regs;
out_8(&regs->alm_enable, 0);
out_8(&regs->int_enable, in_8(&regs->int_enable) & ~0x1);
rtc_device_unregister(rtc->rtc);
iounmap(rtc->regs);
free_irq(rtc->irq, &op->dev);
free_irq(rtc->irq_periodic, &op->dev);
irq_dispose_mapping(rtc->irq);
irq_dispose_mapping(rtc->irq_periodic);
dev_set_drvdata(&op->dev, NULL);
kfree(rtc);
return 0;
}
static int __init mpc5121_rtc_init(void)
{
return platform_driver_register(&mpc5121_rtc_driver);
}
static void __exit mpc5121_rtc_exit(void)
{
platform_driver_unregister(&mpc5121_rtc_driver);
}
