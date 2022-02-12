static int __init h720x_mtd_init(void)
{
char *part_type = NULL;
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
nr_mtd_parts = parse_mtd_partitions(mymtd, probes, &mtd_parts, 0);
if (nr_mtd_parts > 0)
part_type = "command line";
if (nr_mtd_parts <= 0) {
mtd_parts = h720x_partitions;
nr_mtd_parts = NUM_PARTITIONS;
part_type = "builtin";
}
printk(KERN_INFO "Using %s partition table\n", part_type);
mtd_device_register(mymtd, mtd_parts, nr_mtd_parts);
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
if (mtd_parts && (mtd_parts != h720x_partitions))
kfree (mtd_parts);
if (h720x_map.virt) {
iounmap((void *)h720x_map.virt);
h720x_map.virt = 0;
}
}
