static inline bool sdhci_acpi_flag(struct sdhci_acpi_host *c, unsigned int flag)
{
return c->slot && (c->slot->flags & flag);
}
static int sdhci_acpi_enable_dma(struct sdhci_host *host)
{
return 0;
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
static const struct sdhci_acpi_slot *sdhci_acpi_get_slot_by_ids(const char *hid,
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
static const struct sdhci_acpi_slot *sdhci_acpi_get_slot(acpi_handle handle,
const char *hid)
{
const struct sdhci_acpi_slot *slot;
struct acpi_device_info *info;
const char *uid = NULL;
acpi_status status;
status = acpi_get_object_info(handle, &info);
if (!ACPI_FAILURE(status) && (info->valid & ACPI_VALID_UID))
uid = info->unique_id.string;
slot = sdhci_acpi_get_slot_by_ids(hid, uid);
kfree(info);
return slot;
}
static irqreturn_t sdhci_acpi_sd_cd(int irq, void *dev_id)
{
mmc_detect_change(dev_id, msecs_to_jiffies(200));
return IRQ_HANDLED;
}
static int sdhci_acpi_add_own_cd(struct device *dev, struct mmc_host *mmc)
{
struct gpio_desc *desc;
unsigned long flags;
int err, irq;
desc = devm_gpiod_get_index(dev, "sd_cd", 0);
if (IS_ERR(desc)) {
err = PTR_ERR(desc);
goto out;
}
err = gpiod_direction_input(desc);
if (err)
goto out_free;
irq = gpiod_to_irq(desc);
if (irq < 0) {
err = irq;
goto out_free;
}
flags = IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING;
err = devm_request_irq(dev, irq, sdhci_acpi_sd_cd, flags, "sd_cd", mmc);
if (err)
goto out_free;
return 0;
out_free:
devm_gpiod_put(dev, desc);
out:
dev_warn(dev, "failed to setup card detect wake up\n");
return err;
}
static int sdhci_acpi_add_own_cd(struct device *dev, struct mmc_host *mmc)
{
return 0;
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
int err;
if (acpi_bus_get_device(handle, &device))
return -ENODEV;
if (acpi_bus_get_status(device) || !device->status.present)
return -ENODEV;
hid = acpi_device_hid(device);
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
c->slot = sdhci_acpi_get_slot(handle, hid);
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
if (!dev->dma_mask) {
u64 dma_mask;
if (sdhci_readl(host, SDHCI_CAPABILITIES) & SDHCI_CAN_64BIT) {
dma_mask = DMA_BIT_MASK(32);
} else {
dma_mask = DMA_BIT_MASK(32);
}
err = dma_coerce_mask_and_coherent(dev, dma_mask);
if (err)
goto err_free;
}
if (c->slot) {
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
err = sdhci_add_host(host);
if (err)
goto err_free;
if (sdhci_acpi_flag(c, SDHCI_ACPI_SD_CD)) {
if (sdhci_acpi_add_own_cd(dev, host->mmc))
c->use_runtime_pm = false;
}
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
