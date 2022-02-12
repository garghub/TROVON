static int __init parse_tag_acorn(const struct tag *tag)
{
memc_ctrl_reg = tag->u.acorn.memc_control_reg;
number_mfm_drives = tag->u.acorn.adfsdrives;
switch (tag->u.acorn.vram_pages) {
case 512:
vram_size += PAGE_SIZE * 256;
case 256:
vram_size += PAGE_SIZE * 256;
default:
break;
}
#if 0
if (vram_size) {
desc->video_start = 0x02000000;
desc->video_end = 0x02000000 + vram_size;
}
#endif
return 0;
}
static void __init rpc_map_io(void)
{
iotable_init(rpc_io_desc, ARRAY_SIZE(rpc_io_desc));
writeb(0xc, PCIO_BASE + (0x3f2 << 2));
elf_hwcap &= ~HWCAP_HALF;
}
static int __init rpc_init(void)
{
i2c_register_board_info(0, &i2c_rtc, 1);
return platform_add_devices(devs, ARRAY_SIZE(devs));
}
