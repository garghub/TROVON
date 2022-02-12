static int __init init_rpxlite(void)
{
printk(KERN_NOTICE "RPX Lite or CLLF flash device: %x at %x\n", WINDOW_SIZE*4, WINDOW_ADDR);
rpxlite_map.virt = ioremap(WINDOW_ADDR, WINDOW_SIZE * 4);
if (!rpxlite_map.virt) {
printk("Failed to ioremap\n");
return -EIO;
}
simple_map_init(&rpxlite_map);
mymtd = do_map_probe("cfi_probe", &rpxlite_map);
if (mymtd) {
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, NULL, 0);
return 0;
}
iounmap((void *)rpxlite_map.virt);
return -ENXIO;
}
static void __exit cleanup_rpxlite(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (rpxlite_map.virt) {
iounmap((void *)rpxlite_map.virt);
rpxlite_map.virt = 0;
}
}
