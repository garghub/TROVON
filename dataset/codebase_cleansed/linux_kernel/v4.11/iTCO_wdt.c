static inline unsigned int seconds_to_ticks(struct iTCO_wdt_private *p,
int secs)
{
return p->iTCO_version == 3 ? secs : (secs * 10) / 6;
}
static inline unsigned int ticks_to_seconds(struct iTCO_wdt_private *p,
int ticks)
{
return p->iTCO_version == 3 ? ticks : (ticks * 6) / 10;
}
static inline u32 no_reboot_bit(struct iTCO_wdt_private *p)
{
u32 enable_bit;
switch (p->iTCO_version) {
case 5:
case 3:
enable_bit = 0x00000010;
break;
case 2:
enable_bit = 0x00000020;
break;
case 4:
case 1:
default:
enable_bit = 0x00000002;
break;
}
return enable_bit;
}
static void iTCO_wdt_set_NO_REBOOT_bit(struct iTCO_wdt_private *p)
{
u32 val32;
if (p->iTCO_version >= 2) {
val32 = readl(p->gcs_pmc);
val32 |= no_reboot_bit(p);
writel(val32, p->gcs_pmc);
} else if (p->iTCO_version == 1) {
pci_read_config_dword(p->pci_dev, 0xd4, &val32);
val32 |= no_reboot_bit(p);
pci_write_config_dword(p->pci_dev, 0xd4, val32);
}
}
static int iTCO_wdt_unset_NO_REBOOT_bit(struct iTCO_wdt_private *p)
{
u32 enable_bit = no_reboot_bit(p);
u32 val32 = 0;
if (p->iTCO_version >= 2) {
val32 = readl(p->gcs_pmc);
val32 &= ~enable_bit;
writel(val32, p->gcs_pmc);
val32 = readl(p->gcs_pmc);
} else if (p->iTCO_version == 1) {
pci_read_config_dword(p->pci_dev, 0xd4, &val32);
val32 &= ~enable_bit;
pci_write_config_dword(p->pci_dev, 0xd4, val32);
pci_read_config_dword(p->pci_dev, 0xd4, &val32);
}
if (val32 & enable_bit)
return -EIO;
return 0;
}
static int iTCO_wdt_start(struct watchdog_device *wd_dev)
{
struct iTCO_wdt_private *p = watchdog_get_drvdata(wd_dev);
unsigned int val;
spin_lock(&p->io_lock);
iTCO_vendor_pre_start(p->smi_res, wd_dev->timeout);
if (iTCO_wdt_unset_NO_REBOOT_bit(p)) {
spin_unlock(&p->io_lock);
pr_err("failed to reset NO_REBOOT flag, reboot disabled by hardware/BIOS\n");
return -EIO;
}
if (p->iTCO_version >= 2)
outw(0x01, TCO_RLD(p));
else if (p->iTCO_version == 1)
outb(0x01, TCO_RLD(p));
val = inw(TCO1_CNT(p));
val &= 0xf7ff;
outw(val, TCO1_CNT(p));
val = inw(TCO1_CNT(p));
spin_unlock(&p->io_lock);
if (val & 0x0800)
return -1;
return 0;
}
static int iTCO_wdt_stop(struct watchdog_device *wd_dev)
{
struct iTCO_wdt_private *p = watchdog_get_drvdata(wd_dev);
unsigned int val;
spin_lock(&p->io_lock);
iTCO_vendor_pre_stop(p->smi_res);
val = inw(TCO1_CNT(p));
val |= 0x0800;
outw(val, TCO1_CNT(p));
val = inw(TCO1_CNT(p));
iTCO_wdt_set_NO_REBOOT_bit(p);
spin_unlock(&p->io_lock);
if ((val & 0x0800) == 0)
return -1;
return 0;
}
static int iTCO_wdt_ping(struct watchdog_device *wd_dev)
{
struct iTCO_wdt_private *p = watchdog_get_drvdata(wd_dev);
spin_lock(&p->io_lock);
iTCO_vendor_pre_keepalive(p->smi_res, wd_dev->timeout);
if (p->iTCO_version >= 2) {
outw(0x01, TCO_RLD(p));
} else if (p->iTCO_version == 1) {
outw(0x0008, TCO1_STS(p));
outb(0x01, TCO_RLD(p));
}
spin_unlock(&p->io_lock);
return 0;
}
static int iTCO_wdt_set_timeout(struct watchdog_device *wd_dev, unsigned int t)
{
struct iTCO_wdt_private *p = watchdog_get_drvdata(wd_dev);
unsigned int val16;
unsigned char val8;
unsigned int tmrval;
tmrval = seconds_to_ticks(p, t);
if (p->iTCO_version == 1)
tmrval /= 2;
if (tmrval < 0x04)
return -EINVAL;
if ((p->iTCO_version >= 2 && tmrval > 0x3ff) ||
(p->iTCO_version == 1 && tmrval > 0x03f))
return -EINVAL;
iTCO_vendor_pre_set_heartbeat(tmrval);
if (p->iTCO_version >= 2) {
spin_lock(&p->io_lock);
val16 = inw(TCOv2_TMR(p));
val16 &= 0xfc00;
val16 |= tmrval;
outw(val16, TCOv2_TMR(p));
val16 = inw(TCOv2_TMR(p));
spin_unlock(&p->io_lock);
if ((val16 & 0x3ff) != tmrval)
return -EINVAL;
} else if (p->iTCO_version == 1) {
spin_lock(&p->io_lock);
val8 = inb(TCOv1_TMR(p));
val8 &= 0xc0;
val8 |= (tmrval & 0xff);
outb(val8, TCOv1_TMR(p));
val8 = inb(TCOv1_TMR(p));
spin_unlock(&p->io_lock);
if ((val8 & 0x3f) != tmrval)
return -EINVAL;
}
wd_dev->timeout = t;
return 0;
}
static unsigned int iTCO_wdt_get_timeleft(struct watchdog_device *wd_dev)
{
struct iTCO_wdt_private *p = watchdog_get_drvdata(wd_dev);
unsigned int val16;
unsigned char val8;
unsigned int time_left = 0;
if (p->iTCO_version >= 2) {
spin_lock(&p->io_lock);
val16 = inw(TCO_RLD(p));
val16 &= 0x3ff;
spin_unlock(&p->io_lock);
time_left = ticks_to_seconds(p, val16);
} else if (p->iTCO_version == 1) {
spin_lock(&p->io_lock);
val8 = inb(TCO_RLD(p));
val8 &= 0x3f;
if (!(inw(TCO1_STS(p)) & 0x0008))
val8 += (inb(TCOv1_TMR(p)) & 0x3f);
spin_unlock(&p->io_lock);
time_left = ticks_to_seconds(p, val8);
}
return time_left;
}
static int iTCO_wdt_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct itco_wdt_platform_data *pdata = dev_get_platdata(dev);
struct iTCO_wdt_private *p;
unsigned long val32;
int ret;
if (!pdata)
return -ENODEV;
p = devm_kzalloc(dev, sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
spin_lock_init(&p->io_lock);
p->tco_res = platform_get_resource(pdev, IORESOURCE_IO, ICH_RES_IO_TCO);
if (!p->tco_res)
return -ENODEV;
p->smi_res = platform_get_resource(pdev, IORESOURCE_IO, ICH_RES_IO_SMI);
if (!p->smi_res)
return -ENODEV;
p->iTCO_version = pdata->version;
p->pci_dev = to_pci_dev(dev->parent);
if (p->iTCO_version >= 2) {
p->gcs_pmc_res = platform_get_resource(pdev,
IORESOURCE_MEM,
ICH_RES_MEM_GCS_PMC);
p->gcs_pmc = devm_ioremap_resource(dev, p->gcs_pmc_res);
if (IS_ERR(p->gcs_pmc))
return PTR_ERR(p->gcs_pmc);
}
if (iTCO_wdt_unset_NO_REBOOT_bit(p) &&
iTCO_vendor_check_noreboot_on()) {
pr_info("unable to reset NO_REBOOT flag, device disabled by hardware/BIOS\n");
return -ENODEV;
}
iTCO_wdt_set_NO_REBOOT_bit(p);
if (!devm_request_region(dev, p->smi_res->start,
resource_size(p->smi_res),
pdev->name)) {
pr_err("I/O address 0x%04llx already in use, device disabled\n",
(u64)SMI_EN(p));
return -EBUSY;
}
if (turn_SMI_watchdog_clear_off >= p->iTCO_version) {
val32 = inl(SMI_EN(p));
val32 &= 0xffffdfff;
outl(val32, SMI_EN(p));
}
if (!devm_request_region(dev, p->tco_res->start,
resource_size(p->tco_res),
pdev->name)) {
pr_err("I/O address 0x%04llx already in use, device disabled\n",
(u64)TCOBASE(p));
return -EBUSY;
}
pr_info("Found a %s TCO device (Version=%d, TCOBASE=0x%04llx)\n",
pdata->name, pdata->version, (u64)TCOBASE(p));
switch (p->iTCO_version) {
case 5:
case 4:
outw(0x0008, TCO1_STS(p));
outw(0x0002, TCO2_STS(p));
break;
case 3:
outl(0x20008, TCO1_STS(p));
break;
case 2:
case 1:
default:
outw(0x0008, TCO1_STS(p));
outw(0x0002, TCO2_STS(p));
outw(0x0004, TCO2_STS(p));
break;
}
p->wddev.info = &ident,
p->wddev.ops = &iTCO_wdt_ops,
p->wddev.bootstatus = 0;
p->wddev.timeout = WATCHDOG_TIMEOUT;
watchdog_set_nowayout(&p->wddev, nowayout);
p->wddev.parent = dev;
watchdog_set_drvdata(&p->wddev, p);
platform_set_drvdata(pdev, p);
iTCO_wdt_stop(&p->wddev);
if (iTCO_wdt_set_timeout(&p->wddev, heartbeat)) {
iTCO_wdt_set_timeout(&p->wddev, WATCHDOG_TIMEOUT);
pr_info("timeout value out of range, using %d\n",
WATCHDOG_TIMEOUT);
}
watchdog_stop_on_reboot(&p->wddev);
ret = devm_watchdog_register_device(dev, &p->wddev);
if (ret != 0) {
pr_err("cannot register watchdog device (err=%d)\n", ret);
return ret;
}
pr_info("initialized. heartbeat=%d sec (nowayout=%d)\n",
heartbeat, nowayout);
return 0;
}
static int iTCO_wdt_remove(struct platform_device *pdev)
{
struct iTCO_wdt_private *p = platform_get_drvdata(pdev);
if (!nowayout)
iTCO_wdt_stop(&p->wddev);
return 0;
}
static inline bool need_suspend(void)
{
return acpi_target_system_state() == ACPI_STATE_S0;
}
static inline bool need_suspend(void) { return true; }
static int iTCO_wdt_suspend_noirq(struct device *dev)
{
struct iTCO_wdt_private *p = dev_get_drvdata(dev);
int ret = 0;
p->suspended = false;
if (watchdog_active(&p->wddev) && need_suspend()) {
ret = iTCO_wdt_stop(&p->wddev);
if (!ret)
p->suspended = true;
}
return ret;
}
static int iTCO_wdt_resume_noirq(struct device *dev)
{
struct iTCO_wdt_private *p = dev_get_drvdata(dev);
if (p->suspended)
iTCO_wdt_start(&p->wddev);
return 0;
}
static int __init iTCO_wdt_init_module(void)
{
pr_info("Intel TCO WatchDog Timer Driver v%s\n", DRV_VERSION);
return platform_driver_register(&iTCO_wdt_driver);
}
static void __exit iTCO_wdt_cleanup_module(void)
{
platform_driver_unregister(&iTCO_wdt_driver);
pr_info("Watchdog Module Unloaded\n");
}
