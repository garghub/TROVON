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
if (reg == SDHCI_HOST_CONTROL) {
u32 dma_bits;
dma_bits = in_be32(host->ioaddr + reg);
dma_bits = (dma_bits >> 5) & SDHCI_CTRL_DMA_MASK;
ret &= ~SDHCI_CTRL_DMA_MASK;
ret |= dma_bits;
}
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
if (reg == SDHCI_HOST_CONTROL) {
u32 dma_bits;
dma_bits = (val & SDHCI_CTRL_DMA_MASK) << 5;
clrsetbits_be32(host->ioaddr + reg , SDHCI_CTRL_DMA_MASK << 5,
dma_bits);
val &= ~SDHCI_CTRL_DMA_MASK;
val |= in_be32(host->ioaddr + reg) & SDHCI_CTRL_DMA_MASK;
}
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
static void esdhc_of_set_clock(struct sdhci_host *host, unsigned int clock)
{
if (of_find_compatible_node(NULL, NULL, "fsl,p1010-esdhc")) {
if (clock > 20000000)
clock -= 5000000;
if (clock > 40000000)
clock -= 5000000;
}
esdhc_set_clock(host, clock);
}
static void esdhc_of_suspend(struct sdhci_host *host)
{
esdhc_proctl = sdhci_be32bs_readl(host, SDHCI_HOST_CONTROL);
}
static void esdhc_of_resume(struct sdhci_host *host)
{
esdhc_of_enable_dma(host);
sdhci_be32bs_writel(host, esdhc_proctl, SDHCI_HOST_CONTROL);
}
static int __devinit sdhci_esdhc_probe(struct platform_device *pdev)
{
return sdhci_pltfm_register(pdev, &sdhci_esdhc_pdata);
}
static int __devexit sdhci_esdhc_remove(struct platform_device *pdev)
{
return sdhci_pltfm_unregister(pdev);
}
