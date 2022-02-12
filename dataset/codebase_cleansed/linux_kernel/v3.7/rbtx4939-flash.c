static int rbtx4939_flash_remove(struct platform_device *dev)
{
struct rbtx4939_flash_info *info;
info = platform_get_drvdata(dev);
if (!info)
return 0;
platform_set_drvdata(dev, NULL);
if (info->mtd) {
struct rbtx4939_flash_data *pdata = dev->dev.platform_data;
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
err = mtd_device_parse_register(info->mtd, NULL, NULL, pdata->parts,
pdata->nr_parts);
if (err)
goto err_out;
return 0;
err_out:
rbtx4939_flash_remove(dev);
return err;
}
static void rbtx4939_flash_shutdown(struct platform_device *dev)
{
struct rbtx4939_flash_info *info = platform_get_drvdata(dev);
if (mtd_suspend(info->mtd) == 0)
mtd_resume(info->mtd);
}
