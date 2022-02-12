static int __sh_rtc_interrupt(struct sh_rtc *rtc)
{
unsigned int tmp, pending;
tmp = readb(rtc->regbase + RCR1);
pending = tmp & RCR1_CF;
tmp &= ~RCR1_CF;
writeb(tmp, rtc->regbase + RCR1);
if (pending && rtc->periodic_freq & PF_OXS)
rtc_update_irq(rtc->rtc_dev, 1, RTC_UF | RTC_IRQF);
return pending;
}
static int __sh_rtc_alarm(struct sh_rtc *rtc)
{
unsigned int tmp, pending;
tmp = readb(rtc->regbase + RCR1);
pending = tmp & RCR1_AF;
tmp &= ~(RCR1_AF | RCR1_AIE);
writeb(tmp, rtc->regbase + RCR1);
if (pending)
rtc_update_irq(rtc->rtc_dev, 1, RTC_AF | RTC_IRQF);
return pending;
}
static int __sh_rtc_periodic(struct sh_rtc *rtc)
{
struct rtc_device *rtc_dev = rtc->rtc_dev;
struct rtc_task *irq_task;
unsigned int tmp, pending;
tmp = readb(rtc->regbase + RCR2);
pending = tmp & RCR2_PEF;
tmp &= ~RCR2_PEF;
writeb(tmp, rtc->regbase + RCR2);
if (!pending)
return 0;
if ((rtc->periodic_freq & PF_HP) && (rtc->periodic_freq & PF_COUNT))
rtc->periodic_freq &= ~PF_COUNT;
else {
if (rtc->periodic_freq & PF_HP)
rtc->periodic_freq |= PF_COUNT;
if (rtc->periodic_freq & PF_KOU) {
spin_lock(&rtc_dev->irq_task_lock);
irq_task = rtc_dev->irq_task;
if (irq_task)
irq_task->func(irq_task->private_data);
spin_unlock(&rtc_dev->irq_task_lock);
} else
rtc_update_irq(rtc->rtc_dev, 1, RTC_PF | RTC_IRQF);
}
return pending;
}
static irqreturn_t sh_rtc_interrupt(int irq, void *dev_id)
{
struct sh_rtc *rtc = dev_id;
int ret;
spin_lock(&rtc->lock);
ret = __sh_rtc_interrupt(rtc);
spin_unlock(&rtc->lock);
return IRQ_RETVAL(ret);
}
static irqreturn_t sh_rtc_alarm(int irq, void *dev_id)
{
struct sh_rtc *rtc = dev_id;
int ret;
spin_lock(&rtc->lock);
ret = __sh_rtc_alarm(rtc);
spin_unlock(&rtc->lock);
return IRQ_RETVAL(ret);
}
static irqreturn_t sh_rtc_periodic(int irq, void *dev_id)
{
struct sh_rtc *rtc = dev_id;
int ret;
spin_lock(&rtc->lock);
ret = __sh_rtc_periodic(rtc);
spin_unlock(&rtc->lock);
return IRQ_RETVAL(ret);
}
static irqreturn_t sh_rtc_shared(int irq, void *dev_id)
{
struct sh_rtc *rtc = dev_id;
int ret;
spin_lock(&rtc->lock);
ret = __sh_rtc_interrupt(rtc);
ret |= __sh_rtc_alarm(rtc);
ret |= __sh_rtc_periodic(rtc);
spin_unlock(&rtc->lock);
return IRQ_RETVAL(ret);
}
static int sh_rtc_irq_set_state(struct device *dev, int enable)
{
struct sh_rtc *rtc = dev_get_drvdata(dev);
unsigned int tmp;
spin_lock_irq(&rtc->lock);
tmp = readb(rtc->regbase + RCR2);
if (enable) {
rtc->periodic_freq |= PF_KOU;
tmp &= ~RCR2_PEF;
tmp |= (rtc->periodic_freq & ~PF_HP);
} else {
rtc->periodic_freq &= ~PF_KOU;
tmp &= ~(RCR2_PESMASK | RCR2_PEF);
}
writeb(tmp, rtc->regbase + RCR2);
spin_unlock_irq(&rtc->lock);
return 0;
}
static int sh_rtc_irq_set_freq(struct device *dev, int freq)
{
struct sh_rtc *rtc = dev_get_drvdata(dev);
int tmp, ret = 0;
spin_lock_irq(&rtc->lock);
tmp = rtc->periodic_freq & PF_MASK;
switch (freq) {
case 0:
rtc->periodic_freq = 0x00;
break;
case 1:
rtc->periodic_freq = 0x60;
break;
case 2:
rtc->periodic_freq = 0x50;
break;
case 4:
rtc->periodic_freq = 0x40;
break;
case 8:
rtc->periodic_freq = 0x30 | PF_HP;
break;
case 16:
rtc->periodic_freq = 0x30;
break;
case 32:
rtc->periodic_freq = 0x20 | PF_HP;
break;
case 64:
rtc->periodic_freq = 0x20;
break;
case 128:
rtc->periodic_freq = 0x10 | PF_HP;
break;
case 256:
rtc->periodic_freq = 0x10;
break;
default:
ret = -ENOTSUPP;
}
if (ret == 0)
rtc->periodic_freq |= tmp;
spin_unlock_irq(&rtc->lock);
return ret;
}
static inline void sh_rtc_setaie(struct device *dev, unsigned int enable)
{
struct sh_rtc *rtc = dev_get_drvdata(dev);
unsigned int tmp;
spin_lock_irq(&rtc->lock);
tmp = readb(rtc->regbase + RCR1);
if (enable)
tmp |= RCR1_AIE;
else
tmp &= ~RCR1_AIE;
writeb(tmp, rtc->regbase + RCR1);
spin_unlock_irq(&rtc->lock);
}
static int sh_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct sh_rtc *rtc = dev_get_drvdata(dev);
unsigned int tmp;
tmp = readb(rtc->regbase + RCR1);
seq_printf(seq, "carry_IRQ\t: %s\n", (tmp & RCR1_CIE) ? "yes" : "no");
tmp = readb(rtc->regbase + RCR2);
seq_printf(seq, "periodic_IRQ\t: %s\n",
(tmp & RCR2_PESMASK) ? "yes" : "no");
return 0;
}
static inline void sh_rtc_setcie(struct device *dev, unsigned int enable)
{
struct sh_rtc *rtc = dev_get_drvdata(dev);
unsigned int tmp;
spin_lock_irq(&rtc->lock);
tmp = readb(rtc->regbase + RCR1);
if (!enable)
tmp &= ~RCR1_CIE;
else
tmp |= RCR1_CIE;
writeb(tmp, rtc->regbase + RCR1);
spin_unlock_irq(&rtc->lock);
}
static int sh_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
sh_rtc_setaie(dev, enabled);
return 0;
}
static int sh_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_rtc *rtc = platform_get_drvdata(pdev);
unsigned int sec128, sec2, yr, yr100, cf_bit;
do {
unsigned int tmp;
spin_lock_irq(&rtc->lock);
tmp = readb(rtc->regbase + RCR1);
tmp &= ~RCR1_CF;
tmp |= RCR1_CIE;
writeb(tmp, rtc->regbase + RCR1);
sec128 = readb(rtc->regbase + R64CNT);
tm->tm_sec = bcd2bin(readb(rtc->regbase + RSECCNT));
tm->tm_min = bcd2bin(readb(rtc->regbase + RMINCNT));
tm->tm_hour = bcd2bin(readb(rtc->regbase + RHRCNT));
tm->tm_wday = bcd2bin(readb(rtc->regbase + RWKCNT));
tm->tm_mday = bcd2bin(readb(rtc->regbase + RDAYCNT));
tm->tm_mon = bcd2bin(readb(rtc->regbase + RMONCNT)) - 1;
if (rtc->capabilities & RTC_CAP_4_DIGIT_YEAR) {
yr = readw(rtc->regbase + RYRCNT);
yr100 = bcd2bin(yr >> 8);
yr &= 0xff;
} else {
yr = readb(rtc->regbase + RYRCNT);
yr100 = bcd2bin((yr == 0x99) ? 0x19 : 0x20);
}
tm->tm_year = (yr100 * 100 + bcd2bin(yr)) - 1900;
sec2 = readb(rtc->regbase + R64CNT);
cf_bit = readb(rtc->regbase + RCR1) & RCR1_CF;
spin_unlock_irq(&rtc->lock);
} while (cf_bit != 0 || ((sec128 ^ sec2) & RTC_BIT_INVERTED) != 0);
#if RTC_BIT_INVERTED != 0
if ((sec128 & RTC_BIT_INVERTED))
tm->tm_sec--;
#endif
if (!(rtc->periodic_freq & PF_OXS))
sh_rtc_setcie(dev, 0);
dev_dbg(dev, "%s: tm is secs=%d, mins=%d, hours=%d, "
"mday=%d, mon=%d, year=%d, wday=%d\n",
__func__,
tm->tm_sec, tm->tm_min, tm->tm_hour,
tm->tm_mday, tm->tm_mon + 1, tm->tm_year, tm->tm_wday);
return rtc_valid_tm(tm);
}
static int sh_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_rtc *rtc = platform_get_drvdata(pdev);
unsigned int tmp;
int year;
spin_lock_irq(&rtc->lock);
tmp = readb(rtc->regbase + RCR2);
tmp |= RCR2_RESET;
tmp &= ~RCR2_START;
writeb(tmp, rtc->regbase + RCR2);
writeb(bin2bcd(tm->tm_sec), rtc->regbase + RSECCNT);
writeb(bin2bcd(tm->tm_min), rtc->regbase + RMINCNT);
writeb(bin2bcd(tm->tm_hour), rtc->regbase + RHRCNT);
writeb(bin2bcd(tm->tm_wday), rtc->regbase + RWKCNT);
writeb(bin2bcd(tm->tm_mday), rtc->regbase + RDAYCNT);
writeb(bin2bcd(tm->tm_mon + 1), rtc->regbase + RMONCNT);
if (rtc->capabilities & RTC_CAP_4_DIGIT_YEAR) {
year = (bin2bcd((tm->tm_year + 1900) / 100) << 8) |
bin2bcd(tm->tm_year % 100);
writew(year, rtc->regbase + RYRCNT);
} else {
year = tm->tm_year % 100;
writeb(bin2bcd(year), rtc->regbase + RYRCNT);
}
tmp = readb(rtc->regbase + RCR2);
tmp &= ~RCR2_RESET;
tmp |= RCR2_RTCEN | RCR2_START;
writeb(tmp, rtc->regbase + RCR2);
spin_unlock_irq(&rtc->lock);
return 0;
}
static inline int sh_rtc_read_alarm_value(struct sh_rtc *rtc, int reg_off)
{
unsigned int byte;
int value = 0xff;
byte = readb(rtc->regbase + reg_off);
if (byte & AR_ENB) {
byte &= ~AR_ENB;
value = bcd2bin(byte);
}
return value;
}
static int sh_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_rtc *rtc = platform_get_drvdata(pdev);
struct rtc_time *tm = &wkalrm->time;
spin_lock_irq(&rtc->lock);
tm->tm_sec = sh_rtc_read_alarm_value(rtc, RSECAR);
tm->tm_min = sh_rtc_read_alarm_value(rtc, RMINAR);
tm->tm_hour = sh_rtc_read_alarm_value(rtc, RHRAR);
tm->tm_wday = sh_rtc_read_alarm_value(rtc, RWKAR);
tm->tm_mday = sh_rtc_read_alarm_value(rtc, RDAYAR);
tm->tm_mon = sh_rtc_read_alarm_value(rtc, RMONAR);
if (tm->tm_mon > 0)
tm->tm_mon -= 1;
tm->tm_year = 0xffff;
wkalrm->enabled = (readb(rtc->regbase + RCR1) & RCR1_AIE) ? 1 : 0;
spin_unlock_irq(&rtc->lock);
return 0;
}
static inline void sh_rtc_write_alarm_value(struct sh_rtc *rtc,
int value, int reg_off)
{
if (value < 0)
writeb(0, rtc->regbase + reg_off);
else
writeb(bin2bcd(value) | AR_ENB, rtc->regbase + reg_off);
}
static int sh_rtc_check_alarm(struct rtc_time *tm)
{
if (tm->tm_year == 0xffff)
tm->tm_year = -1;
if (tm->tm_mon >= 0xff)
tm->tm_mon = -1;
if (tm->tm_mday >= 0xff)
tm->tm_mday = -1;
if (tm->tm_wday >= 0xff)
tm->tm_wday = -1;
if (tm->tm_hour >= 0xff)
tm->tm_hour = -1;
if (tm->tm_min >= 0xff)
tm->tm_min = -1;
if (tm->tm_sec >= 0xff)
tm->tm_sec = -1;
if (tm->tm_year > 9999 ||
tm->tm_mon >= 12 ||
tm->tm_mday == 0 || tm->tm_mday >= 32 ||
tm->tm_wday >= 7 ||
tm->tm_hour >= 24 ||
tm->tm_min >= 60 ||
tm->tm_sec >= 60)
return -EINVAL;
return 0;
}
static int sh_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *wkalrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_rtc *rtc = platform_get_drvdata(pdev);
unsigned int rcr1;
struct rtc_time *tm = &wkalrm->time;
int mon, err;
err = sh_rtc_check_alarm(tm);
if (unlikely(err < 0))
return err;
spin_lock_irq(&rtc->lock);
rcr1 = readb(rtc->regbase + RCR1);
rcr1 &= ~(RCR1_AF | RCR1_AIE);
writeb(rcr1, rtc->regbase + RCR1);
sh_rtc_write_alarm_value(rtc, tm->tm_sec, RSECAR);
sh_rtc_write_alarm_value(rtc, tm->tm_min, RMINAR);
sh_rtc_write_alarm_value(rtc, tm->tm_hour, RHRAR);
sh_rtc_write_alarm_value(rtc, tm->tm_wday, RWKAR);
sh_rtc_write_alarm_value(rtc, tm->tm_mday, RDAYAR);
mon = tm->tm_mon;
if (mon >= 0)
mon += 1;
sh_rtc_write_alarm_value(rtc, mon, RMONAR);
if (wkalrm->enabled) {
rcr1 |= RCR1_AIE;
writeb(rcr1, rtc->regbase + RCR1);
}
spin_unlock_irq(&rtc->lock);
return 0;
}
static int __init sh_rtc_probe(struct platform_device *pdev)
{
struct sh_rtc *rtc;
struct resource *res;
struct rtc_time r;
char clk_name[6];
int clk_id, ret;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (unlikely(!rtc))
return -ENOMEM;
spin_lock_init(&rtc->lock);
ret = platform_get_irq(pdev, 0);
if (unlikely(ret <= 0)) {
dev_err(&pdev->dev, "No IRQ resource\n");
return -ENOENT;
}
rtc->periodic_irq = ret;
rtc->carry_irq = platform_get_irq(pdev, 1);
rtc->alarm_irq = platform_get_irq(pdev, 2);
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (unlikely(res == NULL)) {
dev_err(&pdev->dev, "No IO resource\n");
return -ENOENT;
}
rtc->regsize = resource_size(res);
rtc->res = devm_request_mem_region(&pdev->dev, res->start,
rtc->regsize, pdev->name);
if (unlikely(!rtc->res))
return -EBUSY;
rtc->regbase = devm_ioremap_nocache(&pdev->dev, rtc->res->start,
rtc->regsize);
if (unlikely(!rtc->regbase))
return -EINVAL;
clk_id = pdev->id;
if (clk_id < 0)
clk_id = 0;
snprintf(clk_name, sizeof(clk_name), "rtc%d", clk_id);
rtc->clk = devm_clk_get(&pdev->dev, clk_name);
if (IS_ERR(rtc->clk)) {
rtc->clk = NULL;
}
clk_enable(rtc->clk);
rtc->capabilities = RTC_DEF_CAPABILITIES;
if (dev_get_platdata(&pdev->dev)) {
struct sh_rtc_platform_info *pinfo =
dev_get_platdata(&pdev->dev);
rtc->capabilities |= pinfo->capabilities;
}
if (rtc->carry_irq <= 0) {
ret = devm_request_irq(&pdev->dev, rtc->periodic_irq,
sh_rtc_shared, 0, "sh-rtc", rtc);
if (unlikely(ret)) {
dev_err(&pdev->dev,
"request IRQ failed with %d, IRQ %d\n", ret,
rtc->periodic_irq);
goto err_unmap;
}
} else {
ret = devm_request_irq(&pdev->dev, rtc->periodic_irq,
sh_rtc_periodic, 0, "sh-rtc period", rtc);
if (unlikely(ret)) {
dev_err(&pdev->dev,
"request period IRQ failed with %d, IRQ %d\n",
ret, rtc->periodic_irq);
goto err_unmap;
}
ret = devm_request_irq(&pdev->dev, rtc->carry_irq,
sh_rtc_interrupt, 0, "sh-rtc carry", rtc);
if (unlikely(ret)) {
dev_err(&pdev->dev,
"request carry IRQ failed with %d, IRQ %d\n",
ret, rtc->carry_irq);
goto err_unmap;
}
ret = devm_request_irq(&pdev->dev, rtc->alarm_irq,
sh_rtc_alarm, 0, "sh-rtc alarm", rtc);
if (unlikely(ret)) {
dev_err(&pdev->dev,
"request alarm IRQ failed with %d, IRQ %d\n",
ret, rtc->alarm_irq);
goto err_unmap;
}
}
platform_set_drvdata(pdev, rtc);
sh_rtc_irq_set_freq(&pdev->dev, 0);
sh_rtc_irq_set_state(&pdev->dev, 0);
sh_rtc_setaie(&pdev->dev, 0);
sh_rtc_setcie(&pdev->dev, 0);
rtc->rtc_dev = devm_rtc_device_register(&pdev->dev, "sh",
&sh_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev)) {
ret = PTR_ERR(rtc->rtc_dev);
goto err_unmap;
}
rtc->rtc_dev->max_user_freq = 256;
if (rtc_read_time(rtc->rtc_dev, &r) < 0) {
rtc_time_to_tm(0, &r);
rtc_set_time(rtc->rtc_dev, &r);
}
device_init_wakeup(&pdev->dev, 1);
return 0;
err_unmap:
clk_disable(rtc->clk);
return ret;
}
static int __exit sh_rtc_remove(struct platform_device *pdev)
{
struct sh_rtc *rtc = platform_get_drvdata(pdev);
sh_rtc_irq_set_state(&pdev->dev, 0);
sh_rtc_setaie(&pdev->dev, 0);
sh_rtc_setcie(&pdev->dev, 0);
clk_disable(rtc->clk);
return 0;
}
static void sh_rtc_set_irq_wake(struct device *dev, int enabled)
{
struct platform_device *pdev = to_platform_device(dev);
struct sh_rtc *rtc = platform_get_drvdata(pdev);
irq_set_irq_wake(rtc->periodic_irq, enabled);
if (rtc->carry_irq > 0) {
irq_set_irq_wake(rtc->carry_irq, enabled);
irq_set_irq_wake(rtc->alarm_irq, enabled);
}
}
static int sh_rtc_suspend(struct device *dev)
{
if (device_may_wakeup(dev))
sh_rtc_set_irq_wake(dev, 1);
return 0;
}
static int sh_rtc_resume(struct device *dev)
{
if (device_may_wakeup(dev))
sh_rtc_set_irq_wake(dev, 0);
return 0;
}
