static int __init init_dbox2_flash(void)
{
printk(KERN_NOTICE "D-Box 2 flash driver (size->0x%X mem->0x%X)\n", WINDOW_SIZE, WINDOW_ADDR);
dbox2_flash_map.virt = ioremap(WINDOW_ADDR, WINDOW_SIZE);
if (!dbox2_flash_map.virt) {
printk("Failed to ioremap\n");
return -EIO;
}
simple_map_init(&dbox2_flash_map);
mymtd = do_map_probe("cfi_probe", &dbox2_flash_map);
if (!mymtd) {
dbox2_flash_map.bankwidth = 2;
mymtd = do_map_probe("cfi_probe", &dbox2_flash_map);
}
if (mymtd) {
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, partition_info, NUM_PARTITIONS);
return 0;
}
iounmap((void *)dbox2_flash_map.virt);
return -ENXIO;
}
static void __exit cleanup_dbox2_flash(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (dbox2_flash_map.virt) {
iounmap((void *)dbox2_flash_map.virt);
dbox2_flash_map.virt = 0;
}
}
