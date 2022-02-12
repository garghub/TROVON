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
static int ebc_c384_wdt_probe(struct device *dev, unsigned int id)
{
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
return devm_watchdog_register_device(dev, wdd);
}
static int __init ebc_c384_wdt_init(void)
{
if (!dmi_match(DMI_BOARD_NAME, "EBC-C384 SBC"))
return -ENODEV;
return isa_register_driver(&ebc_c384_wdt_driver, 1);
}
static void __exit ebc_c384_wdt_exit(void)
{
isa_unregister_driver(&ebc_c384_wdt_driver);
}
