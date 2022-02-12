void sdhci_f_sdh30_soft_voltage_switch(struct sdhci_host *host)
{
struct f_sdhost_priv *priv = sdhci_priv(host);
u32 ctrl = 0;
usleep_range(2500, 3000);
ctrl = sdhci_readl(host, F_SDH30_IO_CONTROL2);
ctrl |= F_SDH30_CRES_O_DN;
sdhci_writel(host, ctrl, F_SDH30_IO_CONTROL2);
ctrl |= F_SDH30_MSEL_O_1_8;
sdhci_writel(host, ctrl, F_SDH30_IO_CONTROL2);
ctrl &= ~F_SDH30_CRES_O_DN;
sdhci_writel(host, ctrl, F_SDH30_IO_CONTROL2);
usleep_range(2500, 3000);
if (priv->vendor_hs200) {
dev_info(priv->dev, "%s: setting hs200\n", __func__);
ctrl = sdhci_readl(host, F_SDH30_ESD_CONTROL);
ctrl |= priv->vendor_hs200;
sdhci_writel(host, ctrl, F_SDH30_ESD_CONTROL);
}
ctrl = sdhci_readl(host, F_SDH30_TUNING_SETTING);
ctrl |= F_SDH30_CMD_CHK_DIS;
sdhci_writel(host, ctrl, F_SDH30_TUNING_SETTING);
}
unsigned int sdhci_f_sdh30_get_min_clock(struct sdhci_host *host)
{
return F_SDH30_MIN_CLOCK;
}
void sdhci_f_sdh30_reset(struct sdhci_host *host, u8 mask)
{
if (sdhci_readw(host, SDHCI_CLOCK_CONTROL) == 0)
sdhci_writew(host, 0xBC01, SDHCI_CLOCK_CONTROL);
sdhci_reset(host, mask);
}
static int sdhci_f_sdh30_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct device *dev = &pdev->dev;
struct resource *res;
int irq, ctrl = 0, ret = 0;
struct f_sdhost_priv *priv;
u32 reg = 0;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "%s: no irq specified\n", __func__);
return irq;
}
host = sdhci_alloc_host(dev, sizeof(struct sdhci_host) +
sizeof(struct f_sdhost_priv));
if (IS_ERR(host))
return PTR_ERR(host);
priv = sdhci_priv(host);
priv->dev = dev;
host->quirks = SDHCI_QUIRK_NO_ENDATTR_IN_NOPDESC |
SDHCI_QUIRK_INVERTED_WRITE_PROTECT;
host->quirks2 = SDHCI_QUIRK2_SUPPORT_SINGLE |
SDHCI_QUIRK2_TUNING_WORK_AROUND;
ret = mmc_of_parse(host->mmc);
if (ret)
goto err;
platform_set_drvdata(pdev, host);
sdhci_get_of_property(pdev);
host->hw_name = "f_sdh30";
host->ops = &sdhci_f_sdh30_ops;
host->irq = irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->ioaddr)) {
ret = PTR_ERR(host->ioaddr);
goto err;
}
priv->clk_iface = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(priv->clk_iface)) {
ret = PTR_ERR(priv->clk_iface);
goto err;
}
ret = clk_prepare_enable(priv->clk_iface);
if (ret)
goto err;
priv->clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(priv->clk)) {
ret = PTR_ERR(priv->clk);
goto err_clk;
}
ret = clk_prepare_enable(priv->clk);
if (ret)
goto err_clk;
ctrl = sdhci_readw(host, F_SDH30_AHB_CONFIG);
ctrl |= F_SDH30_SIN | F_SDH30_AHB_INCR_16 | F_SDH30_AHB_INCR_8 |
F_SDH30_AHB_INCR_4;
ctrl &= ~(F_SDH30_AHB_BIGED | F_SDH30_BUSLOCK_EN);
sdhci_writew(host, ctrl, F_SDH30_AHB_CONFIG);
reg = sdhci_readl(host, F_SDH30_ESD_CONTROL);
sdhci_writel(host, reg & ~F_SDH30_EMMC_RST, F_SDH30_ESD_CONTROL);
msleep(20);
sdhci_writel(host, reg | F_SDH30_EMMC_RST, F_SDH30_ESD_CONTROL);
reg = sdhci_readl(host, SDHCI_CAPABILITIES);
if (reg & SDHCI_CAN_DO_8BIT)
priv->vendor_hs200 = F_SDH30_EMMC_HS200;
ret = sdhci_add_host(host);
if (ret)
goto err_add_host;
return 0;
err_add_host:
clk_disable_unprepare(priv->clk);
err_clk:
clk_disable_unprepare(priv->clk_iface);
err:
sdhci_free_host(host);
return ret;
}
static int sdhci_f_sdh30_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct f_sdhost_priv *priv = sdhci_priv(host);
sdhci_remove_host(host, readl(host->ioaddr + SDHCI_INT_STATUS) ==
0xffffffff);
clk_disable_unprepare(priv->clk_iface);
clk_disable_unprepare(priv->clk);
sdhci_free_host(host);
platform_set_drvdata(pdev, NULL);
return 0;
}
