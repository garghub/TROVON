static inline unsigned int seconds_to_ticks(int seconds)
{
return (seconds * 10) / 6;
}
static void iTCO_wdt_set_NO_REBOOT_bit(void)
{
u32 val32;
if (iTCO_wdt_private.iTCO_version == 2) {
val32 = readl(iTCO_wdt_private.gcs);
val32 |= 0x00000020;
writel(val32, iTCO_wdt_private.gcs);
} else if (iTCO_wdt_private.iTCO_version == 1) {
pci_read_config_dword(iTCO_wdt_private.pdev, 0xd4, &val32);
val32 |= 0x00000002;
pci_write_config_dword(iTCO_wdt_private.pdev, 0xd4, val32);
}
}
static int iTCO_wdt_unset_NO_REBOOT_bit(void)
{
int ret = 0;
u32 val32;
if (iTCO_wdt_private.iTCO_version == 2) {
val32 = readl(iTCO_wdt_private.gcs);
val32 &= 0xffffffdf;
writel(val32, iTCO_wdt_private.gcs);
val32 = readl(iTCO_wdt_private.gcs);
if (val32 & 0x00000020)
ret = -EIO;
} else if (iTCO_wdt_private.iTCO_version == 1) {
pci_read_config_dword(iTCO_wdt_private.pdev, 0xd4, &val32);
val32 &= 0xfffffffd;
pci_write_config_dword(iTCO_wdt_private.pdev, 0xd4, val32);
pci_read_config_dword(iTCO_wdt_private.pdev, 0xd4, &val32);
if (val32 & 0x00000002)
ret = -EIO;
}
return ret;
}
static int iTCO_wdt_start(struct watchdog_device *wd_dev)
{
unsigned int val;
spin_lock(&iTCO_wdt_private.io_lock);
iTCO_vendor_pre_start(iTCO_wdt_private.smi_res, wd_dev->timeout);
if (iTCO_wdt_unset_NO_REBOOT_bit()) {
spin_unlock(&iTCO_wdt_private.io_lock);
pr_err("failed to reset NO_REBOOT flag, reboot disabled by hardware/BIOS\n");
return -EIO;
}
if (iTCO_wdt_private.iTCO_version == 2)
outw(0x01, TCO_RLD);
else if (iTCO_wdt_private.iTCO_version == 1)
outb(0x01, TCO_RLD);
val = inw(TCO1_CNT);
val &= 0xf7ff;
outw(val, TCO1_CNT);
val = inw(TCO1_CNT);
spin_unlock(&iTCO_wdt_private.io_lock);
if (val & 0x0800)
return -1;
return 0;
}
static int iTCO_wdt_stop(struct watchdog_device *wd_dev)
{
unsigned int val;
spin_lock(&iTCO_wdt_private.io_lock);
iTCO_vendor_pre_stop(iTCO_wdt_private.smi_res);
val = inw(TCO1_CNT);
val |= 0x0800;
outw(val, TCO1_CNT);
val = inw(TCO1_CNT);
iTCO_wdt_set_NO_REBOOT_bit();
spin_unlock(&iTCO_wdt_private.io_lock);
if ((val & 0x0800) == 0)
return -1;
return 0;
}
static int iTCO_wdt_ping(struct watchdog_device *wd_dev)
{
spin_lock(&iTCO_wdt_private.io_lock);
iTCO_vendor_pre_keepalive(iTCO_wdt_private.smi_res, wd_dev->timeout);
if (iTCO_wdt_private.iTCO_version == 2)
outw(0x01, TCO_RLD);
else if (iTCO_wdt_private.iTCO_version == 1) {
outw(0x0008, TCO1_STS);
outb(0x01, TCO_RLD);
}
spin_unlock(&iTCO_wdt_private.io_lock);
return 0;
}
static int iTCO_wdt_set_timeout(struct watchdog_device *wd_dev, unsigned int t)
{
unsigned int val16;
unsigned char val8;
unsigned int tmrval;
tmrval = seconds_to_ticks(t);
if (iTCO_wdt_private.iTCO_version == 1)
tmrval /= 2;
if (tmrval < 0x04)
return -EINVAL;
if (((iTCO_wdt_private.iTCO_version == 2) && (tmrval > 0x3ff)) ||
((iTCO_wdt_private.iTCO_version == 1) && (tmrval > 0x03f)))
return -EINVAL;
iTCO_vendor_pre_set_heartbeat(tmrval);
if (iTCO_wdt_private.iTCO_version == 2) {
spin_lock(&iTCO_wdt_private.io_lock);
val16 = inw(TCOv2_TMR);
val16 &= 0xfc00;
val16 |= tmrval;
outw(val16, TCOv2_TMR);
val16 = inw(TCOv2_TMR);
spin_unlock(&iTCO_wdt_private.io_lock);
if ((val16 & 0x3ff) != tmrval)
return -EINVAL;
} else if (iTCO_wdt_private.iTCO_version == 1) {
spin_lock(&iTCO_wdt_private.io_lock);
val8 = inb(TCOv1_TMR);
val8 &= 0xc0;
val8 |= (tmrval & 0xff);
outb(val8, TCOv1_TMR);
val8 = inb(TCOv1_TMR);
spin_unlock(&iTCO_wdt_private.io_lock);
if ((val8 & 0x3f) != tmrval)
return -EINVAL;
}
wd_dev->timeout = t;
return 0;
}
static unsigned int iTCO_wdt_get_timeleft(struct watchdog_device *wd_dev)
{
unsigned int val16;
unsigned char val8;
unsigned int time_left = 0;
if (iTCO_wdt_private.iTCO_version == 2) {
spin_lock(&iTCO_wdt_private.io_lock);
val16 = inw(TCO_RLD);
val16 &= 0x3ff;
spin_unlock(&iTCO_wdt_private.io_lock);
time_left = (val16 * 6) / 10;
} else if (iTCO_wdt_private.iTCO_version == 1) {
spin_lock(&iTCO_wdt_private.io_lock);
val8 = inb(TCO_RLD);
val8 &= 0x3f;
if (!(inw(TCO1_STS) & 0x0008))
val8 += (inb(TCOv1_TMR) & 0x3f);
spin_unlock(&iTCO_wdt_private.io_lock);
time_left = (val8 * 6) / 10;
}
return time_left;
}
static void iTCO_wdt_cleanup(void)
{
if (!nowayout)
iTCO_wdt_stop(&iTCO_wdt_watchdog_dev);
watchdog_unregister_device(&iTCO_wdt_watchdog_dev);
release_region(iTCO_wdt_private.tco_res->start,
resource_size(iTCO_wdt_private.tco_res));
release_region(iTCO_wdt_private.smi_res->start,
resource_size(iTCO_wdt_private.smi_res));
if (iTCO_wdt_private.iTCO_version == 2) {
iounmap(iTCO_wdt_private.gcs);
release_mem_region(iTCO_wdt_private.gcs_res->start,
resource_size(iTCO_wdt_private.gcs_res));
}
iTCO_wdt_private.tco_res = NULL;
iTCO_wdt_private.smi_res = NULL;
iTCO_wdt_private.gcs_res = NULL;
iTCO_wdt_private.gcs = NULL;
}
static int iTCO_wdt_probe(struct platform_device *dev)
{
int ret = -ENODEV;
unsigned long val32;
struct lpc_ich_info *ich_info = dev_get_platdata(&dev->dev);
if (!ich_info)
goto out;
spin_lock_init(&iTCO_wdt_private.io_lock);
iTCO_wdt_private.tco_res =
platform_get_resource(dev, IORESOURCE_IO, ICH_RES_IO_TCO);
if (!iTCO_wdt_private.tco_res)
goto out;
iTCO_wdt_private.smi_res =
platform_get_resource(dev, IORESOURCE_IO, ICH_RES_IO_SMI);
if (!iTCO_wdt_private.smi_res)
goto out;
iTCO_wdt_private.iTCO_version = ich_info->iTCO_version;
iTCO_wdt_private.dev = dev;
iTCO_wdt_private.pdev = to_pci_dev(dev->dev.parent);
if (iTCO_wdt_private.iTCO_version == 2) {
iTCO_wdt_private.gcs_res = platform_get_resource(dev,
IORESOURCE_MEM,
ICH_RES_MEM_GCS);
if (!iTCO_wdt_private.gcs_res)
goto out;
if (!request_mem_region(iTCO_wdt_private.gcs_res->start,
resource_size(iTCO_wdt_private.gcs_res), dev->name)) {
ret = -EBUSY;
goto out;
}
iTCO_wdt_private.gcs = ioremap(iTCO_wdt_private.gcs_res->start,
resource_size(iTCO_wdt_private.gcs_res));
if (!iTCO_wdt_private.gcs) {
ret = -EIO;
goto unreg_gcs;
}
}
if (iTCO_wdt_unset_NO_REBOOT_bit() && iTCO_vendor_check_noreboot_on()) {
pr_info("unable to reset NO_REBOOT flag, device disabled by hardware/BIOS\n");
ret = -ENODEV;
goto unmap_gcs;
}
iTCO_wdt_set_NO_REBOOT_bit();
if (!request_region(iTCO_wdt_private.smi_res->start,
resource_size(iTCO_wdt_private.smi_res), dev->name)) {
pr_err("I/O address 0x%04llx already in use, device disabled\n",
(u64)SMI_EN);
ret = -EBUSY;
goto unmap_gcs;
}
if (turn_SMI_watchdog_clear_off >= iTCO_wdt_private.iTCO_version) {
val32 = inl(SMI_EN);
val32 &= 0xffffdfff;
outl(val32, SMI_EN);
}
if (!request_region(iTCO_wdt_private.tco_res->start,
resource_size(iTCO_wdt_private.tco_res), dev->name)) {
pr_err("I/O address 0x%04llx already in use, device disabled\n",
(u64)TCOBASE);
ret = -EBUSY;
goto unreg_smi;
}
pr_info("Found a %s TCO device (Version=%d, TCOBASE=0x%04llx)\n",
ich_info->name, ich_info->iTCO_version, (u64)TCOBASE);
outw(0x0008, TCO1_STS);
outw(0x0002, TCO2_STS);
outw(0x0004, TCO2_STS);
iTCO_wdt_watchdog_dev.bootstatus = 0;
iTCO_wdt_watchdog_dev.timeout = WATCHDOG_TIMEOUT;
watchdog_set_nowayout(&iTCO_wdt_watchdog_dev, nowayout);
iTCO_wdt_watchdog_dev.parent = dev->dev.parent;
iTCO_wdt_stop(&iTCO_wdt_watchdog_dev);
if (iTCO_wdt_set_timeout(&iTCO_wdt_watchdog_dev, heartbeat)) {
iTCO_wdt_set_timeout(&iTCO_wdt_watchdog_dev, WATCHDOG_TIMEOUT);
pr_info("timeout value out of range, using %d\n",
WATCHDOG_TIMEOUT);
}
ret = watchdog_register_device(&iTCO_wdt_watchdog_dev);
if (ret != 0) {
pr_err("cannot register watchdog device (err=%d)\n", ret);
goto unreg_tco;
}
pr_info("initialized. heartbeat=%d sec (nowayout=%d)\n",
heartbeat, nowayout);
return 0;
unreg_tco:
release_region(iTCO_wdt_private.tco_res->start,
resource_size(iTCO_wdt_private.tco_res));
unreg_smi:
release_region(iTCO_wdt_private.smi_res->start,
resource_size(iTCO_wdt_private.smi_res));
unmap_gcs:
if (iTCO_wdt_private.iTCO_version == 2)
iounmap(iTCO_wdt_private.gcs);
unreg_gcs:
if (iTCO_wdt_private.iTCO_version == 2)
release_mem_region(iTCO_wdt_private.gcs_res->start,
resource_size(iTCO_wdt_private.gcs_res));
out:
iTCO_wdt_private.tco_res = NULL;
iTCO_wdt_private.smi_res = NULL;
iTCO_wdt_private.gcs_res = NULL;
iTCO_wdt_private.gcs = NULL;
return ret;
}
static int iTCO_wdt_remove(struct platform_device *dev)
{
if (iTCO_wdt_private.tco_res || iTCO_wdt_private.smi_res)
iTCO_wdt_cleanup();
return 0;
}
static void iTCO_wdt_shutdown(struct platform_device *dev)
{
iTCO_wdt_stop(NULL);
}
static int __init iTCO_wdt_init_module(void)
{
int err;
pr_info("Intel TCO WatchDog Timer Driver v%s\n", DRV_VERSION);
err = platform_driver_register(&iTCO_wdt_driver);
if (err)
return err;
return 0;
}
static void __exit iTCO_wdt_cleanup_module(void)
{
platform_driver_unregister(&iTCO_wdt_driver);
pr_info("Watchdog Module Unloaded\n");
}
