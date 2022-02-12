static irqreturn_t jz4740_hwmon_irq(int irq, void *data)
{
struct jz4740_hwmon *hwmon = data;
complete(&hwmon->read_completion);
return IRQ_HANDLED;
}
static ssize_t in0_input_show(struct device *dev,
struct device_attribute *dev_attr, char *buf)
{
struct jz4740_hwmon *hwmon = dev_get_drvdata(dev);
struct platform_device *pdev = hwmon->pdev;
struct completion *completion = &hwmon->read_completion;
long t;
unsigned long val;
int ret;
mutex_lock(&hwmon->lock);
reinit_completion(completion);
enable_irq(hwmon->irq);
hwmon->cell->enable(pdev);
t = wait_for_completion_interruptible_timeout(completion, HZ);
if (t > 0) {
val = readw(hwmon->base) & 0xfff;
val = (val * 3300) >> 12;
ret = sprintf(buf, "%lu\n", val);
} else {
ret = t ? t : -ETIMEDOUT;
}
hwmon->cell->disable(pdev);
disable_irq(hwmon->irq);
mutex_unlock(&hwmon->lock);
return ret;
}
static int jz4740_hwmon_probe(struct platform_device *pdev)
{
int ret;
struct device *dev = &pdev->dev;
struct jz4740_hwmon *hwmon;
struct device *hwmon_dev;
struct resource *mem;
hwmon = devm_kzalloc(dev, sizeof(*hwmon), GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
hwmon->cell = mfd_get_cell(pdev);
hwmon->irq = platform_get_irq(pdev, 0);
if (hwmon->irq < 0) {
dev_err(&pdev->dev, "Failed to get platform irq: %d\n",
hwmon->irq);
return hwmon->irq;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hwmon->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(hwmon->base))
return PTR_ERR(hwmon->base);
hwmon->pdev = pdev;
init_completion(&hwmon->read_completion);
mutex_init(&hwmon->lock);
ret = devm_request_irq(dev, hwmon->irq, jz4740_hwmon_irq, 0,
pdev->name, hwmon);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq: %d\n", ret);
return ret;
}
disable_irq(hwmon->irq);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, "jz4740", hwmon,
jz4740_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
