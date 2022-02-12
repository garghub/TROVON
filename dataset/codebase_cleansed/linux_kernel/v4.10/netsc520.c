static int __init init_netsc520(void)
{
printk(KERN_NOTICE "NetSc520 flash device: 0x%Lx at 0x%Lx\n",
(unsigned long long)netsc520_map.size,
(unsigned long long)netsc520_map.phys);
netsc520_map.virt = ioremap_nocache(netsc520_map.phys, netsc520_map.size);
if (!netsc520_map.virt) {
printk("Failed to ioremap_nocache\n");
return -EIO;
}
simple_map_init(&netsc520_map);
mymtd = do_map_probe("cfi_probe", &netsc520_map);
if(!mymtd)
mymtd = do_map_probe("map_ram", &netsc520_map);
if(!mymtd)
mymtd = do_map_probe("map_rom", &netsc520_map);
if (!mymtd) {
iounmap(netsc520_map.virt);
return -ENXIO;
}
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, partition_info, NUM_PARTITIONS);
return 0;
}
static void __exit cleanup_netsc520(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (netsc520_map.virt) {
iounmap(netsc520_map.virt);
netsc520_map.virt = NULL;
}
}
