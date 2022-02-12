static int sdhci_arasan_syscon_write(struct sdhci_host *host,
const struct sdhci_arasan_soc_ctl_field *fld,
u32 val)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
struct regmap *soc_ctl_base = sdhci_arasan->soc_ctl_base;
u32 reg = fld->reg;
u16 width = fld->width;
s16 shift = fld->shift;
int ret;
if (shift < 0)
return -EINVAL;
if (sdhci_arasan->soc_ctl_map->hiword_update)
ret = regmap_write(soc_ctl_base, reg,
HIWORD_UPDATE(val, GENMASK(width, 0),
shift));
else
ret = regmap_update_bits(soc_ctl_base, reg,
GENMASK(shift + width, shift),
val << shift);
if (ret)
pr_warn("%s: Regmap write fail: %d\n",
mmc_hostname(host->mmc), ret);
return ret;
}
static unsigned int sdhci_arasan_get_timeout_clock(struct sdhci_host *host)
{
u32 div;
unsigned long freq;
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
div = readl(host->ioaddr + SDHCI_ARASAN_CLK_CTRL_OFFSET);
div = (div & CLK_CTRL_TIMEOUT_MASK) >> CLK_CTRL_TIMEOUT_SHIFT;
freq = clk_get_rate(pltfm_host->clk);
freq /= 1 << (CLK_CTRL_TIMEOUT_MIN_EXP + div);
return freq;
}
static void sdhci_arasan_set_clock(struct sdhci_host *host, unsigned int clock)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
bool ctrl_phy = false;
if (!IS_ERR(sdhci_arasan->phy)) {
if (!sdhci_arasan->is_phy_on && clock <= PHY_CLK_TOO_SLOW_HZ) {
sdhci_set_clock(host, host->max_clk);
spin_unlock_irq(&host->lock);
phy_power_on(sdhci_arasan->phy);
spin_lock_irq(&host->lock);
sdhci_arasan->is_phy_on = true;
} else if (clock > PHY_CLK_TOO_SLOW_HZ) {
ctrl_phy = true;
}
}
if (ctrl_phy && sdhci_arasan->is_phy_on) {
spin_unlock_irq(&host->lock);
phy_power_off(sdhci_arasan->phy);
spin_lock_irq(&host->lock);
sdhci_arasan->is_phy_on = false;
}
sdhci_set_clock(host, clock);
if (ctrl_phy) {
spin_unlock_irq(&host->lock);
phy_power_on(sdhci_arasan->phy);
spin_lock_irq(&host->lock);
sdhci_arasan->is_phy_on = true;
}
}
static void sdhci_arasan_hs400_enhanced_strobe(struct mmc_host *mmc,
struct mmc_ios *ios)
{
u32 vendor;
struct sdhci_host *host = mmc_priv(mmc);
vendor = readl(host->ioaddr + SDHCI_ARASAN_VENDOR_REGISTER);
if (ios->enhanced_strobe)
vendor |= VENDOR_ENHANCED_STROBE;
else
vendor &= ~VENDOR_ENHANCED_STROBE;
writel(vendor, host->ioaddr + SDHCI_ARASAN_VENDOR_REGISTER);
}
static void sdhci_arasan_reset(struct sdhci_host *host, u8 mask)
{
u8 ctrl;
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
sdhci_reset(host, mask);
if (sdhci_arasan->quirks & SDHCI_ARASAN_QUIRK_FORCE_CDTEST) {
ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
ctrl |= SDHCI_CTRL_CDTEST_INS | SDHCI_CTRL_CDTEST_EN;
sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
}
}
static int sdhci_arasan_voltage_switch(struct mmc_host *mmc,
struct mmc_ios *ios)
{
switch (ios->signal_voltage) {
case MMC_SIGNAL_VOLTAGE_180:
return 0;
case MMC_SIGNAL_VOLTAGE_330:
case MMC_SIGNAL_VOLTAGE_120:
break;
}
return -EINVAL;
}
static int sdhci_arasan_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
int ret;
ret = sdhci_suspend_host(host);
if (ret)
return ret;
if (!IS_ERR(sdhci_arasan->phy) && sdhci_arasan->is_phy_on) {
ret = phy_power_off(sdhci_arasan->phy);
if (ret) {
dev_err(dev, "Cannot power off phy.\n");
sdhci_resume_host(host);
return ret;
}
sdhci_arasan->is_phy_on = false;
}
clk_disable(pltfm_host->clk);
clk_disable(sdhci_arasan->clk_ahb);
return 0;
}
static int sdhci_arasan_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
int ret;
ret = clk_enable(sdhci_arasan->clk_ahb);
if (ret) {
dev_err(dev, "Cannot enable AHB clock.\n");
return ret;
}
ret = clk_enable(pltfm_host->clk);
if (ret) {
dev_err(dev, "Cannot enable SD clock.\n");
return ret;
}
if (!IS_ERR(sdhci_arasan->phy) && host->mmc->actual_clock) {
ret = phy_power_on(sdhci_arasan->phy);
if (ret) {
dev_err(dev, "Cannot power on phy.\n");
return ret;
}
sdhci_arasan->is_phy_on = true;
}
return sdhci_resume_host(host);
}
static unsigned long sdhci_arasan_sdcardclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct sdhci_arasan_data *sdhci_arasan =
container_of(hw, struct sdhci_arasan_data, sdcardclk_hw);
struct sdhci_host *host = sdhci_arasan->host;
return host->mmc->actual_clock;
}
static void sdhci_arasan_update_clockmultiplier(struct sdhci_host *host,
u32 value)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
const struct sdhci_arasan_soc_ctl_map *soc_ctl_map =
sdhci_arasan->soc_ctl_map;
if (!soc_ctl_map)
return;
if (!sdhci_arasan->soc_ctl_base) {
pr_warn("%s: Have regmap, but no soc-ctl-syscon\n",
mmc_hostname(host->mmc));
return;
}
sdhci_arasan_syscon_write(host, &soc_ctl_map->clockmultiplier, value);
}
static void sdhci_arasan_update_baseclkfreq(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
const struct sdhci_arasan_soc_ctl_map *soc_ctl_map =
sdhci_arasan->soc_ctl_map;
u32 mhz = DIV_ROUND_CLOSEST(clk_get_rate(pltfm_host->clk), 1000000);
if (!soc_ctl_map)
return;
if (!sdhci_arasan->soc_ctl_base) {
pr_warn("%s: Have regmap, but no soc-ctl-syscon\n",
mmc_hostname(host->mmc));
return;
}
sdhci_arasan_syscon_write(host, &soc_ctl_map->baseclkfreq, mhz);
}
static int sdhci_arasan_register_sdclk(struct sdhci_arasan_data *sdhci_arasan,
struct clk *clk_xin,
struct device *dev)
{
struct device_node *np = dev->of_node;
struct clk_init_data sdcardclk_init;
const char *parent_clk_name;
int ret;
if (!of_find_property(np, "#clock-cells", NULL))
return 0;
ret = of_property_read_string_index(np, "clock-output-names", 0,
&sdcardclk_init.name);
if (ret) {
dev_err(dev, "DT has #clock-cells but no clock-output-names\n");
return ret;
}
parent_clk_name = __clk_get_name(clk_xin);
sdcardclk_init.parent_names = &parent_clk_name;
sdcardclk_init.num_parents = 1;
sdcardclk_init.flags = CLK_GET_RATE_NOCACHE;
sdcardclk_init.ops = &arasan_sdcardclk_ops;
sdhci_arasan->sdcardclk_hw.init = &sdcardclk_init;
sdhci_arasan->sdcardclk =
devm_clk_register(dev, &sdhci_arasan->sdcardclk_hw);
sdhci_arasan->sdcardclk_hw.init = NULL;
ret = of_clk_add_provider(np, of_clk_src_simple_get,
sdhci_arasan->sdcardclk);
if (ret)
dev_err(dev, "Failed to add clock provider\n");
return ret;
}
static void sdhci_arasan_unregister_sdclk(struct device *dev)
{
struct device_node *np = dev->of_node;
if (!of_find_property(np, "#clock-cells", NULL))
return;
of_clk_del_provider(dev->of_node);
}
static int sdhci_arasan_probe(struct platform_device *pdev)
{
int ret;
const struct of_device_id *match;
struct device_node *node;
struct clk *clk_xin;
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_arasan_data *sdhci_arasan;
struct device_node *np = pdev->dev.of_node;
host = sdhci_pltfm_init(pdev, &sdhci_arasan_pdata,
sizeof(*sdhci_arasan));
if (IS_ERR(host))
return PTR_ERR(host);
pltfm_host = sdhci_priv(host);
sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
sdhci_arasan->host = host;
match = of_match_node(sdhci_arasan_of_match, pdev->dev.of_node);
sdhci_arasan->soc_ctl_map = match->data;
node = of_parse_phandle(pdev->dev.of_node, "arasan,soc-ctl-syscon", 0);
if (node) {
sdhci_arasan->soc_ctl_base = syscon_node_to_regmap(node);
of_node_put(node);
if (IS_ERR(sdhci_arasan->soc_ctl_base)) {
ret = PTR_ERR(sdhci_arasan->soc_ctl_base);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Can't get syscon: %d\n",
ret);
goto err_pltfm_free;
}
}
sdhci_arasan->clk_ahb = devm_clk_get(&pdev->dev, "clk_ahb");
if (IS_ERR(sdhci_arasan->clk_ahb)) {
dev_err(&pdev->dev, "clk_ahb clock not found.\n");
ret = PTR_ERR(sdhci_arasan->clk_ahb);
goto err_pltfm_free;
}
clk_xin = devm_clk_get(&pdev->dev, "clk_xin");
if (IS_ERR(clk_xin)) {
dev_err(&pdev->dev, "clk_xin clock not found.\n");
ret = PTR_ERR(clk_xin);
goto err_pltfm_free;
}
ret = clk_prepare_enable(sdhci_arasan->clk_ahb);
if (ret) {
dev_err(&pdev->dev, "Unable to enable AHB clock.\n");
goto err_pltfm_free;
}
ret = clk_prepare_enable(clk_xin);
if (ret) {
dev_err(&pdev->dev, "Unable to enable SD clock.\n");
goto clk_dis_ahb;
}
sdhci_get_of_property(pdev);
if (of_property_read_bool(np, "xlnx,fails-without-test-cd"))
sdhci_arasan->quirks |= SDHCI_ARASAN_QUIRK_FORCE_CDTEST;
pltfm_host->clk = clk_xin;
if (of_device_is_compatible(pdev->dev.of_node,
"rockchip,rk3399-sdhci-5.1"))
sdhci_arasan_update_clockmultiplier(host, 0x0);
sdhci_arasan_update_baseclkfreq(host);
ret = sdhci_arasan_register_sdclk(sdhci_arasan, clk_xin, &pdev->dev);
if (ret)
goto clk_disable_all;
ret = mmc_of_parse(host->mmc);
if (ret) {
dev_err(&pdev->dev, "parsing dt failed (%u)\n", ret);
goto unreg_clk;
}
sdhci_arasan->phy = ERR_PTR(-ENODEV);
if (of_device_is_compatible(pdev->dev.of_node,
"arasan,sdhci-5.1")) {
sdhci_arasan->phy = devm_phy_get(&pdev->dev,
"phy_arasan");
if (IS_ERR(sdhci_arasan->phy)) {
ret = PTR_ERR(sdhci_arasan->phy);
dev_err(&pdev->dev, "No phy for arasan,sdhci-5.1.\n");
goto unreg_clk;
}
ret = phy_init(sdhci_arasan->phy);
if (ret < 0) {
dev_err(&pdev->dev, "phy_init err.\n");
goto unreg_clk;
}
host->mmc_host_ops.hs400_enhanced_strobe =
sdhci_arasan_hs400_enhanced_strobe;
host->mmc_host_ops.start_signal_voltage_switch =
sdhci_arasan_voltage_switch;
}
ret = sdhci_add_host(host);
if (ret)
goto err_add_host;
return 0;
err_add_host:
if (!IS_ERR(sdhci_arasan->phy))
phy_exit(sdhci_arasan->phy);
unreg_clk:
sdhci_arasan_unregister_sdclk(&pdev->dev);
clk_disable_all:
clk_disable_unprepare(clk_xin);
clk_dis_ahb:
clk_disable_unprepare(sdhci_arasan->clk_ahb);
err_pltfm_free:
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_arasan_remove(struct platform_device *pdev)
{
int ret;
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_arasan_data *sdhci_arasan = sdhci_pltfm_priv(pltfm_host);
struct clk *clk_ahb = sdhci_arasan->clk_ahb;
if (!IS_ERR(sdhci_arasan->phy)) {
if (sdhci_arasan->is_phy_on)
phy_power_off(sdhci_arasan->phy);
phy_exit(sdhci_arasan->phy);
}
sdhci_arasan_unregister_sdclk(&pdev->dev);
ret = sdhci_pltfm_unregister(pdev);
clk_disable_unprepare(clk_ahb);
return ret;
}
