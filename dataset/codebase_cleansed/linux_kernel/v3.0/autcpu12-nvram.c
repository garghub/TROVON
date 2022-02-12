static int __init init_autcpu12_sram (void)
{
int err, save0, save1;
autcpu12_sram_map.virt = ioremap(0x12000000, SZ_128K);
if (!autcpu12_sram_map.virt) {
printk("Failed to ioremap autcpu12 NV-RAM space\n");
err = -EIO;
goto out;
}
simple_map_init(&autcpu_sram_map);
save0 = map_read32(&autcpu12_sram_map,0);
save1 = map_read32(&autcpu12_sram_map,0x10000);
map_write32(&autcpu12_sram_map,~save0,0x10000);
if ( map_read32(&autcpu12_sram_map,0) != save0) {
map_write32(&autcpu12_sram_map,save0,0x0);
goto map;
}
map_write32(&autcpu12_sram_map,save1,0x10000);
autcpu12_sram_map.size = SZ_128K;
map:
sram_mtd = do_map_probe("map_ram", &autcpu12_sram_map);
if (!sram_mtd) {
printk("NV-RAM probe failed\n");
err = -ENXIO;
goto out_ioremap;
}
sram_mtd->owner = THIS_MODULE;
sram_mtd->erasesize = 16;
if (mtd_device_register(sram_mtd, NULL, 0)) {
printk("NV-RAM device addition failed\n");
err = -ENOMEM;
goto out_probe;
}
printk("NV-RAM device size %ldKiB registered on AUTCPU12\n",autcpu12_sram_map.size/SZ_1K);
return 0;
out_probe:
map_destroy(sram_mtd);
sram_mtd = 0;
out_ioremap:
iounmap((void *)autcpu12_sram_map.virt);
out:
return err;
}
static void __exit cleanup_autcpu12_maps(void)
{
if (sram_mtd) {
mtd_device_unregister(sram_mtd);
map_destroy(sram_mtd);
iounmap((void *)autcpu12_sram_map.virt);
}
}
