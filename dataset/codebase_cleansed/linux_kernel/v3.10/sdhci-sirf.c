static unsigned int sdhci_sirf_get_max_clk(struct sdhci_host *host)
{
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_sirf_priv *priv = pltfm_host->priv;
return clk_get_rate(priv->clk);
}
static int sdhci_sirf_probe(struct platform_device *pdev)
{
struct sdhci_host *host;
struct sdhci_pltfm_host *pltfm_host;
struct sdhci_sirf_priv *priv;
struct pinctrl *pinctrl;
int ret;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
dev_err(&pdev->dev, "unable to get pinmux");
return PTR_ERR(pinctrl);
}
priv = devm_kzalloc(&pdev->dev, sizeof(struct sdhci_sirf_priv),
GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "unable to allocate private data");
return -ENOMEM;
}
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(&pdev->dev, "unable to get clock");
return PTR_ERR(priv->clk);
}
if (pdev->dev.of_node) {
priv->gpio_cd = of_get_named_gpio(pdev->dev.of_node,
"cd-gpios", 0);
} else {
priv->gpio_cd = -EINVAL;
}
host = sdhci_pltfm_init(pdev, &sdhci_sirf_pdata);
if (IS_ERR(host)) {
ret = PTR_ERR(host);
goto err_sdhci_pltfm_init;
}
pltfm_host = sdhci_priv(host);
pltfm_host->priv = priv;
sdhci_get_of_property(pdev);
clk_prepare_enable(priv->clk);
ret = sdhci_add_host(host);
if (ret)
goto err_sdhci_add;
if (gpio_is_valid(priv->gpio_cd)) {
ret = mmc_gpio_request_cd(host->mmc, priv->gpio_cd);
if (ret) {
dev_err(&pdev->dev, "card detect irq request failed: %d\n",
ret);
goto err_request_cd;
}
}
return 0;
err_request_cd:
sdhci_remove_host(host, 0);
err_sdhci_add:
clk_disable_unprepare(priv->clk);
sdhci_pltfm_free(pdev);
err_sdhci_pltfm_init:
return ret;
}
static int sdhci_sirf_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_sirf_priv *priv = pltfm_host->priv;
sdhci_pltfm_unregister(pdev);
if (gpio_is_valid(priv->gpio_cd))
mmc_gpio_free_cd(host->mmc);
clk_disable_unprepare(priv->clk);
return 0;
}
static int sdhci_sirf_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_sirf_priv *priv = pltfm_host->priv;
int ret;
ret = sdhci_suspend_host(host);
if (ret)
return ret;
clk_disable(priv->clk);
return 0;
}
static int sdhci_sirf_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
struct sdhci_sirf_priv *priv = pltfm_host->priv;
int ret;
ret = clk_enable(priv->clk);
if (ret) {
dev_dbg(dev, "Resume: Error enabling clock\n");
return ret;
}
return sdhci_resume_host(host);
}
