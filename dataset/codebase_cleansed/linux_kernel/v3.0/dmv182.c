static int __init init_svme182(void)
{
struct mtd_partition *partitions;
int num_parts = ARRAY_SIZE(svme182_partitions);
partitions = svme182_partitions;
svme182_map.virt = ioremap(FLASH_BASE_ADDR, svme182_map.size);
if (svme182_map.virt == 0) {
printk("Failed to ioremap FLASH memory area.\n");
return -EIO;
}
simple_map_init(&svme182_map);
this_mtd = do_map_probe("cfi_probe", &svme182_map);
if (!this_mtd)
{
iounmap((void *)svme182_map.virt);
return -ENXIO;
}
printk(KERN_NOTICE "SVME182 flash device: %dMiB at 0x%08x\n",
this_mtd->size >> 20, FLASH_BASE_ADDR);
this_mtd->owner = THIS_MODULE;
mtd_device_register(this_mtd, partitions, num_parts);
return 0;
}
static void __exit cleanup_svme182(void)
{
if (this_mtd)
{
mtd_device_unregister(this_mtd);
map_destroy(this_mtd);
}
if (svme182_map.virt)
{
iounmap((void *)svme182_map.virt);
svme182_map.virt = 0;
}
return;
}
