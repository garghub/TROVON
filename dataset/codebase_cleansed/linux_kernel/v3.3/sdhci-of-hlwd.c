static void sdhci_hlwd_writel(struct sdhci_host *host, u32 val, int reg)
{
sdhci_be32bs_writel(host, val, reg);
udelay(SDHCI_HLWD_WRITE_DELAY);
}
static void sdhci_hlwd_writew(struct sdhci_host *host, u16 val, int reg)
{
sdhci_be32bs_writew(host, val, reg);
udelay(SDHCI_HLWD_WRITE_DELAY);
}
static void sdhci_hlwd_writeb(struct sdhci_host *host, u8 val, int reg)
{
sdhci_be32bs_writeb(host, val, reg);
udelay(SDHCI_HLWD_WRITE_DELAY);
}
static int __devinit sdhci_hlwd_probe(struct platform_device *pdev)
{
return sdhci_pltfm_register(pdev, &sdhci_hlwd_pdata);
}
static int __devexit sdhci_hlwd_remove(struct platform_device *pdev)
{
return sdhci_pltfm_unregister(pdev);
}
