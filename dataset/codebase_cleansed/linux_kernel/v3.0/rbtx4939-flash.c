static int rbtx4939_flash_remove(struct platform_device *dev)
{
struct rbtx4939_flash_info *info;
info = platform_get_drvdata(dev);
if (!info)
return 0;
platform_set_drvdata(dev, NULL);
if (info->mtd) {
struct rbtx4939_flash_data *pdata = dev->dev.platform_data;
if (info->nr_parts)
kfree(info->parts);
mtd_device_unregister(info->mtd);
map_destroy(info->mtd);
}
return 0;
}
static int rbtx4939_flash_probe(struct platform_device *dev)
{
struct rbtx4939_flash_data *pdata;
struct rbtx4939_flash_info *info;
struct resource *res;
const char **probe_type;
int err = 0;
unsigned long size;
pdata = dev->dev.platform_data;
if (!pdata)
return -ENODEV;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
info = devm_kzalloc(&dev->dev, sizeof(struct rbtx4939_flash_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
platform_set_drvdata(dev, info);
size = resource_size(res);
pr_notice("rbtx4939 platform flash device: %pR\n", res);
if (!devm_request_mem_region(&dev->dev, res->start, size,
dev_name(&dev->dev)))
return -EBUSY;
info->map.name = dev_name(&dev->dev);
info->map.phys = res->start;
info->map.size = size;
info->map.bankwidth = pdata->width;
info->map.virt = devm_ioremap(&dev->dev, info->map.phys, size);
if (!info->map.virt)
return -EBUSY;
if (pdata->map_init)
(*pdata->map_init)(&info->map);
else
simple_map_init(&info->map);
probe_type = rom_probe_types;
for (; !info->mtd && *probe_type; probe_type++)
info->mtd = do_map_probe(*probe_type, &info->map);
if (!info->mtd) {
dev_err(&dev->dev, "map_probe failed\n");
err = -ENXIO;
goto err_out;
}
info->mtd->owner = THIS_MODULE;
if (err)
goto err_out;
err = parse_mtd_partitions(info->mtd, part_probe_types,
&info->parts, 0);
if (err > 0) {
mtd_device_register(info->mtd, info->parts, err);
info->nr_parts = err;
return 0;
}
if (pdata->nr_parts) {
pr_notice("Using rbtx4939 partition information\n");
mtd_device_register(info->mtd, pdata->parts, pdata->nr_parts);
return 0;
}
mtd_device_register(info->mtd, NULL, 0);
return 0;
err_out:
rbtx4939_flash_remove(dev);
return err;
}
static void rbtx4939_flash_shutdown(struct platform_device *dev)
{
struct rbtx4939_flash_info *info = platform_get_drvdata(dev);
if (info->mtd->suspend && info->mtd->resume)
if (info->mtd->suspend(info->mtd) == 0)
info->mtd->resume(info->mtd);
}
static int __init rbtx4939_flash_init(void)
{
return platform_driver_register(&rbtx4939_flash_driver);
}
static void __exit rbtx4939_flash_exit(void)
{
platform_driver_unregister(&rbtx4939_flash_driver);
}
