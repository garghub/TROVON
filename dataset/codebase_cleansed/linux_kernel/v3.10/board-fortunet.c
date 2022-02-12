static void __init
fortunet_fixup(struct tag *tags, char **cmdline, struct meminfo *mi)
{
IMAGE_PARAMS *ip = phys_to_virt(IMAGE_PARAMS_PHYS);
*cmdline = phys_to_virt(ip->command_line);
#ifdef CONFIG_BLK_DEV_INITRD
if(ip->ramdisk_ok)
{
initrd_start = __phys_to_virt(ip->ramdisk_address);
initrd_end = initrd_start + ip->ramdisk_size;
}
#endif
memmap.bank[0].size = ip->ram_size;
*mi = memmap;
}
