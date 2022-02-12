static void __init bcmring_init_machine(void)
{
bcmring_sysctl_header = register_sysctl_table(bcmring_sysctl_reboot);
chipcHw_enableSpreadSpectrum();
platform_add_devices(devices, ARRAY_SIZE(devices));
bcmring_amba_init();
dma_init();
}
static void __init bcmring_fixup(struct tag *t, char **cmdline,
struct meminfo *mi) {
#ifdef CONFIG_BLK_DEV_INITRD
printk(KERN_NOTICE "bcmring_fixup\n");
t->hdr.tag = ATAG_CORE;
t->hdr.size = tag_size(tag_core);
t->u.core.flags = 0;
t->u.core.pagesize = PAGE_SIZE;
t->u.core.rootdev = 31 << 8 | 0;
t = tag_next(t);
t->hdr.tag = ATAG_MEM;
t->hdr.size = tag_size(tag_mem32);
t->u.mem.start = CFG_GLOBAL_RAM_BASE;
t->u.mem.size = CFG_GLOBAL_RAM_SIZE;
t = tag_next(t);
t->hdr.tag = ATAG_NONE;
t->hdr.size = 0;
#endif
}
