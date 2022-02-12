static int sram_probe(struct platform_device *pdev)
{
void __iomem *virt_base;
struct sram_dev *sram;
struct resource *res;
unsigned long size;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
virt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(virt_base))
return PTR_ERR(virt_base);
size = resource_size(res);
sram = devm_kzalloc(&pdev->dev, sizeof(*sram), GFP_KERNEL);
if (!sram)
return -ENOMEM;
sram->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sram->clk))
sram->clk = NULL;
else
clk_prepare_enable(sram->clk);
sram->pool = devm_gen_pool_create(&pdev->dev, ilog2(SRAM_GRANULARITY), -1);
if (!sram->pool)
return -ENOMEM;
ret = gen_pool_add_virt(sram->pool, (unsigned long)virt_base,
res->start, size, -1);
if (ret < 0) {
if (sram->clk)
clk_disable_unprepare(sram->clk);
return ret;
}
platform_set_drvdata(pdev, sram);
dev_dbg(&pdev->dev, "SRAM pool: %ld KiB @ 0x%p\n", size / 1024, virt_base);
return 0;
}
static int sram_remove(struct platform_device *pdev)
{
struct sram_dev *sram = platform_get_drvdata(pdev);
if (gen_pool_avail(sram->pool) < gen_pool_size(sram->pool))
dev_dbg(&pdev->dev, "removed while SRAM allocated\n");
gen_pool_destroy(sram->pool);
if (sram->clk)
clk_disable_unprepare(sram->clk);
return 0;
}
static int __init sram_init(void)
{
return platform_driver_register(&sram_driver);
}
