static int ad7606_par16_read_block(struct device *dev,
int count, void *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct ad7606_state *st = iio_priv(indio_dev);
insw((unsigned long)st->base_address, buf, count);
return 0;
}
static int ad7606_par8_read_block(struct device *dev,
int count, void *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct ad7606_state *st = iio_priv(indio_dev);
insb((unsigned long)st->base_address, buf, count * 2);
return 0;
}
static int ad7606_par_probe(struct platform_device *pdev)
{
struct resource *res;
struct iio_dev *indio_dev;
void __iomem *addr;
resource_size_t remap_size;
int irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(addr))
return PTR_ERR(addr);
remap_size = resource_size(res);
indio_dev = ad7606_probe(&pdev->dev, irq, addr,
platform_get_device_id(pdev)->driver_data,
remap_size > 1 ? &ad7606_par16_bops :
&ad7606_par8_bops);
if (IS_ERR(indio_dev))
return PTR_ERR(indio_dev);
platform_set_drvdata(pdev, indio_dev);
return 0;
}
static int ad7606_par_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
ad7606_remove(indio_dev, platform_get_irq(pdev, 0));
return 0;
}
