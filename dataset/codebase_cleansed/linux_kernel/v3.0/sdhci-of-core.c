u32 sdhci_be32bs_readl(struct sdhci_host *host, int reg)
{
return in_be32(host->ioaddr + reg);
}
u16 sdhci_be32bs_readw(struct sdhci_host *host, int reg)
{
return in_be16(host->ioaddr + (reg ^ 0x2));
}
u8 sdhci_be32bs_readb(struct sdhci_host *host, int reg)
{
return in_8(host->ioaddr + (reg ^ 0x3));
}
void sdhci_be32bs_writel(struct sdhci_host *host, u32 val, int reg)
{
out_be32(host->ioaddr + reg, val);
}
void sdhci_be32bs_writew(struct sdhci_host *host, u16 val, int reg)
{
struct sdhci_of_host *of_host = sdhci_priv(host);
int base = reg & ~0x3;
int shift = (reg & 0x2) * 8;
switch (reg) {
case SDHCI_TRANSFER_MODE:
of_host->xfer_mode_shadow = val;
return;
case SDHCI_COMMAND:
sdhci_be32bs_writel(host, val << 16 | of_host->xfer_mode_shadow,
SDHCI_TRANSFER_MODE);
return;
}
clrsetbits_be32(host->ioaddr + base, 0xffff << shift, val << shift);
}
void sdhci_be32bs_writeb(struct sdhci_host *host, u8 val, int reg)
{
int base = reg & ~0x3;
int shift = (reg & 0x3) * 8;
clrsetbits_be32(host->ioaddr + base , 0xff << shift, val << shift);
}
static int sdhci_of_suspend(struct platform_device *ofdev, pm_message_t state)
{
struct sdhci_host *host = dev_get_drvdata(&ofdev->dev);
return mmc_suspend_host(host->mmc);
}
static int sdhci_of_resume(struct platform_device *ofdev)
{
struct sdhci_host *host = dev_get_drvdata(&ofdev->dev);
return mmc_resume_host(host->mmc);
}
static bool __devinit sdhci_of_wp_inverted(struct device_node *np)
{
if (of_get_property(np, "sdhci,wp-inverted", NULL))
return true;
#ifdef CONFIG_PPC
return machine_is(mpc837x_rdb) || machine_is(mpc837x_mds);
#else
return false;
#endif
}
static int __devinit sdhci_of_probe(struct platform_device *ofdev)
{
const struct of_device_id *match;
struct device_node *np = ofdev->dev.of_node;
struct sdhci_of_data *sdhci_of_data;
struct sdhci_host *host;
struct sdhci_of_host *of_host;
const __be32 *clk;
int size;
int ret;
match = of_match_device(sdhci_of_match, &ofdev->dev);
if (!match)
return -EINVAL;
sdhci_of_data = match->data;
if (!of_device_is_available(np))
return -ENODEV;
host = sdhci_alloc_host(&ofdev->dev, sizeof(*of_host));
if (IS_ERR(host))
return -ENOMEM;
of_host = sdhci_priv(host);
dev_set_drvdata(&ofdev->dev, host);
host->ioaddr = of_iomap(np, 0);
if (!host->ioaddr) {
ret = -ENOMEM;
goto err_addr_map;
}
host->irq = irq_of_parse_and_map(np, 0);
if (!host->irq) {
ret = -EINVAL;
goto err_no_irq;
}
host->hw_name = dev_name(&ofdev->dev);
if (sdhci_of_data) {
host->quirks = sdhci_of_data->quirks;
host->ops = &sdhci_of_data->ops;
}
if (of_get_property(np, "sdhci,auto-cmd12", NULL))
host->quirks |= SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12;
if (of_get_property(np, "sdhci,1-bit-only", NULL))
host->quirks |= SDHCI_QUIRK_FORCE_1_BIT_DATA;
if (sdhci_of_wp_inverted(np))
host->quirks |= SDHCI_QUIRK_INVERTED_WRITE_PROTECT;
clk = of_get_property(np, "clock-frequency", &size);
if (clk && size == sizeof(*clk) && *clk)
of_host->clock = be32_to_cpup(clk);
ret = sdhci_add_host(host);
if (ret)
goto err_add_host;
return 0;
err_add_host:
irq_dispose_mapping(host->irq);
err_no_irq:
iounmap(host->ioaddr);
err_addr_map:
sdhci_free_host(host);
return ret;
}
static int __devexit sdhci_of_remove(struct platform_device *ofdev)
{
struct sdhci_host *host = dev_get_drvdata(&ofdev->dev);
sdhci_remove_host(host, 0);
sdhci_free_host(host);
irq_dispose_mapping(host->irq);
iounmap(host->ioaddr);
return 0;
}
static int __init sdhci_of_init(void)
{
return platform_driver_register(&sdhci_of_driver);
}
static void __exit sdhci_of_exit(void)
{
platform_driver_unregister(&sdhci_of_driver);
}
