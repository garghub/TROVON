static inline u32 sdhci_iproc_readl(struct sdhci_host *host, int reg)
{
u32 val = readl(host->ioaddr + reg);
pr_debug("%s: readl [0x%02x] 0x%08x\n",
mmc_hostname(host->mmc), reg, val);
return val;
}
static u16 sdhci_iproc_readw(struct sdhci_host *host, int reg)
{
u32 val = sdhci_iproc_readl(host, (reg & ~3));
u16 word = val >> REG_OFFSET_IN_BITS(reg) & 0xffff;
return word;
}
static u8 sdhci_iproc_readb(struct sdhci_host *host, int reg)
{
u32 val = sdhci_iproc_readl(host, (reg & ~3));
u8 byte = val >> REG_OFFSET_IN_BITS(reg) & 0xff;
return byte;
}
static inline void sdhci_iproc_writel(struct sdhci_host *host, u32 val, int reg)
{
pr_debug("%s: writel [0x%02x] 0x%08x\n",
mmc_hostname(host->mmc), reg, val);
writel(val, host->ioaddr + reg);
if (host->clock <= 400000) {
if (host->clock)
udelay((4 * 1000000 + host->clock - 1) / host->clock);
else
udelay(10);
}
}
static void sdhci_iproc_writew(struct sdhci_host *host, u16 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_iproc_host *iproc_host = sdhci_pltfm_priv(pltfm_host);
u32 word_shift = REG_OFFSET_IN_BITS(reg);
u32 mask = 0xffff << word_shift;
u32 oldval, newval;
if (reg == SDHCI_COMMAND) {
if (iproc_host->shadow_blk != 0) {
sdhci_iproc_writel(host, iproc_host->shadow_blk,
SDHCI_BLOCK_SIZE);
iproc_host->shadow_blk = 0;
}
oldval = iproc_host->shadow_cmd;
} else if (reg == SDHCI_BLOCK_SIZE || reg == SDHCI_BLOCK_COUNT) {
oldval = iproc_host->shadow_blk;
} else {
oldval = sdhci_iproc_readl(host, (reg & ~3));
}
newval = (oldval & ~mask) | (val << word_shift);
if (reg == SDHCI_TRANSFER_MODE) {
iproc_host->shadow_cmd = newval;
} else if (reg == SDHCI_BLOCK_SIZE || reg == SDHCI_BLOCK_COUNT) {
iproc_host->shadow_blk = newval;
} else {
sdhci_iproc_writel(host, newval, reg & ~3);
}
}
static void sdhci_iproc_writeb(struct sdhci_host *host, u8 val, int reg)
{
u32 oldval = sdhci_iproc_readl(host, (reg & ~3));
u32 byte_shift = REG_OFFSET_IN_BITS(reg);
u32 mask = 0xff << byte_shift;
u32 newval = (oldval & ~mask) | (val << byte_shift);
sdhci_iproc_writel(host, newval, reg & ~3);
}
static int sdhci_iproc_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct sdhci_iproc_data *iproc_data;
struct sdhci_host *host;
struct sdhci_iproc_host *iproc_host;
struct sdhci_pltfm_host *pltfm_host;
int ret;
match = of_match_device(sdhci_iproc_of_match, &pdev->dev);
if (!match)
return -EINVAL;
iproc_data = match->data;
host = sdhci_pltfm_init(pdev, iproc_data->pdata, sizeof(*iproc_host));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
iproc_host = sdhci_pltfm_priv(pltfm_host);
iproc_host->data = iproc_data;
mmc_of_parse(host->mmc);
sdhci_get_of_property(pdev);
host->mmc->caps |= MMC_CAP_1_8V_DDR;
pltfm_host->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pltfm_host->clk)) {
ret = PTR_ERR(pltfm_host->clk);
goto err;
}
if (iproc_host->data->pdata->quirks & SDHCI_QUIRK_MISSING_CAPS) {
host->caps = iproc_host->data->caps;
host->caps1 = iproc_host->data->caps1;
}
return sdhci_add_host(host);
err:
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_iproc_remove(struct platform_device *pdev)
{
return sdhci_pltfm_unregister(pdev);
}
