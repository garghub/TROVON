static inline bool sdhci_acpi_flag(struct sdhci_acpi_host *c, unsigned int flag)
{
return c->slot && (c->slot->flags & flag);
}
static int sdhci_acpi_enable_dma(struct sdhci_host *host)
{
struct sdhci_acpi_host *c = sdhci_priv(host);
struct device *dev = &c->pdev->dev;
int err = -1;
if (c->dma_setup)
return 0;
if (host->flags & SDHCI_USE_64_BIT_DMA) {
if (host->quirks2 & SDHCI_QUIRK2_BROKEN_64_BIT_DMA) {
host->flags &= ~SDHCI_USE_64_BIT_DMA;
} else {
err = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(64));
if (err)
dev_warn(dev, "Failed to set 64-bit DMA mask\n");
}
}
if (err)
err = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
c->dma_setup = !err;
return err;
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
struct acpi_device *device;
struct sdhci_acpi_host *c;
struct sdhci_host *host;
struct resource *iomem;
resource_size_t len;
const char *hid;
const char *uid;
int err;
if (acpi_bus_get_device(handle, &device))
return -ENODEV;
if (acpi_bus_get_status(device) || !device->status.present)
return -ENODEV;
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
return sdhci_runtime_resume_host(c->host);
}
static int sdhci_acpi_runtime_idle(struct device *dev)
{
return 0;
}
