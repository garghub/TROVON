static int ebc_c384_wdt_start(struct watchdog_device *wdev)
{
unsigned t = wdev->timeout;
if (t > 255)
t = DIV_ROUND_UP(t, 60);
outb(t, PET_ADDR);
return 0;
}
static int ebc_c384_wdt_stop(struct watchdog_device *wdev)
{
outb(0x00, PET_ADDR);
return 0;
}
static int ebc_c384_wdt_set_timeout(struct watchdog_device *wdev, unsigned t)
{
if (t > 255) {
wdev->timeout = roundup(t, 60);
outb(0x00, CFG_ADDR);
} else {
wdev->timeout = t;
outb(0x80, CFG_ADDR);
}
return 0;
}
static int __init ebc_c384_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct watchdog_device *wdd;
if (!devm_request_region(dev, BASE_ADDR, ADDR_EXTENT, dev_name(dev))) {
dev_err(dev, "Unable to lock port addresses (0x%X-0x%X)\n",
BASE_ADDR, BASE_ADDR + ADDR_EXTENT);
return -EBUSY;
}
wdd = devm_kzalloc(dev, sizeof(*wdd), GFP_KERNEL);
if (!wdd)
return -ENOMEM;
wdd->info = &ebc_c384_wdt_info;
wdd->ops = &ebc_c384_wdt_ops;
wdd->timeout = WATCHDOG_TIMEOUT;
wdd->min_timeout = 1;
wdd->max_timeout = WATCHDOG_MAX_TIMEOUT;
watchdog_set_nowayout(wdd, nowayout);
if (watchdog_init_timeout(wdd, timeout, dev))
dev_warn(dev, "Invalid timeout (%u seconds), using default (%u seconds)\n",
timeout, WATCHDOG_TIMEOUT);
platform_set_drvdata(pdev, wdd);
return watchdog_register_device(wdd);
}
static int ebc_c384_wdt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
watchdog_unregister_device(wdd);
return 0;
}
static int __init ebc_c384_wdt_init(void)
{
int err;
if (!dmi_match(DMI_BOARD_NAME, "EBC-C384 SBC"))
return -ENODEV;
ebc_c384_wdt_device = platform_device_alloc(MODULE_NAME, -1);
if (!ebc_c384_wdt_device)
return -ENOMEM;
err = platform_device_add(ebc_c384_wdt_device);
if (err)
goto err_platform_device;
err = platform_driver_probe(&ebc_c384_wdt_driver, ebc_c384_wdt_probe);
if (err)
goto err_platform_driver;
return 0;
err_platform_driver:
platform_device_del(ebc_c384_wdt_device);
err_platform_device:
platform_device_put(ebc_c384_wdt_device);
return err;
}
static void __exit ebc_c384_wdt_exit(void)
{
platform_device_unregister(ebc_c384_wdt_device);
platform_driver_unregister(&ebc_c384_wdt_driver);
}
