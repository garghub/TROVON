static irqreturn_t sdhci_gpio_irq(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct sdhci_host *host = platform_get_drvdata(pdev);
struct spear_sdhci *sdhci = dev_get_platdata(&pdev->dev);
unsigned long gpio_irq_type;
int val;
val = gpio_get_value(sdhci->data->card_int_gpio);
gpio_irq_type = val ? IRQF_TRIGGER_LOW : IRQF_TRIGGER_HIGH;
irq_set_irq_type(irq, gpio_irq_type);
if (sdhci->data->card_power_gpio >= 0) {
if (!sdhci->data->power_always_enb) {
val = sdhci->data->power_active_high ? !val : val ;
gpio_set_value(sdhci->data->card_power_gpio, val);
}
}
tasklet_schedule(&host->card_tasklet);
return IRQ_HANDLED;
}
static struct sdhci_plat_data *sdhci_probe_config_dt(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct sdhci_plat_data *pdata = NULL;
int cd_gpio;
cd_gpio = of_get_named_gpio(np, "cd-gpios", 0);
if (!gpio_is_valid(cd_gpio))
cd_gpio = -1;
if (cd_gpio != -1) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(&pdev->dev, "DT: kzalloc failed\n");
return ERR_PTR(-ENOMEM);
}
}
pdata->card_int_gpio = cd_gpio;
return pdata;
}
static struct sdhci_plat_data *sdhci_probe_config_dt(struct platform_device *pdev)
{
return ERR_PTR(-ENOSYS);
}
static int sdhci_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct sdhci_host *host;
struct resource *iomem;
struct spear_sdhci *sdhci;
int ret;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "memory resource not defined\n");
goto err;
}
if (!devm_request_mem_region(&pdev->dev, iomem->start,
resource_size(iomem), "spear-sdhci")) {
ret = -EBUSY;
dev_dbg(&pdev->dev, "cannot request region\n");
goto err;
}
sdhci = devm_kzalloc(&pdev->dev, sizeof(*sdhci), GFP_KERNEL);
if (!sdhci) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "cannot allocate memory for sdhci\n");
goto err;
}
sdhci->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(sdhci->clk)) {
ret = PTR_ERR(sdhci->clk);
dev_dbg(&pdev->dev, "Error getting clock\n");
goto err;
}
ret = clk_prepare_enable(sdhci->clk);
if (ret) {
dev_dbg(&pdev->dev, "Error enabling clock\n");
goto put_clk;
}
ret = clk_set_rate(sdhci->clk, 50000000);
if (ret)
dev_dbg(&pdev->dev, "Error setting desired clk, clk=%lu\n",
clk_get_rate(sdhci->clk));
if (np) {
sdhci->data = sdhci_probe_config_dt(pdev);
if (IS_ERR(sdhci->data)) {
dev_err(&pdev->dev, "DT: Failed to get pdata\n");
return -ENODEV;
}
} else {
sdhci->data = dev_get_platdata(&pdev->dev);
}
pdev->dev.platform_data = sdhci;
if (pdev->dev.parent)
host = sdhci_alloc_host(pdev->dev.parent, 0);
else
host = sdhci_alloc_host(&pdev->dev, 0);
if (IS_ERR(host)) {
ret = PTR_ERR(host);
dev_dbg(&pdev->dev, "error allocating host\n");
goto disable_clk;
}
host->hw_name = "sdhci";
host->ops = &sdhci_pltfm_ops;
host->irq = platform_get_irq(pdev, 0);
host->quirks = SDHCI_QUIRK_BROKEN_ADMA;
host->ioaddr = devm_ioremap(&pdev->dev, iomem->start,
resource_size(iomem));
if (!host->ioaddr) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "failed to remap registers\n");
goto free_host;
}
ret = sdhci_add_host(host);
if (ret) {
dev_dbg(&pdev->dev, "error adding host\n");
goto free_host;
}
platform_set_drvdata(pdev, host);
if (!sdhci->data)
return 0;
if (sdhci->data->card_power_gpio >= 0) {
int val = 0;
ret = devm_gpio_request(&pdev->dev,
sdhci->data->card_power_gpio, "sdhci");
if (ret < 0) {
dev_dbg(&pdev->dev, "gpio request fail: %d\n",
sdhci->data->card_power_gpio);
goto set_drvdata;
}
if (sdhci->data->power_always_enb)
val = sdhci->data->power_active_high;
else
val = !sdhci->data->power_active_high;
ret = gpio_direction_output(sdhci->data->card_power_gpio, val);
if (ret) {
dev_dbg(&pdev->dev, "gpio set direction fail: %d\n",
sdhci->data->card_power_gpio);
goto set_drvdata;
}
}
if (sdhci->data->card_int_gpio >= 0) {
ret = devm_gpio_request(&pdev->dev, sdhci->data->card_int_gpio,
"sdhci");
if (ret < 0) {
dev_dbg(&pdev->dev, "gpio request fail: %d\n",
sdhci->data->card_int_gpio);
goto set_drvdata;
}
ret = gpio_direction_input(sdhci->data->card_int_gpio);
if (ret) {
dev_dbg(&pdev->dev, "gpio set direction fail: %d\n",
sdhci->data->card_int_gpio);
goto set_drvdata;
}
ret = devm_request_irq(&pdev->dev,
gpio_to_irq(sdhci->data->card_int_gpio),
sdhci_gpio_irq, IRQF_TRIGGER_LOW,
mmc_hostname(host->mmc), pdev);
if (ret) {
dev_dbg(&pdev->dev, "gpio request irq fail: %d\n",
sdhci->data->card_int_gpio);
goto set_drvdata;
}
}
return 0;
set_drvdata:
platform_set_drvdata(pdev, NULL);
sdhci_remove_host(host, 1);
free_host:
sdhci_free_host(host);
disable_clk:
clk_disable_unprepare(sdhci->clk);
put_clk:
clk_put(sdhci->clk);
err:
dev_err(&pdev->dev, "spear-sdhci probe failed: %d\n", ret);
return ret;
}
static int sdhci_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct spear_sdhci *sdhci = dev_get_platdata(&pdev->dev);
int dead = 0;
u32 scratch;
platform_set_drvdata(pdev, NULL);
scratch = readl(host->ioaddr + SDHCI_INT_STATUS);
if (scratch == (u32)-1)
dead = 1;
sdhci_remove_host(host, dead);
sdhci_free_host(host);
clk_disable_unprepare(sdhci->clk);
clk_put(sdhci->clk);
return 0;
}
static int sdhci_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct spear_sdhci *sdhci = dev_get_platdata(dev);
int ret;
ret = sdhci_suspend_host(host);
if (!ret)
clk_disable(sdhci->clk);
return ret;
}
static int sdhci_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct spear_sdhci *sdhci = dev_get_platdata(dev);
int ret;
ret = clk_enable(sdhci->clk);
if (ret) {
dev_dbg(dev, "Resume: Error enabling clock\n");
return ret;
}
return sdhci_resume_host(host);
}
