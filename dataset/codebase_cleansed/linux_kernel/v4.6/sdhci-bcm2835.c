static void bcm2835_sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
writel(val, host->ioaddr + reg);
udelay(BCM2835_SDHCI_WRITE_DELAY);
}
static inline u32 bcm2835_sdhci_readl(struct sdhci_host *host, int reg)
{
u32 val = readl(host->ioaddr + reg);
if (reg == SDHCI_CAPABILITIES)
val |= SDHCI_CAN_VDD_330;
return val;
}
static void bcm2835_sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct bcm2835_sdhci *bcm2835_host = sdhci_pltfm_priv(pltfm_host);
u32 oldval = (reg == SDHCI_COMMAND) ? bcm2835_host->shadow :
bcm2835_sdhci_readl(host, reg & ~3);
u32 word_num = (reg >> 1) & 1;
u32 word_shift = word_num * 16;
u32 mask = 0xffff << word_shift;
u32 newval = (oldval & ~mask) | (val << word_shift);
if (reg == SDHCI_TRANSFER_MODE)
bcm2835_host->shadow = newval;
else
bcm2835_sdhci_writel(host, newval, reg & ~3);
}
static u16 bcm2835_sdhci_readw(struct sdhci_host *host, int reg)
{
u32 val = bcm2835_sdhci_readl(host, (reg & ~3));
u32 word_num = (reg >> 1) & 1;
u32 word_shift = word_num * 16;
u32 word = (val >> word_shift) & 0xffff;
return word;
}
static void bcm2835_sdhci_writeb(struct sdhci_host *host, u8 val, int reg)
{
u32 oldval = bcm2835_sdhci_readl(host, reg & ~3);
u32 byte_num = reg & 3;
u32 byte_shift = byte_num * 8;
u32 mask = 0xff << byte_shift;
u32 newval = (oldval & ~mask) | (val << byte_shift);
bcm2835_sdhci_writel(host, newval, reg & ~3);
}
static u8 bcm2835_sdhci_readb(struct sdhci_host *host, int reg)
{
u32 val = bcm2835_sdhci_readl(host, (reg & ~3));
u32 byte_num = reg & 3;
u32 byte_shift = byte_num * 8;
u32 byte = (val >> byte_shift) & 0xff;
return byte;
}
static unsigned int bcm2835_sdhci_get_min_clock(struct sdhci_host *host)
{
return MIN_FREQ;
}
static int bcm2835_sdhci_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct bcm2835_sdhci *bcm2835_host;
struct sdhci_pltfm_host *pltfm_host;
int ret;
host = sdhci_pltfm_init(pdev, &bcm2835_sdhci_pdata,
sizeof(*bcm2835_host));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
pltfm_host->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pltfm_host->clk)) {
ret = PTR_ERR(pltfm_host->clk);
goto err;
}
ret = clk_prepare_enable(pltfm_host->clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable host clk\n");
goto err;
}
ret = sdhci_add_host(host);
if (ret)
goto err_clk;
return 0;
err_clk:
clk_disable_unprepare(pltfm_host->clk);
err:
sdhci_pltfm_free(pdev);
return ret;
}
