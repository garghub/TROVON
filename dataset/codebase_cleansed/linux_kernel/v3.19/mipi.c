static inline u32 tegra_mipi_readl(struct tegra_mipi *mipi,
unsigned long offset)
{
return readl(mipi->regs + (offset << 2));
}
static inline void tegra_mipi_writel(struct tegra_mipi *mipi, u32 value,
unsigned long offset)
{
writel(value, mipi->regs + (offset << 2));
}
struct tegra_mipi_device *tegra_mipi_request(struct device *device)
{
struct device_node *np = device->of_node;
struct tegra_mipi_device *dev;
struct of_phandle_args args;
int err;
err = of_parse_phandle_with_args(np, "nvidia,mipi-calibrate",
"#nvidia,mipi-calibrate-cells", 0,
&args);
if (err < 0)
return ERR_PTR(err);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
err = -ENOMEM;
goto out;
}
dev->pdev = of_find_device_by_node(args.np);
if (!dev->pdev) {
err = -ENODEV;
goto free;
}
dev->mipi = platform_get_drvdata(dev->pdev);
if (!dev->mipi) {
err = -EPROBE_DEFER;
goto put;
}
of_node_put(args.np);
dev->pads = args.args[0];
dev->device = device;
return dev;
put:
platform_device_put(dev->pdev);
free:
kfree(dev);
out:
of_node_put(args.np);
return ERR_PTR(err);
}
void tegra_mipi_free(struct tegra_mipi_device *device)
{
platform_device_put(device->pdev);
kfree(device);
}
static int tegra_mipi_wait(struct tegra_mipi *mipi)
{
unsigned long timeout = jiffies + msecs_to_jiffies(250);
u32 value;
while (time_before(jiffies, timeout)) {
value = tegra_mipi_readl(mipi, MIPI_CAL_STATUS);
if ((value & MIPI_CAL_STATUS_ACTIVE) == 0 &&
(value & MIPI_CAL_STATUS_DONE) != 0)
return 0;
usleep_range(10, 50);
}
return -ETIMEDOUT;
}
int tegra_mipi_calibrate(struct tegra_mipi_device *device)
{
const struct tegra_mipi_soc *soc = device->mipi->soc;
unsigned int i;
u32 value;
int err;
err = clk_enable(device->mipi->clk);
if (err < 0)
return err;
mutex_lock(&device->mipi->lock);
value = tegra_mipi_readl(device->mipi, MIPI_CAL_BIAS_PAD_CFG0);
value &= ~MIPI_CAL_BIAS_PAD_PDVCLAMP;
value |= MIPI_CAL_BIAS_PAD_E_VCLAMP_REF;
tegra_mipi_writel(device->mipi, value, MIPI_CAL_BIAS_PAD_CFG0);
tegra_mipi_writel(device->mipi, MIPI_CAL_BIAS_PAD_DRV_DN_REF(2),
MIPI_CAL_BIAS_PAD_CFG1);
value = tegra_mipi_readl(device->mipi, MIPI_CAL_BIAS_PAD_CFG2);
value &= ~MIPI_CAL_BIAS_PAD_PDVREG;
tegra_mipi_writel(device->mipi, value, MIPI_CAL_BIAS_PAD_CFG2);
for (i = 0; i < soc->num_pads; i++) {
u32 clk = 0, data = 0;
if (device->pads & BIT(i)) {
data = MIPI_CAL_CONFIG_SELECT |
MIPI_CAL_CONFIG_HSPDOS(0) |
MIPI_CAL_CONFIG_HSPUOS(4) |
MIPI_CAL_CONFIG_TERMOS(5);
clk = MIPI_CAL_CONFIG_SELECT |
MIPI_CAL_CONFIG_HSCLKPDOSD(0) |
MIPI_CAL_CONFIG_HSCLKPUOSD(4);
}
tegra_mipi_writel(device->mipi, data, soc->pads[i].data);
if (soc->has_clk_lane)
tegra_mipi_writel(device->mipi, clk, soc->pads[i].clk);
}
value = tegra_mipi_readl(device->mipi, MIPI_CAL_CTRL);
value |= MIPI_CAL_CTRL_START;
tegra_mipi_writel(device->mipi, value, MIPI_CAL_CTRL);
err = tegra_mipi_wait(device->mipi);
mutex_unlock(&device->mipi->lock);
clk_disable(device->mipi->clk);
return err;
}
static int tegra_mipi_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct tegra_mipi *mipi;
struct resource *res;
int err;
match = of_match_node(tegra_mipi_of_match, pdev->dev.of_node);
if (!match)
return -ENODEV;
mipi = devm_kzalloc(&pdev->dev, sizeof(*mipi), GFP_KERNEL);
if (!mipi)
return -ENOMEM;
mipi->soc = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mipi->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mipi->regs))
return PTR_ERR(mipi->regs);
mutex_init(&mipi->lock);
mipi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(mipi->clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(mipi->clk);
}
err = clk_prepare(mipi->clk);
if (err < 0)
return err;
platform_set_drvdata(pdev, mipi);
return 0;
}
static int tegra_mipi_remove(struct platform_device *pdev)
{
struct tegra_mipi *mipi = platform_get_drvdata(pdev);
clk_unprepare(mipi->clk);
return 0;
}
