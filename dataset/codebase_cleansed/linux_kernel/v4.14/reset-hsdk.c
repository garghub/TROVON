static void hsdk_reset_config(struct hsdk_rst *rst, unsigned long id)
{
writel(rst_map[id], rst->regs_ctl + CGU_SYS_RST_CTRL);
}
static int hsdk_reset_do(struct hsdk_rst *rst)
{
u32 reg;
reg = readl(rst->regs_rst + CGU_IP_SW_RESET);
reg &= ~CGU_IP_SW_RESET_DELAY_MASK;
reg |= CGU_IP_SW_RESET_DELAY << CGU_IP_SW_RESET_DELAY_SHIFT;
reg |= CGU_IP_SW_RESET_RESET;
writel(reg, rst->regs_rst + CGU_IP_SW_RESET);
return readl_poll_timeout_atomic(rst->regs_rst + CGU_IP_SW_RESET, reg,
!(reg & CGU_IP_SW_RESET_RESET), 5, SW_RESET_TIMEOUT);
}
static int hsdk_reset_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct hsdk_rst *rst = to_hsdk_rst(rcdev);
unsigned long flags;
int ret;
spin_lock_irqsave(&rst->lock, flags);
hsdk_reset_config(rst, id);
ret = hsdk_reset_do(rst);
spin_unlock_irqrestore(&rst->lock, flags);
return ret;
}
static int hsdk_reset_probe(struct platform_device *pdev)
{
struct hsdk_rst *rst;
struct resource *mem;
rst = devm_kzalloc(&pdev->dev, sizeof(*rst), GFP_KERNEL);
if (!rst)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rst->regs_ctl = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rst->regs_ctl))
return PTR_ERR(rst->regs_ctl);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
rst->regs_rst = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rst->regs_rst))
return PTR_ERR(rst->regs_rst);
spin_lock_init(&rst->lock);
rst->rcdev.owner = THIS_MODULE;
rst->rcdev.ops = &hsdk_reset_ops;
rst->rcdev.of_node = pdev->dev.of_node;
rst->rcdev.nr_resets = HSDK_MAX_RESETS;
rst->rcdev.of_reset_n_cells = 1;
return reset_controller_register(&rst->rcdev);
}
