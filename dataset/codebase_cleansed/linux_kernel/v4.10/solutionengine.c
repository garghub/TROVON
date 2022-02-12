static int __init init_soleng_maps(void)
{
soleng_flash_map.phys = 0;
soleng_flash_map.virt = (void __iomem *)P2SEGADDR(0);
soleng_eprom_map.phys = 0x01000000;
soleng_eprom_map.virt = (void __iomem *)P1SEGADDR(0x01000000);
simple_map_init(&soleng_eprom_map);
simple_map_init(&soleng_flash_map);
printk(KERN_NOTICE "Probing for flash chips at 0x00000000:\n");
flash_mtd = do_map_probe("cfi_probe", &soleng_flash_map);
if (!flash_mtd) {
printk(KERN_NOTICE "Probing for flash chips at 0x01000000:\n");
soleng_flash_map.phys = 0x01000000;
soleng_flash_map.virt = P2SEGADDR(0x01000000);
soleng_eprom_map.phys = 0;
soleng_eprom_map.virt = P1SEGADDR(0);
flash_mtd = do_map_probe("cfi_probe", &soleng_flash_map);
if (!flash_mtd) {
printk(KERN_NOTICE "Flash chips not detected at either possible location.\n");
return -ENXIO;
}
}
printk(KERN_NOTICE "Solution Engine: Flash at 0x%08lx, EPROM at 0x%08lx\n",
soleng_flash_map.phys & 0x1fffffff,
soleng_eprom_map.phys & 0x1fffffff);
flash_mtd->owner = THIS_MODULE;
eprom_mtd = do_map_probe("map_rom", &soleng_eprom_map);
if (eprom_mtd) {
eprom_mtd->owner = THIS_MODULE;
mtd_device_register(eprom_mtd, NULL, 0);
}
mtd_device_parse_register(flash_mtd, probes, NULL, NULL, 0);
return 0;
}
static void __exit cleanup_soleng_maps(void)
{
if (eprom_mtd) {
mtd_device_unregister(eprom_mtd);
map_destroy(eprom_mtd);
}
mtd_device_unregister(flash_mtd);
map_destroy(flash_mtd);
}
