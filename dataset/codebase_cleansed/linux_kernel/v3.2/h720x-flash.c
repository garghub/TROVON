static int __init h720x_mtd_init(void)
{
h720x_map.virt = ioremap(h720x_map.phys, h720x_map.size);
if (!h720x_map.virt) {
printk(KERN_ERR "H720x-MTD: ioremap failed\n");
return -EIO;
}
simple_map_init(&h720x_map);
printk (KERN_INFO "H720x-MTD probing 32bit FLASH\n");
mymtd = do_map_probe("cfi_probe", &h720x_map);
if (!mymtd) {
printk (KERN_INFO "H720x-MTD probing 16bit FLASH\n");
h720x_map.bankwidth = 2;
mymtd = do_map_probe("cfi_probe", &h720x_map);
}
if (mymtd) {
mymtd->owner = THIS_MODULE;
mtd_device_parse_register(mymtd, NULL, 0,
h720x_partitions, NUM_PARTITIONS);
return 0;
}
iounmap((void *)h720x_map.virt);
return -ENXIO;
}
static void __exit h720x_mtd_cleanup(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (h720x_map.virt) {
iounmap((void *)h720x_map.virt);
h720x_map.virt = 0;
}
}
