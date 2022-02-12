static int ad7606_par16_read_block(struct device *dev,
int count, void *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct ad7606_state *st = iio_priv(indio_dev);
insw((unsigned long) st->base_address, buf, count);
return 0;
}
static int ad7606_par8_read_block(struct device *dev,
int count, void *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct ad7606_state *st = iio_priv(indio_dev);
insb((unsigned long) st->base_address, buf, count * 2);
return 0;
}
static int __devinit ad7606_par_probe(struct platform_device *pdev)
{
struct resource *res;
struct iio_dev *indio_dev;
void __iomem *addr;
resource_size_t remap_size;
int ret, irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
remap_size = resource_size(res);
if (!request_mem_region(res->start, remap_size, "iio-ad7606")) {
ret = -EBUSY;
goto out1;
}
addr = ioremap(res->start, remap_size);
if (!addr) {
ret = -ENOMEM;
goto out1;
}
indio_dev = ad7606_probe(&pdev->dev, irq, addr,
platform_get_device_id(pdev)->driver_data,
remap_size > 1 ? &ad7606_par16_bops :
&ad7606_par8_bops);
if (IS_ERR(indio_dev)) {
ret = PTR_ERR(indio_dev);
goto out2;
}
platform_set_drvdata(pdev, indio_dev);
return 0;
out2:
iounmap(addr);
out1:
release_mem_region(res->start, remap_size);
return ret;
}
static int __devexit ad7606_par_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct resource *res;
struct ad7606_state *st = iio_priv(indio_dev);
ad7606_remove(indio_dev, platform_get_irq(pdev, 0));
iounmap(st->base_address);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(pdev, NULL);
return 0;
}
static int ad7606_par_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
ad7606_suspend(indio_dev);
return 0;
}
static int ad7606_par_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
ad7606_resume(indio_dev);
return 0;
}
