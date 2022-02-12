static int denali_dt_probe(struct platform_device *ofdev)
{
struct resource *denali_reg, *nand_data;
struct denali_dt *dt;
struct denali_nand_info *denali;
int ret;
const struct of_device_id *of_id;
of_id = of_match_device(denali_nand_dt_ids, &ofdev->dev);
if (of_id) {
ofdev->id_entry = of_id->data;
} else {
pr_err("Failed to find the right device id.\n");
return -ENOMEM;
}
dt = devm_kzalloc(&ofdev->dev, sizeof(*dt), GFP_KERNEL);
if (!dt)
return -ENOMEM;
denali = &dt->denali;
denali->platform = DT;
denali->dev = &ofdev->dev;
denali->irq = platform_get_irq(ofdev, 0);
if (denali->irq < 0) {
dev_err(&ofdev->dev, "no irq defined\n");
return denali->irq;
}
denali_reg = platform_get_resource_byname(ofdev, IORESOURCE_MEM, "denali_reg");
denali->flash_reg = devm_ioremap_resource(&ofdev->dev, denali_reg);
if (IS_ERR(denali->flash_reg))
return PTR_ERR(denali->flash_reg);
nand_data = platform_get_resource_byname(ofdev, IORESOURCE_MEM, "nand_data");
denali->flash_mem = devm_ioremap_resource(&ofdev->dev, nand_data);
if (IS_ERR(denali->flash_mem))
return PTR_ERR(denali->flash_mem);
if (!of_property_read_u32(ofdev->dev.of_node,
"dma-mask", (u32 *)&denali_dma_mask)) {
denali->dev->dma_mask = &denali_dma_mask;
} else {
denali->dev->dma_mask = NULL;
}
dt->clk = devm_clk_get(&ofdev->dev, NULL);
if (IS_ERR(dt->clk)) {
dev_err(&ofdev->dev, "no clk available\n");
return PTR_ERR(dt->clk);
}
clk_prepare_enable(dt->clk);
ret = denali_init(denali);
if (ret)
goto out_disable_clk;
platform_set_drvdata(ofdev, dt);
return 0;
out_disable_clk:
clk_disable_unprepare(dt->clk);
return ret;
}
static int denali_dt_remove(struct platform_device *ofdev)
{
struct denali_dt *dt = platform_get_drvdata(ofdev);
denali_remove(&dt->denali);
clk_disable_unprepare(dt->clk);
return 0;
}
