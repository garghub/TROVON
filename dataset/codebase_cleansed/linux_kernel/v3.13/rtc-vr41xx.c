static inline unsigned long read_elapsed_second(void)
{
unsigned long first_low, first_mid, first_high;
unsigned long second_low, second_mid, second_high;
do {
first_low = rtc1_read(ETIMELREG);
first_mid = rtc1_read(ETIMEMREG);
first_high = rtc1_read(ETIMEHREG);
second_low = rtc1_read(ETIMELREG);
second_mid = rtc1_read(ETIMEMREG);
second_high = rtc1_read(ETIMEHREG);
} while (first_low != second_low || first_mid != second_mid ||
first_high != second_high);
return (first_high << 17) | (first_mid << 1) | (first_low >> 15);
}
static inline void write_elapsed_second(unsigned long sec)
{
spin_lock_irq(&rtc_lock);
rtc1_write(ETIMELREG, (uint16_t)(sec << 15));
rtc1_write(ETIMEMREG, (uint16_t)(sec >> 1));
rtc1_write(ETIMEHREG, (uint16_t)(sec >> 17));
spin_unlock_irq(&rtc_lock);
}
static void vr41xx_rtc_release(struct device *dev)
{
spin_lock_irq(&rtc_lock);
rtc1_write(ECMPLREG, 0);
rtc1_write(ECMPMREG, 0);
rtc1_write(ECMPHREG, 0);
rtc1_write(RTCL1LREG, 0);
rtc1_write(RTCL1HREG, 0);
spin_unlock_irq(&rtc_lock);
disable_irq(aie_irq);
disable_irq(pie_irq);
}
static int vr41xx_rtc_read_time(struct device *dev, struct rtc_time *time)
{
unsigned long epoch_sec, elapsed_sec;
epoch_sec = mktime(epoch, 1, 1, 0, 0, 0);
elapsed_sec = read_elapsed_second();
rtc_time_to_tm(epoch_sec + elapsed_sec, time);
return 0;
}
static int vr41xx_rtc_set_time(struct device *dev, struct rtc_time *time)
{
unsigned long epoch_sec, current_sec;
epoch_sec = mktime(epoch, 1, 1, 0, 0, 0);
current_sec = mktime(time->tm_year + 1900, time->tm_mon + 1, time->tm_mday,
time->tm_hour, time->tm_min, time->tm_sec);
write_elapsed_second(current_sec - epoch_sec);
return 0;
}
static int vr41xx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
unsigned long low, mid, high;
struct rtc_time *time = &wkalrm->time;
spin_lock_irq(&rtc_lock);
low = rtc1_read(ECMPLREG);
mid = rtc1_read(ECMPMREG);
high = rtc1_read(ECMPHREG);
wkalrm->enabled = alarm_enabled;
spin_unlock_irq(&rtc_lock);
rtc_time_to_tm((high << 17) | (mid << 1) | (low >> 15), time);
return 0;
}
static int vr41xx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
unsigned long alarm_sec;
struct rtc_time *time = &wkalrm->time;
alarm_sec = mktime(time->tm_year + 1900, time->tm_mon + 1, time->tm_mday,
time->tm_hour, time->tm_min, time->tm_sec);
spin_lock_irq(&rtc_lock);
if (alarm_enabled)
disable_irq(aie_irq);
rtc1_write(ECMPLREG, (uint16_t)(alarm_sec << 15));
rtc1_write(ECMPMREG, (uint16_t)(alarm_sec >> 1));
rtc1_write(ECMPHREG, (uint16_t)(alarm_sec >> 17));
if (wkalrm->enabled)
enable_irq(aie_irq);
alarm_enabled = wkalrm->enabled;
spin_unlock_irq(&rtc_lock);
return 0;
}
static int vr41xx_rtc_ioctl(struct device *dev, unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case RTC_EPOCH_READ:
return put_user(epoch, (unsigned long __user *)arg);
case RTC_EPOCH_SET:
if (arg < 1900)
return -EINVAL;
epoch = arg;
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int vr41xx_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
spin_lock_irq(&rtc_lock);
if (enabled) {
if (!alarm_enabled) {
enable_irq(aie_irq);
alarm_enabled = 1;
}
} else {
if (alarm_enabled) {
disable_irq(aie_irq);
alarm_enabled = 0;
}
}
spin_unlock_irq(&rtc_lock);
return 0;
}
static irqreturn_t elapsedtime_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = (struct platform_device *)dev_id;
struct rtc_device *rtc = platform_get_drvdata(pdev);
rtc2_write(RTCINTREG, ELAPSEDTIME_INT);
rtc_update_irq(rtc, 1, RTC_AF);
return IRQ_HANDLED;
}
static irqreturn_t rtclong1_interrupt(int irq, void *dev_id)
{
struct platform_device *pdev = (struct platform_device *)dev_id;
struct rtc_device *rtc = platform_get_drvdata(pdev);
unsigned long count = periodic_count;
rtc2_write(RTCINTREG, RTCLONG1_INT);
rtc1_write(RTCL1LREG, count);
rtc1_write(RTCL1HREG, count >> 16);
rtc_update_irq(rtc, 1, RTC_PF);
return IRQ_HANDLED;
}
static int rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct rtc_device *rtc;
int retval;
if (pdev->num_resources != 4)
return -EBUSY;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EBUSY;
rtc1_base = ioremap(res->start, resource_size(res));
if (!rtc1_base)
return -EBUSY;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
retval = -EBUSY;
goto err_rtc1_iounmap;
}
rtc2_base = ioremap(res->start, resource_size(res));
if (!rtc2_base) {
retval = -EBUSY;
goto err_rtc1_iounmap;
}
rtc = rtc_device_register(rtc_name, &pdev->dev, &vr41xx_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
retval = PTR_ERR(rtc);
goto err_iounmap_all;
}
rtc->max_user_freq = MAX_PERIODIC_RATE;
spin_lock_irq(&rtc_lock);
rtc1_write(ECMPLREG, 0);
rtc1_write(ECMPMREG, 0);
rtc1_write(ECMPHREG, 0);
rtc1_write(RTCL1LREG, 0);
rtc1_write(RTCL1HREG, 0);
spin_unlock_irq(&rtc_lock);
aie_irq = platform_get_irq(pdev, 0);
if (aie_irq <= 0) {
retval = -EBUSY;
goto err_device_unregister;
}
retval = request_irq(aie_irq, elapsedtime_interrupt, 0,
"elapsed_time", pdev);
if (retval < 0)
goto err_device_unregister;
pie_irq = platform_get_irq(pdev, 1);
if (pie_irq <= 0) {
retval = -EBUSY;
goto err_free_irq;
}
retval = request_irq(pie_irq, rtclong1_interrupt, 0,
"rtclong1", pdev);
if (retval < 0)
goto err_free_irq;
platform_set_drvdata(pdev, rtc);
disable_irq(aie_irq);
disable_irq(pie_irq);
dev_info(&pdev->dev, "Real Time Clock of NEC VR4100 series\n");
return 0;
err_free_irq:
free_irq(aie_irq, pdev);
err_device_unregister:
rtc_device_unregister(rtc);
err_iounmap_all:
iounmap(rtc2_base);
rtc2_base = NULL;
err_rtc1_iounmap:
iounmap(rtc1_base);
rtc1_base = NULL;
return retval;
}
static int rtc_remove(struct platform_device *pdev)
{
struct rtc_device *rtc;
rtc = platform_get_drvdata(pdev);
if (rtc)
rtc_device_unregister(rtc);
free_irq(aie_irq, pdev);
free_irq(pie_irq, pdev);
if (rtc1_base)
iounmap(rtc1_base);
if (rtc2_base)
iounmap(rtc2_base);
return 0;
}
