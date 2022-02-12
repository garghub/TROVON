static void bcmring_restart(char mode, const char *cmd)
{
printk("arch_reset:%c %x\n", mode, bcmring_arch_warm_reboot);
if (mode == 'h') {
if (bcmring_arch_warm_reboot) {
printk("warm reset\n");
chipcHw_reset(chipcHw_REG_SOFT_RESET_CHIP_WARM);
} else {
printk("force reset\n");
chipcHw_reset(chipcHw_REG_SOFT_RESET_CHIP_SOFT);
}
} else {
printk("force reset\n");
chipcHw_reset(chipcHw_REG_SOFT_RESET_CHIP_SOFT);
}
}
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
