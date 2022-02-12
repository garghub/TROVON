u32 __init rcar_gen2_read_mode_pins(void)
{
void __iomem *modemr = ioremap_nocache(MODEMR, 4);
u32 mode;
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
return mode;
}
void __init rcar_gen2_timer_init(void)
{
#if defined(CONFIG_ARM_ARCH_TIMER) || defined(CONFIG_COMMON_CLK)
u32 mode = rcar_gen2_read_mode_pins();
#endif
#ifdef CONFIG_ARM_ARCH_TIMER
void __iomem *base;
int extal_mhz = 0;
u32 freq;
switch (mode & (MD(14) | MD(13))) {
case 0:
extal_mhz = 15;
break;
case MD(13):
extal_mhz = 20;
break;
case MD(14):
extal_mhz = 26;
break;
case MD(13) | MD(14):
extal_mhz = 30;
break;
}
freq = extal_mhz * (1000000 / 2);
base = ioremap(0xe6080000, PAGE_SIZE);
if ((ioread32(base + CNTCR) & 1) == 0 ||
ioread32(base + CNTFID0) != freq) {
iowrite32(freq, base + CNTFID0);
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
iowrite32(1, base + CNTCR);
}
iounmap(base);
#endif
#ifdef CONFIG_COMMON_CLK
rcar_gen2_clocks_init(mode);
#endif
clocksource_of_init();
}
