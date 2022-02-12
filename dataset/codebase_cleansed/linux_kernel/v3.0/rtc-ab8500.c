static unsigned long get_elapsed_seconds(int year)
{
unsigned long secs;
struct rtc_time tm = {
.tm_year = year - 1900,
.tm_mday = 1,
};
rtc_tm_to_time(&tm, &secs);
return secs;
}
static int ab8500_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
unsigned long timeout = jiffies + HZ;
int retval, i;
unsigned long mins, secs;
unsigned char buf[ARRAY_SIZE(ab8500_rtc_time_regs)];
u8 value;
retval = abx500_set_register_interruptible(dev,
AB8500_RTC, AB8500_RTC_READ_REQ_REG, RTC_READ_REQUEST);
if (retval < 0)
return retval;
if (abx500_get_chip_id(dev) == 0) {
msleep(1);
} else {
while (time_before(jiffies, timeout)) {
retval = abx500_get_register_interruptible(dev,
AB8500_RTC, AB8500_RTC_READ_REQ_REG, &value);
if (retval < 0)
return retval;
if (!(value & RTC_READ_REQUEST))
break;
msleep(1);
}
}
for (i = 0; i < ARRAY_SIZE(ab8500_rtc_time_regs); i++) {
retval = abx500_get_register_interruptible(dev,
AB8500_RTC, ab8500_rtc_time_regs[i], &value);
if (retval < 0)
return retval;
buf[i] = value;
}
mins = (buf[0] << 16) | (buf[1] << 8) | buf[2];
secs = (buf[3] << 8) | buf[4];
secs = secs / COUNTS_PER_SEC;
secs = secs + (mins * 60);
secs += get_elapsed_seconds(AB8500_RTC_EPOCH);
rtc_time_to_tm(secs, tm);
return rtc_valid_tm(tm);
}
static int ab8500_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
int retval, i;
unsigned char buf[ARRAY_SIZE(ab8500_rtc_time_regs)];
unsigned long no_secs, no_mins, secs = 0;
if (tm->tm_year < (AB8500_RTC_EPOCH - 1900)) {
dev_dbg(dev, "year should be equal to or greater than %d\n",
AB8500_RTC_EPOCH);
return -EINVAL;
}
rtc_tm_to_time(tm, &secs);
secs -= get_elapsed_seconds(AB8500_RTC_EPOCH);
no_mins = secs / 60;
no_secs = secs % 60;
no_secs = no_secs * COUNTS_PER_SEC;
buf[4] = no_secs & 0xFF;
buf[3] = (no_secs >> 8) & 0xFF;
buf[2] = no_mins & 0xFF;
buf[1] = (no_mins >> 8) & 0xFF;
buf[0] = (no_mins >> 16) & 0xFF;
for (i = 0; i < ARRAY_SIZE(ab8500_rtc_time_regs); i++) {
retval = abx500_set_register_interruptible(dev, AB8500_RTC,
ab8500_rtc_time_regs[i], buf[i]);
if (retval < 0)
return retval;
}
return abx500_set_register_interruptible(dev, AB8500_RTC,
AB8500_RTC_READ_REQ_REG, RTC_WRITE_REQUEST);
}
static int ab8500_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
int retval, i;
u8 rtc_ctrl, value;
unsigned char buf[ARRAY_SIZE(ab8500_rtc_alarm_regs)];
unsigned long secs, mins;
retval = abx500_get_register_interruptible(dev, AB8500_RTC,
AB8500_RTC_STAT_REG, &rtc_ctrl);
if (retval < 0)
return retval;
if (rtc_ctrl & RTC_ALARM_ENA)
alarm->enabled = 1;
else
alarm->enabled = 0;
alarm->pending = 0;
for (i = 0; i < ARRAY_SIZE(ab8500_rtc_alarm_regs); i++) {
retval = abx500_get_register_interruptible(dev, AB8500_RTC,
ab8500_rtc_alarm_regs[i], &value);
if (retval < 0)
return retval;
buf[i] = value;
}
mins = (buf[0] << 16) | (buf[1] << 8) | (buf[2]);
secs = mins * 60;
secs += get_elapsed_seconds(AB8500_RTC_EPOCH);
rtc_time_to_tm(secs, &alarm->time);
return rtc_valid_tm(&alarm->time);
}
static int ab8500_rtc_irq_enable(struct device *dev, unsigned int enabled)
{
return abx500_mask_and_set_register_interruptible(dev, AB8500_RTC,
AB8500_RTC_STAT_REG, RTC_ALARM_ENA,
enabled ? RTC_ALARM_ENA : 0);
}
static int ab8500_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
int retval, i;
unsigned char buf[ARRAY_SIZE(ab8500_rtc_alarm_regs)];
unsigned long mins, secs = 0;
if (alarm->time.tm_year < (AB8500_RTC_EPOCH - 1900)) {
dev_dbg(dev, "year should be equal to or greater than %d\n",
AB8500_RTC_EPOCH);
return -EINVAL;
}
rtc_tm_to_time(&alarm->time, &secs);
secs -= get_elapsed_seconds(AB8500_RTC_EPOCH);
mins = secs / 60;
buf[2] = mins & 0xFF;
buf[1] = (mins >> 8) & 0xFF;
buf[0] = (mins >> 16) & 0xFF;
for (i = 0; i < ARRAY_SIZE(ab8500_rtc_alarm_regs); i++) {
retval = abx500_set_register_interruptible(dev, AB8500_RTC,
ab8500_rtc_alarm_regs[i], buf[i]);
if (retval < 0)
return retval;
}
return ab8500_rtc_irq_enable(dev, alarm->enabled);
}
static irqreturn_t rtc_alarm_handler(int irq, void *data)
{
struct rtc_device *rtc = data;
unsigned long events = RTC_IRQF | RTC_AF;
dev_dbg(&rtc->dev, "%s\n", __func__);
rtc_update_irq(rtc, 1, events);
return IRQ_HANDLED;
}
static int __devinit ab8500_rtc_probe(struct platform_device *pdev)
{
int err;
struct rtc_device *rtc;
u8 rtc_ctrl;
int irq;
irq = platform_get_irq_byname(pdev, "ALARM");
if (irq < 0)
return irq;
err = abx500_mask_and_set_register_interruptible(&pdev->dev, AB8500_RTC,
AB8500_RTC_STAT_REG, RTC_STATUS_DATA, RTC_STATUS_DATA);
if (err < 0)
return err;
msleep(1);
err = abx500_get_register_interruptible(&pdev->dev, AB8500_RTC,
AB8500_RTC_STAT_REG, &rtc_ctrl);
if (err < 0)
return err;
if (!(rtc_ctrl & RTC_STATUS_DATA)) {
dev_err(&pdev->dev, "RTC supply failure\n");
return -ENODEV;
}
rtc = rtc_device_register("ab8500-rtc", &pdev->dev, &ab8500_rtc_ops,
THIS_MODULE);
if (IS_ERR(rtc)) {
dev_err(&pdev->dev, "Registration failed\n");
err = PTR_ERR(rtc);
return err;
}
err = request_threaded_irq(irq, NULL, rtc_alarm_handler, 0,
"ab8500-rtc", rtc);
if (err < 0) {
rtc_device_unregister(rtc);
return err;
}
platform_set_drvdata(pdev, rtc);
return 0;
}
static int __devexit ab8500_rtc_remove(struct platform_device *pdev)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
int irq = platform_get_irq_byname(pdev, "ALARM");
free_irq(irq, rtc);
rtc_device_unregister(rtc);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init ab8500_rtc_init(void)
{
return platform_driver_register(&ab8500_rtc_driver);
}
static void __exit ab8500_rtc_exit(void)
{
platform_driver_unregister(&ab8500_rtc_driver);
}
