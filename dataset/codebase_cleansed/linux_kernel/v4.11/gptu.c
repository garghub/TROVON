static irqreturn_t timer_irq_handler(int irq, void *priv)
{
int timer = irq - irqres[0].start;
gptu_w32(1 << timer, GPTU_IRNCR);
return IRQ_HANDLED;
}
static void gptu_hwinit(void)
{
gptu_w32(0x00, GPTU_IRNEN);
gptu_w32(0xff, GPTU_IRNCR);
gptu_w32(CLC_RMC | CLC_SUSPEND, GPTU_CLC);
}
static void gptu_hwexit(void)
{
gptu_w32(0x00, GPTU_IRNEN);
gptu_w32(0xff, GPTU_IRNCR);
gptu_w32(CLC_DISABLE, GPTU_CLC);
}
static int gptu_enable(struct clk *clk)
{
int ret = request_irq(irqres[clk->bits].start, timer_irq_handler,
IRQF_TIMER, "gtpu", NULL);
if (ret) {
pr_err("gptu: failed to request irq\n");
return ret;
}
gptu_w32(CON_CNT | CON_EDGE_ANY | CON_SYNC | CON_CLK_INT,
GPTU_CON(clk->bits));
gptu_w32(1, GPTU_RLD(clk->bits));
gptu_w32(gptu_r32(GPTU_IRNEN) | BIT(clk->bits), GPTU_IRNEN);
gptu_w32(RUN_SEN | RUN_RL, GPTU_RUN(clk->bits));
return 0;
}
static void gptu_disable(struct clk *clk)
{
gptu_w32(0, GPTU_RUN(clk->bits));
gptu_w32(0, GPTU_CON(clk->bits));
gptu_w32(0, GPTU_RLD(clk->bits));
gptu_w32(gptu_r32(GPTU_IRNEN) & ~BIT(clk->bits), GPTU_IRNEN);
free_irq(irqres[clk->bits].start, NULL);
}
static inline void clkdev_add_gptu(struct device *dev, const char *con,
unsigned int timer)
{
struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
clk->cl.dev_id = dev_name(dev);
clk->cl.con_id = con;
clk->cl.clk = clk;
clk->enable = gptu_enable;
clk->disable = gptu_disable;
clk->bits = timer;
clkdev_add(&clk->cl);
}
static int gptu_probe(struct platform_device *pdev)
{
struct clk *clk;
struct resource *res;
if (of_irq_to_resource_table(pdev->dev.of_node, irqres, 6) != 6) {
dev_err(&pdev->dev, "Failed to get IRQ list\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gptu_membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(gptu_membase))
return PTR_ERR(gptu_membase);
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Failed to get clock\n");
return -ENOENT;
}
clk_enable(clk);
gptu_hwinit();
if (((gptu_r32(GPTU_ID) >> 8) & 0xff) != GPTU_MAGIC) {
dev_err(&pdev->dev, "Failed to find magic\n");
gptu_hwexit();
clk_disable(clk);
clk_put(clk);
return -ENAVAIL;
}
clkdev_add_gptu(&pdev->dev, "timer1a", TIMER1A);
clkdev_add_gptu(&pdev->dev, "timer1b", TIMER1B);
clkdev_add_gptu(&pdev->dev, "timer2a", TIMER2A);
clkdev_add_gptu(&pdev->dev, "timer2b", TIMER2B);
clkdev_add_gptu(&pdev->dev, "timer3a", TIMER3A);
clkdev_add_gptu(&pdev->dev, "timer3b", TIMER3B);
dev_info(&pdev->dev, "gptu: 6 timers loaded\n");
return 0;
}
int __init gptu_init(void)
{
int ret = platform_driver_register(&dma_driver);
if (ret)
pr_info("gptu: Error registering platform driver\n");
return ret;
}
