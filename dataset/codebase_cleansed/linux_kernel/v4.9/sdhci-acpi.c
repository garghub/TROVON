static inline bool sdhci_acpi_flag(struct sdhci_acpi_host *c, unsigned int flag)
{
return c->slot && (c->slot->flags & flag);
}
static void sdhci_acpi_int_hw_reset(struct sdhci_host *host)
{
u8 reg;
reg = sdhci_readb(host, SDHCI_POWER_CONTROL);
reg |= 0x10;
sdhci_writeb(host, reg, SDHCI_POWER_CONTROL);
udelay(9);
reg &= ~0x10;
sdhci_writeb(host, reg, SDHCI_POWER_CONTROL);
usleep_range(300, 1000);
}
static bool sdhci_acpi_byt(void)
{
static const struct x86_cpu_id byt[] = {
{ X86_VENDOR_INTEL, 6, INTEL_FAM6_ATOM_SILVERMONT1 },
{}
};
return x86_match_cpu(byt);
}
static void sdhci_acpi_byt_setting(struct device *dev)
{
u32 val = 0;
if (!sdhci_acpi_byt())
return;
if (iosf_mbi_read(BYT_IOSF_SCCEP, MBI_CR_READ, BYT_IOSF_OCP_NETCTRL0,
&val)) {
dev_err(dev, "%s read error\n", __func__);
return;
}
if (!(val & BYT_IOSF_OCP_TIMEOUT_BASE))
return;
val &= ~BYT_IOSF_OCP_TIMEOUT_BASE;
if (iosf_mbi_write(BYT_IOSF_SCCEP, MBI_CR_WRITE, BYT_IOSF_OCP_NETCTRL0,
val)) {
dev_err(dev, "%s write error\n", __func__);
return;
}
dev_dbg(dev, "%s completed\n", __func__);
}
static bool sdhci_acpi_byt_defer(struct device *dev)
{
if (!sdhci_acpi_byt())
return false;
if (!iosf_mbi_available())
return true;
sdhci_acpi_byt_setting(dev);
return false;
}
static inline void sdhci_acpi_byt_setting(struct device *dev)
{
}
static inline bool sdhci_acpi_byt_defer(struct device *dev)
{
return false;
}
static int bxt_get_cd(struct mmc_host *mmc)
{
int gpio_cd = mmc_gpio_get_cd(mmc);
struct sdhci_host *host = mmc_priv(mmc);
unsigned long flags;
int ret = 0;
if (!gpio_cd)
return 0;
spin_lock_irqsave(&host->lock, flags);
if (host->flags & SDHCI_DEVICE_DEAD)
goto out;
ret = !!(sdhci_readl(host, SDHCI_PRESENT_STATE) & SDHCI_CARD_PRESENT);
out:
spin_unlock_irqrestore(&host->lock, flags);
return ret;
}
static int sdhci_acpi_emmc_probe_slot(struct platform_device *pdev,
const char *hid, const char *uid)
{
struct sdhci_acpi_host *c = platform_get_drvdata(pdev);
struct sdhci_host *host;
if (!c || !c->host)
return 0;
host = c->host;
if (hid && uid && !strcmp(hid, "80860F14") && !strcmp(uid, "1") &&
sdhci_readl(host, SDHCI_CAPABILITIES) == 0x446cc8b2 &&
sdhci_readl(host, SDHCI_CAPABILITIES_1) == 0x00000807)
host->timeout_clk = 1000;
return 0;
}
static int sdhci_acpi_sdio_probe_slot(struct platform_device *pdev,
const char *hid, const char *uid)
{
struct sdhci_acpi_host *c = platform_get_drvdata(pdev);
struct sdhci_host *host;
if (!c || !c->host)
return 0;
host = c->host;
return 0;
}
static int sdhci_acpi_sd_probe_slot(struct platform_device *pdev,
const char *hid, const char *uid)
{
struct sdhci_acpi_host *c = platform_get_drvdata(pdev);
struct sdhci_host *host;
if (!c || !c->host || !c->slot)
return 0;
host = c->host;
if (hid && !strcmp(hid, "80865ACA")) {
host->mmc_host_ops.get_cd = bxt_get_cd;
host->mmc->caps |= MMC_CAP_AGGRESSIVE_PM;
}
return 0;
}
static const struct sdhci_acpi_slot *sdhci_acpi_get_slot(const char *hid,
const char *uid)
{
const struct sdhci_acpi_uid_slot *u;
for (u = sdhci_acpi_uids; u->hid; u++) {
if (strcmp(u->hid, hid))
continue;
if (!u->uid)
return u->slot;
if (uid && !strcmp(u->uid, uid))
return u->slot;
}
return NULL;
}
static int sdhci_acpi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
acpi_handle handle = ACPI_HANDLE(dev);
struct acpi_device *device, *child;
struct sdhci_acpi_host *c;
struct sdhci_host *host;
struct resource *iomem;
resource_size_t len;
const char *hid;
const char *uid;
int err;
if (acpi_bus_get_device(handle, &device))
return -ENODEV;
acpi_device_fix_up_power(device);
list_for_each_entry(child, &device->children, node)
acpi_device_fix_up_power(child);
if (acpi_bus_get_status(device) || !device->status.present)
return -ENODEV;
if (sdhci_acpi_byt_defer(dev))
return -EPROBE_DEFER;
hid = acpi_device_hid(device);
uid = device->pnp.unique_id;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem)
return -ENOMEM;
len = resource_size(iomem);
if (len < 0x100)
dev_err(dev, "Invalid iomem size!\n");
if (!devm_request_mem_region(dev, iomem->start, len, dev_name(dev)))
return -ENOMEM;
host = sdhci_alloc_host(dev, sizeof(struct sdhci_acpi_host));
if (IS_ERR(host))
return PTR_ERR(host);
c = sdhci_priv(host);
c->host = host;
c->slot = sdhci_acpi_get_slot(hid, uid);
c->pdev = pdev;
c->use_runtime_pm = sdhci_acpi_flag(c, SDHCI_ACPI_RUNTIME_PM);
platform_set_drvdata(pdev, c);
host->hw_name = "ACPI";
host->ops = &sdhci_acpi_ops_dflt;
host->irq = platform_get_irq(pdev, 0);
host->ioaddr = devm_ioremap_nocache(dev, iomem->start,
resource_size(iomem));
if (host->ioaddr == NULL) {
err = -ENOMEM;
goto err_free;
}
if (c->slot) {
if (c->slot->probe_slot) {
err = c->slot->probe_slot(pdev, hid, uid);
if (err)
goto err_free;
}
if (c->slot->chip) {
host->ops = c->slot->chip->ops;
host->quirks |= c->slot->chip->quirks;
host->quirks2 |= c->slot->chip->quirks2;
host->mmc->caps |= c->slot->chip->caps;
host->mmc->caps2 |= c->slot->chip->caps2;
host->mmc->pm_caps |= c->slot->chip->pm_caps;
}
host->quirks |= c->slot->quirks;
host->quirks2 |= c->slot->quirks2;
host->mmc->caps |= c->slot->caps;
host->mmc->caps2 |= c->slot->caps2;
host->mmc->pm_caps |= c->slot->pm_caps;
}
host->mmc->caps2 |= MMC_CAP2_NO_PRESCAN_POWERUP;
if (sdhci_acpi_flag(c, SDHCI_ACPI_SD_CD)) {
bool v = sdhci_acpi_flag(c, SDHCI_ACPI_SD_CD_OVERRIDE_LEVEL);
if (mmc_gpiod_request_cd(host->mmc, NULL, 0, v, 0, NULL)) {
dev_warn(dev, "failed to setup card detect gpio\n");
c->use_runtime_pm = false;
}
}
err = sdhci_add_host(host);
if (err)
goto err_free;
if (c->use_runtime_pm) {
pm_runtime_set_active(dev);
pm_suspend_ignore_children(dev, 1);
pm_runtime_set_autosuspend_delay(dev, 50);
pm_runtime_use_autosuspend(dev);
pm_runtime_enable(dev);
}
device_enable_async_suspend(dev);
return 0;
err_free:
sdhci_free_host(c->host);
return err;
}
static int sdhci_acpi_remove(struct platform_device *pdev)
{
struct sdhci_acpi_host *c = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
int dead;
if (c->use_runtime_pm) {
pm_runtime_get_sync(dev);
pm_runtime_disable(dev);
pm_runtime_put_noidle(dev);
}
if (c->slot && c->slot->remove_slot)
c->slot->remove_slot(pdev);
dead = (sdhci_readl(c->host, SDHCI_INT_STATUS) == ~0);
sdhci_remove_host(c->host, dead);
sdhci_free_host(c->host);
return 0;
}
static int sdhci_acpi_suspend(struct device *dev)
{
struct sdhci_acpi_host *c = dev_get_drvdata(dev);
return sdhci_suspend_host(c->host);
}
static int sdhci_acpi_resume(struct device *dev)
{
struct sdhci_acpi_host *c = dev_get_drvdata(dev);
sdhci_acpi_byt_setting(&c->pdev->dev);
return sdhci_resume_host(c->host);
}
static int sdhci_acpi_runtime_suspend(struct device *dev)
{
struct sdhci_acpi_host *c = dev_get_drvdata(dev);
return sdhci_runtime_suspend_host(c->host);
}
static int sdhci_acpi_runtime_resume(struct device *dev)
{
struct sdhci_acpi_host *c = dev_get_drvdata(dev);
sdhci_acpi_byt_setting(&c->pdev->dev);
return sdhci_runtime_resume_host(c->host);
}
