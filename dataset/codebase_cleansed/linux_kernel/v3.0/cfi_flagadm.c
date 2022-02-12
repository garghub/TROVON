static int __init init_flagadm(void)
{
printk(KERN_NOTICE "FlagaDM flash device: %x at %x\n",
FLASH_SIZE, FLASH_PHYS_ADDR);
flagadm_map.phys = FLASH_PHYS_ADDR;
flagadm_map.virt = ioremap(FLASH_PHYS_ADDR,
FLASH_SIZE);
if (!flagadm_map.virt) {
printk("Failed to ioremap\n");
return -EIO;
}
simple_map_init(&flagadm_map);
mymtd = do_map_probe("cfi_probe", &flagadm_map);
if (mymtd) {
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, flagadm_parts, PARTITION_COUNT);
printk(KERN_NOTICE "FlagaDM flash device initialized\n");
return 0;
}
iounmap((void *)flagadm_map.virt);
return -ENXIO;
}
static void __exit cleanup_flagadm(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (flagadm_map.virt) {
iounmap((void *)flagadm_map.virt);
flagadm_map.virt = 0;
}
}
