static inline void wdt_reset(void)
{
unsigned int ctl = readl(wdt_mem);
writel(ctl | VIA_WDT_TRIGGER, wdt_mem);
}
static void wdt_timer_tick(unsigned long data)
{
if (time_before(jiffies, next_heartbeat) ||
(!watchdog_active(&wdt_dev))) {
wdt_reset();
mod_timer(&timer, jiffies + WDT_HEARTBEAT);
} else
pr_crit("I will reboot your machine !\n");
}
static int wdt_ping(struct watchdog_device *wdd)
{
next_heartbeat = jiffies + wdd->timeout * HZ;
return 0;
}
static int wdt_start(struct watchdog_device *wdd)
{
unsigned int ctl = readl(wdt_mem);
writel(wdd->timeout, wdt_mem + VIA_WDT_COUNT);
writel(ctl | VIA_WDT_RUNNING | VIA_WDT_TRIGGER, wdt_mem);
wdt_ping(wdd);
mod_timer(&timer, jiffies + WDT_HEARTBEAT);
return 0;
}
static int wdt_stop(struct watchdog_device *wdd)
{
unsigned int ctl = readl(wdt_mem);
writel(ctl & ~VIA_WDT_RUNNING, wdt_mem);
return 0;
}
static int wdt_set_timeout(struct watchdog_device *wdd,
unsigned int new_timeout)
{
writel(new_timeout, wdt_mem + VIA_WDT_COUNT);
wdd->timeout = new_timeout;
return 0;
}
static int wdt_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned char conf;
int ret = -ENODEV;
if (pci_enable_device(pdev)) {
dev_err(&pdev->dev, "cannot enable PCI device\n");
return -ENODEV;
}
if (allocate_resource(&iomem_resource, &wdt_res, VIA_WDT_MMIO_LEN,
0xf0000000, 0xffffff00, 0xff, NULL, NULL)) {
dev_err(&pdev->dev, "MMIO allocation failed\n");
goto err_out_disable_device;
}
pci_write_config_dword(pdev, VIA_WDT_MMIO_BASE, wdt_res.start);
pci_read_config_byte(pdev, VIA_WDT_CONF, &conf);
conf |= VIA_WDT_CONF_ENABLE | VIA_WDT_CONF_MMIO;
pci_write_config_byte(pdev, VIA_WDT_CONF, conf);
pci_read_config_dword(pdev, VIA_WDT_MMIO_BASE, &mmio);
if (mmio) {
dev_info(&pdev->dev, "VIA Chipset watchdog MMIO: %x\n", mmio);
} else {
dev_err(&pdev->dev, "MMIO setting failed. Check BIOS.\n");
goto err_out_resource;
}
if (!request_mem_region(mmio, VIA_WDT_MMIO_LEN, "via_wdt")) {
dev_err(&pdev->dev, "MMIO region busy\n");
goto err_out_resource;
}
wdt_mem = ioremap(mmio, VIA_WDT_MMIO_LEN);
if (wdt_mem == NULL) {
dev_err(&pdev->dev, "cannot remap VIA wdt MMIO registers\n");
goto err_out_release;
}
if (timeout < 1 || timeout > WDT_TIMEOUT_MAX)
timeout = WDT_TIMEOUT;
wdt_dev.timeout = timeout;
watchdog_set_nowayout(&wdt_dev, nowayout);
if (readl(wdt_mem) & VIA_WDT_FIRED)
wdt_dev.bootstatus |= WDIOF_CARDRESET;
ret = watchdog_register_device(&wdt_dev);
if (ret)
goto err_out_iounmap;
mod_timer(&timer, jiffies + WDT_HEARTBEAT);
return 0;
err_out_iounmap:
iounmap(wdt_mem);
err_out_release:
release_mem_region(mmio, VIA_WDT_MMIO_LEN);
err_out_resource:
release_resource(&wdt_res);
err_out_disable_device:
pci_disable_device(pdev);
return ret;
}
static void wdt_remove(struct pci_dev *pdev)
{
watchdog_unregister_device(&wdt_dev);
del_timer(&timer);
iounmap(wdt_mem);
release_mem_region(mmio, VIA_WDT_MMIO_LEN);
release_resource(&wdt_res);
pci_disable_device(pdev);
}
