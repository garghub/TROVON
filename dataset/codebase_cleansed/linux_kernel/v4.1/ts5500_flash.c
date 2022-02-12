static int __init init_ts5500_map(void)
{
int rc = 0;
ts5500_map.virt = ioremap_nocache(ts5500_map.phys, ts5500_map.size);
if (!ts5500_map.virt) {
printk(KERN_ERR "Failed to ioremap_nocache\n");
rc = -EIO;
goto err2;
}
simple_map_init(&ts5500_map);
mymtd = do_map_probe("jedec_probe", &ts5500_map);
if (!mymtd)
mymtd = do_map_probe("map_rom", &ts5500_map);
if (!mymtd) {
rc = -ENXIO;
goto err1;
}
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, ts5500_partitions, NUM_PARTITIONS);
return 0;
err1:
iounmap(ts5500_map.virt);
err2:
return rc;
}
static void __exit cleanup_ts5500_map(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (ts5500_map.virt) {
iounmap(ts5500_map.virt);
ts5500_map.virt = NULL;
}
}
