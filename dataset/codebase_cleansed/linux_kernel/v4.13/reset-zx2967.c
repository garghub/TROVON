static int zx2967_reset_act(struct reset_controller_dev *rcdev,
unsigned long id, bool assert)
{
struct zx2967_reset *reset = NULL;
int bank = id / 32;
int offset = id % 32;
u32 reg;
unsigned long flags;
reset = container_of(rcdev, struct zx2967_reset, rcdev);
spin_lock_irqsave(&reset->lock, flags);
reg = readl_relaxed(reset->reg_base + (bank * 4));
if (assert)
reg &= ~BIT(offset);
else
reg |= BIT(offset);
writel_relaxed(reg, reset->reg_base + (bank * 4));
spin_unlock_irqrestore(&reset->lock, flags);
return 0;
}
static int zx2967_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return zx2967_reset_act(rcdev, id, true);
}
static int zx2967_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return zx2967_reset_act(rcdev, id, false);
}
static int zx2967_reset_probe(struct platform_device *pdev)
{
struct zx2967_reset *reset;
struct resource *res;
reset = devm_kzalloc(&pdev->dev, sizeof(*reset), GFP_KERNEL);
if (!reset)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reset->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(reset->reg_base))
return PTR_ERR(reset->reg_base);
spin_lock_init(&reset->lock);
reset->rcdev.owner = THIS_MODULE;
reset->rcdev.nr_resets = resource_size(res) * 8;
reset->rcdev.ops = &zx2967_reset_ops;
reset->rcdev.of_node = pdev->dev.of_node;
return devm_reset_controller_register(&pdev->dev, &reset->rcdev);
}
