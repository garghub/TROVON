static void retu_wdt_ping_enable(struct retu_wdt_dev *wdev)
{
retu_write(wdev->rdev, RETU_REG_WATCHDOG, RETU_WDT_MAX_TIMER);
schedule_delayed_work(&wdev->ping_work,
round_jiffies_relative(RETU_WDT_MAX_TIMER * HZ / 2));
}
static void retu_wdt_ping_disable(struct retu_wdt_dev *wdev)
{
retu_write(wdev->rdev, RETU_REG_WATCHDOG, RETU_WDT_MAX_TIMER);
cancel_delayed_work_sync(&wdev->ping_work);
}
static void retu_wdt_ping_work(struct work_struct *work)
{
struct retu_wdt_dev *wdev = container_of(to_delayed_work(work),
struct retu_wdt_dev, ping_work);
retu_wdt_ping_enable(wdev);
}
static int retu_wdt_start(struct watchdog_device *wdog)
{
struct retu_wdt_dev *wdev = watchdog_get_drvdata(wdog);
retu_wdt_ping_disable(wdev);
return retu_write(wdev->rdev, RETU_REG_WATCHDOG, wdog->timeout);
}
static int retu_wdt_stop(struct watchdog_device *wdog)
{
struct retu_wdt_dev *wdev = watchdog_get_drvdata(wdog);
retu_wdt_ping_enable(wdev);
return 0;
}
static int retu_wdt_ping(struct watchdog_device *wdog)
{
struct retu_wdt_dev *wdev = watchdog_get_drvdata(wdog);
return retu_write(wdev->rdev, RETU_REG_WATCHDOG, wdog->timeout);
}
static int retu_wdt_set_timeout(struct watchdog_device *wdog,
unsigned int timeout)
{
struct retu_wdt_dev *wdev = watchdog_get_drvdata(wdog);
wdog->timeout = timeout;
return retu_write(wdev->rdev, RETU_REG_WATCHDOG, wdog->timeout);
}
static int retu_wdt_probe(struct platform_device *pdev)
{
struct retu_dev *rdev = dev_get_drvdata(pdev->dev.parent);
bool nowayout = WATCHDOG_NOWAYOUT;
struct watchdog_device *retu_wdt;
struct retu_wdt_dev *wdev;
int ret;
retu_wdt = devm_kzalloc(&pdev->dev, sizeof(*retu_wdt), GFP_KERNEL);
if (!retu_wdt)
return -ENOMEM;
wdev = devm_kzalloc(&pdev->dev, sizeof(*wdev), GFP_KERNEL);
if (!wdev)
return -ENOMEM;
retu_wdt->info = &retu_wdt_info;
retu_wdt->ops = &retu_wdt_ops;
retu_wdt->timeout = RETU_WDT_MAX_TIMER;
retu_wdt->min_timeout = 0;
retu_wdt->max_timeout = RETU_WDT_MAX_TIMER;
watchdog_set_drvdata(retu_wdt, wdev);
watchdog_set_nowayout(retu_wdt, nowayout);
wdev->rdev = rdev;
wdev->dev = &pdev->dev;
INIT_DELAYED_WORK(&wdev->ping_work, retu_wdt_ping_work);
ret = watchdog_register_device(retu_wdt);
if (ret < 0)
return ret;
if (nowayout)
retu_wdt_ping(retu_wdt);
else
retu_wdt_ping_enable(wdev);
platform_set_drvdata(pdev, retu_wdt);
return 0;
}
static int retu_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdog = platform_get_drvdata(pdev);
struct retu_wdt_dev *wdev = watchdog_get_drvdata(wdog);
watchdog_unregister_device(wdog);
cancel_delayed_work_sync(&wdev->ping_work);
return 0;
}
