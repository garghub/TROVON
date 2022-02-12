static int stm32_sai_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct stm32_sai_data *sai;
struct reset_control *rst;
struct resource *res;
void __iomem *base;
const struct of_device_id *of_id;
sai = devm_kzalloc(&pdev->dev, sizeof(*sai), GFP_KERNEL);
if (!sai)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
of_id = of_match_device(stm32_sai_ids, &pdev->dev);
if (of_id)
sai->version = (enum stm32_sai_version)of_id->data;
else
return -EINVAL;
sai->clk_x8k = devm_clk_get(&pdev->dev, "x8k");
if (IS_ERR(sai->clk_x8k)) {
dev_err(&pdev->dev, "missing x8k parent clock\n");
return PTR_ERR(sai->clk_x8k);
}
sai->clk_x11k = devm_clk_get(&pdev->dev, "x11k");
if (IS_ERR(sai->clk_x11k)) {
dev_err(&pdev->dev, "missing x11k parent clock\n");
return PTR_ERR(sai->clk_x11k);
}
sai->irq = platform_get_irq(pdev, 0);
if (sai->irq < 0) {
dev_err(&pdev->dev, "no irq for node %s\n", pdev->name);
return sai->irq;
}
rst = reset_control_get(&pdev->dev, NULL);
if (!IS_ERR(rst)) {
reset_control_assert(rst);
udelay(2);
reset_control_deassert(rst);
}
sai->pdev = pdev;
platform_set_drvdata(pdev, sai);
return of_platform_populate(np, NULL, NULL, &pdev->dev);
}
static int stm32_sai_remove(struct platform_device *pdev)
{
of_platform_depopulate(&pdev->dev);
return 0;
}
