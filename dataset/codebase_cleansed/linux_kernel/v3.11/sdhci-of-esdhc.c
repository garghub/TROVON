static u32 esdhc_readl(struct sdhci_host *host, int reg)
{
u32 ret;
ret = in_be32(host->ioaddr + reg);
if ((reg == SDHCI_CAPABILITIES) && (ret & SDHCI_CAN_DO_ADMA1)) {
u32 tmp = in_be32(host->ioaddr + SDHCI_SLOT_INT_STATUS);
tmp = (tmp & SDHCI_VENDOR_VER_MASK) >> SDHCI_VENDOR_VER_SHIFT;
if (tmp > VENDOR_V_22)
ret |= SDHCI_CAN_DO_ADMA2;
}
return ret;
}
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
static void esdhc_writel(struct sdhci_host *host, u32 val, int reg)
{
if (reg == SDHCI_INT_ENABLE)
val |= SDHCI_INT_BLK_GAP;
sdhci_be32bs_writel(host, val, reg);
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
if (host->quirks2 & SDHCI_QUIRK2_BROKEN_HOST_CONTROL)
return;
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
static void esdhci_of_adma_workaround(struct sdhci_host *host, u32 intmask)
{
u32 tmp;
bool applicable;
dma_addr_t dmastart;
dma_addr_t dmanow;
tmp = in_be32(host->ioaddr + SDHCI_SLOT_INT_STATUS);
tmp = (tmp & SDHCI_VENDOR_VER_MASK) >> SDHCI_VENDOR_VER_SHIFT;
applicable = (intmask & SDHCI_INT_DATA_END) &&
(intmask & SDHCI_INT_BLK_GAP) &&
(tmp == VENDOR_V_23);
if (!applicable)
return;
host->data->error = 0;
dmastart = sg_dma_address(host->data->sg);
dmanow = dmastart + host->data->bytes_xfered;
dmanow = (dmanow & ~(SDHCI_DEFAULT_BOUNDARY_SIZE - 1)) +
SDHCI_DEFAULT_BOUNDARY_SIZE;
host->data->bytes_xfered = dmanow - dmastart;
sdhci_writel(host, dmanow, SDHCI_DMA_ADDRESS);
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
esdhc_set_clock(host, clock, host->max_clk);
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
static void esdhc_of_platform_init(struct sdhci_host *host)
{
u32 vvn;
vvn = in_be32(host->ioaddr + SDHCI_SLOT_INT_STATUS);
vvn = (vvn & SDHCI_VENDOR_VER_MASK) >> SDHCI_VENDOR_VER_SHIFT;
if (vvn == VENDOR_V_22)
host->quirks2 |= SDHCI_QUIRK2_HOST_NO_CMD23;
if (vvn > VENDOR_V_22)
host->quirks &= ~SDHCI_QUIRK_NO_BUSY_IRQ;
}
static int esdhc_pltfm_bus_width(struct sdhci_host *host, int width)
{
u32 ctrl;
switch (width) {
case MMC_BUS_WIDTH_8:
ctrl = ESDHC_CTRL_8BITBUS;
break;
case MMC_BUS_WIDTH_4:
ctrl = ESDHC_CTRL_4BITBUS;
break;
default:
ctrl = 0;
break;
}
clrsetbits_be32(host->ioaddr + SDHCI_HOST_CONTROL,
ESDHC_CTRL_BUSWIDTH_MASK, ctrl);
return 0;
}
static int sdhci_esdhc_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct device_node *np;
int ret;
host = sdhci_pltfm_init(pdev, &sdhci_esdhc_pdata, 0);
if (IS_ERR(host))
return PTR_ERR(host);
sdhci_get_of_property(pdev);
np = pdev->dev.of_node;
if (of_device_is_compatible(np, "fsl,p2020-esdhc")) {
host->quirks2 |= SDHCI_QUIRK2_BROKEN_HOST_CONTROL;
}
mmc_of_parse(host->mmc);
ret = sdhci_add_host(host);
if (ret)
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_esdhc_remove(struct platform_device *pdev)
{
return sdhci_pltfm_unregister(pdev);
}
