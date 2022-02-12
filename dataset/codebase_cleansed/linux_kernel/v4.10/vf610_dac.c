static void vf610_dac_init(struct vf610_dac *info)
{
int val;
info->conv_mode = VF610_DAC_CONV_LOW_POWER;
val = VF610_DAC_DACEN | VF610_DAC_DACRFS |
VF610_DAC_LPEN;
writel(val, info->regs + VF610_DACx_STATCTRL);
}
static void vf610_dac_exit(struct vf610_dac *info)
{
int val;
val = readl(info->regs + VF610_DACx_STATCTRL);
val &= ~VF610_DAC_DACEN;
writel(val, info->regs + VF610_DACx_STATCTRL);
}
static int vf610_set_conversion_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct vf610_dac *info = iio_priv(indio_dev);
int val;
mutex_lock(&indio_dev->mlock);
info->conv_mode = mode;
val = readl(info->regs + VF610_DACx_STATCTRL);
if (mode)
val |= VF610_DAC_LPEN;
else
val &= ~VF610_DAC_LPEN;
writel(val, info->regs + VF610_DACx_STATCTRL);
mutex_unlock(&indio_dev->mlock);
return 0;
}
static int vf610_get_conversion_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct vf610_dac *info = iio_priv(indio_dev);
return info->conv_mode;
}
static int vf610_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct vf610_dac *info = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
*val = VF610_DAC_DAT0(readl(info->regs));
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 3300 ;
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static int vf610_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2,
long mask)
{
struct vf610_dac *info = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
writel(VF610_DAC_DAT0(val), info->regs);
mutex_unlock(&indio_dev->mlock);
return 0;
default:
return -EINVAL;
}
}
static int vf610_dac_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct vf610_dac *info;
struct resource *mem;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev,
sizeof(struct vf610_dac));
if (!indio_dev) {
dev_err(&pdev->dev, "Failed allocating iio device\n");
return -ENOMEM;
}
info = iio_priv(indio_dev);
info->dev = &pdev->dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
info->clk = devm_clk_get(&pdev->dev, "dac");
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "Failed getting clock, err = %ld\n",
PTR_ERR(info->clk));
return PTR_ERR(info->clk);
}
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &vf610_dac_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = vf610_dac_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(vf610_dac_iio_channels);
ret = clk_prepare_enable(info->clk);
if (ret) {
dev_err(&pdev->dev,
"Could not prepare or enable the clock\n");
return ret;
}
vf610_dac_init(info);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "Couldn't register the device\n");
goto error_iio_device_register;
}
return 0;
error_iio_device_register:
clk_disable_unprepare(info->clk);
return ret;
}
static int vf610_dac_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct vf610_dac *info = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
vf610_dac_exit(info);
clk_disable_unprepare(info->clk);
return 0;
}
static int vf610_dac_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct vf610_dac *info = iio_priv(indio_dev);
vf610_dac_exit(info);
clk_disable_unprepare(info->clk);
return 0;
}
static int vf610_dac_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct vf610_dac *info = iio_priv(indio_dev);
int ret;
ret = clk_prepare_enable(info->clk);
if (ret)
return ret;
vf610_dac_init(info);
return 0;
}
