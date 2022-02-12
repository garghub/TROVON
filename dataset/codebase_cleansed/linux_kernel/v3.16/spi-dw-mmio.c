static int dw_spi_mmio_probe(struct platform_device *pdev)
{
struct dw_spi_mmio *dwsmmio;
struct dw_spi *dws;
struct resource *mem;
int ret;
dwsmmio = devm_kzalloc(&pdev->dev, sizeof(struct dw_spi_mmio),
GFP_KERNEL);
if (!dwsmmio)
return -ENOMEM;
dws = &dwsmmio->dws;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -EINVAL;
}
dws->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dws->regs)) {
dev_err(&pdev->dev, "SPI region map failed\n");
return PTR_ERR(dws->regs);
}
dws->irq = platform_get_irq(pdev, 0);
if (dws->irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return dws->irq;
}
dwsmmio->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dwsmmio->clk))
return PTR_ERR(dwsmmio->clk);
ret = clk_prepare_enable(dwsmmio->clk);
if (ret)
return ret;
dws->bus_num = pdev->id;
dws->num_cs = 4;
dws->max_freq = clk_get_rate(dwsmmio->clk);
if (pdev->dev.of_node) {
int i;
for (i = 0; i < dws->num_cs; i++) {
int cs_gpio = of_get_named_gpio(pdev->dev.of_node,
"cs-gpios", i);
if (cs_gpio == -EPROBE_DEFER) {
ret = cs_gpio;
goto out;
}
if (gpio_is_valid(cs_gpio)) {
ret = devm_gpio_request(&pdev->dev, cs_gpio,
dev_name(&pdev->dev));
if (ret)
goto out;
}
}
}
ret = dw_spi_add_host(&pdev->dev, dws);
if (ret)
goto out;
platform_set_drvdata(pdev, dwsmmio);
return 0;
out:
clk_disable_unprepare(dwsmmio->clk);
return ret;
}
static int dw_spi_mmio_remove(struct platform_device *pdev)
{
struct dw_spi_mmio *dwsmmio = platform_get_drvdata(pdev);
clk_disable_unprepare(dwsmmio->clk);
dw_spi_remove_host(&dwsmmio->dws);
return 0;
}
