static u16 esdhc_readw(struct sdhci_host *host, int reg)
{
u16 ret;
int base = reg & ~0x3;
int shift = (reg & 0x2) * 8;
if (unlikely(reg == SDHCI_HOST_VERSION))
ret = in_be32(host->ioaddr + base) & 0xffff;
else
ret = (in_be32(host->ioaddr + base) >> shift) & 0xffff;
return ret;
}
static u8 esdhc_readb(struct sdhci_host *host, int reg)
{
int base = reg & ~0x3;
int shift = (reg & 0x3) * 8;
u8 ret = (in_be32(host->ioaddr + base) >> shift) & 0xff;
return ret;
}
static void esdhc_writew(struct sdhci_host *host, u16 val, int reg)
{
if (reg == SDHCI_BLOCK_SIZE) {
val &= ~SDHCI_MAKE_BLKSZ(0x7, 0);
}
sdhci_be32bs_writew(host, val, reg);
}
static void esdhc_writeb(struct sdhci_host *host, u8 val, int reg)
{
if (reg == SDHCI_HOST_CONTROL)
val &= ~ESDHC_HOST_CONTROL_RES;
sdhci_be32bs_writeb(host, val, reg);
}
static int esdhc_of_enable_dma(struct sdhci_host *host)
{
setbits32(host->ioaddr + ESDHC_DMA_SYSCTL, ESDHC_DMA_SNOOP);
return 0;
}
static unsigned int esdhc_of_get_max_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return pltfm_host->clock;
}
static unsigned int esdhc_of_get_min_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return pltfm_host->clock / 256 / 16;
}
static int __devinit sdhci_esdhc_probe(struct platform_device *pdev)
{
return sdhci_pltfm_register(pdev, &sdhci_esdhc_pdata);
}
static int __devexit sdhci_esdhc_remove(struct platform_device *pdev)
{
return sdhci_pltfm_unregister(pdev);
}
static int __init sdhci_esdhc_init(void)
{
return platform_driver_register(&sdhci_esdhc_driver);
}
static void __exit sdhci_esdhc_exit(void)
{
platform_driver_unregister(&sdhci_esdhc_driver);
}
