static int dw_spi_mmio_probe(struct platform_device *pdev)
{
struct dw_spi_mmio *dwsmmio;
struct dw_spi *dws;
struct resource *mem, *ioarea;
int ret;
dwsmmio = kzalloc(sizeof(struct dw_spi_mmio), GFP_KERNEL);
if (!dwsmmio) {
ret = -ENOMEM;
goto err_end;
}
dws = &dwsmmio->dws;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
ret = -EINVAL;
goto err_kfree;
}
ioarea = request_mem_region(mem->start, resource_size(mem),
pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "SPI region already claimed\n");
ret = -EBUSY;
goto err_kfree;
}
dws->regs = ioremap_nocache(mem->start, resource_size(mem));
if (!dws->regs) {
dev_err(&pdev->dev, "SPI region already mapped\n");
ret = -ENOMEM;
goto err_release_reg;
}
dws->irq = platform_get_irq(pdev, 0);
if (dws->irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
ret = dws->irq;
goto err_unmap;
}
dwsmmio->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dwsmmio->clk)) {
ret = PTR_ERR(dwsmmio->clk);
goto err_unmap;
}
clk_enable(dwsmmio->clk);
dws->parent_dev = &pdev->dev;
dws->bus_num = 0;
dws->num_cs = 4;
dws->max_freq = clk_get_rate(dwsmmio->clk);
ret = dw_spi_add_host(dws);
if (ret)
goto err_clk;
platform_set_drvdata(pdev, dwsmmio);
return 0;
err_clk:
clk_disable(dwsmmio->clk);
clk_put(dwsmmio->clk);
dwsmmio->clk = NULL;
err_unmap:
iounmap(dws->regs);
err_release_reg:
release_mem_region(mem->start, resource_size(mem));
err_kfree:
kfree(dwsmmio);
err_end:
return ret;
}
static int dw_spi_mmio_remove(struct platform_device *pdev)
{
struct dw_spi_mmio *dwsmmio = platform_get_drvdata(pdev);
struct resource *mem;
clk_disable(dwsmmio->clk);
clk_put(dwsmmio->clk);
dwsmmio->clk = NULL;
dw_spi_remove_host(&dwsmmio->dws);
iounmap(dwsmmio->dws.regs);
kfree(dwsmmio);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
return 0;
}
