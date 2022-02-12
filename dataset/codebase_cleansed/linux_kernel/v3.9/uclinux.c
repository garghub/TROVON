static int uclinux_point(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, void **virt, resource_size_t *phys)
{
struct map_info *map = mtd->priv;
*virt = map->virt + from;
if (phys)
*phys = map->phys + from;
*retlen = len;
return(0);
}
static int __init uclinux_mtd_init(void)
{
struct mtd_info *mtd;
struct map_info *mapp;
mapp = &uclinux_ram_map;
if (physaddr == -1)
mapp->phys = (resource_size_t)__bss_stop;
else
mapp->phys = physaddr;
if (!mapp->size)
mapp->size = PAGE_ALIGN(ntohl(*((unsigned long *)(mapp->phys + 8))));
mapp->bankwidth = 4;
printk("uclinux[mtd]: probe address=0x%x size=0x%x\n",
(int) mapp->phys, (int) mapp->size);
mapp->virt = phys_to_virt(mapp->phys);
if (mapp->virt == 0) {
printk("uclinux[mtd]: no virtual mapping?\n");
return(-EIO);
}
simple_map_init(mapp);
mtd = do_map_probe("map_" MAP_NAME, mapp);
if (!mtd) {
printk("uclinux[mtd]: failed to find a mapping?\n");
return(-ENXIO);
}
mtd->owner = THIS_MODULE;
mtd->_point = uclinux_point;
mtd->priv = mapp;
uclinux_ram_mtdinfo = mtd;
mtd_device_register(mtd, uclinux_romfs, NUM_PARTITIONS);
return(0);
}
static void __exit uclinux_mtd_cleanup(void)
{
if (uclinux_ram_mtdinfo) {
mtd_device_unregister(uclinux_ram_mtdinfo);
map_destroy(uclinux_ram_mtdinfo);
uclinux_ram_mtdinfo = NULL;
}
if (uclinux_ram_map.virt)
uclinux_ram_map.virt = 0;
}
