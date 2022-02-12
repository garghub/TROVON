static enum hrtimer_restart ltc2952_poweroff_timer_wde(struct hrtimer *timer)
{
ktime_t now;
int state;
unsigned long overruns;
struct ltc2952_poweroff *data = to_ltc2952(timer, timer_wde);
if (data->kernel_panic)
return HRTIMER_NORESTART;
state = gpiod_get_value(data->gpio_watchdog);
gpiod_set_value(data->gpio_watchdog, !state);
now = hrtimer_cb_get_time(timer);
overruns = hrtimer_forward(timer, now, data->wde_interval);
return HRTIMER_RESTART;
}
static void ltc2952_poweroff_start_wde(struct ltc2952_poweroff *data)
{
hrtimer_start(&data->timer_wde, data->wde_interval, HRTIMER_MODE_REL);
}
static enum hrtimer_restart
ltc2952_poweroff_timer_trigger(struct hrtimer *timer)
{
struct ltc2952_poweroff *data = to_ltc2952(timer, timer_trigger);
ltc2952_poweroff_start_wde(data);
dev_info(data->dev, "executing shutdown\n");
orderly_poweroff(true);
return HRTIMER_NORESTART;
}
static irqreturn_t ltc2952_poweroff_handler(int irq, void *dev_id)
{
struct ltc2952_poweroff *data = dev_id;
if (data->kernel_panic || hrtimer_active(&data->timer_wde)) {
return IRQ_HANDLED;
}
if (gpiod_get_value(data->gpio_trigger)) {
hrtimer_start(&data->timer_trigger, data->trigger_delay,
HRTIMER_MODE_REL);
} else {
hrtimer_cancel(&data->timer_trigger);
}
return IRQ_HANDLED;
}
static void ltc2952_poweroff_kill(void)
{
gpiod_set_value(ltc2952_data->gpio_kill, 1);
}
static void ltc2952_poweroff_default(struct ltc2952_poweroff *data)
{
data->wde_interval = ktime_set(0, 300L*1E6L);
data->trigger_delay = ktime_set(2, 500L*1E6L);
hrtimer_init(&data->timer_trigger, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
data->timer_trigger.function = ltc2952_poweroff_timer_trigger;
hrtimer_init(&data->timer_wde, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
data->timer_wde.function = ltc2952_poweroff_timer_wde;
}
static int ltc2952_poweroff_init(struct platform_device *pdev)
{
int ret;
struct ltc2952_poweroff *data = platform_get_drvdata(pdev);
ltc2952_poweroff_default(data);
data->gpio_watchdog = devm_gpiod_get(&pdev->dev, "watchdog",
GPIOD_OUT_LOW);
if (IS_ERR(data->gpio_watchdog)) {
ret = PTR_ERR(data->gpio_watchdog);
dev_err(&pdev->dev, "unable to claim gpio \"watchdog\"\n");
return ret;
}
data->gpio_kill = devm_gpiod_get(&pdev->dev, "kill", GPIOD_OUT_LOW);
if (IS_ERR(data->gpio_kill)) {
ret = PTR_ERR(data->gpio_kill);
dev_err(&pdev->dev, "unable to claim gpio \"kill\"\n");
return ret;
}
data->gpio_trigger = devm_gpiod_get_optional(&pdev->dev, "trigger",
GPIOD_IN);
if (IS_ERR(data->gpio_trigger)) {
dev_err(&pdev->dev, "unable to claim gpio \"trigger\"\n");
data->gpio_trigger = NULL;
}
if (devm_request_irq(&pdev->dev, gpiod_to_irq(data->gpio_trigger),
ltc2952_poweroff_handler,
(IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING),
"ltc2952-poweroff",
data)) {
if (data->gpio_trigger) {
dev_warn(&pdev->dev,
"unable to configure the trigger interrupt\n");
devm_gpiod_put(&pdev->dev, data->gpio_trigger);
data->gpio_trigger = NULL;
}
dev_info(&pdev->dev,
"power down trigger input will not be used\n");
ltc2952_poweroff_start_wde(data);
}
return 0;
}
static int ltc2952_poweroff_notify_panic(struct notifier_block *nb,
unsigned long code, void *unused)
{
struct ltc2952_poweroff *data = to_ltc2952(nb, panic_notifier);
data->kernel_panic = true;
return NOTIFY_DONE;
}
static int ltc2952_poweroff_probe(struct platform_device *pdev)
{
int ret;
struct ltc2952_poweroff *data;
if (pm_power_off) {
dev_err(&pdev->dev, "pm_power_off already registered");
return -EBUSY;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->dev = &pdev->dev;
platform_set_drvdata(pdev, data);
ret = ltc2952_poweroff_init(pdev);
if (ret)
return ret;
ltc2952_data = data;
pm_power_off = ltc2952_poweroff_kill;
data->panic_notifier.notifier_call = ltc2952_poweroff_notify_panic;
atomic_notifier_chain_register(&panic_notifier_list,
&data->panic_notifier);
dev_info(&pdev->dev, "probe successful\n");
return 0;
}
static int ltc2952_poweroff_remove(struct platform_device *pdev)
{
struct ltc2952_poweroff *data = platform_get_drvdata(pdev);
pm_power_off = NULL;
hrtimer_cancel(&data->timer_trigger);
hrtimer_cancel(&data->timer_wde);
atomic_notifier_chain_unregister(&panic_notifier_list,
&data->panic_notifier);
return 0;
}
