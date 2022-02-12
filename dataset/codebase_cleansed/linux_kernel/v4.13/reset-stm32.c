static int stm32_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct stm32_reset_data *data = container_of(rcdev,
struct stm32_reset_data,
rcdev);
int bank = id / BITS_PER_LONG;
int offset = id % BITS_PER_LONG;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&data->lock, flags);
reg = readl(data->membase + (bank * 4));
writel(reg | BIT(offset), data->membase + (bank * 4));
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int stm32_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct stm32_reset_data *data = container_of(rcdev,
struct stm32_reset_data,
rcdev);
int bank = id / BITS_PER_LONG;
int offset = id % BITS_PER_LONG;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&data->lock, flags);
reg = readl(data->membase + (bank * 4));
writel(reg & ~BIT(offset), data->membase + (bank * 4));
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int stm32_reset_probe(struct platform_device *pdev)
{
struct stm32_reset_data *data;
struct resource *res;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->membase))
return PTR_ERR(data->membase);
spin_lock_init(&data->lock);
data->rcdev.owner = THIS_MODULE;
data->rcdev.nr_resets = resource_size(res) * 8;
data->rcdev.ops = &stm32_reset_ops;
data->rcdev.of_node = pdev->dev.of_node;
return devm_reset_controller_register(&pdev->dev, &data->rcdev);
}
