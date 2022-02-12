static int qfprom_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
static int qfprom_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct nvmem_device *nvmem;
struct regmap *regmap;
void __iomem *base;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
qfprom_regmap_config.max_register = resource_size(res) - 1;
regmap = devm_regmap_init_mmio(dev, base, &qfprom_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(regmap);
}
econfig.dev = dev;
nvmem = nvmem_register(&econfig);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
