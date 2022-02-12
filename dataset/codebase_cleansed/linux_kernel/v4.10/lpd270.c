static void lpd270_mask_irq(struct irq_data *d)
{
int lpd270_irq = d->irq - LPD270_IRQ(0);
__raw_writew(~(1 << lpd270_irq), LPD270_INT_STATUS);
lpd270_irq_enabled &= ~(1 << lpd270_irq);
__raw_writew(lpd270_irq_enabled, LPD270_INT_MASK);
}
static void lpd270_unmask_irq(struct irq_data *d)
{
int lpd270_irq = d->irq - LPD270_IRQ(0);
lpd270_irq_enabled |= 1 << lpd270_irq;
__raw_writew(lpd270_irq_enabled, LPD270_INT_MASK);
}
static void lpd270_irq_handler(struct irq_desc *desc)
{
unsigned int irq;
unsigned long pending;
pending = __raw_readw(LPD270_INT_STATUS) & lpd270_irq_enabled;
do {
desc->irq_data.chip->irq_ack(&desc->irq_data);
if (likely(pending)) {
irq = LPD270_IRQ(0) + __ffs(pending);
generic_handle_irq(irq);
pending = __raw_readw(LPD270_INT_STATUS) &
lpd270_irq_enabled;
}
} while (pending);
}
static void __init lpd270_init_irq(void)
{
int irq;
pxa27x_init_irq();
__raw_writew(0, LPD270_INT_MASK);
__raw_writew(0, LPD270_INT_STATUS);
for (irq = LPD270_IRQ(2); irq <= LPD270_IRQ(4); irq++) {
irq_set_chip_and_handler(irq, &lpd270_irq_chip,
handle_level_irq);
irq_clear_status_flags(irq, IRQ_NOREQUEST | IRQ_NOPROBE);
}
irq_set_chained_handler(PXA_GPIO_TO_IRQ(0), lpd270_irq_handler);
irq_set_irq_type(PXA_GPIO_TO_IRQ(0), IRQ_TYPE_EDGE_FALLING);
}
static void lpd270_irq_resume(void)
{
__raw_writew(lpd270_irq_enabled, LPD270_INT_MASK);
}
static int __init lpd270_irq_device_init(void)
{
if (machine_is_logicpd_pxa270()) {
register_syscore_ops(&lpd270_irq_syscore_ops);
return 0;
}
return -ENODEV;
}
static int __init lpd270_set_lcd(char *str)
{
if (!strncasecmp(str, "lq057q3dc02", 11)) {
lpd270_lcd_to_use = &sharp_lq057q3dc02;
} else if (!strncasecmp(str, "lq121s1dg31", 11)) {
lpd270_lcd_to_use = &sharp_lq121s1dg31;
} else if (!strncasecmp(str, "lq036q1da01", 11)) {
lpd270_lcd_to_use = &sharp_lq036q1da01;
} else if (!strncasecmp(str, "lq64d343", 8)) {
lpd270_lcd_to_use = &sharp_lq64d343;
} else if (!strncasecmp(str, "lq10d368", 8)) {
lpd270_lcd_to_use = &sharp_lq10d368;
} else if (!strncasecmp(str, "lq035q7db02-20", 14)) {
lpd270_lcd_to_use = &sharp_lq035q7db02_20;
} else {
printk(KERN_INFO "lpd270: unknown lcd panel [%s]\n", str);
}
return 1;
}
static void __init lpd270_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(lpd270_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
lpd270_flash_data[0].width = (__raw_readl(BOOT_DEF) & 1) ? 2 : 4;
lpd270_flash_data[1].width = 4;
ARB_CNTRL = ARB_CORE_PARK | 0x234;
pwm_add_table(lpd270_pwm_lookup, ARRAY_SIZE(lpd270_pwm_lookup));
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
pxa_set_ac97_info(NULL);
if (lpd270_lcd_to_use != NULL)
pxa_set_fb_info(NULL, lpd270_lcd_to_use);
pxa_set_ohci_info(&lpd270_ohci_platform_data);
}
static void __init lpd270_map_io(void)
{
pxa27x_map_io();
iotable_init(lpd270_io_desc, ARRAY_SIZE(lpd270_io_desc));
PSLR |= 0x00000F04;
PCFR = 0x00000066;
}
