static u32 tegra_sdhci_readl(struct sdhci_host *host, int reg)
{
u32 val;
if (unlikely(reg == SDHCI_PRESENT_STATE)) {
val = readl(host->ioaddr + reg);
return val | SDHCI_WRITE_PROTECT;
}
return readl(host->ioaddr + reg);
}
static u16 tegra_sdhci_readw(struct sdhci_host *host, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
if (unlikely((soc_data->nvquirks & NVQUIRK_FORCE_SDHCI_SPEC_200) &&
(reg == SDHCI_HOST_VERSION))) {
return SDHCI_SPEC_200;
}
return readw(host->ioaddr + reg);
}
static void tegra_sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
if (unlikely(reg == SDHCI_SIGNAL_ENABLE))
val &= ~(SDHCI_INT_TIMEOUT|SDHCI_INT_CRC);
writel(val, host->ioaddr + reg);
if (unlikely((soc_data->nvquirks & NVQUIRK_ENABLE_BLOCK_GAP_DET) &&
(reg == SDHCI_INT_ENABLE))) {
u8 gap_ctrl = readb(host->ioaddr + SDHCI_BLOCK_GAP_CONTROL);
if (val & SDHCI_INT_CARD_INT)
gap_ctrl |= 0x8;
else
gap_ctrl &= ~0x8;
writeb(gap_ctrl, host->ioaddr + SDHCI_BLOCK_GAP_CONTROL);
}
}
static unsigned int tegra_sdhci_get_ro(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct tegra_sdhci_platform_data *plat = tegra_host->plat;
if (!gpio_is_valid(plat->wp_gpio))
return -1;
return gpio_get_value(plat->wp_gpio);
}
static irqreturn_t carddetect_irq(int irq, void *data)
{
struct sdhci_host *sdhost = (struct sdhci_host *)data;
tasklet_schedule(&sdhost->card_tasklet);
return IRQ_HANDLED;
}
static void tegra_sdhci_reset_exit(struct sdhci_host *host, u8 mask)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct sdhci_tegra_soc_data *soc_data = tegra_host->soc_data;
if (!(mask & SDHCI_RESET_ALL))
return;
if (soc_data->nvquirks & NVQUIRK_ENABLE_SDHCI_SPEC_300) {
u32 misc_ctrl;
misc_ctrl = sdhci_readb(host, SDHCI_TEGRA_VENDOR_MISC_CTRL);
misc_ctrl |= SDHCI_MISC_CTRL_ENABLE_SDHCI_SPEC_300;
sdhci_writeb(host, misc_ctrl, SDHCI_TEGRA_VENDOR_MISC_CTRL);
}
}
static int tegra_sdhci_8bit(struct sdhci_host *host, int bus_width)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct tegra_sdhci_platform_data *plat = tegra_host->plat;
u32 ctrl;
ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
if (plat->is_8bit && bus_width == MMC_BUS_WIDTH_8) {
ctrl &= ~SDHCI_CTRL_4BITBUS;
ctrl |= SDHCI_CTRL_8BITBUS;
} else {
ctrl &= ~SDHCI_CTRL_8BITBUS;
if (bus_width == MMC_BUS_WIDTH_4)
ctrl |= SDHCI_CTRL_4BITBUS;
else
ctrl &= ~SDHCI_CTRL_4BITBUS;
}
sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
return 0;
}
static struct tegra_sdhci_platform_data * __devinit sdhci_tegra_dt_parse_pdata(
struct platform_device *pdev)
{
struct tegra_sdhci_platform_data *plat;
struct device_node *np = pdev->dev.of_node;
if (!np)
return NULL;
plat = devm_kzalloc(&pdev->dev, sizeof(*plat), GFP_KERNEL);
if (!plat) {
dev_err(&pdev->dev, "Can't allocate platform data\n");
return NULL;
}
plat->cd_gpio = of_get_named_gpio(np, "cd-gpios", 0);
plat->wp_gpio = of_get_named_gpio(np, "wp-gpios", 0);
plat->power_gpio = of_get_named_gpio(np, "power-gpios", 0);
if (of_find_property(np, "support-8bit", NULL))
plat->is_8bit = 1;
return plat;
}
static int __devinit sdhci_tegra_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct sdhci_tegra_soc_data *soc_data;
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct tegra_sdhci_platform_data *plat;
struct sdhci_tegra *tegra_host;
struct clk *clk;
int rc;
match = of_match_device(sdhci_tegra_dt_match, &pdev->dev);
if (match)
soc_data = match->data;
else
soc_data = &soc_data_tegra20;
host = sdhci_pltfm_init(pdev, soc_data->pdata);
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
plat = pdev->dev.platform_data;
if (plat == NULL)
plat = sdhci_tegra_dt_parse_pdata(pdev);
if (plat == NULL) {
dev_err(mmc_dev(host->mmc), "missing platform data\n");
rc = -ENXIO;
goto err_no_plat;
}
tegra_host = devm_kzalloc(&pdev->dev, sizeof(*tegra_host), GFP_KERNEL);
if (!tegra_host) {
dev_err(mmc_dev(host->mmc), "failed to allocate tegra_host\n");
rc = -ENOMEM;
goto err_no_plat;
}
tegra_host->plat = plat;
tegra_host->soc_data = soc_data;
pltfm_host->priv = tegra_host;
if (gpio_is_valid(plat->power_gpio)) {
rc = gpio_request(plat->power_gpio, "sdhci_power");
if (rc) {
dev_err(mmc_dev(host->mmc),
"failed to allocate power gpio\n");
goto err_power_req;
}
gpio_direction_output(plat->power_gpio, 1);
}
if (gpio_is_valid(plat->cd_gpio)) {
rc = gpio_request(plat->cd_gpio, "sdhci_cd");
if (rc) {
dev_err(mmc_dev(host->mmc),
"failed to allocate cd gpio\n");
goto err_cd_req;
}
gpio_direction_input(plat->cd_gpio);
rc = request_irq(gpio_to_irq(plat->cd_gpio), carddetect_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
mmc_hostname(host->mmc), host);
if (rc) {
dev_err(mmc_dev(host->mmc), "request irq error\n");
goto err_cd_irq_req;
}
}
if (gpio_is_valid(plat->wp_gpio)) {
rc = gpio_request(plat->wp_gpio, "sdhci_wp");
if (rc) {
dev_err(mmc_dev(host->mmc),
"failed to allocate wp gpio\n");
goto err_wp_req;
}
gpio_direction_input(plat->wp_gpio);
}
clk = clk_get(mmc_dev(host->mmc), NULL);
if (IS_ERR(clk)) {
dev_err(mmc_dev(host->mmc), "clk err\n");
rc = PTR_ERR(clk);
goto err_clk_get;
}
clk_enable(clk);
pltfm_host->clk = clk;
host->mmc->pm_caps = plat->pm_flags;
if (plat->is_8bit)
host->mmc->caps |= MMC_CAP_8_BIT_DATA;
rc = sdhci_add_host(host);
if (rc)
goto err_add_host;
return 0;
err_add_host:
clk_disable(pltfm_host->clk);
clk_put(pltfm_host->clk);
err_clk_get:
if (gpio_is_valid(plat->wp_gpio))
gpio_free(plat->wp_gpio);
err_wp_req:
if (gpio_is_valid(plat->cd_gpio))
free_irq(gpio_to_irq(plat->cd_gpio), host);
err_cd_irq_req:
if (gpio_is_valid(plat->cd_gpio))
gpio_free(plat->cd_gpio);
err_cd_req:
if (gpio_is_valid(plat->power_gpio))
gpio_free(plat->power_gpio);
err_power_req:
err_no_plat:
sdhci_pltfm_free(pdev);
return rc;
}
static int __devexit sdhci_tegra_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_tegra *tegra_host = pltfm_host->priv;
const struct tegra_sdhci_platform_data *plat = tegra_host->plat;
int dead = (readl(host->ioaddr + SDHCI_INT_STATUS) == 0xffffffff);
sdhci_remove_host(host, dead);
if (gpio_is_valid(plat->wp_gpio))
gpio_free(plat->wp_gpio);
if (gpio_is_valid(plat->cd_gpio)) {
free_irq(gpio_to_irq(plat->cd_gpio), host);
gpio_free(plat->cd_gpio);
}
if (gpio_is_valid(plat->power_gpio))
gpio_free(plat->power_gpio);
clk_disable(pltfm_host->clk);
clk_put(pltfm_host->clk);
sdhci_pltfm_free(pdev);
return 0;
}
