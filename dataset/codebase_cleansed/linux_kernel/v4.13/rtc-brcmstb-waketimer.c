static inline void brcmstb_waketmr_clear_alarm(struct brcmstb_waketmr *timer)
{
writel_relaxed(1, timer->base + BRCMSTB_WKTMR_EVENT);
(void)readl_relaxed(timer->base + BRCMSTB_WKTMR_EVENT);
}
static void brcmstb_waketmr_set_alarm(struct brcmstb_waketmr *timer,
unsigned int secs)
{
brcmstb_waketmr_clear_alarm(timer);
writel_relaxed(secs + 1, timer->base + BRCMSTB_WKTMR_ALARM);
}
static irqreturn_t brcmstb_waketmr_irq(int irq, void *data)
{
struct brcmstb_waketmr *timer = data;
pm_wakeup_event(timer->dev, 0);
return IRQ_HANDLED;
}
static void wktmr_read(struct brcmstb_waketmr *timer,
struct wktmr_time *t)
{
u32 tmp;
do {
t->sec = readl_relaxed(timer->base + BRCMSTB_WKTMR_COUNTER);
tmp = readl_relaxed(timer->base + BRCMSTB_WKTMR_PRESCALER_VAL);
} while (tmp >= timer->rate);
t->pre = timer->rate - tmp;
}
static int brcmstb_waketmr_prepare_suspend(struct brcmstb_waketmr *timer)
{
struct device *dev = timer->dev;
int ret = 0;
if (device_may_wakeup(dev)) {
ret = enable_irq_wake(timer->irq);
if (ret) {
dev_err(dev, "failed to enable wake-up interrupt\n");
return ret;
}
}
return ret;
}
static int brcmstb_waketmr_reboot(struct notifier_block *nb,
unsigned long action, void *data)
{
struct brcmstb_waketmr *timer;
timer = container_of(nb, struct brcmstb_waketmr, reboot_notifier);
if (action == SYS_POWER_OFF)
brcmstb_waketmr_prepare_suspend(timer);
return NOTIFY_DONE;
}
static int brcmstb_waketmr_gettime(struct device *dev,
struct rtc_time *tm)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(dev);
struct wktmr_time now;
wktmr_read(timer, &now);
rtc_time_to_tm(now.sec, tm);
return 0;
}
static int brcmstb_waketmr_settime(struct device *dev,
struct rtc_time *tm)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(dev);
time64_t sec;
sec = rtc_tm_to_time64(tm);
if (sec > U32_MAX || sec < 0)
return -EINVAL;
writel_relaxed(sec, timer->base + BRCMSTB_WKTMR_COUNTER);
return 0;
}
static int brcmstb_waketmr_getalarm(struct device *dev,
struct rtc_wkalrm *alarm)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(dev);
time64_t sec;
u32 reg;
sec = readl_relaxed(timer->base + BRCMSTB_WKTMR_ALARM);
if (sec != 0) {
alarm->enabled = 1;
rtc_time64_to_tm(sec, &alarm->time);
}
reg = readl_relaxed(timer->base + BRCMSTB_WKTMR_EVENT);
alarm->pending = !!(reg & 1);
return 0;
}
static int brcmstb_waketmr_setalarm(struct device *dev,
struct rtc_wkalrm *alarm)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(dev);
time64_t sec;
if (alarm->enabled)
sec = rtc_tm_to_time64(&alarm->time);
else
sec = 0;
if (sec > U32_MAX || sec < 0)
return -EINVAL;
brcmstb_waketmr_set_alarm(timer, sec);
return 0;
}
static int brcmstb_waketmr_alarm_enable(struct device *dev,
unsigned int enabled)
{
return 0;
}
static int brcmstb_waketmr_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct brcmstb_waketmr *timer;
struct resource *res;
int ret;
timer = devm_kzalloc(dev, sizeof(*timer), GFP_KERNEL);
if (!timer)
return -ENOMEM;
platform_set_drvdata(pdev, timer);
timer->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
timer->base = devm_ioremap_resource(dev, res);
if (IS_ERR(timer->base))
return PTR_ERR(timer->base);
device_set_wakeup_capable(dev, true);
device_wakeup_enable(dev);
timer->irq = platform_get_irq(pdev, 0);
if (timer->irq < 0)
return -ENODEV;
timer->clk = devm_clk_get(dev, NULL);
if (!IS_ERR(timer->clk)) {
ret = clk_prepare_enable(timer->clk);
if (ret)
return ret;
timer->rate = clk_get_rate(timer->clk);
if (!timer->rate)
timer->rate = BRCMSTB_WKTMR_DEFAULT_FREQ;
} else {
timer->rate = BRCMSTB_WKTMR_DEFAULT_FREQ;
timer->clk = NULL;
}
ret = devm_request_irq(dev, timer->irq, brcmstb_waketmr_irq, 0,
"brcmstb-waketimer", timer);
if (ret < 0)
return ret;
timer->reboot_notifier.notifier_call = brcmstb_waketmr_reboot;
register_reboot_notifier(&timer->reboot_notifier);
timer->rtc = rtc_device_register("brcmstb-waketmr", dev,
&brcmstb_waketmr_ops, THIS_MODULE);
if (IS_ERR(timer->rtc)) {
dev_err(dev, "unable to register device\n");
unregister_reboot_notifier(&timer->reboot_notifier);
return PTR_ERR(timer->rtc);
}
dev_info(dev, "registered, with irq %d\n", timer->irq);
return ret;
}
static int brcmstb_waketmr_remove(struct platform_device *pdev)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(&pdev->dev);
unregister_reboot_notifier(&timer->reboot_notifier);
rtc_device_unregister(timer->rtc);
return 0;
}
static int brcmstb_waketmr_suspend(struct device *dev)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(dev);
return brcmstb_waketmr_prepare_suspend(timer);
}
static int brcmstb_waketmr_resume(struct device *dev)
{
struct brcmstb_waketmr *timer = dev_get_drvdata(dev);
int ret;
if (!device_may_wakeup(dev))
return 0;
ret = disable_irq_wake(timer->irq);
brcmstb_waketmr_clear_alarm(timer);
return ret;
}
