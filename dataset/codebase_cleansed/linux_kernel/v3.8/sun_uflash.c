int uflash_devinit(struct platform_device *op, struct device_node *dp)
{
struct uflash_dev *up;
if (op->resource[1].flags) {
printk(KERN_ERR PFX "Unsupported device at %s, 0x%llx\n",
dp->full_name, (unsigned long long)op->resource[0].start);
return -ENODEV;
}
up = kzalloc(sizeof(struct uflash_dev), GFP_KERNEL);
if (!up) {
printk(KERN_ERR PFX "Cannot allocate struct uflash_dev\n");
return -ENOMEM;
}
memcpy(&up->map, &uflash_map_templ, sizeof(uflash_map_templ));
up->map.size = resource_size(&op->resource[0]);
up->name = of_get_property(dp, "model", NULL);
if (up->name && 0 < strlen(up->name))
up->map.name = (char *)up->name;
up->map.phys = op->resource[0].start;
up->map.virt = of_ioremap(&op->resource[0], 0, up->map.size,
DRIVER_NAME);
if (!up->map.virt) {
printk(KERN_ERR PFX "Failed to map device.\n");
kfree(up);
return -EINVAL;
}
simple_map_init(&up->map);
up->mtd = do_map_probe("cfi_probe", &up->map);
if (!up->mtd) {
of_iounmap(&op->resource[0], up->map.virt, up->map.size);
kfree(up);
return -ENXIO;
}
up->mtd->owner = THIS_MODULE;
mtd_device_register(up->mtd, NULL, 0);
dev_set_drvdata(&op->dev, up);
return 0;
}
static int uflash_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
if (!of_find_property(dp, "user", NULL))
return -ENODEV;
return uflash_devinit(op, dp);
}
static int uflash_remove(struct platform_device *op)
{
struct uflash_dev *up = dev_get_drvdata(&op->dev);
if (up->mtd) {
mtd_device_unregister(up->mtd);
map_destroy(up->mtd);
}
if (up->map.virt) {
of_iounmap(&op->resource[0], up->map.virt, up->map.size);
up->map.virt = NULL;
}
kfree(up);
return 0;
}
