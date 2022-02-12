static int intel_spi_platform_probe(struct platform_device *pdev)
{
struct intel_spi_boardinfo *info;
struct intel_spi *ispi;
struct resource *mem;
info = dev_get_platdata(&pdev->dev);
if (!info)
return -EINVAL;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ispi = intel_spi_probe(&pdev->dev, mem, info);
if (IS_ERR(ispi))
return PTR_ERR(ispi);
platform_set_drvdata(pdev, ispi);
return 0;
}
static int intel_spi_platform_remove(struct platform_device *pdev)
{
struct intel_spi *ispi = platform_get_drvdata(pdev);
return intel_spi_remove(ispi);
}
