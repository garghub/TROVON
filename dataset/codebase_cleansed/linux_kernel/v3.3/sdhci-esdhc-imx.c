static inline int is_imx25_esdhc(struct pltfm_imx_data *data)
{
return data->devtype == IMX25_ESDHC;
}
static inline int is_imx35_esdhc(struct pltfm_imx_data *data)
{
return data->devtype == IMX35_ESDHC;
}
static inline int is_imx51_esdhc(struct pltfm_imx_data *data)
{
return data->devtype == IMX51_ESDHC;
}
static inline int is_imx53_esdhc(struct pltfm_imx_data *data)
{
return data->devtype == IMX53_ESDHC;
}
static inline int is_imx6q_usdhc(struct pltfm_imx_data *data)
{
return data->devtype == IMX6Q_USDHC;
}
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
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
u32 val = readl(host->ioaddr + reg);
if (unlikely((reg == SDHCI_PRESENT_STATE)
&& gpio_is_valid(boarddata->cd_gpio))) {
if (gpio_get_value(boarddata->cd_gpio))
val &= ~SDHCI_CARD_PRESENT;
else
val |= SDHCI_CARD_PRESENT;
}
if (unlikely(reg == SDHCI_CAPABILITIES)) {
if (val & SDHCI_CAN_DO_ADMA1) {
val &= ~SDHCI_CAN_DO_ADMA1;
val |= SDHCI_CAN_DO_ADMA2;
}
}
if (unlikely(reg == SDHCI_INT_STATUS)) {
if (val & SDHCI_INT_VENDOR_SPEC_DMA_ERR) {
val &= ~SDHCI_INT_VENDOR_SPEC_DMA_ERR;
val |= SDHCI_INT_ADMA_ERROR;
}
}
return val;
}
static void esdhc_writel_le(struct sdhci_host *host, u32 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
u32 data;
if (unlikely(reg == SDHCI_INT_ENABLE || reg == SDHCI_SIGNAL_ENABLE)) {
if (boarddata->cd_type == ESDHC_CD_GPIO)
val &= ~(SDHCI_INT_CARD_REMOVE | SDHCI_INT_CARD_INSERT);
if (val & SDHCI_INT_CARD_INT) {
data = readl(host->ioaddr + SDHCI_HOST_CONTROL);
data &= ~SDHCI_CTRL_D3CD;
writel(data, host->ioaddr + SDHCI_HOST_CONTROL);
data |= SDHCI_CTRL_D3CD;
writel(data, host->ioaddr + SDHCI_HOST_CONTROL);
}
}
if (unlikely((imx_data->flags & ESDHC_FLAG_MULTIBLK_NO_INT)
&& (reg == SDHCI_INT_STATUS)
&& (val & SDHCI_INT_DATA_END))) {
u32 v;
v = readl(host->ioaddr + SDHCI_VENDOR_SPEC);
v &= ~SDHCI_VENDOR_SPEC_SDIO_QUIRK;
writel(v, host->ioaddr + SDHCI_VENDOR_SPEC);
}
if (unlikely(reg == SDHCI_INT_ENABLE || reg == SDHCI_SIGNAL_ENABLE)) {
if (val & SDHCI_INT_ADMA_ERROR) {
val &= ~SDHCI_INT_ADMA_ERROR;
val |= SDHCI_INT_VENDOR_SPEC_DMA_ERR;
}
}
writel(val, host->ioaddr + reg);
}
static u16 esdhc_readw_le(struct sdhci_host *host, int reg)
{
if (unlikely(reg == SDHCI_HOST_VERSION)) {
u16 val = readw(host->ioaddr + (reg ^ 2));
if ((val & SDHCI_SPEC_VER_MASK) == 3)
return --val;
}
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
if ((host->cmd->opcode == MMC_STOP_TRANSMISSION ||
host->cmd->opcode == MMC_SET_BLOCK_COUNT) &&
(imx_data->flags & ESDHC_FLAG_MULTIBLK_NO_INT))
val |= SDHCI_CMD_ABORTCMD;
if (is_imx6q_usdhc(imx_data)) {
u32 m = readl(host->ioaddr + SDHCI_MIX_CTRL);
m = imx_data->scratchpad | (m & 0xffff0000);
writel(m, host->ioaddr + SDHCI_MIX_CTRL);
writel(val << 16,
host->ioaddr + SDHCI_TRANSFER_MODE);
} else {
writel(val << 16 | imx_data->scratchpad,
host->ioaddr + SDHCI_TRANSFER_MODE);
}
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
new_val = val & (SDHCI_CTRL_LED | \
SDHCI_CTRL_4BITBUS | \
SDHCI_CTRL_D3CD);
new_val |= ESDHC_HOST_CONTROL_LE;
new_val |= (val & SDHCI_CTRL_DMA_MASK) << 5;
esdhc_clrset_le(host, 0xffff, new_val, reg);
return;
}
esdhc_clrset_le(host, 0xff, val, reg);
if ((reg == SDHCI_SOFTWARE_RESET) && (val & 1))
esdhc_clrset_le(host, 0x7, 0x7, ESDHC_SYSTEM_CONTROL);
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
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
switch (boarddata->wp_type) {
case ESDHC_WP_GPIO:
if (gpio_is_valid(boarddata->wp_gpio))
return gpio_get_value(boarddata->wp_gpio);
case ESDHC_WP_CONTROLLER:
return !(readl(host->ioaddr + SDHCI_PRESENT_STATE) &
SDHCI_WRITE_PROTECT);
case ESDHC_WP_NONE:
break;
}
return -ENOSYS;
}
static irqreturn_t cd_irq(int irq, void *data)
{
struct sdhci_host *sdhost = (struct sdhci_host *)data;
tasklet_schedule(&sdhost->card_tasklet);
return IRQ_HANDLED;
}
static int __devinit
sdhci_esdhc_imx_probe_dt(struct platform_device *pdev,
struct esdhc_platform_data *boarddata)
{
struct device_node *np = pdev->dev.of_node;
if (!np)
return -ENODEV;
if (of_get_property(np, "fsl,card-wired", NULL))
boarddata->cd_type = ESDHC_CD_PERMANENT;
if (of_get_property(np, "fsl,cd-controller", NULL))
boarddata->cd_type = ESDHC_CD_CONTROLLER;
if (of_get_property(np, "fsl,wp-controller", NULL))
boarddata->wp_type = ESDHC_WP_CONTROLLER;
boarddata->cd_gpio = of_get_named_gpio(np, "cd-gpios", 0);
if (gpio_is_valid(boarddata->cd_gpio))
boarddata->cd_type = ESDHC_CD_GPIO;
boarddata->wp_gpio = of_get_named_gpio(np, "wp-gpios", 0);
if (gpio_is_valid(boarddata->wp_gpio))
boarddata->wp_type = ESDHC_WP_GPIO;
return 0;
}
static inline int
sdhci_esdhc_imx_probe_dt(struct platform_device *pdev,
struct esdhc_platform_data *boarddata)
{
return -ENODEV;
}
static int __devinit sdhci_esdhc_imx_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(imx_esdhc_dt_ids, &pdev->dev);
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_host *host;
struct esdhc_platform_data *boarddata;
struct clk *clk;
int err;
struct pltfm_imx_data *imx_data;
host = sdhci_pltfm_init(pdev, &sdhci_esdhc_imx_pdata);
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
imx_data = kzalloc(sizeof(struct pltfm_imx_data), GFP_KERNEL);
if (!imx_data) {
err = -ENOMEM;
goto err_imx_data;
}
if (of_id)
pdev->id_entry = of_id->data;
imx_data->devtype = pdev->id_entry->driver_data;
pltfm_host->priv = imx_data;
clk = clk_get(mmc_dev(host->mmc), NULL);
if (IS_ERR(clk)) {
dev_err(mmc_dev(host->mmc), "clk err\n");
err = PTR_ERR(clk);
goto err_clk_get;
}
clk_enable(clk);
pltfm_host->clk = clk;
if (!is_imx25_esdhc(imx_data))
host->quirks |= SDHCI_QUIRK_BROKEN_TIMEOUT_VAL;
if (is_imx25_esdhc(imx_data) || is_imx35_esdhc(imx_data))
host->quirks |= SDHCI_QUIRK_NO_MULTIBLOCK
| SDHCI_QUIRK_BROKEN_ADMA;
if (is_imx53_esdhc(imx_data))
imx_data->flags |= ESDHC_FLAG_MULTIBLK_NO_INT;
if (is_imx6q_usdhc(imx_data))
writel(0x08100810, host->ioaddr + SDHCI_WTMK_LVL);
boarddata = &imx_data->boarddata;
if (sdhci_esdhc_imx_probe_dt(pdev, boarddata) < 0) {
if (!host->mmc->parent->platform_data) {
dev_err(mmc_dev(host->mmc), "no board data!\n");
err = -EINVAL;
goto no_board_data;
}
imx_data->boarddata = *((struct esdhc_platform_data *)
host->mmc->parent->platform_data);
}
if (boarddata->wp_type == ESDHC_WP_GPIO) {
err = gpio_request_one(boarddata->wp_gpio, GPIOF_IN, "ESDHC_WP");
if (err) {
dev_warn(mmc_dev(host->mmc),
"no write-protect pin available!\n");
boarddata->wp_gpio = -EINVAL;
}
} else {
boarddata->wp_gpio = -EINVAL;
}
if (boarddata->cd_type != ESDHC_CD_GPIO)
boarddata->cd_gpio = -EINVAL;
switch (boarddata->cd_type) {
case ESDHC_CD_GPIO:
err = gpio_request_one(boarddata->cd_gpio, GPIOF_IN, "ESDHC_CD");
if (err) {
dev_err(mmc_dev(host->mmc),
"no card-detect pin available!\n");
goto no_card_detect_pin;
}
err = request_irq(gpio_to_irq(boarddata->cd_gpio), cd_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
mmc_hostname(host->mmc), host);
if (err) {
dev_err(mmc_dev(host->mmc), "request irq error\n");
goto no_card_detect_irq;
}
case ESDHC_CD_CONTROLLER:
host->quirks &= ~SDHCI_QUIRK_BROKEN_CARD_DETECTION;
break;
case ESDHC_CD_PERMANENT:
host->mmc->caps = MMC_CAP_NONREMOVABLE;
break;
case ESDHC_CD_NONE:
break;
}
err = sdhci_add_host(host);
if (err)
goto err_add_host;
return 0;
err_add_host:
if (gpio_is_valid(boarddata->cd_gpio))
free_irq(gpio_to_irq(boarddata->cd_gpio), host);
no_card_detect_irq:
if (gpio_is_valid(boarddata->cd_gpio))
gpio_free(boarddata->cd_gpio);
if (gpio_is_valid(boarddata->wp_gpio))
gpio_free(boarddata->wp_gpio);
no_card_detect_pin:
no_board_data:
clk_disable(pltfm_host->clk);
clk_put(pltfm_host->clk);
err_clk_get:
kfree(imx_data);
err_imx_data:
sdhci_pltfm_free(pdev);
return err;
}
static int __devexit sdhci_esdhc_imx_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct pltfm_imx_data *imx_data = pltfm_host->priv;
struct esdhc_platform_data *boarddata = &imx_data->boarddata;
int dead = (readl(host->ioaddr + SDHCI_INT_STATUS) == 0xffffffff);
sdhci_remove_host(host, dead);
if (gpio_is_valid(boarddata->wp_gpio))
gpio_free(boarddata->wp_gpio);
if (gpio_is_valid(boarddata->cd_gpio)) {
free_irq(gpio_to_irq(boarddata->cd_gpio), host);
gpio_free(boarddata->cd_gpio);
}
clk_disable(pltfm_host->clk);
clk_put(pltfm_host->clk);
kfree(imx_data);
sdhci_pltfm_free(pdev);
return 0;
}
