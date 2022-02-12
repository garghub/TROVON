struct atmel_tc *atmel_tc_alloc(unsigned block)
{
struct atmel_tc *tc;
struct platform_device *pdev = NULL;
spin_lock(&tc_list_lock);
list_for_each_entry(tc, &tc_list, node) {
if (tc->allocated)
continue;
if ((tc->pdev->dev.of_node && tc->id == block) ||
(tc->pdev->id == block)) {
pdev = tc->pdev;
tc->allocated = true;
break;
}
}
spin_unlock(&tc_list_lock);
return pdev ? tc : NULL;
}
void atmel_tc_free(struct atmel_tc *tc)
{
spin_lock(&tc_list_lock);
if (tc->allocated)
tc->allocated = false;
spin_unlock(&tc_list_lock);
}
static int __init tc_probe(struct platform_device *pdev)
{
struct atmel_tc *tc;
struct clk *clk;
int irq;
struct resource *r;
unsigned int i;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -EINVAL;
tc = devm_kzalloc(&pdev->dev, sizeof(struct atmel_tc), GFP_KERNEL);
if (!tc)
return -ENOMEM;
tc->pdev = pdev;
clk = devm_clk_get(&pdev->dev, "t0_clk");
if (IS_ERR(clk))
return PTR_ERR(clk);
tc->slow_clk = devm_clk_get(&pdev->dev, "slow_clk");
if (IS_ERR(tc->slow_clk))
return PTR_ERR(tc->slow_clk);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tc->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(tc->regs))
return PTR_ERR(tc->regs);
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(atmel_tcb_dt_ids, pdev->dev.of_node);
if (match)
tc->tcb_config = match->data;
tc->id = of_alias_get_id(tc->pdev->dev.of_node, "tcb");
} else {
tc->id = pdev->id;
}
tc->clk[0] = clk;
tc->clk[1] = devm_clk_get(&pdev->dev, "t1_clk");
if (IS_ERR(tc->clk[1]))
tc->clk[1] = clk;
tc->clk[2] = devm_clk_get(&pdev->dev, "t2_clk");
if (IS_ERR(tc->clk[2]))
tc->clk[2] = clk;
tc->irq[0] = irq;
tc->irq[1] = platform_get_irq(pdev, 1);
if (tc->irq[1] < 0)
tc->irq[1] = irq;
tc->irq[2] = platform_get_irq(pdev, 2);
if (tc->irq[2] < 0)
tc->irq[2] = irq;
for (i = 0; i < 3; i++)
writel(ATMEL_TC_ALL_IRQ, tc->regs + ATMEL_TC_REG(i, IDR));
spin_lock(&tc_list_lock);
list_add_tail(&tc->node, &tc_list);
spin_unlock(&tc_list_lock);
platform_set_drvdata(pdev, tc);
return 0;
}
static void tc_shutdown(struct platform_device *pdev)
{
int i;
struct atmel_tc *tc = platform_get_drvdata(pdev);
for (i = 0; i < 3; i++)
writel(ATMEL_TC_ALL_IRQ, tc->regs + ATMEL_TC_REG(i, IDR));
}
static int __init tc_init(void)
{
return platform_driver_probe(&tc_driver, tc_probe);
}
