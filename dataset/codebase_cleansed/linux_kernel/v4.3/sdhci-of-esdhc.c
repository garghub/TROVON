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
int pre_div = 1;
int div = 1;
u32 temp;
host->mmc->actual_clock = 0;
if (clock == 0)
return;
temp = esdhc_readw(host, SDHCI_HOST_VERSION);
temp = (temp & SDHCI_VENDOR_VER_MASK) >> SDHCI_VENDOR_VER_SHIFT;
if (temp < VENDOR_V_23)
pre_div = 2;
if (of_find_compatible_node(NULL, NULL, "fsl,p1010-esdhc")) {
if (clock > 20000000)
clock -= 5000000;
if (clock > 40000000)
clock -= 5000000;
}
temp = sdhci_readl(host, ESDHC_SYSTEM_CONTROL);
temp &= ~(ESDHC_CLOCK_IPGEN | ESDHC_CLOCK_HCKEN | ESDHC_CLOCK_PEREN
| ESDHC_CLOCK_MASK);
sdhci_writel(host, temp, ESDHC_SYSTEM_CONTROL);
while (host->max_clk / pre_div / 16 > clock && pre_div < 256)
pre_div *= 2;
while (host->max_clk / pre_div / div > clock && div < 16)
div++;
dev_dbg(mmc_dev(host->mmc), "desired SD clock: %d, actual: %d\n",
clock, host->max_clk / pre_div / div);
host->mmc->actual_clock = host->max_clk / pre_div / div;
pre_div >>= 1;
div--;
temp = sdhci_readl(host, ESDHC_SYSTEM_CONTROL);
temp |= (ESDHC_CLOCK_IPGEN | ESDHC_CLOCK_HCKEN | ESDHC_CLOCK_PEREN
| (div << ESDHC_DIVIDER_SHIFT)
| (pre_div << ESDHC_PREDIV_SHIFT));
sdhci_writel(host, temp, ESDHC_SYSTEM_CONTROL);
mdelay(1);
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
static void esdhc_pltfm_set_bus_width(struct sdhci_host *host, int width)
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
}
static void esdhc_reset(struct sdhci_host *host, u8 mask)
{
sdhci_reset(host, mask);
sdhci_writel(host, host->ier, SDHCI_INT_ENABLE);
sdhci_writel(host, host->ier, SDHCI_SIGNAL_ENABLE);
}
static int esdhc_of_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
esdhc_proctl = sdhci_be32bs_readl(host, SDHCI_HOST_CONTROL);
return sdhci_suspend_host(host);
}
static int esdhc_of_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
int ret = sdhci_resume_host(host);
if (ret == 0) {
esdhc_of_enable_dma(host);
sdhci_be32bs_writel(host, esdhc_proctl, SDHCI_HOST_CONTROL);
}
return ret;
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
if (of_device_is_compatible(np, "fsl,p5040-esdhc") ||
of_device_is_compatible(np, "fsl,p5020-esdhc") ||
of_device_is_compatible(np, "fsl,p4080-esdhc") ||
of_device_is_compatible(np, "fsl,p1020-esdhc") ||
of_device_is_compatible(np, "fsl,t1040-esdhc"))
host->quirks &= ~SDHCI_QUIRK_BROKEN_CARD_DETECTION;
if (of_device_is_compatible(np, "fsl,p2020-esdhc")) {
host->quirks2 |= SDHCI_QUIRK2_BROKEN_HOST_CONTROL;
}
ret = mmc_of_parse(host->mmc);
if (ret)
goto err;
mmc_of_parse_voltage(np, &host->ocr_mask);
ret = sdhci_add_host(host);
if (ret)
goto err;
return 0;
err:
sdhci_pltfm_free(pdev);
return ret;
}
