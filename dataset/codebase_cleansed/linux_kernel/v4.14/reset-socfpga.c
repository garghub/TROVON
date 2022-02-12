static int socfpga_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct socfpga_reset_data *data = container_of(rcdev,
struct socfpga_reset_data,
rcdev);
int reg_width = sizeof(u32);
int bank = id / (reg_width * BITS_PER_BYTE);
int offset = id % (reg_width * BITS_PER_BYTE);
unsigned long flags;
u32 reg;
spin_lock_irqsave(&data->lock, flags);
reg = readl(data->membase + (bank * BANK_INCREMENT));
writel(reg | BIT(offset), data->membase + (bank * BANK_INCREMENT));
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int socfpga_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct socfpga_reset_data *data = container_of(rcdev,
struct socfpga_reset_data,
rcdev);
int reg_width = sizeof(u32);
int bank = id / (reg_width * BITS_PER_BYTE);
int offset = id % (reg_width * BITS_PER_BYTE);
unsigned long flags;
u32 reg;
spin_lock_irqsave(&data->lock, flags);
reg = readl(data->membase + (bank * BANK_INCREMENT));
writel(reg & ~BIT(offset), data->membase + (bank * BANK_INCREMENT));
spin_unlock_irqrestore(&data->lock, flags);
return 0;
}
static int socfpga_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct socfpga_reset_data *data = container_of(rcdev,
struct socfpga_reset_data, rcdev);
int reg_width = sizeof(u32);
int bank = id / (reg_width * BITS_PER_BYTE);
int offset = id % (reg_width * BITS_PER_BYTE);
u32 reg;
reg = readl(data->membase + (bank * BANK_INCREMENT));
return !(reg & BIT(offset));
}
static int socfpga_reset_probe(struct platform_device *pdev)
{
struct socfpga_reset_data *data;
struct resource *res;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
u32 modrst_offset;
if (!of_find_property(pdev->dev.of_node, "#reset-cells", NULL)) {
dev_err(&pdev->dev, "%pOF missing #reset-cells property\n",
pdev->dev.of_node);
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->membase))
return PTR_ERR(data->membase);
if (of_property_read_u32(np, "altr,modrst-offset", &modrst_offset)) {
dev_warn(dev, "missing altr,modrst-offset property, assuming 0x10!\n");
modrst_offset = 0x10;
}
data->membase += modrst_offset;
spin_lock_init(&data->lock);
data->rcdev.owner = THIS_MODULE;
data->rcdev.nr_resets = NR_BANKS * (sizeof(u32) * BITS_PER_BYTE);
data->rcdev.ops = &socfpga_reset_ops;
data->rcdev.of_node = pdev->dev.of_node;
return devm_reset_controller_register(dev, &data->rcdev);
}
