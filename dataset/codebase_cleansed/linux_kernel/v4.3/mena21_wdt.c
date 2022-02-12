static unsigned int a21_wdt_get_bootstatus(struct a21_wdt_drv *drv)
{
int reset = 0;
reset |= gpio_get_value(drv->gpios[GPIO_WD_RST0]) ? (1 << 0) : 0;
reset |= gpio_get_value(drv->gpios[GPIO_WD_RST1]) ? (1 << 1) : 0;
reset |= gpio_get_value(drv->gpios[GPIO_WD_RST2]) ? (1 << 2) : 0;
return reset;
}
static int a21_wdt_start(struct watchdog_device *wdt)
{
struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);
mutex_lock(&drv->lock);
gpio_set_value(drv->gpios[GPIO_WD_ENAB], 1);
mutex_unlock(&drv->lock);
return 0;
}
static int a21_wdt_stop(struct watchdog_device *wdt)
{
struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);
mutex_lock(&drv->lock);
gpio_set_value(drv->gpios[GPIO_WD_ENAB], 0);
mutex_unlock(&drv->lock);
return 0;
}
static int a21_wdt_ping(struct watchdog_device *wdt)
{
struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);
mutex_lock(&drv->lock);
gpio_set_value(drv->gpios[GPIO_WD_TRIG], 0);
ndelay(10);
gpio_set_value(drv->gpios[GPIO_WD_TRIG], 1);
mutex_unlock(&drv->lock);
return 0;
}
static int a21_wdt_set_timeout(struct watchdog_device *wdt,
unsigned int timeout)
{
struct a21_wdt_drv *drv = watchdog_get_drvdata(wdt);
if (timeout != 1 && timeout != 30) {
dev_err(wdt->dev, "Only 1 and 30 allowed as timeout\n");
return -EINVAL;
}
if (timeout == 30 && wdt->timeout == 1) {
dev_err(wdt->dev,
"Transition from fast to slow mode not allowed\n");
return -EINVAL;
}
mutex_lock(&drv->lock);
if (timeout == 1)
gpio_set_value(drv->gpios[GPIO_WD_FAST], 1);
else
gpio_set_value(drv->gpios[GPIO_WD_FAST], 0);
wdt->timeout = timeout;
mutex_unlock(&drv->lock);
return 0;
}
static int a21_wdt_probe(struct platform_device *pdev)
{
struct device_node *node;
struct a21_wdt_drv *drv;
unsigned int reset = 0;
int num_gpios;
int ret;
int i;
drv = devm_kzalloc(&pdev->dev, sizeof(struct a21_wdt_drv), GFP_KERNEL);
if (!drv)
return -ENOMEM;
node = pdev->dev.of_node;
num_gpios = of_gpio_count(node);
if (num_gpios != NUM_GPIOS) {
dev_err(&pdev->dev, "gpios DT property wrong, got %d want %d",
num_gpios, NUM_GPIOS);
return -ENODEV;
}
for (i = 0; i < num_gpios; i++) {
int val;
val = of_get_gpio(node, i);
if (val < 0)
return val;
drv->gpios[i] = val;
}
for (i = 0; i < num_gpios; i++) {
ret = devm_gpio_request(&pdev->dev, drv->gpios[i],
"MEN A21 Watchdog");
if (ret)
return ret;
if (i < GPIO_WD_RST0)
ret = gpio_direction_output(drv->gpios[i],
gpio_get_value(drv->gpios[i]));
else
ret = gpio_direction_input(drv->gpios[i]);
if (ret)
return ret;
}
mutex_init(&drv->lock);
watchdog_init_timeout(&a21_wdt, 30, &pdev->dev);
watchdog_set_nowayout(&a21_wdt, nowayout);
watchdog_set_drvdata(&a21_wdt, drv);
a21_wdt.parent = &pdev->dev;
reset = a21_wdt_get_bootstatus(drv);
if (reset == 2)
a21_wdt.bootstatus |= WDIOF_EXTERN1;
else if (reset == 4)
a21_wdt.bootstatus |= WDIOF_CARDRESET;
else if (reset == 5)
a21_wdt.bootstatus |= WDIOF_POWERUNDER;
else if (reset == 7)
a21_wdt.bootstatus |= WDIOF_EXTERN2;
drv->wdt = a21_wdt;
dev_set_drvdata(&pdev->dev, drv);
ret = watchdog_register_device(&a21_wdt);
if (ret) {
dev_err(&pdev->dev, "Cannot register watchdog device\n");
goto err_register_wd;
}
dev_info(&pdev->dev, "MEN A21 watchdog timer driver enabled\n");
return 0;
err_register_wd:
mutex_destroy(&drv->lock);
return ret;
}
static int a21_wdt_remove(struct platform_device *pdev)
{
struct a21_wdt_drv *drv = dev_get_drvdata(&pdev->dev);
dev_warn(&pdev->dev,
"Unregistering A21 watchdog driver, board may reboot\n");
watchdog_unregister_device(&drv->wdt);
mutex_destroy(&drv->lock);
return 0;
}
static void a21_wdt_shutdown(struct platform_device *pdev)
{
struct a21_wdt_drv *drv = dev_get_drvdata(&pdev->dev);
gpio_set_value(drv->gpios[GPIO_WD_ENAB], 0);
}
