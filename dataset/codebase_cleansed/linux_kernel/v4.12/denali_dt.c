static int denali_dt_probe(struct platform_device *pdev)
{
struct resource *denali_reg, *nand_data;
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
}
denali->platform = DT;
denali->dev = &pdev->dev;
denali->irq = platform_get_irq(pdev, 0);
if (denali->irq < 0) {
dev_err(&pdev->dev, "no irq defined\n");
return denali->irq;
}
denali_reg = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"denali_reg");
denali->flash_reg = devm_ioremap_resource(&pdev->dev, denali_reg);
if (IS_ERR(denali->flash_reg))
return PTR_ERR(denali->flash_reg);
nand_data = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"nand_data");
denali->flash_mem = devm_ioremap_resource(&pdev->dev, nand_data);
if (IS_ERR(denali->flash_mem))
return PTR_ERR(denali->flash_mem);
dt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dt->clk)) {
dev_err(&pdev->dev, "no clk available\n");
return PTR_ERR(dt->clk);
}
clk_prepare_enable(dt->clk);
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
