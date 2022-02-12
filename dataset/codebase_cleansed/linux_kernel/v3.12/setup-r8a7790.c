void __init r8a7790_pinmux_init(void)
{
platform_device_register_simple("pfc-r8a7790", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
r8a7790_register_gpio(0);
r8a7790_register_gpio(1);
r8a7790_register_gpio(2);
r8a7790_register_gpio(3);
r8a7790_register_gpio(4);
r8a7790_register_gpio(5);
}
static inline void r8a7790_register_scif(int idx)
{
platform_device_register_data(&platform_bus, "sh-sci", idx, &scif[idx],
sizeof(struct plat_sci_port));
}
void __init r8a7790_add_dt_devices(void)
{
r8a7790_register_scif(SCIFA0);
r8a7790_register_scif(SCIFA1);
r8a7790_register_scif(SCIFB0);
r8a7790_register_scif(SCIFB1);
r8a7790_register_scif(SCIFB2);
r8a7790_register_scif(SCIFA2);
r8a7790_register_scif(SCIF0);
r8a7790_register_scif(SCIF1);
r8a7790_register_scif(HSCIF0);
r8a7790_register_scif(HSCIF1);
r8a7790_register_cmt(00);
}
void __init r8a7790_add_standard_devices(void)
{
r8a7790_add_dt_devices();
r8a7790_register_irqc(0);
r8a7790_register_thermal();
}
u32 __init r8a7790_read_mode_pins(void)
{
void __iomem *modemr = ioremap_nocache(MODEMR, 4);
u32 mode;
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
return mode;
}
void __init r8a7790_timer_init(void)
{
#ifdef CONFIG_ARM_ARCH_TIMER
u32 mode = r8a7790_read_mode_pins();
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
iowrite32(freq, base + CNTFID0);
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
iowrite32(1, base + CNTCR);
iounmap(base);
#endif
clocksource_of_init();
}
void __init r8a7790_init_delay(void)
{
#ifndef CONFIG_ARM_ARCH_TIMER
shmobile_setup_delay(1300, 2, 4);
#endif
}
