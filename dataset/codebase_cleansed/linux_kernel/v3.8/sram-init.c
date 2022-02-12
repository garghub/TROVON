static void __init omap_detect_and_map_sram(void)
{
unsigned long omap_sram_skip = SRAM_BOOTLOADER_SZ;
unsigned long omap_sram_start = OMAP1_SRAM_PA;
unsigned long omap_sram_size;
if (cpu_is_omap7xx())
omap_sram_size = 0x32000;
else if (cpu_is_omap15xx())
omap_sram_size = 0x30000;
else if (cpu_is_omap1610() || cpu_is_omap1611() ||
cpu_is_omap1621() || cpu_is_omap1710())
omap_sram_size = 0x4000;
else {
pr_err("Could not detect SRAM size\n");
omap_sram_size = 0x4000;
}
omap_map_sram(omap_sram_start, omap_sram_size,
omap_sram_skip, 1);
}
void omap_sram_reprogram_clock(u32 dpllctl, u32 ckctl)
{
BUG_ON(!_omap_sram_reprogram_clock);
if (cpu_is_omap7xx())
ckctl |= 0x2000;
_omap_sram_reprogram_clock(dpllctl, ckctl);
}
int __init omap_sram_init(void)
{
omap_detect_and_map_sram();
_omap_sram_reprogram_clock =
omap_sram_push(omap1_sram_reprogram_clock,
omap1_sram_reprogram_clock_sz);
return 0;
}
