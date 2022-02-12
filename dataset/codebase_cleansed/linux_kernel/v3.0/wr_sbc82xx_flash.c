static int __init init_sbc82xx_flash(void)
{
volatile memctl_cpm2_t *mc = &cpm2_immr->im_memctl;
int bigflash;
int i;
#ifdef CONFIG_SBC8560
mc = ioremap(0xff700000 + 0x5000, sizeof(memctl_cpm2_t));
#else
mc = &cpm2_immr->im_memctl;
#endif
bigflash = 1;
if ((mc->memc_br0 & 0x00001800) == 0x00001800)
bigflash = 0;
init_sbc82xx_one_flash(sbc82xx_flash_map[0], mc->memc_br0, mc->memc_or0);
init_sbc82xx_one_flash(sbc82xx_flash_map[1], mc->memc_br6, mc->memc_or6);
init_sbc82xx_one_flash(sbc82xx_flash_map[2], mc->memc_br1, mc->memc_or1);
#ifdef CONFIG_SBC8560
iounmap((void *) mc);
#endif
for (i=0; i<3; i++) {
int8_t flashcs[3] = { 0, 6, 1 };
int nr_parts;
printk(KERN_NOTICE "PowerQUICC II %s (%ld MiB on CS%d",
sbc82xx_flash_map[i].name,
(sbc82xx_flash_map[i].size >> 20),
flashcs[i]);
if (!sbc82xx_flash_map[i].phys) {
printk("): disabled by bootloader.\n");
continue;
}
printk(" at %08lx)\n", sbc82xx_flash_map[i].phys);
sbc82xx_flash_map[i].virt = ioremap(sbc82xx_flash_map[i].phys, sbc82xx_flash_map[i].size);
if (!sbc82xx_flash_map[i].virt) {
printk("Failed to ioremap\n");
continue;
}
simple_map_init(&sbc82xx_flash_map[i]);
sbcmtd[i] = do_map_probe("cfi_probe", &sbc82xx_flash_map[i]);
if (!sbcmtd[i])
continue;
sbcmtd[i]->owner = THIS_MODULE;
nr_parts = parse_mtd_partitions(sbcmtd[i], part_probes,
&sbcmtd_parts[i], 0);
if (nr_parts > 0) {
mtd_device_register(sbcmtd[i], sbcmtd_parts[i],
nr_parts);
continue;
}
if (i == 2) {
mtd_device_register(sbcmtd[i], NULL, 0);
} else if (i == bigflash) {
mtd_device_register(sbcmtd[i], bigflash_parts,
ARRAY_SIZE(bigflash_parts));
} else {
mtd_device_register(sbcmtd[i], smallflash_parts,
ARRAY_SIZE(smallflash_parts));
}
}
return 0;
}
static void __exit cleanup_sbc82xx_flash(void)
{
int i;
for (i=0; i<3; i++) {
if (!sbcmtd[i])
continue;
if (i<2 || sbcmtd_parts[i])
mtd_device_unregister(sbcmtd[i]);
else
mtd_device_unregister(sbcmtd[i]);
kfree(sbcmtd_parts[i]);
map_destroy(sbcmtd[i]);
iounmap((void *)sbc82xx_flash_map[i].virt);
sbc82xx_flash_map[i].virt = 0;
}
}
