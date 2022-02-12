static void __init cmx2xx_init_dm9000(void)
{
if (cpu_is_pxa25x())
cmx2xx_dm9000_device.resource = cmx255_dm9000_resource;
else
cmx2xx_dm9000_device.resource = cmx270_dm9000_resource;
platform_device_register(&cmx2xx_dm9000_device);
}
static inline void cmx2xx_init_dm9000(void) {}
static void __init cmx2xx_init_touchscreen(void)
{
platform_device_register(&cmx2xx_ts_device);
}
static inline void cmx2xx_init_touchscreen(void) {}
static void __init cmx2xx_init_leds(void)
{
if (cpu_is_pxa25x()) {
cmx2xx_leds[0].gpio = CMX255_GPIO_RED;
cmx2xx_leds[1].gpio = CMX255_GPIO_GREEN;
} else {
cmx2xx_leds[0].gpio = CMX270_GPIO_RED;
cmx2xx_leds[1].gpio = CMX270_GPIO_GREEN;
}
platform_device_register(&cmx2xx_led_device);
}
static inline void cmx2xx_init_leds(void) {}
static int __init cmx2xx_set_display(char *str)
{
int disp_type = simple_strtol(str, NULL, 0);
switch (disp_type) {
case MTYPE_STN320x240:
cmx2xx_display = &generic_stn_320x240;
break;
case MTYPE_TFT640x480:
cmx2xx_display = &generic_tft_640x480;
break;
case MTYPE_CRT640x480:
cmx2xx_display = &generic_crt_640x480;
break;
case MTYPE_CRT800x600:
cmx2xx_display = &generic_crt_800x600;
break;
case MTYPE_TFT320x240:
cmx2xx_display = &generic_tft_320x240;
break;
case MTYPE_STN640x480:
cmx2xx_display = &generic_stn_640x480;
break;
default:
cmx2xx_display = &generic_crt_640x480;
break;
}
return 1;
}
static void __init cmx2xx_init_display(void)
{
pxa_set_fb_info(NULL, cmx2xx_display);
}
static inline void cmx2xx_init_display(void) {}
static int cmx2xx_suspend(void)
{
cmx2xx_pci_suspend();
sleep_save_msc[0] = __raw_readl(MSC0);
sleep_save_msc[1] = __raw_readl(MSC1);
sleep_save_msc[2] = __raw_readl(MSC2);
PCFR = 0x0;
PSLR = 0xff400000;
PMCR = 0x00000005;
PWER = 0x80000000;
PFER = 0x00000000;
PRER = 0x00000000;
PGSR0 = 0xC0018800;
PGSR1 = 0x004F0002;
PGSR2 = 0x6021C000;
PGSR3 = 0x00020000;
return 0;
}
static void cmx2xx_resume(void)
{
cmx2xx_pci_resume();
__raw_writel(sleep_save_msc[0], MSC0);
__raw_writel(sleep_save_msc[1], MSC1);
__raw_writel(sleep_save_msc[2], MSC2);
}
static int __init cmx2xx_pm_init(void)
{
register_syscore_ops(&cmx2xx_pm_syscore_ops);
return 0;
}
static int __init cmx2xx_pm_init(void) { return 0; }
static void __init cmx2xx_init_ac97(void)
{
pxa_set_ac97_info(NULL);
}
static inline void cmx2xx_init_ac97(void) {}
static void __init cmx2xx_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
cmx2xx_pm_init();
if (cpu_is_pxa25x())
cmx255_init();
else
cmx270_init();
cmx2xx_init_dm9000();
cmx2xx_init_display();
cmx2xx_init_ac97();
cmx2xx_init_touchscreen();
cmx2xx_init_leds();
}
static void __init cmx2xx_init_irq(void)
{
if (cpu_is_pxa25x()) {
pxa25x_init_irq();
cmx2xx_pci_init_irq(CMX255_GPIO_IT8152_IRQ);
} else {
pxa27x_init_irq();
cmx2xx_pci_init_irq(CMX270_GPIO_IT8152_IRQ);
}
}
static void __init cmx2xx_map_io(void)
{
if (cpu_is_pxa25x())
pxa25x_map_io();
if (cpu_is_pxa27x())
pxa27x_map_io();
iotable_init(cmx2xx_io_desc, ARRAY_SIZE(cmx2xx_io_desc));
it8152_base_address = CMX2XX_IT8152_VIRT;
}
static void __init cmx2xx_map_io(void)
{
if (cpu_is_pxa25x())
pxa25x_map_io();
if (cpu_is_pxa27x())
pxa27x_map_io();
}
