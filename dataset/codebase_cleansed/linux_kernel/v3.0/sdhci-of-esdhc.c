static u16 esdhc_readw(struct sdhci_host *host, int reg)
{
u16 ret;
if (unlikely(reg == SDHCI_HOST_VERSION))
ret = in_be16(host->ioaddr + reg);
else
ret = sdhci_be32bs_readw(host, reg);
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
struct sdhci_of_host *of_host = sdhci_priv(host);
return of_host->clock;
}
static unsigned int esdhc_of_get_min_clock(struct sdhci_host *host)
{
struct sdhci_of_host *of_host = sdhci_priv(host);
return of_host->clock / 256 / 16;
}
