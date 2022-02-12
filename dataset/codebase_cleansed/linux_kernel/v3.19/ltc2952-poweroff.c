static enum hrtimer_restart ltc2952_poweroff_timer_wde(struct hrtimer *timer)
{
ktime_t now;
int state;
unsigned long overruns;
if (ltc2952_poweroff_panic)
return HRTIMER_NORESTART;
state = gpiod_get_value(ltc2952_data->gpio[POWERPATH_IO_WATCHDOG]);
gpiod_set_value(ltc2952_data->gpio[POWERPATH_IO_WATCHDOG], !state);
now = hrtimer_cb_get_time(timer);
overruns = hrtimer_forward(timer, now, ltc2952_data->wde_interval);
return HRTIMER_RESTART;
}
static enum hrtimer_restart ltc2952_poweroff_timer_trigger(
struct hrtimer *timer)
{
int ret;
ret = hrtimer_start(&ltc2952_data->timer_wde,
ltc2952_data->wde_interval, HRTIMER_MODE_REL);
if (ret) {
dev_err(ltc2952_data->dev, "unable to start the timer\n");
}
dev_info(ltc2952_data->dev, "executing shutdown\n");
orderly_poweroff(true);
return HRTIMER_NORESTART;
}
static irqreturn_t ltc2952_poweroff_handler(int irq, void *dev_id)
{
int ret;
struct ltc2952_poweroff_data *data = dev_id;
if (ltc2952_poweroff_panic)
goto irq_ok;
if (hrtimer_active(&data->timer_wde)) {
goto irq_ok;
}
if (!hrtimer_active(&data->timer_trigger)) {
ret = hrtimer_start(&data->timer_trigger, data->trigger_delay,
HRTIMER_MODE_REL);
if (ret)
dev_err(data->dev, "unable to start the wait timer\n");
} else {
ret = hrtimer_cancel(&data->timer_trigger);
}
irq_ok:
return IRQ_HANDLED;
}
static void ltc2952_poweroff_kill(void)
{
gpiod_set_value(ltc2952_data->gpio[POWERPATH_IO_KILL], 1);
}
static int ltc2952_poweroff_suspend(struct platform_device *pdev,
pm_message_t state)
{
return -ENOSYS;
}
static int ltc2952_poweroff_resume(struct platform_device *pdev)
{
return -ENOSYS;
}
static void ltc2952_poweroff_default(struct ltc2952_poweroff_data *data)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(data->gpio); i++)
data->gpio[i] = NULL;
data->wde_interval = ktime_set(0, 300L*1E6L);
data->trigger_delay = ktime_set(2, 500L*1E6L);
hrtimer_init(&data->timer_trigger, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
data->timer_trigger.function = &ltc2952_poweroff_timer_trigger;
hrtimer_init(&data->timer_wde, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
data->timer_wde.function = &ltc2952_poweroff_timer_wde;
}
static int ltc2952_poweroff_init(struct platform_device *pdev)
{
int ret, virq;
unsigned int i;
struct ltc2952_poweroff_data *data;
static char *name[] = {
"trigger",
"watchdog",
"kill",
NULL
};
data = ltc2952_data;
ltc2952_poweroff_default(ltc2952_data);
for (i = 0; i < ARRAY_SIZE(ltc2952_data->gpio); i++) {
ltc2952_data->gpio[i] = gpiod_get(&pdev->dev, name[i]);
if (IS_ERR(ltc2952_data->gpio[i])) {
ret = PTR_ERR(ltc2952_data->gpio[i]);
dev_err(&pdev->dev,
"unable to claim the following gpio: %s\n",
name[i]);
goto err_io;
}
}
ret = gpiod_direction_output(
ltc2952_data->gpio[POWERPATH_IO_WATCHDOG], 0);
if (ret) {
dev_err(&pdev->dev, "unable to use watchdog-gpio as output\n");
goto err_io;
}
ret = gpiod_direction_output(ltc2952_data->gpio[POWERPATH_IO_KILL], 0);
if (ret) {
dev_err(&pdev->dev, "unable to use kill-gpio as output\n");
goto err_io;
}
virq = gpiod_to_irq(ltc2952_data->gpio[POWERPATH_IO_TRIGGER]);
if (virq < 0) {
dev_err(&pdev->dev, "cannot map GPIO as interrupt");
goto err_io;
}
ltc2952_data->virq = virq;
ret = request_irq(virq,
ltc2952_poweroff_handler,
(IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING),
"ltc2952-poweroff",
ltc2952_data
);
if (ret) {
dev_err(&pdev->dev, "cannot configure an interrupt handler\n");
goto err_io;
}
return 0;
err_io:
for (i = 0; i < ARRAY_SIZE(ltc2952_data->gpio); i++)
if (ltc2952_data->gpio[i])
gpiod_put(ltc2952_data->gpio[i]);
return ret;
}
static int ltc2952_poweroff_probe(struct platform_device *pdev)
{
int ret;
if (pm_power_off) {
dev_err(&pdev->dev, "pm_power_off already registered");
return -EBUSY;
}
ltc2952_data = kzalloc(sizeof(*ltc2952_data), GFP_KERNEL);
if (!ltc2952_data)
return -ENOMEM;
ltc2952_data->dev = &pdev->dev;
ret = ltc2952_poweroff_init(pdev);
if (ret)
goto err;
pm_power_off = &ltc2952_poweroff_kill;
dev_info(&pdev->dev, "probe successful\n");
return 0;
err:
kfree(ltc2952_data);
return ret;
}
static int ltc2952_poweroff_remove(struct platform_device *pdev)
{
unsigned int i;
pm_power_off = NULL;
if (ltc2952_data) {
free_irq(ltc2952_data->virq, ltc2952_data);
for (i = 0; i < ARRAY_SIZE(ltc2952_data->gpio); i++)
gpiod_put(ltc2952_data->gpio[i]);
kfree(ltc2952_data);
}
return 0;
}
static int ltc2952_poweroff_notify_panic(struct notifier_block *nb,
unsigned long code, void *unused)
{
ltc2952_poweroff_panic = 1;
return NOTIFY_DONE;
}
static int __init ltc2952_poweroff_platform_init(void)
{
ltc2952_poweroff_panic = 0;
atomic_notifier_chain_register(&panic_notifier_list,
&ltc2952_poweroff_panic_nb);
return platform_driver_register(&ltc2952_poweroff_driver);
}
static void __exit ltc2952_poweroff_platform_exit(void)
{
atomic_notifier_chain_unregister(&panic_notifier_list,
&ltc2952_poweroff_panic_nb);
platform_driver_unregister(&ltc2952_poweroff_driver);
}
