static int denali_dt_probe(struct platform_device *pdev)
{
struct resource *res;
struct denali_dt *dt;
const struct denali_dt_data *data;
struct denali_nand_info *denali;
int ret;
dt = devm_kzalloc(&pdev->dev, sizeof(*dt), GFP_KERNEL);
if (!dt)
return -ENOMEM;
denali = &dt->denali;
data = of_device_get_match_data(&pdev->dev);
if (data) {
denali->revision = data->revision;
denali->caps = data->caps;
denali->ecc_caps = data->ecc_caps;
}
denali->dev = &pdev->dev;
denali->irq = platform_get_irq(pdev, 0);
if (denali->irq < 0) {
dev_err(&pdev->dev, "no irq defined\n");
return denali->irq;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "denali_reg");
denali->reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(denali->reg))
return PTR_ERR(denali->reg);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_data");
denali->host = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(denali->host))
return PTR_ERR(denali->host);
dt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dt->clk)) {
dev_err(&pdev->dev, "no clk available\n");
return PTR_ERR(dt->clk);
}
ret = clk_prepare_enable(dt->clk);
if (ret)
return ret;
denali->clk_x_rate = clk_get_rate(dt->clk);
ret = denali_init(denali);
if (ret)
goto out_disable_clk;
platform_set_drvdata(pdev, dt);
return 0;
out_disable_clk:
clk_disable_unprepare(dt->clk);
return ret;
}
static int denali_dt_remove(struct platform_device *pdev)
{
struct denali_dt *dt = platform_get_drvdata(pdev);
denali_remove(&dt->denali);
clk_disable_unprepare(dt->clk);
return 0;
}
