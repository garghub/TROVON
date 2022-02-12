static int rockchip_softrst_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct rockchip_softrst *softrst = container_of(rcdev,
struct rockchip_softrst,
rcdev);
int bank = id / softrst->num_per_reg;
int offset = id % softrst->num_per_reg;
if (softrst->flags & ROCKCHIP_SOFTRST_HIWORD_MASK) {
writel(BIT(offset) | (BIT(offset) << 16),
softrst->reg_base + (bank * 4));
} else {
unsigned long flags;
u32 reg;
spin_lock_irqsave(&softrst->lock, flags);
reg = readl(softrst->reg_base + (bank * 4));
writel(reg | BIT(offset), softrst->reg_base + (bank * 4));
spin_unlock_irqrestore(&softrst->lock, flags);
}
return 0;
}
static int rockchip_softrst_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct rockchip_softrst *softrst = container_of(rcdev,
struct rockchip_softrst,
rcdev);
int bank = id / softrst->num_per_reg;
int offset = id % softrst->num_per_reg;
if (softrst->flags & ROCKCHIP_SOFTRST_HIWORD_MASK) {
writel((BIT(offset) << 16), softrst->reg_base + (bank * 4));
} else {
unsigned long flags;
u32 reg;
spin_lock_irqsave(&softrst->lock, flags);
reg = readl(softrst->reg_base + (bank * 4));
writel(reg & ~BIT(offset), softrst->reg_base + (bank * 4));
spin_unlock_irqrestore(&softrst->lock, flags);
}
return 0;
}
void __init rockchip_register_softrst(struct device_node *np,
unsigned int num_regs,
void __iomem *base, u8 flags)
{
struct rockchip_softrst *softrst;
int ret;
softrst = kzalloc(sizeof(*softrst), GFP_KERNEL);
if (!softrst)
return;
spin_lock_init(&softrst->lock);
softrst->reg_base = base;
softrst->flags = flags;
softrst->num_regs = num_regs;
softrst->num_per_reg = (flags & ROCKCHIP_SOFTRST_HIWORD_MASK) ? 16
: 32;
softrst->rcdev.owner = THIS_MODULE;
softrst->rcdev.nr_resets = num_regs * softrst->num_per_reg;
softrst->rcdev.ops = &rockchip_softrst_ops;
softrst->rcdev.of_node = np;
ret = reset_controller_register(&softrst->rcdev);
if (ret) {
pr_err("%s: could not register reset controller, %d\n",
__func__, ret);
kfree(softrst);
}
}
