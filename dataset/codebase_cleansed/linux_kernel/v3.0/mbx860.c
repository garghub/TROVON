static int __init init_mbx(void)
{
printk(KERN_NOTICE "Motorola MBX flash device: 0x%x at 0x%x\n", WINDOW_SIZE*4, WINDOW_ADDR);
mbx_map.virt = ioremap(WINDOW_ADDR, WINDOW_SIZE * 4);
if (!mbx_map.virt) {
printk("Failed to ioremap\n");
return -EIO;
}
simple_map_init(&mbx_map);
mymtd = do_map_probe("jedec_probe", &mbx_map);
if (mymtd) {
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, NULL, 0);
mtd_device_register(mymtd, partition_info, NUM_PARTITIONS);
return 0;
}
iounmap((void *)mbx_map.virt);
return -ENXIO;
}
static void __exit cleanup_mbx(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (mbx_map.virt) {
iounmap((void *)mbx_map.virt);
mbx_map.virt = 0;
}
}
