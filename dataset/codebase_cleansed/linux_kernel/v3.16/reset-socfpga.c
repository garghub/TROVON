static int socfpga_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct socfpga_reset_data *data = container_of(rcdev,
struct socfpga_reset_data,
rcdev);
int bank = id / BITS_PER_LONG;
int offset = id % BITS_PER_LONG;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&data->lock, flags);
reg = readl(data->membase + OFFSET_MODRST + (bank * NR_BANKS));
writel(reg | BIT(offset), data->membase + OFFSET_MODRST +
(bank * NR_BANKS));
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int socfpga_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct socfpga_reset_data *data = container_of(rcdev,
struct socfpga_reset_data,
rcdev);
int bank = id / BITS_PER_LONG;
int offset = id % BITS_PER_LONG;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&data->lock, flags);
reg = readl(data->membase + OFFSET_MODRST + (bank * NR_BANKS));
writel(reg & ~BIT(offset), data->membase + OFFSET_MODRST +
(bank * NR_BANKS));
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int socfpga_reset_probe(struct platform_device *pdev)
{
struct socfpga_reset_data *data;
struct resource *res;
if (!of_find_property(pdev->dev.of_node, "#reset-cells", NULL)) {
dev_err(&pdev->dev, "%s missing #reset-cells property\n",
pdev->dev.of_node->full_name);
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->membase))
return PTR_ERR(data->membase);
spin_lock_init(&data->lock);
data->rcdev.owner = THIS_MODULE;
data->rcdev.nr_resets = NR_BANKS * BITS_PER_LONG;
data->rcdev.ops = &socfpga_reset_ops;
data->rcdev.of_node = pdev->dev.of_node;
reset_controller_register(&data->rcdev);
return 0;
}
static int socfpga_reset_remove(struct platform_device *pdev)
{
struct socfpga_reset_data *data = platform_get_drvdata(pdev);
reset_controller_unregister(&data->rcdev);
return 0;
}
