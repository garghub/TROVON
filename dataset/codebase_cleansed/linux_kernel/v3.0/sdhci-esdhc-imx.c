static inline void esdhc_clrset_le(struct sdhci_host *host, u32 mask, u32 val, int reg)
{
void __iomem *base = host->ioaddr + (reg & ~0x3);
u32 shift = (reg & 0x3) * 8;
writel(((readl(base) & ~(mask << shift)) | (val << shift)), base);
}
static u32 esdhc_readl_le(struct sdhci_host *host, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
u32 val = readl(host->ioaddr + reg);
if (unlikely((reg == SDHCI_PRESENT_STATE)
&& (imx_data->flags & ESDHC_FLAG_GPIO_FOR_CD_WP))) {
struct esdhc_platform_data *boarddata =
host->mmc->parent->platform_data;
if (boarddata && gpio_is_valid(boarddata->cd_gpio)
&& gpio_get_value(boarddata->cd_gpio))
val &= SDHCI_CARD_PRESENT;
else
val |= SDHCI_CARD_PRESENT;
}
return val;
}
static void esdhc_writel_le(struct sdhci_host *host, u32 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
if (unlikely((reg == SDHCI_INT_ENABLE || reg == SDHCI_SIGNAL_ENABLE)
&& (imx_data->flags & ESDHC_FLAG_GPIO_FOR_CD_WP)))
val &= ~(SDHCI_INT_CARD_REMOVE | SDHCI_INT_CARD_INSERT);
if (unlikely((imx_data->flags & ESDHC_FLAG_MULTIBLK_NO_INT)
&& (reg == SDHCI_INT_STATUS)
&& (val & SDHCI_INT_DATA_END))) {
u32 v;
v = readl(host->ioaddr + SDHCI_VENDOR_SPEC);
v &= ~SDHCI_VENDOR_SPEC_SDIO_QUIRK;
writel(v, host->ioaddr + SDHCI_VENDOR_SPEC);
}
writel(val, host->ioaddr + reg);
}
static u16 esdhc_readw_le(struct sdhci_host *host, int reg)
{
if (unlikely(reg == SDHCI_HOST_VERSION))
reg ^= 2;
return readw(host->ioaddr + reg);
}
static void esdhc_writew_le(struct sdhci_host *host, u16 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
switch (reg) {
case SDHCI_TRANSFER_MODE:
if ((imx_data->flags & ESDHC_FLAG_MULTIBLK_NO_INT)
&& (host->cmd->opcode == SD_IO_RW_EXTENDED)
&& (host->cmd->data->blocks > 1)
&& (host->cmd->data->flags & MMC_DATA_READ)) {
u32 v;
v = readl(host->ioaddr + SDHCI_VENDOR_SPEC);
v |= SDHCI_VENDOR_SPEC_SDIO_QUIRK;
writel(v, host->ioaddr + SDHCI_VENDOR_SPEC);
}
imx_data->scratchpad = val;
return;
case SDHCI_COMMAND:
if ((host->cmd->opcode == MMC_STOP_TRANSMISSION)
&& (imx_data->flags & ESDHC_FLAG_MULTIBLK_NO_INT))
val |= SDHCI_CMD_ABORTCMD;
writel(val << 16 | imx_data->scratchpad,
host->ioaddr + SDHCI_TRANSFER_MODE);
return;
case SDHCI_BLOCK_SIZE:
val &= ~SDHCI_MAKE_BLKSZ(0x7, 0);
break;
}
esdhc_clrset_le(host, 0xffff, val, reg);
}
static void esdhc_writeb_le(struct sdhci_host *host, u8 val, int reg)
{
u32 new_val;
switch (reg) {
case SDHCI_POWER_CONTROL:
return;
case SDHCI_HOST_CONTROL:
new_val = val & (SDHCI_CTRL_LED | SDHCI_CTRL_4BITBUS);
new_val |= ESDHC_HOST_CONTROL_LE;
new_val |= (val & SDHCI_CTRL_DMA_MASK) << 5;
esdhc_clrset_le(host, 0xffff, new_val, reg);
return;
}
esdhc_clrset_le(host, 0xff, val, reg);
}
static unsigned int esdhc_pltfm_get_max_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return clk_get_rate(pltfm_host->clk);
}
static unsigned int esdhc_pltfm_get_min_clock(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
return clk_get_rate(pltfm_host->clk) / 256 / 16;
}
static unsigned int esdhc_pltfm_get_ro(struct sdhci_host *host)
{
struct esdhc_platform_data *boarddata = host->mmc->parent->platform_data;
if (boarddata && gpio_is_valid(boarddata->wp_gpio))
return gpio_get_value(boarddata->wp_gpio);
else
return -ENOSYS;
}
static irqreturn_t cd_irq(int irq, void *data)
{
struct sdhci_host *sdhost = (struct sdhci_host *)data;
tasklet_schedule(&sdhost->card_tasklet);
return IRQ_HANDLED;
}
static int esdhc_pltfm_init(struct sdhci_host *host, struct sdhci_pltfm_data *pdata)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct esdhc_platform_data *boarddata = host->mmc->parent->platform_data;
struct clk *clk;
int err;
struct pltfm_imx_data *imx_data;
clk = clk_get(mmc_dev(host->mmc), NULL);
if (IS_ERR(clk)) {
dev_err(mmc_dev(host->mmc), "clk err\n");
return PTR_ERR(clk);
}
clk_enable(clk);
pltfm_host->clk = clk;
imx_data = kzalloc(sizeof(struct pltfm_imx_data), GFP_KERNEL);
if (!imx_data) {
clk_disable(pltfm_host->clk);
clk_put(pltfm_host->clk);
return -ENOMEM;
}
pltfm_host->priv = imx_data;
if (!cpu_is_mx25())
host->quirks |= SDHCI_QUIRK_BROKEN_TIMEOUT_VAL;
if (cpu_is_mx25() || cpu_is_mx35()) {
host->quirks |= SDHCI_QUIRK_NO_MULTIBLOCK;
sdhci_esdhc_ops.get_ro = esdhc_pltfm_get_ro;
}
if (!(cpu_is_mx25() || cpu_is_mx35() || cpu_is_mx51()))
imx_data->flags |= ESDHC_FLAG_MULTIBLK_NO_INT;
if (boarddata) {
err = gpio_request_one(boarddata->wp_gpio, GPIOF_IN, "ESDHC_WP");
if (err) {
dev_warn(mmc_dev(host->mmc),
"no write-protect pin available!\n");
boarddata->wp_gpio = err;
}
err = gpio_request_one(boarddata->cd_gpio, GPIOF_IN, "ESDHC_CD");
if (err) {
dev_warn(mmc_dev(host->mmc),
"no card-detect pin available!\n");
goto no_card_detect_pin;
}
if (!cpu_is_mx25() && !cpu_is_mx35())
goto not_supported;
err = request_irq(gpio_to_irq(boarddata->cd_gpio), cd_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
mmc_hostname(host->mmc), host);
if (err) {
dev_warn(mmc_dev(host->mmc), "request irq error\n");
goto no_card_detect_irq;
}
imx_data->flags |= ESDHC_FLAG_GPIO_FOR_CD_WP;
host->quirks &= ~SDHCI_QUIRK_BROKEN_CARD_DETECTION;
}
return 0;
no_card_detect_irq:
gpio_free(boarddata->cd_gpio);
no_card_detect_pin:
boarddata->cd_gpio = err;
not_supported:
kfree(imx_data);
return 0;
}
static void esdhc_pltfm_exit(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct esdhc_platform_data *boarddata = host->mmc->parent->platform_data;
struct pltfm_imx_data *imx_data = pltfm_host->priv;
if (boarddata && gpio_is_valid(boarddata->wp_gpio))
gpio_free(boarddata->wp_gpio);
if (boarddata && gpio_is_valid(boarddata->cd_gpio)) {
gpio_free(boarddata->cd_gpio);
if (!(host->quirks & SDHCI_QUIRK_BROKEN_CARD_DETECTION))
free_irq(gpio_to_irq(boarddata->cd_gpio), host);
}
clk_disable(pltfm_host->clk);
clk_put(pltfm_host->clk);
kfree(imx_data);
}
