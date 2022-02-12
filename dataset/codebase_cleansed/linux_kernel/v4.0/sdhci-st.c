static u32 sdhci_st_readl(struct sdhci_host *host, int reg)
{
u32 ret;
switch (reg) {
case SDHCI_CAPABILITIES:
ret = readl_relaxed(host->ioaddr + reg);
ret &= ~SDHCI_CAN_VDD_300;
break;
default:
ret = readl_relaxed(host->ioaddr + reg);
}
return ret;
}
static int sdhci_st_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct clk *clk;
int ret = 0;
u16 host_version;
clk = devm_clk_get(&pdev->dev, "mmc");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Peripheral clk not found\n");
return PTR_ERR(clk);
}
host = sdhci_pltfm_init(pdev, &sdhci_st_pdata, 0);
if (IS_ERR(host)) {
dev_err(&pdev->dev, "Failed sdhci_pltfm_init\n");
return PTR_ERR(host);
}
ret = mmc_of_parse(host->mmc);
if (ret) {
dev_err(&pdev->dev, "Failed mmc_of_parse\n");
goto err_of;
}
clk_prepare_enable(clk);
pltfm_host = sdhci_priv(host);
pltfm_host->clk = clk;
ret = sdhci_add_host(host);
if (ret) {
dev_err(&pdev->dev, "Failed sdhci_add_host\n");
goto err_out;
}
platform_set_drvdata(pdev, host);
host_version = readw_relaxed((host->ioaddr + SDHCI_HOST_VERSION));
dev_info(&pdev->dev, "SDHCI ST Initialised: Host Version: 0x%x Vendor Version 0x%x\n",
((host_version & SDHCI_SPEC_VER_MASK) >> SDHCI_SPEC_VER_SHIFT),
((host_version & SDHCI_VENDOR_VER_MASK) >>
SDHCI_VENDOR_VER_SHIFT));
return 0;
err_out:
clk_disable_unprepare(clk);
err_of:
sdhci_pltfm_free(pdev);
return ret;
}
static int sdhci_st_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
clk_disable_unprepare(pltfm_host->clk);
return sdhci_pltfm_unregister(pdev);
}
static int sdhci_st_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
int ret = sdhci_suspend_host(host);
if (ret)
goto out;
clk_disable_unprepare(pltfm_host->clk);
out:
return ret;
}
static int sdhci_st_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
clk_prepare_enable(pltfm_host->clk);
return sdhci_resume_host(host);
}
