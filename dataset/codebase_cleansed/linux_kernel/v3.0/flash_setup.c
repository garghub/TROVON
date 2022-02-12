static int __init flash_init(void)
{
union cvmx_mio_boot_reg_cfgx region_cfg;
region_cfg.u64 = cvmx_read_csr(CVMX_MIO_BOOT_REG_CFGX(0));
if (region_cfg.s.en) {
flash_map.name = "phys_mapped_flash";
flash_map.phys = region_cfg.s.base << 16;
flash_map.size = 0x1fc00000 - flash_map.phys;
flash_map.bankwidth = 1;
flash_map.virt = ioremap(flash_map.phys, flash_map.size);
pr_notice("Bootbus flash: Setting flash for %luMB flash at "
"0x%08llx\n", flash_map.size >> 20, flash_map.phys);
simple_map_init(&flash_map);
mymtd = do_map_probe("cfi_probe", &flash_map);
if (mymtd) {
mymtd->owner = THIS_MODULE;
nr_parts = parse_mtd_partitions(mymtd,
part_probe_types,
&parts, 0);
mtd_device_register(mymtd, parts, nr_parts);
} else {
pr_err("Failed to register MTD device for flash\n");
}
}
return 0;
}
